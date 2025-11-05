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

#ifndef __HALPHYRF_H__
#define __HALPHYRF_H__
#include "halrf/halrf_powertracking_iot.h"
#include "halrf/halrf_kfree.h"


enum spur_cal_method {
	PLL_RESET,
	AFE_PHASE_SEL
};

enum pwrtrack_method {
	BBSWING,
	TXAGC,
	MIX_MODE,
	TSSI_MODE,
	MIX_2G_TSSI_5G_MODE,
	MIX_5G_TSSI_2G_MODE,
	CLEAN_MODE
};

struct txpwrtrack_cfg {
	u8		swing_table_size_cck;
	u8		swing_table_size_ofdm;
	u8		threshold_iqk;
	u8		threshold_dpk;
	u8		threshold_lck;
	u8		average_thermal_num;
	u8		rf_path_count;
	u32		thermal_reg_addr;
	void	(*odm_tx_pwr_track_set_pwr)(void *, enum pwrtrack_method, u8, u8);
	void	(*do_iqk)(void *, u8, u8, u8);
	void	(*phy_lc_calibrate)(void *);
	void	(*get_delta_swing_table)(void *, u8 **, u8 **, u8 **, u8 **);
	void	(*get_delta_swing_table8814only)(void *, u8 **, u8 **, u8 **, u8 **);
	void	(*get_delta_swing_xtal_table)(void *, s8 **, s8 **);
	void	(*odm_txxtaltrack_set_xtal)(void *);
	void	(*halrf_pa_dynamic_bias)(void *, u8, s8);
};


void
odm_clear_txpowertracking_state(
	void
);

void
odm_txpowertracking_callback_thermal_meter(
	void
);



#define ODM_TARGET_CHNL_NUM_2G_5G	59

u8
odm_get_right_chnl_place_for_iqk(
	u8 chnl
);

void phydm_rf_init(void);
void phydm_rf_watchdog(void);

#endif	/*#ifndef __HALPHYRF_H__*/
