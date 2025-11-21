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

/*-------------------------------------------------------------------------------
	Premature includes for related structures which will not use padapter.
--------------------------------------------------------------------------------*/
#ifndef __RTW_ADAPTER_H__
#define __RTW_ADAPTER_H__

#include "ameba.h"
#include "rtw_wifi_constants.h"
#include "rom_rtw_core.h"
#include "rom_wifi_hal.h"
#include "rtw_wifi_common.h"

#include <rtw_debug.h>

#include <os_wrapper.h>
#include <wifi_api.h>
#include <wifi_fast_connect.h>
#include <rtw_timer.h>
#include <rtw_task.h>
#include <rtw_queue.h>
#include <rtw_wakelock.h>
#include <rtw_atomic.h>
#include <rtw_misc.h>
#include "wifi_intf_drv_to_upper.h"

#ifdef CONFIG_RTW_MBO
#include <rtw_mbo.h>
#endif
#include <rtw_sta_mgt.h>
#include <rtw_macid_mgt.h>
#include "rtw_wifi_struct.h"
#include <rtw_skbuff.h>
#include <rtw_cmd.h>
#include <rtw_xmit.h>
#include <rtw_recv.h>
#include <rtw_rrm.h>
#include <phl_def.h>
#include "rtw_11d.h"

#ifdef CONFIG_80211AC_VHT
#include <rtw_vht.h>
#endif
#include "wpa_lite_intf.h"
#include "rtw_pmksa_cache.h"
#include <rtw_security.h>
#include <rtw_lps.h>
#include <rtw_sitesurvy.h>
#include <rtw_shortcut.h>
#include <rtw_connect.h>
//#ifdef CONFIG_TWT
#include <rtw_twt.h>
//#endif

#include <rtw_mp.h>
#include <rtw_state.h>
#include <rtw_promisc.h>

//#ifdef CONFIG_NAN
#include <rtw_nan.h>
//#endif
#ifdef CONFIG_P2P
#include <rtw_p2p.h>
#endif
#include <rtw_mcc.h>
#include <rtw_wtn.h>

/*-------------------------------------------------------------------------------
	Frequently used first-layer child structs of padapter.
--------------------------------------------------------------------------------*/
struct ht_priv {
	struct rtw_ieee80211_ht_cap		ht_cap;
	struct HT_caps_element			*HT_caps;
	struct ht_info_element_t			*HT_info;

	u8					ht_enable;
	u8					ht_option;
	u8					ampdu_enable;			/* for enable Tx A-MPDU */
	u8					bwmode;
	u8					ch_offset;
	u8					sgi_20m;			/* short GI */
	u8					sgi_40m;
	u8					addba_success_bitmap;
	u8					addba_ongoing_bitmap;
	u8					addba_retry_bitmap;
	u8					addba_giveup_bitmap;

	u8					HT_enable;
	u8					HT_caps_enable;
	u8					HT_info_enable;
	u8					HT_protection : 2; //dot11 spec
#ifdef CONFIG_80211AC_VHT
	u16					vht_beamform_cap;
	u8					vht_option;
	u8					vht_ldpc_cap;
	u8					vht_stbc_cap;
	u8					vht_mcs_map[2];
#endif
#ifdef CONFIG_80211AX_HE
	struct HE_caps_element *HE_caps;
	u8					*HE_op;
	u8					he_option;
	u8					pre_he_muedca_cnt;
	u8					he_muedca_enabled;
#endif
	u32					rom_rsvd;
};

#ifdef CONFIG_OWE_SUPPORT
struct owe_priv {
	u8					param_ready;
	u8					len;
	u8					dh_ie_info[1 + 2 + RTW_OWE_KEY_LEN]; /*1(EID ext)+2(group)+32(pubkey)*/
};
#endif

struct sta_security_priv {
//#ifdef CONFIG_IEEE80211W
	struct timer_list		dot11w_expire_timer;
//#endif /* CONFIG_IEEE80211W */
	union Keytype		dot11tkiptxmickey;
	union Keytype		dot11tkiprxmickey;
	union Keytype_32		dot118021x_UncstKey;
	union pn48			dot11txpn;			/* PN48 used for Unicast xmit. */
	union pn48			dot11rxpn;			/* PN48 used for Unicast recv. */
	union pn48			dot11wtxpn; 		/* PN48 used for Unicast mgmt xmit. */

