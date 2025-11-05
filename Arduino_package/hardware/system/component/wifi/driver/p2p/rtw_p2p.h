#ifndef __RTW_P2P_H_
#define __RTW_P2P_H_

/*********************************/
/**	Define Constants & Macros	**/
/*********************************/
enum NOA_UPDATE_TYPE {
	NOA_MCC_STOP,	/* no NOA in beacon or probersp */
	NOA_MCC_DIRECT_START,	/* calculate NOA and update bcn */
	NOA_MCC_PRE_START,	/* record param first, wait for NOA_MCC_POST_START to actually calculate NOA */
	NOA_MCC_POST_START,	/* calculate NOA and update bcn after port0 tsf synced*/
	NOA_TSF_TOGGLE,	/* tsf 32bit toggle, need update noa */
};

/*****************************/
/**	Define Data Structure	**/
/*****************************/
struct p2p_noa_attr {
	u8	noa_idx;
	u8	noa_count;
	u32	noa_starttime;
	u32	noa_duration;
	u32	noa_interval;
	u8	noa_enable: 1;
};

struct p2p_priv {
	enum rtw_p2p_role p2p_role;
	u8	*p2p_probe_req_ie;
	u16	p2p_probe_req_ie_len;
	u8	*p2p_assoc_req_ie;
	u16	p2p_assoc_req_ie_len;
	u8	wireless_mode_backup;
	u8	mgnt_rate_backup;
	u8	b_roch_start: 1;
	u8	b_wlan1_scan: 1;
#ifdef CONFIG_P2PPS
	struct p2p_noa_attr noa;
#endif
};

u8 *rtw_get_p2p_ie(u8 *in_ie, u32 in_len, u8 *p2p_ie, u32 *p2p_ielen);
u8 *rtw_remove_p2p_ie(u8 *pframe, u32 *pkt_len);
int  rtw_p2p_on_action(u8 iface_type, union recv_frame *precv_frame);
void rtw_p2p_set_role(enum rtw_p2p_role role);
int rtw_p2p_remain_on_ch(u8 wlan_idx, u8 enable);
u8 *rtw_p2p_set_assoc_p2p_ie(u8 *pframe, u32 *pktlen);
u8 *rtw_p2p_set_probereq_p2p_ie(u8 *pframe, u32 *pktlen);
void rtw_p2p_set_mgnt_tx_rate(void);
void rtw_p2p_set_supported_rates(u8 *supported_rateset, u8 bssrate_len);
int rtw_p2p_probereq_indicate(u8 *pframe, u32 len, u8 iface_type);
void rtw_p2p_check_wildcast_ssid(u32 scan_ssidlen, u8 *be_p2p_wildcast_ssid);
int rtw_p2p_check_probersp_ess_bit(struct wlan_network *scan_network, u8 *pframe);
void rtw_p2p_scan_done_process(void);
int rtw_p2p_check_scan_option(u8 scan_option, u8 *iface_type);
void rtw_p2p_set_wlan1_scan(u8 enable, u8 *p_iface_type);
u8 rtw_p2p_get_roch_state(void);
#ifdef CONFIG_P2PPS
void rtw_p2p_noa_ie_append(u8 *pframe, u32 *pkt_len);
void rtw_p2p_on_beacon_noa(u8 *pframe, u32 pkt_len);
void rtw_p2p_probersp_noa_ie_append(u8 *pframe, u32 *pktlen);
void rtw_p2p_go_noa_update(u8 type, u32 p1_tbtt_before, u32 ap_active_dur);
#endif
#endif
