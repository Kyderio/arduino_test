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

#ifndef __HALRF_BCNMODE_8721DA_H__
#define __HALRF_BCNMODE_8721DA_H__
/*
const u32 array_rf_enter_bcnmode_2G_reg[RF_ENTER_BCNMODE_2G_SIZE] = {
	0x5,	BIT0,		0x0,// for enable write rf0
	0x0,	0xfffff,	0xD3860,//RF SETING
	0x1f,	0x1c00,		0x2,//SET RF BW=40M
	0x20,	0xfffff,	0x86E5F,//FOR RXG,IQKPLL_EN_BCN_A[7]//RF REG,IQKPLL_EN_IQK_A[5]
	0x18,	0xfffff,	PHY_REG_TO_CHANGE,//G mode RF BW=40M 18[13]=1, POW_BEACON_RXG,CHANNEL SETTIING FOR IQK PLL
	0x1f,	0x3ff,		PHY_REG_TO_CHANGE,// CHANNEL SETTIING FOR IQK PLL
	0x1e,	0xfffff,	0x80000,// 1E[19]; POW_IQKPLL// 1E[5:0]; IQKPLL_FOS_SEL = 0MHz
	0x5,	BIT0,		0x1,// for enable write rf0
};

const u32 array_rf_enter_bcnmode_5G_reg[RF_ENTER_BCNMODE_5G_SIZE] = {
	0x5,	BIT0,		0x0,// for enable write rf0
	0x0,	0xfffff,	0xD3860,//RF SETING
	0x1f,	0x1c00,		0x2,//SET RF BW=40M
	0x1f,	0x30000,	0x1,//SET IQKPLL_MODE_AGH
	0x20,	0xfffff,	0x86E3F,//EN_BCN_A=1
	0xdf,	0xfffff,	0x01000,//DEBUG_TIA_GAIN=1
	0x9e,	0xfffff,	0x00564,//TIA_N6=1
	0x18,	0xfffff,	PHY_REG_TO_CHANGE,//A mode RF BW=40M 18[13]=1, POW_BEACON_RXG,CHANNEL SETTIING FOR IQK PLL
	0x1f,	0x3ff,		PHY_REG_TO_CHANGE,// CHANNEL SETTIING FOR IQK PLL
	0x1e,	0xfffff,	0x80000,// 1E[19]; POW_IQKPLL// 1E[5:0]; IQKPLL_FOS_SEL = 0MHz
	0x5,	BIT0,		0x1,// for enable write rf0
};

const u32 array_rf_exit_bcnmode_2G_reg[RF_EXIT_BCNMODE_2G_SIZE] = {
	0x5,	BIT0,		0x0,// for enable write rf0
	0x0,	0xfffff,	0x33860,//RF SETING
	0x1e,	0xfffff,	0x00000,//RF SETING
	0x20,	0xfffff,	0x86E1F,//EN_BCN_A=0
	0x1f,	0xfffff,	0x0,
	0x18,	0xfffff,	PHY_REG_TO_CHANGE,// Disable Beacon mode
	0x05,	BIT0,		0x1,// for enable write rf0
};

const u32 array_rf_exit_bcnmode_5G_reg[RF_EXIT_BCNMODE_5G_SIZE] = {
	0x5,	BIT0,		0x0,// for enable write rf0
	0x0,	0xfffff,	0x33860,//RF SETING
	0x1e,	0xfffff,	0x00000,//RF SETING
	0x20,	0xfffff,	0x86E1F,//EN_BCN_A=0
	0xdf,	0xfffff,	0x0,//DEBUG_TIA_GAIN=0
	0x9e,	0xfffff,	0x00564,//TIA_N6=1
	0x1f,	0xfffff,	0x0,
	0x18,	0xfffff,	PHY_REG_TO_CHANGE,// Disable Beacon mode
	0x05,	BIT0,		0x1,// for enable write rf0
};
*/
#endif /*#ifndef __HALRF_BCNMODE_8721DA_H__*/
