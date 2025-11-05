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
#ifndef __RTW_NAN_SCHDLR_H_
#define __RTW_NAN_SCHDLR_H_

#define advance_bitmap_by_count(_count, _bitmap_len, _bitmap, _start_offset,_period,_bit_dur)\
{\
	(_count)++;\
	(_start_offset)+=(BIT0<<(_bit_dur));\
	if((_period)){\
		if((_count) && !((_count)%((_bitmap_len)*8))){\
			(_bitmap)-=((_bitmap_len)-1);\
			if(((_bitmap_len)*8*(BIT0<<(_bit_dur))) < (_period)){\
				(_start_offset)-=((_bitmap_len)*8*(BIT0<<(_bit_dur)));\
				(_start_offset)+=(_period);\
			}\
			else if(((_bitmap_len)*8*(BIT0<<_bit_dur))%(_period)){\
				(_start_offset)-=(((_bitmap_len)*8*(BIT0<<_bit_dur))%(_period));\
				(_start_offset)+=(_period);\
			}\
		}\
		else if((_count) && !((_count)%8)){\
			(_bitmap)++;\
		}\
	}\
	else if((_count) && !((_count)%((_bitmap_len)*8))){\
			(_start_offset)-=((_bitmap_len)*8*(BIT0<<(_bit_dur)));\
		}\
}

#define setup_perfer_channel_info(_prefer_ch, _channel,_bw,_pri_ch)\
{\
	(_prefer_ch).channel = (_channel);\
	(_prefer_ch).bw = (_bw);\
	(_prefer_ch).primary_ch_idx = (_pri_ch);\
}

#define setup_committed_schdl_info(_pcmt_schdl, pavl_entry, _entry_ctrl)\
{\
	memcpy(&((_pcmt_schdl)->bitmap_ctrl),((pavl_entry)->avlentry_bitmap_ctl),sizeof(u16));\
	(_pcmt_schdl)->bitmap_length = ((pavl_entry)->avlentry_bitmap_len);\
	(_pcmt_schdl)->bitmap = ((pavl_entry)->avlentry_tmbitmap);\
	(_pcmt_schdl)->passoc_avail_entry = (pavl_entry);\
	(_pcmt_schdl)->cmt_schdl_ndc = 0;\
	(_pcmt_schdl)->cmt_schdl_ch_changed = 0;\
	(_pcmt_schdl)->cmt_schdl_potential_ch_provide = 0;\
	(_pcmt_schdl)->cmt_schdl_potential_overall_provide = 0;\
	(_pcmt_schdl)->cmt_schdl_new_faw = 0;\
	(_pcmt_schdl)->cmt_schdl_immutable = 0;\
	if((!((_entry_ctrl).avl_entryctl_tmbitmap_present) && ((_entry_ctrl).avl_entryctl_type == AVAIL_ENTRY_TYPE_POTENTIAL))){\
		(_pcmt_schdl)->bitmap_length = 0;\
		(_pcmt_schdl)->cmt_schdl_potential_overall_provide = 1;\
	}\
}

#define is_pow_of_2(_val) (!((_val) & ((_val)-1)))
#define SLOT_ENTRY_COUNT_LIMIT	20


struct nan_phyinfo_t {
	u8 channel;	// center channel
	u8 bw;
	u8 primary_ch_idx; // pimary channel index
};

struct nan_schdl_qosinfo_t {
	u8 min_time_slot;
	u16 max_latency;
};

struct nan_cmt_schdl_t {
	struct list_head list;

	struct avl_entry_t *passoc_avail_entry;
	struct nan_avl_schdl_entry_t *pfw_schedule;

	struct nan_phyinfo_t  nan_phyinfo;
	struct tm_bitmap_t bitmap_ctrl;

	u8 *bitmap;
	u8  bitmap_length;

	u8 cmt_schdl_ndc : 1;
	u8 cmt_schdl_ch_changed : 1;
	u8 cmt_schdl_potential_ch_provide : 1;
	u8 cmt_schdl_potential_overall_provide : 1;
	u8 cmt_schdl_new_faw : 1;
	u8 cmt_schdl_immutable : 1;
};

struct nan_schdl_entity_t {
	struct list_head list;
	struct __queue cmt_schdl_queue;        /*list of struct nan_cmt_schdl_t, which describe ndc & immutable schedule, sorted by start offset*/

	struct avl_ctrl_t attr_ctrl;
	struct avl_attr_t avail_attr;
	struct dev_cap_t devcap_attr;			/* preserve device capability attribute with dedicated MAP ID*/

	u16 schdl_entity_end_offset;						/* indicate the offset in time map when schedule entry is set as invalid */

