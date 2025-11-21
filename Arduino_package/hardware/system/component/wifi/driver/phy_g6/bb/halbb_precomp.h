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
#ifndef __HALBB_PRECOMP_H__
#define __HALBB_PRECOMP_H__

#include "wifi_intf_os_to_g6.h"
#include "halbb_cfg_ic.h"

/*---[Define Only] ----------------------------------------------------------*/
#include "halbb_types.h"
#include "halbb_features.h"
#include "halbb_ic_hw_info.h"
#include "halbb_ic_sw_info.h"
#include "halbb_interface.h"
#include "halbb_dbg.h"
#include "halbb_dbg_cnsl_out.h"

#if (PLATFOM_IS_LITTLE_ENDIAN)
#include "halbb_physts_ie_l_endian.h"
#else
#include "halbb_physts_ie_b_endian.h"
#endif

/*---[Include structure & prototype] ----------------------------------------*/
#ifdef BB_8730E_SUPPORT
#include "halbb_8730e/halbb_cr_info_8730e.h"
#include "halbb_8730e/halbb_8730e.h"
#include "halbb_8730e/halbb_8730e_api.h"
#include "halbb_8730e/halbb_hwimg_8730e.h"
#include "halbb_8730e/halbb_reg_cfg_8730e.h"
#include "halbb_8730e/halbb_version_rtl8730e.h"
#endif

#ifdef BB_8720E_SUPPORT
#include "halbb_8720e/halbb_cr_info_8720e.h"
#include "halbb_8720e/halbb_8720e.h"
#include "halbb_8720e/halbb_8720e_api.h"
#include "halbb_8720e/halbb_hwimg_8720e.h"
#include "halbb_8720e/halbb_reg_cfg_8720e.h"
#include "halbb_8720e/halbb_version_rtl8720e.h"
#endif

#ifdef BB_8721F_SUPPORT
#include "halbb_8721f/halbb_cr_info_8721f.h"
#include "halbb_8721f/halbb_8721f.h"
#include "halbb_8721f/halbb_8721f_api.h"
#include "halbb_8721f/halbb_hwimg_8721f.h"
#include "halbb_8721f/halbb_reg_cfg_8721f.h"
#include "halbb_8721f/halbb_version_rtl8721f.h"
#endif

#ifdef BB_6955_SUPPORT
#include "halbb_6955/halbb_cr_info_8730e.h"
#include "halbb_6955/halbb_8730e.h"
#include "halbb_6955/halbb_8730e_api.h"
#include "halbb_6955/halbb_hwimg_8730e.h"
#include "halbb_6955/halbb_reg_cfg_8730e.h"
#include "halbb_6955/halbb_version_rtl8730e.h"
#endif

#include "halbb_hw_cfg.h"
#include "halbb_hw_cfg_ex.h"
#include "halbb_api.h"
#include "halbb_api_ex.h"
#include "halbb_interface_ex.h"
#include "halbb_math_lib_ex.h"
#include "halbb_math_lib.h"
#include "halbb_dbg_cmd.h"
#include "halbb_dbg_cmd_ex.h"
#include "halbb_cmn_rpt_ex.h"
#include "halbb_cmn_rpt.h"
#include "halbb_physts_ex.h"
#include "halbb_physts.h"
#include "halbb_init.h"
#include "halbb_init_ex.h"
#include "halbb_pmac_setting.h"
#include "halbb_pmac_setting_ex.h"
#include "halbb_plcp_tx_ex.h"
#include "halbb_plcp_tx.h"
#include "halbb_plcp_gen.h"
#include "halbb_la_mode.h"
#include "halbb_psd.h"
#include "halbb_pwr_ctrl_ex.h"
#include "halbb_pwr_ctrl.h"
#include "halbb_mp_ex.h"
#include "halbb_dfs.h"
#include "halbb_dfs_ex.h"
#include "halbb_cfo_trk.h"
#include "halbb_env_mntr.h"

#include "halbb_statistics.h"
#include "halbb_ch_info_ex.h"
#include "halbb_ch_info.h"
#ifdef CONFIG_RADAR
#include "halbb_radar_rpt.h"
#include "halbb_radar_tx.h"
#endif
#include "halbb_dbcc_ex.h"
#include "halbb_spur_suppress.h"

#include "halbb_ex.h"
#include "halbb.h"

#endif
