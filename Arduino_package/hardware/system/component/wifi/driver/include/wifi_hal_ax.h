
/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
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
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/

#ifdef _PHL_DEF_H_
#ifndef __WIFI_HAL_AX_H__
#define __WIFI_HAL_AX_H__

/*
* structs defined in this file are shared with halbb or halrf
*/
/*==================hal_general_def.h of g6 driver==============*/
#define FL_COMP_BB BIT16

/*control of pwr by limit and power by rate*/
enum hal_pwr_by_rate_setting {
	PW_BY_RATE_ALL_SAME = 0,
	PW_BY_RATE_ON = 1
};

enum hal_pwr_table_type {
	PWLMT_DISABLE = 0,
	PWBYRATE_AND_PWLMT = 1,
	PWR_TABLE_BY_EFUSE = 2
};

enum rtw_chip_id {
	CHIP_WIFI6_8852A,
	CHIP_WIFI6_8834A,
	CHIP_WIFI6_8852B,
	CHIP_WIFI6_8852C,
	CHIP_WIFI6_8192XB,
	CHIP_WIFI6_8832BR,
	CHIP_WIFI6_8852BP,
	CHIP_WIFI6_8730E,
	CHIP_WIFI6_8720E,
	CHIP_WIFI6_8721F,
};

/*================== Definitions of g6 driver ===================*/

enum hal_rate_bw {
	HAL_RATE_BW_20	= 0,
};

enum rtw_h2c_pkt_type { //AX_TODO:need fw further check
	H2CB_TYPE_CMD = 0,
	H2CB_TYPE_DATA = 1,
	H2CB_TYPE_LONG_DATA = 2,
	H2CB_TYPE_MAX = 0x3
};

struct rtw_g6_h2c_hdr { //AX_TODO:need fw further check
	u8 h2c_class; //0x0~0x7: Phydm; 0x8~0xF: RF; 0x10~0x17: BTC
	u8 h2c_func;
	u8 seq_valid: 1;
	u8 seq: 3;
	u8 seq_stop: 1;
	enum rtw_h2c_pkt_type type; //0:cmd ; 1:cmd+data ; 2:cmd+long data
	u16 content_len: 12;
	u16 rec_ack: 1; //Ack when receive H2C
	u16 done_ack: 1; //Ack when FW execute H2C cmd done
	u16 rsvd2: 2;
};

struct hal_dfs_rpt {
	u8 *dfs_ptr;
	u16 dfs_num;
	u8 phy_idx; /*phy0,phy1*/
};

/*HW_BAND0 - CMAC0 + PHY0 + S0*/
/*HW_BAND1 - CMAC1 + PHY1 + S1*/
enum phl_band_idx {
	HW_BAND_0,
	HW_BAND_1,
};

enum rtw_tpu_op_mode {
	TPU_NORMAL_MODE		= 0,
	TPU_DBG_MODE		= 1
};

enum phl_pwr_table {
	PWR_BY_RATE	= BIT0,
	PWR_LIMIT	= BIT1,
	PWR_LIMIT_RU	= BIT2
};

#define HAL_MAX_PATH	1

/*[TX Power Unit(TPU) array size]*/
#define TPU_SIZE_PWR_TAB	16 /*MCS0~MCS11(12) + {dcm_0,1,3,4}4 = 16*/
#define TPU_SIZE_PWR_TAB_lGCY	12 /*cck(4) + ofdm(8) = 12*/
#define TPU_SIZE_MODE		5  /*0~4: HE, VHT, HT, Legacy, CCK, */
#define TPU_SIZE_BW		5 /*0~4: 80_80, 160, 80, 40, 20*/
#define TPU_SIZE_RUA		3 /*{26, 52, 106}*/
#define TPU_SIZE_BW20_SC	8 /*8 * 20M = 160M*/
#define TPU_SIZE_BW40_SC	4 /*4 * 40M = 160M*/
#define TPU_SIZE_BW80_SC	2 /*2 * 80M = 160M*/
#define TPU_SIZE_BF		2 /*{NON_BF, BF}*/

struct rtw_tpu_pwr_by_rate_info { /*TX Power Unit (TPU)*/
	s8 pwr_by_rate_lgcy[TPU_SIZE_PWR_TAB_lGCY];
	s8 pwr_by_rate[HAL_MAX_PATH][TPU_SIZE_PWR_TAB];
};

