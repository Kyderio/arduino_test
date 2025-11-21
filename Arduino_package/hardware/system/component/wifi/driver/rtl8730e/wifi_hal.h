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

#ifndef __WIFI_HAL_H__
#define __WIFI_HAL_H__

#include "rtw_adapter.h"
#include "wifi_intf_g6_to_hal_def.h"
#include "hal.h"

#ifdef WIFI_TEST
#ifdef CONFIG_AMEBASMARTPLUS
#include "../../../../soc/amebasmartplus/verification/wifi/amebad2_wifi_test.h"
#else
#include "../../../../soc/amebasmart/verification/wifi/amebad2_wifi_test.h"
#endif
#endif
#if defined (CONFIG_CLINTWOOD) && CONFIG_CLINTWOOD
#include "wifi_hal_power_save.h"
#endif
#include "wifi_intf_hal_to_g6_bb.h"
#include "wifi_intf_hal_to_g6_mac.h"
#include "wifi_intf_hal_to_g6_mac_common.h"

#ifdef CONFIG_P2P
#include "wifi_hal_p2p.h"
#endif
#include "halbb_hwimg_8730e.h"

#define CSI_BUF_SIZE_MAC	1536	/*CSI + DFS=2048, so MAC's DFS BUF = 2048-1536 = 512bytes*/
#define wifi_hal_rf_struct_size_get()	halrf_struct_size_get()

#define MAC_TXPKTBUF_OFFSET (0x20000)

enum _RFE_GPIO_SOURCE_SEL {
	BTC_RFE_BB_GPIO_RFM_PAPE	= 0x0,
	BTC_RFE_BB_GPIO_GNT_WL_INV	= 0x1,
	BTC_RFE_BB_GPIO_RFM_LNAON	= 0x3,
	BTC_RFE_BB_GPIO_RFM_TRSW	= 0x5,
	BTC_RFE_BB_GPIO_GNT_BT		= 0x6,
	BTC_RFE_BB_GPIO_FIX_ZERO	= 0x7,
	BTC_RFE_BB_GPIO_ANT_SEL0	= 0x8,
	BTC_RFE_BB_GPIO_MAX
};

enum _BTC_ANTENNA_POS {
	BTC_ANTENNA_AT_S0				= 0x0,
	BTC_ANTENNA_AT_S1				= 0x1,
};

#define wifi_hal_mbssid_sta_cfg(enable, bssid_idx_to_join, bssid_ref)	\
							ROM_WIFI_AX_MBSSID_Cfg(enable, bssid_idx_to_join, bssid_ref)


void rtl8730e_set_btc_rf_bton_para(bool bt_s1);
void rtl8730e_set_btc_rf_switchband_para(void);
void rtl8730e_set_btc_bb_switchchannel_para(u8 channel, u8 bt_on);
void wifi_hal_init_rfe_ctrl_gpio(u8 state);
void wifi_hal_reset_rfe_ctrl_gpio(void);
#endif

