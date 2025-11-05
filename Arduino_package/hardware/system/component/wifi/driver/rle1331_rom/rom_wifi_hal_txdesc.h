#ifndef __ROM_WIFI_HAL_TXDESC_H__
#define __ROM_WIFI_HAL_TXDESC_H__

//
// Queue Select Value in TxDesc
//
#define QSLT_BK					0x2//0x01
#define QSLT_BE					0x0
#define QSLT_VI					0x5//0x4
#define QSLT_VO					0x7//0x6
#define QSLT_BEACON				0xF
#define QSLT_HIGH				0xE
#define QSLT_MGNT				0xD
#define QSLT_RDQ				0x9	//used for radar
#define QSLT_EVTQ				0x8	//used for NAN
#define MAX_TID (7)

//
//defined for TX DESC Operation
//
//20211203 R01 updated
struct txdesc_priv {
	// Offset 0
	u32 pktlen: 12;
	u32 offset: 4;
	u32 macid: 7;
	u32 qsel: 4;
	u32 port_id: 2;
	u32 tri_frame: 1;
	u32 bmc: 1;
	u32 rsvd0031: 1;

	// Offset 4
	u32 p_aid: 9;
	u32 rsvd0409: 2;
	u32 bcnpkt_tsf_ctrl: 1;
	u32 rsvd0412: 1;
	u32 spp_valid: 1;
	u32 key_index: 6;
	u32 sectype: 4;
	u32 group_bit_ie: 8;

	// Offset 8
	u32 polluted: 1;
	u32 rts_rc: 7;
	u32 data_rc: 6;
	u32 bar_rty_th: 2;
	u32 rtsrate: 6;
	u32 retry_pkt: 1;
	u32 final_gi_ltf: 3;
	u32 final_datarate: 6;

	// Offset 12
	u32 datarate: 6;
	u32 data_gi: 3;
	u32 data_bw: 1;
	u32 rsvd1210: 2;
	u32 agg_en: 1;
	u32 rsvd1213: 6;
	u32 en_hwseq: 1;
	u32 seq: 12;

	// Offset 16
	u32 rsvd1600: 1;
	u32 null_0: 1;
	u32 null_1: 1;
	u32 userate: 1;
	u32 navusehdr: 1;
	u32 rty_use_des: 1;
	u32 bk: 1;
	u32 rts_retry_limit: 5;
	u32 retry_limit: 5;
	u32 moredata: 1;
	u32 a_ctrl_cas: 1;
	u32 a_ctrl_bsr: 1;
	u32 a_ctrl_uph: 1;
	u32 a_ctrl_bqr: 1;
	u32 htc: 1;
	u32 dis_retry_drop: 1;
	u32 sw_define: 8;

	// Offset 20
	u32 ampdu_max_time: 8;
	u32 use_max_time: 1;
	u32 data_dcm: 1;
	u32 highest_rate: 1;
	u32 rts_short: 1;
	u32 data_bw_er: 1;
	u32 data_er: 1;
	u32 data_ldpc: 1;
	u32 rsvd2015: 3;
	u32 disrtsfb: 1;
	u32 disdatafb: 1;
	u32 hw_ssn_sel: 2;
	u32 npda: 2;
	u32 rsvd2024: 2;
	u32 ampdu_density: 3;
	u32 fb_mask_idx: 2;
	u32 rsvd2031: 1;

	// Offset 24
	u32 cts2self: 1;
	u32 rtsen: 1;
	u32 hw_rts_en: 1;
	u32 raw: 1;
	u32 rsvd2404: 1;
	u32 force_txop: 1;
	u32 ack_ch_info: 1;
	u32 vendor_adv: 1;
	u32 signaling_tapkt: 1;
	u32 cca_rts: 2;
	u32 pifs: 1;
	u32 max_agg_num: 5;
	u32 obw_cts2self_dup_type: 4;
	u32 tx_swap: 1;
	u32 ul_swap: 1;
	u32 rsvd2423: 1;
	u32 bmode_wi_rtk_signature: 1;
	u32 ack_rssi: 1;
	u32 ftm_en: 1;
	u32 tm_en: 1;
	u32 rsvd2428: 4;
};

// Dword 0, offset0
#define SET_TX_DESC_PKT_SIZE(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc, 0, 12, __Value)
#define SET_TX_DESC_OFFSET(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc, 12, 4, __Value)
#define SET_TX_DESC_MACID(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc, 16, 7, __Value)
#define SET_TX_DESC_QUEUE_SEL(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc, 23, 4, __Value)
#define SET_TX_DESC_BMC(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc, 30, 1, __Value)

// Dword 1, offset 4
#define SET_TX_DESC_PAID(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 0,  9, __Value)
#define SET_TX_DESC_KEY_INDEX(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 14, 6, __Value)
#define SET_TX_DESC_SEC_TYPE(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 20, 4, __Value)

// Dword 2, offset 8
#define SET_TX_DESC_RTS_RATE(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 16, 6, __Value)

// Dword 3, offset 12
#define SET_TX_DESC_TX_RATE(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 0, 6, __Value)
#define SET_TX_DESC_DATA_BW(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 9, 1, __Value)
#define SET_TX_DESC_AGG_ENABLE(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 12, 1, __Value)
#define SET_TX_DESC_HWSEQ_EN(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 19, 1, __Value)
#define SET_TX_DESC_SEQ(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 20, 12, __Value)

// Dword 4, offset 16
#define SET_TX_DESC_USE_RATE(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 3, 1, __Value)
#define SET_TX_DESC_NAV_USE_HDR(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 4, 1, __Value)
#define SET_TX_DESC_AGG_BREAK(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 6, 1, __Value)
#define SET_TX_DESC_DATA_RETRY_LIMIT(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 12, 4, __Value)
#define SET_TX_DESC_HTC(__pTxDesc, __Value)			SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 22, 1, __Value)
#define SET_TX_DESC_SW_DEFINE(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 24, 8, __Value)

// Dword 5, offset 20
#define SET_TX_DESC_DATA_LDPC(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 8, 1, __Value)
#define SET_TX_DESC_RTS_SHORT(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 11, 1, __Value)
#define SET_TX_DESC_DISABLE_RTS_FB(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 18, 1, __Value)
#define SET_TX_DESC_DISABLE_FB(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 19, 1, __Value)
#define SET_TX_DESC_HWSEQ_SEL(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 20, 2, __Value)
#define SET_TX_DESC_AMPDU_DENSITY(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 26, 3, __Value)

// Dword 6, offset 24
#define SET_TX_DESC_CTS2SELF(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 0, 1, __Value)
#define SET_TX_DESC_RTS_ENABLE(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 1, 1, __Value)
#define SET_TX_DESC_HW_RTS_ENABLE(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 2, 1, __Value)
#define SET_TX_DESC_RAW(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 3, 1, __Value)
#define SET_TX_DESC_CCA_RTS(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 9, 2, __Value)
#define SET_TX_DESC_PIFS(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 11, 1, __Value)
#define SET_TX_DESC_MAX_AGG_NUM(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 12, 5, __Value)

void ROM_WIFI_TXDESC_FillVCS(struct txdesc_priv *ptxdesc, u8 vcs_mode, u8 cur_channel, u8 preamble_mode);
#endif
