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

#ifndef _HALRF_FW_RESTORE_RFK_8730E_H
#define _HALRF_FW_RESTORE_RFK_8730E_H

const u16 array_X2K_table[] = {
	0xBC,
	0xBD,
};

const u16 array_fw_macpg_rfdpkreg[] = {
	0x8008,
	//0x8080,
	0x8108,
	0x80b8,
	0x80cc,
	0x8120,
	0x8138,
	0x8028,
	//IQK
	0x8038,
	0x803C,
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
	HIOECmdFileEndFlg,
};


#endif	/* _HALRF_HWIMG_RAW_DATA_8730E_H */
