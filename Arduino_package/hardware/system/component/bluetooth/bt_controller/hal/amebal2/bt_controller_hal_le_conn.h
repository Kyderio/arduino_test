#ifndef BT_CONTROLLER_HAL_LE_CONN_H
#define BT_CONTROLLER_HAL_LE_CONN_H

struct bt_controller_hal_ll_le_acl_pkt {
	uint32_t cmd[BT_CONTROLLER_CMD_MAX_SIZE];
	uint8_t phy;
	uint8_t *pdata;
	uint16_t len;
};

struct bt_controller_hal_ll_le_conn {
	struct bt_controller_hal_ll_le_acl_pkt acl_empty_pkt;
	struct bt_controller_hal_ll_le_acl_pkt acl_tx_pkt;
	struct bt_controller_hal_ll_le_acl_pkt acl_rx_pkt;
	uint8_t data_chnl_used;
	uint8_t current_channel;
};

bool bt_controller_ll_le_hal_conn_init(struct bt_controller_hal_ll_le_conn *phal_le_conn, uint8_t role);
uint16_t bt_controller_hal_ll_le_get_sca_ppm_us_peer(uint8_t sca);
void bt_controller_hal_ll_le_conn_send_empty_pkt(struct bt_controller_hal_ll_le_conn *phal_le_conn, uint32_t instant, uint8_t nesn, uint8_t sn, uint8_t md,
												 uint8_t phy);
void bt_controller_hal_ll_le_conn_send_data_pkt(struct bt_controller_hal_ll_le_conn *phal_le_conn, uint8_t *pkt, uint8_t len, uint8_t phy, uint32_t instant);
void bt_controller_hal_ll_le_conn_prepare_recv_data_pkt(struct bt_controller_hal_ll_le_conn *phal_le_conn, uint32_t instant, uint16_t timeout, uint8_t phy,
														uint8_t *access_address);
#endif