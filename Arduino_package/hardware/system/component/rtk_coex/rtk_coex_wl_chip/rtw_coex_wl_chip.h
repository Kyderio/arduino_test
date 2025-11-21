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
#ifndef RTW_COEX_WL_CHIP_H
#define RTW_COEX_WL_CHIP_H

#define RTK_COEX_LE_EXTRA_INFO_DEF_NEW	0

#define RTK_COEX_MAXIMUM_SLOT 			4
#define RTK_COEX_BT_BUSY_THRESHOLD 		50

#define RTK_COEX_BT_INFO_LENGTH  		6

#define RTK_COEX_HW_MAILBOX_MAX_LENGTH 	8
#define RTK_COEX_HW_MAILBOX_HEADER_LENGTH 	2
#define RTK_COEX_WL_FW_H2C_MAX_LENGTH 	8
#define RTK_COEX_WL_FW_H2C_HEADER_LENGTH 	1
#define RTK_COEX_WL_FW_H2C_MAILBOX_MAX_LENGTH 	( RTK_COEX_WL_FW_H2C_MAX_LENGTH - RTK_COEX_WL_FW_H2C_HEADER_LENGTH )

//The value agreed by COEX and BT FW, provide feedback through SCBD two bit
#define RTK_COEX_BT_RX_LNACONSTRAIN_LEVEL_BASE 		4

#define RTK_COEX_TDMA_OFF_BT_SCAN_DUTY_CYCLE_THR 2     // window/interval < 1/2  
#define RTK_COEX_TDMA_OFF_BT_SCAN_THR            0x20    //20ms, unit: 0.625ms

#define RTK_COEX_BT_LE_SETUP_LINK_TIMEOUT_THR_MAX            500 //unit: 1ms
#define RTK_COEX_BT_LE_SETUP_LINK_TIMEOUT_THR_MIN            200 //unit: 1ms

//for C2H_BT_LE_AUDIO_TDMA_RPT 0x48
#define RTK_COEX_TDMA_RPT_ISO_START BIT(0)  // 0: ISO Start Indication; 1: ISO Stop Indication
#define RTK_COEX_TDMA_RPT_ISO_TRX BIT(1) // 0: ISO RX; 1: ISO TX 
#define COEX_DIFF(A,B) ((A>=B) ? (A-B):(B-A))
#define ARRAY_SIZE(arr)		(sizeof(arr) / sizeof((arr)[0]))

///////////////////////////////////////////////////////////////////
// POLICY_TYPE IMPLIMENT///////////////////////////////////////////
///////////////////////////////////////////////////////////////////
/* policy_type: u32
[B31:B29]：TDMA Ctrl Type  	-> enum rtk_coex_tdma_type
[B28:B13]: TDMA Index
	***RTK_COEX_TDMA_OFF==[B31:B29]***
	[B28:B14]: reserved
	[B13]: reg778_in_tdmaoff 	-> enum rtk_coex_tdma_off_tdma_idx
	***RTK_COEX_WL_CTRL_TDMA==[B31:B29]***
	[B28]: null_data_en
	[B27]: long_nav
	[B26]: no_tx_pause
	[B25]: bt_auto_slot
	[B24]: bt_bouncing_slot
	[B23]: wifi_dynamic_slot
	[B22:B21]: slot_num
	[B20:B17]: wl_slot_duration
	[B16:B15]: reserved
	[B14]: reg778_in_wl_slot
	[B13]: reg778_in_bt_slot
	***RTK_COEX_BT_CTRL_TDMA==[B31:B29]***
	[B28]: null_data_en
	[B27]: long_nav
	[B26]: no_tx_pause
	[B25:B15]: reserved
	[B14]: reg778_in_wl_slot
	[B13]: reg778_in_bt_slot
	***RTK_COEX_TDMA_EXT==[B31:B29]***
	[B28:B13]: reserved
	***RTK_COEX_DRV_CTRL_TDMA==[B31:B29]***
	[B28:B20]: reserved
	[B19:18]: reg778_in_wl_slot
	[B17:16]: reg778_in_bt_slot
	[B15:B13]: -> enum rtk_coex_wl_tdma_drvc_type
[B12:B10]：Break Table  -> enum rtk_coex_break_btl
[B9:B5]: WL Coex Table	-> enum rtk_coex_bt_wl_tbl_type
[B4:B0]: BT Coex Table	-> enum rtk_coex_bt_wl_tbl_type
*/

#if (SYSTEM_ENDIAN == PLATFORM_LITTLE_ENDIAN)
union policy_type_u {
	u32 raw;
	struct {
		u32 bt_tbl_idx: 5;	/// !!! bit pos must same in bits_tdmaoff/bits_tdmawlc/bits_tdmabtc/bits_tdmadrvc
		u32 wl_tbl_idx: 5;	/// !!! bit pos must same in bits_tdmaoff/bits_tdmawlc/bits_tdmabtc/bits_tdmadrvc
		u32 brk_tbl_idx: 3;	/// !!! bit pos must same in bits_tdmaoff/bits_tdmawlc/bits_tdmabtc/bits_tdmadrvc
		u32 reg778: 1;
		u32 reserved: 15;
		u32 tdma_type: 3;	/// !!! bit pos must same in bits_tdmaoff/bits_tdmawlc/bits_tdmabtc/bits_tdmadrvc
	} bits_tdmaoff;
	struct {
		u32 bt_tbl_idx: 5;	/// !!! bit pos must same in bits_tdmaoff/bits_tdmawlc/bits_tdmabtc/bits_tdmadrvc
		u32 wl_tbl_idx: 5;	/// !!! bit pos must same in bits_tdmaoff/bits_tdmawlc/bits_tdmabtc/bits_tdmadrvc
		u32 brk_tbl_idx: 3;	/// !!! bit pos must same in bits_tdmaoff/bits_tdmawlc/bits_tdmabtc/bits_tdmadrvc
		u32 reg778_in_bt_slot: 1;
		u32 reg778_in_wl_slot: 1;
		u32 reserved: 2;
		u32 wl_slot_duration: 4;
		u32 slot_num: 2;
		u32 wifi_dynamic_slot: 1;
		u32 bt_bouncing_slot: 1;
		u32 bt_auto_slot: 1;
		u32 no_tx_pause: 1;
		u32 long_nav: 1;
		u32 null_data_en: 1;
		u32 tdma_type: 3;	/// !!! bit pos must same in bits_tdmaoff/bits_tdmawlc/bits_tdmabtc/bits_tdmadrvc
	} bits_tdmawlc;
	struct {
		u32 bt_tbl_idx: 5;	/// !!! bit pos must same in bits_tdmaoff/bits_tdmawlc/bits_tdmabtc/bits_tdmadrvc
		u32 wl_tbl_idx: 5;	/// !!! bit pos must same in bits_tdmaoff/bits_tdmawlc/bits_tdmabtc/bits_tdmadrvc
		u32 brk_tbl_idx: 3;	/// !!! bit pos must same in bits_tdmaoff/bits_tdmawlc/bits_tdmabtc/bits_tdmadrvc
		u32 reg778_in_bt_slot: 1;
		u32 reg778_in_wl_slot: 1;
		u32 reserved: 11;
		u32 no_tx_pause: 1;
		u32 long_nav: 1;
		u32 null_data_en: 1;
		u32 tdma_type: 3;	/// !!! bit pos must same in bits_tdmaoff/bits_tdmawlc/bits_tdmabtc/bits_tdmadrvc
	} bits_tdmabtc;
	struct {
		u32 bt_tbl_idx: 5;	/// !!! bit pos must same in bits_tdmaoff/bits_tdmawlc/bits_tdmabtc/bits_tdmadrvc
		u32 wl_tbl_idx: 5;	/// !!! bit pos must same in bits_tdmaoff/bits_tdmawlc/bits_tdmabtc/bits_tdmadrvc
		u32 brk_tbl_idx: 3;	/// !!! bit pos must same in bits_tdmaoff/bits_tdmawlc/bits_tdmabtc/bits_tdmadrvc
		u32 drvc_type: 3;
		u32 reg778_in_bt_slot: 2;
		u32 reg778_in_wl_slot: 2;
		u32 reserved: 9;
		u32 tdma_type: 3;	/// !!! bit pos must same in bits_tdmaoff/bits_tdmawlc/bits_tdmabtc/bits_tdmadrvc
	} bits_tdmadrvc;
};
#else
union policy_type_u {
	u32 raw;
	struct {
		u32 tdma_type: 3;
		u32 reserved: 15;
		u32 reg778: 1;
		u32 brk_tbl_idx: 3;
		u32 wl_tbl_idx: 5;
		u32 bt_tbl_idx: 5;
	} bits_tdmaoff;
	struct {
		u32 tdma_type: 3;
		u32 null_data_en: 1;
		u32 long_nav: 1;
		u32 no_tx_pause: 1;
		u32 bt_auto_slot: 1;
		u32 bt_bouncing_slot: 1;
		u32 wifi_dynamic_slot: 1;
		u32 slot_num: 2;
		u32 wl_slot_duration: 4;
		u32 reserved: 2;
		u32 reg778_in_wl_slot: 1;
		u32 reg778_in_bt_slot: 1;
		u32 brk_tbl_idx: 3;
		u32 wl_tbl_idx: 5;
		u32 bt_tbl_idx: 5;
	} bits_tdmawlc;
	struct {
		u32 tdma_type: 3;
		u32 null_data_en: 1;
		u32 long_nav: 1;
		u32 no_tx_pause: 1;
		u32 reserved: 11;
		u32 reg778_in_wl_slot: 1;
		u32 reg778_in_bt_slot: 1;
		u32 brk_tbl_idx: 3;
		u32 wl_tbl_idx: 5;
		u32 bt_tbl_idx: 5;
	} bits_tdmabtc;
	struct {
		u32 tdma_type: 3;
		u32 reserved: 9;
		u32 reg778_in_wl_slot: 2;
		u32 reg778_in_bt_slot: 2;
		u32 drvc_type: 3;
		u32 brk_tbl_idx: 3;
		u32 wl_tbl_idx: 5;
		u32 bt_tbl_idx: 5;
	} bits_tdmadrvc;
};
#endif

