#ifndef REALTEK_VENDOR_H
#define REALTEK_VENDOR_H

#define OUI_REALTEK    0x00E04C

enum rtk_nl80211_vendor_events {
	RTK_VENDOR_SCMD_UNSPEC		= 0,
	RTK_VENDOR_SCMD_PASN_START	= 29,
	RTK_VENDOR_SCMD_PASN_RX		= 30,
	RTK_VENDOR_SCMD_PASN_UPD_PMKID	= 31
};

/*
 * @RTK_NL80211_VENDOR_SUBCMD_PASN_NAN_SET_KEY: Set key operation that can be
 *	used to configure NM-TK and NM-KDK to the driver even when not connected.
 *      xxxxx This can
 *	be used to request offloading of key management operations. Only used
 *	if device supports RTK_NL80211_VENDOR_SUBCMD_PASN_NAN_SET_KEY.
 */
enum rtk_nl80211_vendor_subcmds {
	/* pasn nan */
	RTK_NL80211_VENDOR_SUBCMD_PASN_NAN_SET_KEY = 0x1909,
};

enum rtk_wlan_vendor_attr_nan_pasn_trigger {
	RTK_WLAN_VENDOR_ATTR_NAN_PASN_TYPE = 0,
	RTK_WLAN_VENDOR_ATTR_NAN_PASN_PEER_NMI = 1,
	RTK_WLAN_VENDOR_ATTR_NAN_PASN_SETUP_PARA_AUTH_METHOD = 2,
	RTK_WLAN_VENDOR_ATTR_NAN_PASN_SETUP_PARA_NIK_CACHING = 3,
	RTK_WLAN_VENDOR_ATTR_NAN_PASN_SETUP_PARA_PASSPHRASE = 4,

	/* keep last */
	RTK_WLAN_VENDOR_ATTR_NAN_PASN_AFTER_LAST,
	RTK_WLAN_VENDOR_ATTR_NAN_PASN_MAX =
	RTK_WLAN_VENDOR_ATTR_NAN_PASN_AFTER_LAST - 1
};

#define NAN_PMKID_LEN		(16)
#define MAX_PASSPHRASE_LEN	(16)
#define MAX_PASN_RX_LEN		(512)
#define MAX_PASN_NAN_APPEND_IE_LEN   (64)

struct rtk_nan_pasn_start {
	u8 deinit;
	u8 role;
	u8 pairing_type;
	u8 peer_nmi[ETH_ALEN];
	u8 bssid[ETH_ALEN];
	u8 setup_para_auth_method;
	u8 setup_para_nik_caching;
	u8 setup_para_passphrase_len;
	char setup_para_passphrase[MAX_PASSPHRASE_LEN];
	u16 auth_frame_len;
	u8 auth_frame[MAX_PASN_RX_LEN];
	u8 append_nan_attr_len;
	u8 append_nan_attr[MAX_PASN_NAN_APPEND_IE_LEN];
	u8 own_pmkid[NAN_PMKID_LEN];
	u8 peer_pmkid[NAN_PMKID_LEN];
}__attribute__ ((packed));

struct rtk_nan_pasn_rx {
	u8 seq;
	u8 pairing_type;
	u8 passphrase_len;
	char passphrase[MAX_PASSPHRASE_LEN];
	u16 auth_frame_len;
	u8 auth_frame[MAX_PASN_RX_LEN];
	u8 append_nan_attr_len;
	u8 append_nan_attr[MAX_PASN_NAN_APPEND_IE_LEN];
}__attribute__ ((packed));

struct rtk_nan_pasn_upd_pmkid {
	u8 role;
	u8 status;
	u8 peer_nmi[ETH_ALEN];
	u8 peer_pmkid[NAN_PMKID_LEN];
	u8 auth_method;
}__attribute__ ((packed));
#endif /* REALTEK_VENDOR_H */
