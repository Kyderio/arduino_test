/******************************************************************************
 *
 * Copyright(c) 2007 - 2012 Realtek Corporation. All rights reserved.
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
#ifndef _WIFI_INTF_HAL_TO_CORE_H_
#define _WIFI_INTF_HAL_TO_CORE_H_

#include <rtw_adapter.h>

extern const u32 tx_buf_addr_table[16];

/*-------------------------------------------------------------------------------
	Configurations/Capabilities
--------------------------------------------------------------------------------*/
void wifi_hal_read_adapterinfo(void);
u32 wifi_hal_11ax_limitation(void);

/*-------------------------------------------------------------------------------
	init/deinit
--------------------------------------------------------------------------------*/
int wifi_hal_init(void);
void wifi_hal_power_off(void);
int wifi_hal_deinit(void);
void wifi_hal_init_haldata(void);
void wifi_hal_free_haldata(void);
u32 wifi_hal_us_to_twt_early_unit(u32 twt_early_us);
void wifi_hal_check_efuse_info(void);

/*-------------------------------------------------------------------------------
	hal irq interface
--------------------------------------------------------------------------------*/
void wifi_hal_interrupt_enable(void);
void wifi_hal_interrupt_disable(void);
s32 wifi_hal_interrupt_handle(void);
void wifi_hal_tx_isr(u8 iface_type, int prio);

/*-------------------------------------------------------------------------------
	Dynamic settings.
--------------------------------------------------------------------------------*/
void wifi_hal_set_channel(u8 center_ch);
void wifi_hal_set_channel_bw(unsigned char channel, unsigned char channel_offset, unsigned short bwmode);
void wifi_hal_apmode_set(u8 enable);
void wifi_hal_basic_rate_set(u8 *val);
u8 wifi_hal_ps_wait_txcmd_idle(void);
void wifi_hal_ps_mac_sleep_by_macid(u8 macid_bitmap_lowbit, u8 macid_bitmap_highbit, u8 be_pause);
u64 wifi_hal_port0_get_cur_tbtt_time(void);
u64 wifi_hal_port1_get_cur_tbtt_time(void);
void wifi_hal_ps_port0_set_hw_overwrite_pwrbit1(u8 power_mode);
void wifi_hal_ps_mac_sleep_releaseall(void);
void wifi_hal_resvpage_null_xmit(u8 bPowerBit, u8 rty_lmt);
void wifi_hal_beacon_contention_area_set(u32 bcn_contention_area);

#ifdef CONFIG_WMMPS_STA
void wifi_hal_update_uapsd_tid(u8 uapsd_tid);
#endif

/*-------------------------------------------------------------------------------
	xmit
--------------------------------------------------------------------------------*/
void wifi_hal_tx_ring_init(struct xmit_priv *pxmitpriv, const u32 *tx_buf_addr_table);
void wifi_hal_tx_ring_free(struct xmit_priv	*pxmitpriv);
void wifi_hal_tx_ring_reset(void);
int wifi_hal_tx_ring_skb_enqueue(struct rtw_tx_ring	*ring, struct sk_buff *pkt);
void wifi_hal_tx_ring_skb_dequeue(struct rtw_tx_ring	*ring);
u32 wifi_hal_hwqueue_get(u8 qsel);
int wifi_hal_xmit(u8 iface_type, struct xmit_frame *pxmitframe);
int wifi_hal_mgnt_xmit(u8 iface_type, struct xmit_frame *pmgntframe);
void wifi_hal_pending_queue_free(struct hw_xmit *pending_top, struct sta_xmit_priv *psta_xmitpriv);
void wifi_hal_pending_q_enqueue(struct hw_xmit *pending_top, struct sta_xmit_priv *psta_xmitpriv, struct sk_buff *pkt, u32 hw_queue);
void wifi_hal_pending_q_resume(struct hw_xmit *pending_top);
int wifi_hal_txbd_set(u8 hw_queue,  struct sk_buff *skb);
/*-------------------------------------------------------------------------------
	recv
--------------------------------------------------------------------------------*/
int wifi_hal_rx_ring_init(u8 *rxring_addr);
void wifi_hal_rx_ring_free(void);
void wifi_hal_rx_ring_reset(void);
void wifi_recv_tasklet(void);
#ifdef RA_RX_ACK_RSSI
void wifi_hal_rx_ack(u8 enable);
#endif

