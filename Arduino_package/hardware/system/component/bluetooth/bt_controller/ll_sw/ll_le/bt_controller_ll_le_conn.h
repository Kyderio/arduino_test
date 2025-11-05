#ifndef BT_CONTROLLER_LL_LE_CONN_H
#define BT_CONTROLLER_LL_LE_CONN_H

#define BT_CONTROLLER_LE_CONN_RX_THREAD_TASK_SIZE                          1024

#define BT_CONTROLLER_LL_LE_CONN_EXTRA_OVER_HEAD_US                        500
#define BT_CONTROLLER_LL_LE_GUART_TIME_US                                  400

#define BT_CONTROLLER_LL_LE_WAIT_FOR_FIRST_DATA_PACKET_CNT                  6

#define BT_CONTROLLER_LE_ROLE_CENTRAL                                       0
#define BT_CONTROLLER_LE_ROLE_PERIPHERAL                                    1

#define BT_CONTROLLER_LE_INVALID_CONN_HANDLE                                0xFFFF

#define BT_CONTROLLER_LE_CONN_IND_TRANSMIT_WINDOW_DELAY_US                  1250
#define BT_CONTROLLER_LE_AUX_CONN_REQ_TRANSMIT_WINDOW_DELAY_UNCODED_US      2500
#define BT_CONTROLLER_LE_AUX_CONN_REQ_TRANSMIT_WINDOW_DELAY_CODED_US        3750


#define BT_LL_LE_CONN_MIN_PKT_SIZE                                  (BT_CONTROLLER_CMD_MAX_SIZE * 4 + 32 + BT_CONTROLLER_RX_DESC_SIZE + LL_LE_PDU_CODED_PHY_PREAMBLE_SIZE + LL_LE_PDU_ACCESS_ADDRESS_SIZE + LL_LE_PDU_HEADER_LEN + LL_LE_PDU_MAX_DATA_LENGTH + LL_LE_PDU_MIC_LEN)

#if (BT_LL_FEATURE_BT42_LE_DATA_LENGTH_EXTENSION == 1)
#define BT_LL_LE_CONN_MAX_PKT_SIZE                                  (BT_CONTROLLER_CMD_MAX_SIZE * 4 + 32 + BT_CONTROLLER_RX_DESC_SIZE + LL_LE_DATA_PKT_MAX_LEN)
#else
#define BT_LL_LE_CONN_MAX_PKT_SIZE                                  BT_LL_LE_CONN_MIN_PKT_SIZE
#endif

enum bt_controller_ll_le_tx_pause_reason {
	BT_CONTROLLER_LL_LE_TX_PAUSE_BY_TERMINATE = BIT0,

};

struct bt_controller_ll_le_conn_data_pkt {
	struct list_head list;
	uint8_t *pdata;
	uint16_t conn_handle;
	uint16_t conn_event;
	uint16_t pkt_len;
	uint8_t pkt_offset;
	uint8_t pdu_offset;
	uint8_t phy : 4;
	uint8_t ctrl_queue : 2;
	uint8_t tx_ack : 1;
	uint8_t bmalloc : 1;
};

struct bt_controller_ll_le_conn_empty_pkt {
	uint8_t pkt_offset;
	uint8_t data[BT_CONTROLLER_TX_CMD_SIZE * 4 + 32 + 16];
	uint8_t pkt_len;
	uint8_t preamble_size;
};


struct bt_controller_ll_le_conn_rx_res {
	struct list_head    data_list;
	struct list_head    pending_list;
	uint8_t rx_md       : 1;
	uint8_t rx_mic_err  : 1;
	uint8_t rx_fec      : 1;
	uint8_t rx_empty    : 1;
	uint8_t rx_pkt_ok   : 1;
	uint8_t rx_intr_cnt : 3;
	uint8_t rx_phy      : 4;
	uint8_t rx_phy_ci   : 4;
	uint16_t rx_header_duration : 16;
	uint8_t rx_preamble_size    : 8;
	uint16_t max_rx_duration    : 16;
	uint32_t rx_instant         : 32;
	uint8_t rx_first_intr : 8;
};

struct bt_controller_ll_le_conn_tx_res {
	struct bt_controller_ll_queue acl_data_pending_queue;
	struct bt_controller_ll_queue ctrl_data_pending_queue;
	struct bt_controller_ll_le_conn_empty_pkt empty_pkt;
	struct list_head    tx_list;
	struct list_head    unack_list;
	struct list_head    release_list;
	uint32_t tx_pause       : 8;
	uint32_t nesn           : 1;
	uint32_t sn             : 1;
	uint32_t rsvd           : 6;
	uint32_t tx_phy         : 4;
	uint32_t tx_phy_ci      : 4;
	uint32_t tx_preamble_size: 8;
	uint32_t tx_instant;
};

struct bt_controller_ll_le_conn_param {
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
};

struct bt_controller_ll_le_conn_data_length {
	uint16_t max_tx_octets;
	uint16_t max_tx_time;
	uint16_t max_rx_octets;
	uint16_t max_rx_time;
};

