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
#include "lcdc_interface.h"

typedef void (*lcdc_vblank_cb)(void *data);

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
        LCDC_Interface* lcdIf = NULL;
        void clear(uint32_t color);
        void setWindow(uint16_t xStar, uint16_t yStar, uint16_t xEnd, uint16_t yEnd);
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
