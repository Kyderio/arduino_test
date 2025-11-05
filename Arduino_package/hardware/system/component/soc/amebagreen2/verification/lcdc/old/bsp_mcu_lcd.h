#ifndef __BSP_MCU_LCD_H
#define __BSP_MCU_LCD_H

#define MCU_LCD_8BIT_IF		(0)
#define MCU_LCD_16BIT_IF	(1)
#define MCU_LCD_24BIT_IF	(2)
// #define LCM_ILI9341			(0)
// #define LCM_ILI9488			(1)

#define MCULCDBitMode		MCU_LCD_8BIT_IF
#define LCD_MODULE			LCM_ILI9806

#if (LCD_MODULE == LCM_ILI9806)
#define LCD_WIDTH			480
#define LCD_HEIGHT			800
#define LCD_INITIALIZE		ILI9806_Init

#elif (LCD_MODULE == LCM_ILI9488)
// #define LCD_WIDTH			320
// #define LCD_HEIGHT			480
// #define LCD_INITIALIZE		ILI9488_Init

#endif

/*0000 8bit, 1100, 9bit, 0001 16bit, 1101 18bit, 0010 24bit */
enum ILI9806_MCU_Parallel {
	ILI9806_MCU_Parallel_8b_0000 = 0,
	ILI9806_MCU_Parallel_9b_1100,
	ILI9806_MCU_Parallel_16b_0001,
	ILI9806_MCU_Parallel_18b_1101,
	ILI9806_MCU_Parallel_24b_0010,
};

typedef struct {
	u16 width;
	u16 height;
	u16 id;
	u8  dir;
	u16	wramcmd;
	u16 setxcmd;
	u16  setycmd;
	volatile u32 McuLcdBitMode;
} _lcd_dev;

extern _lcd_dev lcddev;

#define WHITE			0xFFFF
#define CLEAR_WHITE_8BIT			0xFF

#endif