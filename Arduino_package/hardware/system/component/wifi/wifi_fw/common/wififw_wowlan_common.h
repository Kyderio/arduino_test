#ifndef __WIFIFW_WOWLAN_COMMON_H__
#define __WIFIFW_WOWLAN_COMMON_H__

/*--------------------Define MACRO--------------------------------------*/
//3 wowlan rx used type

#define Rx_DeAuth_DisAssoc						0x08
#define Rx_ArpRequest							0x09
#define FWDecisionDisconnect					0x10
#define Rx_UnicastPkt							0x22
#define Rx_Unicast_ACTION						0x23
#define Rx_TCP									0x24
#define Rx_UDP									0x25
#define Rx_ICMP									0x26
#define Rx_ArpRsp								0x27
#define Rx_EapolKey							0x28
#define BCNModeBad_WakeUp					0x29
#define BroadDHCP_Match						0x56
#define TWT_NO_CLIENT_ENABLE				0x57
#define FW_TUNNEL							0x58

#define DEFAULT_KEEP_ALIVE_COUNT_LIMIT		0x14    /*Unit: BCN interval*/
#define ARP_RSP_LOCK_INTERVAL				(10000000)//10s

#define ProtectedFrame							BIT6

#define ARP_SEL_PASSIVE_RESPONSE				0
#define ARP_SEL_KEEPALIVE_UNICAST_GATEWAY		1
#define ARP_SEL_KEEPALIVE_GRATUITOUS_ARP		2

#define KEEPALIVE_TYPE_NULLDATA				0
#define KEEPALIVE_TYPE_ARP_RESPONSE			1

#define ARP_OPERATION_REQUEST					1
#define ARP_OPERATION_RESPONSE					2

#define LLC_LEN 									8
#define SEQ_OFFSET									22
#define IP6_HEADER_LEN								40
#define IPV6_NOT_SUPPORT							0xff

/*--------------------Define Enum---------------------------------------*/
enum ETHER_TYPE {
	TYPE_IPV4 = 0x0800,
	TYPE_ARP = 0x0806,
	TYPE_IPV6 = 0x86DD,
	TYPE_EAPOverLAN = 0x888E,
};

enum IP_TYPE {
	TYPE_ICMP = 1,
	TYPE_TCP = 6,
	TYPE_UDP = 17,
};

enum IPV6ExtentionHeader {
	TPV6_HopByHop = 0,
	IPV6_TCP = 6,
	IPV6_UDP = 17,
	IPV6_Encaps = 41,
	IPV6_Routing = 43,
	IPV6_Fragment = 44,
	IPV6_ESP = 50,
	IPV6_AH = 51,
	IPV6_ICMP6 = 58,
	IPV6_NoNextHeader = 59,
	IPV6_DestinationOption = 60,
	IPV6_UDPLite = 136,
};

enum WIFI_FRAME_TYPE {
	WIFI_MGT_TYPE  = (0),
	WIFI_CTRL_TYPE = (BIT2),
	WIFI_DATA_TYPE = (BIT3),
};

enum WIFI_FRAME_TYPESUBTYPE {
	// below is for mgt frame
	WIFI_BEACON         = (BIT7 | WIFI_MGT_TYPE),
	WIFI_DISASSOC       = (BIT7 | BIT5 | WIFI_MGT_TYPE),
	WIFI_DEAUTH         = (BIT7 | BIT6 | WIFI_MGT_TYPE),
	WIFI_ACTION         = (BIT7 | BIT6 | BIT4 | WIFI_MGT_TYPE),

	//new for ax add 211022 david
	WIFI_TRIGGER				= (BIT5 | WIFI_CTRL_TYPE),
	WIFI_NDP_ANCMT			= (BIT6 | BIT4 | WIFI_CTRL_TYPE),

	// below is for data frame
	WIFI_DATA           = (0 | WIFI_DATA_TYPE),
	WIFI_DATA_NULL      = (BIT6 | WIFI_DATA_TYPE),
	WIFI_QOS_DATA       = (BIT7 | WIFI_DATA_TYPE),
	WIFI_QOS_NULL       = (BIT7 | BIT6 | WIFI_DATA_TYPE),
};

enum RT_ENC_ALG {
	NO_Encryption				= 0,
	WEP40_Encryption  		= 1,
	TKIP_Encryption   		= 2,
	Reserved_Encryption  	= 3,
	AESCCMP_Encryption  		= 4,
	WEP104_Encryption  		= 5,
};

