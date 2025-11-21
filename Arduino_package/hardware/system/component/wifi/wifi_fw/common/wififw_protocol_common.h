#ifndef _WIFIFW_PROTOCOL_COMMON_H_
#define _WIFIFW_PROTOCOL_COMMON_H_

//  below is MAC Header offset
#define MAC_ADRESS1_OFFSET  4
#define MAC_ADRESS2_OFFSET 10
#define MAC_ADRESS3_OFFSET 16
#define LENGTH_IEEE80211_HDR_3ADDR	24
#define BCN_FIX_IE_LENGTH           12
#define BCN_DS_IE_ID                3

/*-----------------------------------------------------------------------------
                Below is the definition for 802.11i / 802.1x
------------------------------------------------------------------------------*/
#define _WIFI_NO_PRIVACY_       0
#define _WEP_40_PRIVACY_        1
#define _TKIP_PRIVACY_          2
#define _WRAP_PRIVACY_          3
#define _CCMP_PRIVACY_          4
#define _WEP_104_PRIVACY_       5
#define _WEP_WPA_MIXED_PRIVACY_ 6   // WEP + WPA
#define _WAPI_SMS4_             7

struct MAC_HEADER {
	// Offset 0
	u16 protocol_version: 		2;
	u16 type: 					2;
	u16 subtype: 				4;

	u16 toDS: 					1;
	u16 fromDS: 				1;
	u16 more_fragments: 		1;
	u16 retry: 					1;
	u16 power_management: 		1;
	u16 more_data: 				1;
	u16 protected_frame: 		1;
	u16 order: 					1;

	// Offset 2
	u16 duration;

	// Offset 4
	u8 da[6];
	u8 sa[6];
	u8 bssid[6];
	u16 seq_ctrl;
} ;

#endif  //_WIFIFW_PROTOCOL_COMMON_H_