struct rtw_tpu_pwr_imt_info { /*TX Power Unit (TPU)*/
	s8 pwr_lmt_cck_20m[HAL_MAX_PATH][TPU_SIZE_BF];
	s8 pwr_lmt_cck_40m[HAL_MAX_PATH][TPU_SIZE_BF];
	s8 pwr_lmt_lgcy_20m[HAL_MAX_PATH][TPU_SIZE_BF]; /*ofdm*/
	s8 pwr_lmt_20m[HAL_MAX_PATH][TPU_SIZE_BW20_SC][TPU_SIZE_BF];
	s8 pwr_lmt_40m[HAL_MAX_PATH][TPU_SIZE_BW40_SC][TPU_SIZE_BF];
	s8 pwr_lmt_80m[HAL_MAX_PATH][TPU_SIZE_BW80_SC][TPU_SIZE_BF];
	s8 pwr_lmt_160m[HAL_MAX_PATH][TPU_SIZE_BF];
	s8 pwr_lmt_40m_0p5[HAL_MAX_PATH][TPU_SIZE_BF];
	s8 pwr_lmt_40m_2p5[HAL_MAX_PATH][TPU_SIZE_BF];
};

struct rtw_tpu_info { /*TX Power Unit (TPU)*/
#if (PHYDM_VERSION == 3)
	/*[Pwr By rate]*/ /*-> HW: s(7,1)*/
	struct rtw_tpu_pwr_by_rate_info rtw_tpu_pwr_by_rate_i;
	/*[Pwr Limit]*/ /*-> HW: s(7,1)*/
	struct rtw_tpu_pwr_imt_info rtw_tpu_pwr_imt_i;

	enum rtw_tpu_op_mode op_mode; /*In debug mode, only debug tool control TPU APIs*/

	u16 tssi_16dBm_cw;
	/*[Ref Pwr]*/
	s16 ref_pow_ofdm; /*-> HW: s(9,2)*/
	s16 ref_pow_cck; /*-> HW: s(9,2)*/
	u16 ref_pow_ofdm_cw; /*BBCR 0x58E0[9:0]*/
	u16 ref_pow_cck_cw; /*BBCR 0x58E0[21:12]*/
	/*[Pwr Ofsset]*/ /*-> HW: s(7,1)*/
	s8 pwr_ofst_mode[TPU_SIZE_MODE]; /*0~4: HE, VHT, HT, Legacy, CCK, */
	s8 pwr_ofst_bw[TPU_SIZE_BW]; /*0~4: 80_80, 160, 80, 40, 20*/

	/*[Pwr Limit RUA]*/ /*-> HW: s(7,1)*/
	s8 pwr_lmt_ru[HAL_MAX_PATH][TPU_SIZE_RUA][TPU_SIZE_BW20_SC];
	u8 tx_ptrn_shap_idx;
	u8 tx_ptrn_shap_idx_cck;
	s8 ofst_int; /*SW: S(8,3) -16 ~ +15.875 (dB)*/
	u8 ofst_fraction; /*[0:3] * 0.125(dBm)*/
	u8 base_cw_0db; /*[63~39~15]: [+24~0~-24 dBm]*/

	bool normal_mode_lock_en;
#endif
	u8 b_pwr_lmt_en : 1; // 0: not refer to power by limit table and not set values to reg, 1: enable
	u8 b_pwr_rate_en : 1; // 0: all rate use the same tx power, set values to reg, 1: enable, use different tx power for different rate

};

struct rtw_bb_stat_t {
	u32 cnt_fail_all;
	u32 cnt_cck_fail;
	u32 cnt_ofdm_fail;
	u32 cnt_cca_all;
	u32 cnt_ofdm_cca;
	u32 cnt_cck_cca;
	u32 cnt_crc32_error_all;
	u32 cnt_he_crc32_error;
	u32 cnt_vht_crc32_error;
	u32 cnt_ht_crc32_error ;
	u32 cnt_ofdm_crc32_error;
	u32 cnt_cck_crc32_error;
	u32 cnt_crc32_ok_all;
	u32 cnt_he_crc32_ok;
	u32 cnt_vht_crc32_ok;
	u32 cnt_ht_crc32_ok;
	u32 cnt_ofdm_crc32_ok;
	u32 cnt_cck_crc32_ok;
	u32 cck_mac_txen;
	u32 cck_phy_txon;
	u32 ofdm_mac_txen;
	u32 ofdm_phy_txon;
};

enum phl_rf_mode {
	RF_MODE_SHUTDOWN	= 1,
	RF_MODE_STANDBY		= 2,
};



#define FL_CFG_OP_SET 0

#define FL_CFG_TYPE_LEVEL 0
#define FL_CFG_TYPE_OUTPUT 1
#define FL_CFG_TYPE_COMP 2

#define FL_LV_LOUD 4

#define FL_OP_C2H BIT1

