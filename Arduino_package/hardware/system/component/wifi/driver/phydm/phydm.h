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

#ifndef __HALDMOUTSRC_H__
#define __HALDMOUTSRC_H__

/*@============================================================*/
/*@include files*/
/*@============================================================*/
/*PHYDM header*/
#include "phydm_pre_define.h"
#include "phydm_features.h"
#include "phydm_ch_info.h"

#ifdef CONFIG_ANT_DETECTION
#include "phydm_antdect.h"
#endif
#ifdef CONFIG_DYNAMIC_TX_TWR
#include "phydm_dynamictxpower.h"
#endif
#include "phydm_cfotracking.h"
#include "phydm_dfs.h"
#include "phydm_ccx.h"

#if (PHYDM_LA_MODE_SUPPORT)
#include "phydm_adc_sampling.h"
#endif
#ifdef CONFIG_PSD_TOOL
#include "phydm_psd.h"
#endif
#ifdef PHYDM_PRIMARY_CCA
#include "phydm_primary_cca.h"
#endif
#include "phydm_rssi_monitor.h"
#include "phydm_math_lib.h"
#include "phydm_noisemonitor.h"
#include "phydm_api.h"
#ifdef PHYDM_PMAC_TX_SETTING_SUPPORT
#include "phydm_pmac_tx_setting.h"
#endif
#ifdef CONFIG_MP_INCLUDED
#include "phydm_mp.h"
#endif


#ifdef CONFIG_DIRECTIONAL_BF
#include "phydm_direct_bf.h"
#endif

#include "phydm_regtable.h"

/*@HALRF header*/
#include "halrf/halrf_iqk.h"
#include "halrf/halrf_dpk.h"
#include "halrf/halrf.h"
#include "halrf/halrf_powertracking.h"
#if(DM_ODM_SUPPORT_TYPE & (ODM_IOT))
#include "halrf/halphyrf_iot.h"
#endif

extern const u16	phy_rate_table[84];

/*@============================================================*/
/*@Definition */
/*@============================================================*/

#define	ACTIVE_TP_THRESHOLD	1

/* Traffic load decision */
#define TRAFFIC_NO_TP			0
#define	TRAFFIC_ULTRA_LOW		1
#define	TRAFFIC_LOW			2
#define	TRAFFIC_MID			3
#define	TRAFFIC_HIGH			4

#define	NONE				0

#if defined(DM_ODM_CE_MAC80211)
#define MAX_2(x, y)					\
	__max2(typeof(x), typeof(y),			\
	      x, y)
#define __max2(t1, t2, x, y) ({		\
	t1 m80211_max1 = (x);					\
	t2 m80211_max2 = (y);					\
	m80211_max1 > m80211_max2 ? m80211_max1 : m80211_max2; })

#define MIN_2(x, y)					\
	__min2(typeof(x), typeof(y),			\
	      x, y)
#define __min2(t1, t2, x, y) ({		\
	t1 m80211_min1 = (x);					\
	t2 m80211_min2 = (y);					\
	m80211_min1 < m80211_min2 ? m80211_min1 : m80211_min2; })

#define DIFF_2(x, y)					\
	__diff2(typeof(x), typeof(y),			\
	      x, y)
#define __diff2(t1, t2, x, y) ({		\
	t1 __d1 = (x);					\
	t2 __d2 = (y);					\
	(__d1 >= __d2) ? (__d1 - __d2) : (__d2 - __d1); })
#else
#define MAX_2(_x_, _y_)	(((_x_) > (_y_)) ? (_x_) : (_y_))
#define MIN_2(_x_, _y_)	(((_x_) < (_y_)) ? (_x_) : (_y_))
#define DIFF_2(_x_, _y_)	((_x_ >= _y_) ? (_x_ - _y_) : (_y_ - _x_))
#endif

#define IS_GREATER(_x_, _y_)	(((_x_) >= (_y_)) ? true : false)
#define IS_LESS(_x_, _y_)	(((_x_) < (_y_)) ? true : false)

#if defined(DM_ODM_CE_MAC80211)
#define BYTE_DUPLICATE_2_DWORD(B0) ({	\
	u32 __b_dup = (B0);\
	(((__b_dup) << 24) | ((__b_dup) << 16) | ((__b_dup) << 8) | (__b_dup));\
	})
