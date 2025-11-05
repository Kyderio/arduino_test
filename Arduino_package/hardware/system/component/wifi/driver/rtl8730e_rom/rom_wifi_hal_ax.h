
#ifndef __ROM_WIFI_HAL_AX_H__
#define __ROM_WIFI_HAL_AX_H__

#define MUEDCA_TIMER_UNIT_US	32

void ROM_WIFI_AX_BSS_COLOR_SET(u8 iface_type, u8 *val);
void ROM_WIFI_AX_SET_ULOFDMA_RESP_NOMINAL_PAD(u8 mac_id, u8 *val);
void ROM_WIFI_AX_MUEDCA_Para(u32 ac_param[], u8 first);
void ROM_WIFI_AX_MBSSID_Cfg(u8 enable, u8 bssid_idx_to_join, u8 bssid_ref[]);
void ROM_WIFI_AX_SpecialReuse_Cfg(u8 SR_Param_IE[], u8 enable, u8 first);
void ROM_WIFI_AX_SET_MAC_AID(u16 aid);
void ROM_WIFI_AX_GET_MUDECA_PARAM(u8 *ele_start, u8 slot_time, u8 sifs, u32 *val32);

#endif

