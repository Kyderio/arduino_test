#ifndef __BSP_MCU_LCD_CMN_H
#define __BSP_MCU_LCD_CMN_H

#define MCU_LCD_8BIT_IF		(0)
#define MCU_LCD_16BIT_IF	(1)
#define MCU_LCD_24BIT_IF	(2)

#define LCM_ILI9806			(1)
#define LCD_MODULE			LCM_ILI9806

#if defined(LCD_MODULE) && (LCD_MODULE == LCM_ILI9806)
#define LCD_WIDTH			480
#define LCD_HEIGHT			800
#define LCD_INITIALIZE		ILI9806_Init

#endif




typedef struct {
	u16 width;
	u16 height;
	// u16 id;
	u32 id;//aa
	u8  dir;
	u16	wramcmd;
	u16 setxcmd;
	u16  setycmd;
	volatile u32 McuLcdBitMode;
} _lcd_dev;

extern _lcd_dev lcddev;


void LCD_Display_Dir(u8 dir);
void LCD_WriteRAM_Prepare(void);
void LCD_WriteRAM(u32 RGB_Code);
void LCD_SetWindow(u16 xStar, u16 yStar, u16 xEnd, u16 yEnd);
void LCD_Clear(u32 color);

void LCD_WR_REG(u32 data);
void LCD_WR_DATAX(u32 data);

// #define WHITE			0xFFFFFF//0xFFFF
// #define CLEAR_WHITE_8BIT			0xFF

#endif