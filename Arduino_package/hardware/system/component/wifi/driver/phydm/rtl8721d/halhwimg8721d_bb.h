/******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation.
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

/*Image2HeaderVersion: R3 1.5.10.1*/
#if defined(CONFIG_AMEBAD)
#ifndef __INC_MP_BB_HW_IMG_8721D_H
#define __INC_MP_BB_HW_IMG_8721D_H

#define TYPE_AGC_REG 0
#define TYPE_PHY_REG 1
#define TYPE_AFE_REG 2

/******************************************************************************
 *                           phy_reg.TXT
 ******************************************************************************/
extern const u32 array_mp_8721d_afe_reg[];
extern const u32 array_mp_8721d_phy_reg[];
extern const u32 array_mp_8721d_agc_reg[];

/* tc: Test Chip, mp: mp Chip*/
u32 odm_get_version_mp_8721d_phy_reg(void);
void odm_read_and_config_mp_8721d_phy_reg_pg_type0(void);
void odm_read_and_config_mp_8721d_phy_reg_pg_type1(void);


/******************************************************************************
 *                           afe_reg.TXT
 ******************************************************************************/
/* tc: Test Chip, mp: mp Chip*/
u32 odm_get_phyreg_size(u8 reg_type);

void
odm_read_and_config_mp_8721d_reg(u8 reg_type);

#endif
#endif /* end of HWIMG_SUPPORT*/

