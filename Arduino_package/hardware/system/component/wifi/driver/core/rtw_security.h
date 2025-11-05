/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef __RTW_SECURITY_H_
#define __RTW_SECURITY_H_


/* 802.11W use wrong key */
#define IEEE80211W_RIGHT_KEY	0x0
#define IEEE80211W_WRONG_KEY	0x1
#define IEEE80211W_NO_KEY		0x2

#define is_wep_enc(alg) (((alg) == _WEP40_) || ((alg) == _WEP104_))

#define AES_BLOCK_SIZE 16

#define RTW_KEK_LEN 16
#define RTW_KCK_LEN 16
#define RTW_TKIP_MIC_LEN 8

/* Flags for encoding (along with the token) */
#define RTW_ENCODE_TEMP		0x0400  /* Temporary key */

struct security_priv {
	union Keytype_32	dot11_wpa_grpkey[1];	// 802.1x Group Key, for inx0 and inx1
	union Keytype	dot11_tkip_grpmickey_tx[1];
	union Keytype	dot11_tkip_grpmickey_rx[1];
	union Keytype   dot11_wep_key[1];			// this is only valid for def. key
	union Keytype_32	dot11w_bipkey[1];		/* BIP Key, for index4 and index5 */
	union pn48		dot11_wpa_grpkey_rxpn[2];			// PN48 used for Grp Key recv. NumGroupKey: 4.
	union pn48		dot11wBIPtxpn;			/* PN48 used for BIP xmit. */

	u32 dot11PrivacyAlgrthm;	// This specify the privacy for shared auth. algorithm.
	/* WEP */
	u32 dot118021XGrpPrivacy;	// This specify the privacy algthm. used for Grp key
	u32 AuthKeyMgmt;	// This specify the auth key algthm. used for 11w


	//keeps the auth_type & enc_status from upper layer ioctl(wpa_supplicant or wzc)
	u32 dot11_wpa_mode;	// NDIS_802_11_AUTHENTICATION_MODE
	u32 wep_grp_key_index;	// this is only valid for legendary wep, 0~3 for key id.
	u32 dot11_wpa_mode_force;
	u32 doc11_iv;

	//extend security capabilities for AP_MODE
	u32 wpa_psk;//0:disable, bit(0): WPA, bit(1):WPA2
	u32 wpa_group_cipher;
	u32 wpa2_group_cipher;
	u32 wpa_pairwise_cipher;
	u32 wpa2_pairwise_cipher;

	u8	  *supplicant_ie;  //store sta security information element
	u8	  rsnxe_ie[RSNXE_MAX_LEN];

	u8	  ieee80211w;//11w capability
	u8    wpa_passphrase[RTW_MAX_PSK_LEN + 1];
	u8    dot11_wep_key_index;	// this is only valid for legendary wep, 0~3 for key id. (tx key index)
	u8    dot11_wep_keylen[1];
	u8    dot11_wpa_grpkey_index; 	// key id used for Grp Key ( tx key index)
	u8    dot11w_bipkey_id; 					/* key id used for BIP Key ( tx key index) */

	u8    b_dot11_use_shared_key: 1;
	u8	  b_installBIPkey: 1;
	u8    b_h2e: 1;
	u8	  b_installGrpkey: 1;
	u8	  b_usetkipkey: 1;
	u8	  b_sw_encrypt: 1;
	u8    b_hw_decrypted: 1; //if the rx packets is b_hw_decrypted==FALSE, it means the hw has not been ready.
	u8	  b_wps_phase: 1;
	u8	  b_wps_disable_wpa3: 1; // if connection is establishing/ed by WPS, should set to TRUE to avoid apply SAE auth
	u8	  b_eap_phase: 1;
	u8    b_external_sae_ongoing: 1;
	u8    b_pmk_cache_enable: 1;
	u8    b_wep_enable : 1;
	u8    b_grpkey_rxpn_cur_index: 1;
	u8    b_need_host_indicate_psk_done: 1; /* For RTOS architecture: Set to TRUE to signal NP should start auth/assoc after AP sets PSK info */
	u32		rom_rsvd;

};

#define GET_ENCRY_ALGO(psecuritypriv, psta_security, encry_algo, bmcst)\
do{\
	if ((psecuritypriv)->dot11_wpa_mode) {\
		if(bmcst)\
				encry_algo = (u8)(psecuritypriv)->dot118021XGrpPrivacy;\
			else\
				encry_algo =(u8) (psta_security)->dot11_security_privacy;\
			break;\
	} else {\
		encry_algo = (u8)(psecuritypriv)->dot11PrivacyAlgrthm;\
	}\
}while(0)


#define SET_ICE_IV_LEN( iv_len, icv_len, encrypt)\
do{\
	switch(encrypt)\
	{\
		case _WEP40_:\
		case _WEP104_:\
			iv_len = 4;\
			icv_len = 4;\
			break;\
		case _TKIP_:\
			iv_len = 8;\
			icv_len = 4;\
			break;\
		case _AES_:\
			iv_len = 8;\
			icv_len = 8;\
			break;\
		case _GCMP_256_:\
			iv_len = 8;\
			icv_len = 16;\
			break;\
		case _SMS4_:\
			iv_len = 18;\
			icv_len = 16;\
			break;\
		default:\
			iv_len = 0;\
			icv_len = 0;\
			break;\
	}\
}while(0)


extern const u32 Te0[256];
extern const u32 Te1[256];
extern const u32 Te2[256];
extern const u32 Te3[256];
extern const u32 Te4[256];
extern const u32 Td0[256];
extern const u32 Td1[256];
extern const u32 Td2[256];
extern const u32 Td3[256];
extern const u32 Td4[256];
extern const u32 rcon[10];
extern const u8 Td4s[256];
extern const u8 rcons[10];

#define RCON(i) (rcons[(i)] << 24)

static inline u32 rotr(u32 val, int bits)
{
	return (val >> bits) | (val << (32 - bits));
}

#define TE0(i) Te0[((i) >> 24) & 0xff]
#define TE1(i) rotr(Te0[((i) >> 16) & 0xff], 8)
#define TE2(i) rotr(Te0[((i) >> 8) & 0xff], 16)
#define TE3(i) rotr(Te0[(i) & 0xff], 24)
#define TE41(i) ((Te0[((i) >> 24) & 0xff] << 8) & 0xff000000)
#define TE42(i) (Te0[((i) >> 16) & 0xff] & 0x00ff0000)
#define TE43(i) (Te0[((i) >> 8) & 0xff] & 0x0000ff00)
#define TE44(i) ((Te0[(i) & 0xff] >> 8) & 0x000000ff)
#define TE4(i) ((Te0[(i)] >> 8) & 0x000000ff)

#define TD0(i) Td0[((i) >> 24) & 0xff]
#define TD1(i) rotr(Td0[((i) >> 16) & 0xff], 8)
#define TD2(i) rotr(Td0[((i) >> 8) & 0xff], 16)
#define TD3(i) rotr(Td0[(i) & 0xff], 24)



#endif	//__RTL871X_SECURITY_H_

