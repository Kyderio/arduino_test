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
#ifndef __ROM_WIFI_HAL_COMMON_H__
#define __ROM_WIFI_HAL_COMMON_H__

//CCK
#define RATE_1M				BIT(0)
#define RATE_2M				BIT(1)
#define RATE_5_5M			BIT(2)
#define RATE_11M			BIT(3)
//OFDM
#define RATE_6M				BIT(4)
#define RATE_9M				BIT(5)
#define RATE_12M			BIT(6)
#define RATE_18M			BIT(7)
#define RATE_24M			BIT(8)
#define RATE_36M			BIT(9)
#define RATE_48M			BIT(10)
#define RATE_54M			BIT(11)
//MCS 1 Spatial Stream
#define RATE_MCS0			BIT(12)
#define RATE_MCS1			BIT(13)
#define RATE_MCS2			BIT(14)
#define RATE_MCS3			BIT(15)
#define RATE_MCS4			BIT(16)
#define RATE_MCS5			BIT(17)
#define RATE_MCS6			BIT(18)
#define RATE_MCS7			BIT(19)
//MCS 2 Spatial Stream
#define RATE_MCS8			BIT(20)
#define RATE_MCS9			BIT(21)
#define RATE_MCS10			BIT(22)
#define RATE_MCS11			BIT(23)
#define RATE_MCS12			BIT(24)
#define RATE_MCS13			BIT(25)
#define RATE_MCS14			BIT(26)
#define RATE_MCS15			BIT(27)

#define RATE_BITMAP_ALL			0xFFFFF

//-----------------------------------------------------------
//	Rate
//-----------------------------------------------------------
// CCK Rates, TxHT = 0
#define DESC_RATE1M			0x00
#define DESC_RATE2M			0x01
#define DESC_RATE5_5M			0x02
#define DESC_RATE11M			0x03

// OFDM Rates, TxHT = 0
#define DESC_RATE6M			0x04
#define DESC_RATE9M			0x05
#define DESC_RATE12M			0x06
#define DESC_RATE18M			0x07
#define DESC_RATE24M			0x08
#define DESC_RATE36M			0x09
#define DESC_RATE48M			0x0a
#define DESC_RATE54M			0x0b

// MCS Rates, TxHT = 1
#define DESC_RATEMCS0			0x0c
#define DESC_RATEMCS1			0x0d
#define DESC_RATEMCS2			0x0e
#define DESC_RATEMCS3			0x0f
#define DESC_RATEMCS4			0x10
#define DESC_RATEMCS5			0x11
#define DESC_RATEMCS6			0x12
#define DESC_RATEMCS7			0x13
#define DESC_RATEMCS8			0x14
#define DESC_RATEMCS9			0x15
#define DESC_RATEMCS10			0x16
#define DESC_RATEMCS11			0x17
#define DESC_RATEMCS12			0x18
#define DESC_RATEMCS13			0x19
#define DESC_RATEMCS14			0x1a
#define DESC_RATEMCS15			0x1b
#define DESC_RATEMCS16			0x1C
#define DESC_RATEMCS17			0x1D
#define DESC_RATEMCS18			0x1E
#define DESC_RATEMCS19			0x1F
#define DESC_RATEMCS20			0x20
#define DESC_RATEMCS21			0x21
#define DESC_RATEMCS22			0x22
#define DESC_RATEMCS23			0x23
#define DESC_RATEMCS24			0x24
#define DESC_RATEMCS25			0x25
#define DESC_RATEMCS26			0x26
#define DESC_RATEMCS27			0x27
#define DESC_RATEMCS28			0x28
#define DESC_RATEMCS29			0x29
#define DESC_RATEMCS30			0x2A
#define DESC_RATEMCS31			0x2B

