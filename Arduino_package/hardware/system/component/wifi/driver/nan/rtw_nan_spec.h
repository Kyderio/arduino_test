
#ifndef __RTW_NAN_SPEC_H_
#define __RTW_NAN_SPEC_H_

//NOTICE: carefor ndl_rx_state_from_typewhen you change this enum
enum ndl_type_e {
	NDL_TYPE_REQ = 0,
	NDL_TYPE_RSP,
	NDL_TYPE_CONFIRM,
	NDL_TYPE_MAX
};

enum ndp_end_reason_e {
	NAN_DATAPATH_END_REASON_USER_INITIATED                              = 0,
	NAN_DATAPATH_END_REASON_PEER_INITIATED                              = 1,
	NAN_DATAPATH_END_REASON_CHIP_RESET                                  = 2,
	NAN_DATAPATH_END_REASON_NAN_DISABLE                                 = 3,
	NAN_DATAPATH_END_REASON_REQUEST_TX_FAIL                             = 4,
	NAN_DATAPATH_END_REASON_RESPONSE_TIMEOUT                            = 5,
	NAN_DATAPATH_END_REASON_USER_INPUT_TIMEOUT                          = 6,
	NAN_DATAPATH_END_REASON_RESPONSE_TX_FAIL                            = 7,
	NAN_DATAPATH_END_REASON_CONFIRMATION_TIMEOUT                        = 8,
	NAN_DATAPATH_END_REASON_CONFIRMATION_TX_FAIL                        = 9,
	NAN_DATAPATH_END_REASON_PEER_CACHE_TIMEOUT                          = 10,
	NAN_DATAPATH_END_REASON_TERM_TIMEOUT                                = 11,
	NAN_DATAPATH_END_REASON_PEER_INACTIVE                               = 12,
	NAN_DATAPATH_END_REASON_INITIATE_WAIT_TIMEOUT                       = 13,
	NAN_DATAPATH_END_REASON_PEER_NOT_FOUND                              = 14,
	NAN_DATAPATH_END_REASON_PEER_CHIP_REJECT                            = 15,
	NAN_DATAPATH_END_REASON_KEEP_ALIVE_TIMEOUT                          = 16,
	NAN_DATAPATH_END_REASON_ENCRYPTED_DATAPATH_TERMINATED_ON_CHIP_RESET = 17,
	NAN_DATAPATH_END_REASON_CHIP_TIMEOUT                                = 18,
	NAN_DATAPATH_END_REASON_UNKNOWN                                     = 19,
} ;

//NOTICE: carefor ndp_tx_state_from_type & ndp_rx_state_from_typewhen you change this enum
enum ndp_type_e {
	NDP_TYPE_REQ = 0,
	NDP_TYPE_RSP,
	NDP_TYPE_CONFIRM,
	NDP_TYPE_SEC_INSTALL,
	NDP_TYPE_TERMINATE,
	NDP_TYPE_MAX
};

enum ndp_rsp_mode_e {
	NDP_RSP_MODE_PEER = 0,
	NDP_RSP_MODE_AUTO,
};

enum _nan_action_frame_subtype {
	NAF_SUBTYPE_NONE = 0,
	NAF_SUBTYPE_RANGE_REQ = 1,
	NAF_SUBTYPE_RANGE_RSP = 2,
	NAF_SUBTYPE_RANGE_TERMINATE = 3,
	NAF_SUBTYPE_RANGE_RPT = 4,

	NAF_SUBTYPE_DATA_PATH_REQ = 5,
	NAF_SUBTYPE_DATA_PATH_RSP = 6,
	NAF_SUBTYPE_DATA_PATH_CONFIRM = 7,
	NAF_SUBTYPE_DATA_PATH_KEY_INSTALL = 8,
	NAF_SUBTYPE_DATA_PATH_TERMINATE = 9,

	NAF_SUBTYPE_SCHEDULE_REQ = 10,
	NAF_SUBTYPE_SCHEDULE_RSP = 11,
	NAF_SUBTYPE_SCHEDULE_CONFIRM = 12,
	NAF_SUBTYPE_SCHEDULE_NOTIFICATION = 13
};

