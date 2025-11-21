/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
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
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef __WIFI_HAL_RECV_H__
#define __WIFI_HAL_RECV_H__

//DWORD 0
#define SET_TRX_BD(addr, offset, len, val)	((HAL_WRITE32(addr, 0, ((HAL_READ32(addr, 0) & (~(BIT_LEN_MASK_32(len) << offset))) | ((val & BIT_LEN_MASK_32(len))  << offset)))))
#define GET_TRX_BD(addr, offset, len)		((HAL_READ32(addr, 0) >> offset) & BIT_LEN_MASK_32(len))

#define SET_RX_BUFFER_DESC_DATA_LENGTH_92E(rxbd, val)		SET_TRX_BD(rxbd, 0, 14, val)
#define SET_RX_BUFFER_DESC_LS_92E(rxbd,val)			SET_TRX_BD(rxbd, 14, 1, val)
#define SET_RX_BUFFER_DESC_FS_92E(rxbd, val)			SET_TRX_BD(rxbd, 15, 1, val)
#define SET_RX_BUFFER_DESC_RX_TAG_92E(rxbd, val)		SET_TRX_BD(rxbd, 16, 13, val)

#define GET_RX_BUFFER_DESC_OWN_92E(rxbd)			GET_TRX_BD(rxbd, 31, 1)
#define GET_RX_BUFFER_DESC_LS_92E(rxbd)				GET_TRX_BD(rxbd, 14, 1)
#define GET_RX_BUFFER_DESC_FS_92E(rxbd)				GET_TRX_BD(rxbd, 15, 1)
#define GET_RX_BUFFER_DESC_RX_TAG_92E(rxbd)			GET_TRX_BD(rxbd, 16, 13)
#define GET_RX_BUFFER_DESC_TOTAL_LENGTH_92E(rxbd) 		GET_TRX_BD(rxbd, 0, 14)

//DWORD 1
#define SET_RX_BUFFER_PHYSICAL_LOW_92E(rxbd, val)		SET_TRX_BD(rxbd+4, 0, 32, val)
#define GET_RX_BUFFER_PHYSICAL_LOW_92E(rxbd)			GET_TRX_BD(rxbd+4, 0, 32)

//DWORD 2
#define SET_RX_BUFFER_PHYSICAL_HIGH_92E(rxbd, val)		GET_TRX_BD(rxbd+8, 0, 32)

//20210409 R04 updated
//Offset 0
#define GET_RX_STATUS_DESC_PKT_LEN(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 0, 14)
#define GET_RX_STATUS_DESC_CRC32(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 14, 1)
#define GET_RX_STATUS_DESC_ICV(__pRxStatusDesc)			LE_BITS_TO_4BYTE( __pRxStatusDesc, 15, 1)
#define GET_RX_STATUS_DESC_SNIFFER_LEN(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 16, 3)
#define GET_RX_STATUS_DESC_EOSP(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 19, 1)
#define GET_RX_STATUS_DESC_SECURITY(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 20, 3)
#define GET_RX_STATUS_DESC_SHIFT(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 23, 2)
#define GET_RX_STATUS_DESC_SWDEC(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 25, 1)
#define GET_RX_STATUS_DESC_HE_MU_RU_SZ(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 26, 3)
#define GET_RX_STATUS_DESC_RX_BW(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 29, 2)
#define GET_RX_STATUS_DESC_INTER_PPDU(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 31, 1)

//Offset 4
#define GET_RX_STATUS_DESC_MACID(__pRxDesc) 			LE_BITS_TO_4BYTE(__pRxDesc+4, 0, 7)
#define GET_RX_STATUS_DESC_EXT_SECTYPE(__pRxDesc) 		LE_BITS_TO_4BYTE(__pRxDesc+4, 7, 1)
#define GET_RX_STATUS_DESC_TID(__pRxDesc) 			LE_BITS_TO_4BYTE(__pRxDesc+4, 8, 4)
#define GET_RX_STATUS_DESC_MACID_VLD(__pRxDesc) 		LE_BITS_TO_4BYTE(__pRxDesc+4, 12, 1)
#define GET_RX_STATUS_DESC_AMSDU(__pRxDesc) 			LE_BITS_TO_4BYTE(__pRxDesc+4, 13, 1)
#define GET_RX_STATUS_DESC_RXID_MATCH(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+4, 14, 1)
#define GET_RX_STATUS_DESC_PAGGR(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+4, 15, 1)
#define GET_RX_STATUS_DESC_PKT_INDICATE(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+4, 16, 3)
#define GET_RX_STATUS_DESC_SENT_RXCMD(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+4, 19, 1)
#define GET_RX_STATUS_DESC_CHKERR(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+4, 20, 1)
#define GET_RX_STATUS_DESC_IPVER(__pRxDesc)			LE_BITS_TO_4BYTE(__pRxDesc+4, 21, 1)
#define GET_RX_STATUS_DESC_IS_TCPUDP_(__pRxDesc)		LE_BITS_TO_4BYTE(__pRxDesc+4, 22, 1)
#define GET_RX_STATUS_DESC_CHK_VLD(__pRxDesc)			LE_BITS_TO_4BYTE(__pRxDesc+4, 23, 1)
#define GET_RX_STATUS_DESC_PAM(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+4, 24, 1)
#define GET_RX_STATUS_DESC_PWR(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+4, 25, 1)
#define GET_RX_STATUS_DESC_MORE_DATA(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+4, 26, 1)
#define GET_RX_STATUS_DESC_MORE_FRAG(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+4, 27, 1)
#define GET_RX_STATUS_DESC_TYPE(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+4, 28, 2)
#define GET_RX_STATUS_DESC_MC(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+4, 30, 1)
#define GET_RX_STATUS_DESC_BC(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+4, 31, 1)

