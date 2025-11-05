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

#ifndef _RTW_HAL_ODM_H_
#define _RTW_HAL_ODM_H_

#include <rtw_adapter.h>
#include "wifi_hal.h"

#define	DYNAMIC_FUNC_DISABLE		(0x0)
#define DYNAMIC_ALL_FUNC_ENABLE		0xFFFFFFF

void rtw_odm_acquirespinlock(enum rt_spinlock_type type);
void rtw_odm_releasespinlock(enum rt_spinlock_type type);

enum _HAL_PHYDM_OPS {
	HAL_PHYDM_DIS_ALL_FUNC,
	HAL_PHYDM_FUNC_SET,
	HAL_PHYDM_FUNC_CLR,
	HAL_PHYDM_ABILITY_BK,
	HAL_PHYDM_ABILITY_RESTORE,
	HAL_PHYDM_ABILITY_SET,
	HAL_PHYDM_ABILITY_GET,
};

u32 rtw_phydm_ability_ops(enum _HAL_PHYDM_OPS ops, u32 ability);

#define rtw_phydm_func_disable_all() \
		rtw_phydm_ability_ops(HAL_PHYDM_DIS_ALL_FUNC, 0)

#define rtw_phydm_func_for_offchannel() \
		rtw_phydm_ability_ops(HAL_PHYDM_DIS_ALL_FUNC, 0); \

#define rtw_phydm_func_clr(ability)	\
		rtw_phydm_ability_ops(HAL_PHYDM_FUNC_CLR, ability)

#define rtw_phydm_func_set(ability)	\
		rtw_phydm_ability_ops(HAL_PHYDM_FUNC_SET, ability)

#define rtw_phydm_ability_backup()	\
		rtw_phydm_ability_ops(HAL_PHYDM_ABILITY_BK, 0)

#define rtw_phydm_ability_restore()	\
		rtw_phydm_ability_ops(HAL_PHYDM_ABILITY_RESTORE, 0)

u32 rtw_phydm_ability_get(void);

#endif	//_RTW_HAL_ODM_H_

