/******************************************************************************
 *
 * Copyright(c) 2021 Realtek Corporation.
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
#ifndef _HALRF_TSSI_8721F_H_
#define _HALRF_TSSI_8721F_H_
#ifdef RF_8721F_SUPPORT

#define EFEM 0

//#define TSSI_PATH_MAX_8721F 1

/*@--------------------------Define Parameters-------------------------------*/
/*@-----------------------End Define Parameters-----------------------*/
void halrf_tssi_get_efuse_8721f(void);
void halrf_set_tssi_de_for_tx_verify_8721f(u32 tssi_de);
void halrf_set_tssi_de_offset_8721f(u32 tssi_de_offset);
void halrf_do_tssi_8721f(void);
void halrf_do_tssi_init_8721f(void);
void halrf_tssi_tracking_8721f(void);
void halrf_tssi_pre_tx_mp_8721f(void);
void halrf_do_tssi_scan_8721f(void);
void halrf_tssi_enable_8721f(void);
void halrf_tssi_disable_8721f(void);
s32 halrf_get_online_tssi_de_8721f(s32 dbm, s32 pout);
//void halrf_tssi_set_efuse_to_de_8721f(void);
#if 0
bool halrf_tssi_check_efuse_data_8721f(void);
void halrf_set_tssi_de_offset_zero_8721f(void);
void halrf_tssi_cck_8721f(bool is_cck);
void halrf_set_tssi_avg_mp_8721f(s32 xdbm);
void halrf_tssi_default_txagc_8721f(bool enable);

void halrf_tssi_scan_ch_8721f(void);

void halrf_tssi_backup_txagc_8721f(bool enable);

u32 halrf_tssi_get_final_8721f(void);
void halrf_get_tssi_info_8721f(
	char input[][16], u32 *_used, char *output, u32 *_out_len);
#endif
#endif
#endif	/*_HALRF_SET_PWR_TABLE_8721F_H_*/