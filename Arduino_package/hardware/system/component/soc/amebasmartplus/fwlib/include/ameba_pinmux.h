/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _AMEBA_PINMUX_H_
#define _AMEBA_PINMUX_H_

/** @addtogroup Ameba_Periph_Driver
 * @{
 */

/** @verbatim
 *****************************************************************************************
* Introduction
*****************************************************************************************
*		-Every GPIO pin can be set to some function based on pinmux spec.
*		-Every GPIO pin can set internal pull-up, pull-down based on pinmux spec.
*
*====================================================================
* Pad Control Spec.
*====================================================================
*		-[31:18]		reserved
*		-[17]			pull down resistor enable when system is in sleep
*		-[16]			pull up resistor enable when system is in sleep
*		-[13]			srew rate control
*		-[12]			schmitt trigger enable
*		-[11]			pad driving strength
*		-[10]			pull resistor selection
*		-[9]			pull down resistor enable when system is in active
*		-[8]			pull up resistor enable when system is in active
*		-[7:5]			reserved for function id extend
*		-[4:0]			function id
*
*****************************************************************************************
* How to use Pinmux
*****************************************************************************************
*		1. Set the Internal pad function type for  each pin using the follwoing function:
*			Pinmux_Config(u8 PinName, u32 PinFunc)
*
*		2. Set the Internal pad pull type for each pin using the follwoing function:
*			PAD_PullCtrl(u8 PinName, u8 PullType)
*			PAD_SleepPullCtrl(u8 PinName, u8 PullType);
*
*****************************************************************************************
* @endverbatim
*/

/** @defgroup PIN
 * @brief PIN driver modules
 * @{
 */


/** @defgroup PINMUX
 * @brief PINMUX driver modules
 * @{
 */

/* Exported constants --------------------------------------------------------*/

/** @defgroup PINMUX_Exported_Constants PINMUX Exported Constants
  * @{
  */

/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/** @defgroup PINMUX_Pin_Name_definitions
  * @note: Pin_Name = (((port)<<5)|(pin))
  * @{
  */
#define _PA_0           (0x00)  //0x0
#define _PA_1           (0x01)  //0x4
#define _PA_2           (0x02)  //0x8
#define _PA_3           (0x03)  //0xC
#define _PA_4           (0x04)  //0x10
#define _PA_5           (0x05)  //0x14
#define _PA_6           (0x06)  //0x18
#define _PA_7           (0x07)  //0x1C
#define _PA_8           (0x08)  //0x20
#define _PA_9           (0x09)  //0x24
#define _PA_10          (0x0A)  //0x28
#define _PA_11          (0x0B)  //0x2C
#define _PA_12          (0x0C)  //0x30
#define _PA_13          (0x0D)  //0x34
#define _PA_14          (0x0E)  //0x38
#define _PA_15          (0x0F)  //0x3C
#define _PA_16          (0x10)  //0x40
#define _PA_17          (0x11)  //0x44
#define _PA_18          (0x12)  //0x48
#define _PA_19          (0x13)  //0x4C
#define _PA_20          (0x14)  //0x50
#define _PA_21          (0x15)  //0x54
#define _PA_22          (0x16)  //0x58
#define _PA_23          (0x17)  //0x5C
#define _PA_24          (0x18)  //0x60
#define _PA_25          (0x19)  //0x64
#define _PA_26          (0x1A)  //0x68
#define _PA_27          (0x1B)  //0x6C
#define _PA_28          (0x1C)  //0x70
#define _PA_29          (0x1D)  //0x74
#define _PA_30          (0x1E)  //0x78
#define _PA_31          (0x1F)  //0x7C

