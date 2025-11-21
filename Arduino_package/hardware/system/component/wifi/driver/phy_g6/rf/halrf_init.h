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
#ifndef _HALRF_INIT_H_
#define _HALRF_INIT_H_
#include "wifi_intf_os_to_g6.h"


/*@--------------------------[Define] ---------------------------------------*/

/*@--------------------------[Enum]------------------------------------------*/

/*@--------------------------[Structure]-------------------------------------*/

/*@--------------------------[Prptotype]-------------------------------------*/
struct rf_info;
extern struct rf_info g6_rf;
//void halrf_cmn_info_self_init(void);
void halrf_rfability_init_mp(void);
void halrf_rfability_init(void);
void halrf_set_rfability(void);
u32 halrf_struct_size_get(void);
#endif
