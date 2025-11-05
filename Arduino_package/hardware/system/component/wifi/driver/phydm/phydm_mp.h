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

#ifndef __PHYDM_MP_H__
#define __PHYDM_MP_H__

/*2020.04.27 Refine single tone Tx flow*/
#define MP_VERSION "1.5"

/* @1 ============================================================
 * 1  Definition
 * 1 ============================================================
 */
/* @1 ============================================================
 * 1  structure
 * 1 ============================================================
 */
struct phydm_mp {
	/*Rx OK count, statistics used in Mass Production Test.*/
	u32 rx_phy_ok_cnt;
	/*The Value of IO operation is depend of MptActType.*/
	u32 rf0[RF_PATH_MEM_SIZE];
	u32 rf1[RF_PATH_MEM_SIZE];
};

/* @1 ============================================================
 * 1  enumeration
 * 1 ============================================================
 */
enum TX_MODE_OFDM {
	OFDM_OFF = 0,
	OFDM_CONT_TX = 1,
	OFDM_SINGLE_CARRIER = 2,
	OFDM_SINGLE_TONE = 4,
};
/* @1 ============================================================
 * 1  function prototype
 * 1 ============================================================
 */
void phydm_mp_set_single_tone(bool is_single_tone, u8 path);

void phydm_mp_set_carrier_supp(bool is_carrier_supp, u32 rate_index);

void phydm_mp_set_single_carrier(bool is_single_carrier);

void phydm_mp_get_rx_ok(void);
#endif
