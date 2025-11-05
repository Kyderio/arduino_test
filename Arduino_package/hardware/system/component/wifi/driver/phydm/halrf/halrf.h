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

#ifndef __HALRF_H__
#define __HALRF_H__

/*@============================================================*/
/*@include files*/
/*@============================================================*/
#include "halrf/halrf_psd.h"


/*@============================================================*/
/*@Definition */
/*@============================================================*/
/*IQK version*/
#if (DM_ODM_SUPPORT_TYPE & (ODM_IOT))
#define IQK_VER_8188E "0x01"
#define IQK_VER_8192E "0x01"
#define IQK_VER_8192F "0x01"
#define IQK_VER_8723B "0x1e"
#define IQK_VER_8812A "0x01"
#define IQK_VER_8821A "0x01"
#endif
#define IQK_VER_8814A "0x0f"
#define IQK_VER_8188F "0x01"
#define IQK_VER_8197F "0x1d"
#define IQK_VER_8703B "0x05"
#define IQK_VER_8710B "0x01"
#define IQK_VER_8723D "0x02"
#define IQK_VER_8822B "0x32"
#define IQK_VER_8822C "0x14"
#define IQK_VER_8821C "0x23"
#define IQK_VER_8198F "0x0b"
#define IQK_VER_8814B "0x15"
#define IQK_VER_8812F "0x0c"
#define IQK_VER_8710C "0x0b"
#define IQK_VER_8197G "0x05"
#define IQK_VER_8723F "0x00"
#define IQK_VER_8814C "0x00"
#define IQK_VER_8735B "0x03"
#define IQK_VER_8822E "0x0E"

/*LCK version*/
#define LCK_VER_8188E "0x02"
#define LCK_VER_8192E "0x02"
#define LCK_VER_8192F "0x01"
#define LCK_VER_8723B "0x02"
#define LCK_VER_8812A "0x01"
#define LCK_VER_8821A "0x01"
#define LCK_VER_8814A "0x01"
#define LCK_VER_8188F "0x01"
#define LCK_VER_8197F "0x01"
#define LCK_VER_8703B "0x01"
#define LCK_VER_8710B "0x01"
#define LCK_VER_8723D "0x01"
#define LCK_VER_8822B "0x02"
#define LCK_VER_8822C "0x00"
#define LCK_VER_8821C "0x04"
#define LCK_VER_8814B "0x02"
#define LCK_VER_8195B "0x02"
#define LCK_VER_8710C "0x02"
#define LCK_VER_8197G "0x01"
#define LCK_VER_8198F "0x01"
#define LCK_VER_8814C "0x00"
#define LCK_VER_8735B "0x01"
/*power tracking version*/
#define PWRTRK_VER_8188E "0x01"
#define PWRTRK_VER_8192E "0x01"
#define PWRTRK_VER_8192F "0x01"
#define PWRTRK_VER_8723B "0x01"
#define PWRTRK_VER_8812A "0x01"
#define PWRTRK_VER_8821A "0x01"
#define PWRTRK_VER_8814A "0x01"
#define PWRTRK_VER_8188F "0x01"
#define PWRTRK_VER_8197F "0x01"
#define PWRTRK_VER_8703B "0x01"
#define PWRTRK_VER_8710B "0x01"
#define PWRTRK_VER_8723D "0x01"
#define PWRTRK_VER_8822B "0x01"
#define PWRTRK_VER_8822C "0x00"
#define PWRTRK_VER_8821C "0x01"
#define PWRTRK_VER_8814B "0x00"
#define PWRTRK_VER_8197G "0x00"
#define PWRTRK_VER_8814C "0x00"
#define PWRTRK_VER_8822E "0x01"

/*DPK version*/
#define DPK_VER_8188E "NONE"
#define DPK_VER_8192E "NONE"
#define DPK_VER_8723B "NONE"
#define DPK_VER_8812A "NONE"
#define DPK_VER_8821A "NONE"
#define DPK_VER_8814A "NONE"
#define DPK_VER_8188F "NONE"
#define DPK_VER_8197F "0x08"
#define DPK_VER_8703B "NONE"
#define DPK_VER_8710B "NONE"
#define DPK_VER_8723D "NONE"
#define DPK_VER_8822B "NONE"
#define DPK_VER_8822C "0x20"
#define DPK_VER_8821C "NONE"
#define DPK_VER_8192F "0x15"
#define DPK_VER_8198F "0x0e"
#define DPK_VER_8814B "0x0f"
#define DPK_VER_8195B "0x0c"
#define DPK_VER_8812F "0x0a"
#define DPK_VER_8197G "0x0d"
#define DPK_VER_8814C "0x01"
#define DPK_VER_8735B "0x0d"
#define DPK_VER_8822E "0x06"