struct rtw_hal_mac_ax_cctl_info {
	/* dword 0 */
	u32 datarate: 9;
	u32 force_txop: 1;
	u32 data_bw: 2;
	u32 data_gi_ltf: 3;
	u32 darf_tc_index: 1;
	u32 arfr_ctrl: 4;
	u32 acq_rpt_en: 1;
	u32 mgq_rpt_en: 1;
	u32 ulq_rpt_en: 1;
	u32 twtq_rpt_en: 1;
	u32 rsvd0: 1;
	u32 disrtsfb: 1;
	u32 disdatafb: 1;
	u32 tryrate: 1;
	u32 ampdu_density: 4;
	/* dword 1 */
	u32 data_rty_lowest_rate: 9;
	u32 ampdu_time_sel: 1;
	u32 ampdu_len_sel: 1;
	u32 rts_txcnt_lmt_sel: 1;
	u32 rts_txcnt_lmt: 4;
	u32 rtsrate: 9;
	u32 rsvd1: 2;
	u32 vcs_stbc: 1;
	u32 rts_rty_lowest_rate: 4;
	/* dword 2 */
	u32 data_tx_cnt_lmt: 6;
	u32 data_txcnt_lmt_sel: 1;
	u32 max_agg_num_sel: 1;
	u32 rts_en: 1;
	u32 cts2self_en: 1;
	u32 cca_rts: 2;
	u32 hw_rts_en: 1;
	u32 rts_drop_data_mode: 2;
	u32 preld_en: 1;
	u32 ampdu_max_len: 11;
	u32 ul_mu_dis: 1;
	u32 ampdu_max_time: 4;
	/* dword 3 */
	u32 max_agg_num: 9;
	u32 ba_bmap: 2;
	u32 rsvd3: 5;
	u32 vo_lftime_sel: 3;
	u32 vi_lftime_sel: 3;
	u32 be_lftime_sel: 3;
	u32 bk_lftime_sel: 3;
	u32 sectype: 4;
	/* dword 4 */
	u32 multi_port_id: 3;
	u32 bmc: 1;
	u32 mbssid: 4;
	u32 navusehdr: 1;
	u32 txpwr_mode: 3;
	u32 data_dcm: 1;
	u32 data_er: 1;
	u32 data_ldpc: 1;
	u32 data_stbc: 1;
	u32 a_ctrl_bqr: 1;
	u32 a_ctrl_uph: 1;
	u32 a_ctrl_bsr: 1;
	u32 a_ctrl_cas: 1;
	u32 data_bw_er: 1;
	u32 lsig_txop_en: 1;
	u32 rsvd4: 5;
	u32 ctrl_cnt_vld: 1;
	u32 ctrl_cnt: 4;
	/* dword 5 */
	u32 resp_ref_rate: 9;
	u32 rsvd5: 3;
	u32 all_ack_support: 1;
	u32 bsr_queue_size_format: 1;
	u32 bsr_om_upd_en: 1;
	u32 macid_fwd_idc: 1;
	u32 ntx_path_en: 4;
	u32 path_map_a: 2;
	u32 path_map_b: 2;
	u32 path_map_c: 2;
	u32 path_map_d: 2;
	u32 antsel_a: 1;
	u32 antsel_b: 1;
	u32 antsel_c: 1;
	u32 antsel_d: 1;
	/* dword 6 */
	u32 addr_cam_index: 8;
	u32 paid: 9;
	u32 uldl: 1;
	u32 doppler_ctrl: 2;
	u32 nominal_pkt_padding: 2;
	u32 nominal_pkt_padding40: 2;
	u32 txpwr_tolerence: 6;
	/*u32 rsvd9:2;*/
	u32 nominal_pkt_padding80: 2;
	/* dword 7 */
	u32 nc: 3;
	u32 nr: 3;
	u32 ng: 2;
	u32 cb: 2;
	u32 cs: 2;
	u32 csi_txbf_en: 1;
	u32 csi_stbc_en: 1;
	u32 csi_ldpc_en: 1;
	u32 csi_para_en: 1;
	u32 csi_fix_rate: 9;
	u32 csi_gi_ltf: 3;
	u32 nominal_pkt_padding160: 2;
	u32 csi_bw: 2;
};

#define HAL_MAX_MU_STA_NUM 6
struct hal_mu_score_tbl_ctrl {
	u32 mu_sc_thr: 2;
	u32 mu_opt: 1;
	u32 rsvd: 29;
};
#define HAL_MAX_MU_SCORE_SIZE 8 /* Unit: Byte */
struct hal_mu_score_tbl_score {
	u8 valid;
	u16 macid;
	u8 score[HAL_MAX_MU_SCORE_SIZE]; /*by case: [1:0], [3:2], ..... */
};
struct hal_mu_score_tbl {
	struct hal_mu_score_tbl_ctrl mu_ctrl;
	//_os_lock lock;
	u8 num_mu_sta; /*By IC, shall alway <= than HAL_MAX_MU_STA_NUM , 0 = tbl invalid */
	u8 sz_mu_score; /*By IC, shall alway <= than HAL_MAX_MU_SCORE_SIZE , 0 = score invalid */
	struct hal_mu_score_tbl_score mu_score[HAL_MAX_MU_STA_NUM]; /* mu_score[num_mu_sta] */
};

enum rtw_dv_sel {
	DAV,
	DDV,
};
#endif
#endif
