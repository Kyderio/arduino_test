#ifndef __RTW_CLUSTER_H_
#define __RTW_CLUSTER_H_

void rtw_nan_cluster_join_timer_hdl(void *ctx);
void rtw_nan_cluster_join_end_timer_hdl(void *ctx);
void rtw_nan_cluster_join_start(u8 bcn_channel, u8 *pbcn_clusterid, u64 bcn_tsf, struct anchor_mast_record_t *pamr_bcn);
void rtw_nan_cluster_operation(u8 type);

#endif /* __RTW_CLUSTER_H_ */