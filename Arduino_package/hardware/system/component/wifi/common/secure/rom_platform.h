/**
 * \file platform.h
 *
 * \brief This file contains the definitions and functions of the
 *        Mbed TLS platform abstraction layer.
 *
 *        The platform abstraction layer removes the need for the library
 *        to directly link to standard C library functions or operating
 *        system services, making the library easier to port and embed.
 *        Application developers and users of the library can provide their own
 *        implementations of these functions, or implementations specific to
 *        their platform, which can be statically linked to the library or
 *        dynamically configured at runtime.
 */
/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 *
 *  This file is provided under the Apache License 2.0, or the
 *  GNU General Public License v2.0 or later.
 *
 *  **********
 *  Apache License 2.0:
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  **********
 *
 *  **********
 *  GNU General Public License v2.0 or later:
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *  **********
 */
#ifndef ROM_PLATFORM_H
#define ROM_PLATFORM_H

#include "wifi_intf_ram_to_rom.h"
#include "rom_hal_rom_to_flash.h"
#ifdef __cplusplus
extern "C" {
#endif

/* Internal macros meant to be called only from within the library. */
#define INTERNAL_VALIDATE_RET( cond, ret )  do { } while( 0 )
#define INTERNAL_VALIDATE( cond )           do { } while( 0 )

void wifi_rom_platform_zeroize(void *buf, size_t len);

/*
 * The function pointers for calloc and free.
 */
#define wifi_rom_mfree(p)				p_wifi_rom_func_map->mfree(p)
#define wifi_rom_calloc(n, sz)			p_wifi_rom_func_map->zmalloc(n, sz)
#define wifi_rom_zmalloc(n)			p_wifi_rom_func_map->zmalloc(n, 1)
#define wifi_rom_rand				p_wifi_rom_func_map->random

#define wifi_rom_enter_critical      p_wifi_rom2flash->rtw_rtos_critical_enter_t
#define wifi_rom_exit_critical      p_wifi_rom2flash->rtw_rtos_critical_exit_t
#define wifi_rom_mutex_give         p_wifi_rom2flash->rtw_rtos_mutex_give_t
#define wifi_rom_mutex_take         p_wifi_rom2flash->rtw_rtos_mutex_take_t
#define	wifi_rom_rtos_sema_give     p_wifi_rom2flash->rtos_sema_give
#define	wifi_rom_rtos_sema_take     p_wifi_rom2flash->rtos_sema_take

#define wifi_rom_mutex_delete_static    p_wifi_rom2flash->rtos_mutex_delete_static_t
#define wifi_rom_mutex_create_static    p_wifi_rom2flash->rtos_mutex_create_static_t
#define wifi_rom_delayms            p_wifi_rom2flash->rtos_time_delay_ms_t
#define wifi_rom_rtos_time_get_current_system_time_ms	p_wifi_rom2flash->rtos_time_get_current_system_time_ms

#define wifi_rom_dev_kfree_skb_any  p_wifi_rom2flash->rtw_dev_kfree_skb_any_t
#define wifi_rom_dev_alloc_skb      p_wifi_rom2flash->rtw_dev_alloc_skb_t

#define wifi_rom_rtw_acquire_wakelock     p_wifi_rom2flash->rtw_acquire_wakelock_t
#define wifi_rom_rtw_release_wakelock     p_wifi_rom2flash->rtw_release_wakelock_t

#define wifi_rom_wifi_hal_normal_rx_process  p_wifi_rom2flash->wifi_hal_normal_rx_process_t

/* adapter */
#define wifi_rom_rtw_get_adapter_mac_addr    p_wifi_rom2flash->rtw_get_adapter_mac_addr
#define wifi_rom_rtw_get_adapter_bssid       p_wifi_rom2flash->rtw_get_adapter_bssid
#define wifi_rom_rtw_get_adapter_mlmeinfo    p_wifi_rom2flash->rtw_get_adapter_mlmeinfo
#define wifi_rom_rtw_get_adapter_bcninfo     p_wifi_rom2flash->rtw_get_adapter_bcninfo
#define wifi_rom_wifi_get_country_code_info  p_wifi_rom2flash->wifi_get_country_code_info
#define wifi_rom_rtw_get_adapter_stopped     p_wifi_rom2flash->rtw_get_adapter_stopped
#define wifi_rom_rtw_rtw_state_check_ap_on   p_wifi_rom2flash->rtw_state_check_ap_on
#define wifi_rom_rtw_get_adapter_dot11dpriv  p_wifi_rom2flash->rtw_get_adapter_dot11dpriv
#define wifi_rom_rtw_get_adapter_addba_req   p_wifi_rom2flash->rtw_get_adapter_addba_req
#define wifi_rom_rtw_get_pendingqueue        p_wifi_rom2flash->rtw_get_pendingqueue
#define wifi_rom_rtw_reset_securitypriv      p_wifi_rom2flash->rtw_reset_securitypriv

#define wifi_rom_rtw_init_timer               p_wifi_rom2flash->rtw_init_timer_t
#define wifi_rom_rtw_set_timer                p_wifi_rom2flash->rtw_set_timer_t
#define wifi_rom_rtw_del_timer                p_wifi_rom2flash->rtw_del_timer_t
#define wifi_rom_rtw_cancel_timer             p_wifi_rom2flash->rtw_cancel_timer_t
#define wifi_rom_pmu_set_sysactive_time       p_wifi_rom2flash->pmu_set_sysactive_time_t
#define wifi_rom_rtw_wakelock_timeout         p_wifi_rom2flash->rtw_wakelock_timeout

#define wifi_rom_wifi_if_netif_rx             p_wifi_rom2flash->wifi_if_netif_rx_t
#define wifi_rom_rtw_start_clnt_assoc         p_wifi_rom2flash->rtw_start_clnt_assoc
#define wifi_rom_rtw_start_clnt_auth          p_wifi_rom2flash->rtw_start_clnt_auth
#define wifi_rom_rtw_leavebss_start           p_wifi_rom2flash->rtw_leavebss_start

#define wifi_rom_rtw_network_zmalloc          p_wifi_rom2flash->rtw_network_zmalloc
#define wifi_rom_rtw_network_copy             p_wifi_rom2flash->rtw_network_copy
#define wifi_rom_rtw_11d_update_regulatory_from_country     p_wifi_rom2flash->rtw_11d_update_regulatory_from_country
#define wifi_rom_rtw_ips_wakeup               p_wifi_rom2flash->rtw_ips_wakeup


/* psta */
#define	wifi_rom_rtw_alloc_stainfo              p_wifi_rom2flash->rtw_alloc_stainfo
#define	wifi_rom_rtw_free_stainfo               p_wifi_rom2flash->rtw_free_stainfo
#define	wifi_rom_rtw_sta_get_mlmepriv           p_wifi_rom2flash->rtw_sta_get_mlmepriv
#define	wifi_rom_rtw_sta_get_secpriv            p_wifi_rom2flash->rtw_sta_get_secpriv
#define	wifi_rom_rtw_sta_get_xmitpriv           p_wifi_rom2flash->rtw_sta_get_xmitpriv
#define	wifi_rom_rtw_sta_get_recvpriv           p_wifi_rom2flash->rtw_sta_get_recvpriv
#define	wifi_rom_rtw_sta_get_htpriv             p_wifi_rom2flash->rtw_sta_get_htpriv
#define	wifi_rom_rtw_sta_get_scpriv             p_wifi_rom2flash->rtw_sta_get_scpriv
#define	wifi_rom_rtw_free_stainfo_enqueue_cmd   p_wifi_rom2flash->rtw_free_stainfo_enqueue_cmd
#define	wifi_rom_rtw_sta_del_event              p_wifi_rom2flash->rtw_sta_del_event
#define	wifi_rom_rtw_ap_polling_sta_hdl         p_wifi_rom2flash->rtw_ap_polling_sta_hdl
#define	wifi_rom_rtw_macid_max_num              p_wifi_rom2flash->rtw_macid_max_num

/* join & scan */
#define	wifi_rom_rtw_joinbss_cmd                p_wifi_rom2flash->rtw_joinbss_cmd
#define	wifi_rom_rtw_joinbss_result             p_wifi_rom2flash->rtw_joinbss_result
#define	wifi_rom_rtw_disassoc_cmd               p_wifi_rom2flash->rtw_disassoc_cmd
#define	wifi_rom_rtw_scan_start_cmd             p_wifi_rom2flash->rtw_scan_start_cmd
#define	wifi_rom_rtw_xmit_mgntframe             p_wifi_rom2flash->rtw_xmit_mgntframe
#define	wifi_rom_wifi_hal_mgnt_xmit             p_wifi_rom2flash->wifi_hal_mgnt_xmit
#define	wifi_rom_wifi_hal_xmit              	p_wifi_rom2flash->wifi_hal_xmit
#define	wifi_rom_wifi_hal_txdesc_fill       	p_wifi_rom2flash->wifi_hal_txdesc_fill
#define	wifi_rom_rtw_mgmt_xmitframe_coalesce	p_wifi_rom2flash->rtw_mgmt_xmitframe_coalesce
#define	wifi_rom_rtw_recv_validate_mgnt_frame   p_wifi_rom2flash->rtw_recv_validate_mgnt_frame
#define wifi_rom_rtw_enqueue_cmd                p_wifi_rom2flash->rtw_enqueue_cmd
#define wifi_rom_rtos_timer_is_timer_active     p_wifi_rom2flash->rtos_timer_is_timer_active
#define wifi_rom_wifi_hal_xmitframe_dump_sc     p_wifi_rom2flash->wifi_hal_xmitframe_dump_sc
#define wifi_rom_rtw_setkey_cmd_hdl             p_wifi_rom2flash->rtw_setkey_cmd_hdl
#define wifi_rom_btc_sec_key_exchange_notify    p_wifi_rom2flash->rtw_hal_btc_sec_key_exchange_notify
#define wifi_rom_rtw_ft_check_en				p_wifi_rom2flash->rtw_ft_check_en

#ifdef CONFIG_80211AX_HE
#define wifi_rom_HE_operation_update_asoc_cap   p_wifi_rom2flash->HE_operation_update_asoc_cap
#define wifi_rom_halbb_set_bss_color            p_wifi_rom2flash->halbb_set_bss_color
#endif

#define wifi_rom_hal_bb_sta_add(iface_type, psta_mlmepriv)     do {\
        if (p_wifi_rom2flash->wifi_hal_bb_sta_add) {\
            p_wifi_rom2flash->wifi_hal_bb_sta_add(iface_type, psta_mlmepriv);\
        } \
    } while(0)
