
#ifndef __WIFI_TUNNEL_H__
#define __WIFI_TUNNEL_H__

#include "wififw_h2c_c2h_format.h"

extern const char *TAG_WIFI_TUNNEL;
extern const u8 ICAN_HELP_OUI[];
extern const u8 WHOCAN_HELP_OUI[];
extern struct wtn_priv_t g_wtn;
extern struct wtn_ps_t g_wtn_ps;

#define wtn_get_ap_bssid      (g_wtn.wtn_ap_bssid)
#define wtn_self_mac          (primary_adapter.mac_addr)
#define wtn_self_aid          (primary_adapter.mlmeinfo.aid)
#define wtn_scan_state        rtw_check_under_sitesurvey()
#define wtn_ap_security_on    ((primary_adapter.securitypriv.dot11PrivacyAlgrthm == _NO_PRIVACY_) ? 0 : 1)
#define wtn_zrpp_can_help	  (g_wtn.b_wtn_zrpp_can_help_en && g_wtn.b_wtn_dhcp_success)

#if defined(CONFIG_AMEBAGREEN2)
#define WIFI_TUNNEL_REFUGEE_NUM_MAX         32
#else
#define WIFI_TUNNEL_REFUGEE_NUM_MAX         2 /*HW limit is 4, set 2 for default custom trial*/
#endif

#define REFUGEE_TIMEOUT_PTOTECT_TIME        300
#define SHOT_TIMER_TIMEOUT                  1000
#define HELPER_TIMEOUT                      5000

#define WTN_TOO_CLOSE_RSSI_THRESH           (-30)
#define WTN_STRONG_ROOT_TABLE_SIZE          (3)
#define WTN_RNAT_STONG_RSSI_THRESH          (-50)

#define REFRESH_KICKEDOFF_TIMES_THRESH      10 /* unit is 102.4 */
#define SWITCH_BY_SCORE_THRESH              5

#define HELP_BCN_TIMESTAMP_LEN    8
#define HELP_BCN_INTERVAL_LEN     2
#define HELP_BCN_CAPABILITYL_LEN  2

#define WTN_UI_DEMO_RSSI_SIM                1
#define WTN_GRAVIT_SHOW                     "gravitation show "

#define WTN_RSSI_WSIZE			30

#define WTN_MAX_OTA_VER_LEN		20
//=================================power save=================================
#define WTN_AID_WINDOW_SLOT_NUM     (1)
#define WTN_AID_WINDOW_SLOT_NUM_MSK (0xF)
#define WTN_MAX_NODE_NUM_IN_TBTT	32
#define WTN_MIN_NODE_NUM_IN_TBTT	16
//===============================refugee rssi==================================
#define WTN_MA_ACC(old, new_val, ma) ((old) - ((old) >> (ma)) + (new_val))
#define WTN_GET_MA_VAL(val, ma) (((val) + (1 << ((ma) - 1))) >> (ma))
//=============================================================================
enum wtn_hs_type_t {
	WIFI_TUNNEL_HELP_PLS = 0,
	WIFI_TUNNEL_HELP_YES = 1,
	WIFI_TUNNEL_HELP_NO = 2,
	WIFI_TUNNEL_HELP_ZRPP_REQ = 3,
	WIFI_TUNNEL_HELP_ZRPP_RSP = 4,
};

struct rtw_scaninfo4wtn_t {
	struct dot11_ssid Ssid;
	s32 Rssi;
	u8 MacAddress[6];
};

/* used for frame transfer & share between nodes */
struct wtn_node_bssic_t {
	u8 node_mac[ETH_ALEN];
	u8 node_aid;
	u8 node_buffer_data_by_ap : 1;
	u8 node_accepted_by_root : 1;
	u8 node_root_dl_relay_happened : 3;
};

struct wtn_bcn_helpie {
	u8 helpie_element_id; //802.11 WLAN_EID_VENDOR_SPECIFIC
	u8 helpie_length; //[helpie_oui->tail
	u8 helpie_oui[4];

	u8 helpie_bssid[ETH_ALEN];	///<target AP's bssid
	u8 helpie_root_mac[ETH_ALEN];	///<root's bssid
	u8 helpie_father_mac[ETH_ALEN];///<father's bssid
	u8 helpie_identity[4];

	u8 helpie_can_help_sta_num;
	u8 helpie_layer;
	u8 helpie_aid;
	u8 helpie_channel;