#define _PB_0           (0x20)  //0x80
#define _PB_1           (0x21)  //0x84
#define _PB_2           (0x22)  //0x88
#define _PB_3           (0x23)  //0x8C
#define _PB_4           (0x24)  //0x90
#define _PB_5           (0x25)  //0x94
#define _PB_6           (0x26)  //0x98
#define _PB_7           (0x27)  //0x9C
#define _PB_8           (0x28)  //0xA0
#define _PB_9           (0x29)  //0xA4
#define _PB_10          (0x2A)  //0xA8
#define _PB_11          (0x2B)  //0xAC
#define _PB_12          (0x2C)  //0xB0
#define _PB_13          (0x2D)  //0xB4
#define _PB_14          (0x2E)  //0xB8
#define _PB_15          (0x2F)  //0xBC
#define _PB_16          (0x30)  //0xC0
#define _PB_17          (0x31)  //0xC4
#define _PB_18          (0x32)  //0xC8
#define _PB_19          (0x33)  //0xCC
#define _PB_20          (0x34)  //0xD0
#define _PB_21          (0x35)  //0xD4
#define _PB_22          (0x36)  //0xD8
#define _PB_23          (0x37)  //0xDC
#define _PB_24          (0x38)  //0xE0
#define _PB_25          (0x39)  //0xE4
#define _PB_26          (0x3A)  //0xE8
#define _PB_27          (0x3B)  //0xEC
#define _PB_28          (0x3C)  //0xF0
#define _PB_29          (0x3D)  //0xF4
#define _PB_30          (0x3E)  //0xF8
#define _PB_31          (0x3F)  //0xFC

#define _PC_0           (0x40)  //0x100
#define _PC_1           (0x41)  //0x104
#define _PC_2           (0x42)  //0x108
#define _PC_3           (0x43)  //0x10C
#define _PC_4           (0x44)  //0x110
#define _PC_5           (0x45)  //0x114
#define _PC_6           (0x46)  //0x118
#define _PC_7           (0x47)  //0x11C
#define _PC_8           (0x48)  //0x120
#define _PC_9           (0x49)  //0x124
#define _PC_10          (0x4A)  //0x128
#define _PC_11          (0x4B)  //0x12C
#define _PC_12          (0x4C)  //0x130
#define _PC_13          (0x4D)  //0x134

#define _PNC           (0xFFFF)
#define PIN_TOTAL_NUM  (0x4E)
/** @} */

/** @defgroup PINMUX_Function_definitions
  * @{
  */
