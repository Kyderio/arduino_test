#ifndef __RTW_RM_H_
#define __RTW_RM_H_

#define RM_TIMER_NUM 		32
#define RM_ALL_MEAS		BIT(1)
#define RM_ID_FOR_ALL(aid)	((aid<<16)|RM_ALL_MEAS)
/* Keep this value small to put maximum 3 APs inside the ESS. */
#define MAX_BEACON_REPORT	3

#define RTW_RRM_DEBUG		0
#define RTW_RRM_DEBUG_DUMP	0

#define MIN_MEAS_RPT_ELEM_LEN_FOR_BCN	29

#define RM_REQ_TIMEOUT		10000	/* 10 seconds */
#define RM_MEAS_TIMEOUT		10000	/* 10 seconds */
#define RM_REPT_SCAN_INTVL	5000	/*  5 seconds */
#define RM_BUSY_TRAFFIC_TIMES	10
#define RM_WAIT_BUSY_TIMEOUT	1000	/*  1 seconds */

#define MEAS_REP_MOD_INCAP	BIT(1)
#define MEAS_REP_MOD_REFUSE	BIT(2)

#define RM_MASTER		BIT(0)	/* STA who issue meas_req */
#define RM_SLAVE		0	/* STA who do measurement */

#define CLOCK_UNIT		10	/* ms */

#define	MAX_OP_CHANNEL_SET_NUM	15
#define BCN_REQ_OPT_MAX_NUM		16

#define RM_GET_AID(rmid)	((rmid&0xffff0000)>>16)
#define RM_IS_ID_FOR_ALL(rmid)	(rmid&RM_ALL_MEAS)

/* IEEE 802.11-2012 Table 8-59 Measurement Type definitions
*  for measurement request
*  modify rm_meas_type_req_name() when adding new type
*/
enum meas_type_of_req {
	BASIC_REQ = 0,	/* spectrum measurement */
	CCA_REQ = 1,
	RPI_HISTO_REQ = 2,
	CH_LOAD_REQ = 3,
	NOISE_HISTO_REQ = 4,
	BCN_REQ = 5,
	FRAME_REQ = 6,
	STA_STATIS_REQ = 7,
};

/*
* Beacon request
*/
/* IEEE 802.11-2012 Table 8-64 Measurement mode for Beacon Request element */
enum bcn_req_meas_mode {
	BCN_REQ_PASSIVE = 0,
	BCN_REQ_ACTIVE = 1,
	BCN_REQ_BCN_TABLE = 2
};

/* IEEE 802.11-2012 Table 8-65 optional subelement IDs for Beacon Request */
enum bcn_req_opt_sub_id {
	BCN_REQ_SSID = 0,		/* len 0-32 */
	BCN_REQ_BCN_RPTING = 1,		/* len 2 */
	BCN_REQ_RPT_DETAIL = 2,		/* len 1 */
	BCN_REQ_REQ = 10,		/* len 0-237 */
	BCN_REQ_AP_CH_RPT = 51		/* len 1-237 */
};

/* 802.11-2012 Table 8-206 Radio Measurment Action field */
enum rm_action_code {
	RM_ACT_RADIO_MEAS_REQ = 0,
	RM_ACT_RADIO_MEAS_RPT = 1,
	RM_ACT_LINK_MEAS_REQ = 2,
	RM_ACT_LINK_MEAS_REP = 3,
	RM_ACT_NB_RPT_REQ = 4,	/* 4 */
	RM_ACT_NB_RPT_RESP = 5,
};

/* 802.11-2012 Table 8-119 RM Enabled Capabilities definition */
enum rm_cap_en {
	RM_LINK_MEAS_CAP_EN,
	RM_NB_RPT_CAP_EN,		/* neighbor report */
	RM_PARAL_MEAS_CAP_EN,		/* parallel report */
	RM_REPEAT_MEAS_CAP_EN,
	RM_BCN_PASSIVE_MEAS_CAP_EN,
	RM_BCN_ACTIVE_MEAS_CAP_EN,
	RM_BCN_TABLE_MEAS_CAP_EN,
	RM_BCN_MEAS_REP_COND_CAP_EN,	/* conditions */

	RM_FRAME_MEAS_CAP_EN,
	RM_CH_LOAD_CAP_EN,
	RM_NOISE_HISTO_CAP_EN,		/* noise historgram */
	RM_STATIS_MEAS_CAP_EN,		/* statistics */
	RM_LCI_MEAS_CAP_EN,		/* 12 */
	RM_LCI_AMIMUTH_CAP_EN,
	RM_TRANS_STREAM_CAT_MEAS_CAP_EN,
	RM_TRIG_TRANS_STREAM_CAT_MEAS_CAP_EN,

