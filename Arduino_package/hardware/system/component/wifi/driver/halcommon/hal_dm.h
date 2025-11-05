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
#ifndef _HAL_DM_H_
#define _HAL_DM_H_

/*@--------------------------[Define] ---------------------------------------*/

/*@--------------------------[Enum]------------------------------------------*/
/*@--------------------------[Structure]-------------------------------------*/

/*@--------------------------[Prptotype]-------------------------------------*/
void rtw_hal_turbo_edca(void);
void wifi_hal_phy_stats_query(union rtw_phy_stats *phy_stats);
void wifi_hal_phy_init_haldm(void);
void wifi_hal_phy_deinit_haldm(void);
void wifi_hal_phy_haldm_watchdog_byic(void);
void wifi_hal_phy_haldm_watchdog(void);


#endif /*_HAL_DM_H_*/