/*RFK_INIT version*/
#define RFK_INIT_VER_8822B "0x8"
#define RFK_INIT_VER_8822C "0x8"
#define RFK_INIT_VER_8195B "0x1"
#define RFK_INIT_VER_8198F "0x8"
#define RFK_INIT_VER_8814B "0xa"
#define RFK_INIT_VER_8812F "0x4"
#define RFK_INIT_VER_8197G "0x4"
#define RFK_INIT_VER_8814C "0x0"
#define RFK_INIT_VER_8735B "0xe"
#define RFK_INIT_VER_8822E "0xc"

/*DACK version*/
#define DACK_VER_8822C "0xa"
#define DACK_VER_8814B "0x4"
#define DACK_VER_8814C "0x0"
#define DACK_VER_8735B "0x4"
#define DACK_VER_8822E "0x5"
/*TXGAPK version*/
#define TXGAPK_VER_8814B "0x1"
#define TXGAPK_VER_8195B "0x2"
#define TXGAPK_VER_8822E "0x1"

/*RXDCK version*/
#define RXDCK_VER_8735B "0xb"
#define RXDCK_VER_8822E "0x3"
#define RXDCK_VER_8721DA "0x1"


/*RCK version*/
#define RCK_VER_8735B "0x1"

/*RX Spur K version*/
#define RXSPURK_VER_8822E "0xf"

#define TSSI_VER_8812F "0x1"
#define TSSI_VER_8822C "0x1"
#define TSSI_VER_8821C "0x1"
#define TSSI_VER_8814B "0x1"
#define TSSI_VER_8197G "0x1"
#define TSSI_VER_8723F "0x1"
#define TSSI_VER_8735B "0x20"

#define IQK_THRESHOLD 8
#define DPK_THRESHOLD 4
#define HALRF_ABS(a,b) ((a>b) ? (a-b) : (b-a))
#define SN 100

#define CCK_TSSI_NUM 6
#define OFDM_2G_TSSI_NUM 5
#define OFDM_5G_TSSI_NUM 14

/*@===========================================================*/
/*AGC RX High Power mode*/
/*@===========================================================*/
#define lna_low_gain_1 0x64
#define lna_low_gain_2 0x5A
#define lna_low_gain_3 0x58

/*@============================================================*/
/*@ enumeration */
/*@============================================================*/

enum halrf_func_idx { /*F_XXX = PHYDM XXX function*/
	RF00_PWR_TRK = 0, /*Pow_trk, TSSI_trk*/
	RF01_IQK = 1,	  /*LOK, IQK*/
	RF02_LCK = 2,
	RF03_DPK = 3,
	RF04_TXGAPK = 4,
	RF05_DACK = 5,
	RF06_DPK_TRK = 6,
	RF07_2GBAND_SHIFT = 7,
	RF08_RXDCK = 8,
	RF09_RFK = 9,
	RF10_PA_DYNAMIC_BIAS = 10,
	RF11_RX_SPURK = 11,
	RF12_XTAL_TRK = 12
};

enum halrf_ability {
	HAL_RF_TX_PWR_TRACK = BIT(RF00_PWR_TRK),
	HAL_RF_IQK = BIT(RF01_IQK),
	HAL_RF_LCK = BIT(RF02_LCK),
	HAL_RF_DPK = BIT(RF03_DPK),
	HAL_RF_TXGAPK = BIT(RF04_TXGAPK),
	HAL_RF_DACK = BIT(RF05_DACK),
	HAL_RF_DPK_TRACK = BIT(RF06_DPK_TRK),
	HAL_2GBAND_SHIFT = BIT(RF07_2GBAND_SHIFT),
	HAL_RF_RXDCK = BIT(RF08_RXDCK),
	HAL_RF_PA_DYNAMIC_BIAS = BIT(RF10_PA_DYNAMIC_BIAS),
	HAL_RF_RX_SPURK = BIT(RF11_RX_SPURK),
	HAL_RF_TX_XTAL_TRACK = BIT(RF12_XTAL_TRK)

};

enum halrf_shift_band {
	HAL_RF_2P4 = 0,
	HAL_RF_2P3 = 1,
	HAL_RF_2P5 = 2
};

enum halrf_dbg_comp {
	DBG_RF_TX_PWR_TRACK = BIT(RF00_PWR_TRK),
	DBG_RF_IQK = BIT(RF01_IQK),
	DBG_RF_LCK = BIT(RF02_LCK),
	DBG_RF_DPK = BIT(RF03_DPK),
	DBG_RF_TXGAPK = BIT(RF04_TXGAPK),
	DBG_RF_DACK = BIT(RF05_DACK),
	DBG_RF_DPK_TRACK = BIT(RF06_DPK_TRK),
	DBG_RF_RXDCK = BIT(RF08_RXDCK),
	DBG_RF_RFK = BIT(RF09_RFK),
	DBG_RF_RXSPURK = BIT(RF11_RX_SPURK),
	DBG_RF_TX_XTAL_TRACK = BIT(RF12_XTAL_TRK),
	DBG_RF_MP = BIT(29),
	DBG_RF_TMP = BIT(30),
	DBG_RF_INIT = BIT(31)
};

