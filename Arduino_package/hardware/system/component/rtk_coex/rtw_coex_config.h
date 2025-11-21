/******************************************************************************
 *
 * Copyright(c) 2016 - 2017 Realtek Corporation.
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
#ifndef RTW_COEX_CONFIG_H
#define RTW_COEX_CONFIG_H

//config coex debug log
#define COEX_DEBUG_OFF          0
#define COEX_DEBUG_RTKLOG       1
#define COEX_DEBUG_LOGUARTBIN   2

//default enable coex log for auto test
#define COEX_DEBUG_ENABLE_LOG_DEFAULT   0

#define CONFIG_COEX_MAN_CTRL_EN		    0
#define CONFIG_COEX_EXT_CHIP_ENABLE	    1   // define for ext code mark; CONFIG_COEX_EXT_CHIP_SUPPORT for menuconfig & open source code
#define CONFIG_COEX_EXT_CHIP_DEBUG	    0

//for coex gpio debug
#define CONFIG_COEX_DEBUG_GPIO  0

//for scbd bit definiton
#define	RTK_COEX_SCBD_32BIT_MODE   1
#define	RTK_COEX_SCBD_8BIT_MODE    2


#if defined(CONFIG_AMEBADPLUS)
#define CONFIG_COEX_DEBUG		COEX_DEBUG_LOGUARTBIN

#define RTK_COEX_WL_MAX_INTF_NUM  			2
#define CONFIG_COEX_WPAN_SUPPORT			0
#define CONFIG_COEX_SINGLE_ANT              1
#define CONFIG_COEX_DUAL_ANT 				0
#define CONFIG_COEX_LE_AUDIO_SUPPORT		0
#define CONFIG_COEX_BR_EDR_SUPPORT          0
#define CONFIG_COEX_WIFI_5G_BAND_SUPPORT    1
#define CONFIG_COEX_SCBD_BIT_MODE           RTK_COEX_SCBD_8BIT_MODE
#elif defined(CONFIG_AMEBASMART) || defined(CONFIG_AMEBASMARTPLUS)
#define CONFIG_COEX_DEBUG		            COEX_DEBUG_LOGUARTBIN

#define RTK_COEX_WL_MAX_INTF_NUM			2
#define CONFIG_COEX_WPAN_SUPPORT			0
#define CONFIG_COEX_SINGLE_ANT              1
#define CONFIG_COEX_DUAL_ANT				1
#define CONFIG_COEX_LE_AUDIO_SUPPORT		1
#define CONFIG_COEX_BR_EDR_SUPPORT          1
#define CONFIG_COEX_WIFI_5G_BAND_SUPPORT    1
#define CONFIG_COEX_SCBD_BIT_MODE           RTK_COEX_SCBD_32BIT_MODE
#elif defined(CONFIG_AMEBALITE)
#define CONFIG_COEX_DEBUG		            COEX_DEBUG_LOGUARTBIN
#define RTK_COEX_WL_MAX_INTF_NUM			2
#define CONFIG_COEX_WPAN_SUPPORT			0
#define CONFIG_COEX_SINGLE_ANT              1
#define CONFIG_COEX_DUAL_ANT				0
#define CONFIG_COEX_LE_AUDIO_SUPPORT		0
#define CONFIG_COEX_BR_EDR_SUPPORT          1
#define CONFIG_COEX_WIFI_5G_BAND_SUPPORT    0
#define CONFIG_COEX_SCBD_BIT_MODE           RTK_COEX_SCBD_32BIT_MODE
#elif defined(CONFIG_AMEBAGREEN2)
#define CONFIG_COEX_DEBUG		            COEX_DEBUG_LOGUARTBIN

#define RTK_COEX_WL_MAX_INTF_NUM  			2
#define CONFIG_COEX_WPAN_SUPPORT			0
#define CONFIG_COEX_SINGLE_ANT              1
#define CONFIG_COEX_DUAL_ANT 				0
#define CONFIG_COEX_LE_AUDIO_SUPPORT		0
#define CONFIG_COEX_BR_EDR_SUPPORT          0
#define CONFIG_COEX_WIFI_5G_BAND_SUPPORT    1
#define CONFIG_COEX_SCBD_BIT_MODE           RTK_COEX_SCBD_8BIT_MODE
#elif defined(CONFIG_AMEBAL2)
#define CONFIG_COEX_DEBUG		            COEX_DEBUG_LOGUARTBIN

#define RTK_COEX_WL_MAX_INTF_NUM  			2
#define CONFIG_COEX_WPAN_SUPPORT			0
#define CONFIG_COEX_SINGLE_ANT              1
#define CONFIG_COEX_DUAL_ANT 				0
#define CONFIG_COEX_LE_AUDIO_SUPPORT		0
#define CONFIG_COEX_BR_EDR_SUPPORT          0
#define CONFIG_COEX_WIFI_5G_BAND_SUPPORT    0
#define CONFIG_COEX_SCBD_BIT_MODE           RTK_COEX_SCBD_8BIT_MODE
#elif defined(CONFIG_AMEBAD)
// AMEBAD_FIXME
#define CONFIG_COEX_DEBUG		            COEX_DEBUG_RTKLOG

#define RTK_COEX_WL_MAX_INTF_NUM  			2
#define CONFIG_COEX_WPAN_SUPPORT			0
#define CONFIG_COEX_SINGLE_ANT              1
#define CONFIG_COEX_DUAL_ANT 				0
#define CONFIG_COEX_LE_AUDIO_SUPPORT		0
#define CONFIG_COEX_BR_EDR_SUPPORT          0
#define CONFIG_COEX_WIFI_5G_BAND_SUPPORT    1
#define CONFIG_COEX_SCBD_BIT_MODE           RTK_COEX_SCBD_8BIT_MODE
#define CONFIG_COEX_BT_SW_MAILBOX           1
#else
#error "Please config coex setting for support new IC!!!"
#endif

//LINUX not support loguart
#if defined(CONFIG_LINUX_FW_EN)
#if CONFIG_COEX_DEBUG == COEX_DEBUG_LOGUARTBIN
#undef CONFIG_COEX_DEBUG
#define CONFIG_COEX_DEBUG       COEX_DEBUG_RTKLOG
#endif
#endif

#endif
