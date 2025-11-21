#ifndef __ROM_WIFI_HAL_TXDESC_H__
#define __ROM_WIFI_HAL_TXDESC_H__

//
// Queue Select Value in TxDesc
//
#define QSLT_BK							0x2//0x01
#define QSLT_BE							0x0
#define QSLT_VI							0x5//0x4
#define QSLT_VO							0x7//0x6
#define QSLT_BEACON						0x10
#define QSLT_HIGH						0x11
#define QSLT_MGNT						0x12
#define QSLT_CMD						0x13

#define MAX_TID (15)

// Dword 0
#define GET_TX_DESC_OWN(__pTxDesc)				LE_BITS_TO_4BYTE(__pTxDesc, 31, 1)

#define SET_TX_DESC_PKT_SIZE(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 0, 16, __Value)
#define SET_TX_DESC_OFFSET(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 16, 8, __Value)
#define SET_TX_DESC_BMC(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 24, 1, __Value)
#define SET_TX_DESC_HTC(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 25, 1, __Value)
#define SET_TX_DESC_LAST_SEG(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 26, 1, __Value)
#define SET_TX_DESC_FIRST_SEG(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 27, 1, __Value)
#define SET_TX_DESC_LINIP(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 28, 1, __Value)
#define SET_TX_DESC_NO_ACM(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 29, 1, __Value)
#define SET_TX_DESC_GF(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc, 30, 1, __Value)

// Dword 1
#define SET_TX_DESC_MACID(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 0, 7, __Value)
#define SET_TX_DESC_QUEUE_SEL(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 8, 5, __Value)
#define SET_TX_DESC_RDG_NAV_EXT(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 13, 1, __Value)
#define SET_TX_DESC_LSIG_TXOP_EN(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 14, 1, __Value)
#define SET_TX_DESC_PIFS(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 15, 1, __Value)
#define SET_TX_DESC_RATE_ID(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 16, 5, __Value)
#define SET_TX_DESC_EN_DESC_ID(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 21, 1, __Value)
#define SET_TX_DESC_SEC_TYPE(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 22, 2, __Value)
#define SET_TX_DESC_PKT_OFFSET(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+4, 24, 5, __Value)


// Dword 2
#define SET_TX_DESC_PAID(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 0,  9, __Value)
#define SET_TX_DESC_CCA_RTS(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 10, 2, __Value)
#define SET_TX_DESC_AGG_ENABLE(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 12, 1, __Value)
#define SET_TX_DESC_RDG_ENABLE(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 13, 1, __Value)
#define SET_TX_DESC_AGG_BREAK(__pTxDesc, __Value) 				SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 16, 1, __Value)
#define SET_TX_DESC_MORE_FRAG(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 17, 1, __Value)
#define SET_TX_DESC_RAW(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 18, 1, __Value)
#define SET_TX_DESC_SPE_RPT(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 19, 1, __Value)
#define SET_TX_DESC_AMPDU_DENSITY(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 20, 3, __Value)
#define SET_TX_DESC_BT_INT(__pTxDesc, __Value)			SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 23, 1, __Value)
#define SET_TX_DESC_GID(__pTxDesc, __Value)			SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 24, 6, __Value)


// Dword 3
#define SET_TX_DESC_WHEADER_LEN(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 0, 4, __Value)
#define SET_TX_DESC_CHK_EN(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 4, 1, __Value)
#define SET_TX_DESC_EARLY_MODE(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 5, 1, __Value)
#define SET_TX_DESC_HWSEQ_SEL(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 6, 2, __Value)
#define SET_TX_DESC_USE_RATE(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 8, 1, __Value)
#define SET_TX_DESC_DISABLE_RTS_FB(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 9, 1, __Value)
#define SET_TX_DESC_DISABLE_FB(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 10, 1, __Value)
#define SET_TX_DESC_CTS2SELF(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 11, 1, __Value)
#define SET_TX_DESC_RTS_ENABLE(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 12, 1, __Value)
#define SET_TX_DESC_HW_RTS_ENABLE(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 13, 1, __Value)
#define SET_TX_DESC_NAV_USE_HDR(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 15, 1, __Value)
#define SET_TX_DESC_USE_MAX_LEN(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 16, 1, __Value)
#define SET_TX_DESC_MAX_AGG_NUM(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 17, 5, __Value)
#define SET_TX_DESC_NDPA(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 22, 2, __Value)
#define SET_TX_DESC_AMPDU_MAX_TIME(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+12, 24, 8, __Value)