#else
#define BYTE_DUPLICATE_2_DWORD(B0)	\
	(((B0) << 24) | ((B0) << 16) | ((B0) << 8) | (B0))
#endif
#define BYTE_2_DWORD(B3, B2, B1, B0)	\
	(((B3) << 24) | ((B2) << 16) | ((B1) << 8) | (B0))
#define BIT_2_BYTE(B3, B2, B1, B0)	\
	(((B3) << 3) | ((B2) << 2) | ((B1) << 1) | (B0))

/*@For pphy_stainfo */
#define is_sta_active(psta_mlmepriv)	((psta_mlmepriv) && (psta_mlmepriv->b_stainfo_active))

#define PHYDM_WATCH_DOG_PERIOD	2 /*second*/

#define PHY_HIST_SIZE		12
#define PHY_HIST_TH_SIZE	(PHY_HIST_SIZE - 1)

#define	S_TO_US			1000000

/*@============================================================*/
/*structure and define*/
/*@============================================================*/

#define		dm_type_by_fw		0
#define		dm_type_by_driver	1

#define		HW_IGI_TXINFO_TABLE_SIZE 64

#define		PHYDM_SNPRINT_SIZE	64

#ifdef BB_RAM_SUPPORT

struct phydm_bb_ram_per_sta {
	/* @tx_pwr_offset0 offset for Tx power index*/
	s8			tx_pwr_offset0;
	s8			tx_pwr_offset1;
	/* @hw_igi value for paths after packet Tx in a period of time*/
	u8			hw_igi;
	/* @Reg0x1E84 for RAM I/O*/
	u8			tx_pwr_offset0_en: 1;
	u8			tx_pwr_offset1_en: 1;
	u8			hw_igi_en: 1;
};

struct phydm_bb_ram_ctrl {
	/*@ For 98F/14B/22C/12F, each tx_pwr_ofst step will be 1dB*/
	struct phydm_bb_ram_per_sta pram_sta_ctrl[HW_IGI_TXINFO_TABLE_SIZE];
	/*------------ For table2 do not set power offset by macid --------*/
	u64			macid_is_linked;
};

#endif

struct phydm_phystatus_statistic {
	/*@[CCK]*/
	u32			rssi_cck_sum;
	u32			rssi_cck_cnt;
	u32			rssi_beacon_sum[RF_PATH_MEM_SIZE];
	u32			rssi_beacon_cnt;
#ifdef PHYSTS_3RD_TYPE_SUPPORT
#endif
	/*@[OFDM]*/
	u32			rssi_ofdm_sum[RF_PATH_MEM_SIZE];
	u32			rssi_ofdm_cnt;
	u32			evm_ofdm_sum;
	u32			snr_ofdm_sum[RF_PATH_MEM_SIZE];
	/*@[1SS]*/
	u32			rssi_1ss_cnt;
	u32			rssi_1ss_sum[RF_PATH_MEM_SIZE];
	u32			evm_1ss_sum;
	u32			snr_1ss_sum[RF_PATH_MEM_SIZE];
	/*@[OFDM]*/
	u16			evm_ofdm_hist[PHY_HIST_SIZE];
	u16			snr_ofdm_hist[PHY_HIST_SIZE];
	/*@[1SS]*/
	u16			evm_1ss_hist[PHY_HIST_SIZE];
	u16			snr_1ss_hist[PHY_HIST_SIZE];
	/*@[2SS]*/
	/*@[3SS]*/
	/*@[4SS]*/
#ifdef PHYDM_PHYSTAUS_AUTO_SWITCH
	u16			p4_cnt[RF_PATH_MEM_SIZE]; /*phy-sts page4 cnt*/
	u16			cn_sum[RF_PATH_MEM_SIZE]; /*condition number*/
	u16			cn_hist[RF_PATH_MEM_SIZE][PHY_HIST_SIZE];
#endif
};

