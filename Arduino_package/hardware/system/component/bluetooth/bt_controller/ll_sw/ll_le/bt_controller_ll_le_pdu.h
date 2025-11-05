#ifndef BT_CONTROLLER_LL_LE_PDU_H
#define BT_CONTROLLER_LL_LE_PDU_H

#define LL_LE_PDU_CHNL_SEL_1                                       0
#define LL_LE_PDU_CHNL_SEL_2                                       1

#define LL_LE_PDU_ADV_CHNL_LEGACY_ADV_HOST_DATA_MAX_SIZE           31

#if (BT_LL_FEATURE_BT50_LE_CHNL_SEL_ALGO_2 == 1)
#define LL_LE_PDU_CHNL_SEL                                          1
#else
#define LL_LE_PDU_CHNL_SEL                                          0
#endif

#define LL_LE_PDU_1M_PREAMBLE_SIZE                                  1
#define LL_LE_PDU_2M_PREAMBLE_SIZE                                  2
#define LL_LE_PDU_CODED_PHY_PREAMBLE_SIZE                           10

#define LL_LE_PDU_ACCESS_ADDRESS_SIZE                               4

#define LL_LE_PDU_HEADER_LEN                                        2
#define LL_LE_PDU_MIC_LEN                                           4

#define LL_LE_PDU_CRC_LEN                                           3

#define LL_LE_PDU_MIN_DATA_LENGTH                                   27
#define LL_LE_PDU_MAX_DATA_LENGTH                                   251

#define LL_LE_PDU_MIN_DATA_TIME_US                                  328
#define LL_LE_PDU_MAX_CODED_PHY_DATA_TIME_US                        17040
#define LL_LE_PDU_MAX_UNCODED_PHY_DATA_TIME_US                      2120

#define LL_LE_PDU_ADV_CHNL_PREAMBLE                                 0xAA
#define LL_LE_PDU_ADV_CHNL_ACCESS_ADDRESS                           0x8E89BED6

#define LL_LE_PDU_ACL_DATA_LEN                                      251
#define LL_LE_DATA_PKT_MAX_LEN                                      (LL_LE_PDU_CODED_PHY_PREAMBLE_SIZE + LL_LE_PDU_ACCESS_ADDRESS_SIZE + LL_LE_PDU_HEADER_LEN + LL_LE_PDU_ACL_DATA_LEN + LL_LE_PDU_MIC_LEN)

#define LL_LE_PDU_TIFS_US                                           150
#define LL_LE_PDU_TIFS_ACTIVE_CLK_JITTER_US                         4
#define LL_LE_PDU_TIFS_SLEEP_CLK_JETTER_US                          32

#define LL_LE_ADV_CHNL_PDU_MIN_SIZE                                 (LL_LE_PDU_HEADER_LEN + BT_ADDR_SIZE)
#define LL_LE_ADV_CHNL_PKT_MIN_SIZE                                 (LL_LE_PDU_1M_PREAMBLE_SIZE + LL_LE_PDU_ACCESS_ADDRESS_SIZE + LL_LE_ADV_CHNL_PDU_MIN_SIZE)

#define LL_LE_ADV_CHNL_PDU_MAX_SIZE                                 (LL_LE_PDU_HEADER_LEN + BT_ADDR_SIZE + LL_LE_PDU_ADV_CHNL_LEGACY_ADV_HOST_DATA_MAX_SIZE)
#define LL_LE_ADV_CHNL_PKT_MAX_SIZE                                 (LL_LE_PDU_1M_PREAMBLE_SIZE + LL_LE_PDU_ACCESS_ADDRESS_SIZE + LL_LE_ADV_CHNL_PDU_MAX_SIZE)

#define LL_LE_PDU_SCAN_REQ_SIZE                                     12
#define LL_LE_PKT_SCAN_REQ_SIZE                                     (LL_LE_PDU_1M_PREAMBLE_SIZE + LL_LE_PDU_ACCESS_ADDRESS_SIZE + LL_LE_PDU_HEADER_LEN + LL_LE_PDU_SCAN_REQ_SIZE)