struct bt_controller_ll_le_conn_set {
	uint16_t conn_handle;
	struct bt_le_addr_t peer_addr;
	struct bt_ll_procedure_node *le_conn_procedure;
	struct bt_controller_ll_le_llcp le_llcp;
	struct bt_controller_ll_le_conn_param conn_param;
	struct bt_controller_ll_le_conn_rx_res rx_res;
	struct bt_controller_ll_le_conn_tx_res tx_res;
	uint32_t conn_event_start_instant;
	uint32_t conn_event_end_instant;
	uint16_t conn_event_cnt;
	uint16_t supervision_timeout_expire_cnt;
	uint16_t elapsed_conn_event;

	struct bt_controller_ll_le_conn_data_length local_data_length;
	struct bt_controller_ll_le_conn_data_length remote_data_length;

	union {
		struct {
			uint8_t last_unmapped_data_channel;
			uint8_t unmapped_data_channel;
		};

		uint16_t data_channel_id;
	};
	uint8_t data_chnl_used;
	uint8_t cur_channel;

	uint8_t data_channel_count;
	uint8_t terminate_reason;
	uint8_t role                    : 1;
	uint8_t create                  : 1;
	uint8_t establish               : 1;
	uint8_t update_conn             : 1;
	uint8_t benc                    : 1;
	uint8_t chan_sel                : 1;
	uint8_t latency_enable          : 1;
	uint8_t rsvd                    : 1;
};

struct bt_controller_ll_le_conn_manger {
	struct bt_controller_ll_le_conn_set conn_set[BT_LL_LE_MAX_CONN_NUM];
	void *rx_pdu_queue;
	struct bt_controller_ll_queue free_ctrl_data_queue;
	struct bt_controller_ll_queue free_acl_data_queue;
	struct bt_controller_ll_queue free_llcp_ctx_queue;
	struct bt_controller_ll_le_llcp_proc_ctx llcp_ctx_pool[BT_LL_LE_MAX_CONN_NUM * BT_LL_LE_CTRL_CTX_MAX_NUM_PER_LINK];
	struct bt_controller_ll_le_conn_data_pkt data_pkt[BT_LL_LE_ACL_DATA_TOTAL_NUM + (BT_LL_LE_MAX_CONN_NUM * 6)];
	uint8_t ctrl_data_pool[BT_LL_LE_CONN_MIN_PKT_SIZE * BT_LL_LE_MAX_CONN_NUM * 6];
	uint8_t acl_data_pool[BT_LL_LE_CONN_MAX_PKT_SIZE * BT_LL_LE_ACL_DATA_TOTAL_NUM];
	uint32_t conn_map;
	void *conn_mutex;
	void *rx_thread;
	uint16_t default_tx_time;
	uint16_t default_tx_octets;
	uint8_t default_tx_phy : 4;
	uint8_t default_rx_phy : 4;
};

bool bt_controller_ll_le_conn_init(void);
void bt_controller_ll_le_conn_deinit(void);
uint16_t bt_controller_le_conn_acquire(void);
void bt_controller_le_conn_release(uint16_t conn_handle);

bool bt_controller_ll_le_conn_create(uint16_t conn_handle, uint8_t role);
bool bt_controller_ll_le_conn_setup(uint16_t conn_handle, struct bt_ll_procedure_node *pll_le_sche_procedure, uint32_t instant, uint8_t *pconn_pkt);
bool bt_controller_ll_le_conn_check_connection(uint8_t role, uint8_t peer_addr_type, uint8_t *peer_addr);
uint8_t bt_controller_ll_le_conn_get_channel_count(uint8_t *channel_map, uint8_t channel_map_len);
bool bt_controller_ll_le_conn_event_done_hdl(struct bt_controller_ll_le_conn_set *ple_conn_set);

struct bt_controller_ll_le_conn_data_pkt *bt_controller_ll_le_conn_alloc_ctrl_data_pkt(void);
void bt_controller_ll_le_conn_enqueue_ctrl_data_pkt(struct bt_controller_ll_le_conn_set *ple_conn_set,
													struct bt_controller_ll_le_conn_data_pkt *pctrl_data_pkt);
struct bt_controller_ll_le_conn_data_pkt *bt_controller_ll_le_conn_alloc_acl_data_pkt(void);
void bt_controller_ll_le_conn_enqueue_acl_data_pkt(struct bt_controller_ll_le_conn_set *ple_conn_set, struct bt_controller_ll_le_conn_data_pkt *pctrl_data_pkt);

void bt_controller_ll_le_conn_rx_release(struct bt_controller_ll_le_conn_set *ple_conn_set);
void bt_controller_ll_le_conn_tx_release(struct bt_controller_ll_le_conn_set *ple_conn_set);

void bt_controller_ll_le_conn_update_chnl_map(struct bt_controller_ll_le_conn_set *ple_conn_set, uint8_t *pchnl_map) ;


bool bt_controller_ll_le_conn_parsing_rx_pkt(struct bt_controller_ll_le_conn_set *ple_conn_set, uint32_t *instant);
void bt_controller_ll_le_send_data_pkt(struct bt_controller_ll_le_conn_set *ple_conn_set, uint32_t instant);
void bt_controller_ll_le_tx_pause_set(struct bt_controller_ll_le_conn_set *ple_conn_set, bool bset, uint8_t mask);
#endif