struct phydm_phystatus_avg {
	/*@[CCK]*/
	u8			rssi_cck_avg;
	u8			rssi_beacon_avg[RF_PATH_MEM_SIZE];
	/*@[OFDM]*/
	u8			rssi_ofdm_avg[RF_PATH_MEM_SIZE];
	u8			evm_ofdm_avg;
	u8			snr_ofdm_avg[RF_PATH_MEM_SIZE];
	/*@[1SS]*/
	u8			rssi_1ss_avg[RF_PATH_MEM_SIZE];
	u8			evm_1ss_avg;
	u8			snr_1ss_avg[RF_PATH_MEM_SIZE];
	/*@[2SS]*/
	/*@[3SS]*/
	/*@[4SS]*/
};

struct odm_phy_dbg_info {
	struct phydm_phystatus_statistic	physts_statistic_info;
	struct phydm_phystatus_avg		phystatus_statistic_avg;
	/*@ODM Write,debug info*/
	u32			condi_num; /*@condition number U(18,4)*/
#if (ODM_PHY_STATUS_NEW_TYPE_SUPPORT) || (defined(PHYSTS_3RD_TYPE_SUPPORT))
	u32 		num_qry_bf_pkt;
	u16 		num_mu_vht_pkt[VHT_RATE_NUM];
#endif
	u16			show_phy_sts_max_cnt;	/*@show number of phy-status row data per PHYDM watchdog*/
	u16			show_phy_sts_cnt;
	u16			num_qry_legacy_pkt[LEGACY_RATE_NUM];
	u16			num_qry_ht_pkt[HT_RATE_NUM];
	u16			num_qry_pkt_sc_20m[LOW_BW_RATE_NUM]; /*@20M SC*/
	u16 		snr_hist_th[PHY_HIST_TH_SIZE];
	u16 		evm_hist_th[PHY_HIST_TH_SIZE];
#ifdef PHYSTS_3RD_TYPE_SUPPORT
	u16 		cn_hist_th[PHY_HIST_TH_SIZE]; /*U(16,1)*/
	s16 		cfo_tail[4]; /*per-path's cfo_tail */
#endif
#if ODM_IC_11AC_SERIES_SUPPORT || defined(PHYDM_IC_JGR3_SERIES_SUPPORT)
	u16 		num_qry_vht_pkt[VHT_RATE_NUM];
	u16 		num_qry_pkt_sc_40m[LOW_BW_RATE_NUM]; /*@40M SC*/
#endif
	u8			num_qry_beacon_pkt;
	u8			beacon_phy_rate;
	u8			show_phy_sts_all_pkt;	/*@Show phy status witch not match BSSID*/
#ifdef PHYSTS_3RD_TYPE_SUPPORT
	u8			condition_num_seg0;
#endif

	u8		low_bw_20_occur: 1;
	u8		ht_pkt_not_zero: 1;

#if (ODM_PHY_STATUS_NEW_TYPE_SUPPORT) || (defined(PHYSTS_3RD_TYPE_SUPPORT))
	u8 		is_ldpc_pkt: 1;
	u8 		is_stbc_pkt: 1;
#endif

#if ODM_IC_11AC_SERIES_SUPPORT || defined(PHYDM_IC_JGR3_SERIES_SUPPORT)
	u8		vht_pkt_not_zero: 1;
	u8		low_bw_40_occur: 1;
#endif

};

enum odm_cmninfo {
	/*@Fixed value*/

	/*@------------CALL BY VALUE-------------*/
	ODM_CMNINFO_LINK,
	ODM_CMNINFO_RSSI_MIN,
	ODM_CMNINFO_DBG_COMP,
	ODM_CMNINFO_RRSR_VAL,
	/*@------------CALL BY VALUE-------------*/

	/*@Dynamic ptr array hook itms.*/
	ODM_CMNINFO_STA_STATUS,
	ODM_CMNINFO_MAX,

};

enum phydm_rfe_bb_source_sel {
	PAPE_2G			= 0,
	PAPE_5G			= 1,
	LNA0N_2G		= 2,
	LNAON_5G		= 3,
	TRSW			= 4,
	TRSW_B			= 5,
	GNT_BT			= 6,
	ZERO			= 7,
	ANTSEL_0		= 8,
	ANTSEL_1		= 9,
	ANTSEL_2		= 0xa,
	ANTSEL_3		= 0xb,
	ANTSEL_4		= 0xc,
	ANTSEL_5		= 0xd,
	ANTSEL_6		= 0xe,
	ANTSEL_7		= 0xf
};

