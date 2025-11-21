
#ifdef NAN_CUSTOMER_NANDOW

enum nan_customer_nandow_cmd_type {
	NANDOW_CMD_TYPE_GET     = (1 << 0),
	NANDOW_CMD_TYPE_SET     = (1 << 1),
};

union nandow_para {
	struct wfpal_nan_device_capability dev_cap;
	struct wfpal_wifi_driver_capabilities drv_cap;
	struct wfpal_nan_enable nan_enabled;
	struct wfpal_nan_cluster_id cluster_id;
	struct wfpal_nan_master_indication_master_preference master_pref;
	struct wfpal_nan_master_indication_random_factor random_factor;
	struct wfpal_nan_discovery_window_awake_period dw_awake_period;
	struct wfpal_nan_primary_master_channel pri_master_ch;
	struct wfpal_nan_secondary_master_channel second_master_ch;
	struct wfpal_nan_discovery_beacon_period disc_bcn_period;
	struct wfpal_nan_publish_data publish_srv;
	struct wfpal_nan_cancel_publish_data cancel_publish_srv;
	struct wfpal_nan_subscribe_data subscribe_srv;
	struct wfpal_nan_cancel_subscribe_data cancel_sub_srv;
	struct wfpal_nan_follow_up_transmit_data followup_srv;
	struct wfpal_nan_datapath_request datapath_req;
	struct wfpal_nan_datapath_end datapath_end;
	struct wfpal_nan_datapath_response datapath_rsp;
	struct wfpal_nan_datapath_confirm datapath_confirm;
	struct wfpal_nan_committed_availability avail_cmt;
	struct wfpal_nan_potential_availability avail_pot;
	struct wfpal_nan_data_cluster_availability avail_ndc;
	struct wfpal_nan_forced_discovery_beacon_transmission forced_disc_bcn;
	struct wfpal_set_scan_control scan_ctl;
	struct wfpal_country_code_data country_code;
};
struct nan_customer_nandow {
	u8 cmd_id;
	u8 cmd_type; // enum nan_customer_nandow_cmd_type
	u32 para_len;
	union nandow_para para;
};

#define NANDOW_EVENTID_OFFSET 0
#define GET_OVERALL_EVENT_ID(nandow_id) (nandow_id+NANDOW_EVENTID_OFFSET)

/* WFPAL_NAN_INIT */
#define SET_WIFI_DRV_NUM_OF_ANTENNAS_TX(pvaule, set_value) (((struct wfpal_nan_device_capability *)pvaule)->number_of_antennas |= (0x00FF & set_value))
#define SET_WIFI_DRV_NUM_OF_ANTENNAS_RX(pvaule, set_value) (((struct wfpal_nan_device_capability *)pvaule)->number_of_antennas |= (set_value << 4))

/*****************************/
/**	Define Data Structure	**/
/*****************************/

/* WFPAL_NAN_INIT */
int rtw_parse_nandow_nan_init(struct nan_customer_nandow *input);

/* WFPAL_WIFI_DRIVER_CAPABILITIES */
int rtw_parse_nandow_drv_cap(struct nan_customer_nandow *input);

/* WFPAL_NAN_ENABLED */
int rtw_parse_nandow_nan_enabled(struct nan_customer_nandow *input);

/* WFPAL_NAN_CLUSTER_ID */
u8 rtw_parse_nandow_cluster_id(struct nan_customer_nandow *input);

/* WFPAL_NAN_DISCOVERY_BEACON_PERIOD */
int rtw_parse_nandow_nan_disc_bcn_period(struct nan_customer_nandow *input);

/* WFPAL_NAN_MASTER_INDICATION_MASTER_PREFERENCE */
u8 rtw_parse_nandow_master_perference(struct nan_customer_nandow *input);

/* WFPAL_NAN_MASTER_INDICATION_RANDOM_FACTOR */
u8 rtw_parse_nandow_random_factor(struct nan_customer_nandow *input);

/* WFPAL_NAN_DISCOVERY_WINDOW_AWAKE_PERIOD */
int rtw_parse_nandow_dw_awake_period(struct nan_customer_nandow *input);

/* WFPAL_NAN_PAIMARY_MASTER_CHANNEL */
int rtw_parse_nandow_primary_master_channel(struct nan_customer_nandow *input);

/* WFPAL_NAN_SECONDARY_MASTER_CHANNEL */
int rtw_parse_nandow_secondary_master_channel(struct nan_customer_nandow *input);

/* WFPAL_NAN_PUBLISH */
int rtw_parse_nandow_nan_publish(struct nan_customer_nandow *input);

/* WFPAL_NAN_CANCEL_PUBLISH */
int rtw_parse_nandow_nan_cancel_publish(struct nan_customer_nandow *input);

/* WFPAL_NAN_SUBSCRIBE */
int rtw_parse_nandow_nan_subscribe(struct nan_customer_nandow *input);

/* WFPAL_NAN_CANCEL_SUBSCRIBE */
int rtw_parse_nandow_nan_cancel_subscribe(struct nan_customer_nandow *input);

/* WFPAL_NAN_FOLLOW_UP_TRANSMIT */
int rtw_parse_nandow_nan_followup(struct nan_customer_nandow *input);

/* WFPAL_NAN_DATAPATH_REQUEST */
int rtw_parse_nandow_nan_datapath_req(struct nan_customer_nandow *input);

/* WFPAL_NAN_DATAPATH_END */
int rtw_parse_nandow_nan_datapath_end(struct nan_customer_nandow *input);

/* WFPAL_NAN_DATAPATH_RESPONSE */
int rtw_parse_nandow_nan_datapath_rsp(struct nan_customer_nandow *input);

/* WFPAL_NAN_DATAPATH_CONFIRM */
int rtw_parse_nandow_nan_datapath_confirm(struct nan_customer_nandow *input);

/* WFPAL_NAN_COMMITTED_AVAILABILITY */
int rtw_parse_nandow_nan_cmt_avail(struct nan_customer_nandow *input);

/* WFPAL_NAN_POTENTIAL_AVAILABILITY */
int rtw_parse_nandow_nan_pot_avail(struct nan_customer_nandow *input);

/* WFPAL_NAN_DATA_CLUSTER_AVAILABILITY */
int rtw_parse_nandow_ndc_avail(struct nan_customer_nandow *input);

int rtw_nandow_on_naf(union recv_frame *precv_frame);

/* WFPAL_NAN_FORCED_BEACON_TRANSMISSION */
int rtw_parse_nandow_nan_forced_disc_bcn(struct nan_customer_nandow *input);

/* WFPAL_NAN_DATA_SCAN_CONTROL */
int rtw_parse_nandow_scan_control(struct nan_customer_nandow *input);

/* WFPAL_NAN_DATA_CONUTRY_CODE */
int rtw_parse_nandow_country_code(struct nan_customer_nandow *input);

u8 is_cfgvendor_nandow_evt_valid(u8 event_id, u8 work_mode);
#else
#define rtw_nandow_on_naf(precv_frame)
#endif /* NAN_CUSTOMER_NANDOW */