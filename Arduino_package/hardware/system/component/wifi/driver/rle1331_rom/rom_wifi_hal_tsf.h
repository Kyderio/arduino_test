#ifndef __ROM_WIFI_HAL_TSF_H__
#define __ROM_WIFI_HAL_TSF_H__

#define WIFI_TSFTR_SYNC_OFFSET 0x190 /* Unit : 128us, 50ms */

void ROM_WIFI_TSF_SET(u8 iface_type, u32 *tsf);
#endif
