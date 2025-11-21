/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _FLOADER_DEBUG_H_
#define _FLOADER_DEBUG_H_

#include "ameba_soc.h"

#define  DEBUG_FLOADER

#ifdef DEBUG_FLOADER
#define FLOADER_UART_DEV			UART1_DEV	// to be modify for debug
#define FLOADER_UART_RX				_PB_30		// to be modify for debug
#define FLOADER_UART_TX				_PB_31		// to be modify for debug
#define PINMUX_FUNCTION_UART_TX		PINMUX_FUNCTION_UART1_TXD		// to be modify for debug
#define PINMUX_FUNCTION_UART_RX		PINMUX_FUNCTION_UART1_RXD		// to be modify for debug

#define FLOADER_UART_BAUD			1500000
#define FLOADER_DBGSIZE				64

extern char buf[FLOADER_DBGSIZE];
void debug_UartPrint(char *pstr);
void debug_UartInit(void);
void debug_GpioInit(void);
void debug_GpioOut(u32 code, u32 need_delay);
#else
#define debug_UartPrint(...)
#define debug_UartInit(...)
#define debug_GpioInit(...)
#define debug_GpioOut(...)
#endif

#endif  // end of "#define _FLOADER_DEBUG_H_"