#define LL_LE_PDU_CONN_IND_SIZE                                     34
#define LL_LE_PKT_CONN_IND_SIZE                                     (LL_LE_PDU_1M_PREAMBLE_SIZE + LL_LE_PDU_ACCESS_ADDRESS_SIZE + LL_LE_PDU_HEADER_LEN + LL_LE_PDU_CONN_IND_SIZE)

#define LL_LE_PDU_CHNL_MAP_SIZE                                     5

#define LL_LE_CONN_IND_DURATION_US                                  ((LL_LE_PKT_CONN_IND_SIZE + LL_LE_PDU_CRC_LEN) << 3)
#define LL_LE_SCAN_REQ_DURATION_US                                  ((LL_LE_PKT_SCAN_REQ_SIZE + LL_LE_PDU_CRC_LEN) << 3)

#define LL_LE_PDU_EMPTY_PDU_SIZE                                    LL_LE_PDU_HEADER_LEN
#define LL_LE_PDU_EMPTY_PKT_SIZE                                    (LL_LE_PDU_CODED_PHY_PREAMBLE_SIZE + LL_LE_PDU_ACCESS_ADDRESS_SIZE + LL_LE_PDU_EMPTY_PDU_SIZE)

#define LL_LE_PDU_CTRL_PDU_MAX_SIZE                                 (LL_LE_PDU_HEADER_LEN + 30)
#define LL_LE_PDU_CTRL_PKT_MAX_SIZE                                 (LL_LE_PDU_CODED_PHY_PREAMBLE_SIZE + LL_LE_PDU_ACCESS_ADDRESS_SIZE + LL_LE_PDU_CTRL_PDU_MAX_SIZE)

struct pdu_adv_adv_ind {
	uint8_t adv_addr[BT_ADDR_SIZE];
	uint8_t data[LL_LE_PDU_ADV_CHNL_LEGACY_ADV_HOST_DATA_MAX_SIZE];
}  __attribute__((packed));

struct pdu_adv_direct_ind {
	uint8_t adv_addr[BT_ADDR_SIZE];
	uint8_t tgt_addr[BT_ADDR_SIZE];
} __attribute__((packed));

struct pdu_adv_scan_req {
	uint8_t scan_addr[BT_ADDR_SIZE];
	uint8_t adv_addr[BT_ADDR_SIZE];
} __attribute__((packed));

struct pdu_adv_scan_rsp {
	uint8_t adv_addr[BT_ADDR_SIZE];
	uint8_t data[LL_LE_PDU_ADV_CHNL_LEGACY_ADV_HOST_DATA_MAX_SIZE];
} __attribute__((packed));

struct pdu_adv_conn_ind {
	uint8_t init_addr[BT_ADDR_SIZE];
	uint8_t adv_addr[BT_ADDR_SIZE];
	struct {
		uint8_t access_address[4];
		uint8_t crc_init[3];
		uint8_t win_size;
		uint16_t win_offset;
		uint16_t interval;
		uint16_t latency;
		uint16_t timeout;
		uint8_t chan_map[LL_LE_PDU_CHNL_MAP_SIZE];
		uint8_t hop : 5;
		uint8_t sca : 3;
	} __attribute__((packed));

} __attribute__((packed));

struct ll_le_pdu_adv {
	uint8_t type : 4;
	uint8_t rfu : 1;
	uint8_t ch_sel : 1;
	uint8_t tx_addr : 1;
	uint8_t rx_addr : 1;

	uint8_t len;

	union {
		uint8_t payload[0];
		struct pdu_adv_adv_ind adv_ind;
		struct pdu_adv_direct_ind direct_ind;
		struct pdu_adv_scan_req scan_req;
		struct pdu_adv_scan_rsp scan_rsp;
		struct pdu_adv_conn_ind conn_ind;
	} __attribute__((packed));
} __attribute__((packed));

struct ll_le_pdu_data {
	uint16_t llid : 2;
	uint16_t nesn : 1;
	uint16_t sn : 1;
	uint16_t md : 1;
	uint16_t cp : 1;
	uint16_t rfu : 2;
	uint16_t len : 8;
	uint8_t payload[0];
} __attribute__((packed));

enum ll_le_pdu_data_llid {
	BT_LL_LE_PDU_DATA_LLID_RESV = 0x00,
	BT_LL_LE_PDU_DATA_LLID_DATA_CONTINUE = 0x01,
	BT_LL_LE_PDU_DATA_LLID_DATA_START = 0x02,
	BT_LL_LE_PDU_DATA_LLID_CTRL = 0x03,
};

