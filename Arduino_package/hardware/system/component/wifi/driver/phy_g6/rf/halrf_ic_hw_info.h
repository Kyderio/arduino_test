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
#ifndef __HALRF_IC_HW_INFO_H__
#define __HALRF_IC_HW_INFO_H__

enum halrf_ic {
	RF_RTL8730E	=	BIT(7),
	RF_RTL8720E	=	BIT(8),
	RF_RTL8721F	=	BIT(9)
	/* add new IC blow */
};

/*@==========================================================================*/
#define KIP_REG 128
#define KPATH 1

/*@==========================================================================*/

/*@==========================================================================*/



/*@==========================================================================*/

/****************************************************************
 * 1 ============================================================
 * 1  enumeration
 * 1 ============================================================
 ***************************************************************/

enum rf_path_bit {
	RF_A	= BIT(0),
	RF_B	= BIT(1),
	RF_C	= BIT(2),
	RF_D	= BIT(3),

	RF_AB	= (RF_A | RF_B),
};

enum halrf_ant {
	RF_MAIN_ANT	= 1,
	RF_AUX_ANT	= 2,
};

#endif
