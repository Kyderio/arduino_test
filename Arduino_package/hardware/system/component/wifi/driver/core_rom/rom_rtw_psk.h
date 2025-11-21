/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This is ROM code section.
 *
 *
 ******************************************************************************/
#ifndef __ROM_RTW_PSK_H_
#define __ROM_RTW_PSK_H_

int rom_psk_PasswordHash(
	unsigned char *password,
	int passwordlength,
	unsigned char *ssid,
	int ssidlength,
	unsigned char *output);

void wifi_rom_set_wpa_global_PSK(unsigned char *key);
void wifi_rom_psk_derive(u8 index, unsigned char *passphrase, unsigned char *ssid);
u16 wifi_rom_psk_strip_rsn_akmp(u8 *ie, u16 ie_len, u32 wpa_mode, u8 ft_en, u8 owe_en);
u16 wifi_rom_psk_strip_pmkid(u8 *ie, u16 ie_len);
u16 wifi_rom_psk_strip_rsn_pairwise(u8 *ie, u16 ie_len);
u16 wifi_rom_psk_strip_wpa_pairwise(u8 *ie, u16 ie_len, u32 privacy_alg);


#endif	//__ROM_RTW_PSK_H_

