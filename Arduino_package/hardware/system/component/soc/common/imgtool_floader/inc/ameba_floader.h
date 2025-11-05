/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _AMEBA_FLOADER_H
#define _AMEBA_FLOADER_H

#include "ameba_floader_rom_parse.h"
#include "xmodem_uart_rom.h"

/* 1. floader handshake buadrate */
#define HANDSHAKE_BAUD				115200

/* 2. timing settings */
#if defined(CONFIG_AMEBALITE)
/*read loguart register cost 199.92ns*/
#define XDEBUG_GPIO					_PA_6
#define WAIT_FRAME_TIME				(5000 * 1000) 		/* 1 sec, wait frame timeout */
#define WAIT_CHAR_TIME				(2500 * 1000)		/* 0.5 sec, wait char timeout */
#define WAIT_TIME_SERVER			(10000 * 1000)		/* 2 sec, server wait timeout */
#define WAIT_HANDSHAKE_TIME			(5000 * 1000)		/* 1 sec, handshake timeout */
#define WAIT_NAK_PERIOD				(250 * 1000)		/* 50 ms, period of send NAK when handshake */
#else
#define XDEBUG_GPIO					_PA_6
/* amebasmart: read loguart register cost 349.44ns, KM4 is 240MHz(NPPLL/4) */
/* amebadplus: read loguart register cost 350ns, KM4 is 200MHz */
#define WAIT_FRAME_TIME				(2862 * 1000) 			/* 1 sec, wait frame timeout */
#define WAIT_CHAR_TIME				(1431 * 1000)			/* 0.5 sec, wait char timeout */
#define WAIT_TIME_SERVER			(5724 * 1000)			/* 2 sec, server wait timeout */
#define WAIT_HANDSHAKE_TIME			(2862 * 1000)			/* 1 sec, handshake timeout */
#define WAIT_NAK_PERIOD				(143 * 1000)			/* 50 ms, period of send NAK when handshake */
#endif

/* 3. data buffer adddress for downloading */
#define FRAME_BUF_ADDR				(char*)(MSP_RAM_HP_NS - 16 * 1024)

#define RAM_END_ADDR				(char*)(0x20080000)

/* 4. downloading mp image to ram */
#if defined(CONFIG_AMEBALITE) || defined(CONFIG_AMEBADPLUS)
/* For RAM Downloading in AmebaDplus/AmebaLite */
#define BOOTLOADER_MP				0x3000A020
#define ENTRY_RAM_MP				(0x20012000 + 4 * 1024)	//ram addr, boot.bin: 4k manifest + 1k entry + boot text
#endif

#define IS_RAM_ADDR(addr)           ((addr >= 0x20000000) && (addr <= 0x3FFFFFFF))

/* 5. OTP support */
#define OTP_PROGRAM_ENABLE

/* 6. large capacity support for flash(4byte read/write)*/
#define SUPPORT_LARGE_CAPACITY


#endif

