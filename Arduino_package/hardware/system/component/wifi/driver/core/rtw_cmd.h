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
#ifndef __RTW_CMD_H_
#define __RTW_CMD_H_

#include "rtw_wifi_constants.h"

struct cmd_obj {
	u8 iface_type;
	u8	*parmbuf;
	u32	parm_nobuf;
	int(*cmd_hdl)(u8 iface_type, struct cmd_obj *pcmd);
	struct list_head	list;
};

enum LPS_CTRL_TYPE {
	LPS_CTRL_SCAN = 0,
	LPS_CTRL_JOINBSS = 1,
	LPS_CTRL_CONNECT = 2,
	LPS_CTRL_DISCONNECT = 3,
	LPS_CTRL_SPECIAL_PACKET = 4,
	LPS_CTRL_LEAVE = 5,
	LPS_CTRL_DENY = 6,
};

#define RTW_CHANNEL_SCAN_AMOUNT (14+37)

/*
Caller Mode: Infra

a. algorithm: wep40, wep104, tkip & aes
b. keytype: grp key/unicast key
c. key contents

when shared key ==> keyid is the camid
when 802.1x ==> keyid [0:1] ==> grp key
when 802.1x ==> keyid > 2 ==> unicast key

*/
struct setkey_parm {
	u8	algorithm;	// encryption algorithm, could be none, wep40, TKIP, CCMP, wep104
	u8	keyid;
	u8 	grpkey;		// 1: this is the grpkey for 802.1x. 0: this is the unicast key for 802.1x
	u8 	set_tx;		// 1: main tx key for wep. 0: other key.
	u8	key[16];	// this could be 40 or 104
};

/*
When in AP or Ad-Hoc mode, this is used to
allocate an sw/hw entry for a newly associated sta.

Command

when shared key ==> algorithm/keyid

*/
struct set_stakey_parm {
	u8	addr[ETH_ALEN];
	u8	algorithm;
	u8 	id;// currently for erasing cam entry if algorithm == _NO_PRIVACY_
	u8	key[32];
	u8	gk;
};

struct addBaReq_parm {
	unsigned int tid;
	u8	addr[ETH_ALEN];
};


#define REQ_CH_NONE		-1
#define REQ_BW_NONE		-1
#define REQ_OFFSET_NONE	-1
#endif // _RTW_CMD_H_
