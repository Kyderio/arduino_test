/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */


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
	AP_WAKE_IRQ         			= 4,
	IPC_CPU0_IRQ        			= 5,
	IWDG_IRQ            			= 6,
	TIMER0_IRQ          			= 7,
	TIMER1_IRQ          			= 8,
	TIMER2_IRQ          			= 9,
	TIMER3_IRQ          			= 10,
	TIMER4_IRQ          			= 11,
	TIMER5_IRQ          			= 12,
	TIMER6_IRQ          			= 13,
	TIMER7_IRQ          			= 14,
	TIMER8_IRQ          			= 15,
	RSVD_IRQ            			= 16,
	PMC_TIMER0_IRQ      			= 17,
	PMC_TIMER1_IRQ      			= 18,
	UART0_IRQ           			= 19,
	UART1_IRQ           			= 20,
	UART2_IRQ           			= 21,
	UART3_IRQ           			= 22,
	UART_LOG_IRQ        			= 23,
	GPIOA_IRQ           			= 24,
	GPIOB_IRQ           			= 25,
	GPIOC_IRQ           			= 26,
	I2C0_IRQ            			= 27,
	I2C1_IRQ            			= 28,
	GDMA0_CHANNEL0_IRQ  			= 29,
	GDMA0_CHANNEL1_IRQ  			= 30,
	GDMA0_CHANNEL2_IRQ  			= 31,
	GDMA0_CHANNEL3_IRQ  			= 32,
	GDMA0_CHANNEL4_IRQ  			= 33,
	GDMA0_CHANNEL5_IRQ  			= 34,
	GDMA0_CHANNEL6_IRQ  			= 35,
	GDMA0_CHANNEL7_IRQ  			= 36,
	SPI0_IRQ            			= 37,
	SPI1_IRQ            			= 38,
	SPORT_IRQ           			= 39,
	RTC_IRQ             			= 40,
	ADC_IRQ             			= 41,
	ADC_COMP_IRQ        			= 42,
	BOR_IRQ             			= 43,
	PWR_DOWN_IRQ        			= 44,
	PKE_IRQ             			= 45,
	TRNG_IRQ            			= 46,
	AON_TIM_IRQ         			= 47,
	AON_WAKEPIN_IRQ     			= 48,
	SDIO_WIFI_IRQ       			= 49,
	SDIO_BT_IRQ         			= 50,
	RXI300_IRQ          			= 51,
	PSRAMC_IRQ          			= 52,
	SPI_FLASH_IRQ       			= 53,
	RSIP_IRQ            			= 54,
	AES_IRQ             			= 55,
	SHA_IRQ             			= 56,
	CPU0_NS_WDG_IRQ     			= 57,
	CPU0_S_WDG_IRQ      			= 58,
	OCP_IRQ             			= 59,
	CPU1_WDG_RST_IRQ    			= 60,
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
	AP_WAKE_IRQ         			= 4,
	IPC_CPU1_IRQ        			= 5,
	IWDG_IRQ            			= 6,
	TIMER0_IRQ          			= 7,
	TIMER1_IRQ          			= 8,
	TIMER2_IRQ          			= 9,
	TIMER3_IRQ          			= 10,
	TIMER4_IRQ          			= 11,
	TIMER5_IRQ          			= 12,
	TIMER6_IRQ          			= 13,
	TIMER7_IRQ          			= 14,
	TIMER8_IRQ          			= 15,
	RSVD_IRQ            			= 16,
	PMC_TIMER0_IRQ      			= 17,
	PMC_TIMER1_IRQ      			= 18,
	UART0_IRQ           			= 19,
	UART1_IRQ           			= 20,
	UART2_IRQ           			= 21,
	UART3_IRQ           			= 22,
	UART_LOG_IRQ        			= 23,
	GPIOA_IRQ           			= 24,
	GPIOB_IRQ           			= 25,
	GPIOC_IRQ           			= 26,
	I2C0_IRQ            			= 27,
	I2C1_IRQ            			= 28,
	GDMA0_CHANNEL0_IRQ  			= 29,
	GDMA0_CHANNEL1_IRQ  			= 30,
	GDMA0_CHANNEL2_IRQ  			= 31,
	GDMA0_CHANNEL3_IRQ  			= 32,
	GDMA0_CHANNEL4_IRQ  			= 33,
	GDMA0_CHANNEL5_IRQ  			= 34,
	GDMA0_CHANNEL6_IRQ  			= 35,
	GDMA0_CHANNEL7_IRQ  			= 36,
	SPI0_IRQ            			= 37,
	SPI1_IRQ            			= 38,
	SPORT_IRQ           			= 39,
	RTC_IRQ             			= 40,
	ADC_IRQ             			= 41,
	ADC_COMP_IRQ        			= 42,
	BOR_IRQ             			= 43,
	PWR_DOWN_IRQ        			= 44,
	PKE_IRQ             			= 45,
	TRNG_IRQ            			= 46,
	AON_TIM_IRQ         			= 47,
	AON_WAKEPIN_IRQ     			= 48,
	SDIO_WIFI_IRQ       			= 49,
	SDIO_BT_IRQ         			= 50,
	RXI300_IRQ          			= 51,
	PSRAMC_IRQ          			= 52,
	SPI_FLASH_IRQ       			= 53,
	RSIP_IRQ            			= 54,
	AES_IRQ             			= 55,
	SHA_IRQ             			= 56,
	CPU1_WDG_IRQ        			= 57,
	BT_CTRL_HIGH_IRQ    			= 58,
	BT_CTRL_LOW_IRQ     			= 59,
} IRQn_Type;
#endif
/**
  * @}
  */

#ifndef RTL8720F_TODO
#define KM4TZ_NS_WDG_IRQ CPU0_NS_WDG_IRQ
#define KM4TZ_S_WDG_IRQ CPU0_S_WDG_IRQ
#define KM4NS_WDG_IRQ CPU1_WDG_IRQ
#define IPC_KM4NS_IRQ IPC_CPU1_IRQ
#define IPC_KM4TZ_IRQ IPC_CPU0_IRQ
#endif

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
