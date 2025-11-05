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
#ifndef __ROM_IEEE80211_H
#define __ROM_IEEE80211_H

#define WPA_CIPHER_NONE 			BIT(0)
#define WPA_CIPHER_WEP40 			BIT(1)
#define WPA_CIPHER_WEP104 		BIT(2)
#define WPA_CIPHER_TKIP 			BIT(3)
#define WPA_CIPHER_CCMP 			BIT(4)
#define WPA_CIPHER_AES_128_CMAC 	BIT(5)
#define WPA_CIPHER_GCMP 			BIT(6)
#define WPA_CIPHER_SMS4 			BIT(7)
#define WPA_CIPHER_GCMP_256 		BIT(8)
#define WPA_CIPHER_CCMP_256 		BIT(9)
#define WPA_CIPHER_BIP_GMAC_128 	BIT(11)
#define WPA_CIPHER_BIP_GMAC_256 	BIT(12)
#define WPA_CIPHER_BIP_CMAC_256 	BIT(13)
#define WPA_CIPHER_GTK_NOT_USED 	BIT(14)

extern const u8 RTW_WPA_OUI_TYPE[] ;
extern const u8 WPA_CIPHER_SUITE_NONE[];
extern const u8 WPA_CIPHER_SUITE_WEP40[];
extern const u8 WPA_CIPHER_SUITE_TKIP[];
extern const u8 WPA_CIPHER_SUITE_CCMP[];
extern const u8 WPA_CIPHER_SUITE_WEP104[];
extern const u16 RSN_VERSION_BSD;
extern const u8 RSN_AUTH_KEY_MGMT_UNSPEC_802_1X[];
extern const u8 RSN_AUTH_KEY_MGMT_PSK_OVER_802_1X[];
extern const u8 RSN_CIPHER_SUITE_NONE[];
extern const u8 RSN_CIPHER_SUITE_WEP40[];
extern const u8 RSN_CIPHER_SUITE_TKIP[];
extern const u8 RSN_CIPHER_SUITE_CCMP[];
extern const u8 RSN_CIPHER_SUITE_WEP104[];

/* Parsed Information Elements */
struct rtw_ieee802_11_elems {
	u8 *ssid;
	u8 ssid_len;
	u8 *supp_rates;
	u8 supp_rates_len;
	u8 *fh_params;
	u8 fh_params_len;
	u8 *ds_params;
	u8 ds_params_len;
	u8 *cf_params;
	u8 cf_params_len;
	u8 *tim;
	u8 tim_len;
	u8 *ibss_params;
	u8 ibss_params_len;
	u8 *challenge;
	u8 challenge_len;
	u8 *erp_info;
	u8 erp_info_len;
	u8 *ext_supp_rates;
	u8 ext_supp_rates_len;
	u8 *wpa_ie;
	u8 wpa_ie_len;
	u8 *rsn_ie;
	u8 rsn_ie_len;
	u8 *wme;
	u8 wme_len;
	u8 *wme_tspec;
	u8 wme_tspec_len;
	u8 *wps_ie;
	u8 wps_ie_len;
	u8 *power_cap;
	u8 power_cap_len;
	u8 *supp_channels;
	u8 supp_channels_len;
	u8 *mdie;
	u8 mdie_len;
	u8 *ftie;
	u8 ftie_len;
	u8 *timeout_int;
	u8 timeout_int_len;
	u8 *ht_capabilities;
	u8 ht_capabilities_len;
	u8 *ht_operation;
	u8 ht_operation_len;
	u8 *vendor_ht_cap;
	u8 vendor_ht_cap_len;
};

enum ParseRes {
	ParseOK = 0,
	ParseUnknown = 1,
	ParseFailed = -1
};

enum ParseRes rtw_ieee802_11_parse_elems(u8 *start, uint len,
		struct rtw_ieee802_11_elems *elems,
		int show_errors);

u8 *rtw_set_fixed_ie(u8 *pbuf, u32 len, u8 *source, u32 *frlen);
u8 *rtw_set_ie(u8 *pbuf, sint index, u32 len, u8 *source, u32 *frlen);
u8 *rtw_get_ie(u8 *pbuf, sint element_id, u32 *element_len, sint total_len);

void rtw_set_supported_rate(u8 *SupportedRates, uint mode, uint channel);

unsigned char *rtw_get_wpa_ie(unsigned char *pie, u32 *wpa_ie_len, int limit);
unsigned char *rtw_get_wpa2_ie(unsigned char *pie, u32 *rsn_ie_len, int limit);
int rtw_get_wpa_cipher_suite(u8 *s);
int rtw_get_wpa2_cipher_suite(u8 *s);

int rtw_parse_wpa_ie(u8 *wpa_ie, int wpa_ie_len, int *group_cipher, int *pairwise_cipher, int *is_8021x);
int rtw_parse_wpa2_ie(u8 *wpa_ie, int wpa_ie_len, int *group_cipher, int *pairwise_cipher, int *is_8021x);

int rtw_get_sec_ie(u8 *in_ie, uint in_len, u8 *rsn_ie, u16 *rsn_len, u8 *wpa_ie, u16 *wpa_len);

u8 *rtw_get_wps_ie(u8 *in_ie, uint in_len, u8 *wps_ie, uint *wps_ielen);
u8 *rtw_get_wps_attr(u8 *wps_ie, uint wps_ielen, u16 target_attr_id, u8 *buf_attr, u32 *len_attr);
u8 *rtw_get_wps_attr_content(u8 *wps_ie, u32 wps_ielen, u16 target_attr_id, u8 *buf_content, u32 *len_content);

uint rtw_get_rateset_len(u8	*rateset);

int rtw_get_bit_value_from_ieee_value(u8 val);

uint rtw_is_cckrates_included(u8 *rate);

uint rtw_is_cckratesonly_included(u8 *rate);

int rtw_check_wireless_mode(unsigned char *rate, int ratelen, int channel);

u8 key_2char2num(u8 hch, u8 lch);

u32 wifi_rom_parse_rsnxe(u8 *in_ie, u32 in_len, u8 *out_ie, u32 *out_len);
u32 wifi_rom_append_rsnxe(u8 h2e, u8 rsnxe_ie[], u8 *ie);
u8 *wifi_rom_set_ie_ram(u8 *pbuf, sint index, u32 len, u8 *source, u32 *frlen, u8 *pbuf_end);
int wifi_rom_parse_sec_ie_akm_mgc(u8 *ie, int ie_len, u32 *auth_key_mgmt, u32 *mgmt_group_cipher);

u8 *wifi_rom_get_ie_ex(u8 *in_ie, u32 in_len, u8 eid, u8 *oui, u8 oui_len, u8 *ie, u32 *ielen);

u8 wifi_rom_get_wmmps_ac(u8 priority, u8 uapsd_bk, u8 uapsd_vi, u8 uapsd_vo, u8 uapsd_be, u8 bit);
int wifi_rom_check_indicate_seq(u16 *indicate_seq, u16 wsize, u16 wend, u16 seq_num);


#endif /* __ROM_IEEE80211_H */

