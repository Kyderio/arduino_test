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

#ifndef __HALHWOUTSRC_H__
#define __HALHWOUTSRC_H__

/*@--------------------------Define -------------------------------------------*/


/*@************************************************************
 * structure and define
 ************************************************************/

void odm_config_rf_with_tx_pwr_track_header_file(void);

int odm_config_rf_with_header_file(enum odm_rf_config_type config_type,
							   u8 e_rf_path);

int odm_config_bb_with_header_file(enum odm_bb_config_type config_type);


u32 odm_get_hw_img_version(void);

#endif /*@#ifndef	__HALHWOUTSRC_H__*/
