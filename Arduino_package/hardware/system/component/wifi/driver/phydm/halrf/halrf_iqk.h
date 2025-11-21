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

#ifndef __HALRF_IQK_H__
#define __HALRF_IQK_H__

/*@--------------------------Define Parameters-------------------------------*/
#define LOK_delay 1
#define WBIQK_delay 10
#define TX_IQK 0
#define RX_IQK 1
#define TXIQK 0
#define RXIQK 1
#define RXIQK1 1
#define RXIQK2 2
#define NBTXK 3
#define NBRXK 4
#define LOK1 5
#define LOK2 6

#define kcount_limit_80m 2
#define kcount_limit_others 4
#define rxiqk_gs_limit 6
#define TXWBIQK_EN 1
#define RXWBIQK_EN 1
//#define NUM 1

/*@-----------------------End Define Parameters-----------------------*/

struct dm_dack_info {
	bool dack_en;
	u16 msbk_d[2][2][15];
	u8 dck_d[2][2][2];
	u16 biask_d[2][2];

	u8 new_msbk_d[2][2][16];
	u16 new_biask_d[2];
	u8 dadck_d[2][2];
	bool dack_done;
	u16 addck_d[2][2];
	u16 addc[2][2];
	u32 dack_cnt;
	u32 dack_time;
	bool addck_timeout[2];
	bool dadck_timeout[2];
	bool msbk_timeout[2];
	bool dack_fail;
	u32 afedig_d[128];
};

struct dm_iqk_info {
//#if (defined(CONFIG_AMEBADPLUS) && RFDBG)
//	u32 rxxy[2][2];
//#endif
//	u8 iqk_step;
//	u8 iqk_band;
	u8 iqk_ch;
	u8 iqk_bw;
	bool iqk_fail_report;
#if 0 //defined(CONFIG_AMEBADPLUS)
	u8 iqk_fail_report[2][NUM][2]; /*channel/path/TRX(TX:0, RX:1) */
#endif
	u8 b_rfk_forbidden:1;
};

#endif /*__HALRF_IQK_H__*/
