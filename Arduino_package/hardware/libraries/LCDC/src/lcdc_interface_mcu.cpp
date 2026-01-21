#include "lcdc_interface_mcu.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

LCDC_Interface_MCU::LCDC_Interface_MCU(lcdc_interface_mcu_type *ifMcu) {
    lcdDepth = ifMcu->lcdDepth;
    lcdIfWidth = ifMcu->LCDC_MCUInitStruct.Panel_Init.IfWidth;
    lcdWidth = ifMcu->LCDC_MCUInitStruct.Panel_Init.ImgWidth;
    lcdHeight = ifMcu->LCDC_MCUInitStruct.Panel_Init.ImgHeight;
    lcdInitColor = ifMcu->lcdInitColor;
    lcdCmdSetX = ifMcu->lcdCmdSetX;
    lcdCmdSetY = ifMcu->lcdCmdSetY;
    lcdCmdWRam = ifMcu->lcdCmdWRam;
    lcdGpioCtrl = ifMcu->lcdGpioCtrl;
    lcdInitCtrl = ifMcu->lcdInitCtrl;
    lcdTrMode = ifMcu->lcdTrMode;
    lcdGramType = ifMcu->lcdGramType;

    LCDC_MCUInit(LCDC, &ifMcu->LCDC_MCUInitStruct);
}

void LCDC_Interface_MCU::clear(uint32_t color) {
    uint32_t index = 0;
    uint32_t totalpoint = lcdWidth;
    totalpoint *= lcdHeight;

    /* send cmd and para for (x1,y1) and(x2, y2) */
    setWindow(0, 0, lcdWidth - 1, lcdHeight - 1);

    /* send cmd: write mem */
    writeRamPrepare();

    /* send cmd's parameter: pixel data */
    for (index = 0; index < totalpoint; index++) {
        /* clear screen to white */
        writeRam(color);
    }
}

void LCDC_Interface_MCU::setWindow(uint16_t xStar, uint16_t yStar, uint16_t xEnd, uint16_t yEnd) {
    writeCommand(lcdCmdSetX);
    writeData(xStar >> 8);        //SC[17:8]
    writeData(xStar & 0XFF);        //SC[7:0]
    writeData(xEnd >> 8);            //EC[17:8]
    writeData(xEnd & 0XFF);        //EC[7:0]

    writeCommand(lcdCmdSetY);
    writeData(yStar >> 8);        //SP[17:8]
    writeData(yStar & 0XFF);         //SP[7:0]
    writeData(yEnd >> 8);            //EP[17:8]
    writeData(yEnd & 0XFF);        //EP[8:0]
}

void LCDC_Interface_MCU::initialize() {
    const lcdc_init_ctrl *ic;

    delay(50);

    LCDC_Cmd(LCDC, ENABLE);

    if (lcdInitCtrl != NULL) {
        for (ic = (const lcdc_init_ctrl *)lcdInitCtrl; ((ic->ctrl_type != LCD_CTRL_FUNC_INVALID) && (ic->value != 0xFFFFFFFF)); ic++) {
            switch (ic->ctrl_type) {
                case LCD_CMD:
                    writeCommand((uint8_t)ic->value);
                    break;
                case LCD_DATA:
                    writeData((uint8_t)ic->value);
                    break;
                case LCD_DELAY:
                    delay(ic->value);
                    break;
                default:
                    pin_size_t pin_name = lcdc_gpio_ctrl_get_pin(lcdGpioCtrl, ic->ctrl_type);
                    lcdc_gpio_ctrl(pin_name, ic->value);
                    break;
            }
        }
    }

    /* clear lcd to initial color. */
    // clear(lcdInitColor);

    /* set pre-cmd: write ram */
    LCDC_MCUSetPreCmd(LCDC, &lcdCmdWRam, 1);

    LCDC_Cmd(LCDC, DISABLE);

    Lcdc_McuDmaCfgDef LCDC_MCUDmaCfgStruct;
    LCDC_MCUDmaCfgStruct.TeMode = 0;
    if (lcdTrMode == DMA_AUTO) {
        LCDC_MCUDmaCfgStruct.TriggerDma = LCDC_AUTO_DMA_MODE;
    } else if (lcdTrMode == DMA_TRIGGER) {
        if (lcdGramType == BUILDIN_GRAM) {
            LCDC_MCUDmaCfgStruct.TriggerDma = LCDC_TRIGGER_DMA_MODE;
        } else {
            LCDC_MCUDmaCfgStruct.TriggerDma = LCDC_AUTO_DMA_MODE;
        }
    }
    LCDC_MCUDmaMode(LCDC, &LCDC_MCUDmaCfgStruct);
    LCDC_DMABurstSizeConfig(LCDC, LCDC_DMA_BURSTSIZE_4X64BYTES);
}

void LCDC_Interface_MCU::writeCommand(uint32_t cmd) {
    LCDC_MCUIOWriteCmd(LCDC, cmd);
}

void LCDC_Interface_MCU::writeData(uint32_t data) {
    LCDC_MCUIOWriteData(LCDC, data);
}

uint32_t LCDC_Interface_MCU::readData(void) {
    return LCDC_MCUIOReadData(LCDC);
}

void LCDC_Interface_MCU::writeRamPrepare(void) {
    writeCommand(lcdCmdWRam);
}

void LCDC_Interface_MCU::writeRam(uint32_t color) {
    if (lcdIfWidth == LCDC_MCU_IF_24_BIT) {
        color &= 0x00FFFFFF;//RGB888_MASK;
        writeData(color);

    } else if (lcdIfWidth == LCDC_MCU_IF_16_BIT) {
        color &= 0x0000FFFF;//RGB565_MASK
        writeData(color);

    } else if (lcdIfWidth == LCDC_MCU_IF_8_BIT) {
        color &= 0x00FFFFFF;//RGB888_MASK;
        writeData((color >> 16) & 0xFF);
        writeData((color >> 8) & 0xFF);
        writeData((color) & 0xFF);
    } else {

    }
}

pin_size_t LCDC_Interface_MCU::lcdc_gpio_ctrl_get_pin(const lcdc_gpio_ctrl_config *gpioCtrl, uint32_t type) {
    for (; ((gpioCtrl->pin_name != TOTAL_GPIO_PIN_NUM) && (gpioCtrl->func_name != LCD_CTRL_FUNC_INVALID)); gpioCtrl++) {
        if (gpioCtrl->func_name == type) {
            return gpioCtrl->pin_name;
        }
    }

    return TOTAL_GPIO_PIN_NUM;
}

void LCDC_Interface_MCU::lcdc_gpio_ctrl(pin_size_t pin_name, uint32_t status) {
    uint32_t pin;

    amb_ard_pin_check_fun(pin_name, PIO_GPIO);
    pin = g_APinDescription[pin_name].pinname;
    GPIO_WriteBit(pin, status);
}