enum phydm_api {
	PHYDM_API_NBI		= 1,
	PHYDM_API_CSI_MASK	= 2,
};

enum phydm_func_idx { /*@F_XXX = PHYDM XXX function*/
	F02_DYN_TXPWR		= 2,
	F04_RSSI_MNTR		= 4,
	F06_ANT_DIV		= 6,
	F07_SMT_ANT		= 7,
	F08_PWR_TRAIN		= 8,
	F09_RA			= 9,
	F10_PATH_DIV		= 10,
	F11_DFS			= 11,
	F12_DYN_ARFR		= 12,
	F14_CFO_TRK		= 14,
	F15_ENV_MNTR		= 15,
	F16_PRI_CCA		= 16,
	F17_ADPTV_SOML		= 17,
	F18_LNA_SAT_CHK		= 18,
};

/*@=[PHYDM supportability]==========================================*/
enum odm_ability {
	ODM_BB_DYNAMIC_TXPWR	= BIT(F02_DYN_TXPWR),
	ODM_BB_RSSI_MONITOR	= BIT(F04_RSSI_MNTR),
	ODM_BB_ANT_DIV		= BIT(F06_ANT_DIV),
	ODM_BB_SMT_ANT		= BIT(F07_SMT_ANT),
	ODM_BB_PWR_TRAIN	= BIT(F08_PWR_TRAIN),
	ODM_BB_RATE_ADAPTIVE	= BIT(F09_RA),
	ODM_BB_PATH_DIV		= BIT(F10_PATH_DIV),
	ODM_BB_DFS		= BIT(F11_DFS),
	ODM_BB_DYNAMIC_ARFR	= BIT(F12_DYN_ARFR),
	ODM_BB_CFO_TRACKING	= BIT(F14_CFO_TRK),
	ODM_BB_ENV_MONITOR	= BIT(F15_ENV_MNTR),
	ODM_BB_PRIMARY_CCA	= BIT(F16_PRI_CCA),
	ODM_BB_ADAPTIVE_SOML	= BIT(F17_ADPTV_SOML),
	ODM_BB_LNA_SAT_CHK	= BIT(F18_LNA_SAT_CHK),
};

/*@=[PHYDM Debug Component]=====================================*/
enum phydm_dbg_comp {
	/*@BB Driver Functions*/
	DBG_DYN_TXPWR		= BIT(F02_DYN_TXPWR),
	DBG_RSSI_MNTR		= BIT(F04_RSSI_MNTR),
	DBG_ANT_DIV		= BIT(F06_ANT_DIV),
	DBG_SMT_ANT		= BIT(F07_SMT_ANT),
	DBG_PWR_TRAIN		= BIT(F08_PWR_TRAIN),
	DBG_RA			= BIT(F09_RA),
	DBG_PATH_DIV		= BIT(F10_PATH_DIV),
	DBG_DFS			= BIT(F11_DFS),
	DBG_DYN_ARFR		= BIT(F12_DYN_ARFR),
	DBG_CFO_TRK		= BIT(F14_CFO_TRK),
	DBG_ENV_MNTR		= BIT(F15_ENV_MNTR),
	DBG_PRI_CCA		= BIT(F16_PRI_CCA),
	DBG_ADPTV_SOML		= BIT(F17_ADPTV_SOML),
	DBG_LNA_SAT_CHK		= BIT(F18_LNA_SAT_CHK),
	/*Neet to re-arrange*/
	DBG_CH_INFO		= BIT(19),
	DBG_PHY_STATUS		= BIT(20),
	DBG_TMP			= BIT(21),
	DBG_FW_TRACE		= BIT(22),
	DBG_TXBF		= BIT(23),
	DBG_COMMON_FLOW		= BIT(24),
	DBG_COMP_MCC		= BIT(25),
	DBG_FW_DM		= BIT(26),
	DBG_DM_SUMMARY		= BIT(27),
	ODM_PHY_CONFIG		= BIT(28),
	ODM_COMP_INIT		= BIT(29),
	DBG_CMN			= BIT(30),/*@common*/
	ODM_COMP_API		= BIT(31)
};

