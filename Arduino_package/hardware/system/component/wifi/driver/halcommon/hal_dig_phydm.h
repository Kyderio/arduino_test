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
#ifndef __HAL_DIG_PHYDM_H__
#define __HAL_DIG_PHYDM_H__

#define DIG_LIMIT_PERIOD 60 /*60 sec*/

/*@--------------------Define ---------------------------------------*/

/*@=== [DIG Boundary] ========================================*/
/*@DIG coverage mode*/
#define	DIG_MAX_COVERAGR		0x26
#define	DIG_MIN_COVERAGE		0x1c
#define	DIG_MAX_OF_MIN_COVERAGE		0x22

/*@[DIG Balance mode]*/
#define	DIG_MAX_BALANCE_MODE		0x3e
#define	DIG_MAX_OF_MIN_BALANCE_MODE	0x2a

/*@[DIG Performance mode]*/
#define	DIG_MAX_PERFORMANCE_MODE	0x5a
#define	DIG_MAX_OF_MIN_PERFORMANCE_MODE	0x40	/*@[WLANBB-871]*/
#define	DIG_MIN_PERFORMANCE		0x20

/*@DIG DFS function*/
#define	DIG_MAX_DFS			0x28
#define	DIG_MIN_DFS			0x20

/*@DIG LPS function*/
#define	DIG_MAX_LPS			0x3e
#define	DIG_MIN_LPS			0x20

/*@DIG Abnormal Value Limitation*/
#define	DIG_ABNORMAL_TH_H		0x5a
#define	DIG_ABNORMAL_TH_L		0x1c
#define	DIG_FIXED_IGI			0x35

/*@=== [DIG FA Threshold] ======================================*/
/*@LPS*/
#define	DM_DIG_FA_TH0_LPS		4	/* @-> 4 lps */
#define	DM_DIG_FA_TH1_LPS		15	/* @-> 15 lps */
#define	DM_DIG_FA_TH2_LPS		30	/* @-> 30 lps */

#define	RSSI_OFFSET_DIG_LPS		5
#define DIG_RECORD_NUM			4

/*==== [FA duration] ===========================================*/
#define OFDM_FA_EXP_DURATION		12	/*us*/
#define CCK_FA_EXP_DURATION		175	/*us*/

/*==== [CCK PD LOWER BOUND TH] =================================*/
#define DIG_PD_LOWER_MARGIN_LOWEST  9
#define DIG_PD_LOWER_MARGIN_INIT    14  /* rssi - margin = cck pd */
#define DIG_PD_MAX_TH_BY_IGI        12  /* range of ADC */
#define DIG_PD_MIN_TH_BY_IGI        18  /* cca ability & sensitivity */
#define DIG_PD_BOUND_REF_BCN_CNT_L  5
#define DIG_PD_BOUND_REF_BCN_CNT_H  17

/*@--------------------Enum-----------------------------------*/
enum rtw_dig_pause_type {
	DIG_PAUSE        = 0,
	DIG_RESUME       = 1
};

enum rtw_dig_mode {
	DIG_PERFORMANCE_MODE  = 0,  /* service one device */
	DIG_BALANCE_MODE      = 1   /* service more than one device */
};

enum rtw_dig_trend {
	DIG_STABLE      = 0,
	DIG_INCREASING  = 1,
	DIG_DECREASING  = 2
};

#ifdef CONFIG_WIFI_CCKPD
enum cckpd_lv {
	CCK_PD_LV_INIT = 0xff,
	CCK_PD_LV_0 = 0,
	CCK_PD_LV_1 = 1,
	CCK_PD_LV_2 = 2,
	CCK_PD_LV_3 = 3,
	CCK_PD_LV_4 = 4,
	CCK_PD_LV_MAX = 5
};
#endif

/*@--------------------Define Struct-----------------------------------*/
#ifdef CONFIG_WIFI_DIG_DAMPING_CHK
struct rtw_dig_recorder_info {
	u8		igi_bitmap; /*@Don't add any new parameter before this*/
	u8		igi_history[DIG_RECORD_NUM];
	u32		fa_history[DIG_RECORD_NUM];
	u8		damping_limit_en;
	u8		damping_limit_val; /*@Limit IGI_dyn_min*/
	u32		limit_time;
	u8		limit_rssi;
};
#endif

