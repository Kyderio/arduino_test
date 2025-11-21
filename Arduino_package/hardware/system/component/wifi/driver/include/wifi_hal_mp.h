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

#ifndef _WIFI_HAL_MP_H_
#define _WIFI_HAL_MP_H_

#include <rtw_wifi_constants.h>
#ifdef CONFIG_MP_INCLUDED

#include <wifi_hal.h>

int Hal_SetPowerTracking(u8 enable);
void Hal_GetPowerTracking(u8 *enable);
void Hal_SetChannel(void);
void wifi_hal_mp_set_bandwidth(void);
void Hal_SetDataRate(void);
s32 Hal_SetThermalMeter(u8 target_ther);
void Hal_GetThermalMeter(u8 *value);
void wifi_hal_mp_set_singlecarrier_tx(u8 bStart);
void wifi_hal_mp_set_singletone_tx(u8 bStart);
void wifi_hal_mp_pmac_get_pkt_param(struct pmac_txinfo_t	*ppmac_txinfo, struct pmac_pktinfo_t	*ppmac_pktinfo);
void Hal_SetHwPacketTx(u8 bStart, u32 period, u32 len, u32 count);
void wifi_hal_mp_set_carriersuppression_tx(u8 bStart);
void wifi_hal_mp_set_continuous_tx(u8 bStart);
void PHY_IQCalibrate(u8 bReCovery);
void PHY_LCCalibrate(void);
void PHY_DPCalibrate(void);
void wifi_hal_mp_set_rf_path_switch(bool is_main);
void wifi_hal_mp_resetbb(void);
int wifi_hal_mp_arx(struct rtw_point *wrqu);
void wifi_hal_mp_dump(u32 column);
s32 wifi_hal_mp_init(u8 Channel);
void wifi_hal_mp_rx_cca(bool cca_en);
void wifi_hal_mp_rx_filter(void);
void wifi_hal_mp_init_psd(struct rtw_point *wrqu);
void wifi_hal_mp_get_point_data_psd(struct rtw_point *wrqu);
void wifi_hal_mp_restore_psd(struct rtw_point *wrqu);
u32 wifi_hal_mp_query_psd(u8 *data, int data_len);
void wifi_hal_mp_crystal_cap(u32 CrystalCapVal);
void wifi_hal_mp_dpk(struct rtw_point *wrqu);
void wifi_hal_mp_settxedca(void);
void wifi_hal_mp_select_rf_ant(u8 ant_sw);
void wifi_hal_mp_select_btg(u8 btg_sw);
void wifi_hal_mp_set_bt_ant(u8 bt_ant);
u32 wifi_hal_mp_set_period(u32 period);
void wifi_hal_mp_query_phy(u8 *input, u32 input_len);
u32 wifi_hal_mp_get_tx_power(u8	rfpath);
u32 otp_logical_remain(void);
#endif

#endif	//_WIFI_HAL_MP_H_

