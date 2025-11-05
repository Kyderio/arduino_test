/******************************************************************************
 *
 * Copyright(c) 2007 - 2012 Realtek Corporation. All rights reserved.
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
 *
 ******************************************************************************/
#ifndef _RTW_SITESURVY_H_
#define _RTW_SITESURVY_H_

struct _RT_CHANNEL_PLAN {
	unsigned char		Channel[MAX_CHANNEL_NUM];
	unsigned char		Len;
};

struct scan_priv {
	struct channel_set_bitmap	supported_channel_set_bitmaps[CHANNEL_GROUP_NUM];
	struct channel_set_bitmap	channel_set_bitmaps[CHANNEL_GROUP_NUM];
	struct __queue 			scan_report_list;
	s32(*scan_user_callback)(u32 ap_num, void *user_data);
	s32(*scan_report_each_mode_user_callback)(struct rtw_scan_result *scanned_ap_info, void *user_data);

	void *scan_user_data;
	int	softap_leave_time;
	u32 dot11k_token; 	/* 0: use to identify caller */
	u16 duration_per_channel;	/* 0: use default */
	u16 chan_scan_time[2]; //user-specified scan time per channel, index 0 for active scan time, 1 for passive scan time
	u16 scan_cnt;

	u8 join_scan_times;
	u8 retry_times_remained_for_channel;
	u8 cur_channel_group;
	u8 cur_channel_bit_idx;
	u8 max_ap_record_num;

	u8 b_scan_timeout_flag : 1;
	u8 b_softap_stay : 1;
	u8 b_target_network_valid : 1;
	u8 b_hidden_ssid_disable : 1;
	u8 b_report_each_mode_enable : 1;	/* Every time a AP is scanned, it will be reported to user immediately */
	u8 b_probe_in_cur_passive_channel_deleted : 1;
	u8 b_scan_abort : 1;
	u8 b_scan_for_join : 1;
	s32(*scan_report_acs_user_callback)(struct rtw_acs_mntr_rpt *acs_mntr_rpt);/*new add:https://jira.realtek.com/browse/RSWLANDIOT-11612*/
	/*rom reserved start*/
	u16 scan_timeout_remain;
	u8 probe_req_total_num : 4;
	u8 probe_req_remain : 4;
	u8 b_is_wl_slot : 1;
	u8 rom_rsvd : 7;
};

struct rtw_scan_report_node {
	struct list_head			list;
	struct rtw_scan_result	scanned_AP_info;
};

// The channel information about this channel including joining, scanning, and power constraints.
#ifdef CONFIG_PLATFORM_ARM_SUN8I
#define BUSY_TRAFFIC_SCAN_DENY_PERIOD	8000
#else
#define BUSY_TRAFFIC_SCAN_DENY_PERIOD	12000
#endif

#if defined(CONFIG_BT_COEXIST)
#define SCANNING_TIMEOUT 		12000
#else
#define SCANNING_TIMEOUT 		8000
#endif //CONFIG_BT_COEXIST

#define RTW_AUTO_SCAN_REASON_UNSPECIFIED	0
#define RTW_AUTO_SCAN_REASON_2040_BSS		BIT(0)
#define RTW_AUTO_SCAN_REASON_ACS		BIT(1)
#define RTW_AUTO_SCAN_REASON_ROAM		BIT(2)

#define FAST_SURVEY_TO			(25) //Fast connection time, scan only partial channel
#define SURVEY_TO			(110) //Reduce connection time
#define MAX_CNT_SCAN_TIMES		(3) //Max all-channel loop scan times when connect to but fail scan the target ap // retry may loss dhcp
#define RTW_MAX_SCAN_REPORT_NODE	64

#define RTW_SCAN_STAY_ON_SOFTAP		220 /* ms */
#define RTW_SOFTAP_LEAVE_THRESHOLD	500 /* 500ms, PC disconnect for no beacon (2s) */

#define TRY_SCAN_AGAIN	(2)

#define rtw_is_channel_plan_valid(chplan) (chplan < RT_CHANNEL_DOMAIN_MAX || chplan == RT_CHANNEL_DOMAIN_WORLDWIDE)

#endif // _RTW_SITESURVY_H_

