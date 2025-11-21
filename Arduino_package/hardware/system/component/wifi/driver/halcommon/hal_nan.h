#ifndef __HAL_NAN_H__
#define __HAL_NAN_H__

#ifdef CONFIG_NAN

#if defined(CONFIG_AMEBASMART) || defined(CONFIG_AMEBADPLUS) || defined(CONFIG_AMEBAGREEN2) || defined(CONFIG_AMEBASMARTPLUS)
#define NAN_BEACON_SIZE (BCN0_NAN_SYNC_PAGE_NUM * PAGE_SIZE_TX)
#elif defined(CONFIG_AMEBAL2)
#define NAN_BEACON_SIZE 256
#endif

enum nan_rxbcn_ctrl_type_t {
	NAN_RXBCN_CTRL_DW_NORMAL,	// DW for normal case or Sync Device in the same Cluster
	NAN_RXBCN_CTRL_DW_SYNC		// DW for Sync other Cluster
};

enum nan_bcn_attr_e {
	NAN_BCN_ATTR_MIA,		/* master indication attribute */
	NAN_BCN_ATTR_CA,		/* cluster attribute */
	NAN_BCN_ATTR_BSSID,	/* cluster id (A3) */
	NAN_BCN_ATTR_ALL
};

enum nan_dev_state_e {
	NAN_STATE_DISABLE,
	NAN_STATE_INIT,
	NAN_STATE_WARMUP,
	NAN_STATE_SYNC_CLUSTER,
	NAN_STATE_SYNC_DEVICE,
	NAN_STATE_INCLUSTER,
	NAN_STATE_PAUSE
};

enum {
	NAN_CLUSTER_CHANGE_CHECK = BIT0,
	NAN_CLUSTER_PRE_JOIN     = BIT1
};

struct nan_devlist_t {
	u8	dev_interface_addr[ETH_ALEN];
	s8	dev_rssi_dbm;
	u8	count;
	u8	reserved[3];
};

struct nan_counter_t {
	u8    CloCntDurDW;
	u8    MidCntDurDW;
	u8    CloCntToMaster;
	u8    MidCntToMaster;
	u8    CloCntToNonMasterSync;
	u8    MidCntToNonMasterSync;
	u8    SyncRetryCnt;
	u8    DiscBcnCnt;
	u32   DwTimeCnt;
	u32   AmbttChangeTime;
	u32   SmallHopCountTime;
};

struct nan_act_req_t {
	struct list_head         list;               //list for hook onto action req list
	struct list_head         Entrylist;          //list for associated action req entries
};

struct nan_fawinfo_t {
	u8      StartOffset;    /* 16TU unit */
	u8      Duration;       /* 16TU unit */
	u8      Period;         /* 16TU unit min value should be 8*/
	u8      macid;
};

struct nan_fawreq_t {
	struct nan_act_req_t		FAWActReq;
	struct nan_fawinfo_t		FAWInfo;
};

struct nan_dwinfo_t {
	u8 op_channel;	// For tx sync bcn
	u64	src_tsf_val;
	u64 start_time;
	u64 end_time;
	u64 next_start_time;
	u64 start_time_fr;
};

struct nan_pool_t {
	const u8				*start;
	const u8				*end;
	u32					entrySize;
	struct list_head					freeList;
	u32					freeCount;
	u32					cap;
	u32					lowMark;
};

// used as reference for RF resource contention

struct nan_actreq_ref_timeinfo_t {
	u64	src_tsf_val;
	u64	freerun_tsf_val;
	u8	tsf_idx;
};
// prevent src TSF change in the middle of slot

struct nan_act_req_entry_ex {
	struct list_head                    list;                  //bi-direction
	struct nan_phyinfo_t                phy_info;
	struct nan_actreq_ref_timeinfo_t    ref_time_info;
	struct nan_fawreq_t                 *pfaw_req;

