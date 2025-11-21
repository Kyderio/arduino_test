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
#ifndef RTW_COEX_H
#define RTW_COEX_H


//#include "osdep_service_misc.h"
#include "ameba_soc.h"
#include "wifi_hal_reg.h"
#include "os_wrapper.h"
#include <rtw_atomic.h>
#include "ameba.h"
#include "PortNames.h"
#include "PinNames.h"
#include "rtw_coex_dbg.h"
#include "rtw_coex_api.h"
#include "rtw_coex_api_ext.h"
#include "rtw_coex_config.h"
#include "rtw_coex_wl_chip.h"
#include "rtw_coex_ext_chip.h"
#include "rtw_coex_host_api.h"
#include "rtw_coex_version.h"



enum rtk_coex_bt_profile_map {
	RTK_COEX_BT_PROFILE_NONE = 0,
	RTK_COEX_BT_PROFILE_SCO = BIT0,
	RTK_COEX_BT_PROFILE_HID = BIT1,
	RTK_COEX_BT_PROFILE_A2DP = BIT2,
	RTK_COEX_BT_PROFILE_PAN = BIT3,
	RTK_COEX_BT_PROFILE_LE_AUDIO = BIT4,
};

enum rtk_coex_mode {
	RTK_COEX_WIFI_BT = 0,
	RTK_COEX_WIFI_BT_WITH_WPAN = BIT1,
	RTK_COEX_WIFI_WITH_BT_WPAN = BIT2,
	RTK_COEX_WIFI_WITH_BT = BIT3,
	RTK_COEX_WIFI_WITH_WPAN = BIT4,
	RTK_COEX_WIFI_WPAN = BIT5,
};

enum rtk_coex_timer_id {
	RTK_COEX_TIMER_WL_SPECIAL_PKT = 0,
	RTK_COEX_TIMER_WL_SEC_KEY_EXCHANGE,
	RTK_COEX_TIMER_BT_A2DP_ACT,
	RTK_COEX_TIMER_MAX
};

//define in WL FW
enum rtk_coex_wl_ra_mask_flt {
	RTK_COEX_WL_RA_MASK_FLT_CCK_1M = 0, //filter cck 1m in RA mask
	RTK_COEX_WL_RA_MASK_FLT_CCK_1M_2M = 1,  //filter cck 1m and 2m in RA mask
	RTK_COEX_WL_RA_MASK_FLT_CCK_1M_2M_5_5M = 2, //filter cck 1m and 2m and 5.5m in RA mask
	RTK_COEX_WL_RA_MASK_FLT_NONE = 0xFF, //coex not filter any cck rate in RA mask, use fw default ra mask
};

/*coex use 0x60 ~ 0x7F C2H IDs*/
enum rtk_coex_wl_c2h_evt {
	RTK_COEX_C2H_WL2BT_MAILBOX_FAIL = 0x60,
	RTK_COEX_C2H_RCV_BT2WL_SCB = 0x61,
	RTK_COEX_C2H_BT2WL_MAILBOX = 0x62,
};

enum rtk_coex_wl_h2c_cmd {
	RTK_COEX_H2C_BT_TDMA = 0x60,
	RTK_COEX_H2C_W2B_MAILBOX = 0x62,
	RTK_COEX_H2C_W2B_MAILBOX_EXT = 0x63,
	RTK_COEX_H2C_BT_WL_CTRL = 0x69,
	RTK_COEX_H2C_BT_WL_INIT_SETTING = 0x70,
};

/* OPCode for H2C 0x69 */
enum rtk_coex_wl_h2c_btwifictrl_opcode {
	RTK_COEX_OP_BT_SET_TXRETRY_REPORT   = 0,
	RTK_COEX_OP_BT_SET_PTATABLE         = 1,
	RTK_COEX_OP_BT_SET_PSD_MODE         = 2,
	RTK_COEX_OP_BT_SET_LNA_CONSTRAINT   = 3,
	RTK_COEX_OP_BT_RA_RETRYPENALTY      = 6,
	RTK_COEX_OP_BT_WIFI_RQT_INFO        = 8,
	RTK_COEX_OP_BT_SET_A2DP_EMPTY_THD   = 10,
	RTK_COEX_OP_BT_SET_BCN_INTERVAL     = 11,
	RTK_COEX_OP_BT_SET_LEAK_AP_MODE     = 12,
	RTK_COEX_OP_BT_PROTECT_BCN          = 14,
	RTK_COEX_OP_BT_ONOFF_NOTIFY         = 15,
	RTK_COEX_OP_BT_BBCCA_RESET          = 16,
	RTK_COEX_OP_BIT_RA_MASK_LOW_RATE	= 17
};

