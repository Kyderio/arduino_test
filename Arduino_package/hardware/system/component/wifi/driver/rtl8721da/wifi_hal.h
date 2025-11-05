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

#ifndef __WIFI_HAL_H__
#define __WIFI_HAL_H__

#include "hal.h"

#ifdef CONFIG_WIFI_TUNNEL
#include "hal_wtn.h"
#endif

#include "../phydm/phydm_precomp.h"

#include <wifi_hal_odm.h>

#ifdef CONFIG_P2P
#include "wifi_hal_p2p.h"
#endif
#define APCORE_WAKE_IRQ		KM4_WAKE_IRQ

#define MAC_TXPKTBUF_OFFSET		(0x10000)

/* ps mode: data 0. */
#define PS_ENTER_START		0x1
#define PS_LEAVE_START		0x0

/* PowerState: data 4. */
#define PS_IPS_PG_ENTER		0x8
#define PS_LPS_PG_ENTER		0x0
#define PS_REG_RF_ALL_ON	0xC

#define REG_POWER_BASE		14
#define	TX_1S			0

#define PHY_QueryBBReg(hal, RegAddr, BitMask) wifi_hal_read_bb_reg((RegAddr), (BitMask))
#define PHY_SetBBReg(hal, RegAddr, BitMask, Data) wifi_hal_write_bb_reg((RegAddr), (BitMask), (Data))
#define PHY_QueryRFReg(hal, eRFPath, RegAddr, BitMask) wifi_hal_read_rf_reg((eRFPath), (RegAddr), (BitMask))
#define PHY_SetRFReg(hal, eRFPath, RegAddr, BitMask, Data) wifi_hal_write_rf_reg((eRFPath), (RegAddr), (BitMask), (Data))

#define PHY_QueryMacReg PHY_QueryBBReg

void wifi_hal_wlan_int_enable(u8 irq_state);
u8 wifi_hal_wlan_int_disable(void);
u32 wifi_hal_suspend_start(u32 expected_idle_time, void *param);
u32 wifi_hal_resume_start(u32 expected_idle_time, void *param);

void wifi_hal_phy_set_txpower_index(u32 PowerIndex, u8 RFPath, u8 Rate);
void wifi_hal_phy_set_txpower_index_byrate_section(u8 RFPath, u8 Channel, u8 RateSection);
s8 wifi_hal_phy_tx_power_by_user(u8 rate);
void wifi_hal_get_tx_power_table_enable(void);

#ifdef CONFIG_CSI
enum csi_parsing_status rtw_hal_bb_csi_parsing(u8 *addr, u32 len, u8 *rpt_buf, struct rtw_csi_rpt_hdr_info *rpt_hdr,
		struct rtw_csi_phyinfo_rpt *phy_info, struct rtw_csi_drv_rpt *drv);
void rtw_hal_bb_csi_cfg(struct rtw_csi_bbcr_cfg *cfg);
#endif

u8 rtw_hal_bb_acs_mntr_trigger(u16 mntr_time, u8 nhm_incld_cca);
void rtw_hal_bb_acs_mntr_result(u8 is_first_channel, u8 trigger_result, u8 survey_channel, u16 time, u8 scan_done);
void wifi_hal_init_rfe_ctrl_gpio(void);
void wifi_hal_reset_rfe_ctrl_gpio(void);
#endif