enum ll_le_pdu_data_ctrl_type {
	BT_LL_LE_PDU_DATA_CTRL_TYPE_CONNECTION_UPDATE_IND = 0x00,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_CHANNEL_MAP_IND = 0x01,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_TERMINATE_IND = 0x02,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_ENC_REQ = 0x03,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_ENC_RSP = 0x04,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_START_ENC_REQ = 0x05,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_START_ENC_RSP = 0x06,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_UNKNOWN_RSP = 0x07,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_FEATURE_REQ = 0x08,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_FEATURE_RSP = 0x09,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_PAUSE_ENC_REQ = 0x0A,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_PAUSE_ENC_RSP = 0x0B,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_VERSION_IND = 0x0C,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_REJECT_IND = 0x0D,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_PERIPHERAL_FEATURE_REQ = 0x0E,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_CONNECTION_PARAM_REQ = 0x0F,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_CONNECTION_PARAM_RSP = 0x10,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_REJECT_EXT_IND = 0x11,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_PING_REQ = 0x12,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_PING_RSP = 0x13,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_LENGTH_REQ = 0x14,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_LENGTH_RSP = 0x15,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_PHY_REQ = 0x16,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_PHY_RSP = 0x17,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_PHY_UPDATE_IND = 0x18,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_MIN_USED_CHANNELS_IND = 0x19,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_CTE_REQ = 0x1A,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_CTE_RSP = 0x1B,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_PERIODIC_SYNC_IND = 0x1C,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_CLOCK_ACCURACY_REQ = 0x1D,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_CLOCK_ACCURACY_RSP = 0x1E,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_CIS_REQ = 0x1F,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_CIS_RSP = 0x20,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_CIS_IND = 0x21,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_CIS_TERMINATE_IND = 0x22,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_POWER_CONTROL_REQ = 0x23,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_POWER_CONTROL_RSP = 0x24,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_POWER_CHANGE_IND = 0x25,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_SUBRATE_REQ = 0x26,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_SUBRATE_IND = 0x27,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_CHANNEL_REPORTING_IND = 0x28,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_CHANNEL_STATUS_IND = 0x29,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_PERIODIC_SYNC_WR_IND = 0x2A,
	BT_LL_LE_PDU_DATA_CTRL_TYPE_INVALID = 0xFF,
};