/* for H2C 0x70*/
enum rtk_coex_pta_signal_mode {
	RTK_COEX_PTA_SIG_RTK_MODE			= 0,
	RTK_COEX_PTA_SIG_ENH3WIRE_MODE		= 1,
	RTK_COEX_PTA_SIG_DIRECT_MODE		= 2
};

enum rtk_coex_mailbox_cmd {
	RTK_COEX_MAILBOX_BT_FW_PATCH                      	= 0x0a,
	RTK_COEX_MAILBOX_WL_OP_MODE                       	= 0x11,
	RTK_COEX_MAILBOX_WIFI_RF_CALIBRATION_EN           	= 0x15,
	RTK_COEX_MAILBOX_FORCE_BT_TXPWR                   	= 0x17,
	RTK_COEX_MAILBOX_BT_IGNORE_WLAN_ACT               	= 0x1b,
	RTK_COEX_MAILBOX_PSD_CONTROL                      	= 0x21,
	RTK_COEX_MAILBOX_BT_INFO_REPORT                   	= 0x23,
	RTK_COEX_MAILBOX_BT_PSD_REPORT                    	= 0x24,
	RTK_COEX_MAILBOX_BT_INFO_REPORT_BY_ITSELF         	= 0x27,
	RTK_COEX_MAILBOX_BT_INFO_REPORT_CONTROL           	= 0x28,
	RTK_COEX_MAILBOX_BT_SET_TXRETRY_REPORT_PARAMETER  	= 0x29,
	RTK_COEX_MAILBOX_BT_SET_PTA_TABLE                 	= 0x2A,
	RTK_COEX_MAILBOX_BT_MP_REPORT                     	= 0x30,
	RTK_COEX_MAILBOX_BT_PSD_MODE                      	= 0x31,
	RTK_COEX_MAILBOX_BT_SET_BT_LNA_CONSTRAINT         	= 0x32,
	RTK_COEX_MAILBOX_BT_LOOPBACK                      	= 0x33,
	RTK_COEX_MAILBOX_BT_CALIBRATION                   	= 0x34,
	RTK_COEX_MAILBOX_INTERNAL_SWITCH                  	= 0x35,
	RTK_COEX_MAILBOX_BT_CHECK_WLAN_STATE              	= 0x36,
	RTK_COEX_MAILBOX_CHANGE_WIFI_RF_STATE             	= 0x37,
	RTK_COEX_MAILBOX_BT_PAGE_SCAN_INTERVAL            	= 0x38,
	RTK_COEX_MAILBOX_BT_AUTO_SLOT                     	= 0x39,
	RTK_COEX_MAILBOX_MAILBOX_EN                       	= 0x40,
	RTK_COEX_MAILBOX_BT_CALIBRATION_FAIL              	= 0x41,
	RTK_COEX_MAILBOX_WIFI_TDMA_IN_BT_SLOT             	= 0x42,
	RTK_COEX_MAILBOX_WIFI_RPT_TDMA                    	= 0x43,
	RTK_COEX_MAILBOX_BT_LE_EXTRA_INFO_BY_ITSELF    		= 0x46,
	RTK_COEX_MAILBOX_BT_LE_EXTRA_INFO    				= 0x47,
	RTK_COEX_MAILBOX_BT_SLOT_CTRL               		= 0x48,
	RTK_COEX_MAILBOX_BT_SCAN_START_END               	= 0x49,
	RTK_COEX_MAILBOX_BT_HCI_INFO               			= 0x50
};

