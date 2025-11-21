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
#ifndef _RTW_XMIT_H_
#define _RTW_XMIT_H_

/*--------------------------------------------------------------*/
/*  Define XMITBUF_ALIGN_SZ										*/
/*--------------------------------------------------------------*/
#define XMITBUF_ALIGN_SZ 4

#define MAX_CMDBUF_SZ	(5120)	//(4096)
/*--------------------------------------------------------------*/
/*  Define xmit extension buff, size/numbers							*/
/*--------------------------------------------------------------*/
#define MAX_XMIT_EXTBUF_SZ	(1536)

#define NR_XMIT_EXTBUFF		(8)	//Decrease ext xmit buffer due to memory limitation - Alex Fang

#define RTS_THRESH 2347

#define	nr_xmitframe 2
#define TXBD_SIZE    32 //sizeof(struct txbd_t) 

#define WEP_IV(pattrib_iv, dot11txpn, keyidx)\
do{\
	pattrib_iv[0] = dot11txpn._byte_.TSC0;\
	pattrib_iv[1] = dot11txpn._byte_.TSC1;\
	pattrib_iv[2] = dot11txpn._byte_.TSC2;\
	pattrib_iv[3] = ((keyidx & 0x3)<<6);\
	dot11txpn.val = (dot11txpn.val == 0xffffff) ? 0: (dot11txpn.val+1);\
}while(0)


#define TKIP_IV(pattrib_iv, dot11txpn, keyidx)\
do{\
	pattrib_iv[0] = dot11txpn._byte_.TSC1;\
	pattrib_iv[1] = (dot11txpn._byte_.TSC1 | 0x20) & 0x7f;\
	pattrib_iv[2] = dot11txpn._byte_.TSC0;\
	pattrib_iv[3] = BIT(5) | ((keyidx & 0x3)<<6);\
	pattrib_iv[4] = dot11txpn._byte_.TSC2;\
	pattrib_iv[5] = dot11txpn._byte_.TSC3;\
	pattrib_iv[6] = dot11txpn._byte_.TSC4;\
	pattrib_iv[7] = dot11txpn._byte_.TSC5;\
	dot11txpn.val = dot11txpn.val == 0xffffffffffffULL ? 0: (dot11txpn.val+1);\
}while(0)

#define AES_IV(pattrib_iv, dot11txpn, keyidx)\
do{\
	pattrib_iv[0] = dot11txpn._byte_.TSC0;\
	pattrib_iv[1] = dot11txpn._byte_.TSC1;\
	pattrib_iv[2] = 0;\
	pattrib_iv[3] = BIT(5) | ((keyidx & 0x3)<<6);\
	pattrib_iv[4] = dot11txpn._byte_.TSC2;\
	pattrib_iv[5] = dot11txpn._byte_.TSC3;\
	pattrib_iv[6] = dot11txpn._byte_.TSC4;\
	pattrib_iv[7] = dot11txpn._byte_.TSC5;\
	dot11txpn.val = dot11txpn.val == 0xffffffffffffULL ? 0: (dot11txpn.val+1);\
}while(0)

#define GCMP_IV(pattrib_iv, dot11txpn, keyidx)\
do {\
	pattrib_iv[0] = dot11txpn._byte_.TSC0;\
	pattrib_iv[1] = dot11txpn._byte_.TSC1;\
	pattrib_iv[2] = 0;\
	pattrib_iv[3] = BIT(5) | ((keyidx & 0x3)<<6);\
	pattrib_iv[4] = dot11txpn._byte_.TSC2;\
	pattrib_iv[5] = dot11txpn._byte_.TSC3;\
	pattrib_iv[6] = dot11txpn._byte_.TSC4;\
	pattrib_iv[7] = dot11txpn._byte_.TSC5;\
	dot11txpn.val = dot11txpn.val == 0xffffffffffffULL ? 0 : (dot11txpn.val+1);\
} while (0)

#define TX_FRAGMENTATION_THRESHOLD 	2346

//#ifdef TX_SHORTCUT
#define TX_SC_ENTRY_NUM 		3
//#endif

union Keytype {
	u8   skey[16];
	u32  lkey[4];
};

union Keytype_32 {
	u8   skey[32];
	u32  lkey[8];
};
// Suppose (TX_DESC_MODE=1) ==> Segment number for each txbd_t is 4. 2X4 = 8 (double words).
struct txbd_t {
	unsigned int txdw0;
	unsigned int txdw1;
	unsigned int txdw2;
	unsigned int txdw3;
	unsigned int txdw4;
	unsigned int txdw5;
	unsigned int txdw6;
	unsigned int txdw7;
};