// COMMON
// set
#define SET_POLICY_UNDEFINED()	{.raw = 0xFFFFFFFF}
#define SET_BOOL(X)				((X) ? 1 : 0)
#define NULL_DATA(X)		 	SET_BOOL(X)
#define LONG_NAV(X)				SET_BOOL(X)
#define NO_TXPAUSE(X)			SET_BOOL(X)
#define BT_AUTO_SLOT(X)			SET_BOOL(X)
#define BT_BOUNCING_SLOT(X) 	SET_BOOL(X)
#define WIFI_DYNAMIC_SLOT(X) 	SET_BOOL(X)
#define DURATION_MIN			10
#define DURATION_MAX			85 // [10:5:85] mapping to [0:f]
#define DURATION_DIV			5
#define COEX_CLIP(X, MIN, MAX) 	((X < MIN) ? (MIN) : ((X > MAX) ? (MAX) : X))
#define WL_SLOT_DURATION(WL_SLOT_PERCENT) ((COEX_CLIP(WL_SLOT_PERCENT, DURATION_MIN, DURATION_MAX) - DURATION_MIN)/DURATION_DIV)
enum SLOT_NUM_e {
	SLOT_NUM_2 = 0,
	SLOT_NUM_4 = 1,
};
enum REG778_VALUE {
	REG778_0x1 = 0, //1 and D must be located in the first
	REG778_0xD = 1, //1 and D must be located in the first
	REG778_0x9 = 2,
	REG778_0x3 = 3,
};
#define SLOT_NUM(X)				((X==2)?(SLOT_NUM_2):((X==4)?(SLOT_NUM_4):(SLOT_NUM_2)))
#define REG778(X)				((X==0xd)?(REG778_0xD):((X==0x1)?(REG778_0x1):((X==0x9)?(REG778_0x9):((X==0x3)?(REG778_0x3):REG778_0x1))))
#define REG778_TDMAOFF(x) 		REG778(x)
#define REG778_WL_SLOT(x) 		REG778(x)
#define REG778_BT_SLOT(x) 		REG778(x)
// get
#define GET_SLOTNUM_VALUE(X)	((X==SLOT_NUM_2) ? (2):((X==SLOT_NUM_4)?(4):(2)))
#define GET_REG778_VALUE(X)		((X==REG778_0xD)?(0xD):((X==REG778_0x1)?(0x1):((X==REG778_0x9)?(0x9):((X==REG778_0x3)?(0x3):(0x1)))))
#define GET_DURATION_VALUE(X)	(X * DURATION_DIV + DURATION_MIN)
static inline u32 GET_POLICY_TDMA_TYPE(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return temp.bits_tdmaoff.tdma_type;
}
static inline u32 GET_POLICY_BRK_TBL_IDX(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return temp.bits_tdmaoff.brk_tbl_idx;
}
static inline u32 GET_POLICY_WL_TBL_IDX(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return temp.bits_tdmaoff.wl_tbl_idx;
}
static inline u32 GET_POLICY_BT_TBL_IDX(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return temp.bits_tdmaoff.bt_tbl_idx;
}
static inline u32 GET_POLICY_TDMA_ALL(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	temp.bits_tdmaoff.brk_tbl_idx = 0;
	temp.bits_tdmaoff.wl_tbl_idx = 0;
	temp.bits_tdmaoff.bt_tbl_idx = 0;
	return temp.raw;
}
static inline u32 GET_POLICY_TABLE_ALL(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	temp.bits_tdmaoff.tdma_type = 0;
	temp.bits_tdmaoff.reserved = 0;
	temp.bits_tdmaoff.reg778 = 0;
	return temp.raw;
}

// RTK_COEX_TDMA_OFF
// set
#define SET_POLICY_TDMA_OFF(val_tdma_type, val_reg778, val_brk_tbl_idx, val_wl_tbl_idx, val_bt_tbl_idx) \
							{												\
								.bits_tdmaoff.tdma_type = val_tdma_type,	\
								.bits_tdmaoff.reg778 = val_reg778,			\
								.bits_tdmaoff.brk_tbl_idx = val_brk_tbl_idx,\
								.bits_tdmaoff.wl_tbl_idx = val_wl_tbl_idx,	\
								.bits_tdmaoff.bt_tbl_idx = val_bt_tbl_idx,	\
							}
// get
static inline u32 GET_POLICY_OFF_REG778(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return GET_REG778_VALUE(temp.bits_tdmaoff.reg778);
}

// RTK_COEX_WL_CTRL_TDMA
// set
#define SET_POLICY_TDMA_WLC(val_tdma_type, val_null_data, val_longnav, val_no_txpause, val_bt_autoslot, val_bt_bouncingslot, val_wifi_dynamic_slot,val_slot_num, \
							val_wl_slot_duration, val_reg778_in_wl_slot, val_reg778_in_bt_slot, val_brk_tbl_idx, val_wl_tbl_idx, val_bt_tbl_idx) \
							{															\
								.bits_tdmawlc.tdma_type = val_tdma_type,				\
								.bits_tdmawlc.null_data_en = val_null_data,				\
								.bits_tdmawlc.long_nav = val_longnav,					\
								.bits_tdmawlc.no_tx_pause = val_no_txpause,				\
								.bits_tdmawlc.bt_auto_slot = val_bt_autoslot,			\
								.bits_tdmawlc.bt_bouncing_slot = val_bt_bouncingslot,	\
								.bits_tdmawlc.wifi_dynamic_slot = val_wifi_dynamic_slot,\
								.bits_tdmawlc.slot_num = val_slot_num,					\
								.bits_tdmawlc.wl_slot_duration = val_wl_slot_duration,	\
								.bits_tdmawlc.reg778_in_wl_slot = val_reg778_in_wl_slot,\
								.bits_tdmawlc.reg778_in_bt_slot = val_reg778_in_bt_slot,\
								.bits_tdmawlc.brk_tbl_idx = val_brk_tbl_idx,			\
								.bits_tdmawlc.wl_tbl_idx = val_wl_tbl_idx,				\
								.bits_tdmawlc.bt_tbl_idx = val_bt_tbl_idx,				\
							}
// get
static inline u32 GET_POLICY_WLC_NULL_DATA(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return temp.bits_tdmawlc.null_data_en;
}
static inline u32 GET_POLICY_WLC_LONG_NAV(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return temp.bits_tdmawlc.long_nav;
}
static inline u32 GET_POLICY_WLC_NO_TXPAUSE(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return temp.bits_tdmawlc.no_tx_pause;
}
static inline u32 GET_POLICY_WLC_BT_AUTO_SLOT(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return temp.bits_tdmawlc.bt_auto_slot;
}
static inline u32 GET_POLICY_WLC_BT_BOUNCING_SLOT(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return temp.bits_tdmawlc.bt_bouncing_slot;
}
static inline u32 GET_POLICY_WLC_WIFI_DYNAMIC_SLOT(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return temp.bits_tdmawlc.wifi_dynamic_slot;
}
static inline u32 GET_POLICY_WLC_SLOT_NUM(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return GET_SLOTNUM_VALUE(temp.bits_tdmawlc.slot_num);
}
static inline u32 GET_POLICY_WLC_WL_SLOT_DURATION(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return GET_DURATION_VALUE(temp.bits_tdmawlc.wl_slot_duration);
}
static inline u32 GET_POLICY_WLC_REG778_IN_WL_SLOT(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return GET_REG778_VALUE(temp.bits_tdmawlc.reg778_in_wl_slot);
}
static inline u32 GET_POLICY_WLC_REG778_IN_BT_SLOT(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return GET_REG778_VALUE(temp.bits_tdmawlc.reg778_in_bt_slot);
}

// RTK_COEX_BT_CTRL_TDMA
// set
#define SET_POLICY_TDMA_BTC(val_tdma_type, val_null_data, val_longnav, val_no_txpause, val_reg778_in_wl_slot, val_reg778_in_bt_slot, \
							val_brk_tbl_idx, val_wl_tbl_idx, val_bt_tbl_idx) \
							{															\
								.bits_tdmabtc.tdma_type = val_tdma_type,				\
								.bits_tdmabtc.null_data_en = val_null_data,				\
								.bits_tdmabtc.long_nav = val_longnav,					\
								.bits_tdmabtc.no_tx_pause = val_no_txpause,				\
								.bits_tdmabtc.reg778_in_wl_slot = val_reg778_in_wl_slot,\
								.bits_tdmabtc.reg778_in_bt_slot = val_reg778_in_bt_slot,\
								.bits_tdmabtc.brk_tbl_idx = val_brk_tbl_idx,			\
								.bits_tdmabtc.wl_tbl_idx = val_wl_tbl_idx,				\
								.bits_tdmabtc.bt_tbl_idx = val_bt_tbl_idx,				\
							}
// get
static inline u32 GET_POLICY_BTC_NULL_DATA(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return temp.bits_tdmabtc.null_data_en;
}
static inline u32 GET_POLICY_BTC_LONG_NAV(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return temp.bits_tdmabtc.long_nav;
}
static inline u32 GET_POLICY_BTC_NO_TXPAUSE(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return temp.bits_tdmabtc.no_tx_pause;
}
static inline u32 GET_POLICY_BTC_REG778_IN_WL_SLOT(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return GET_REG778_VALUE(temp.bits_tdmabtc.reg778_in_wl_slot);
}
static inline u32 GET_POLICY_BTC_REG778_IN_BT_SLOT(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return GET_REG778_VALUE(temp.bits_tdmabtc.reg778_in_bt_slot);
}

// RTK_COEX_TDMA_EXT
// TODO

// RTK_COEX_DRV_CTRL_TDMA
// set
#define SET_POLICY_TDMA_DRVC(val_tdma_type, val_reg778_in_wl_slot, val_reg778_in_bt_slot, val_drvc_type, val_brk_tbl_idx, val_wl_tbl_idx, val_bt_tbl_idx) \
							{												\
								.bits_tdmadrvc.tdma_type = val_tdma_type,	\
								.bits_tdmadrvc.reg778_in_wl_slot = val_reg778_in_wl_slot,		\
								.bits_tdmadrvc.reg778_in_bt_slot = val_reg778_in_bt_slot,		\
								.bits_tdmadrvc.drvc_type = val_drvc_type,	\
								.bits_tdmadrvc.brk_tbl_idx = val_brk_tbl_idx,\
								.bits_tdmadrvc.wl_tbl_idx = val_wl_tbl_idx,	\
								.bits_tdmadrvc.bt_tbl_idx = val_bt_tbl_idx,	\
							}
