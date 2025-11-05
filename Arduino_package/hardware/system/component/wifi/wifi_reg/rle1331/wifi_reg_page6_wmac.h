#ifndef _RL6955_REG_PAGE6_WMAC_H_
#define _RL6955_REG_PAGE6_WMAC_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE6_WMAC
  * @brief REG_PAGE6_WMAC driver modules
  * @{
  */




/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE6_WMAC_Register_Definitions REG_PAGE6_WMAC Register Definitions
  * @{
  */

/** @defgroup REG_WMAC_CR
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_RXUC_BBYE_MACID   ((u32)0x0000007F << 7)           /*!< R 0x0  when rx handshake relay byebye frame,update macid of the transmitter to this reg*/
#define BIT_WMAC_RXUC_BBYE_MACID(x)     (((u32)((x) & 0x0000007F) << 7))
#define BIT_GET_WMAC_RXUC_BBYE_MACID(x) ((u32)(((x >> 7) & 0x0000007F)))
#define BIT_TRIGGER_TSFT_EN             ((u32)0x00000001 << 6)           /*!< R/W 0x0  When set, enable sync tsft from trigger*/
#define BIT_DIS_ADDRCAM                 ((u32)0x00000001 << 5)           /*!< R/W 0x0  When set,disable filtercam funciton,and use old filter*/
#define BIT_SP_A3_MODE                  ((u32)0x00000001 << 4)           /*!< R/W 0x0  When set,enable search macid cam using rxa3. The packet will send to driver when rxa3 match and fcs ok*/
#define BIT_SP_A1_MODE                  ((u32)0x00000001 << 3)           /*!< R/W 0x0  When set,enable search macid cam using rxa1*/
#define BIT_BOOSTER_MODE                ((u32)0x00000001 << 2)           /*!< R/W 0x0  When set,enable booster mode. Realy and booster are not used samtime*/
#define BIT_RELAY_MODE                  ((u32)0x00000001 << 1)           /*!< R/W 0x0  When set,enable relay mode. Realy and booster are not used samtime*/
#define BIT_REPEAT_MODE                 ((u32)0x00000001 << 0)           /*!< R/W 0x0  When set,enable repeat mode*/
/** @} */

/** @defgroup REG_TCR
  * @brief Transmission Configuration Register
  * @{
  */
#define BIT_TXPWR_CTL_DISGCLK        ((u32)0x00000001 << 31) /*!< R/W 0x0  1:txpwr_ctl clock gating disable 0:txpwr_ctl clock gating enable*/
#define BIT_WMAC_MORE_DATA           ((u32)0x00000001 << 30) /*!< R/W 0x0  when set top 1, set more data bit to 1 in ACK/BA/MBA*/
#define BIT_WMAC_NOTX_IN_RXNDP       ((u32)0x00000001 << 28) /*!< R/W 0x0  1: block original tx when receiving NDP packet*/
#define BIT_WMAC_EN_EOF              ((u32)0x00000001 << 27) /*!< R/W 0x0  when set to 1, enable single ampdu for qos data packet. In early mode,not set to 1.*/
#define BIT_WMAC_BF_SEL              ((u32)0x00000001 << 26) /*!< R/W 0x0  1: set ndp_rx_standby when rx ppdu of ndpa end; 0: set ndp_rx_standby when rx ndpa packet fcs end;*/
#define BIT_WMAC_TCR_PWRMGT_HWCTL    ((u32)0x00000001 << 24) /*!< R/W 0x0  If this bit is set to 1, MAC will overwrite power bit of frame control according to  PWR_ST.  (only for RTS/CTS/ACK/CFEND/BA/BAR frames)*/
#define BIT_WMAC_SMOOTH_VAL          ((u32)0x00000001 << 23) /*!< R/W 0x0  smooth value of plcp header HTSIG2*/
#define BIT_WMAC_EN_SCRAM_INC        ((u32)0x00000001 << 22) /*!< R/W 0x0  Increase 1 in service field scrambler seed per tx end*/
#define BIT_FETCH_MPDU_AFTER_WSECRDY ((u32)0x00000001 << 20) /*!< R/W 0x1  If set to 1,mactx_mpdu_gen will fetch mpdu after wsec is ready when sectype is not tkip/wep40/wep104*/
#define BIT_WMAC_DIS_SIGTA           ((u32)0x00000001 << 18) /*!< R/W 0x0  when set to 1, disable signaling TA information for response packet*/
#define BIT_WMAC_DIS_A2B0            ((u32)0x00000001 << 17) /*!< R/W 0x0  when set to 1, not check bit 0 of rx a2*/
#define BIT_WMAC_MSK_SIGBCRC         ((u32)0x00000001 << 16) /*!< R/W 0x0  when set to 1, mask sigb crc in service field  for vht packet*/
#define BIT_WMAC_TCR_TXSK_PERPKT     ((u32)0x00000001 << 11) /*!< R/W 0x0  Search key for each mpdu*/
#define BIT_WMAC_TCR_ICV             ((u32)0x00000001 << 10) /*!< R/W 0x0  Integrity Check Value. This bit indicates the existence of an ICV appended to an encipherment packet. 1: No ICV appended 0: ICV appended*/
#define BIT_WMAC_TCR_CFENDFORM       ((u32)0x00000001 << 9)  /*!< R/W 0x0  CF-End Frame Format.The Address 2 field of CF-End is defined to be the address of the STA contained in the AP, but in 802.11n a STA can also send CF-End.The Address 2 field is not specified clearly in this case. This register chooses between MAC ID of the STA or BSSID of the network. 0: BSSID 1: MAC ID*/
#define BIT_WMAC_TCR_CRC             ((u32)0x00000001 << 8)  /*!< R/W 0x0  Append 32-bit Cyclic Redundancy Check. This bit indicates the existence of a CRC32 appended to a packet. 1: No CRC32 appended 0: A CRC32 is appended*/
#define BIT_WMAC_TCR_PWRMGT_CTL      ((u32)0x00000001 << 7)  /*!< R/W 0x0  If this bit is set to 1, MAC will overwrite power bit of frame control according to PWR_ST. (only for data frame)*/
#define BIT_WMAC_TCR_PWRMGT_VAL      ((u32)0x00000001 << 6)  /*!< R/W 0x0  MAC will overwrite power bit of frame control according to PWR_ST.(only for data frame)*/
#define BIT_WMAC_TCR_UPD_TIMIE       ((u32)0x00000001 << 5)  /*!< R/W 0x0  when set to 1, enable hw to update beacon's time field*/
#define BIT_WMAC_TCR_VHTSIGA1_TXPS   ((u32)0x00000001 << 3)  /*!< R/W 0x0  This bit controls TXOP_PS_NOT_ALLOWED bit value of VHT-SIG-A1 field in TX VHT packets 1: TXOP_PS_NOT_ALLOWED is set to 1 0: TXOP_PS_NOT_ALLOWED is set to 0*/
#define BIT_WMAC_TCR_PADSEL          ((u32)0x00000001 << 2)  /*!< R/W 0x0  AMPDU Padding pattern selection 0: 32-bit Zero padding,  1: Zero length delimiter.*/
#define BIT_WMAC_TCR_DISGCLK         ((u32)0x00000001 << 1)  /*!< R/W 0x0  when set to 1,disable MACTX clock gating control.*/
/** @} */

/** @defgroup REG_RCR
  * @brief Receive Configuration Register
  * @{
  */
#define BIT_WMAC_RCR_APP_FCS       ((u32)0x00000001 << 31) /*!< R/W 0x0  When set, wmac RX will append FCS after payload.*/
#define BIT_WMAC_RCR_APP_MIC       ((u32)0x00000001 << 30) /*!< R/W 0x0  When this bit is set to 1, MACRX will retain the MIC at the bottom of the packet. Otherwise, MIC will be removed and reported the status in RXDESC. When a MPDU is encrypted with TKIP without MIC, MACRX will ignore this option, that is, MIC must be remained in back of the plain text.*/
#define BIT_WMAC_RCR_APP_ICV       ((u32)0x00000001 << 29) /*!< R/W 0x0  When this bit is set to 1, MACRX will retain the ICV at the bottom of the packet. Otherwise, MIC will be removed and reported the status in RXDESC.*/
#define BIT_WMAC_RCR_APP_PHYSTS    ((u32)0x00000001 << 28) /*!< R/W 0x0  Append RXFF0 PHY Status Enable When this bit is set, then PHY Status is appended before RX packet in RXFF. When this bit is set, the RX_DRV_INFO_SZ shall be set to include PHY Status report.*/
#define BIT_WMAC_RCR_VHT_DACK      ((u32)0x00000001 << 26) /*!< R/W 0x0  This bit to control response type for vht single mpdu data packet. 1: ACK as response 0: BA as response*/
#define BIT_WLAN_RX_REQ_SIFS_CLR   ((u32)0x00000001 << 23) /*!< R/W 0x0  */
#define BIT_WMAC_RCR_MFBEN         ((u32)0x00000001 << 22) /*!< R/W 0x0  Enable immediate MCS Feedback function 1: Enable. When Rx packet with MRQ = 1"b1, then search KEYCAM to find sender"s MCS Feedback function and send response 0: Disable*/
#define BIT_WMAC_RCR_DISCHKPPDULEN ((u32)0x00000001 << 21) /*!< R/W 0x0  When set,do not check PPDU while the PPDU length is smaller than 14 byte.*/
#define BIT_WMAC_RCR_PKTCTL_DLKEN  ((u32)0x00000001 << 20) /*!< R/W 0x0  When set,while rx path dead lock occurs, reset rx path*/
#define BIT_WMAC_RCR_DISGCLK       ((u32)0x00000001 << 19) /*!< R/W 0x0  When set,disable macrx clock gating control*/
#define BIT_WMAC_RCR_TIMPSR_EN     ((u32)0x00000001 << 18) /*!< R/W 0x0  When set, enable RX Beacon TIM Parser*/
#define BIT_WMAC_RCR_BCMDINT_EN    ((u32)0x00000001 << 17) /*!< R/W 0x0  Broadcast data packet interrupt enable. When this bit is set, this bit is auto clear by MAC. As long as a data type broadcast packet is received, this bit will be set.*/
#define BIT_WMAC_RCR_UCMDINT_EN    ((u32)0x00000001 << 16) /*!< R/W 0x0  Unicast data packet with FC.MD = 1 interrupt enable. When this bit is set, this bit is auto clear by MAC. As long as a data type unicast packet is received, this bit will be set.*/
#define BIT_WMAC_RCR_RXSK_PERPKT   ((u32)0x00000001 << 15) /*!< R/W 0x0  Executing key search per MPDU*/
#define BIT_WMAC_RCR_HTCBFMC       ((u32)0x00000001 << 14) /*!< R/W 0x0  1: HTC -> MFC 0: MFC-> HTC*/
#define BIT_WMAC_RCR_CHK_PREVTXA2  ((u32)0x00000001 << 13) /*!< R/W 0x0  When set,enable check rxa1 with txa2.*/
#define BIT_WMAC_RCR_ACK_CBSSID    ((u32)0x00000001 << 12) /*!< R/W 0x0  The field effects behavior of BA/ACK frame.                                                                                       0:Only A1 match to send BA/ACK frame.                                                                                                1:A1 match and satisfy BSSID condition(if BIT_CBSSID_DATA = 1) will send BA/ACK frame. If BIT_CBSSID_DATA = 0, hardware send BA/ACK frame decided by A1 match condition.*/
#define BIT_WMAC_RCR_CHKTA_MGNT    ((u32)0x00000001 << 11) /*!< R/W 0x0  Check TransmitteBCN When set to 1, MAC will check the Transmitter Address (A2) of RX beacon or Probe response to determine if this packet belongs to this Transmitter Address (Address 2) . Both in  Infrastructure mode and  Ad-hoc mode.*/
#define BIT_WMAC_RCR_DISDECNMYPKT  ((u32)0x00000001 << 10) /*!< R/W 0x0  This bit determines whether hw need to do decryption. 0: If A1 match or broadcast, do decryption. 1: Do decryption,do not check A1*/
#define BIT_WMAC_RCR_AICV          ((u32)0x00000001 << 9)  /*!< R/W 0x0  Accept Integrity Check Value Error packets. This bit determines whether packets with ICV errors will be accepted or rejected. 1: Accept 0: Reject*/
#define BIT_WMAC_RCR_ACRC32        ((u32)0x00000001 << 8)  /*!< R/W 0x0  Accept CRC32 Error packets. When set to 1, packets with CRC32 errors will be accepted. When set to 0, packets with CRC32 errors will be rejected. 1: Accept 0: Reject*/
#define BIT_WMAC_RCR_CBSSID_MGNT   ((u32)0x00000001 << 7)  /*!< R/W 0x0  Check BSSID_BCN When set to 1, MAC will check the BSSID of RX beacon or Probe response to determine if this packet belongs to this BSSID.*/
#define BIT_WMAC_RCR_CBSSID_DATA   ((u32)0x00000001 << 6)  /*!< R/W 0x0  Check BSSID_DATA, To DS, From DS Match Packet. When set to 1, MAC will check the Rx data type frame"s BSSID, To DS, and From DS fields, to determine if it is set to Link OK in an Infrastructure or Ad hoc network. Note this setting is independent of nettype. Driver must set this bit in ad hoc mode and client mode.*/
#define BIT_WMAC_RCR_APWRMGT       ((u32)0x00000001 << 5)  /*!< R/W 0x0  Accept Power Management Packet. This bit determines whether the RTL8192D will accept or reject packets with the power management bit set. 1: Accept 0: Reject*/
#define BIT_WMAC_RCR_ADD3          ((u32)0x00000001 << 4)  /*!< R/W 0x0  Accept Address 3 Match Packets. Set this bit to 1 to accept broadcast/multicast data type frames that Address 3 matching RTL8190"s MAC address. This bit is valid only when NETYPE (bit 3-2, MSR) is set to Link OK on an Infrastructure network.*/
#define BIT_WMAC_RCR_AB            ((u32)0x00000001 << 3)  /*!< R/W 0x0  Accept Broadcast packets. This bit determines whether broadcast packets will be accepted or rejected. 1: Accept 0: Reject*/
#define BIT_WMAC_RCR_AM            ((u32)0x00000001 << 2)  /*!< R/W 0x0  Accept Multicast packets. This bit determines whether multicast packets will be accepted or rejected. 1: Accept 0: Reject*/
#define BIT_WMAC_RCR_APM           ((u32)0x00000001 << 1)  /*!< R/W 0x0  Accept Physical Match packets. This bit determines whether physical match packets will be accepted or rejected. 1: Accept 0: Reject*/
#define BIT_WMAC_RCR_AAP           ((u32)0x00000001 << 0)  /*!< R/W 0x0  Accept Destination Address packets. This bit determines whether packets with a destination address will be accepted or rejected.  1: Accept 0: Reject*/
/** @} */

/** @defgroup REG_RXPKT_CTL
  * @brief RX Packet Control Register
  * @{
  */
#define BIT_MASK_PHYSTS_WTIME         ((u32)0x00000007 << 28)           /*!< R/W 0x3  wait physts timeout timer, unit 16 mac clock*/
#define BIT_PHYSTS_WTIME(x)           (((u32)((x) & 0x00000007) << 28))
#define BIT_GET_PHYSTS_WTIME(x)       ((u32)(((x >> 28) & 0x00000007)))
#define BIT_WMAC_EXT_DBGSEL           ((u32)0x00000001 << 26)           /*!< R/W 0x0  enable extend dbg port sel*/
#define BIT_MASK_RXGCK_DLY_SEL        ((u32)0x00000007 << 23)           /*!< R/W 0x2  MAC_RX wait some time to gate clock after making the decision (about gating clock). Unit: T (MAC clock cycle) 0: 0 1: 2 2: 4 3: 8 4: 16 5: 32 6: 64 7: 128*/
#define BIT_RXGCK_DLY_SEL(x)          (((u32)((x) & 0x00000007) << 23))
#define BIT_GET_RXGCK_DLY_SEL(x)      ((u32)(((x >> 23) & 0x00000007)))
#define BIT_BB_RST_RESP               ((u32)0x00000001 << 22)           /*!< R/W 0x0  When set to 1,enable bb/rdrdy_err/cca_spoofing to reset mac and will not tx response*/
#define BIT_MASK_RXD_OFFSET_SEL       ((u32)0x00000003 << 20)           /*!< R/W 0x0  select 2bytes of rxd to debug port 0: 0~1 bytes; 1: 2~3 bytes; 2: 4~5 bytes; 3: 6~7 bytes;*/
#define BIT_RXD_OFFSET_SEL(x)         (((u32)((x) & 0x00000003) << 20))
#define BIT_GET_RXD_OFFSET_SEL(x)     ((u32)(((x >> 20) & 0x00000003)))
#define BIT_MASK_WMAC_RX_DRVINFO_SZ   ((u32)0x00000007 << 16)           /*!< R/W 0x4  RX DESC Driver Info Size: For RXPKTBUF layout, this field indicates the offset starting from the end of RXDESC to the beginning of RX packet. The unit is 8-byte. This value will be copied to DRV_INFO_SIZE field in RXDESC.*/
#define BIT_WMAC_RX_DRVINFO_SZ(x)     (((u32)((x) & 0x00000007) << 16))
#define BIT_GET_WMAC_RX_DRVINFO_SZ(x) ((u32)(((x >> 16) & 0x00000007)))
#define BIT_MASK_WMAC_RX_DLK_TIME     ((u32)0x000000FF << 8)            /*!< R/W 0x04  macrx dead lock timer timeout value (unit in 4us). As data_on is deasserted and no RXD is received but macrx still waits coming RXD, the deadlock timer will be enabled in this case*/
#define BIT_WMAC_RX_DLK_TIME(x)       (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_WMAC_RX_DLK_TIME(x)   ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_RDRDY_NUM_CHK_EN          ((u32)0x00000001 << 7)            /*!< R/W 0x1  When set, enable check rdrdy number is enough or not. If number is not enough will rst macrx*/
#define BIT_NEW_RX_RST_EN             ((u32)0x00000001 << 6)            /*!< R/W 0x1  when set, enable new rx rst macrx when macrx is active*/
#define BIT_MASK_WMAC_RXPKTLMT        ((u32)0x0000003F << 0)            /*!< R/W 0x10  RX PKT Upper Limit. The unit is 512 bytes. When "0", no RX limit is forced.*/
#define BIT_WMAC_RXPKTLMT(x)          (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_WMAC_RXPKTLMT(x)      ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_MACID
  * @brief MAC ID Register
  * @{
  */
#define BIT_MASK_MACID0_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  MAC Identification Number Register BIT[31:0]. Relay mode, when r_P2_WTNAP=1, as relay STA addr; r_P2_WTNAP=0, as relay STA and relay AP addr*/
#define BIT_MACID0_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MACID0_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MACID_H
  * @brief MAC ID Register
  * @{
  */
#define BIT_P2_WTNAP        ((u32)0x00000001 << 19)          /*!< R/W 0x0  when relay mode, set1,use macid2 as port2 addr;  set0, use macid0 as port2 addr*/
#define BIT_EN_PORT2        ((u32)0x00000001 << 18)          /*!< R/W 0x0  When set1,enable NAN PORT2 funtion for nan rx and response. Relay mode set 0*/
#define BIT_EN_PORT1        ((u32)0x00000001 << 17)          /*!< R/W 0x1  When set1,enable PORT1*/
#define BIT_EN_PORT0        ((u32)0x00000001 << 16)          /*!< R/W 0x1  When set1,enable PORT0*/
#define BIT_MASK_MACID0_H   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  MAC Identification Number Register BIT[47:32], relay mode, when r_P2_WTNAP=1, as relay STA addr; r_P2_WTNAP=0, as relay STA and relay AP addr*/
#define BIT_MACID0_H(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MACID0_H(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BSSID
  * @brief BSSID Register
  * @{
  */
#define BIT_MASK_BSSID0_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Basic Station Set Identification BIT[31:0]*/
#define BIT_BSSID0_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BSSID0_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BSSID_H
  * @brief BSSID Register
  * @{
  */
#define BIT_MASK_BSSID0_H   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  Basic Station Set Identification BIT[47:32]*/
#define BIT_BSSID0_H(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BSSID0_H(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_LA_TRIGGER
  * @brief
  * @{
  */
#define BIT_MASK_TXTRIG_STOP_SEL   ((u32)0x0000001F << 24)           /*!< R/W 0x0  select tx trigger stop signal for LA dump*/
#define BIT_TXTRIG_STOP_SEL(x)     (((u32)((x) & 0x0000001F) << 24))
#define BIT_GET_TXTRIG_STOP_SEL(x) ((u32)(((x >> 24) & 0x0000001F)))
#define BIT_MASK_RXTRIG_STOP_SEL   ((u32)0x0000001F << 19)           /*!< R/W 0x0  select rx trigger stop signal for LA dump*/
#define BIT_RXTRIG_STOP_SEL(x)     (((u32)((x) & 0x0000001F) << 19))
#define BIT_GET_RXTRIG_STOP_SEL(x) ((u32)(((x >> 19) & 0x0000001F)))
#define BIT_MASK_TXTRIG_TYPE       ((u32)0x0000003F << 6)            /*!< R/W 0x0  mapping to frame control type and subtype filed, for LA trigger select*/
#define BIT_TXTRIG_TYPE(x)         (((u32)((x) & 0x0000003F) << 6))
#define BIT_GET_TXTRIG_TYPE(x)     ((u32)(((x >> 6) & 0x0000003F)))
#define BIT_MASK_RXTRIG_TYPE       ((u32)0x0000003F << 0)            /*!< R/W 0x0  mapping to frame control type and subtype filed, for LA trigger select*/
#define BIT_RXTRIG_TYPE(x)         (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_RXTRIG_TYPE(x)     ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_A1_ADDR_MASK
  * @brief A1 Addr Mask Register
  * @{
  */
#define BIT_MASK_WMAC_RXA1_MASK   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0xFFFFFFFF  mask rx A1 addr [39:8] for test*/
#define BIT_WMAC_RXA1_MASK(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_WMAC_RXA1_MASK(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_INVALID_PKT_CTL
  * @brief
  * @{
  */
#define BIT_RXGCK_OFDMCCA_EN        ((u32)0x00000001 << 11)          /*!< R/W 0x0  This bit is set to 1 to let OFDMCCA be one of the signals that can wakeup MAC from Rx_idle*/
#define BIT_MASK_RXPSF_PKTLEN_THR   ((u32)0x00000007 << 8)           /*!< R/W 0x0  Packet txtime threshold for invalid packet decision 3'd0:  32us 3'd1:  64us 3'd2:  128us 3'd3:  256us 3'd4:  512us 3'd5:  1024us 3'd6:  2048us 3'd7:  4096us Only the packet which txtime is longer than this threshold will trigger an invalid_pkt pulse.*/
#define BIT_RXPSF_PKTLEN_THR(x)     (((u32)((x) & 0x00000007) << 8))
#define BIT_GET_RXPSF_PKTLEN_THR(x) ((u32)(((x >> 8) & 0x00000007)))
#define BIT_RXPSF_OFDM_RSTEN        ((u32)0x00000001 << 7)           /*!< R/W 0x1  This bit is set to 1 to reset MAC Rx before sending OFDM (include OFDM, HT, VHT) packet triggered invalid_pkt pulse (0 for debug)*/
#define BIT_RXPSF_CCK_RSTEN         ((u32)0x00000001 << 6)           /*!< R/W 0x1  This bit is set to 1 to reset MAC Rx before sending CCK packet triggered invalid_pkt pulse(0 for debug)*/
#define BIT_RXPSF_MHCHKEN           ((u32)0x00000001 << 5)           /*!< R/W 0x0  1:enable MAC to inform BB enter power saving mode as rx unmatch my MACID unicast or unmatch my BSSID Broadcast/Mutlicast mpdu*/
#define BIT_RXPSF_AMCHKEN           ((u32)0x00000001 << 4)           /*!< R/W 0x0  1:enable MAC to inform BB enter power saving mode as rx unmatch my MACID unicast or unmatch my BSSID Broadcast/Mutlicast ampdu*/
/** @} */

/** @defgroup REG_PWRBIT_SETTING
  * @brief
  * @{
  */
#define BIT_WMAC_CLI0_PWRBIT_EN  ((u32)0x00000001 << 1) /*!< R/W 0x0  For client0 (port1). If this bit is set to 1, MAC will overwrite power bit of frame control according to CLI0_PWR_ST. (only for data frame)*/
#define BIT_WMAC_CLI0_PWRBIT_VAL ((u32)0x00000001 << 0) /*!< R/W 0x0  For client0 (port1). MAC will overwrite power bit of frame control according to CLI0_PWR_ST.(only for data frame)*/
/** @} */

/** @defgroup REG_WMAC_TCR_CTL
  * @brief
  * @{
  */
#define BIT_MASK_ZLD_NUM             ((u32)0x000000FF << 24)           /*!< R/W 0x8  Fetch zero length delimiter number(unit : 4bytes) when mactx underflow*/
#define BIT_ZLD_NUM(x)               (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_ZLD_NUM(x)           ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_UDF_THSD            ((u32)0x0000007F << 16)           /*!< R/W 0x6  [22]: enable underflow recovery;r_UDF_THSD[7]=0,disable underflow recovery; [21:16]: Underflow threshold*/
#define BIT_UDF_THSD(x)              (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_UDF_THSD(x)          ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_WMAC_TCR_TSFT_OFS   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  BIT_WMAC_TCR_TSFT_OFS[7:0] is for cck stamp time offset;  BIT_WMAC_TCR_TSFT_OFS[15:8] is for ofdm rate time offset;*/
#define BIT_WMAC_TCR_TSFT_OFS(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_WMAC_TCR_TSFT_OFS(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_STMP_THSD
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_TCR_E_TSFT_OFS   ((u32)0x000000FF << 8)           /*!< R/W 0x0  BIT_WMAC_TCR_TSFT_OFS[7:0] is for ht/vht/he stamp time offset;*/
#define BIT_WMAC_TCR_E_TSFT_OFS(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_WMAC_TCR_E_TSFT_OFS(x) ((u32)(((x >> 8) & 0x000000FF)))
/** @} */

/** @defgroup REG_USTIME_EDCA
  * @brief US Time Tuning for EDCA Register
  * @{
  */
#define BIT_MASK_WMAC_SPEC_SIFS_OFDM   ((u32)0x000000FF << 24)           /*!< R/W 0x10  The spec SIFS value for duration calculation*/
#define BIT_WMAC_SPEC_SIFS_OFDM(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_WMAC_SPEC_SIFS_OFDM(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_WMAC_SPEC_SIFS_CCK    ((u32)0x000000FF << 16)           /*!< R/W 0x0A  The spec SIFS value for duration calculation*/
#define BIT_WMAC_SPEC_SIFS_CCK(x)      (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_WMAC_SPEC_SIFS_CCK(x)  ((u32)(((x >> 16) & 0x000000FF)))
/** @} */

/** @defgroup REG_RESP_SIFS_CCK
  * @brief Response SIFS for CCK Register
  * @{
  */
#define BIT_MASK_WMAC_ACKTO_OFDM   ((u32)0x00000FFF << 12)           /*!< R/W 0x2D  This register sets the Ack time out value after Tx unicast packet with OFDM rate. It is in units of us.*/
#define BIT_WMAC_ACKTO_OFDM(x)     (((u32)((x) & 0x00000FFF) << 12))
#define BIT_GET_WMAC_ACKTO_OFDM(x) ((u32)(((x >> 12) & 0x00000FFF)))
#define BIT_MASK_WMAC_ACKTO_CCK    ((u32)0x00000FFF << 0)            /*!< R/W 0x7E  This register sets the Ack time out value after Tx unicast packet with CCK rate. It is in units of us.*/
#define BIT_WMAC_ACKTO_CCK(x)      (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_WMAC_ACKTO_CCK(x)  ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_ACKTO
  * @brief ACK Timeout Register
  * @{
  */
#define BIT_MASK_WMAC_EIFS   ((u32)0x0000FFFF << 16)           /*!< R/W 0x013A  This register sets the EIFS value mentioned in 802.11 specification. It is in units of us. To receive 1Mbps ACK frame, EIFS = SIFS + 144us (preamble length) + 48us (PLCP header length) + 112us (14 bytes of data) = 314us.*/
#define BIT_WMAC_EIFS(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_WMAC_EIFS(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_WMAC_NESS   ((u32)0x00000003 << 0)            /*!< R/W 0x0  number of extend ht-ltf for ht ppdu*/
#define BIT_WMAC_NESS(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_WMAC_NESS(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_RECCA_CTRL
  * @brief
  * @{
  */
#define BIT_WMAC_RXAI_INFO_RST   ((u32)0x00000001 << 7) /*!< WA0 0x0  write 1 to clear bit6 and bit5 flag,one pulse*/
#define BIT_WMAC_RXAI_PRTCT_REL  ((u32)0x00000001 << 6) /*!< R 0x0  If MAC_reset_protect is set to 0 by MAC decision circuit (address/A-MPDU checking), set this bit to 1. Reset by BIT_RXAI_INFO_RST = 1*/
#define BIT_WMAC_RXAI_PRTCT_VIO  ((u32)0x00000001 << 5) /*!< R 0x0  If MAC gets BB_reset_MAC pulse when MAC_reset_protect = 1, set this bit to 1. Reset by BIT_RXAI_INFO_RST = 1*/
#define BIT_WMAC_RXAI_PRTCT_SEL  ((u32)0x00000001 << 2) /*!< R/W 0x0  MAC_reset_protect rises at 0: DATA_ON rises 1: PLCP check OK (OFDM/CCK) or receiving 3rd/2nd (VHT/HT) RDRDY*/
#define BIT_WMAC_RXAI_AGG_CHKEN  ((u32)0x00000001 << 1) /*!< R/W 0x0  This bit is only workable when BIT_RXAI_ADDR_CHKEN = 1. 1: if and only if the receiving address matched PPDU is A-MPDU and is not VHT single MPDU, then MAC inform BB not doing reCCA.*/
#define BIT_WMAC_RXAI_ADDR_CHKEN ((u32)0x00000001 << 0) /*!< R/W 0x0  This bit is set to 1 to enable MAC to inform BB not doing reCCA during receiving the address matched PPDU.*/
/** @} */

/** @defgroup REG_CSI_PTR
  * @brief
  * @{
  */
#define BIT_MASK_CSI_RADDR_LATCH   ((u32)0x0000FFFF << 16)           /*!< R 0x0  txff read pointer latch value after Tx CSI report pkt (unit: 8B)*/
#define BIT_CSI_RADDR_LATCH(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_CSI_RADDR_LATCH(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_CSI_WADDR_LATCH   ((u32)0x0000FFFF << 0)            /*!< R 0x0  txff write pointer latch value at ndp_valid negative edge (unit: 8B)*/
#define BIT_CSI_WADDR_LATCH(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_CSI_WADDR_LATCH(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BF_CTL
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_CSI_START_PAGE    ((u32)0x0000003F << 16)           /*!< R/W 0x0  The starting page number of csi rpt in buffer,unit 128 byte*/
#define BIT_WMAC_CSI_START_PAGE(x)      (((u32)((x) & 0x0000003F) << 16))
#define BIT_GET_WMAC_CSI_START_PAGE(x)  ((u32)(((x >> 16) & 0x0000003F)))
#define BIT_MASK_MAC_PAUSE_BB_CLR_TH    ((u32)0x000000FF << 8)            /*!< R/W 0x48  MAC_PAUSE_BB High to Low clear threshold of csidma syncff read-write pointer*/
#define BIT_MAC_PAUSE_BB_CLR_TH(x)      (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MAC_PAUSE_BB_CLR_TH(x)  ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_WMAC_NOCHK_BFPOLL_BMP       ((u32)0x00000001 << 5)            /*!< R/W 0x0  Set this bit to ignore retransmission bitmap of rx beamforming report poll*/
#define BIT_MASK_WMAC_CSI_OFDM_LEN_TH   ((u32)0x0000000F << 1)            /*!< R/W 0x0  CSI frame length threshold for using legacy OFDM (unit: 128B). 0 means disabled. If CSI frame length > threshold, search from VHT or HT bitmap If CSI frame length < threshold, search from legacy OFDM bitmap*/
#define BIT_WMAC_CSI_OFDM_LEN_TH(x)     (((u32)((x) & 0x0000000F) << 1))
#define BIT_GET_WMAC_CSI_OFDM_LEN_TH(x) ((u32)(((x >> 1) & 0x0000000F)))
#define BIT_WMAC_MU_BFEE_DIS            ((u32)0x00000001 << 0)            /*!< R/W 0x0  If set to 1, HW will be SU only beamformee and not response to NDPA or Beamforming report poll.*/
/** @} */

/** @defgroup REG_NAV_THRSHOLD
  * @brief NAV Threshold Register
  * @{
  */
#define BIT_MASK_WMAC_NAV_UPBDY     ((u32)0x000000FF << 16)           /*!< R/W 0x0  When NAV update is beyond this value, then NAV update is aborted. When this field is 0x00, NAV_UPPER function is disable. The unit is 128us.*/
#define BIT_WMAC_NAV_UPBDY(x)       (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_WMAC_NAV_UPBDY(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_WMAC_RXMYRTS_NAV   ((u32)0x0000000F << 8)            /*!< R/W 0x4  RX my RTS NAV. As rx my unicast RTS and RxMyRTS_NAV is not equal to zero, then rx NAV is set to wait response transition time and RxMyRTS_NAV to avoid contention with the TXOP originator. If RxMyRTS_NAV is equal to zero, this mechanism is disabled*/
#define BIT_WMAC_RXMYRTS_NAV(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_WMAC_RXMYRTS_NAV(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_WMAC_RTS_RST_DUR   ((u32)0x000000FF << 0)            /*!< R/W 0x26  RTS NAV Reset Time. This is the value in us, not including the time of CTS frame, to reset the NAV set by an RTS frame if no PHY indication occurred during this time. Refer to 802.11 1999 Section 9.2.5.4 for detailed description.*/
#define BIT_WMAC_RTS_RST_DUR(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_WMAC_RTS_RST_DUR(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BACAMCMD
  * @brief Block ACK CAM Command Register
  * @{
  */
#define BIT_BACAM_RST             ((u32)0x00000001 << 17)           /*!< WA0 0x0  Set 1 to reset BA CAM. Hardware will set the invalid bit for all entries. After reset is finished this bit is reset to 0.*/
#define BIT_MASK_WMAC_TXSBMPMOD   ((u32)0x00000003 << 14)           /*!< R/W 0x0  Bit[15]: if macrx_dma idle, grant txsbmp_req Bit[14]: if macrx is idle, grant txsbmp_req 00: If FSM is idle, grant txsbmp_req 01: If FSM and mac rx is idle, grant txsbmp_req 10: If FSM and macrx_dma is idle, grant txsbmp_req 11: if FSM, macrx and macrx_dma is idle, grant txsbmp_req*/
#define BIT_WMAC_TXSBMPMOD(x)     (((u32)((x) & 0x00000003) << 14))
#define BIT_GET_WMAC_TXSBMPMOD(x) ((u32)(((x >> 14) & 0x00000003)))
/** @} */

/** @defgroup REG_WMAC_PLCP_MONITOR
  * @brief
  * @{
  */
#define BIT_WMAC_PLCP_TRX_SEL          ((u32)0x00000001 << 31)           /*!< R/W 0x0  Selection of Tx/Rx plcp header 0:Rx  1:Tx*/
#define BIT_MASK_WMAC_PLCP_RDSIG_SEL   ((u32)0x00000007 << 28)           /*!< R/W 0x0  Selection of plcp header signal field  0:LSIG 1:HTSIG1/VHTSIGA1      2:HTSIG2/VHTSIGA2    3:VHTSIGB   4: SERVICE field*/
#define BIT_WMAC_PLCP_RDSIG_SEL(x)     (((u32)((x) & 0x00000007) << 28))
#define BIT_GET_WMAC_PLCP_RDSIG_SEL(x) ((u32)(((x >> 28) & 0x00000007)))
#define BIT_MASK_WMAC_RATE_IDX         ((u32)0x0000000F << 24)           /*!< R 0x0  ppdu type follow trxinfo definition*/
#define BIT_WMAC_RATE_IDX(x)           (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_WMAC_RATE_IDX(x)       ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_WMAC_PLCP_RDSIG       ((u32)0x00FFFFFF << 0)            /*!< R 0x0  Selected signal field to read out*/
#define BIT_WMAC_PLCP_RDSIG(x)         (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_WMAC_PLCP_RDSIG(x)     ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_LBK_DLY
  * @brief Loopback Delay Register
  * @{
  */
#define BIT_MASK_WMAC_TRX_STS_TYPE   ((u32)0x0000003F << 18)           /*!< R 0x0  The type and subtype field of frame control of rx packet*/
#define BIT_WMAC_TRX_STS_TYPE(x)     (((u32)((x) & 0x0000003F) << 18))
#define BIT_GET_WMAC_TRX_STS_TYPE(x) ((u32)(((x >> 18) & 0x0000003F)))
#define BIT_TXACT_IND                ((u32)0x00000001 << 17)           /*!< R 0x0  Indicate MAC/PHY is busy to tx packet*/
#define BIT_RXACT_IND                ((u32)0x00000001 << 16)           /*!< R 0x0  Indicate MAC is busy to rx packet*/
#define BIT_MASK_WMAC_LBK_DLY        ((u32)0x0000001F << 0)            /*!< R/W 0x19  Loopback Delay. In unit of 'us'; indicates the delay after which the tdrdy_mac starts. In wep/tkip mode, the delay should be larger than 15, because the initial delay of security is about 1320 cycles, approximately to 16.5 us.*/
#define BIT_WMAC_LBK_DLY(x)          (((u32)((x) & 0x0000001F) << 0))
#define BIT_GET_WMAC_LBK_DLY(x)      ((u32)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_RXERR_RPT
  * @brief RX Error Report Register
  * @{
  */
#define BIT_MASK_WMAC_RXPKTCNT_SEL   ((u32)0x00000007 << 29)           /*!< R/W 0x0  Rx packet counter report selection RXERR_RPT_SEL[2:0]: Counter description 3'd0: counter 0 3'd1: counter 1 3'd2: counter 2 3'd3: counter 3 3'd4: counter 4 3'd5: counter 5 3'd6: counter 6 3'd7: counter 7*/
#define BIT_WMAC_RXPKTCNT_SEL(x)     (((u32)((x) & 0x00000007) << 29))
#define BIT_GET_WMAC_RXPKTCNT_SEL(x) ((u32)(((x >> 29) & 0x00000007)))
#define BIT_RXPKTCNT_RST             ((u32)0x00000001 << 28)           /*!< WA0 0x0  Write "1" to set the counter to zero. One pulse*/
#define BIT_UDPKTCNT_SET             ((u32)0x00000001 << 24)           /*!< WA0 0x0  loading user define packet counter, one pulse*/
#define BIT_MASK_WMAC_RXPKTCNT_CFG   ((u32)0x000000FF << 16)           /*!< R/W 0x0  [23:22} Select matched BSSID: 2'b0: Port 0 2'b1: Port 1 2'b2: Port 2; otherwise, do not care bssid match or not [21:18] User defined SubType [17:16] User defined Type*/
#define BIT_WMAC_RXPKTCNT_CFG(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_WMAC_RXPKTCNT_CFG(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_RPT_COUNTER         ((u32)0x0000FFFF << 0)            /*!< R 0x0  The reported counter value corresponding to Report type selected.*/
#define BIT_RPT_COUNTER(x)           (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_RPT_COUNTER(x)       ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_WMAC_TRXPTCL_CTL
  * @brief WMAC TX/RX Protocol Control Register
  * @{
  */
#define BIT_WMAC_EN_STOP_UPDNAV            ((u32)0x00000001 << 28)           /*!< R/W 0x0  When this bit set 1. If RX packet with EDCA_REF is low, not update NAV.*/
#define BIT_WMAC_RST_EDCA_ACKTO            ((u32)0x00000001 << 27)           /*!< R/W 0x1  While in ACKTO duration, reset scheduler top to TX*/
#define BIT_WMAC_RST_EDCA_EIFS             ((u32)0x00000001 << 26)           /*!< R/W 0x1  While in EIFS duration, reset scheduler top to TX*/
#define BIT_WMAC_PLCPCHK_RST_EIFS          ((u32)0x00000001 << 25)           /*!< R/W 0x1  Reset EIFS counter while receive correct PLCP.*/
#define BIT_WMAC_CCA_RST_EIFS              ((u32)0x00000001 << 24)           /*!< R/W 0x0  Reset EIFS counter while CCA on*/
#define BIT_WMAC_DIS_UPD_MYRXPKTNAV        ((u32)0x00000001 << 23)           /*!< R/W 0x1  Do not update NAV, while receiving my packet.*/
#define BIT_WMAC_RESP_EARLY_TXBA           ((u32)0x00000001 << 22)           /*!< R/W 0x0  While phyrxon down, mac_rxactive on. Ignore mac rx busy, respond BA immediately.*/
#define BIT_MASK_WMAC_RESP_CHNBUSY         ((u32)0x00000003 << 20)           /*!< R/W 0x2  Define channel busy condition in responder to determine RX busy 1: PHYRXON (OFDM_VBON/CCKCCA) 0: CCA (CCKCCA/OFDMCCA)*/
#define BIT_WMAC_RESP_CHNBUSY(x)           (((u32)((x) & 0x00000003) << 20))
#define BIT_GET_WMAC_RESP_CHNBUSY(x)       ((u32)(((x >> 20) & 0x00000003)))
#define BIT_WMAC_RESP_SPLCPEN              ((u32)0x00000001 << 17)           /*!< R/W 0x0  Enable responder send SPLCP CCK response for acknowledging Rx SPLCP CCK packet*/
#define BIT_WMAC_RESP_SGIEN                ((u32)0x00000001 << 16)           /*!< R/W 0x0  Enable responder send SGI HT-OFDM response for acknowledging Rx SGI HT-OFDM packet*/
#define BIT_WMAC_RESP_LDPC_EN              ((u32)0x00000001 << 15)           /*!< R/W 0x0  if rxpkt with ldpc, response pkt with ldpc*/
#define BIT_WMAC_DIS_RESP_ACKINCCA         ((u32)0x00000001 << 14)           /*!< R/W 0x0  Disable to response ack when cca goes high after SIFS*/
#define BIT_WMAC_DIS_RESP_CTSINCCA         ((u32)0x00000001 << 13)           /*!< R/W 0x0  8812 Disable to response cts when cca goes high after SIFS*/
#define BIT_MASK_WMAC_SECOND_CCA_TIMER     ((u32)0x00000007 << 10)           /*!< R/W 0x4  8812 The maximum time interval in us that secondary cca is pull high before primary cca When receive duplicated rts. When station response with cts, if the time that secondary cca pull high before primary cca is larger than this threshold, then secondary cca is judged to be interference, otherwise it is judged to the received RTS frame. default: 3"b0*/
#define BIT_WMAC_SECOND_CCA_TIMER(x)       (((u32)((x) & 0x00000007) << 10))
#define BIT_GET_WMAC_SECOND_CCA_TIMER(x)   ((u32)(((x >> 10) & 0x00000007)))
#define BIT_MASK_WMAC_RFMOD                ((u32)0x00000003 << 7)            /*!< R/W 0x0  8812 RF_BW indication, Used to decide response duplicated cts txsc 2"b00: 20M, 2"b01: 40M, 2"b10: 80M e.g: when RF_BW= 80M, duplicated cts BW= 40M, txsc = 9 or 10 when RF_BW = 40M, duplicated cts BW = 40M, txsc = 0*/
#define BIT_WMAC_RFMOD(x)                  (((u32)((x) & 0x00000003) << 7))
#define BIT_GET_WMAC_RFMOD(x)              ((u32)(((x >> 7) & 0x00000003)))
#define BIT_MASK_WMAC_RESP_CTS_DYNBW_SEL   ((u32)0x00000003 << 5)            /*!< R/W 0x0  8812 Response cts bw selection when dynamic rts frame is received 00: current maximum bw indicated by secondary cca 01: bw fall back by one level based on bw in 2"b00 if not reach 20M 10: bw fall back by one level based on bw in 2"b01 if not reach 20M 11: bw fall back by one level based on bw in 2"b10 if not reach 20M e.g, current maximum bw indicated by secondary_cca is 80M, when set to 2"b00, the response cts bw is 80M, when set to 2"b01, cts bw is 40M, when set to 2"b10 or 2"b11 , cts bw is 20M*/
#define BIT_WMAC_RESP_CTS_DYNBW_SEL(x)     (((u32)((x) & 0x00000003) << 5))
#define BIT_GET_WMAC_RESP_CTS_DYNBW_SEL(x) ((u32)(((x >> 5) & 0x00000003)))
/** @} */

/** @defgroup REG_WMAC_TRXPTCL_CTL_H
  * @brief WMAC TX/RX Protocol Control Register Higher Bit
  * @{
  */
#define BIT_MASK_WMAC_ACKRXBA_TYPESEL         ((u32)0x0000000F << 28)           /*!< R/W 0x0  Determine response type for RX BA, and the definition as the bellow 0: NAV 1: Send ACK ACKBA_TYPESEL[0]: used for Basic BA ACKBA_TYPESEL[1]: used for Compression BA ACKBA_TYPESEL[2]: RSVD ACKBA_TYPESEL[3]: used for MTID BA*/
#define BIT_WMAC_ACKRXBA_TYPESEL(x)           (((u32)((x) & 0x0000000F) << 28))
#define BIT_GET_WMAC_ACKRXBA_TYPESEL(x)       ((u32)(((x >> 28) & 0x0000000F)))
#define BIT_MASK_WMAC_ACKRXBA_ACKPCHK         ((u32)0x0000000F << 24)           /*!< R/W 0x0  If set 1, then check ACK Policy of BA control field to determine whether send response or not. When this bit set to 1 and a. ACK Policy of Rx BA control field is 0, then response type is controlled by ACLBA_TYPESEL. b. ACK Policy of Rx BA control field is 1, then don't send response If set 0, then ignore the ACK policy of RX BA control field and response type controlled by ACKBA_TYPESEL ACKBA_ACKPCHK[0]: used for Basic BA ACKBA_ACKPCHK[1]: used for Compression BA ACKBA_ACKPCHK[2]: RSVD ACKBA_ACKPCHK[3]: used for MTID BA*/
#define BIT_WMAC_ACKRXBA_ACKPCHK(x)           (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_WMAC_ACKRXBA_ACKPCHK(x)       ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_WMAC_ACKRXBAR_TYPESEL        ((u32)0x000000FF << 16)           /*!< R/W 0x4  Determine response type for RX BAR, and the definition as the bellow 00: NAV 01: Send BA 10: Send ACK ACKBAR_TYPESEL[1:0]: used for Basic BAR ACKBAR_TYPESEL[3:2]: used for Compression BAR ACKBAR_TYPESEL[5:4]: RSVD ACKBAR_TYPESEL[7:6]: used for MTID BAR*/
#define BIT_WMAC_ACKRXBAR_TYPESEL(x)          (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_WMAC_ACKRXBAR_TYPESEL(x)      ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_WMAC_ACKRXBAR_ACKPCHK        ((u32)0x0000000F << 12)           /*!< R/W 0x2  If set 1, then check ACK Policy of BAR control field to determine whether send response or not. When this bit set to 1 and a. ACK Policy of Rx BAR control field is 0, then response type is controlled by ACLBAR_TYPESEL. b. ACK Policy of Rx BAR control field is 1, then don't send response If set 0, then ignore the ACK policy of RX BAR control field and response type controlled by ACKBA_TYPESEL ACKBA_ACKPCHK[0]: used for Basic BAR ACKBA_ACKPCHK[1]: used for Compression BAR ACKBA_ACKPCHK[2]: RSVD ACKBA_ACKPCHK[3]: used for MTID BAR*/
#define BIT_WMAC_ACKRXBAR_ACKPCHK(x)          (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_WMAC_ACKRXBAR_ACKPCHK(x)      ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_WMAC_RXBA_IGNOREA2                ((u32)0x00000001 << 10)           /*!< R/W 0x0  Disable check A2 field of RX BA*/
#define BIT_WMAC_SAVE_ALL_TXOPADDR            ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_WMAC_EN_TXCTS_TOTXOPOWNER_INRXNAV ((u32)0x00000001 << 8)            /*!< R/W 0x0  together with bit41, implement 802.11ac txop owner function*/
#define BIT_WMAC_DIS_TXBA_AMPDUFCSERR         ((u32)0x00000001 << 7)            /*!< R/W 0x0  Disable to send BA for responding RX AMPDU with FCS error subframe*/
#define BIT_WMAC_DIS_TXBA_RXBARINFULL         ((u32)0x00000001 << 6)            /*!< R/W 0x0  Disable to send BA for responding RX control wrapper BAR dropped by rxpkbuffer full*/
#define BIT_WMAC_DIS_TXCTS_INFULL             ((u32)0x00000001 << 4)            /*!< R/W 0x0  Disable to send CTS for responding RX control wrapper RTS dropped by rxpktbuffer full*/
#define BIT_WMAC_EN_TXACKBA_INTXOP            ((u32)0x00000001 << 2)            /*!< R/W 0x1  If this bit is set, then MAC will Tx ACK/BA to respond previous rx my unitcast packets send by another STA during my TXOP*/
#define BIT_WMAC_EN_TXCTS_INRXNAV             ((u32)0x00000001 << 1)            /*!< R/W 0x1  Enable to send CTS in Rx NAV*/
#define BIT_WMAC_EN_TXCTS_INTXOP              ((u32)0x00000001 << 0)            /*!< R/W 0x1  Enable to send CTS for responding RX RTS during our TXOP period*/
/** @} */

/** @defgroup REG_TRANSMIT_ADDRSS_0
  * @brief TA0 Register
  * @{
  */
#define BIT_MASK_WMAC_TRANS_ADDR0_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  bcn and prob response transmitter address for port 0*/
#define BIT_WMAC_TRANS_ADDR0_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_WMAC_TRANS_ADDR0_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TRANSMIT_ADDRSS_0_H
  * @brief TA0 Register
  * @{
  */
#define BIT_MASK_WMAC_TRANS_ADDR0_H   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  bcn and prob response transmitter address for port 0*/
#define BIT_WMAC_TRANS_ADDR0_H(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_WMAC_TRANS_ADDR0_H(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_CAMDBG
  * @brief CAM Debug Register
  * @{
  */
#define BIT_WMAC_KEYCAM_DBGSEL   ((u32)0x00000001 << 31)          /*!< R/W 0x0  Select TX/RX CAM Information. Set to 1 to retrieve latest Tx search result. Set to 0 to retrieve latest Rx search result.*/
#define BIT_MASK_KEYCAM_DBGOUT   ((u32)0x0000FFFF << 0)           /*!< R 0x0  [15]:Security Key Found in CAM 0: key not found 1: key found [14:]: rx spp valid [13:11]: rx found security key type  [10]: rx found security key ext_sectype  [9:7]:rsvd [6:0]:Security KEY ADDR*/
#define BIT_KEYCAM_DBGOUT(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_KEYCAM_DBGOUT(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_SECCFG
  * @brief Security Configuration Register
  * @{
  */
#define BIT_WMAC_DIS_GCLK_SEC      ((u32)0x00000001 << 6)           /*!< R/W 0x0  Disable gated clock control for AES/GCMP/WAPI engine.*/
#define BIT_MASK_WMAC_AES_SEL_QC   ((u32)0x00000003 << 4)           /*!< R/W 0x0  [12]:1: use QC[7] to compute mic; 0: not use QC[7] to compute mic [11]:1:use QC[7] to compute ctr; 0: not use QC[7] to compute ctr*/
#define BIT_WMAC_AES_SEL_QC(x)     (((u32)((x) & 0x00000003) << 4))
#define BIT_GET_WMAC_AES_SEL_QC(x) ((u32)(((x >> 4) & 0x00000003)))
#define BIT_WMAC_CKEYID            ((u32)0x00000001 << 3)           /*!< R/W 0x0  If this bit is set to 1, key search engine need to check if key ID matched. If this bit is set to 0, then key ID table must be filled with 2"b00.*/
#define BIT_WMAC_RXBCUSEDK         ((u32)0x00000001 << 2)           /*!< R/W 0x0  Force RX Broadcast packets Use Default Key If this bit is set to 1, use default key for RX key search when received packet is broadcast and multicast.*/
#define BIT_WMAC_RXDEC             ((u32)0x00000001 << 1)           /*!< R/W 0x1  Enable Rx Decryption Setting 1 to enable Rx hardware decryption.*/
#define BIT_WMAC_TXENC             ((u32)0x00000001 << 0)           /*!< R/W 0x1  Enable Tx Encryption Setting to 1 to enable Tx hardware encryption.*/
/** @} */

/** @defgroup REG_BCN_IEPSR0
  * @brief
  * @{
  */
#define BIT_WMAC_BCN_MBSSID_MASK     ((u32)0x00000001 << 31)           /*!< R/W 0x0  enable tim no hit don't check whether  BC/MC packets are buffered at nontransmitted BSSID*/
#define BIT_WMAC_BCN_CLR_N           ((u32)0x00000001 << 30)           /*!< R/W 0x0  enable clear macbssid indicator when no multiple BSSID element is found.*/
#define BIT_WMAC_BCN_IE1_PSR         ((u32)0x00000001 << 29)           /*!< R/W 0x0  enable parser specified ie 1 element*/
#define BIT_WMAC_BCN_IE0_PSR         ((u32)0x00000001 << 28)           /*!< R/W 0x0  enable parser specified ie0 element*/
#define BIT_WMAC_BCN_MBSSID_PSR      ((u32)0x00000001 << 27)           /*!< R/W 0x0  enable parser multiple BSSID element*/
#define BIT_WMAC_BCN_SW_MBSSID       ((u32)0x00000001 << 26)           /*!< R/W 0x0  enable the MaxBSSID indicator value from SW*/
#define BIT_MASK_WMAC_BCN_MBSSID_N   ((u32)0x000000FF << 18)           /*!< R/W 0x0  SW write the value of MaxBSSID Indicator field*/
#define BIT_WMAC_BCN_MBSSID_N(x)     (((u32)((x) & 0x000000FF) << 18))
#define BIT_GET_WMAC_BCN_MBSSID_N(x) ((u32)(((x >> 18) & 0x000000FF)))
#define BIT_WMAC_BCN_ID1_EXT         ((u32)0x00000001 << 17)           /*!< R/W 0x0  indicate current ie is the extend element which need to parser extend id field*/
#define BIT_MASK_WMAC_BCN_IE_ID1     ((u32)0x000000FF << 9)            /*!< R/W 0x0  specified Element ID, set corresponding interrupt when it is parsed*/
#define BIT_WMAC_BCN_IE_ID1(x)       (((u32)((x) & 0x000000FF) << 9))
#define BIT_GET_WMAC_BCN_IE_ID1(x)   ((u32)(((x >> 9) & 0x000000FF)))
#define BIT_WMAC_BCN_ID0_EXT         ((u32)0x00000001 << 8)            /*!< R/W 0x0  indicate current ie is the extend element which need to parser extend id field*/
#define BIT_MASK_WMAC_BCN_IE_ID0     ((u32)0x000000FF << 0)            /*!< R/W 0x0  specified Element ID, set corresponding interrupt when it is parsed*/
#define BIT_WMAC_BCN_IE_ID0(x)       (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_WMAC_BCN_IE_ID0(x)   ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BCN_IEPSR1
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_BCN_MBSSID_OFS   ((u32)0x0000FFFF << 16)           /*!< R/W/ES 0x0  the multiple bssid element offset (byte unit) in frame body*/
#define BIT_WMAC_BCN_MBSSID_OFS(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_WMAC_BCN_MBSSID_OFS(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_WMAC_BCN_N0_CHG            ((u32)0x00000001 << 15)           /*!< R/W/ES 0x0  indicate parsed maxmbssid indicator field value has changed which leads to the change of N0.*/
#define BIT_WMAC_BCN_MBSSID_VAL        ((u32)0x00000001 << 14)           /*!< R/W/ES 0x0  indicate ofs and n0 change bit is valid.*/
#define BIT_WMAC_OPS_PSR_EN            ((u32)0x00000001 << 10)           /*!< R/W 0x0  enable parser ops frame tim elemnt and ops element*/
#define BIT_WMAC_TIM_TIMPSR_EN         ((u32)0x00000001 << 9)            /*!< R/W 0x0  enable parser tim frame tim element*/
#define BIT_WMAC_BCN_BMC_MASK          ((u32)0x00000001 << 8)            /*!< R/W 0x0  bcn tim hit bc/mc mask*/
#define BIT_MASK_WMAC_BCN_MBSSID_IDX   ((u32)0x000000FF << 0)            /*!< R/W 0x0  the multiple bssid index that current sta connect with*/
#define BIT_WMAC_BCN_MBSSID_IDX(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_WMAC_BCN_MBSSID_IDX(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_SOUNDING_CFG
  * @brief
  * @{
  */
#define BIT_WMAC_EN_NDP_NSS2         ((u32)0x00000001 << 12)          /*!< R/W 0x0  enable nss=2 when tx ndp in fpga mode*/
#define BIT_MASK_WMAC_BFINFO_20M_0   ((u32)0x00000FFF << 0)           /*!< R/W 0x0  beamforming info*/
#define BIT_WMAC_BFINFO_20M_0(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_WMAC_BFINFO_20M_0(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_MYPKT_FLAG
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_WMMPS_UAPSD_TID   ((u32)0x000000FF << 24)           /*!< R/W 0x0  [7:0]:Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID7-TID0*/
#define BIT_WMAC_WMMPS_UAPSD_TID(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_WMAC_WMMPS_UAPSD_TID(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_RXMGTIN0                    ((u32)0x00000001 << 3)            /*!< RW1C 0x0  It is set to 1 if NIC received management frame with correct BSSID and DA (including unicast and BMC).*/
#define BIT_RXDATAIN2                   ((u32)0x00000001 << 2)            /*!< RW1C 0x0  It is set to 1 if NIC received data frame with correct BSSID and DA (including unicast and BMC).*/
#define BIT_RXDATAIN1                   ((u32)0x00000001 << 1)            /*!< RW1C 0x0  It is set to 1 if NIC received data frame with correct BSSID and DA (including unicast and BMC).*/
#define BIT_RXDATAIN0                   ((u32)0x00000001 << 0)            /*!< RW1C 0x0  It is set to 1 if NIC received data frame with correct BSSID and DA (including unicast and BMC).*/
/** @} */

/** @defgroup REG_BT_ZB_COEX_TB
  * @brief
  * @{
  */
#define BIT_MASK_BT_ZB_COEX_TABLE   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  bt and zigbee coexist table*/
#define BIT_BT_ZB_COEX_TABLE(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BT_ZB_COEX_TABLE(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NAN_BSSID_L
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_BSSID_NAN_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Low 32bit address for NAN BSSID. It will be used as father mac address when relay mode.*/
#define BIT_WMAC_BSSID_NAN_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_WMAC_BSSID_NAN_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NAN_BSSID_H
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_BSSID_NAN_H   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  High 16bit address for NAN BSSID. It will be used as father mac address when relay mode.*/
#define BIT_WMAC_BSSID_NAN_H(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_WMAC_BSSID_NAN_H(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_RXFLTMAP0
  * @brief RX Filter Map Group 0
  * @{
  */
#define BIT_WMAC_CTRLFLT15EN ((u32)0x00000001 << 31) /*!< R/W 0x0  When set, frames with type=01 and subtype=1111 are received into RXFF.*/
#define BIT_WMAC_CTRLFLT14EN ((u32)0x00000001 << 30) /*!< R/W 0x0  When set, frames with type=01 and subtype=1110 are received into RXFF.*/
#define BIT_WMAC_CTRLFLT13EN ((u32)0x00000001 << 29) /*!< R/W 0x0  When set, frames with type=01 and subtype=1101 are received into RXFF.*/
#define BIT_WMAC_CTRLFLT12EN ((u32)0x00000001 << 28) /*!< R/W 0x0  When set, frames with type=01 and subtype=1100 are received into RXFF.*/
#define BIT_WMAC_CTRLFLT11EN ((u32)0x00000001 << 27) /*!< R/W 0x0  When set, frames with type=01 and subtype=1011 are received into RXFF.*/
#define BIT_WMAC_CTRLFLT10EN ((u32)0x00000001 << 26) /*!< R/W 0x0  When set, frames with type=01 and subtype=1010 are received into RXFF.*/
#define BIT_WMAC_CTRLFLT9EN  ((u32)0x00000001 << 25) /*!< R/W 0x0  When set, frames with type=01 and subtype=1001 are received into RXFF.*/
#define BIT_WMAC_CTRLFLT8EN  ((u32)0x00000001 << 24) /*!< R/W 0x0  When set, frames with type=01 and subtype=1000 are received into RXFF.*/
#define BIT_WMAC_CTRLFLT7EN  ((u32)0x00000001 << 23) /*!< R/W 0x0  When set, frames with type=01 and subtype=0111 are received into RXFF.*/
#define BIT_WMAC_CTRLFLT6EN  ((u32)0x00000001 << 22) /*!< R/W 0x0  When set, frames with type=01 and subtype=0110 are received into RXFF.*/
#define BIT_WMAC_CTRLFLT5EN  ((u32)0x00000001 << 21) /*!< R/W 0x0  When set, frames with type=01 and subtype=0101 are received into RXFF.*/
#define BIT_WMAC_CTRLFLT4EN  ((u32)0x00000001 << 20) /*!< R/W 0x0  When set, frames with type=01 and subtype=0100 are received into RXFF.*/
#define BIT_WMAC_CTRLFLT3EN  ((u32)0x00000001 << 19) /*!< R/W 0x0  When set, frames with type=01 and subtype=0011 are received into RXFF.*/
#define BIT_WMAC_CTRLFLT2EN  ((u32)0x00000001 << 18) /*!< R/W 0x0  When set, frames with type=01 and subtype=0010 are received into RXFF.*/
#define BIT_WMAC_CTRLFLT1EN  ((u32)0x00000001 << 17) /*!< R/W 0x0  When set, frames with type=01 and subtype=0001 are received into RXFF.*/
#define BIT_WMAC_CTRLFLT0EN  ((u32)0x00000001 << 16) /*!< R/W 0x0  When set, frames with type=01 and subtype=0000 are received into RXFF.*/
#define BIT_WMAC_MGTFLT15EN  ((u32)0x00000001 << 15) /*!< R/W 0x0  When set, frames with type=00 and subtype=1111 are received into RXFF.*/
#define BIT_WMAC_MGTFLT14EN  ((u32)0x00000001 << 14) /*!< R/W 0x0  When set, frames with type=00 and subtype=1110 are received into RXFF.*/
#define BIT_WMAC_MGTFLT13EN  ((u32)0x00000001 << 13) /*!< R/W 0x0  When set, frames with type=00 and subtype=1101 are received into RXFF.*/
#define BIT_WMAC_MGTFLT12EN  ((u32)0x00000001 << 12) /*!< R/W 0x0  When set, frames with type=00 and subtype=1100 are received into RXFF.*/
#define BIT_WMAC_MGTFLT11EN  ((u32)0x00000001 << 11) /*!< R/W 0x0  When set, frames with type=00 and subtype=1011 are received into RXFF.*/
#define BIT_WMAC_MGTFLT10EN  ((u32)0x00000001 << 10) /*!< R/W 0x0  When set, frames with type=00 and subtype=1010 are received into RXFF.*/
#define BIT_WMAC_MGTFLT9EN   ((u32)0x00000001 << 9)  /*!< R/W 0x0  When set, frames with type=00 and subtype=1001 are received into RXFF.*/
#define BIT_WMAC_MGTFLT8EN   ((u32)0x00000001 << 8)  /*!< R/W 0x0  When set, frames with type=00 and subtype=1000 are received into RXFF.*/
#define BIT_WMAC_MGTFLT7EN   ((u32)0x00000001 << 7)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0111 are received into RXFF.*/
#define BIT_WMAC_MGTFLT6EN   ((u32)0x00000001 << 6)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0110 are received into RXFF.*/
#define BIT_WMAC_MGTFLT5EN   ((u32)0x00000001 << 5)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0101 are received into RXFF.*/
#define BIT_WMAC_MGTFLT4EN   ((u32)0x00000001 << 4)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0100 are received into RXFF.*/
#define BIT_WMAC_MGTFLT3EN   ((u32)0x00000001 << 3)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0011 are received into RXFF.*/
#define BIT_WMAC_MGTFLT2EN   ((u32)0x00000001 << 2)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0010 are received into RXFF.*/
#define BIT_WMAC_MGTFLT1EN   ((u32)0x00000001 << 1)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0001 are received into RXFF.*/
#define BIT_WMAC_MGTFLT0EN   ((u32)0x00000001 << 0)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0000 are received into RXFF.*/
/** @} */

/** @defgroup REG_RXFLTMAP
  * @brief RX Filter Map Group 1
  * @{
  */
#define BIT_WMAC_DATAFLT15EN ((u32)0x00000001 << 15) /*!< R/W 0x0  When set, frames with type=10 and subtype=1111 are received into RXFF.*/
#define BIT_WMAC_DATAFLT14EN ((u32)0x00000001 << 14) /*!< R/W 0x0  When set, frames with type=10 and subtype=1110 are received into RXFF.*/
#define BIT_WMAC_DATAFLT13EN ((u32)0x00000001 << 13) /*!< R/W 0x0  When set, frames with type=10 and subtype=1101 are received into RXFF.*/
#define BIT_WMAC_DATAFLT12EN ((u32)0x00000001 << 12) /*!< R/W 0x0  When set, frames with type=10 and subtype=1100 are received into RXFF.*/
#define BIT_WMAC_DATAFLT11EN ((u32)0x00000001 << 11) /*!< R/W 0x0  When set, frames with type=10 and subtype=1011 are received into RXFF.*/
#define BIT_WMAC_DATAFLT10EN ((u32)0x00000001 << 10) /*!< R/W 0x0  When set, frames with type=10 and subtype=1010 are received into RXFF.*/
#define BIT_WMAC_DATAFLT9EN  ((u32)0x00000001 << 9)  /*!< R/W 0x0  When set, frames with type=10 and subtype=1001 are received into RXFF.*/
#define BIT_WMAC_DATAFLT8EN  ((u32)0x00000001 << 8)  /*!< R/W 0x0  When set, frames with type=10 and subtype=1000 are received into RXFF.*/
#define BIT_WMAC_DATAFLT7EN  ((u32)0x00000001 << 7)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0111 are received into RXFF.*/
#define BIT_WMAC_DATAFLT6EN  ((u32)0x00000001 << 6)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0110 are received into RXFF.*/
#define BIT_WMAC_DATAFLT5EN  ((u32)0x00000001 << 5)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0101 are received into RXFF.*/
#define BIT_WMAC_DATAFLT4EN  ((u32)0x00000001 << 4)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0100 are received into RXFF.*/
#define BIT_WMAC_DATAFLT3EN  ((u32)0x00000001 << 3)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0011 are received into RXFF.*/
#define BIT_WMAC_DATAFLT2EN  ((u32)0x00000001 << 2)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0010 are received into RXFF.*/
#define BIT_WMAC_DATAFLT1EN  ((u32)0x00000001 << 1)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0001 are received into RXFF.*/
#define BIT_WMAC_DATAFLT0EN  ((u32)0x00000001 << 0)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0000 are received into RXFF.*/
/** @} */

/** @defgroup REG_BCN_PSR_RPT0
  * @brief Beacon Parser Report Register
  * @{
  */
#define BIT_MASK_DTIM_CNT0      ((u32)0x000000FF << 24)           /*!< R/W/ES 0x0  The DTIM count field of the TIM element of Rx beacon*/
#define BIT_DTIM_CNT0(x)        (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_DTIM_CNT0(x)    ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_DTIM_PERIOD0   ((u32)0x000000FF << 16)           /*!< R/W/ES 0x0  The DTIM period field of the TIM element of Rx beacon*/
#define BIT_DTIM_PERIOD0(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_DTIM_PERIOD0(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_HAS_MY_BC0          ((u32)0x00000001 << 15)           /*!< R/W/ES 0x0  Indicate BC/MC packets are buffered in transmitted BSSID or AP*/
#define BIT_HAS_MY_BSSID0       ((u32)0x00000001 << 14)           /*!< R/W/ES 0x0  Indicate BC/MC packets are buffered in nontransmitted BSSID, SW need check crespponding dtim count field in multiple bssid index field*/
#define BIT_HAS_MYAID0          ((u32)0x00000001 << 13)           /*!< R/W/ES 0x0  Indicate has my unicast packet*/
#define BIT_RPT_VALID0          ((u32)0x00000001 << 12)           /*!< R/W/ES 0x0  when set to 1, indicate the tim report is valid*/
#define BIT_MASK_WMAC_AID0      ((u32)0x00000FFF << 0)            /*!< R/W 0x0  AID for MACID0*/
#define BIT_WMAC_AID0(x)        (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_WMAC_AID0(x)    ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_NAN_TA_L
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_TA_NAN_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Low 32bit address for NAN BSSID. It will be used as soft ap addr of father node when relay mode.*/
#define BIT_WMAC_TA_NAN_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_WMAC_TA_NAN_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NAN_TA_H
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_TA_NAN_H   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  High 16bit address for NAN BSSID, It will be used as soft ap addr of father node when relay mode.*/
#define BIT_WMAC_TA_NAN_H(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_WMAC_TA_NAN_H(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_STATE_MON
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_STATE_SEL   ((u32)0x0000001F << 24)           /*!< R/W 0x0  WMAC read and write FSM selection: 000,001:read mactx status 010,011:read mactx status 100:read response status 00xxx: write [6:0]to mactx fsm when [7] valid 01xxx:write [6:0]to macrx fsm when [7] valid 100xx: write [6:0]to response fsm when [7] valid*/
#define BIT_WMAC_STATE_SEL(x)     (((u32)((x) & 0x0000001F) << 24))
#define BIT_GET_WMAC_STATE_SEL(x) ((u32)(((x >> 24) & 0x0000001F)))
#define BIT_MASK_WMAC_STATE_CUR   ((u32)0x0000FFFF << 8)            /*!< R 0x0  when BIT_WRITE_FSM_EN is valid,is rsvd. When BIT_WRITE_FSM_EN is not valid, means read status*/
#define BIT_WMAC_STATE_CUR(x)     (((u32)((x) & 0x0000FFFF) << 8))
#define BIT_GET_WMAC_STATE_CUR(x) ((u32)(((x >> 8) & 0x0000FFFF)))
#define BIT_WRITE_FSM_EN          ((u32)0x00000001 << 7)            /*!< WA0 0x0  when set 1, generate write pulse, otherwise means read status*/
#define BIT_MASK_WMAC_STATE_NXT   ((u32)0x0000007F << 0)            /*!< R/W 0x0  when BIT_WRITE_FSM_EN is valid,Indicate the FSM current state to write.*/
#define BIT_WMAC_STATE_NXT(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_WMAC_STATE_NXT(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_ERROR_EVT_CTL
  * @brief
  * @{
  */
#define BIT_CSIRPT_LEN_BB_MORE_THAN_MAC ((u32)0x00000001 << 23) /*!< RW1C 0x0  Indicate MAC Rx csi rxd number overflow*/
#define BIT_CSI_CHKSUM_FAIL             ((u32)0x00000001 << 22) /*!< RW1C 0x0  Indicate MAC Rx csi rpt checksum error*/
#define BIT_MACRX_ERROR_INTPS5          ((u32)0x00000001 << 21) /*!< RW1C 0x0  RSVD*/
#define BIT_MACRX_ERROR_INTPS4          ((u32)0x00000001 << 20) /*!< RW1C 0x0  [20]: Indicate last MPDU length of AMPDU or PPDU length is error.*/
#define BIT_MACRX_ERROR_INTPS3          ((u32)0x00000001 << 19) /*!< RW1C 0x0  [19]: Indicate rxfifo or mac phy interface fifo overflow*/
#define BIT_MACRX_ERROR_INTPS2          ((u32)0x00000001 << 18) /*!< RW1C 0x0  [18]: Indicate MAC Rx occurs internal halt event*/
#define BIT_MACRX_ERROR_INTPS1          ((u32)0x00000001 << 17) /*!< RW1C 0x0  [17]: Indicate Rx packet length >= 12K bytes*/
#define BIT_MACRX_ERROR_INTPS0          ((u32)0x00000001 << 16) /*!< RW1C 0x0  [16]: Indicate MAC Rx occurs halt event*/
#define BIT_WMAC_PRETX_ERRHDL_EN        ((u32)0x00000001 << 15) /*!< R/W 0x0  Pre tx error block enable signal*/
#define BIT_MACTX_ERROR_INTPS4          ((u32)0x00000001 << 4)  /*!< RW1C 0x0  RSVD*/
#define BIT_MACTX_ERROR_INTPS3          ((u32)0x00000001 << 3)  /*!< RW1C 0x0  [3]: Indicate PHY fetch plcp before it is ready*/
#define BIT_MACTX_ERROR_INTPS2          ((u32)0x00000001 << 2)  /*!< RW1C 0x0  [2]: phy_txen is set ,but wait phy_phytxon time out*/
#define BIT_MACTX_ERROR_INTPS1          ((u32)0x00000001 << 1)  /*!< RW1C 0x0  [1]: Indicate TXD FIFO underflow,ppdu fetch zld*/
#define BIT_MACTX_ERROR_INTPS0          ((u32)0x00000001 << 0)  /*!< RW1C 0x0  [0]: Indicate TXD FIFO underflow,mpdu fetch zld*/
/** @} */

/** @defgroup REG_COEX_CFG_MACID_SRCH
  * @brief
  * @{
  */
#define BIT_BT_OOB             ((u32)0x00000001 << 31) /*!< R/W 0x0  out of band indication (0: in band; 1: out of band)*/
#define BIT_BT_ANT_SEL         ((u32)0x00000001 << 30) /*!< R/W 0x0  single or dual antenna (0: single; 1: dual)*/
#define BIT_WMAC_SRCH_FIFOFULL ((u32)0x00000001 << 15) /*!< R/W 0x0  when set to 1, when fifofull, stop macid search;*/
/** @} */

/** @defgroup REG_BT_COEX_TABLE_V1
  * @brief BT Coexistence Control register
  * @{
  */
#define BIT_MASK_PTA_TABLE_0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  coexistence table, used at dual antenna & out of band*/
#define BIT_PTA_TABLE_0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_PTA_TABLE_0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BT_COEX_TABLE2_V1
  * @brief BTCoexistence Control register
  * @{
  */
#define BIT_MASK_PTA_TABLE_1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  coexistence table, used at dual antenna & in band or single antenna*/
#define BIT_PTA_TABLE_1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_PTA_TABLE_1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BT_COEX_BREAK_TABLE
  * @brief BT Coexistence Control register
  * @{
  */
#define BIT_MASK_PTA_TABLE_3   ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  Table used to break BT activity, when new WLAN request is coming and BT is on transmitting or receiving*/
#define BIT_PTA_TABLE_3(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_PTA_TABLE_3(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_PTA_TABLE_2   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  Table used to break WLAN activity, when new BT request is coming and WLAN is on transmitting or receiving*/
#define BIT_PTA_TABLE_2(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_PTA_TABLE_2(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BT_COEX_PRI_MASK
  * @brief BT Coexistence Control register
  * @{
  */
#define BIT_MASK_PRI_MASK   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  [31]: Priority Mask for P2 NAN sync Beacon TBTT [30]: Priority Mask for P2 NAN disc Beacon TBTT [29]: Priority Mask for P2 NAN DW [28]: Priority Mask for RX Response Packet [27]: Priority Mask for RX OFDM [26]: Priority Mask for RX CCK [25:19]: Priority Mask for Tx Queue [18:11]: Priority Mask for Tx NAV [10]: Priority Mask for Tx CCK [9]: Priority Mask for Tx OFDM [8]: Priority Mask for Tx Retry Packet [7:4]: Priority Mask for Tx packet number [3]: Priority Mask for P1 TBTT [2]: Priority Mask for P0 TBTT [1]: Priority Mask for Tx response [0]: Priority Mask for Rx response*/
#define BIT_PRI_MASK(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_PRI_MASK(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_WMAC_MU_BF_CTL
  * @brief
  * @{
  */
#define BIT_WMAC_RETXBFRPTSEQ_UPD ((u32)0x00000001 << 0) /*!< R/W 0x0  */
/** @} */

/** @defgroup REG_RESP_TXINFO_CFG
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_RESP_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  MFB information in register for response packet*/
#define BIT_WMAC_RESP_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_WMAC_RESP_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_CSI_CTRL
  * @brief
  * @{
  */
#define BIT_WMAC_CSIREQ_OPT             ((u32)0x00000001 << 31)           /*!< R/W 0x0  clear csi report request if response fsm idle*/
#define BIT_WMAC_USE_NDPARATE           ((u32)0x00000001 << 30)           /*!< R/W 0x1  1: use ndpa rx rate to decide csi report rate 0: use ndp rx rate to decide csi report rate*/
#define BIT_MASK_CHINFO_CONTENT_BMASK   ((u32)0x0000000F << 26)           /*!< R/W 0xF  byte mask of 4byte contents value that need to compare when set to 1, the conrresponding byte need to compare*/
#define BIT_CHINFO_CONTENT_BMASK(x)     (((u32)((x) & 0x0000000F) << 26))
#define BIT_GET_CHINFO_CONTENT_BMASK(x) ((u32)(((x >> 26) & 0x0000000F)))
#define BIT_MASK_CHINFO_OFFSET          ((u32)0x000000FF << 18)           /*!< R/W 0x0  used for rx normal mode the payload offset for compare with configured value. 0 meansthe 0-3 bytes payload need to compare after header/iv/eiv*/
#define BIT_CHINFO_OFFSET(x)            (((u32)((x) & 0x000000FF) << 18))
#define BIT_GET_CHINFO_OFFSET(x)        ((u32)(((x >> 18) & 0x000000FF)))
#define BIT_WMAC_CSI_RATE_FORCE_EN      ((u32)0x00000001 << 15)           /*!< R/W 0x0  0: disable CSI force rate. Refer to RRSR bitmask 1: CSI frame Tx rate refers to 0x6DC[29:24]*/
#define BIT_MASK_WMAC_CSI_RSC_FORCE     ((u32)0x00000003 << 13)           /*!< R/W 0x0  If csi_force_rate_en = 1, CSI frame sub-channel configuration 00: Primary 20Mhz BW(0x483[3:0]) 01: Follow Rx packet BW. 10: Duplicate mode. 11: Reserved*/
#define BIT_WMAC_CSI_RSC_FORCE(x)       (((u32)((x) & 0x00000003) << 13))
#define BIT_GET_WMAC_CSI_RSC_FORCE(x)   ((u32)(((x >> 13) & 0x00000003)))
#define BIT_WMAC_CSI_GID_SEL            ((u32)0x00000001 << 12)           /*!< R/W 0x0  SIG-A content 1 :  group id=0, 0 :  group id=63*/
#define BIT_CSIRD_EMPTY_APPZERO         ((u32)0x00000001 << 8)            /*!< R/W 0x0  0: Not append zero data when rx_fifo read csi data to empty. If csi data length of BB transmitted is smaller than MAC expected, Tx CSI report would be FCS error. 1: Append zero data when rx_fifo read csi data to empty. If csi data length of BB transmitted is smaller than MAC expected, there would be zero before FCS field of Tx CSI report pkt and the CSI report pkt would be FCS ok*/
#define BIT_WMAC_CSI_RATE_FB_EN         ((u32)0x00000001 << 7)            /*!< R/W 0x0  Enable CSI frame rate fallback (only one step in CSI RRSR) This bit is set to 1 to enable MAC to use previous latched csi resp rate for retry pkt.*/
#define BIT_RXFIFO_WRPTR_WO_CHKSUM      ((u32)0x00000001 << 6)            /*!< R/W 0x0  This bit is set to 1 when rx_fifo don't enable csi data checksum.*/
#define BIT_MASK_RADAR_DATA_WTLMT       ((u32)0x00000007 << 3)            /*!< R/W 0x4  Wait timeout value after data on, unit 4 mac clock cycles*/
#define BIT_RADAR_DATA_WTLMT(x)         (((u32)((x) & 0x00000007) << 3))
#define BIT_GET_RADAR_DATA_WTLMT(x)     ((u32)(((x >> 3) & 0x00000007)))
/** @} */

/** @defgroup REG_CHINFO_CONTENT
  * @brief
  * @{
  */
#define BIT_MASK_CHINFO_CONTENT   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  the packet text value need hw to compare for channel info rx normal mode. When the content check function is enables, channel info will be reiggered only when the text match the cfg value.*/
#define BIT_CHINFO_CONTENT(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_CHINFO_CONTENT(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_SOUNDING_CFG1
  * @brief
  * @{
  */
#define BIT_MASK_RADAR_SIZE           ((u32)0x000007FF << 21)           /*!< R/W 0x0  radar prefull window for hw to check if buffer is enough for next radar pkt*/
#define BIT_RADAR_SIZE(x)             (((u32)((x) & 0x000007FF) << 21))
#define BIT_GET_RADAR_SIZE(x)         ((u32)(((x >> 21) & 0x000007FF)))
#define BIT_MASK_BF_ENDADDR           ((u32)0x000000FF << 13)           /*!< R/W 0x7F  beamforming csi data occupy size of csi buffer, eco use*/
#define BIT_BF_ENDADDR(x)             (((u32)((x) & 0x000000FF) << 13))
#define BIT_GET_BF_ENDADDR(x)         ((u32)(((x >> 13) & 0x000000FF)))
#define BIT_MASK_EXT_CSIBUF_ENDADDR   ((u32)0x00000007 << 10)           /*!< R/W 0x0  chinfo buffer endaddr extension. Chinfo buffer size={EXT_CSIBUF_ENDADDR, CSIBUF_ENDADDR}. Eco use*/
#define BIT_EXT_CSIBUF_ENDADDR(x)     (((u32)((x) & 0x00000007) << 10))
#define BIT_GET_EXT_CSIBUF_ENDADDR(x) ((u32)(((x >> 10) & 0x00000007)))
#define BIT_RELAY_IGNORE_BCNOFSAP     ((u32)0x00000001 << 9)            /*!< R/W 0x0  0: update tsft when bcn a2 fit last soft ap addr 1: not update tsft when bcn a2 fit last soft ap addr, eco use*/
#define BIT_MASK_WMAC_TXCSI_AID0      ((u32)0x000001FF << 0)            /*!< R/W 0x0  P_AID of the associated bemaformer0*/
#define BIT_WMAC_TXCSI_AID0(x)        (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_WMAC_TXCSI_AID0(x)    ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_CHINFO_ADDR
  * @brief
  * @{
  */
#define BIT_MASK_CHINFO_TX_ADDR_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  low 32bit tx address for trigger channel info*/
#define BIT_CHINFO_TX_ADDR_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_CHINFO_TX_ADDR_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CHINFO_CFG
  * @brief
  * @{
  */
#define BIT_CHINFO_CONTENT_EN        ((u32)0x00000001 << 30)           /*!< R/W 0x0  used for rx normal mode 1: the payload( excluding mac header/iv/eiv/mic/fcs) of the specified location must match the configured value 0: do not check the payload value*/
#define BIT_CHINFO_DROP_INVALID      ((u32)0x00000001 << 29)           /*!< R/W 0x1  when set to 1, will drop channe info if valid bit of bb header is 0*/
#define BIT_CHINFO_FCS               ((u32)0x00000001 << 28)           /*!< R/W 0x0  when set to 1, will not check channel info fcs ok flag*/
#define BIT_CHINFO_WTM_OUT           ((u32)0x00000001 << 27)           /*!< RW1C 0x0  BB does't send channel info when timeout occur*/
#define BIT_CHINFO_TIME_OUT          ((u32)0x00000001 << 26)           /*!< RW1C 0x0  BB send channel info length is less than report length*/
#define BIT_CSI_BUFF_FULL            ((u32)0x00000001 << 25)           /*!< RW1C 0x0  Indicate rxcsibuff full occur*/
#define BIT_MASK_CHINFO_DATA_WTLMT   ((u32)0x00000007 << 22)           /*!< R/W 0x4  Wait timeout value after repuest channe info, unit 4 mac clock cycles*/
#define BIT_CHINFO_DATA_WTLMT(x)     (((u32)((x) & 0x00000007) << 22))
#define BIT_GET_CHINFO_DATA_WTLMT(x) ((u32)(((x >> 22) & 0x00000007)))
#define BIT_CHINFO_RPT_DUMMY         ((u32)0x00000001 << 21)           /*!< R/W 0x0  1:rx chinfo rpt alll segment 0: rx chinfo rpt only data*/
#define BIT_CHINFO_TXADDR_EN         ((u32)0x00000001 << 20)           /*!< R/W 0x1  1: chinfo trigger condition need check a2 match txaddr or rx is cts/ack 0: not need to check a2*/
#define BIT_CHINFO_A1_EN             ((u32)0x00000001 << 19)           /*!< R/W 0x1  1: chinfo trigger condition need check a1 match self mac address 0: not need to check a1*/
#define BIT_MASK_CHINFO_MODE         ((u32)0x00000003 << 17)           /*!< R/W 0x0  channel info mode setting. 0: enable normal rx trigger; 1: enable ndpa trigger; note: repsonse mode decided by tx descriptor. Valid when r_CHINFO_EN is 1.*/
#define BIT_CHINFO_MODE(x)           (((u32)((x) & 0x00000003) << 17))
#define BIT_GET_CHINFO_MODE(x)       ((u32)(((x >> 17) & 0x00000003)))
#define BIT_CHINFO_EN                ((u32)0x00000001 << 16)           /*!< R/W 0x0  enable for getting channel info from BB. When set to 0, will not trigger channel info function*/
#define BIT_MASK_CHINFO_TX_ADDR_H    ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  high 16bit tx address for trigger channel info*/
#define BIT_CHINFO_TX_ADDR_H(x)      (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_CHINFO_TX_ADDR_H(x)  ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_RXCSIBUF_CFG
  * @brief
  * @{
  */
#define BIT_RADAR_DROP_INVALID       ((u32)0x00000001 << 31)           /*!< R/W 0x0  when set to 1, will not drop radar info if valid bit of bb header is 0*/
#define BIT_MASK_RADARBUF_ENDADDR    ((u32)0x000007FF << 20)           /*!< R/W 0x17F  rx radarbuffer boundary, default is 3K bytes*/
#define BIT_RADARBUF_ENDADDR(x)      (((u32)((x) & 0x000007FF) << 20))
#define BIT_GET_RADARBUF_ENDADDR(x)  ((u32)(((x >> 20) & 0x000007FF)))
#define BIT_MASK_RADARBUF_THRESHOD   ((u32)0x0000000F << 16)           /*!< R/W 0x4  rx radar buffer full threshold, size must greater than or equal to radar descriptors*/
#define BIT_RADARBUF_THRESHOD(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_RADARBUF_THRESHOD(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_RADAR_RX_EN              ((u32)0x00000001 << 15)           /*!< R/W 0x0  enable for getting radar rpt from BB. When set to 0, will not rx radar rpt from bb*/
#define BIT_MONOSENSE_RX_EN          ((u32)0x00000001 << 14)           /*!< R/W 0x0  enable for getting monosense from BB. When set to 0, will not rx monosense*/
#define BIT_MASK_CSIBUF_ENDADDR      ((u32)0x000000FF << 4)            /*!< R/W 0x7F  rxcsibuffer boundary, default is 1K bytes*/
#define BIT_CSIBUF_ENDADDR(x)        (((u32)((x) & 0x000000FF) << 4))
#define BIT_GET_CSIBUF_ENDADDR(x)    ((u32)(((x >> 4) & 0x000000FF)))
#define BIT_MASK_CSIBUF_THRESHOD     ((u32)0x0000000F << 0)            /*!< R/W 0x4  rxcsibuffer full threshold, size must greater than or equal to csi descriptors*/
#define BIT_CSIBUF_THRESHOD(x)       (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CSIBUF_THRESHOD(x)   ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CHINFO_TRIG_TYPE0
  * @brief
  * @{
  */
#define BIT_WMAC_CTRL_TRIG15EN ((u32)0x00000001 << 31) /*!< R/W 0x0  When set, frames with type=01 and subtype=1111 will triggerchannel info.*/
#define BIT_WMAC_CTRL_TRIG14EN ((u32)0x00000001 << 30) /*!< R/W 0x0  When set, frames with type=01 and subtype=1110 will triggerchannel info.*/
#define BIT_WMAC_CTRL_TRIG13EN ((u32)0x00000001 << 29) /*!< R/W 0x0  When set, frames with type=01 and subtype=1101 will triggerchannel info.*/
#define BIT_WMAC_CTRL_TRIG12EN ((u32)0x00000001 << 28) /*!< R/W 0x0  When set, frames with type=01 and subtype=1100 will triggerchannel info.*/
#define BIT_WMAC_CTRL_TRIG11EN ((u32)0x00000001 << 27) /*!< R/W 0x0  When set, frames with type=01 and subtype=1011 will triggerchannel info.*/
#define BIT_WMAC_CTRL_TRIG10EN ((u32)0x00000001 << 26) /*!< R/W 0x0  When set, frames with type=01 and subtype=1010 will triggerchannel info.*/
#define BIT_WMAC_CTRL_TRIG9EN  ((u32)0x00000001 << 25) /*!< R/W 0x0  When set, frames with type=01 and subtype=1001 will triggerchannel info.*/
#define BIT_WMAC_CTRL_TRIG8EN  ((u32)0x00000001 << 24) /*!< R/W 0x0  When set, frames with type=01 and subtype=1000 will triggerchannel info.*/
#define BIT_WMAC_CTRL_TRIG7EN  ((u32)0x00000001 << 23) /*!< R/W 0x0  When set, frames with type=01 and subtype=0111 will triggerchannel info.*/
#define BIT_WMAC_CTRL_TRIG6EN  ((u32)0x00000001 << 22) /*!< R/W 0x0  When set, frames with type=01 and subtype=0110 will triggerchannel info.*/
#define BIT_WMAC_CTRL_TRIG5EN  ((u32)0x00000001 << 21) /*!< R/W 0x0  When set, frames with type=01 and subtype=0101 will triggerchannel info.*/
#define BIT_WMAC_CTRL_TRIG4EN  ((u32)0x00000001 << 20) /*!< R/W 0x0  When set, frames with type=01 and subtype=0100 will triggerchannel info.*/
#define BIT_WMAC_CTRL_TRIG3EN  ((u32)0x00000001 << 19) /*!< R/W 0x0  When set, frames with type=01 and subtype=0011 will triggerchannel info.*/
#define BIT_WMAC_CTRL_TRIG2EN  ((u32)0x00000001 << 18) /*!< R/W 0x0  When set, frames with type=01 and subtype=0010 will triggerchannel info.*/
#define BIT_WMAC_CTRL_TRIG1EN  ((u32)0x00000001 << 17) /*!< R/W 0x0  When set, frames with type=01 and subtype=0001 will triggerchannel info.*/
#define BIT_WMAC_CTRL_TRIG0EN  ((u32)0x00000001 << 16) /*!< R/W 0x0  When set, frames with type=01 and subtype=0000 will triggerchannel info.*/
#define BIT_WMAC_MGT_TRIG15EN  ((u32)0x00000001 << 15) /*!< R/W 0x0  When set, frames with type=00 and subtype=1111 will triggerchannel info.*/
#define BIT_WMAC_MGT_TRIG14EN  ((u32)0x00000001 << 14) /*!< R/W 0x0  When set, frames with type=00 and subtype=1110 will triggerchannel info.*/
#define BIT_WMAC_MGT_TRIG13EN  ((u32)0x00000001 << 13) /*!< R/W 0x0  When set, frames with type=00 and subtype=1101 will triggerchannel info.*/
#define BIT_WMAC_MGT_TRIG12EN  ((u32)0x00000001 << 12) /*!< R/W 0x0  When set, frames with type=00 and subtype=1100 will triggerchannel info.*/
#define BIT_WMAC_MGT_TRIG11EN  ((u32)0x00000001 << 11) /*!< R/W 0x0  When set, frames with type=00 and subtype=1011 will triggerchannel info.*/
#define BIT_WMAC_MGT_TRIG10EN  ((u32)0x00000001 << 10) /*!< R/W 0x0  When set, frames with type=00 and subtype=1010 will triggerchannel info.*/
#define BIT_WMAC_MGT_TRIG9EN   ((u32)0x00000001 << 9)  /*!< R/W 0x0  When set, frames with type=00 and subtype=1001 will triggerchannel info.*/
#define BIT_WMAC_MGT_TRIG8EN   ((u32)0x00000001 << 8)  /*!< R/W 0x0  When set, frames with type=00 and subtype=1000 will triggerchannel info.*/
#define BIT_WMAC_MGT_TRIG7EN   ((u32)0x00000001 << 7)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0111 will triggerchannel info.*/
#define BIT_WMAC_MGT_TRIG6EN   ((u32)0x00000001 << 6)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0110 will triggerchannel info.*/
#define BIT_WMAC_MGT_TRIG5EN   ((u32)0x00000001 << 5)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0101 will triggerchannel info.*/
#define BIT_WMAC_MGT_TRIG4EN   ((u32)0x00000001 << 4)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0100 will triggerchannel info.*/
#define BIT_WMAC_MGT_TRIG3EN   ((u32)0x00000001 << 3)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0011 will triggerchannel info.*/
#define BIT_WMAC_MGT_TRIG2EN   ((u32)0x00000001 << 2)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0010 will triggerchannel info.*/
#define BIT_WMAC_MGT_TRIG1EN   ((u32)0x00000001 << 1)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0001 will triggerchannel info.*/
#define BIT_WMAC_MGT_TRIG0EN   ((u32)0x00000001 << 0)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0000 will triggerchannel info.*/
/** @} */

/** @defgroup REG_CHINFO_TRIG_TYPE1
  * @brief
  * @{
  */
#define BIT_WMAC_DATA_TRIG15EN ((u32)0x00000001 << 15) /*!< R/W 0x0  When set, frames with type=10 and subtype=1111 will triggerchannel info.*/
#define BIT_WMAC_DATA_TRIG14EN ((u32)0x00000001 << 14) /*!< R/W 0x0  When set, frames with type=10 and subtype=1110 will triggerchannel info.*/
#define BIT_WMAC_DATA_TRIG13EN ((u32)0x00000001 << 13) /*!< R/W 0x0  When set, frames with type=10 and subtype=1101 will triggerchannel info.*/
#define BIT_WMAC_DATA_TRIG12EN ((u32)0x00000001 << 12) /*!< R/W 0x0  When set, frames with type=10 and subtype=1100 will triggerchannel info.*/
#define BIT_WMAC_DATA_TRIG11EN ((u32)0x00000001 << 11) /*!< R/W 0x0  When set, frames with type=10 and subtype=1011 will triggerchannel info.*/
#define BIT_WMAC_DATA_TRIG10EN ((u32)0x00000001 << 10) /*!< R/W 0x0  When set, frames with type=10 and subtype=1010 will triggerchannel info.*/
#define BIT_WMAC_DATA_TRIG9EN  ((u32)0x00000001 << 9)  /*!< R/W 0x0  When set, frames with type=10 and subtype=1001 will triggerchannel info.*/
#define BIT_WMAC_DATA_TRIG8EN  ((u32)0x00000001 << 8)  /*!< R/W 0x0  When set, frames with type=10 and subtype=1000 will triggerchannel info.*/
#define BIT_WMAC_DATA_TRIG7EN  ((u32)0x00000001 << 7)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0111 will triggerchannel info.*/
#define BIT_WMAC_DATA_TRIG6EN  ((u32)0x00000001 << 6)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0110 will triggerchannel info.*/
#define BIT_WMAC_DATA_TRIG5EN  ((u32)0x00000001 << 5)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0101 will triggerchannel info.*/
#define BIT_WMAC_DATA_TRIG4EN  ((u32)0x00000001 << 4)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0100 will triggerchannel info.*/
#define BIT_WMAC_DATA_TRIG3EN  ((u32)0x00000001 << 3)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0011 will triggerchannel info.*/
#define BIT_WMAC_DATA_TRIG2EN  ((u32)0x00000001 << 2)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0010 will triggerchannel info.*/
#define BIT_WMAC_DATA_TRIG1EN  ((u32)0x00000001 << 1)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0001 will triggerchannel info.*/
#define BIT_WMAC_DATA_TRIG0EN  ((u32)0x00000001 << 0)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0000 will triggerchannel info.*/
/** @} */

/*==========REG_PAGE6_WMAC Register Address Definition==========*/
#define REG_WMAC_CR                      0x600
#define REG_TCR                          0x604
#define REG_RCR                          0x608
#define REG_RXPKT_CTL                    0x60C
#define REG_MACID                        0x610
#define REG_MACID_H                      0x614
#define REG_BSSID                        0x618
#define REG_BSSID_H                      0x61C
#define REG_LA_TRIGGER                   0x620
#define REG_A1_ADDR_MASK                 0x624
#define REG_INVALID_PKT_CTL              0x628
#define REG_PWRBIT_SETTING               0x62C
#define REG_WMAC_TCR_CTL                 0x630
#define REG_STMP_THSD                    0x634
#define REG_USTIME_EDCA                  0x638
#define REG_RESP_SIFS_CCK                0x63C
#define REG_ACKTO                        0x640
#define REG_RECCA_CTRL                   0x644
#define REG_CSI_PTR                      0x648
#define REG_BF_CTL                       0x64C
#define REG_NAV_THRSHOLD                 0x650
#define REG_BACAMCMD                     0x654
#define REG_WMAC_PLCP_MONITOR            0x658
#define REG_LBK_DLY                      0x660
#define REG_RXERR_RPT                    0x664
#define REG_WMAC_TRXPTCL_CTL             0x668
#define REG_WMAC_TRXPTCL_CTL_H           0x66C
#define REG_CAM_CFG                      0x670
#define REG_TRANSMIT_ADDRSS_0            0x674
#define REG_TRANSMIT_ADDRSS_0_H          0x678
#define REG_CAMDBG                       0x67C
#define REG_SECCFG                       0x680
#define REG_BCN_IEPSR0                   0x684
#define REG_BCN_IEPSR1                   0x688
#define REG_SOUNDING_CFG                 0x68C
#define REG_MYPKT_FLAG                   0x690
#define REG_BT_ZB_COEX_TB                0x694
#define REG_NAN_BSSID_L                  0x698
#define REG_NAN_BSSID_H                  0x69C
#define REG_RXFLTMAP0                    0x6A0
#define REG_RXFLTMAP                     0x6A4
#define REG_BCN_PSR_RPT0                 0x6A8
#define REG_NAN_TA_L                     0x6AC
#define REG_NAN_TA_H                     0x6B0
#define REG_STATE_MON                    0x6B4
#define REG_ERROR_EVT_CTL                0x6B8
#define REG_COEX_CFG_MACID_SRCH          0x6BC
#define REG_BT_COEX_TABLE_V1             0x6C0
#define REG_BT_COEX_TABLE2_V1            0x6C4
#define REG_BT_COEX_BREAK_TABLE          0x6C8
#define REG_BT_COEX_PRI_MASK             0x6CC
#define REG_WMAC_MU_BF_CTL               0x6D0
#define REG_WMAC_CSIDMA_CFG              0x6D4
#define REG_RESP_TXINFO_CFG              0x6D8
#define REG_CSI_CTRL                     0x6DC
#define REG_DUMMY_PAGE6                  0x6E0
#define REG_CHINFO_CONTENT               0x6E4
#define REG_SOUNDING_CFG1                0x6E8
#define REG_CHINFO_ADDR                  0x6EC
#define REG_CHINFO_CFG                   0x6F0
#define REG_RXCSIBUF_CFG                 0x6F4
#define REG_CHINFO_TRIG_TYPE0            0x6F8
#define REG_CHINFO_TRIG_TYPE1            0x6FC

/** @} */


// Do NOT modify any AUTO_GEN code above
/* AUTO_GEN_END */

/* MANUAL_GEN_START */

// Please add your definitions here

/* Exported Types ------------------------------------------------------------*/

/* Exported Constants --------------------------------------------------------*/

/* Exported Functions --------------------------------------------------------*/


/** @} */

/** @} */

// If other definitions do not need to be extracted to CHM document, add them here.
/* Other Definitions --------------------------------------------------------*/


/* MANUAL_GEN_END */

#endif