//w2b_mailbox 0x11
struct rtk_coex_w2b_mailbox_wl_op_mode {
	u8  mailbox_id;
	u8  mailbox_length;
	u8  op_mode;
	u8  channel_idx;
	u8  bw;
};

//w2b_mailbox 0x17
struct rtk_coex_w2b_mailbox_force_bt_txpwr {
	u8  mailbox_id;
	u8  mailbox_length;
	u8  power_idx;
};

//w2b_mailbox 0x1B
struct rtk_coex_w2b_mailbox_bt_ignore_wlan_act {
	u8  mailbox_id;
	u8  mailbox_length;
	u8  enable;
};

//w2b_mailbox 0x22
struct rtk_coex_w2b_mailbox_ctrl_psd {
	u8  mailbox_id;
	u8  mailbox_length;
	u8  enable_psd : 1;
	u8  fix_gain : 1;
	u8  rsvd : 6;
	u8  gain_index;
};

//w2b_mailbox 0x23 or 0x46
struct rtk_coex_w2b_mailbox_bt_info_report {
	u8  mailbox_id;
	u8  mailbox_length;
	u8  trigger;
};

//b2w_mailbox 0x23
struct rtk_coex_b2w_mailbox_bt_info_report {
	u8  mailbox_id;
	u8  mailbox_length;
	u8  data0;
	u8  data1;
	u8  data2;
	u8  data3;
	u8  data4;
	u8  data5;
};

//w2b_mailbox 0x24
struct rtk_coex_w2b_mailbox_request_map_rssi {
	u8  mailbox_id;
	u8  mailbox_length;
	u8  channel_start_index;
	u8  auto_report_type: 2;
	u8  data_src: 2;
	u8  rsvd : 6;
};

//b2w_mailbox 0x27
struct rtk_coex_b2w_mailbox_bt_info_report_by_itself {
	u8  mailbox_id;
	u8  mailbox_length;
	u8  data0;
	u8  data1;
	u8  data2;
	u8  data3;
	u8  data4;
	u8  data5;
};

//w2b_mailbox 0x30
struct rtk_coex_w2b_mailbox_bt_mp_report {
	u8  mailbox_id;
	u8  mailbox_length;//sequence;
	u8  op_code;
	u8  data0;
	u8  data1;
	u8  data2;
	u8  data3;
	u8  data4;
};

//b2w_mailbox 0x30
struct rtk_coex_b2w_mailbox_bt_mp_report {
	u8  mailbox_id;
	u8  sequence;
	u8  op_code;
	u8  bt_status: 4;
	u8  retlen: 4;
	u8  ret_data0;
	u8  ret_data1;
	u8  ret_data2;
	u8  ret_data3;
};

//b2w_mailbox 0x39
struct rtk_coex_b2w_mailbox_bt_auto_slot {
	u8  mailbox_id;
	u8  length;
	u8  enable;
};

//w2b_mailbox 0x42
struct rtk_coex_w2b_mailbox_wifi_slot_end {
	u8  mailbox_id;
	u8  mailbox_length;
	u8  notify;
};

//b2w_mailbox 0x46
struct rtk_coex_b2w_mailbox_bt_extra_info {
	u8  mailbox_id;
	u8  mailbox_length;
	u8  data0;
	u8  data1;
	u8  data2;
	u8  data3;
	u8  data4;
	u8  data5;
};

//b2w_mailbox 0x47
struct rtk_coex_b2w_mailbox_bt_extra_info_report_by_itself {
	u8  mailbox_id;
	u8  mailbox_length;
	u8  data0;
	u8  data1;
	u8  data2;
	u8  data3;
	u8  data4;
	u8  data5;
};

//b2w_mailbox 0x48
struct rtk_coex_b2w_mailbox_le_audio_iso_tx_end {
	u8  mailbox_id;
	u8  mailbox_length;
	//data0
	u8  start_or_end: 1;
	u8  rx_or_tx : 1;
	u8  rsvd : 6;
	//data1
	u8  next_iso_start_time_low; //unit:1.25ms
	//data2
	u8  next_iso_start_time_high; //unit:1.25ms
};

