/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#if 1//new bitfile

#ifndef _AMEBA_VECTOR_TABLE_H_
#define _AMEBA_VECTOR_TABLE_H_

/* Exported constants --------------------------------------------------------*/
/** @defgroup IRQ_Exported_Constants IRQ Exported Constants
  * @{
  */
/* AUTO_GEN_START */
/** @defgroup APIRQn_enum
  * @{
  */
#if defined (CONFIG_ARM_CORE_CM4_KM4TZ)
typedef enum APIRQn {
	/******  Processor Exceptions Numbers ********/
	NonMaskableInt_IRQn    			= -14,	/*!< 2 Non Maskable Interrupt */
	HardFault_IRQn         			= -13,	/*!< 3 Hard Fault, all classes of Fault */
	MemoryManagement_IRQn  			= -12,	/*!< 4 Cortex-M3 Memory Management Interrupt */
	BusFault_IRQn          			= -11,	/*!< 5 Cortex-M3 Bus Fault Interrupt */
	UsageFault_IRQn        			= -10,	/*!< 6 Cortex-M3 Usage Fault Interrupt */
	SVCall_IRQn            			= -5,	/*!< 11 Cortex-M3 SV Call Interrupt  */
	DebugMonitor_IRQn      			= -4,	/*!< 12 Cortex-M3 Debug Monitor Interrupt */
	PendSV_IRQn            			= -2,	/*!< 14 Cortex-M3 Pend SV Interrupt */
	SysTick_IRQn           			= -1,	/*!< 15 Cortex-M3 System Tick Interrupt */

	/******  Specific Interrupt Numbers ************/
	WIFI_FISR_FESR_IRQ  			= 0,
	WL_PROTOCOL_IRQ     			= 1,
	BT_SCB_IRQ          			= 2,
	BT_MAILBOX_IRQ      			= 3,
	BT_WAKE_HOST_IRQ    			= 4,
	RXI300_IRQ          			= 5,
	IPC_KM4TZ_IRQ       			= 6,
	IWDG_IRQ            			= 7,
	TIMER0_IRQ          			= 8,
	TIMER1_IRQ          			= 9,
	TIMER2_IRQ          			= 10,
	TIMER3_IRQ          			= 11,
	TIMER4_IRQ          			= 12,
	TIMER5_IRQ          			= 13,
	TIMER6_IRQ          			= 14,
	TIMER7_IRQ          			= 15,
	TIMER8_IRQ          			= 16,
	TIMER9_IRQ          			= 17,
	TIMER10_IRQ         			= 18,
	AP_WAKE_IRQ         			= 19,
	PMC_TIMER0_IRQ      			= 20,
	PMC_TIMER1_IRQ      			= 21,
	UART0_IRQ           			= 22,
	UART1_IRQ           			= 23,
	UART2_IRQ           			= 24,
	UART3_IRQ           			= 25,
	UART_LOG_IRQ        			= 26,
	GPIOA_IRQ           			= 27,
	GPIOB_IRQ           			= 28,
	GPIOC_IRQ           			= 29,
	I2C0_IRQ            			= 30,
	I2C1_IRQ            			= 31,
	I3C_IRQ             			= 32,
	GDMA0_CHANNEL0_IRQ  			= 33,
	GDMA0_CHANNEL1_IRQ  			= 34,
	GDMA0_CHANNEL2_IRQ  			= 35,
	GDMA0_CHANNEL3_IRQ  			= 36,
	GDMA0_CHANNEL4_IRQ  			= 37,
	GDMA0_CHANNEL5_IRQ  			= 38,
	GDMA0_CHANNEL6_IRQ  			= 39,
	GDMA0_CHANNEL7_IRQ  			= 40,
	SPI0_IRQ            			= 41,
	SPI1_IRQ            			= 42,
	SPORT_IRQ           			= 43,
	CAN0_IRQ            			= 44,
	CAN1_IRQ            			= 45,
	RTC_IRQ             			= 46,
	ADC_IRQ             			= 47,
	CAPTOUCH_IRQ        			= 48,
	BOR_IRQ             			= 49,
	PWR_DOWN_IRQ        			= 50,
	RMII_IRQ            			= 51,
	LCDC_IRQ            			= 52,
	MJPEG_IRQ           			= 53,
	PPE_IRQ             			= 54,
	DVP_IRQ             			= 55,
	QSPI_IRQ            			= 56,
	SPI_FLASH_IRQ       			= 57,
	RSIP_IRQ            			= 58,
	AES_IRQ             			= 59,
	SHA_IRQ             			= 60,
	PKE_IRQ             			= 61,
	PSRAMC_IRQ          			= 62,
	TRNG_IRQ            			= 63,
	AES_S_IRQ           			= 64,
	SHA_S_IRQ           			= 65,
	AON_TIM_IRQ         			= 66,
	AON_WAKEPIN_IRQ     			= 67,
	SDIO_WIFI_IRQ       			= 68,
	SDIO_BT_IRQ         			= 69,
	USB_IRQ             			= 70,
	UVC_DEC_IRQ         			= 71,
	KM4NS_WDG_RST_IRQ   			= 72,
	KM4TZ_NS_WDG_IRQ    			= 73,
	KM4TZ_S_WDG_IRQ     			= 74,
	SYS_ILLEGAL_WRITE_S_IRQ			= 75,
	OCP_IRQ             			= 76,
} IRQn_Type;
#endif
/**
  * @}
  */


