/**
  ******************************************************************************
  * @file    wpa_80211spec_kvr.h
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

#ifndef	__RTW_80211SPEC_KVR_H_
#define __RTW_80211SPEC_KVR_H_

#define FTIE_SUBELEM_R1KH_ID 1
#define FTIE_SUBELEM_GTK 2
#define FTIE_SUBELEM_R0KH_ID 3

#define MOBILITY_DOMAIN_ID_LEN 2
#define FT_R0KH_ID_MAX_LEN 48
#define FT_R1KH_ID_LEN 6
#define WPA_PMK_NAME_LEN 16
#define KEY_NONCE_LEN		32

#define NB_RPT_ELEM_ID	0x34
/* BSS Transition Candidate Preference */
#define WNM_BTM_CAND_PREF_SUBEID 0x03

/*IEEE Std 80211k Figure 7-95b Neighbor Report element format*/
struct nb_rpt_hdr {
	u8 id; /*0x34: Neighbor Report Element ID*/
	u8 len;
	u8 bssid[ETH_ALEN];
	u32 bss_info;
	u8 reg_class;
	u8 ch_num;
	u8 phy_type;
};

/*IEEE Std 80211v, Figure 7-10 BSS Transition Management Request frame body format */
struct btm_req_hdr {
	u8 dialog_token;
	u8 req_mode;
	/* number of TBTTs until the BSS transition candidate list is no longer valid */
	u8 validity_interval;
};
struct ft_ftie {
	u8 mic_control[2];
	u8 mic[16];
	u8 anonce[KEY_NONCE_LEN];
	u8 snonce[KEY_NONCE_LEN];
	/* followed by optional parameters */
};
struct ft_mdie {
	u8 mobility_domain[MOBILITY_DOMAIN_ID_LEN];
	u8 ft_capab;
};

#endif

