#ifndef LCDC_INTERFACE_H
#define LCDC_INTERFACE_H

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "ameba_soc.h"

#ifdef __cplusplus
}
#endif

#define RGB 0
#define MCU 1

typedef enum {
    DISPLAY_ORI,
    DISPLAY_R180,
} lcdc_display_dir_type;

typedef enum {
    RGB888_WHITE = 0x00FFFFFF,
    RGB888_RED = 0x00FF0000,
    RGB888_GREEN = 0x0000FF00,
    RGB888_BLUE = 0x000000FF,
} lcdc_color_type;

typedef enum {
    WIDTH_6_BITS,
    WIDTH_8_BITS,
    WIDTH_16_BITS,
    WIDTH_24_BITS,
} lcdc_interface_width;

typedef enum {
    COLOR_DEPTH_16 = 16,
    COLOR_DEPTH_24 = 24,
    COLOR_DEPTH_32 = 32,
} lcdc_color_depth;

typedef enum {
    LCD_CMD, 
    LCD_DATA,
    LCD_DELAY,
    // LCD_FLOW_CTRL_FUNC_NUM,
    LCD_BLEN,
    LCD_RESET,
    LCD_DISPLAY,
    LCD_IM0,
    LCD_IM1,
    LCD_IM2,
    LCD_IM3,
    // LCD_GPIO_CTRL_FUNC_NUM,
    LCD_CTRL_FUNC_INVALID,
} lcdc_ctrl_func;

typedef enum {
    DMA_AUTO,
    DMA_TRIGGER,
} lcdc_transfer_mode;

typedef enum {
    NO_BUILDIN_GRAM,
    BUILDIN_GRAM
} lcdc_gram_type;

typedef struct {
    uint32_t func_name;
    pin_size_t pin_name;
} lcdc_pin_config;

typedef struct {
    uint32_t func_name;
    pin_size_t pin_name;
    PinStatus def_sta;
} lcdc_gpio_ctrl_config;

typedef struct {
    uint32_t ctrl_type;
    uint32_t value;
} lcdc_init_ctrl;

typedef struct {
    LCDC_RGBInitTypeDef LCDC_RGBInitStruct;
    uint32_t lcdDepth;
    lcdc_transfer_mode lcdTrMode;
    lcdc_gram_type lcdGramType;
} lcdc_interface_rgb_type;

typedef struct {
    LCDC_MCUInitTypeDef LCDC_MCUInitStruct;
    uint32_t lcdDepth;
    lcdc_display_dir_type lcdDir;
    lcdc_color_type lcdInitColor;
    uint8_t lcdCmdSetX;
    uint8_t lcdCmdSetY;
    uint8_t lcdCmdWRam;
    const lcdc_gpio_ctrl_config *lcdGpioCtrl;
    const lcdc_init_ctrl *lcdInitCtrl;
    lcdc_transfer_mode lcdTrMode;
    lcdc_gram_type lcdGramType;
} lcdc_interface_mcu_type;

#define LCD_PIN_DEF_START                           \
const lcdc_pin_config gPinCfg[] = {

#define LCD_PIN_DEF(func, pin)                      \
    {                                               \
        .func_name = PINMUX_FUNCTION_##func,        \
        .pin_name = pin,                            \
    },

#define LCD_PIN_DEF_END                             \
    {                                               \
        .func_name = 0xFFFFFFFF,                    \
        .pin_name = TOTAL_GPIO_PIN_NUM,             \
    },                                              \
};

#define LCD_GPIO_CTRL_START                         \
const lcdc_gpio_ctrl_config gGpioCtrl[] = {

#define LCD_GPIO_CTRL_DEF(func, pin, sta)           \
    {                                               \
        .func_name = func,                          \
        .pin_name = pin,                            \
        .def_sta = sta,                             \
    },

#define LCD_GPIO_CTRL_END                           \
    {                                               \
        .func_name = LCD_CTRL_FUNC_INVALID,         \
        .pin_name = TOTAL_GPIO_PIN_NUM,             \
        .def_sta = HIGH,                            \
    },                                              \
};

#define LCD_INIT_CTRL_START                         \
const lcdc_init_ctrl gInitCtrl[] = {

#define LCD_INIT_CTRL_DEF(type, val)                \
    {                                               \
        .ctrl_type = type,                          \
        .value = val,                             \
    },

#define LCD_INIT_CTRL_END                           \
    {                                               \
        .ctrl_type = LCD_CTRL_FUNC_INVALID,         \
        .value = 0xFFFFFFFF,                        \
    },                                              \
};

class LCDC_Interface {
public:
    virtual ~LCDC_Interface() {}
    void begin();
    virtual void initialize() = 0;
    virtual void getInfo(uint32_t *width, uint32_t *height, uint32_t *depth) = 0;
    virtual void clear(uint32_t color) = 0;
    virtual void setWindow(uint16_t xStar, uint16_t yStar, uint16_t xEnd, uint16_t yEnd) = 0;

    static LCDC_Interface *createInstance();
    lcdc_transfer_mode getTrMode();
    lcdc_gram_type getGramType();
protected:
    virtual void writeCommand(uint32_t cmd) = 0;
    virtual void writeData(uint32_t data) = 0;
    virtual uint32_t readData(void) = 0;
    virtual void writeRamPrepare(void) = 0;
    virtual void writeRam(uint32_t color) = 0;

    void lcdc_pinmux_config();
    const lcdc_pin_config *lcdcPc;
    const lcdc_gpio_ctrl_config *lcdcGc;
    const lcdc_init_ctrl *lcdcIc;

private:
    static void loadUserSelect(lcdc_interface_rgb_type *ifRgb);
    static void loadUserSelect(lcdc_interface_mcu_type *ifMcu);
};

#endif