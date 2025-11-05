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
#ifndef __HAL_DIG_G6_H__
#define __HAL_DIG_G6_H__

/*@--------------------------[Define] ---------------------------------------*/

/* cr for dig start: need sync with bb */
#define DIG_PATH0_R_RXBB_IDX_INIT_C            0x46A8
#define DIG_PATH0_R_RXBB_IDX_INIT_C_M          0x7C00
#define DIG_PATH0_R_PURE_POST_PD_MODE_C        0x473C
#define DIG_PATH0_R_PURE_POST_PD_MODE_C_M      0x80
#define DIG_PATH0_R_TIA_IDX_INIT_C             0x473C
#define DIG_PATH0_R_TIA_IDX_INIT_C_M           0x200
#define DIG_PATH0_R_LNA_IDX_INIT_C             0x472C
#define DIG_PATH0_R_LNA_IDX_INIT_C_M           0x7000000
#define DIG_PATH0_R_FOLLOW_BY_PAGCUGC_EN_C     0x4C24
#define DIG_PATH0_R_FOLLOW_BY_PAGCUGC_EN_C_M   0x20
/* cr for dig end */

#define DIG_PAUSE_INFO_SIZE 2
#define RSSI_MAX 110
#define RSSI_MIN 0
#define IGI_NOLINK 38

#ifdef CONFIG_WIFI_TDMA_DIG
#define SIMPLE_TDMA_DIG_SWITCH_INTERVAL 50 /*ms*/
#endif

/*@--------------------------[Enum]------------------------------------------*/
enum rtw_dig_pause_type {
	DIG_PAUSE	= 0,
	DIG_RESUME	= 1
};

enum rtw_dig_pause_case {
	DIG_PAUSE_OFDM = 0,
	DIG_PAUSE_OFDM_CCK = 1
};

/*@--------------------------[Structure]-------------------------------------*/

/* struct for state unit, i.e., L/H */
struct rtw_dig_op_unit {
	u8			pd_low_th_ofst;	/* pd low safe cca region */
	bool			sdagc_follow_pagc_en;
};

struct rtw_dig_info {
#ifdef CONFIG_WIFI_DIG
	struct rtw_dig_op_unit	*p_cur_dig_unit;
	struct rtw_dig_op_unit	dig_state_h_i; /* high state */
#ifdef CONFIG_WIFI_TDMA_DIG
	struct rtw_dig_op_unit	dig_state_l_i; /* low state */
	struct timer_list		tdma_dig_timer;
#endif

	/* pause dig start */
	u32			rvrt_val[DIG_PAUSE_INFO_SIZE]; /* [Pause fucntion] must set to u32 */
	u16			igi_pause_cnt; /* consective pause counter */
	/* pause dig end */
	u16			dig_hold_cnt;

	u8			b_linked : 1;
	u8			b_dyn_pd_th_en : 1;
	u8			b_dig_pause_en : 1; /* 0-run dig;1-pause dig */
	u8			b_tdma_dig_enable : 1;
	u8			b_tdma_dig_usrcfg : 1;	/*add for application ctrl tdma dig on/off*/
	u8			b_dig_enable: 1; /* dig capability enable */

	u8			igi_rssi; /* =rssi_min */
	u8			igi_final_rssi; /* =rssi_min - margin */
	u8			tdma_passed_time_cnt;
	u8			dig_pd_low_margin;
#endif
};

/*@--------------------------[Prptotype]-------------------------------------*/
#ifdef CONFIG_WIFI_TDMA_DIG
void wifi_hal_dig_tdma_timer_init(void);
#endif
void wifi_hal_dig_cfg_cr(u8 igi_new);
void wifi_hal_dig_update_by_per_rx(s8 rx_rssi);
void wifi_hal_dig_connect_cfg(enum rtw_dig_pause_type pause_type);
void wifi_hal_dig_scan_cfg(enum rtw_dig_pause_type pause_type);
void wifi_hal_dig_watchdog(void);
void wifi_hal_dig_init(void);

#endif /*__HAL_DIG_G6_H__*/
