
/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
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
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef _WIFI_HAL_DEF_H_
#define _WIFI_HAL_DEF_H_

#include "wifi_hal_ax.h"
#if (PHYDM_VERSION == 2)
#include "phydm_precomp.h"
#include "phydm.h"
#endif

#define wifi_set_bit(pbuf, bit_index)	\
	do	{	\
			pbuf |= BIT(bit_index); \
		} while(0)
#define wifi_clr_bit(pbuf, bit_index)	\
	do	{	\
			pbuf &= (~BIT(bit_index)); \
		} while(0)

struct rtw_hw_band {
	struct rtw_chan_def cur_chandef;
	struct rtw_tpu_info rtw_tpu_i; /*TX Power Unit (TPU)*/
#if defined(HALBB_STATISTICS_SUPPORT) || defined (CONFIG_MP_INCLUDED) || defined (CONFIG_PHYDM_CMD)
	struct rtw_bb_stat_t bb_statistic;
#endif
};

struct txpwr_aux {
	u8 txpwr_2g_aux[12];
	u8 txpwr_5g_aux[15];
};

struct efuse_info_t {
	u8 txpwr_2g[12];/*tssi has 11bytes, power index has 12bytes*/
	u8 thermal_a;
	u8 xtal_cap;
	u8 rfe_type;
	u8 pwr_supply_mode;
	u8 bt_pa_pwr_mode;
	u8 rf_board_opt;  /* 0: enable power by rate, disable power limit, 1: enable power by rate and limit, 2: disable both */
	u8 rxgain_2g_cck;
	u8 rxgain_2g_ofdm;
#if defined(SUPPORT_5G_CHANNEL)
	u8 txpwr_5g[15];/*tssi has 14bytes, power index has 15bytes*/
	u8 rxgain_5gl;
	u8 rxgain_5gm;
	u8 rxgain_5gh;
#endif
#if defined(CONFIG_AMEBAGREEN2) || defined(CONFIG_AMEBAPRO3)
	struct txpwr_aux *ptxpwr_aux;
#endif
};

struct hal_phy_share_t {
	rtos_mutex_t rfk_mutex;

	enum rtw_drv_mode phl_drv_mode;			/* normal or mp mode */
	enum rtw_dev_state phl_dev_state;
	enum chip_name_e chip_name;
	enum chip_cut_e chip_cut;
	enum chip_vendor_e chip_vendor;

	u8 assoc_sta_cnt; /*number of associated nodes (sta or ap)*/
	u8 phl_dfs_region_domain;

	u8 b_dbcc_en : 1; /* useless, could be deleted later when halbb code all use DBCC macro*/
	u8 b_phl_bb_log : 1;
	u8 b_phl_rf_log : 1;
	u8 b_phl_csa_switch_ch : 1;			/* add for bb reset rssi only when csa switch channel */
	u8 b_phl_ap_on : 1;				/*provide ap on information to BB DIG*/
	u8 b_dfs_master_enabled : 1;
	u8 b_delay_dis_cck: 1; /* flag to disable CCK rate, refer to RSWLANDIOT-11344 */
	u8 dis_cck_cnt: 2; /* delay to disable CCK rate counter on 5G channel, refer to RSWLANDIOT-11344 */
};

struct _hal_data {
#ifdef CONFIG_CSI
	struct csi_priv				csipriv;
#endif
#ifdef CONFIG_RADAR
	struct radar_priv				radarpriv;
#endif
	struct efuse_info_t			efuse_info;
	struct rtw_dig_info			diginfo;
	struct rtw_edcca_info		edccainfo;
	struct rtw_antdiv_info		antdivinfo;

	struct hal_phy_share_t		halphy_shareinfo;

	struct rtw_hw_band band[MAX_BAND_NUM];/*band0/band1 for DBCC*/
	struct rtw_tx_power_ctl_info	txpwr_ctl_info;

	u32			intr_array[4];
	u32			intr_mask[4];

	u16			rx_expect_tag;

	u8			ant_path; /* for 8730E BT s0/s1 selection	 */
	u8			pwr_lmt_regu; //not distinguish 2.4G and 5G
	u8			iface_nums;			/* total number of ifaces used runtime */

	u8			b_ant_type : 1;/* 0 : shared antenna, 1 : dedicated antenna */
	u8			b_use_channel_plan : 1;
	u8			b_irq_enabled : 1;
	u8			b_irq_alloc : 1;
	u8			b_mac_pwr_ctrl_on : 1; // Auto FSM to Turn On, include clock, isolation, power control for MAC only
	u8			b_need_IQK : 1;
	u8			b_hw_up : 1;				/* Used to represent wifi HW status. */
	u8			b_rf_pwr_off : 1;
	u8			b_sw_chnl : 1;
	u8			b_set_chnl_bw : 1;
	u8			b_chnl_bw_initialized : 1;
	u8			b_ant_div_cfg: 1;
	u8			b_fw_wowlan_disconnect: 1;
	u8			b_efuse_skip_check: 1;
};

extern struct _hal_data hal_data;
extern struct dm_struct g_odm;


#endif //_WIFI_HAL_DEF_H_
