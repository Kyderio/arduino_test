
#ifndef __RTW_NAN_SPEC_NDP_H_
#define __RTW_NAN_SPEC_NDP_H_

#define MAX_IPV6_INFO_LEN 		(8)
#define MAX_NDP_ATTR_HDR_LEN 	(14)
#define GET_NDP_BY_INIT_NDI 	(1)
#define GET_NDP_BY_NDP_ID 		(2)
#define GET_NDP_BY_PEER 		(4)
#define GET_NDP_BY_TOKEN 		(5)

/* TLV format for NDPE TLV List Field */
#define NDPE_TLV_TYPE_IPV6_LINK_LOCAL  0
#define NDPE_TLV_TYPE_SERVICE_INFO     1

RTW_PACK_STRUCT_BEGIN
struct ndpe_tlv_t {
	u8 ndpe_svcinfo_type;
	u8 ndpe_svcinfo_len[2];
	u8 ndpe_val[0];
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct ndpe_ipv6_t {
	u8 ndpe_ipv6_type;
	u8 ndpe_ipv6_len[2];
	u8 interface_id[8];
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
#define NAN_SRVC_PROTOCOL_BONJOUR    1
#define NAN_SRVC_PROTOCOL_GENIC      2
struct ndpe_svcinfo_t {
	u8 ndpe_svcinfo_type;
	u8 ndpe_svcinfo_len[2];
	u8 ndpe_svcinfo_oui[3];
	u8 ndpe_svcinfo_ptotocol_type;
	u8 ndpe_svcinfo_specinfo[0];
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

/* NDP attribute */
RTW_PACK_STRUCT_BEGIN
struct ndp_ctrl_t {//same with ndpe
	u8 ndpctrl_conform_requier: 1;
	u8 ndpctrl_resvd: 1;
	u8 ndpctrl_sec_present: 1;
	u8 ndpctrl_publishid_present: 1;
	u8 ndpctrl_rsp_ndi_present: 1;
	u8 ndpctrl_gtk_required: 1;
	u8 ndpctrl_gtk_rsvd: 2;
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct ndp_attr_t {//same with ndpe
	u8 ndp_attr_id;
	u8 ndp_attr_len[2];
	u8 ndp_attr_token;
	u8 ndp_attr_type: 4;
	u8 ndp_attr_status: 4;
	u8 ndp_attr_reason;
	u8 ndp_attr_init_ndi[ETH_ALEN];
	u8 ndp_attr_ndpid;
	struct ndp_ctrl_t ndp_ctrl;
	u8 ndp_attr_publishid;
	u8 ndp_attr_rsp_ndi[ETH_ALEN];
	u8 ndp_attr_specinfo[0];//ndpe is tlv list
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

#endif /* __RTW_NAN_SPEC_NDP_H_ */