#ifndef __RTW_NAN_H_
#define __RTW_NAN_H_

#include "rtw_nan_enum.h"

#if defined(CONFIG_AMEBASMART) || defined(CONFIG_AMEBADPLUS) || defined(CONFIG_AMEBALITE) || defined(CONFIG_AMEBAD) || defined(CONFIG_AMEBASMARTPLUS)
#define DISC_BCN_PORT	HW_PORT1
#else
#define DISC_BCN_PORT	HW_PORT2
#endif
#define NAN_PORT		IFACE_PORT2

#ifdef CONFIG_NAN

#include "rtw_nan_spec.h"
#ifdef NAN_CUSTOMER_NANDOW
#include <WFPAL.h>
#endif

/*********************************/
/**	Define Constants & Macros	**/
/*********************************/
extern u8 nan_network_id[];
extern u8 nan_cluster_id[];

extern unsigned char 	NAN_OUI_BCN[];
extern unsigned char 	NAN_OUI_SDF[];
extern unsigned char 	NAN_OUI_NAF[];
extern unsigned char 	WFA_OUI[];

#define NAN_SLOT                (16)
#define DW_INTERVAL             (512)	//unit: TU
#define DEFAULT_DW_SLOT_PERIOD  (DW_INTERVAL / NAN_SLOT) //32
#define DW0_INTERVAL            (8192)	//unit: TU
#define DW_5G_OFFSET            (128)	//unit: TU
#define DW_5G_OFFSET_SLOT_NUM   (DW_5G_OFFSET / NAN_SLOT) //8
#define DISC_BCN_INTVL          (100)
#define SYNC_BCN_INTVL          (512)
#define SW_DW_TIMER_OFFSET      (3*NAN_SLOT)
#define SW_DW_TIMER_DEVIATION   (10)

#define MAX_NDI_NUM                         (2)

#define MAX_SRVC_INSTANCE_TYPE              (3)
#define FIRST_SRVC_INSTANCE_ID              (1)
#define DEFAULT_NAN_24G_CH                  (6)
#define DEFAULT_NAN_5G_CH                   (149)
#define FW_TIME_INFO_INDICATION_PERIOD      (4)

#define SRVC_INST_QUEUE_NUM					(MAX_SRVC_INSTANCE_TYPE - 1)

#define NAN_ATTR_CONTENT_OFFSET             (3)

#define NAN_BCN_TYPE_SYNC	0
#define NAN_BCN_TYPE_DISC	1
#define AP_BCN_TYPE		    2
#define PORT0_BCN_TYPE		3	// only used in d2&dp STA+NAN concurrent mode

#define SDF_ATTR_START_OFFSET      (6)
#define NAF_ATTR_START_OFFSET      (7)
#define MAX_CHANNEL_SWITCH_TIME    (TU)

#define SCF_TYPE_PUBLISH	0x0
#define SCF_TYPE_SUBSCRIBE	0x1
#define SCF_TYPE_FOLLOWUP	0x2

#define MAX_NAN_SLOTS_LEN              (512)   			/* number of nan slots between consecutive DW0*/
#define MAX_NAN_FW_ACT_REQ_NUM         (8) 		/*Maximum amount of Act requests reserved for NAN operation*/
#define TOTAL_SLOTS_AMOUNT_IN_BYTE     (64)
#define DEFAULT_PREFER_FAW_24G_CH      (6)
#define DEFAULT_PREFER_FAW_5G_CH       (149)
#define NAN_MAX_AVAIL_TIME_BITMAP_LEN  64	//=(512*16TU) /(16TU*8)

/* Service response filter (SRF) control field */
#define BIT_SRF_CTRL_TYPE         BIT(0)
#define BIT_SRF_CTRL_INCLUDE      BIT(1)
#define SRF_CTRL_BFI_MASK         0xC
#define SRF_CTRL_BFI_SHIFT        (2)

/* NAN IE Element ID field 1 byte + Length filed 1 byte + Maximum Length 256
*/
#define MAX_NAN_IE_LEN            256+2
#define NAN_IE_FIXED_LEN          (6)
#define NAN_IE_ID_OFFSET          (0)
#define NAN_IE_LEN_OFFSET         (1)
#define NAN_IE_OUI_OFFSET         (2)
#define NAN_IE_OUI_TYPE_OFFSET    (5)
#define NAN_IE_ATTR_OFFSET        (6)

