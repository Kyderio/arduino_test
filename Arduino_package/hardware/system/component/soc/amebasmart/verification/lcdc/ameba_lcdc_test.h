#ifndef _AMEBA_LCDC_TEST_H_
#define _AMEBA_LCDC_TEST_H_

#define LCDC_TEST_CNT    1000

#define LCDC_FPGA_VERIFICATION    0

/* UI related macro */
#define LCDC_UCGUI			0

#define MCU_IF_GUI			0
#define RGB_IF_GUI			1

#define GUI_IF_TYPE			RGB_IF_GUI
#define LCDC_GUI_TYPE		LCDC_UCGUI

/* JPG decode macro*/
#define JPG_DECODER_TEST	0

#define RGB_WHITE			0x00FFFFFF
#define RGB_BLACK			0x00000000
#define RGB_RED 			0x00FF0000
#define RGB_GREEN 			0x0000FF00
#define RGB_BLUE 			0x000000FF
#define RGB_CYAN			0x0000FFFF
#define RGB_MAGENTA			0x00FF00FF
#define RGB_YELLOW			0x00FFFF00
#define RGB_TOMATO			0x00FF6347

#define RGB888_RED_MASK 	0x00FF0000
#define RGB888_GREEN_MASK 	0x0000FF00
#define RGB888_BLUE_MASK 	0x000000FF
#define RGB888_MASK			0x00FFFFFF
#define RGB666_MASK			0x003F3F3F
#define RGB565_MASK			0x0000FFFF
#define RGB555_MASK			0x00007FFF
#define RGB444_MASK			0x00000FFF

#define LCDC_TEST_PIXEL_CMP(x, y) (((x).red == (y).red) && ((x).green == (y).green) && ((x).blue == (y).blue))

#define LCDC_TEST_LAYCTRL_MAX_NUM		((LCDC_LAYER_IMG_FORMAT_ARGB8666 + 1) *2 * 2)
#define LCDC_TEST_GET_IMGFORMAT(x)		((u32)(((x >> 2) & 0x00000FF)))
#define LCDC_TEST_BIT_COLORKEYINGEN		((u32)0x00000001 << 1)
#define LCDC_TEST_BIT_BLENDINGCONFIG	((u32)0x00000001 << 0)

typedef struct {
	u8 blue;
	u8 green;
	u8 red;
	u8 alpha;
} argb8888_t;

typedef struct {
	u8 blue: 6;
	u8 green: 6;
	u8 red: 6;
	u8 alpha;
} argb8666_t;

typedef struct {
	u8 blue;
	u8 green;
	u8 red;
} rgb888_t;

typedef struct {
	u8 blue: 6;
	u8 green: 6;
	u8 red: 6;
} rgb666_t;

typedef struct {
	u16 blue: 5;
	u16 green: 6;
	u16 red: 5;
} rgb565_t;

typedef struct {
	u16 blue: 5;
	u16 green: 5;
	u16 red: 5;
	u16 alpha: 1;
} argb1555_t;

typedef struct {
	u16 blue: 4;
	u16 green: 4;
	u16 red: 4;
	u16 alpha: 4;
} argb4444_t;

/*=========LCDC IRQ Info=========*/
typedef struct LCDC_Irq {
	u32 IrqNum;
	u32 IrqData;
	u32 IrqPriority;
} LCDC_IRQInfo ;



extern LCDC_InitTypeDef LCDC_InitStruct;



#endif