	u8 helpie_b_partial_bcn : 1;
	u8 helpie_b_helpprobe : 1;
	u8 helpie_b_leavebss : 1;
	u8 helpie_b_ap_changed : 1;
	u8 helpie_b_accepted_by_root : 1;
	u8 helpie_b_too_weak_no_helper : 1;
	u8 helpie_b_have_child_not_enter_ps : 1;
	u8 helpie_b_self_enter_ps : 1;

	u8 helpie_b_root_dl_relay_happened : 1;
	u8 helpie_b_rnat_bcn : 1;
	u8 helpie_b_rnat_group : 1;
	u8 helpie_b_zrpp_can_help : 1; //can help provision wifi to other devices using Zero R-mesh Provisioning Protocal(ZRPP)

	s16 helpie_wtn_signal_lowest_2ap;

	u8 helpie_ap_ssid_len; //[put ssid in helpie_vlen_content]
	u8 helpie_my_refugee_num; //[put bssid of refugee in helpie_vlen_content after ssid]
	/* The helpie_vlen_content includes:
	1. AP SSID
	2. wtn_node_bssic_t (8 bytes) list, may include one fake item
	3. entire length (2 bytes)
	4. magic code (5 bytes) */
	u8 helpie_vlen_content[RTW_ESSID_MAX_SIZE + (WIFI_TUNNEL_REFUGEE_NUM_MAX + 1) * 8 + 2 + 5];
} RTW_PACK_STRUCT_STRUCT;

//{"PLS", "YES", "NO"}
struct wtn_help_payload_t {
	u8 root_mac[ETH_ALEN]; //for bye it's invalid
	u8 depart_father_mac[ETH_ALEN];
	u8 requestor_aid;
	u8 too_weak_no_helper : 1;

	u8 child_num;
	struct wtn_node_bssic_t child_tbl[WIFI_TUNNEL_REFUGEE_NUM_MAX];
};

struct wtn_node_t {
	struct list_head list;
	u32 node_refresh_sys_time_ms;
	s32 node_rssi_sum;
	s16 node_rssi_map[WTN_RSSI_WSIZE];
	s16 node_rssi_aver;
	s16 node_score;
	s16 node_lowest_2ap_signal;
	s16 node2me_signal_strength; /* node to me */

	u8 node_rssi_seq;
	u8 node_ssid[33]; /**< SSID name (AP name)  */
	u8 node_true_bssid[ETH_ALEN];
	u8 node_root_mac[ETH_ALEN];

	u8 node_aid;
	u8 node_layer;
	u8 node_can_help_num;
	u8 node_accepted_by_root : 1;
	u8 node_too_weak_no_helper : 1;
	u8 node_enter_wtn_ps : 1;
	u8 node_root_dl_relay_happened : 1;
	u8 node_rssi_num_full : 1;
};

struct wtn_refugee_info_t {
	u32 refugee_refresh_time_ms;
	u32 refugee_enter_time_ms; /* if we enter this father a short while ago, dont timeout it */
	u8 refugee_kickedoff_times;
	u8 refugee_enter_ps;
	u8 refugee_used;

	u8 refugee_rssi;/*convert to dbm need -100*/
	u16 refugee_rssi_ma;/*convert to dbm need -100*/

	struct wtn_node_bssic_t node;
};

struct wtn_priv_t {
	struct dot11_ssid             wtn_ap_ssid;
	struct wtn_refugee_info_t     wtn_refugee[WIFI_TUNNEL_REFUGEE_NUM_MAX];
	struct wtn_bcn_helpie         wtn_helpie_buf;
	struct h2c_ra_cfginfo         wtn_sta_ra_cfg;
	struct __queue                wtn_scan_list;
	struct __queue                wtn_frame_pending_list;
	_lock                         wtn_refugee_lock;

	struct timer_list wtn_hs_wait_timer;

	u32 wtn_frame_pending_cnt;
	u32 wtn_short_timer_start_ms;
	u32 wtn_father_refresh_time_ms;
	u8 wtn_can_not_help_times;
	u8 wtn_me_kickedoff_times;

	/* for root group use */
	u8 wtn_self_layer; /* self layer*/
	u8 wtn_ap_bssid[ETH_ALEN];	///<target AP's bssid
	u8 wtn_root_mac[ETH_ALEN];	///<root's bssid
	u8 wtn_father_mac[ETH_ALEN];///<father's bssid
	u8 wtn_identity[4];
	u8 wtn_identity_key[16];
	u8 wtn_father_can_help_sta_num;//from father IE
	u8 wtn_father_aid;	//father's aid, from father IE
	u8 wtn_refugee_num;	///< should <= WIFI_TUNNEL_REFUGEE_NUM_MAX
	u8 wtn_partial_bcn_len_without_helpie;