#define MAX_SDF_LEN		300

//#define NAN_SUPPORT_BW_80MHZ      1
/*****************************/
/**	Define Data Structure	**/
/*****************************/
struct nan_mac_addr_info {
	u8 mac[ETH_ALEN];	/* mac address of the device */
	u8 bssid[ETH_ALEN];	/* cluster id, default is randomly chosen */
};

struct nan_avail_t_bitmap {
	u16 start_offset_bit; /* unit: bits */
	u16 period_bit; /* unit: bits 1:128tu, 2:256tu,......, 7:8192tu */
	u8 bit_duration_tu; /* unit: tu 0:16tu, 1:32tu, 2:64tu, 3:128tu */
	u8 time_bitmap_len;
	u8 time_bitmap[NAN_MAX_AVAIL_TIME_BITMAP_LEN];
};

struct rtw_bcn_info {
	u8 bssid[6];
	u32 bcn_interval;
	u8 bcn_buf[MAX_IE_SZ];
	u32 bcn_length;
	u32 bcn_rate;
};

struct nan_qos_req {
	u8 min_duration;
	u16 max_latency;
	u8 type;
};

struct nan_peer_info_t {
	struct list_head list;
	struct sta_mlme_priv *psta_mlmepriv;

	struct __queue srvc_info_queue; /* list is composed of service information received from peer, struct nan_peer_srvcinfo_t */
	struct __queue ndp_queue;	/* list of struct ndp_entry_t */
	struct __queue schdl_entity_queue;			/* list of struct nan_schdl_entity_t */

	struct ndp_entry_t *pndp_entry_negoing;	/* ndp entry negoing now */
	struct wpa_crypt *gtk;
	struct wpa_crypt *igtk;
	struct wpa_crypt *bigtk;

	/* committed_dw_info extract from Device Cap Attribute */
	u16 cmt_dw_24g : 3;
	u16 cmt_dw_5g : 3;
	u16 cmt_dw_overwrite_24g : 4;
	u16 cmt_dw_overwrite_5g : 4;
	u16 cmt_dw_reserved : 2;
	u8 cmt_dw_apply_to_all_map;

	u8 peer_info_nmi[ETH_ALEN]; /* Peer's NMI for data link setup & protocol handshakes */
	u8 nmi_mac_id;

	/* peer ndl info */
	struct dev_cap_t devcap_attr; /* preserve device capability attribute with MAP ID = 8b'0*/
	struct ndl_attr_t peer_ndl_attr;
	struct ndc_attr_t peer_ndc_attr;
	struct qos_attr_t peer_ndl_qos_attr;
	u8 peer_ndl_seq_id;
	u8 peer_ndl_state; /* enum ndl_nego_state */
	u8 peer_ndl_mac_id;								/* MAC ID for controling data frame transmissions over NDL */
	u8 peer_ndl_bitmap[TOTAL_SLOTS_AMOUNT_IN_BYTE]; /* records for current booked committed schedule*/

	u32 peer_info_ndl_establish : 1;
	u32 peer_info_ndl_immutable_present : 1;
	u32 peer_info_ndl_qos_present : 1;
	u32 peer_info_ndl_nego_need_look_potential : 1;
	u32 peer_info_ndl_ndc_schdl_present : 1;
	u32 peer_info_ndl_recv_nego_conter : 1;
	u32 peer_info_ndl_nego_counter : 1;
	u32 peer_info_ndl_nego_start : 1;
	u32 peer_info_ndl_setup_with_ndp : 1;
	u32 peer_info_ndl_renego : 1;
	u32 peer_info_schdl_invalid : 1;
	u32 peer_info_schdl_updating : 1;
	u32 peer_info_schdl_update_notify : 1;
	u32 peer_info_schdl_update_nego : 1;
	u32 peer_info_pmf_required : 1;
	u32 peer_info_gtk_required : 1;

	u8 reason_code; /* used when rejecting schedule */
	u8 ndp_id_pool;

#ifdef CONFIG_NAN_PAIRING
	struct wpa_eapol_key *nmi_eapol_key; /* For peer NMI */
	struct nan_wpa_ptk pasn_nm_ptk;
	struct timer_list bstrap_comeback_timer; // the timer for bstrap comeback req timer
	struct nan_srvc_inst_t *psrvc_inst_bstrap; //the corresponding self srvc

