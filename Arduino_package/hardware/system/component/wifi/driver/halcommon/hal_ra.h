/******************************************************************************
 *
 * Copyright(c) 2019 Realtek Corporation.
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
 *****************************************************************************/
#ifndef _HAL_RA_H_
#define _HAL_RA_H_

/*@--------------------------[Define] ---------------------------------------*/
#define RAMASK_MASK_CCK	0x0000000000fffff5  //[1]cck;[2-3]ofdm;[4-5]ht;[4-6]vht/he
#define RAMASK_MASK_OFDM	0x0000000000fff00f  //[1]cck;[2-3]ofdm;[4-5]ht;[4-6]vht/he

/* WiFi Support Mode */
#define CCK_SUPPORT 	BIT(0)
#define OFDM_SUPPORT	BIT(1)
#define HT_SUPPORT		BIT(2)
#define VHT_SUPPORT		BIT(3)
#define HE_SUPPORT		BIT(4)

/*@--------------------------[Enum]------------------------------------------*/
#if (PHYDM_VERSION == 2)
enum rtw_rateid_idx {
	RTW_BGN_40M_2SS	= 0,
	RTW_BGN_40M_1SS	= 1,
	RTW_BGN_20M_2SS	= 2,
	RTW_BGN_20M_1SS	= 3,
	RTW_GN_N2SS		= 4,
	RTW_GN_N1SS		= 5,
	RTW_BG		= 6,
	RTW_G			= 7,
	RTW_B_20M		= 8,
	RTW_ARFR_STA	= 9
};
#endif
/*@--------------------------[Structure]-------------------------------------*/

/*@--------------------------[Prptotype]-------------------------------------*/
void wifi_hal_ra_update_support_rate(struct sta_mlme_priv *psta_mlmepriv);
void wifi_hal_ra_register(u8 iface_type, struct sta_mlme_priv *psta_mlmepriv);
void wifi_hal_ra_watchdog(void);

#endif /*_HAL_RA_H_*/