// get
static inline u32 GET_POLICY_DRVC_TYPE(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return temp.bits_tdmadrvc.drvc_type;
}
static inline u32 GET_POLICY_DRVC_REG778_IN_WL_SLOT(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return GET_REG778_VALUE(temp.bits_tdmadrvc.reg778_in_wl_slot);
}
static inline u32 GET_POLICY_DRVC_REG778_IN_BT_SLOT(u32 policy)
{
	union policy_type_u temp = {.raw = policy};
	return GET_REG778_VALUE(temp.bits_tdmadrvc.reg778_in_bt_slot);
}
///////////////////////////////////////////////////////////////////
// END OF POLICY_TYPE IMPLIMENT////////////////////////////////////
///////////////////////////////////////////////////////////////////



enum rtk_coex_wl_chip_id {
	RTK_COEX_WL_CHIP_ID_UNDEF = 0x0,
	RTK_COEX_WL_CHIP_ID_8720E = 0x1,
	RTK_COEX_WL_CHIP_ID_8730E = 0x2,
	RTK_COEX_WL_CHIP_ID_8721DA = 0x3,
	RTK_COEX_WL_CHIP_ID_8721F = 0x4,
	RTK_COEX_WL_CHIP_ID_8721D = 0x6,
	RTK_COEX_WL_CHIP_ID_MAX = 0xFF
};

enum rtk_coex_bt_ant_pos {
	RTK_COEX_BT_ANT_POS_S0 = 0x0,
	RTK_COEX_BT_ANT_POS_S1 = 0x1
};

enum rtk_coex_bt_ant_type {
	RTK_COEX_BT_WIFI_SHARED_ANT = 0x0,
	RTK_COEX_BT_WIFI_DEDICATED_ANT = 0x1
};

enum rtk_coex_gnt_state {
	RTK_COEX_GNT_HW	= 0,
	RTK_COEX_GNT_SW_LO,
	RTK_COEX_GNT_SW_HI,
	RTK_COEX_GNT_MAX
};

enum rtk_coex_wl_pri_mask_type {
	RTK_COEX_WL_MASK_TX_RESP = 0x0,
	RTK_COEX_WL_MASK_TX_BEACON,
	RTK_COEX_WL_MASK_TX_BEACON_QUEUE,
	RTK_COEX_WL_MASK_RX_CCK,
	RTK_COEX_WL_MASK_CPUMGQ
};

#if CONFIG_COEX_SCBD_BIT_MODE == RTK_COEX_SCBD_32BIT_MODE

enum rtk_coex_scbd_wl2bt {
	RTK_COEX_SCBD_W2B_ACTIVE			= BIT0,
	RTK_COEX_SCBD_W2B_ON				= BIT1,
	RTK_COEX_SCBD_W2B_SCAN				= BIT2,
	RTK_COEX_SCBD_W2B_RX_GAIN			= BIT4,
	RTK_COEX_SCBD_W2B_RX_SCAN_PRI		= BIT5,
	RTK_COEX_SCBD_W2B_WLBUSY			= BIT7,
	RTK_COEX_SCBD_W2B_TDMA				= BIT9,
	RTK_COEX_SCBD_W2B_BR_EDR_SUPPORT	= BIT12,
	RTK_COEX_SCBD_W2B_BT_HILNA			= BIT13
};
enum rtk_coex_scbd_bt2wl {
	RTK_COEX_SCBD_B2W_ACTIVE		= BIT0,
	RTK_COEX_SCBD_B2W_ON			= BIT1,
	RTK_COEX_SCBD_B2W_S1			= BIT3,
	RTK_COEX_SCBD_B2W_A2DP_ACT		= BIT4,
	RTK_COEX_SCBD_B2W_LPS 			= BIT7,
	RTK_COEX_SCBD_B2W_LNAB0			= BIT8,
	RTK_COEX_SCBD_B2W_AVRCP_PAUSE	= BIT9,
	RTK_COEX_SCBD_B2W_LNAB1			= BIT10,
	RTK_COEX_SCBD_B2W_EN_BREDR 		= BIT12,
	RTK_COEX_SCBD_B2W_GAIN_TBL 		= BIT13,
	RTK_COEX_SCBD_B2W_RCV_CNT_CODE	= BIT15,
	RTK_COEX_SCBD_B2W_CONNECT		= BIT16,
	RTK_COEX_SCBD_B2W_NTF_SOF_EOF	= BIT17,
	RTK_COEX_SCBD_B2W_SOF_EOF_CTRL	= BIT18,
	RTK_COEX_SCBD_B2W_PATCH_DL		= BIT30
};

#elif CONFIG_COEX_SCBD_BIT_MODE == RTK_COEX_SCBD_8BIT_MODE
#define	RTK_COEX_SCBD_NOT_SUPPORT_BIT  0
enum rtk_coex_scbd_wl2bt {
	RTK_COEX_SCBD_W2B_ACTIVE		= BIT0,
	RTK_COEX_SCBD_W2B_ON			= BIT1,
	RTK_COEX_SCBD_W2B_SCAN			= BIT2,
	RTK_COEX_SCBD_W2B_RX_SCAN_PRI	= BIT5,
	/* follow bits not support for 8 bit scbd ICs */
	RTK_COEX_SCBD_W2B_RX_GAIN		= RTK_COEX_SCBD_NOT_SUPPORT_BIT,
	RTK_COEX_SCBD_W2B_WLBUSY		= RTK_COEX_SCBD_NOT_SUPPORT_BIT,
	RTK_COEX_SCBD_W2B_TDMA			= RTK_COEX_SCBD_NOT_SUPPORT_BIT,
	RTK_COEX_SCBD_W2B_BR_EDR_SUPPORT = RTK_COEX_SCBD_NOT_SUPPORT_BIT,
	RTK_COEX_SCBD_W2B_BT_HILNA		= RTK_COEX_SCBD_NOT_SUPPORT_BIT
};

enum rtk_coex_scbd_bt2wl {
	RTK_COEX_SCBD_B2W_ACTIVE		= BIT0,
	RTK_COEX_SCBD_B2W_ON			= BIT1,
	RTK_COEX_SCBD_B2W_LPS 			= BIT2,
	RTK_COEX_SCBD_B2W_PATCH_DL		= BIT3,
	RTK_COEX_SCBD_B2W_CONNECT		= BIT4,
	/* follow bits not support for 8 bit scbd ICs */
	RTK_COEX_SCBD_B2W_S1			= RTK_COEX_SCBD_NOT_SUPPORT_BIT,
	RTK_COEX_SCBD_B2W_A2DP_ACT		= RTK_COEX_SCBD_NOT_SUPPORT_BIT,
	RTK_COEX_SCBD_B2W_LNAB0			= RTK_COEX_SCBD_NOT_SUPPORT_BIT,
	RTK_COEX_SCBD_B2W_AVRCP_PAUSE	= RTK_COEX_SCBD_NOT_SUPPORT_BIT,
	RTK_COEX_SCBD_B2W_LNAB1			= RTK_COEX_SCBD_NOT_SUPPORT_BIT,
	RTK_COEX_SCBD_B2W_EN_BREDR		= RTK_COEX_SCBD_NOT_SUPPORT_BIT,
	RTK_COEX_SCBD_B2W_GAIN_TBL 		= RTK_COEX_SCBD_NOT_SUPPORT_BIT,
	RTK_COEX_SCBD_B2W_RCV_CNT_CODE	= RTK_COEX_SCBD_NOT_SUPPORT_BIT,
	RTK_COEX_SCBD_B2W_NTF_SOF_EOF	= RTK_COEX_SCBD_NOT_SUPPORT_BIT,
	RTK_COEX_SCBD_B2W_SOF_EOF_CTRL	= RTK_COEX_SCBD_NOT_SUPPORT_BIT
};
#else
#error "CONFIG_COEX_SCBD_BIT_MODE NOT DEFINE !!"
#endif

enum rtk_coex_wl_mode {
	RTK_COEX_WL_MODE_NONE = 0,
	RTK_COEX_WL_MODE_STA = BIT0,
	RTK_COEX_WL_MODE_AP = BIT1,
	RTK_COEX_WL_MODE_P2P_DEVICE = BIT2,
	RTK_COEX_WL_MODE_P2P_GC = BIT3,
	RTK_COEX_WL_MODE_P2P_GO = BIT4,
	RTK_COEX_WL_MODE_NAN = BIT5,
};

enum rtk_coex_wl_bw_type {
	RTK_COEX_WL_BW_20 = 0x0,
	RTK_COEX_WL_BW_40 = 0x1
};

enum rtk_coex_bt_le_role {
	RTK_COEX_BT_LE_IDLE 			= 0,
	RTK_COEX_BT_LE_ADV 				= BIT0,
	RTK_COEX_BT_LE_CONNECTED 		= BIT1,
	RTK_COEX_BT_LE_SCAN 			= BIT2,
	RTK_COEX_BT_LE_CONNECTING 		= BIT3,
	RTK_COEX_BT_LE_ISO_BRO 			= BIT4,
	RTK_COEX_BT_LE_SYNC				= BIT5,
};

enum rtk_coex_bt_cnt_type {
	RTK_COEX_BT_TX_HI = 0,
	RTK_COEX_BT_TX_LO,
	RTK_COEX_BT_RX_HI,
	RTK_COEX_BT_RX_LO,
	RTK_COEX_BT_CNT_MAX,
};


enum rtk_coex_bt_mp_report_sub_id {
	RTK_COEX_BT_MP_REPORT_LE_SCAN_TYPE	 = 0x2D,
	RTK_COEX_BT_MP_REPORT_LE_SCAN_PARAM = 0x2E
};

enum rtk_coex_bt_mp_report_ble_scan_type {
	RTK_COEX_LE_BG_SCAN		= BIT0,
	RTK_COEX_LE_INIT_SCAN	= BIT1,
	RTK_COEX_LE_SCAN		= BIT2
};