	u32 pair_ident_key_lifetime;
	u16 pair_ident_key_lifetime_bitmap; /* enum nan_key_lifetime_bitmap */
	u8 pair_ident_pmkid_valid : 1;
	u8 pair_ident_nik[WPA_NIK_LEN];
	u8 pair_ident_nonce[WPA_NIRA_NONCE_LEN];
	u8 pair_ident_tag[WPA_NIRA_TAG_LEN];
	u8 pair_ident_pmk_id[MAX_PMKID_LEN];

	char pasn_password[MAX_PASN_PW_LEN]; /* using in pasn process */
	u8 pasn_phase;
	u8 pasn_password_len;
	u8 pasn_type;         /* enum nan_pairing_type */
	u8 pasn_auth_method;  /* enum nan_pairing_auth */
	u8 pasn_nik_cache_enable;
	u8 pasn_append_nanie[MAX_PASN_NAN_APPEND_IE_LEN];
	u8 pasn_append_nanie_len;

	u8 bstrap_phase; /* enum nan_bstrap_phase */
	u8 bstrap_cur_dialog_token; //the latest (recv/sent) token number for the corresponding peer

	/* the following member is for comeback req info: */
	u16 bstrap_req_method; //the request bstrap method
	u8 bstrap_peer_inst_id; //req inst id in bstrap comeback req
	u8 bstrap_peer_cookie_len; //the cookie length from bstrap comeback rsp
	u8 *bstrap_peer_cookie; //the cookie from bstrao comeback rsp
	u8 pairing_role; /* record own role for this peer: enum nan_pairing_rol */
	u8 peer_dcea_len;
	struct devcap_eattr_t peer_dcea;
#endif /* CONFIG_NAN_PAIRING */
};

struct rtw_nan_mgnt_send_entry {
	struct list_head list;
	struct sk_buff		*skb;
	struct nan_peer_info_t *ppeer_info;
};

struct rtw_nan_priv {
	struct nan_mac_addr_info nmi; /* settings for NAN Management Interface */
	struct nan_mac_addr_info ndi[MAX_NDI_NUM];
	struct nan_avail_t_bitmap avail_t_bitmap; /* NAN Beacon */
	struct rtw_bcn_info nan_sync_bcn; /* NAN Beacon */
	struct rtw_bcn_info nan_disc_bcn; /* NAN Beacon */
	struct wpa_crypt *gtk;
	struct wpa_crypt *igtk;
	struct wpa_crypt *bigtk;

	union pn48		dot11wBIPtxpn;			/* PN48 used for BIP beacon xmit. */

#ifdef CONFIG_NAN_PAIRING
	struct wpa_eapol_key *nmi_eapol_key; /* For NMI */
	u32 pair_ident_key_lifetime;
	u16 pair_ident_key_lifetime_bitmap; /* enum nan_key_lifetime_bitmap */
	u8 pair_ident_nik[WPA_NIK_LEN];
	u8 pair_ident_nonce[WPA_NIRA_NONCE_LEN];
	u8 pair_ident_tag[WPA_NIRA_TAG_LEN];
	u8 pair_ident_pmk_id[MAX_PMKID_LEN];
#endif

	struct timer_list dw_timer;
	struct timer_list getip_timer;

	struct __queue peerinfo_list;	/* list of struct nan_peer_info_t */
	struct __queue mgnt_frame_queue;	/* list of struct rtw_nan_mgnt_send_entry */

	u16 mac_id_bitmap;	/* biti=1 represent macid (MACID_NAN_START + i) is used,  */
	u8 cmd_type;	/* refer to nan_cmd_type */

	u16 committed_dw_peiod_24G; /* unit: NAN_SLOT (16tu) */
	u16 committed_dw_peiod_5G; /* unit: NAN_SLOT (16tu) */

	u8 master_pref;
	u8 master_random_factor;	//range: [0, 255]

	/* group_key_flags */
	u8 nan_gtk_tx_install : 1;
	u8 nan_gtk_rx_get : 1;
	u8 nan_igtk_tx_install : 1;
	u8 nan_igtk_rx_get : 1;
	u8 nan_bigtk_tx_install : 1;
	u8 nan_bigtk_rx_get : 1;

