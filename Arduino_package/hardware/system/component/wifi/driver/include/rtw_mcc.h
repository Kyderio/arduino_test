/******************************************************************************
 *
 * Copyright(c) 2015 Realtek Corporation. All rights reserved.
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
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 ******************************************************************************/
#ifndef _HAL_MCC_H_
#define _HAL_MCC_H_

#define TAG_WLAN_MCC   "MCC"

#define MAX_MCC_IFACE_NUM                     3

#define MCC_SLOT_NUM                          25
#define MCC_SLOT_TIME_US                      (102400/MCC_SLOT_NUM) //4096us
#define MCC_SLOT_TIME_TU                      (100/MCC_SLOT_NUM) //4TU

#define MCC_AP_END_SLOT_IDX                   (MCC_SLOT_NUM - 1 - 2) //index=NUM-1, slot24 for STA TBTT early, slot23 for cts2self delay
#define MCC_AP_END_SLOT_DIFF_WITH_MAX         (MCC_SLOT_NUM - 1 - MCC_AP_END_SLOT_IDX)
#define MCC_AP_SLOT_RATIO_MAX                 80 //STA:1slot for TBTT<slot0> + 2slot for Null1<slot1/2> + 1slot for switch_ch + optional_slot >> (3+MCC_AP_END_SLOT_DIFF_WITH_MAX) / 25 = 20% -> 80%
#define MCC_AP_SLOT_RATIO_MIN                 12 //SAP:1slot for cts2slef + 1slot for BCN_early + 1slot for TBTT >> 3 / 25 = 12%

#define MCC_STAGC_ORDER                       0
#define MCC_APGO_ORDER                        1
#define MCC_NAN_ORDER                         2

#define MCC_EARLY_TIME_UNIT_US                1024	//twt early unit: 1024us
#define MCC_SWCH_P0_RUNAWAY_EARLY_US          (MCC_EARLY_TIME_UNIT_US * 3) //sta txnull(1)
#define MCC_SWCH_P1_RUNAWAY_EARLY_US          (MCC_EARLY_TIME_UNIT_US * 3) //softap tx cts2self
#define MCC_SWCH_P2_COMEBACK_EARLY_US         (MCC_EARLY_TIME_UNIT_US * 3) //sta may txnull(1)

#define MCC_FORCE_AP_GAP                      ((WiFiNavUpperUs -MCC_SWCH_P1_RUNAWAY_EARLY_US) / MCC_SLOT_TIME_US)

#define MCC_NOAON_SWCH_LATENCY                2 //TU
#define MCC_FORCE_STA_ROLE_NUM                50 //MCC_SLOT_TIME_US

#define MCC_NAN_TSF_512TU                     (512*1024)
#define MCC_NAN_TSF_128TU                     (128*1024)

enum MCC_ROLE {
	MCC_ROLE_STA = 0,
	MCC_ROLE_AP = 1,
	MCC_ROLE_GC = 2,
	MCC_ROLE_GO = 3,
};

struct mcc_priv {
	u32 mcc_swch_active_time_ms[MAX_MCC_IFACE_NUM];
	u32 mcc_swch_comeback_time_ms[MAX_MCC_IFACE_NUM];
	u32 mcc_swch_runaway_time_ms[MAX_MCC_IFACE_NUM];
	u16 mcc_macid_bitmap[MAX_MCC_IFACE_NUM]; /* all interface share total 16 macid, 1 is for NAN */
	u8 mcc_bw[MAX_MCC_IFACE_NUM];
	u8 mcc_bw40sc[MAX_MCC_IFACE_NUM];
	u8 mcc_role[MAX_MCC_IFACE_NUM];
	u8 mcc_chan_idx[MAX_MCC_IFACE_NUM];
	u8 mcc_time_slot;
	u8 mcc_time_slot_force_ap;
	u8 mcc_nan_chan_time_tu;
	u8 mcc_p1_tbtt_offset;

