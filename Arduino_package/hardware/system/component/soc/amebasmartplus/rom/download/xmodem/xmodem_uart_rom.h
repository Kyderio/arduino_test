/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _XMPORT_UART_H_
#define _XMPORT_UART_H_

_LONG_CALL_ void xmodem_uart_init(u8 pin_mux, u32 baud_rate);
_LONG_CALL_ void xmodem_uart_deinit(void) ;
_LONG_CALL_ void xmodem_uart_port_init(UNUSED_WARN_DIS u8 uart_idx, UNUSED_WARN_DIS u8 pin_mux, u32 baud_rate);
_LONG_CALL_ void xmodem_uart_port_deinit(UNUSED_WARN_DIS u8 uart_idx);
_LONG_CALL_ char xmodem_uart_readable(void) ;
_LONG_CALL_ char xmodem_uart_writable(void) ;
_LONG_CALL_ char xmodem_uart_getc(void) ;
_LONG_CALL_ void xmodem_uart_putc(char c) ;
_LONG_CALL_ void xmodem_uart_putdata(u8 *buf, u32 cnt) ;
_LONG_CALL_ char xmodem_uart_getc_to(char *pch, u32 timeout);
_LONG_CALL_ void xmodem_uart_clean_rx(void);
_LONG_CALL_ void xmodem_uart_waitbusy(void);
_LONG_CALL_ void xmodem_uart_setbaud(u32 baud);

#endif  // end of "#define _XMPORT_UART_H_"