	u8 disc_bcn_intvl_ms; /* NAN Beacon */
	u8 ndi_available_cnt; 				/* set to MAX_NDI_NUM by default*/
	u8 nmi_mac_id; /* MAC ID for NMI Transmission */
	u8 cluster_id[ETH_ALEN];
	u8 dual_band_support;
	u8 op_ch_24g;
	u8 op_ch_5g;
	u8 b_dis_24g_disc_bcn;
	u8 b_dis_5g_disc_bcn;

	u8 nan_priv_flag_init : 1;
	u8 nan_priv_flag_start : 1;
	u8 nan_priv_flag_new_cluster_joined : 1;
	u8 nan_priv_allow_join_new_cluster : 1;
};

struct nan_srvc_ext_info {
	u8 updating;
	/* indicate when cmd srv_ext_info is called and
	 * these info need to update to the adding service in rtw_add_nan_func_xxx
	 */
	u8 period; /* (pub/sub) announcement_period for publish or query_period for subscribe */
	u8 event_condition; /* (pub) determine when publish related events are generated; nan_publish_event_condition_flags */
	u8 proximity_flag; /* (pub/sub)  discovery range; not implement */
	u8 awake_dw_int; /* (pub/sub)  Interval between two DWs during which the device supporting the service is awake to transmit or receive */
	u8 further_srvc_disc; /* (pub) more frames will come with this service */
	u8 further_srvc_disc_func; /* (pub) 0: followup, 1 : GAS */
	u8 data_path_flag; /* (pub) NDP setup is required */
	u8 data_path_type; /* (pub) 0: unicast */
	u8 qos; /* (pub) qos required */
	u8 sec; /* (pub) sec required */

	/*
	*	pmk_publish and pmkid_publish only use for publish
	*	and these two parameters follow specific service.
	*	pmkid_publish is calculated form pmk_publish and broadcast
	*	mac addr,and used in solicted/unsolicated publish SDF
	*/
	u8 passphrase[MAX_PASSPHRASE_LEN + 1]; /* (pub) use to extend to pmk if set */
	u8 passphrase_len;
	u8 pmk_publish[MAX_PMK_LEN];
	u8 pmkid_publish[MAX_PMKID_LEN];
	u8 gtk_protection;

	/*
	 * Unicast: data_path_type = 0 qos = 1
	 * Multicast: data_path_type = 1 qos = 1
	 */
	struct nan_qos_req qos_req;
	/* range_config_param not support yet */

	u8 service_id[SDA_SERVICE_ID_LEN]; /* (pub/sub) overwrite service info feild */
	u8 srvc_info[NAN_MAX_SERVICE_INFO_LEN];
	u16 srvc_info_len;
	u16 csid; /* represent in bitwise */
#ifdef CONFIG_NAN_PAIRING
	u8 pairing_setup_enable;
	u8 npk_nik_cache_enable;
	u16 bstrap_method;
#endif
};

struct rtw_nan_de_priv {
	struct __queue srvc_inst_queue[SRVC_INST_QUEUE_NUM]; /* list is composed of service instances with certain type, without followup servie */
	/*Do not change orders of declarations above, put additional members below*/
	u32 srvc_num;
	u32 instant_id;
	u8 min_awake_dw_intvl; /* minimal interval within all existing NAN services */
};

struct ndp_specific_info {
	u8 *pbuf;
	u32 len;
};

struct nan_peer_srvcinfo_t {
	struct list_head list;
	struct nan_srvc_inst_t *p_assoc_srvc_inst; /* reference pointer to associated srvc_instance_entry*/

	struct srvc_ctrl_t srvc_ctrl;
	struct sdea_ctrl_t sdea_ctrl; // Service Descriptor Extension Attribute

	u16 gen_srvcinfo_trans_port; //Generic Service Protocol in SDEA/NDPE
	u8 gen_srvcinfo_trans_protocol;

	u8 *pspec_srvcinfo_buf;
	u32 spec_srvcinfo_len;

	u8 peer_service_id[SDA_SERVICE_ID_LEN]; // Service Descriptor Attribute
	u8 peer_inst_id;

	u8 peer_srvcinfo_flag_valid : 1;
};

struct nan_service_info {
	/*
	 * service info can be conatined in SDA/SDEA/NDP/NDPE
	 * If the content start with 0x50-6F-9A (Wi-Fi Alliance specific OUI),
	 * the format of service info is defineded in spec
	 */
	u8 *info; //[MAX_SDA_SRVC_INFO_LEN];
	u16 len;
};

