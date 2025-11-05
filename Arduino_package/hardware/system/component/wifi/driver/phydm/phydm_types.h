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
#ifndef __ODM_TYPES_H__
#define __ODM_TYPES_H__

/*Define Different SW team support*/
#define	ODM_ADSL		0x10
/*BIT(4)*/		/*already combine with ODM_AP, and is nouse now*/
#define	ODM_IOT		0x20	/*BIT(5)*/

/*For FW API*/
#define	__iram_odm_func__
#define	__odm_func__
#define	__odm_func_aon__

/*Deifne HW endian support*/
#define	ODM_ENDIAN_BIG	0
#define	ODM_ENDIAN_LITTLE	1

#if defined(CONFIG_RTL_TRIBAND_SUPPORT) && defined(CONFIG_USB_HCI)
/* enable PCI & USB HCI at the same time */
#define RT_PCI_USB_INTERFACE			1
#define	RT_PCI_INTERFACE			RT_PCI_USB_INTERFACE
#define RT_USB_INTERFACE			RT_PCI_USB_INTERFACE
#define	RT_SDIO_INTERFACE			3
#define   RT_AXI_INTERFACE			4
#else
#define	RT_PCI_INTERFACE			1
#define	RT_USB_INTERFACE			2
#define	RT_SDIO_INTERFACE			3
#define   RT_AXI_INTERFACE			4
#endif

#define		VISTA_USB_RX_REVISE			0

/*
 * Declare for ODM spin lock definition temporarily fro compile pass.
 */
enum rt_spinlock_type {
	RT_TX_SPINLOCK = 1,
	RT_RX_SPINLOCK = 2,
	RT_RM_SPINLOCK = 3,
	RT_CAM_SPINLOCK = 4,
	RT_SCAN_SPINLOCK = 5,
	RT_LOG_SPINLOCK = 7,
	RT_BW_SPINLOCK = 8,
	RT_CHNLOP_SPINLOCK = 9,
	RT_RF_OPERATE_SPINLOCK = 10,
	RT_INITIAL_SPINLOCK = 11,
	RT_RF_STATE_SPINLOCK = 12,
	/* For RF state. Added by Bruce, 2007-10-30. */
#if VISTA_USB_RX_REVISE
	RT_USBRX_CONTEXT_SPINLOCK = 13,
	RT_USBRX_POSTPROC_SPINLOCK = 14,
	/* protect data of padapter->IndicateW/ IndicateR */
#endif
	/* Shall we define Ndis 6.2 SpinLock Here ? */
	RT_PORT_SPINLOCK = 16,
	RT_VNIC_SPINLOCK = 17,
	RT_HVL_SPINLOCK = 18,
	RT_H2C_SPINLOCK = 20,
	/* For H2C cmd. Added by tynli. 2009.11.09. */

	rt_bt_data_spinlock = 25,

	RT_WAPI_OPTION_SPINLOCK = 26,
	RT_WAPI_RX_SPINLOCK = 27,

	/* add for 92D CCK control issue */
	RT_CCK_PAGEA_SPINLOCK = 28,
	RT_BUFFER_SPINLOCK = 29,
	RT_CHANNEL_AND_BANDWIDTH_SPINLOCK = 30,
	RT_GEN_TEMP_BUF_SPINLOCK = 31,
	RT_AWB_SPINLOCK = 32,
	RT_FW_PS_SPINLOCK = 33,
	RT_HW_TIMER_SPIN_LOCK = 34,
	RT_MPT_WI_SPINLOCK = 35,
	RT_P2P_SPIN_LOCK = 36,	/* Protect P2P context */
	RT_DBG_SPIN_LOCK = 37,
	RT_IQK_SPINLOCK = 38,
	RT_PENDED_OID_SPINLOCK = 39,
	RT_CHNLLIST_SPINLOCK = 40,
	RT_INDIC_SPINLOCK = 41,	/* protect indication */
	RT_RFD_SPINLOCK = 42,
	RT_SYNC_IO_CNT_SPINLOCK = 43,
	RT_LAST_SPINLOCK,
};

