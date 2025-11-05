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

//Rx Buffer Descriptor
//DWORD 0
#define SET_TRX_BD(addr, offset, len, val)	((HAL_WRITE32(addr, 0, ((HAL_READ32(addr, 0) & (~(BIT_LEN_MASK_32(len) << offset))) | ((val & BIT_LEN_MASK_32(len))  << offset)))))
#define GET_TRX_BD(addr, offset, len)				((HAL_READ32(addr, 0) >> offset) & BIT_LEN_MASK_32(len))

#define SET_RX_BUFFER_DESC_DATA_LENGTH_92E(rxbd, val)		SET_TRX_BD(rxbd, 0, 14, val)
#define SET_RX_BUFFER_DESC_LS_92E(rxbd,val)			SET_TRX_BD(rxbd, 14, 1, val)
#define SET_RX_BUFFER_DESC_FS_92E(rxbd, val)			SET_TRX_BD(rxbd, 15, 1, val)

#define GET_RX_BUFFER_DESC_LS_92E(rxbd)				GET_TRX_BD(rxbd, 14, 1)
#define GET_RX_BUFFER_DESC_FS_92E(rxbd)				GET_TRX_BD(rxbd, 15, 1)
#define GET_RX_BUFFER_DESC_RX_TAG_92E(rxbd)			GET_TRX_BD(rxbd, 16, 13)
#define GET_RX_BUFFER_DESC_TOTAL_LENGTH_92E(rxbd) 		GET_TRX_BD(rxbd, 0, 14)

//DWORD 1
#define SET_RX_BUFFER_PHYSICAL_LOW_92E(rxbd, val)		SET_TRX_BD(rxbd+4, 0, 32, val)
#define GET_RX_BUFFER_PHYSICAL_LOW_92E(rxbd)			GET_TRX_BD(rxbd+4, 0, 32)

//Offset 0
#define GET_RX_STATUS_DESC_PKT_LEN(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 0, 14)
#define GET_RX_STATUS_DESC_CRC32(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 14, 1)
#define GET_RX_STATUS_DESC_ICV(__pRxStatusDesc)			LE_BITS_TO_4BYTE( __pRxStatusDesc, 15, 1)
#define GET_RX_STATUS_DESC_DRV_INFO_SIZE(__pRxStatusDesc)	LE_BITS_TO_4BYTE( __pRxStatusDesc, 16, 4)
#define GET_RX_STATUS_DESC_SECURITY(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 20, 3)
#define GET_RX_STATUS_DESC_QOS(__pRxStatusDesc)			LE_BITS_TO_4BYTE( __pRxStatusDesc, 23, 1)
#define GET_RX_STATUS_DESC_SHIFT(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 24, 2)
#define GET_RX_STATUS_DESC_PHYSTS(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 26, 1)
#define GET_RX_STATUS_DESC_SWDEC(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 27, 1)
#define GET_RX_STATUS_DESC_RELAY_FIT(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc, 28, 1)
#define GET_RX_STATUS_DESC_UL_RELAY_FIT(__pRxStatusDesc)	LE_BITS_TO_4BYTE( __pRxStatusDesc, 29, 1)
#define GET_RX_STATUS_DESC_R_SENT_RXCMD(__pRxStatusDesc)	LE_BITS_TO_4BYTE( __pRxStatusDesc, 30, 1)
#define GET_RX_STATUS_DESC_RELAY_HANDSHAKE(__pRxStatusDesc)	LE_BITS_TO_4BYTE( __pRxStatusDesc, 31, 1)