	u64	slot_start_time;
	u64	slot_end_time;
	u64	slot_end_time_temp;	/* valid when overlap is set */

	u8 slot_overlap_faw_include_dw : 1;
	u8 slot_overlap_fawend_equal_dwstart : 1;
	u8 slot_overlap_dwend_equal_fawstart : 1;

	u32 act_req_id;           //stay at the bottom, initially assgined
};

struct rtw_nan_ctrl_t {
	struct timer_list warmupTimer;
	struct timer_list joincluster_timer;
	struct timer_list joincluster_end_timer;

	struct nan_phyinfo_t             nanctrl_phy_info[2];
	struct nan_actreq_ref_timeinfo_t nanctrl_ref_timeinfo[2];
	struct rtw_nan_avail_t_bitmap    disc_avail_t_bitmap;

	struct anchor_mast_record_t amr_cur;
	struct anchor_mast_record_t amr_last;
	struct mast_rankinfo_t      master_rankinfo;
	struct nan_devlist_t        device_list[NAN_DEVICE_LIST_LIMIT_DMEM];

	struct nan_counter_t    nanctrl_counter;
	struct nanctrl_para_t   nanctrl_info;
	struct nan_dwinfo_t     dw_info;
	struct nan_fawreq_t     *faw_req;

	enum nan_dev_state_e dev_state_last; // NAN Last State
	enum nan_dev_state_e dev_state_cur; // NAN Current State
	enum nan_dev_role_e  dev_role;

	struct nan_act_req_entry_ex     act_req_ext_array[MAX_ACTION_REQUEST_ENTRY_NUM];
	struct nan_pool_t               act_req_ext_pool;
	struct __queue                  act_req_list;
	u64 mstrank_bcn;
	u64 act_slot_time;
	u32 act_slot_entry_id;

	u8 clusterid[ETH_ALEN];
	u8 clusterid_to_sync[ETH_ALEN];
	u8 target_ta_to_sync[ETH_ALEN];

	u8 apinfo_bssid[ETH_ALEN];
	u8 apinfo_macid[ETH_ALEN];
	u8 apinfo_macid_start;
	u8 apinfo_macid_end;

	u64 joincluster_src_tsf_val;
	u64 joincluster_start_time;
	u64 joincluster_end_time;

	u32 faw_pause_idmap;
	u32 ambtt_of_prev_dw;
	u64 tsf_current; /* current port tsf in NAN_RxNanBcnHandler */
	u64 tsf_disc_start;
	u32 disc_bcn_interval;	//unit: us

	u8 ch_cluster;	// For Join and Merge Cluster
	u8 ch_disc;	// For tx disc bcn
	u8 ch_sta;
	u8 ch_ap;
	u8 ch_current;
	u8 ch_target_ta;	/* used in dual-band device to sync with single-band device */
	u8 faw_req_cnt;

	u8 cmt_dw_2g4 : 3;  /* Wake up every 2^(n-1) */
	u8 cmt_dw_5g : 3;   /* Wake up every 2^(n-1) */
	u8 cmt_dw_rsvd : 2;
	u8 cmt_dw_overwrite2g4 : 4;
	u8 cmt_dw_overwrite5g : 4;

	u8 nanctrl_refresh_bcn_req : 1;
	u8 nanctrl_ready_to_sync : 1; // can be deleted?
	u8 nanctrl_sync_cluster_success : 1;
	u8 nanctrl_notify_drv_join : 1; // can be deleted? no need to handshake with driver
	u8 nanctrl_in_oneshot_dw : 1;
	u8 nanctrl_propagation : 1;
	u8 nanctrl_disc_bcn_suppression : 1;
	u8 nanctrl_in_dw : 1;
	u8 nanctrl_changing_role_clus : 1;
	u8 nanctrl_act_pause : 1;
	u8 nanctrl_sta_mode_add : 1;
	u8 nanctrl_ap_mode_add : 1;
	u8 nanctrl_port0_used_for_nan : 1;
	u8 nanctrl_dw_end_early : 1;
};