	/* NAN used, peer's GTK, RX only */
	u8 group_privacy;
	u8 gtk_bmp;
	union Keytype gtk;
	union pn48 gtk_pn;

	/* NAN used, peer's IGTK, RX only */
	u8 igtk_bmp;
	u8 igtk_id;
	union Keytype igtk;
	union pn48 igtk_pn;

	u32					dot11_security_privacy;		/* aes, tkip... */
	int					sta_wpa_psk;			/* 0:disable, bit(0): WPA, bit(1):WPA2 */

	u8					b_pairwise_key_installed : 1;
	u8					b_ieee8021x_blocked : 1;		/* 0: allowed, 1:blocked */
	u8					b_setkey_en : 1;			/* normal join: set after eapol4 txdone; FT roaming: set after rx assocrsp, considering no need to execute 4-way handshake */
u8					b_wait_eapol4_for_setkey :
	1;	/* If rtw_setkey() is called before tx eapol4 (b_setkey_en == 0), set b_wait_eapol4_for_setkey = 1 for setting pairwise key after tx eapol4.*/

	u16					rom_rsvd;
};

/* for mp code */
//#ifdef TX_SHORTCUT
struct sta_sc_priv {
//#ifdef TX_SHORTCUT
	struct tx_sc_entry			tx_sc_ent[TX_SC_ENTRY_NUM];
	struct tx_raw_sc_entry		tx_raw_sc_ent;
//#endif
	u8	tx_sc_replace_idx;
	u16 rom_rsvd;
};
//#endif
struct sta_mlme_priv {
	struct sta_security_priv *psta_security; /* point to sta->sta_security*/
	struct sta_recv_priv *psta_recvpriv; /* point to sta->sta_recvpriv*/
	struct sta_xmit_priv *psta_xmitpriv; /* point to sta->sta_xmitpriv*/
	struct sta_sc_priv *psta_scpriv; /* point to sta->sta_scpriv*/
	void *pphy_stainfo; /* point to sta->phy_stainfo*/
	void	*pspeaker_stainfo;

	rtos_mutex_t			mutex;
	struct list_head		auth_list;
	struct list_head		asoc_list;

	struct asoc_cap_t		asoc_cap;
	struct __queue			sleep_q;
	struct rtw_chan_def		chandef;
	struct ht_priv			htpriv;
	struct sta_rssi_info	sta_rssi_stat;

	u32			wmode;/*val: RTW_80211_B, RTW_80211_G...*/
#if (PHYDM_VERSION == 2)
	enum wireless_set	support_wireless_set;/*[Driver]*/
#endif
	u64					supported_rate_map; /* drv decide by specific req, tx rate bitmap */

	u32					sta_bssratelen;
	u32					stainfo_authalg;
	u32					stainfo_flags;

	u32					stainfo_tx_byte_uni_in2s;
	u32					stainfo_rx_byte_uni_in2s;
	u16					stainfo_rx_data_pkts_in2s;
	u16					stainfo_rx_mgnt_pkts_in2s;
	u16					stainfo_rx_ctrl_pkts_in2s;

	u16					sta_capability;
	s16					sleepq_len;
	u16					ap_auth_seq;

	/* port0:
		* aid is aid from ap
		* macid 0 for sta, 1 for bcmc
	* por1:
		* aid=0&macid=1 for bcmc
		* aid=1/2/3..., macid=2/3/4...: for ap's sta
	*/
	u16					stainfo_aid;
	u8					stainfo_macid;
	u8					sta_iface_type;
	u8					stainfo_mac_addr[6]; /* driver */

	u8					stainfo_rx_bcn_pkts_in2s;
	u8					stainfo_rx_tp_mbits_smooth;
	u8					stainfo_tx_tp_mbits_smooth;
	u8					ra_pre_bcn_rssi;	/* record pre bcn rssi, send 0x42 only when bcn rssi changed */

