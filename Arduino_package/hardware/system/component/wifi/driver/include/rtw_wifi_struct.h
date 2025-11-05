#ifndef __RTW_WIFI_STRUCT_H_
#define __RTW_WIFI_STRUCT_H_

enum _NDIS_802_11_NETWORK_INFRASTRUCTURE {
	Ndis802_11Infrastructure,
	Ndis802_11AutoUnknown,
	Ndis802_11APMode,
};

struct _NDIS_802_11_CONFIGURATION {
	u32 		  DSConfig; 		  // Frequency, units are kHz
};

RTW_PACK_STRUCT_BEGIN
struct _WLAN_PHY_INFO {

} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

//#ifdef CONFIG_MBSSID_AX

#define MAX_VIRTUAL_AP_NUM	8
struct mbssid_virtual_ap_info_t {
	u8					bssid_idx;	// from bssid-index ie
	struct dot11_ssid	Ssid;		//from ssid ie
};

struct mbssid_info {
	struct mbssid_virtual_ap_info_t virtual_ap_info[MAX_VIRTUAL_AP_NUM];	// store non-transmitted BSSID profile
	u8 *mbssid_ie;		//start with non-transmitted BSSID profile
	u8 bssid_max;		//max_bssid_indicator
	u8 bssid_ref[6];		// transmitted-BSSID
	u8 virtual_ap_num;	// num of non-transmitted BSSID
	u8 bssid_idx_to_join;	//bssid index of non-transmitted BSSID to join
	u8 dynamic_alloc: 1;
} ;

//#endif

struct	wlan_network {
	struct dot11_ssid			Ssid;

	long			Rssi;			//(in dBM,raw data ,get from PHY)
	int				softap_wireless_mode;	//refer to ieee80211.h for WIRELESS_11A/B/G
	int				aid;			//will only be valid when a BSS is joinned.
	u32				Privacy;
	u32				last_scanned; //timestamp for the network
	int				mbo_assoc_disallow;

	u32				BeaconPeriod; 	  // units are Kusec
	u32				DSConfig; 		  // network channel, different from the operating RF channel, generally consistent
	u32				IELength;

	u8				MacAddress[6];
	u8				SupportedRates[WLAN_RATES_EX_MAXLEN];
	u8				CountryCode[2];

	u8				is_beacon;		//[0]: IS beacon frame
	u8				b_softap_ready: 1;
	u8				b_connected_to_mcc_ap: 1; //1: ap to join is rtk mcc softap
	u8				b_WrongChannel: 1;
	u8				b_mbssid_virtual_ap : 1;		// 1: ap to join is non-transmitted
	u8				b_mbssid_enable: 1;	// AP support mbssid
	u8				b_wtn_helper: 1;	// wtn helper
	u32				rom_rsvd;

	u8 				*IEs; 	//(timestamp, beacon interval, and capability information)
	struct mbssid_info	*mbssid_info;
};

struct net_device_stats {
	struct smooth_signal_stat mixed_rssi_stat;
	struct smooth_signal_stat data_rssi_stat;
	struct smooth_signal_stat beacon_rssi_stat;
	struct smooth_signal_stat snr_stat;
	u32	rx_bytes_in2s;				/*!< total bytes received         */
	u32	tx_bytes_in2s;				/*!< total bytes transmitted      */

	u32 rx_tf_cnt; /* rx trigger frame number (accumulated, only reset in disconnect) optimize_tobe_check */

	u32 tx_byte_uni_in2s;/*halbb just print for debug*/
	u32 rx_byte_uni_in2s;/*halbb just print for debug*/

	u32 tx_tp_kbits;/*halbb needs*/
	u32 rx_tp_kbits;/*halbb needs*/

	/* For display the phy informatiom */
	s8 rssi;   //data&beacon rssi
	s8 data_rssi;  //data rssi(except beacon)
	s8 beacon_rssi;  //beacon rssi
	s8 snr;

	u8 tx_tp_mbps;			/*@Mbps*/
	u8 rx_tp_mbps;			/*@Mbps*/
	u8 total_tp_mbps;

	u8 b_is_any_non_be_pkts: 1;

	u16 cur_rx_data_rate; // current rx data rate

	u32 rx_packets;					/*!< total packets received       */
	u32 tx_packets;					/*!< total packets transmitted    */
};

/* ------------------------ iwpriv related ------------------------ */
#undef IFNAMSIZ
#define IFNAMSIZ	16

/*
 *	Generic format for most parameters that fit in an int
 */
struct	rtw_param {
	s32		value;		/* The value of the parameter itself */
	u8		fixed;		/* Hardware should not use auto select */
	u8		disabled;	/* Disable the feature */
	u16		flags;		/* Various specifc flags (if any) */
};

struct	rtw_point {
	void		*pointer;	/* Pointer to the data  (in user space) */
	u16		length;		/* number of fields or size in bytes */
	u16		flags;		/* Optional params */
};

struct	rtw_freq {
	s32		m;		/* Mantissa */
	s16		e;		/* Exponent */
	u8		i;		/* List index (when in range struct) */
	u8		flags;		/* Flags (fixed/auto) */
};


union rtwreq_data {
	/* Config - generic */
	char			name[IFNAMSIZ];	/* Name : used to verify the presence of  wireless extensions. * Name of the protocol/provider... */
	struct rtw_point	essid;		/* Extended network name */
	struct rtw_param	nwid;		/* network id (or domain - the cell) */
	struct rtw_freq		freq;		/* frequency or channel : * 0-1000 = channel * > 1000 = frequency in Hz */
	struct rtw_param	sens;		/* signal level threshold */
	struct rtw_param	snr;		/* signal noise ratio */
	struct rtw_param	bitrate;	/* default bit rate */
	struct rtw_param	txpower;	/* default transmit power */
	struct rtw_param	rts;		/* RTS threshold threshold */
	struct rtw_param	frag;		/* Fragmentation threshold */
	u32			mode;		/* Operation mode */
	struct rtw_param	retry;		/* Retry limits & lifetime */
	struct rtw_point	encoding;	/* Encoding stuff : tokens */
	struct rtw_param	power;		/* PM duration/timeout */
	struct sockaddr_t	ap_addr;	/* Access point address */
	struct sockaddr_t	addr;		/* Destination address (hw/mac) */
	struct rtw_param	param;		/* Other small parameters */
	struct rtw_point	data;		/* Other large parameters */
	struct rtw_point	passphrase;	/* Extended network name */
};

struct rtwreq {
	char		ifr_name[IFNAMSIZ];	/* if name, e.g. "eth0" */
	union		rtwreq_data	u;
};

struct rtw_priv_args {
	u32		cmd;		/* Number of the ioctl to issue */
	char		name[IFNAMSIZ];	/* Name of the extension */
};

struct  transition_disable_ctx {
	u32 AKM_suite; //Secure algorithm (keymgmt)

	u8 ssid_len;      /**< SSID length */
	u8 bitmap; //Transition Disable Bitmap
	u8 ssid[RTW_ESSID_MAX_SIZE + 1]; /**< SSID name (AP name)  */
	u8 mac_addr[6];
};

/**
  * @brief  The structure is used to describe the mac filter list
  */
struct _rtw_mac_filter_list_t {
	struct list_head node;
	unsigned char mac_addr[6];
} ;
#endif
