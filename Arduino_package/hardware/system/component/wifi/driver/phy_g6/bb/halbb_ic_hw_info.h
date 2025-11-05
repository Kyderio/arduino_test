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
#ifndef __HALBB_IC_HW_INFO_H__
#define __HALBB_IC_HW_INFO_H__

enum bb_ic_t {
	/*BB_RTL8852AA	=	BIT(0), 8852A Acut*/
	BB_RTL8852A	=	BIT(1), /*8852A > Bcut*/
	BB_RTL8852B	=	BIT(2),
	BB_RTL8852C	=	BIT(3),
	BB_RTL8834A	=	BIT(4),
	BB_RTL8192XB	=	BIT(5),
	BB_RTL8730E	=	BIT(6),
	BB_RTL8720E = 	BIT(7),
	BB_RTL8721F = 	BIT(8)
};


#define BB_IC_AX_1SS		(BB_RTL8730E | BB_RTL8720E | BB_RTL8721F)

/*@====the following macro DO NOT need to update when adding a new IC======= */


/*@==========================================================================*/

#define BB_IC_AX_CLIENT		(BB_RTL8730E | BB_RTL8720E | BB_RTL8721F)

/*@==========================================================================*/

#define BB_IC_DBCC		0

/*@==========================================================================*/

/*@==========================================================================*/
#define HALBB_MAX_PATH	1

#define HALBB_EFUSE_MAX_PATH 2
/*@==========================================================================*/
#define HALBB_COMPILE_CLIENT_SERIES

/*@==========================================================================*/

/*@==========================================================================*/
/*txdesc rate format for ax ic*/
enum halbb_rate_table {
	BB_01M			= 0,
	BB_02M			= 1,
	BB_05M			= 2,
	BB_11M			= 3,
	BB_06M			= 4,
	BB_09M			= 5,
	BB_12M			= 6,
	BB_18M			= 7,
	BB_24M			= 8,
	BB_36M			= 9,
	BB_48M			= 10,
	BB_54M			= 11,
	BB_HT_MCS0		= 128,	/*0x80*/
	BB_VHT_1SS_MCS0	= 256,	/*0x100*/
	BB_VHT_2SS_MCS0	= 272,	/*0x110*/
	BB_VHT_3SS_MCS0	= 288,
	BB_VHT_4SS_MCS0	= 304,
	BB_VHT_5SS_MCS0	= 320,
	BB_VHT_6SS_MCS0	= 336,
	BB_VHT_7SS_MCS0	= 352,
	BB_VHT_8SS_MCS0	= 368,
	BB_HE_1SS_MCS0		= 384,	/*0x180*/
	BB_HE_2SS_MCS0		= 400,	/*0x190*/
	BB_HE_3SS_MCS0		= 416,
	BB_HE_4SS_MCS0		= 432,
	BB_HE_5SS_MCS0		= 448,
	BB_HE_6SS_MCS0		= 464,
	BB_HE_7SS_MCS0		= 480,
	BB_HE_8SS_MCS0		= 496
};

enum halbb_legacy_spec_rate {
	BB_SPEC_RATE_6M		= 0xb,
	BB_SPEC_RATE_9M		= 0xf,
	BB_SPEC_RATE_12M	= 0xa,
	BB_SPEC_RATE_18M	= 0xe,
	BB_SPEC_RATE_24M	= 0x9,
	BB_SPEC_RATE_36M	= 0xd,
	BB_SPEC_RATE_48M	= 0x8,
	BB_SPEC_RATE_54M	= 0xc
};

#define BB_HT_MCS(x) 		(BB_HT_MCS0 + x)
#define BB_VHT_1SS_MCS(x)	(BB_VHT_1SS_MCS0 + x)
#define BB_HE_1SS_MCS(x)	(BB_HE_1SS_MCS0 + x)

#define BB_VHT_MCS(SS, x)	(BB_VHT_1SS_MCS0 + ((SS - 1) * 16 ) + x)
#define BB_HE_MCS(SS, x)	(BB_HE_1SS_MCS0 + ((SS - 1) * 16 ) + x)

