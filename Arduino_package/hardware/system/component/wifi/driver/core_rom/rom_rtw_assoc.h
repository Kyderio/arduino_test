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
#ifndef _ROM_RTW_ASSOC_H
#define _ROM_RTW_ASSOC_H

u8 *wifi_rom_issue_assocreq_fill_cap(
	unsigned char	*pframe, u32	*pktlen,
	struct issue_assoc_req_param *req_parms,
	unsigned char rtw_trp_tis_cert_en,
	u8 dfs_en, u32 size);


u8 *wifi_rom_issue_assocreq_fill_vendor_ie(
	unsigned char	*pframe, u32	*pktlen,
	struct issue_assoc_req_param_2 *req_parms,
	struct wps_priv *pwpspriv, u32 size);


u8 *wifi_rom_issue_assocrsp_fill_cap(
	struct issue_assoc_rsp_param *assocrsp_param,
	unsigned char	*pframe, u32	*pktlen,
	unsigned short status, u16 aid, u32 size);

u8 wifi_rom_on_assocreq_check(
	u8 *pframe, u32 pkt_len, unsigned short ie_offset,
	struct on_assoc_req_param *assocreq_param);

u8 wifi_rom_on_assocrsp_wmm(
	u32 *ACParam,
	u8 *wmm_param,
	u8 cur_wireless_mode,
	u8 slotTime);

#endif