struct nan_instparam_t {
	struct sdea_ctrl_t sde_control_4nadow;
	u8 *pservice_id;
	u8 instance_id4nadow;
	u8 inst_period_4nadow;
	u8 awake_dw_int_4nadow;
	u8 alloc_4nadow : 1;
};

struct nan_srvc_inst_t {
	struct list_head list;

	void *p_srv_data; /* ppub_info/psub_info/pflow_info */

	struct ndp_specific_info ndp_auto_rsp_info;
	struct nan_service_info service_specific_info;
	struct sdea_ctrl_t sde_control; /* just for pub/sub */
	struct srvc_ctrl_t service_control;

	u16 csid_list;

	u64 instance_cookie; // unique NAN function identifier; implement aspect
	u8 instance_id; // == /* ppub_info/psub_info/pflow_info instance_id */
	u8 inst_service_id[SDA_SERVICE_ID_LEN]; /* common service id and config for pub/sub */

	struct rtw_nan_func_filter *subpub_rx_filters;//[MAX_MATCHING_FILTERS];
	struct rtw_nan_func_filter *subpub_tx_filters;//[MAX_MATCHING_FILTERS];
	u8 subpub_num_tx_filters;
	u8 subpub_num_rx_filters;
	u8 subpub_inst_period; /* just for pub/sub */
	u8 subpub_awake_dw_int; /* just for pub/sub */ /* unit: discovery windows */

	/* service response filter */
	struct rtw_mac *sub_srf_macs; /* ptr of mac addr * srf_num_macs */
	int sub_srf_num_macs;
	u8 sub_srf_bf_len;
	u8 sub_srf_bf_idx;
	u8 *sub_srf_bf;

	u8 ndp_rsp_mode;
	u8 ndp_auto_rsp_publish_id;
	u8 ndp_auto_rsp_ndp_state;

	u8 binst_in_list : 1;
	u8 sub_srf_include : 1;
	u8 sub_active : 1; //just for sub
	u8 pub_inst_type : 2;	// bitmap : unsolicited(bit1) | solicited(bit0)
	u8 pub_solicited_bcast : 1; /* if service need to send bcast SDF on solicited publish */
	u8 pub_solicited_tx_type : 2; /* nan_publish_solicited_tx_type */

	u64 os_dep_data; /* such as struct cfg80211_nan_func in linux */
};

struct rtw_nan_event_parm {
	u32 event_type;
	u32 length;
	u8	data[0];
};

struct nan_rmv_nmi_sta_info_cmd {
	u8 nmi[ETH_ALEN];
	u8 mac_id;
};

/*----------------------h2c-------------------*/

enum _bcn_req_option {
	BCN_REQ_OPT_REMOVE = BIT0,
	BCN_REQ_OPT_UPDATE = BIT1
};

enum _act_schdl_req_option {
	ACT_REQ_OPT_REMOVE = BIT0,
	ACT_REQ_OPT_UPDATE = BIT1
};

enum _nan_func_ctrl_option {
	NAN_CTRL_OPT_ENABLE = BIT0,
	NAN_CTRL_OPT_DUAL_BAND = BIT2,
	NAN_CTRL_OPT_DISABLE_DISC_BCN_24G = BIT3,
	NAN_CTRL_OPT_DISABLE_DISC_BCN_5G = BIT4,
	NAN_CTRL_OPT_UPDATE_PARAMETER = BIT7,
	NAN_CTRL_OPT_PROFILE_MODE_ENABLE = BIT8
};
/*refer to struct halmac_nan_func_ctrl*/
enum _nan_func_ctrl_update_para_option {
	NAN_CTRL_UPDATE_PORT_IDX = BIT0,
	NAN_CTRL_UPDATE_MAC_ID = BIT1,
	NAN_CTRL_UPDATE_MASTER_PREF = BIT2,
	NAN_CTRL_UPDATE_RANDOM_FACTOR = BIT3,
	NAN_CTRL_UPDATE_OP_CH_24G = BIT4,
	NAN_CTRL_UPDATE_OP_CH_5G = BIT5,
	NAN_CTRL_UPDATE_TIME_INDICATE_PERIOD = BIT6,
	NAN_CTRL_UPDATE_NAN_CLUSTER_ID = BIT7
};

