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
#ifndef __HAL_COMMON_REG_H__
#define __HAL_COMMON_REG_H__

#include "wifi_reg_page0.h"
#include "wifi_reg_page1.h"
#include "wifi_reg_page2.h"
#include "wifi_reg_page3.h"
#include "wifi_reg_page4.h"
#include "wifi_reg_page5.h"
#include "wifi_reg_page6.h"
#include "wifi_reg_page7.h"
#include "wifi_share_info.h"

#define REG_AMPDU_MIN_SPACE			0x045C

#define MAX_MSS_DENSITY_1T 			0x0A

#define BW_OPMODE_20MHZ			BIT2

//2 RF_CTRL
#define RF_EN					BIT(0)
#define RF_RSTB					BIT(1)
#define RF_SDMRSTB				BIT(2)
#define RF_DAI_REG00_WREN		BIT(6)
#define RF_DAI_RW_EN			BIT(7)

//2 MCUFWDL
#define WINTINI_RDY				BIT(6)

//2 PBP - Page Size Register
#define _PSRX(x)				(x)
#define _PSTX(x)				((x) << 4)

#define PBP_64					0x0
#define PBP_128					0x1
#define PBP_256					0x2
#define PBP_512					0x3
#define PBP_1024				0x4

// For normal driver, 0x10C
#define BIT_TXDMA_CMQ_MAP(x) 	 		(((x)&0x3) << 16)
#define BIT_TXDMA_HIQ_MAP(x) 	 		(((x)&0x3) << 14)
#define BIT_TXDMA_MGQ_MAP(x) 	 		(((x)&0x3) << 12)
#define BIT_TXDMA_BKQ_MAP(x) 	 		(((x)&0x3) << 10)
#define BIT_TXDMA_BEQ_MAP(x) 	 		(((x)&0x3) << 8 )
#define BIT_TXDMA_VIQ_MAP(x) 	 		(((x)&0x3) << 6 )
#define BIT_TXDMA_VOQ_MAP(x) 	 		(((x)&0x3) << 4 )

//2 BCN_CTRL
#define DIS_ATIM					BIT(0)
#define DIS_BCNQ_SUB			BIT(1)

// REG_HCI_CTRL
#define SW_BCN_ADDR_SEL		BIT(16)

#define bCCKEn                      BIT(24)
#define bOFDMEn                     BIT(25)

// 4. PageA(0xA00)
#define bCCKBBMode					0x3
#define bCCKSideBand				0x10		// Reg 0xa00 rCCK0_System 20/40 switch
#define bCCKScramble				0x8
#define bCCKTxRate					0x3000

// 6. PageE(0xE00)
#define bOFDMContinueTx				0x10000000
#define bOFDMSingleCarrier			0x20000000
#define bOFDMSingleTone				0x40000000


#define BIT_MASK_RESP_TXRATE			((u8)0x000000FF << 0)          /*!<R/W 0x04  tx rate use to decide response rate */
#define BIT_RESP_TXRATE(x)				(((u8)((x) & 0x000000FF) << 0))

#define REG_AXI_CTRL					REG_HCI_CTRL
#define REG_WOW_NAN_CTRL				REG_WOW_CTRL


#define REG_RXFLTMAP0					REG_RXFLTER0

#endif //__HAL_COMMON_H__