struct ll_le_pdu_data_ctrl_connection_update_ind {
	uint8_t win_size;
	uint16_t win_offset;
	uint16_t interval;
	uint16_t latency;
	uint16_t timeout;
	uint16_t instant;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_channel_map_ind {
	uint8_t chnl_map[5];
	uint16_t instant;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_terminate_ind {
	uint8_t err_code;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_enc_req {
	uint8_t rand[8];
	uint8_t enc_div[2];
	uint8_t skd_c[8];
	uint8_t iv_c[4];
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_enc_rsp {
	uint8_t skd_p[8];
	uint8_t iv_p[4];
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_start_enc_req {
	//no memeber
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_start_enc_rsp {
	//no member
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_unknown_rsp {
	uint8_t unknown_type;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_feature_req {
	uint8_t feature_set[8];
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_feature_rsp {
	uint8_t feature_set[8];
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_pause_enc_req {
	//no member
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_pause_enc_rsp {
	//no member
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_version_id {
	uint8_t version;
	uint16_t company_id;
	uint16_t sub_version;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_reject_ind {
	uint8_t error_code;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_peripheral_feature_req {
	uint8_t feature_set[8];
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_connection_param_req {
	uint16_t interval_min;
	uint16_t interval_max;
	uint16_t latency;
	uint16_t timeout;
	uint8_t preference_periodicity;
	uint16_t preference_conn_event_count;
	uint16_t offset0;
	uint16_t offset1;
	uint16_t offset2;
	uint16_t offset3;
	uint16_t offset4;
	uint16_t offset5;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_connection_param_rsp {
	uint16_t interval_min;
	uint16_t interval_max;
	uint16_t latency;
	uint16_t timeout;
	uint8_t preference_periodicity;
	uint16_t preference_conn_event_count;
	uint16_t offset0;
	uint16_t offset1;
	uint16_t offset2;
	uint16_t offset3;
	uint16_t offset4;
	uint16_t offset5;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_reject_ext_ind {
	uint8_t reject_opcode;
	uint8_t error_code;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_ping_req {

} __attribute__((packed));

struct ll_le_pdu_data_ctrl_ping_rsp {

} __attribute__((packed));

struct ll_le_pdu_data_ctrl_length_req {
	uint16_t max_rx_octects;
	uint16_t max_rx_time;
	uint16_t max_tx_octects;
	uint16_t max_tx_time;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_length_rsp {
	uint16_t max_rx_octects;
	uint16_t max_rx_time;
	uint16_t max_tx_octects;
	uint16_t max_tx_time;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_phy_req {
	uint8_t tx_phys;
	uint8_t rx_phys;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_phy_rsp {
	uint8_t tx_phys;
	uint8_t rx_phys;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_phy_update_ind {
	uint8_t phy_c_to_p;
	uint8_t phy_p_to_c;
	uint16_t instant;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_min_used_channels_ind {
	uint8_t phys;
	uint8_t min_used_channels;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_cte_req {
	uint8_t min_cte_len_req : 5;
	uint8_t rfu : 1;
	uint8_t cte_type_req : 2;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_cte_rsp {

} __attribute__((packed));

struct ll_le_pdu_data_ctrl_periodic_sync_ind {
	uint16_t id;
	uint8_t sync_info[18];
	uint16_t conn_event_count;
	uint16_t last_pa_event_count;
	uint8_t sid : 4;
	uint8_t a_type : 1;
	uint8_t sca : 3;
	uint8_t phy;
	uint8_t adv_a[6];
	uint16_t sync_conn_event_count;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_clock_accuracy_req {
	uint8_t sca;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_clock_accuracy_rsp {
	uint8_t sca;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_cis_req {
	uint8_t cig_id;
	uint8_t cis_id;
	uint8_t phy_c_to_p;
	uint8_t phy_p_to_c;
	uint16_t max_sdu_c_to_p : 12;
	uint16_t rfu : 3;
	uint16_t framed : 1;
	uint16_t max_sdu_p_to_c;
	uint8_t sdu_interval_c_to_p[3];
	uint8_t sdu_interval_p_to_c[3];
	uint16_t max_pdu_c_to_p;
	uint16_t max_pdu_p_to_c;
	uint8_t nse;
	uint8_t sub_interval[3];
	uint8_t bn_c_to_p : 4;
	uint8_t bn_p_to_c : 4;
	uint8_t ft_c_to_p;
	uint8_t ft_p_to_c;
	uint16_t iso_interval;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_cis_rsp {
	uint8_t cis_offset_min[3];
	uint8_t cis_offset_max[3];
	uint16_t conn_event_count;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_cis_ind {
	uint8_t aa[4];
	uint8_t cis_offset[3];
	uint8_t cig_sync_delay[3];
	uint8_t cis_sync_delay[3];
	uint16_t conn_event_count;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_cis_terminate_ind {
	uint8_t cig_id;
	uint8_t cis_id;
	uint8_t error_code;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_power_control_req {
	uint8_t phy;
	uint8_t delta;
	uint8_t tx_power;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_power_control_rsp {
	uint8_t min : 1;
	uint8_t max : 1;
	uint8_t rfu : 6;
	uint8_t delta;
	uint8_t tx_power;
	uint8_t apr;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_power_change_ind {
	uint8_t phy;
	uint8_t min : 1;
	uint8_t max : 1;
	uint8_t rfu : 6;
	uint8_t delta;
	uint8_t tx_power;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_subrate_req {
	uint16_t subrate_factor_min;
	uint16_t subrate_factor_max;
	uint16_t max_latency;
	uint16_t continuation_number;
	uint16_t timeout;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_subrate_ind {
	uint16_t subrate_factor;
	uint16_t subrate_base_event;
	uint16_t latency;
	uint16_t continuation_number;
	uint16_t timeout;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_channel_reporting_ind {
	uint8_t enable;
	uint8_t min_spacing;
	uint8_t max_delay;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_channel_status_ind {
	uint8_t channel_classification[10];
} __attribute__((packed));

struct ll_le_pdu_data_ctrl_periodic_sync_wr_ind {
	struct ll_le_pdu_data_ctrl_periodic_sync_ind sync_ind;
	uint8_t rsp_aa[4];
	uint8_t num_sub_events;
	uint8_t sub_event_interval;
	uint8_t response_slot_delay;
	uint8_t response_slot_spacint;
} __attribute__((packed));

struct ll_le_pdu_data_ctrl {
	uint8_t opcode;
	union {
		struct ll_le_pdu_data_ctrl_connection_update_ind connection_update_ind;
		struct ll_le_pdu_data_ctrl_channel_map_ind channel_map_ind;
		struct ll_le_pdu_data_ctrl_terminate_ind terminate_ind;
		struct ll_le_pdu_data_ctrl_enc_req enc_req;
		struct ll_le_pdu_data_ctrl_enc_rsp enc_rsp;
		struct ll_le_pdu_data_ctrl_start_enc_req start_enc_req;
		struct ll_le_pdu_data_ctrl_start_enc_rsp start_enc_rsp;
		struct ll_le_pdu_data_ctrl_unknown_rsp unknown_rsp;
		struct ll_le_pdu_data_ctrl_feature_req feature_req;
		struct ll_le_pdu_data_ctrl_feature_rsp feature_rsp;
		struct ll_le_pdu_data_ctrl_pause_enc_req pause_enc_req;
		struct ll_le_pdu_data_ctrl_pause_enc_rsp pause_enc_rsp;
		struct ll_le_pdu_data_ctrl_version_id version_ind;
		struct ll_le_pdu_data_ctrl_reject_ind reject_ind;
		struct ll_le_pdu_data_ctrl_peripheral_feature_req peripheral_feature_req;
		struct ll_le_pdu_data_ctrl_connection_param_req connection_param_req;
		struct ll_le_pdu_data_ctrl_connection_param_rsp conenction_param_rsp;
		struct ll_le_pdu_data_ctrl_reject_ext_ind reject_ext_ind;
		struct ll_le_pdu_data_ctrl_ping_req ping_req;
		struct ll_le_pdu_data_ctrl_ping_rsp ping_rsp;
		struct ll_le_pdu_data_ctrl_length_req length_req;
		struct ll_le_pdu_data_ctrl_length_rsp length_rsp;
		struct ll_le_pdu_data_ctrl_phy_req phy_req;
		struct ll_le_pdu_data_ctrl_phy_rsp phy_rsp;
		struct ll_le_pdu_data_ctrl_phy_update_ind phy_update_ind;
		struct ll_le_pdu_data_ctrl_min_used_channels_ind min_used_channels_ind;
		struct ll_le_pdu_data_ctrl_cte_req cte_req;
		struct ll_le_pdu_data_ctrl_cte_rsp cte_rsp;
		struct ll_le_pdu_data_ctrl_periodic_sync_ind periodic_sync_ind;
		struct ll_le_pdu_data_ctrl_clock_accuracy_req clock_accuracy_req;
		struct ll_le_pdu_data_ctrl_clock_accuracy_rsp clock_accuracy_rsp;
		struct ll_le_pdu_data_ctrl_cis_req cis_req;
		struct ll_le_pdu_data_ctrl_cis_rsp cis_rsp;
		struct ll_le_pdu_data_ctrl_cis_ind cis_ind;
		struct ll_le_pdu_data_ctrl_cis_terminate_ind cis_terminate_ind;
		struct ll_le_pdu_data_ctrl_power_control_req power_control_req;
		struct ll_le_pdu_data_ctrl_power_control_rsp power_control_rsp;
		struct ll_le_pdu_data_ctrl_power_change_ind power_change_ind;
		struct ll_le_pdu_data_ctrl_subrate_req  subrate_req;
		struct ll_le_pdu_data_ctrl_subrate_ind subrate_ind;
		struct ll_le_pdu_data_ctrl_channel_reporting_ind channel_reporting_ind;
		struct ll_le_pdu_data_ctrl_channel_status_ind channel_status_ind;
		struct ll_le_pdu_data_ctrl_periodic_sync_wr_ind periodic_sync_wr_ind;
	} __attribute__((packed));
} __attribute__((packed));

#endif