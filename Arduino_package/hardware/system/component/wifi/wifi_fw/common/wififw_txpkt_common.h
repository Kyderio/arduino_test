#ifndef __WIFIFW_TXPKT_COMMON_H__
#define __WIFIFW_TXPKT_COMMON_H__

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
#define _ISSUE_ARP_RESPONSE_         16
#define _ISSUE_NA_            		17
#define _ISSUE_KEEPALIVE_NULL_      18
#define _ISSUE_CSI_ACTION_          19
#define _ISSUE_RA_NULL_				20
#define _ISSUE_ARP_KEEPALIVE_        21

//Tx pause set
#define NO_PAUSE                    0x0
#define PAUSE_EXCEPT_CMGQ_MGQ       0x6F
#define PAUSE_EXCEPT_CMGQ           0xEF
#define PAUSE_ALL                   0xFF
#define PAUSE_AC_QUEUE              0xF

/*--------------------Function declaration---------------------------------*/
extern void wififw_irq_register(bool on);
extern void wififw_init_ready(bool on);
extern void wififw_txpkt_set_pause_status(u8 tx_pause);
extern u8 wififw_txpkt_get_pause_status(void);
extern void wififw_txpkt_set_power_bit(u8 bPowerBit, u16 offset);
extern void wififw_txpkt_mac_power_bit_ctrl(u8 bPowerBit);
extern bool wififw_txpkt_wait_cpumgq_empty(void);
extern u16 wififw_txpkt_set_fields(u8 PageNum, u8 bPowerBit,  u8 RtyLmt,  u8 TxInd);
extern u8 wififw_txpkt_cpumgq(u8 bPowerBit, u8 RtyLmt, u8 loc_rsvdpage, u8 TxInd);
extern void wififw_txpkt_pspoll(void);
extern void wififw_txpkt_qosnulldata(u8 bPowerBit);
extern u8 wififw_txpkt_nulldata(u8 bPowerBit, u8 RtyLmt, u8 TxInd);
extern void wififw_btc_issue_bt_qnull(u8 bPowerBit, u16 NAV);
extern u32 wififw_txpkt_get_txaddr(u8 TxInd);
#endif  /* __WIFIFW_TXPKT_H__ */
