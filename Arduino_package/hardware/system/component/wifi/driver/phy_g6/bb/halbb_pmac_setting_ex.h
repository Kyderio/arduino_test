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

#ifndef _HALBB_PMAC_SETTING_EX_H_
#define _HALBB_PMAC_SETTING_EX_H_
#include "halbb_ic_hw_info.h"
#include "halbb_pmac_setting.h"

/*  ============================================================
 			   structure
    ============================================================
*/
struct halbb_pmac_info {
	u8 en_pmac_tx: 1; /*0: PMAC Tx Off 1: PMAC Tx On */
	u8 is_cck: 1;
	u8 mode: 3; /*1: Packet TX 3:Continuous TX */
	u8 rsvd: 3;
	u16 tx_cnt;
	u16 period; // unit=50ns
	u16 tx_time; // us
	u8 duty_cycle; // for fw trig. tx used
	bool cck_lbk_en;
};

/*  ============================================================
 		     Function Prototype
    ============================================================
*/


void halbb_set_pmac_tx(struct halbb_pmac_info *tx_info,
					   enum phl_phy_idx phy_idx);

void halbb_set_tmac_tx(enum phl_phy_idx phy_idx);

bool halbb_set_txpwr_dbm(s16 pwr_dbm,
						 enum phl_phy_idx phy_idx);

s16 halbb_get_txpwr_dbm(enum phl_phy_idx phy_idx);

s16 halbb_get_txinfo_txpwr_dbm(void);

bool halbb_set_cck_txpwr_idx(u16 pwr_idx,
							 enum rf_path tx_path);

u16 halbb_get_cck_txpwr_idx(enum rf_path tx_path);

s16 halbb_get_cck_ref_dbm(enum rf_path tx_path);

bool halbb_set_ofdm_txpwr_idx(u16 pwr_idx,
							  enum rf_path tx_path);

u16 halbb_get_ofdm_txpwr_idx(enum rf_path tx_path);

s16 halbb_get_ofdm_ref_dbm(enum rf_path tx_path);

void halbb_backup_info(enum phl_phy_idx phy_idx);

void halbb_restore_info(enum phl_phy_idx phy_idx);

bool halbb_set_txsc(u8 txsc, enum phl_phy_idx phy_idx);

bool halbb_set_bss_color(u8 bss_color,
						 enum phl_phy_idx phy_idx);

bool halbb_set_sta_id(u16 sta_id, enum phl_phy_idx phy_idx);

#endif
