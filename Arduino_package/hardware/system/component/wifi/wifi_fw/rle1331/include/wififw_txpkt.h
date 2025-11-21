#ifndef __WIFIFW_TXPKT_H__
#define __WIFIFW_TXPKT_H__
//1331 todo reg define
#if CONFIG_AMEBAL2
#define BIT_R_WMAC_BCN_BMC_MASK				BIT_WMAC_BCN_BMC_MASK
#define BIT_WL_PMC_LPS_EN                    BIT_WL_PMC_LPS
#define BIT_WL_PMC_OFFMAC                    BIT_WL_PMC_POFF
#define BIT_WL_PMC_ONMAC                     BIT_WL_PMC_PON         /*!<R/W 0  Inform WLAN PMC FSM to power On mode, include clock, isolation, power control for MAC only (clear when Power Ready) */

#define BIT_FEN_BBRSTB_V2 					BIT_FEN_BB_RSTB
#define BIT_FEN_BB_GLB_RSTN_V2				BIT_FEN_BB_GLB

#endif

/*--------------------------Define -------------------------------------------*/
// retry limit
#define RTY_LMT_NULLDATA			8
#define RTY_LMT_QNULL				8
#define RTY_LMT_BTQNULL			8
#define RTY_LMT_ARP					24
#define RTY_LMT_PSPOLL				24
#define RTY_LMT_NDP					24
#define RTY_LMT_CTS2SELF			0	//Alan ,use 0 is correct, suggest by Ausin-Lo

//issue rsvdpage marco
#define _ISSUE_BTQNULL				1
#define _ISSUE_DBGPKT_				2
#define _ISSUE_FCSNULL_				3
#define _ISSUE_LTEQNULL_      		4
#define _ISSUE_NDPA_           		5
#define _ISSUE_PROBERSP_			6
#define _ISSUE_PROBEREQ_			7
#define _ISSUE_GTKRSP_            	8
#define _ISSUE_PSPOLL_            	9
#define _ISSUE_NULL_             	10
#define _ISSUE_QNULL_           	11
#define _ISSUE_CTS2SELF_        	12
#define _ISSUE_REALWOW_KA_     		13
#define _ISSUE_RS_          		14
#define _ISSUE_BUBBLE_        		15
#define _ISSUE_ARP_RESPONSE_        16
#define _ISSUE_NA_            		17
#define _ISSUE_KEEPALIVE_NULL_      18
#define _ISSUE_CSI_ACTION_          19
#define _ISSUE_RA_NULL_				20
#define _ISSUE_ARP_KEEPALIVE_        21

//Tx pause set
#define NO_PAUSE                    0x0
#define PAUSE_EXCEPT_CMGQ_MGQ       0x1EF
#define PAUSE_EXCEPT_CMGQ           0x1EF
#define PAUSE_ALL                   0x1FF
#define PAUSE_AC_QUEUE              0xF

#define DEPTH_CPUMGQ_TXQ			0x4
#define CPUMGQ_TX_FULL(x, y)				(((((x) == 0) && ((y) == (DEPTH_CPUMGQ_TXQ - 1)))||((y) == ((x) - 1))) ? TRUE : FALSE)
#define CPUMGQ_TX_EMPTY(x, y)				(((x) == (y)) ? TRUE : FALSE)
#define CPUMGQTXPTR_REACH_BOTTOM(x)		(((x) == DEPTH_CPUMGQ_TXQ) ? TRUE : FALSE)

#define	TX_PS_POLL					BIT0
#define	TX_NULL						BIT1
#define	TX_QOSNULL					BIT2
#define	TX_BTQOSNULL				BIT3
#define	TX_CSI						BIT4
#define	TX_ARP						BIT5

//1331 for FW CPUMGQ TX

struct fw_rsvdpage {
	u8 *ps_poll;        //start address of pspoll pkt (tx descriptor)
	u8 *null;
	u8 *qosnull;
	u8 *bt_qosnull;
	u8 *csi;
	u8 *arp;
};

struct fw_cpumgq {
	struct fw_rsvdpage rsvdpage;
	u8 pktid_tx_notdone_bitmap;//8 BIT
	u8 pkt_tx_notdone_list[DEPTH_CPUMGQ_TXQ];
	u8 pkt_tx_in_txbd_pointer;
	u8 pkt_tx_rls_pointer;
};


/*--------------------Function declaration---------------------------------*/
extern struct fw_cpumgq fwpkt;
extern void wififw_irq_register(bool on);
extern void wififw_init_ready(bool on);
extern void wififw_txpkt_set_pause_status(u16 tx_pause);
extern u16 wififw_txpkt_get_pause_status(void);
extern u32 GetMACHeaderAddr(u32 offset);
extern u32 wififw_txrls_fifo_read(void);
extern u8 wififw_txrls_fifo_valid_check(void);
extern u8 wififw_txbd_enough_check(void);
extern void wififw_txpkt_set_power_bit(u8 bPowerBit, u32 offset);
extern void wififw_txpkt_mac_power_bit_ctrl(u8 TxInd, u8 bPowerBit);
extern u32 wififw_txpkt_get_txaddr(u8 TxInd);
extern void wififw_txpkt_set_fields(u32 offset, u8 bPowerBit, u8 RtyLmt, u8 TxInd);
extern u8 wififw_txpkt_cpumgq(u8 bPowerBit, u8 RtyLmt, u8 TxInd);
extern void wififw_inthdl_cpumgq_txdone(void);
extern u8 wififw_cpumgq_txbd_inqueue(u32 txaddr);
extern void wififw_inthdl_fw_rlsfifo_valid(void);
extern void wififw_txpkt_pspoll(void);
extern void wififw_txpkt_qosnulldata(u8 bPowerBit);
extern u8 wififw_txpkt_nulldata(u8 bPowerBit, u8 RtyLmt, u8 TxInd);
extern void wififw_btc_issue_bt_qnull(u8 bPowerBit, u16 NAV);
extern u8 wififw_check_csichinfo_buf_empty(void);
#endif  /* __WIFIFW_TXPKT_H__ */