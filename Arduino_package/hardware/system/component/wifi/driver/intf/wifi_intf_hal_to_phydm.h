/******************************************************************************
 *
 * Copyright(c) 2007 - 2012 Realtek Corporation. All rights reserved.
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
#ifndef _WIFI_INTF_HAL_TO_PHYDM_H_
#define _WIFI_INTF_HAL_TO_PHYDM_H_

#include <rtw_adapter.h>

#define phy_query_mac_reg(RegAddr, BitMask) wifi_hal_read_bb_reg((RegAddr), (BitMask))
#define phy_query_bb_reg(RegAddr, BitMask) wifi_hal_read_bb_reg((RegAddr), (BitMask))
#define phy_set_bb_reg(RegAddr, BitMask, Data) wifi_hal_write_bb_reg((RegAddr), (BitMask), (Data))
#define phy_query_rf_reg(eRFPath, RegAddr, BitMask) wifi_hal_read_rf_reg((eRFPath), (RegAddr), (BitMask))
#define phy_set_rf_reg(eRFPath, RegAddr, BitMask, Data) wifi_hal_write_rf_reg((eRFPath), (RegAddr), (BitMask), (Data))

enum RTL871X_HCI_TYPE {
	RTW_LXBUS = BIT4,
	RTW_AXI = BIT5
};

#endif //_WIFI_INTF_HAL_TO_PHYDM_H_