	s16 wtn_ap_signal_strength;
	s16 wtn_father_signal_strength;
	s16 wtn_father_score;
	s16 wtn_signal_lowest_2ap;
	u16 wtn_ap_bcnie_len;

	u8 *wtn_ap_bcnie;
	u8 wtn_scan_cnt;
	u8 wtn_strongroot_macs[WTN_STRONG_ROOT_TABLE_SIZE];
	u8 wtn_strongroot_num;

	// info of the device(helper) who provides us with wifi info during Zero R-mesh Provisioning Protocol(ZRPP)
	u8 wtn_zrpp_helper_mac[ETH_ALEN];
	u8 wtn_zrpp_helper_ch;
	s16 wtn_zrpp_helper_rssi;

	u8 b_wtn_zrpp_scan_ongoing : 1;

	u8 b_wtn_strongroot_allfull : 1;
	u8 b_wtn_strongroot_mein : 1;
	u8 b_wtn_ap_strong : 1;
	u8 b_wtn_user_req : 1;
	u8 b_wtn_hs_pair_success : 1;
	u8 b_wtn_wait_hs_pair_success : 1;
	u8 b_wtn_ap_join_success : 1;
	u8 b_wtn_dhcp_success : 1;
	u8 b_wtn_accepted_by_root : 1;
	u8 b_wtn_ap_changed : 1;
	u8 b_wtn_ap_join_progress : 1;
	u8 b_wtn_too_weak_no_helper : 1;
	u8 b_wtn_rnat_start : 1;
	u8 b_wtn_father_in_rnat_group : 1;
	u8 b_wtn_trigger_scan_again : 1;
	u8 b_wtn_zrpp_can_help_en : 1; //can help provision wifi to other devices using Zero R-mesh Provisioning Protocal(ZRPP)

	u8 b_wtn_dbg_helpierx : 1;
	u8 b_wtn_dbg_helpietx : 1;
	u8 b_wtn_dbg_power_save : 1;
	u8 b_wtn_dbg_bcn_sync: 1;
};

struct wtn_ps_t {
	u32 wtn_rfon_time_ms_show_gravitation;
	u32 wtn_rfon_time_ms_this_tbtt;
	u32 wtn_p1_tbtt_seconds;
	u32 wtn_rfon_start_ms;

	u8 *wtn_slot_map;
	u16 wtn_slot_time_us;
	u8 wtn_total_slot_num;
	u8 wtn_wake_slot_index;

	u8 wtn_wink_mode_leave_times;
	u8 wtn_wink_switch_decided_times; //in wink mode, we should leave and send null-0, then some time later switch

	u8 b_wtn_root_dl_relay_happened : 3;
	u8 b_wtn_have_child_not_enter_ps : 1;
	u8 b_wtn_rf_off : 1;
	u8 b_wtn_in_wink_mode : 1;
	u8 b_wtn_wink_mode_user_en : 1;
	u8 b_wtn_fw_wink_mode_en : 1; //fw do rf on/off
	u8 b_wtn_scan_in_wink_mode : 4;
};

inline u8 wifi_tunnel_be_empty_mac(u8 *mac)
{
	u8 empty_mac = 1;
	u8 index = 0;

	for (index = 0; index < 3; index++) {
		if (mac[index] != 0) {
			empty_mac = 0;
			break;
		}
	}

	return empty_mac;
}

s8 wifi_tunnel_gravitation_rssi_by_bssid_get(const u8 *bssid);
void wifi_tunnel_gravitation_rssi_by_bssid_set(const char *argv[], int argc);
void wifi_tunnel_gravitation_rssi_init(void);
void wifi_tunnel_gravitation_rssi_show(void);
void wifi_tunnel_bcn_trigger_dynamic_check(void);

/* wifi tunnel configure */
void wifi_tunnelapi_sw_init(void);
void wifi_tunnelapi_sw_deinit(void);
u8 wifi_tunnel_check_mac_contain_in_mactable(u8 *mac_addr, u8 *mac_table, u8 mac_num);
int wifi_tunnel_check_mac_contain_in_nodetable(u8 *mac_addr, struct wtn_node_bssic_t *node_table, u8 mac_num);
void wifi_tunnel_update_rsvpage_macswap(u8 enbale_swap);
void wifi_tunnelapi_setkey(struct set_stakey_parm *pparm);
void wifi_tunnelapi_set_racfg(u8 *sta_ra_cfg);
void wifi_tunnelapi_change_txbd_num(void);
void wifi_tunnel_dump_info(void);
void wifi_tunnelapi_identity_calculate(u8 *grpkey, u8 *help_mac, u8 *bssid, u8 *outbuf);

