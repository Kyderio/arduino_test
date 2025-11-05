/******************************************************************************
 *
 * Copyright(c) 2016 - 2017 Realtek Corporation.
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
 *****************************************************************************/
#ifndef RTW_COEX_API_H
#define RTW_COEX_API_H

#include "rtw_coex_host_api.h"

enum rtk_coex_ret {
	RTK_COEX_OK = 0x0,
	RTK_COEX_FAIL = 0x1
};

enum rtk_coex_protocol {
	RTK_COEX_PROTOCOL_UDEF = 0x0,
	RTK_COEX_PROTOCOL_WL = BIT0,
	RTK_COEX_PROTOCOL_BT = BIT1,
	RTK_COEX_PROTOCOL_15_4_MAC = BIT2,
	RTK_COEX_PROTOCOL_ZB = BIT3,
	RTK_COEX_PROTOCOL_OT = BIT4,
	RTK_COEX_PROTOCOL_MAX = BIT15
};

u8 rtk_coex_init(void);
void rtk_coex_deinit(void);
u8 rtk_coex_bind_chip(void *p_hal, u16 protocol_map);

void rtk_coex_man_ctrl_enable(u8 manual);
void rtk_coex_dbg(char *cmd, u32 cmdlen);
void rtk_coex_wl_sw_ctrl_gnt(u8 gnt_bt, u8 gnt_wl);

void  rtk_coex_wl_ntfy_hal_init(u8 b_wifionly);
void rtk_coex_wl_ntfy_periodical(void);
void rtk_coex_wl_ntfy_connect(u8 iface_idx, u8 b_start);
void rtk_coex_wl_ntfy_media_connect(u8 iface_idx, u8 media_status);
void rtk_coex_wl_ntfy_specific_packet(u8 packet_type);
void rtk_coex_wl_ntfy_sec_key_exchange(u8 iface_type, u8 b_start, u8 b_grp_key_update);
void rtk_coex_wl_ntfy_ips(bool b_enter_ips);
void rtk_coex_wl_ntfy_lps(bool b_lps_enable);
void rtk_coex_wl_ntfy_rfk_start(u8 bt_rfk);
void rtk_coex_wl_ntfy_rfk_stop(u8 bt_rfk);
void rtk_coex_wl_ntfy_halt(void);
void rtk_coex_wl_ntfy_scan(bool b_scan_start);
void rtk_coex_wl_ntfy_recv_beacon(u8 iface_idx, u16 bcn_len);
void rtk_coex_wl_ntfy_switch_channel(u8 center_ch);
void rtk_coex_wl_ntfy_switch_band(u8 under_scan, u8 band_type);
void rtk_coex_wl_ntfy_rf_onoff(bool b_rf_on);
void rtk_coex_wl_ntfy_fw_c2h(u8 id, u8 length, u8 *tmp_buf);
u16 rtk_coex_wl_ntfy_tdma_scan_start(bool scan_type);
u16 rtk_coex_wl_ntfy_tdma_scan_handle(void);
u8 rtk_coex_wl_ntfy_rfk(u8 rfk_process);

// BT
bool rtk_coex_is_bt_disabled(void);

// DBG
void rtw_coex_log_enable(u8 log_enable);
#endif

