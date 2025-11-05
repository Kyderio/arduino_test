/******************************************************************************
 *
 * Copyright(c) 2007 - 2020  Realtek Corporation.
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
 * The full GNU General Public License is included in this distribution in the
 * file called LICENSE.
 *
 * Contact Information:
 * wlanfae <wlanfae@realtek.com>
 * Realtek Corporation, No. 2, Innovation Road II, Hsinchu Science Park,
 * Hsinchu 300, Taiwan.
 *
 * Larry Finger <Larry.Finger@lwfinger.net>
 *
 *****************************************************************************/

#ifndef _HALRF_FW_RESTORE_RFK_8720E_H
#define _HALRF_FW_RESTORE_RFK_8720E_H

const u16 array_fw_macpg_rfdpkreg[] = {
	//DPK
	0x5864,
	0x8020,
	0x81c4,
	0x81c8,
	0x80bc,
	0x81bc,
};

const u16 array_AFE_BB_for_RFK[] = {
	//AFE&BB for RFK(GAPK/IQK/DPK)
	0x5864,
	0x2008,
	0x20fc,
	0x5670,
	0x12a0,
	0x030c,
	0x032c,
	0x12b8,
	0x8008,
	0x8108,
	0x80b8,
	0x80cc,
	0x8120,
	0x8138,
	0x8028,
	//IQK
	0x8038,
	0x803C,
	HIOECmdFileEndFlg,
};

const u32 array_fw_pginit_drfctrx[] = {
	0xe00035,
	0x10500000,
	0x156a0000,
	0x1ee04000,
	0x130001ed,
	0x130005ab,
	0x130009a5,
	0x13000d9f,
	0x13001199,
	0x1300155f,
	0x13001959,
	0x13001d1f,
	0x13002119,
	0x13002513,
	0x130028d9,
	0x13002cd3,
	0x13003099,
	0x13003493,
	0x13003859,
	0x13003c53,
	0x1300404d,
	0x13004413,
	0x1ee00000,
	0x1ee02000,
	0x130000f9,
	0x130004f6,
	0x130008f3,
	0x13000cf0,
	0x130010ed,
	0x130014ea,
	0x1300186a,
	0x13001c67,
	0x13002064,
	0x13002425,
	0x13002822,
	0x13002c1f,
	0x1300301c,
	0x13003419,
	0x13003816,
	0x13003c13,
	0x13004010,
	0x1ee00000,
	0x10500001,
};

#endif	/* _HALRF_FW_RESTORE_RFK_8720E_H */
