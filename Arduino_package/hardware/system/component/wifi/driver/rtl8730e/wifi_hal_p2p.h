#ifndef __WIFI_HAL_P2P_H__
#define __WIFI_HAL_P2P_H__

#ifdef CONFIG_P2PPS
void wifi_hal_p2p_noa0_set(u32 noa_duration, u32 noa_interval, u32 noa_starttime, u8 noa_count);
void wifi_hal_p2p_noa0_disable(void);
#endif
#endif
