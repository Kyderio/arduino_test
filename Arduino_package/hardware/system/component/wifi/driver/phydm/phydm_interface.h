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

#ifndef __ODM_INTERFACE_H__
#define __ODM_INTERFACE_H__

#define INTERFACE_VERSION "1.3"

#define	H2C_MAX_LENGTH		7
#define pdm_set_reg odm_set_bb_reg

/*@=========== Constant/Structure/Enum/... Define*/

enum phydm_h2c_cmd {
	PHYDM_H2C_TXBF			= 0x41,
	ODM_H2C_RSSI_REPORT		= 0x42,
	ODM_H2C_IQ_CALIBRATION		= 0x45,
	PHYDM_RA_MASK_ABOVE_3SS		= 0x46,
	ODM_H2C_RA_PARA_ADJUST		= 0x47,
	PHYDM_H2C_DYNAMIC_TX_PATH	= 0x48,
	PHYDM_H2C_FW_TRACE_EN		= 0x49,
	ODM_H2C_WIFI_CALIBRATION	= 0x6d,
	PHYDM_H2C_MU			= 0x4a,
	PHYDM_H2C_FW_GENERAL_INIT	= 0x4c,
	PHYDM_H2C_FW_CLM_MNTR		= 0x4d,
	PHYDM_H2C_MCC			= 0x4f,
	PHYDM_H2C_RESP_TX_PATH_CTRL	= 0x50,
	PHYDM_H2C_RESP_TX_ANT_CTRL	= 0x51,
	PHYDM_H2C_FW_DM_CTRL		= 0x55,
	ODM_MAX_H2CCMD
};

enum phydm_c2h_evt {
	PHYDM_C2H_DBG =		0,
	PHYDM_C2H_LB =		1,
	PHYDM_C2H_XBF =		2,
	PHYDM_C2H_TX_REPORT =	3,
	PHYDM_C2H_INFO =	9,
	PHYDM_C2H_BT_MP =	11,
	PHYDM_C2H_DYNAMIC_TX_PATH_RPT = 15,
	PHYDM_C2H_IQK_FINISH =	17, /*@0x11*/
	PHYDM_C2H_CLM_MONITOR =	0x2a,
	PHYDM_C2H_EXTEND =	0xFF,
};

enum phydm_extend_c2h_evt {
	PHYDM_EXTEND_C2H_DBG_PRINT = 0

};

enum phydm_halmac_param {
	PHYDM_HALMAC_CMD_MAC_W8 = 0,
	PHYDM_HALMAC_CMD_MAC_W16 = 1,
	PHYDM_HALMAC_CMD_MAC_W32 = 2,
	PHYDM_HALMAC_CMD_BB_W8,
	PHYDM_HALMAC_CMD_BB_W16,
	PHYDM_HALMAC_CMD_BB_W32,
	PHYDM_HALMAC_CMD_RF_W,
	PHYDM_HALMAC_CMD_DELAY_US,
	PHYDM_HALMAC_CMD_DELAY_MS,
	PHYDM_HALMAC_CMD_END = 0XFF,
};

/*@=========== Macro Define*/

#define _reg_all(_name)			ODM_##_name
#define _reg_ic(_name, _ic)		ODM_##_name##_ic
#define _bit_all(_name)			BIT_##_name
#define _bit_ic(_name, _ic)		BIT_##_name##_ic

#define _reg_11N(_name)			ODM_REG_##_name##_11N
#define _reg_11AC(_name)		ODM_REG_##_name##_11AC
#define _bit_11N(_name)			ODM_BIT_##_name##_11N
#define _bit_11AC(_name)		ODM_BIT_##_name##_11AC

