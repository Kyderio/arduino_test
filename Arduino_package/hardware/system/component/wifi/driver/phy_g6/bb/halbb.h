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

#ifndef __HALBB_H__
#define __HALBB_H__

/*@--------------------------[Define] ---------------------------------------*/

#define	ACTIVE_TP_THRESHOLD	1
#define BB_WATCH_DOG_PERIOD	2 /*sec*/
#define is_sta_active(psta_mlmepriv)	((psta_mlmepriv) && (psta_mlmepriv->b_stainfo_active))
#define HALBB_SNPRINT_SIZE	200
#define HALBB_SNPRINT_SIZE_S	20
#if defined BB_8720E_SUPPORT
#define BB_EFUSE_BAND_NUM	2
#elif defined BB_8721F_SUPPORT
#define BB_EFUSE_BAND_NUM	2
#else
#define BB_EFUSE_BAND_NUM	5
#endif

#define IC_LNA_NUM		7
#define IC_TIA_NUM		2
#define IC_RXBB_NUM 1
#define IC_LNA_OP1DB_NUM	7
#define IC_TIA_LNA_OP1DB_NUM	8
#define EFUSE_OFST_NUM		1
#define PIN_for_gain_NUM 16

/*@--------------------------[extern] ---------------------------------------*/
extern const u16 bb_phy_rate_table[LEGACY_RATE_NUM + HE_RATE_NUM_4SS];

/*@--------------------------[Enum]------------------------------------------*/
/* rate_idx table used in FW */
enum rate_table {
	RATE_CCK_1M        = 0x00,
	RATE_CCK_2M        = 0x01,
	RATE_CCK_5M        = 0x02,
	RATE_CCK_11M       = 0x03,
	RATE_OFDM_6M       = 0x04,
	RATE_OFDM_9M       = 0x05,
	RATE_OFDM_12M      = 0x06,
	RATE_OFDM_18M      = 0x07,
	RATE_OFDM_24M      = 0x08,
	RATE_OFDM_36M      = 0x09,
	RATE_OFDM_48M      = 0x0A,
	RATE_OFDM_54M      = 0x0B,
	RATE_HT_MCS0       = 0x0C,
	RATE_HT_MCS1       = 0x0D,
	RATE_HT_MCS2       = 0x0E,
	RATE_HT_MCS3       = 0x0F,
	RATE_HT_MCS4       = 0x10,
	RATE_HT_MCS5       = 0x11,
	RATE_HT_MCS6       = 0x12,
	RATE_HT_MCS7       = 0x13,
	RATE_HT_MCS8       = 0x14,
	RATE_HT_MCS9       = 0x15,
	RATE_HT_MCS10      = 0x16,
	RATE_HT_MCS11      = 0x17,
	RATE_HT_MCS12      = 0x18,
	RATE_HT_MCS13      = 0x19,
	RATE_HT_MCS14      = 0x1A,
	RATE_HT_MCS15      = 0x1B,
	RATE_HT_MCS16      = 0x1C,
	RATE_HT_MCS17      = 0x1D,
	RATE_HT_MCS18      = 0x1E,
	RATE_HT_MCS19      = 0x1F,
	RATE_HT_MCS20      = 0x20,
	RATE_HT_MCS21      = 0x21,
	RATE_HT_MCS22      = 0x22,
	RATE_HT_MCS23      = 0x23,
	RATE_HT_MCS24      = 0x24,
	RATE_HT_MCS25      = 0x25,
	RATE_HT_MCS26      = 0x26,
	RATE_HT_MCS27      = 0x27,
	RATE_HT_MCS28      = 0x28,
	RATE_HT_MCS29      = 0x29,
	RATE_HT_MCS30      = 0x2A,
	RATE_HT_MCS31      = 0x2B,
	RATE_VHT1SS_MCS0   = 0x2C,
	RATE_VHT1SS_MCS1   = 0x2D,
	RATE_VHT1SS_MCS2   = 0x2E,
	RATE_VHT1SS_MCS3   = 0x2F,
	RATE_VHT1SS_MCS4   = 0x30,
	RATE_VHT1SS_MCS5   = 0x31,
	RATE_VHT1SS_MCS6   = 0x32,
	RATE_VHT1SS_MCS7   = 0x33,
	RATE_VHT1SS_MCS8   = 0x34,
	RATE_VHT1SS_MCS9   = 0x35,
	RATE_VHT2SS_MCS0   = 0x36,
	RATE_VHT2SS_MCS1   = 0x37,
	RATE_VHT2SS_MCS2   = 0x38,
	RATE_VHT2SS_MCS3   = 0x39,
	RATE_VHT2SS_MCS4   = 0x3A,
	RATE_VHT2SS_MCS5   = 0x3B,
	RATE_VHT2SS_MCS6   = 0x3C,
	RATE_VHT2SS_MCS7   = 0x3D,
	RATE_VHT2SS_MCS8   = 0x3E,
	RATE_VHT2SS_MCS9   = 0x3F,
	RATE_VHT3SS_MCS0   = 0x40,
	RATE_VHT3SS_MCS1   = 0x41,
	RATE_VHT3SS_MCS2   = 0x42,
	RATE_VHT3SS_MCS3   = 0x43,
	RATE_VHT3SS_MCS4   = 0x44,
	RATE_VHT3SS_MCS5   = 0x45,
	RATE_VHT3SS_MCS6   = 0x46,
	RATE_VHT3SS_MCS7   = 0x47,
	RATE_VHT3SS_MCS8   = 0x48,
	RATE_VHT3SS_MCS9   = 0x49,
	RATE_VHT4SS_MCS0   = 0x4A,
	RATE_VHT4SS_MCS1   = 0x4B,
	RATE_VHT4SS_MCS2   = 0x4C,
	RATE_VHT4SS_MCS3   = 0x4D,
	RATE_VHT4SS_MCS4   = 0x4E,
	RATE_VHT4SS_MCS5   = 0x4F,
	RATE_VHT4SS_MCS6   = 0x50,
	RATE_VHT4SS_MCS7   = 0x51,
	RATE_VHT4SS_MCS8   = 0x52,
	RATE_VHT4SS_MCS9   = 0x53,
	// HE
	RATE_HE1SS_MCS0    = 0x54,
	RATE_HE1SS_MCS1    = 0x55,
	RATE_HE1SS_MCS2    = 0x56,
	RATE_HE1SS_MCS3    = 0x57,
	RATE_HE1SS_MCS4    = 0x58,
	RATE_HE1SS_MCS5    = 0x59,
	RATE_HE1SS_MCS6    = 0x5A,
	RATE_HE1SS_MCS7    = 0x5B,
	RATE_HE1SS_MCS8    = 0x5C,
	RATE_HE1SS_MCS9    = 0x5D,
	RATE_HE1SS_MCS10   = 0x5E,
	RATE_HE1SS_MCS11   = 0x5F,
	RATE_HE2SS_MCS0    = 0x60,
	RATE_HE2SS_MCS1    = 0x61,
	RATE_HE2SS_MCS2    = 0x62,
	RATE_HE2SS_MCS3    = 0x63,
	RATE_HE2SS_MCS4    = 0x64,
	RATE_HE2SS_MCS5    = 0x65,
	RATE_HE2SS_MCS6    = 0x66,
	RATE_HE2SS_MCS7    = 0x67,
	RATE_HE2SS_MCS8    = 0x68,
	RATE_HE2SS_MCS9    = 0x69,
	RATE_HE2SS_MCS10   = 0x6A,
	RATE_HE2SS_MCS11   = 0x6B,
};

