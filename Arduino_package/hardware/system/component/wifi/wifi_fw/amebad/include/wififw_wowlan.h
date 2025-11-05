#ifndef __WIFIFW_WoWLAN_H__
#define __WIFIFW_WoWLAN_H__

/*--------------------Function declaration---------------------------------*/
extern void wififw_get_tsf(u32 *tsf_h, u32 *tsf_l);
extern bool wififw_wowlan_check_rxff_empty(void);
extern u8 wififw_wowlan_check_rxdma_idle(void);
extern void wififw_wowlan_wakeuphost(void);
extern void wififw_wowlan_get_bcnrssi(u16 pkthead);
extern void wififw_bbgain_idx_backup(void);
#endif  //__WIFIFW_WoWLAN_H__
