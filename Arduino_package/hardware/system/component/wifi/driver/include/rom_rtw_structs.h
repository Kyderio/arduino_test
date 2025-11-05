#ifndef __ROM_RTW_STRUCTS_H_
#define __ROM_RTW_STRUCTS_H_

#define PHY_SIGNAL_SLID_WIN_MAX			10

/* Fasten in ROM CODE, revise cautiously. */
struct _RT_CHANNEL_PLAN_MAP {
	unsigned char	ChannelPlan;
	unsigned char	Index2G;
	unsigned char	Index5G;
	unsigned char	PwrLmt;
};

struct _RT_CHANNEL_PLAN_2G {
	unsigned char	Channel[MAX_CHANNEL_NUM_2G];
	unsigned char	Len;
};

struct _RT_CHANNEL_PLAN_5G {
	unsigned char	Channel[MAX_CHANNEL_NUM_5G];
	unsigned char	Len;
};

struct channel_set_bitmap {	//use one channel_set_bitmap for each channel group (see enum channel_group)
	u16		chan_bitmap;	//use each bit to indicate whether a channel is included in this channel set, 1 for included, 0 for not included
	u16		passive_bitmap;	//use each bit to indicate whether a channel needs passive scan, 1 for passive, 0 for active
};

struct channel_set_bitmap_with_size {
	struct channel_set_bitmap set;
	int size;
};

struct wps_priv {
	uint8_t *wps_probe_req_ie;
	uint16_t wps_probe_req_ie_len;
	uint8_t *wps_assoc_req_ie;
	uint16_t wps_assoc_req_ie_len;

	uint8_t *wps_beacon_ie;
	uint8_t *wps_probe_resp_ie;
	uint8_t *wps_assoc_resp_ie; // for CONFIG_IOCTL_CFG80211, this IE could include p2p ie

	uint16_t wps_beacon_ie_len;
	uint16_t wps_probe_resp_ie_len;
	uint16_t wps_assoc_resp_ie_len;

	uint32_t rom_rsvd;
};

struct init_chset_parms {
	u8	band_type_support;
	u8	ChannelPlan;
};

struct update_mode_parms {
	u8	*SupportedRates;
	u8	HT_info_enable;
	u8	HT_caps_enable;
	u8	cur_channel;
	u8	he_option;
	u8	*pHT_enable;
	u8	*pcur_wireless_mode;
	u8	wireless_mode_support;
	u8	*puser_tx_rate;
	u8 ht_enable;
	u8	*cur_ch_offset;
	u8 ht_option;
	u8 qos_option;
};

struct security_ie_set {
	u8 *supplicant_ie;
	u8 *rsnxe_ie;
	u8 *pmkid;
	u8 h2e;
	u32 dot11_wpa_mode;
};

struct fill_wlan_hdr_parms {
	u8	*pstart;
	u8	*paddr1;
	u8	*paddr2;
	u8	*paddr3;
	u16	frame_ctl;
	u16	*pseq;
	u16	frame_subtype;
	u16	*phdrlen;
	u32	*ppktlen;
};

struct bcn_info_param {
	/* these infor get from rtw_get_encrypt_info when
	 * 	 * translate scan to UI */
	u8	encryp_protocol;	//ENCRYP_PROTOCOL_E: OPEN/WEP/WPA/WPA2/WAPI
	int	group_cipher;		//WPA/WPA2 group cipher
	int	pairwise_cipher;	//WPA/WPA2/WEP pairwise cipher
	int	is_8021x;
	u8 rsvd;

	/* bwmode 20/40 and ch_offset UP/LOW */
	unsigned short 	ht_cap_info;
	unsigned char	ht_info_infos_0;

	/* Some significant parameters inside beacon IE. If these Element-IEs in beacon changed, need reconnect immediately. Refer to CMW500 Signalling Test. */
	/* BIT(0): DS Parameter set - b, g. */
	/* BIT(1): ERP Information - g. */
	/* BIT(2): HT Capabilities - gn, ofdm. */
	/* BIT(3): VHT Capabilities - ac. */
	/* BIT(4): EXT HE Capabilites - ax. */
	u8 mode_change;

	u8 rsn_valid: 1;	// for spp valid value in thr past, ot be uesd now, and keep it.
	u8 spp_valid;  // for spp valid value
	u32 iebuf_len; // not be uesd now, and keep it.
	u16	rom_rsvd;
};

struct network_param {
	u32	*BeaconPeriod;
	u8 *Ssid;
	u32  *SsidLength;
	u32           *DSConfig;
	unsigned char *SupportedRates;
	u32 *Privacy;
	u8 *IEs;
	u32 IELength;
};

struct securitypriv_parms {
	u32 *dot11PrivacyAlgrthm;
	u32 *dot11_wpa_mode;
	u32 *dot118021XGrpPrivacy;
	u32 *AuthKeyMgmt;
	u8 *ieee80211w;
	u32 *parm_wep_enable;
	u32 *dot11_use_wpax;	//useless, but this structure is used by rom code, cannot delete

	u32 *wpa_psk;//0:disable, bit(0): WPA, bit(1):WPA2
	u32 *wpa_group_cipher;
	u32 *wpa2_group_cipher;
	u32 *wpa_pairwise_cipher;
	u32 *wpa2_pairwise_cipher;

	u8 *supplicant_ie;

	unsigned char rtw_cmd_tsk_spt_wap3;
};

struct stainfo_parms {
	uint *parms_qos_option;
	u16 *capability;
	u32 *flags;

	int *wpa_psk;//0:disable, bit(0): WPA, bit(1):WPA2
	int *wpa_group_cipher;

	u8 *qos_info;
	u8 *bssrateset;
	u32	*bssratelen;

	u8 *ht_cap;
	u8 ht_cap_len;
};

struct issue_assoc_req_param {
	struct network_param net_param;

	u8 *supported_rateset;
	u8 rateset_len;
	struct channel_set_bitmap *channel_set;

	u8 cur_channel;
};

struct issue_assoc_req_param_2 {
	struct network_param net_param;
	u8 wps_phase;
	u8 ht_option;
	u8 vht_option;
	u8 he_option;
};


struct on_assoc_req_param {
	struct securitypriv_parms secure_params;
	struct network_param net_param;
	struct stainfo_parms sta_param;
	struct update_mode_parms mode_param;
	struct wps_priv *wpspriv;
};

struct issue_assoc_rsp_param {
	u8 *IEs;
	u32 IELength;
	u8 *bssrateset;
	u32 bssratelen;
	u32 stainfo_flags;
	u8 ht_option;
	u8 qos_option;

	struct wps_priv *wpspriv;
};

struct dot11w_action_params {
	unsigned char *ra;
	unsigned char *bssid;
	unsigned char *sa;
	u16 *mgnt_seq;
	u32 *pktlen;
	unsigned char action;
	unsigned short tid;
	u16	*sa_query_seq;
};

struct smooth_signal_stat {
	s32	total_num;		//num of valid elements
	s32	total_val;		//sum of valid elements
};

struct joinbss_ie_param {
	unsigned char rtw_802_11d_en;
	unsigned char lps_enable;
	unsigned char lps_mode;
	unsigned char uapsd_max_sp_len;
	unsigned char uapsd_ac_enable;
};

struct on_auth_param {
	struct sta_mlme_priv *psta_mlmepriv;
	unsigned char *sa;
	int status;
	u16 seq;
	u16 algorithm;
};
#endif //__ROM_RTW_STRUCTS_H_
