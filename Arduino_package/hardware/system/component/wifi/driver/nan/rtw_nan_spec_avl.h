
#ifndef __RTW_NAN_SPEC_AVL_H_
#define __RTW_NAN_SPEC_AVL_H_

/* NNA Availability attribute */
#define BAND_CHANNEL_ENTRY_HDR_LEN        (1)
#define CHANNEL_ENTRY_LEN                 (4)
#define CHANNEL_ENTRY_LEN_WITH_AUXI       (6)
#define BAND_ENTRY_LEN                    (1)

#define NAN_AVAIL_ENTRY_LENGTH_FIELD      (2)
#define NAN_AVAIL_ENTRY_HEADER_LENGTH     (7)

#define MAX_NAN_AVAIL_ATTR_LEN            (150)
#define MAX_NAN_AVAIL_PERIOD              (512)
#define MIN_NAN_AVAIL_PERIOD              (8)

#define BIT_DURATION_16_TU                (0)	/* 1 bit = 16 TUs */
#define BIT_DURATION_128_TU               (3)	/* 1 bit = 128 TUs */
#define DEFAULT_NDC_BIT_DURATION          BIT_DURATION_16_TU
#define DEFAULT_NDC_DURATION              (2)	/* 1 NAN Slot, 16 TUs */
#define DEFAULT_MAP_ID                    (0)
#define DEFAULT_WITHDRAW_TIMER_COUNT_DOWN (0)
#define DEFAULT_POTENTIAL_PREF            (2)

RTW_PACK_STRUCT_BEGIN
struct ch_entry_t {
	u8 ch_entry_op_cls;
	u8 ch_entry_ch_map[2];
	u8 ch_entry_ch_primary;
	u8 ch_entry_ch_aux[2];
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct bwch_entry_t {
	u8 bwch_entry_type: 1; //0-bw, 1-ch
	u8 bwch_entry_noncont_bw: 1;
	u8 bwch_entry_rsvd: 2;
	u8 bwch_entry_number: 4;

	u8 phy_entry[0];
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct tm_bitmap_t {
	u16 avl_tmbitmap_dur: 3;
	u16 avl_tmbitmap_period: 3;
	u16 avl_tmbitmap_startoffset: 9;
	u16 avl_tmbitmap_rsvd: 1;
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct avl_entrycontrl_t {
	u8 avl_entryctl_type : 3;
	u8 avl_entryctl_user_pree : 2;
	u8 avl_entryctl_utilization : 3;
	u8 avl_entryctl_rxnss: 4;
	u8 avl_entryctl_tmbitmap_present : 1;
	u8 avl_entryctl_rsvd : 3;
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct avl_entry_t {
	u8 avlentry_len[2];
	struct avl_entrycontrl_t avlentry_ctrl;
	u8 avlentry_bitmap_ctl[2];
	u8 avlentry_bitmap_len;

	u8 avlentry_tmbitmap[MAX_NAN_AVAIL_ATTR_LEN - 7]; //for time bitmap & band/channel entry list
	//time bitmap; //varable length
	//band/channel entry list; //varable length
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct avl_ctrl_t {
	u8 avlctrl_mapid: 4;
	u8 avlctrl_cmt_changed: 1;
	u8 avlctrl_potentail_changed: 1;
	u8 avlctrl_public_changed: 1;
	u8 avlctrl_ndc_changed: 1;
	u8 avlctrl_rsvd;
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct avl_attr_t {
	u8 avlattr_id;
	u8 avlattr_length[2];
	u8 avlattr_seqid;
	struct avl_ctrl_t avlattr_ctrl; //2 Byte
	u8 avlattr_entry[MAX_NAN_AVAIL_ATTR_LEN - 6];
} RTW_PACK_STRUCT_STRUCT;
RTW_PACK_STRUCT_END
#endif /* __RTW_NAN_SPEC_AVL_H_ */