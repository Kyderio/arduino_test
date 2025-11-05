
#ifndef __RTW_NAN_SPEC_NDC_H_
#define __RTW_NAN_SPEC_NDC_H_

#define MAX_NDC_ATTR_HDR_LEN (10)

/* NNA Schedule Entry attribute */
#define	BITMAP_OFFSET_IN_SCHEDULE_ENTRY						(4)
RTW_PACK_STRUCT_BEGIN
struct ndc_sch_entry_t {
	u8 ndc_schentry_mapid;
	u8 ndc_schentry_bitmap_ctl[2];
	u8 ndc_schentry_bitmap_len;
	u8 ndc_schentry_bitmap[0];
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct ndc_attr_t {
	u8 ndc_attr_id;
	u8 ndc_attr_len[2];
	u8 ndc_attr_ndcid[6];
	u8 ndc_attr_selected_ndc: 1;
	u8 ndc_attr_rsvd: 7;
	u8 ndc_attr_schentry[0];
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

#endif /* __RTW_NAN_SPEC_NDC_H_ */