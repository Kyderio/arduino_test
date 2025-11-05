#ifndef _AMEBAX_WIFI_TEST_H_
#define _AMEBAX_WIFI_TEST_H_
#include "ameba_soc.h"
#include "wifi_hal.h"

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
	u8 show_txbd;
	u8 show_rx;
	u8 show_tx;
	u16 show_bytes;
	u8 show_beacon;
	u8 show_phystatus;
	u8 phystatus_check;
	u8 show_csi;
	u8 show_csi_all;
	u8 show_radar;
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
	u8 data_gi;
	u8 txrpt;
	u8 rts;
	u8 cts;
	u8 vcs;
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
	u32 rx_cnt_csi;
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

	u8 htc_bsr;
	u8 htc_uph;
	u8 htc_bqr;
	u8 htc_cas;
	u8 htc_ht;
	u8 htc_null;

	u16 partial_aid;
	u8 ack_ch_info;

	u8 macid;
	u8 key_idx;

	u8 agg_num;

	u8 data_rate;
	u8 rts_rate;
	u8 data_rate_rty_lmt;
	u8 rts_rate_rty_lmt;
	u8 rty_use_des;
	u8 highest_rate;
	u8 use_rate;
	u8 dis_retry_drop;

	u8 enable_datafb;
	u8 enable_rtsfb;

	u8 ack_rssi;

	u8 raw;
	u8 signaling_ta;
	u8 mu_ul_rate_test;

	u8 tx_swap;
	u8 ul_swap;

	u8 random_tx;
	u8 random_qsel;

	u8 mu_edca_test;
};

struct wifi_ra_para_t {
	u8 data_rate;
	u8 data_rate_rty_lmt;
	u8 rts_rate_rty_lmt;
	u8 data_lowest_rate;
	u8 norminal_pkt_padding;
	u8 ofdma_force_rts;
	u8 ht_force_rts;

};

#define RTL8721F_BB_REG_BASE	WIFI_REG_BASE

#define TXDESC_BFRP_VHT	1
#define TXDESC_MU_RTS	4
#define TXDESC_BFRP_HE	5
#define TXDESC_TF_OTHER	7
#define NOT_SPECIFIC	0xff

extern struct wifi_test_para_t wpara;
extern u8 Addr1[6];
extern u8 Addr2[6];
extern u8 Addr3[6];
extern u8 tm_latch;
extern u8 to_ds;

inline void print_buf(char *name, unsigned char *buf, int len)
{
	RTK_LOGS(NOTAG, RTK_LOG_ALWAYS, "======%s=======", name);
	for (int i = 0; i < len; i++) {
		if (i % 16 == 0) {
			RTK_LOGS(NOTAG, RTK_LOG_ALWAYS, "\r\n");
		}
		RTK_LOGS(NOTAG, RTK_LOG_ALWAYS, "%02x ", buf[i]);
	}

	RTK_LOGS(NOTAG, RTK_LOG_ALWAYS, "\r\n");
}

/************************** TXRPT PARSE *************************************/
#define GET_TXRPT_CW_TIME(__pTxRpt)		LE_BITS_TO_4BYTE( __pTxRpt, 0, 7)
#define GET_TXRPT_TOTAL_PKT_NUM(__pTxRpt)		LE_BITS_TO_4BYTE( __pTxRpt, 7, 4)
#define GET_TXRPT_DATA_RETRY_COUNT(__pTxRpt)		LE_BITS_TO_4BYTE( __pTxRpt, 11, 6)
#define GET_TXRPT_OK_PKT_NUM(__pTxRpt)		LE_BITS_TO_4BYTE( __pTxRpt, 17, 4)
#define GET_TXRPT_DROP_PKT_NUM(__pTxRpt)		LE_BITS_TO_4BYTE( __pTxRpt, 21, 4)
#define GET_TXRPT_MACID(__pTxRpt)		LE_BITS_TO_4BYTE( __pTxRpt, 25, 6)
#define GET_TXRPT_PULLUTED(__pTxRpt)		LE_BITS_TO_4BYTE( __pTxRpt, 31, 1)

#define GET_TXRPT_FIX_RATE(__pTxRpt)		LE_BITS_TO_4BYTE( __pTxRpt, 0, 1)
#define GET_TXRPT_INIT_BW(__pTxRpt)		LE_BITS_TO_4BYTE( __pTxRpt, 1, 1)
#define GET_TXRPT_FINAL_BW(__pTxRpt)		LE_BITS_TO_4BYTE( __pTxRpt, 2, 1)
#define GET_TXRPT_ACK_RSSI(__pTxRpt)		LE_BITS_TO_4BYTE( __pTxRpt, 3, 8)
#define GET_TXRPT_ACK_RSSI_VALID(__pTxRpt)		LE_BITS_TO_4BYTE( __pTxRpt, 11, 1)
#define GET_TXRPT_SWDEF(__pTxRpt)		LE_BITS_TO_4BYTE( __pTxRpt, 12, 8)
#define GET_TXRPT_INIT_DATARATE(__pTxRpt)		LE_BITS_TO_4BYTE( __pTxRpt, 20, 6)
#define GET_TXRPT_FINAL_DATARATE(__pTxRpt)		LE_BITS_TO_4BYTE( __pTxRpt, 26, 6)

