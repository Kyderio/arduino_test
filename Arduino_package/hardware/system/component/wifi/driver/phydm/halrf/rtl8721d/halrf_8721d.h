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

#ifndef __HALRF_8721D_H__
#define __HALRF_8721D_H__

#define AVG_THERMAL_NUM_8721DA 4
//#define MAX_PATH_NUM_8721DA 1
#define RF_T_METER_8721DA 0x42
#define TXPWR_TRACK_TABLE_SIZE 30
#define	CCK_TABLE_SIZE_8721D   41
#define	OFDM_TABLE_SIZE	43


s8 halrf_thermal_read_8721d(void);
void halrf_powertracking_thermal_8721d(void);
void phy_aac_8721d(void);
void phy_x2k_8721d(void);
void phy_x2_check_8721d(void);
void phy_syn_calibrate_part1_8721d(void);
void phy_syn_calibrate_part2_8721d(void);
void halrf_synk_8721d(void);
void _phy_lc_calibrate_8721d(void);
void _phy_realtime_calibrate_8721d(void);
void phy_lc_calibrate_8721d(void);
void halrf_tx_pause_8721d(void);
void backup_bb_register_8721d(u32 *bb_backup, u32 *backup_bb_reg, u32 counter);
void restore_bb_register_8721d(u32 *bb_backup, u32 *backup_bb_reg, u32 counter);
void set_iqk_matrix_8721d(u8 OFDM_index, s32 iqk_result_x, s32 iqk_result_y);
u8 get_right_ch_place_for_iqk(u8 chnl);
void odm_xtaltrack_set_xtal_8721d(s8 xtal_offset);

#endif /*__HALRF_8721DA_H__*/
