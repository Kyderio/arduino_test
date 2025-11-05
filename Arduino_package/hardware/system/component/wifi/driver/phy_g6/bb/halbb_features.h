/******************************************************************************
 *
 * Copyright(c) 2007 - 2020  Realtek Corporation.
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

#ifndef __HALBB_FEATURES_H__
#define __HALBB_FEATURES_H__

#include "wifi_intf_os_to_g6.h"
#include "halbb_cfg_ic.h"
#include "halbb_ic_hw_info.h"

/*[Control by Outer Driver]--------------------------------------------------*/
#ifndef CONFIG_PHYDM_CMD
#define DRV_BB_DBG_TRACE_DISABLE
#define DRV_BB_PMAC_TX_DISABLE
#define DRV_BB_CMN_RPT_DISABLE
#define DRV_BB_STATISTICS_DISABLE
#define DRV_BB_DGB_SUPPORT_DISABLE
#endif
#ifndef DRV_BB_TIMER_SUPPORT_DISABLE
#define HALBB_TIMER_SUPPORT
#endif

#ifndef DRV_BB_DGB_SUPPORT_DISABLE
#define HALBB_DBG_SUPPORT
#endif

#ifndef DRV_BB_DBG_TRACE_DISABLE
#define HALBB_DBG_TRACE_SUPPORT
#endif

#ifndef DRV_BB_PHYSTS_PARSING_DISABLE
#define HALBB_PHYSTS_PARSING_SUPPORT
#endif
#ifndef DRV_BB_ENV_MNTR_DISABLE
#define HALBB_ENV_MNTR_SUPPORT
#define CLM_SUPPORT
#if defined(BB_8730E_SUPPORT) || defined(BB_8721F_SUPPORT)
#define NHM_SUPPORT
#endif
//#define IFS_CLM_SUPPORT
//#define FAHM_SUPPORT
//#define EDCCA_CLM_SUPPORT
#endif
#ifndef DRV_BB_STATISTICS_DISABLE
#define HALBB_STATISTICS_SUPPORT
#endif
#ifndef DRV_BB_DFS_DISABLE
#define HALBB_DFS_SUPPORT
#define HALBB_ENV_MNTR_SUPPORT
#endif

#define HALBB_CFO_TRK_DISABLE_BY_SHARE_XTAL

#ifndef DRV_BB_CFO_TRK_DISABLE
#define HALBB_CFO_TRK_SUPPORT
#define HALBB_CFO_DAMPING_CHK
//#define BB_DYN_CFO_TRK_LOP
#endif

#ifndef DRV_BB_LA_MODE_DISABLE
#define HALBB_LA_MODE_SUPPORT
#define HALBB_DBG_SUPPORT
#endif
#ifndef DRV_BB_PSD_DISABLE
//#define HALBB_PSD_SUPPORT
#endif
#ifndef DRV_BB_PWR_CTRL_DISABLE
#define NHM_SUPPORT
#define HALBB_PWR_CTRL_SUPPORT
#endif
#ifndef DRV_BB_PMAC_TX_DISABLE
#define HALBB_PMAC_TX_SUPPORT
#endif
#ifndef DRV_BB_CH_INFO_DISABLE
#define HALBB_CH_INFO_SUPPORT
#endif

#ifndef DRV_BB_PMAC_TX_SETTING_DISABLE
#define HALBB_PMAC_TX_SETTING_SUPPORT
#endif

//#define HALBB_RADAR_SUPPORT

//#define HALBB_TDMA_CR_SUPPORT

/*[POP resolved hang]*/
#ifdef DRV_RESOLVED_POP_BY_BB
#define HALBB_RESOLVED_POP_BY_BB
#endif

/*[Shared crystal]*/
#if (defined(CONFIG_SHARE_XSTAL) || defined(CONFIG_2G_25MHZ_XSTAL))
#define HALBB_SHARE_XSTAL_SUPPORT
#endif

#ifdef DRV_BB_CMN_RPT_DISABLE
#define HALBB_CMN_RPT_SIMPLE
#endif

#if (defined(DRV_BB_CNSL_CMN_INFO) || !defined(HALBB_DBG_TRACE_SUPPORT))
#define HALBB_CNSL_CMN_INFO_SUPPORT
#endif
#endif
