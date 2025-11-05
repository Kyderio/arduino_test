/******************************************************************************
 *
 * Copyright(c) 2007 - 2020  Realtek Corporation.
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
#ifndef __HALRF_INTERFACE_H__
#define __HALRF_INTERFACE_H__

#define CF_PHL_BB_CTRL_RX_CCA

/*@--------------------------[Define] ---------------------------------------*/
/*[IO Reg]*/
#define RF_OFST 0x10000
#define halrf_r32( addr) hal_read32((addr | RF_OFST))
#define halrf_r16( addr) hal_read16((addr | RF_OFST))
#define halrf_r8( addr) hal_read8((addr | RF_OFST))
#define halrf_w32( addr, val) hal_write32((addr | RF_OFST), val)
#define halrf_w16( addr, val) hal_write16((addr | RF_OFST), val)
#define halrf_w8( addr, val) hal_write8((addr | RF_OFST), val)

#define halrf_read_mem( addr, cnt, pmem) hal_read_mem(addr, cnt, pmem)

/*[TX]*/
#define halrf_tx_pause( band_idx, tx_pause, rson) rtw_hal_tx_pause(tx_pause, rson)
#define halrf_set_pmac_pattern( ppdu_type, case_id, phy_idx) rtw_hal_bb_set_plcp_pattern(ppdu_type, case_id, phy_idx)
#define halrf_set_pmac_plcp_tx( plcp, usr, phy_idx, sts) *sts = halbb_plcp_gen( (struct halbb_plcp_info *)plcp, (struct usr_plcp_gen_in *)usr, phy_idx)
#define halrf_set_pmac_packet_tx( enable, is_cck, cnt, period, time, phy_idx) rtw_hal_bb_set_pmac_packet_tx(enable, is_cck, cnt, period, time, false, phy_idx)
#define halrf_set_pmac_power( dbm, phy_idx) halbb_set_txpwr_dbm( dbm, phy_idx)
#define halrf_cfg_tx_path( path) halbb_ctrl_tx_path( path)
#define halrf_cfg_rx_path( path) halbb_ctrl_rx_path( path)
#define halrf_tx_mode_switch( phy_idx, mode) 	halbb_set_tmac_tx( phy_idx)
#define halrf_query_regulation_info( info) rtw_phl_query_regulation(info)
#define halrf_hal_bb_backup_info( phy_idx) halbb_backup_info( phy_idx)
#define halrf_hal_bb_restore_info( phy_idx) halbb_restore_info( phy_idx)

/*[Delay]*/
#define halrf_delay_ms(ms) rtos_time_delay_ms(ms)
#define halrf_delay_us(us) rtos_time_delay_us(us)

/*[Timer]*/
#define halrf_init_timer( timer, call_back_func, context, sz_id) _os_init_timer(timer, call_back_func, context, sz_id)
#define halrf_set_timer( timer, ms_delay) _os_set_timer(timer, ms_delay)
#define halrf_cancel_timer( timer) _os_cancel_timer(timer)
#define halrf_release_timer( timer) _os_release_timer(timer)

/*efuse*/
#define halrf_phy_efuse_get_info( addr, size, value) rtw_hal_mac_read_phy_efuse(addr, size, value)

/*Set power by rate, power limit, power */
#define halrf_bb_set_tx_pow_ref( phy_idx) halbb_set_tx_pow_ref( phy_idx)

/*BB related*/
#define halrf_bb_ctrl_rx_cca( cca_en, phy_idx) halbb_ctrl_rx_cca( cca_en, phy_idx)

/*@--------------------------[Enum]------------------------------------------*/


/*@--------------------------[Structure]-------------------------------------*/

/*@--------------------------[Prptotype]-------------------------------------*/

u8 halrf_btc_ntfy(enum halrf_rfk_process process);

u32 halrf_cal_bit_shift(u32 bit_mask);

//u32 halrf_get_sys_time(void);

void halrf_wreg(u32 addr, u32 bit_mask, u32 val);

u32 halrf_rreg(u32 addr, u32 bit_mask);

void halrf_wrf(u32 addr, u32 mask, u32 val);

u32 halrf_rrf(u32 addr, u32 mask);

void halrf_wrf_maskrf(u32 addr, u32 val);
void halrf_wreg_maskdword(u32 addr, u32 val);
u32 halrf_rreg_maskdword(u32 addr);

void halrf_wmac32(u32 addr, u32 val);
u32 halrf_rmac32(u32 addr);

void halrf_wrf_radioa(enum rf_path path, u32 addr, u32 mask, u32 val);

void halrf_fill_h2c_cmd(u16 cmdlen, u8 cmdid,
						u8 classid, u32 cmdtype, u32 *pval);
void halrf_delay_10us(u32 count);
#endif