struct tx_desc {
	//DWORD 0
	unsigned int txdw0;
	unsigned int txdw1;
	unsigned int txdw2;
	unsigned int txdw3;
	unsigned int txdw4;
	unsigned int txdw5;
	unsigned int txdw6;
	unsigned int txdw7;
#if defined(CONFIG_LX_HCI)|| \
	defined(CONFIG_RTL8730A) || defined(CONFIG_AMEBALITE) || defined(CONFIG_AMEBASMART) || defined(CONFIG_AMEBASMARTPLUS) || defined(CONFIG_AMEBADPLUS) || defined(CONFIG_AMEBAD) || defined(CONFIG_AMEBAGREEN2)
	unsigned int txdw8;
	unsigned int txdw9;
#endif
};

union txdesc {
	struct tx_desc txdesc;
	unsigned int value[TXDESC_SIZE >> 2];
};

struct rtw_tx_ring {
	struct txbd_t	*buf_desc;
	dma_addr_t		*dma;
	struct __queue	queue;
	u8		idx;
	u8		entries;
	u8		qlen;
};

//reduce size
struct pkt_attrib {
	u8	b_swenc : 1;
	u8	b_qos_en : 1;
	u8	b_relay_packet : 1;
	u8	b_fix_rate : 1;
	u8	b_ht_en : 1;
	u8	b_ampdu_en : 1; //tx ampdu enable
	u8	b_mdata : 1; //more data bit
	u8	b_tx_eosp : 1;
	u8	b_tx_order : 1; // +htc/order bit: fc->bit15
	u8	b_tx_navusehdr : 1;	//NAVUSEHDR
	u8	b_fllldesc_raw : 1;
	u8	b_tx_raw : 1;
	u8	b_dhcp_pkt : 1;
	u8	vcs_mode : 3;	//virtual carrier sense method
	u8	bwmode : 3;

	u8	encrypt : 4;	//when 0 indicate no encrypt. when non-zero, indicate the encrypt algorith
	u8	b_tx_sgi : 4; //short GI

	u8	rom_rsvd[2];

	u32	pktlen;		//the original 802.3 pkt raw_data len (not include ether_hdr data)
	u16	ether_type;
	u16	seqnum;
	u16	hdrlen;		//the WLAN Header Len
	u16	last_txcmdsz;

	u8	pkt_hdrlen;	//the original 802.3 pkt header len
	u8	type_subtype;
	u8	iv_len;
	u8	icv_len;
	u8	iv[18];
	u8	priority;
	u8	ack_policy;
	u8	mac_id;
	u8 	dst[ETH_ALEN];
	u8	src[ETH_ALEN];
	u8	ta[ETH_ALEN];
	u8 	ra[ETH_ALEN];
	u8	key_idx;
	u8	raid;//rate adpative id
	u8	ch_offset;//PRIME_CHNL_OFFSET
	u8	qsel;
	u8	rate;
	u8 	retry_limit_by_user; //for user control retry limit
	u8 	tx_done_id;

//#ifdef TX_SHORTCUT
	u8 ether_hdr[14];
//#endif

//#if defined (CONFIG_CLINTWOOD) && CONFIG_CLINTWOOD
	u8 rate_fallback_table_idx;
//#endif
//#ifdef CONFIG_WIFI_TUNNEL
	u8	wtunnel_tx_swap;
	u8 	wtunnel_ul_swap;
//#endif

//#ifdef CONFIG_WMMPS_STA
	u8 uapsd_trigger;
//#endif
//#ifdef CONFIG_NAN
	u8 nan_pkt_type;
	u8 key_type;
//#endif
};

#define NULL_FRAMETAG		(0x0)
#define DATA_FRAMETAG		0x01
#define MGNT_FRAMETAG		0x03
#define MP_FRAMETAG		0x07

enum {
	XMITBUF_DATA = 0,
	XMITBUF_MGNT = 1,
	XMITBUF_CMD = 2,
};

enum {
	RTW_SCTX_DONE_SUCCESS = 0,
	RTW_SCTX_DONE_UNKNOWN,
	RTW_SCTX_DONE_BUF_ALLOC,
	RTW_SCTX_DONE_BUF_FREE,
};

struct xmit_frame {
	struct list_head			list;
	struct pkt_attrib	attrib;
	struct sk_buff			*pkt;
	int			frame_tag;
//#ifdef TX_SHORTCUT
	int tx_shortcut_idx;
//#endif
	u8 iface_type;
	u8 b_need_polling : 1;
	u8	rom_rsvd;
};

struct pending_sta_t {
	struct list_head	list;
	struct __queue	frame_queue;
	int qcnt;
};

struct sta_xmit_priv {
	struct timer_list		addba_retry_timer;		/* for A-MPDU TX, ADDBA timeout check */
	struct pending_sta_t	sta_pending_queue;
	u16 txseq_tid[MAXTID];
	u16 ba_starting_seqctrl[MAXTID];
	u8	addba_compat[8];		/* for ap compatibility */
};

struct pkt_file {
	struct sk_buff *pkt;
	size_t pkt_len;	 //the remainder length of the open_file
	u8 *cur_buffer;
	u8 *buf_start;
	u8 *cur_addr;
	size_t buf_len;
};

#endif //_RTW_XMIT_H_