// Dword 4
#define SET_TX_DESC_TX_RATE(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 0, 7, __Value)
#define SET_TX_DESC_DATA_RATE_FB_LIMIT(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 8, 5, __Value)
#define SET_TX_DESC_RTS_RATE_FB_LIMIT(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 13, 4, __Value)
#define SET_TX_DESC_RETRY_LIMIT_ENABLE(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 17, 1, __Value)
#define SET_TX_DESC_DATA_RETRY_LIMIT(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 18, 6, __Value)
#define SET_TX_DESC_RTS_RATE(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+16, 24, 5, __Value)


// Dword 5
#define SET_TX_DESC_DATA_SC(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 0, 4, __Value)
#define SET_TX_DESC_DATA_SHORT(__pTxDesc, __Value)	SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 4, 1, __Value)
#define SET_TX_DESC_DATA_BW(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 5, 2, __Value)
#define SET_TX_DESC_DATA_LDPC(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 7, 1, __Value)
#define SET_TX_DESC_DATA_STBC(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 8, 2, __Value)
#define SET_TX_DESC_CTROL_STBC(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 10, 2, __Value)
#define SET_TX_DESC_RTS_SHORT(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 12, 1, __Value)
#define SET_TX_DESC_RTS_SC(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+20, 13, 4, __Value)


// Dword 6
#define SET_TX_DESC_SW_DEFINE(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 0, 12, __Value)
#define SET_TX_DESC_ANTSEL_A(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 16, 3, __Value)
#define SET_TX_DESC_ANTSEL_B(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 19, 3, __Value)
#define SET_TX_DESC_ANTSEL_C(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 22, 3, __Value)
#define SET_TX_DESC_ANTSEL_D(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+24, 25, 3, __Value)

// Dword 7
#if defined(DEV_BUS_TYPE) && (DEV_BUS_TYPE == RT_PCI_INTERFACE)
#define SET_TX_DESC_TX_BUFFER_SIZE(__pTxDesc, __Value)		SET_BITS_TO_LE_4BYTE(__pTxDesc+28, 0, 16, __Value)
#else
#define SET_TX_DESC_TX_DESC_CHECKSUM(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+28, 0, 16, __Value)
#endif
#define SET_TX_DESC_USB_TXAGG_NUM(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+28, 24, 8, __Value)
#if defined(DEV_BUS_TYPE) && (DEV_BUS_TYPE == RT_SDIO_INTERFACE)
#define SET_TX_DESC_SDIO_TXSEQ(__pTxDesc, __Value)			SET_BITS_TO_LE_4BYTE(__pTxDesc+28, 16, 8, __Value)
#endif

// Dword 8
#define SET_TX_DESC_HWSEQ_EN(__pTxDesc, __Value)			SET_BITS_TO_LE_4BYTE(__pTxDesc+32, 15, 1, __Value)

// Dword 9
#define SET_TX_DESC_SEQ(__pTxDesc, __Value)					SET_BITS_TO_LE_4BYTE(__pTxDesc+36, 12, 12, __Value)

// Dword 10
#define SET_TX_DESC_TX_BUFFER_ADDRESS(__pTxDesc, __Value) 	SET_BITS_TO_LE_4BYTE(__pTxDesc+40, 0, 32, __Value)


// Dword 11
#define SET_TX_DESC_NEXT_DESC_ADDRESS(__pTxDesc, __Value) 	SET_BITS_TO_LE_4BYTE(__pTxDesc+48, 0, 32, __Value)

//
//defined for TX DESC Operation
//
struct txdesc_priv {
	// Offset 0
	u32 pktlen: 16;
	u32 offset: 8;
	u32 bmc: 1;
	u32 rate_fallback_table_idx: 1;
	u32 rsvd0026: 1;
	u32 rsvd0027: 1;
	u32 bcnpkt_tsf_ctrl: 1;
	u32 noacm: 1;
	u32 gf: 1;
	u32 rsvd0031: 1;

