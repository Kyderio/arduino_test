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
#include "wifi_hal_beacon_xmit.h"
#include "wifi_hal_h2c.h"
#include "hal.h"

#ifdef CONFIG_WIFI_TUNNEL
#include "hal_relay_com.h"
#include "hal_wtn.h"
#endif

#ifdef WIFI_TEST
#include "../../../../soc/amebaL2/verification/wifi/amebax_wifi_test.h"
#endif

#include "wifi_intf_hal_to_g6_bb.h"
#include "wifi_intf_hal_to_g6_rf.h"
#include "wifi_intf_hal_to_g6_mac.h"
#include "wifi_intf_hal_to_g6_mac_common.h"

#define APCORE_WAKE_IRQ		AP_WAKE_IRQ

/************************** DEFINES ABOUT MACID_CAM ADDR ****************************/
#define BA_MAX_NUM		MACID_HW_MAX_NUM

#define CRC5_CAM_A1_BASE	MACID_CAM_BASE
#define CRC5_CAM_A2_BASE	(CRC5_CAM_A1_BASE + 8 * (MACID_HW_MAX_NUM/10 + ((MACID_HW_MAX_NUM%10) ? 1 : 0)))
#define CRC5_CAM_A3_BASE	(CRC5_CAM_A1_BASE + 2 * 8 * (MACID_HW_MAX_NUM/10 + ((MACID_HW_MAX_NUM%10) ? 1 : 0)))
#define CONTROL_INFO_BASE	(CRC5_CAM_A1_BASE + 3 * 8 * (MACID_HW_MAX_NUM/10 + ((MACID_HW_MAX_NUM%10) ? 1 : 0)))
#define KEYCFG_CAM_BASE         (CONTROL_INFO_BASE + 16 * MACID_HW_MAX_NUM)
#define KEY_CAM_BASE		(KEYCFG_CAM_BASE + 4 * KEY_MAX_NUM)
#define BA_CAM_BASE		(KEY_CAM_BASE + 16 * KEY_MAX_NUM) // consider 128bit key
#define ADDR_CAM_BASE		(BA_CAM_BASE + 12 * BA_MAX_NUM)

/**************************** DEFINES ABOUT SECCFG *******************************/
#ifdef SECCFG_8021X
#undef SECCFG_8021X
#undef SECCFG_8021X_GCMP_256
#undef SECCFG_NON_8021X
#ifdef CONFIG_NAN
#undef SECCFG_NAN
#endif
#endif
#define SECCFG_8021X		(BIT_WMAC_RXDEC | BIT_WMAC_TXENC | BIT_WMAC_CKEYID)
#define SECCFG_NON_8021X	(BIT_WMAC_RXDEC | BIT_WMAC_TXENC | BIT_WMAC_CKEYID)
#define SECCFG_8021X_GCMP_256	(BIT_WMAC_RXDEC | BIT_WMAC_TXENC | BIT_WMAC_CKEYID)  //need check future
#ifdef CONFIG_NAN
#define SECCFG_NAN		(BIT_WMAC_RXDEC | BIT_WMAC_TXENC)
#endif

/**************************** DEFINES ABOUT TXPAUSE *******************************/
#ifdef MAC_TXPAUSE_ALL
#undef MAC_TXPAUSE_ALL
#undef MAC_TXPAUSE_KEEP_MGTQ
#undef MAC_TXPAUSE_BCNQ
#undef MAC_TXPAUSE_MGTQ

#define MAC_TXPAUSE_ALL                       0x1FF
#define MAC_TXPAUSE_KEEP_MGTQ                 (0x1FF & ~BIT(4))
#define MAC_TXPAUSE_BCNQ                      (BIT(6))
#define MAC_TXPAUSE_MGTQ                      (BIT(4))
#define MAC_TXPAUSE_EVTQ					  (BIT(7))
#endif

/**************************** DEFINES ABOUT power save *******************************/
/* ps mode: data 0. */
#define PS_ENTER_START		0x1
#define PS_LEAVE_START		0x0

/* PowerState: data 4. */
#define PS_IPS_PG_ENTER		0x8
#define PS_LPS_PG_ENTER		0x0
#define PS_REG_RF_ALL_ON	0xC

#define REG_POWER_BASE		14
#define TX_1S			0

/*-------------------------------------------------------------------------------
	Define Alias: wifi secure
--------------------------------------------------------------------------------*/
#ifdef wifi_rom_write_cam
#undef wifi_rom_write_cam
#endif
#define wifi_rom_write_cam(entry, ctrl, mac, key, macid)	ROM_WIFI_CAM_WRITE(entry, ctrl, macid, key)

#define wifi_hal_mbssid_sta_cfg(enable, bssid_idx_to_join, bssid_ref)	do {	\
							ROM_WIFI_AX_MBSSID_Cfg(enable, bssid_idx_to_join, bssid_ref);	\
							ROM_WIFI_ADDR_CAM_ENTRY_VALID(ADDRCAM_ENTRY_MBSSID, enable);	\
			} while(0);

/*-------------------------------------------------------------------------------
	Define Alias: wifi suspend
--------------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------------
	Define Alias: phy
--------------------------------------------------------------------------------*/
void wifi_hal_phl_stainfo_init(struct sta_mlme_priv *psta_mlmepriv);

void wifi_hal_init_rfe_ctrl_gpio(u8 state);
void wifi_hal_reset_rfe_ctrl_gpio(void);
#endif

