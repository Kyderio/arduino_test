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
#ifndef __INC_PHYDM_API_H_8721DA__
#define __INC_PHYDM_API_H_8721DA__

#if defined(CONFIG_AMEBADPLUS)

#define PHY_CONFIG_VERSION_8721DA "1.1.1"
/*#define CONFIG_TXAGC_DEBUG_8721DA*/

#define INVALID_RF_DATA 0xffffffff
#define INVALID_TXAGC_DATA 0xff
#define L_BND_DEFAULT_8721DA 0xd
#define number_channel_interferecne 4

#define config_phydm_read_rf_check_8721da(data) ((data) != INVALID_RF_DATA)
#define config_phydm_read_txagc_check_8721da(data) ((data) != INVALID_TXAGC_DATA)

enum agc_tab_sel_8721da {
	OFDM_2G_BW40_8721da		= 0,
	OFDM_5G_LOW_BAND_8721da		= 1,
	OFDM_5G_MID_BAND_8721da		= 2,
	OFDM_5G_HIGH_BAND_8721da		= 3,
	OFDM_2G_BW20_8721da		= 4,
	CCK_BW20_40_8721da			= 5,
};

struct txagc_table_8721da {
	u8 ref_pow_cck[MAX_RF_PATH_NUM];
	u8 ref_pow_ofdm[MAX_RF_PATH_NUM];
	s8 diff_t[NUM_RATE_N_1SS]; /*by rate differential table*/
};

u32 config_phydm_read_rf_reg_8721da(enum rf_path path, u32 reg_addr, u32 bit_mask);

bool config_phydm_write_rf_reg_8721da(enum rf_path path, u32 reg_addr,
		u32 bit_mask, u32 data);

bool phydm_write_txagc_1byte_8721da(u32 pw_idx, u8 hw_rate);

bool config_phydm_write_txagc_ref_8721da(u8 power_index, enum rf_path path,
		enum PDM_RATE_TYPE rate_type);

bool config_phydm_write_txagc_diff_8721da(s8 power_index1, s8 power_index2,
		s8 power_index3, s8 power_index4, u8 hw_rate);

s8 config_phydm_read_txagc_diff_8721da(u8 hw_rate);

u8 config_phydm_read_txagc_8721da(enum rf_path path, u8 hw_rate,
								  enum PDM_RATE_TYPE rate_type);

bool config_phydm_switch_band_8721da(u8 central_ch);

bool phydm_set_pd_lower_bound_cck(u8 new_igi);

bool config_phydm_switch_channel_8721da(u8 central_ch);

bool config_phydm_switch_bandwidth_8721da(u8 pri_ch, enum channel_width bw);

bool config_phydm_switch_channel_bw_8721da(u8 central_ch,
		u8 primary_ch_idx,
		enum channel_width bandwidth);

void phydm_cck_tx_shaping_filter_8721da(u8 central_ch);


bool config_phydm_parameter_init_8721da(enum odm_parameter_init type);

void phydm_nbi_notch_filter_manual_config_8721da(bool enable,
		u16 toneindex);

void phydm_csi_mask_config_8721da(bool enable, u16 toneindex,
								  u8 non_smo_left_width, u8 non_smo_right_width, u8 csi_left_tone, u8 csi_right_tone);

void config_phydm_set_txagc_to_hw_8721da(void);

bool config_phydm_write_txagc_8721da(u32 power_index, enum rf_path path, u8 hw_rate);
#endif /* RTL8721DA_SUPPORT */
#endif /*  __INC_PHYDM_API_H_8721DA__ */
