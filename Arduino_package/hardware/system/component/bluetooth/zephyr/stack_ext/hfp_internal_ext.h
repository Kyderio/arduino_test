/*
*******************************************************************************
* Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
*******************************************************************************
*/

#define HFP_XAPL_FEAT_BIT_BATTERY_REPORT        1
#define HFP_XAPL_FEAT_BIT_DOC_OR_POWERED        2
#define HFP_XAPL_FEAT_BIT_SIRI_STATUS_REPORT    3
#define HFP_XAPL_FEAT_BIT_NR_STATUS_REPORT      4

#define HFP_XAPL_VENDOR_ID    0x005D
#define HFP_XAPL_PRODUCT_ID   0x8763
#define HFP_XAPL_VERSION      0x1
#define HFP_XAPL_SUPPORTED_FEATURE          (1 << HFP_XAPL_FEAT_BIT_BATTERY_REPORT)

static int clip_finish(struct at_client *hf_at, enum at_result result, enum at_cme cme_err);

static int clip_handle(struct at_client *hf_at);

static int vgm_handle(struct at_client *hf_at);

static int vgs_handle(struct at_client *hf_at);

static void hfp_hf_sco_recv(struct bt_sco_chan *chan, struct net_buf *buf);

static int bt_hfp_hf_sco_accept(const struct bt_sco_accept_info *info,
		      struct bt_sco_chan **chan);