enum _nan_attr_id {
	NAN_ATTR_ID_MASTER_INDICATION            = 0x0,
	NAN_ATTR_ID_CLUSTER                      = 0x1,
	NAN_ATTR_ID_SERVICE_DESCRIPTOR           = 0x3,
	NAN_ATTR_ID_NAN_CONNECTION_CAPABILITY    = 0x4,
	NAN_ATTR_ID_SERVICE_DESCRIPTOR_EXTENSION = 0xE,
	NAN_ATTR_ID_DEVICE_CAPABILITY            = 0xF,
	NAN_ATTR_ID_NDP                          = 0x10,
	NAN_ATTR_ID_NAN_AVAILABILITY             = 0x12,
	NAN_ATTR_ID_NDC                          = 0x13,
	NAN_ATTR_ID_NDL                          = 0x14,
	NAN_ATTR_ID_NDL_QOS                      = 0x15,
	NAN_ATTR_ID_ELEMENT_CONTAINER            = 0x1D,
	NAN_ATTR_ID_CIPHER_SUITE_INFO            = 0x22,
	NAN_ATTR_ID_SECURITY_CONTEXT_INFO        = 0x23,
	NAN_ATTR_ID_SHARED_KEY_DESCRIPTOR        = 0x24,
	NAN_ATTR_ID_PUBLIC_AVAILABILITY          = 0x27,
	NAN_ATTR_ID_NDP_EXTENSION                = 0x29,
	NAN_ATTR_ID_DEV_CAP_EXTENSION            = 0x2A,
	NAN_ATTR_ID_IDENTITY_RESOLUTION          = 0x2B,
	NAN_ATTR_ID_PAIR_BOOTSTRAPPING           = 0x2C,
	NAN_ATTR_ID_VECDOR_SPECIFIC              = 0xDD,
	NAN_ATTR_MAX,
};

/* Connection Capability attribute */
RTW_PACK_STRUCT_BEGIN
struct concap_attr_t {
	u8 concap_attr_id;
	u8 concap_attr_len[2];

	u8 concap_attr_wifi_direct: 1;
	u8 concap_attr_p2ps: 1;
	u8 concap_attr_tdls: 1;
	u8 concap_attr_infra: 1;
	u8 concap_attr_ibss: 1;
	u8 concap_attr_mesh: 1;
	u8 rsvd0: 2;

	u8 rsvd1;
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

/* identity resolution attribute (NIRA) */
#define WPA_NIRA_NONCE_LEN            (8)
#define WPA_NIRA_TAG_LEN              (8)

RTW_PACK_STRUCT_BEGIN
struct identity_attr_t {
	u8 identity_attr_id;
	u8 identity_attr_len[2];
	u8 identity_attr_chiperver;
	u8 identity_attr_nonce[WPA_NIRA_NONCE_LEN];
	u8 identity_attr_tag[WPA_NIRA_TAG_LEN];
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

/* nan device capability extension attribute(DCEA) */
#define MAX_DECA_TOTAL_LEN             (8)
RTW_PACK_STRUCT_BEGIN
struct devcap_eattr_t {
	u8 devcap_eattr_id;
	u8 devcap_eattr_len[2];

	u8 devcap_eattr_rsvd;

	u8 devcap_eattr_pairing_setup : 1;
	u8 devcap_eattr_npk_nik_caching : 1;
	u8 devcap_eattr_rsvd2 : 6;

	u8 devcap_eattr_rsvd3[3];
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END


RTW_PACK_STRUCT_BEGIN
struct qos_attr_t {
	u8 qos_attr_id;
	u8 qos_attr_len[2];
	u8 qos_attr_min_interval;
	u8 qos_attr_max_latendy[2];
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

/* NAN Element Container attribute */
#define GET_NAN_ELE_CONT_ELE_ID(_pEleStart)		LE_BITS_TO_1BYTE(_pEleStart, 0, 8)
#define GET_NAN_ELE_CONT_ELE_LEN(_pEleStart)	LE_BITS_TO_1BYTE(_pEleStart + 1, 0, 8)

RTW_PACK_STRUCT_BEGIN
struct container_attr_t {
	u8 ctn_attr_id;
	u8 ctn_attr_len[2];
	u8 ctn_attr_mapid;
	u8 elements[0];
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

#include "rtw_nan_spec_avl.h"
#include "rtw_nan_spec_bstrap.h"
#include "rtw_nan_spec_devcap.h"
#include "rtw_nan_spec_ndc.h"
#include "rtw_nan_spec_ndl.h"
#include "rtw_nan_spec_ndp.h"
#include "rtw_nan_spec_sda.h"
#include "rtw_nan_spec_sec.h"

static const u8 RSN_SELECTOR_GTK[RSN_SELECTOR_LEN] = {0x00, 0x0F, 0xAC, 0x01};
static const u8 RSN_SELECTOR_MAC[RSN_SELECTOR_LEN] = {0x00, 0x0F, 0xAC, 0x03};
static const u8 RSN_SELECTOR_IGTK[RSN_SELECTOR_LEN] = {0x00, 0x0F, 0xAC, 0x09};
static const u8 RSN_SELECTOR_BIGTK[RSN_SELECTOR_LEN] = {0x00, 0x0F, 0xAC, 0x0E};
static const u8 RSN_SELECTOR_NIK[RSN_SELECTOR_LEN] = {0x00, 0x0F, 0xAC, 0x24};
static const u8 RSN_SELECTOR_NAN_KEY_LIFE[RSN_SELECTOR_LEN] = {0x00, 0x0F, 0xAC, 0x25};
#endif /* __RTW_NAN_SPEC_H_ */