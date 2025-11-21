#ifndef BT_CONTROLLER_VHCI_H
#define BT_CONTROLLER_VHCI_H

#define BT_CONTROLLER_HCI_RECV_STACK_SIZE                       2048

#define BT_CONTROLLER_HCI_CMD_QUEUE_SIZE                        BT_LL_HCI_CMD_NUM
#define BT_CONTROLLER_HCI_CMD_MAX_SIZE                          (BT_LL_HCI_CMD_SIZE + 2 + 1)

#define BT_CONTROLLER_ACL_DATA_RX_QUEUE_SIZE                    BT_LL_ACL_DATA_RX_NUM
#define BT_CONTROLLER_ACL_DATA_MAX_SIZE                         (BT_LL_ACL_DATA_SIZE + 4 + 1)

#define BT_CONTROLLER_HCI_RX_QUEUE_SIZE                         (BT_CONTROLLER_HCI_CMD_QUEUE_SIZE + BT_CONTROLLER_ACL_DATA_RX_QUEUE_SIZE)


#define BT_CONTROLLER_HCI_TX_QUEUE_SIZE                         (BT_LL_HCI_EVT_NUM + BT_LL_ACL_DATA_TX_NUM)

#define BT_CONTROLLER_HCL_ACL_DATA_PACKET_LENGTH                LL_LE_PDU_ACL_DATA_LEN
#define BT_CONTROLLER_HCL_ACL_DATA_TOTAL_NUM                    BT_LL_LE_ACL_DATA_TOTAL_NUM

struct bt_controller_hci_manager {
	void *hci_recv_task;
	void *hci_evt_mutex;
	void *hci_cmd_free_queue;
	void *acl_data_free_queue;
	void *hci_recv_queue;
	void *hci_send_queue;
	uint8_t num_hci_cmd_pkts;
	uint64_t evt_mask;
	uint64_t le_evt_mask;
	uint8_t hci_initialized : 1;
	uint8_t hci_enable : 1;
	uint8_t hci_disable : 1;
	uint8_t rsvd : 5;
};

struct bt_hci_cmd_pkt {
	uint16_t opcode;
	uint8_t param_len;
	uint8_t param[0];
};

struct bt_hci_evt_pkt {
	uint8_t evt_code;
	uint8_t param_len;
	uint8_t param[0];
};

bool bt_controller_vhci_init(void);
void bt_controller_vhci_enable(void);
void bt_controller_vhci_recv(uint8_t type, uint8_t *pbuf, uint16_t len);
void bt_controller_vhci_disable(void);
void bt_controller_vhci_deinit(void);

bool bt_controller_vhci_is_enable(void);

void bt_controller_hci_cmd_handler(uint8_t *pbuf);
bool bt_controller_hci_cmd_ogf_baseband_handler(uint16_t opcode, uint8_t *phci_cmd_param);
bool bt_controller_hci_cmd_ogf_info_handler(uint16_t opcode, uint8_t *phci_cmd_param);
bool bt_controller_hci_cmd_ogf_le_handler(uint16_t opcode, uint8_t *phci_cmd_param);

uint8_t *bt_controller_hci_evt_command_status(uint16_t cmd_opcode, uint8_t status, void **packet);
uint8_t *bt_controller_hci_evt_command_complete(uint16_t opcode, uint8_t plen, void **packet);
void bt_controller_hci_evt_disconnect_complete(uint16_t conn_handle, uint8_t reason);
void bt_controller_hci_evt_le_connection_complete(uint8_t status, uint16_t conn_handle, uint8_t role, uint8_t peer_addr_type, uint8_t *peer_addr,
												  uint8_t *local_rpa, uint8_t *peer_rpa, uint16_t interval, uint16_t latency, uint16_t supversion_timeout, uint8_t sca);
void bt_controller_hci_send_evt(void *packet);

#endif
