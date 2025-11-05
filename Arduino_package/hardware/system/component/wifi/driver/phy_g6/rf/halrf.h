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

#ifndef __HALRF_H__
#define __HALRF_H__

/*@--------------------------[Define] ---------------------------------------*/

/*H2C cmd ID*/
/*Class 8*/
/*Class 9*/
/*Class a*/
#define FWCMD_H2C_BACKUP_RFK 0
#define FWCMD_H2C_RELOAD_RFK 1
#define FWCMD_H2C_GET_MCCCH 2
#define FWCMD_H2C_DPK_OFFLOAD 3
#define FWCMD_H2C_IQK_OFFLOAD 4

//#define IOT_FAST_RFK 1


/*@--------------------------[Enum]------------------------------------------*/
enum halrf_func_idx {
	RF00_PWR_TRK = 0,
	RF01_IQK = 1,
	RF02_LCK = 2,
	RF03_DPK = 3,
	RF04_TXGAPK = 4,
	RF05_DACK = 5,
	RF06_DPK_TRK = 6,
	RF07_2GBAND_SHIFT = 7,
	RF08_RXDCK = 8,
	RF09_RFK = 9,
	RF10_RF_INIT = 10,
	RF11_RF_POWER = 11,
	RF12_RXGAINK = 12,
	RF13_THER_TRIM = 13,
	RF14_PABIAS_TRIM = 14,
	RF15_TSSI_TRIM = 15,
	RF16_PSD = 16,
	RF17_TSSI_TRK = 17,
	RF18_XTAL_TRK = 18,
	RF19_TX_SHAPE = 19,
	RF20_OP5K_TRK = 20,
	RF21_OP5K = 21,
	RF22_TPE_CTRL = 22,
	RF23_RXDCK_TRK = 23,
	RF24_VCOIB_TRIM = 24,
	//RF24_LOK_TRK = 24
};

enum halrf_rf_mode {
	RF_SHUT_DOWN = 0x0,
	RF_STANDBY = 0x1,
	RF_TX = 0x2,
	RF_RX = 0x3,
	RF_TXIQK = 0x4,
	RF_DPK = 0x5,
	RF_RXK1 = 0x6,
	RF_RXK2 = 0x7
};

enum halrf_rfe_src_sel {
	HALRF_PAPE_RFM		= 0,
	HALRF_GNT_BT_INV	= 1,
	HALRF_LNA0N		= 2,
	HALRF_LNAON_RFM		= 3,
	HALRF_TRSW_RFM		= 4,
	HALRF_TRSW_RFM_B	= 5,
	HALRF_GNT_BT		= 6,
	HALRF_ZERO		= 7,
	HALRF_ANTSEL_0		= 8,
	HALRF_ANTSEL_1		= 9,
	HALRF_ANTSEL_2		= 0xa,
	HALRF_ANTSEL_3		= 0xb,
	HALRF_ANTSEL_4		= 0xc,
	HALRF_ANTSEL_5		= 0xd,
	HALRF_ANTSEL_6		= 0xe,
	HALRF_ANTSEL_7		= 0xf
};

/*@=[HALRF supportability]=======================================*/
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
	HAL_RF_RXGAINK = BIT(RF12_RXGAINK),
	HAL_RF_THER_TRIM = BIT(RF13_THER_TRIM),
	HAL_RF_PABIAS_TRIM = BIT(RF14_PABIAS_TRIM),
	HAL_RF_TSSI_TRIM = BIT(RF15_TSSI_TRIM),
	HAL_RF_TSSI_TRK = BIT(RF17_TSSI_TRK),
	HAL_RF_XTAL_TRACK = BIT(RF18_XTAL_TRK),
	HAL_RF_TX_SHAPE = BIT(RF19_TX_SHAPE),
	HAL_RF_OP5K_TRACK = BIT(RF20_OP5K_TRK),
	HAL_RF_OP5K = BIT(RF21_OP5K),
	HAL_RF_TPE_CTRL = BIT(RF22_TPE_CTRL),
	HAL_RF_RXDCK_TRACK = BIT(RF23_RXDCK_TRK),
	HAL_RF_VCOIB_TRIM = BIT(RF24_VCOIB_TRIM),
	//HAL_RF_LOK_TRACK = BIT(RF24_LOK_TRK),
};

/*@=[HALRF Debug Component]=====================================*/
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
	DBG_RF_INIT = BIT(RF10_RF_INIT),
	DBG_RF_POWER = BIT(RF11_RF_POWER),
	DBG_RF_RXGAINK = BIT(RF12_RXGAINK),
	DBG_RF_THER_TRIM = BIT(RF13_THER_TRIM),
	DBG_RF_PABIAS_TRIM = BIT(RF14_PABIAS_TRIM),
	DBG_RF_TSSI_TRIM = BIT(RF15_TSSI_TRIM),
	DBG_RF_PSD = BIT(RF16_PSD),
	DBG_RF_TSSI_TRK = BIT(RF17_TSSI_TRK),
	DBG_RF_XTAL_TRACK = BIT(RF18_XTAL_TRK),
	DBG_RF_VCOIB_TRIM = BIT(RF24_VCOIB_TRIM),
	//DBG_RF_LOK = BIT(RF24_LOK_TRK),
	DBG_RF_FW = BIT(28),
	DBG_RF_MP = BIT(29),
	DBG_RF_TMP = BIT(30),
	DBG_RF_CHK = BIT(31)
};


/*@--------------------------[Structure]-------------------------------------*/

struct rfk_location {
	enum rtw_band_type cur_band;
	enum channel_width cur_bw;
	u8 cur_ch;
};

