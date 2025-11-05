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
#ifndef __HALRF_DBG_H__
#define __HALRF_DBG_H__

/*@--------------------------[Define] ---------------------------------------*/
#define HALRF_WATCHDOG_PERIOD	2 /*second*/

#if (defined(CONFIG_PHYDM_CMD) || defined(CONFIG_HALRF_CMD))
#define RFDBG_TRACE_EN
#endif

//#define RFDBG_TRACE_EN

#ifdef RFDBG_TRACE_EN
/*
#define RF_DBG(comp, fmt, ...)     \
		do {\
			if(g6_rf.dbg_component & comp)\
				_os_dbgdump("[RF]" fmt, ##__VA_ARGS__);\
		} while (0)
*/
#define RF_DBG(comp, fmt, ...)     \
		do {\
			if(g6_rf.dbg_component & comp)\
				RTK_LOGA("RF", fmt, ##__VA_ARGS__);\
		} while (0)

#define RF_TRACE(fmt, ...)     \
		do {\
			_os_dbgdump("[RF]" fmt, ##__VA_ARGS__);\
		} while (0)

#define RF_WARNING(fmt, ...)     \
		do {\
			_os_dbgdump("[WARNING][RF]" fmt, ##__VA_ARGS__);\
		} while (0)

#define RF_DBG_VAST(max_buff_len, used_len, buff_addr, remain_len, fmt, ...)\
		do {\
			_os_dbgdump(fmt, ##__VA_ARGS__);\
		} while (0)
/*
#define	RF_DBG_CNSL(max_buff_len, used_len, buff_addr, remain_len, fmt, ...)\
		do {									\
			u32 *used_len_tmp = &(used_len);				\
			if (*used_len_tmp < max_buff_len)				\
				*used_len_tmp += _os_snprintf(buff_addr, remain_len, fmt, ##__VA_ARGS__);\
		} while (0)
*/
#define	RF_DBG_CNSL(max_buff_len, used_len, buff_addr, remain_len, fmt, ...)\
		do {									\
			u32 *used_len_tmp = &(used_len);				\
			if (*used_len_tmp < max_buff_len)				\
				*used_len_tmp += DiagSnPrintf(buff_addr, remain_len, fmt, ##__VA_ARGS__);\
		} while (0)
#else
#define RF_DBG(...)  do {} while(0)
#define RF_TRACE(...)  do {} while(0)
#define RF_WARNING(...)  do {} while(0)
#define RF_DBG_CNSL(...)  do {} while(0)  /*Print on Consol,CLI */
#define RF_DBG_VAST(...)	 do {} while(0)  /*Print to Comport, Debug View*/
#endif


/*@--------------------------[Enum]------------------------------------------*/

/*@--------------------------[Structure]-------------------------------------*/

/*@--------------------------[Prptotype]-------------------------------------*/
struct rf_info;
void halrf_dbg_setting_init(void);
void halrf_iqk_log(void);
void halrf_lck_log(void);
void _halrf_dpk_info(u32 *_used, char *output, u32 *_out_len);
void halrf_support_ability(char input[][16], u32 *_used, char *output, u32 *_out_len);
void halrf_dbg_trace(char input[][16], u32 *_used, char *output, u32 *_out_len);
void halrf_dpk_dbg_cmd(char input[][16], u32 *_used, char *output, u32 *_out_len);
void halrf_rx_dck_dbg_cmd(char input[][16], u32 *_used, char *output, u32 *_out_len);
void halrf_dack_dbg_cmd(char input[][16], u32 *_used, char *output, u32 *_out_len);
void halrf_tssi_dbg_cmd(char input[][16], u32 *_used, char *output, u32 *_out_len);
void halrf_iqk_dbg_cmd(char input[][16], u32 *_used,
					   char *output, u32 *_out_len);
void halrf_scanf(char *in, enum rf_scanf_type type, u32 *out);
void halrf_txgapk_dbg_cmd(char input[][16], u32 *_used, char *output, u32 *_out_len);

#endif
