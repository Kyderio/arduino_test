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
#ifndef __HALBB_PHYSTS_H__
#define __HALBB_PHYSTS_H__

#define VAR_LENGTH 0xff
#define TRANS_2_RSSI(X) (X >> 1)
#define PHYSTS_HDR_LEN	8
#define TB_USER_MAX	4
#define MU_USER_MAX	4
#define PSTS_USR(x,y)	psts_##x_usr_##y

#define IE11_PKT_INFO_LEN 10

/* IE 0/1 is basic */
#define HALBB_PHYSTS_PARSING_DEFAULT /* parse IE 2/3/4/8/13 in the future: reduce ram size */

enum bb_physts_bw_info {
	PSTS_BW5 	= 0,
	PSTS_BW10 	= 1,
	PSTS_BW20 	= 2,
	PSTS_BW40 	= 3,
	PSTS_BW80 	= 4,
	PSTS_BW160 	= 5,
	PSTS_BW80_80	= 6,
	PSTS_BW_MAX
};

enum bb_physts_ie_t {
	IE00_CMN_CCK			= 0,
	IE01_CMN_OFDM			= 1,
	IE02_CMN_EXT_AX			= 2,
	IE03_CMN_EXT_SEG_1		= 3,
	IE04_CMN_EXT_PATH_A		= 4,
	IE05_CMN_EXT_PATH_B		= 5,
	IE06_CMN_EXT_PATH_C		= 6,
	IE07_CMN_EXT_PATH_D		= 7,
	IE08_FTR_CH			= 8,
	IE09_FTR_PLCP_0			= 9,
	IE10_FTR_PLCP_EXT		= 10,
	IE11_FTR_PLCP_HISTOGRAM		= 11,
	IE12_MU_EIGEN_INFO		= 12,
	IE13_DL_MU_DEF			= 13,
	IE14_TB_UL_CQI			= 14,
	IE15_TB_UL_DEF			= 15,
	IE16_RSVD16			= 16,
	IE17_TB_UL_CTRL			= 17,
	IE18_DBG_OFDM_FD_CMN		= 18,
	IE19_DBG_OFDM_TD_CMN		= 19,
	IE20_DBG_OFDM_FD_USER_SEG_0	= 20,
	IE21_DBG_OFDM_FD_USER_SEG_1	= 21,
	IE22_DBG_OFDM_FD_USER_AGC	= 22,
	IE23_RSVD23			= 23,
	IE24_DBG_OFDM_TD_PATH_A		= 24,
	IE25_DBG_OFDM_TD_PATH_B		= 25,
	IE26_DBG_OFDM_TD_PATH_C		= 26,
	IE27_DBG_OFDM_TD_PATH_D		= 27,
	IE28_DBG_CCK_PATH_A		= 28,
	IE29_DBG_CCK_PATH_B		= 29,
	IE30_DBG_CCK_PATH_C		= 30,
	IE31_DBG_CCK_PATH_D		= 31,
	IE_PHYSTS_LEN_ALL		= 32
};

static const char bb_physts_bitmap_type_t[][10] = {
	"SRH_FAIL",
	"BRK_BY_TX",
	"CCA_SPF",
	"OFDM_BRK",
	"CCK_BRK",
	"DLMU_SPF",
	"HE_MU",
	"VHT_MU",
	"TB_SPF",
	"N/A",
	"TB",
	"CCK",
	"LEGACY",
	"HT",
	"VHT",
	"HE",
};

struct bb_physts_rslt_hdr_info {
	u8 rssi[4];
#ifdef HALBB_DBG_TRACE_SUPPORT
	u8 rssi_td[4];
#endif
	u8 rssi_avg;
	enum bb_physts_bitmap_t ie_map_type;
};

struct bb_physts_rslt_0_info {
	//u8 *ie_00_addr;
	u8 rx_path_en_cck;
#ifdef HALBB_DBG_TRACE_SUPPORT
	s16 cfo_avg_cck; /*S(12,2), -512~+511.75 kHz*/
	u8 evm_avg_cck;
	u8 pop_idx_cck;
	u16 rpl; /*U(9,2)*/

#endif
	u8 avg_idle_noise_pwr_cck; /*u(8,1)*/
};

struct bb_physts_rslt_1_info {
#ifdef HALBB_DBG_TRACE_SUPPORT
	u8 *ie_01_addr;
	u8 pop_idx;
	u8 rpl_fd; /*u(8,1)*/
#endif
	s16 cfo_avg; /*S(12,2), -512~+511.75 kHz, FD tracking CFO*/
	s16 cfo_pab_avg; /*S(12,2), -512~+511.75 kHz, preamble CFO*/
	u8 rx_path_en;
	u8 evm_max;
	u8 evm_min;
	u8 snr_avg;
	u8 cn_avg;
	u8 avg_idle_noise_pwr; /*u(8,1)*/
	u8 rxsc;
	u8 ch_idx;
	enum channel_width bw_idx;

