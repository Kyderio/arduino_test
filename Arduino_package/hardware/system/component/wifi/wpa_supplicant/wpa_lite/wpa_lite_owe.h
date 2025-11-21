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
#ifndef __RTW_OWE_H_
#define __RTW_OWE_H_

struct owe_priv_t {
	u8					pmk[PMK_LEN_MAX];
	u8					pmkid[64];
	mpi					cli_pri;
	ecp_point			cli_pub;
	u8					cli_pubkey[RTW_OWE_KEY_LEN];
	ecp_group			grp;
};

#endif	//__RTW_OWE_H_