//Offset 8
#define GET_RX_STATUS_DESC_SEQ(__pRxStatusDesc)			LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 0, 12)
#define GET_RX_STATUS_DESC_FRAG(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 12, 4)
#define GET_RX_STATUS_DESC_QOS(__pRxStatusDesc)			LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 16, 1)
#define GET_RX_STATUS_DESC_IFS_CNT0_PHY(__pRxStatusDesc)	LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 17, 1)
#define GET_RX_STATUS_DESC_WLANHD_IV_LEN(__pRxStatusDesc)	LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 18, 6)
#define GET_RX_STATUS_DESC_RXMAGPKT(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 24, 1)
#define GET_RX_STATUS_DESC_GI_LTF(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 25, 3)
#define GET_RX_STATUS_DESC_C2H(__pRxStatusDesc)			LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 28, 1)
#define GET_RX_STATUS_DESC_PPDU_CNT(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 29, 2)
#define GET_RX_STATUS_DESC_FCS_OK(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 31, 1)

//Offset 12
#define GET_RX_STATUS_DESC_RX_RATE(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 0, 9)
#define GET_RX_STATUS_DESC_HTC(__pRxStatusDesc)			LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 9, 1)
#define GET_RX_STATUS_DESC_BSSID_FIT_H(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 10, 2)
/*[28:12] start, different for normal pkt, channel info pkt and ppdu status pkt*/
/*normal pkt:*/
#define GET_RX_STATUS_DESC_PWR_LV(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 12, 9)
#define GET_RX_STATUS_DESC_PPDU_TYPE(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 21, 4)
#define GET_RX_STATUS_DESC_R_SENT_RXCMD(__pRxStatusDesc)	LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 25, 1)
#define GET_RX_STATUS_DESC_RELAY_FIT(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 26, 1)
#define GET_RX_STATUS_DESC_UL_RELAY_FIT(__pRxStatusDesc)	LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 27, 1)
#define GET_RX_STATUS_DESC_RELAY_HANDSHAKE(__pRxStatusDesc)	LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 28, 1)
/*channel info pkt:*/
#define GET_RX_STATUS_DESC_CH_INFO_CSI_LEN(__pRxStatusDesc)	LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 16, 10)
#define GET_RX_STATUS_DESC_CH_INFO_BW(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 26, 2)
/*ppdu status pkt:*/
#define GET_RX_STATUS_DESC_PHYSTS_LEN(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 16, 8)
#define GET_RX_STATUS_DESC_PHYSTS_OF_DATA(__pRxStatusDesc)	LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 24, 1)
/*[28:12] end*/
#define GET_RX_STATUS_DESC_PATTERN_MATCH(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+12, 29, 1)
#define GET_RX_STATUS_DESC_UNICAST_MATCH(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+12, 30, 1)
#define GET_RX_STATUS_DESC_MAGIC_MATCH(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+12, 31, 1)

//Offset 16
#define GET_RX_STATUS_DESC_PATTERN_MATCH_IDX(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+16, 0, 8)
#define GET_RX_STATUS_DESC_RX_EOF(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+16, 8, 1)
#define GET_RX_STATUS_DESC_RX_SCRAMBLER(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+16, 9, 7)
#define GET_RX_STATUS_DESC_RX_PRE_NDP_OK(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+16, 16, 1)
#define GET_RX_STATUS_DESC_TXRPTMID_SRCH(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+16, 17, 7)
#define GET_RX_STATUS_DESC_MBSSID_FIT_INDEX(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+16, 24, 5)
#define GET_RX_STATUS_DESC_TXRPT_CTL_MASK(__pRxDesc)	LE_BITS_TO_4BYTE( __pRxDesc+16, 29, 1)
#define GET_RX_STATUS_DESC_SUP_ADDR3_FIT(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+16, 30, 1)
#define GET_RX_STATUS_DESC_RX_SERV_SIG_FIT(__pRxDesc)	LE_BITS_TO_4BYTE( __pRxDesc+16, 31, 1)

//Offset 20
#define GET_RX_STATUS_DESC_TSFL(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+20, 0, 32)

//for compatibility
#define GET_RX_STATUS_DESC_DRV_INFO_SIZE(__pRxStatusDesc)	0

enum DESC_FRAME_TYPE {
	DESC_MGT_TYPE = 0x0,
	DESC_CTRL_TYPE = 0x1,
	DESC_DATA_TYPE = 0x2,
};

#if  WIFI_LOGO_CERTIFICATION
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
#endif


#endif

