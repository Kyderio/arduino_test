#ifndef __BSP_MCU_LCD_H
#define __BSP_MCU_LCD_H

#ifndef LCDC_VERIFY_FPGA
#define MCU_IM3_PIN		_PA_31 //_PB_28
#define MCU_IM2_PIN		_PB_0 //_PC_0
#define MCU_IM1_PIN		_PB_3 //_PA_13
#define MCU_IM0_PIN		_PA_27 //_PA_28

#define MCU_RESET_PIN	_PA_22
#else

#define MCU_IM3_PIN		_PA_20
#define MCU_IM2_PIN		_PA_24
#define MCU_IM1_PIN		_PA_26
#define MCU_IM0_PIN		_PA_18

#define MCU_RESET_PIN	_PB_16

#endif

/*0000 8bit, 1100, 9bit, 0001 16bit, 1101 18bit, 0010 24bit */
enum ILI9806_MCU_Parallel {
	ILI9806_MCU_Parallel_8b_0000 = 0,
	ILI9806_MCU_Parallel_9b_1100,
	ILI9806_MCU_Parallel_16b_0001,
	ILI9806_MCU_Parallel_18b_1101,
	ILI9806_MCU_Parallel_24b_0010,
};

void ILI9806_Init(void);
void ILI9806_IFbitmode_Config(u32 BitMode);

#endif