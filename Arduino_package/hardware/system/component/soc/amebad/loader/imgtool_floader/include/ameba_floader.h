/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _AMEBA_FLOADER_H_
#define _AMEBA_FLOADER_H_

#include "ameba_floader_rom_parse.h"
#include "xmodem_uart_rom.h"

#define SUPPORT_LARGE_CAPACITY

#define IS_FLASH_ADDR(addr)			((addr >= SPI_FLASH_BASE) && (addr <= 0x0FFFFFFF))

#undef IMAGE_WRITE_PARSER
#ifdef IMAGE_WRITE_PARSER
#define FLASH_ERASE_AND_WRITE		0
#define FLASH_WRITE_ONLY			BIT_SOC_XMODEM_FLASH_EMPTY
#define FLASH_ERASE_WRITE_PAGE		BIT_SOC_XMODEM_PAGE_PG
#define FLASH_WRITE_PAGE_ONLY		(BIT_SOC_XMODEM_FLASH_EMPTY | BIT_SOC_XMODEM_PAGE_PG)
#endif

#define XDEBUG_GPIO					_PA_12
#define WAIT_FRAME_TIME			(830 * 1000) 			/* 1 sec, wait frame timeout */
#define WAIT_CHAR_TIME				(415 * 1000)			/* 0.5 sec, wait char timeout */
#define WAIT_TIME_SERVER			(1660 * 1000)		/* 2 sec, server wait timeout */
#define WAIT_HANDSHAKE_TIME		(830 * 1000)		/* 1 sec, handshake timeout */

#define FRAME_BUF_ADDR				(char*)(MSP_RAM_LP - 16 * 1024)
#define HANDSHAKE_BAUD				115200
#define OTP_PROGRAM_ENABLE

u32 Get_FlashWriteMethod(void);
u32 Get_LogUartPinmux(void);
void Reboot_Uart_Download(void);


#endif