/* wifi tunnel helpie */
struct wtn_node_bssic_t *wifi_tunnel_helpie_get_refugee_table(struct wtn_bcn_helpie *phelpie);
u16 wifi_tunnel_helpie_get_entire_len(struct wtn_bcn_helpie *phelpie);
void wifi_tunnel_helpie_update_tosw(struct wtn_bcn_helpie *phelpie, u8 partial_bcn);
void wifi_tunnelapi_helpie_update_tohw(void);
struct wtn_bcn_helpie *wifi_tunnel_helpie_get_from_tail(u8 *pbcnie_tail);
void wifi_tunnel_helpie_parse(struct wtn_bcn_helpie *phelpie, u8 *sender_mac);

/* wifi tunnel beacon */
int wifi_tunnel_send_raw_frame(struct rtw_raw_frame_desc *raw_frame_desc);
void wifi_tunnel_issue_beacon_partial(void);
void wifi_tunnel_beacon_partial_update_tim(void);
void wifi_tunnelapi_on_beacon(union recv_frame *precv_frame);
void wifi_tunnel_issue_beacon_entire(u8 *receiver);
void wifi_tunnel_issue_helpprobe(void);

/* wifi tunnel frame */
void wifi_tunnelapi_pending_q_free(void);
void wifi_tunnelapi_pending_q_resume(void);
void wifi_tunnel_socket_normal_rpt_send(void);

/* wifi tunnel scan */
struct wtn_node_t *wifi_tunnel_scan_get_best_node(void);
void wifi_tunnel_scan_free_one_node(u8 *wtn_true_bssid);
void wifi_tunnel_scan_dump_report_list(void);
void wifi_tunnel_scan_report_one_node(struct rtw_scaninfo4wtn_t *scan_info, struct wtn_bcn_helpie *phelpie);
void wifi_tunnel_scan_free_timeout_helper(void);
void wifi_tunnel_scan_free_report_list(void);
void wifi_tunnelapi_scan_original_rssi_record(struct wlan_network *new_network, u8 is_wtn_bcn);
struct wtn_node_t *wifi_tunnel_scan_pop_match_node(u8 *wtn_true_bssid);

/* wifi tunnel handshake */
void wifi_tunnel_handshake_on_hs_frame(u8 *rx_desc, u8 *pframe, u16 pframe_len);
void wifi_tunnel_handshake_issue_help_pls(struct wtn_node_t *target_helper, u8 switch_helper);
void wifi_tunnel_handshake_issue_help_yes(u8 *requestor, struct wtn_help_payload_t *phelp_payload, u16 payload_len);
void wifi_tunnel_handshake_issue_help_no(u8 *requestor, struct wtn_help_payload_t *phelp_payload, u16 payload_len);
void wifi_tunnel_handshake_issue_bye_to_node(u8 *refigee_mac);
void wifi_tunnel_handshake_wait_timer_handler(void *arg);
void wifi_tunnel_handshake_issue_help_frame(u8 handshake_type, u8 *receiver, u8 *phelp_payload, u16 payload_len);

/* Zero R-mesh Provisioning Protocol */
int wifi_tunnel_zrpp_on_hs_req(u8 *pframe);
int wifi_tunnel_zrpp_on_hs_rsp(u8 *pframe);
void wifi_tunnel_zrpp_issue_hs_req(u8 *requestor);
void wifi_tunnel_zrpp_issue_hs_rsp(u8 *requestor, u8 *payload, u16 payload_len);

/* corner case process */
void wifi_tunnel_sw_issue_sw2group_through_ap(u8 *child_tbl, u8 child_num_in, u8 *switch_leader_mac, u8 *pdepart_root_mac, u8 *pdepart_father_mac);
int wifi_tunnel_sw_bye2group(struct wtn_help_payload_t *phelp_payload, u8 *requestor, u8 child_num);

/* wifi tunnel refugee */
int wifi_tunnel_refugee_add(u8 *addr, u8 aid);
int wifi_tunnel_refugee_del(u8 *addr);
void wifi_tunnel_refugee_table_clear(void);
int wifi_tunnel_refugee_table_get_index(u8 *addr);
void wifi_tunnel_refugee_udate_num(u8 add, u8 refugee_idx);
void wifi_tunnel_refugee_dump(void);
void wifi_tunnel_refugee_timeout_check(void);
u8 wifi_tunnel_refugee_get_ican_help_num(void);
void wifi_tunnelapi_refugee_get_rssi_min(u8 *p_odm_rssi_min, u8 *p_odm_pre_rssi_min);
void wifi_tunnel_refugee_rssi_update(s16 rssi, int refugee_idx);

