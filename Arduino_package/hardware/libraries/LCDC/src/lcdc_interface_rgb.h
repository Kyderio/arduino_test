#ifndef LCDC_INTERFACE_RGB_H
#define LCDC_INTERFACE_RGB_H

#include "lcdc_interface.h"

class LCDC_Interface_RGB : public LCDC_Interface {
private:

public:
    LCDC_Interface_RGB(lcdc_interface_rgb_type *ifRgb);
    void getInfo(uint32_t *width, uint32_t *height, uint32_t *depth) override {
        *width = lcdWidth;
        *height = lcdHeight;
        *depth = lcdDepth;
    }

    void clear(uint32_t color) override {}
    void setWindow(uint16_t xStar, uint16_t yStar, uint16_t xEnd, uint16_t yEnd) override {}
protected:
    void initialize() override;
    void writeCommand(uint32_t cmd) override {}
    void writeData(uint32_t data) override {}
    uint32_t readData(void) override {}
    void writeRamPrepare(void) override {}
    void writeRam(uint32_t color) override {}

private:
    uint32_t lcdWidth;
    uint32_t lcdHeight;
    uint32_t lcdDepth;
    uint32_t lcdIfWidth;
    const lcdc_init_ctrl *lcdInitCtrl;
    lcdc_transfer_mode lcdTrMode;
    lcdc_gram_type lcdGramType;
};

#endif