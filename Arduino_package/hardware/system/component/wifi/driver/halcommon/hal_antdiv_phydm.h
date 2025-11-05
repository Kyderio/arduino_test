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

#ifndef __HAL_ANTDIV_PHYDM_H__
#define __HAL_ANTDIV_PHYDM_H__

/* @1 ============================================================
 * 1  Definition
 * 1 ============================================================
 */

#define	ANTDIV_INIT		0xff

/* ant type define, note that it needs to be matched with txd/rxd */
#define	MAIN_ANT	1		/*@ant A or ant Main   or S1*/
#define	AUX_ANT		2		/*@AntB or ant Aux   or S0*/
#define	MAX_ANT		3		/* @3 for AP using*/

#define ANTDIV_ON	1
#define ANTDIV_OFF	0

#define TX_BY_DESC	1		/* multi-entry */
#define TX_BY_REG	0		/* one entry */
/* @1 ============================================================
 * 1  enumeration
 * 1 ============================================================
 */



/* @1 ============================================================
 * 1  structure
 * 1 ============================================================
 */

struct rtw_antdiv_rssi_info {
	u16 main_rssi_sum_ofdm;  /* >=ofdm(including ht/vht) */
	u16 main_rssi_sum_cck;  /* cck */
	u16 main_cnt_ofdm;
	u16 main_cnt_cck;
	u16 aux_rssi_sum_ofdm;
	u16 aux_rssi_sum_cck;
	u16 aux_cnt_ofdm;
	u16 aux_cnt_cck;
	u8 txd_antsel_a;
};

struct rtw_antdiv_info {
#ifdef CONFIG_WIFI_ANTDIV
	/* rssi static */
	struct rtw_antdiv_rssi_info antdiv_rssi_info;  /* for rssi */

	u8 rxd_antsel_a;           /* physts report info */
	u8 rx_idle_ant;
	u8 hw_antdiv_on_off;

	u8 b_linked : 1;
	u8 b_one_entry_only : 1;   /* only one assocaited client */
	u8 b_antdiv_enable : 1;    /* antdiv capability enable */
#endif
};


/* @1 ============================================================
 * 1  function prototype
 * 1 ============================================================
 */
void wifi_hal_antdiv_update_rx_idle_ant(u8 ant);
void wifi_hal_antdiv_get_rssi_info(bool is_cck, u8 mac_id, u8 rssi);
void wifi_hal_antdiv_init(void);
void wifi_hal_antdiv_watchdog(void);

#endif /* __HAL_ANTDIV_PHYDM_H__ */

