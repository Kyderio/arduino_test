#ifndef __WIFIFW_TUNNEL_H__
#define __WIFIFW_TUNNEL_H__

//#include "rtw_wtn.h"

#if 1
#define WTN_AID_WINDOW_SLOT_NUM     		(1)
#define WTN_AID_WINDOW_SLOT_NUM_MSK 		(0xF)
#define WTN_MAX_NODE_NUM_IN_TBTT	32
#define WTN_MIN_NODE_NUM_IN_TBTT	16

#if defined(CONFIG_AMEBAGREEN2)
#define WIFI_TUNNEL_REFUGEE_NUM_MAX         32
#else
#define WIFI_TUNNEL_REFUGEE_NUM_MAX         4
#endif

#endif

#define ETH_ALEN 6

struct WTN_NODE_BSSIC {
	u8 node_mac[6];
	u8 node_aid;
	u8 node_buffer_data_by_ap : 1;
	u8 node_accepted_by_root : 1;
	u8 node_root_dl_relay_happened : 3;
};


struct WTN_BCN_HELPIE {
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
	s16 helpie_wtn_signal_lowest_2ap;

	u8 helpie_ap_ssid_len; //[put ssid in helpie_vlen_content]
	u8 helpie_my_refugee_num; //[put bssid of refugee in helpie_vlen_content after ssid]
	/* The helpie_vlen_content includes:
	1. AP SSID (<= 32 bytes)
	2. wtn_node_bssic_t (8 bytes) list, may include one fake item
	3. entire length (2 bytes)
	4. magic code (5 bytes) */
	u8 helpie_vlen_content[32 + (WIFI_TUNNEL_REFUGEE_NUM_MAX + 1) * 8 + 2 + 5];
};

#if 0
struct WTN_REFUGEE_INFO {
	u32 refugee_refresh_time_ms;
	u32 refugee_enter_time_ms; /* if we enter this father a short while ago, dont timeout it */
	u8 refugee_kickedoff_times;
	u8 refugee_enter_ps;

	struct WTN_NODE_BSSIC node;
};
#endif

struct WTN_PS_PARM {
	// struct WTN_REFUGEE_INFO   wtn_refugee[WIFI_TUNNEL_REFUGEE_NUM_MAX];
	u16 wtn_slot_time_us;
	u8 wtn_total_slot_num;
	u8 *wtn_slot_map;
	u8 wtn_wake_slot_index;
	u8 wtn_father_aid;
	u8 wtn_rfon;
	u8 wtn_refugee_aid_list[WIFI_TUNNEL_REFUGEE_NUM_MAX];
};

extern const char *TAG_FW_WTN;
extern u8 wififw_wtn_helpie_get_from_tail(u16 bcn_tail);
extern void wififw_wtn_get_wtn_node_bssic(u16 rxbuf_offset, struct WTN_NODE_BSSIC *node);
extern u8 wififw_wtn_helpie_parsing(u16 bcn_tail, u8 helpie_len);
extern u8 wififw_wtn_beacon_data_buffered(u16 bcnhead, u16 pktlen);
extern u8 wififw_wtnps_set_wake_slot_by_aid(u32 child_aid);
extern void wififw_wtnps_wake_slot_map_set(void);
extern u8 wififw_wtnps_find_next_wake_slot(u8 cur_slot);
extern u8 wififw_wtnps_twt_timer_enable(u64 cur_tst_time_us);
extern void wififw_get_tsf_port1(u32 *tsf_h, u32 *tsf_l);
extern void wififw_wtnps_bcn_early_inthdl(void);
extern void wififw_wtnps_twt_timer_early_inthdl(void);
extern void wififw_wtnps_twt_timer_inthdl(void);
extern void wififw_ps_mode_wtnps(void);
extern void wififw_wtnps_add_aid_to_list(u8 *aid);
extern void wififw_wtnps_delete_aid_from_list(u8 *aid);
extern void wififw_h2c_wtnps_set_father_aid(struct h2c_wtnps_father_aid_info *pbuf);
extern void wififw_h2c_wtnps_set_refugee_aid(struct h2c_wtnps_refugee_aid_info *pbuf);
#endif