/*-------------------------------------------------------------------------------
	bb related
--------------------------------------------------------------------------------*/
u32 wifi_hal_read_bb_reg(u32 RegAddr, u32 BitMask);
void wifi_hal_write_bb_reg(u32 addr, u32 mask, u32 val);

/*-------------------------------------------------------------------------------
	rf related
--------------------------------------------------------------------------------*/
u32 wifi_hal_read_rf_reg(u32 path, u32 addr, u32 mask);
void wifi_hal_write_rf_reg(u32 path, u32 addr, u32 mask, u32 val);
void wifi_hal_openrf(void);
void wifi_hal_closerf(void);

/*-------------------------------------------------------------------------------
	phy related
--------------------------------------------------------------------------------*/
void wifi_hal_phy_init_dm_priv(void);
void wifi_hal_phy_haldm_watchdog(void);
void wifi_hal_phy_stats_query(union rtw_phy_stats *phy_stats);

/*-------------------------------------------------------------------------------
	FW related
--------------------------------------------------------------------------------*/
void wifi_hal_bcn_info_to_fw(u8 *pframe, u32 pkt_len, u8 is_cck_rate, u8 is_clear);

/*-------------------------------------------------------------------------------
	hal layer scan/connect
--------------------------------------------------------------------------------*/
void wifi_hal_sitesurvey_set(u8 iface_type, u8 survey_state);
void wifi_hal_disconnect_set(void);

/*-------------------------------------------------------------------------------
	hal layer power save.
--------------------------------------------------------------------------------*/
u8 wifi_hal_fwlps_rf_on(void);
void wifi_hal_tsf_correct(u8 iface_type);
#ifdef CONFIG_TWT
int wifi_hal_h2c_twt_param(struct twt_para_t twt_para, u8 enable);
#endif
int wifi_hal_wake_pll_rdy_in_ps_state(u8 need);
/*-------------------------------------------------------------------------------
	debug
--------------------------------------------------------------------------------*/
void wifi_hal_phydm_dbg(char *cmd_ptr, u32 extra_arg);
void wifi_hal_dbg_no_beacon(u8 param);

/*-------------------------------------------------------------------------------
	h2c/c2h command
--------------------------------------------------------------------------------*/
s32 wifi_hal_h2c_fill_cmd(u32 CmdLen, u8 *pCmdBuffer);
void wifi_hal_h2c_set_media_status(u8 mstatus, u8 macid);
void wifi_hal_h2c_set_pwr_mode(u8 psmode);
void wifi_hal_h2c_joinbss(u8 mstatus);
void wifi_hal_rsvpage_pkt_download(u8 iface_type, u8 mstatus);

/*-------------------------------------------------------------------------------
	hci interface
--------------------------------------------------------------------------------*/
extern void wifi_hal_hci_intf_init(void);
extern void wifi_hal_hci_intf_deinit(void);
extern void wifi_hal_interrupt_request_irq(void);
extern void wifi_hal_interrupt_free_irq(void);
extern void wifi_hal_interrupt_twt_cmd(u8 idx, u8 early_en, u8 b_enabe);
void wifi_hal_hci_intf_stop(void);

/*-------------------------------------------------------------------------------
	Define Alias: update/set/check/get common information in hal
--------------------------------------------------------------------------------*/
#define wifi_hal_update_slottime(updateCap, preamble_mode, slotTime, cur_channel) ROM_WIFI_UPDATE_Slottime(updateCap, preamble_mode, slotTime, cur_channel)
#define wifi_hal_set_TSF_sync()				ROM_WIFI_TSF_Sync()
#define wifi_hal_set_tsf_sync_p1_from_p0()			ROM_WIFI_TSF_Sync_P1_From_P0()
#define wifi_hal_acm_ctrl_set(acm_msk)			ROM_WIFI_ACM_CTRL(acm_msk)
#define wifi_hal_bcn_interval_set(iface_type, interval)	ROM_WIFI_BCN_Interval(iface_type,interval)
#define wifi_hal_ac_param_set(ACparam, pBE_param)	ROM_WIFI_Set_AC_Param(ACparam, pBE_param)
#define wifi_hal_bcn_func_set(iface_type, enable)	ROM_WIFI_BCN_FUNC(iface_type, enable);
#define wifi_hal_macaddr_set(iface_type, macaddr)	ROM_WIFI_INIT_MACADDR_SET(iface_type, macaddr);
#define wifi_hal_bssid_set(iface_type, bssid)		ROM_WIFI_BSSID_SET(iface_type, bssid);
#define wifi_hal_fifo_cleanup(bkeepfwalive)		ROM_WIFI_FIFO_CLEARN_UP(bkeepfwalive)
#define rtw_hal_get_tsftr_by_port(port)		ROM_WIFI_TSF_GetByPort(port)