enum halrf_cmninfo_init {
	HALRF_CMNINFO_ABILITY = 0,
	HALRF_CMNINFO_RFK_FORBIDDEN,
	HALRF_CMNINFO_PWT_TYPE, //usless
	HALRF_CMNINFO_MP_PSD_POINT,
	HALRF_CMNINFO_MP_PSD_START_POINT,
	HALRF_CMNINFO_MP_PSD_STOP_POINT,
	HALRF_CMNINFO_MP_PSD_AVERAGE,
	HALRF_CMNINFO_IQK_TIMES,
	HALRF_CMNINFO_MP_POWER_TRACKING_TYPE, //useless
	HALRF_CMNINFO_POWER_TRACK_CONTROL,
	HALRF_CMNINFO_DRAM_SIZE, //useless
	HALRF_CMNINFO_DRAM_TYPE, //uselss
};

enum halrf_lna_set {
	HALRF_LNA_DISABLE = 0,
	HALRF_LNA_ENABLE = 1,
};

enum halrf_k_segment_time {
	SEGMENT_FREE = 0,
	SEGMENT_10MS = 10, /*10ms*/
	SEGMENT_30MS = 30, /*30ms*/
	SEGMENT_50MS = 50, /*50ms*/
};

enum halrf_iqk_segment {
	HAL_RFIQK_TXLOK,
	HAL_RFIQK_TXIQK,
	HAL_RFIQK_RXIQK,
	HAL_RFIQK_SEGMENTS,
};

enum halrf_iot_dram_size {
	HALRF_DRAM_SIZE_64M,
	HALRF_DRAM_SIZE_128M,
	HALRF_DRAM_SIZE_256M
};

enum halrf_iot_dram_type {
	HALRF_DRAM_TYPE_DDR2,
	HALRF_DRAM_TYPE_DDR3
};

enum halrf_rfk_process {
	RFK_STOP		= 0,
	RFK_START		= 1,
	RFK_ONESHOT_START	= 2,
	RFK_ONESHOT_STOP	= 3
};

#define POWER_INDEX_DIFF 4
#define TSSI_TXAGC_DIFF 2

#define TSSI_CODE_NUM 84

#define TSSI_SLOPE_2G 8
#define TSSI_SLOPE_5G 5

#define TSSI_EFUSE_NUM 25
#define TSSI_EFUSE_KFREE_NUM 4
#define TSSI_DE_DIFF_EFUSE_NUM 10

struct _halrf_tssi_data {
	s32 cck_offset_patha;
	s32 cck_offset_pathb;
	s32 tssi_trk_txagc_offset[PHYDM_MAX_RF_PATH];
	s32 delta_tssi_txagc_offset[PHYDM_MAX_RF_PATH];
	s16 txagc_codeword[TSSI_CODE_NUM];
	u16 tssi_codeword[TSSI_CODE_NUM];
	s8 tssi_efuse[PHYDM_MAX_RF_PATH][TSSI_EFUSE_NUM];
	s8 tssi_de_diff_efuse[PHYDM_MAX_RF_PATH][TSSI_DE_DIFF_EFUSE_NUM];
	s8 tssi_kfree_efuse[PHYDM_MAX_RF_PATH][TSSI_EFUSE_KFREE_NUM];
	u8 thermal[PHYDM_MAX_RF_PATH];
	u32 index[PHYDM_MAX_RF_PATH][14];
	u8 do_tssi;
	u8 get_thermal;
	u8 tssi_finish_bit[PHYDM_MAX_RF_PATH];
	u8 thermal_trigger;
	s8 tssi_de;
};

#define RF_GAIN_TABLE_NUM 12

struct _halrf_txgapk_info {
	bool txgapk_bp_done;
	bool	is_txgapk_ok;

	u8 read_txgain;
	s8 offset[RF_GAIN_TABLE_NUM][PHYDM_MAX_RF_PATH];
	s8 fianl_offset[RF_GAIN_TABLE_NUM][PHYDM_MAX_RF_PATH];
	u32 txgapk_rf3f_bp[5][RF_GAIN_TABLE_NUM][PHYDM_MAX_RF_PATH]; /* band(2Gcck/2GOFDM/5GL/5GM/5GH)/idx/path */
	u32 txgapk_rf3f_same[5][RF_GAIN_TABLE_NUM][PHYDM_MAX_RF_PATH]; /* band(2Gcck/2GOFDM/5GL/5GM/5GH)/idx/path */
	s32 track_d[2][11];
	s32 track_ta[2][11];
	s32 power_d[2][11];
	s32 power_ta[2][11];
};

