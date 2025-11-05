/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef __RTW_TASK_H_
#define __RTW_TASK_H_

#include <stdio.h>
#include <os_wrapper.h>

#if defined(CONFIG_WPS)
#define RECV_STACK_FOR_WPS 448//512//384 //Change to 512 for WPS (IAR STM32) stack overflow
#else
#define RECV_STACK_FOR_WPS 0
#endif

/* max 920 in smart wifi_hal_mccapi_port1_bcn_early_hdl */
#define WIFI_STACK_SIZE_LITTLE_TASKLET		((920 + 128 + CONTEXT_SAVE_SIZE) / 4)	/* rtw_if_wifi_create_task: size will *4 */

#ifdef CONFIG_WIFI_TUNNEL
#define RCV_WTN_ADD	200
#else
#define RCV_WTN_ADD	0
#endif

#if defined (CONFIG_WHC_DEV)
#if defined(CONFIG_WHC_INTF_IPC)
#define WIFI_STACK_SIZE_RECV_TASKLET	((2280 + 128 + CONTEXT_SAVE_SIZE) / 4 + RCV_WTN_ADD)	/* max 2280 in lite, rtw_if_wifi_create_task: size will *4 */
#else
#define WIFI_STACK_SIZE_RECV_TASKLET	((2032 + 128 + CONTEXT_SAVE_SIZE + 1024) / 4 + RCV_WTN_ADD)	/* 1k: for sdio fullmac proxy */
#endif
#else
#define WIFI_STACK_SIZE_RECV_TASKLET	(1024 + RECV_STACK_FOR_WPS + RCV_WTN_ADD)		/* considering single core */
#endif

/*
NOTE: DiagPrintf only use 90Byte
	for Lite KR4, if use RTK_LOGA to debug, need enlarge stack size to about 300
	the OS API: uxTaskGetStackHighWaterMark can be called to get the available stack size of the task
*/
#define WIFI_STACK_SIZE_DRIVER_RESUME_TASKLET ((368 + 128 + CONTEXT_SAVE_SIZE) / 4)	/* max 368 in lite, rtw_if_wifi_create_task: size will *4 */

#include "rtw_wifi_constants.h"

#endif	// __RTW_TASK_H_
