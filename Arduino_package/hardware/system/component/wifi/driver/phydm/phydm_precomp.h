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

#ifndef __ODM_PRECOMP_H__
#define __ODM_PRECOMP_H__

#include "phydm_types.h"

#define		TEST_FALG___		1

/* @2 Config Flags and Structs - defined by each ODM type */

#include <rtw_adapter.h>
#define	ODM_ENDIAN_TYPE				ODM_ENDIAN_LITTLE
#define __PACK
extern struct dm_struct g_odm;

/* @2 OutSrc Header Files */

#include "phydm.h"
#include "phydm_hwconfig.h"
#include "phydm_phystatus.h"
#include "phydm_debug.h"
#include "phydm_regdefine11ac.h"
#include "phydm_regdefine11n.h"
#include "phydm_interface.h"
#include "phydm_reg.h"
#include "halrf/halrf_debug.h"

#if defined(CONFIG_AMEBADPLUS)
#include "rtl8721da/halhwimg8721da_bb.h"
#include "rtl8721da/halhwimg8721da_BCNmode.h"

#include "rtl8721da/phydm_regconfig8721da.h"
#include "halrf/rtl8721da/halrf_8721da.h"
#include "halrf/rtl8721da/halhwimg8721da_rf.h"
#include "halrf/rtl8721da/halrf_iqk_8721da.h"
#include "halrf/rtl8721da/halrf_dpk_8721da.h"
#include "halrf/rtl8721da/halrf_rfk_init_8721da.h"
#include "halrf/rtl8721da/halrf_txgapk_8721da.h"
#include "rtl8721da/phydm_hal_api8721da.h"
#include "rtl8721da/version_rtl8721da.h"
#include <wifi_hal.h>
#endif

#if defined(CONFIG_AMEBAD)
#include "rtl8721d/halhwimg8721d_bb.h"
#include "rtl8721d/halhwimg8721d_BCNmode.h"

#include "rtl8721d/phydm_regconfig8721d.h"
#include "halrf/rtl8721d/halrf_8721d.h"
#include "halrf/rtl8721d/halhwimg8721d_rf.h"
#include "halrf/rtl8721d/halrf_iqk_8721d.h"
#include "halrf/rtl8721d/halrf_dpk_8721d.h"
#include "halrf/rtl8721d/halrf_rfk_init_8721d.h"
#include "halrf/rtl8721d/halrf_txgapk_8721d.h"
#include "rtl8721d/phydm_hal_api8721d.h"
#include "rtl8721d/version_rtl8721d.h"
#include <wifi_hal.h>
#endif

#endif /* @__ODM_PRECOMP_H__ */
