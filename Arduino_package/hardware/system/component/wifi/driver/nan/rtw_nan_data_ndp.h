#ifndef __RTW_NAN_NDP_H_
#define __RTW_NAN_NDP_H_

struct ndp_entry_t {
	struct list_head list;

	struct ndp_attr_t ndp_attr;
	struct nan_wpa_ptk sec_ptk;//hash value of (PMK, "Token String", IAddr, RAddr, INounce, RNounce), would include KCK (16Bytes), KEK(16Bytes), TK(16Bytes)
	struct wpa_eapol_key *sec_rsna_key_desc;

	/* for info which is different between local and peer */
	struct ndp_specific_info local_devinfo_specinfo;
	struct ndp_specific_info peers_devinfo_specinfo;
	u8 local_devinfo_ipv6_info[MAX_IPV6_INFO_LEN];
	u8 peers_devinfo_ipv6_info[MAX_IPV6_INFO_LEN];

	u32 sec_m1_info_len;
	u8 *sec_m1_info_buf;
	u8 sec_replay_cnt[REPLAY_CNT_LEN];
	u8 sec_cipher_suite_cap;
	u8 sec_cipher_suite_id[NAN_CIPHER_SUITE_ID_MAX];
	u8 sec_i_nounce[MAX_KEY_NOUNCE_LEN];
	u8 sec_r_nounce[MAX_KEY_NOUNCE_LEN];
	u8 sec_pmk[MAX_PMK_LEN];
	u8 sec_pmkid[MAX_PMKID_LEN];//hash value of (PMK, "Token String", IAddr, RAddr, Service ID)
	u8 sec_auth_token[AUTH_TOKEN_LEN]; //derived from M1

	u8 peer_role;	/* refer to nan_ndp_role */
	u8 publish_id;
	u8 ndp_entry_status;		/* store NDP entry status*/
	u8 responder_ndi[ETH_ALEN];

	u8 ndp_entry_invalid : 1;
	u8 ndp_entry_conform_required : 1;
	u8 ndp_entry_sec_setup_required : 1;
	u8 ndp_entry_sec_present : 1;
	u8 ndp_entry_established : 1;
	u8 ndp_entry_gtk_required : 1;
};

struct ndp_entry_setup_info_t {
	u8 ndp_id;
	u8 publish_id;
	u8 ndp_state;		/* defined in table 73 in NAN spec v2.0.r4 */
	u8 ndp_type;		/* defined in table 73 in NAN spec v2.0.r4 */
	u8 ndp_rsp_mode;
	u8 reason_code;
	u8 confirm_required;
	u8 sec_required;
	u8 ipv6_info[MAX_IPV6_INFO_LEN];;		/* 8 octets long*/
	struct ndp_specific_info info;
	u8 *pw_subscribe;/*provided by subscriber(data req)to match the wanted service configuration*/
	u8  pw_subscribe_len;

	/* config info from customer cmd */
	u8 ndp_role; /* enum nan_ndp_role */
	u8 cipher_suite_id; /* nan_cipher_suite */
	u8 pmk[MAX_PMK_LEN];
	u8 pmkid[MAX_PMKID_LEN];
};

struct ndp_entry_end_info_t {
	u8 ndp_id;
	u8 dialog_token;
	u8 reason_code;
	u8 initiator_data_addr[ETH_ALEN];
	u8 peer_addr[ETH_ALEN];
};

/**
 * struct rtw_nan_data_engine_priv:
 * device bstrap capabilities; saved in struct rtw_nan_data_engine_priv
 * @comeback_enable: enable the comeback mech when recv the comeback req
 * @comeback_time: the value of comeback after field in bstrap comeback rsp
 * @bstrap_method: the supported bstrap method
 * @cookie_len: cookie for bstrap comeback rsp
 * @cookie: cookie for bstrap comeback rsp
 */

struct rtw_nan_data_engine_priv {
#ifdef CONFIG_NAN_PAIRING
	u8 comeback_enable;
	u16 comeback_time;
	u16 bstrap_method;
	u8 cookie_len;
	u8 *cookie;
	u8 pairing_setup_enable;
	u8 npk_nik_cache_enable;
	u8 pmkid[PMKID_LEN];
#endif
};

inline u8 *set_data_path_frame_subtype(u8 *pframe,  enum ndp_type_e ndp_type, u32 *frlen)
{
	u32 len = 1;
	if (ndp_type == NDP_TYPE_REQ) {
		*pframe = NAF_SUBTYPE_DATA_PATH_REQ;
	}
	if (ndp_type == NDP_TYPE_RSP) {
		*pframe = NAF_SUBTYPE_DATA_PATH_RSP;
	}
	if (ndp_type == NDP_TYPE_CONFIRM) {
		*pframe = NAF_SUBTYPE_DATA_PATH_CONFIRM;
	}
	if (ndp_type == NDP_TYPE_TERMINATE) {
		*pframe = NAF_SUBTYPE_DATA_PATH_TERMINATE;
	}
	if (ndp_type == NDP_TYPE_SEC_INSTALL) {
		*pframe = NAF_SUBTYPE_DATA_PATH_KEY_INSTALL;
	}
	*frlen += len;
	pframe += len;
	return pframe;
}

u8 rtw_nan_ndp_nego_state_change(struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry, enum nan_peer_ndp_nego_state new_state);
void rtw_nan_ndp_terminate_indicate(struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry);
void rtw_nan_ndp_nego_confirm_indicate(struct nan_peer_info_t *ppeer_info,	struct ndp_entry_t *pndp_entry);
u8 rtw_nan_ndp_send_cmd(struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry, u8 ndp_type, u8 ndp_status);
u8 rtw_nan_ndp_send_frame(struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry, u8 ndp_type, u8 ndp_status);
void rtw_nan_ndp_nego_rx(union recv_frame *precv_frame);
struct ndp_entry_t *rtw_nan_ndp_request_prehandle(struct nan_peer_info_t *ppeer_info, struct ndp_entry_setup_info_t *pndp_setup_info);
struct ndp_entry_t *rtw_nan_ndp_response_prehandle(struct nan_peer_info_t *ppeer_info, struct ndp_entry_setup_info_t *pndp_setup_info);
struct ndp_entry_t *rtw_nan_ndp_terminate_by_ndpid(struct nan_peer_info_t *ppeer_info, struct ndp_entry_setup_info_t *pndp_setup_info);
u8 rtw_nan_ndp_terminate_by_initndi(u8 *init_ndi, struct ndp_entry_setup_info_t *pndp_setup_info);
u8 rtw_nan_ndp_terminate_by_endinfo(struct ndp_entry_end_info_t *p_ndp_end_info);
u8 rtw_nan_ndp_response_send_cmd(struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry);
#endif /* __RTW_NAN_NDP_H_ */