	RM_AP_CH_REP_CAP_EN,
	RM_RM_MIB_CAP_EN,
	RM_OP_CH_MAX_MEAS_DUR0,		/* 18-20 */
	RM_OP_CH_MAX_MEAS_DUR1,
	RM_OP_CH_MAX_MEAS_DUR2,
	RM_NONOP_CH_MAX_MEAS_DUR0,	/* 21-23 */
	RM_NONOP_CH_MAX_MEAS_DUR1,
	RM_NONOP_CH_MAX_MEAS_DUR2,

	RM_MEAS_PILOT_CAP0,		/* 24-26 */
	RM_MEAS_PILOT_CAP1,
	RM_MEAS_PILOT_CAP2,
	RM_MEAS_PILOT_TRANS_INFO_CAP_EN,
	RM_NB_REP_TSF_OFFSET_CAP_EN,
	RM_RCPI_MEAS_CAP_EN,		/* 29 */
	RM_RSNI_MEAS_CAP_EN,
	RM_BSS_AVG_ACCESS_DELAY_CAP_EN,

	RM_AVALB_ADMIS_CAPACITY_CAP_EN,
	RM_ANT_CAP_EN,
	RM_RSVD,			/* 34-39 */
	RM_MAX
};

/*
* State machine
*/
enum RRM_STATE {
	RRM_ST_IDLE,
	RRM_ST_DO_MEAS,
	RRM_ST_WAIT_MEAS,
	RRM_ST_SEND_REPORT,
	RRM_ST_RECV_REPORT,
	RRM_ST_END,
};

/* remember to modify rm_event_name() when adding new event */
enum RRM_EV_ID {
	RRM_EV_state_in,
	RRM_EV_busy_timer_expire,
	RRM_EV_delay_timer_expire,
	RRM_EV_meas_timer_expire,
	RRM_EV_retry_timer_expire,
	RRM_EV_repeat_delay_expire,
	RRM_EV_request_timer_expire,
	RRM_EV_wait_report,
	RRM_EV_start_meas,
	RRM_EV_survey_done,
	RRM_EV_recv_rep,
	RRM_EV_cancel,
	RRM_EV_state_out,
	RRM_EV_max
};

struct rrm_event {
	u32 rmid;
	enum RRM_EV_ID evid;
	struct list_head list;
};

struct rrm_clock {
	struct rrm_obj *prrm;
	ATOMIC_T counter;
	enum RRM_EV_ID evid;
};



struct dot11k_bcn_accum_rpt {
	s32 RCPI;
	u8 dot11k_channel;
	u8 dot11k_bssid[ETH_ALEN];
};

struct bcn_req_opt {
	/* all req cmd id */
	u8 subelem_id_num;
	u8 rep_detail;
	struct dot11_ssid ssid;

	/* for subelement ID=10(Request) in beacon request */
	u8 *subelem_body;
	u8 subelem_len;
};

struct rm_meas_req {
	u8 category;
	u8 action_code;		/* T8-206  */
	u8 diag_token;
	u16 repetitions;

	u8 e_id;
	u8 len;
	u8 m_token;
	u8 m_request_mode;		/* req:F8-105, rep:F8-141 */
	u8 m_type;		/* T8-59 */
	u8 op_class;
	u8 ch_num;
	u16 rand_intvl;		/* units of TU */
	u16 meas_dur;		/* units of TU */

	u8 bssid[6];		/* for bcn_req */
	u8 bcn_req_m_mode;		/* for bcn_req */

	u8 *pssid;

	struct bcn_req_opt bcn;

	u16 ch_set[MAX_OP_CHANNEL_SET_NUM];
	u8 ch_set_ch_amount;
};

struct rm_meas_rpt {
	u8 category;
	u8 action_code;		/* T8-206  */
	u8 diag_token;

	u8 e_id;		/* T8-54, 38 request; 39 report */
	u8 len;
	u8 m_token;
	u8 m_report_mode;		/* req:F8-105, rep:F8-141 */
	u8 m_type;		/* T8-59 */
	u8 op_class;
	u8 ch_num;

	u16 repetitions;
	u8 bssid[6];		/* for bcn_rep */
};

struct rrm_obj {

	/* aid << 16
		|diag_token << 8
		|B(1) 1/0:All_AID/UNIC
		|B(0) 1/0:RM_MASTER/RM_SLAVE */
	u32 rmid;

