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

#ifndef __HAL_H__
#define __HAL_H__

#include "rtw_adapter.h"

#include "wifi_hal_reg.h"
#include "wififw_h2c_c2h_format.h"
#ifdef CONFIG_CSI
#include "hal_csi.h"
#endif
#ifdef CONFIG_RADAR
#include "hal_radar.h"
#endif

#include "hal_ra.h"

#include "hal_edcca.h"

#if (PHYDM_VERSION == 3)
#include "hal_dig_g6.h"
#else
#include "hal_dig_phydm.h"
#include "wifi_hal_dig_phydm.h"
#endif

#if (PHYDM_VERSION == 3)
#include "hal_antdiv_g6.h"
#else
#include "hal_antdiv_phydm.h"
#include "wifi_hal_antdiv.h"
#endif

#ifdef CONFIG_NAN
#include "wifi_hal_nan.h"
#include "hal_nan.h"
#endif

#include "hal_phycfg.h"
#include "hal_h2c.h"

#include "wifi_hal_def.h"
#include <phl.h>

#ifdef CONFIG_80211AX_HE
#include "halbb_export_fun.h"
#include "halrf_api.h"
#include "halrf_export_fun.h"
#endif
#include "wifi_intf_hal_to_core.h"
#include "wifi_intf_hal_to_phydm.h"

#include "wifi_hal_eeprom.h"
#include "hal_dm.h"
#include "wifi_hal_dm.h"
#include "wifi_hal_recv.h"
#include "hal_recv.h"
#include "wifi_hal_xmit.h"
#include "wifi_hal_io.h"
#include "wifi_hal_promisc.h"

#include "rom_wifi_hal.h"

#include <rtw_mcc.h>
#include <wifi_hal_interrupt.h>
#include <hal_interrupt.h>

#if defined(CONFIG_BT_COEXIST)
#include "rtw_coex_api.h"
#endif
#include "wifi_hal_txpower.h"
#include "hal_debug.h"
#include "hal_twt_timer.h"

#include "hal_speaker.h"
/************************** SOME DEFINES ABOUT KEYCAM ****************************/
#define KEY_MAX_NUM			32

#define STA_PTK_TRX_KEYCAM_ID		4
#define AP_PTK_TRX_KEYCAM_ID_OFFSET	(STA_PTK_TRX_KEYCAM_ID - 1)
#define AP_GTK_TX_KEYCAM_ID		(KEY_MAX_NUM - 1)
#define NAN_GTK_TX_KEYCAM_ID		(KEY_MAX_NUM - 2)

/**************************** DEFINES ABOUT SECCFG *******************************/
#define SECCFG_8021X		(BIT_RXDEC | BIT_TXENC | BIT_RXUHUSEDK | BIT_TXBCUSEDK)	//0x4E
#define SECCFG_8021X_GCMP_256		(BIT_TXENC | BIT_RXUHUSEDK | BIT_TXBCUSEDK)	//0x46, disable RXDEC becasue of mgnt hw enc/dec bug
#define SECCFG_NON_8021X	(BIT_RXDEC | BIT_TXENC | BIT_TXBCUSEDK | BIT_RXUHUSEDK | BIT_TXUHUSEDK)	//0x4F
#ifdef CONFIG_NAN
#define SECCFG_NAN		(BIT_RXDEC | BIT_TXENC)		//0x0C
#endif

#define MAC_TXPAUSE_ALL                       0xFF
#define MAC_TXPAUSE_KEEP_MGTQ                 (0xFF & ~((BIT_MAC_STOPMGQ | BIT_STOP_CPUMGQ) >> 16))
#define MAC_TXPAUSE_BCNQ                      (BIT_MAC_STOPBCNQ >> 16)
#define MAC_TXPAUSE_MGTQ                      (BIT_MAC_STOPMGQ >> 16)
#define MAC_TXPAUSE_ACQ                       0xF

int wifi_hal_init(void);
int rtw_config_map_read(u16 addr, u16 cnts, u8 *data, u8 is_phycial);
int rtw_config_map_write(u16 addr, u16 cnts, u8 *data, u8 is_phycial);
u8 wifi_hal_switch_chnl_and_set_bw(void);

void wifi_hal_suspend_lxbus_reg_restore(u8 store);
void wifi_hal_suspend_release_rx_dma(void);
u32 wifi_hal_suspend_check_remain_pkt(void);
int wifi_hal_suspend_pause_rx_dma(void);
u8 wifi_hal_suspend_get_rxdma_release_state(void);
u8 wifi_hal_suspend_check_wow_ctrl(u8 chk_type);