/************************** TXDESC PARSE *************************************/
// Dword 0, offset0
#define GET_TX_DESC_PKT_SIZE(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc, 0, 12)
#define GET_TX_DESC_OFFSET(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc, 12, 4)
#define GET_TX_DESC_MACID(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc, 16, 7)
#define GET_TX_DESC_QUEUE_SEL(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc, 23, 4)
#define GET_TX_DESC_BMC(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc, 30, 1)

// Dword 1, offset 4
#define GET_TX_DESC_PAID(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc+4, 0,  9)
#define GET_TX_DESC_NDPA(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc+4, 9, 2)
#define GET_TX_DESC_SEC_TYPE(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+4, 20, 4)

// Dword 2, offset 8
#define GET_TX_DESC_RTS_RATE(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+8, 16, 6)

// Dword 3, offset 12
#define GET_TX_DESC_TX_RATE(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+12, 0, 6)
#define GET_TX_DESC_DATA_BW(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+12, 9, 1)
#define GET_TX_DESC_AGG_ENABLE(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+12, 12, 1)
#define GET_TX_DESC_HWSEQ_EN(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+12, 19, 1)
#define GET_TX_DESC_SEQ(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc+12, 20, 12)

// Dword 4, offset 16
#define GET_TX_DESC_USE_RATE(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc+16, 3, 1)
#define GET_TX_DESC_NAV_USE_HDR(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc+16, 4, 1)
#define GET_TX_DESC_AGG_BREAK(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc+16, 6, 1)
#define GET_TX_DESC_DATA_RETRY_LIMIT(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+16, 12, 4)
#define GET_TX_DESC_HTC(__pTxDesc)			LE_BITS_TO_4BYTE(__pTxDesc+16, 22, 1)
#define GET_TX_DESC_SW_DEFINE(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc+16, 24, 8)

// Dword 5, offset 20
#define GET_TX_DESC_DATA_LDPC(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+20, 8, 1)
#define GET_TX_DESC_RTS_SHORT(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+20, 11, 1)
#define GET_TX_DESC_DISABLE_RTS_FB(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+20, 18, 1)
#define GET_TX_DESC_DISABLE_FB(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+20, 19, 1)
#define GET_TX_DESC_HWSEQ_SEL(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+20, 20, 2)
#define GET_TX_DESC_AMPDU_DENSITY(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+20, 26, 3)

// Dword 6, offset 24
#define GET_TX_DESC_CTS2SELF(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+24, 0, 1)
#define GET_TX_DESC_RTS_ENABLE(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+24, 1, 1)
#define GET_TX_DESC_HW_RTS_ENABLE(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+24, 2, 1)
#define GET_TX_DESC_RAW(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc+24, 3, 1)
#define GET_TX_DESC_CCA_RTS(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+24, 9, 2)
#define GET_TX_DESC_PIFS(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc+24, 11, 1)
#define GET_TX_DESC_MAX_AGG_NUM(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+24, 12, 5)


/************************** CSI BB header *************************************/
// Dword 0, offset0
#define GET_CSI_BBHDR_TOTAL_LEN(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc, 0, 17)
#define GET_CSI_BBHDR_TOTAL_SEG_NUM(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc, 17, 7)
#define GET_CSI_BBHDR_NOISE_POWER(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc, 24, 8)

// Dword 1, offset 4
#define GET_CSI_BBHDR_PKT_END(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+4, 0, 1)
#define GET_CSI_BBHDR_SETTING_VALID(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc+4, 1,  1)
#define GET_CSI_BBHDR_NC(__pTxDesc)				LE_BITS_TO_4BYTE(__pTxDesc+4, 2, 3)
#define GET_CSI_BBHDR_NR(__pTxDesc)			LE_BITS_TO_4BYTE(__pTxDesc+4, 5, 3)
#define GET_CSI_BBHDR_SEG_LEN(__pTxDesc)			LE_BITS_TO_4BYTE(__pTxDesc+4, 8, 8)
#define GET_CSI_BBHDR_EVM(__pTxDesc)			LE_BITS_TO_4BYTE(__pTxDesc+4, 16, 8)
#define GET_CSI_BBHDR_SEQ_NUM(__pTxDesc)			LE_BITS_TO_4BYTE(__pTxDesc+4, 24, 8)

/************************** CSI PHYINFO *************************************/
// Dword 0, offset0
#define GET_CSI_PHYINFO_RSSI0(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc, 0, 8)
#define GET_CSI_PHYINFO_RSSI1(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc, 8, 8)
#define GET_CSI_PHYINFO_AMP(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc, 16, 11)
#define GET_CSI_PHYINFO_POP_IDX(__pTxDesc)		LE_BITS_TO_4BYTE(__pTxDesc, 27, 2)

// Dword 1, offset 4
#define GET_CSI_PHYINFO_RSSI_AVG(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+4, 0, 8)
#define GET_CSI_PHYINFO_RXSC(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+4, 8, 4)
#define GET_CSI_PHYINFO_STS1_EVM(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+4, 12, 8)
#define GET_CSI_PHYINFO_T_OFF(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+4, 20, 12)


