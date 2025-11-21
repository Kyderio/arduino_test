#ifndef _RTW_NAN_EVENT_H_
#define _RTW_NAN_EVENT_H_

struct nan_sdf_param_t {
	struct nan_peer_info_t *ppeer_info;
	struct nan_srvc_inst_t *psrvc_inst;
	u8 requestor_inst_id; //inst id get form SDF request, should send in SDF reply packet
};

struct nan_schdlr_ndp_nego_cmd {
	struct nan_peer_info_t *ppeer_info;
	struct ndp_entry_t *pndp_entry;
	u8 ndp_type;	/* refer to enum ndp_type_e */
	u8 ndp_status; /* refer to enum nan_peer_ndl_or_ndp_status */
};


struct nan_alloc_peer_sta_info_cmd {
	struct nan_peer_info_t *ppeer_info;
	u8 peer_ndi[ETH_ALEN];
};

struct nan_accept_ndp_cmd {
	struct nan_peer_info_t *ppeer_info;
	struct ndp_entry_t *pndp_entry;
	u8 peer_ndi[ETH_ALEN];
};

struct nan_event_data_comfirm {
	u8 type; 	/* 0 = ucast */
	u8 status;
	u8 ndp_id;	/* ucast */
	u8 mc_id;	/* mcast */
	u8 nmsg_id; /* mcast */
	u8 initiator_data_address[ETH_ALEN];	/* ucast */
	u8 responder_data_address[ETH_ALEN];	/* ucast */
	u8 srvc_info[MAX_SDA_SRVC_INFO_LEN];
	u8 srvc_info_len;
};

struct nan_event_data_termination {
	u8 type;	/* 0 = ucast */
	u8 status;
	u8 ndp_id;	/* ucast */
	u8 mc_id;	/* mcast */
	u8 nmsg_id;	/* mcast */
	u8 initiator_data_address[ETH_ALEN];	/* ucast */
};
struct nan_event_data_indication {
	u8 type;		/* 0 = ucast */
	u8 publish_id;
	u8 ndp_id;	/* ucast */
	u8 mc_id;	/* mcast */
	u8 initiator_data_address[ETH_ALEN];	/* ucast */
	u8 responder_data_address[ETH_ALEN];	/* ucast */
	u8 security;
	u8 ipv6_interfac_id[MAX_IPV6_INFO_LEN];
	u8 srvc_info[MAX_SDA_SRVC_INFO_LEN];
	u8 srvc_info_len;
};

u8 rtw_nan_event_enqueue(enum rtw_nan_event_type type, void *pbuf, u32 len);

void rtw_nan_ndp_nego_confirm_accept_event(struct rtw_nan_event_parm *p_parm);
void rtw_nan_sdf_reply_event(struct rtw_nan_event_parm *p_parm);
void rtw_nan_ndp_send_frame_event(struct rtw_nan_event_parm *p_parm);
void rtw_nan_ndp_empty_event(struct rtw_nan_event_parm *p_parm);
void rtw_nan_schdlr_new_schedule_reject_event(struct rtw_nan_event_parm *p_parm);
void rtw_nan_ndl_reply_accept_event(struct rtw_nan_event_parm *p_parm);
#endif /* _RTW_NAN_EVENT_H_ */