#define wifi_rom_hal_bb_sta_del(iface_type, psta_mlmepriv)     do {\
        if (p_wifi_rom2flash->wifi_hal_bb_sta_del) {\
            p_wifi_rom2flash->wifi_hal_bb_sta_del(iface_type, psta_mlmepriv);\
        } \
    } while(0)

#define wifi_rom_hal_update_uapsd_tid(uapsd_tid)     do {\
        if (p_wifi_rom2flash->wifi_hal_update_uapsd_tid) {\
            p_wifi_rom2flash->wifi_hal_update_uapsd_tid(uapsd_tid);\
        } \
    } while(0)

#define wifi_rom_hal_ra_register(iface_type, psta_mlmepriv)     do {\
        if (p_wifi_rom2flash->wifi_hal_ra_register) {\
            p_wifi_rom2flash->wifi_hal_ra_register(iface_type, psta_mlmepriv);\
        } \
    } while(0)
#define wifi_rom_hal_txdesc_setrate                 p_wifi_rom2flash->wifi_hal_txdesc_setrate
#define wifi_rom_hal_set_channel_bw                 p_wifi_rom2flash->wifi_hal_set_channel_bw

#define wifi_rom_wifi_hal_ra_update_support_rate(psta_mlme_priv)    do {\
        if (p_wifi_rom2flash->wifi_hal_ra_update_support_rate) {\
            p_wifi_rom2flash->wifi_hal_ra_update_support_rate(psta_mlme_priv);\
        } \
    } while(0)

