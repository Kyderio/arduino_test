/******************************************************************************
 *
 * Copyright(c) 2007 - 2012 Realtek Corporation. All rights reserved.
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
#ifndef _WIFI_HAL_XMIT_H_
#define _WIFI_HAL_XMIT_H_

//OFFSET 0
#define OFFSET_SZ			0

//OFFSET 4

//OFFSET 8

//OFFSET 12

//OFFSET 16

//OFFSET 20

#define GET_FIX_RATE(v)		((v) & 0x003F)
#define GET_FIX_RATE_SGI(v)	(((v) & 0x7000) >> 12)
#define GET_FIX_RATE_ER_EN(v)	(((v) & 0x10000) >> 16)
#define GET_FIX_RATE_ER_BW(v)	(((v) & 0x20000) >> 17)

u32 wifi_hal_txrls_fifo_valid_check(void);
u32 wifi_hal_txrls_fifo_read(void);
void wifi_hal_tx_ring_skb_search_and_dequeue(struct rtw_tx_ring *ring, u32 addr);
void wifi_hal_txrpt_init(void);
void wifi_hal_txrpt_parse(void);

#endif