#define IS_CURRENT_ROLE_MASTER(_Role) (_Role == NAN_ROLE_MASTER || _Role == NAN_ROLE_ANCHOR_MASTER)

__STATIC_INLINE bool pool_OnBoundary(const struct nan_pool_t *pool, const void *entry)
{
	bool	bOnBoundary = FALSE;

	do {
		if ((pool->end <= (u8 *)entry) || ((u8 *)entry < pool->start) || (((u8 *)entry - pool->start) % pool->entrySize)) {
			break;
		}

		bOnBoundary = TRUE;
	} while (FALSE);

	return bOnBoundary;
}

__STATIC_INLINE u8 wifi_hal_nan_cluster_cg_compare(u64 bcn_tsf, struct anchor_mast_record_t *pamr_bcn)
{
	if ((pamr_bcn->amr_amr >> 56) > (g_nanctrl.amr_cur.amr_amr >> 56)) {
		return TRUE;
	} else if ((pamr_bcn->amr_amr >> 56) == (g_nanctrl.amr_cur.amr_amr >> 56)) {
		/* same master pref of anchor master, compare tsf */
		if ((bcn_tsf >> 19) > (g_nanctrl.tsf_current >> 19)) {
			return TRUE;
		} else if ((bcn_tsf >> 19) == (g_nanctrl.tsf_current >> 19)) {
			/* same CG, compare AMR */
			if (pamr_bcn->amr_amr > g_nanctrl.amr_cur.amr_amr) {
				return TRUE;
			}
		}
	}
	return FALSE;
}

/******************************** struct nan_pool_t DECLARATION **************************************/
void Pool_Init(struct nan_pool_t	*pool, u32 buflen, void *buf, u32 entrySize);
void *Pool_Acquire(struct nan_pool_t *pool);
void Pool_Release(struct nan_pool_t *pool, void *entry);

/******************************** COMMON FUNCTION ABOUT NAN SYNC DECLARATION **************************************/


void rtw_nan_disc_early_hdl(void);
void rtw_nan_disc_end_hdl(void);




void rtw_nan_avail_t_bitmap_disc_bcn_profile_mode_check(void);
void wifi_hal_nan_update_tsf_sync(u8 enable);

/******************************** MAC FUNCTION DECLARATION **************************************/
void wifi_hal_nan_5g_enable(u8 enable);
void wifi_hal_nan_tsf_sync(u8 enable);
void wifi_hal_nan_check_ta_bcn_for_sync(u8 enable);
u32 wifi_hal_nan_check_ta_bcn_for_sync_status(void);
u64 wifi_hal_nan_p2_backup_tsf_get(void);
void wifi_hal_nan_set_ta_to_sync(void);
extern u8 wifi_hal_nan_get_bcn_early(u8 bcn_type);
extern void wifi_hal_nan_update_dw_tsf(u32 offset);
extern void wifi_hal_nan_role_set(u8 role);
extern void wifi_hal_nan_polling_bcn(u8 port);
extern void wifi_hal_nan_bcn_tx_stop(void);
extern void wifi_hal_nan_bcn_tx_start(u8 bcnType);
extern void wifi_hal_nan_bcn_content_update(enum nan_bcn_attr_e attrId);
extern void wifi_hal_nan_bcn_interval_update(u8 bcn_type, u16 interval);
extern void wifi_hal_nan_bcn_ctrl(u8 bcn_type, u8 enable);
extern void wifi_hal_nan_set_sdf_tx(u8 option);
extern void wifi_hal_nan_concurrent_port0_set(u8 option);
extern void wifi_hal_nan_bcn_tx_init(void);
extern void wifi_hal_nan_macid_pause(u8 macid);
extern void wifi_hal_nan_macid_release(u8 macid);

