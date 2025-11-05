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
#ifndef __HAL_ANTDIV_G6_H__
#define __HAL_ANTDIV_G6_H__

/*@--------------------------[Define] ---------------------------------------*/
#define ANTDIV_INIT                           0xFF
#define ANTDIV_FIXANT_RSSI_TH_BD              55 /*@ >-55dbm, tp always maintain max */
#define ANTDIV_FIXANT_RSSI_DIFF_TH            2
#define ANTDIV_TP_ONE_ENTRY_ACTIVE_TH         5  /* Mbit*/

#define ANTDIV_TRAINING_NUM                   4
#define ANTDIV_TRAINING_DELAY_MS              1
#define ANTDIV_TRAINING_INTVL_MS              10
#define ANTDIV_NO_TRAIN_PERIOD_BY_TP          1
#define ANTDIV_NO_TRAIN_PERIOD_BY_RSSI        3

#define ANTDIV_DECISION_TP_HIGH               100
#define ANTDIV_DECISION_TP_LOW                5
#define ANTDIV_DECISION_TP_CNT_LOWER_BD_TH    1
#define ANTDIV_DECISION_EVM_DIFF_TH           8
#define ANTDIV_DECISION_RSSI_DIFF_TH          3

#define ANTDIV_DIV_FUNC(a, b) ((b) ? ((a) / (b)) : 0)

#define HT_RATE_SUPPORT_NUM                   8   /* mcs0 ~ mcs7 */
#define HE_VHT_RATE_SUPPORT_NUM               10  /* mcs0 ~ mcs9 */
#define LEGACY_RATE_SUPPORT_NUM               12  /* cck4 + ofdm8 */

/*@--------------------------[Enum]------------------------------------------*/
enum rtw_antdiv_tp_method {
	TP_REF_MAX_DOMAIN     = 0,
	TP_REF_HIGHEST_DOMAIN = 1,
	TP_REF_AVG_DOMAIN     = 2,
};

enum rtw_antdiv_evm_method {
	EVM_REF_LINEAR_AVG = 0,
	EVM_REF_DB_AVG     = 1,
};

enum rtw_antdiv_physts_cfg_mode {
	PSTS_COND_NO_CHANGE_MODE   = 0,
	PSTS_COND_AUTO_CHANGE_MODE = 1,
	PSTS_COND_FIX_MODE         = 2,
};

enum rtw_antdiv_physts_chk_cond {
	PHYSTS_CHK_FLASH_OK       = 0,  /* pkt in rxptkbuffer */
	PHYSTS_CHK_PLCP_OK        = 1,
	PHYSTS_CHK_FCS_OK_PAM_BMC = 2,  /* mpdu fcs ok & (a1 match| bc | mc) */
	PHYSTS_CHK_IS_NDP         = 3,
	PHYSTS_CHK_FCS_OK         = 4,  /* mpdu fcs ok */
};

/*@--------------------------[Structure]-------------------------------------*/

struct rtw_antdiv_rssi_info { /*all in U(8,1)*/
	/*acc value*/
	u32 rssi_cck_avg_acc;
	u32 rssi_ofdm_avg_acc;
	u32 rssi_t_avg_acc;
	u8 rssi_cck_avg;
	u8 rssi_ofdm_avg;
	u8 rssi_t_avg;
	u8 rssi_final;
	u16 pkt_cnt_t;
	u16 pkt_cnt_cck;
	u16 pkt_cnt_ofdm;

	u32 main_rssi_cck_avg_acc;
	u32 main_rssi_ofdm_avg_acc;
	u32 main_rssi_t_avg_acc;
	u8 main_rssi_cck_avg;
	u8 main_rssi_ofdm_avg;
	u8 main_rssi_t_avg;
	u8 main_rssi_final;
	u16 main_pkt_cnt_t;
	u16 main_pkt_cnt_cck;
	u16 main_pkt_cnt_ofdm;

	u32 aux_rssi_cck_avg_acc;
	u32 aux_rssi_ofdm_avg_acc;
	u32 aux_rssi_t_avg_acc;
	u8 aux_rssi_cck_avg;
	u8 aux_rssi_ofdm_avg;
	u8 aux_rssi_t_avg;
	u8 aux_rssi_final;
	u16 aux_pkt_cnt_t;
	u16 aux_pkt_cnt_cck;
	u16 aux_pkt_cnt_ofdm;

	u8 rssi_diff;
	u8 b_no_change_flag : 1;
};

struct rtw_antdiv_evm_info {
	u32 main_evm_1ss;   /*U(8,2)*/ /*only for 1SS & L-OFDM*/
	u32 aux_evm_1ss;    /*U(8,2)*/ /*only for 1SS & L-OFDM*/
	u8 evm_diff;
	u8 b_no_change_flag : 1;
};

