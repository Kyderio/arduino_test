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
#ifndef _ROM_IEEE80211_PART2_H
#define _ROM_IEEE80211_PART2_H

int wifi_rom_channel_num2bitmap_index(u8 channel_num, int *pgroup_index, int *pbit_index);
u8 wifi_rom_channel_bitmap_index2num(int group, int bit_index);
int wifi_rom_channel_is_contained(struct channel_set_bitmap *channel_set, const u8 channel_num, int *pchannel_group, int *pbit_index);
u8 wifi_rom_chset_is_chbw_valid(struct channel_set_bitmap *ch_set, u8 ch, u8 bw, u8 offset);
u8 wifi_rom_get_band_type_by_channel_plan(u8 channel_plan);
u8 wifi_rom_init_channel_set(struct init_chset_parms *parms, struct channel_set_bitmap *channel_set);
void wifi_rom_update_wireless_mode(struct update_mode_parms *parms);
unsigned int wifi_rom_is_ap_in_tkip(u32 capability, u32 IELength, u8 *pIEs);
int wifi_rom_support_short_GI(u8 HT_enable, unsigned short HT_caps_info, u8 bwmode);
u8 *wifi_rom_fill_wlan_header(struct fill_wlan_hdr_parms *parms);
int wifi_rom_get_wpa2_akmp_suite(u8 *s);
int wifi_rom_get_mgmt_group_cipher_suite(u8 *s);
int wifi_rom_parse_wpa_ie_akm(u8 *ie, int ie_len, u32 *auth_key_mgmt);
int wifi_rom_parse_sec_ie_akm_mgc(u8 *ie, int ie_len, u32 *auth_key_mgmt, u32 *mgmt_group_cipher);
u8 *wifi_rom_fill_frame_content(u8 *pframe, unsigned char *src, int len, u32 *pkt_len);
u8 *wifi_rom_set_ie_ram(u8 *pbuf, sint index, u32 len, u8 *source, u32 *frlen, u8 *pbuf_end);
u8 *wifi_rom_get_ie_ex(u8 *in_ie, u32 in_len, u8 eid, u8 *oui, u8 oui_len, u8 *ie, u32 *ielen);
u32 wifi_rom_parse_rsnxe(u8 *in_ie, u32 in_len, u8 *out_ie, u32 *out_len);
u8	wifi_rom_ht_mcsset_to_nss(u8 *supp_mcs_set);
u32 wifi_rom_append_rsnxe(u8 h2e, u8 rsnxe_ie[], u8 *ie);
int wifi_rom_restruct_wmm_ie(u8 *in_ie, u8 *out_ie, uint in_len, uint initial_out_len);
int wifi_rom_restruct_sec_ie(struct security_ie_set *sec_ie_set, u8 is_80211w, u8 is_sae, u8 *in_ie, u8 *out_ie);
void wifi_rom_append_exented_cap(u8 is_wnm, u8 is_mbssid, u8 *out_ie, u32 *pout_len);
int wifi_rom_check_rsn_ie_pmkid(u8 *ie, u8 ie_len, u8 *pmkid);

#endif
