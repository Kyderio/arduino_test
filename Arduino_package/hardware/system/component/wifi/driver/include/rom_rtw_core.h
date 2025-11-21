/******************************************************************************
 *
 * Copyright(c) 2007 - 2014 Realtek Corporation. All rights reserved.
 *
 * This is ROM code section.
 *
 *
 ******************************************************************************/
#ifndef _ROM_RTW_CORE_H_
#define _ROM_RTW_CORE_H_

#include "rtw_wifi_constants.h"
#include "rom_secure_common.h"
#include "rom_wpa_lite_intf.h"
#include "rom_rtw_defs.h"
#include "rom_rtw_rf.h"
#include "rom_rtw_structs.h"
#include "rom_rtw_80211w.h"
#include "rom_rtw_security.h"
#include "rom_rtw_rate.h"
#include "rom_rtw_chbw.h"
#include "rom_ieee80211.h"
#include "rom_rtw_pmksa_cache.h"
#include "rom_rtw_psk.h"
#include "rom_platform.h"
#include "rom_rtw_ieee80211_part2.h"
#include <rom_rtw_assoc.h>
#include "rom_hal_debug.h"

#include "rom_hal_rom_to_flash.h"

/*-------------------------------------------------------------------------------
	rom_rtw_action.c.
--------------------------------------------------------------------------------*/
u16 wifi_rom_para_set_for_addba(unsigned char action, unsigned short content, u16 max_rx_ampdu_factor);
bool wifi_rom_on_action_csa(u8 *pframe, u8 *ch_mode, u8 *ch_no, u8 *ch_count);

/*-------------------------------------------------------------------------------
	rom_rtw_recv.c.
--------------------------------------------------------------------------------*/
sint wifi_rom_check_pn(u8 fragnum, union pn48 *rxPN, union pn48 *pCurRxPN);
int wifi_rom_check_indicate_seq(u16 *indicate_seq, u16 wsize, u16 wend, u16 seq_num);
u8 wifi_rom_get_wmmps_ac(u8 priority, u8 uapsd_bk, u8 uapsd_vi, u8 uapsd_vo, u8 uapsd_be, u8 bit);

/*-------------------------------------------------------------------------------
	rom_rtw_beacon.c.
--------------------------------------------------------------------------------*/
u8 wifi_rom_beacon_rate_check(u8 *rate, u8 rate_len, unsigned char *SupportedRates, unsigned char *MCS_rate_cap, u8 *MCS_rate);
void wifi_rom_beacon_bw_check(unsigned char infos, unsigned char *bw_mode, unsigned char *ch_offset);
u8 wifi_rom_beacon_ssid_check(u8 *bssid_IEs, u32 bssid_IELength, u8  *Ssid, u32  SsidLength);
u8 wifi_rom_beacon_encryption_check(u8 *bssid_IEs, u32 bssid_IELength, u32 Privacy, u8 *is_beacon, struct bcn_info_param *BcnInfo);
void wifi_rom_beacon_info_get(u8 *pIE, u32 pIELength, u32 *Privacy, struct bcn_info_param *BcnInfo, unsigned char **ht_cap, unsigned char **ht_info);
u8 wifi_rom_beacon_csa_info_get(u8 *pframe, u32 pkt_len, u8 *ch_mode, u8 *ch_no, u8 *ch_count);
int wifi_rom_ap_beacon_update_hidden_ssid(u8 *ies, u32 ies_len, u8 hidden_ssid_mode);
void wifi_rom_ap_beacon_update_bcn_tim(unsigned char *pie, u32 *IELength, u32 SsidLength, u16 tim_bitmap);
void wifi_rom_ap_beacon_update_erpinfo_ie(unsigned char *ie, u32 IELength, u8 num_sta_non_erp, u8 num_sta_no_short_preamble, u8 *ERP_IE);
void wifi_rom_ap_beacon_add_ie(u8 index, u8 *data, u8 len, u8 *pie, u32 *IELength);
void wifi_rom_ap_beacon_remove_ie(u8 index, u8 *pie, u32 *IELength);
int wifi_rom_ap_beacon_gen_ie(u8 *ie, u8 *ssid, u16 ssid_len, u32 max_ie_sz, struct update_mode_parms *param, struct securitypriv_parms *secur_param,
							  u8 support_40M, u32 max_rx_ampdu_factor, u8 is_p2p_go);

/*-------------------------------------------------------------------------------
	rom_rtw_psk.c.
--------------------------------------------------------------------------------*/
int rom_psk_PasswordHash(unsigned char *password, int passwordlength, unsigned char *ssid, int ssidlength, unsigned char *output);
u16 wifi_rom_psk_strip_rsn_pairwise(u8 *ie, u16 ie_len);
u16 wifi_rom_psk_strip_wpa_pairwise(u8 *ie, u16 ie_len, u32 privacy_alg);

/*-------------------------------------------------------------------------------
	rom_rtw_auth.c.
--------------------------------------------------------------------------------*/
u32 wifi_rom_set_beacon_timeout(u16 bcn_interval);

/*-------------------------------------------------------------------------------
	rom_rtw_he.c.
--------------------------------------------------------------------------------*/
u8 wifi_rom_he_get_highest_rate(u8 *he_mcs_map);
void wifi_rom_he_nss_to_mcsmap(u8 nss, u8 *target_mcs_map, u8 *cur_mcs_map);
u64	wifi_rom_he_mcsmap_to_bitmap(u8 *mcs_map, u8 nss);

/*-------------------------------------------------------------------------------
	ht code in rom_rtw_ieee80211_part2.h.
--------------------------------------------------------------------------------*/
void wifi_rom_HT_caps_handler(struct HT_caps_element *HT_caps, struct _NDIS_802_11_VARIABLE_IEs *pIE);

/*-------------------------------------------------------------------------------
	rom_rtw_rate.c.
--------------------------------------------------------------------------------*/
int wifi_rom_cckrates_included(unsigned char *rate, int ratelen);
int wifi_rom_cckratesonly_included(unsigned char *rate, int ratelen);
void wifi_rom_updateBratetbl(u8 *mBratesOS);
void wifi_rom_updateBratetbl_softap(u8 *bssrateset, u32 bssratelen);
int wifi_rom_rate2tbl_inx(unsigned char rate);
unsigned int wifi_rom_update_mcs_rate(struct HT_caps_element *pHT_caps);
unsigned char wifi_rom_get_highest_rateidx(u32 mask);

/*-------------------------------------------------------------------------------
	rom_rtw_probe.c.
--------------------------------------------------------------------------------*/
u8 *wifi_rom_set_probersp_tim_ie(u8 *pframe, u8 *pIEs, u32 ie_len, u32 *pkt_len);
u8 wifi_rom_on_probereq(u8 *pframe, u32 len, u8 *ssid, u32 ssid_len, u8 hidden);

#endif // _ROM_RTW_CORE_H_