	u8					expire_to_x2s;
	u8					twt_id; 			/* bit0 represent id0, .......bit7 represent id7 */

	u8					sta_bssrateset[16]; /* to be check */
	u8					sta_qos_info;
	u8					sta_raid;
	u8					sta_state;
	u8					muedca_enable_delay;

	u8					b_ap_pollsta_tx_null0_retry : 4;
	u8					b_ap_pollsta_tx_null0_fail : 1;
	u8					b_ap_pollsta_tx_null0 : 1;
	u8					b_erp_protection : 1;
	u8					b_nonerp_set : 1;
	u8					b_no_short_slot_time_set : 1;
	u8					b_no_short_preamble_set : 1;
	u8					b_no_ht_gf_set : 1;
	u8					b_no_ht_set : 1;
	u8					b_ht_20mhz_set : 1;
	u8					b_sta_qos_option : 1;
	u8					b_stainfo_active : 1;
	u32					rom_rsvd;
};

struct sta_info {
	struct list_head		list;				/* sta_list */

	/* core/driver/phydm/g6 common */
	struct phy_sta_info 		phy_stainfo;

	struct sta_security_priv	sta_security;
	struct sta_xmit_priv		sta_xmitpriv;
	struct sta_recv_priv		sta_recvpriv;
	struct sta_mlme_priv		sta_mlmepriv;
//#ifdef TX_SHORTCUT
	struct sta_sc_priv			sta_scpriv;
//#endif

	/* NAN used, peer's BIGTK, RX only */
	u8 bigtk_bmp;
	u8 bigtk_id;
	union pn48 bigtk_pn;
};

/*
Accesser of recv_priv: rtw_recv_entry(dispatch / passive level); recv_thread(passive) ; return pkt(dispatch); halt(passive) ;
Using enter_critical section to protect.
*/
struct recv_priv {
	struct rx_sc_entry	rx_sc_ent[RX_SC_ENTRY_NUM];
	u8					rx_sc_replace_idx;

	struct rtw_rx_ring	rx_ring[MAX_RX_QUEUE];

	struct __queue				free_recv_queue;

	struct amsdu_priv_t	*amsdu_priv;
#ifdef CONFIG_G2_WIFI
	struct rtw_csi_radar_rxbd	csiradar_rxbd;
#endif
	u8					*pallocated_frame_buf;

	u16					rxbuffersize;
	s8					free_recvframe_cnt;
	s8					rxringcount;
	u8					b_rxbd_use_skb : 1;
	u32					rom_rsvd;
};

struct xmit_priv {
	rtos_mutex_t		mutex;
	struct __queue				free_xmit_queue;
	struct rtw_tx_ring	tx_ring[RTW_MAX_TX_QUEUE_COUNT];

	u8					*pallocated_frame_buf;
	u8					*pxmit_frame_buf;

	u8					free_xmitframe_cnt;
	u8					tx_agg_max_num;

	u8					beaconDMAing;			/* Flag of indicating beacon is transmiting to HW by DMA */
	u8 					tx_done_seq;
	u32					rom_rsvd;
};

struct	hw_xmit	{
	struct __queue					sta_queue;
	int					accnt[RTW_MAX_TX_QUEUE_COUNT];
};

struct ap_mlme_priv {
	rtos_mutex_t		bcn_update_mutex;
	rtos_mutex_t		expire_mutex;
	rtos_mutex_t		asoc_list_mutex;
	rtos_mutex_t		auth_list_mutex;
	struct list_head	asoc_list;
	struct list_head	auth_list;

	u32					aid_bitmap; /* bit index is alloced aid, bit0 is not used */
	u16					sta_dz_bitmap;			/* Only support 15 stations, staion aid bitmap for sleeping sta. */
	u16					tim_bitmap;			/* Only support 15 stations, aid=0~15 mapping bit0~bit15 */