#define PINMUX_FUNCTION_GPIO                0
#define PINMUX_FUNCTION_LOG_UART            1
#define PINMUX_FUNCTION_SPI                 2
#define PINMUX_FUNCTION_SPI_FLASH           3
#define PINMUX_FUNCTION_SDIO                4
#define PINMUX_FUNCTION_SWD                 5
#define PINMUX_FUNCTION_AUDIO               6
#define PINMUX_FUNCTION_CTC_ADC             7
#define PINMUX_FUNCTION_SIC                 8
#define PINMUX_FUNCTION_I2S2_DATA           9
#define PINMUX_FUNCTION_I2S2_CLK            10
#define PINMUX_FUNCTION_I2S3_DATA           11
#define PINMUX_FUNCTION_I2S3_CLK            12
#define PINMUX_FUNCTION_MIPI                13
#define PINMUX_FUNCTION_USB                 14
#define PINMUX_FUNCTION_ZB_UART             15
#define PINMUX_FUNCTION_BT_UART             16
#define PINMUX_FUNCTION_BT_GPIO             17
#define PINMUX_FUNCTION_DEBUG_PORT          18
#define PINMUX_FUNCTION_UART_LOG_RXD        32
#define PINMUX_FUNCTION_UART_LOG_TXD        33
#define PINMUX_FUNCTION_SICK                34
#define PINMUX_FUNCTION_SIDD                35
#define PINMUX_FUNCTION_SWD_CLK             36
#define PINMUX_FUNCTION_SWD_DATA            37
#define PINMUX_FUNCTION_BT_LOG              38
#define PINMUX_FUNCTION_UART0_TXD           39
#define PINMUX_FUNCTION_UART0_RXD           40
#define PINMUX_FUNCTION_UART0_CTS           41
#define PINMUX_FUNCTION_UART0_RTS           42
#define PINMUX_FUNCTION_UART1_TXD           43
#define PINMUX_FUNCTION_UART1_RXD           44
#define PINMUX_FUNCTION_UART1_CTS           45
#define PINMUX_FUNCTION_UART1_RTS           46
#define PINMUX_FUNCTION_UART2_TXD           47
#define PINMUX_FUNCTION_UART2_RXD           48
#define PINMUX_FUNCTION_UART2_CTS           49
#define PINMUX_FUNCTION_UART2_RTS           50
#define PINMUX_FUNCTION_SPI0_CLK            51
#define PINMUX_FUNCTION_SPI0_MISO           52
#define PINMUX_FUNCTION_SPI0_MOSI           53
#define PINMUX_FUNCTION_SPI0_CS             54
#define PINMUX_FUNCTION_SPI1_CLK            55
#define PINMUX_FUNCTION_SPI1_MISO           56
#define PINMUX_FUNCTION_SPI1_MOSI           57
#define PINMUX_FUNCTION_SPI1_CS             58
#define PINMUX_FUNCTION_LP_I2C0_SCL         59
#define PINMUX_FUNCTION_LP_I2C0_SDA         60
#define PINMUX_FUNCTION_HP_I2C1_SCL         61
#define PINMUX_FUNCTION_HP_I2C1_SDA         62
#define PINMUX_FUNCTION_HP_I2C2_SCL         63
#define PINMUX_FUNCTION_HP_I2C2_SDA         64
#define PINMUX_FUNCTION_SD_CLK              65
#define PINMUX_FUNCTION_SD_CMD              66
#define PINMUX_FUNCTION_SD_D0               67
#define PINMUX_FUNCTION_SD_D1               68
#define PINMUX_FUNCTION_SD_D2               69
#define PINMUX_FUNCTION_SD_D3               70
#define PINMUX_FUNCTION_I2S0_BCLK           71
#define PINMUX_FUNCTION_I2S0_WS             72
#define PINMUX_FUNCTION_I2S0_DOUT           73
#define PINMUX_FUNCTION_I2S0_DIN            74
#define PINMUX_FUNCTION_I2S1_BCLK           75
#define PINMUX_FUNCTION_I2S1_WS             76
#define PINMUX_FUNCTION_I2S1_DOUT           77
#define PINMUX_FUNCTION_I2S1_DIN            78
#define PINMUX_FUNCTION_I2S2_BCLK           79
#define PINMUX_FUNCTION_I2S2_MCLK           80
#define PINMUX_FUNCTION_I2S2_WS             81
#define PINMUX_FUNCTION_I2S2_DIN0           82
#define PINMUX_FUNCTION_I2S2_DIN1           83
#define PINMUX_FUNCTION_I2S2_DIN2           84
#define PINMUX_FUNCTION_I2S2_DIN3           85
#define PINMUX_FUNCTION_I2S2_DOUT0          86
#define PINMUX_FUNCTION_I2S2_DOUT1          87
#define PINMUX_FUNCTION_I2S2_DOUT2          88
#define PINMUX_FUNCTION_I2S2_DOUT3          89
#define PINMUX_FUNCTION_I2S3_BCLK           90
#define PINMUX_FUNCTION_I2S3_MCLK           91
#define PINMUX_FUNCTION_I2S3_WS             92
#define PINMUX_FUNCTION_I2S3_DIN0           93
#define PINMUX_FUNCTION_I2S3_DIN1           94
#define PINMUX_FUNCTION_I2S3_DIN2           95
#define PINMUX_FUNCTION_I2S3_DIN3           96
#define PINMUX_FUNCTION_I2S3_DOUT0          97
#define PINMUX_FUNCTION_I2S3_DOUT1          98
#define PINMUX_FUNCTION_I2S3_DOUT2          99
#define PINMUX_FUNCTION_I2S3_DOUT3          100
#define PINMUX_FUNCTION_DMIC0_CLK           101
#define PINMUX_FUNCTION_DMIC0_DATA0         102
#define PINMUX_FUNCTION_DMIC0_DATA1         103
#define PINMUX_FUNCTION_DMIC0_DATA2         104
#define PINMUX_FUNCTION_DMIC0_DATA3         105
#define PINMUX_FUNCTION_SPK_DATA            106
#define PINMUX_FUNCTION_SPK_CLK             107
#define PINMUX_FUNCTION_LEDC                108
#define PINMUX_FUNCTION_RTC_OUT             109
#define PINMUX_FUNCTION_RTC_EXT_32K         110
#define PINMUX_FUNCTION_HS_PWM0             111
#define PINMUX_FUNCTION_HS_PWM1             112
#define PINMUX_FUNCTION_HS_PWM2             113
#define PINMUX_FUNCTION_HS_PWM3             114
#define PINMUX_FUNCTION_HS_PWM4             115
#define PINMUX_FUNCTION_HS_PWM5             116
#define PINMUX_FUNCTION_IR_TX               117
#define PINMUX_FUNCTION_IR_RX               118
#define PINMUX_FUNCTION_HS_TIM8_TRIG        119
#define PINMUX_FUNCTION_HS_TIM9_TRIG        120
#define PINMUX_FUNCTION_ANT_SEL_P           121
#define PINMUX_FUNCTION_ANT_SEL_N           122
#define PINMUX_FUNCTION_TRSW_N              123
#define PINMUX_FUNCTION_TRSW_P              124
#define PINMUX_FUNCTION_PA_EN0              125
#define PINMUX_FUNCTION_LNA_EN0             126
#define PINMUX_FUNCTION_PA_EN1              127
#define PINMUX_FUNCTION_LNA_EN1             128
#define PINMUX_FUNCTION_BT_WAKE_HOST        129
#define PINMUX_FUNCTION_HOST_WAKE_BT        130
#define PINMUX_FUNCTION_DBG_GNT_WL          131
#define PINMUX_FUNCTION_DBG_GNT_BT          132
#define PINMUX_FUNCTION_WLAN_ACT            133
#define PINMUX_FUNCTION_BT_ACT              134
#define PINMUX_FUNCTION_BT_STE              135
#define PINMUX_FUNCTION_BT_CK               136
#define PINMUX_FUNCTION_ZB_REQ              137
#define PINMUX_FUNCTION_ZB_GRANT            138
#define PINMUX_FUNCTION_ZB_PRI              139
#define PINMUX_FUNCTION_BT_ANT_SW_0         140
#define PINMUX_FUNCTION_BT_ANT_SW_1         141
#define PINMUX_FUNCTION_BT_ANT_SW_2         142
#define PINMUX_FUNCTION_BT_ANT_SW_3         143
#define PINMUX_FUNCTION_BT_ANT_SW_4         144
#define PINMUX_FUNCTION_BT_ANT_SW_5         145
#define PINMUX_FUNCTION_BT_ANT_SW_6         146
#define PINMUX_FUNCTION_BT_ANT_SW_7         147
#define PINMUX_FUNCTION_BT_I2C_SDA_TST      148
#define PINMUX_FUNCTION_BT_I2C_SCL_TST      149
/** @} */

