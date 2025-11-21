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

//RX descriptor
//Offset 0
#define GET_RX_STATUS_DESC_PKT_LEN(__pRxDesc)       LE_BITS_TO_4BYTE( __pRxDesc, 0, 14)
#define GET_RX_STATUS_DESC_PHYSTS_VALID(__pRxDesc)          LE_BITS_TO_4BYTE( __pRxDesc, 14, 1)
#define GET_RX_STATUS_DESC_MACID_VLD(__pRxDesc)             LE_BITS_TO_4BYTE( __pRxDesc, 15, 1)
#define GET_RX_STATUS_DESC_RX_RATE(__pRxDesc)       LE_BITS_TO_4BYTE( __pRxDesc, 16, 6)
#define GET_RX_STATUS_DESC_PHYSTS_LEN(__pRxDesc)        LE_BITS_TO_4BYTE( __pRxDesc, 22, 3)
#define GET_RX_STATUS_DESC_MACID(__pRxDesc)             LE_BITS_TO_4BYTE(__pRxDesc, 25, 7)

//Offset 4
#define GET_RX_STATUS_DESC_PKT_INDICATE(__pRxDesc)      LE_BITS_TO_4BYTE( __pRxDesc+4, 0, 2)
#define GET_RX_STATUS_DESC_A2_SWAP(__pRxDesc)           LE_BITS_TO_4BYTE( __pRxDesc+4, 3, 1)
#define GET_RX_STATUS_DESC_SWDEC(__pRxDesc)         LE_BITS_TO_4BYTE( __pRxDesc+4, 4, 1)
#define GET_RX_STATUS_DESC_PPDU_CNT(__pRxDesc)          LE_BITS_TO_4BYTE( __pRxDesc+4, 5, 2)
#define GET_RX_STATUS_DESC_SIG_FIT(__pRxDesc)               LE_BITS_TO_4BYTE( __pRxDesc+4, 7, 1)
#define GET_RX_STATUS_DESC_CRC32(__pRxDesc)         LE_BITS_TO_4BYTE( __pRxDesc+4, 8, 1)
#define GET_RX_STATUS_DESC_ICV(__pRxDesc)           LE_BITS_TO_4BYTE( __pRxDesc+4, 9, 1)
#define GET_RX_STATUS_DESC_SECURITY(__pRxDesc)          LE_BITS_TO_4BYTE( __pRxDesc+4, 10, 4)
#define GET_RX_STATUS_DESC_PWR_LV(__pRxDesc)                LE_BITS_TO_4BYTE( __pRxDesc+4, 14, 9)
#define GET_RX_STATUS_DESC_GI_LTF(__pRxDesc)                LE_BITS_TO_4BYTE( __pRxDesc+4, 23, 3)
#define GET_RX_STATUS_DESC_PAM(__pRxDesc)                   LE_BITS_TO_4BYTE( __pRxDesc+4, 26, 3)
#define GET_RX_STATUS_DESC_RELAY_FIT(__pRxDesc)         LE_BITS_TO_4BYTE( __pRxDesc+4, 29, 1)
#define GET_RX_STATUS_DESC_UL_RELAY_FIT(__pRxDesc)      LE_BITS_TO_4BYTE( __pRxDesc+4, 30, 1)
#define GET_RX_STATUS_DESC_RELAY_HANDSHAKE(__pRxDesc)   LE_BITS_TO_4BYTE( __pRxDesc+4, 31, 1)

//Offset 8
#define GET_RX_STATUS_DESC_SEQ(__pRxDesc)                   LE_BITS_TO_4BYTE( __pRxDesc+8, 0, 12)
#define GET_RX_STATUS_DESC_RP_MACID(__pRxStatusDesc)        LE_BITS_TO_4BYTE( __pRxStatusDesc+8, 12, 7)
#define GET_RX_STATUS_DESC_BSSID_FIT(__pRxDesc)     LE_BITS_TO_4BYTE( __pRxDesc+8, 19, 3)
#define GET_RX_STATUS_DESC_AMPDU(__pRxDesc)                 LE_BITS_TO_4BYTE(__pRxDesc+8, 22, 1)
#define GET_RX_STATUS_DESC_A3_FIT(__pRxDesc)                LE_BITS_TO_4BYTE( __pRxDesc+8, 23, 1)
#define GET_RX_STATUS_DESC_CENTRAL_CH(__pRxDesc)            LE_BITS_TO_4BYTE( __pRxDesc+8, 24, 8)

