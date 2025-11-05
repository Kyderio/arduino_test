#ifndef BT_CONTROLLER_LL_LE_PHY_H
#define BT_CONTROLLER_LL_LE_PHY_H

#define BT_CONTROLLER_LL_LE_PHY_1M              0
#define BT_CONTROLLER_LL_LE_PHY_2M              1
#define BT_CONTROLLER_LL_LE_PHY_CODED           2

uint8_t bt_controller_ll_le_get_preamble_size(uint8_t phy);
uint16_t bt_controller_ll_le_get_pkt_duration_us(uint8_t len, uint8_t phy);
uint8_t bt_controller_ll_le_get_preamble(uint8_t phy, uint8_t *access_address, uint8_t *preamble);
#endif