struct halrf_fem_info {
	u8 epa_2g;		/*@with 2G ePA    NO/Yes = 0/1*/
	u8 epa_5g;		/*@with 5G ePA    NO/Yes = 0/1*/
	u8 epa_6g;		/*@with 6G ePA    NO/Yes = 0/1*/
};

#if 1 /* all rf operation usage (header) */

/* clang-format on */
#define RF_PATH_MAX_NUM (1)
#define RF_TASK_RECORD_MAX_TIMES (16)
#define RF_BACKUP_MAC_REG_MAX_NUM (16)
#define RF_BACKUP_BB_REG_MAX_NUM (16)
#define RF_BACKUP_RF_REG_MAX_NUM (16)
#define RF_BACKUP_KIP_REG_MAX_NUM (16)

struct rfk_iqk_info {
	u8 rf_max_path_num;
	u32 rf_iqk_version;
	u8 rf_iqk_ch_num;
	u8 rf_iqk_path_num;

	const u32 *backup_mac_reg;
	u32 backup_mac_reg_num;
	const u32 *backup_bb_reg;
	u32 backup_bb_reg_num;
	const u32 *backup_rf_reg;
	u32 backup_rf_reg_num;
};
/* clang-format off */
#endif /* all rf operation usage (header) */

struct halrf_rx_dck_info {
#ifdef	RFDBG_TRACE_EN
	bool rx_dck_is_afe; //
	struct rfk_location loc[KPATH]; /*max RF path*/
	u32 rxdck_time;
#endif
	bool is_rxdck_track_en; //
	u8 ther_rxdck[KPATH];
	u8 ther_rxdck_2g;
	u8 ther_rxdck_5g;
	u32 tia_table_main[8];
	u32 tia_table_aux[8];
	bool bbgm_on;
	bool bts1_on;
	bool done_dck;
};

#ifdef IOT_FAST_RFK
#ifdef RF_8730E_SUPPORT

#define CH_NUM 28

struct halrf_channel_rfk {
	bool	bk_init;
	bool	relaod_init;

	u32	rxdck_rxbb[CH_NUM][13];
	u32	rxdck_tia[CH_NUM][8];
	u32	rxdck_tia_aux[CH_NUM][8];
	u32	dpk_gs[CH_NUM];
	u32	dpk_pwsf[CH_NUM];
	u32	dpk_txagc_lut0[CH_NUM] ;
	u32	dpk_txagc_lut1[CH_NUM];
	u32	dpk_txagc_bnd0[CH_NUM];
	u32	dpk_txagc_bnd2[CH_NUM];
	u32	dpk_lut0[CH_NUM][32];
	u32	dpk_lut1[CH_NUM][32];
	u32	iqk[CH_NUM][3];

	u32	lok1[CH_NUM];
	u32	pwr_by_rate[CH_NUM][11];
	u32	pwr_limit[CH_NUM][20];
	u32	pwr_limit_ru[CH_NUM][12];
	u32	tssi_data[CH_NUM][21];
	u32	tssi_ftable[CH_NUM][32];
	u8	gapk[CH_NUM][12];
};
#endif
#endif

struct rf_info {
	/*[Common Info]*/
	/*[System Info]*/
	/*[DM Info]*/
	u32			support_ability;
	u32			hw_rf_ability;
	/*[FW Info]*/
	/*[Drv Dbg Info]*/
	u32			dbg_component;
	/*[BTC / RFK Info ]*/
	bool 			rfk_is_processing;
	bool			is_bt_iqk_timeout;
	bool			is_chl_rfk;
	bool			is_rfk_init;
	/*[initial]*/
	/*[TSSI Info]*/
	bool		is_tssi_mode; /*S0/S1*/
	/*[Thermal]*/
	u8		cur_ther_s0;
	u8		ther_ofst_lsb;
	u8		cur_ther_lo;
	/*LCK*/
	u8		lck_ther_s0;
	u8		pa_ib_def;
	u8		pa_ib_ther;
	/*[Do Coex]*/
	/*[watchdog]*/
	bool		is_watchdog_stop;
	/*[thermal rek indictor]*/
#ifdef RFDBG_TRACE_EN
	/*reg check*/
	u32	rfk_reg[KIP_REG];
	u32	rfc_reg[2][10];
	u32	rfk_check_fail_count;
	/*fast channel switch*/
	u8	ther_init;
	u32	fcs_rfk_ok_map;
	u8	pre_chl_idx;
	u8	pre_ther_idx;
	/* [Check NCTL Done status Read Times] */
	u32 nctl_ck_times[2];  /* 0xbff8 0x80fc*/
#endif
	u32	fw_ofld_enable;
	s32 freq_offset_last;

	/*@=== [HALRF Structure] ============================================*/
	struct halrf_tssi_info		tssi;
	struct halrf_iqk_info		iqk;
	struct halrf_dpk_info	dpk;
	struct halrf_rx_dck_info rx_dck;
#ifdef	RFDBG_TRACE_EN
	struct halrf_dack_info	dack;
#endif
	struct halrf_gapk_info	gapk;
	struct halrf_pwr_info	pwr_info;
	struct halrf_fem_info	fem;
	struct rf_dbg_cmd_info	rf_dbg_cmd_i;
	struct halrf_psd_data	psd;
#ifdef IOT_FAST_RFK
#ifdef RF_8730E_SUPPORT
	struct halrf_channel_rfk	rfk_data;
#endif
#endif
	struct rfk_location		iqk_loc[2];	/*S0/S1*/
	struct rfk_location		dpk_loc[2];	/*S0/S1*/
	struct rfk_location		gapk_loc[2];	/*S0/S1*/
	struct rfk_iqk_info	*rfk_iqk_info;
};

/*@--------------------------[Prptotype]-------------------------------------*/


#endif