enum rtk_coex_ant_phase {
	RTK_COEX_ANT_WL_INIT = 0x0,
	RTK_COEX_ANT_WL_ONLY,
	RTK_COEX_ANT_BT_ONLY,
	RTK_COEX_ANT_WL_OFF,
	RTK_COEX_ANT_WL_2G,
	RTK_COEX_ANT_WL_5G,
	RTK_COEX_ANT_WL_RFK,
	RTK_COEX_ANT_BT_RFK,
	RTK_COEX_ANT_SW_CTRL,
	RTK_COEX_ANT_MANUAL = 0xFF,
};

enum rtk_coex_rfk_state {
	RTK_COEX_RFK_STOP = 0,
	RTK_COEX_RFK_START
};

enum rtk_coex_tdma_type {
	RTK_COEX_TDMA_OFF 			= 0x0,
	RTK_COEX_WL_CTRL_TDMA 		= 0x1,
	RTK_COEX_BT_CTRL_TDMA 		= 0x2,
	RTK_COEX_TDMA_EXT 			= 0x3,
	RTK_COEX_DRV_CTRL_TDMA		= 0x4,
	RTK_COEX_TDMA_MAX 			= 0xF
};

enum rtk_coex_slot_index {
	RTK_COEX_SLOT_WL1,
	RTK_COEX_SLOT_BT1,
	RTK_COEX_SLOT_WL2,
	RTK_COEX_SLOT_BT2,
} ;

enum rtk_coex_slot_type {
	RTK_COEX_WL_SLOT,
	RTK_COEX_BT_SLOT
} ;

struct rtk_coex_bt_wl_tbl_type_t {
	u32 RTK_COEX_TBL_EQ;
	u32 RTK_COEX_TBL_BT;
	u32 RTK_COEX_TBL_BT_TX_WL_HI;
	u32 RTK_COEX_TBL_WL;
	u32 RTK_COEX_TBL_WL_HI_BT_HI;
	u32 RTK_COEX_TBL_BT_HI_WL;
	u32 RTK_COEX_TBL_WL_HI_BT_HI_TX;
	u32 RTK_COEX_TBL_WL_HI_RX_BT_HI;
	u32 RTK_COEX_TBL_BT_HI_TX_WL_HI_TX;
	u32 RTK_COEX_TBL_WL_HI_BT_HI_RX;
	u32 RTK_COEX_TBL_BT_HI_RX_WL;
	u32 RTK_COEX_TBL_BT_HI_TX_WL;
	u32 RTK_COEX_TBL_WL_HI_BT;
	u32 RTK_COEX_TBL_BT_TX_WL_TX;
};
#if defined(RTK_COEX_POLICY_GLOBAL_VARIABLES_DEFINE)
//!!! comment format must not changed: /* AA > BB*/
const struct rtk_coex_bt_wl_tbl_type_t g_rtk_coex_bt_wl_tbl_type = {
	.RTK_COEX_TBL_EQ = 0xFFFFFFFF,					/* B = W */
	.RTK_COEX_TBL_BT = 0x55555555,					/* B > W */
	.RTK_COEX_TBL_BT_TX_WL_HI = 0x66555555,			/* BT > WHT > BR > W */
	.RTK_COEX_TBL_WL = 0xAAAAAAAA,					/* W > B */
	.RTK_COEX_TBL_WL_HI_BT_HI = 0xAAAA5A5A,			/* WH > BH > WL > BL */
	.RTK_COEX_TBL_BT_HI_WL = 0x5A5A5A5A,			/* BH > W > BL */
	.RTK_COEX_TBL_WL_HI_BT_HI_TX = 0xAAAA6A6A, 		/* WH > BHT > W > B */
	.RTK_COEX_TBL_WL_HI_RX_BT_HI = 0x5AAA5A5A,		/* WHR > BH > W > BL */
	.RTK_COEX_TBL_BT_HI_TX_WL_HI_TX = 0x6A5A5A5A,	/* BHT > WHT > BHR> W > BL */
	.RTK_COEX_TBL_WL_HI_BT_HI_RX = 0xAAAA9A9A,		/* WH > BHR > WL > B */
	.RTK_COEX_TBL_BT_HI_RX_WL = 0x9A9A9A9A,			/* BHR > W > B */
	.RTK_COEX_TBL_BT_HI_TX_WL = 0x6A6A6A6A,			/* BHT > W > B */
	.RTK_COEX_TBL_WL_HI_BT = 0xAAAA5555,			/* WH > B > WL */
	.RTK_COEX_TBL_BT_TX_WL_TX = 0x66556655,  		/* BT > WT > BR > WR */
};
#else
extern const struct rtk_coex_bt_wl_tbl_type_t g_rtk_coex_bt_wl_tbl_type;
#endif

// rtk_coex_bt_wl_tbl_type
#define COEX_TBL_OFFS(x)	((u8)((u32)(&(((struct rtk_coex_bt_wl_tbl_type_t*)0)->x))/sizeof(u32)))
#define GET_COEX_TBL_VALUE_BY_OFFSET(offset)	(*((u32*)(&g_rtk_coex_bt_wl_tbl_type) + offset))
#define GET_COEX_TBL_VALUE_BY_NAME(name)		(g_rtk_coex_bt_wl_tbl_type.name)
#define COEX_WL_TBL(x)	COEX_TBL_OFFS(x)
#define COEX_BT_TBL(x)	COEX_TBL_OFFS(x)
struct rtk_coex_break_tbl_t {
	u32 RTK_COEX_BREAK_TBL_ALL;
	u32 RTK_COEX_BREAK_TBL_RX_NO_BREAK;
};
#if defined(RTK_COEX_POLICY_GLOBAL_VARIABLES_DEFINE)
const struct rtk_coex_break_tbl_t g_rtk_coex_break_tbl = {
	.RTK_COEX_BREAK_TBL_ALL = 0xFFFFFFFF,			/* break all*/
	.RTK_COEX_BREAK_TBL_RX_NO_BREAK = 0xFAFAFAFA,	/* bt break table: wl rx not break bt rx, wl break table: bt rx not break wl rx*/
};
#else
extern const struct rtk_coex_break_tbl_t g_rtk_coex_break_tbl;
#endif

// rtk_coex_break_btl
#define BRK_TBL(x)	((u8)((u32)(&(((struct rtk_coex_break_tbl_t*)0)->x))/sizeof(u32)))
#define GET_BREAK_TBL_VALUE_BY_OFFSET(offset)	(*((u32*)(&g_rtk_coex_break_tbl) + offset))
#define GET_BREAK_TBL_VALUE_BY_NAME(name)		(g_rtk_coex_break_tbl.name)

//RTK_COEX_DRV_CTRL_TDMA
enum rtk_coex_wl_tdma_drvc_type {
	RTK_COEX_WL_TDMA_DRVC_DISABLE		= 0,
	RTK_COEX_WL_TDMA_DRVC_SCAN_2_SLOT		= 1, //for WL scan + LE scan
	RTK_COEX_WL_TDMA_DRVC_SCAN_6_SLOT		= 2, //for WL scan + A2DP sink /source
	RTK_COEX_WL_TDMA_DRVC_SCAN_1_SLOT_210MS	= 3, //for WL scan + LE audio, WL slot/ISO interval > 2/3
	RTK_COEX_WL_TDMA_DRVC_SCAN_1_SLOT_300MS	= 4, //for WL scan + LE audio, WL slot/ISO interval <=1/2
	RTK_COEX_WL_TDMA_DRVC_VENDOR_SLOT,
};


/* !!! sizeof(struct rtk_coex_policy_type_t)/4 must <= 256 */
struct rtk_coex_policy_type_t {
	union policy_type_u RTK_COEX_TDMA_OFF_BT;
	union policy_type_u RTK_COEX_TDMA_OFF_WL;
	union policy_type_u RTK_COEX_TDMA_OFF_EQ0;
	union policy_type_u RTK_COEX_TDMA_OFF_EQ1;
	union policy_type_u RTK_COEX_TDMA_OFF_BWB0;
	union policy_type_u RTK_COEX_TDMA_OFF_BWB1;
	union policy_type_u RTK_COEX_TDMA_OFF_BWB2;
	union policy_type_u RTK_COEX_TDMA_OFF_BWB3;
	union policy_type_u RTK_COEX_TDMA_OFF_BWB4;
	union policy_type_u RTK_COEX_TDMA_OFF_BWB5;
	union policy_type_u RTK_COEX_TDMA_OFF_BWB6;
	union policy_type_u RTK_COEX_TDMA_OFF_BWB7;
	union policy_type_u RTK_COEX_TDMA_OFF_BWB8;
	union policy_type_u RTK_COEX_TDMA_DRVC_SCAN_2SLOT;
	union policy_type_u RTK_COEX_TDMA_DRVC_SCAN_6SLOT;
	union policy_type_u RTK_COEX_TDMA_DRVC_SCAN_1SLOT_210MS;
	union policy_type_u RTK_COEX_TDMA_DRVC_SCAN_1SLOT_300MS;
	union policy_type_u RTK_COEX_TDMA_DRVC_VENDOR_2SLOT;
	union policy_type_u RTK_COEX_WL_TDMA_FIX_SLOT_TD2030_BWB0;
	union policy_type_u RTK_COEX_WL_TDMA_FIX_SLOT_TD1634_BWB0;
	union policy_type_u RTK_COEX_WL_TDMA_FIX_SLOT_TD5050_BWB0;
	union policy_type_u RTK_COEX_WL_TDMA_FIX_SLOT_TD5050_BWB1;
	union policy_type_u RTK_COEX_WL_TDMA_FIX_SLOT_TD3268_BWB1;
	union policy_type_u RTK_COEX_WL_TDMA_FIX_SLOT_TD3218_BWB0;
	union policy_type_u RTK_COEX_WL_TDMA_FIX_SLOT_TD3218_BWB1;
	union policy_type_u RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD5842_BWB0;
	union policy_type_u RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD5050_BWB0;
	union policy_type_u RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD5050_BWB1;
	union policy_type_u RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD5050_BWB2;
	union policy_type_u RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD5050_BWB3;
	union policy_type_u RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD1684_BWB0;
	union policy_type_u RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD1684_BWB1;
	union policy_type_u RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD3268_BWB0;
	union policy_type_u RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD3268_BWB1;
	union policy_type_u RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD3268_BWB2;
	union policy_type_u RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD3268_BWB3;
	union policy_type_u RTK_COEX_WL_TDMA_AUTO_SLOT_TD3268_BWB1;
	union policy_type_u RTK_COEX_WL_PS_TDMA_AUTO_SLOT_TD1684_BWB1;
	union policy_type_u RTK_COEX_WL_PS_TDMA_AUTO_SLOT_TD3268_BWB1;
	union policy_type_u RTK_COEX_WL_PS_TDMA_AUTO_SLOT_TD3268_BWB2;
	union policy_type_u RTK_COEX_BT_TDMA_NULL_BWB0;
	union policy_type_u RTK_COEX_BT_TDMA_NULL_BWB1;
	union policy_type_u RTK_COEX_BT_TDMA_NULL_BWB2;
	union policy_type_u RTK_COEX_BT_TDMA_NULL_BWB3;
	union policy_type_u RTK_COEX_BT_TDMA_QOSNULL_BWB0;
	union policy_type_u RTK_COEX_BT_TDMA_QOSNULL_BWB1;
	union policy_type_u RTK_COEX_BT_TDMA_QOSNULL_BWB2;
	union policy_type_u RTK_COEX_BT_TDMA_QOSNULL_BWB3;
	union policy_type_u RTK_COEX_POLICY_UNDEFINED;
};

