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

#ifdef CONFIG_WIFI_TUNNEL
#include "hal_wtn.h"
#endif

#ifdef WIFI_TEST
#include "../../../../soc/amebagreen2/verification/wifi/amebagreen2_wifi_test.h"
#endif

#include "wifi_intf_hal_to_g6_bb.h"
#include "wifi_intf_hal_to_g6_rf.h"
#include "wifi_intf_hal_to_g6_mac.h"
#include "wifi_intf_hal_to_g6_mac_common.h"
#include "halbb_8721f/halbb_hwimg_8721f.h"

#ifdef CONFIG_P2P
#include "wifi_hal_p2p.h"
#endif

#define APCORE_WAKE_IRQ		AP_WAKE_IRQ
#define MAC_TXPKTBUF_OFFSET		(0x20000)

#define wifi_hal_mbssid_sta_cfg(enable, bssid_idx_to_join, bssid_ref)	do {	\
							ROM_WIFI_AX_MBSSID_Cfg(enable, bssid_idx_to_join, bssid_ref);	\
							if (enable) {													\
								for (int idx = 0; idx < 6; idx++) {							\
									HAL_WRITE8(WIFI_REG_BASE, (REG_ADDRESS_TABLE0 + idx), bssid_ref[idx]);	\
								}																	\
							}																		\
							ROM_WIFI_ADDR_CAM_ENTRY_VALID(ADDRCAM_ENTRY_MBSSID, enable);	\
			} while(0);

void wifi_hal_init_rfe_ctrl_gpio(u8 state);
void wifi_hal_reset_rfe_ctrl_gpio(void);
#endif

