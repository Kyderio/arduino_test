/******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation.
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
#ifndef _HAL_TWT_TIMER_H_
#define _HAL_TWT_TIMER_H_

enum twt_class {
	TWTCLIENTA               = 0x0,
	TWTCLIENTB               = 0x1,
	TWTCLIENTC               = 0x2,
	TWTCLIENTD               = 0x3,
	TWTCLIENTE               = 0x4,
};

#define TWT_TIMER_BOUND_TO_FREERUN        3

#define TWT_TIMER_SPEAKER                 TWTCLIENTB

#ifdef CONFIG_NAN
#define TWT_TIMER_NAN_FAW_PS              TWTCLIENTA
#if defined(CONFIG_AMEBASMART) || defined(CONFIG_AMEBADPLUS)
#define TWT_TIMER_NAN_SDF_TX              TWTCLIENTB
#define TWT_TIMER_NAN_SET_P0              TWTCLIENTC
#define TWT_TIMER_NAN_SET_P1              TWTCLIENTD
#elif defined(CONFIG_AMEBAL2) || defined(CONFIG_AMEBAGREEN2)
#define TWT_TIMER_NAN_JOINCLUSTER_PS      TWTCLIENTB
#endif
#endif

#ifdef CONFIG_MCC_MODE
#define TWT_TIMER_MCC                     TWTCLIENTE
#endif

#ifdef CONFIG_WIFI_TUNNEL
#define TWT_TIMER_WTN                     TWTCLIENTE
#endif

#ifdef CONFIG_P2PPS
/*for rtl8721da, rtl8730e, may conflict with NAN*/
#define TWT_TIMER_GO_TSF31					TWTCLIENTC
#endif

#ifdef CONFIG_RADAR
/*only for amebax */
#define TWT_TIMER_RADAR					TWTCLIENTD
#define TWT_TIMER_RADAR_COEX_TEST		TWTCLIENTE
#endif

void wifi_hal_twt_timer_enable(u8 idx, u8 port);
void wifi_hal_twt_timer_disable(u8 idx);
void wifi_hal_twt_set_early_time(u8 idx, u32 early_time_us);
void wifi_hal_twt_set_target_wake_time(u8 idx, u64 twt_us);

#endif