/** @defgroup NPIRQn_enum
  * @{
  */
#if defined (CONFIG_ARM_CORE_CM4_KM4NS)
typedef enum NPIRQn {
	/******  Processor Exceptions Numbers ********/
	NonMaskableInt_IRQn    			= -14,	/*!< 2 Non Maskable Interrupt */
	HardFault_IRQn         			= -13,	/*!< 3 Hard Fault, all classes of Fault */
	MemoryManagement_IRQn  			= -12,	/*!< 4 Cortex-M3 Memory Management Interrupt */
	BusFault_IRQn          			= -11,	/*!< 5 Cortex-M3 Bus Fault Interrupt */
	UsageFault_IRQn        			= -10,	/*!< 6 Cortex-M3 Usage Fault Interrupt */
	SVCall_IRQn            			= -5,	/*!< 11 Cortex-M3 SV Call Interrupt  */
	DebugMonitor_IRQn      			= -4,	/*!< 12 Cortex-M3 Debug Monitor Interrupt */
	PendSV_IRQn            			= -2,	/*!< 14 Cortex-M3 Pend SV Interrupt */
	SysTick_IRQn           			= -1,	/*!< 15 Cortex-M3 System Tick Interrupt */

	/******  Specific Interrupt Numbers ************/
	WIFI_FISR_FESR_IRQ  			= 0,
	WL_PROTOCOL_IRQ     			= 1,
	BT_SCB_IRQ          			= 2,
	BT_MAILBOX_IRQ      			= 3,
	BT_WAKE_HOST_IRQ    			= 4,
	RXI300_IRQ          			= 5,
	IPC_KM4NS_IRQ       			= 6,
	IWDG_IRQ            			= 7,
	TIMER0_IRQ          			= 8,
	TIMER1_IRQ          			= 9,
	TIMER2_IRQ          			= 10,
	TIMER3_IRQ          			= 11,
	TIMER4_IRQ          			= 12,
	TIMER5_IRQ          			= 13,
	TIMER6_IRQ          			= 14,
	TIMER7_IRQ          			= 15,
	TIMER8_IRQ          			= 16,
	TIMER9_IRQ          			= 17,
	TIMER10_IRQ         			= 18,
	AP_WAKE_IRQ         			= 19,
	PMC_TIMER0_IRQ      			= 20,
	PMC_TIMER1_IRQ      			= 21,
	UART0_IRQ           			= 22,
	UART1_IRQ           			= 23,
	UART2_IRQ           			= 24,
	UART3_IRQ           			= 25,
	UART_LOG_IRQ        			= 26,
	GPIOA_IRQ           			= 27,
	GPIOB_IRQ           			= 28,
	GPIOC_IRQ           			= 29,
	I2C0_IRQ            			= 30,
	I2C1_IRQ            			= 31,
	I3C_IRQ             			= 32,
	GDMA0_CHANNEL0_IRQ  			= 33,
	GDMA0_CHANNEL1_IRQ  			= 34,
	GDMA0_CHANNEL2_IRQ  			= 35,
	GDMA0_CHANNEL3_IRQ  			= 36,
	GDMA0_CHANNEL4_IRQ  			= 37,
	GDMA0_CHANNEL5_IRQ  			= 38,
	GDMA0_CHANNEL6_IRQ  			= 39,
	GDMA0_CHANNEL7_IRQ  			= 40,
	SPI0_IRQ            			= 41,
	SPI1_IRQ            			= 42,
	SPORT_IRQ           			= 43,
	CAN0_IRQ            			= 44,
	CAN1_IRQ            			= 45,
	RTC_IRQ             			= 46,
	ADC_IRQ             			= 47,
	CAPTOUCH_IRQ        			= 48,
	BOR_IRQ             			= 49,
	PWR_DOWN_IRQ        			= 50,
	RMII_IRQ            			= 51,
	LCDC_IRQ            			= 52,
	MJPEG_IRQ           			= 53,
	PPE_IRQ             			= 54,
	DVP_IRQ             			= 55,
	QSPI_IRQ            			= 56,
	SPI_FLASH_IRQ       			= 57,
	RSIP_IRQ            			= 58,
	AES_IRQ             			= 59,
	SHA_IRQ             			= 60,
	PKE_IRQ             			= 61,
	PSRAMC_IRQ          			= 62,
	TRNG_IRQ            			= 63,
	AON_TIM_IRQ         			= 64,
	AON_WAKEPIN_IRQ     			= 65,
	SDIO_WIFI_IRQ       			= 66,
	SDIO_BT_IRQ         			= 67,
	USB_IRQ             			= 68,
	UVC_DEC_IRQ         			= 69,
	KM4NS_WDG_IRQ       			= 70,
} IRQn_Type;
#endif
/**
  * @}
  */


