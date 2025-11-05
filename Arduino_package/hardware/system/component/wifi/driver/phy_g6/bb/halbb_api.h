/******************************************************************************
 *
 * Copyright(c) 2019 Realtek Corporation.
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
#ifndef _HALBB_API_H_
#define _HALBB_API_H_

#include "halbb_ic_hw_info.h"
#include "halbb_dbcc_ex.h"

/*@--------------------------[Define] ---------------------------------------*/
#define IGI_2_RSSI(igi)		(igi - 10)

#define FUNC_ENABLE 1
#define FUNC_DISABLE 2
/*@--------------------------[Enum]------------------------------------------*/
enum bb_ablty_ops {
	HALBB_DIS_ALL_FUNC,
	HALBB_FUNC_CLR,
	HALBB_ABILITY_SET,
	HALBB_ABILITY_SET_ALL,
	HALBB_ABILITY_GET,
};
/*@--------------------------[Structure]-------------------------------------*/
struct bb_api_info {
	u8 pri_ch_idx;
	u8 central_ch;
	u8 bw;
	enum rtw_band_type band;
};
/*@--------------------------[Prptotype]-------------------------------------*/
u8 halbb_get_rssi_min(void);
u8 halbb_ch_2_band(u8 fc_ch);
u16 halbb_get_csi_buf_idx(u8 buf_idx, u8 txsc_idx);

void halbb_reset_bb(void);
void halbb_gpio_setting(u8 gpio_idx, enum bb_path path,
						bool inv, enum bb_rfe_src_sel src);
void halbb_gpio_setting_init(void);
void halbb_rfe_ctrl_extfem_by_band(u8 rfe_idx, enum rtw_band_type band);
void halbb_init_rfe_ctrl_reg(u8 rfe_idx, enum bb_rfe_src_sel src_sel, bool bt_s1);
void halbb_pre_agc_en(bool enable);
void halbb_set_gain_error(u8 central_ch, u8 ant, u8 bt);
int halbb_stop_ic_trx(u8 set_type);
u16 halbb_fc_mapping(enum rtw_band_type band, u8 central_ch);
void halbb_ic_hw_setting_dbcc(void);
void halbb_ic_hw_setting(void);
void halbb_ic_hw_setting_dbg(char input[][16],
							 u32 *_used, char *output, u32 *_out_len);
void halbb_btc_bb_switchchannel_para(u8 central_ch, u8 bt_on);
u64 halbb_ability_ops(enum bb_ablty_ops ops, u32 ability);
void halbb_cnt_statistics(void);
void halbb_ccx_query_clm_info(union rtw_phy_stats *phy_stats);
#endif