enum bb_trx_state_t {
	BB_TX_STATE	= 0,
	BB_RX_STATE	= 1,
	BB_BI_DIR_STATE	= 2
};

enum bb_trafic_t {
	TRAFFIC_NO_TP		= 0,
	TRAFFIC_ULTRA_LOW	= 1,
	TRAFFIC_LOW		= 2,
	TRAFFIC_MID		= 3,
	TRAFFIC_HIGH		= 4
};

enum efuse_bit_mask {
	LOW_MASK = 0,
	HIGH_MASK = 1
};
/*@--------------------------[Structure]-------------------------------------*/

struct halbb_pause_lv {
	s8			lv_cfo;
};

struct bb_func_hooker_info {
	void (*pause_bb_dm_handler)(u32 *val_buf, u8 val_len);
};

struct bb_link_info {
	/*[Link Info]*/
	u8			b_linked : 1;
	u8			b_linked_pre : 1;
	u8			b_first_connect : 1;
	u8			b_first_disconnect : 1;
	u8			b_one_entry_only : 1;

	/*[One Entry TP Info]*/
	u8			one_entry_macid;
	u8			one_entry_tp_mbps;
	u8			one_entry_tp_pre_mbps;
	u8			tp_active_th_mbps;

	/*[Client Number]*/
	u8			num_linked_client;
	u8			num_linked_client_pre;
	/*[TP & Traffic]*/
	u8			traffic_load;
	u8			traffic_load_pre;
	u16			consecutive_idle_time;	/*@unit: second*/
	u16			wlan_mode_bitmap; /*val: RTW_80211_B, RTW_80211_G...*/
#if ((defined HALBB_DBG_TRACE_SUPPORT) ||(defined CONFIG_PHYDM_CMD))
	u16 		rx_rate_plurality;
	u16 		rx_rate_plurality_mu;
#endif
};

