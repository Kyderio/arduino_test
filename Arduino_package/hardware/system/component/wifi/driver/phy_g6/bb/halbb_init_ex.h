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
#ifdef _RTW_ADAPTER_DEFINED_H_
#ifndef _HALBB_INIT_EX_H_
#define _HALBB_INIT_EX_H_

/*@--------------------------[Define] ---------------------------------------*/

/*@--------------------------[Enum]------------------------------------------*/

/*@--------------------------[Structure]-------------------------------------*/

/*@--------------------------[Prptotype]-------------------------------------*/
void halbb_dm_deinit(void);
void halbb_dm_init_phy1(void);
void halbb_dm_init(void);

void halbb_buffer_deinit(void);
int halbb_buffer_init(void);

void halbb_get_efuse_init(void);

void halbb_ic_hw_setting_init(void);

u32 halbb_buffer_size_get(void);

#endif
#endif