#if defined(RTK_COEX_POLICY_GLOBAL_VARIABLES_DEFINE)
const struct rtk_coex_policy_type_t g_policy_type = {
	/* TDMA Off case: PTA only*/
	/* 0x00000021, TDMA OFF + Pri 0x55555555 B > W */
	.RTK_COEX_TDMA_OFF_BT = SET_POLICY_TDMA_OFF(RTK_COEX_TDMA_OFF, REG778_TDMAOFF(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_BT), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x00000063, TDMA OFF + Pri 0xAAAAAAAA W > B*/
	.RTK_COEX_TDMA_OFF_WL = SET_POLICY_TDMA_OFF(RTK_COEX_TDMA_OFF, REG778_TDMAOFF(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL), COEX_BT_TBL(RTK_COEX_TBL_WL)),
	/* 0x00000000, TDMA OFF + Pri 0xFFFFFFFF B = W */
	.RTK_COEX_TDMA_OFF_EQ0 = SET_POLICY_TDMA_OFF(RTK_COEX_TDMA_OFF, REG778_TDMAOFF(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_EQ), COEX_BT_TBL(RTK_COEX_TBL_EQ)),
	/* 0x00002000, TDMA OFF + Pri 0xFFFFFFFF B = W + 778 = 0xD */
	.RTK_COEX_TDMA_OFF_EQ1 = SET_POLICY_TDMA_OFF(RTK_COEX_TDMA_OFF, REG778_TDMAOFF(0xD), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_EQ), COEX_BT_TBL(RTK_COEX_TBL_EQ)),
	/* 0x00000042, TDMA OFF + Pri 0x66555555 BT > WHT > BR > W */
	.RTK_COEX_TDMA_OFF_BWB0 = SET_POLICY_TDMA_OFF(RTK_COEX_TDMA_OFF, REG778_TDMAOFF(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_BT_TX_WL_HI), COEX_BT_TBL(RTK_COEX_TBL_BT_TX_WL_HI)),
	/* 0x00000084, TDMA OFF + Pri 0xAAAA5A5A WH > BH > WL > BL */
	.RTK_COEX_TDMA_OFF_BWB1 = SET_POLICY_TDMA_OFF(RTK_COEX_TDMA_OFF, REG778_TDMAOFF(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT_HI), COEX_BT_TBL(RTK_COEX_TBL_WL_HI_BT_HI)),
	/* 0x000000a5, TDMA OFF + Pri 0x5A5A5A5A BH > W > BL */
	.RTK_COEX_TDMA_OFF_BWB2 = SET_POLICY_TDMA_OFF(RTK_COEX_TDMA_OFF, REG778_TDMAOFF(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_BT_HI_WL), COEX_BT_TBL(RTK_COEX_TBL_BT_HI_WL)),
	/* 0x000000c6, TDMA OFF + Pri 0xAAAA6A6A WH > BHT > W > B */
	.RTK_COEX_TDMA_OFF_BWB3 = SET_POLICY_TDMA_OFF(RTK_COEX_TDMA_OFF, REG778_TDMAOFF(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT_HI_TX), COEX_BT_TBL(RTK_COEX_TBL_WL_HI_BT_HI_TX)),
	/* 0x00000129, TDMA OFF + Pri 0xAAAA9A9A WH > BHR > WL > B */
	.RTK_COEX_TDMA_OFF_BWB4 = SET_POLICY_TDMA_OFF(RTK_COEX_TDMA_OFF, REG778_TDMAOFF(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT_HI_RX), COEX_BT_TBL(RTK_COEX_TBL_WL_HI_BT_HI_RX)),
	/* 0x0000014a, TDMA OFF + Pri 0x9A9A9A9A BHR > W > B */
	.RTK_COEX_TDMA_OFF_BWB5 = SET_POLICY_TDMA_OFF(RTK_COEX_TDMA_OFF, REG778_TDMAOFF(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_BT_HI_RX_WL), COEX_BT_TBL(RTK_COEX_TBL_BT_HI_RX_WL)),
	/* 0x0000016b, TDMA OFF + Pri 0x6A6A6A6A BHT > W > B */
	.RTK_COEX_TDMA_OFF_BWB6 = SET_POLICY_TDMA_OFF(RTK_COEX_TDMA_OFF, REG778_TDMAOFF(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_BT_HI_TX_WL), COEX_BT_TBL(RTK_COEX_TBL_BT_HI_TX_WL)),
	/* 0x0000018c, TDMA OFF + Pri 0xAAAA5555 WH > B > WL */
	.RTK_COEX_TDMA_OFF_BWB7 = SET_POLICY_TDMA_OFF(RTK_COEX_TDMA_OFF, REG778_TDMAOFF(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT), COEX_BT_TBL(RTK_COEX_TBL_WL_HI_BT)),
	/* 0x0000018c, TDMA OFF + Pri 0x66556655 BT > WT > BR > WR */
	.RTK_COEX_TDMA_OFF_BWB8 = SET_POLICY_TDMA_OFF(RTK_COEX_TDMA_OFF, REG778_TDMAOFF(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_BT_TX_WL_TX), COEX_BT_TBL(RTK_COEX_TBL_BT_TX_WL_TX)),

	/* Driver Control TDMA case */
	/* 0x80042061, BT Slot: 0x55555555 B > W; WL Slot: 0xAAAAAAAA W > B */
	.RTK_COEX_TDMA_DRVC_SCAN_2SLOT = SET_POLICY_TDMA_DRVC(RTK_COEX_DRV_CTRL_TDMA, REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), RTK_COEX_WL_TDMA_DRVC_SCAN_2_SLOT, BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x80044061, BT Slot: 0x55555555 B > W; WL Slot: 0xAAAAAAAA W > B */
	.RTK_COEX_TDMA_DRVC_SCAN_6SLOT = SET_POLICY_TDMA_DRVC(RTK_COEX_DRV_CTRL_TDMA, REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), RTK_COEX_WL_TDMA_DRVC_SCAN_6_SLOT, BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x800460a5, BT Slot: 0x5A5A5A5A BH > W > BL; WL Slot: 0x5A5A5A5A BH > W > BL */
	.RTK_COEX_TDMA_DRVC_SCAN_1SLOT_210MS = SET_POLICY_TDMA_DRVC(RTK_COEX_DRV_CTRL_TDMA, REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), RTK_COEX_WL_TDMA_DRVC_SCAN_1_SLOT_210MS, BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_BT_HI_WL), COEX_BT_TBL(RTK_COEX_TBL_BT_HI_WL)),
	/* 0x800480a5, BT Slot: 0x5A5A5A5A BH > W > BL; WL Slot: 0x5A5A5A5A BH > W > BL */
	.RTK_COEX_TDMA_DRVC_SCAN_1SLOT_300MS = SET_POLICY_TDMA_DRVC(RTK_COEX_DRV_CTRL_TDMA, REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), RTK_COEX_WL_TDMA_DRVC_SCAN_1_SLOT_300MS, BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_BT_HI_WL), COEX_BT_TBL(RTK_COEX_TBL_BT_HI_WL)),
	/* 0x8008a0a1, BT Slot: 0x55555555 BT > WL; WL Slot: 0x5A5A5A5A BH > W > BL */
	.RTK_COEX_TDMA_DRVC_VENDOR_2SLOT = SET_POLICY_TDMA_DRVC(RTK_COEX_DRV_CTRL_TDMA, REG778_WL_SLOT(0x9), REG778_BT_SLOT(0x1), RTK_COEX_WL_TDMA_DRVC_VENDOR_SLOT, BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_BT_HI_WL), COEX_BT_TBL(RTK_COEX_TBL_BT)),

	/* WL Control TDMA case */
	/* 0x282c4102, TDMA 4 Slot: BT Slot: 0x66555555 BT > WHT > BR > W; WL Slot: 0x6A5A5A5A BHT > WHT > BHR> W > BL */
	.RTK_COEX_WL_TDMA_FIX_SLOT_TD2030_BWB0 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(0), LONG_NAV(1), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(0), SLOT_NUM(4), WL_SLOT_DURATION(40), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_BT_HI_TX_WL_HI_TX), COEX_BT_TBL(RTK_COEX_TBL_BT_TX_WL_HI)),
	/* 0x28284102, TDMA 4 Slot: BT Slot: 0x66555555 BT > WHT > BR > W; WL Slot: BHT > WHT > BHR> W > BL */
	.RTK_COEX_WL_TDMA_FIX_SLOT_TD1634_BWB0 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(0), LONG_NAV(1), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(0), SLOT_NUM(4), WL_SLOT_DURATION(32),  REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_BT_HI_TX_WL_HI_TX), COEX_BT_TBL(RTK_COEX_TBL_BT_TX_WL_HI)),
	/* 0x20104061, TDMA 2 slot: BT Slot: 0x55555555 B > W; WL Slot: 0xAAAAAAAA WL > BT */
	.RTK_COEX_WL_TDMA_FIX_SLOT_TD5050_BWB0 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(0), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(0), SLOT_NUM(2), WL_SLOT_DURATION(50), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x20104081, TDMA 2 Slot: BT Slot: 0x55555555 B > W; WL Slot: 0xAAAA5A5A WH > BH > WL > BL */
	.RTK_COEX_WL_TDMA_FIX_SLOT_TD5050_BWB1 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(0), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(0), SLOT_NUM(2), WL_SLOT_DURATION(50), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT_HI), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x200840e1, TDMA 2 slot: BT Slot: 0x55555555 B > W; WL Slot: 0x5AAA5A5A WHR > BH > W > BL */
	.RTK_COEX_WL_TDMA_FIX_SLOT_TD3268_BWB1 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(0), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(0), SLOT_NUM(2), WL_SLOT_DURATION(32), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_RX_BT_HI), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x28344061, TDMA 4 Slot: BT Slot: 0x55555555 B > W; WL Slot: 0xAAAAAAAA WL > BT */
	.RTK_COEX_WL_TDMA_FIX_SLOT_TD3218_BWB0 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(0), LONG_NAV(1), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(0), SLOT_NUM(4), WL_SLOT_DURATION(64), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x28344081, TDMA 4 Slot: BT Slot: 0x55555555 B > W; WL Slot: 0xAAAA5A5A WH > BH > WL > BL */
	.RTK_COEX_WL_TDMA_FIX_SLOT_TD3218_BWB1 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(0), LONG_NAV(1), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(0), SLOT_NUM(4), WL_SLOT_DURATION(64), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT_HI), COEX_BT_TBL(RTK_COEX_TBL_BT)),

	/* 0x309240c1, PS TDMA 2 slot: BT Slot: 0x55555555 B > W; WL Slot: 0xAAAA6A6A WH > BHT > W > B */
	.RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD5842_BWB0 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(1), SLOT_NUM(2), WL_SLOT_DURATION(58), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT_HI_TX), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x301040a5, PS TDMA 2 slot: BT Slot: 0x5A5A5A5A BH > W > BL; WL Slot: 0x5A5A5A5A BH > W > BL */
	.RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD5050_BWB0 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(0), SLOT_NUM(2), WL_SLOT_DURATION(50), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_BT_HI_WL), COEX_BT_TBL(RTK_COEX_TBL_BT_HI_WL)),
	/* 0x309040e1, PS TDMA 2 slot: BT Slot: 0x55555555 B > W; WL Slot: 0x5AAA5A5A WHR > BH > W > BL */
	.RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD5050_BWB1 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(1), SLOT_NUM(2), WL_SLOT_DURATION(50), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_RX_BT_HI), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x30104061, PS TDMA 2 slot: BT Slot: 0x55555555 B > W; WL Slot: 0xAAAAAAAA WL > BT */
	.RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD5050_BWB2 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(0), SLOT_NUM(2), WL_SLOT_DURATION(50), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x30904081, PS TDMA 2 Slot: BT Slot: 0x55555555 B > W; WL Slot: 0xAAAA5A5A WH > BH > WL > BL */
	.RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD5050_BWB3 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(1), SLOT_NUM(2), WL_SLOT_DURATION(50), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT_HI), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x308240c1, PS TDMA 2 slot: BT Slot: 0x55555555 B > W; WL Slot: 0xAAAA6A6A WH > BHT > W > B */
	.RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD1684_BWB0 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(1), SLOT_NUM(2), WL_SLOT_DURATION(16), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT_HI_TX), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x308240e1, PS TDMA 2 slot: BT Slot: 0x55555555 B > W; WL Slot: 0x5AAA5A5A WHR > BH > W > BL */
	.RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD1684_BWB1 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(1), SLOT_NUM(2), WL_SLOT_DURATION(16), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_RX_BT_HI), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x308840c1, PS TDMA 2 slot: BT Slot: 0x55555555 B > W; WL Slot: 0xAAAA6A6A  WH > BHT > W > B */
	.RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD3268_BWB0 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(1), SLOT_NUM(2), WL_SLOT_DURATION(32), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT_HI_TX), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x308840e1, PS TDMA 2 slot: BT Slot: 0x55555555 B > W; WL Slot: 0x5AAA5A5A WHR > BH > W > BL */
	.RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD3268_BWB1 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(1), SLOT_NUM(2), WL_SLOT_DURATION(32), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_RX_BT_HI), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x30884061, PS TDMA 2 slot: BT Slot: 0x55555555 B > W; WL Slot: 0xAAAAAAAA W > B */
	.RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD3268_BWB2 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(1), SLOT_NUM(2), WL_SLOT_DURATION(32), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x30884161, PS TDMA 2 slot: BT Slot: 0x55555555 B > W; WL Slot: 0x6A6A6A6A BHT > W > B */
	.RTK_COEX_WL_PS_TDMA_FIX_SLOT_TD3268_BWB3 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(0), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(1), SLOT_NUM(2), WL_SLOT_DURATION(32), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_BT_HI_TX_WL), COEX_BT_TBL(RTK_COEX_TBL_BT)),

	/* 0x22084081, TDMA On 2 AUTO slot: BT Slot: 0x55555555 B > W; WL Slot: 0xAAAA5A5A WH > BH > WL > BL */
	.RTK_COEX_WL_TDMA_AUTO_SLOT_TD3268_BWB1 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(0), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(1), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(0), SLOT_NUM(2), WL_SLOT_DURATION(32), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT_HI), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x328240e1, PS TDMA 2 AUTO slot: BT Slot: 0x55555555 B > W; WL Slot: 0x5AAA5A5A WHR > BH > W > BL */
	.RTK_COEX_WL_PS_TDMA_AUTO_SLOT_TD1684_BWB1 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(1), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(1), SLOT_NUM(2), WL_SLOT_DURATION(16), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_RX_BT_HI), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x328840e1, PS TDMA 2 AUTO slot: BT Slot: 0x55555555 B > W; WL Slot: 0x5AAA5A5A WHR > BH > W > BL */
	.RTK_COEX_WL_PS_TDMA_AUTO_SLOT_TD3268_BWB1 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(1), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(1), SLOT_NUM(2), WL_SLOT_DURATION(32), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_RX_BT_HI), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x32884061, PS TDMA 2 AUTO slot: BT Slot: 0x55555555 B > W; WL Slot: 0xAAAAAAAA W > B */
	.RTK_COEX_WL_PS_TDMA_AUTO_SLOT_TD3268_BWB2 = SET_POLICY_TDMA_WLC(RTK_COEX_WL_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), BT_AUTO_SLOT(1), BT_BOUNCING_SLOT(0), WIFI_DYNAMIC_SLOT(1), SLOT_NUM(2), WL_SLOT_DURATION(32), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL), COEX_BT_TBL(RTK_COEX_TBL_BT)),

	/*BT control TDMA  */
	/* 0x50004061, TDMA: BT slot: 0x55555555 B > W; WL Slot: 0xAAAAAAAA W > B */
	.RTK_COEX_BT_TDMA_NULL_BWB0 = SET_POLICY_TDMA_BTC(RTK_COEX_BT_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x50004121, TDMA: BT slot: 0x55555555 B > W; WL Slot: 0xAAAA9A9A WH > BHR > WL > B */
	.RTK_COEX_BT_TDMA_NULL_BWB1 = SET_POLICY_TDMA_BTC(RTK_COEX_BT_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT_HI_RX), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x500040c1, TDMA: BT slot: 0x55555555 B > W; WL Slot: 0xAAAA6A6A WH > BHT > W > B */
	.RTK_COEX_BT_TDMA_NULL_BWB2 = SET_POLICY_TDMA_BTC(RTK_COEX_BT_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT_HI_TX), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x50004081, TDMA: BT slot: 0x55555555 B > W; WL Slot: 0xAAAA5A5A WH > BH > WL > BL */
	.RTK_COEX_BT_TDMA_NULL_BWB3 = SET_POLICY_TDMA_BTC(RTK_COEX_BT_CTRL_TDMA, NULL_DATA(1), LONG_NAV(0), NO_TXPAUSE(0), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT_HI), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x48004061, TDMA: BT slot: 0x55555555 B > W; WL Slot: 0xAAAAAAAA W > B */
	.RTK_COEX_BT_TDMA_QOSNULL_BWB0 = SET_POLICY_TDMA_BTC(RTK_COEX_BT_CTRL_TDMA, NULL_DATA(0), LONG_NAV(1), NO_TXPAUSE(0), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x48004121, TDMA: BT slot: 0x55555555 B > W; WL Slot: 0xAAAA9A9A WH > BHR > WL > B */
	.RTK_COEX_BT_TDMA_QOSNULL_BWB1 = SET_POLICY_TDMA_BTC(RTK_COEX_BT_CTRL_TDMA, NULL_DATA(0), LONG_NAV(1), NO_TXPAUSE(0), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT_HI_RX), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x480040c1, TDMA: BT slot: 0x55555555 B > W; WL Slot: 0xAAAA6A6A WH > BHT > W > B */
	.RTK_COEX_BT_TDMA_QOSNULL_BWB2 = SET_POLICY_TDMA_BTC(RTK_COEX_BT_CTRL_TDMA, NULL_DATA(0), LONG_NAV(1), NO_TXPAUSE(0), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT_HI_TX), COEX_BT_TBL(RTK_COEX_TBL_BT)),
	/* 0x48004081, TDMA: BT slot: 0x55555555 B > W; WL Slot: 0xAAAA5A5A WH > BH > WL > BL */
	.RTK_COEX_BT_TDMA_QOSNULL_BWB3 = SET_POLICY_TDMA_BTC(RTK_COEX_BT_CTRL_TDMA, NULL_DATA(0), LONG_NAV(1), NO_TXPAUSE(0), REG778_WL_SLOT(0xD), REG778_BT_SLOT(0x1), BRK_TBL(RTK_COEX_BREAK_TBL_ALL), COEX_WL_TBL(RTK_COEX_TBL_WL_HI_BT_HI), COEX_BT_TBL(RTK_COEX_TBL_BT)),

	.RTK_COEX_POLICY_UNDEFINED = SET_POLICY_UNDEFINED(),
};
#else
extern const struct rtk_coex_policy_type_t g_policy_type;
#endif