enum nan_dev_role_e {
	NAN_ROLE_NONE,
	NAN_ROLE_DEVICE,
	NAN_ROLE_MASTER,
	NAN_ROLE_ANCHOR_MASTER,
	NAN_ROLE_NONMASTER_SYNC,
	NAN_ROLE_NONMASTER_NONSYNC
};

struct nanctrl_para_t {
	u8 port_idx;
	u8 mac_id;
	u8 master_pref;
	u8 random_factor;
	u8 op_ch_24g;
	u8 op_ch_5g;
	u16 options;
	u8 time_indicate_period;
	u8 nan_cluster_id[ETH_ALEN];
	/* need HALMAC_NAN_CTRL_OPT_UPDATE_PARAMETER in options.
	   refer to halmac_nan_func_ctrl_update_para_option. */
	u16 para_options;
};

struct anchor_mast_record_t {
	u64	amr_amr;
	u32	amr_ambtt;
	u8	amr_hopcount;
};

struct mast_rankinfo_t {
	u8      MasterPref;
	u8      RandomFactor;
	u8      rank_interface_addr[6];
};

struct nan_rx_bcninfo_t {
	struct anchor_mast_record_t ClusterAttr;
	struct mast_rankinfo_t master_rankinfo;
	u8 BcnType;
	u64 TSF;
	u16 BeaconInterval;
	u8 Channel;
	u8 clusterid[ETH_ALEN];
};

#define NAN_MAX_H2C_AVAIL_TIME_BITMAP_LEN 16 /* constrained by H2C cmd size */

enum _nan_avail_t_bitmap_module_id {
	NAN_AVAIL_T_BITMAP_MODULE_ID_NONE = 0x0,
	NAN_AVAIL_T_BITMAP_MODULE_ID_DISC_BCN,
	/*HALMAC_NAN_AVAIL_T_BITMAP_MODULE_ID_FAW,*/
	NAN_AVAIL_T_BITMAP_MODULE_ID_MAX
};
enum _nan_avail_t_bitmap_option {
	NAN_AVAIL_T_BITMAP_OPT_REMOVE = BIT0
};

struct rtw_nan_avail_t_bitmap {
	u8 module_id; /* ref: _nan_avail_t_bitmap_module_id */
	u8 option; /* ref: _nan_avail_t_bitmap_option */
	u16 start_offset_bit; /* unit: bits */
	u16 period_bit; /* unit: bits */
	u8 bit_duration_tu; /* unit: tu */
	u8 time_bitmap_len;
	u8 time_bitmap[NAN_MAX_H2C_AVAIL_TIME_BITMAP_LEN];
};

#include "rtw_nan_scheduler.h"
#include "rtw_nan_role.h"
#include "rtw_nan_dw.h"
#include "rtw_nan_attr.h"
#include "rtw_nan_bcn.h"
#include "rtw_nan_peer.h"
#include "rtw_nan_cluster.h"
#include "rtw_nan_security.h"
#include "rtw_nan_ch.h"
#include "rtw_nan_action_frame.h"
#include "rtw_nan_event.h"
#include "rtw_nan_disc_engine.h"
#include "rtw_nan_data_ndp_api.h"
#include "rtw_nan_data_ndp.h"
#include "rtw_nan_data_ndi.h"
#include "rtw_nan_data_pairing.h"
#include "rtw_nan_data_ndl.h"
#include "rtw_nan_eapol.h"
#include "rtw_nan_eapolkey.h"
#include "rtw_nan_data_entry.h"
#include "rtw_nan_vendor_api.h"
#include "rtw_nan_vendor_api_nandow.h"
#include "rtw_nan_stainfo.h"

/**
 * is_counter_proposal_needed - evaluate if counter proposal is needed
 */
inline u8 is_counter_proposal_needed(struct nan_peer_info_t *ppeer_info)
{
	return (!(ppeer_info->peer_info_schdl_invalid)
			&& (ppeer_info->peer_info_ndl_nego_counter)) ? (TRUE) : (FALSE);
}

