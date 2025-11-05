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
#ifndef __ROM_RTW_80211W_H_
#define __ROM_RTW_80211W_H_

void wifi_rom_dot11w_construct_action_frame(u8 *buf, struct dot11w_action_params *params);
u32 wifi_rom_dot11w_BIP_verify(u8 *pframe, u16 pkt_len, u64 *mgnt_80211w_IPN_rx, u32 dot11wBIPKeyid, u8 *key, u8 encrypt);

#endif