	u8					hidden_ssid_mode;
	u8					num_sta_no_ht;			/* Number of non-HT AP/stations */
	u8					num_sta_non_erp;		/* Number of associated Non-ERP stations (i.e., stations using 802.11b in 802.11g BSS) */
	u8					num_sta_no_short_slot_time;	/* Number of associated stations that do not support Short Slot Time */
	u8					num_sta_no_short_preamble;	/* Number of associated stations that do not support Short Preamble */
	u8					num_sta_ht_no_gf;		/* Number of HT associated stations that do not support greenfield */
	u8					num_sta_ht_20mhz;		/* Number of HT associated stations 20 MHz */
	u8					num_sta_no_wmm;
	u8					olbc_ht;			/* Overlapping BSS information */
	u8					ht_op_mode;
	u8					update_bcn;
	/*ap csa related*/
	u8					ap_csa_start;
	u8					csa_new_chl;
	u8					csa_action_type;	/* 0: unicast csa action, 1: broadcast csa action */
	u8					bc_action_cnt; /* indicate the number of broadcast csa actions to send for each beacon interval. only valid when action_type = 1*/
	u8					nan_linking_client_cnt;		/* represent the number of client under linking */
	u8					b_start_bss : 1;
	u8					eapol_key_rsnd_limit : 4;	/* retry limit of eapol key resnd for 4way/2way */
	u8					b_invisible : 1;	/* softap is not allowed to be discovered: pause BCN_Q & not resp probe_req. scenario:port1 only used for tx_raw */
	u8 					rom_rsvd[8];
};

struct ap_priv {
	struct timer_list	ap_csa_update_timer;
	/* pointers to STA info; based on allocated AID or NULL if AID free
	 * AID is in the range 1-2007, so sta_aid[0] corresponders to AID 1
	 * and so on
	 */
	struct ap_join_info			*apjoininfo;
	union recv_frame			*ap_bcmc_recvframe;
	u8					*csa_ie;

	void (*ap_channel_switch_callback)(u8 channel, s8 ret);/*ret val: RTK_FAIL, RTK_SUCCESS*/
};

struct pwrctrl_priv {
	rtos_sema_t			lock;

	u32					ips_deny_time;			/* will deny IPS when system time is smaller than this */
	u32					DelayLPSLastTimeStamp;
	u64					wowlan_fw_iv;

	u8					LpsIdleCount;
	u8					lps_mode;
	u8					ips_level;
	u8					legacy_ps_listen_interval; //unit: 102.4 ms(100 TUs)
	u8					bcn_ant_mode;
	u8					wowlan_mode;
	u8					wowlan_wake_reason;
	u32					last_dynamic_timer_process_time;
	u32					last_ips_check_time;
	u8					b_allQueueUAPSD : 1;
	u8					b_ips_user_req : 1;
	u8					b_ips_driver_req : 1;
	u8					b_ips_processing : 1;
	u8					b_ps_processing : 1;			/* temporarily used to mark whether in rtw_ps_processor */
	u8					b_lps_driver_req : 1;
	u8					b_lps_user_req : 1;
	u8					b_InSuspend : 1;

	u8					b_keepfwalive : 1;
	u8					b_ips_miss_by_bt_req : 1;
	u8 					rom_rsvd[8];
};
/* Mac Layer management entire:
 * Manage the settings of some common wifi events, like scan, join, csa.
 * Manage some basic wifi parameters, like mac address, band, channel.

there are several "locks" in mlme_priv,
since mlme_priv is a shared resource between many threads,
like ISR/Call-Back functions, the OID handlers, and even timer functions.

Each struct __queue has its own locks, already.
Other items are protected by mlme_priv.lock.

To avoid possible dead lock, any thread trying to modifiying mlme_priv
SHALL not lock up more than one locks at a time!

*/
struct mlme_priv {
	rtos_mutex_t				mutex;
	rtos_mutex_t				target_network_mutex;
	rtos_mutex_t 				h2c_mutex;
	rtos_mutex_t				set_chan_mutex;
	struct transition_disable_ctx	transition_disable;
	struct dot11_ssid			assoc_ssid;
	struct wlan_network			target_network;
	struct dot11_ssid			target_ssid;
	struct timer_list			scan_to_timer;			/* driver itself handles scan_timeout status. */
	struct timer_list			dynamic_chk_timer;		/* dynamic/periodic check timer */
	struct timer_list			survey_timer;
	struct timer_list			join_timer;
	struct timer_list			csa_timer;
	int					connect_result;	/*RTK_FAIL/ -RTK_ERR_WIFI_CONN_INVALID_KEY...*/

