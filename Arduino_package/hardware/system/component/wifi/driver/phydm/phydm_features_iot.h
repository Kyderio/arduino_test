/******************************************************************************
 *
 * Copyright(c) 2007 - 2017  Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * The full GNU General Public License is included in this distribution in the
 * file called LICENSE.
 *
 * Contact Information:
 * wlanfae <wlanfae@realtek.com>
 * Realtek Corporation, No. 2, Innovation Road II, Hsinchu Science Park,
 * Hsinchu 300, Taiwan.
 *
 * Larry Finger <Larry.Finger@lwfinger.net>
 *
 *****************************************************************************/

#ifndef	__PHYDM_FEATURES_IOT_H__
#define __PHYDM_FEATURES_IOT_H__

#if defined(CONFIG_AMEBADPLUS)
#ifdef CONFIG_MP_SHRINK
#define PHYDM_PMAC_TX_SETTING_SUPPORT
#define PHYDM_LA_MODE_SUPPORT			0
#else
#define PHYDM_LA_MODE_SUPPORT			1
#define FAHM_SUPPORT
#define EDCCA_CLM_SUPPORT
#define PHYDM_PMAC_TX_SETTING_SUPPORT
#define PHYDM_CH_INFO_SUPPORT
#define PHYDM_DBG_TRACE_SUPPORT
#endif
#endif

#if defined(CONFIG_AMEBAD)
#define PHYDM_LA_MODE_SUPPORT			0
#define PHYDM_SUPPORT_CCKPD				1
#endif

#ifndef CONFIG_MP_SHRINK
#define NHM_SUPPORT
#define CLM_SUPPORT

#ifdef CONFIG_SUPPORT_DYNAMIC_TXPWR
#define CONFIG_DYNAMIC_TX_TWR
#endif

/* --------------------------------------------------*/

#ifdef CONFIG_DFS_MASTER
#define CONFIG_PHYDM_DFS_MASTER
#endif

#define	CONFIG_PSD_TOOL
/*#define	CONFIG_RA_DBG_CMD*/
/*#define	CONFIG_ANT_DETECTION*/
/*#define	CONFIG_RA_DYNAMIC_RTY_LIMIT*/
//#define	CONFIG_BB_TXBF_API
#if DBG
#define	CONFIG_PHYDM_DEBUG_FUNCTION
#endif

#if defined(CONFIG_BT_COEXIST)
#define	ODM_CONFIG_BT_COEXIST
#endif
#define	PHYDM_SUPPORT_RSSI_MONITOR
#endif
#endif
