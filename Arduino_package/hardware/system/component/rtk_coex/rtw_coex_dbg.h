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
#ifndef RTW_COEX_DBG_H
#define RTW_COEX_DBG_H

#include "rtw_coex_config.h"

#if (CONFIG_COEX_DEBUG == COEX_DEBUG_RTKLOG)

#include "log.h"
#include "rtw_wifi_common.h"
#define RTK_COEX_LOG_LEVEL_CHECK(level) (((struct rtk_coex_t *)rtk_coex_get_coex_ptr()) && (((struct rtk_coex_t *)rtk_coex_get_coex_ptr())->config.log_enable & level))
#define RTK_COEX_LOGA( format, ... )  \
	do {	\
		if (RTK_COEX_LOG_LEVEL_CHECK(RTK_COEX_LOG_ENABLE_ALWAYS)) {	\
			RTK_LOGS( TAG_WLAN_COEX, RTK_LOG_ALWAYS, format, ##__VA_ARGS__ );	\
		}	\
	} while(0);
#define RTK_COEX_LOGE( format, ... )  \
	do {	\
		if (RTK_COEX_LOG_LEVEL_CHECK(RTK_COEX_LOG_ENABLE_ERROR)) {	\
			RTK_LOGS( TAG_WLAN_COEX, RTK_LOG_ALWAYS, format, ##__VA_ARGS__ );	\
		}	\
	} while(0);
#define RTK_COEX_LOGW( format, ... )  \
	do {	\
		if (RTK_COEX_LOG_LEVEL_CHECK(RTK_COEX_LOG_ENABLE_WARN)) {\
			RTK_LOGS(TAG_WLAN_COEX, RTK_LOG_ALWAYS, format, ##__VA_ARGS__);			\
		}	\
	} while (0);
#define RTK_COEX_LOGI( format, ... )  \
	do { \
		if (RTK_COEX_LOG_LEVEL_CHECK(RTK_COEX_LOG_ENABLE_INFO)) {\
			RTK_LOGS(TAG_WLAN_COEX, RTK_LOG_ALWAYS, format, ##__VA_ARGS__);			\
		}	\
	} while (0);
#define RTK_COEX_LOGD( format, ... ) \
	do {	\
		if (RTK_COEX_LOG_LEVEL_CHECK(RTK_COEX_LOG_ENABLE_DEBUG)) {\
			RTK_LOGS(TAG_WLAN_COEX, RTK_LOG_ALWAYS, format, ##__VA_ARGS__);			\
		}	\
	} while (0);
#define RTK_COEX_DUMP( data, length, format, ... )  \
	do {	\
		if (RTK_COEX_LOG_LEVEL_CHECK(RTK_COEX_LOG_ENABLE_DEBUG)) {	\
			int __dump_idx = 0;	\
			RTK_LOGS(TAG_WLAN_COEX, RTK_LOG_ALWAYS, format, ##__VA_ARGS__);	\
			for (__dump_idx = 0; __dump_idx < length; __dump_idx++) {	\
				RTK_LOGS(TAG_WLAN_COEX, RTK_LOG_ALWAYS, "0x%x  ", *((char *)data + __dump_idx));	\
				if ((__dump_idx + 1) % 16 == 0) {	\
					RTK_LOGS(TAG_WLAN_COEX, RTK_LOG_ALWAYS, "\r\n");	\
				}	\
			}	\
			if (length % 16) {	\
				RTK_LOGS(TAG_WLAN_COEX, RTK_LOG_ALWAYS, "\r\n");	\
			}	\
		}	\
	} while(0)

#elif (CONFIG_COEX_DEBUG == COEX_DEBUG_LOGUARTBIN)

void rtw_coex_log_init_to_bin(void);
void rtw_coex_log_send_to_bin(char level, int log_idx, char num, ...);

#define COEX_STRING_DATA __attribute__((section(".COEXTRACE"))) __attribute__((aligned(4))) __attribute__((used))
#define _coex_count_args(_0,   _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9, _10, _11, _12, _13, _14, _15,\
						 _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31,\
						 _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47,\
						 _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, N, ...) N
#define coex_count_args(...) \
	_coex_count_args(__VA_ARGS__, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, \
								  47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, \
								  31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, \
								  15, 14, 13, 12, 11, 10, 9,  8,  7,  6,  5,  4,  3,  2,  1,  0)
#define COEX_TRACE_LOG(_level, format, ...)	\
	do {	\
		static const char __coex_string[] COEX_STRING_DATA = format;	\
		rtw_coex_log_send_to_bin(_level, (int)__coex_string, coex_count_args(format, ##__VA_ARGS__), ##__VA_ARGS__); \
	} while(0)

#define COEX_TRACE_DUMP(data, length)	\
	do {	\
		int __dump_idx = 0;	\
		for (__dump_idx = 0; __dump_idx < length; __dump_idx += 16) {	\
			rtw_coex_log_send_to_bin('D', 0, (length - __dump_idx < 16) ? (length - __dump_idx) : 16, (char *)data + __dump_idx); \
		}	\
	} while(0)

#define RTK_COEX_LOGA( format, ... ) COEX_TRACE_LOG( 'A', format, ##__VA_ARGS__ )
#define RTK_COEX_LOGE( format, ... ) COEX_TRACE_LOG( 'E', format, ##__VA_ARGS__ )
#define RTK_COEX_LOGW( format, ... ) COEX_TRACE_LOG( 'W', format, ##__VA_ARGS__ )
#define RTK_COEX_LOGI( format, ... ) COEX_TRACE_LOG( 'I', format, ##__VA_ARGS__ )
#define RTK_COEX_LOGD( format, ... ) COEX_TRACE_LOG( 'D', format, ##__VA_ARGS__ )
#define RTK_COEX_DUMP( data, length, format, ... ) \
	COEX_TRACE_LOG( 'D', format, ##__VA_ARGS__ ); \
	COEX_TRACE_DUMP(data, length)

#else

#define RTK_COEX_LOGA(format, ... )
#define RTK_COEX_LOGE(format, ... )
#define RTK_COEX_LOGW(format, ... )
#define RTK_COEX_LOGI(format, ... )
#define RTK_COEX_LOGD(format, ... )
#define RTK_COEX_DUMP( data, length, format, ... )

#endif


//for coex gpio debug
#if (CONFIG_COEX_DEBUG_GPIO == 1)
void rtk_coex_dbg_gpio_pulse(u32 GPIO_Pin);
void rtk_coex_dbg_gpio_wave(u32 GPIO_Pin, u32 Val);
#else
#define rtk_coex_dbg_gpio_pulse(...)
#define rtk_coex_dbg_gpio_wave(...)
#endif

#if defined(CONFIG_AMEBADPLUS)
#define COEX_TDMA_DRVC_SLOT_SWITCH	_PA_26
#define COEX_WL_CHNL_SWITCH			_PA_27
#elif defined(CONFIG_AMEBASMART) || defined(CONFIG_AMEBASMARTPLUS)
#define COEX_TDMA_DRVC_SLOT_SWITCH	_PA_20
#define COEX_WL_CHNL_SWITCH			_PA_21
#elif defined(CONFIG_AMEBALITE)
#define COEX_TDMA_DRVC_SLOT_SWITCH	_PA_28
#define COEX_WL_CHNL_SWITCH			_PA_29
#elif defined(CONFIG_AMEBAGREEN2)
// FIXME: no any test, just for compile ok
#define COEX_TDMA_DRVC_SLOT_SWITCH	_PA_26
#define COEX_WL_CHNL_SWITCH			_PA_27
#elif defined(CONFIG_AMEBAL2)
// FIXME: no any test, just for compile ok
#define COEX_TDMA_DRVC_SLOT_SWITCH	_PA_26
#define COEX_WL_CHNL_SWITCH			_PA_27
#elif defined(CONFIG_AMEBAD)
// FIXME: AMEBAD_FIXME
#define COEX_TDMA_DRVC_SLOT_SWITCH	_PA_26
#define COEX_WL_CHNL_SWITCH			_PA_27
#else
#error "Please config coex setting for support new IC!!!"
#endif

#endif