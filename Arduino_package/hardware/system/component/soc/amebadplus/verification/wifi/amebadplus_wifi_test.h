#ifndef _AMEBALITE_WIFI_TEST_H_
#define _AMEBALITE_WIFI_TEST_H_

struct ampdu_delimiter {
	u32 eof: 1;
	u32 rsvd: 1;
	u32 len: 14;
	u32 crc: 8;
	u32 signature: 8;
};

struct wifi_test_para_t {
	u8 show_rx_desc;
	u8 show_tx_desc;
	u8 show_rx;
	u8 show_tx;
	u16 show_bytes;
	u8 show_beacon;
	u8 show_phystatus;
	u64 target_wake_time[5];
	u8 twt_port;
	u8 basic_trx_ac;
	u8 dcm;
	u8 er;
	u8 er_bw;
	u8 bw;
	u8 ldpc;
	u8 contious_tx;
	u8 ctx_nodelay;
	u16 acq;
	u16 payload_len;
	u16 rate;
	u8 len_rand;
	u8 rate_rand;
	u8 rate_type; /*0: all rate rand; 1:cck ofdm; 2: ht; 3:vht; 4:he */
	u32 tx_cnt_data;
	u32 tx_cnt_mgnt;
	u32 rx_cnt_trigger_bc;
	u32 rx_cnt_trigger_uc;
	u32 rx_cnt_trigger_basic;
	u32 rx_cnt_trigger_bar;
	u32 rx_cnt_trigger_rts;
	u32 rx_cnt_data;
	u32 rx_cnt_data_rty;
	u32 rx_cnt_qos_data;
	u32 rx_cnt_qos_data_rty;
	u32 rx_cnt_mgnt;
	rtos_sema_t dfs_int;
	u8 tp_rx_start;
	u32 tp_rx_last_time;
	u64 tp_rx_last_time_tsft;
	u32 tp_rx_size;
	u32 tp_rx_size_tsft;
	u8 trx_pldchk_start;
	u8 mba_bc;
	u8 mba_type;
	u8 mba_tid;
	u8 mba_user;
	u16 mba_aid;
	u8 bitmap_oft;
	u8 bitmap_tim0;
	u8 bitmap_tim1;
};

#define RTL8721F_BB_REG_BASE	WIFI_REG_BASE

#define TXDESC_BFRP_VHT	1
#define TXDESC_MU_RTS	4
#define TXDESC_BFRP_HE	5
#define TXDESC_TF_OTHER	7
#define NOT_SPECIFIC	0xff

void WifiCmdHelp(void);
void WifiCsiCmdHelp(void);
void WifiShowRX(u8 *rx_data, struct rx_pkt_attrib	*pattrib, u8 *rx_desc);
void WifiShowTX(u8 *buf1, u32 len1, u8 *buf0, u32 len0);
void WifiTWTTimerIrqHandler(u32 isr, u32 isr1);
void WifiBasicTrxTest(struct txdesc_priv *ptxdesc);
void WifiTestSetTxdesc(struct txdesc_priv *ptxdesc, struct xmit_frame *pxmitframe);
void WifiDfsIrqHandler(u32 isr);
#ifdef CONFIG_CSI
void WifiShowCsiPkt(struct rx_csi_data *csi_pkt);
#endif
void WifiTestSetMacAddr(struct _ADAPTER *padapter);
#endif