//Offset 4
#define GET_RX_STATUS_DESC_MACID(__pRxDesc) 			LE_BITS_TO_4BYTE(__pRxDesc+4, 0, 7)
#define GET_RX_STATUS_DESC_EXT_SECTYPE(__pRxDesc) 		LE_BITS_TO_4BYTE(__pRxDesc+4, 7, 1)
#define GET_RX_STATUS_DESC_TID(__pRxDesc) 			LE_BITS_TO_4BYTE(__pRxDesc+4, 8, 4)
#define GET_RX_STATUS_DESC_MACID_VLD(__pRxDesc) 		LE_BITS_TO_4BYTE(__pRxDesc+4, 12, 1)
#define GET_RX_STATUS_DESC_AMSDU(__pRxDesc) 			LE_BITS_TO_4BYTE(__pRxDesc+4, 13, 1)
#define GET_RX_STATUS_DESC_RXID_MATCH(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+4, 14, 1)
#define GET_RX_STATUS_DESC_PAGGR(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+4, 15, 1)
#define GET_RX_STATUS_DESC_PKT_INDICATE(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+4, 16, 2)
#define GET_RX_STATUS_DESC_RX_A2_SWAP(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+4, 18, 1)
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
#define GET_RX_STATUS_DESC_IFS_CNT0_PHY(__pRxStatusDesc)	LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 17, 1)
#define GET_RX_STATUS_DESC_WLANHD_IV_LEN(__pRxStatusDesc)	LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 18, 6)
#define GET_RX_STATUS_DESC_RXMAGPKT(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 24, 1)
#define GET_RX_STATUS_DESC_C2H(__pRxStatusDesc)			LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 28, 1)
#define GET_RX_STATUS_DESC_PPDU_CNT(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 29, 2)
#define GET_RX_STATUS_DESC_FCS_OK(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 31, 1)

//Offset 12
#define GET_RX_STATUS_DESC_RX_RATE(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 0, 7)
#define GET_RX_STATUS_DESC_BSSID_FIT_H(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 7, 3)
#define GET_RX_STATUS_DESC_HTC(__pRxStatusDesc)			LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 10, 1)
#define GET_RX_STATUS_DESC_EOSP(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 11, 1)
#define GET_RX_STATUS_DESC_BSSID_FIT_L(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 12, 2)
/*[27:16] start, different for normal pkt, channel info pkt*/
/*normal pkt:[23:16]-DMA_AGG_NUM,[27:24]-RSVD	 */
#define GET_RX_STATUS_DESC_DMA_AGG_NUM(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 16, 8)
/*channel info pkt:[25:16]-CSI Length, [27:26]-Rx_bw*/
#define GET_RX_STATUS_DESC_CH_INFO_CSI_LEN(__pRxStatusDesc)	LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 16, 10)
#define GET_RX_STATUS_DESC_CH_INFO_BW(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+12, 26, 2)
/*[27:16] end*/
#define GET_RX_STATUS_DESC_PATTERN_MATCH(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+12, 29, 1)
#define GET_RX_STATUS_DESC_UNICAST_WAKE(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+12, 30, 1)
#define GET_RX_STATUS_DESC_MAGIC_WAKE(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+12, 31, 1)

//Offset 16
#define GET_RX_STATUS_DESC_PATTERN_MATCH_IDX_LOW(__pRxDesc)	LE_BITS_TO_4BYTE( __pRxDesc+16, 0, 6)
#define GET_RX_STATUS_DESC_TXRPT_MID_CTL_MASK(__pRxDesc)	LE_BITS_TO_4BYTE( __pRxDesc+16, 6, 1)
#define GET_RX_STATUS_DESC_FC_POWER(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+16, 7, 1)
#define GET_RX_STATUS_DESC_RX_EOF(__pRxDesc)			LE_BITS_TO_4BYTE( __pRxDesc+16, 8, 1)
#define GET_RX_STATUS_DESC_RX_SCRAMBLER(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+16, 9, 7)
#define GET_RX_STATUS_DESC_RX_PRE_NDP_OK(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+16, 16, 1)
#define GET_RX_STATUS_DESC_TXRPTMID_SRCH(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+16, 17, 7)
#define GET_RX_STATUS_DESC_MBSSID_FIT_INDEX(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+16, 24, 5)
#define GET_RX_STATUS_DESC_PATTERN_MATCH_IDX_HIGH(__pRxDesc)	LE_BITS_TO_4BYTE( __pRxDesc+16, 29, 2)
#define GET_RX_STATUS_DESC_RX_SERV_SIG_FIT(__pRxDesc)		LE_BITS_TO_4BYTE( __pRxDesc+16, 31, 1)

//Offset 20
#define GET_RX_STATUS_DESC_TSFL(__pRxStatusDesc)		LE_BITS_TO_4BYTE( __pRxStatusDesc+20, 0, 32)

void wifi_hal_rxdesc_query(struct rx_pkt_attrib	*pattrib, u8 *pdesc);
#ifdef CONFIG_CSI
void wifi_hal_rxdesc_csi_query(struct rtw_csi_desc *csi_desc, u8 *pdesc);
#endif
void wifi_hal_normal_rx_process(union recv_frame *precvframe);
#endif