	u16					disassoc_reason;
	u32 				ac_param_be; //Original parameter for BE, use for EDCA turbo.
	/* Log: Merge from mlmeext. */
	u16					mgnt_seq;

	u8					assoc_bssid[6];
	u8					ipaddr[4];
	u8 					key_mask;			/* use for ips to set wep key after rtw_ips_leave */
	u8					acm_mask;			/* for wmm acm mask */
	u8					ChannelPlan;
	u8 					country_code[COUNTRY_CODE_LEN];
	u8					wmm_param[18];
	u8					tx_rate_ToS_cfg;		/* 8 bit control 8 ToS type */
	u8					tx_rate_by_ToS[8];		/*record different ToS's tx rate which configured by user */

	u64					mgnt_80211w_IPN;
	u64					mgnt_80211w_IPN_rx;
	u16					sa_query_seq_11w;
	u16					max_join_timeout;		/* auth + assoc */
	u8					key_type_11w;			/* for debug */
	u8 					rtw_pmf_mode; /* This variable is used to set PMF mode by AT command (ATMF)
									 0 : NO_MGMT_FRAME_PROTECTION
									 1 : MGMT_FRAME_PROTECTION_OPTIONAL
									 2 : MGMT_FRAME_PROTECTION_REQUIRED */

	u8					wireless_mode_support;		/* A, B, G, auto */
	u8					band_type_support;
	u8					cur_wireless_mode;		/* wireless_mode */
	u8					max_chan_nums;
	u8					user_tx_rate;			/* TXRATE when USERATE is set. */
	u8					retry;				/* record the number of retries for no bcn */
	u8					csa_channel;
	u8					g_recnt_times_internal;
	u8					h2c_last_num;
	u8					ampdu_density;
	u8					lps_cur_state; /* not in pspriv for rom */

	/*rejoin limit start*/
	u8					auth_retry_limit : 4;     /* retry limit of auth-open/shared key */
	u8					sae_auth_retry_limit : 4; /* retry limit of sae auth */
	u8					assoc_retry_limit : 4;    /* retry limit of assoc */
	u8					eapol_key_rsnd_limit : 4; /* retry limit of eapol key resnd for 4way/2way */
	/*rejoin limit end*/

	u8					b_join_abort : 1;
	u8					b_csa_ongoing : 1; //flag
	u8					b_assoc_by_bssid : 1;
	u8					b_scan_inprocess: 1;
	u8 					fix_edca_param;
	u8 					rom_rsvd[7];
	u8					b_set_key_inform_fw: 1;
	u8					b_csa_txpause: 1;
};

/* Mac Layer management entire for wifi information:
 * Manage the process and state of some common wifi events, like scan, join, auth and assoc.
 * The mlme info will be real-time updated by the current wifi environment.
 */
struct mlme_info {
	struct join_info			*sta_joininfo;
	struct pmksa_cache			*ppmksa; /* point to adapter->pmksa */
	struct net_device_stats		*padapter_stats;; /* point to adapter->adapter_stats */
	struct security_priv		*psecuritypriv; /* point to adapter->securitypriv */
	struct qos_priv				*pqospriv; /* point to adapter->qospriv */
	struct ht_priv				*phtpriv; /* point to adapter->htpriv */
	struct wlan_network			*pcur_network; /* point to adapter->cur_network */
	struct addba_request		*paddba_req; /* point to adapter->addba_req */

	struct rtw_custom_ie			*cus_ven_ie_arry;

	u8					*chg_txt;
	u32					state;
	u32					auth_seq;
	u32					fix_rate;
	int					total_sta_count_by_port; //port0 sta + bcmc + ap_sta_num

	u16					aid;
	u16					bcn_interval;
	u16					capability;