//b2w_mailbox 0x49
struct rtk_coex_b2w_mailbox_bt_le_init_scan_start_end {
	u8  mailbox_id;
	u8  mailbox_length;
	//data0
	u8  le_init_scan_window_low; //unit:0.625ms
	//data1
	u8  le_init_scan_window_high;//unit:0.625ms;
	//data2
	u8  le_init_scan_interval_low; //unit:0.625ms
	//data3
	u8  le_init_scan_interval_high;//unit:0.625ms;
	//data4
	u8  le_init_scan_start_end: 1;
	u8  rsvd: 7;
};

//w2b_mailbox 0x50
struct rtk_coex_w2b_mailbox_bt_hci_info {
	u8  mailbox_id;
	u8  mailbox_length;
	u8  subid;
	u8  data0;
	u8  data1;
	u8  data2;
	u8  data3;
	u8  data4;
};

//b2w_mailbox 0x50
struct rtk_coex_b2w_mailbox_bt_hci_info {
	u8  mailbox_id;
	u8  mailbox_length;
	u8  subid;
	u8  data0;
	u8  data1;
	u8  data2;
	u8  data3;
	u8  data4;
};

/* for RTK_COEX_MAILBOX_BT_MP_REPORT 0x30*/
enum rtk_coex_mailbox_mp_report_opcode {
	RTK_COEX_MAILBOX_MP_REPORT_OPCODE_GET_BT_VERSION 		= 0x0,
	RTK_COEX_MAILBOX_MP_REPORT_OPCODE_WRITE_REG_ADDR 		= 0xC,
	RTK_COEX_MAILBOX_MP_REPORT_OPCODE_WRITE_REG_VALUE 		= 0xD,
	RTK_COEX_MAILBOX_MP_REPORT_OPCODE_READ_REG 				= 0x11,
	RTK_COEX_MAILBOX_MP_REPORT_OPCODE_IND_SPEC_ACL_PKT		= 0x21,
	RTK_COEX_MAILBOX_MP_REPORT_OPCODE_COEX_SUPPORT_VERSION	= 0x2B,
	RTK_COEX_MAILBOX_MP_REPORT_OPCODE_GET_BT_LE_SCAN_TYPE 	= 0x2D,
	RTK_COEX_MAILBOX_MP_REPORT_OPCODE_GET_BT_LE_SCAN_PARA 	= 0x2E,
	RTK_COEX_MAILBOX_MP_REPORT_OPCODE_SET_BT_LANCONS_LVL	= 0x32,
};

enum rtk_coex_log_enable {
	RTK_COEX_LOG_DISABLE_ALL			= 0,
	RTK_COEX_LOG_ENABLE_ALWAYS			= BIT(0),
	RTK_COEX_LOG_ENABLE_ERROR			= BIT(1),
	RTK_COEX_LOG_ENABLE_WARN			= BIT(2),
	RTK_COEX_LOG_ENABLE_INFO			= BIT(3),
	RTK_COEX_LOG_ENABLE_DEBUG			= BIT(4),
};
struct rtk_coex_timer {
	u8  b_sync_watchdog: 1;
	u8  cnt;
	u16 unit;
};

struct rtk_coex_ctrl {
	u8 stop_dm: 1;
	u8 manual: 1;
	u8 igno_bt: 1;
	u8 always_freerun: 1;
	u8 sw_gnt_bt: 2;
	u8 sw_gnt_wl: 2;
};

struct rtk_coex_config_vendor {
	u8 vendor_id;
	u8 product_id;
	u8 wl_slot;		// percent value, [0-100]
	u8 wl_slot_trig;
};

struct rtk_coex_version_info {
	u32	coex_ver;
	u32 coex_ver_wlfw_desired;
	u32 coex_ver_btfw_desired;
	u32 coex_ver_wlfw_cur;
	u32 coex_ver_btfw_cur;
	u8 is_wlfw_ver_matched: 2;
	u8 is_btfw_ver_matched: 2;
};

struct rtk_coex_config {
	u8 single_chip: 1;
	u8 dual_chip: 1;
	u8 rsvd: 6;
	u8 mode;  			//enum rtk_coex_mode
	u8 log_enable; 		//enum rtk_coex_log_enable
	u16 wl_chip_protocol_map;
	u16 ext_chip_protocol_map;
	struct rtk_coex_config_vendor vendor_config;
};

