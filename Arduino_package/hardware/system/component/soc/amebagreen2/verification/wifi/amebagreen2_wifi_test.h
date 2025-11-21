#ifndef _AMEBAD2_WIFI_TEST_H_
#define _AMEBAD2_WIFI_TEST_H_

struct trigger_common {
	u32 trigger_type: 4;
	u32 ul_len: 12;
	u32 more_tf: 1;
	u32 cs_rqd: 1;
	u32 ul_bw: 2;
	u32 gi_ltf: 2;
	u32 mimo_ltfmode: 1;
	u32 num_heltf: 3;
	u32 ul_stbc: 1;
	u32 ldpc_extra_sym: 1;

	u32 ap_tx_pwr_l: 4; //32bit
	u32 ap_tx_pwr_h: 2;
	u32 pre_fec_padding_factor: 2;
	u32 pe_disambiguity: 1;
	u32 ul_sr: 16;
	u32 doppler: 1;
	u32 ul_siga2_rsvd: 9;
	u32 rsvd: 1;
};

struct trigger_user {
	u32 aid12: 12;
	u32 ru_pos: 8;
	u32 ul_fec_code: 1;
	u32 ul_mcs: 4;
	u32 ul_dcm: 1;
	u32 ss_alloc: 6;
	u16 ul_tgt_rssi: 7;
	u16 rsvd1: 1;
	u16 spacing_factor: 2;
	u16 tid_agg_limit: 3;
	u16 rsvd2: 1;
	u16 pre_ac: 2;
};

struct murts_user {
	u32 aid12: 12;
	u32 ru_pos: 8;
	u32 ul_fec_code: 1;
	u32 ul_mcs: 4;
	u32 ul_dcm: 1;
	u32 ss_alloc: 6;
	u8 ul_tgt_rssi: 7;
	u8 rsvd1: 1;
};

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
	u8 show_beacon;
	u16 show_bytes;
	u8 show_phystatus;
	u64 target_wake_time[5];
	u8 twt_port;
	u8 basic_trx_ac;
	u8 mu_ul_rate_test;
	u32 mu_ul_rate_test_len;
	u8 dcm;
	u8 tx_userate;
	u8 tx_raw;
	u8 retry_limit;
	u8 tx_port_id;
	u8 tx_macid;
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
	u8 ccx;
	u8 rts;
	u8 cts;
	u8 vcs;
	u32 tx_cnt_qos_data;
	u32 tx_raw_cnt_data;
	u32 tx_raw_cnt_mgnt;
	u32 rx_cnt_trigger_bc;
	u32 rx_cnt_trigger_uc;
	u32 rx_cnt_trigger_basic;
	u32 rx_cnt_trigger_bar;
	u32 rx_cnt_trigger_rts;
	u32 rx_cnt_trigger_bfrp;
	u32 rx_cnt_trigger_bsrp;
	u32 rx_cnt_trigger_bqrp;
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
	u8 mba_start;
	u16 mba_aid;
	u8 bitmap_oft;
	u8 bitmap_tim0;
	u8 bitmap_tim1;
	u8 cs_required;

	u8 htc_bsr;
	u8 htc_uph;
	u8 htc_bqr;
	u8 htc_cas;
	u8 htc_ht;
	u8 htc_null;

	u16 partial_aid;
	u8 ack_ch_info;
};

struct tx_rpt_format {
	//offset 0
	u8 tx_polluted: 1;
	u8 tx_state: 4;
	u8 rpt_sel: 3;
	//offset 1
	u8 rpt_qsel: 5;
	u8 collision_head: 1; //for 97G/12F
	u8 collision_tail: 1; //for 97G/12F
	u8 fixed_rate: 1; //driver fixed rate
	//offset 2
	u16 macid: 7;
	//offset 3
	u16 init_rate: 9;
	//offset 4
	u8 ok_num: 6;
	u8 rsvd0: 1;
	u8 try_rate: 1;
	//offset 5
	u8 drop_num: 6;
	u8 bitmap_short: 2;
	//offset 6
	u8 sw_def;
	//offset 7
	u8 rts_rty_count: 4;
	u8 tb_ppdu_flag: 1;
	u8 rts_bmc: 1;
	u8 rx_polluted: 1;
	u8 rsvd2: 1;
	//offset 8
	u16 data_rty_count: 6;
	//offset 9
	u16 final_data_rate: 9;
	u16 rsvd3: 1;
	//offset 10
	u8 rsvd4;
	//offset 11
	u8 rsvd5: 2;
	u8 ch_sc: 4;
	u8 ch_bw: 2;
	//offset 12
	u8 total_cnt: 6; /*total number of MPDU have been transmitted*/
	u8 ppdu_type: 2;
	//offset 13
	u8 zero_retry_pkt_num: 6;
	u8 rsvd: 2;
	//offset 14
	u16 bSR: 1;
	u16 init_data_gi_ltf: 3;
	u16 final_gi_ltf: 3;
	//offset 15
	u16 txpwr_pd: 5;
};

#define RTL8730A_BB_REG_BASE	(WIFI_REG_BASE + 0x10000)

#define TXDESC_BFRP_VHT	1
#define TXDESC_MU_RTS	4
#define TXDESC_BFRP_HE	5
#define TXDESC_TF_OTHER	7
#define NOT_SPECIFIC	0xff


struct _ADAPTER *WifiGetAdapter(void);
void WifiShowRX(u8 *rx_data, struct rx_pkt_attrib	*pattrib, u8 *rx_desc);
void WifiShowTX(u8 *buf1, u32 len1, u8 *buf0, u32 len0);
void WifiTWTTimerIrqHandler(void);
void WifiBasicTrxTest(struct txdesc_priv *ptxdesc);
void WifiTestSetTxdesc(struct txdesc_priv *ptxdesc, struct xmit_frame *pxmitframe);
void WifiIntTest(u32 isr0, u32 isr1, u32 isr2, u32 isr3);
#ifdef CONFIG_CSI
void WifiShowCsiPkt(struct rx_csi_data *csi_pkt);
#endif
void WifiTestSetMacAddr(struct _ADAPTER *padapter);
void WifiTestSetPhyRegPxp(void);
void rtw_relay_xframe(struct _ADAPTER *padapter, u8 *rx_data, struct rx_pkt_attrib *pattrib, u8 ul_relay);
struct xmit_frame *txraw_alloc_xmitframe(u8 iface_type);
void txraw_update_attrib(struct _ADAPTER *padapter, struct pkt_attrib *pattrib, u16 payload_len, u8 acq, u8 encrypt, u8 tx_swap, u8 ul_swap);
int txraw_dump_frame(struct _ADAPTER *padapter, struct xmit_frame *prawframe);
void _ConvertStringToMacAddr(const char *argv[], u8 *mac_addr);
void WifiSetKeyCam(u8 cam_id);
u32 rand_32(u32 min, u32 max);
void WifiTunnel(const char *argv[]);
void WifiCsiCmdHelp(void);
void WifiCsiConfig(u8 *argv[]);
void WifiBcnConfig(u8 *argv[]);
void WifiCmdHelp(void);
int WifiTxData(void);
void WifiGenBaiscTrigger(u8 *pframe, u16 *len_in);
void WifiTxMba(void);
void wifi_audio_show_latch(void);
#endif