	u8 mcc_cur_order : 2;	 //now user mcc_cur_order
	u8 mcc_tsfsync_bcn_period: 5;
	u8 b_mcc_ap_sta_diff_channel : 1;
	u8 b_mcc_enable: 1;
	u8 b_mcc_needed: 1; /* we need stop mcctemp when scan, then keep it true */
	u8 b_mcc_first_p1_interrupt_done: 1;
	u8 b_mcc_nan_lock_chan: 1;
	u8 b_mcc_force_ap: 1;
	u8 b_mcc_sent_cts: 1;
	u8 b_mcc_4way_handshake_mode: 1; /* 4way mcc force to sta */
	u8 b_mcc_force_sta: 1;
};

extern u8 g_mcc_slot_map[MCC_SLOT_NUM];

void rtw_mcc_port0_issue_null(unsigned int power_mode);
void rtw_mcc_port1_issue_cts2self(u16 duration);
u8 *rtw_mcc_append_vendor_ie(u8 *pbuf, u32 *frlen, u8 *pbuf_end);
int rtw_mcc_parse_vendor_ie(u8 *pframe, u32 pkt_len);
u8 rtw_mcc_filter_mgnt_rx_by_port(u8 iface_type, u8 subtype);

void rtw_mcc_swch_portx_runaway_statistic(u8 runaway_order, u8 comeback_order);
void rtw_mcc_swch_slot_enter(u8 first_entry);
void rtw_mcc_swch_twt_timer_disable(void);
void rtw_mcc_swch_init_time_slot_map(void);
void rtw_mcc_drv_switch_channel(u8 mcc_order, u8 ch);
int rtw_mcc_swch_set_channel_bw(u8 mcc_order);
void rtw_mcc_swch_time_slot_exit(void);
void rtw_mcc_swch_timeout(void);
void rtw_mcc_swch_port1_bcn_early_interrupt(void);
void rtw_mcc_swch_port1_runaway_early(u32 runaway_dur_us);

u8 rtw_mccapi_swch_port2_comeback_early(u8 b_p2_tbtt, u8 nan_occupied_time_tu);
u8 rtw_mccapi_swch_port2_comeback(u8 nan_chan, u8 nan_bw40_sc, u8 nan_bw);
u8 rtw_mccapi_swch_port2_runaway(u8 next_slot);
void rtw_mccapi_swch_port2_add_sta(u8 mac_id, u8 add);
void rtw_mcc_swch_port2_twt_timer_enable_test(void);
void rtw_mcc_swch_port2_twt_timer_disable_test(void);
void rtw_mcc_swch_port2_to_port1_check(u8 next_slot);
void rtw_mcc_swch_port1_to_port0_check(void);
u32 rtw_mcc_swch_get_runaway_duration_by_order(u8 mcc_order, u8 start_slot);

void rtw_mccapi_port0_sitesurvey_start(void);
void rtw_mccapi_port0_sitesurvey_complete(void);
void rtw_mccapi_port1_start_bss_mcc_start(u8 ap_chan);
void rtw_mccapi_port1_stop_bss_network(void);
void rtw_mccapi_port1_add_sta(u8 mac_id, u8 add);
void rtw_mccapi_port0_leavebss(void);
int rtw_mccapi_port0_joinbss_chk_done_concurrent(u8 sta_chan, int join_res);

u8 wifi_hal_mcc_check_cpu_mgtq_idle(void);
void wifi_hal_mcc_resvpage_cts2self_xmit(u16 duration);
void wifi_hal_mccapi_port1_bcn_early_hdl(void);
void wifi_hal_mcc_tsf_sync_p0top1(u8 tsf_p1p0_offset);
void wifi_hal_mcc_mac_sleep_by_macid(u8 mcc_order, u8 be_pause);

#define rtw_mcc_user_enable		(wifi_user_config.en_mcc)
#endif