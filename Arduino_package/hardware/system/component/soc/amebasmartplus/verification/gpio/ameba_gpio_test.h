#ifndef _AMEBA_GPIO_TEST_H_
#define _AMEBA_GPIO_TEST_H_

typedef struct {
	GPIO_TypeDef *GPIOx;
	IRQn_Type IrqNum;
} GPIO_DevTable;

typedef enum _GPIO_TEST_INT_TYPE_ {
	GPIO_TEST_INT_EDGE_RISING = 0,
	GPIO_TEST_INT_EDGE_FALLING,
	GPIO_TEST_INT_EDGE_BOTH,
	GPIO_TEST_INT_LEVEL_HIGH,
	GPIO_TEST_INT_LEVEL_LOW,

	GPIO_TEST_INT_MAX,
} GPIO_TEST_INT_TYPE, *PGPIO_TEST_INT_TYPE;

typedef enum _PAD_TEST_TYPE_ {
	PAD_EST_NORMAL_NOPULL = 0,
	PAD_EST_NORMAL_PU,
	PAD_EST_NORMAL_PD,
	PAD_EST_SLEEP_NOPULL,
	PAD_EST_SLEEP_PU,
	PAD_EST_SLEEP_PD,

	PAD_TEST_TYPE_MAX,
} PAD_TEST_TYPE, *PPAD_TEST_TYPE;

#define GPIO_PINNAME(PORT, PIN)			(((PORT) << 5) | ((PIN) & 0x1F))

#if 1
void GPIO_SetDWWrapper(u32 Option);
u32 GPIO_GetDWWrapper(void);

#define GPIO_DR_DDR_FUNC_DW			0x0
#define GPIO_DR_DDR_FUNC_WRAP		0x1

/* ECO register and bit definition, control the three ports of PA/PB/PC */
#define GPIO_REG_COM_OPT				(0x4200DC78)
#define GPIO_BIT_CTRL_DW_WRAPPER		(BIT0) /* default 0, which use dw-function; set 1 to enable wrapper function. Note:eco enable */

#endif

#endif
