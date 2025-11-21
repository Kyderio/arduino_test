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

#ifndef __HALRF_DPK_8721DA_H__
#define __HALRF_DPK_8721DA_H__

#if defined(CONFIG_AMEBADPLUS)
/*--------------------------Define Parameters-------------------------------*/
#define DPK_RF_PATH_NUM_8721DA 1
#define DPK_BB_REG_NUM_8721DA 8
#define DPK_RF_REG_NUM_8721DA 8
#define DPK_PAS_CHK_DBG_8721DA 0
#define DPK_REG_DBG_8721DA 0
#define DPK_PAS_DBG_8721DA 1
#define DPK_LMS_DBG_8721DA 1
#define DPK_SRAM_IQ_DBG_8721DA 1
#define DPK_SRAM_read_DBG_8721DA 1
#define DPK_PATH_A_8721DA 1
#define DPK_NCTL_RXAGC_8721DA 0x15
#define DPK_NCTL_TXAGC_8721DA 0x16
#define DPK_NCTL_LMS_8721DA 0x17


/*---------------------------End Define Parameters----------------------------*/

void dpk_enable_disable_8721da(void);


void do_dpk_8721da(void);

void dpk_lut_write_8721da(void);

#endif /* RTL8721DA_SUPPORT */

#endif /*#ifndef __HALRF_DPK_8721DA_H__*/
