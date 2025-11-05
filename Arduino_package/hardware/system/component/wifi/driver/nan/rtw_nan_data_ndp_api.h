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
#ifndef _RTW_NAN_NDP_API_H_
#define _RTW_NAN_NDP_API_H_

#ifdef CONFIG_NAN
#define NAN_MAX_SECURITY_INFO_LEN      (127)

struct nan_data_req_info {
	/* CAPI parameters */
	u8 req_type;	/* 0 = ndp */
	u8 rsp_nan_mac[ETH_ALEN];
	u8 sec;
	/* spec parameters */
	u8 type;	/* 0 = ucast */
	u8 publish_id;
	u8 mcast_addr[ETH_ALEN];
	/*
	*	Unicast: data_path_type = 0 qos = 1
	*	Multicast: data_path_type = 1 qos = 1
	*/
	struct nan_qos_req qos_req;
	/* sec_config_param not implement yet */
	u8 srvc_info[MAX_SDA_SRVC_INFO_LEN];
	u16 srvc_info_len;

	u8 sec_type; /* 1: set pmk */
	u8 sec_info[NAN_MAX_SECURITY_INFO_LEN];
	u8 sec_info_len;
};


struct nan_data_rsp_info {
	/* CAPI parameters */
	u8 rsp_mode;
	u8 ndl_rsp;
	u8 data_path_id;
	u8 publish_id;
	u8 m4_rsp_type;
	/* spec parameters */
	u8 type;	/* 0 = ucast */
	u8 mc_id; 	/* mcast */
	u8 initiator_data_address[ETH_ALEN];	/* ucast */
	u8 mcast_addr[ETH_ALEN];
	/*
	*	Unicast: data_path_type = 0 qos = 1
	*	Multicast: data_path_type = 1 qos = 1
	*/
	struct nan_qos_req qos_req;
	/* sec_config_param not implement yet */
	u8 srvc_info[MAX_SDA_SRVC_INFO_LEN];
	u16 srvc_info_len;
};

struct nan_data_end_info {
	/* CAPI parameters */
	u8 ndp_id;
	u8 initiatorndi[ETH_ALEN];
	/* spec parameters */
	u8 type; /* 0 = ucast */
	u8 status;
	u8 mc_id; /* mcast */
	u8 nmsg_id; /* mcast */
};

int rtw_nan_ndp_request_api(struct nan_data_req_info *pset_input);
int rtw_nan_ndp_response_auto_api(struct nan_data_rsp_info *pset_input);
int rtw_nan_ndp_response_peer_api(struct nan_data_rsp_info *pset_input);
int rtw_nan_ndp_terminate_api(struct nan_data_end_info *pset_input);
#endif /* CONFIG_NAN */
#endif /* _RTW_NAN_NDP_API_H_ */
