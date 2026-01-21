#include "lcdc_interface.h"
#include "User_Select.h"

#include "lcdc_interface_rgb.h"
#include "lcdc_interface_mcu.h"

void LCDC_Interface::begin(void) {
    lcdc_pinmux_config();
}

void LCDC_Interface::loadUserSelect(lcdc_interface_rgb_type *ifRgb) {
    #if defined(LCDC_INTERFACE) && (LCDC_INTERFACE == RGB)
    ifRgb->lcdDepth = LCDC_COLOR_DEPTH;
    ifRgb->lcdTrMode = LCDC_TRANSFER_MODE;
    ifRgb->lcdGramType = LCDC_GRAM_TYPE;

    LCDC_RGBStructInit(&ifRgb->LCDC_RGBInitStruct);

    ifRgb->LCDC_RGBInitStruct.Panel_Init.IfWidth = LCDC_INTERFACE_WIDTH;
    ifRgb->LCDC_RGBInitStruct.Panel_Init.ImgWidth = LCDC_WIDTH;
    ifRgb->LCDC_RGBInitStruct.Panel_Init.ImgHeight = LCDC_HEIGHT;

    /* set HV para according to lcd spec */
    ifRgb->LCDC_RGBInitStruct.Panel_RgbTiming.RgbVsw = LCDC_RGB_VSW;
    ifRgb->LCDC_RGBInitStruct.Panel_RgbTiming.RgbVbp = LCDC_RGB_VBP;
    ifRgb->LCDC_RGBInitStruct.Panel_RgbTiming.RgbVfp = LCDC_RGB_VFP;

    ifRgb->LCDC_RGBInitStruct.Panel_RgbTiming.RgbHsw = LCDC_RGB_HSW;
    ifRgb->LCDC_RGBInitStruct.Panel_RgbTiming.RgbHbp = LCDC_RGB_HBP;
    ifRgb->LCDC_RGBInitStruct.Panel_RgbTiming.RgbHfp = LCDC_RGB_HFP;

    ifRgb->LCDC_RGBInitStruct.Panel_RgbTiming.Flags.RgbEnPolar = LCDC_RGB_ENABLE_POLAR;
    ifRgb->LCDC_RGBInitStruct.Panel_RgbTiming.Flags.RgbDclkActvEdge = LCDC_RGB_DCLK_ACTIVE_EDGE;
    ifRgb->LCDC_RGBInitStruct.Panel_RgbTiming.Flags.RgbHsPolar = LCDC_RGB_HS_POLAR;
    ifRgb->LCDC_RGBInitStruct.Panel_RgbTiming.Flags.RgbVsPolar = LCDC_RGB_VS_POLAR;

    ifRgb->LCDC_RGBInitStruct.Panel_Init.RGBRefreshFreq = LCDC_RGB_REFRESH_FREQ;
    
    if (LCDC_COLOR_DEPTH == COLOR_DEPTH_16) {
        ifRgb->LCDC_RGBInitStruct.Panel_Init.InputFormat = LCDC_INPUT_FORMAT_RGB565;
        ifRgb->LCDC_RGBInitStruct.Panel_Init.OutputFormat = LCDC_OUTPUT_FORMAT_RGB565;
    } else if (LCDC_COLOR_DEPTH == COLOR_DEPTH_24) {
        ifRgb->LCDC_RGBInitStruct.Panel_Init.InputFormat = LCDC_INPUT_FORMAT_RGB888;
        ifRgb->LCDC_RGBInitStruct.Panel_Init.OutputFormat = LCDC_OUTPUT_FORMAT_RGB888;
    } else if (LCDC_COLOR_DEPTH == COLOR_DEPTH_32) {
        ifRgb->LCDC_RGBInitStruct.Panel_Init.InputFormat = LCDC_INPUT_FORMAT_ARGB8888;
        ifRgb->LCDC_RGBInitStruct.Panel_Init.OutputFormat = LCDC_OUTPUT_FORMAT_RGB888;
    } else {

    }
    #endif
}

