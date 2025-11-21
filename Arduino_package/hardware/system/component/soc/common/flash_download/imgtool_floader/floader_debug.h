/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _FLOADER_DEBUG_H_
#define _FLOADER_DEBUG_H_

/* Includes ------------------------------------------------------------------*/

#include "ameba_soc.h"
#include "floader_intf.h"

/* Exported defines ----------------------------------------------------------*/

//#define  FL_LOG_EN
//#define  FL_DEBUG_LOG_EN
//#define  FL_DEBUG_GPIO_EN
//#define  FL_DEBUG_GPIO_FSM

#ifdef FL_DEBUG_GPIO_EN
#if defined(CONFIG_AMEBADPLUS)
#define DBG_WRITE_PIN _PB_2
#define DBG_ERASE_PIN _PB_3
#define DBG_PROCESS_PIN _PB_15
#define DBG_IRQ_H_PIN _PB_21
#elif defined(CONFIG_AMEBASMART) || defined(CONFIG_AMEBASMARTPLUS)
#define DBG_WRITE_PIN _PA_14
#define DBG_ERASE_PIN _PA_9
#define DBG_PROCESS_PIN _PA_13
#define DBG_IRQ_H_PIN _PA_10 //smartplus: _PA_5
#elif defined(CONFIG_AMEBALITE)
#define DBG_WRITE_PIN _PA_11
#define DBG_ERASE_PIN _PA_12
#define DBG_PROCESS_PIN _PA_14
#define DBG_IRQ_H_PIN _PA_15
#elif defined(CONFIG_AMEBAGREEN2)
#define DBG_WRITE_PIN _PA_0
#define DBG_ERASE_PIN _PA_4
#define DBG_PROCESS_PIN _PA_5
#define DBG_IRQ_H_PIN _PA_6
#elif defined(CONFIG_AMEBAL2)
#define DBG_WRITE_PIN _PA_0
#define DBG_ERASE_PIN _PA_4
#define DBG_PROCESS_PIN _PA_5
#define DBG_IRQ_H_PIN _PC_7
#else
#error "ERROR: SoC NOT supported yet"
#endif
#endif

#ifdef FL_LOG_EN

#if defined(CONFIG_AMEBADPLUS)
#define FL_DEBUG_UART_DEV					UART1_DEV
#define FL_DEBUG_UART_RX					_PB_30
#define FL_DEBUG_UART_TX					_PB_31
#define FL_DEBUG_UART_TX_PINMUX_FUNCTION	PINMUX_FUNCTION_UART1_TXD
#define FL_DEBUG_UART_RX_PINMUX_FUNCTION	PINMUX_FUNCTION_UART1_RXD
#define FL_DEBUG_UART_CLOCK_ON()			do { \
	RCC_PeriphClockCmd(APBPeriph_UART1, APBPeriph_UART1_CLOCK, ENABLE); \
} while(0)
#elif defined(CONFIG_AMEBASMART)
#define FL_DEBUG_UART_DEV					UART1_DEV
#define FL_DEBUG_UART_RX					_PB_19
#define FL_DEBUG_UART_TX					_PB_20
#define FL_DEBUG_UART_TX_PINMUX_FUNCTION	PINMUX_FUNCTION_UART
#define FL_DEBUG_UART_RX_PINMUX_FUNCTION	PINMUX_FUNCTION_UART
#define FL_DEBUG_UART_CLOCK_ON()			do { \
	RCC_PeriphClockCmd(APBPeriph_UART1, APBPeriph_UART1_CLOCK, ENABLE); \
} while(0)
#elif defined(CONFIG_AMEBASMARTPLUS)
#define FL_DEBUG_UART_DEV					UART1_DEV
#define FL_DEBUG_UART_RX					_PB_19
#define FL_DEBUG_UART_TX					_PA_4
#define FL_DEBUG_UART_TX_PINMUX_FUNCTION	PINMUX_FUNCTION_UART1_TXD
#define FL_DEBUG_UART_RX_PINMUX_FUNCTION	PINMUX_FUNCTION_UART1_RXD

