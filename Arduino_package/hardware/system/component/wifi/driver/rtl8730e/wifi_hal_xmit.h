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
#ifndef __WIFI_HAL_XMIT_H__
#define __WIFI_HAL_XMIT_H__

//OFFSET 0
#define OFFSET_SZ			0
#define OFFSET_SHT			16
#define BMC				BIT(24)
#define LSG				BIT(26)
#define FSG				BIT(27)
#define OWN 				BIT(31)

//OFFSET 4
#define PKT_OFFSET_SZ			0
#define BK				BIT(6)
#define QSEL_SHT			8
#define Rate_ID_SHT			16
#define NAVUSEHDR			BIT(20)
#define PKT_OFFSET_SHT			26
#define HWPC				BIT(31)

//OFFSET 8
#define AGG_EN				BIT(29)

//OFFSET 12
#define SEQ_SHT				16

//OFFSET 16
#define QoS				BIT(6)
#define HW_SEQ_EN			BIT(7)
#define USERATE				BIT(8)
#define DISDATAFB			BIT(10)
#define DATA_SHORT			BIT(24)
#define DATA_BW				BIT(25)

//OFFSET 20
#define SGI				BIT(6)

#define GET_FIX_RATE(v)		((v) & 0x0FFF)
#define GET_FIX_RATE_SGI(v)	(((v) & 0x7000) >> 12)
#define GET_FIX_RATE_ER_EN(v)	(((v) & 0x10000) >> 16)
#define GET_FIX_RATE_ER_BW(v)	(((v) & 0x20000) >> 17)

//Tx Buffer Descriptor
#define SET_TXBUFFER_DESC_LEN_WITH_OFFSET(txbd, offset, val)		SET_TRX_BD(txbd+(offset*8), 0, 16, val)
#define SET_TXBUFFER_DESC_AMSDU_WITH_OFFSET(txbd, offset, val)		SET_TRX_BD(txbd+(offset*8), 31, 1, val)
#define SET_TXBUFFER_DESC_ADD_LOW_WITH_OFFSET(txbd, offset, val)	SET_TRX_BD(txbd+(offset*8)+4, 0, 32, val)

// Dword 0
#define SET_TX_BUFF_DESC_LEN(txbd, val)				SET_TRX_BD(txbd, 0, 16, val)
#define SET_TX_BUFF_DESC_PSB(txbd, val)				SET_TRX_BD(txbd, 16, 8, val)
#define SET_TX_BUFF_DESC_OWN(txbd, val)				SET_TRX_BD(txbd, 31, 1, val)

// Dword 1
#define SET_TX_BUFF_DESC_ADDR_LOW(txbd, val)			SET_TRX_BD(txbd+4, 0, 32, val)
#endif

