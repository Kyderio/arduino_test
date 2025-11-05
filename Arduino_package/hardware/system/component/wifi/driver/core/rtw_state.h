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

#ifndef __RTW_STATE_H__
#define __RTW_STATE_H__

/*for sta mode to use*/
#define WIFI_STA_STATE_NOLINK				0x00000000
#define	WIFI_STA_STATE_JOIN_PREPARE 		0x00000100
#define	WIFI_STA_STATE_AUTH_NULL			0x00000200
#define	WIFI_STA_STATE_AUTH_DOING			0x00000400
#define	WIFI_STA_STATE_AUTH_SUCCESS			0x00000800
#define	WIFI_STA_STATE_ASSOC_DOING			0x00002000
#define	WIFI_STA_STATE_ASSOC_SUCCESS		0x00004000

/*for softap's client to use*/
#define	WIFI_AP_CLIENT_AUTH_DOING	0x00000001
#define	WIFI_AP_CLIENT_AUTH_SUCCESS	0x00000002
#define	WIFI_AP_CLIENT_ASSOC_SUCCESS	0x00000004

struct traffic_detect {
	u32			NumTxOkInPeriod;
	u32			NumRxOkInPeriod;
	u32			NumRxUnicastOkInPeriod;
	u16			NumRxBcnInPeriod;
	u8			bBusyTraffic : 1;
	u8			bBusyRxTraffic : 1;
	u8			bBusyTxTraffic : 1;
	u32			rom_rsvd;
};

enum join_result_stats {
	RES_SUCCESS                =  0,  /* boundary between succes and failure, when > 0, joinbss is successful */
	RES_FAIL_IN_AUTH           = -1,  /* auth_doing | auth_null & b_external_sae_ongoing */
	RES_FAIL_IN_ASSOC          = -2,  /* assoc_doing */
	RES_FAIL_IN_PRE_AUTH       = -3,  /* join_prepare(after scan done) | auth_null */
	RES_FAIL_IN_ASSOC_RESP_ERR = -4,  /* specially: assoc resp with status code > 0 */
};

#endif //__RTW_STATE_H__

