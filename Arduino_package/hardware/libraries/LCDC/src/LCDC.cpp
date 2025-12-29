/*
 * Copyright (c) 2015 Arduino LLC
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "LCDC.h"
#include <User_Select.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "ameba_soc.h"

#ifdef __cplusplus
}
#endif

#define LCDC_LINE_NUM_INTR_DEF      (LCDC_HEIGHT / 2)

extern const lcdc_pin_config gPinCfg[];
extern const lcdc_gpio_ctrl gGpioCtrl[];
AmebaLCDC *gInstance = NULL;
static rtos_sema_t g_vsync_sem = NULL;

/* config pinmux and control blen pad */
static void lcdc_pinmux_config(void)
{
    const lcdc_pin_config *pc;
    const lcdc_gpio_ctrl *gc;
    uint32_t pin;

    for (pc = (lcdc_pin_config *)gPinCfg; ((pc->pin_name != TOTAL_GPIO_PIN_NUM) && (pc->func_name != 0xFFFFFFFF)); pc++) {
        amb_ard_pin_check_fun(pc->pin_name, PIO_LCDC);

        pin = g_APinDescription[pc->pin_name].pinname;
        Pinmux_Config(pin, pc->func_name);
    }

    for (gc = (lcdc_gpio_ctrl *)gGpioCtrl; ((gc->pin_name != TOTAL_GPIO_PIN_NUM) && (gc->func_name != LCD_GPIO_CTRL_FUNC_INVALID)); gc++) {
        amb_ard_pin_check_fun(gc->pin_name, PIO_GPIO);

        pin = g_APinDescription[gc->pin_name].pinname;
        GPIO_InitTypeDef gpioOther;
        gpioOther.GPIO_Pin = pin;
        gpioOther.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_Init(&gpioOther);
        GPIO_WriteBit(pin, gc->def_sta);
    }
}

static uint32_t lcdc_irq_handler(void *data)
{
    (void)data;
    volatile u32 IntId;
    lcdc_vblank_cb cb = NULL;
    void *cbData = NULL;
    uint8_t *buf = NULL;

    IntId = LCDC_GetINTStatus(LCDC);
    LCDC_ClearINT(LCDC, IntId);

    if (IntId & LCDC_BIT_LCD_FRD_INTS) {
        //RTK_LOGS(NOTAG, RTK_LOG_DEBUG, "intr: frame done \r\n");
    }

    if (IntId & LCDC_BIT_LCD_LIN_INTS) {
        //RTK_LOGS(NOTAG, RTK_LOG_DEBUG, "intr: line hit \r\n");
        if (gInstance != NULL) {
            if ((cb = gInstance->get_callback()) != NULL) {
                cbData = gInstance->get_callback_data();
                cb(cbData);
            }
            if (g_vsync_sem != NULL) {
                if (rtos_sema_get_count(g_vsync_sem) > 0) {
                    rtos_sema_take(g_vsync_sem, 0);
                    if ((buf = gInstance->get_cur_buffer()) != NULL) {
                        LCDC_DMAImgCfg(LCDC, (u32)buf);
                        LCDC_ShadowReloadConfig(LCDC);
                    }
                }
            }
        }
    }

    if (IntId & LCDC_BIT_DMA_UN_INTS) {
        //RTK_LOGS(NOTAG, RTK_LOG_ALWAYS, "intr: dma udf !!! \r\n");
    }

    return 0;
}

