#ifndef BT_CONTROLLER_LL_LE_LLCP_H
#define BT_CONTROLLER_LL_LE_LLCP_H

#define BT_CONTROLLER_LL_LE_LLCP_PROC_RESPONSE_TIMEOUT_MS           40000

enum bt_controller_ll_le_llcp_proc_type {
	BT_LL_LE_PROC_TYPE_UNKNOWN,
	BT_LL_LE_PROC_TYPE_CONNECTION_UPDATE,
	BT_LL_LE_PROC_TYPE_CHANNEL_MAP_UPDATE,
	BT_LL_LE_PROC_TYPE_ENCRYPTION_START,
	BT_LL_LE_PROC_TYPE_ENCRYPTION_PAUSE,
	BT_LL_LE_PROC_TYPE_FEATURE_EXCHANGE,
	BT_LL_LE_PROC_TYPE_VERSION_EXCHANGE,
	BT_LL_LE_PROC_TYPE_TERMINATE,
	BT_LL_LE_PROC_TYPE_CONNECTION_PARAM_REQ,
	BT_LL_LE_PROC_TYPE_PING,
	BT_LL_LE_PROC_TYPE_DATA_LENAGTH_UPDATE,
	BT_LL_LE_PROC_TYPE_PHY_UPDATE,
	BT_LL_LE_PROC_TYPE_MIN_NUM_OF_USED_CHANNEL,
	BT_LL_LE_PROC_TYPE_CTE_REQUEST,
	BT_LL_LE_PROC_TYPE_PAST,
	BT_LL_LE_PROC_TYPE_SLEEP_CLOCK_ACCURACY_UPDATE,
	BT_LL_LE_PROC_TYPE_CIS_CREATION,
	BT_LL_LE_PROC_TYPE_CIS_TERMINATION,
	BT_LL_LE_PROC_TYPE_POWER_CONTROL_REQUEST,
	BT_LL_LE_PROC_TYPE_POWER_CHANGE_INDICATION,
	BT_LL_LE_PROC_TYPE_CONNECTION_SUBRATE_UPDATE,
	BT_LL_LE_PROC_TYPE_CONNECTION_SUBRATE_REQUEST,
	BT_LL_LE_PROC_TYPE_CHANNEL_CLASSIFICATION_ENABLE,
	BT_LL_LE_PROC_TYPE_CHANNEL_CLASSIFICATION_REPORTING,
};

enum bt_controller_ll_le_llcp_proc_state {
	BT_LL_LE_LLCP_PROC_DISCONNECT,
	BT_LL_LE_LLCP_PROC_IDLE,
	BT_LL_LE_LLCP_PROC_REJECT,
	BT_LL_LE_LLCP_PROC_UNSUPPORTTED,
	BT_LL_LE_LLCP_PROC_ACT,
	BT_LL_LE_LLCP_PROC_TERMINATE,
};

enum bt_controller_ll_le_llcp_proc_evt {
	BT_LL_LE_LLCP_PROC_EVT_PREPARE,
	BT_LL_LE_LLCP_PROC_EVT_CONNECT,
	BT_LL_LE_LLCP_PROC_EVT_RUN,
	BT_LL_LE_LLCP_PROC_EVT_COMPLETE,
	BT_LL_LE_LLCP_PROC_EVT_DISCONNECT
};

enum bt_controller_ll_le_llcp_collision {
	BT_LL_LE_LLCP_LOCAL_INCOMPAT_NOT_SEND_FIRST_PDU,
	BT_LL_LE_LLCP_LOCAL_INCOMPAT_SEND_FIRST_PDU,
	BT_LL_LE_LLCP_LOCAL_INCOMPAT_RECV_PDU,
};

#define BT_LL_LE_LLCP_PROC_CTX_STATE_IDLE                           0

enum bt_controller_ll_le_llcp_remote_proc_ctx_state {
	BT_LL_LE_LLCP_REMOTE_PROC_CTX_STATE_IDLE = BT_LL_LE_LLCP_PROC_CTX_STATE_IDLE,
	BT_LL_LE_LLCP_REMOTE_PROC_CTX_STATE_WAIT_RX,
	BT_LL_LE_LLCP_REMOTE_PROC_CTX_STATE_WAIT_INSTANT,
	BT_LL_LE_LLCP_REMOTE_PROC_CTX_STATE_WAIT_TX,
	BT_LL_LE_LLCP_REMOTE_PROC_CTX_STATE_WAIT_TX_ACK,

};

