/******************************************************************************
 *
 * Copyright(c) 2016 - 2017 Realtek Corporation.
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
#ifndef RTW_COEX_ACTION_H
#define RTW_COEX_ACTION_H

void rtk_coex_action_wl_init(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_wl_rfk(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_wl_update_afh_info(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_bt_off(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_wl_ips(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_wl_rf_off(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_wl_only(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_wl_scan(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_wl_no_link(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_wl_link_2g(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_wl_link_5g(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_wl_link_2g_scc(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_wl_link_2g_mcc(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_wl_link_5g_scc(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_wl_link_5g_mcc(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_wl_link_25g_mcc(struct rtk_coex_t *p_rtk_coex);

void rtk_coex_action_free_run(struct rtk_coex_t *p_rtk_coex);

void rtk_coex_action_dual_ant(struct rtk_coex_t *p_rtk_coex);

void rtk_coex_action_dual_chip(struct rtk_coex_t *p_rtk_coex);

void rtk_coex_action_single_ant(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_single_ant_scc(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_single_ant_mcc(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_single_ant_wl_scan(struct rtk_coex_t *p_rtk_coex);


// for EXT CHIP
void rtk_coex_action_ext_chip_single_ant(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_ext_chip_single_ant_scc(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_ext_chip_wl_no_link(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_ext_chip_wl_link_2g(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_ext_chip_wl_link_2g_scc(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_ext_chip_single_ant_wl_scan(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_ext_chip_wl_rf_off(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_ext_chip_wl_rfk(struct rtk_coex_t *p_rtk_coex);
void rtk_coex_action_ext_chip_wl_ips(struct rtk_coex_t *p_rtk_coex);

#endif