#define FL_DEBUG_UART_CLOCK_ON()			do { \
	RCC_PeriphClockCmd(APBPeriph_UART1, APBPeriph_UART1_CLOCK, ENABLE); \
} while(0)
#elif defined(CONFIG_AMEBALITE)
#define FL_DEBUG_UART_DEV					UART1_DEV
#define FL_DEBUG_UART_RX					_PA_18
#define FL_DEBUG_UART_TX					_PA_17
#define FL_DEBUG_UART_TX_PINMUX_FUNCTION	PINMUX_FUNCTION_UART1_TXD
#define FL_DEBUG_UART_RX_PINMUX_FUNCTION	PINMUX_FUNCTION_UART1_RXD
#define FL_DEBUG_UART_CLOCK_ON()			do { \
	RCC_PeriphClockCmd(APBPeriph_UART1, APBPeriph_UART1_CLOCK, ENABLE); \
} while(0)
#elif defined(CONFIG_AMEBAGREEN2)
#define FL_DEBUG_UART_DEV					UART0_DEV
#define FL_DEBUG_UART_RX					_PA_9
#define FL_DEBUG_UART_TX					_PA_8
#define FL_DEBUG_UART_TX_PINMUX_FUNCTION	PINMUX_FUNCTION_UART0_TXD
#define FL_DEBUG_UART_RX_PINMUX_FUNCTION	PINMUX_FUNCTION_UART0_RXD
#define FL_DEBUG_UART_CLOCK_ON()			do { \
	RCC_PeriphClockCmd(APBPeriph_UART0, APBPeriph_UART0_CLOCK, ENABLE); \
} while(0)
#elif defined(CONFIG_AMEBAL2)
#define FL_DEBUG_UART_DEV					UART1_DEV
#define FL_DEBUG_UART_RX					_PC_10
#define FL_DEBUG_UART_TX					_PC_14
#define FL_DEBUG_UART_TX_PINMUX_FUNCTION	PINMUX_FUNCTION_UART1_TXD
#define FL_DEBUG_UART_RX_PINMUX_FUNCTION	PINMUX_FUNCTION_UART1_RXD
#define FL_DEBUG_UART_CLOCK_ON()			do { \
	RCC_PeriphClockCmd(APBPeriph_UART1, APBPeriph_UART1_CLOCK, ENABLE); \
} while(0)
#else
#error "ERROR: SoC NOT supported yet"
#endif

#define FL_DEBUG_UART_BAUDRATE				1500000
#define FL_DEBUG_BUF_LEN					128

/* Exported types ------------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

extern char fl_debug_buf[FL_DEBUG_BUF_LEN];

/* Exported functions ------------------------------------------------------- */

void fl_debug_print(char *str);
void fl_debug_uart_init(void);

#define FL_LOG(format, ... )				do { \
	__disable_irq(); \
	DiagSnPrintf(fl_debug_buf, FL_DEBUG_BUF_LEN, format, ##__VA_ARGS__); \
	fl_debug_print(fl_debug_buf); \
	__enable_irq(); \
} while (0)

#ifdef FL_DEBUG_LOG_EN
#define FL_DBG								FL_LOG
#else
#define FL_DBG(format, ... )
#endif

#else

#define fl_debug_uart_print(...)
#define fl_debug_uart_init(...)
#define FL_DBG(format, ... )
#define FL_LOG(format, ... )

#endif

#ifdef FL_DEBUG_GPIO_EN
void fl_debug_gpio_init(void);
#ifdef FL_DEBUG_GPIO_FSM
void fl_debug_gpio_out(u32 code, u32 need_delay);
#else
#define fl_debug_gpio_out(...)
#endif
#else
#define fl_debug_gpio_init(...)
#define fl_debug_gpio_out(...)
#endif

#endif  // _FLOADER_DEBUG_H_
