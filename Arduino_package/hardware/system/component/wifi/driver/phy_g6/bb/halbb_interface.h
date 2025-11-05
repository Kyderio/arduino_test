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
#ifndef __HALBB_INTERFACE_H__
#define __HALBB_INTERFACE_H__

/*@--------------------------[Define] ---------------------------------------*/
/*[IO Reg]*/

#define BB_OFST 0x10000

#define HALBB_SET_CR_CMN(cr, val, phy_idx) halbb_set_reg_cmn(cr, cr##_M, val, phy_idx);
#define HALBB_SET_CR( cr, val) halbb_set_reg( cr, cr##_M, val);

#define HALBB_GET_CR_CMN(cr, val, phy_idx) halbb_get_reg_cmn(cr, cr##_M, phy_idx);
#define HALBB_GET_CR( cr) halbb_get_reg( cr, cr##_M);

#define halbb_get_32( addr) hal_read32((addr | BB_OFST))
#define halbb_get_16( addr) hal_read16((addr | BB_OFST))
#define halbb_get_8( addr) hal_read8((addr | BB_OFST))
#define halbb_set_32( addr, val) hal_write32((addr | BB_OFST), val)
#define halbb_set_16( addr, val) hal_write16((addr | BB_OFST), val)
#define halbb_set_8( addr, val) hal_write8((addr | BB_OFST), val)

#define halbb_read_mem( addr, cnt, pmem) hal_read_mem(addr, cnt, pmem)

/*[Delay]*/
#define halbb_delay_ms(ms) rtos_time_delay_ms(ms)
#define halbb_delay_us(us) rtos_time_delay_us(us)

/*[Timer]*/
#ifdef HALBB_TIMER_SUPPORT
#define halbb_init_timer( timer, call_back_func, context, sz_id) _os_init_timer(timer, call_back_func, context, sz_id)
#define halbb_set_timer( timer, ms_delay) _os_set_timer(timer, ms_delay)
#define halbb_cancel_timer( timer) _os_cancel_timer(timer)
#define halbb_release_timer( timer) _os_release_timer(timer)
#else
#define halbb_init_timer( timer, call_back_func, context, sz_id)
#define halbb_set_timer( timer, ms_delay)
#define halbb_cancel_timer( timer)
#define halbb_release_timer( timer)
#endif

/*[Efuse]*/
#define halbb_phy_efuse_get_info( addr, size, value) rtw_hal_mac_read_phy_efuse(addr, size, value)

/*[String]*/
#define halbb_snprintf _os_snprintf

/*[PwrTable]*/
#define PWR_TBL_NUM 32
#define NUM_HE_MCS 12
#define NUM_DCM_MCS 4


/*@--------------------------[Enum]------------------------------------------*/
enum bb_timer_cfg_t {
	BB_INIT_TIMER		= 0,
	BB_CANCEL_TIMER		= 1,
	BB_RELEASE_TIMER	= 2,
	BB_SET_TIMER		= 3
};

enum halbb_h2c_rua_cmdid {
	RUA_H2C_TABLE		= 0x0,
	RUA_H2C_SWGRP		= 0x1,
	RUA_H2C_DL_MACID	= 0x2,
	RUA_H2C_UL_MACID	= 0x3,
	RUA_H2C_CSIINFO		= 0x4,
	RUA_H2C_CQI			= 0x5,
	RUA_H2C_BBINFO		= 0x6,
	RUA_H2C_SEN_TBL		= 0x7,
	RUA_H2C_PWR_TBL		= 0x8,
	RUA_MAX_H2CCMD
};

enum halbb_h2c_classid {
	HALBB_H2C_RUA		= 0x0,
	HALBB_H2C_DM		= 0x2,
	HALBB_MAX_H2CCMD
};

enum halbb_h2c_dm_cmdid {
	DM_H2C_FWTRACE		= 0x0,
	DM_H2C_FW_TRIG_TX	= 0x1,
	DM_H2C_FW_H2C_TEST	= 0x3,
	DM_H2C_FW_CMW		= 0x5,
	DM_H2C_FW_MCC		= 0x6,
	DM_H2C_FW_L6M_WA	= 0x7,
	DM_MAX_H2CCMD
};

enum halbb_h2c_cmd {
	DM_IOT_H2C_FWTRACE			= 0x49,
	DM_MAX_IOT_H2CCMD
};

enum halbb_c2h_classid {
	HALBB_C2H_RUA		= 0x0,
	HALBB_C2H_DM		= 0x2,
	HALBB_MAX_C2HCMD
};

enum halbb_c2h_dm_cmdid {
	DM_C2H_FW_TEST			= 0x0,
	DM_C2H_FW_TRIG_TX_RPT		= 0x1,
	DM_C2H_SIGB			= 0x2,
	DM_C2H_LOWRT_RTY		= 0x3,
	HALBB_MAX_C2HDMCMD
};

enum halbb_event_idx_t {
	/*timer*/
	BB_EVENT_TIMER_CFO		= 1,
	BB_EVENT_TIMER_TDMA_CR		= 3,
	BB_EVENT_TIMER_LA		= 4
};

enum halbb_timer_state_t {
	/*timer*/
	BB_TIMER_IDLE			= 0,
	BB_TIMER_RUN			= 1,
	BB_TIMER_RELEASE		= 0xff,
};

/*@--------------------------[Structure]-------------------------------------*/
struct halbb_timer_info {
	struct timer_list timer_list;
	u32	cb_time; /*callback time (ms)*/
	enum halbb_event_idx_t	event_idx;
	enum halbb_timer_state_t timer_state;
};

struct halbb_pwr_by_rate_tbl {
	u8 pwr_by_rate[PWR_TBL_NUM * 2];
};

/*@--------------------------[Prptotype]-------------------------------------*/

extern struct bb_info	g6_bb;
extern struct bb_cmn_info	g6_bb_cmn;

void halbb_cfg_timers(enum bb_timer_cfg_t cfg,
					  struct halbb_timer_info *timer);
void halbb_set_reg_curr_phy(u32 addr, u32 mask, u32 val);
void halbb_set_reg_cmn(u32 addr, u32 mask, u32 val,
					   enum phl_phy_idx phy_idx);
void halbb_set_reg_phy0_1(u32 addr, u32 mask, u32 val);
u32 halbb_get_reg_curr_phy(u32 addr, u32 mask);
u32 halbb_get_reg_cmn(u32 addr, u32 mask,
					  enum phl_phy_idx phy_idx);
u32 halbb_get_reg_phy0_1(u32 addr, u32 mask);
bool halbb_fill_h2c_cmd(u16 cmdlen, u8 cmdid,
						u8 classid, u32 *pval);
bool halbb_test_h2c_c2h_flow(void);

bool halbb_check_fw_ofld(void);
bool halbb_fw_set_reg(u32 addr, u32 mask, u32 val, u8 lst_cmd);
bool halbb_fw_set_reg_cmn(u32 addr, u32 mask, u32 val,
						  enum phl_phy_idx phy_idx, u8 lst_cmd);
bool halbb_fw_set_rf_reg(enum rf_path path,
						 u32 reg_addr, u32 bit_mask, u32 data);

#endif
