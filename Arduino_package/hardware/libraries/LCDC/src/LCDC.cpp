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

#ifdef __cplusplus
extern "C" {
#endif

#include "ameba_soc.h"

#ifdef __cplusplus
}
#endif

AmebaLCDC *gInstance = NULL;
static rtos_sema_t g_vsync_sem = NULL;

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
        // printf("Frame done!\r\n");
        if ((cb = gInstance->get_callback()) != NULL) {
            cbData = gInstance->get_callback_data();
            cb(cbData);
        }
    }

    if (IntId & LCDC_BIT_LCD_LIN_INTS) {
        // printf("Line hit!\r\n");
        if (gInstance != NULL) {
            lcdc_transfer_mode trMode = gInstance->lcdIf->getTrMode();
            lcdc_gram_type gramType = gInstance->lcdIf->getGramType();
            if ((trMode == DMA_AUTO)
                || ((trMode == DMA_TRIGGER) && (gramType == NO_BUILDIN_GRAM))) {
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
    }

    if (IntId & LCDC_BIT_DMA_UN_INTS) {
        // printf("DMA udf!\r\n")
    }

    return 0;
}

AmebaLCDC::AmebaLCDC(bool user_buffer) {
    /* enable function and clock */
    LCDC_RccEnable();
    LCDC_Cmd(LCDC, DISABLE);

    lcdIf = LCDC_Interface::createInstance();
    if (lcdIf != NULL) {
        lcdIf->getInfo(&lcdWidth, &lcdHeight, &lcdDepth);
    
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
    if (lcdIf) {
        delete lcdIf;
        lcdIf = NULL;
    }
    lcdWidth = 0;
    lcdHeight = 0;
    lcdDepth = 0;
    lcdCB = NULL;
    lcdCBData = NULL;
    lcdCurBuffer = NULL;
    lcdIf = NULL;
}

void AmebaLCDC::get_info(uint32_t *width, uint32_t *height, uint32_t *depth) {
    *width = lcdWidth;
    *height = lcdHeight;
    *depth = lcdDepth;
}

void AmebaLCDC::begin(AmebaLCDC *instance) {
    gInstance = instance;

    if (lcdIf != NULL) {
        /* register irq handler */
        InterruptRegister(lcdc_irq_handler, LCDC_IRQ, NULL, INT_PRI_MIDDLE);
        InterruptEn(LCDC_IRQ, INT_PRI_MIDDLE);

        /* init lcdc driver */
        lcdIf->begin();
        lcdIf->initialize();

        /* config irq event */
        if ((lcdIf->getTrMode() == DMA_AUTO) 
            || ((lcdIf->getTrMode() == DMA_TRIGGER) && (lcdIf->getGramType() == NO_BUILDIN_GRAM))) {
            LCDC_LineINTPosConfig(LCDC, lcdHeight/2);
            LCDC_INTConfig(LCDC, LCDC_BIT_LCD_FRD_INTEN | LCDC_BIT_DMA_UN_INTEN | LCDC_BIT_LCD_LIN_INTEN, ENABLE);
        }
        
        /* enable lcdc */
        LCDC_Cmd(LCDC, ENABLE);
    }
}

void AmebaLCDC::end() {
    LCDC_DeInit(LCDC);
    gInstance = NULL;
}

/**
  * @brief  Register vblank callback if you need to be informed when a frame is displayed done.
  * @param  callback: vblank callback function.
  * @param  data: pointer to callback function's parameter.
  * @retval None
  */
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
    if (buffer != NULL) {
        if (buffer == gInstance->get_buffer(0)) {
            gInstance->set_cur_buffer(gInstance->get_buffer(0));
        } else if (buffer == gInstance->get_buffer(1)) {
            gInstance->set_cur_buffer(gInstance->get_buffer(1));
        } else {
            // User buffer
            gInstance->set_cur_buffer(buffer);
        }

        lcdc_transfer_mode trMode = gInstance->lcdIf->getTrMode();
        lcdc_gram_type gramType = gInstance->lcdIf->getGramType();
        if (trMode == DMA_AUTO) {
            if (g_vsync_sem != NULL) {
                rtos_sema_give(g_vsync_sem);
            }
        } else if (trMode == DMA_TRIGGER) {
            if (gramType == NO_BUILDIN_GRAM) {
                if (g_vsync_sem != NULL) {
                    rtos_sema_give(g_vsync_sem);
                }
            } else {
                LCDC_DMAImgCfg(LCDC, (uint32_t)gInstance->get_cur_buffer());
                LCDC_MCUDMATrigger(LCDC);
            }
        } else {

        }
    }
}

void AmebaLCDC::clear(uint32_t color) {
    lcdIf->clear(color);
}

void AmebaLCDC::setWindow(uint16_t xStar, uint16_t yStar, uint16_t xEnd, uint16_t yEnd) {
    lcdIf->setWindow(xStar, yStar, xEnd, yEnd);
}