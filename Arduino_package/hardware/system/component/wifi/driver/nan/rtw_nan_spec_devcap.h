
#ifndef __RTW_NAN_SPEC_DEVCAP_H_
#define __RTW_NAN_SPEC_DEVCAP_H_

/* Field Control of Device Capability attribute */
#define DEVICE_CAP_MAPID_LEN					(1)
#define DEVICE_CAP_COMMITTED_DW_INFO_LEN		(2)
#define DEVICE_CAP_SUPPORT_BANDS_LEN			(1)
#define DEVICE_CAP_OPERATION_MODE_LEN			(1)
#define DEVICE_CAP_NUMBER_OF_ANTENNAS_LEN		(1)
#define DEVICE_CAP_MAX_CHANNEL_SWITCH_TIME_LEN	(2)
#define DEVICE_CAP_CAPABILITIES_LEN				(1)

#define SET_NAN_DEVICE_CAP_ELE_MAPID(_pEleStart, _val)  SET_BITS_TO_LE_1BYTE(_pEleStart, 0, 5, _val)
#define SET_NDPE_SUPPORT_IN_CAPABILITIES(_cap, _val)    ((_cap) = ((_cap)&0xf7)|((_val)<<3))
#define IS_SUPPORT_SIMUTANEOUS_OPERATION(_cap)          ((_cap)&BIT2)
#define IS_SUPPORT_NDPE(_cap)                           (((_cap)&BIT3) ? TRUE:FALSE)

#define MAX_DEV_CAP_ATTR_LEN (12)

RTW_PACK_STRUCT_BEGIN
struct dev_cap_t {
	u8 devcap_attr_id;
	u8 devcap_attr_len[2];

	u8 devcap_attr_mapid;

	u8 devcap_attr_24gdw : 3;
	u8 devcap_attr_5gdw : 3;
	u8 devcap_attr_24gdw_overwrite_lsb : 2;
	u8 devcap_attr_24gdw_overwrite_hsb : 2;
	u8 devcap_attr_5gdw_overwrite : 4;
	u8 devcap_attr_rsvd : 2;

	u8 devcap_attr_rsvd_1 : 2;
	u8 devcap_attr_spt_bw24g : 1;
	u8 devcap_attr_rsvd_2 : 1;
	u8 devcap_attr_spt_bw5g : 1;
	u8 devcap_attr_rsvd_3 : 3;

	u8 devcap_attr_op_phymode : 1;
	u8 devcap_attr_op_vht160nc : 1;
	u8 devcap_attr_op_vht160c : 1;
	u8 devcap_attr_rsvd_4 : 5;

	u8 devcap_attr_txant_num : 4;
	u8 devcap_attr_rxant_num : 4;
	u8 devcap_attr_max_chsw_time[2];
	u8 devcap_attr_capbilitys;
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

#endif /* __RTW_NAN_SPEC_DEVCAP_H_ */