/* wifi tunnel switch */
void wifi_tunnel_switch_to_ap(struct wtn_node_t *target_node);
void wifi_tunnel_switch_to_helper(struct wtn_node_t *target_node, u8 switch_helper);
int wifi_tunnel_switch_on_sw_through_ap(u8 *rx_data);
int wifi_tunnelapi_dynamic_check(struct sta_mlme_priv *psta_mlmepriv);
void wifi_tunnel_switch_score_father_get(struct wtn_bcn_helpie *phelpie, s16 Rssi, u8 *sender_mac, s16 node_score);
s16 wifi_tunnel_switch_score_node_get(s16 *pRssi, struct wtn_bcn_helpie *phelpie, u8 *sender_mac);
void wifi_tunnel_switch_to_best_node(void);
void wifi_tunnel_switch_to_target_node(struct wtn_node_t *best_node);
void wifi_tunnel_switch_check(void);
void wifi_tunnel_switch_father_off_check(void);

/******************* connect *******************/
void wifi_tunnelapi_joinbss_set_network_by_user(u8 *user_bssid, u8 *user_ssid);
void wifi_tunnelapi_joinbss_set_target_network_by_joinscan(struct wlan_network *ptarget_network);
u32 wifi_tunnelapi_joinbss_set_current_network_by_joincmd(struct wlan_network *pcur_network);
void wifi_tunnelapi_joinbss_done_indicate(u8 iface_type);
void wifi_tunnelapi_leavebss_indicate(u16 disassoc_reason);
int wifi_tunnelapi_joinbss_check_helperlist_ready(u8 ap_channel, int ap_rssi);
int wifi_tunnelapi_joinbss_continue_after_pair_success(void);

/* hal_wifi_tunnel.c */
void hal_wifi_tunnel_refugee_update(u8 *macaddr, u8 addr_idx, u8 add);
void hal_wifi_tunnel_macid_and_aid_update(u8 *macaddr, u8 mac_id, u8 aid, u8 add);
void hal_wifi_tunnel_mode_set(u8 enable);
void hal_wifi_tunnel_cam_entry_valid(u32 entrys, u8 valid);
void hal_wifi_tunnel_update_father_mac_and_aid(u8 *father_mac, u8 aid, u8 add);
void wifi_tunnel_relay_frame(u8 *rx_data, u16 data_len, u8 ul_swap, u8 frame_tag, u8 dhcp, u8 privacy);
void hal_wifi_tunnel_port1_and_beacon_enable(void);
void hal_wifi_tunnel_prepare_rx_zrpp_hs(u8 channel);
void hal_wifi_tunnel_beacon_enable(u8 enable);
void hal_wifi_tunnel_rnat_partial_bcn_enable(void);

/* ps */
void wtn_ps_p1_bcn_interrupt_hdl(void);
void wtn_ps_p1_sync_with_p0(void);
void wtn_ps_dbg_dump(void);
void wtn_ps_wink_leave(u8 leave_times, char *leave_reason);
void wtn_ps_wink_enter(void);
void wtn_ps_wink_leave_times_set(u8 ps_leave_times);
void wtn_ps_wink_mode_check(void);
void wtn_ps_root_dl_relay_set(u8 *mac_addr);
void wtn_ps_tim_aid_check_by_root(u8 *pframe, u16 frame_len);
void wtn_ps_dbg_bcn_gpio_init(void);
void wtn_ps_slot_time_calculate(void);
/******************* trx *******************/
extern void wifi_tunnelapi_update_txdata_macswap(struct txdesc_priv *ptxdesc, u8 *pframe, u8 sc);
extern int wifi_tunnelapi_rx_process(u8 *rx_desc, union recv_frame *precvframe);

/* wifi tunnel cmd */
void wifi_tunnel_command(char *cmd_ptr, u32 extra_arg);

/* rnat */
void wifi_tunnel_rnat_softap_start(u8 enable);
void wifi_tunnel_rnat_bcn_statistic(struct wtn_bcn_helpie *phelpie, u8 bssid_match);
int wifi_tunnel_rnat_rx_process(u8 subtype, u8 *sa);
void wifi_tunnelapi_rnat_softap_bcnie_record(u8 *IEs, u32 ie_len);
int wifi_tunnelapi_rnat_wtn_bcn_bypass(union recv_frame *precv_frame);
#endif