enum bt_controller_ll_le_llcp_remote_proc_ctx_evt {
	BT_LL_LE_LLCP_REMOTE_PROC_CTX_EVT_RUN,
	BT_LL_LE_LLCP_REMOTE_PROC_CTX_EVT_RECV_REQUEST,
	BT_LL_LE_LLCP_REMOTE_PROC_CTX_EVT_SEND_RESPONSE,
};


enum bt_controller_ll_le_llcp_local_proc_ctx_state {
	BT_LL_LE_LLCP_LOCAL_PROC_CTX_STATE_IDLE = BT_LL_LE_LLCP_PROC_CTX_STATE_IDLE,
	BT_LL_LE_LLCP_LOCAL_PROC_CTX_STATE_WAIT_TX,
	BT_LL_LE_LLCP_LOCAL_PROC_CTX_STATE_WAIT_TX_ACK,
	BT_LL_LE_LLCP_LOCAL_PROC_CTX_STATE_WAIT_RX,
};

enum bt_controller_ll_le_llcp_local_proc_ctx_evt {
	BT_LL_LE_LLCP_LOCAL_PROC_CTX_EVT_RUN,
	BT_LL_LE_LLCP_LOCAL_PROC_CTX_EVT_RECV_REQUEST,
	BT_LL_LE_LLCP_LOCAL_PROC_CTX_EVT_SEND_RESPONSE,
};

struct bt_controller_ll_le_llcp_proc {
	struct bt_controller_ll_queue pending_proc_queue;
	uint16_t expire_conn_evt;
	uint16_t elapse_conn_evt;
	uint8_t state       : 3;
	uint8_t pause       : 1;
	uint8_t collision   : 1;
	uint8_t incompat    : 1;
	uint8_t init        : 1;
	uint8_t btimeout_en : 1;
};


struct bt_controller_ll_le_llcp_version_proc {
	uint8_t valid       : 4;
	uint8_t sent        : 4;
	struct ll_le_pdu_data_ctrl_version_id remote_version;
};

struct bt_controller_ll_le_llcp_feature_proc {
	uint8_t valid;
	uint64_t feature_remote;
	uint64_t feature_used;
};

struct bt_controller_ll_le_llcp {
	struct bt_controller_ll_le_llcp_proc llcp_local;
	struct bt_controller_ll_le_llcp_proc llcp_remote;
	struct bt_controller_ll_le_llcp_version_proc version;
	struct bt_controller_ll_le_llcp_feature_proc feature;
};

struct bt_controller_ll_le_llcp_proc_ctx {
	struct list_head list;
	uint8_t proc_type;
	uint8_t tx_opcode;
	uint8_t rx_opcode;
	uint8_t response_opcode;
	void  *tx_pkt;
	void  *rx_pkt;
	uint8_t state       : 6;
	uint8_t done        : 2;

	union {
		struct ll_le_pdu_data_ctrl_terminate_ind terminate_ind;
		struct ll_le_pdu_data_ctrl_unknown_rsp unknown_rsp;
		struct ll_le_pdu_data_ctrl_reject_ext_ind reject_ext_ind;
		struct ll_le_pdu_data_ctrl_channel_map_ind chnl_map_ind;
	} data;
};


bool bt_controller_ll_le_llcp_init(uint16_t conn_handle);
void bt_controller_ll_le_llcp_connect(uint16_t conn_handle);
void bt_controller_ll_le_llcp_disconnect(uint16_t conn_handle);
void bt_controller_ll_le_llcp_run(uint16_t conn_handle);
void bt_controller_ll_le_llcp_rx_control_pdu(void *prx_controll_pdu);
void bt_controller_ll_le_llcp_tx_ack_hdl(void *ptx_ack_pkt);
void bt_controller_ll_le_llcp_terminate(uint16_t conn_handle);
void bt_controller_ll_le_llcp_update_conn_cnt(uint16_t conn_handle, uint16_t conn_cnt);
bool bt_controller_ll_le_llcp_response_timeout_hdl(uint16_t conn_handle);
void bt_controller_ll_le_llcp_stop_response_timeout(struct bt_controller_ll_le_llcp_proc *ple_llcp_proc);

void bt_controller_ll_le_llcp_remote_complete(uint16_t conn_handle);
#endif