	u8 schdl_entity_invalid : 1;
	u8 schdl_entity_ndc_changed  : 1;
	u8 schdl_entity_cmt_avil_changed  : 1;
	u8 schdl_entity_new : 1;
	u8 schdl_entity_potential_avil_provide  : 1;
	u8 schdl_entity_ndc_schdl_exist  : 1;
	u8 schdl_entity_overall_potential_avil_provide  : 1;
};

struct nan_time_slot_t {
	u8  	status; 							/*refer to enum nan_time_map_slot_status*/
	struct nan_phyinfo_t  nan_phyinfo;
	u32 entry_count;
};

struct nan_time_map_condition {
	enum nan_schdl_pattern_e pattern;
	struct nan_phyinfo_t  nan_phyinfo;
	struct nan_schdl_qosinfo_t qos_info;
};

struct nan_avl_schdl_entry_t {
	u32 fw_schedule_id;
	u8 macid;
	struct nan_cmt_schdl_t *pasoc_cmt_schdl;
	u8 used;
};

struct nan_ndc_entry_t {
	struct list_head list;
	u8 ndc_id[ETH_ALEN];
	u32 shared_count;
};

struct nan_schdl_priv_t {
	struct nan_time_slot_t schdl_slots[MAX_NAN_SLOTS_LEN];
	struct nan_time_map_condition schdl_condition;
	struct nan_avl_schdl_entry_t schdl_avl_pool[MAX_NAN_FW_ACT_REQ_NUM];
	struct nan_schdl_qosinfo_t self_qos;
	struct nan_phyinfo_t prefer_ch_24g;
	struct nan_phyinfo_t prefer_ch_5g;
	struct __queue ndc_info_queue;	/* list of struct nan_ndc_entry_t */

	u32 obsolete_fw_schdl_id_map;	/* bitmap of fw_schdl_id to remove in remove_dummy_schedule_entry */
	u32 changing_fw_schdl_id_map;	/* bitmap of fw_schdl_id found by ndc/cmt changed bits in the avail. attri of updating naf */
	u32 period_lb; /* used to keep time map from being divided into many small pieces and cause a longer availability attribute */
	struct avl_entry_t *nan_slot_map_tmp[MAX_NAN_SLOTS_LEN];		/* pre-allocated buffer for nan availability validation, in case of stack overflow*/

	struct avl_attr_t nan_avail_attr;		/* preserve avail attr for schedule negotiation */
	u8 avlattr_seqid;

	u8 schdler_refresh_whole_schdl	: 1;
	u8 schdler_check_potential_schdl	: 1;
	u8 schdler_self_qos_set			: 1;
	u8 schdler_peer_qos_set			: 1;
	u8 schdler_new_schdl_rule_apply	: 1;
	u8 schdler_support_simultaneous_ndp : 1;
	u8 schdler_force_dw_blocked : 1;
};

extern struct nan_schdl_priv_t g_nanschdl_priv;

/* methods for interfacing with data engine*/
inline u8 is_slot_avail(struct nan_time_slot_t *pslots)
{
	if ((pslots->status == SLOT_STATUS_AVAILABLE || pslots->status == SLOT_STATUS_CONDITIONAL_BLOCK) ||
		(pslots->status == SLOT_STATUS_CONDITIONAL_ALLOW && pslots->entry_count < SLOT_ENTRY_COUNT_LIMIT)) {
		return TRUE;
	} else {
		return FALSE;
	}
}

inline u8 get_avail_type(u32 start_offset, u8 flags)
{
	if (g_nanschdl_priv.schdl_slots[start_offset].status == SLOT_STATUS_CHECKED_COND_ALLOW ||
		g_nanschdl_priv.schdl_slots[start_offset].status == SLOT_STATUS_CONDITIONAL_ALLOW) {
		if (g_nanschdl_priv.schdl_slots[start_offset].entry_count) {
			return AVAIL_ENTRY_TYPE_COMMITTED;
		} else {
			return AVAIL_ENTRY_TYPE_COMMITTED | AVAIL_ENTRY_TYPE_POTENTIAL;
		}
	} else if (flags & AVAIL_ENTRY_TYPE_FLAG_ISSUE_SDF) {
		return AVAIL_ENTRY_TYPE_POTENTIAL;
	} else if ((flags & AVAIL_ENTRY_TYPE_FLAG_ISSUE_NAF) && (flags & AVAIL_ENTRY_TYPE_FLAG_NEGO_ONGOING)) {
		return AVAIL_ENTRY_TYPE_CONDITIONAL;
	} else {
		return 0;
	}
}

