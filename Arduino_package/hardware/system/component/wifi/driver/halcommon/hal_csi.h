/******************************************************************************
 *
 * Copyright(c)2019 Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 *****************************************************************************/
#ifndef __HAL_CSI_H__
#define __HAL_CSI_H__

#ifdef CONFIG_CSI

#define CSI_SUPPORT_MAX_NUM_STA      5
#define CSI_MAX_SIZE                 1024  /* max_tone * 2 * 2 = 242 * 4 = 968 */
#define CSI_PKT_TOTAL                1
#define CSI_REPORT_DONE_TIMEOUT      3  /* ms */
#define CSI_BB_BLOCK_SZ              (10 * 128)
#define CSI_BB_BLOCK_NUM             2

enum csi_parsing_status {
	CSI_PARSE_SUCCESS = 0,   /* 0 */
	CSI_PARSE_FAILURE = 1,   /* 1 */
	CSI_PARSE_LAST_SEG = 13, /* 13 */
};

struct rtw_csi_bbcr_cfg {
	u8 b_csi_wl_opt : 1; /* 0:S(8,4); 1:S(16,12) */
	u8 b_csi_type : 1; /* 0:legacy channel; 1:mimo channel */
	u8 b_csi_alg_opt : 1;  /* 0:LS(channel estimation); 1:CS(channel smoothing) */
	u8 b_csi_ch_opt : 1;  /* 0:legacy portion; 1:no-legacy portion */
	u32 csi_ele_bitmap;
	u8 csi_grp_num_non_he;  /* 0:per tone; 1:per 2tone; 2:per 4tone; 3:per 16tone */
	u8 csi_grp_num_he;
	u8 csi_seg_len;  /* 0:12(96bytes); 1:28(224bytes);2:60(480bytes);3:124(992bytes) */
	u8 csi_blk_start_idx;
	u8 csi_blk_end_idx;
};

struct rtw_csi_rpt_hdr_info {
	u32 total_len;    /* header(16byte) + Raw data length(Unit: byte) */
	u8 total_seg_num;
	bool is_pkt_end;
	bool set_valid;
	u8 avg_noise_pow;
	u8 nr;
	u8 nc;
	u8 segment_size;  /* unit (8Bytes) */
	s8 sts0_evm;      /* db */
	u8 sequence_number;
};

struct rtw_csi_phyinfo_rpt {
	s8 rssi[2];  /* dbm */
	s8 sts1_evm; /* db */
	u8 rxsc;
	u8 rssi_avg;
};

struct rtw_csi_drv_rpt {
	u32 raw_data_len;
	u8 seg_idx_curr;
};

struct rtw_csi_desc {
	u8 rx_bw;
	u16 csi_length;
	u16 rx_rate;
	u32 r_rx_tsfl;
	u8 txrptmid_srch;
	u8 frag_num;
};

struct rx_csi_data {
	struct list_head list;
	u8 *csi_buffer;
	u32 length;
	struct rtw_event_csi_report_info csi_rpt_info;
};

struct rx_csi_pool {
	struct rx_csi_data csi_pkt[CSI_PKT_TOTAL];
	struct list_head idle;
	struct list_head busy;
	u32 idle_cnt;
	u32 busy_cnt;
};

struct rx_csi_sta_info {
	u32 rx_csi_cnt;
	u8 mac_addr[6];
	u8 flag_id;  /* macid in softap and input_flag in sta mode */
	u8 csi_en : 1;
};
struct csi_priv {
	struct rx_csi_pool *csi_pool;  /* csi buffer pool */
	struct rx_csi_data *handing_buf;  /* handing csi packet */
	rtos_mutex_t csi_queue_mutex;  /* mutex */
	struct rx_csi_sta_info csi_sta[CSI_SUPPORT_MAX_NUM_STA];
	u16 per_macid_csi_en;  /* latch per sta csi en or dis, bitx indicate macid=x*/
	u8 num_csi_sta;  /* record the number of sta which en csi*/
	u8 num_bit_per_tone;
	u8 b_csi_handle_flag : 1; /* 0: wait new csi; 1: handling curr csi */
	u8 b_csi_ch_opt: 1;  /* record ch_opt for getting num_tone for csi header */
	u8 csi_grp_num: 3;  /* record group_num for getting num_tone for csi header */
};

void wifi_hal_csi_en_by_user(u8 *csi_en_by_user);
void wifi_hal_csi_deinit(struct csi_priv *pcsipriv);
s32 wifi_hal_csi_en(struct rtw_csi_action_parm *act_param);
void wifi_hal_csi_pkt_hdl(u8 *buf, struct rtw_csi_desc *csi_desc);
s32 wifi_hal_csi_cfg(struct rtw_csi_action_parm *act_param);

#ifdef CONFIG_AMEBADPLUS
void rtw_hal_mac_update_mac_address(u8 mac_id, u8 *mac_addr);
#endif
#endif /* CONFIG_CSI */

#endif /* __HAL_CSI_H__ */