/*-------------------------------------------------------------------------------
	Define Alias: for 80211 AX
--------------------------------------------------------------------------------*/
#ifdef CONFIG_80211AX_HE
#define wifi_hal_bb_bss_color_set(bss_color, phy_idx)	halbb_set_bss_color(bss_color, phy_idx)
#define wifi_hal_mac_bss_color_set(iface_type, bsscolor)		ROM_WIFI_AX_BSS_COLOR_SET(iface_type, bsscolor);
#define wiif_hal_set_mu_edca_param(val, first)			ROM_WIFI_AX_MUEDCA_Para(val, first)
#define wifi_hal_set_spatial_reuse(val, enable, first) \
								ROM_WIFI_AX_SpecialReuse_Cfg(val, enable, first)
#define wifi_hal_set_TXOP_thres(rts_th, enable)	ROM_WIFI_Set_TXOP_Thres(rts_th, enable)
#else
#define wifi_hal_bb_bss_color_set(bss_color, phy_idx)
#define wifi_hal_mac_bss_color_set(iface_type, bsscolor)
#define wifi_hal_set_spatial_reuse(val, enable, first)
#define wifi_hal_set_TXOP_thres(rts_th, enable)
#endif

/*-------------------------------------------------------------------------------
	Define Alias: update information for bb and phy.
--------------------------------------------------------------------------------*/
void wifi_hal_bb_sta_add(u8 iface_type, struct sta_mlme_priv *psta_mlme_priv);
void wifi_hal_bb_sta_del(u8 iface_type, struct sta_mlme_priv *psta_mlme_priv);
#if (PHYDM_VERSION == 2)
#define wifi_hal_phy_deinit_dm_priv()
#define wifi_hal_set_TXOP_thres(rts_th, enable)
#endif

/*-------------------------------------------------------------------------------
	Define Alias: antenna diversity.
--------------------------------------------------------------------------------*/
#define wifi_hal_antdiv_before_linked(padapter)	FALSE
#define wifi_hal_antdiv_rssi_compared(padapter, dst, src)

/*-------------------------------------------------------------------------------
	Define Alias: wifi packet management.
--------------------------------------------------------------------------------*/
#define wifi_hal_max_agg_num_set(num)			ROM_WIFI_SET_MAX_AGG_NUM(num)
#define wifi_hal_ctrl_pkt_rpt_set(enable)		ROM_WIFI_CTRL_PKT_RPT(enable)
#define wifi_hal_icv_check_set(security_alg)		ROM_WIFI_ICV_CHECK_CFG(security_alg)
#define wifi_hal_txpause_set(pause, val)		ROM_WIFI_TX_PAUSE_SET(pause,val)
#define wifi_hal_limit_mode_set(enable)			ROM_WIFI_LIMIT_MODE_SET(enable)
#define wifi_hal_get_txbuf_pkt_num()			ROM_WIFI_GET_TXBUF_PKT_NUM()
#define wifi_hal_cca_set(enable)			ROM_WIFI_SET_CCA(enable)
#define wifi_hal_edcca_set(enable)			ROM_WIFI_SET_EDCCA(enable)
#define wifi_hal_nav_check_set(nav_update_th, ignore_tx_nav)			ROM_WIFI_SET_NAV_CHK(nav_update_th, ignore_tx_nav)
#define wifi_hal_lifetime_set(lifetime_bebk, lifetime_vivo)			ROM_WIFI_SET_LIFETIME(lifetime_bebk, lifetime_vivo)

/*-------------------------------------------------------------------------------
	Define Alias: wifi secure
--------------------------------------------------------------------------------*/
#define wifi_hal_sec_cfg_set(psecuritypriv, cfg)		ROM_WIFI_SEC_CFG(cfg, psecuritypriv->b_sw_encrypt);
#define write_cam_spp_amsdu_valid(entry, value)	ROM_WIFI_CAM_WriteSppAmsduValid(entry, value)
#define clear_cam_entry(entry)			ROM_WIFI_CAM_Entry_Clear(entry)
#define flush_all_cam_entry(is_STA, buddy_linked)	ROM_WIFI_CAM_FLUSH_ALL(is_STA, buddy_linked)

#endif //_WIFI_INTF_HAL_TO_CORE_H_