	u8					reassoc_count;
	u8					reauth_count;
	u8					slotTime;
	u8					fix_bcc_coding;
	u8					adapter_retry_limit;

	u8					dialogToken;
	u8					cur_channel;			/* current operating RF channel, different from the network channel, generally consistent */
	u8					cur_bwmode;
	u8					cur_ch_offset;			/* PRIME_CHNL_OFFSET */
	u8					driver_tx_bw_mode;

	u8					cus_ie_num;
	u8					b_accept_addba_req: 1;		/* Accept ADDBA Request */
	u8					b_wmm_enable : 1;
	u8					b_erp_protection : 1; //ERP_IE & BIT(1)
	u8					b_preamble_mode : 2; //_REG_PREAMBLE_MODE
	u8					b_fix_rts : 1;
	u32					rom_rsvd;

};

struct supplicant_sme_priv {
	struct rtw_sme_auth_info		*sme_auth;
	u16 					expect_trans;
	u8					prompt_sae_auth_confirm;

	u8					*assocreq_ies;
	u32 				assocreq_ie_len;
	u8					wpa_rsn_exist;

	u8					*deauth_ies;
	u32					deauth_ie_len;
	u16					deauth_reason_code;
	u8					b_deauth_from_wpas: 1;
};

struct cmd_priv {
	struct __queue					cmd_queue;
	u8					cmdthd_running;
};

struct	sta_priv {
	struct list_head  	sta_list;
	rtos_mutex_t		sta_list_mutex;

	u8					iface_type;
};

/* Struct not economical, may merge to other struct or spread later. */
struct qos_priv	{
	/* qos_option: fix addr for rtw_restructure_ht_ie in rom */
	u32					qos_option;			/* bit mask option: u-apsd, s-apsd, ts, block ack... */
//#ifdef CONFIG_WMMPS_STA
	u16 uapsd_tid;
	/* declare uapsd_ap_supported to record whether the connected ap  supports uapsd or not */
	/* uapsd (unscheduled automatic power-save delivery) = a kind of wmmps */
	u8 uapsd_max_sp_len;
	/* declare uapsd_tid as a bitmap for the uapsd setting of TID 0~15 */
	u8 uapsd_ap_supported;
//#endif /* CONFIG_WMMPS_STA */
};

struct tsf_info {
	u8					sync_port;			/*tsf sync from portx*/
	u8					offset;				/*tsf timer offset*/
};

struct macid_mgt_t {
	u8 macid_ap_start;
	u8 macid_ap_end;
#ifdef CONFIG_NAN
	u8 macid_nan_mgnt;
	u8 macid_nan_start;
	u8 macid_nan_end;

	u8 max_nan_schedule_num;
	u8 max_nan_peer_num;
#endif
	u8 macid_max_num;
};
/*-------------------------------------------------------------------------------
	padapter.
--------------------------------------------------------------------------------*/

struct share_adapter {
	struct task_struct			single_thread;
	struct task_struct			little_stack_thread;
#if defined (CONFIG_FW_DRIVER_COEXIST) && CONFIG_FW_DRIVER_COEXIST
	struct task_struct			driver_resumeThread;
#endif
#ifdef CONFIG_RTW_MBO
	struct mbo_non_pref_ch      mbo_non_pref; /* Set non-prefer channels. */
#endif
	struct macid_mgt_t          macid_mgt;
	struct sta_mlme_priv        **psta_mlmepriv_by_macid;//*psta_mlmepriv_by_macid[];

	u32 				work_mode;			/* STA, AP, NAN, P2P */
	u8					oper_channel;			/* saved channel info when call set_channel_bw */
	u8					b_disable_dm : 1;		/* disable dynamic mechanism */
	u8					b_rx_stop : 1;				/* Used to stop rx thread as early as possible. */
};

struct join_info {
	struct HT_caps_element	mlmeinfo_HT_caps;
	struct ht_info_element_t	mlmeinfo_HT_info;
#ifdef CONFIG_80211AX_HE
	struct HE_caps_element	mlmeinfo_HE_caps;
#endif
	u8	mlmeinfo_HE_op[HE_OP_ELE_MAX_LEN];
	u8	mlmeinfo_chg_txt[128];
	u8	supplicant_ie[MAX_WPA_IE_LEN];  //store sta security information element

};