/*--------------------Define Struct---------------------------------------*/


struct Keep_Alive_Parm {
	u8		DelayKeepalive: 1;
	u8		ARPType: 2;
	u8		keepalive_log_en: 1;
	u8		KeepaliveTxFail: 1;
	u8		rsvd: 3;

	u8		KeepAliveCountLimit;
} ;

struct WoWlan_Parm {
#if CONFIG_CONSTANT_ARPREQ_POWERSAVE_PATCH
	u32 	Lock_Arprsp_TSF_H;
	u32 	Lock_Arprsp_TSF_L;
#endif
	u16 	RXFF_BNDY;
	u16		DisconnectCountLmt;
	u16		DisconnectCount;
	u8 		DisconnectEN: 1;
	u8		rsvd1: 7;

	u8		MACAddr[6];
	u8		BSSIDAddr[6];
#if CONFIG_CONSTANT_ARPREQ_POWERSAVE_PATCH
	u8		Last_Arp_Requester[6];
#endif
	u8		TryPKTCount;
	u8		BCNCount;
};

struct AOAC_REPORT {
	u8   pPTKTXIV[8];
	u8   u1SecurityType;         //per received packet
};

struct ARP_INFO {
	u8		A3Addr[6];/*gateway's address*/
	u8		IPV4[4];
	u8		THA[6];
	u8 		TPA[4];
} ;

struct AOAC_INFO {
	struct ARP_INFO    ARPInfo;
	struct AOAC_REPORT AOACReport;
} ;
/*------------------------------Function declaration--------------------------*/
extern const char *TAG_FW_WOW;

extern void wififw_wowlan_parm_init(void);
extern u16 wififw_wowlan_get_aid(void);
extern void wififw_wowlan_rxpkt_release(u16 RPtr);
extern u16 wififw_wowlan_page_offset_align(u16 offset);
extern void wififw_wowlan_get_arp_info(void);
extern void wififw_wowlan_on_arp(u16 addrl_frame_ctrl, u8 MacHeaderLen);
extern void wififw_wowlan_get_addr(void);
extern void wififw_wowlan_iv_increase(u8 *iv, u8 len);
extern void wififw_wowlan_aes_tkip_iv_fun(u8 *pattrib_iv, u8 SecurityType);
extern void wififw_wowlan_wep_iv_fun(unsigned char *iv);
extern void wififw_wowlan_iv_to_keyrsc(u8 *pattrib_iv, u8 *KeyRsc, u8 *KeyID, u8 SecurityType);
extern void wififw_wowlan_keyrsc_to_iv(u8 *pattrib_iv, u8 *KeyRsc, u8 SecurityType);
extern u8 wififw_wowlan_get_ivlen(u8 raaddr);
extern u8 wififw_wowlan_get_mac_header_len(u8 macheader, u8 FrameCtrl, u8 ivLen);
extern void wififw_wowlan_update_iv(u8 *buf, u8 MACHeaderLen, u8 IVLen);
extern void wififw_txpkt_arp(u8 bPowerBit, u8 *TargetIP, u8 *TargetMAC, u8  arpsel, u8 TxInd);
extern u8 wififw_wowlan_destination_match(u16 addrl_frame_ctrl);
extern u8 wififw_wowlan_read_rxbuff(u16 headaddr, u8 offset);
extern void wififw_wowlan_rxpkt_handle(void);
extern void wififw_wowlan_set_arp_rsp_lock_info(void);
extern bool wififw_wowlan_arp_rsp_lock(void);
extern void wififw_disconchk(void);
extern void wififw_disconchk_txnullchk(u8 null_result);
extern void wififw_h2c_wowlan(struct h2c_wowlan *pbuf);
extern void wififw_wowlan_enable_bit(u8 on);
extern u8 wififw_wowlan_get_rxbuf_pkt_num(void);
extern void wififw_rxdone_imr_enable(u8 on);
extern void wififw_periodcca_en_update(void);
extern u16 wififw_wowlan_get_rxpktbuf_boundy(void);
extern u8 wififw_wowlan_get_phyinfo_offset(u16 head_packet);
extern u16 wififw_wowlan_get_rxpktbuf_rptr(void);
#endif  /* #ifndef   __WIFIFW_WOWLAN_COMMON_H__ */

