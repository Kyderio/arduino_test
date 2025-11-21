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

#ifndef __PHYDM_FEATURES_H__
#define __PHYDM_FEATURES_H__

#define CONFIG_RUN_IN_DRV

/*@20170103 YuChen add for FW API*/
#define PHYDM_FW_API_ENABLE_8822B		1
#define PHYDM_FW_API_FUNC_ENABLE_8822B		1
#define PHYDM_FW_API_ENABLE_8821C		1
#define PHYDM_FW_API_FUNC_ENABLE_8821C		1
#define PHYDM_FW_API_ENABLE_8195B		1
#define PHYDM_FW_API_FUNC_ENABLE_8195B		1
#define PHYDM_FW_API_ENABLE_8198F		1
#define PHYDM_FW_API_FUNC_ENABLE_8198F		1
#define PHYDM_FW_API_ENABLE_8822C 1
#define PHYDM_FW_API_FUNC_ENABLE_8822C 1
#define PHYDM_FW_API_ENABLE_8814B 1
#define PHYDM_FW_API_FUNC_ENABLE_8814B 1
#define PHYDM_FW_API_ENABLE_8812F 1
#define PHYDM_FW_API_FUNC_ENABLE_8812F 1
#define PHYDM_FW_API_ENABLE_8197G 1
#define PHYDM_FW_API_FUNC_ENABLE_8197G 1
#define PHYDM_FW_API_ENABLE_8723F 1
#define PHYDM_FW_API_FUNC_ENABLE_8723F 1
#define PHYDM_FW_API_ENABLE_8735B 1
#define PHYDM_FW_API_FUNC_ENABLE_8735B 1
#define PHYDM_FW_API_ENABLE_8730A 1
#define PHYDM_FW_API_FUNC_ENABLE_8730A 1
#define PHYDM_FW_API_ENABLE_8822E 1
#define PHYDM_FW_API_FUNC_ENABLE_8822E 1
#define PHYDM_FW_API_ENABLE_8721DA 1
#define PHYDM_FW_API_FUNC_ENABLE_8721DA 1
#define PHYDM_FW_API_ENABLE_8721D 1
#define PHYDM_FW_API_FUNC_ENABLE_8721D 1


#define CONFIG_POWERSAVING 0

#if (DM_ODM_SUPPORT_TYPE == ODM_IOT)
#include	"phydm_features_iot.h"
#endif

#endif