void wifi_hal_suspend_get_current_ip_address(u8 *pcurrentip, u8 *gateway);
void wifi_hal_suspend_get_sec_iv(u8 *pcur_dot11txpn, u8 *StaAddr);
void wifi_hal_suspend_set_sec_pn(void);

//Hal Debug
int wifi_hal_iwpriv_command(unsigned char wlan_idx, char *cmd, int show_msg);
u32 wifi_hal_dma_interrupt(void *data);

#define hal_chk_bw_cap(cap)		({g_hal_spec.bw_cap & cap;})
#define hal_is_bw_support(bw) 	({g_hal_spec.bw_cap & ch_width_to_bw_cap(bw);})
#define hal_largest_bw(in_bw)	({												\
											u8 bw = in_bw;							\
											for (; bw > CHANNEL_WIDTH_20; bw--)		\
												if (hal_is_bw_support(bw))	\
													break;								\
																						\
											if (!hal_is_bw_support(bw)) 		\
												rtw_warn_on(1);							\
																						\
											bw;										\
										})

#define wifi_hal_hw_rate_to_m_rate(rate) ROM_WIFI_HwRateToMRate(rate)
#define HwRateTo2MRate(rate) ROM_WIFI_HwRateToMRate(rate)
#define wifi_rom_write_cam(entry, ctrl, mac, key, macid)	ROM_WIFI_CAM_WRITE(entry, ctrl, mac, key)

void HalSetBrateCfg(u8 *mBratesOS, u16 *pBrateCfg);

void wifi_hal_connect_hw_info_set(struct sta_mlme_priv *psta_mlmepriv, bool is_connect);

void wifi_hal_interrupt_init(void);

/* For IPS PG Mode. */
void wifi_hal_leave_ips_pg(void);
void wifi_hal_enter_ips_pg(void);
int wifi_hal_check_trx_status(void);

/*-------------------------------------------------------------------------------
	common function in hal_xmit.c and wifi_hal_xmit.c
--------------------------------------------------------------------------------*/
u8 wifi_hal_polling_tx_done(u8 func_id, u8 seq_num, u8 polling_time);
#ifdef TX_SHORTCUT
int wifi_hal_xmitframe_dump_sc(u8 iface_type, struct sk_buff *pkt, struct sta_mlme_priv *psta_mlmepriv, int idx, u8 UserPriority);
#endif
void wifi_hal_txdesc_setrate(u8 iface_type, struct txdesc_priv *ptxdesc);
void wifi_hal_txbuf_check(void);
u8 wifi_hal_txbd_enough_check(struct xmit_priv	*pxmitpriv, int prio);
u8 wifi_hal_txbd_enough_check_all(struct xmit_priv	*pxmitpriv);
int wifi_hal_xmitframe_coalesce(u8 iface_type, struct sk_buff *pkt, struct xmit_frame *pxmitframe, u8 force_cts2self);
int wifi_hal_raw_xmitframe_coalesce(u8 iface_type, struct xmit_frame *pxmitframe);
void wifi_hal_txdesc_fill(struct xmit_frame *pxmitframe, u8 *pmem);
u32 wifi_hal_hwqueue_get(u8 qsel);
int wifi_hal_xmitframe_dump(u8 iface_type, struct xmit_frame *pxmitframe, u8 ampdu_tx_en, u8 tx_shortcut_enable);
void rtw_mgnt_80211w_sw_encrypt(u8 iface_type, struct xmit_frame *pmgntframe, u8 key_type_11w);
int wifi_hal_xmitframe_dump_sc_filldesc(u8 iface_type,
										struct sk_buff *pkt,
										struct sta_mlme_priv *psta_mlmepriv,
										int idx,
										u8 UserPriority,
										u8 agg_en);
u16 wifi_hal_txrate_get(u8 macid);
/*-------------------------------------------------------------------------------
	common function in wifi_hal.h
--------------------------------------------------------------------------------*/
void wifi_hal_wlan_int_enable(u8 irq_state);
u8 wifi_hal_wlan_int_disable(void);
u32 wifi_hal_suspend_start(u32 expected_idle_time, void *param);
u32 wifi_hal_resume_start(u32 expected_idle_time, void *param);
u32 APcore_status_on(void);
void wifi_hal_wlan_timer_process(void);
#if (PHYDM_VERSION != 2)
void wifi_hal_phy_deinit_dm_priv(void);
#endif
void wifi_hal_phy_dm_cmd(char *input, char *output, u32 out_len);

#endif