#ifdef NAN_DBG
inline void RTW_PRINT_DUMP(char *_titlestring, const u8 *_hexdata, int _hexdatalen)
{
	int __i;
	u8 *ptr = (u8 *)_hexdata;

	if (_titlestring) {
		RTK_LOGA(NOTAG, "%s len=%d\n", _titlestring, _hexdatalen);
	}

	for (__i = 0; __i < _hexdatalen; __i++) {
		if (((__i % 16) == 0) && (_hexdatalen >= 16)) {
			RTK_LOGA(NOTAG, " ");
		}
		RTK_LOGA(NOTAG, "%02X%s", ptr[__i], (((__i + 1) % 4) == 0) ? "  " : " ");
		if ((__i + 1 < _hexdatalen) && ((__i + 1) % 16) == 0) {
			RTK_LOGA(NOTAG, "\n");
		}
	}
	RTK_LOGA(NOTAG, "\n");
}
#else
#define RTW_PRINT_DUMP(_titlestring, _hexdata, _hexdatalen)
#endif

void rtw_nan_stop_api(void);
void rtw_nan_start(u8 mp, u8 band_support, u8 nan_cmd_type);
u8 rtw_nan_ctrl_para_update(u16 update_options);
u8 rtw_nan_avail_t_bitmap_update(u8 module_id, u8 op);
u8 rtw_nan_master_pref_update(u8 master_pref);
u8 rtw_nan_random_factor_update(u8 random_factor);
u8 rtw_nan_ctrl_para_issue(u8 enable);

u8 rtw_nan_random_num_generate(u8 *num, u8 key_len);
u8 rtw_nan_nir_tag_generate(u8 *nik, u8 *nmi, u8 *nonce, u8 *tag, u8 tag_len);
void rtw_nan_key_nonce_generate(u8 *buf, u32 len);
u8 rtw_nan_pmkid_get(u8 *pmk, size_t pmk_len, u8 *iaddr, u8 *raddr, u8 *service_id, u8 *pmkid);
int rtw_nan_kdk_to_kek(u16 cipher_suite, u8 *initiator_nmi, u8 *responder_nmi, struct nan_wpa_ptk *ptk);
int rtw_nan_kdk_to_pmk(u16 cipher_suite, u8 *initiator_nmi, u8 *responder_nmi, struct nan_wpa_ptk *ptk, u8 *nd_pmk);
u8 rtw_nan_pairwise_key_set(struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry, u8 *peer_addr);
u8 rtw_nan_pairwise_key_clear(u8 *peer_ndi);
u8 rtw_nan_group_key_set(struct nan_peer_info_t *ppeer_info, enum nan_gtk_crypt_type crypt_type, u8 set_tx, u8 *addr);
u8 rtw_nan_group_keys_init(void);
u8 rtw_nan_group_keys_free(void);
u8 rtw_nan_group_keys_free_for_peer(struct nan_peer_info_t *ppeer_info);
u8 *rtw_nan_key_data_decrypt(u8 *kek, u8 key_len, struct wpa_eapol_key *eapol_key, u16 *len);
u8 nan_rsn_key_data_parsing(struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry, u8 *keydata_start, u16 keydatalen);
u8 rtw_nan_pairwise_key_get(struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry, u8 *peer_ndi);
void rtw_nan_nd_pmk_get(struct nan_peer_info_t *ppeer_info, u8 *nd_pmk);
int rtw_nan_password_to_pmk(u8 *password, size_t password_len, u8 cipher_suite_id, u8 *service_id, u8 *publish_nmi, u8 *nd_pmk);


void rtw_nan_disc_priv_init(void);
void rtw_nan_disc_priv_free(void);
void rtw_nan_disc_set_default_ipv6(u8 *target);
void rtw_nan_srvc_dump(struct nan_srvc_inst_t *psrvc_inst);
void rtw_nan_update_txdesc(struct xmit_frame *pxmitframe, u8 *pmem);

void rtw_nan_sdf_rx(union recv_frame *precv_frame);
void rtw_nan_sdf_tx_in_DW(u32 dw_idx, u8 is_5g);
struct nan_srvc_inst_t *rtw_nan_srvc_publish_inst_get_and_update(u8 publish_id, struct nan_service_info *service_specific_info);
void rtw_nan_sdf_solicited_publish_bcast_time_set(u8 publish_id, u16 time);
void _rtw_nan_sdf_reply_tx(struct nan_peer_info_t *ppeer_info, struct nan_srvc_inst_t *psrvc_inst, u8 *peer_addr, u8 requestor_inst_id, u16 binding_bitmap);

int rtw_nan_bcn_mme_append(u8 *pframe, u32 pktlen);
int rtw_nan_bcn_bip_verify(u8 *pframe, u32 pkt_len, u8 encrypt);
#endif
#endif