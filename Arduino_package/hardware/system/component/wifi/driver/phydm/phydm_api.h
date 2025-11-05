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

#ifndef __PHYDM_API_H__
#define __PHYDM_API_H__

/* 2019.10.22 Add get/shift rxagc API for 8822C*/
#define PHYDM_API_VERSION "2.3"

/* @1 ============================================================
 * 1  Definition
 * 1 ============================================================
 */

#define CN_CNT_MAX 10 /*@max condition number threshold*/

#define FUNC_ENABLE 1
#define FUNC_DISABLE 2

#define PHYDM_IS_LEGACY_RATE(rate) ((rate <= ODM_RATE54M) ? true : false)
#define PHYDM_IS_CCK_RATE(rate) ((rate <= ODM_RATE11M) ? true : false)

/*@NBI API------------------------------------*/
#define NBI_128TONE 27 /*register table size*/
#define NBI_256TONE 59 /*register table size*/

#define NUM_START_CH_80M 7
#define NUM_START_CH_40M 14

#define CH_OFFSET_40M 2
#define CH_OFFSET_80M 6

#define FFT_128_TYPE 1
#define FFT_256_TYPE 2

#define FREQ_POSITIVE 1
#define FREQ_NEGATIVE 2
/*@------------------------------------------------*/

enum phystat_rpt {
	PHY_PWDB = 0,
	PHY_EVM = 1,
	PHY_CFO = 2,
	PHY_RXSNR = 3,
	PHY_LGAIN = 4,
	PHY_HT_AAGC_GAIN = 5,
};

#ifndef PHYDM_COMMON_API_SUPPORT
#define INVALID_RF_DATA 0xffffffff
#define INVALID_TXAGC_DATA 0xff
#endif

/* @1 ============================================================
 * 1  structure
 * 1 ============================================================
 */

struct phydm_api_stuc {
	u32 rxiqc_reg1; /*N-mode: for pathA REG0xc14*/
	u32 rxiqc_reg2; /*N-mode: for pathB REG0xc1c*/
	u8 tx_queue_bitmap; /*REG0x520[23:16]*/
};

/* @1 ============================================================
 * 1  enumeration
 * 1 ============================================================
 */

/* @1 ============================================================
 * 1  function prototype
 * 1 ============================================================
 */
bool phydm_is_cck_rate(u8 rate);

bool phydm_is_ofdm_rate(u8 rate);

bool phydm_is_ht_rate(u8 rate);

bool phydm_is_vht_rate(u8 rate);

u8 phydm_legacy_rate_2_spec_rate(u8 rate);

u8 phydm_rate_2_rate_digit(u8 rate);

u8 phydm_rate_to_num_ss(u8 data_rate);

enum channel_width phydm_rxsc_2_bw(u8 rxsc);

void phydm_reset_bb_hw_cnt(void);

void phydm_cnt_statistics(void);

void phydm_trx_antenna_setting_init(u8 num_rf_path);

int phydm_stop_ic_trx(u8 set_type);

void phydm_dis_cck_trx(u8 set_type);

bool phydm_check_cck_en(void);

void phydm_nbi_enable(u32 enable);

int phydm_csi_mask_setting(u32 enable, u32 ch, u32 bw, u32 f_intf,
						  u32 sec_ch);

int phydm_nbi_setting(u32 enable, u32 ch, u32 bw, u32 f_intf,
					 u32 sec_ch);

void phydm_nbi_debug(char input[][16], u32 *_used,
					 char *output, u32 *_out_len);

void phydm_csi_debug(char input[][16], u32 *_used,
					 char *output, u32 *_out_len);

void phydm_stop_3_wire(u8 set_type);

#ifdef PHYDM_IC_JGR3_SERIES_SUPPORT

int phydm_csi_mask_setting_jgr3(u32 enable, u32 ch, u32 bw,
							   u32 f_intf, u32 sec_ch, u8 wgt);

void phydm_set_csi_mask_jgr3(u32 tone_idx_tmp, u8 tone_direction,
							 u8 wgt);

int phydm_nbi_setting_jgr3(u32 enable, u32 ch, u32 bw, u32 f_intf,
						  u32 sec_ch, u8 path);

void phydm_set_nbi_reg_jgr3(u32 tone_idx_tmp, u8 tone_direction,
							u8 path);

void phydm_nbi_enable_jgr3(u32 enable, u8 path);

#endif

#ifdef PHYDM_COMMON_API_SUPPORT
void phydm_reset_txagc(void);

bool
phydm_api_set_txagc(u32 power_index, enum rf_path path,
					u8 hw_rate, bool is_single_rate);

u8 phydm_api_get_txagc(enum rf_path path, u8 hw_rate);

bool
phydm_api_switch_bw_channel(u8 central_ch, u8 primary_ch_idx,
							enum channel_width bandwidth);

void phydm_init_rfe_ctrl_reg(u8 rfe_idx);
void phydm_rfe_ctrl_extfem_by_band(u8 rfe_idx, enum rtw_band_type band);
void phydm_bb_rf_rx_ant(u8 rfe_idx, u8 ant);
#endif

void phydm_set_crc32_cnt2_rate(u8 rate_idx);
#endif