inline void update_scheduler_period_lower_bound(u32 period, u8 is_force)
{
	/* make sure period meet power of 2*/
	if (period < MIN_NAN_AVAIL_PERIOD || period > MAX_NAN_AVAIL_PERIOD || !is_pow_of_2(period)) {
		return;
	}

	/* if force=FALSE, chose the smaller one to be period_lb */
	if (g_nanschdl_priv.period_lb) {
		g_nanschdl_priv.period_lb = ((is_force == FALSE && g_nanschdl_priv.period_lb > period) || (is_force == TRUE)) ? (period) : (g_nanschdl_priv.period_lb);
	} else {
		g_nanschdl_priv.period_lb = period;
	}
}

/*********************** scheduler ********************************/
void rtw_nan_schdlr_indicate_peer_invalid(struct nan_peer_info_t *ppeer_info, u8 reason_code);
void rtw_nan_schdlr_priv_init(void);
void rtw_nan_schdlr_priv_free(void);
void rtw_nan_schdlr_priv_post_init(void);
void rtw_nan_schdlr_sta_set(u8 iface_type, bool bconnect);
void rtw_nan_schdlr_ap_set(u8 iface_type, u8 status);
u8 rtw_nan_schdlr_set_pause_schedule(u8 iface_type, bool bpause);


/*********************** scheduler entry ********************************/
u32 rtw_nan_schdlr_cmt_schdl_free(struct nan_cmt_schdl_t *pcmt_schdl);
u32 rtw_nan_schdlr_cmt_schdl_free_particular(struct __queue *pcmt_schdl_queue, u8 is_ndc, u8 check_fw_schdl);
struct nan_cmt_schdl_t *rtw_nan_schdlr_cmt_schdl_alloc(struct __queue *pcmt_schdl_queue);
u8 rtw_nan_schdlr_cmt_schdl_create(u8 *schdl_entry_start, u8 *schdl_entry_end, struct nan_schdl_entity_t *pschdl_entity, u8 be_immutable, u8 *fail_reason);
struct nan_schdl_entity_t *rtw_nan_schdlr_entry_alloc(struct nan_peer_info_t *ppeer_info);
struct nan_schdl_entity_t *rtw_nan_schdlr_entry_find_by_mapid(struct __queue *pschdl_entry_queue, u8 mapid);
void rtw_nan_schdlr_cmt_schdl_release(struct nan_peer_info_t *ppeer_info);
u32 rtw_nan_schdlr_entry_all_immutable_free(struct nan_peer_info_t *ppeer_info);
void rtw_nan_schdlr_entry_timeout_free(struct nan_peer_info_t *ppeer_info);
u32 rtw_nan_schdlr_entry_queue_free(struct __queue *pschdl_entry_queue);
u16 rtw_nan_convert_cmt_schdl_to_attr(struct nan_peer_info_t *ppeer_info, u8 *psch_entry_attr, u8 is_ndc);


/*********************** scheduler timemap ********************************/
u8 rtw_nan_slot_beincluded_in_cmtschdl(u16 start_offset, struct nan_cmt_schdl_t *pcmt_schdl);
u8 rtw_nan_slot_check_avail_in_period(u16 start_offset, struct nan_phyinfo_t nan_phyinfo, u16 *duration, struct nan_cmt_schdl_t *pcmt_schdl);
u8 rtw_nan_schdlr_refresh_time_map(void);


/*********************** scheduler ndc ********************************/
struct nan_ndc_entry_t *rtw_nan_ndc_info_exist(u8 *ndc_id);
void rtw_nan_ndc_info_add_new(struct nan_peer_info_t *ppeer_info);
void rtw_nan_ndc_info_del(struct nan_peer_info_t *ppeer_info);


/*********************** scheduler faw ********************************/
u16 rtw_nan_schdl_get_duration_in_cmt_schdl(u16 start_offset, struct nan_cmt_schdl_t *pcmt_schdl);
u32 rtw_nan_schdl_idmap_get(struct __queue *pcmt_schdl_queue, u8 is_ndc);
u8 rtw_nan_schdl_faw_calcu(struct nan_peer_info_t *ppeer_info, struct nan_schdl_entity_t *pschdl_entity);
u32 rtw_nan_schdl_faw_act_add(struct nan_cmt_schdl_t *pcmt_schdl, u32 startoffset, u8 channel_in, u32 duration_in, u32 period_in, u8 macid);
void rtw_nan_schdl_faw_act_remove(u32 fw_schedule_id);
void rtw_nan_schdl_withdraw(u32 id_map);
u16 rtw_nan_schdl_get_start_offset_in_cmt_schdl(struct nan_cmt_schdl_t *pcmt_schdl);

#endif
