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
#ifndef __HAL_PHYCFG_H__
#define __HAL_PHYCFG_H__

enum _RATE_SECTION {
	CCK = 0,
	OFDM,
	HT_MCS0_MCS7,
	HT_MCS8_MCS15,
	HT_MCS16_MCS23,
	HT_MCS24_MCS31,
	VHT_1SSMCS0_1SSMCS9,
	VHT_2SSMCS0_2SSMCS9,
	VHT_3SSMCS0_3SSMCS9,
	VHT_4SSMCS0_4SSMCS9,
	RATE_SECTION_NUM,
};

enum _RF_TX_NUM {
	RF_1TX = 0,
	RF_2TX,
	RF_3TX,
	RF_4TX,
	RF_MAX_TX_NUM,
};

#define MAX_POWER_INDEX		0x7F //8721d TXAGC power index extends 1 bit (6 bit->7bit), 0.25dB a step

#define bMaskByte0		0xff
#define bMaskDWord		0xffffffff
#define bEnable			0x1

/* MAC/BB/RF HAL config */
int wifi_hal_phy_init(void);
void wifi_hal_set_channel(u8 center_ch);
bool wifi_hal_is_legalchannel(u32 Channel);

u8 wifi_hal_phy_get_txpower_index(u8 rfpath, u8 rate, enum channel_width bandwidth, u8 channel);
void wifi_hal_zbc_rfk(void);
u32 wifi_hal_phy_calculatebitshift(u32 mask);
u8 wifi_hal_need_switch_band(enum rtw_band_type *Band, u8 channelToSW);

void wifi_hal_btc_sec_key_exchange_ntfy_wrapper(u8 iface_type, u8 b_start, u8 b_grp_key_update);
#endif // __HAL_PHYCFG_H__

