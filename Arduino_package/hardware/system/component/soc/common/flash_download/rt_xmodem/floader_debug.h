/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _FLOADER_DEBUG_H_
#define _FLOADER_DEBUG_H_

#include "ameba_soc.h"
//#include "pinnames.h"

#define DEBUG_FLOADER 	0

#if DEBUG_FLOADER
#define FLOADER_UART_DEV			UART0_DEV	// to be modify for debug
#define FLOADER_UART_RX				PA_2		// to be modify for debug
#define FLOADER_UART_TX				PA_3		// to be modify for debug
#define PINMUX_FUNCTION_UART_TX		PINMUX_FUNCTION_UART0_TXD		// to be modify for debug
#define PINMUX_FUNCTION_UART_RX		PINMUX_FUNCTION_UART0_RXD		// to be modify for debug

#define FLOADER_UART_BAUD			1500000

_LONG_CALL_ void UARTDBG_Print(char *pstr);
_LONG_CALL_ void UARTDBG_Init(void);

#define XMDBG_UART_INIT()		do{\
	UARTDBG_Init(); \
}while(0)

#define XMDBG_UART_PRINT(...)		do{\
	UARTDBG_Print(__VA_ARGS__); \
}while(0)

#else

#define XMDBG_UART_INIT(...)
#define XMDBG_UART_PRINT(...)

#endif

#endif  // end of "#define _FLOADER_DEBUG_H_"