struct ap_join_info {
	struct HT_caps_element	mlmeinfo_HT_caps;
	struct ht_info_element_t	mlmeinfo_HT_info;
};

struct _ADAPTER {
	struct mlme_info			mlmeinfo;			/* For Current scanning/connecting/connected related info. */
	struct sta_priv				stapriv;
	struct security_priv		securitypriv;
	struct qos_priv				qospriv;
	struct ht_priv				htpriv;
#ifdef CONFIG_OWE_SUPPORT
	struct owe_priv				owepriv;
#endif
#ifdef CONFIG_SUPPLICANT_SME
	struct supplicant_sme_priv	smepriv;
#endif
	struct wlan_network			cur_network;
	struct bcn_info_param		cur_network_bcninfo;
	struct dot11d_priv 			dot11dpriv;
	struct net_device_stats		adapter_stats;
	struct pmksa_cache			pmksa;
	struct addba_request		addba_req;
	struct hw_xmit				pending_queue;

	u8					iface_type;			/* IFACE_PORT0/IFACE_PORT1/IFACE_PORT2, extend to support multi interface. */
	u8					mac_addr[6];
	u8					b_driver_stopped : 1;		/* Used to represent wifi SW status. */
};

/*-------------------------------------------------------------------------------
	Member acquisition.
--------------------------------------------------------------------------------*/

/* Get elementes from padapter. */
#define rtw_get_stapriv(index)			(((g_padapter[index]) == NULL)? NULL : &((rtw_get_adapter(index))->stapriv))
#define rtw_get_pmlmeinfo(index)		(((g_padapter[index]) == NULL)? NULL : &((rtw_get_adapter(index))->mlmeinfo))
#define rtw_get_stats(index)			(((g_padapter[index]) == NULL)? NULL : &((rtw_get_adapter(index))->adapter_stats))

#ifdef CONFIG_MCC_MODE
#define rtw_get_mcc_adappriv(index)		(((g_padapter[index]) == NULL)? NULL : &((rtw_get_adapter(index))->mcc_adappriv))
#endif
#ifdef CONFIG_OWE_SUPPORT
#define rtw_get_owepriv(index)			(((g_padapter[index]) == NULL)? NULL : &((rtw_get_adapter(index))->owepriv))
#endif
#ifdef CONFIG_SUPPLICANT_SME
#define rtw_get_smepriv(index)			(((g_padapter[index]) == NULL)? NULL : &((rtw_get_adapter(index))->smepriv))
#endif


/* Get elements from pshare_adapter. */
#define rtw_get_adapter(index)			((index >= SUPPORT_ADAPTER_NUM)? NULL : g_padapter[index])
#define padaptersta						(g_padapter[STA_WLAN_INDEX])
#define padapterap						((SUPPORT_ADAPTER_NUM < 2)? NULL : g_padapter[SOFTAP_WLAN_INDEX])
#define padapternan						((SUPPORT_ADAPTER_NUM < 3)? NULL : g_padapter[NAN_WLAN_INDEX])
#define rtw_get_singlethread()			(&(shared_adapter.single_thread))
#define rtw_get_littlethread()			(&(shared_adapter.little_stack_thread))
#define rtw_get_channel_set_bitmaps()	(g_scanpriv.supported_channel_set_bitmaps)
#if defined (CONFIG_FW_DRIVER_COEXIST) && CONFIG_FW_DRIVER_COEXIST
#define rtw_get_driverresumethread()	(&(shared_adapter.driver_resumeThread))
#endif
#define rtw_get_csipriv()				(&hal_data.csipriv)
#define rtw_get_radarpriv()				(&hal_data.radarpriv)
#define rtw_wifi_hw_bup()				(hal_data.b_hw_up == TRUE)
#define rtw_get_workmode()				(shared_adapter.work_mode)

