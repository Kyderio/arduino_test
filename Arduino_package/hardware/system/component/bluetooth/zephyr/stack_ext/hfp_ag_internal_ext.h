/*
*******************************************************************************
* Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
*******************************************************************************
*/

static int bt_hfp_ag_xapl_handler(struct bt_hfp_ag *ag, struct net_buf *buf);

static int bt_hfp_ag_iphoneaccev_handler(struct bt_hfp_ag *ag, struct net_buf *buf);

static int bt_hfp_ag_vgs_handler(struct bt_hfp_ag *ag, struct net_buf *buf);

static int bt_hfp_ag_vgm_handler(struct bt_hfp_ag *ag, struct net_buf *buf);

static void hfp_ag_sco_recv(struct bt_sco_chan *chan, struct net_buf *buf);

static void bt_hfp_ag_outgoing_call_cancel(struct bt_hfp_ag *ag, void *user_data);