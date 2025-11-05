#ifndef __WIFIFW_WOWLAN_H__
#define __WIFIFW_WOWLAN_H__

#define RXFF_BNDY_ALIGH_ADD 					7
/*------------------------------Function declaration--------------------------*/

extern void wififw_get_tsf(u32 *tsf_h, u32 *tsf_l);
extern bool wififw_wowlan_check_rxff_empty(void);
extern u8 wififw_wowlan_check_rxdma_idle(void);
extern void wififw_wowlan_wakeuphost(void);
extern void wififw_wowlan_get_bcnrssi(u16 pkthead);
extern void wififw_wowlan_rx_chinfo_release(void);
#endif  /* #ifndef   __WIFIFW_WOWLAN_H__ */