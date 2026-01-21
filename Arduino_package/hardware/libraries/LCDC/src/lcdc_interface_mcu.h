#ifndef LCDC_INTERFACE_MCU_H
#define LCDC_INTERFACE_MCU_H

#include "lcdc_interface.h"

class LCDC_Interface_MCU : public LCDC_Interface {
private:

public:
    LCDC_Interface_MCU(lcdc_interface_mcu_type *ifMcu);
    void getInfo(uint32_t *width, uint32_t *height, uint32_t *depth) override {
        *width = lcdWidth;
        *height = lcdHeight;
        *depth = lcdDepth;
    }
    void clear(uint32_t color) override;
    void setWindow(uint16_t xStar, uint16_t yStar, uint16_t xEnd, uint16_t yEnd) override;

protected:
    void initialize() override;
    void writeCommand(uint32_t cmd) override;
    void writeData(uint32_t data) override;
    uint32_t readData(void) override;
    void writeRamPrepare(void) override;
    void writeRam(uint32_t color) override;

private:
    uint32_t lcdWidth;
    uint32_t lcdHeight;
    uint32_t lcdDepth;
    uint32_t lcdIfWidth;
    lcdc_color_type lcdInitColor;
    uint8_t lcdCmdSetX;
    uint8_t lcdCmdSetY;
    uint8_t lcdCmdWRam;
    const lcdc_gpio_ctrl_config *lcdGpioCtrl;
    const lcdc_init_ctrl *lcdInitCtrl;
    lcdc_transfer_mode lcdTrMode;
    lcdc_gram_type lcdGramType;

    pin_size_t lcdc_gpio_ctrl_get_pin(const lcdc_gpio_ctrl_config *gpioCtrl, uint32_t type);
    void lcdc_gpio_ctrl(pin_size_t pin_name, uint32_t status);
};

#endif