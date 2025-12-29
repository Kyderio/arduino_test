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

#ifndef _LCDC_H_
#define _LCDC_H_

#include <Arduino.h>

typedef enum {
    RGB,
    MCU,
} lcdc_interface;

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

typedef struct {
    uint32_t func_name;
    pin_size_t pin_name;
} lcdc_pin_config;

typedef struct {
    uint32_t func_name;
    pin_size_t pin_name;
    PinStatus def_sta;
} lcdc_gpio_ctrl;

typedef void (*lcdc_vblank_cb)(void *data);

typedef enum {
    LCD_BLEN,
    LCD_RESET,
    LCD_DISPLAY,
    LCD_IM0,
    LCD_IM1,
    LCD_IM2,
    LCD_IM3,
    LCD_GPIO_CTRL_FUNC_INVALID,
} lcdc_gpio_ctrl_func;

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
const lcdc_gpio_ctrl gGpioCtrl[] = {

#define LCD_GPIO_CTRL_DEF(func, pin, sta)           \
    {                                               \
        .func_name = func,                          \
        .pin_name = pin,                            \
        .def_sta = sta,                             \
    },

#define LCD_GPIO_CTRL_END                           \
    {                                               \
        .func_name = LCD_GPIO_CTRL_FUNC_INVALID,    \
        .pin_name = TOTAL_GPIO_PIN_NUM,             \
        .def_sta = HIGH,                            \
    },                                              \
};

class AmebaLCDC {
    public:
        AmebaLCDC(bool user_buffer);
        ~AmebaLCDC();
        void begin(AmebaLCDC *instance);
        void end();
        void get_info(uint32_t *width, uint32_t *height, uint32_t *depth);
        void register_callback(lcdc_vblank_cb callback, void *data);
        lcdc_vblank_cb get_callback(void);
        void *get_callback_data(void);
        void set_cur_buffer(uint8_t *buffer);
        uint8_t *get_cur_buffer(void);
        uint8_t *get_buffer(int buffer_id);
        void inform_render_done(uint8_t *buffer);
    private:
        uint32_t lcdWidth;
        uint32_t lcdHeight;
        uint32_t lcdDepth;
        lcdc_vblank_cb lcdCB;
        void *lcdCBData;
        uint8_t *lcdCurBuffer;
        uint8_t *lcdBuffer0;
        uint8_t *lcdBuffer1;
};


#endif
