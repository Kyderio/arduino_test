#ifndef __ROM_WIFI_HAL_TSF_H__
#define __ROM_WIFI_HAL_TSF_H__

#define WIFI_TSFTR_SYNC_OFFSET 0x640 /* Unit : 32us, 50ms */

void ROM_WIFI_TSF_SET(int sta_buddy_fwstate_ap, u8 iface_type, u32 *tsf);

#endif