#define wifi_rom_wifi_indication                    p_wifi_rom2flash->wifi_indication
#define wifi_rom_rtw_is_adapter_up                  p_wifi_rom2flash->rtw_is_adapter_up

#define wifi_rom_singlethread_wakeup_sema           p_wifi_rom2flash->singlethread_wakeup_sema

/* nan */
#define wifi_rom_rtw_is_nan_frame                       p_wifi_rom2flash->rtw_is_nan_frame
#define wifi_rom_rtw_check_nan_enabled              p_wifi_rom2flash->rtw_check_nan_enabled
#define wifi_rom_rtw_check_nan_datalink_exist       p_wifi_rom2flash->rtw_check_nan_datalink_exist
#define wifi_rom_rtw_xmit_make_wlanhdr_nanaddr      p_wifi_rom2flash->rtw_xmit_make_wlanhdr_nanaddr

#define wifi_rom_hal_nan_set_pause_schedule_cmd(iface_type, bpause)     do {\
        if (p_wifi_rom2flash->rtw_nan_schdlr_set_pause_schedule) {\
            p_wifi_rom2flash->rtw_nan_schdlr_set_pause_schedule(iface_type, bpause);\
        } \
    } while(0)

#define wifi_rom_hal_nan_set_ap_schedule(iface_type, status)     do {\
        if (p_wifi_rom2flash->rtw_nan_schdlr_ap_set) {\
            p_wifi_rom2flash->rtw_nan_schdlr_ap_set(iface_type, status);\
        } \
    } while(0)

#define wifi_rom_hal_nan_set_sta_schedule(iface_type, bconnect)     do {\
        if (p_wifi_rom2flash->rtw_nan_schdlr_sta_set) {\
            p_wifi_rom2flash->rtw_nan_schdlr_sta_set(iface_type, bconnect);\
        } \
    } while(0)

#define wifi_rom_hal_wifi_tunnel_update_txdesc(ptxdesc, pframe, sc)     do {\
        if (p_wifi_rom2flash->wifi_tunnelapi_update_txdata_macswap) {\
            p_wifi_rom2flash->wifi_tunnelapi_update_txdata_macswap(ptxdesc, pframe, sc);\
        } \
    } while(0)

#define wifi_rom_sscanf_ss         p_wifi_rom2flash->_sscanf_ss

/* p2p */
#define wifi_rom_rtw_get_p2p_role   p_wifi_rom2flash->rtw_get_p2p_role

#ifdef __cplusplus
}
#endif

#endif /* platform.h */