/* AUTO_GEN_END */
/**
  * @}
  */

/* Other Definitions --------------------------------------------------------*/
/** @defgroup IRQn_Priority_def
  * @{
  */
enum IRQnPriority {
	INT_PRI0 = 0,	//Priority value 0 is the highest active priority
	INT_PRI_HIGHEST	= INT_PRI0,
	INT_PRI1,		//lower numbers have higher priority.
	INT_PRI2,
	INT_PRI_HIGH 	= INT_PRI2,
	INT_PRI3,
	INT_PRI4,
	INT_PRI_MIDDLE	= INT_PRI4,
	INT_PRI5,
	INT_PRI6,
	INT_PRI7,
	INT_PRI_LOWEST	= INT_PRI7,
};
/**
  * @}
  */

#endif //_AMEBA_VECTOR_TABLE_H_


#else //primary bitfile

#ifndef _AMEBA_VECTOR_TABLE_H_
#define _AMEBA_VECTOR_TABLE_H_

/* Exported constants --------------------------------------------------------*/
/** @defgroup IRQ_Exported_Constants IRQ Exported Constants
  * @{
  */
/* AUTO_GEN_START */
/** @defgroup APIRQn_enum
  * @{
  */
#if defined (CONFIG_ARM_CORE_CM4_KM4TZ)
typedef enum APIRQn {
	/******  Processor Exceptions Numbers ********/
	NonMaskableInt_IRQn    			= -14,	/*!< 2 Non Maskable Interrupt */
	HardFault_IRQn         			= -13,	/*!< 3 Hard Fault, all classes of Fault */
	MemoryManagement_IRQn  			= -12,	/*!< 4 Cortex-M3 Memory Management Interrupt */
	BusFault_IRQn          			= -11,	/*!< 5 Cortex-M3 Bus Fault Interrupt */
	UsageFault_IRQn        			= -10,	/*!< 6 Cortex-M3 Usage Fault Interrupt */
	SVCall_IRQn            			= -5,	/*!< 11 Cortex-M3 SV Call Interrupt  */
	DebugMonitor_IRQn      			= -4,	/*!< 12 Cortex-M3 Debug Monitor Interrupt */
	PendSV_IRQn            			= -2,	/*!< 14 Cortex-M3 Pend SV Interrupt */
	SysTick_IRQn           			= -1,	/*!< 15 Cortex-M3 System Tick Interrupt */

	/******  Specific Interrupt Numbers ************/
	WIFI_FISR_FESR_IRQ  			= 0,
	WIFI_FTSR_MAILBOX_IRQ			= 1,
	WL_DMA_IRQ          			= 2,
	WL_PROTOCOL_IRQ     			= 3,
	BT_SCB_IRQ          			= 4,
	BT_MAILBOX_IRQ      			= 5,
	BT_WAKE_HOST_IRQ    			= 6,
	RXI300_IRQ          			= 7,
	IPC_KM4TZ_IRQ       			= 8,
	IWDG_IRQ            			= 9,
	TIMER0_IRQ          			= 10,
	TIMER1_IRQ          			= 11,
	TIMER2_IRQ          			= 12,
	TIMER3_IRQ          			= 13,
	TIMER4_IRQ          			= 14,
	TIMER5_IRQ          			= 15,
	TIMER6_IRQ          			= 16,
	TIMER7_IRQ          			= 17,
	TIMER8_IRQ          			= 18,
	TIMER9_IRQ          			= 19,
	TIMER10_IRQ         			= 20,
	TIMER11_IRQ         			= 21,
	PMC_TIMER0_IRQ      			= 22,
	PMC_TIMER1_IRQ      			= 23,
	UART0_IRQ           			= 24,
	UART1_IRQ           			= 25,
	UART2_IRQ           			= 26,
	UART3_IRQ           			= 27,
	UART_LOG_IRQ        			= 28,
	GPIOA_IRQ           			= 29,
	GPIOB_IRQ           			= 30,
	GPIOC_IRQ           			= 31,
	I2C0_IRQ            			= 32,
	I2C1_IRQ            			= 33,
	I3C_IRQ             			= 34,
	GDMA0_CHANNEL0_IRQ  			= 35,
	GDMA0_CHANNEL1_IRQ  			= 36,
	GDMA0_CHANNEL2_IRQ  			= 37,
	GDMA0_CHANNEL3_IRQ  			= 38,
	GDMA0_CHANNEL4_IRQ  			= 39,
	GDMA0_CHANNEL5_IRQ  			= 40,
	GDMA0_CHANNEL6_IRQ  			= 41,
	GDMA0_CHANNEL7_IRQ  			= 42,
	SPI0_IRQ            			= 43,
	SPI1_IRQ            			= 44,
	SPORT_IRQ           			= 45,
	CAN0_IRQ            			= 46,
	CAN1_IRQ            			= 47,
	RTC_IRQ             			= 48,
	ADC_IRQ             			= 49,
	CAPTOUCH_IRQ        			= 50,
	BOR_IRQ             			= 51,
	PWR_DOWN_IRQ        			= 52,
	RMII_IRQ            			= 53,
	LCDC_IRQ            			= 54,
	MJPEG_IRQ           			= 55,
	PPE_IRQ             			= 56,
	DVP_IRQ             			= 57,
	QSPI_IRQ            			= 58,
	SPI_FLASH_IRQ       			= 59,
	RSIP_IRQ            			= 60,
	AES_IRQ             			= 61,
	SHA_IRQ             			= 62,
	PKE_IRQ             			= 63,
	PSRAMC_IRQ          			= 64,
	TRNG_IRQ            			= 65,
	AES_S_IRQ           			= 66,
	SHA_S_IRQ           			= 67,
	AON_TIM_IRQ         			= 68,
	AON_WAKEPIN_IRQ     			= 69,
	SDIO_WIFI_IRQ       			= 70,
	SDIO_BT_IRQ         			= 71,
	USB_IRQ             			= 72,
	UVC_DEC_IRQ         			= 73,
	AP_WAKE_IRQ         			= 74,
	KM4NS_WDG_RST_IRQ   			= 75,
	KM4TZ_NS_WDG_IRQ    			= 76,
	KM4TZ_S_WDG_IRQ     			= 77,
	SYS_ILLEGAL_WRITE_S_IRQ			= 78,
	OCP_IRQ             			= 79,
} IRQn_Type;
#endif
/**
  * @}
  */