//Offset 12
#define GET_RX_STATUS_DESC_TSFL(__pRxDesc)              LE_BITS_TO_4BYTE( __pRxDesc+12, 0, 32)

//CSI descriptor
//offset 0
#define GET_RX_STATUS_DESC_CH_INFO_CSI_LEN(__pRxDesc)   LE_BITS_TO_4BYTE( __pRxDesc, 0, 7)
#define GET_RX_STATUS_DESC_CH_INFO_FC_TYPE(__pRxDesc)   LE_BITS_TO_4BYTE( __pRxDesc, 7, 2)
#define GET_RX_STATUS_DESC_CH_INFO_BW(__pRxDesc)        LE_BITS_TO_4BYTE( __pRxDesc, 9, 2)
#define GET_RX_STATUS_DESC_CH_INFO_FRAG_NUM(__pRxDesc)      LE_BITS_TO_4BYTE( __pRxDesc, 11, 4)

//offset 4
#define GET_RX_STATUS_DESC_CH_INFO_FC_SUBTYPE(__pRxDesc)    LE_BITS_TO_4BYTE( __pRxDesc+4, 4, 4)
#define GET_RX_STATUS_DESC_CH_INFO_SRC_ADDR_0(__pRxDesc)    LE_BITS_TO_4BYTE( __pRxDesc+4, 8, 8)
#define GET_RX_STATUS_DESC_CH_INFO_SRC_ADDR_1(__pRxDesc)    LE_BITS_TO_4BYTE( __pRxDesc+4, 16, 8)
#define GET_RX_STATUS_DESC_CH_INFO_SRC_ADDR_2(__pRxDesc)    LE_BITS_TO_4BYTE( __pRxDesc+4, 24, 8)

//offset 8
#define GET_RX_STATUS_DESC_CH_INFO_SRC_ADDR_3(__pRxDesc)    LE_BITS_TO_4BYTE( __pRxDesc+8, 0, 8)
#define GET_RX_STATUS_DESC_CH_INFO_SRC_ADDR_4(__pRxDesc)    LE_BITS_TO_4BYTE( __pRxDesc+8, 8, 8)
#define GET_RX_STATUS_DESC_CH_INFO_SRC_ADDR_5(__pRxDesc)    LE_BITS_TO_4BYTE( __pRxDesc+8, 16, 8)

//offset 12

//RADAR descriptor
//offset 0
#define GET_RX_STATUS_DESC_RADAR_LEN(__pRxDesc)   LE_BITS_TO_4BYTE( __pRxDesc, 0, 10)

//offset 4
#define GET_RX_STATUS_DESC_RADAR_TIIMESTAMP(__pRxDesc)   LE_BITS_TO_4BYTE( __pRxDesc+4, 8, 24)


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
void wifi_hal_rxbd_init(void);
void wifi_hal_rxbd_write(u32 addr);
u32 wifi_hal_rxbd_read(struct sk_buff *skb);
void wifi_hal_rxdesc_query_from_machdr(struct rx_pkt_attrib	*pattrib, u8 *machdr);
u16 wifi_hal_check_rxdesc_remain(int rxringcount);

#if defined(CONFIG_CSI) || defined(CONFIG_RADAR)
void wifi_hal_csibd_write(u32 addr);
u32 wifi_hal_csibd_read(void);
u16 wifi_hal_check_csidesc_remain(void);
void wifi_hal_rx_csi(void);
#ifdef CONFIG_CSI
void wifi_hal_rxdesc_csi_query(struct rtw_csi_desc *csi_desc, u8 *pdesc);
#endif
#ifdef CONFIG_RADAR
void wifi_hal_rxdesc_radar_query(struct rtw_radar_desc *radar_desc, u8 *pdesc);
#endif
#endif
#endif