#define DESC_RATEVHTSS1MCS0		0x2c
#define DESC_RATEVHTSS1MCS1		0x2d
#define DESC_RATEVHTSS1MCS2		0x2e
#define DESC_RATEVHTSS1MCS3		0x2f
#define DESC_RATEVHTSS1MCS4		0x30
#define DESC_RATEVHTSS1MCS5		0x31
#define DESC_RATEVHTSS1MCS6		0x32
#define DESC_RATEVHTSS1MCS7		0x33
#define DESC_RATEVHTSS1MCS8		0x34
#define DESC_RATEVHTSS1MCS9		0x35
#define DESC_RATEVHTSS2MCS0		0x36
#define DESC_RATEVHTSS2MCS1		0x37
#define DESC_RATEVHTSS2MCS2		0x38
#define DESC_RATEVHTSS2MCS3		0x39
#define DESC_RATEVHTSS2MCS4		0x3a
#define DESC_RATEVHTSS2MCS5		0x3b
#define DESC_RATEVHTSS2MCS6		0x3c
#define DESC_RATEVHTSS2MCS7		0x3d
#define DESC_RATEVHTSS2MCS8		0x3e
#define DESC_RATEVHTSS2MCS9		0x3f
#define DESC_RATEVHTSS3MCS0		0x40
#define DESC_RATEVHTSS3MCS1		0x41
#define DESC_RATEVHTSS3MCS2		0x42
#define DESC_RATEVHTSS3MCS3		0x43
#define DESC_RATEVHTSS3MCS4		0x44
#define DESC_RATEVHTSS3MCS5		0x45
#define DESC_RATEVHTSS3MCS6		0x46
#define DESC_RATEVHTSS3MCS7		0x47
#define DESC_RATEVHTSS3MCS8		0x48
#define DESC_RATEVHTSS3MCS9		0x49
#define DESC_RATEVHTSS4MCS0		0x4A
#define DESC_RATEVHTSS4MCS1		0x4B
#define DESC_RATEVHTSS4MCS2		0x4C
#define DESC_RATEVHTSS4MCS3		0x4D
#define DESC_RATEVHTSS4MCS4		0x4E
#define DESC_RATEVHTSS4MCS5		0x4F
#define DESC_RATEVHTSS4MCS6		0x50
#define DESC_RATEVHTSS4MCS7		0x51
#define DESC_RATEVHTSS4MCS8		0x52
#define DESC_RATEVHTSS4MCS9		0x53

#define HAL_NAV_UPPER_UNIT		128		// micro-second

#define PageNum_128(_Len)		(u32)(((_Len)>>7) + ((_Len)&0x7F ? 1:0))
#define PageNum(_Len, _Size)		(u32)(((_Len)/(_Size)) + ((_Len)&((_Size) - 1) ? 1:0))

enum chip_name_e {
	CHIP_8721D = 14,
	CHIP_8735B = 18,
	CHIP_8720E = 20,
	CHIP_8730E = 21,
	CHIP_8721DA = 22,
	CHIP_8721F = 23,
	CHIP_8735C = 24,
};

enum chip_type_e {
	TEST_CHIP = 0,
	NORMAL_CHIP = 1,
	FPGA = 2,
};

enum chip_cut_e {	/* Cut version: halbb version name merged with phydm HAL_CUT_VERSION_E. */
	CAV,	/* A_CUT_VERSION = 0. */
	CBV,	/* B_CUT_VERSION = 1. */
	CCV,	/* C_CUT_VERSION = 2. */
	CDV,	/* D_CUT_VERSION = 3. */
	CEV,	/* E_CUT_VERSION = 4. */
	CFV,	/* F_CUT_VERSION = 5. */
	CIV,	/* I_CUT_VERSION = 8. */
};

// HAL_Manufacturer
enum chip_vendor_e {
	CHIP_VENDOR_TSMC = 0,
	CHIP_VENDOR_UMC = 1,
	CHIP_VENDOR_SMIC = 2,
};

enum {
	VO_QUEUE = 0,
	VI_QUEUE = 1,
	BE_QUEUE = 2,
	BK_QUEUE = 3,
	MG_QUEUE = 4,
	RX_QUEUE = 5,
	H0_QUEUE = 6,
	H1_QUEUE = 7,
	H2_QUEUE = 8,
	H3_QUEUE = 9,
	H4_QUEUE = 10,
	H5_QUEUE = 11,
	H6_QUEUE = 12,
	H7_QUEUE = 13,
	BCN_QUEUE = 14,
	MAX_TX_QUEUE = 15,
	ERROR_QUEUE = 16,
};

#define IS_LEGACY_MODE_RATE(desc_rate)	(((desc_rate >> 7) & 0x3) == HAL_LEGACY_MODE)
#define IS_HT_MODE_RATE(desc_rate)	(((desc_rate >> 7) & 0x3) == HAL_HT_MODE)
#define IS_VHT_MODE_RATE(desc_rate)	(((desc_rate >> 7) & 0x3) == HAL_VHT_MODE)
#define IS_HE_MODE_RATE(desc_rate)	(((desc_rate >> 7) & 0x3) == HAL_HE_MODE)

#endif

