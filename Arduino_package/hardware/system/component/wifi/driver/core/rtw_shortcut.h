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
#ifndef __RTW_SHORTCUT_H_
#define __RTW_SHORTCUT_H_

//#ifdef TX_SHORTCUT
struct tx_sc_entry {
	u8 shortcut_hdr[128];//tx_desc(32B) + wlanhdr + snap[6];
	u8 sc_hdr_len;
	u8 tx_sc_ethhdr[14];
	u8 tx_sc_entry_busy;
} __attribute__((aligned(4)));
struct tx_raw_sc_entry {
	u8 shortcut_txdesc[40];
	u32 sc_len;
};

//#endif

#endif

