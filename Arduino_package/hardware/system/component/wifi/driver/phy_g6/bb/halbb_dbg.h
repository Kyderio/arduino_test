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
#ifndef __HALBB_DBG_H__
#define __HALBB_DBG_H__

#include "wifi_intf_os_to_g6.h"

/*@--------------------------[Define] ---------------------------------------*/
#define HALBB_WATCHDOG_PERIOD	2 /*second*/

#define PHY_HIST_SIZE		12
#define PHY_HIST_TH_SIZE	(PHY_HIST_SIZE - 1)

#define LA_CLK_EN 	0x014 /*Just for dbg, will be removed*/
#define LA_CLK_EN_M 	0x1 /*Just for dbg, will be removed*/

#define FRC_PRINT_LINE 0xffffffff

#define VHT_2_HE32_RATE(X) ((((X) << 3) + (X) + 4) >> 3) /*= Round(X * 1.125)*/
#define HE32_2_HE16_RATE(X) ((((X) << 3) + (X) + 4) >> 3) /*= Round(X * 1.125)*/
#define HE32_2_HE08_RATE(X) ((((X) << 4) + ((X) << 1) + (X) + 8) >> 4) /*= Round(X * 1.1875)*/

#ifdef HALBB_DBG_TRACE_SUPPORT
#define BB_DBG(comp, fmt, ...)     \
			do {\
				if(g6_bb.dbg_component & comp) {\
					_os_dbgdump("[BB]" fmt, ##__VA_ARGS__);\
				} \
			} while (0)

#define BB_TRACE1( fmt, ...)     \
			do {\
				_os_dbgdump("[BB]" fmt, ##__VA_ARGS__);\
			} while (0)

#define BB_TRACE(fmt, ...)     \
		do {\
			_os_dbgdump("[BB]" fmt, ##__VA_ARGS__);\
		} while (0)

#define BB_WARNING(fmt, ...)     \
		do {\
			_os_dbgdump("[WARNING][BB]" fmt, ##__VA_ARGS__);\
		} while (0)

#define	BB_DBG_CNSL2(in_cnsl, max_buff_len, used_len, buff_addr, remain_len, fmt, ...)\
		do {								\
			u32 *used_len_tmp = &(used_len);			\
			u32 len_tmp = 0;					\
			if (*used_len_tmp < max_buff_len) {			\
				len_tmp = _os_snprintf(buff_addr, remain_len, fmt, ##__VA_ARGS__); \
				if (in_cnsl) {					\
					*used_len_tmp += len_tmp; 		\
				} else {					\
					BB_TRACE("%s\n", buff_addr); 		\
				}						\
			}\
		} while (0)
#else
#define BB_DBG(...)   do {} while(0)
#define BB_TRACE(...)   do {} while(0)
#define BB_TRACE1(...)   do {} while(0)
#define BB_WARNING(...)   do {} while(0)
#define	BB_DBG_CNSL2(in_cnsl, max_buff_len, used_len, buff_addr, remain_len, fmt, ...)\
		do {								\
			u32 *used_len_tmp = &(used_len);				\
			if (*used_len_tmp < max_buff_len)				\
				*used_len_tmp += _os_snprintf(buff_addr, remain_len, fmt, ##__VA_ARGS__);\
		} while (0)
#endif

#define BB_BRIEF(fmt, ...)     \
	do {\
		_os_dbgdump("[BB]" fmt, ##__VA_ARGS__);\
	} while (0)

#define BB_DBG_VAST(max_buff_len, used_len, buff_addr, remain_len, fmt, ...)\
	do {\
		_os_dbgdump("[CNSL]" fmt, ##__VA_ARGS__);\
	} while (0)

#define	BB_DBG_CNSL(max_buff_len, used_len, buff_addr, remain_len, fmt, ...)\
	do {									\
		u32 *used_len_tmp = &(used_len);				\
		if (*used_len_tmp < max_buff_len)				\
			*used_len_tmp += _os_snprintf(buff_addr, remain_len, fmt, ##__VA_ARGS__);\
	} while (0)

#define	DBGPORT_PRI_3	3	/*@Debug function (the highest priority)*/
#define	DBGPORT_PRI_2	2	/*@Check hang function & Strong function*/
#define	DBGPORT_PRI_1	1	/*Watch dog function*/
#define	DBGPORT_RELEASE	0	/*@Init value (the lowest priority)*/

/*@--------------------------[Enum]------------------------------------------*/
enum bb_dbg_devider_len_t {
	BB_DEVIDER_LEN_32 = 0,
	BB_DEVIDER_LEN_16 = 1,
};

enum bb_dbg_port_ip_t {
	DBGPORT_IP_TD		= 1,
	DBGPORT_IP_RX_INNER	= 2,
	DBGPORT_IP_TX_INNER	= 3,
	DBGPORT_IP_OUTER	= 4,
	DBGPORT_IP_INTF		= 5,
	DBGPORT_IP_CCK		= 6,
	DBGPORT_IP_BF		= 7,
	DBGPORT_IP_RX_OUTER	= 8,
	DBGPORT_IP_RFC0		= 0X1B,
	DBGPORT_IP_RFC1		= 0X1C,
	DBGPORT_IP_RFC2		= 0X1D,
	DBGPORT_IP_RFC3		= 0X1E,
	DBGPORT_IP_TST		= 0X1F,
};

enum bb_frc_phy_dump_reg {
	FRC_DUMP_PHY0		= 0,
	FRC_DUMP_PHY1		= 1,
	FRC_DUMP_ALL
};

enum bb_basic_dbg_info {
	BB_BASIC_DBG_01_SYSTEM		= BIT1,
	BB_BASIC_DBG_02_ENVMNTR		= BIT2,
	BB_BASIC_DBG_03_PMAC		= BIT3,
	BB_BASIC_DBG_04_TX		= BIT4,
	BB_BASIC_DBG_05_RX		= BIT5,
	BB_BASIC_DBG_06_RSSI_RATE	= BIT6,
	BB_BASIC_DBG_07_HIST		= BIT7,
	BB_BASIC_DBG_08_RSSI_RATE_MU	= BIT8,
	BB_BASIC_DBG_09_DM_SUMMARY	= BIT9
};

/*@--------------------------[Structure]-------------------------------------*/
struct bb_tx_info {
	/*From reg*/
	u8 type;
	u8 tx_path_en;
	u8 path_map;
	u8 txcmd_num;
	u8 txsc;
	u8 bw;
	u16 tx_pw; /*tmac*/
	u8 n_usr;
	u8 max_mcs;
	bool stbc;
	u8 gi;
	u8 ltf;
	u8 u_id[4];
	u8 n_sts[4];
	bool fec[4];
	u8 mcs[4];
	bool dcm[4];
	u8 precoding[4];
	u16 n_sym;
	u8 pkt_ext;
	u8 pre_fec;
	u32 l_sig;
	u32 sig_a1;
	u32 sig_a2;
	u32 sig_b;
	u32 txinfo[4];
	u32 txcomct[2];
	u32 txusrct[4][2];
	u32 txtimct;
	u16 txpw_path0; /*bb_path0*/
	u16 txpw_path1; /*bb_path1*/
	/*sw variable*/
	u16 t_data;
	u32 psdu_length;
};

struct bb_dbg_info {
	struct bb_tx_info tx_info_i;
};

/*@--------------------------[Prptotype]-------------------------------------*/
void halbb_print_devider(u8 len, bool with_space, u64 comp);
void halbb_print_rate_2_buff(u16 rate_idx, enum rtw_gi_ltf gi_ltf, char *buf, u16 buf_size);

void halbb_dbg_comp_init(void);
void halbb_bb_dbg_port_clock_en(u8 enable);
u32 halbb_get_bb_dbg_port_idx(void);
void halbb_set_bb_dbg_port(u32 dbg_port);
void halbb_set_bb_dbg_port_ip(enum bb_dbg_port_ip_t ip);
void halbb_release_bb_dbg_port(void);
bool halbb_bb_dbg_port_racing(u8 curr_dbg_priority);
u32 halbb_get_bb_dbg_port_val(void);
u16 halbb_rx_utility(u16 avg_phy_rate, u8 rx_max_ss,
					 enum channel_width bw);
u16 halbb_rx_avg_phy_rate(void);
void halbb_get_tx_dbg_reg(void);
void halbb_basic_dbg_message(void);
void halbb_get_bb_para_pkg_ver(u32 *date, u32 *release_ver);
void halbb_cr_table_dump(u32 *cr_table, u32 cr_len);
void halbb_dump_bb_reg(u32 *_used, char *output,
					   u32 *_out_len, bool dump_2_buff);
void halbb_show_rx_rate(char input[][16], u32 *_used,
						char *output, u32 *_out_len);
void halbb_tx_info_dbg(char input[][16], u32 *_used,
					   char *output, u32 *_out_len);
void halbb_cmn_dbg(char input[][16], u32 *_used, char *output, u32 *_out_len);
void halbb_dbg_setting_init(void);
#endif
