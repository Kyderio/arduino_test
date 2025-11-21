/******************************************************************************
 *
 * Copyright(c) 2007 - 2012 Realtek Corporation. All rights reserved.
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
#ifndef _RTW_RECV_H_
#define _RTW_RECV_H_

#define MAX_RX_PKT_SIZE				WLAN_MAX_PROTOCOL_OVERHEAD + WLAN_MAX_ETHFRM_LEN	// MAX_RX_PKT_SIZE = 64+1514 = 1578
#define MAX_RX_PKT_LIMIT				8						// Limit HW RX packet size, unit 512bytes, N-5.2.38 RX_AMSDU

#ifndef CONFIG_HIGH_TP
#define NR_RECVBUFF (1)	//Decrease recv buffer due to memory limitation - YangJue
#else
#define NR_RECVBUFF (32)
#endif //CONFIG_HIGH_TP

// Rx smooth factor
#define Rx_Smooth_Factor			(20)

#define RXFRAME_ALIGN				8
#define RXFRAME_ALIGN_SZ			(1<<RXFRAME_ALIGN)

#define DRVINFO_SZ				4 // unit is 8bytes

#define RECVFRAME_HDR_ALIGN			128

#define SNAP_SIZE sizeof(struct ieee80211_snap_hdr)

#define RX_MPDU_QUEUE				0
#define RX_CMD_QUEUE				1
#define RX_MAX_QUEUE				2

#define RX_SC_ENTRY_NUM				3

#define RF_PATH 1

struct reorder_node {
	struct list_head	list;
	struct sk_buff	*skb;
	u16	seq_num;
};

//for Rx reordering buffer control
struct recv_reorder_ctrl {
	struct __queue pending_recvframe_queue;
	struct timer_list reordering_ctrl_timer;
	struct reorder_node *new_node;

	u16 indicate_seq;//=wstart_b, init_value=0xffff
	u16 wend_b;
	u16 wsize_b;

	u8 iface_type;
	u8 enable;
	u8 bReorderWaiting;
	unsigned char ap_compatibilty_enabled;// BIT0-BIT3 rx counter, BIT4 compatibilty

};

struct rxphyinfo_struct {
#if (PHYDM_VERSION < 3)
	u8		rx_pwdb_all;
	u8		signal_quality;				/* OFDM: signal_quality=rx_mimo_signal_quality[0], CCK: signal qualityin 0-100 index. */
	u8		rx_mimo_signal_strength[RF_PATH];	/* RSSI in 0~100 index */
	s8		rx_mimo_signal_quality[RF_PATH];		/* OFDM: per-path's EVM translate to 0~100% , no used for CCK*/
	u8		rx_mimo_evm_dbm[RF_PATH];			/* per-path's original EVM (dbm) */
	s8		rx_pwr[RF_PATH];					/* per-path's pwdb */
	u8		phyinfo_channel;	//nan					/* channel number---*/

	u8		rx_count: 2;					/* RX path counter---*/
	u8		is_mu_packet: 1;				/* is MU packet or not---boolean*/
	u8		is_beamformed: 1;				/* BF packet---boolean*/
	u8		rxsc: 4;						/* sub-channel---*/
#endif

	/* phydm & G6 commnt info for every packet*/
	s8		recv_signal_power;			/* Real power in dBm for this packet, no beautification and aggregation. Keep this raw info to be used for the other procedures. */
	s8		rx_snr[RF_PATH];					/* per-path's SNR	*/

	u8		band_width: 2; //rm
	u8		rom_rsvd;
};

struct phydm_perpkt_info_struct {
	u8		data_rate;
	u8		station_id;
	u8		is_cck_rate: 1;
	u8		rate_ss: 3;			/*spatial stream of data rate*/
	u8		is_packet_match_bssid: 1;	/*boolean*/
	u8		is_packet_to_self: 1;		/*boolean*/
	u8		is_packet_beacon: 1;		/*boolean*/
	u8		is_to_self: 1;				/*boolean*/
	u8		ppdu_cnt;
};

struct rx_pkt_attrib {
	u8	b_physt_valid : 1;
	u8 	b_amsdu : 1;
	u8	b_qos : 1;
	u8	b_mdata : 1;
	u8	b_mfrag : 1;
	u8	b_privacy : 1; //in frame_ctrl field
	u8	b_decrypted : 1;
	u8	b_bc : 1;
	u8	b_order : 1 ;
	u8	b_crc_err  : 1;
	u8	b_icv_err  : 1;
	u8	b_ap_bcmc_frame  : 1;
	u8	shift_sz : 2;
	u8	encrypt : 4; //when 0 indicate no encrypt. when non-zero, indicate the encrypt algorith
	u8 	key_index : 4;
	u8 	sgi : 4;
	u8 	pkt_rpt_type : 4;
	u8 	A1_matched : 4;
	u8	b_wtn_bcn : 1;
	u8	b_wtn_partial_bcn : 1;
	u8	rom_rsvd[2];