void LCDC_Interface::loadUserSelect(lcdc_interface_mcu_type *ifMcu) {
    #if defined(LCDC_INTERFACE) && (LCDC_INTERFACE == MCU)
    ifMcu->lcdDepth = LCDC_COLOR_DEPTH;
    ifMcu->lcdCmdSetX = LCDC_CMD_SETX;
    ifMcu->lcdCmdSetY = LCDC_CMD_SETY;
    ifMcu->lcdCmdWRam = LCDC_CMD_WRAM;
    ifMcu->lcdTrMode = LCDC_TRANSFER_MODE;
    ifMcu->lcdGramType = LCDC_GRAM_TYPE;
    ifMcu->lcdInitColor = LCDC_INIT_COLOR;
    #if defined(LCD_GPIO_CTRL_DEF_EXIST) && (LCD_GPIO_CTRL_DEF_EXIST == 1)
    ifMcu->lcdGpioCtrl = (const lcdc_gpio_ctrl_config *)gGpioCtrl;
    #else
    ifMcu->lcdGpioCtrl = NULL;
    #endif
    #if defined(LCD_INIT_CTRL_DEF_EXIST) && (LCD_INIT_CTRL_DEF_EXIST == 1)
    ifMcu->lcdInitCtrl = (const lcdc_init_ctrl *)gInitCtrl;
    #else
    ifMcu->lcdInitCtrl = NULL;
    #endif

    LCDC_MCUStructInit(&ifMcu->LCDC_MCUInitStruct);

    ifMcu->LCDC_MCUInitStruct.Panel_Init.IfWidth = LCDC_INTERFACE_WIDTH;
    if (LCDC_DISPLAY_DIR == DISPLAY_R180) {
        ifMcu->LCDC_MCUInitStruct.Panel_Init.ImgWidth = LCDC_HEIGHT;
        ifMcu->LCDC_MCUInitStruct.Panel_Init.ImgHeight = LCDC_WIDTH;
    } else {
        ifMcu->LCDC_MCUInitStruct.Panel_Init.ImgWidth = LCDC_WIDTH;
        ifMcu->LCDC_MCUInitStruct.Panel_Init.ImgHeight = LCDC_HEIGHT;
    }

    ifMcu->LCDC_MCUInitStruct.Panel_McuTiming.McuRdPolar = LCDC_MCU_RD_POLAR;
    ifMcu->LCDC_MCUInitStruct.Panel_McuTiming.McuWrPolar = LCDC_MCU_WR_POLAR;
    ifMcu->LCDC_MCUInitStruct.Panel_McuTiming.McuRsPolar = LCDC_MCU_RS_POLAR;
    ifMcu->LCDC_MCUInitStruct.Panel_McuTiming.McuTePolar = LCDC_MCU_TE_POLAR;  /* workaround for G2 a-cut MCU-TE irq issue */
    ifMcu->LCDC_MCUInitStruct.Panel_McuTiming.McuSyncPolar = LCDC_MCU_VSYNC_POLAR;
    
    if (LCDC_COLOR_DEPTH == COLOR_DEPTH_16) {
        ifMcu->LCDC_MCUInitStruct.Panel_Init.InputFormat = LCDC_INPUT_FORMAT_RGB565;
        ifMcu->LCDC_MCUInitStruct.Panel_Init.OutputFormat = LCDC_OUTPUT_FORMAT_RGB565;
    } else if (LCDC_COLOR_DEPTH == COLOR_DEPTH_24) {
        ifMcu->LCDC_MCUInitStruct.Panel_Init.InputFormat = LCDC_INPUT_FORMAT_RGB888;
        ifMcu->LCDC_MCUInitStruct.Panel_Init.OutputFormat = LCDC_OUTPUT_FORMAT_RGB888;
    } else if (LCDC_COLOR_DEPTH == COLOR_DEPTH_32) {
        ifMcu->LCDC_MCUInitStruct.Panel_Init.InputFormat = LCDC_INPUT_FORMAT_ARGB8888;
        ifMcu->LCDC_MCUInitStruct.Panel_Init.OutputFormat = LCDC_OUTPUT_FORMAT_RGB888;
    } else {

    }
    #endif
}

LCDC_Interface * LCDC_Interface::createInstance() {
    LCDC_Interface *ptr = NULL;

    #if defined(LCDC_INTERFACE) && (LCDC_INTERFACE == RGB)
    lcdc_interface_rgb_type ifRgb;
    loadUserSelect(&ifRgb);
    ptr = new LCDC_Interface_RGB(&ifRgb);
    #elif defined(LCDC_INTERFACE) && (LCDC_INTERFACE == MCU)
    lcdc_interface_mcu_type ifMcu;
    loadUserSelect(&ifMcu);
    ptr = new LCDC_Interface_MCU(&ifMcu);
    #else
    
    #endif

    return ptr;
}

lcdc_transfer_mode LCDC_Interface::getTrMode() {
    return LCDC_TRANSFER_MODE;
}

lcdc_gram_type LCDC_Interface::getGramType() {
    return LCDC_GRAM_TYPE;
}

void LCDC_Interface::lcdc_pinmux_config() {
    uint32_t pin;

    #if defined(LCD_PIN_DEF_EXIST) && (LCD_PIN_DEF_EXIST == 1)
    for (lcdcPc = (const lcdc_pin_config *)gPinCfg; ((lcdcPc->pin_name != TOTAL_GPIO_PIN_NUM) && (lcdcPc->func_name != 0xFFFFFFFF)); lcdcPc++) {
        amb_ard_pin_check_fun(lcdcPc->pin_name, PIO_LCDC);

        pin = g_APinDescription[lcdcPc->pin_name].pinname;
        Pinmux_Config(pin, lcdcPc->func_name);
    }
    #endif

    #if defined(LCD_GPIO_CTRL_DEF_EXIST) && (LCD_GPIO_CTRL_DEF_EXIST == 1)
    for (lcdcGc = (const lcdc_gpio_ctrl_config *)gGpioCtrl; ((lcdcGc->pin_name != TOTAL_GPIO_PIN_NUM) && (lcdcGc->func_name != LCD_CTRL_FUNC_INVALID)); lcdcGc++) {
        amb_ard_pin_check_fun(lcdcGc->pin_name, PIO_GPIO);

        pin = g_APinDescription[lcdcGc->pin_name].pinname;
        GPIO_InitTypeDef gpioOther;
        gpioOther.GPIO_Pin = pin;
        gpioOther.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_Init(&gpioOther);
        GPIO_WriteBit(pin, lcdcGc->def_sta);
    }
    #endif
}