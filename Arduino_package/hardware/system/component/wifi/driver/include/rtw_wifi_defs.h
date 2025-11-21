/**
  ******************************************************************************
  * @file    rtw_wifi_defs.h
  * @author
  * @version
  * @date
  * @brief
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef	__RTW_WIFI_DEFS_H_
#define __RTW_WIFI_DEFS_H_

#define _WEAK           __attribute__ ((weak))

/** @defgroup WIFI_Exported_Constants WIFI Exported Constants
  * @{
  */

/** @defgroup WLAN_Defs
   *@{
   */
#define IsSupported24G(band_type) ((band_type) & RTW_SUPPORT_BAND_2_4G? TRUE : FALSE)
#define IsSupported5G(band_type) ((band_type) & RTW_SUPPORT_BAND_5G ?  TRUE : FALSE)

#define IsLegacyOnly(NetType)  ((NetType) == ((NetType) & (RTW_80211_BG | RTW_80211_A)))

#define IsSupportedTxOFDM(NetType) ((NetType) & (RTW_80211_G | RTW_80211_A) ? TRUE : FALSE)

#define is_supported_ht(NetType) ((NetType) & (RTW_80211_N) ? TRUE : FALSE)
#define is_supported_vht(NetType) ((NetType) & (RTW_80211_AC) ? TRUE : FALSE)
#define is_supported_he(NetType) ((NetType) & (RTW_80211_AX) ? TRUE : FALSE)

#define IS_HT_RATE(_rate)				(((_rate) & 0x80) ? TRUE : FALSE)
#define IS_CCK_RATE(_rate) 				(RTW_RATE_1M == _rate || _rate == RTW_RATE_2M || _rate == RTW_RATE_5_5M || _rate == RTW_RATE_11M )
#define IS_OFDM_RATE(_rate)				(RTW_RATE_6M <= _rate && _rate <= RTW_RATE_54M )

#define is_broadcast_mac_addr(Addr) ((((Addr[0]) & 0xff) == 0xff) && (((Addr[1]) & 0xff) == 0xff) && \
(((Addr[2]) & 0xff) == 0xff) && (((Addr[3]) & 0xff) == 0xff) && (((Addr[4]) & 0xff) == 0xff) && \
(((Addr[5]) & 0xff) == 0xff))
#define is_zero_mac_addr(Addr)	((Addr[0] == 0x00) && (Addr[1] == 0x00) && (Addr[2] == 0x00) &&   \
                    (Addr[3] == 0x00) && (Addr[4] == 0x00) && (Addr[5] == 0x00))

/**
  * @}
  */


/** @defgroup Security_Defs
   *@{
   */
#define AUTH_ALG_OPEN_SYSTEM	0x1
#define AUTH_ALG_SHARED_KEY	0x2
#define AUTH_ALG_SAE		0x8
#define AUTH_ALG_LEAP		0x00000004

#define MCSSET_LEN		16		/**<mcsset length */

/* adaptivity */
#define RTW_ADAPTIVITY_EN_DISABLE			0
#define RTW_ADAPTIVITY_EN_ENABLE			1

/**
  * @}
  */

/** @defgroup Packet_Defs
   *@{
   */
#define	PACKET_NORMAL			0
#define	PACKET_DHCP			1
#define	PACKET_ARP			2
#define	PACKET_EAPOL			3

/**
  * @}
  */


/** @defgroup WPA_MODE_CHECK_Defs
   *@{
   */
#define WPA2_MODE_CHECK(wpa_mode) ((wpa_mode == RTW_WPA_AUTO_MODE) || (wpa_mode == RTW_WPA2_ONLY_MODE) || (wpa_mode == RTW_WPA3_ONLY_MODE) || \
									(wpa_mode == RTW_WPA_WPA2_MIXED_MODE) || (wpa_mode == RTW_WPA2_WPA3_MIXED_MODE))
#define WPA_MODE_CHECK(wpa_mode) ((wpa_mode == RTW_WPA_AUTO_MODE) ||(wpa_mode == RTW_WPA_ONLY_MODE) ||(wpa_mode == RTW_WPA_WPA2_MIXED_MODE))

/**
  * @}
  */


/**
  * @}
  */

/** @defgroup WIFI_Exported_Types WIFI Exported Types
* @{
*/

/** @addtogroup Enums
   *@{
   */

/* For freertos, core, hal, rf, halbb. */
enum phl_phy_idx {
	HW_PHY_0,
	HW_PHY_1,
	HW_PHY_MAX
};

/**
  * @brief Power Mgnt
  */
enum rtw_power_mgnt_mode {
	RTW_PS_MODE_ACTIVE	= 0	, ///< active mode
	RTW_PS_MODE_LEGACY		,       ///< legacy mode
	RTW_PS_MODE_UAPSD_WMM	, ///< uapsd wmm mode
	RTW_PS_MODE_WTNPS	, ///< wtn ps mode
};

/**
  * @}
  */

/**
  * @}
  */

#endif