	u16	seq_num;
	u16	pkt_len;
	u16	eth_type;
	u16	data_rate;

	u8	drvinfo_sz;
	u8	hdrlen; //the WLAN Header Len
	u8 	to_fr_ds;
	u8	priority;
	u8	frag_num;
	u8	iv_len;
	u8	icv_len;
	u8 	dst[ETH_ALEN];
	u8 	src[ETH_ALEN];
	u8 	ta[ETH_ALEN];
	u8 	ra[ETH_ALEN];
	u8 	bssid[ETH_ALEN];
	u8 	channel;

	u8 wifi_addr_rxsc[3 * ETH_ALEN];

#if (PHYDM_VERSION == 3) /*for halbb physts_rxd*/
	u8 macid_from_rxdesc;
	u8 frame_type; //subtype not included
#endif

	struct rxphyinfo_struct phy_info;
};

#define REORDER_WAIT_TIME	(30) // (ms)

#define MAC_HEADER_RESEARVED_LEN	40
struct amsdu_priv_t {
	struct sk_buff		*pending_skb;
	u16			pending_skb_len;
	struct rx_pkt_attrib	attrib;
	u8			mac_hdr[MAC_HEADER_RESEARVED_LEN];
	u8			mac_hdr_len;	// The total length of mac header, including iv_len
	u8			icv_len;	// At the tail of packet, need move icv_len in the end.
	int			remain_len;
	u8			wait_sub_seg;
};

struct rxbd_t {
	unsigned int rxdw0;

	unsigned int rxdw1;
};

#define EOR BIT(30)

#define MAX_RX_QUEUE		1 // MSDU packet queue, Rx Command Queue

struct rtw_rx_ring {
	struct rxbd_t	*buf_desc;
	dma_addr_t		dma;
	unsigned int	idx;
#ifdef CONFIG_EXTRA_ALLOC_RXBUF
	u8 *rx_buf[RX_Q_DESC_NUM];
#else
	struct sk_buff	*rx_buf[RX_Q_DESC_NUM];
#endif
};

#ifdef CONFIG_G2_WIFI
struct rtw_csi_radar_rxbd {
	u8 **csi_radar_buf;
	u32 buffer_size;
	u8 buffer_num;
};
#endif


struct rx_sc_entry {
	u8 shortcut_hdr[2 * ETH_ALEN];
	u8 wifi_addr[3 * ETH_ALEN]; //A1 A2 A3
	u8 b_rxsc_ent_dirty;//0 is free, 1 is alloced
};

struct promisc_priv {
	u8 promisc_enabled;
	u8(*promisc_rx_callback)(struct rtw_rx_pkt_info *pkt_info);
	u8 filter_mode;
	u8 rom_rsvd[3];
};

struct recv_defrag_ctrl {
	struct timer_list		defrag_timer; 	/* for free defrag memory */
	u8 *pfragbuf;
	u32 len;
	u8 latest_frag_num;
	u8 rom_rsvd[3];
};

struct sta_recv_priv {
	struct recv_reorder_ctrl	*recvreorder_ctrl[MAXTID];	/* for A-MPDU Rx reordering buffer control */
	u16 tid_rxseq[16];
	struct recv_defrag_ctrl	defrag_ctrl;	/* Maintain 32 bytes for original ROM code */
	u16 rom_rsvd;
};

struct recv_buf {
	struct list_head list;
	struct _ADAPTER *padapter;
	u32	len;
	u8	*phead;
	u8	*pdata;
	u8	*ptail;
	u8	*pend;
	struct sk_buff	*pskb;
};

/*
	head  ----->

		data  ----->

			payload

		tail  ----->


	end   ----->

	len = (unsigned int )(tail - data);

*/
struct recv_frame_hdr {
	struct list_head	list;

	struct sk_buff	 *pkt;

	struct rx_pkt_attrib attrib;

	u32  len;
	u8 *rx_head;
	u8 *rx_data;
	u8 *rx_tail;
	u8 *rx_end;

	struct sta_mlme_priv *psta_mlmepriv;

	u8 iface_type;

	u8 rom_rsvd[2];
};

union recv_frame {
	union {
		struct list_head list;
		struct recv_frame_hdr hdr;
		uint mem[RECVFRAME_HDR_ALIGN >> 3];
	} u;
};

enum _RX_PACKET_TYPE {
	NORMAL_RX = 0,//Normal rx packet
	CH_INFO_NDPA = 1,//Channel info trigger by NDPA or normal pkt
	CH_INFO_RSP = 2,//Channel info trigger by response pkt
	RADAR_RPT = 3,//radar rpt
	PPDU_STATUS = 4,// phystatus
	C2H_PACKET = 5
};

#endif // _RTW_RECV_H_