#define RXSPURK_PSD_RESULT_NUM 24

struct _halrf_rxspurk_info {
	u32 rxspurk_psd_result[RXSPURK_PSD_RESULT_NUM];
	u32 final_psd_idx;
	bool nbi_csi_en;
};

/*@============================================================*/
/*@ structure */
/*@============================================================*/
#if defined(CONFIG_AMEBAD)
#define IQK_MATRIX_SETTINGS_NUM	(14+24+21) /* Channels_2_4G_NUM + Channels_5G_20M_NUM + Channels_5G */
struct iqk_matrix_regs_setting {
	bool	is_iqk_done;
	s32		value[3][8];
	bool	is_bw_iqk_result_saved[3];
};

#endif
struct _hal_rf_ {
	/*update*/
	u32 rf_supportability;
	/*u32 halrf_tssi_data;*/
	s32 freq_offset_last;
	u32 rf_dbg_comp;
#if defined(CONFIG_AMEBADPLUS)
	u32 reg1c68;
	u32 reg2a24;
	u32 reg1b3c;
	u8	lck_ther_s0;
	u8	cur_ther_s0;
	u8	lok_ther_cur;
	u8	thermal_value;
	u8	thermal_value_iqk;
#endif
	bool is_iqk_enable;
	bool is_lok_enable;

	s8  last_delta_power_index;

	/* _halrf_rxdck_info */
	u8 is_set_rxdck: 1;
	u8 is_rxdck_off: 1;

	u8 is_dpk_in_progress: 1;
	u8 is_tssi_in_progress: 1;
	u8 is_txgapk_in_progress: 1;
	u8 is_rxspurk_in_progress: 1;
	u8 is_bt_rfk_timeout: 1;
	u8 is_chl_rfk: 1;
	bool is_watchdog_stop;
#if defined(CONFIG_AMEBAD)
	//struct iqk_matrix_regs_setting iqk_matrix_reg_setting[IQK_MATRIX_SETTINGS_NUM];
	s8 remnant_ofdm_swing_idx;
	s8 remnant_cck_swing_idx;
	s8 xtal_offset_last;
	s8	thermal_value;
	s8	lck_ther_s0;
	//bool	modify_tx_agc_flag;
	//bool	modify_cck_agc_flag;
#endif
};



/*@============================================================*/
/*@ function prototype */
/*@============================================================*/


void halrf_support_ability_debug(char input[][16], u32 *_used,
								 char *output, u32 *_out_len);

void halrf_cmn_info_set(u32 cmn_info, u64 value);

u64 halrf_cmn_info_get(u32 cmn_info);

void halrf_watchdog(void);
void halrf_ability_set_xtal_track(u8 enable);

void halrf_supportability_init(void);

void halrf_init(void);

void halrf_iqk_trigger(bool is_recovery);
void halrf_lok_tracking(void);

void halrf_rf_k_connect_trigger(enum halrf_k_segment_time seg_time);

void halrf_segment_iqk_trigger(void);
void halrf_segment_iqk_trigger_start(enum halrf_iqk_segment segment_iqk);
void halrf_rck_trigger(void);
void halrf_lck_trigger(void);

void halrf_lck_track(void);

void halrf_btc_rfk_notify(enum halrf_rfk_process process);
u8 halrf_btc_ntfy(enum halrf_rfk_process process);

void halrf_dpk_trigger(void);
void halrf_dpk_reload(void);
void halrf_txgapk_trigger(void);

void halrf_rxspurk_trigger(void);

void halrf_disable_aac(bool is_dis_cca);

void halrf_dpk_enable_disable(void);

void halrf_dpk_track(void);

void halrf_dpk_switch(u8 enable);

void halrf_rx_dck_trigger(void);

void halrf_rx_dck_debug_cmd(char input[][16], u32 *_used,
							char *output, u32 *_out_len);
/*Global function*/

int halrf_config_rfk_with_header_file(u32 config_type);

u32 halrf_get_online_tssi_de_new(u8 path, s32 dbm, s32 pout);

void halrf_tssi_trigger(void);

void halrf_set_dpk_track(u8 enable);

void halrf_dack_trigger(bool force);

void halrf_set_rfsupportability(void);
void halrf_clear_tracking(void);

//void halrf_delay_10us(u16 v1);

void halrf_txgapk_debug_cmd(char input[][16], u32 *_used,
							char *output, u32 *_out_len);

void halrf_bandedge_settings(u8 ch, u8 shape_idx, bool is_ofdm);

#endif /*__HALRF_H__*/