/** @defgroup NPIRQn_enum
  * @{
  */
#if defined (CONFIG_ARM_CORE_CM4_KM4NS)
typedef enum NPIRQn {
	/******  Processor Exceptions Numbers ********/
	NonMaskableInt_IRQn    			= -14,	/*!< 2 Non Maskable Interrupt */
	HardFault_IRQn         			= -13,	/*!< 3 Hard Fault, all classes of Fault */
	MemoryManagement_IRQn  			= -12,	/*!< 4 Cortex-M3 Memory Management Interrupt */
	BusFault_IRQn          			= -11,	/*!< 5 Cortex-M3 Bus Fault Interrupt */
	UsageFault_IRQn        			= -10,	/*!< 6 Cortex-M3 Usage Fault Interrupt */
	SVCall_IRQn            			= -5,	/*!< 11 Cortex-M3 SV Call Interrupt  */
	DebugMonitor_IRQn      			= -4,	/*!< 12 Cortex-M3 Debug Monitor Interrupt */
	PendSV_IRQn            			= -2,	/*!< 14 Cortex-M3 Pend SV Interrupt */
	SysTick_IRQn           			= -1,	/*!< 15 Cortex-M3 System Tick Interrupt */

	/******  Specific Interrupt Numbers ************/
	WIFI_FISR_FESR_IRQ  			= 0,
	WIFI_FTSR_MAILBOX_IRQ			= 1,
	WL_DMA_IRQ          			= 2,
	WL_PROTOCOL_IRQ     			= 3,
	BT_SCB_IRQ          			= 4,
	BT_MAILBOX_IRQ      			= 5,
	BT_WAKE_HOST_IRQ    			= 6,
	RXI300_IRQ          			= 7,
	IPC_KM4NS_IRQ       			= 8,
	IWDG_IRQ            			= 9,
	TIMER0_IRQ          			= 10,
	TIMER1_IRQ          			= 11,
	TIMER2_IRQ          			= 12,
	TIMER3_IRQ          			= 13,
	TIMER4_IRQ          			= 14,
	TIMER5_IRQ          			= 15,
	TIMER6_IRQ          			= 16,
	TIMER7_IRQ          			= 17,
	TIMER8_IRQ          			= 18,
	TIMER9_IRQ          			= 19,
	TIMER10_IRQ         			= 20,
	TIMER11_IRQ         			= 21,
	PMC_TIMER0_IRQ      			= 22,
	PMC_TIMER1_IRQ      			= 23,
	UART0_IRQ           			= 24,
	UART1_IRQ           			= 25,
	UART2_IRQ           			= 26,
	UART3_IRQ           			= 27,
	UART_LOG_IRQ        			= 28,
	GPIOA_IRQ           			= 29,
	GPIOB_IRQ           			= 30,
	GPIOC_IRQ           			= 31,
	I2C0_IRQ            			= 32,
	I2C1_IRQ            			= 33,
	I3C_IRQ             			= 34,
	GDMA0_CHANNEL0_IRQ  			= 35,
	GDMA0_CHANNEL1_IRQ  			= 36,
	GDMA0_CHANNEL2_IRQ  			= 37,
	GDMA0_CHANNEL3_IRQ  			= 38,
	GDMA0_CHANNEL4_IRQ  			= 39,
	GDMA0_CHANNEL5_IRQ  			= 40,
	GDMA0_CHANNEL6_IRQ  			= 41,
	GDMA0_CHANNEL7_IRQ  			= 42,
	SPI0_IRQ            			= 43,
	SPI1_IRQ            			= 44,
	SPORT_IRQ           			= 45,
	CAN0_IRQ            			= 46,
	CAN1_IRQ            			= 47,
	RTC_IRQ             			= 48,
	ADC_IRQ             			= 49,
	CAPTOUCH_IRQ        			= 50,
	BOR_IRQ             			= 51,
	PWR_DOWN_IRQ        			= 52,
	RMII_IRQ            			= 53,
	LCDC_IRQ            			= 54,
	MJPEG_IRQ           			= 55,
	PPE_IRQ             			= 56,
	DVP_IRQ             			= 57,
	QSPI_IRQ            			= 58,
	SPI_FLASH_IRQ       			= 59,
	RSIP_IRQ            			= 60,
	AES_IRQ             			= 61,
	SHA_IRQ             			= 62,
	PKE_IRQ             			= 63,
	PSRAMC_IRQ          			= 64,
	TRNG_IRQ            			= 65,
	AON_TIM_IRQ         			= 66,
	AON_WAKEPIN_IRQ     			= 67,
	SDIO_WIFI_IRQ       			= 68,
	SDIO_BT_IRQ         			= 69,
	USB_IRQ             			= 70,
	UVC_DEC_IRQ         			= 71,
	AP_WAKE_IRQ         			= 72,
	KM4NS_WDG_IRQ       			= 73,
} IRQn_Type;
#endif
/**
  * @}
  */


/* AUTO_GEN_END */
/**
  * @}
  */

/* Other Definitions --------------------------------------------------------*/
/** @defgroup IRQn_Priority_def
  * @{
  */
enum IRQnPriority {
	INT_PRI0 = 0,	//Priority value 0 is the highest active priority
	INT_PRI_HIGHEST	= INT_PRI0,
	INT_PRI1,		//lower numbers have higher priority.
	INT_PRI2,
	INT_PRI_HIGH 	= INT_PRI2,
	INT_PRI3,
	INT_PRI4,
	INT_PRI_MIDDLE	= INT_PRI4,
	INT_PRI5,
	INT_PRI6,
	INT_PRI7,
	INT_PRI_LOWEST	= INT_PRI7,
};
/**
  * @}
  */

#endif //_AMEBA_VECTOR_TABLE_H_

#endif