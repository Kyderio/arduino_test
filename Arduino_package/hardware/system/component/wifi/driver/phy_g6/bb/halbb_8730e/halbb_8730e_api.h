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
#ifndef __HALBB_8730E_API_H__
#define __HALBB_8730E_API_H__
#ifdef BB_8730E_SUPPORT
#ifdef HALBB_CONFIG_RUN_IN_DRV
#include "../halbb_api.h"
#endif

/*@--------------------------[Define]-------------------------------------*/
#define INVALID_RF_DATA 0xffffffff
#define RFREG_MASK		0xfffff
#define BB_PATH_MAX_8730E 1
#define GAIN_HIDE_EFUSE_A_2G_8730E 0x7C4
#define GAIN_HIDE_EFUSE_A_5GL_8730E 0x7C5
#define GAIN_HIDE_EFUSE_A_5GM_8730E 0x7C6
#define GAIN_HIDE_EFUSE_A_5GH_8730E 0x7C7


/*@--------------------------[Enum]------------------------------------------*/
/*@--------------------------[Prptotype]-------------------------------------*/
bool halbb_set_pwr_ul_tb_ofst(
	s16 pw_ofst, enum phl_phy_idx phy_idx);

void halbb_digital_cfo_comp(s32 curr_cfo);

void halbb_tx_triangular_shap_cfg(u8 shape_idx,
								  enum phl_phy_idx phy_idx);
void halbb_tx_dfir_shap_cck(u8 ch, u8 shape_idx);
bool halbb_ctrl_bw_ch(u8 pri_ch, u8 central_ch,
					  enum rtw_band_type band, enum channel_width bw, enum phl_phy_idx phy_idx);

bool halbb_ctrl_rx_path(enum rf_path rx_path);

bool halbb_ctrl_tx_path(enum rf_path tx_path);

void halbb_ctrl_tx_path_tmac(enum rf_path tx_path);

#ifdef HALBB_CONFIG_RUN_IN_DRV

void halbb_gpio_trsw_table(enum bb_path path,
						   bool path_en, bool trsw_tx,
						   bool trsw_rx, bool trsw, bool trsw_b);

void halbb_bb_reset(enum phl_phy_idx phy_idx);

void halbb_dfs_en(bool en);

void halbb_adc_en(bool en);

void halbb_tssi_cont_en(bool en, enum rf_path path);

void halbb_bb_reset_en(bool en, enum phl_phy_idx phy_idx);

u32 halbb_read_rf_reg(enum rf_path path, u32 reg_addr,
					  u32 bit_mask);

bool halbb_direct_write_rf_reg(enum rf_path path, u32 reg_addr,
							   u32 bit_mask, u32 data);

bool halbb_write_rf_reg(enum rf_path path, u32 reg_addr,
						u32 bit_mask, u32 data);

bool halbb_ctrl_bw(u8 pri_ch, enum channel_width bw,
				   enum phl_phy_idx phy_idx);

bool halbb_ctrl_ch(u8 central_ch, enum rtw_band_type band,
				   enum phl_phy_idx phy_idx);

void halbb_ctrl_cck_en(bool cck_en);

bool halbb_check_cck_en(void);

void halbb_ctrl_trx_path(enum rf_path tx_path,
						 u8 tx_nss, enum rf_path rx_path, u8 rx_nss);

void halbb_tssi_bb_reset(void);

u16 halbb_sco_mapping(enum rtw_band_type band, u8 central_ch);

bool halbb_ctrl_sco_cck(u8 pri_ch);

bool halbb_bw_setting(enum channel_width bw,
					  enum rf_path path);

bool halbb_ch_setting(u8 central_ch,
					  bool *is_2g_ch);

void halbb_ctrl_rf_mode(enum phl_rf_mode mode);

bool halbb_ctrl_ch2_80p80(u8 central_ch);

void halbb_ctrl_rx_cca(bool cca_en, enum phl_phy_idx phy_idx);

void halbb_ctrl_ofdm_en(bool ofdm_en,
						enum phl_phy_idx phy_idx);
bool halbb_set_txpwr_dbm(s16 power_dbm,
						 enum phl_phy_idx phy_idx);

void halbb_reset_bb_hw_cnt(void);

s16 halbb_get_txpwr_dbm(enum phl_phy_idx phy_idx);

s16 halbb_get_txinfo_txpwr_dbm(void);

bool halbb_set_cck_txpwr_idx(u16 power_idx,
							 enum rf_path tx_path);
u16 halbb_get_cck_txpwr_idx(enum rf_path tx_path);

s16 halbb_get_cck_ref_dbm(enum rf_path tx_path);

bool halbb_set_ofdm_txpwr_idx(u16 power_idx,
							  enum rf_path tx_path);

u16 halbb_get_ofdm_txpwr_idx(enum rf_path tx_path);

s16 halbb_get_ofdm_ref_dbm(enum rf_path tx_path);

void halbb_backup_info(enum phl_phy_idx phy_idx);

void halbb_restore_info(enum phl_phy_idx phy_idx);

void halbb_ctrl_btg(bool btg);

void halbb_ctrl_btc_preagc(bool bt_en);

bool halbb_set_txsc(u8 txsc, enum phl_phy_idx phy_idx);

bool halbb_set_bss_color(u8 bss_color,
						 enum phl_phy_idx phy_idx);

bool halbb_set_sta_id(u16 sta_id,
					  enum phl_phy_idx phy_idx);

void halbb_set_igi(u8 lna_idx, bool tia_idx,
				   u8 rxbb_idx, enum rf_path path);
void halbb_set_tx_pow_ref(enum phl_phy_idx phy_idx);
void halbb_dump_bb_reg(u32 *_used, char *output,
					   u32 *_out_len, bool dump_2_buff);
void halbb_dbgport_dump_all(u32 *_used, char *output,
							u32 *_out_len);
void halbb_physts_brk_fail_pkt_rpt(enum phl_phy_idx phy_idx);

bool halbb_rf_write_bb_reg(u32 addr, u32 mask, u32 data);

void halbb_pre_agc_en(bool enable);

void halbb_set_gain_error(u8 central_ch, u8 ant, u8 bt);
void halbb_set_normal_efuse(u8 central_ch, enum rtw_band_type band_type, enum rf_rx_path path);
void halbb_set_hidden_efuse(u8 central_ch, enum rtw_band_type band_type, enum rf_path path);
void halbb_get_normal_efuse_init(void);
void halbb_get_hidden_efuse_init(void);
void halbb_set_rxsc_rpl_comp(u8 central_ch);
u8 halbb_band_determine(u8 central_ch,
						enum rtw_band_type band_type, bool is_normal_efuse);
void halbb_normal_efuse_verify(s8 rx_gain_offset,
							   enum rf_path rx_path,
							   enum phl_phy_idx phy_idx);
void halbb_normal_efuse_verify_cck(s8 rx_gain_offset,
								   enum rf_path rx_path,
								   enum phl_phy_idx phy_idx);
void halbb_bb_rx_auxpath(u8 aux);
#endif
#endif
#endif /*  __INC_PHYDM_API_H_8730E__ */
