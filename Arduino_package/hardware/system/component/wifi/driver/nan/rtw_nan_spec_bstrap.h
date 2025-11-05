
#ifndef __RTW_NAN_SPEC_BSTRAP_H_
#define __RTW_NAN_SPEC_BSTRAP_H_

/* nan paring bootstrapping attribute */
#define BSTRAP_TYPE_ADV           0
#define BSTRAP_TYPE_REQ           1
#define BSTRAP_TYPE_RSP           2
#define BSTRAP_STATUS_ACCEPT      0
#define BSTRAP_STATUS_REJECT      1
#define BSTRAP_STATUS_COMEBACK    2

#define GET_COMEBACK_FIELD_IN_NPBA(_attr_start) ((_attr_start) + 6)
#define GET_BSTRAP_METHOD_IN_NPBA(_attr_start, _attr_len)  ReadEF2Byte((_attr_start) + ((_attr_len) - 2 + 3))
#define SET_COMEBACK_AFTER_IN_NPBA(_attr_start, _val) 	SET_BITS_TO_LE_2BYTE((_attr_start) + 6, 0, 16, (_val))
#define SET_BSTRAP_METHOD_IN_NPBA(_attr_start, _offset, _val) 	SET_BITS_TO_LE_2BYTE((_attr_start) + (_offset), 0, 16, (_val))

RTW_PACK_STRUCT_BEGIN
struct npba_attr_t {
	u8 npba_attr_id;
	u8 npba_attr_len[2];
	u8 npba_attr_token;
	u8 npba_attr_type: 4;
	u8 npba_attr_status: 4;
	u8 npba_attr_reason;
	//u8 COMEBACK_AFTER_IN_NPBA[variable];
	//u8 BSTRAP_METHOD_IN_NPBA[2];
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END
#endif /* __RTW_NAN_SPEC_BSTRAP_H_ */