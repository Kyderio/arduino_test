#include "lcdc_interface_rgb.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

LCDC_Interface_RGB::LCDC_Interface_RGB(lcdc_interface_rgb_type *ifRgb) {
    lcdDepth = ifRgb->lcdDepth;
    lcdIfWidth = ifRgb->LCDC_RGBInitStruct.Panel_Init.IfWidth;
    lcdWidth = ifRgb->LCDC_RGBInitStruct.Panel_Init.ImgWidth;
    lcdHeight = ifRgb->LCDC_RGBInitStruct.Panel_Init.ImgHeight;
    lcdTrMode = ifRgb->lcdTrMode;
    lcdGramType = ifRgb->lcdGramType;

    LCDC_RGBInit(LCDC, &ifRgb->LCDC_RGBInitStruct);
}

void LCDC_Interface_RGB::initialize() {
    LCDC_Cmd(LCDC, DISABLE);

    uint32_t DmaModeCfg = LCDC->LCDC_DMA_MODE_CFG;
    /* clear te mode to avoid hang when config with none-te sync mode */
    DmaModeCfg &= ~LCDC_BIT_DMA_TE_MODE;
    if (lcdTrMode == DMA_AUTO) {
        /* auto dma mode */
        DmaModeCfg &= ~LCDC_BIT_DMA_TRIGER_MODE;
    } else if (lcdTrMode == DMA_TRIGGER) {
        if (lcdGramType == BUILDIN_GRAM) {
            /* trigger dma mode */
            DmaModeCfg |= LCDC_BIT_DMA_TRIGER_MODE;
        } else {
            /* auto dma mode */
            DmaModeCfg &= ~LCDC_BIT_DMA_TRIGER_MODE;
        }
    }
    /* write the value configured back to registers */
    LCDC->LCDC_DMA_MODE_CFG = DmaModeCfg;

    LCDC_DMABurstSizeConfig(LCDC, LCDC_DMA_BURSTSIZE_4X64BYTES);
}