	enum RRM_STATE state;
	struct rm_meas_req req;
	struct rm_meas_rpt rpt;
	struct sta_mlme_priv *psta_mlmepriv;
	struct rrm_clock *pclock;

	/* meas report */
	int wait_busy;

	struct list_head list;
};

struct fsm_state {
	char *name;
	int(*fsm_func)(struct rrm_obj *prrm, enum RRM_EV_ID evid);
};

struct rrm_priv {
	struct __queue ev_queue;
	struct __queue rrm_queue;
	struct timer_list rrm_timer;
	struct rrm_clock clock[RM_TIMER_NUM];

	/* rm debug */
	void *prm_sel;

	u8 rm_en_cap_def[5];
	u8 rm_en_cap_assoc[5];

	u8 enable;

	u16 rom_rsvd;
};

struct kvr_priv {
	struct dot11k_bcn_accum_rpt dot11k_bcn_accum_rpt_arry[MAX_BEACON_REPORT];
	struct rrm_priv *rrmpriv;

	u8 *dot11r_ie; /* inculde MDIE for initial assocation req; inculde MDIE&RSNIE&FTIE for roaming reassocation req*/
	u16 dot11r_ielen;

	u8 dot11r_ft_enable;
	u8 dot11k_bcn_accum_num;

	/* Share kvr params with linux fullmac. */
	u8 previous_ap[ETH_ALEN];
	u8 need_to_roam : 1;

	u16 rom_rsvd;
};

/*rtw_rrm_fsm.c*/
#ifdef CONFIG_IEEE80211K
void rtw_rrm_timer_callback(void *data);
struct rrm_clock *rtw_rrm_clock_alloc(struct rrm_obj *prrm);
void rtw_rrm_clock_free(struct rrm_clock *pclock);
void rtw_rrm_state_run(struct rrm_obj *prrm, enum RRM_EV_ID evid);
int rtw_rrm_state_idle(struct rrm_obj *prrm, enum RRM_EV_ID evid);
int rtw_rrm_state_end(struct rrm_obj *prrm, enum RRM_EV_ID evid);
int rtw_rrm_state_do_meas(struct rrm_obj *prrm, enum RRM_EV_ID evid);
int rtw_rrm_state_wait_meas(struct rrm_obj *prrm, enum RRM_EV_ID evid);
int rtw_rrm_state_send_report(struct rrm_obj *prrm, enum RRM_EV_ID evid);
int rtw_rrm_state_recv_report(struct rrm_obj *prrm, enum RRM_EV_ID evid);
#endif
/*rtw_rrm.c*/
#ifdef CONFIG_IEEE80211K
int rtw_rrmobj_enqueue(struct rrm_obj *prrm);
struct rrm_obj *rtw_rrmobj_alloc(void);
void rtw_rrmobj_free(struct rrm_obj *prrm);
struct rrm_obj *rtw_rrmobj_get(u32 rmid);
int rtw_rrm_add_nb_req(struct sta_mlme_priv *psta_mlmepriv);
int rtw_rrm_ready_for_scan(struct rrm_obj *prrm);
int rtw_rrm_sitesurvey(struct rrm_obj *prrm);
void rtw_rrm_sitesurvey_abort(void);
void rtw_rrmapi_ess_scan_accumulate(void);
void rtw_rrmapi_nb_discover(void);
void rtw_rrm_init_priv(void);
void rtw_rrm_enable(void);
void rtw_rrm_disable(void);
#endif
#if defined(CONFIG_IEEE80211V) || defined(CONFIG_IEEE80211K) || defined(CONFIG_IEEE80211R) || defined(CONFIG_SUPPLICANT_SME)
u8 rtw_check_peer_kvr_cap(struct wlan_network *pcur_network);
#endif
u8 rtw_ft_check_en(struct wlan_network *target_network);
/*rtw_rrm_frame.c*/
int rtw_rrm_issue_null_reply(struct rrm_obj *prrm);
int rtw_rrm_issue_beacon_rpt(struct rrm_obj *prrm);
int rtw_rrm_issue_meas_req(struct rrm_obj *prrm);
int rtw_on_action_rrm(u8 iface_type, union recv_frame *precv_frame);
/*rtw_rrm_event.c*/
struct rrm_event *rtw_rrm_event_dequeue(struct __queue *queue);
int rtw_rrm_event_enqueue(u32 rmid, enum RRM_EV_ID evid);
void rtw_rrm_event_handler(void);
int rtw_rrmapi_event_post_cmd(u8 iface_type, u32 rmid, enum RRM_EV_ID evid);

#endif /* __RTW_RM_H_ */