extern void wifi_hal_nan_bcn_bssid_check(u8 enable);
extern void wifi_hal_nan_data_bssid_check(u8 enable);

/***************** COMMON FUNCTION DECLARATION, INDEPENDENT IMPLEMENTATION **********************/
extern void wifi_hal_nan_interrupt_handle(void);
void wifi_hal_nan_beacon_xmit_init(void);
void wifi_hal_nan_beacon_xmit_deinit(void);
void wifi_hal_nan_beacon_buffer_update(u8 alloc, u8 nan_bcn_type);
void wifi_hal_nan_beacon_xmit(u8 *data, u32 data_len, u8 nan_bcn_type, u8 macid);
void wifi_hal_nan_beacon_head_update(void);

/******************************** FAW FUNCTION DECLARATION **************************************/
void wifi_hal_nan_faw_schdl_init(void);
void wifi_hal_nan_faw_schdl_deinit(void);
struct nan_act_req_entry_ex *wifi_hal_nan_faw_entry_search(struct nan_act_req_entry_ex *pact_req_ex_skip);
void wifi_hal_nan_faw_schdl_update(struct nan_act_req_entry_ex *pact_req_ex_skip);
void wifi_hal_nan_action_req_dequeue(struct nan_act_req_t *pact_req);
void wifi_hal_nan_faw_entry_pause(void);
u32 wifi_hal_nan_faw_eventhdl(struct nan_act_req_entry_ex *Entry, u64 portTsf, struct nan_act_req_entry_ex **ppact_req_ex_next);
u8 wifi_hal_nan_faw_exist_check(void);
void wifi_hal_nan_faw_pstimer_hdl(void);
u8 wifi_hal_nan_action_entry_acquire_from_pool(struct nan_act_req_t *pact_req);
void wifi_hal_nan_action_entry_release_to_pool(struct nan_act_req_t *pact_req);
void wifi_hal_nan_faw_entry_update(struct nan_act_req_entry_ex *pact_req_ex, u8 bUpdate);

/******************************** CONCURRENT FUNCTION DECLARATION **************************************/
void wifi_hal_nan_concurrent_port0_switch(u8 mode);
void rtw_nan_concurrent_infra_mode_leave_check(struct nan_act_req_entry_ex *pact_req_ex);
u64 rtw_nan_concurrent_schedule_check(u64 cur_tsf);
void rtw_nan_concurrent_infra_mode_enter_check(void);
void rtw_nan_concurrent_sta_mode_enter(void);
void rtw_nan_concurrent_sta_mode_leave(void);
void rtw_nan_concurrent_ap_mode_enter(void);
void rtw_nan_concurrent_ap_mode_leave(void);
u8 wifi_hal_nan_concurrent_schedule_check(void);
void wifi_hal_nan_concurrent_port1_switch(u8 mode);

/******************************** API ABOUT INTERFACE TO UPPER LAYER DECLARATION **************************************/

void wifi_hal_nan_set_nanmode(u8 enable);

u8 wifi_hal_nan_get_cluster_info(void);
u8 wifi_hal_nan_send_bcns(u8 nan_macid, struct rtw_bcn_info *nan_sync_bcn, struct rtw_bcn_info *nan_disc_bcn);
u8 wifi_hal_nan_func_ctrl(struct nanctrl_para_t *nan_option);
void wifi_hal_nan_act_schedule_sta(u8 options, u8 bw, u8 channel, u8 primary_ch_idx);
void wifi_hal_nan_act_schedule_ap(u8 iface_type, u8 options, u8 bw, u8 channel, u8 primary_ch_idx, u8 macid_start, u8 macid_end);
void wifi_hal_nan_act_schedule_pause(u8 iface_type, u8 options);
#endif

void wifi_hal_nan_evtq_update_early_time(void);
void wifi_hal_nan_evtq_update_head(u8 page_num);
void wifi_hal_nan_evtq_polling(void);
#endif//__HAL_NAN_H__
