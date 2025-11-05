
#ifndef __RTW_NAN_SPEC_NDL_H_
#define __RTW_NAN_SPEC_NDL_H_

#define MAX_NDL_ATTR_HDR_LEN (10)


RTW_PACK_STRUCT_BEGIN
struct ndl_ctrl_t {
	u8 ndl_ctrl_peerid_present: 1;
	u8 ndl_ctrl_immutable_present: 1;
	u8 ndl_ctrl_ndc_present: 1;
	u8 ndl_ctrl_qos_present: 1;
	u8 ndl_ctrl_max_idleperiod_present: 1;
	u8 ndl_ctrl_ndl_type: 1;
	u8 ndl_ctrl_setup_reason: 2;
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct ndl_attr_t {
	u8 ndl_attr_id;
	u8 ndl_attr_len[2];
	u8 ndl_attr_token;
	u8 ndl_attr_type: 4;
	u8 ndl_attr_status: 4;
	u8 ndl_attr_reason;
	struct ndl_ctrl_t ndl_ctrl;
	//u8 NDL_PEER_ID; optinal
	//u16 MAX_IDLE_PERIOD; optinal
	//u8 IMMUTABLE_SCHDULE_ENTRY_LIST[0]; optinal
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

#endif /* __RTW_NAN_SPEC_NDL_H_ */