	u8 is_su: 1; /*if (not MU && not OFDMA), is_su = 1*/
	u8 is_ldpc: 1;
	u8 is_ndp: 1;
	u8 is_stbc: 1;
	u8 grant_bt: 1;
	u8 is_awgn: 1;
	u8 is_bf: 1;
};

struct bb_physts_rslt_2_info {
	u8 *ie_02_addr;
	u8 max_nsts;
	u8 ltf_type;
	u8 gi;
	s32 c_cfo_i;
	u8 rx_info_1;
	u8 rx_state_feq;
	s32 c_cfo_q;
	u8 est_cmped_phase;
	u8 pkt_extension;
	s32 f_cfo_i;
	u8 n_ltf;
	u16 n_sym;
	s32 f_cfo_q;
	bool midamble;
	bool is_mu_mimo;
	bool is_dl_ofdma;
	bool is_dcm;
	bool is_doppler;
};

struct bb_physts_rslt_3_info {
	u8 *ie_03_addr;
	u8 avg_cn_seg1;
	u8 sigval_below_th_tone_cnt_seg1;
	u8 cn_excess_th_tone_cnt_seg1;
	u16 avg_cfo_seg1;
	u16 avg_cfo_premb_seg1;
	u8 est_cmped_phase_seg1;
	u8 avg_snr_seg1;
	u32 c_cfo_i_seg1;
	u32 c_cfo_q_seg1;
	u32 f_cfo_i_seg1;
	u32 f_cfo_q_seg1;
	u8 ch_idx_seg1;
	u8 evm_max_seg1;
	u8 evm_min_seg1;
};

struct bb_physts_rslt_4_info {
	u8 *ie_04_addr;
	u8 ant_idx;
	s8 sig_val_y;
	u8 rf_gain_idx;
	u8 snr_lgy;
	u8 evm_ss_y;
	u8 td_ant_weight;
	s8 dc_est_re;
	s8 dc_est_im;
	bool rf_tia_gain_idx;
	bool tia_shrink_indicator;
	//bool ant_idx_0_msb;
};

struct bb_physts_rslt_8_info {
	u8 *ie_08_addr;
	u8 rxsc;
	u8 n_rx;
	u8 n_sts;
	u16 ch_info_len;
	u8 evm_1_sts;
	u8 evm_2_sts;
	u8 avg_idle_noise_pwr;
	bool is_ch_info_len_valid;
	s16 *ch_info_addr;
};

struct bb_physts_rslt_9_info {
	u8 *ie_09_addr;
	u32 l_sig;
	u32 sig_a1;
	u16 sig_a2;
};

struct bb_physts_rslt_11_info {
	u8 *ie_11_addr;
	u32 l_sig;
	u32 sig_a1;
	u16 sig_a2;
	u16 time_stamp;
	u8 rx_pkt_info_idx;
	u8 tx_pkt_info_idx;
};

struct bb_physts_user_info_ie_12 {
	u8 sig_val_ss0_seg_cr_user_i;
	u8 sig_val_ss1_seg_cr_user_i;
	u8 sig_val_ss2_seg_cr_user_i;
	u8 sig_val_ss3_seg_cr_user_i;
	u8 sig_bad_tone_cnt_seg_cr_user_i;
	u8 cn_bad_tone_cnt_seg_cr_user_i;
};

struct bb_physts_rslt_12_info {
	u8 *ie_12_addr;
	u8 n_user;
	struct bb_physts_user_info_ie_12 bb_physts_uer_info[MU_USER_MAX];
};

struct bb_physts_user_info_ie_13 {
	u8 is_bf;
	u8 fec_type;
	u8 mcs;
	u8 pilot_exist;
	u8 n_sts;
	u8 n_sts_ru_total;
	u8 is_awgn;
	u8 is_mu_mimo;
	u8 pdp_he_ltf_and_gi_type;
	u8 start_sts;
	u8 rx_evm_max_seg_cr;
	u8 rx_evm_min_seg_cr;
	s8 snr;
	u8 ru_alloc;
	u8 is_dcm;
	u8 avg_cn_seg_cr;
	u16 sta_id;
};

struct bb_physts_rslt_13_info {
	u8 *ie_13_addr;
	u8 n_user;
	struct bb_physts_user_info_ie_13 bb_physts_uer_info[MU_USER_MAX];
	u8 n_not_sup_sta;
};

struct bb_physts_user_info_ie_14 {
	u8 cqi_bitmap_ul_tb;
	u8 cqi_raw_len_ul_tb;
	u8 *cqi_raw_ul_tb_addr;
};

struct bb_physts_rslt_14_info {
	u8 *ie_14_addr;
	u8 rxinfo_ndp_en;
	u8 n_user;
	struct bb_physts_user_info_ie_14 bb_physts_uer_info[MU_USER_MAX];

};

struct bb_physts_user_info_ie_15 {
	/* 64bit cmn_info */
	u8 mcs;
	u8 fec_type;
	u8 is_bf;

	u8 n_sts_ru_total;
	u8 n_sts;
	u8 pilot_exist;

	u8 start_sts;
	u8 pdp_he_ltf_and_gi_type;
	u8 is_mu_mimo;
	u8 is_awgn;

