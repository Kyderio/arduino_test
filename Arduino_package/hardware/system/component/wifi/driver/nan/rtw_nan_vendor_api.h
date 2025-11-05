/******************************************************************************
 * Copyright (c) 2007-2016 Realtek Semiconductor Corp. All Rights Reserved.
 *
 * This program is dual-licensed under both the GPL version 2 and BSD
 * license. Either license may be used at your option.
 *
 *
 * License
 *
 *
 * GPL v2:
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 *
 * Alternatively, this software may be distributed, used, and modified
 * under the terms of BSD license:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name(s) of the above-listed copyright holder(s) nor the
 * names of its contributors may be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/
#ifndef _RTW_NAN_VENDOR_API_H_
#define _RTW_NAN_VENDOR_API_H_

#ifdef CONFIG_NAN

/*********************************/
/**	Define Constants & Macros	**/
/*********************************/
enum ANDROID_VENDOR_SUB_COMMAND {
	/* don't use 0 as a valid subcommand */
	VENDOR_NL80211_SUBCMD_UNSPECIFIED,

	/* define all NAN related commands between 0x1900 and 0x19FF */
	NL80211_SUBCMD_NAN_RANGE_START = 0x1900,
	NL80211_SUBCMD_NAN_RANGE_END   = 0x19FF,

	/* This is reserved for future usage */
} ;

enum _nan_vendor_map {
	NAN_VENDOE_RTW		= (1 << 0),
	NAN_VENDOE_NANDOW	= (1 << 1),
};

enum rtw_vendor_subcmd {
	NAN_SUBCMD_SRVC_EXT_INFO = NL80211_SUBCMD_NAN_RANGE_START,	/* 0x1900 */
	NAN_SUBCMD_DATA_REQ,						/* 0x1901 */
	NAN_SUBCMD_DATA_RSP,						/* 0x1902 */
	NAN_SUBCMD_DATA_END,						/* 0x1903 */
	NAN_SUBCMD_DATA_UPDATE,					/* 0x1904 */
	NAN_SUBCMD_CUSTOMER_NANDOW,			/* 0x1905 */
	NAN_SUBCMD_FOLLOWUP,						/* 0x1906 */
	NAN_SUBCMD_PAIRING_SET_PW,          /* 0x1907 */
	NAN_SUBCMD_PASN_START,              /* 0x1908 */
	NAN_SUBCMD_PASN_SET_KEY,            /* 0x1909 */

	VENDOR_SUBCMD_MAX
};

enum rtw_vendor_event {
	NAN_EVENT_DATA_COMFIRM,
#ifdef NAN_CUSTOMER_NANDOW
	NAN_EVENT_NANDOW_MAX    =   WFPAL_M_SET_INFRA_CHANNEL,
#endif
	NAN_EVENT_DATA_TERMINATION,
	NAN_EVENT_DATA_INDICATION,
	NAN_EVENT_PASN_START,
	NAN_EVENT_PASN_RX,
	NAN_EVENT_PASN_UPD_PMKID,
};

#ifdef CONFIG_NAN_PAIRING
/**
 * nan_vendor_tx_followup_info
 * @follow_up_type: enum nan_tx_follow_up_type
 * @remote_inst_id: the instance id of the peer's service
 * @local_inst_id: the instance id
 * @remote_mac: the peer's mac
 * @bstrap_type_status:
 *  [3:0] type: 1: request 2: response
 *  [7:4] status: 0: accepted (only applicable with type = 2)
 *                1: rejected (only applicable with type = 2)
 *                2: comeback
 * @bootstrap_method:
 */
struct nan_vendor_tx_followup_info {
	u8 follow_up_type;
	u8 remote_inst_id;
	u8 local_inst_id;
	u8 remote_mac[ETH_ALEN];
	/* general */
	// todo: buf (check iw r1/r2)
	/* bootstrapping param */
	u8 bstrap_type_status;
	u8 bstrap_reason;
	u16 bstrap_method;
	u8 sec_key_type; /* enum nan_tx_follow_up_key_type */
};
#endif

#ifdef CONFIG_NAN_PAIRING
struct nan_pairing_setpw {
	u8 peer_nmi[ETH_ALEN];
	char pw[MAX_PASN_PW_LEN+1];
	u8 pw_len;
};

struct nan_pairing_start {
	u8 role;
	u8 type;
	u8 peer_nmi[ETH_ALEN];
	u8 auth_method;
	u8 nik_caching;
};

struct nan_event_pasn_start {
	u8 deinit;
	u8 role;
	u8 pairing_type;
	u8 peer_nmi[ETH_ALEN];
	u8 bssid[ETH_ALEN];
	u8 setup_para_auth_method;
	u8 setup_para_nik_chahing;
	u8 setup_para_passphrase_len;
	char setup_para_passphrase[MAX_PASN_PW_LEN];
	u16 auth_frame_len;
	u8 auth_frame[MAX_PASN_RX_LEN];
	u8 append_nan_attr_len;
	u8 append_nan_attr[MAX_PASN_NAN_APPEND_IE_LEN];
	u8 own_pmkid[MAX_PMKID_LEN];
	u8 peer_pmkid[MAX_PMKID_LEN];
} __attribute__((packed));