/*@=========================================================*/

/*@ODM_CMNINFO_ONE_PATH_CCA*/
enum odm_cca_path {
	ODM_CCA_2R		= 0,
	ODM_CCA_1R_A		= 1,
	ODM_CCA_1R_B		= 2,
};

enum phy_reg_pg_type {
	PHY_REG_PG_RELATIVE_VALUE = 0,
	PHY_REG_PG_EXACT_VALUE	= 1
};

enum phydm_offload_ability {
	PHYDM_PHY_PARAM_OFFLOAD = BIT(0),
	PHYDM_RF_IQK_OFFLOAD	= BIT(1),
	PHYDM_RF_DPK_OFFLOAD	= BIT(2),
};

enum phydm_init_result {
	PHYDM_INIT_SUCCESS = 0,
	PHYDM_INIT_FAIL_BBRF_REG_INVALID = 1
};

struct phydm_func_poiner {
	void (*pause_phydm_handler)(void *p_gdm, u32 *val_buf, u8 val_len);
};

struct pkt_process_info {
#ifdef PHYDM_PHYSTAUS_AUTO_SWITCH
	/*@send phystatus in each sampling time*/
	u8			mac_ppdu_cnt;
	u8			phy_ppdu_cnt; /*change with phy cca cnt*/
	u8			page_bitmap_target;
	u8			page_bitmap_record;
	u8			ppdu_phy_rate;
	u8			ppdu_macid;
	u8			b_physts_auto_swch_en: 1;
	u8		    b_is_1st_mpdu: 1;
#endif
};

struct dm_struct {
	/*@=== PHYDM Timer ========================================== (start)*/

	/*@=== PHYDM Structure ======================================== (start)*/
	struct	pkt_process_info	pkt_proc_struct;
#ifdef CONFIG_PHYDM_DFS_MASTER
	struct _DFS_STATISTICS		dfs;
#endif
	//struct odm_noise_monitor	noise_level;
#if DBG
	struct odm_phy_dbg_info 	phy_dbg_info;
#endif

#ifdef CONFIG_MP_INCLUDED
	struct _halrf_psd_data halrf_psd_data;
#endif
	struct _hal_rf_ 	 	    rf_table;	/*@for HALRF function*/
	struct dm_rf_calibration_struct rf_calibrate_info;
	struct dm_iqk_info		    IQK_info;
	struct dm_dpk_info		    dpk_info;

#ifdef PHYDM_PRIMARY_CCA
	struct phydm_pricca_struct	dm_pri_cca;
#endif

	struct phydm_cfo_track_struct	dm_cfo_track;
	struct ccx_info 		    dm_ccx_info;

	struct odm_power_trim_data	power_trim_data;

#if (PHYDM_LA_MODE_SUPPORT)
	struct rt_adcsmp		    adcsmp;
#endif

	struct	phydm_api_stuc		api_table;

#ifdef CONFIG_MP_INCLUDED
	struct phydm_mp             dm_mp_table;
#endif

	/* for 8721DA ch_info start */
#ifdef PHYDM_CH_INFO_SUPPORT
	struct bb_ch_rpt_info       bb_ch_rpt_i;
#endif
	/* for 8721DA ch_info end */

	/*@----------Dyn Tx Pwr ---------------------------------------*/
#ifdef BB_RAM_SUPPORT
	struct phydm_bb_ram_ctrl    p_bb_ram_ctrl;
#endif
	/*-------------------------------------------------------------*/

	struct	phydm_func_poiner	phydm_func_handler;

	/*@Add for different team use temporarily*/
	u64			support_ability;	/*@PHYDM function Supportability*/
	u64			pause_ability;		/*@PHYDM function pause Supportability*/
	u64			debug_components;

	enum phydm_phy_sts_type	ic_phy_sts_type;	/*@Type1/type2/type3*/

	u32			support_ic_type;	/*@PHYDM supported IC*/
	u32			bk_support_ability;	/*SD4 only*/
	u32			phydm_sys_up_time;
	u32			u32_dummy;

#ifdef CONFIG_MP_INCLUDED
	struct mp_priv		 *p_mppriv;
#endif