#define UART_LOG_RXD                        _PB_23
#define UART_LOG_TXD                        _PB_24
#define SWD_DATA                            _PA_13
#define SWD_CLK                             _PA_14
#define SICK                                _PA_13
#define SIDD                                _PA_14




// Do NOT modify any AUTO_GEN code above
/* AUTO_GEN_END */

/* MANUAL_GEN_START */

//Please add your defination here
/* Exported Types --------------------------------------------------------*/

/** @defgroup PINMUX_Port_and_Pin_definitions
 * @{
 */
#define PORT_NUM(pin)		((pin>>5) & 0x03)
#define PIN_NUM(pin)		(pin & 0x1f)
/** @} */

/** @defgroup PINMUX_Peripheral_Location_definitions
 * @note just used by function PINMUX_Ctrl
 * @{
 */
#define PINMUX_S0		(0)
#define PINMUX_S1		(1)
#define PINMUX_S2		(2)
#define PINMUX_S3		(3)
#define PINMUX_S4		(4)
#define PINMUX_S5		(5)
/** @} */

/**************************************************************************//**
 * @defgroup AMEBASMARTPLUS_PINMUX
 * @{
 * @brief AMEBASMARTPLUS_PINMUX Register Declaration
 *****************************************************************************/

typedef struct {
	__IO uint32_t REG_GPIOx[PIN_TOTAL_NUM];			/*!< Pad control register */
} PINMUX_TypeDef;
/** @} */

/** @} */

/** @defgroup PINMUX_Exported_Functions PINMUX Exported Functions
 * @{
 */
_LONG_CALL_ void _Pinmux_Config(u8 PinName, u32 PinFunc);
_LONG_CALL_ void Pinmux_Config(u8 PinName, u32 PinFunc);
_LONG_CALL_ u32 Pinmux_ConfigGet(u8 PinName);
_LONG_CALL_ void Pinmux_UartLogCtrl(u32  PinLocation, bool   Operation);
_LONG_CALL_ void Pinmux_SpicCtrl(u32  PinLocation, bool Operation);
_LONG_CALL_ void Pinmux_Swdoff(void);
/** @} */

/** @} */


/** @defgroup PAD
 * @brief PAD driver modules
 * @{
 */

