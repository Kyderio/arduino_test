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

#ifndef __HALRF_POWERTRACKING_H__
#define __HALRF_POWERTRACKING_H__

#define MAX_RF_PATH 4
#define		DPK_DELTA_MAPPING_NUM	13
#define		index_mapping_HP_NUM	15
#define	OFDM_TABLE_SIZE	43
#define	CCK_TABLE_SIZE			33
#define	CCK_TABLE_SIZE_88F	21
#define TXSCALE_TABLE_SIZE		37
#define CCK_TABLE_SIZE_8723D	41
/* JJ ADD 20161014 */
#define CCK_TABLE_SIZE_8710B	41
#define	CCK_TABLE_SIZE_8192F   41
#define	CCK_TABLE_SIZE_8721D   41
#define	CCK_TABLE_SIZE_8710C   41
#define	CCK_03DB_TABLE_SIZE_8710C   81
#define	OFDM_03DB_TABLE_SIZE_8710C	81


#define TXPWR_TRACK_TABLE_SIZE	30
#define DELTA_SWINGIDX_SIZE     30
#define DELTA_SWINTSSI_SIZE     61
#define BAND_NUM				4

#define AVG_THERMAL_NUM		8
#define IQK_MAC_REG_NUM		4
#define IQK_ADDA_REG_NUM		16
#define IQK_BB_REG_NUM_MAX	10

#define IQK_BB_REG_NUM		9



#define iqk_matrix_reg_num	8
#define IQK_MATRIX_SETTINGS_NUM	(14+24+21) /* Channels_2_4G_NUM + Channels_5G_20M_NUM + Channels_5G */

extern const u32 ofdm_swing_table[OFDM_TABLE_SIZE];
extern const u8 cck_swing_table_ch1_ch13[CCK_TABLE_SIZE][8];
extern const u8 cck_swing_table_ch14[CCK_TABLE_SIZE][8];

extern const u32 ofdm_swing_table_new[OFDM_TABLE_SIZE];
extern const u8 cck_swing_table_ch1_ch13_new[CCK_TABLE_SIZE][8];
extern const u8 cck_swing_table_ch14_new[CCK_TABLE_SIZE][8];
extern const u8 cck_swing_table_ch1_ch14_88f[CCK_TABLE_SIZE_88F][16];
extern const u8 cck_swing_table_ch1_ch13_88f[CCK_TABLE_SIZE_88F][16];
extern const u8 cck_swing_table_ch14_88f[CCK_TABLE_SIZE_88F][16];
extern const u32 cck_swing_table_ch1_ch14_8723d[CCK_TABLE_SIZE_8723D];
/* JJ ADD 20161014 */
extern const u32 cck_swing_table_ch1_ch14_8710b[CCK_TABLE_SIZE_8710B];
extern const u32 cck_swing_table_ch1_ch14_8192f[CCK_TABLE_SIZE_8192F];
extern const u32 cck_swing_table_ch1_ch14_8721d[CCK_TABLE_SIZE_8721D];
extern const u32 cck_swing_table_ch1_ch14_8710c[CCK_TABLE_SIZE_8710C];
extern const u32 cck_swing_table_03db_ch1_ch14_8710c[CCK_03DB_TABLE_SIZE_8710C];
extern const u32 ofdm_swing_table_03DB_8710c[OFDM_03DB_TABLE_SIZE_8710C];

extern const u32 tx_scaling_table_jaguar[TXSCALE_TABLE_SIZE];

void
odm_txpowertracking_init(
	void
);

#define dm_check_txpowertracking	odm_txpowertracking_check
/*
struct iqk_matrix_regs_setting {
	bool	is_iqk_done;
	s32		value[1][iqk_matrix_reg_num];
	bool	is_bw_iqk_result_saved[3];
};
*/
struct dm_rf_calibration_struct {
	/* for tx power tracking */
	u8  txpowertrack_control; /* for mp mode, turn off txpwrtracking as default */
	u8	thermal_value;
	u8	thermal_value_lck;
	u8	thermal_value_iqk;
	u8	thermal_value_avg_index;

	u8	tm_trigger: 1;
	u8	is_lck_in_progress: 1;
	u8	is_iqk_in_progress: 1;
};


void
odm_txpowertracking_check(
	void
);

void
odm_txpowertracking_thermal_meter_init(
	void
);

void
odm_txpowertracking_check_iot(
	void
);

#endif	/*#ifndef __HALRF_POWER_TRACKING_H__*/