#ifdef __ECOS
#define _rtk_cat(_name, _ic_type, _func)                                \
	(                                                               \
		((_ic_type) & ODM_IC_11N_SERIES) ? _func##_11N(_name) : \
						   _func##_11AC(_name))
#else

#define _cat(_name, _ic_type, _func)                                    \
	(                                                               \
		((_ic_type) & ODM_IC_11N_SERIES) ? _func##_11N(_name) : \
						   _func##_11AC(_name))
#endif
/*@
 * only sample code
 *#define _cat(_name, _ic_type, _func)					\
 *	(								\
 *		((_ic_type) & ODM_RTL8188E) ? _func##_ic(_name, _8188E) :\
 *		_func##_ic(_name, _8195)				\
 *	)
 */

/* @_name: name of register or bit.
 * Example: "ODM_REG(R_A_AGC_CORE1, pg_odm)"
 * gets "ODM_R_A_AGC_CORE1" or "ODM_R_A_AGC_CORE1_8192C",
 * depends on support_ic_type.
 */
#define ODM_REG(_name, pg_odm)	\
		_cat(_name, (pg_odm)->support_ic_type, _reg)
#define ODM_BIT(_name, pg_odm)	\
		_cat(_name, (pg_odm)->support_ic_type, _bit)

/*@
 * =========== Extern Variable ??? It should be forbidden.
 */

/*@
 * =========== EXtern Function Prototype
 */

u8 odm_read_1byte(u32 reg_addr);

u32 odm_read_4byte(u32 reg_addr);

void odm_write_1byte(u32 reg_addr, u8 data);

void odm_write_2byte(u32 reg_addr, u16 data);

void odm_write_4byte(u32 reg_addr, u32 data);

void odm_set_mac_reg(u32 reg_addr, u32 bit_mask, u32 data);

u32 odm_get_mac_reg(u32 reg_addr, u32 bit_mask);

void odm_set_bb_reg(u32 reg_addr, u32 bit_mask, u32 data);

u32 odm_get_bb_reg(u32 reg_addr, u32 bit_mask);


void odm_set_rf_reg(u32 reg_addr, u32 bit_mask, u32 data);

u32 odm_get_rf_reg(u32 reg_addr, u32 bit_mask);

u32 odm_convert_to_le32(u32 value);

/*@
 * Memory Relative Function.
 */
void odm_allocate_memory(void **ptr, u32 length);
void odm_free_memory(void *ptr, u32 length);

void odm_move_memory(void *dest, void *src, u32 length);

void odm_memory_set(void *pbuf, s8 value, u32 length);

/*@
 * ODM MISC-spin lock relative API.
 */
void odm_acquire_spin_lock(enum rt_spinlock_type type);

void odm_release_spin_lock(enum rt_spinlock_type type);
/*@
 * ODM Timer relative API.
 */
void ODM_delay_ms(u32 ms);

void ODM_delay_us(u32 us);

void ODM_sleep_ms(u32 ms);

void ODM_sleep_us(u32 us);

void odm_set_timer(struct phydm_timer_list *timer, u32 ms_delay);

void odm_initialize_timer(struct phydm_timer_list *timer,
						  void *call_back_func, void *context,
						  const char *sz_id);

void odm_cancel_timer(struct phydm_timer_list *timer);

void odm_release_timer(struct phydm_timer_list *timer);

/*ODM FW relative API.*/

int phydm_set_reg_by_fw(enum phydm_halmac_param config_type,
					u32 offset, u32 data, u32 mask, enum rf_path e_rf_path,
					u32 delay_time);

void odm_fill_h2c_cmd(u8 element_id, u32 cmd_len, u8 *cmd_buffer);

u8 phydm_c2H_content_parsing(u8 c2h_cmd_id, u8 c2h_cmd_len, u8 *tmp_buf);

u64 odm_get_current_time(void);
u64 odm_get_progressing_time(u64 start_time);

int odm_efuse_one_byte_read(u16 addr, u8 *data, bool b_pseu_do_test);

void odm_efuse_logical_map_read(u8 type, u16 offset, u32 *data);

#endif /* @__ODM_INTERFACE_H__ */
