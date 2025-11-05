#ifndef __ROM_WIFI_HAL_MISC_H__
#define __ROM_WIFI_HAL_MISC_H__

bool ROM_WIFI_GetChnlGroup(u8 Channel, u8 *pGroup);
void ROM_WIFI_TX_PAUSE_SET(u8 tx_pause, u8 tx_cfg);
void ROM_WIFI_LIMIT_MODE_SET(u8 enable);

#endif
