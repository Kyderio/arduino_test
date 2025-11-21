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
#ifndef __INC_MP_BB_HW_IMG_8721F_BCN_MODE_H
#define __INC_MP_BB_HW_IMG_8721F_BCN_MODE_H

#if defined(CONFIG_AMEBAGREEN2) || defined(CONFIG_AMEBAPRO3)

//2G I+Q,
const u32 array_mp_8721f_Set_2G_BCNmode_IQ_reg[BCN_MODE_SET_2G_IQ_SIZE] = {
	0x12AC, 0x00FFF000, 0xEEE,
};
const u32 array_mp_8721f_Cancel_2G_BCNmode_IQ_reg[BCN_MODE_CANCEL_2G_IQ_SIZE] = {
	0x12AC, 0x00FFF000, 0x333,
};

//AmebaGreen2 A cut, backup
const u32 array_mp_8721f_BCNmode_2G_reg[BCN_MODE_2G_SIZE] = {
	0x4F38, 0x07FC0000, 0x28, //TIA0
	0x4F3C, 0x000001FF, 0x56, //TIA1
	0x4678, 0xFFFF0000, 0xD8B8, //lna 1,0
	0x467C, 0xFFFFFFFF, 0x44210cea, //lna 5,4,3,2,
	0x4680, 0x0000FFFF, 0xE460,	//rxbb0,lna6
	0x4F4C, 0xFFFF0000, 0xFA02,	//g_pin_for_gain 1,0
	0x4F54, 0xFFFFFFFF, 0xEDF5CBCB, //g_pin_for_gain 3,2,15,14
	0x4F58, 0xFFFFFFFF, 0xCBD4D9E7, //g_pin_for_gain 7,6,5,4
	0x4F5C, 0x0000FFFF, 0xCBCB, //g_pin_for_gain 9,8
	0x4F50, 0xFFFFFFFF, 0xCBCBCBCB, //g_pin_for_gain 13,12,11,10
};

//5G I-only
const u32 array_mp_8721f_Set_Ionly_reg[BCN_MODE_SET_IONLY_SIZE] = {
	0x12AC, 0x00FFF000, 0xDDD,
	0x4454, 0x0000000C, 0x3,
	0x4978, 0x00000F00, 0x1,
	0x4738, 0x40000000, 0x1,
};

const u32 array_mp_8721f_Cancel_Ionly_reg[BCN_MODE_CANCEL_IONLY_SIZE] = {
	0x12AC, 0x00FFF000, 0x333,
	0x4454, 0x0000000C, 0x0,
	0x4978, 0x00000F00, 0x0,
	0x4738, 0x40000000, 0x0,
};

//AmebaGreen2 A cut, V23
//close PD function, beacon I only
//4738 bit29 1//bit30 0
//0x4f68, 0xffffffff, 0x80a4eff4,
const u32 array_mp_8721f_BCNmode_5G_com_reg[BCN_MODE_5G_COM_SIZE] = {
	// 0x4694, 0xffffffff, 0x02FC2A2A,
	// 0x469c, 0xffffffff, 0x7D891428,
	// 0x46b8, 0xF0000000, 0x3,
	// 0x472c, 0x00038000, 0x1,
	// 0x4730, 0x60000000, 0x3,
	// 0x4f68, 0xffffffff, 0x90a96ff4,
	0x4f6c, 0x00000400, 0x1,
	0x424c, 0x00000001, 0x0, //  r_indi_QBPSK_check_en
};

const u32 array_mp_8721f_BCNmode_5GL_reg[BCN_MODE_5GL_SIZE] = {
	0x45dc, 0xffff0000, 0xBE9C, //lna 1,0
	0x4660, 0xffffffff, 0x13FEE5D5, //lna 5,4,3,2
	0x4664, 0x0000ffff, 0xE441, //rxbb0,lna6
	0x4F38, 0x0003FFFF, 0xa446, //TIA1 [17:9], TIA0 [8:0]
	0x4F3C, 0x01FFFE00, 0xF0F8, //g_pin_for_gain 1,0
	0x4F44, 0xFFFFFFFF, 0xE6EACACA, //g_pin_for_gain 3,2,15,14
	0x4F48, 0xFFFFFFFF, 0xCACFDAE0, //g_pin_for_gain 7,6,5,4
	0x4F4C, 0x0000FFFF, 0xCACA, //g_pin_for_gain 9,8
	0x4F40, 0xFFFFFFFF, 0XCACACACA, //g_pin_for_gain 13,12,11,10
};

const u32 array_mp_8721f_BCNmode_5GM_reg[BCN_MODE_5GM_SIZE] = {
	0x45dc, 0xffff0000, 0xC8A4, //lna 1,0
	0x4660, 0xffffffff, 0x1905EBDD, //lna 5,4,3,2
	0x4664, 0x0000ffff, 0xE447, //rxbb0,lna6
	0x4F38, 0x0003FFFF, 0xA043, //TIA1 [17:9], TIA0 [8:0]
	0x4F3C, 0x01FFFE00, 0xECF5, //g_pin_for_gain 1,0
	0x4F44, 0xFFFFFFFF, 0xE3E7CDCD, //g_pin_for_gain 3,2,15,14
	0x4F48, 0xFFFFFFFF, 0xCDCDD8DD, //g_pin_for_gain 7,6,5,4
	0x4F4C, 0x0000FFFF, 0xCDCD, //g_pin_for_gain 9,8
	0x4F40, 0xFFFFFFFF, 0xCDCDCDCD, //g_pin_for_gain 13,12,11,10
};

const u32 array_mp_8721f_BCNmode_5GH_reg[BCN_MODE_5GH_SIZE] = {
	0x45dc, 0xffff0000, 0xC9a5, //lna 1,0
	0x4660, 0xffffffff, 0x1500E8D5, //lna 5,4,3,2
	0x4664, 0x0000ffff, 0xE441, //rxbb0,lna6
	0x4F38, 0x0003FFFF, 0xAC47, //TIA1 [17:9], TIA0 [8:0]
	0x4F3C, 0x01FFFE00, 0xEEF6, //g_pin_for_gain 1,0
	0x4F44, 0xFFFFFFFF, 0xE6E6CDCD,//g_pin_for_gain 3,2,15,14
	0x4F48, 0xFFFFFFFF, 0xCDCFDAE0,//g_pin_for_gain 7,6,5,4
	0x4F4C, 0x0000FFFF, 0xCDCD,//g_pin_for_gain 9,8
	0x4F40, 0xFFFFFFFF, 0xCDCDCDCD,//g_pin_for_gain 13,12,11,10
};


#endif /* end of BB_8721F_SUPPORT*/
#endif

