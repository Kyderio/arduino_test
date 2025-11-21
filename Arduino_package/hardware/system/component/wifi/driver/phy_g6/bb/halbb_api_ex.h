/******************************************************************************
 *
 * Copyright(c) 2020 Realtek Corporation.
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
 *****************************************************************************/
#ifndef _HALBB_API_EX_H_
#define _HALBB_API_EX_H_
#include "halbb_ic_hw_info.h"
#include "halbb_api.h"
/*@--------------------------[Prptotype]-------------------------------------*/
struct bb_mcc_i {
	enum role_type type;
	struct rtw_chan_def *chandef;
	u32 *macid_bitmap;
	u8 macid_map_len;
	u8 self_macid;
};

void halbb_reset_bb(void);

u32 halbb_read_rf_reg(enum rf_path path, u32 addr, u32 mask);

bool halbb_write_rf_reg(enum rf_path path, u32 addr, u32 mask,
						u32 data);
bool halbb_rf_set_bb_reg(u32 addr, u32 bit_mask, u32 data);
u32 halbb_rf_get_bb_reg(u32 addr, u32 mask);
void halbb_ctrl_rf_mode(enum phl_rf_mode mode);

bool halbb_ctrl_rx_path(enum rf_path rx_path);

bool halbb_ctrl_tx_path(enum rf_path rx_path);

void halbb_ctrl_trx_path(enum rf_path tx_path, u8 tx_nss,
						 enum rf_path rx_path, u8 rx_nss);

void halbb_bb_reset(enum phl_phy_idx phy_idx);

void halbb_adc_en(bool en);

void halbb_tssi_cont_en(bool en, enum rf_path path);

void halbb_bb_reset_en(bool en, enum phl_phy_idx phy_idx);

bool halbb_ctrl_bw(u8 pri_ch, enum channel_width bw,
				   enum phl_phy_idx phy_idx);

bool halbb_ctrl_bw_ch(u8 pri_ch, u8 central_ch, enum rtw_band_type band,
					  enum channel_width bw, enum phl_phy_idx phy_idx);

void halbb_ctrl_rx_cca(bool cca_en, enum phl_phy_idx phy_idx);

void halbb_ctrl_ofdm_en(bool ofdm_enable,
						enum phl_phy_idx phy_idx);

void halbb_ctrl_btg(bool btg);

void halbb_pop_en(bool en, enum phl_phy_idx phy_idx);

bool halbb_querry_pop_en(enum phl_phy_idx phy_idx);

bool halbb_set_pd_lower_bound(u8 bound,
							  enum phl_phy_idx phy_idx);

bool halbb_set_pd_lower_bound_cck(u8 bound,
								  enum phl_phy_idx phy_idx);

u8 halbb_querry_pd_lower_bound(bool get_en_info,
							   enum phl_phy_idx phy_idx);

void halbb_set_igi(u8 lna_idx, bool tia_idx, u8 rxbb_idx,
				   enum rf_path path);
void halbb_set_tx_pow_pattern_shap(u8 ch,
								   bool is_ofdm, enum phl_phy_idx phy_idx);
void halbb_set_tx_pow_ref(enum phl_phy_idx phy_idx);

void halbb_normal_efuse_verify(s8 rx_gain_offset,
							   enum rf_path rx_path, enum phl_phy_idx phy_idx);

void halbb_normal_efuse_verify_cck(s8 rx_gain_offset,
								   enum rf_path rx_path,
								   enum phl_phy_idx phy_idx);

void halbb_bb_rf_rx_ant(u8 rfe_idx, u8 ant);
void halbb_bb_rx_auxpath(u8 aux);
#endif