#define IX(x)	((u8)((u32)(&(((struct rtk_coex_policy_type_t*)0)->x))/sizeof(union policy_type_u)))
#define GET_POLICY_BY_OFFSET(offset)	((*((union policy_type_u*)(&g_policy_type) + offset)).raw)
#define GET_POLICY_BY_NAME(name)		(g_policy_type.name.raw)

struct rtk_coex_custom_policy_t {
	u8 vid;
	u8 pid;
	u8 tbl_type;
	u8 wl_state_st;
	u8 wl_state_ed;	// [wl_state_st, wl_state_ed]
	u8 bt_state_st;
	u8 bt_state_ed;	// [bt_state_st, bt_state_ed]
	u8 policy_idx;
};

enum rtk_coex_custom_policy_tbl_type {
	TBL_REPLACE_PART = 0,
	TBL_REPLACE_ALL
};

enum rtk_coex_wl_band_type {
	RTK_COEX_WL_BAND_2G = 0x0,
	RTK_COEX_WL_BAND_5G = 0x1
};


enum rtk_coex_wl_link_mode {
	RTK_COEX_WL_LINK_NONE,
	RTK_COEX_WL_LINK_2G_STA, //2g sta only
	RTK_COEX_WL_LINK_5G_STA,
	RTK_COEX_WL_LINK_2G_AP,  //2g ap only
	RTK_COEX_WL_LINK_5G_AP,
	RTK_COEX_WL_LINK_2G_SCC,
	RTK_COEX_WL_LINK_2G_MCC,
	RTK_COEX_WL_LINK_5G_SCC,
	RTK_COEX_WL_LINK_5G_MCC,
	RTK_COEX_WL_LINK_25G_MCC,
	RTK_COEX_WL_LINK_MAX
};


