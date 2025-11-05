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
#ifndef __RTW_SAE_H_
#define __RTW_SAE_H_

/*********************************************************************************************

                     						Micro Defination

*********************************************************************************************/
#define SAE_SEQ_COMMIT 		1
#define SAE_SEQ_CONFIRM 	2

/*********************************************************************************************

                     						Data Structure

*********************************************************************************************/

enum sae_group_config {
	_GRP_KEEP_CURRENT_,		/* keep current group id */
	_GRP_AUTO_SELECT_, 		/* auto select a group id in sae_groups[] */
	_GRP_USER_CONFIG_		/* manually config the group id through user cmd */
};

/*
**  event defination(32bits):
**
**  [ 31:16 ]	[ ~ ]	   [ 9 ]	   [ 8 ]	   [ 7 ]	 [ 6 ]		[ 5 ]	 [ 4 ]	  [ 3 ]   [ 2 ]  [ 1 ]	[ 0 ]
**   status  | reserve | moregroups | lowmac | highmac | badauth | diffgroup | badgroup | badid  | con	| com  | init
*/
enum sae_event {
	_SAE_INIT_ 		 = BIT(0),
	_SAE_COM_  		 = BIT(1),
	_SAE_CON_  		 = BIT(2),
	_SAE_BADID_ 	 = BIT(3),
	_SAE_BADGROUP_ 	 = BIT(4),
	_SAE_DIFFGROUP_  = BIT(5),
	_SAE_BADAUTH_	 = BIT(6),
	_SAE_HIGMAC_	 = BIT(7),
	_SAE_LOWMAC_	 = BIT(8),
	_SAE_MOREGROUPS_ = BIT(9),
};

struct wpa_lite_sae_t {
	u8	user_group_id;     /* for sta global */
	u8	sae_reauth_limit;  /* sta & softap */
	u8	dot11RSNASAESync;  /* sta & softap */
};

extern struct wpa_lite_sae_t wpa_lite_sae;


void rtw_sae_free_instance(struct wpa_sta_info *pStaInfo, const char *reason);

#endif	//__RTW_SAE_H_

