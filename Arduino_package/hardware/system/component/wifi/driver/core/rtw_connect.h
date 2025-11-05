#ifndef __RTW_CONNECT_H_
#define __RTW_CONNECT_H_

/*-------------------------------------------------------------------------------
	AP and STA Both Related Connection.
--------------------------------------------------------------------------------*/
#define AUTH_TIMEOUT		3
#define ASSOC_TIMEOUT		3
#define EXPIRE_TIMEOUT		60		/* 60*2 = 120 sec = 2 min, expire after no any traffic. */

enum _RT_MEDIA_STATUS {
	RT_MEDIA_DISCONNECT = 0,
	RT_MEDIA_CONNECT = 1
};

static inline u16 rtw_get_capability(struct	wlan_network *pwlan_network)
{
	u16	val;

	memcpy((u8 *)&val, rtw_get_capability_from_ie(pwlan_network->IEs), 2);
	return val;
}


/*-------------------------------------------------------------------------------
	AP Related Connection.
--------------------------------------------------------------------------------*/

#define DEL_STA_MAC_ID		0x7F

/*
Used to report a given STA has joinned the created BSS.
It is used in AP mode.
*/
struct stassoc_event {
	unsigned char		macaddr[6];
	unsigned char		rsvd[2];
	int			cam_id;
};

struct stadel_event {
	unsigned char		macaddr[6];
	unsigned char		rsvd[2];	/* for reason */
	int			mac_id;
};

struct free_sta_event {
	struct sta_mlme_priv *psta_mlmepriv;
};

/*-------------------------------------------------------------------------------
	STA Related Connection.
--------------------------------------------------------------------------------*/
#define TRANSITION_DISABLE_WPA3_PERSONAL	BIT(0)
#define TRANSITION_DISABLE_SAE_PK		BIT(1)
#define TRANSITION_DISABLE_WPA3_ENTERPRISE	BIT(2)
#define TRANSITION_DISABLE_ENHANCED_OPEN	BIT(3)

#ifdef CONFIG_SUPPLICANT_SME
#define MAX_CNT_AUTH_TIMES			(0)
#else
#define MAX_CNT_AUTH_TIMES			(3) //Max connect times in case of receiving deauth/deassoc during auth&&assoc procedure and not reporting disconnect event
#endif

enum {
	RTW_MLME_PREPARE_JOIN = 0,
	RTW_MLME_JOIN_FAIL = 1,
	RTW_MLME_JOIN_SUCCESS = 2,
	RTW_MLME_MCC_JOIN_SUCCESS = 3,
};

#endif // __RTW_CONNECT_H_