enum rtk_coex_wl_chip_bt_state_map {
	RTK_COEX_WL_IDLE_BT_NOSCAN = 0x0,
	RTK_COEX_WL_IDLE_BT_SCAN,
	RTK_COEX_WL_SCAN_BT_NOSCAN,
	RTK_COEX_WL_SCAN_BT_SCAN,
	RTK_COEX_WL_LINKING,
	RTK_COEX_WL_BUSY_BT_NOSCAN,
	RTK_COEX_WL_BUSY_BT_SCAN,
	RTK_COEX_WL_CONN_BT_NOSCAN,
	RTK_COEX_WL_CONN_BT_SCAN,
};

enum rtk_coex_wl_info_update_reason {
	RTK_COEX_REASON_WL_PERIDICAL = 0x0,
	RTK_COEX_REASON_WL_STA_LINK_START,
	RTK_COEX_REASON_WL_STA_LINK_END,
	RTK_COEX_REASON_WL_STA_DISCONNECT_START,
	RTK_COEX_REASON_WL_STA_DISCONNECT_END,
	RTK_COEX_REASON_WL_AP_START,
	RTK_COEX_REASON_WL_AP_END,
	RTK_COEX_REASON_WL_SEC_KEY_EXCHANGE
};

enum rtk_coex_wl_spec_packet_evt {
	RTK_COEX_WL_PACKET_EVT_NONE = 0x0,
	RTK_COEX_WL_PACKET_EVT_DHCP = 0x1,
	RTK_COEX_WL_PACKET_EVT_ARP = 0x2,
	RTK_COEX_WL_PACKET_EVT_EAPOL = 0x3,
};
enum rtk_coex_wl_tp_status {
	RTK_COEX_WL_TP_BIT_TX	= BIT(0),
	RTK_COEX_WL_TP_BIT_RX	= BIT(1)
};
/* H2C Index: 0x60 */
struct rtk_coex_wl_chip_h2c_tdma_v1 {
	//Byte 0
	u8 tdma_enable: 1;
	u8 rsvd1: 3;
	u8 ps: 2;
	u8 allow_bt_high: 1;
	u8 btc_longnav: 1;

	//Byte 1
	u8 wl_slot_duration;

	//Byte 2
	u8 btc_second_slot: 4; //not used
	u8 rsvd3: 1;
	u8 btc_txpause: 1;
	u8 btc_nulldata: 1;
	u8 btc_tdma_enable: 1;

	//Byte 3
	u8 wl_tx_pause_disable: 1;
	u8 wl_4_slot_value_of_0x778: 1;
	u8 wl_2_slot_value_of_0x778: 1;
	u8 wl_tdma_off_value_of_0x778: 1;
	u8 slot_option: 1;
	u8 rsvd: 2;
	u8 reduce_wl_power: 1;

	//Byte 4
	u8 decision_0x778: 1;
	u8 cck_priority_toggle: 1;
	u8 bt_auto_slot: 1;
	u8 packet_control: 1;
	u8 coex_tbl_toggle: 1;
	u8 long_nav: 1;
	u8 dynamic_slot: 1;
	u8 bt_slot_778_value: 1;
};
/* H2C Index: 0x60 */
struct rtk_coex_wl_chip_h2c_tdma_v2 {
	//Byte 0
	u8 tdma_enable: 1;
	u8 four_slot_mode: 1;
	u8 null_data_en: 1;
	u8 long_nav: 1;
	u8 no_tx_pause: 1;
	u8 cck_priority_toggle: 1;
	u8 bt_auto_slot: 1;
	u8 bt_bouncing_slot: 1;

	//Byte 1
	u8 wifi_dynamic_slot: 1;
	u8 b1_rsvd: 3;
	u8 btc_tdma_tx_pause: 1;
	u8 btc_tdma_null_data_en: 1;
	u8 btc_tdma_long_nav: 1;
	u8 btc_tdma_enable: 1;

	//Byte 2
	u8 wl_slot_duration;

	//Byte 3
	u8 reg778_in_wl_slot: 4;//778=1/3/9/d
	u8 reg778_in_bt_slot: 4;


	//Byte 4
	u8 reg778_tdma_off: 4;
	u8 btc_tdma_second_slot: 4; //second bt slot, not used now
};
/* H2C Index: 0x60 */
struct rtk_coex_wl_chip_h2c_tdma_v3 {
	//Byte 0
	u8 wlc_tdma_enable: 1;
	u8 btc_tdma_enable: 1;
	u8 null_data_en: 1;
	u8 long_nav: 1;
	u8 no_tx_pause: 1;
	u8 cck_priority_toggle: 1;
	u8 bt_auto_slot: 1;
	u8 bt_bouncing_slot: 1;

	//Byte 1
	u8 wifi_dynamic_slot: 1;
	u8 disable_leak_ap: 1;
	u8 b1_rsvd: 6;

	//Byte 2
	u8 wl_slot_duration;

	//Byte 3
	u8 reg778_in_wl_slot: 4;//778=1/3/9/d
	u8 reg778_in_bt_slot: 4;


	//Byte 4
	u8 reg778_tdma_off: 4;
	u8 btc_tdma_second_slot: 4; //second bt slot, not used now

	//Byte 5
	u8 skip_insert_mode: 1;//0: insert mode; 1: skip mode;
	u8 skip_insert_times: 4;
	u8 b5_rsvd: 3;
};
struct rtk_coex_wl_chip_btinfo_lb2 {
	u8 connect: 1;
	u8 sco_eso: 1;
	u8 inq_page: 1;
	u8 acl_busy: 1;
	u8 sco_busy: 1;
	u8 hid: 1;
	u8 a2dp: 1;
	u8 rsvd: 1;
};

struct rtk_coex_wl_chip_btinfo_lb3 {
	u8 rsvd: 5;
	u8 inq: 1;
	u8 mesh_busy: 1;
	u8 page: 1;
};

struct rtk_coex_wl_chip_btinfo_hb0 {
	u8 rssi; /* dBm */
};

struct rtk_coex_wl_chip_btinfo_hb1 {
	u8 ble_connect: 1;
	u8 re_init: 1;
	u8 re_link: 1;
	u8 ignore_wl: 1;
	u8 voice: 1;
	u8 ble_scan: 1;
	u8 role_switch: 1;
	u8 multi_link: 1;
};

struct rtk_coex_wl_chip_btinfo_hb2 {
	u8 rsvd: 2;
	u8 a2dp_active: 1;
	u8 bt_slave: 1;
	u8 hid_slot: 2;
	u8 hid_cnt: 2;
};

struct rtk_coex_wl_chip_btinfo_hb3 {
	u8 bit_pool: 5; //bit_pool is 6 bit in BT info, confict with sniff bit, so change it to 5 bit in future
	u8 non_hid_sniff_link: 1;
	u8 _3m_packet: 1;
	u8 a2dp_sink: 1;
};

#if RTK_COEX_LE_EXTRA_INFO_DEF_NEW
struct rtk_coex_wl_chip_bt_le_extra_info_lb2 {
	u8 bis: 1;
	u8 bis_count: 3;
	u8 cis: 1;
	u8 cis_count: 3;
};
#else
struct rtk_coex_wl_chip_bt_le_extra_info_lb2 {
	u8 le_audio_exist: 1;
	u8 bis: 1;
	u8 cis: 1;
};
#endif
struct rtk_coex_wl_chip_bt_le_extra_info_lb3 {
	u8 rssi; /* dBm, for cis only */
};
#if RTK_COEX_LE_EXTRA_INFO_DEF_NEW
struct rtk_coex_wl_chip_bt_le_extra_info_hb0 {
	u8 ft_for_cig_0: 4;
	u8 ft_for_cig_1: 4;
};

#else
struct rtk_coex_wl_chip_bt_le_extra_info_hb0 {
	u8 rsvd;
};
#endif
struct rtk_coex_wl_chip_bt_le_extra_info_hb1 {
	u8 rsv0: 2;
	u8 le_setup_link: 1;
	u8 rsv1: 5;
};

struct rtk_coex_wl_chip_bt_le_extra_info_hb2 {
	u8 iso_interval_low;
};

struct rtk_coex_wl_chip_bt_le_extra_info_hb3 {
	u8 iso_interval_high;
};