	u16			type_glna;
	u16			type_gpa;
	u16			type_alna;
	u16			type_apa;

	u8			fw_offload_ability;

#if RFDBG
	s8		rxsc_40;
	s8		rxsc_20;
	s8		rxsc_l;

	u8		cck_lna_idx;
	u8		cck_vga_idx;
	u8		curr_station_id;
	u8		ofdm_agc_idx[4];
	u8		rx_rate;
#endif

	/*@Add for different team use temporarily*/
	u8			cmn_dbg_msg_period;
	u8			cmn_dbg_msg_cnt;

	u8			rf_path_rx_enable;
	/*@Init value*/
	/*@-----------HOOK BEFORE REG INIT-----------*/
	u8			ic_ip_series;		/*N/AC/JGR3*/

	u8			rf_type;		/*@RF type 4T4R/3T3R/2T2R/1T2R/1T1R/...*/
	u8			board_type;
	u8			package_type;
#if (DBG || ODM_IC_11N_SERIES_SUPPORT)
	u8			ext_lna_gain;		/*@gain of external lna*/
#endif
	u8			num_rf_path;		/*@ex: 8821C=1, 8192E=2, 8814B=4*/
	s8			s8_dummy;

#if defined(CONFIG_AMEBADPLUS)
	u8			txagc_buff[RF_PATH_MEM_SIZE][PHY_NUM_RATE_IDX];
#endif
#if DBG
	char			dbg_buf[PHYDM_SNPRINT_SIZE];
#endif
	/*@-----------HOOK BEFORE REG INIT-----------*/
	/*@===========================================================*/
	/*@====[ CALL BY VALUE ]===========================================*/
	/*@===========================================================*/
	u8			rssi_min;
	u8			pre_rssi_min;
	u8			one_entry_macid;
	u8			pre_one_entry_tp_mbps;
	u8			number_linked_client;
#if DBG
	u8			rssi_max;
	u8			rssi_a;
#endif
	u8			rx_ant_status; /*RX path enable*/

	/*@[traffic]*/
	u8			traffic_load;

	u8			tp_active_th_mbps;
	/*@---------------------------*/
	/*@---8821C Antenna and RF Set BTG/WLG/WLA Select---------------*/
	/*@-----------------------------------------------------------*/
	u8			pre_dbg_priority;
	u8			c2h_cmd_start;
	u8			pre_c2h_seq;
	/*@-----------------------------------------------------------*/
#ifdef CONFIG_DYNAMIC_TX_TWR
	/*@--- for MCC ant weighting ------------------------------------*/
	/*@-----------------------------------------------------------*/
	u8			enhance_pwr_th[3];
	u8			set_pwr_th[3];
	/*@----------Dyn Tx Pwr ---------------------------------------*/
	u8			dynamic_tx_high_power_lvl;
	u8			last_dtp_lvl;
	/*-------------------------------------------------------------*/
#endif
#ifdef CONFIG_PHYDM_DFS_MASTER
	u8			dfs_region_domain;
#endif

/*@=== RTL8721D ===*/
#if defined(CONFIG_AMEBAD)
	bool		cbw20_adc80;
	bool		invalid_mode;
	u8			power_voltage;
	u8			cca_cbw20_lev;
	u8			cca_cbw40_lev;
	u8			antdiv_gpio;
	u8			peak_detect_mode;
	u8			anti_interference_en;
	u8			regulation_srrc;
	struct psd_info 	dm_psd_table;
	enum phy_reg_pg_type	phy_reg_pg_value_type;
	u8			phy_reg_pg_version;
#endif
#ifdef ODM_CONFIG_BT_COEXIST
	u8		is_bt_enabled: 1;		/*@BT is enabled*/
#endif
#ifdef PHYDM_PMAC_TX_SETTING_SUPPORT
	/*struct phydm_pmac_tx	dm_pmac_tx_table;*/
	u8      b_is_cck_rate: 1;
	u8      b_is_ht_rate: 1;
	u8      b_is_vht_rate: 1;
#endif
	//TSSI
	u8		b_init_hw_info_by_rfe: 1;
	/*@------ ODM HANDLE, DRIVER NEEDS NOT TO HOOK------*/
	u8		b_in_hct_test: 1;
	/*@cck agc relative*/
	u8		b_cck_new_agc: 1;
	u8		b_dfs_band: 1;
#if DBG
	u8		b_nbi_csi: 1;
#endif
	u8		b_disable_phydm_watchdog: 1;
	u8		b_linked: 1;
	u8		b_tp_active_occur: 1;
	u8		is_one_entry_only: 1;
	u8		is_disable_phy_api: 1;
	/*@---------------------------*/
	u8		fw_buff_is_enpty: 1;
#ifdef CONFIG_DYNAMIC_TX_TWR
	/*@--- for noise detection ---------------------------------------*/
	u8		noisy_decision: 1; /*@b_noisy*/
#endif
	/*@---PSD Relative ---------------------------------------------*/
	u8		is_psd_in_process: 1;
	/*@-----------------------------------------------------------*/
#if RFDBG
	/*@--- for spur detection ---------------------------------------*/
	u8		en_reg_mntr_bb: 1;
	u8		en_reg_mntr_rf: 1;
	u8		en_reg_mntr_mac: 1;
	u8		en_reg_mntr_byte: 1;
#endif
};