	u8 rx_evm_max_seg_cr;
	u8 rx_evm_min_seg_cr;
	s8 snr;
	u8 ru_alloc;

	u8 avg_cn_seg_cr;
	u8 is_dcm;

	/* others */
	u8 uid;
	s16 avg_cfo_seg0;
	u16 rssi_m_ul_tb;
};

struct bb_physts_rslt_15_info {
	u8 *ie_15_addr;
	u8 n_user;
	struct bb_physts_user_info_ie_15 bb_physts_uer_info[MU_USER_MAX];

};

struct bb_physts_cmn_info_ie_17 {
	bool stbc_en;
	bool ldpc_extra;
	bool doppler_en;
	bool midamle_mode;
	u8 gi_type;
	u8 ltf_type;
	u8 n_ltf;
	u8 n_sym;
	u8 pe_idx;
	u8 pre_fec_factor;
	u8 n_usr;
	bool mumimo_ltf_mode_en;
	bool ndp;
	u8 pri_exp_rssi_dbm;
	u8 dbw_idx;

	u8 rsvd;

	u16 rxtime;
};

struct bb_physts_user_info_ie_17 {
	u8 u_id;
	u8 ru_alloc;
	u8 n_sts_ru_tot;

	u8 rsvd1;

	u8 strt_sts;
	u8 n_sts;
	bool fec_type;
	u8 mcs;

	u8 rsvd2;

	bool dcm_en;

	u8 rsvd3;
};

struct bb_physts_rslt_17_info {
	u8 *ie_17_addr;
	u8 n_user;
	struct bb_physts_cmn_info_ie_17 bb_physts_cmn_info;
	struct bb_physts_user_info_ie_17 bb_physts_uer_info[MU_USER_MAX];
};

struct bb_physts_cnt_info {
#ifdef HALBB_DBG_TRACE_SUPPORT
	u16 all_cnt;
	u16 is_2_self_cnt;
	u16 err_ie_cnt;
	u16 ok_ie_cnt;
	u16 err_len_cnt;
	u32 invalid_he_cnt;

#endif
	bool invalid_he_occur;
};

struct bb_physts_info {
	u8 rx_path_en;
#ifdef HALBB_DBG_TRACE_SUPPORT
	u8 physts_dump_mode; /*0: disable, 1:raw data, 2: msg mode, 3:raw data + msg mode*/
	u16 physts_dump_idx;
	bool is_valid; // used for UI parsing
	u16 show_phy_sts_cnt;
	u16 show_phy_sts_max_cnt;
	u16 ie_len_curr[IE_PHYSTS_LEN_ALL];
#endif
	bool show_phy_sts_all_pkt;
	bool dfs_phy_sts_privilege;// used for CAC period in DFS channel
	bool rssi_cvrt_2_rpl_en;
	u8 rpl_path[4]; /*u(8,1)*/
	u8 rpl_avg; /*u(8,1)*/
	u8 frc_mu; /*force data type to SU/MU(debug mode)*/
	u8 tmp_mcs;/*fake MCS (debug mode)*/
	u8 tmp_sts;/*fake STS (debug mode)*/
	struct bb_rate_info		bb_rate_i;
	struct bb_physts_cnt_info	bb_physts_cnt_i;
	struct bb_physts_rslt_hdr_info	bb_physts_rslt_hdr_i;
	struct bb_physts_rslt_0_info	bb_physts_rslt_0_i;
	struct bb_physts_rslt_1_info	bb_physts_rslt_1_i;
#ifndef HALBB_PHYSTS_PARSING_DEFAULT
	struct bb_physts_rslt_2_info	bb_physts_rslt_2_i;
	struct bb_physts_rslt_3_info	bb_physts_rslt_3_i;
	struct bb_physts_rslt_4_info	bb_physts_rslt_4_i;
	struct bb_physts_rslt_8_info	bb_physts_rslt_8_i;
	struct bb_physts_rslt_13_info	bb_physts_rslt_13_i;
#endif
#ifdef HALBB_DBG_TRACE_SUPPORT
	struct bb_physts_rslt_9_info	bb_physts_rslt_9_i;
	struct bb_physts_rslt_11_info	bb_physts_rslt_11_i;
	struct bb_physts_rslt_12_info	bb_physts_rslt_12_i;
	struct bb_physts_rslt_14_info	bb_physts_rslt_14_i;
	struct bb_physts_rslt_15_info	bb_physts_rslt_15_i;
	struct bb_physts_rslt_17_info	bb_physts_rslt_17_i;
#endif
};

/*@--------------------------[Prptotype]-------------------------------------*/
void halbb_physts_cvrt_2_mp(void);
void halbb_physts_ie_bitmap_en(enum bb_physts_bitmap_t type,
							   enum bb_physts_ie_t ie, bool en);
void halbb_phy_sts_manual_trig(enum bb_mode_type mode, u8 ss);
void halbb_physts_watchdog(void);
void halbb_physts_parsing_init(void);
#endif