	// Offset 4
	u32 macid: 7;
	u32 bip_keyid_sel: 1;
	u32 qsel: 5;
	u32 force_txop: 1;
	u32 lsig_txop_en: 1;
	u32 pifs: 1;
	u32 a_ctrl_cas: 1;
	u32 a_ctrl_bsr: 1;
	u32 a_ctrl_uph: 1;
	u32 a_ctrl_bqr: 1;
	u32 htc: 1;
	u32 en_desc_id: 1;
	u32 sectype: 2;
	u32 pkt_offset: 5; // unit: 8 bytes
	u32 moredata: 1;
	u32 ftm_en: 1;
	u32 hw_aesiv: 1;

	// Offset 8
	u32 p_aid: 9;
	u32 tri_frame: 1;
	u32 cca_rts: 2;
	u32 agg_en: 1;
	u32 ack_ch_info: 1;
	u32 null_0: 1;
	u32 null_1: 1;
	u32 bk: 1;
	u32 tm_en: 1;
	u32 raw: 1;
	u32 ccx: 1;
	u32 ampdu_density: 3;
	u32 bt_int: 1;
	u32 spe_frame_ind: 3;
	u32 mu_snd_flag: 1;
	u32 rsvd0828: 4;

	// Offset 12
	u32 wheader_len: 5;
	u32 txdesc_info_en: 1;
	u32 hw_ssn_sel: 2;
	u32 userate: 1;
	u32 disrtsfb: 1;
	u32 disdatafb: 1;
	u32 cts2self: 1;
	u32 rtsen: 1;
	u32 hw_rts_en: 1;
	u32 chk_en: 1;
	u32 navusehdr: 1;
	u32 use_max_time: 1;
	u32 max_agg_num: 5;
	u32 ndpa: 2;
	u32 ampdu_max_time: 8;

	// Offset 16
	u32 datarate: 9;
	u32 data_rty_lowest_rate: 9;
	u32 retry_limit: 6;
	u32 obw_cts2self_dup_type: 4;
	u32 try_rate: 1;
	u32 data_gi: 3;

	// Offset 20
	u32 data_sc: 4;
	u32 data_dcm: 1;
	u32 data_bw: 2;
	u32 data_ldpc: 1;
	u32 data_stbc: 2;
	u32 rts_stbc: 2;
	u32 rts_short: 1;
	u32 rts_sc: 4;
	u32 signaling_tapkt: 1;
	u32 data_bw_er: 1;
	u32 data_er: 1;
	u32 mbssid: 4;
	u32 txpwr_offset: 5;
	u32 rsvd2028: 1;
	u32 port_id: 1;
	u32 polluted: 1;

	// Offset 24
	u32 rtsrate: 9;
	u32 rts_rty_lowest_rate: 9;
	u32 antsel_en: 1;
	u32 rty_use_des: 1;
	u32 antsel_A: 1;
	u32 antsel_B: 1;
	u32 antsel_C: 1;
	u32 antsel_D: 1;
	u32 ant_mapA: 2;
	u32 ant_mapB: 2;
	u32 ant_mapC: 2;
	u32 ant_mapD: 2;

	// Offset 28
	u32 checksum: 16;
	u32 sw_define_l: 7;
	u32 usb_txagg_num: 9;

	// Offset 32
	u32 rts_rc: 6;
	u32 bar_rty_th: 2;
	u32 data_rc: 6;
	u32 tx_vendor_adv_mode: 1;
	u32 en_hwseq: 1;
	u32 nextheadpage_l: 8;
	u32 tailpage_l: 8;

	// Offset 36
	u32 group_bit_ie: 8;
	u32 sw_define_h: 4;
	u32 seq: 12;
	u32 nextheadpage_h: 4;
	u32 tailpage_h: 4;
};


void ROM_WIFI_TXDESC_FillVCS(struct txdesc_priv *ptxdesc, u8 vcs_mode, u8 cur_channel, u8 preamble_mode, u8 ht_en, u8 rts_sc);

#endif
