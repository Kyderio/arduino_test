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
#ifndef __RTW_LPS_H_
#define __RTW_LPS_H_

#if 1//def CONFIG_WMMPS_STA
#define WMM_IE_UAPSD_VO 	BIT0
#define WMM_IE_UAPSD_VI 		BIT1
#define WMM_IE_UAPSD_BK 	BIT2
#define WMM_IE_UAPSD_BE 	BIT3

#define WMM_TID0 	BIT0
#define WMM_TID1 	BIT1
#define WMM_TID2 	BIT2
#define WMM_TID3 	BIT3
#define WMM_TID4 	BIT4
#define WMM_TID5 	BIT5
#define WMM_TID6 	BIT6
#define WMM_TID7 	BIT7

#define AP_SUPPORTED_UAPSD				BIT7
/* TC = Traffic Category,  TID0~7 represents TC */
#define BIT_MASK_TID_TC					0xff
#define ALL_TID_TC_SUPPORTED_UAPSD		0xff

#endif /* CONFIG_WMMPS_STA */

/*
	BIT[2:0] = HW state
	BIT[3] = Protocol PS state,   0: register active state , 1: register sleep state
	BIT[4] = sub-state
*/

#define PS_DPS				BIT(0)
#define PS_LCLK				(PS_DPS)
#define PS_RF_OFF			BIT(1)
#define PS_ALL_ON			BIT(2)
#define PS_ST_ACTIVE		BIT(3)

#define PS_ACK				BIT(6)

#define PS_STATE_MASK		(0x0F)
#define PS_STATE_HW_MASK	(0x07)
#define PS_SEQ_MASK			(0xc0)

#define PS_STATE(x)		(PS_STATE_MASK & (x))
#define PS_STATE_HW(x)	(PS_STATE_HW_MASK & (x))
#define PS_SEQ(x)		(PS_SEQ_MASK & (x))

#define PS_STATE_S0		(PS_DPS)
#define PS_STATE_S4		((PS_ST_ACTIVE) | (PS_ALL_ON))

struct reportpwrstate_parm {
	unsigned char mode;
	unsigned char state; //the CPWM value
	unsigned short rsvd;
};

#define LPS_DELAY_TIME	1 // 1 sec

// RF Off Level for IPS or HW/SW radio off



#define RTW_PWR_STATE_CHK_INTERVAL 2000

#endif  //__RTW_LPS_H_