/** @defgroup PAD_Exported_Constants PAD Exported Constants
 * @{
 */

/** @defgroup PAD_Pull_Resistor_definitions
 * @{
 */
#define PAD_Resistor_LARGE		0x00 /*!< PAD Resistor LARGE */
#define PAD_Resistor_SMALL		0x01 /*!< PAD Resistor SMALL */
/** @} */


/** @defgroup PINMUX_PAD_DrvStrength_definitions
 * @{
 */
#define PAD_DRV_ABILITITY_LOW			(0)
#define PAD_DRV_ABILITITY_HIGH			(1)
/** @} */


/** @defgroup PINMUX_Special_Pad_definitions
 * @{
 */
#define APAD_NAME_START				_PA_18	/* PA18 & PA19 no pin output in all pkgs */
#define APAD_NAME_END				_PB_6

#define APAD_MIC_PAD__START			_PA_20
#define APAD_MIC_PAD_END			_PA_29

#define APAD_MIC_BIAS_PAD_START		_PA_30
#define APAD_MIC_BIAS_PAD_END		_PB_2

#define APAD_OUT_PAD_START			_PB_3
#define APAD_OUT_PAD_END			_PB_6

/** @} */

/** @} */


/** @defgroup PAD_Exported_Functions PAD Exported Functions
 * @{
 */
_LONG_CALL_ void PAD_CMD(u8 PinName, u8 NewStatus);
_LONG_CALL_ void PAD_DrvStrength(u8 PinName, u32 DrvStrength);
_LONG_CALL_ void PAD_PullCtrl(u8 PinName, u8 PullType);
_LONG_CALL_ void PAD_SleepPullCtrl(u8 PinName, u8 PullType);
_LONG_CALL_ void PAD_SpicCtrl(u32  PinLocation);
_LONG_CALL_ void PAD_ResistorCtrl(u8 PinName, u8 RType);


/**
 *  @brief Control digital path input for ADC and CTC pad.
 *  @param PinName: Pin for ADC module or CTC module.
 *  @param NewState: Digital path input status.
 *    @arg ENABLE: Enable digital path input.
 *    @arg DISABLE: Disable digital path input.
 *  @retval None
 *  @note only valid for ADC and CTC pads
 */
__STATIC_INLINE
void PAD_InputCtrl(u8 PinName, u32 NewState)
{
	u32 RTemp, PadShift = 0;

	if (PinName > _PA_8) {
		return;
	}

	RTemp = HAL_READ32(SYSTEM_CTRL_BASE, REG_LSYS_DUMMY_094);

	PadShift = PinName - _PA_0;

	if (NewState != DISABLE) {
		RTemp |= BIT(PadShift);
	} else {
		RTemp &= (~ BIT(PadShift));
	}

	HAL_WRITE32(SYSTEM_CTRL_BASE, REG_LSYS_DUMMY_094, RTemp);
}

/**
 *  @brief Control digital path input for Audio share PAD.
 *  @param PinName: Pin of Audio share PAD or 0xFF.
 *  @param NewState: Digital path input status.
 *    @arg ENABLE: Enable digital path input.
 *    @arg DISABLE: Disable digital path input.
 *  @retval None
 *  @note Only valid for Audio share PADs.
 *  @note If PinName is 0xFF, all the pins of Audio share PAD will be controlled.
 */
__STATIC_INLINE
void APAD_InputCtrl(u8 PinName, u32 NewState)
{
	u32 RTemp, PadShift = 0;

	if (PinName == 0xFF) {
		if (NewState != DISABLE) {
			RTemp = 0x1FFFFF;
		} else {
			RTemp = 0x0;
		}
	} else {
		if (PinName < APAD_NAME_START || PinName > APAD_NAME_END) {
			return;
		}

		RTemp = HAL_READ32(PINMUX_REG_BASE, REG_PAD_AUD_PAD_CTRL);
		PadShift = PinName - APAD_NAME_START;
		if (NewState != DISABLE) {
			RTemp |= BIT(PadShift);
		} else {
			RTemp &= ~BIT(PadShift);
		}
	}

	HAL_WRITE32(PINMUX_REG_BASE, REG_PAD_AUD_PAD_CTRL, RTemp);
}
/** @} */

/** @} */

/** @} */

/** @} */

/* MANUAL_GEN_END */

#endif   //_AMEBA_PINMUX_H_