static void lcdc_driver_init(void)
{
    LCDC_RGBInitTypeDef LCDC_RGBInitStruct;

    LCDC_Cmd(LCDC, DISABLE);
    LCDC_RGBStructInit(&LCDC_RGBInitStruct);

    LCDC_RGBInitStruct.Panel_Init.IfWidth = LCDC_INTERFACE_WIDTH;
    LCDC_RGBInitStruct.Panel_Init.ImgWidth = LCDC_WIDTH;
    LCDC_RGBInitStruct.Panel_Init.ImgHeight = LCDC_HEIGHT;

    if (LCDC_INTERFACE == RGB) {
        /* set HV para according to lcd spec */
        LCDC_RGBInitStruct.Panel_RgbTiming.RgbVsw = LCDC_RGB_VSW;
        LCDC_RGBInitStruct.Panel_RgbTiming.RgbVbp = LCDC_RGB_VBP;
        LCDC_RGBInitStruct.Panel_RgbTiming.RgbVfp = LCDC_RGB_VFP;

        LCDC_RGBInitStruct.Panel_RgbTiming.RgbHsw = LCDC_RGB_HSW;
        LCDC_RGBInitStruct.Panel_RgbTiming.RgbHbp = LCDC_RGB_HBP;
        LCDC_RGBInitStruct.Panel_RgbTiming.RgbHfp = LCDC_RGB_HFP;

        LCDC_RGBInitStruct.Panel_RgbTiming.Flags.RgbEnPolar = LCDC_RGB_ENABLE_POLAR;
        LCDC_RGBInitStruct.Panel_RgbTiming.Flags.RgbDclkActvEdge = LCDC_RGB_DCLK_ACTIVE_EDGE;
        LCDC_RGBInitStruct.Panel_RgbTiming.Flags.RgbHsPolar = LCDC_RGB_HS_POLAR;
        LCDC_RGBInitStruct.Panel_RgbTiming.Flags.RgbVsPolar = LCDC_RGB_VS_POLAR;

        LCDC_RGBInitStruct.Panel_Init.RGBRefreshFreq = LCDC_RGB_REFRESH_FREQ;
    /*} else if (LCDC_INTERFACE == MCU) {
        LCDC_MCUInitStruct.Panel_McuTiming.McuRdPolar = LCDC_MCU_RD_POLAR;
        LCDC_MCUInitStruct.Panel_McuTiming.McuWrPolar = LCDC_MCU_WR_POLAR;
        LCDC_MCUInitStruct.Panel_McuTiming.McuRsPolar = LCDC_MCU_RS_POLAR;
        LCDC_MCUInitStruct.Panel_McuTiming.McuTePolar = LCDC_MCU_TE_POLAR;    // workaround for G2 a-cut MCU-TE irq issue
        LCDC_MCUInitStruct.Panel_McuTiming.McuSyncPolar = LCDC_MCU_VSYNC_POLAR;*/
    } else {

    }
    
    if (LCDC_COLOR_DEPTH == COLOR_DEPTH_16) {
        LCDC_RGBInitStruct.Panel_Init.InputFormat = LCDC_INPUT_FORMAT_RGB565;
        LCDC_RGBInitStruct.Panel_Init.OutputFormat = LCDC_OUTPUT_FORMAT_RGB565;
    } else if (LCDC_COLOR_DEPTH == COLOR_DEPTH_24) {
        LCDC_RGBInitStruct.Panel_Init.InputFormat = LCDC_INPUT_FORMAT_RGB888;
        LCDC_RGBInitStruct.Panel_Init.OutputFormat = LCDC_OUTPUT_FORMAT_RGB888;
    } else if (LCDC_COLOR_DEPTH == COLOR_DEPTH_32) {
        LCDC_RGBInitStruct.Panel_Init.InputFormat = LCDC_INPUT_FORMAT_ARGB8888;
        LCDC_RGBInitStruct.Panel_Init.OutputFormat = LCDC_OUTPUT_FORMAT_RGB888;
    } else {

    }

    LCDC_RGBInit(LCDC, &LCDC_RGBInitStruct);

    /* configure DMA burst size */
    LCDC_DMABurstSizeConfig(LCDC, 2);
}