struct rtw_false_alm_cnt_info {
	u32		cnt_parity_fail;
	u32		cnt_rate_illegal;
	u32		cnt_crc8_fail;
	u32		cnt_crc8_fail_vhta;
	u32		cnt_crc8_fail_vhtb;
	u32		cnt_mcs_fail;
	u32		cnt_mcs_fail_vht;
	u32		cnt_ofdm_fail;
	u32		cnt_cck_fail;
	u32		cnt_all;
	u32		cnt_fast_fsync;
	u32		cnt_sb_search_fail;
	u32		cnt_ofdm_cca;
	u32		cnt_cck_cca;
	u32		cnt_cca_all;
	u32		cnt_cck_crc32_error;
	u32		cnt_cck_crc32_ok;
	u32		cnt_ofdm_crc32_error;
	u32		cnt_ofdm_crc32_ok;
	u32		cnt_ht_crc32_error;
	u32		cnt_ht_crc32_ok;
	u32		cnt_vht_crc32_error;
	u32		cnt_vht_crc32_ok;
	u32		time_fa_all;
	u32		time_fa_exp;        /*FA duration, [PHYDM-406]*/
	u32		time_fa_ifs_clm;    /*FA duration, [PHYDM-406]*/
	u32		time_fa_fahm;       /*FA duration, [PHYDM-406]*/
	u8		ofdm2_rate_idx;     /*cnt2_ofdm_cr_idx*/
	u32		cnt_ofdm2_crc32_error;
	u32		cnt_ofdm2_crc32_ok;
	u8		ht2_rate_idx;       /*cnt2_ht_cr_idx*/
	u32		cnt_ht2_crc32_error;
	u32		cnt_ht2_crc32_ok;
	u8		vht2_rate_idx;      /*cnt2_vht_cr_idx*/
	u32		cnt_vht2_crc32_error;
	u32		cnt_vht2_crc32_ok;
	u32		cnt_cck_txen;
	u32		cnt_cck_txon;
	u32		cnt_ofdm_txen;
	u32		cnt_ofdm_txon;
	u32		cnt_mpdu_crc32_ok;
	u32		cnt_mpdu_crc32_error;
};

struct rtw_dig_info {
#ifdef CONFIG_WIFI_DIG
#ifdef CONFIG_WIFI_DIG_DAMPING_CHK
	struct rtw_dig_recorder_info dig_recorder_t;
#endif

	struct rtw_false_alm_cnt_info fa_cnt_info;
	u32		fa_th[3];
	u8		cur_ig_value;
	u8		igi_trend;
	u8		rvrt_val;
	u8		operation_mode;       /* performance or banlance mode */
	u8		rx_gain_range_max;    /* dig_dynamic_max */
	u8		rx_gain_range_min;    /* dig_dynamic_min */
	u8		dm_dig_max;           /* absolutly upper bound */
	u8		dm_dig_min;           /* absolutly lower bound */
	u8		dig_max_of_min;       /* absolutly max of min */
	u8		fa_source;
	u8		dig_pd_dynamic_margin;

#ifdef CONFIG_WIFI_CCKPD

	u32 	cck_fa_ma;
	enum channel_width cck_bw;
	enum cckpd_lv	cck_pd_lv;

	/*Default value*/
	u8		cck_pd_20m_1r;
	u8		cck_pd_40m_1r;
	u8		cck_cs_ratio_20m_1r;
	u8		cck_cs_ratio_40m_1r;
	u8		cck_din_shift_opt;

	u8		b_cckpd_enable : 1; 		  /* cckpd capability enable */
#endif

	u8		b_linked : 1;
	u8		b_linked_pre : 1;
	u8		b_first_connect : 1;
	u8		b_first_disconnect : 1;
	u8		b_dig_enable : 1;           /* dig capability enable */
	u8		b_dig_dl_en : 1;            /*damping limit function enable */
	u8		b_dbg_fa_th : 1;            /* en dbg fa thres by fix it */
	u8		b_dig_pause_en : 1;         /* 0-run dig;1-pause dig */
#endif

};

/*@--------------------Function declaration-----------------------------*/
void wifi_hal_fa_cnt_cal_fa_duration(void);
void wifi_hal_dig_scan_cfg(enum rtw_dig_pause_type pause_type);
void wifi_hal_dig_connect_cfg(enum rtw_dig_pause_type pause_type);
int wifi_hal_dig_dm_cfg(enum rtw_dig_pause_type pause_type, u8 igi_value);
void wifi_hal_dig_set(u8 current_igi, u8 b_dis_pd_low_bd);
void wifi_hal_dig_init(void);
void wifi_hal_dig_update_by_per_rx(s8 rx_rssi);
void wifi_hal_dig_watchdog(void);

#endif /*__HAL_DIG_PHYDM_H__*/