struct bb_ch_info {
	u8			ch_info_rssi_min;
	u8			rf_central_ch_cfg; /*report in phy-sts*/
#if ((defined HALBB_DBG_TRACE_SUPPORT) ||(defined CONFIG_PHYDM_CMD))
	u8			rxsc_40;
	u8			rxsc_20;
	u8			rxsc_l;
#endif
};

struct bb_cmn_backup_info {
	s16			cur_tx_pwr;
	u8			cur_pd_lower_bound;
#ifdef CONFIG_MP_INCLUDED
	u8			last_rpl;
	u16 		last_cfo;
	struct rssi_physts 	last_rssi_rpt;
	struct rxevm_physts 	last_rxevm_rpt;
#endif
};

struct bb_gain_info {
	s8 lna_gain[BB_GAIN_BAND_NUM][HALBB_MAX_PATH][IC_LNA_NUM];
	u8 tia_gain[BB_GAIN_BAND_NUM][HALBB_MAX_PATH][IC_TIA_NUM];
	s8 rxbb_gain[BB_GAIN_BAND_NUM][HALBB_MAX_PATH][IC_RXBB_NUM];
	s8 pin_for_gain_idx[BB_GAIN_BAND_NUM][HALBB_MAX_PATH][PIN_for_gain_NUM];
#ifdef CONFIG_PHYDM_CMD
	s8 lna_op1db[BB_GAIN_BAND_NUM][HALBB_MAX_PATH][IC_LNA_NUM];
	s8 tia_lna_op1db[BB_GAIN_BAND_NUM][HALBB_MAX_PATH][IC_LNA_NUM + 1]; // TIA0_LNA0~6 + TIA1_LNA6
#endif
	s8 rpl_ofst_20[BB_GAIN_BAND_NUM][HALBB_MAX_PATH];
};

struct bb_efuse_info {
	bool normal_efuse_check;
	bool hidden_efuse_check;
	s8 efuse_gain_offset[HALBB_EFUSE_MAX_PATH][BB_BAND_NUM_MAX]; // S(8,0)
	s8 gain_cs[HALBB_EFUSE_MAX_PATH][BB_BAND_NUM_MAX]; // S(8,0)

	s8 efuse_ofst[HW_PHY_MAX]; // 8852A:S(5,2) 8852B:S(8,4)
};

struct bb_cmn_dbg_info {
	bool cmn_log_2_cnsl_en;
};

struct bb_cmn_info {
	u8 bb_dm_number;
	bool cck_blk_en;
	enum phl_phy_idx cck_phy_map;
	bool bb_dbcc_en;
#ifdef HALBB_PSD_SUPPORT
	struct bb_psd_info	bb_psd_i;
#endif
#ifdef HALBB_LA_MODE_SUPPORT
	struct bb_la_mode_info	bb_la_mode_i;
#endif
	struct bb_echo_cmd_info	bb_echo_cmd_i;
	struct bb_func_hooker_info bb_func_hooker_i;
	struct bb_cmn_dbg_info bb_cmn_dbg_i;
};

struct bb_info {
	u8		b_mp_mode_pre : 1;
	/*[pmac]*/
	u8		b_dyn_pmac_tri_en : 1;
	u8		b_pmac_tri_en : 1;
	/*[DM Info]*/
	u8		b_adv_bb_dm_en : 1;
	/*[System Info]*/
	u8		b_bb_cmn_info_init_ready : 1;
	u8		b_bb_dm_init_ready : 1;
	/*[Drv Dbg Info]*/
	u8		b_cr_recorder_en: 1;
	u8		b_cr_recorder_rf_en: 1; /*HALRF write BB CR*/

	u8		num_rf_path;

	/*[System Info]*/
	u8		bb_watchdog_period; /*2s, 4s, 8s...,254s*/
	u8		pre_dbg_priority;
	/*[Drv Dbg Info]*/
	u8		cmn_dbg_msg_cnt;
	u8		cmn_dbg_msg_period;
	/*[Dummy]*/
	s8		s8_dummy;
	u8		u8_dummy;

	u32		b_sta_exist;
	u32		bb_sys_up_time;

