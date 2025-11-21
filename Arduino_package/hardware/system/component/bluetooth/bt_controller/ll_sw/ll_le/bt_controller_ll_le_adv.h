#ifndef BT_CONTROLLER_LL_LE_ADV_H
#define BT_CONTROLLER_LL_LE_ADV_H


#define BT_CONTROLLER_LL_LE_ADV_HCI_CMD_PREPARATION_TIME            5000
#define BT_CONTROLLER_LL_LE_ADV_CHNL_TO_CHNL_TIME_US                625

#define BT_CONTROLLER_LL_LE_DEFAULT_TX_POWER_INDEX                  0x3F

#define BT_CONTROLLER_LL_LE_HIGH_DUTY_ADV_DURATION_US               1280000
#define BT_CONTROLLER_LL_LE_HIGH_DUTY_ADV_H2H_US                    3750

//core spectification v5.4|Vol 6, PartB Table 2.3
enum bt_controller_ll_le_pdu_adv_type {
	LL_LE_PDU_ADV_TYPE_ADV_IND = 0x00,
	LL_LE_PDU_ADV_TYPE_ADV_DIRECT_IND = 0x01,
	LL_LE_PDU_ADV_TYPE_NONCONN_IND  = 0x02,
	LL_LE_PDU_ADV_TYPE_SCAN_REQ = 0x03,
	LL_LE_PDU_ADV_TYPE_AUX_SCAN_REQ = LL_LE_PDU_ADV_TYPE_SCAN_REQ,
	LL_LE_PDU_ADV_TYPE_SCAN_RSP = 0x04,
	LL_LE_PDU_ADV_TYPE_CONNECT_IND = 0x05,
	LL_LE_PDU_ADV_TYPE_AUX_CONNECT_REQ = LL_LE_PDU_ADV_TYPE_CONNECT_IND,
	LL_LE_PDU_ADV_TYPE_SCAN_IND = 0x06,
	LL_LE_PDU_ADV_TYPE_ADV_EXT_IND = 0x07,
	LL_LE_PDU_ADV_TYPE_AUX_ADV_IND = LL_LE_PDU_ADV_TYPE_ADV_EXT_IND,
	LL_LE_PDU_ADV_TYPE_AUX_SCAN_RSP = LL_LE_PDU_ADV_TYPE_ADV_EXT_IND,
	LL_LE_PDU_ADV_TYPE_AUX_SYNC_IND = LL_LE_PDU_ADV_TYPE_ADV_EXT_IND,
	LL_LE_PDU_ADV_TYPE_CHAIN_IND = LL_LE_PDU_ADV_TYPE_ADV_EXT_IND,
	LL_LE_PDU_ADV_TYPE_AUX_SYNC_SUBEVENT_IND = LL_LE_PDU_ADV_TYPE_ADV_EXT_IND,
	LL_LE_PDU_ADV_TYPE_AUX_SYNC_SUBEVENT_RSP = LL_LE_PDU_ADV_TYPE_ADV_EXT_IND,
	LL_LE_PDU_ADV_TYPE_AUX_CONNECT_RSP = 0x08,
	LL_LE_PDU_ADV_TYPE_INVALID = 0xF,
};


enum bt_controller_hci_adv_type {
	LL_LE_ADV_HCI_CMD_TYPE_UNINITIALZE = 0x00,
	LL_LE_ADV_HCI_CMD_TYPE_LEGACY = 0x01,
	LL_LE_ADV_HCI_CMD_TYPE_EXTENDED = 0x02,
};

enum bt_controller_ll_le_legacy_adv_state {
	LL_LE_ADV_ADV_EVENT_START,
	LL_LE_ADV_SEND_ADV_PKT,
	LL_LE_ADV_SEND_SCAN_RSP,
	LL_LE_ADV_STOP,
};

struct bt_controller_ll_le_adv_param {
	uint16_t interval;
	struct bt_le_addr_t peer_addr;
	uint8_t pdu_type : 8;
	uint8_t chan_map: 3;
	uint8_t filter_policy : 2;
	uint8_t own_add_type : 1;
	uint8_t direct_high_duty : 1;
};

struct bt_controller_ll_le_adv_set {
	uint8_t handle;
	struct bt_controller_ll_le_adv_param adv_param;
	struct bt_ll_procedure_node *adv_procedure;
	struct bt_controller_hal_adv hal_adv;
	uint32_t adv_event_start_instant;
	uint32_t high_duty_adv_stop_instant;
	uint8_t max_channel_num : 4;
	uint8_t cur_channel_idx : 4;
	uint8_t channel_number[3];
	uint8_t create : 1;
	uint8_t enable : 1;
	uint8_t start : 1;
	uint8_t cur_state : 5;

	uint16_t conn_handle;
};

struct bt_controller_ll_le_adv_manager {
	uint8_t hci_cmd_type;
	struct bt_controller_ll_le_adv_set le_adv_set[BT_LL_LE_ADV_SET_NUM];
};

void bt_controller_ll_le_adv_init(void);
void bt_controller_ll_le_adv_reset(void);
bool bt_controller_ll_le_adv_check_hci_cmd_valid(uint8_t hci_cmd_type);

struct bt_controller_ll_le_adv_set *bt_controller_ll_le_find_adv_set_by_handle(uint8_t adv_handle);

uint8_t bt_controller_ll_le_adv_set_param(uint8_t adv_handle, uint16_t interval_min, uint16_t interval_max,
										  uint8_t pdu_type, uint8_t own_addr_type, uint8_t direct_add_type,
										  uint8_t *direct_addr, uint8_t channel_map, uint8_t policy_type
										 );
uint8_t bt_controller_ll_le_adv_set_adv_data(u8 adv_handle, uint8_t *pdata, uint8_t len);
uint8_t bt_controller_ll_le_adv_set_scan_rsp_data(u8 adv_handle, uint8_t *pdata, uint8_t len);
uint8_t bt_controller_ll_le_adv_set_enable(uint8_t adv_handle, uint8_t enable);
#endif