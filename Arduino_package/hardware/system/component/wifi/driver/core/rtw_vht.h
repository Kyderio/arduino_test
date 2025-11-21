/******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation.
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
#ifndef _RTW_VHT_H_
#define _RTW_VHT_H_

#define BW_MODE_2G(bw_mode) ((bw_mode) & 0x0F)
#define BW_MODE_5G(bw_mode) ((bw_mode) >> 4)
#define REGSTY_BW_2G(bw_mode) BW_MODE_2G(bw_mode)
#define REGSTY_BW_5G(bw_mode) BW_MODE_5G(bw_mode)
#define REGSTY_IS_BW_5G_SUPPORT(bw_mode, bw) (REGSTY_BW_5G((bw_mode)) >= (bw))

u8 wifi_rom_vht_get_highest_rate(u8 *pvht_mcs_map);
u64 wifi_rom_vht_mcsmap_to_bitmap(u8 *mcs_map, u8 nss);
u8 wifi_rom_vht_mcsmap_to_nss(u8 *pvht_mcs_map);
void wifi_rom_vht_nss_to_mcsmap(u8 nss, u8 *target_mcs_map, u8 *cur_mcs_map);

#endif /* _RTW_VHT_H_ */
