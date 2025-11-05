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

#ifndef __PHYDM_DFS_H__
#define __PHYDM_DFS_H__

#define DFS_VERSION "1.1"

/*@
 * ============================================================
 *  Definition
 * ============================================================
 */

/*@
 * ============================================================
 * 1  structure
 * ============================================================
 */

struct _DFS_STATISTICS {
	u32		fa_cnt_th;
	/*@dfs histogram threshold*/
	u8		pri_hist_idle_th;
	u8		pri_hist_th;
	u8		pri_sum_g1_th;
	u8		pri_sum_g0_idle_th;
	u8		pri_sum_g0_th;
	u8		pri_sum_g5_idle_th;
	u8		pri_sum_g5_th;
	u8		pw_sum_g0_idle_th;
	u8		pw_sum_g0_th;
	u8		pw_sum_g5_idle_th;
	u8		pw_sum_g5_th;
	u8		pw_pri_valid_set_idle_th;
	u8		pw_pri_valid_set_th;
	u8		fa_mask_th;
	u8		nhm_cnt_th;
	u8		nhm_dty_th;
	u8 		pri_var_offset;
	u8 		pri_var_tp_offset;
	u8 		pri_cnt_th;
	u8 		loct_diff_th;
	u8 		dc_cnt_th;
	u8		pri_pw_diff_idle_th;
	u8		pri_pw_diff_th;
	/*@dfs histogram*/
	u8 	    pw_flag_en;
	u8 	    loct_flag_en;
	u8 	    pri_flag_en;

	u8		pri_sum_g1_fcc_th : 3;
	u8		pri_sum_g3_fcc_th : 3;
	u8		pri_sum_safe_fcc_th : 7;
	u8		pri_sum_type4_th : 5;
	u8		pri_sum_type6_th : 5;
	u8		pri_sum_safe_th : 6;
	u8		pri_sum_g5_under_g1_th : 3;

	u8		pri_pw_diff_fcc_th : 4;
	u8		pri_pw_diff_fcc_idle_th : 2;
	u8		pri_pw_diff_w53_th : 4;
	u8		pri_type1_low_fcc_th : 7;
	u8		pri_type1_upp_fcc_th : 7;
	u8		pri_type1_cen_fcc_th : 7;
	u8		pw_g0_th : 4;
	u8		pw_long_lower_20m_th : 4;
	u8		pw_long_lower_th : 3;
	u8		pri_long_upper_th : 6;
	u8		pw_long_sum_upper_th : 7;
	u8		pw_std_th : 4;
	u8		pw_std_idle_th : 4;
	u8		pri_std_th : 4;
	u8		pri_std_idle_th : 4;
	u8		type4_pw_max_cnt : 4;
	u8		type4_safe_pri_sum_th : 3;

	u8		force_TP_mode: 1;
	u8		dbg_mode: 1;
	u8		sw_trigger_mode: 1;
	u8		det_print: 1;
	u8		det_print2: 1;
	u8		det_print_sw: 1;
	u8		det_print_jar3: 1;
	u8		det_jar3_en: 1;
	u8		print_hist_rpt: 1;
	u8		hist_cond_on: 1;
	/*@dfs histogram*/
	u8		nhm_dfs_en: 1;

	/*
	u8		pw_lth[10];
	u8		pri_lth[10];
	u16		pw_uth[10];
	u8		pri_uth[10];
	*/
};

/*@
 * ============================================================
 * enumeration
 * ============================================================
 */

enum phydm_dfs_region_domain {
	PHYDM_DFS_DOMAIN_UNKNOWN =	0,
	PHYDM_DFS_DOMAIN_FCC =		1,
	PHYDM_DFS_DOMAIN_MKK =		2,
	PHYDM_DFS_DOMAIN_ETSI =		3,
};

/*@
 * ============================================================
 * function prototype
 * ============================================================
 */
#if defined(CONFIG_PHYDM_DFS_MASTER)

void phydm_dfs_hist_dbg(char input[][16], u32 *_used,
						char *output, u32 *_out_len);
void phydm_dfs_debug(char input[][16], u32 *_used,
					 char *output, u32 *_out_len);
#endif /* @defined(CONFIG_PHYDM_DFS_MASTER) */

bool
phydm_is_dfs_band(void);

bool
phydm_dfs_master_enabled(void);

#endif /*@#ifndef __PHYDM_DFS_H__ */