/* for phydm interface */
#define rtw_get_psta_mlmepriv(macidex)  (shared_adapter.psta_mlmepriv_by_macid[macidex])
#define rtw_get_psta_phyinfo(macidex)   ((struct phy_sta_info *)(shared_adapter.psta_mlmepriv_by_macid[macidex]->pphy_stainfo))
#define rtw_hal_band                    hal_data.band
#define rtw_hal_efuse_info              hal_data.efuse_info
#define rtw_halphy_shareinfo            hal_data.halphy_shareinfo
#define rtw_txpwr_usr_ctl               hal_data.txpwr_ctl_info
#define rtw_hal_antdivinfo              hal_data.antdivinfo
#define rtw_hal_diginfo                 hal_data.diginfo

/* Get special elements. */
#define rtw_netdev_priv(netdev)			(netdev_priv(netdev))
#define rltk_ap_compatibility_is_enable(a,b)	((a & b) ? 1 : 0)

#define _RTW_ADAPTER_DEFINED_H_

u8 rtw_get_adapter_stopped(u8 iface_type);
u8 *rtw_get_adapter_mac_addr(u8 iface_type);
u8 *rtw_get_adapter_bssid(u8 iface_type);
struct mlme_info *rtw_get_adapter_mlmeinfo(u8 iface_type);
struct bcn_info_param *rtw_get_adapter_bcninfo(u8 iface_type);
struct dot11d_priv *rtw_get_adapter_dot11dpriv(u8 iface_type);
struct addba_request *rtw_get_adapter_addba_req(u8 iface_type);
struct hw_xmit *rtw_get_pendingqueue(u8 iface_type);
struct wlan_network *rtw_network_zmalloc(struct wlan_network *network);
void rtw_network_free(struct wlan_network *target_network, u8 dynamic_network);
void rtw_network_copy(struct wlan_network *target_network, struct wlan_network *src_network, u8 with_ie);

extern struct _ADAPTER *g_padapter[];
extern struct _ADAPTER primary_adapter;
extern struct share_adapter shared_adapter;
extern struct recv_priv g_recvpriv;
extern struct xmit_priv g_xmitpriv;
extern struct scan_priv g_scanpriv;
extern struct pwrctrl_priv g_pspriv;
extern struct traffic_detect g_traffic_statis;
extern struct mlme_priv g_mlmepriv;
extern struct kvr_priv g_kvrpriv;
extern struct promisc_priv g_promiscpriv;
extern struct wps_priv g_wpspriv;
extern struct cmd_priv g_cmdpriv;
extern struct asoc_spec_t g_hal_spec;
extern struct sta_info *g_papstainfo;

extern struct ap_priv g_appriv;
extern struct ap_mlme_priv g_apmlmepriv;

#if defined(CONFIG_MP_INCLUDED)
extern struct mp_priv g_mppriv;
extern struct fastmp_priv g_fastmppriv;
#endif

#ifdef CONFIG_NAN
extern struct rtw_nan_priv g_nanpriv;
extern struct rtw_nan_de_priv g_nandisc_priv;
extern struct nan_srvc_ext_info g_srvc_ext_info;
extern struct nan_schdl_priv_t g_nanschdl_priv;
extern struct rtw_nan_data_engine_priv g_nandata_priv;
extern struct rtw_nan_ctrl_t g_nanctrl;
#endif
#ifdef CONFIG_P2P
extern struct p2p_priv  g_p2ppriv;
#endif
#ifdef CONFIG_MCC_MODE
extern struct mcc_priv g_mccpriv;
#endif
/*-------------------------------------------------------------------------------
	Function includes for related structures which will depend on padapter.
--------------------------------------------------------------------------------*/
#include "rtw_romfunc_parms.h"
#include <rtw_core_function.h>
#include <wifi_intf_drv_to_bt.h>
#include <os_wrapper.h>

#if defined(CONFIG_WHC_DEV)
#if !defined(CONFIG_WHC_INTF_IPC)
#include "whc_dev.h"
#else
#include "whc_ipc_dev_trx.h"
#include "whc_ipc.h"
#endif
#endif

#endif // __RTW_ADAPTER_H__