/*[Rate Number]*/
#define	HT_NUM_MCS		8
#define	HE_VHT_NUM_MCS		12
#define	LEGACY_RATE_NUM		12

#define	HT_RATE_NUM_4SS		(HT_NUM_MCS * 4)
#define	VHT_RATE_NUM_4SS	(HE_VHT_NUM_MCS * 4)
#define	HE_RATE_NUM_4SS		(HE_VHT_NUM_MCS * 4)

#define	HT_RATE_NUM_3SS		(HT_NUM_MCS * 3)
#define	VHT_RATE_NUM_3SS	(HE_VHT_NUM_MCS * 3)
#define	HE_RATE_NUM_3SS		(HE_VHT_NUM_MCS * 3)

#define	HT_RATE_NUM_2SS		(HT_NUM_MCS * 2)
#define	VHT_RATE_NUM_2SS	(HE_VHT_NUM_MCS * 2)
#define	HE_RATE_NUM_2SS		(HE_VHT_NUM_MCS * 2)

#define	HT_RATE_NUM_1SS		HT_NUM_MCS
#define	VHT_RATE_NUM_1SS	HE_VHT_NUM_MCS
#define	HE_RATE_NUM_1SS		HE_VHT_NUM_MCS

#define	HT_RATE_NUM	HT_RATE_NUM_1SS
#define	VHT_RATE_NUM	VHT_RATE_NUM_1SS
#define	HE_RATE_NUM	HE_RATE_NUM_1SS

#define	LOW_BW_RATE_NUM		HE_RATE_NUM

/*@==========================================================================*/

/****************************************************************
 * 1 ============================================================
 * 1  enumeration
 * 1 ============================================================
 ***************************************************************/
enum bb_mode_type { /*@Fast antenna training*/
	BB_LEGACY_MODE	= 0,
	BB_HT_MODE	= 1,
	BB_VHT_MODE	= 2,
	BB_HE_MODE	= 3
};


/* BB_CMNINFO_CART_VER */
enum halbb_cart_ver {
	BB_CART_A		= 0,
	BB_CART_B		= 1,
	BB_CART_C		= 2,
	BB_CART_D		= 3,
	BB_CART_E		= 4,
	BB_CART_F		= 5,
	BB_CART_G		= 6,
	BB_CART_H		= 7,
	BB_CART_I		= 8,
	BB_CART_J		= 9,
	BB_CART_K		= 10,
	BB_CART_L		= 11,
	BB_CART_M		= 12,
	BB_CART_N		= 13,
	BB_CART_O		= 14,
	BB_CART_TEST		= 15,
};

enum bb_path {
	BB_PATH_NON	= 0,
	BB_PATH_A	= 0x00000001,
	BB_PATH_B	= 0x00000002,
	BB_PATH_C	= 0x00000004,
	BB_PATH_D	= 0x00000008,

	BB_PATH_AB	= (BB_PATH_A | BB_PATH_B),
	BB_PATH_AC	= (BB_PATH_A | BB_PATH_C),
	BB_PATH_AD	= (BB_PATH_A | BB_PATH_D),
	BB_PATH_BC	= (BB_PATH_B | BB_PATH_C),
	BB_PATH_BD	= (BB_PATH_B | BB_PATH_D),
	BB_PATH_CD	= (BB_PATH_C | BB_PATH_D),

	BB_PATH_ABC	= (BB_PATH_A | BB_PATH_B | BB_PATH_C),
	BB_PATH_ABD	= (BB_PATH_A | BB_PATH_B | BB_PATH_D),
	BB_PATH_ACD	= (BB_PATH_A | BB_PATH_C | BB_PATH_D),
	BB_PATH_BCD	= (BB_PATH_B | BB_PATH_C | BB_PATH_D),

	BB_PATH_ABCD	= (BB_PATH_A | BB_PATH_B | BB_PATH_C | BB_PATH_D),
	BB_PATH_AUTO	= 0xff /*for auto path selection*/
};

enum rf_syn {
	RF_SYN0 = 0,
	RF_SYN1 = 1,
};

enum rf_rx_path {
	RF_PATH_MAIN = 0,
	RF_PATH_AUX = 1,
};

#endif