enum phydm_adv_ota {
	PHYDM_PATHB_1RCCA		= BIT(0),
	PHYDM_HP_OTA_SETTING_A		= BIT(1),
	PHYDM_HP_OTA_SETTING_B		= BIT(2),
	PHYDM_ASUS_OTA_SETTING		= BIT(3),
	PHYDM_ASUS_OTA_SETTING_CCK_PATH = BIT(4),
	PHYDM_HP_OTA_SETTING_CCK_PATH	= BIT(5),
	PHYDM_LENOVO_OTA_SETTING_NBI_CSI = BIT(6),

};

enum odm_bb_config_type {
	CONFIG_BB_PHY_REG,
	CONFIG_BB_AGC_TAB,
	CONFIG_BB_AGC_TAB_2G,
	CONFIG_BB_AGC_TAB_5G,
	CONFIG_BB_PHY_REG_PG,
	CONFIG_BB_PHY_REG_MP,
	CONFIG_BB_AGC_TAB_DIFF,
	CONFIG_BB_RF_CAL_INIT,
};

enum odm_rf_config_type {
	CONFIG_RF_RADIO,
	CONFIG_RF_TXPWR_LMT,
	CONFIG_RF_SYN_RADIO,
};

enum odm_fw_config_type {
	CONFIG_FW_NIC,
	CONFIG_FW_NIC_2,
	CONFIG_FW_AP,
	CONFIG_FW_AP_2,
	CONFIG_FW_MP,
	CONFIG_FW_WOWLAN,
	CONFIG_FW_WOWLAN_2,
	CONFIG_FW_AP_WOWLAN,
	CONFIG_FW_BT,
};

/*status code*/
enum rt_status {
	RT_STATUS_SUCCESS,
	RT_STATUS_FAILURE,
	RT_STATUS_PENDING,
	RT_STATUS_RESOURCE,
	RT_STATUS_INVALID_CONTEXT,
	RT_STATUS_INVALID_PARAMETER,
	RT_STATUS_NOT_SUPPORT,
	RT_STATUS_OS_API_FAILED,
};

void
phydm_watchdog_lps(void);

enum phydm_init_result
odm_dm_init(void);

void
phydm_supportability_en(char input[][16], u32 *_used,
						char *output, u32 *_out_len);

void
phydm_watchdog(void);

int
phydm_pause_func(enum phydm_func_idx pause_func,
				 enum phydm_pause_type pause_type,
				 enum phydm_pause_level pause_lv, u8 val_lehgth, u32 *val_buf);

void
phydm_pause_func_console(char input[][16], u32 *_used,
						 char *output, u32 *_out_len);

void
odm_cmn_info_update(u32 cmn_info, u64 value);

#ifdef PHYDM_CH_INFO_SUPPORT
void
phydm_ch_info_init(void);
#endif

#endif