AmebaLCDC::AmebaLCDC(bool user_buffer) {
    lcdWidth = LCDC_WIDTH;
    lcdHeight = LCDC_HEIGHT;
    lcdDepth = LCDC_COLOR_DEPTH;
    lcdCB = NULL;
    lcdCBData = NULL;
    lcdCurBuffer = NULL;
    if (user_buffer == true) {
        lcdBuffer0 = NULL;
        lcdBuffer1 = NULL;
    } else {
        lcdBuffer0 = (uint8_t *)malloc(lcdWidth*lcdHeight*lcdDepth/8);
        if (lcdBuffer0 == NULL) {
            while (1) {
                printf("Allocate buffer0 fail!!!");
                delay(5000);
            }
        }
        memset(lcdBuffer0, 0, lcdWidth*lcdHeight*lcdDepth/8);
        lcdBuffer1 = (uint8_t *)malloc(lcdWidth*lcdHeight*lcdDepth/8);
        if (lcdBuffer1 == NULL) {
            while (1) {
                printf("Allocate buffer1 fail!!!");
                delay(5000);
            }
        }
        memset(lcdBuffer1, 0, lcdWidth*lcdHeight*lcdDepth/8);
    }    
    rtos_sema_create(&g_vsync_sem, 0, RTOS_SEMA_MAX_COUNT);
}

AmebaLCDC::~AmebaLCDC() {
    if (g_vsync_sem != NULL) {
        rtos_sema_delete(g_vsync_sem);
    }
	if (lcdBuffer0) {
		free(lcdBuffer0);
        lcdBuffer0 = NULL;
	}
	if (lcdBuffer1) {
		free(lcdBuffer1);
        lcdBuffer1 = NULL;
	}
    lcdWidth = 0;
    lcdHeight = 0;
    lcdDepth = 0;
    lcdCB = NULL;
    lcdCBData = NULL;
    lcdCurBuffer = NULL;
}

void AmebaLCDC::get_info(uint32_t *width, uint32_t *height, uint32_t *depth) {
    *width = lcdWidth;
    *height = lcdHeight;
    *depth = lcdDepth;
}

void AmebaLCDC::begin(AmebaLCDC *instance) {
    gInstance = instance;

    /* config pin info */
    lcdc_pinmux_config();

    /* enable function and clock */
    LCDC_RccEnable();

    /* register irq handler */
    InterruptRegister(lcdc_irq_handler, LCDC_IRQ, NULL, INT_PRI_MIDDLE);
    InterruptEn(LCDC_IRQ, INT_PRI_MIDDLE);

    /* init lcdc driver */
    lcdc_driver_init();

    /* config irq event */
    LCDC_LineINTPosConfig(LCDC, LCDC_LINE_NUM_INTR_DEF);
    LCDC_INTConfig(LCDC, LCDC_BIT_LCD_FRD_INTEN | LCDC_BIT_DMA_UN_INTEN | LCDC_BIT_LCD_LIN_INTEN, ENABLE);

    /* enable lcdc */
    LCDC_Cmd(LCDC, ENABLE);
}

void AmebaLCDC::end() {
    LCDC_DeInit(LCDC);
    gInstance = NULL;
}

void AmebaLCDC::register_callback(lcdc_vblank_cb callback, void * data) {
    lcdCB = callback;
    lcdCBData = data;
}

void AmebaLCDC::set_cur_buffer(uint8_t *buffer) {
    lcdCurBuffer = buffer;
}

lcdc_vblank_cb AmebaLCDC::get_callback(void) {
    return lcdCB;
}

void *AmebaLCDC::get_callback_data(void) {
    return lcdCBData;
}

uint8_t *AmebaLCDC::get_cur_buffer(void) {
    return lcdCurBuffer;
}

uint8_t *AmebaLCDC::get_buffer(int buffer_id) {
    if (buffer_id == 0) {
        return lcdBuffer0;
    } else if (buffer_id == 1) {
        return lcdBuffer1;
    } else {
        return NULL;
    }
}

void AmebaLCDC::inform_render_done(uint8_t *buffer) {
    if ((g_vsync_sem != NULL) && (buffer != NULL)) {
        if (buffer == gInstance->get_buffer(0)) {
            gInstance->set_cur_buffer(gInstance->get_buffer(0));
        } else if (buffer == gInstance->get_buffer(1)) {
            gInstance->set_cur_buffer(gInstance->get_buffer(1));
        } else {
            // User buffer
            gInstance->set_cur_buffer(buffer);
        }
        rtos_sema_give(g_vsync_sem);
    }
}