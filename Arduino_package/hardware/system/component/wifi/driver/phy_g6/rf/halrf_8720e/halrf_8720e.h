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
#ifndef __HALRF_8720E_H__
#define __HALRF_8720E_H__
#ifdef RF_8720E_SUPPORT

//#define RXDCK_VER_8720E 0x1
//#define RCK_VER_8720E 0x1

//#define LCK_TH_8720E 0x20
void halrf_set_bias_for_ch11_8720e(void);
void halrf_lo_test_8720e(bool is_on);
void halrf_set_singletone_8720e(bool is_on);
//void halrf_set_rx_dck_8720e(bool is_afe);
void halrf_set_rx_dck_8720e_bcut(bool is_wifi);
void halrf_rxdck_track_8720e(void);
//void halrf_rx_dck_8720e(bool is_afe);
void halrf_rf_reduce_gain_8720e(bool is_reduce);
void halrf_rx_dck_8720e_bcut(bool is_wifi);
void halrf_dbg_log_8720e(void);
void halrf_dbg_watchdog_8720e(void);
//void halrf_rf_direct_cntrl_8720e(bool is_bybb);
//void halrf_drf_direct_cntrl_8720e(bool is_bybb);
//extern struct rfk_iqk_info rf_iqk_hwspec_8720e;
bool halrf_ctrl_ch_8720e(u8 central_ch, enum rtw_band_type band);
bool halrf_ctrl_bw_8720e(enum channel_width bw);
void halrf_synk_8720e(void);
void halrf_lck_8720e(void);
void halrf_lck_tracking_8720e(void);
void halrf_xtal_tracking_8720e(void);


#endif
#endif /*  __HALRF_8720e_H__ */
