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
#ifndef __RTW_NAN_DE_H_
#define __RTW_NAN_DE_H_

#define MAX_PUBLISHER_NUM	(8)
#define MAX_SUBSCRIBER_NUM	(8)
#define MAX_TOTAL_SRV_NUM	(8)

#define SOLICITED_BCAST_TIME 	(4)


struct nan_publish_info {
	struct nan_qos_req qos_req; //Unicast: data_path_type = 0 qos = 1; Multicast: data_path_type = 1 qos = 1

	u32 solicited_bcast_end_time; /* Time to stop sending bcast SDF on solicited publish */

	/*
	 * pub_pmk and pub_pmkid only use for publish
	 * and these two parameters follow specific service.
	 * pub_pmkid is calculated form pub_pmk and broadcast
	 * mac addr,and used in solicted/unsolicated publish SDF
	 */
	u8 passphrase[MAX_PASSPHRASE_LEN + 1];
	u8 passphrase_len;
	u8 pub_pmk[MAX_PMK_LEN];
	u8 pub_pmkid[MAX_PMKID_LEN];

	u8 srvc_update_indicator; /* Version of the service specific information corresponding to the Publish instance */

	u8 ipv6_info[MAX_IPV6_INFO_LEN];
};

struct nan_subscribe_info {
	u8 rsvd;
};


struct nan_followup_info {
	u8 followup_reqid; /*req service info: instance id */
	u8 followup_dest[ETH_ALEN]; /*req service info: dest */
	u8 matched_instance_id; /* matched service info: pub or sub instance id */

#ifdef CONFIG_NAN_PAIRING
	u8 *bstrap_cookie;
	u16 bstrap_method;
	/**
	 * pairing bootstrapping
	 * type: 1: request 2: response
	 * status: 0: accepted (only applicable with type = 2)
	 *          1: rejected (only applicable with type = 2)
	 *          2: comeback
	 */
	u8 bstrap_type;
	u8 bstrap_status;
	u8 bstrap_reason;
	u8 bstrap_cookie_len;
	u8 sec_key_type;
#endif
};

int rtw_nanapi_instance_add(struct rtw_nan_func_t *func, u64 nan_func_pointer);
void rtw_nanapi_instance_del(u64 cookie);
struct nan_srvc_inst_t *rtw_nan_srvc_instance_alloc(u8 scf_type, const u8 *psrv_specinfo, u16 srv_specinfo_len);
void rtw_nan_srvc_instance_free(struct nan_srvc_inst_t *psrvc_inst);
void rtw_nan_matchfilter_init_4subpub(struct nan_srvc_inst_t *psrvc_inst, struct rtw_nan_func_t *func);
struct nan_srvc_inst_t *rtw_nan_srvc_instance_get(u8 type_index, void *pdata, u8 search_type);
void rtw_nan_srvc_instance_remove(struct nan_srvc_inst_t *psrvc_inst);
void rtw_nan_srvc_instance_init(u8 scf_type, struct nan_srvc_inst_t *psrvc_inst, struct nan_instparam_t *pinst_parm);
void rtw_nan_srvc_followup_inst_equeue(struct nan_srvc_inst_t *psrvc_inst, u8 requestor_inst_id, struct nan_peer_info_t *ppeer_info);


void rtw_nan_peer_srvcinfo_store(struct nan_peer_srvcinfo_t *ppeer_srvcinfo, struct svcinfo_field_t *psvc_info_field, u32 len);
void rtw_nan_peer_srvcinfo_free(struct nan_peer_srvcinfo_t *ppeer_srvcinfo);
struct nan_peer_srvcinfo_t *rtw_nan_peer_srvcinfo_alloc(struct nan_peer_info_t *ppeer_info, struct nan_srvc_inst_t *psrvc_inst, u8 peer_inst_id,
		u8 *peer_service_id);
struct nan_peer_srvcinfo_t *rtw_nan_peer_srvcinfo_get(struct nan_peer_info_t *ppeer_info, u8 *pdata, u8 search_type);
u16 rtw_nan_generic_srvcinfo_construct(u8 *srv_info);
void rtw_nan_peer_generic_srvcinfo_store(struct nan_peer_srvcinfo_t *ppeer_srvcinfo, struct svcinfo_field_t *psrvc_info, u16 srvc_len);


u8 rtw_nan_svcrsp_filter_check(u8 *pnan_attr_start, u32 *filter_len, u8 mf_list_len);
void rtw_nan_svcrsp_filter_alloc_4sub(struct nan_srvc_inst_t *psrvc_inst, struct rtw_nan_func_t *func);
void rtw_nan_svcrsp_filter_free_4sub(struct nan_srvc_inst_t *psrvc_inst);
u8 rtw_nan_matchfilter_check_4subpub(struct nan_srvc_inst_t *psrvc_inst, u8 *pnan_attr_start, u32 *filter_len, u8 *pmf_list_len);

#endif