	/*[DM Info]*/
	u64		support_ability;	/*HALBB function Supportability*/
	u64		pause_ability;		/*HALBB function pause Supportability*/
	/*[Drv Dbg Info]*/
	u64		dbg_component;
	u16		cmn_dbg_msg_component;

	/*[Dummy]*/
	u32 	u32_dummy;

	/*[Link Info]*/
	/*[pmac]*/
	u32		pmac_tri_idx;
	u32		pmac_pwr_ofst;

	/*[DBCC]*/
	enum phl_phy_idx		bb_phy_idx;
	/*[Common Info]*/
	struct bb_gain_info		bb_gain_i;
	struct bb_efuse_info	bb_efuse_i;
	/*[System Info]*/
	enum bb_watchdog_mode_t bb_watchdog_mode;
	/*[DM Info]*/
	struct halbb_pause_lv	pause_lv_table;

	/*@=== [HALBB Structure] ============================================*/
	struct bb_link_info		bb_link_i;
	struct bb_ch_info		bb_ch_i;
	struct bb_cmn_rpt_info	bb_cmn_rpt_i;
	struct bb_cmn_backup_info	bb_cmn_backup_i;

#ifdef HALBB_ENV_MNTR_SUPPORT
	struct bb_env_mntr_info bb_env_mntr_i;
#endif
#ifdef HALBB_DFS_SUPPORT
	struct bb_dfs_info		bb_dfs_i;
#endif
#if (defined HALBB_STATISTICS_SUPPORT) || (defined CONFIG_MP_INCLUDED)
	struct bb_stat_info		bb_stat_i;
#endif
#ifdef HALBB_CFO_TRK_SUPPORT
	struct bb_cfo_trk_info	bb_cfo_trk_i;
#endif
#ifdef HALBB_PHYSTS_PARSING_SUPPORT
	struct bb_physts_info	bb_physts_i;
#endif
#ifdef HALBB_LA_MODE_SUPPORT
	struct bb_la_mode_info	bb_la_mode_i;
#endif
	struct bb_pwr_ctrl_info	bb_pwr_ctrl_i;
#ifdef HALBB_PWR_CTRL_SUPPORT
	struct bb_dyncca_info	bb_dyncca_i;
#endif

#ifdef HALBB_PSD_SUPPORT
	struct bb_api_info		bb_api_i;
#endif
#if ((defined HALBB_DBG_SUPPORT)||(defined CONFIG_PHYDM_CMD))
	struct bb_dbg_info		bb_dbg_i;
#endif
#ifdef CONFIG_MP_INCLUDED
	struct rxevm_physts	rxevm;
#endif
#ifdef HALBB_CH_INFO_SUPPORT
	struct bb_ch_rpt_info	bb_ch_rpt_i;
#endif
	/*@=== [HALBB Radar] ================================================*/
#ifdef HALBB_RADAR_SUPPORT
	struct radar_rpt_normal_hdr_info hdr_normal_i;
	struct rtw_radar_iq_data rpt_range_buf_phasek_i;
	struct radar_rpt_srk_lms_data srk_data_i;
	struct radar_rpt_normal_data normal_data_i;
	struct radar_rpt_TD_data td_data_i;
	struct radar_rpt_agc_hdr_info hdr_agc_i;
	struct radar_rpt_normal_hdr_info hdr_srk_i;
	struct radar_rpt_doppler_hdr_info hdr_doppler_i;
#endif

	/*@=== [HALBB Timer] ================================================*/
};


/*@--------------------------[Prptotype]-------------------------------------*/
extern struct bb_info	g6_bb;
extern struct bb_cmn_info	g6_bb_cmn;


void halbb_cmn_info_self_reset(void);
void halbb_sta_info_dbg(char input[][16], u32 *_used,
						char *output, u32 *_out_len);
void halbb_supportability_dbg(char input[][16], u32 *_used,
							  char *output, u32 *_out_len);
void halbb_pause_func_dbg(char input[][16], u32 *_used,
						  char *output, u32 *_out_len);
void halbb_store_data(void);
void halbb_sta_rssi_reset_all(void);
bool halbb_is_cck_rate(u16 rate);
bool halbb_is_ofdm_rate(u16 rate);
bool halbb_is_ht_rate(u16 rate);
bool halbb_is_vht_rate(u16 rate);
bool halbb_is_he_rate(u16 rate);
void halbb_rate_idx_parsor(u16 rate_idx, enum rtw_gi_ltf gi_ltf, struct bb_rate_info *ra_i);
#endif