struct rtw_antdiv_rate_info {
	/*====[Phy rate counter main ant]=============================================*/
	u16		main_pkt_cnt_cck;
	u16		main_pkt_cnt_ofdm; /*L-OFDM*/
	u16		main_pkt_cnt_t; /*HT, VHT, HE = pkt_cnt_1ss*/
	/*Legacy*/
	u16		main_pkt_cnt_legacy[LEGACY_RATE_SUPPORT_NUM];
	/*HT*/
	u16		main_pkt_cnt_ht[HT_RATE_SUPPORT_NUM];
	/*VHT*/
	u16		main_pkt_cnt_vht[HE_VHT_RATE_SUPPORT_NUM];
	/*HE*/
	u16		main_pkt_cnt_he[HE_VHT_RATE_SUPPORT_NUM];

	/*====[Phy rate counter] aux ant=============================================*/
	u16		aux_pkt_cnt_cck;
	u16		aux_pkt_cnt_ofdm; /*L-OFDM*/
	u16		aux_pkt_cnt_t; /*HT, VHT, HE = pkt_cnt_1ss*/
	/*Legacy*/
	u16		aux_pkt_cnt_legacy[LEGACY_RATE_SUPPORT_NUM];
	/*HT*/
	u16		aux_pkt_cnt_ht[HT_RATE_SUPPORT_NUM];
	/*VHT*/
	u16		aux_pkt_cnt_vht[HE_VHT_RATE_SUPPORT_NUM];
	/*HE*/
	u16		aux_pkt_cnt_he[HE_VHT_RATE_SUPPORT_NUM];

	u16		main_cnt_all;
	u16		aux_cnt_all;

	u64		main_tp;
	u64		aux_tp;
	u64		tp_diff;

	u8 b_no_change_flag : 1;
	u8 b_main_ht_pkt_not_zero : 1;
	u8 b_main_vht_pkt_not_zero : 1;
	u8 b_main_he_pkt_not_zero : 1;
	u8 b_aux_ht_pkt_not_zero : 1;
	u8 b_aux_vht_pkt_not_zero : 1;
	u8 b_aux_he_pkt_not_zero : 1;
};

struct rtw_antdiv_info {
#ifdef CONFIG_WIFI_ANTDIV
	struct rtw_antdiv_evm_info antdiv_evm_info;    /* for evm cacluation */
	struct rtw_antdiv_rate_info antdiv_rate_info;  /* for mcs/tp cacluation */
	struct rtw_antdiv_rssi_info antdiv_rssi_info;  /* for rssi */

	enum rtw_antdiv_mode pre_antdiv_mode;          /* record previous ant when fix ant */
	enum rtw_antdiv_tp_method tp_decision_method;
	enum rtw_antdiv_evm_method evm_decision_method;

	/* Training state & period related*/
	u8	notrain_cnt_by_tp;
	u8	notrain_period_by_tp;
	u8	notrain_cnt_by_rssi;
	u8	notrain_period_by_rssi;
	u8	antdiv_training_state_cnt;
	u32	antdiv_intvl;
	u32	antdiv_delay;
	u32	antdiv_train_num;

	u8	tp_cnt_l_bd_th;
	u8	rssi_pre;
	u8	one_entry_tp_pre_mbps;

	/* antenna setting */
	u8	pre_target_ant;
	u8	training_ant;
	u8	target_ant;
	u8	target_ant_evm;
	u8	target_ant_tp;
	u8	target_ant_rssi;

	/* Decision*/
	u16 tp_diff_th_high;
	u16 tp_diff_th_low;
	u8 evm_diff_th;
	u8 rssi_diff_th;

	struct timer_list		antdiv_training_timer;
	enum rtw_antdiv_physts_cfg_mode physts_cfg_mode;
	u8 physts_cond_value;
	u8 physts_chk_backup;
	u8 b_get_stats : 1;          /* indicate whether conut main/aux info*/
	u8 b_linked : 1;
	u8 b_one_entry_only : 1;     /* only one assocaited client */
	u8 b_one_entry_tp_active_occur : 1;
	u8 b_antdiv_enable : 1;      /* antdiv capability enable */
#endif /*CONFIG_WIFI_ANTDIV*/
};

/*@--------------------------[Prptotype]-------------------------------------*/
void wifi_hal_antdiv_training_timer_init(void);
void wifi_hal_antdiv_init(void);
void wifi_hal_antdiv_watchdog(void);
void wifi_hal_antdiv_get_rssi_info(bool is_cck, u8 rate_mode, u8 rssi_avg);
void wifi_hal_antdiv_get_rate_info(bool is_cck, u8 rate_mode, u8 rate_idx);
void wifi_hal_antdiv_get_evm_info(bool is_cck, u8 evm_val);
void wifi_hal_antdiv_set_ant(u8 target_ant);

#endif /*__HAL_ANTDIV_G6_H__*/

