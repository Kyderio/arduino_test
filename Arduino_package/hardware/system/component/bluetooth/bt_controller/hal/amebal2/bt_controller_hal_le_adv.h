#ifndef BT_CONTROLLER_HAL_LE_PKT_H
#define BT_CONTROLLER_HAL_LE_PKT_H

struct bt_controller_hal_adv_pkt {
	uint32_t cmd[BT_CONTROLLER_CMD_MAX_SIZE];
	uint8_t *pdata;
	uint8_t len;
};

struct bt_controller_hal_adv {
	struct bt_controller_hal_adv_pkt adv_pkt;
	struct bt_controller_hal_adv_pkt scan_rsp_pkt;
	struct bt_controller_hal_adv_pkt rx_pkt;
};

bool bt_controller_hal_adv_init(struct bt_controller_hal_adv *phal_adv, bool is_legacy_adv);
void bt_controller_hal_adv_deinit(struct bt_controller_hal_adv *phal_adv);
uint16_t bt_controller_hal_adv_enable(struct bt_controller_hal_adv *phal_adv, bool bhigh_duty, uint8_t phy, uint8_t channel_num);
void bt_controller_hal_adv_update_instant(struct bt_controller_hal_adv *phal_adv, uint32_t adv_event_instant, uint8_t chnl_idx);
uint8_t bt_controller_adv_hal_get_pdu_type(struct bt_controller_hal_adv *phal_adv, uint32_t *instant, uint8_t *len);
bool bt_controller_adv_hal_handler_scan_req(struct bt_controller_hal_adv *phal_adv, uint32_t rx_end_instant);
#endif