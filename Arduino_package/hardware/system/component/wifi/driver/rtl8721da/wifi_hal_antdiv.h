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

#ifndef __WIFI_HAL_ANTDIV_H__
#define __WIFI_HAL_ANTDIV_H__

/* cr for dig start: need sync with bb */
#define ANTDIV_R_OFDM_HW_ANTDIV_EN_C           0x83C
#define ANTDIV_R_OFDM_HW_ANTDIV_EN_C_M         0x10000
#define ANTDIV_R_CCK_HW_ANTDIV_EN_C            0x1A48
#define ANTDIV_R_CCK_HW_ANTDIV_EN_C_M          0x10000
#define ANTDIV_R_CCK_ANTSEL_EN_C               0x1C68
#define ANTDIV_R_CCK_ANTSEL_EN_C_M             0x2
#define ANTDIV_R_TX_BY_TXD_OR_REG_C            0x186C
#define ANTDIV_R_TX_BY_TXD_OR_REG_C_M          0x2
#define ANTDIV_R_TR_SWTX_EXTEND_C              0x1C8C
#define ANTDIV_R_TR_SWTX_EXTEND_C_M            0xF00
/* cr for dig end */

void wifi_hal_antdiv_hw_switch_on_off(u8 swch);
bool wifi_hal_antdiv_fix_ant_by_bt(void);

#endif