/************************** PHYSTS *************************************/
#define GET_PHYSTS_HEADER(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc, 0, 16)
#define GET_PHYSTS_RSSI_TD(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc, 16, 8)
#define GET_PHYSTS_RSSI_FD(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc, 24, 8)

#define GET_PHYSTS_ANT_IDX(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+4, 0, 3)
#define GET_PHYSTS_RF_GAIN_IDX(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+4, 3, 8)
#define GET_PHYSTS_EVM(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+4, 11, 8)
#define GET_PHYSTS_CH_IDX(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+4, 19, 8)
#define GET_PHYSTS_RXSC(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+4, 27, 4)
#define GET_PHYSTS_IS_PKT_END(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+4, 31, 1)

#define GET_PHYSTS_CFO(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+8, 0, 12)
#define GET_PHYSTS_AVG_NOISE_PWR(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+8, 12, 8)
#define GET_PHYSTS_RPL(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+8, 20, 9)
#define GET_PHYSTS_BW_IDX(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+8, 29, 3)

#define GET_PHYSTS_SNR_LGY(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+12, 0, 6)
#define GET_PHYSTS_POP_IDX(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+12, 6, 2)
#define GET_PHYSTS_DC_EST_RE(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+12, 8, 8)
#define GET_PHYSTS_DC_EST_IM(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+12, 16, 8)
#define GET_PHYSTS_RF_TIA_GAIN(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+12, 24, 1)
#define GET_PHYSTS_TIA_SHRINK(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+12, 25, 1)
#define GET_PHYSTS_PDP(__pTxDesc)	LE_BITS_TO_4BYTE(__pTxDesc+12, 26, 6)

/************************** DRIVER API *************************************/
extern int wifi_set_ips_internal(u8 enable);
extern void WifiTestSetTxdesc(struct txdesc_priv *ptxdesc, struct xmit_frame *pxmitframe);
extern void WifiRandomTestSetTxdesc(struct txdesc_priv *ptxdesc);
extern void WifiDynamicTest(void);

/************************** BASIC *************************************/
extern u32 _rand_32(u32 min, u32 max);
extern void _ConvertStringToMacAddr(const char  *argv[], u8 *mac_addr);
extern void WifiTestSetMacAddr(struct _ADAPTER *padapter, u8 mac);
extern void WifiCmdHelp(void);
extern struct xmit_frame *txraw_alloc_xmitframe(u8 iface_type);
extern void txraw_update_attrib(struct pkt_attrib *pattrib, u16 payload_len, u8 acq, u8 encrypt);
extern int txraw_dump_frame(u8 iface_type, struct xmit_frame *prawframe);
extern void WifiTestSetPhyRegPxp(void);

/************************** TRX *************************************/
int WifiTxData(void);
void WifiShowRX(u8 *rx_data, struct rx_pkt_attrib	*pattrib, u8 *rx_desc);
void WifiShowTX(u8 *buf1, u32 len1, u8 *buf0, u32 len0);
void WifiBasicTrxTest(struct txdesc_priv *ptxdesc);
void WifiRxTest(u8 *pframe, u32 pframe_len, struct rx_pkt_attrib *pattrib, u8 *rx_desc);

/************************** LBK *************************************/
extern void WifiLbkTestApp(u8  *argv[]);

/************************** TWT *************************************/
#ifdef CONFIG_TWT
extern void WifiTWTTimerTest(u8  *argv[]);
extern void WifiTWTTimerIrqHandler(void);
#endif

/************************** NAN *************************************/
#ifdef CONFIG_NAN
extern void WifiNANTest(u8  *argv[]);
extern void rtw_nan_faw_del(u32 fw_schedule_id);
extern void rtw_nan_faw_add(u32 startoffset, u32 duration, u32 period, u8 channel);
extern void nan_interrupt_handle(void);
#endif

/************************** CSI *************************************/
#ifdef CONFIG_CSI
extern void WifiCsiRaw(u8  *argv[]);
extern void WifiShowCsiPkt(struct rx_csi_data *csi_pkt);
#endif
#ifdef CONFIG_RADAR
extern void WifiRadarRaw(u8  *argv[]);
#endif

/************************** TUNNEL *************************************/
void WifiSetKeyCam(u8 macid);
void WifiRelay(u8  *argv[]);
int tunnel_rx_process(u8 *rx_desc, union recv_frame *precvframe);

/************************** TM *************************************/
void WifiTM(u8  *argv[]);
void WifiTMIrqHandler(void);

/************************** TWT *************************************/
void WifiTWTTimerTest(u8  *argv[]);
void WifiTWTTimerIrqHandler(void);

/************************** RA *************************************/
void WifiRa(u8  *argv[]);

/************************** BOOSTER *************************************/
void WifiBooster(u8  *argv[]);
int booster_rx_process(u8 *rx_desc, union recv_frame *precvframe);

/************************** MU *************************************/
void WifiMuSendDataForUlRateTest(void);


#endif //_AMEBAX_WIFI_TEST_H_
