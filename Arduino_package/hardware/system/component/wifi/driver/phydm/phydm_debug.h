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

#ifndef __ODM_DBG_H__
#define __ODM_DBG_H__

/*#define DEBUG_VERSION	"1.1"*/ /*2015.07.29 YuChen*/
/*#define DEBUG_VERSION	"1.2"*/ /*2015.08.28 Dino*/
/*#define DEBUG_VERSION	"1.3"*/ /*2016.04.28 YuChen*/
/*#define DEBUG_VERSION	"1.4"*/ /*2017.03.13 Dino*/
/*#define DEBUG_VERSION "2.0"*/ /*2018.01.10 Dino*/
/*2020.07.03 fix cck report bug due to 8723F coding error*/
#define DEBUG_VERSION "4.6"

/*@
 * ============================================================
 *  Definition
 * ============================================================
 */

/*@FW DBG MSG*/
#define	RATE_DECISION		1
#define	INIT_RA_TABLE		2
#define	RATE_UP			4
#define	RATE_DOWN		8
#define	TRY_DONE		16
#define	RA_H2C			32
#define	F_RATE_AP_RPT		64
#define	DBC_FW_CLM		9

#define PHYDM_SNPRINT_SIZE	64
/* @----------------------------------------------------------------------------
 * Define the tracing components
 *
 * -----------------------------------------------------------------------------
 * BB FW Functions
 */
#define	PHYDM_FW_COMP_RA	BIT(0)
#define	PHYDM_FW_COMP_MU	BIT(1)
#define	PHYDM_FW_COMP_PATH_DIV	BIT(2)
#define	PHYDM_FW_COMP_PT	BIT(3)

/*@------------------------Export Marco Definition---------------------------*/

#define config_phydm_read_txagc_check(data) (data != INVALID_TXAGC_DATA)

#if (DM_ODM_SUPPORT_TYPE == ODM_IOT)
#define pr_debug(fmt, args...)		RTW_PRINT_MSG(fmt, ## args)
#define RT_DEBUG(comp, drv_level, fmt, args...)	\
		RTW_PRINT_MSG(fmt, ## args)
#define PHYDM_SNPRINTF		snprintf
#endif

#ifndef ASSERT
#define ASSERT(expr)
#endif

#if DBG

#define PHYDM_DBG(comp, fmt, args...)			\
	do {							\
		if ((comp) & g_odm.debug_components) {		\
			RT_DEBUG(COMP_PHYDM, \
				 DBG_DMESG, "[PHYDM] " fmt, ##args);	\
		}						\
	} while (0)

#define PHYDM_DBG_F(comp, fmt, args...)			\
	do {							\
		if ((comp) & g_odm.debug_components) {		\
			RT_DEBUG(COMP_PHYDM, \
				 DBG_DMESG, fmt, ##args);	\
		}	\
	} while (0)

#define PHYDM_PRINT_ADDR(comp, title_str, addr)		\
	do {							\
		if ((comp) & g_odm.debug_components) {		\
			RT_DEBUG(COMP_PHYDM, \
				 DBG_DMESG, "[PHYDM] " title_str "%pM\n",	\
				 addr);				\
		}						\
	} while (0)

#else /*@#if DBG*/
#define PHYDM_DBG(comp, fmt, args...)
#define PHYDM_DBG_F(comp, fmt, args...)
#define PHYDM_PRINT_ADDR(comp, title_str, ptr)

#endif

#define	DBGPORT_PRI_3	3	/*@Debug function (the highest priority)*/
#define	DBGPORT_PRI_2	2	/*@Check hang function & Strong function*/
#define	DBGPORT_PRI_1	1	/*Watch dog function*/
#define	DBGPORT_RELEASE	0	/*@Init value (the lowest priority)*/

#ifdef __OSK__
#define	PHYDM_DBGPRINT	0
#else
#define	PHYDM_DBGPRINT	1
#endif
#define	MAX_ARGC_BB		20
#define	MAX_ARGV_BB		16
#define	DCMD_DECIMAL		"%d"
#define	DCMD_CHAR		"%c"
#define	DCMD_HEX		"%x"

#define	PHYDM_SSCANF(x, y, z)	_sscanf_ss(x, y, z)

#if (DM_ODM_SUPPORT_TYPE & ODM_IOT)
#define	PDM_VAST_SNPF(out_len, used, buff, len, fmt, args...)	\
	do {								\
		RT_DEBUG(COMP_PHYDM, DBG_DMESG, fmt, ##args);		\
	} while (0)
#endif

#if (PHYDM_DBGPRINT == 1)
#define	PDM_SNPF(out_len, used, buff, len, fmt, args...)		\
	do {								\
		snprintf(buff, len, fmt, ##args);			\
		pr_debug("%s", output);					\
	} while (0)
#else
#define	PDM_SNPF(out_len, used, buff, len, fmt, args...)		\
	do {								\
		u32 *__pdm_snpf_u = &(used);				\
		if (out_len > *__pdm_snpf_u)				\
			*__pdm_snpf_u += snprintf(buff, len, fmt, ##args);\
	} while (0)
#endif
/* @1 ============================================================
 * 1  enumeration
 * 1 ============================================================
 */

enum auto_detection_state { /*@Fast antenna training*/
	AD_LEGACY_MODE	= 0,
	AD_HT_MODE	= 1,
	AD_VHT_MODE	= 2
};

/*@
 * ============================================================
 * 1  structure
 * ============================================================
 */

#ifdef CONFIG_PHYDM_DEBUG_FUNCTION
u8 phydm_get_l_sig_rate(u8 rate_idx_l_sig);
#endif

void phydm_print_rate_2_buff(u8 rate, char *buf, u16 buf_size);

void phydm_init_debug_setting(void);

void phydm_bb_dbg_port_header_sel(u32 header_idx);

u32 phydm_get_bb_dbg_port_idx(void);

u8 phydm_set_bb_dbg_port(u8 curr_dbg_priority, u32 debug_port);

void phydm_release_bb_dbg_port(void);

u32 phydm_get_bb_dbg_port_val(void);

void phydm_reset_rx_rate_distribution(void);

void phydm_rx_rate_distribution(void);

u16 phydm_rx_avg_phy_rate(void);

void phydm_show_phy_hitogram(void);

void phydm_get_avg_phystatus_val(void);

void phydm_get_phy_statistic(void);

void phydm_dm_summary(u8 macid);

void phydm_basic_dbg_message(void);

void phydm_basic_profile(u32 *_used, char *output,
						 u32 *_out_len);
#if (DM_ODM_SUPPORT_TYPE & ODM_IOT)
s32 phydm_cmd(char *input, u32 in_len, u8 flag,
			  char *output, u32 out_len);
#endif
void phydm_cmd_parser(char input[][16], u32 input_num,
					  u8 flag, char *output, u32 out_len);

void phydm_fw_trace_handler(u8 *cmd_buf, u8 cmd_len);

void phydm_fw_trace_handler_8051(u8 *cmd_buf, u8 cmd_len);

void phydm_crc32_cnt_dbg(char input[][16], u32 *_used,
						 char *output, u32 *_out_len);

#endif /* @__ODM_DBG_H__ */
