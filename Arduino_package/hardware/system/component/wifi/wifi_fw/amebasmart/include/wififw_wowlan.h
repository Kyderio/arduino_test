#ifndef __WIFIFW_WoWLAN_RAM_H__
#define __WIFIFW_WoWLAN_RAM_H__

/*--------------------Define MACRO--------------------------------------*/

/*--------------------Define Enum---------------------------------------*/

/*--------------------Function declaration---------------------------------*/
extern void wififw_get_tsf(u32 *tsf_h, u32 *tsf_l);
extern void wififw_wowlan_wakeuphost(void);
extern bool wififw_wowlan_check_rxff_empty(void);
extern u8 wififw_wowlan_check_rxdma_idle(void);
extern void wififw_wowlan_updatechinforeadptr_droppkt(u16 RPtr);
extern void wififw_wowlan_updatephystsreadptr_droppkt(u16 RPtr);
extern void wififw_wowlan_rx_physts_release(void);
extern void wififw_wowlan_rx_chinfo_release(void);
extern void wififw_wowlan_get_bcnrssi(u16 pkthead);
#endif  /* __WIFIFW_WoWLAN_RAM_H__ */