struct rtk_coex_tdma_drvc_para {
	u8 reg778_in_wl_slot;
	u8 reg778_in_bt_slot;
};

struct rtk_coex_wl_smap {
	u32 busy: 1;
	u32 wl_tp_status: 2;
	u32 scan: 1;
	u32 connecting: 1;
	u32 roaming: 1;
	u32 dbccing: 1;
	u32 _4way: 1;
	u32 update_gtk: 1;
	u32 special_pkt: 1;

	u32 rf_off_: 1;
	u32 lps: 2;  /* 1: refer to enum btc_lps_state  */
	u32 ips: 1;
	u32 ips_pre: 1;
	u32 init_ok: 1;
	u32 traffic_dir : 2;
	u32 rf_off_pre: 1;
	u32 lps_pre: 2;
	u32 lps_exiting: 1; /* Exit-LPS to rf_state = BTC_RFCTRL_WL_ON in 6s */
};

struct rtk_coex_wl_link_info {
	u8 mode;    /* enum rtk_coex_wl_mode */
	u8 channel;
	u8 band: 1; /* enum rtk_coex_wl_band_type */
	u8 bandwidth: 1;	 /*enum rtk_coex_wl_bw_type */
	u8 media_status: 1;
	u8 busy: 1;
	u8 _4way: 1;  /* _4way flag for each port */
	u8 update_gtk: 1; /* _update_gtk flag for each port */
	u8 wl_tp_status: 2; /* enum RTK_COEX_WL_TP_STATUS */
	u16 bcn_len;
	u8 bcn_time;
	u8 rssi; /* 0%~110% (dBm = rssi -110) */
	u32 bcn_cnt;
};

struct rtk_coex_wl_scan_info {
	u16 tdma_scan_type : 3;
	u16 tdma_scan_cur_slot : 3; //tdma_scan_cur_slot bit definition must same with slot_time_num
	u16 slot_time_num : 3;
	u16 *slot_time_array;
};

struct rtk_coex_wl_5g_afh_info {
	u8 center_ch;
	u8 bt_skip_ch;
	u8 afh_span;
};

struct rtk_coex_wl_info {
	struct rtk_coex_wl_smap status;
	u8 link_mode;
	u8  conn_cnt;
	u16 role_map;
	u8  media_conn_idx_array[RTK_COEX_WL_MAX_INTF_NUM];
	struct rtk_coex_wl_link_info link_info[RTK_COEX_WL_MAX_INTF_NUM];
	u8 afh_info[3];
	struct rtk_coex_wl_scan_info scan_info;
	bool wireless_mode_11b;
	u8 cur_chnl;
	u8 cur_band; /*0:2.4G, 1:5G*/
};

struct rtk_coex_state_chg {
	u8 now: 1;
	u8 last: 1;
	u8 remain: 1;
	u8 srvd: 5;
};

struct rtk_coex_bt_a2dp_desc {
	u8 exist: 1;

	u8 active: 1;
	u8 active_last: 1;
	u8 active_remain: 1;
	u8 sink: 1;
	u8 bit_pool: 5; //bit_pool is 6 bit in BT info, confict with sniff bit, so change it to 5 bit in future
};

struct rtk_coex_bt_hid_desc {
	u8 exist: 1;

	u8 hid_slot: 2;
	u8 hid_pair_cnt: 2;
};

struct rtk_coex_bt_le_audio_desc {
	u8 exist: 1;

	u8 bis: 1;
	u8 bis_count: 3;
	u8 cis: 1;
	u8 cis_count: 3;
	u8 ft_for_cig_0: 4;
	u8 ft_for_cig_1: 4;
	u8 bt_le_audio_iso_tx: 1;
	u8 bt_le_audio_iso_rx: 1;

	u8 rssi; /* 0%~100% (dBm = rssi - 100) */
	u16 bt_iso_interval;//unit:ms
	u8 bt_iso_wl_slot; //unit:ms
	u8 wl_ra_mask_flt; /*enum btc_wl_ra_mask_flt*/
};

struct rtk_coex_bt_link_info {
	struct rtk_coex_state_chg re_link;
	struct rtk_coex_state_chg multi_link;
	struct rtk_coex_bt_a2dp_desc a2dp_desc;
	struct rtk_coex_bt_hid_desc hid_desc;
	struct rtk_coex_bt_le_audio_desc le_audio_desc;
	u8 rssi;  /* 0%~100% (dBm = rssi - 100) */
	u8 role_switch: 1;
	u8 legacy_slave: 1;
	u8 sniff: 1;
	u8 bt_info_raw[RTK_COEX_BT_INFO_LENGTH];
	u8 le_extra_info_raw[RTK_COEX_BT_INFO_LENGTH];
};

struct rtk_coex_bt_smap {
	u8 connect: 1;
	u8 ble_connect: 1;
	u8 acl_busy: 1;
	u8 sco_busy: 1;
	u8 mesh_busy: 1;
	u8 ble_busy: 1;
	u8 inq_pag: 1;
	u8 ble_scan: 1;
	u8 le_setup_link: 1;
};

struct rtk_coex_bt_scan_info {
	u8 le_scan_type;      //enum rtk_coex_bt_mp_report_ble_scan_type
	u16 le_scan_interval;
	u16 le_scan_window;
};

struct rtk_coex_bt_info {
	struct rtk_coex_bt_smap status;
	struct rtk_coex_state_chg enable;
	struct rtk_coex_bt_link_info link_info;
	struct rtk_coex_bt_scan_info scan_info;
	u32 cnt[RTK_COEX_BT_CNT_MAX];
	u8 bt_le_role;
	u8 profile_map;
	u8 ignore_wl: 1;
	u8 inq: 1;
	u8 page: 1;
	u8 hi_lna_rx: 1;
	u8 run_patch_code: 1;
	u8 lna_constrain: 3;
	u8 get_ver_done: 1;
	u8 b_rcv_spec_acl_pkt: 1;
};

struct rtk_coex_ext_info {
};

struct rtk_coex_wl_board_info {
	u8 rfe_type;
	u8 ant_type;	//enum rtk_coex_bt_ant_type
	u8 ant_div_cfg;
	u8 bt_pos;		//enum rtk_coex_bt_ant_pos
};

struct rtk_coex_rfk_info {
	ATOMIC_T in_progress;
	ATOMIC_T ref;
	u8 rfk_type: 1;
	u8 rfk_state: 1;
};

struct rtk_coex_wl_chip_dm {
	u8  wl_bt_state;
	u16 bcn_interval;
	u32 policy_type;
	u16 wl_only: 1;
	u16 mp_mode: 1;
	u16 bcn_protection_enable: 1;
	u16 bcn_time: 8;
	u16 scbd_change: 1;
	u32 scbd_val;
	u8  active_wl_slot; // percent
	u8 coex_tdma_h2c_para[6];
	u8 current_wl_state;
	u8 current_bt_state;
};

struct rtk_coex_wl_chip_ops {
	void (*init_mac_cfg)(void *p_rtk_coex);
	void (*init_rf_cfg)(void *p_rtk_coex, u8 bt_enabled);
	void (*pta_enable)(void *p_rtk_coex, u8 enable);
	void (*mac_set_gnt)(void *p_rtk_coex, u8 gnt_bt, u8 gnt_wl);
	void (*fw_send_tdma_cmd)(void *p_rtk_coex, void *tdma_para);
	void (*set_wl_pri_mask)(void *p_rtk_coex, u8 pri_mask_type, u8 pri);
	void (*set_wl_act_gate)(void *p_rtk_coex, bool b_auto);
	void (*set_coex_tbl)(void *p_rtk_coex, u32 bt_coex_tbl, u32 wl_coex_tbl, u32 coex_break_tbl);
	void (*wl_5g_afh_handle)(void *p_rtk_coex, u8 center_ch, u8 bw, u8 *afh_cfg);
	void (*wl_set_switch_channel_para)(void *p_rtk_coex, u8 center_ch);
	void (*wl_set_switch_band_para)(void *p_rtk_coex, u8 band_type);
	u8(*write_wl2bt_scbd)(void *p_rtk_coex);
	u32(*read_bt2wl_scbd)(void *p_rtk_coex);
	u16(*read_bcn_space)(void *p_rtk_coex);
	void (*set_bt_rx_agc)(void *p_rtk_coex);
	void (*set_bb_btg_ctrl)(void *p_rtk_coex);
	void (*set_bt_rx_gain)(void *p_rtk_coex);
	void (*get_bt_lna_constrain)(void *p_rtk_coex);
	bool(*get_chipinfo_bredr_support)(void);
	void (*set_bredr_support)(void *p_rtk_coex);
	void (*tdma_drvc_set_slot)(void *p_rtk_coex, u8 slot_type);
	void (*get_bt_version)(void *p_rtk_coex);
	void (*reset_bt_cnt)(void);
	void (*read_bt_cnt)(u32 *bt_cnt_hi, u32 *bt_cnt_lo);
	void (*print_coex_status)(void *p_rtk_coex);
	void (*print_wl_status)(void *p_rtk_coex);
	void (*pta_deinit)(void *p_rtk_coex);
};

struct rtk_coex_wl_chip_para {
	u8 chip_id;

	u8 concurrent_rx_2g_support: 1;
	u8 concurrent_trx_5g_support: 1;
	u8 le_audio_support: 1;
	u8 hw_mailbox_support: 1;
	u8 afh_5g_workaround: 1;
	u8 rsvd_support: 1;

	u8 bt_afh_span_bw20;
	u8 bt_afh_span_bw40;

	struct rtk_coex_wl_chip_ops *ops;
};

struct rtk_coex_wl_chip {
	struct rtk_coex_wl_chip_para *p_chip_para;
	struct rtk_coex_rfk_info rfk_info;
	struct rtk_coex_wl_info wl_info;
	struct rtk_coex_bt_info bt_info;
	struct rtk_coex_ext_info wpan_info;
	struct rtk_coex_wl_chip_dm coex_dm;
	struct rtk_coex_wl_board_info board_info;
	struct rtk_coex_tdma_drvc_para tdma_drvc_para;
	void *h2c_send_mutex;
	void *rfk_mutex;
	//struct rtk_coex_tdma_info tdma_info;
};

#endif


