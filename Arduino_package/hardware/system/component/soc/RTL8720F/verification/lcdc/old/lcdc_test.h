#ifndef _LCDC_TEST_H_
#define _LCDC_TEST_H_

#define LCDC_TEST_DISPLAY_RGB	1
#define LCDC_TEST_DISPLAY_SRGB	0
#define LCDC_TEST_DISPLAY_MCU	0

#define RGB888_RED_MASK 	0x00FF0000
#define RGB888_GREEN_MASK 	0x0000FF00
#define RGB888_BLUE_MASK 	0x000000FF
#define RGB888_MASK			0x00FFFFFF
#define RGB666_MASK			0x003F3F3F
#define RGB565_MASK			0x0000FFFF
#define RGB555_MASK			0x00007FFF

#define FRAME_BUF_BYTE_MASK	0xFF
#define RGB888_WHITE		0x00FFFFFF

// #define LCDC_TEST_CNT    1000

// #define MCU_IF_GUI			0
// #define RGB_IF_GUI			1


#define LCD_BLEN_SRGB	_PA_31
#define LCD_BLEN_RGB	_PA_31
#define LCD_BLEN_MCU	_PB_2

extern u32 fps_srgb;
extern u32 pix_srgb;


extern void LcdcDumpRegValue(void);

#endif