struct nan_event_pasn_rx {
	u8 seq;
	u8 pairing_type;
	u8 passphrase_len;
	char passphrase[MAX_PASN_PW_LEN];
	u16 auth_frame_len;
	u8 auth_frame[MAX_PASN_RX_LEN];
	u8 append_nan_attr_len;
	u8 append_nan_attr[MAX_PASN_NAN_APPEND_IE_LEN];
} __attribute__((packed));

struct nan_event_pasn_upd_pmkid {
	u8 role;
	u8 status;
	u8 peer_nmi[ETH_ALEN];
	u8 peer_pmkid[PMKID_LEN];
	u8 auth_method;
} __attribute__((packed));

int rtw_cfgvendor_set_nan_follow_up(const void *data, int len);
void rtw_cfgvendor_nan_event_hdr_pasn_start(u8 *peer, u8 pairing_role, struct nan_peer_info_t *ppeer_info, u8 *auth_frame,
		u16 auth_frame_len, u8 *own_pmkid, u8 *peer_pmkid);
void rtw_cfgvendor_nan_event_hdr_pasn_rx(u8 seq, struct nan_peer_info_t *ppeer_info, u8 *auth_frame, u16 auth_frame_len);
void rtw_cfgvendor_nan_event_hdr_pasn_upd_pmkid(u8 status, struct nan_peer_info_t *ppeer_info);
int rtw_cfgvendor_nan_pairing_set_pw(const void *data, int len);
int rtw_cfgvendor_nan_pasn_start(const void *data, int len);
int rtw_cfgvendor_nan_pasn_setkeys(const void *data, int len);
#endif /* CONFIG_NAN_PAIRING */

#ifdef NAN_CUSTOMER_NANDOW
int rtw_cfgvendor_nandow_entry(const void *data, int len);
#endif

u8 is_cfgvendor_nan_evt_valid(u8 event_id, u8 work_mode);
int rtw_cfgvendor_set_nan_srvc_extinfo(const void *data, int len);
int rtw_cfgvendor_set_ndp_request(const void *data, int len);
int rtw_cfgvendor_set_ndp_response(const void *data, int len);
int rtw_cfgvendor_set_ndp_terminate(const void *data, int len);
void rtw_cfgvendor_nan_data_indication_evt(struct nan_event_data_indication *event);
void rtw_cfgvendor_nan_sdf_indication_match(struct nan_peer_info_t *ppeer_info,	struct nan_peer_srvcinfo_t *ppeer_srvcinfo,	struct nan_srvc_inst_t *psrvc_inst);
void rtw_cfgvendor_nan_data_comfirm_evt(struct nan_event_data_comfirm event);
void rtw_cfgvendor_nan_data_termination_evt(struct nan_event_data_termination event);
void rtw_cfgvendor_nan_event_pass_on_entry(int event_id, u8 *event, int size);
void rtw_cfgvendor_nan_event_hdr_cluster_changed(void);
void rtw_cfgvendor_nan_event_pub_rx_4nandow(u8 instance_id, u8 peer_inst_id, u8 *peer_mac, u8 *sdf_attr_start, u16 attr_total_len);
void rtw_cfgvendor_nan_event_follow_rx_4nandow(u8 instance_id, u8 peer_inst_id, u8 *peer_mac, u8 *sdf_attr_start, u16 attr_total_len);
void rtw_cfgvendor_nan_event_pub_replied_4nandow(u8 instance_id, u8 peer_inst_id, u8 *peer_mac);
void rtw_cfgvendor_nan_event_follow_replied_4nandow(struct nan_srvc_inst_t *psrvc_inst);
void rtw_cfgvendor_nan_event_hdr_subscribe_terminated(u8 subscribe_id, u8 reason);
void rtw_cfgvendor_nan_event_hdr_publish_terminated(u8 publish_id, u8 reason);
void rtw_cfgvendor_nan_event_hdr_datapath_request_received(u8 *attr_start, u16 attr_total_len, struct ndp_attr_t *pndp_attr, u8 *sender_nmi);
void rtw_cfgvendor_nan_event_hdr_datapath_response_received(u8 *attr_start, u16 attr_total_len, struct ndp_attr_t *pndp_attr, u8 *sender_nmi);
void rtw_cfgvendor_nan_event_hdr_datapath_confirm_received(u8 *attr_start, u16 attr_total_len, struct ndp_attr_t *pndp_attr, u8 *sender_nmi);
void rtw_cfgvendor_nan_event_hdr_datapath_established(struct ndp_entry_t *pndp_entry, u8 init_ndi_self, u8 *sender_nmi);
void rtw_cfgvendor_nan_event_hdr_datapath_end(struct ndp_entry_t *pndp_entry, u8 reason, u8 *sender_nmi);
void rtw_cfgvendor_nan_event_hdr_beacon(union recv_frame *precv_frame);
#endif /* CONFIG_NAN */

#endif
