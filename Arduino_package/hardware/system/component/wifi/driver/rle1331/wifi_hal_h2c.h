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
#ifndef __WIFI_HAL_H2C_H__
#define __WIFI_HAL_H2C_H__

#define MAX_H2CCMD_LEN	8
#define MAX_C2HCMD_LEN	12
#define MAX_H2C_ENTRY	4
#define MAX_C2H_ENTRY	4

extern struct fw_rsvdpage_priv g_pagepriv;
extern struct fw_fifo_priv g_fwpriv;

//---------------------------------------------------------------------------------------------------------//
//----------------------------------    Structure Define     --------------------------------------------------//
//---------------------------------------------------------------------------------------------------------//
struct fw_fifo_priv {
	/* define of h2c fifo */
	u8 h2c_entry_num;
	u8 h2c_entry_size;	//unit: bytes
	u8 *h2c_buffer;		//start address of h2c entry, should be alignment
	/* define of c2h fifo */
	u8 c2h_entry_num;
	u8 c2h_entry_size;	//unit: bytes
	u8 *c2h_buffer;		//start address of c2h entry, should be alignment
};

struct fw_rsvdpage_priv {
	u8 *ps_poll;        //start address of pspoll pkt (tx descriptor)
	u8 *null;
	u8 *qosnull;
	u8 *bt_qosnull;
	u8 *csi;
	u8 *arp;
};

//---------------------------------------------------------------------------------------------------------//
//----------------------------------    Function Statement     --------------------------------------------------//
//---------------------------------------------------------------------------------------------------------//

void wifi_hal_h2c_init(void);
void wifi_hal_h2c_deinit(void);
#endif