#if (DM_ODM_SUPPORT_TYPE == ODM_IOT)
#define RATE_ADAPTIVE_SUPPORT			0

#define DEV_BUS_TYPE		RT_AXI_INTERFACE

/* for power limit table */
/*Considering the compatible of tool to all ic on global variable of regu_en [15],
 ** modifying Value in enum odm_pw_lmt_regulation_type according to enum halrf_pw_lmt_regulation_type
 */
enum odm_pw_lmt_regulation_type {
	PW_LMT_REGU_WW13 = 0,
	PW_LMT_REGU_ETSI = 1,
	PW_LMT_REGU_FCC = 2,
	PW_LMT_REGU_MKK = 3,
	PW_LMT_REGU_NA = 4,
	PW_LMT_REGU_IC = 5,
	PW_LMT_REGU_KCC = 6,
	PW_LMT_REGU_ACMA = 7,
	PW_LMT_REGU_NCC = 8,
	PW_LMT_REGU_MEXICO = 9,
	PW_LMT_REGU_CHILE = 10,
	PW_LMT_REGU_UKRAINE = 11,
	PW_LMT_REGU_CN = 12,
	PW_LMT_REGU_QATAR = 13,
	PW_LMT_REGU_UK = 14,
	PW_LMT_REGU_MAX_NUM = 15
};

enum odm_pw_lmt_band_type {
	PW_LMT_BAND_2_4G = 0,
	PW_LMT_BAND_5G = 1
};

enum odm_pw_lmt_bandwidth_type {
	PW_LMT_BW_20M = 0,
	PW_LMT_BW_40M = 1,
	PW_LMT_BW_80M = 2
};

enum odm_pw_lmt_ratesection_type {
	PW_LMT_RS_CCK = 0,
	PW_LMT_RS_OFDM = 1,
	PW_LMT_RS_HT = 2,
	PW_LMT_RS_VHT = 3
};

enum odm_pw_lmt_rfpath_type {
	PW_LMT_PH_1T = 0,
	PW_LMT_PH_2T = 1,
	PW_LMT_PH_3T = 2,
	PW_LMT_PH_4T = 3
};

#define	phydm_timer_list	timer_list
#if (defined(TESTCHIP_SUPPORT))
#define	PHYDM_TESTCHIP_SUPPORT 1
#else
#define	PHYDM_TESTCHIP_SUPPORT 0
#endif

#endif

#define READ_NEXT_PAIR(v1, v2, i) do { if (i + 2 >= array_len) break; i += 2; v1 = array[i]; v2 = array[i + 1]; } while (0)
#define COND_ELSE  2
#define COND_ENDIF 3

#define	MASKBYTE0		0xff
#define	MASKBYTE1		0xff00
#define	MASKBYTE2		0xff0000
#define	MASKBYTE3		0xff000000
#define	MASKHWORD		0xffff0000
#define	MASKLWORD		0x0000ffff
#define	MASKDWORD		0xffffffff

#define	MASK7BITS		0x7f
#define	MASK12BITS		0xfff
#define	MASKH4BITS		0xf0000000
#define	MASK20BITS		0xfffff
#define	MASK24BITS		0xffffff
#define	MASKOFDM_D		0xffc00000
#define	MASKCCK			0x3f3f3f3f

#define RFREGOFFSETMASK		0xfffff
#define RFREG_MASK		0xfffff

#define MASKH3BYTES		0xffffff00
#define MASKL3BYTES		0x00ffffff
#define MASKBYTE2HIGHNIBBLE	0x00f00000
#define MASKBYTE3LOWNIBBLE	0x0f000000
#define	MASKL3BYTES		0x00ffffff

#endif /* __ODM_TYPES_H__ */
