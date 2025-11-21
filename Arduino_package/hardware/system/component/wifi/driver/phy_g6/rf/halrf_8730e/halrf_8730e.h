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
#ifndef __HALRF_8730E_H__
#define __HALRF_8730E_H__
#ifdef RF_8730E_SUPPORT

//#define RXDCK_VER_8730E 0x1
//#define RCK_VER_8730E 0x1

//#define LCK_TH_8730E 0x20

void halrf_lo_test_8730e(bool is_on);
void halrf_set_singletone_8730e(bool is_on);
//void halrf_set_rx_dck_8730e( bool is_afe);
void halrf_set_rx_dck_8730e_bcut(bool band);

//void halrf_rx_dck_8730e(bool init);
void halrf_dbg_log_8730e(void);
void halrf_dbg_watchdog_8730e(void);
void halrf_rx_dck_8730e_bcdcut(bool init);
//void halrf_rx_dck_8730e_dcut(bool init);
void halrf_rxdck_track_8730e(void);
void halrf_spur_compensation_8730e(void);
void halrf_set_rx_path(bool rx_path);
void halrf_fast_chl_sw_backup_8730e(u8 chl_index);
void halrf_fast_chl_drv_reload_8730e(u8 chl_index);
//extern struct rfk_iqk_info rf_iqk_hwspec_8730e;
void halrf_dpk_init_8730e(void);
bool halrf_ctrl_bw_8730e(enum channel_width bw);
void halrf_rx_dck_8730e_band(bool band);
void halrf_rx_dck_8730e_2G(void);
void halrf_rf_reduce_gain_8730e(bool is_reduce, bool bts1_on);
void halrf_btc_rf_para_8730e(bool bt_s1);
void halrf_s1_bt_on_rf_band_8730e(void);

#if 0
void halrf_rx_dck_onoff_8730e(bool is_enable);
void halrf_rck_8730e(void);
void halrf_bf_config_rf_8730e(void);
bool halrf_ctrl_bw_8730e(enum channel_width bw);
void halrf_rxbb_bw_8730e(enum phl_phy_idx phy, enum channel_width bw);
void halrf_fw_ntfy_8730e(enum phl_phy_idx phy_idx);
void halrf_disconnect_notify_8730e(struct rtw_chan_def *chandef) ;
/ bool halrf_check_mcc_ch_8730e(struct rtw_chan_def *chandef) ;
void halrf_quick_checkrf_8730e(void);

void halrf_before_one_shot_enable_8730e(void);
bool halrf_one_shot_nctl_done_check_8730e(enum rf_path path);
#endif
void halrf_synk_8730e(void);
void halrf_lck_8730e(void);
void halrf_lck_tracking_8730e(void);
void halrf_xtal_tracking_8730e(void);
void halrf_lok_tracking_8730e(void);
#endif
#endif /*  __HALRF_8730e_H__ */