struct rtk_coex_t {
	u8 coex_enable;
	struct rtk_coex_config  config;
	struct rtk_coex_ctrl ctrl;

	struct rtk_coex_timer timer[RTK_COEX_TIMER_MAX];
	u32 timer_map;

	struct rtk_coex_wl_chip wl_chip;
	struct rtk_coex_ext_chip ext_chip;

	struct rtk_coex_version_info version_info;
};

void *rtk_coex_get_coex_ptr(void);

void rtk_coex_wl_chip_init(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_wl_chip_send_fw_cmd(struct rtk_coex_t *p_rtk_coex, u8 h2c_id, u8 cmd_len, u8 *p_cmd_buf);
void rtk_coex_wl_chip_send_w2b_mailbox(struct rtk_coex_t *p_rtk_coex, u8 *p_mailbox_buf, u8 mailbox_buf_len);
u8 rtk_coex_wl_chip_set_wl_scbd(struct rtk_coex_t *p_rtk_coex, u32 bit_pos, u8 state);
u8 rtk_coex_wl_chip_write_wl2bt_scbd(struct rtk_coex_t *p_rtk_coex, bool b_force);
void rtk_coex_wl_chip_bcn_protection(struct rtk_coex_t *p_rtk_coex, u8 enable);
void rtk_coex_wl_chip_init_pta(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_wl_chip_mac_init_cfg(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_wl_chip_init_rf_cfg(struct rtk_coex_t *p_rtk_coex, u8 bt_enable);
void rtk_coex_wl_chip_mac_set_gnt(struct rtk_coex_t *p_rtk_coex, u8 gnt_bt, u8 gnt_wl);
void rtk_coex_wl_chip_set_wl_pri_mask(struct rtk_coex_t *p_rtk_coex, u8 pri_mask_type, u8 pri);
void rtk_coex_wl_chip_set_ant(struct rtk_coex_t *p_rtk_coex, u8 wl_bt_state, bool b_force_execute);
void rtk_coex_wl_chip_get_tdma_state(struct rtk_coex_t *p_rtk_coex, u8 *tdma_en, u8 *slot_num, u8 *wl_slot_duration, u8 *bt_ctrl_tdma);
void rtk_coex_wl_chip_set_policy(struct rtk_coex_t *p_rtk_coex, u32 policy_type, bool b_force_execute);
void rtk_coex_wl_chip_set_wlan_act(struct rtk_coex_t *p_rtk_coex, u8 b_auto);
void rtk_coex_wl_chip_hal_init(struct rtk_coex_t *p_rtk_coex, u8 b_wifionly);

void rtk_coex_wl_chip_man_ctrl_pta(struct rtk_coex_t *p_rtk_coex, u8 gnt_bt, u8 gnt_wl);
void rtk_coex_wl_chip_afh_5g_handle(struct rtk_coex_t *p_rtk_coex, u8 wl_center_ch, u8 wl_bw, u8 *h2c_para);
void rtk_coex_wl_chip_set_switch_band_para(struct rtk_coex_t *p_rtk_coex, u8 band_type);
void rtk_coex_wl_chip_set_switch_channel_para(struct rtk_coex_t *p_rtk_coex, u8 wl_center_channel);
void rtk_coex_wl_chip_bind(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_wl_chip_get_board_info(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_wl_chip_run_coex(struct rtk_coex_t *p_rtk_coex, bool b_init);
void rtk_coex_wl_chip_update_bt_scbd(struct rtk_coex_t *p_rtk_coex, bool b_only_update);
u32 rtk_coex_wl_chip_read_bt2wl_scbd(struct rtk_coex_t *p_rtk_coex);
u8 rtk_coex_wl_chip_monitor_bt_cnt(struct rtk_coex_t *p_rtk_coex);
u8 rtk_coex_wl_chip_monitor_wl_info(struct rtk_coex_t *p_rtk_coex, u8 idx_map, u8 reason);
void rtk_coex_wl_chip_bt_info_bt_scbd(struct rtk_coex_t *p_rtk_coex, u8 *data, u8 len);
void rtk_coex_wl_chip_bt_info_wl_fw(struct rtk_coex_t *p_mrcoex, u8 *data, u8 len);
void rtk_coex_wl_chip_trigger_bt_info(struct rtk_coex_t *p_rtk_coex);

void rtk_coex_extc_set_enable(bool enable);
bool rtk_coex_extc_is_enabled(void);
void rtk_coex_ext_chip_init(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_ext_chip_run_coex(struct rtk_coex_t *p_rtk_coex, u8 step);
void rtk_coex_ext_chip_bind(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_ext_chip_pta_pinmux(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_ext_chip_pta_gnt_config(struct rtk_coex_t *p_rtk_coex, bool manual);
void rtk_coex_ext_chip_get_board_info(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_ext_chip_set_board_info(void *info);
void rtk_coex_ext_chip_set_pta_enable(struct rtk_coex_t *p_rtk_coex, bool enable);
void rtk_coex_ext_chip_set_pta_para(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_ext_chip_set_tbl(struct rtk_coex_t *p_rtk_coex, u8 coex_tbl_choose, u32 coex_tbl_1, u32 coex_tbl_2, u32 coex_break_tbl);
bool rtk_coex_ext_chip_is_use_wlbtpta(void);

void rtk_coex_wl_chip_set_bt_rx_agc(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_wl_chip_set_bb_btg_ctrl(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_wl_chip_set_bt_rx_gain(struct rtk_coex_t *p_rtk_coex);
bool rtk_coex_wl_chip_get_chipinfo_bredr_support(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_wl_chip_tdma_drvc_set_slot(struct rtk_coex_t *p_rtk_coex, u8 slot_type);

void rtk_coex_wl_chip_update_bt_info(struct rtk_coex_t *p_rtk_coex, u8 *data, u8 len);
void rtk_coex_wl_chip_update_bt_extra_info(struct rtk_coex_t *p_rtk_coex, u8 *data, u8 len);
void rtk_coex_wl_chip_update_le_audio_tdma_rpt(struct rtk_coex_t *p_rtk_coex, u8 *data, u8 len);
void rtk_coex_wl_chip_update_bt_mp_report(struct rtk_coex_t *p_rtk_coex, u8 *data, u8 len);
void rtk_coex_wl_chip_update_le_init_scan_param(struct rtk_coex_t *p_rtk_coex, u8 *data, u8 len);
void rtk_coex_wl_chip_set_ra_mask_flt(struct rtk_coex_t *p_rtk_coex,  u8 ra_mask_flt);
void rtk_coex_wl_chip_trigger_bt_le_scan_param(struct rtk_coex_t *p_rtk_coex, u8 le_scan_type);

int rtk_coex_wl_fw_h2c_send(u32 cmd_len, u8 *p_cmd_buf);
u8 rtk_coex_wl_get_rfe_type(void);
u8 rtk_coex_wl_get_ant_div(void);
u8 rtk_coex_wl_get_bt_pos(void);
u8 rtk_coex_wl_get_ant_type(void);
u8 rtk_coex_wl_get_iface_nums(void);
void rtw_coex_wl_get_busy_status(u8 iface_idx, bool *p_wl_busy, u8 *p_wl_tp_status);
bool rtk_coex_wl_sta_mode_on(u8 iface_idx);
bool rtk_coex_wl_ap_mode_on(u8 iface_idx);
bool rtk_coex_wl_get_media_status(u8 iface_idx);
u8 rtk_coex_wl_get_center_channel(u8 iface_idx);
u8 rtk_coex_wl_get_wifi_rssi(u8 iface_type);
u8 rtk_coex_wl_get_bandwidth(u8 iface_idx);
bool rtk_coex_wl_link_11b_mode(void);
bool rtk_coex_wl_get_mp_mode(void);

// coex->bt application
void rtk_coex_btc_wl_send_sw_mailbox(u8 type, u8 *data, u16 length);

// coex enable/disable
void rtk_coex_com_coex_set_enable(bool enable);
bool rtk_coex_com_coex_is_enabled(void);
#endif


