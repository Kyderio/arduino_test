#ifndef BT_CONTROLLER_LL_LE_CHAN_H
#define BT_CONTROLLER_LL_LE_CHAN_H

uint8_t bt_controller_ll_le_channel_sel_1(uint8_t *channel_map, uint8_t hop, uint16_t latency, uint8_t last_unmapped_channel, uint8_t channel_count,
										  uint8_t *channel_used);
uint8_t bt_controller_ll_le_get_local_channel_sel(uint8_t peer_channel_sel);

#endif