/******************************************************************************
 *
 * Copyright(c) 2007 - 2017  Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
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

#ifndef __HALRF_FW_RESTORE_RFK_8721DA_H__
#define __HALRF_FW_RESTORE_RFK_8721DA_H__

const u16 array_fw_macpg_rfdpkreg[] = {
	0x1bcc,
	0x1bf8,
	0x1bb8,
	0x1b30,
	0x1bbc,
	0x29bc,
	0x1b20,
	0x1b90,
	0x1b94,
	0x2920,
	0x1b08,
	0x1b34,
	0x29c4,
	0x29c8,
	0x1e24,
};

const u16 array_AFE_BB_for_RFK[] = {
	//RF IQK
	0x1b38,
	0x1b3c,
	//RF ADCK
	0x1868,
	//AFE&BB for RFK(GAPK/IQK/DPK)
	0x85c,
	0x940,
	0x96c,
	0x1000,
	0x1800,
	0x180c,
	0x1810,
	0x1814,
	0x1830,
	0x1860,
	0x1864,
	0x1880,
	0x1c20,
	//0x1c38,
	0x1c68,
	0x1d40,
	0x1e24,
	0x1e28,
	0x2a24,
	0x2920,
	0x2938,
	HIOECmdFileEndFlg,
};

#endif /*#ifndef __HALRF_FW_RESTORE_RFK_8721DA_H__*/
