/******************************************************************************
 *
 * Copyright(c) 2019 Realtek Corporation.
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
 *****************************************************************************/
#ifndef _HALBB_INIT_H_
#define _HALBB_INIT_H_
#include "wifi_intf_os_to_g6.h"


/*@--------------------------[Define] ---------------------------------------*/

/*@--------------------------[Enum]------------------------------------------*/

/*@--------------------------[Structure]-------------------------------------*/

/*@--------------------------[Prptotype]-------------------------------------*/
void halbb_cmn_info_self_init_per_phy(void);
void halbb_timer_ctrl(enum bb_timer_cfg_t timer_state);
void halbb_timer_init(void);
void halbb_dm_init_per_phy(enum phl_phy_idx phy_idx);
void halbb_hw_init(void);
#endif
