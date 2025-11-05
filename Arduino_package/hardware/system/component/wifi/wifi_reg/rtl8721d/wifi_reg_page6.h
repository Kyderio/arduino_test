#ifndef _project_name_REG_PAGE6_H_
#define _project_name_REG_PAGE6_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE6
  * @brief REG_PAGE6 driver modules
  * @{
  */


/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE6_Register_Definitions REG_PAGE6 Register Definitions
  * @{
  */

/** @defgroup REG_WMAC_CR
  * @brief WMAC CR Register
  * @{
  */
#define BIT_APSDOFF_STATUS ((u32)0x00000001 << 7) /*!< R 0x0  When APSDOFF bit is set, MAC will issue sleep signal to disable BB/AFE/RF TRX function. After MAC has finished, this bit will report "1". When APSDOFF bit is pulled low from high, MAC will issue wakeup signal to recall BB/AFE/RF back to RX idle mode. After MAC has finished, this bit will report "0".*/
#define BIT_APSDOFF        ((u32)0x00000001 << 6) /*!< R/W 0x0  When this bit is set, MAC will issue sleep signal to disable BB/AFE/RF TRX function. After MAC has finished, APSDOFF_STATUS will report "1". When this bit is pulled low from high, MAC will issue wakeup signal to recall BB/AFE/RF back to RX idle mode. After MAC has finished, APSDOFF _STATUS will report "0".*/
#define BIT_STANDBY_STATUS ((u32)0x00000001 << 5) /*!< R 0x0  Indicate WLANBB already enters standby mode*/
#define BIT_IC_MACPHY_M    ((u32)0x00000001 << 0) /*!< R/W 0x0  To make ASIC become BB+RF only, and put out the MAC_PHY interface*/
/** @} */

/** @defgroup REG_TCR
  * @brief Transmission Configuration Register
  * @{
  */
#define BIT_WMAC_TCRPWRMGT_HWCTL_V1 ((u32)0x00000001 << 26)           /*!< R/W 0x0  If this bit is set to 1, MAC will overwrite power bit of frame control according to  PWR_ST.  (only for RTS/CTS/ACK/CFEND/BA/BAR frames)*/
#define BIT_BF_SEL                  ((u32)0x00000001 << 25)           /*!< R/W 0x0  1: set ndp_rx_standby when rx ppdu of ndpa end; 0: set ndp_rx_standby when rx ndpa packet fcs end;*/
#define BIT_RXLEN_SEL               ((u32)0x00000001 << 24)           /*!< R/W 0x0  for rx length control for vht pkt*/
#define BIT_MASK_TSFT_CMP           ((u32)0x0000000F << 20)           /*!< R/W 0x0  TSFT insertion compensation value (unit in 1us) When inserting TSFT, add this value with local TSF timer as the timestamp.*/
#define BIT_TSFT_CMP(x)             (((u32)((x) & 0x0000000F) << 20))
#define BIT_GET_TSFT_CMP(x)         ((u32)(((x >> 20) & 0x0000000F)))
#define BIT_MASK_TSFT_CMP_CCK       ((u32)0x0000000F << 16)           /*!< R/W 0x0  TSFT insertion compensation value (unit in 1us) When inserting TSFT and Tx_rate is CCK, add this value with local TSF timer as the timestamp.*/
#define BIT_TSFT_CMP_CCK(x)         (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_TSFT_CMP_CCK(x)     ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_WMAC_TCR_ERRSTEN_3      ((u32)0x00000001 << 15)           /*!< R/W 0x0  Use phytxend_ps to reset mactx state machine*/
#define BIT_WMAC_TCR_ERRSTEN_2      ((u32)0x00000001 << 14)           /*!< R/W 0x0  If txd fifo underflow when txtype is cmpba, reset mactx state machine*/
#define BIT_WMAC_TCR_ERRSTEN_1      ((u32)0x00000001 << 13)           /*!< R/W 0x0  If txd fifo underflow, reset mactx state machine*/
#define BIT_WMAC_TCR_ERRSTEN_0      ((u32)0x00000001 << 12)           /*!< R/W 0x0  Phytxend_ps comes but mactx still active, reset mactx state machine*/
#define BIT_WMAC_TCR_TXSK_PERPKT    ((u32)0x00000001 << 11)           /*!< R/W 0x0  Search key for each mpdu*/
#define BIT_TXSK_PERPKT             ((u32)0x00000001 << 11)           /*!< R/W 0x0  Search key for each mpdu*/
#define BIT_ICV                     ((u32)0x00000001 << 10)           /*!< R/W 0x0  Integrity Check Value. This bit indicates the existence of an ICV appended to an encipherment packet. 1: No ICV appended 0: ICV appended*/
#define BIT_CFENDFORM               ((u32)0x00000001 << 9)            /*!< R/W 0x0  CF-End Frame Format The Address 2 field of CF-End is defined to be the address of the STA contained in the AP, but in 802.11n a STA can also send CF-End. The Address 2 field is not specified clearly in this case. This register chooses between MAC ID of the STA or BSSID of the network. 0: BSSID 1: MAC ID*/
#define BIT_CRC                     ((u32)0x00000001 << 8)            /*!< R/W 0x0  Append 32-bit Cyclic Redundancy Check. This bit indicates the existence of a CRC32 appended to a packet. 1: No CRC32 appended 0: A CRC32 is appended*/
#define BIT_WMAC_TCR_PWRMGT_CTL     ((u32)0x00000001 << 7)            /*!< R/W 0x0  Enable power management bit control.*/
#define BIT_WMAC_TCR_PWRMGT_VAL     ((u32)0x00000001 << 6)            /*!< R/W 0x0  Value of power management bit.*/
#define BIT_UPD_TIMIE               ((u32)0x00000001 << 5)            /*!< R/W 0x0  when set to 1, enable hw to update beacon's time field*/
#define BIT_UPD_HGQMD               ((u32)0x00000001 << 4)            /*!< R/W 0x0  when set to 1, enable HGQ  set moredata bit in Frame control field*/
#define BIT_VHTSIGA1_TXPS           ((u32)0x00000001 << 3)            /*!< R/W 0x0  This bit controls TXOP_PS_NOT_ALLOWED bit value of VHT-SIG-A1 field in TX VHT packets 1: TXOP_PS_NOT_ALLOWED is set to 1 0: TXOP_PS_NOT_ALLOWED is set to 0*/
#define BIT_PAD_SEL                 ((u32)0x00000001 << 2)            /*!< R/W 0x0  AMPDU Padding pattern selection, "0": 32-bit Zero padding, "1": Zero length delimiter.*/
#define BIT_DIS_GCLK                ((u32)0x00000001 << 1)            /*!< R/W 0x0  Disable MACTX clock gating control.*/
/** @} */

/** @defgroup REG_RCR
  * @brief Receive Configuration Register
  * @{
  */
#define BIT_APP_FCS       ((u32)0x00000001 << 31) /*!< R/W 0x0  When set, wmac RX will append FCS after payload.*/
#define BIT_APP_MIC       ((u32)0x00000001 << 30) /*!< R/W 0x0  When this bit is set to 1, MACRX will retain the MIC at the bottom of the packet. Otherwise, MIC will be removed and reported the status in RXDESC. When a MPDU is encrypted with TKIP without MIC, MACRX will ignore this option, that is, MIC must be remained in back of the plain text.*/
#define BIT_APP_ICV       ((u32)0x00000001 << 29) /*!< R/W 0x0  When this bit is set to 1, MACRX will retain the ICV at the bottom of the packet. Otherwise, MIC will be removed and reported the status in RXDESC.*/
#define BIT_APP_PHYSTS    ((u32)0x00000001 << 28) /*!< R/W 0x0  Append RXFF0 PHY Status Enable When this bit is set, then PHY Status is appended before RX packet in RXFF. When this bit is set, the RX_DRV_INFO_SZ shall be set to include PHY Status report.*/
#define BIT_APP_BASSN     ((u32)0x00000001 << 27) /*!< R/W 0x0  Append SSN of previous TXBA Enable When this bit is set, then SSN of previous TXBA is appended as after original RXDESC as the 4-th DW of RXDESC.*/
#define BIT_VHT_DACK      ((u32)0x00000001 << 26) /*!< R/W 0x0  This bit to control response type for vht single mpdu data packet. 1. ACK as response 0. BA as response*/
#define BIT_TCPOFLD_EN    ((u32)0x00000001 << 25) /*!< R/W 0x0  Enable TCP checksum offload*/
#define BIT_ENMBID        ((u32)0x00000001 << 24) /*!< R/W 0x0  Enable Multiple BssId. 1: Enable. Only response ACK to the packets whose DID(A1) matching to the addresses in the MBSSID CAM Entries. 0: Disable.*/
#define BIT_LSIGEN        ((u32)0x00000001 << 23) /*!< R/W 0x0  Enable LSIG TXOP Protection function. 1: Enable. Search KEYCAM for each rx packet to check if LSIGEN bit is set. If LSIGEN is set, then sender support LSIG TXOP protection and we need send response with LSIG TXOP protection 0: Disable*/
#define BIT_MFBEN         ((u32)0x00000001 << 22) /*!< R/W 0x0  Enable immediate MCS Feedback function 1: Enable. When Rx packet with MRQ = 1"b1, then search KEYCAM to find sender"s MCS Feedback function and send response 0: Disable*/
#define BIT_DISCHKPPDLLEN ((u32)0x00000001 << 21) /*!< R/W 0x0  Do not check PPDU while the PPDU length is smaller than 14 byte.*/
#define BIT_PKTCTL_DLEN   ((u32)0x00000001 << 20) /*!< R/W 0x0  While rx path dead lock occurs, reset rx path*/
#define BIT_DISGCLK       ((u32)0x00000001 << 19) /*!< R/W 0x0  Disable macrx clock gating control*/
#define BIT_TIMPSR_EN     ((u32)0x00000001 << 18) /*!< R/W 0x0  RX Beacon TIM Parser*/
#define BIT_BCMDINT_EN    ((u32)0x00000001 << 17) /*!< R/W 0x0  Broadcast data packet interrupt enable. When this bit is set, this bit is auto clear by MAC. As long as a data type broadcast packet is received, this bit will be set.*/
#define BIT_UCMDINT_EN    ((u32)0x00000001 << 16) /*!< R/W 0x0  Unicast data packet with FC.MD = 1 interrupt enable. When this bit is set, this bit is auto clear by MAC. As long as a data type unicast packet is received, this bit will be set.*/
#define BIT_RXSK_PERPKT   ((u32)0x00000001 << 15) /*!< R/W 0x0  Executing key search per MPDU*/
#define BIT_HTCBFMC       ((u32)0x00000001 << 14) /*!< R/W 0x0  1: HTC -> MFC, 0: MFC-> HTC*/
#define BIT_AMF           ((u32)0x00000001 << 13) /*!< R/W 0x0  Accept Management Frame. This bit determines whether the RTL8192D will accept or reject a management frame. 1: Accept 0: Check RXFLTMAP0 for subtype matched(accept) or not(reject).*/
#define BIT_ACF           ((u32)0x00000001 << 12) /*!< R/W 0x0  Accept Control Frame. This bit determines whether the RTL8192D will accept or reject a control frame. However, control frames BA, BAR, and PS-Poll (when in AP mode) are not controlled by this bit. They are controlled by ADF. 1: Accept 0: Check RXFLTMAP1 for subtype matched(accept) or not(reject).*/
#define BIT_ADF           ((u32)0x00000001 << 11) /*!< R/W 0x0  Accept Data Frame. This bit determines whether the RTL8192D will accept or reject a data frame. This bit also regulates BA, BAR, and PS-Poll (AP mode only). . 1: Accept 0: Check RXFLTMAP2 for subtype matched(accept) or not(reject)*/
#define BIT_DISDECNMYPKT  ((u32)0x00000001 << 10) /*!< R/W 0x0  This bit determines whether hw need to do decryption. 1: If A1 match or broadcast, do decryption. 0: Do decryption.*/
#define BIT_AICV          ((u32)0x00000001 << 9)  /*!< R/W 0x0  Accept Integrity Check Value Error packets. This bit determines whether packets with ICV errors will be accepted or rejected. 1: Accept 0: Reject*/
#define BIT_ACRC32        ((u32)0x00000001 << 8)  /*!< R/W 0x0  Accept CRC32 Error packets. When set to 1, packets with CRC32 errors will be accepted. When set to 0, packets with CRC32 errors will be rejected. 1: Accept 0: Reject*/
#define BIT_CBSSID_MGNT   ((u32)0x00000001 << 7)  /*!< R/W 0x0  Check BSSID_BCN When set to 1, MAC will check the BSSID of RX beacon or Probe response to determine if this packet belongs to this BSSID.*/
#define BIT_CBSSID_DATA   ((u32)0x00000001 << 6)  /*!< R/W 0x0  Check BSSID_DATA, To DS, From DS Match Packet. When set to 1, MAC will check the Rx data type frame"s BSSID, To DS, and From DS fields, to determine if it is set to Link OK in an Infrastructure or Ad hoc network. Note this setting is independent of nettype. Driver must set this bit in ad hoc mode and client mode.*/
#define BIT_APWRMGT       ((u32)0x00000001 << 5)  /*!< R/W 0x0  Accept Power Management Packet. This bit determines whether the RTL8192D will accept or reject packets with the power management bit set. 1: Accept 0: Reject*/
#define BIT_ADD3          ((u32)0x00000001 << 4)  /*!< R/W 0x0  Accept Address 3 Match Packets. Set this bit to 1 to accept broadcast/multicast data type frames that Address 3 matching RTL8190"s MAC address. This bit is valid only when NETYPE (bit 3-2, MSR) is set to Link OK on an Infrastructure network.*/
#define BIT_AB            ((u32)0x00000001 << 3)  /*!< R/W 0x0  Accept Broadcast packets. This bit determines whether broadcast packets will be accepted or rejected. 1: Accept 0: Reject*/
#define BIT_AM            ((u32)0x00000001 << 2)  /*!< R/W 0x0  Accept Multicast packets. This bit determines whether multicast packets will be accepted or rejected. 1: Accept 0: Reject*/
#define BIT_APM           ((u32)0x00000001 << 1)  /*!< R/W 0x0  Accept Physical Match packets. This bit determines whether physical match packets will be accepted or rejected. 1: Accept 0: Reject*/
#define BIT_AAP           ((u32)0x00000001 << 0)  /*!< R/W 0x0  Accept Destination Address packets. This bit determines whether packets with a destination address will be accepted or rejected.  1: Accept 0: Reject*/
/** @} */

/** @defgroup REG_RXPKT_LIMIT
  * @brief RX Packet Length Limit Register
  * @{
  */
#define BIT_MASK_RXPKTLMT   ((u8)0x0000003F << 0)           /*!< R/W 0x20  RX PKT Upper Limit. The unit is 512 bytes. When "0", no RX limit is forced.*/
#define BIT_RXPKTLMT(x)     (((u8)((x) & 0x0000003F) << 0))
#define BIT_GET_RXPKTLMT(x) ((u8)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_RX_DLK_TIME
  * @brief RX Deadlock Time Register
  * @{
  */
#define BIT_MASK_RX_DLK_TIME   ((u8)0x000000FF << 0)           /*!< R/W 0x0  macrx dead lock timer timeout value (unit in 4us).  As CCA is deasserted and no RXD is received but macrx still waits coming RXD, the deadlock timer will be enabled in this case*/
#define BIT_RX_DLK_TIME(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_RX_DLK_TIME(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_SDIO_RXINT_LEN_TH
  * @brief
  * @{
  */
#define BIT_MASK_SDIO_RXINT_LEN_TH   ((u8)0x000000FF << 0)           /*!< R/W 0x0  SDIO rx interface length threshold.*/
#define BIT_SDIO_RXINT_LEN_TH(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_SDIO_RXINT_LEN_TH(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RX_DRVINFO_SZ
  * @brief RX Driver INFO Size Register
  * @{
  */
#define BIT_APP_PHYSTS_PER_SUBMPDU ((u8)0x00000001 << 7)           /*!< R/W 0x0  When this bit is set to 1,append phy status for each mpdu if phy status is valid. Otherwise,append phy status for each ppdu.*/
#define BIT_APP_MH_SHIFT_VAL       ((u8)0x00000001 << 6)           /*!< R/W 0x0  When this bit is set to 1,append MAC header shift value in rx descriptor,otherwise, not append*/
#define BIT_WMAC_ENSHIFT           ((u8)0x00000001 << 5)           /*!< R/W 0x0  MAC header shift function enable signal in MACRX*/
#define BIT_MASK_DRVINFO_SZ_V1     ((u8)0x0000000F << 0)           /*!< R/W 0x0  RX DESC Driver Info Size: For RXPKTBUF layout, this field indicates the offset starting from the end of RXDESC to the beginning of RX packet. The unit is 8-byte. This value will be copied to DRV_INFO_SIZE field in RXDESC.*/
#define BIT_DRVINFO_SZ_V1(x)       (((u8)((x) & 0x0000000F) << 0))
#define BIT_GET_DRVINFO_SZ_V1(x)   ((u8)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_MACID_H
  * @brief MAC ID Register
  * @{
  */
#define BIT_MASK_MACID_H   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  MAC Identification Number Register BIT[47:32]*/
#define BIT_MACID_H(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MACID_H(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BSSID
  * @brief BSSID Register
  * @{
  */
#define BIT_MASK_BSSID_V1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Basic Station Set Identification BIT[31:0]*/
#define BIT_BSSID_V1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BSSID_V1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BSSID_H
  * @brief BSSID Register
  * @{
  */
#define BIT_MASK_BSSID_H   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  Basic Station Set Identification BIT[47:32]*/
#define BIT_BSSID_H(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BSSID_H(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MAR
  * @brief Multicast Address Register
  * @{
  */
#define BIT_MASK_MAR_V1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Multicast Address Register BIT[31:0]. The value of this register is written by the driver to specify the type of multicast address supported by RTL8192D. The value is created by a hashed calculation that is also implemented by the hardware for multicast address filtering.*/
#define BIT_MAR_V1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MAR_V1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MAR_H
  * @brief Multicast Address Register
  * @{
  */
#define BIT_MASK_MAR_H   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Multicast Address Register BIT[63:32]. The value of this register is written by the driver to specify the type of multicast address supported by RTL8192D. The value is created by a hashed calculation that is also implemented by the hardware for multicast address filtering.*/
#define BIT_MAR_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MAR_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAMCFG_1
  * @brief MBSSID CAM Configuration Register
  * @{
  */
#define BIT_MASK_MBIDCAM_RWDA_TA_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  BSSID[31:0]*/
#define BIT_MBIDCAM_RWDA_TA_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM_RWDA_TA_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM_CFG
  * @brief MBSSID CAM Configuration Register
  * @{
  */
#define BIT_MBIDCAM_POLL            ((u32)0x00000001 << 31)           /*!< W 0x0  Pooling bit.*/
#define BIT_MBIDCAM_WT_EN           ((u32)0x00000001 << 30)           /*!< R/W 0x0  Write Enable.*/
#define BIT_MBIDCAM_RST_V1          ((u32)0x00000001 << 29)           /*!< R/W 0x0  Reset bit*/
#define BIT_MASK_MBIDCAM_ADDR       ((u32)0x0000001F << 24)           /*!< R/W 0x0  CAM Address*/
#define BIT_MBIDCAM_ADDR(x)         (((u32)((x) & 0x0000001F) << 24))
#define BIT_GET_MBIDCAM_ADDR(x)     ((u32)(((x >> 24) & 0x0000001F)))
#define BIT_MBIDCAM_VALID           ((u32)0x00000001 << 23)           /*!< R/W 0x0  CAM Valid bit.*/
#define BIT_LSIC_TXOP_EN            ((u32)0x00000001 << 17)           /*!< R/W 0x0  LSIG TXOP enable*/
#define BIT_CTS_EN                  ((u32)0x00000001 << 16)           /*!< R/W 0x0  Dual CTS/CFE enable*/
#define BIT_MASK_MBIDCAM_RWDATA_H   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  BSSID[47:32]*/
#define BIT_MBIDCAM_RWDATA_H(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM_RWDATA_H(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_USTIME_EDCA
  * @brief US Time Tuning for EDCA Register
  * @{
  */
#define BIT_MASK_USTIME   ((u16)0x000000FF << 0)           /*!< R/W 0x28  Sets the microsecond time unit used by MAC EDCA clock.*/
#define BIT_USTIME(x)     (((u16)((x) & 0x000000FF) << 0))
#define BIT_GET_USTIME(x) ((u16)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_MAC_SPEC_SIFS
  * @brief Specification SIFS Register
  * @{
  */
#define BIT_MASK_SPEC_SIFS_OFDM   ((u16)0x000000FF << 8)           /*!< R/W 0x10  The spec SIFS value for duration calculation*/
#define BIT_SPEC_SIFS_OFDM(x)     (((u16)((x) & 0x000000FF) << 8))
#define BIT_GET_SPEC_SIFS_OFDM(x) ((u16)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_SPEC_SIFS_CCK    ((u16)0x000000FF << 0)           /*!< R/W 0x0A  The spec SIFS value for duration calculation*/
#define BIT_SPEC_SIFS_CCK(x)      (((u16)((x) & 0x000000FF) << 0))
#define BIT_GET_SPEC_SIFS_CCK(x)  ((u16)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RESP_SIFS_CCK
  * @brief Response SIFS for CCK Register
  * @{
  */
#define BIT_MASK_R2T_SIFS_CCK   ((u16)0x000000FF << 8)           /*!< R/W 0x10  This register sets the SIFS time required for any immediate response for example Data-Ack. It is in unit of us.*/
#define BIT_R2T_SIFS_CCK(x)     (((u16)((x) & 0x000000FF) << 8))
#define BIT_GET_R2T_SIFS_CCK(x) ((u16)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_T2T_SIFS_CCK   ((u16)0x000000FF << 0)           /*!< R/W 0x10  This register sets the SIFS time required for consecutive TX events for example CTS-Data, or broadcast bursting. It is in unit of us.*/
#define BIT_T2T_SIFS_CCK(x)     (((u16)((x) & 0x000000FF) << 0))
#define BIT_GET_T2T_SIFS_CCK(x) ((u16)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RESP_SIFS_OFDM
  * @brief Response SIFS for OFDM Register
  * @{
  */
#define BIT_MASK_R2T_SIFS_OFDM   ((u16)0x000000FF << 8)           /*!< R/W 0x10  This register sets the SIFS time required for any immediate response for example Data-Ack. It is in unit of us.*/
#define BIT_R2T_SIFS_OFDM(x)     (((u16)((x) & 0x000000FF) << 8))
#define BIT_GET_R2T_SIFS_OFDM(x) ((u16)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_T2T_SIFS_OFDM   ((u16)0x000000FF << 0)           /*!< R/W 0x10  This register sets the SIFS time required for consecutive TX events for example CTS-Data, or broadcast bursting. It is in unit of us.*/
#define BIT_T2T_SIFS_OFDM(x)     (((u16)((x) & 0x000000FF) << 0))
#define BIT_GET_T2T_SIFS_OFDM(x) ((u16)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_ACKTO
  * @brief ACK Timeout Register
  * @{
  */
#define BIT_MASK_ACKTO   ((u8)0x000000FF << 0)           /*!< R/W 0x14  This register sets the Ack time out value after Tx unicast packet. It is in units of us.*/
#define BIT_ACKTO(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_ACKTO(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_CTS2TO
  * @brief CTS2 Timeout Register
  * @{
  */
#define BIT_MASK_CTS2TO   ((u8)0x000000FF << 0)           /*!< R/W 0x14  This register sets the CTS2 time out value after CTS1 in Dual CTS sequence. It is in units of us.*/
#define BIT_CTS2TO(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_CTS2TO(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_EIFS
  * @brief EIFS Register
  * @{
  */
#define BIT_MASK_EIFS   ((u16)0x0000FFFF << 0)           /*!< R/W 0x013A  This register sets the EIFS value mentioned in 802.11 specification. It is in units of us. To receive 1Mbps ACK frame, EIFS = SIFS + 144us (preamble length) + 48us (PLCP header length) + 112us (14 bytes of data) = 314us.*/
#define BIT_EIFS(x)     (((u16)((x) & 0x0000FFFF) << 0))
#define BIT_GET_EIFS(x) ((u16)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_NAV_CTRL
  * @brief NAV Control Register
  * @{
  */
#define BIT_MASK_NAV_UPPER     ((u32)0x000000FF << 16)           /*!< R/W 0x0  When NAV update is beyond this value, then NAV update is aborted. When this field is 0x00, NAV_UPPER function is disable. The unit is 128us.*/
#define BIT_NAV_UPPER(x)       (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_NAV_UPPER(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_RXMYRTS_NAV   ((u32)0x0000000F << 8)            /*!< R/W 0x0  RX my RTS NAV As rx my unicast RTS and RxMyRTS_NAV is not equal to zero, then rx NAV is set to wait response transition time and RxMyRTS_NAV to avoid contention with the TXOP originator. If RxMyRTS_NAV is equal to zero, this mechanism is disabled*/
#define BIT_RXMYRTS_NAV(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_RXMYRTS_NAV(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_RTSRST        ((u32)0x000000FF << 0)            /*!< R/W 0x26  RTS NAV Reset Time This is the value in us, not including the time of CTS frame, to reset the NAV set by an RTS frame if no PHY indication occurred during this time. Refer to 802.11 1999 Section 9.2.5.4 for detailed description.*/
#define BIT_RTSRST(x)          (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_RTSRST(x)      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BACAMCMD
  * @brief Block ACK CAM Command Register
  * @{
  */
#define BIT_BACAM_POLL        ((u32)0x00000001 << 31)           /*!< W 0x0  Polling bit BA CAM*/
#define BIT_BACAM_RW          ((u32)0x00000001 << 16)           /*!< R/W 0x0  Set 1 = Write, set 0 = Read*/
#define BIT_MASK_TXSBMPMOD    ((u32)0x00000003 << 14)           /*!< R/W 0x0  Bit[15]: if macrx_dma idle, grant txsbmp_req Bit[14]: if macrx is idle, grant txsbmp_req 00: If FSM is idle, grant txsbmp_req 01: If FSM and mac rx is idle, grant txsbmp_req 10: If FSM and macrx_dma is idle, grant txsbmp_req 11: if FSM, macrx and macrx_dma is idle, grant txsbmp_req*/
#define BIT_TXSBMPMOD(x)      (((u32)((x) & 0x00000003) << 14))
#define BIT_GET_TXSBMPMOD(x)  ((u32)(((x >> 14) & 0x00000003)))
#define BIT_MASK_BACAM_ADDR   ((u32)0x0000003F << 0)            /*!< R/W 0x0  BA CAM address. Memory is double-word access.*/
#define BIT_BACAM_ADDR(x)     (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_BACAM_ADDR(x) ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_BACAM_WD
  * @brief Block ACK CAM Content Register
  * @{
  */
#define BIT_MASK_BA_CONTENT_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Used for CAM content read and write access register. Because BA CAM is 64 bit access, the double word (32-bit) responds to the lower 32 bits of CAM content.*/
#define BIT_BA_CONTENT_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BA_CONTENT_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM_WD_H
  * @brief Block ACK CAM Content Register
  * @{
  */
#define BIT_MASK_BA_CONTENT_H   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Used for CAM content read and write access register. Because BA CAM is 64 bit access, the double word (32-bit) responds to the upper 32 bits of CAM content.*/
#define BIT_BA_CONTENT_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BA_CONTENT_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_LBK_DLY
  * @brief Loopback Delay Register
  * @{
  */
#define BIT_MASK_LBDLY   ((u8)0x0000001F << 0)           /*!< R/W 0x0  Loopback Delay. In unit of 'us'; indicates the delay after which the tdrdy_mac starts. In wep/tkip mode, the delay should be larger than 15, because the initial delay of security is about 1320 cycles, approximately to 16.5 us.*/
#define BIT_LBDLY(x)     (((u8)((x) & 0x0000001F) << 0))
#define BIT_GET_LBDLY(x) ((u8)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_BITMAP_CMD
  * @brief
  * @{
  */
#define BIT_MASK_BITMAP_SSNBK_COUNTER   ((u8)0x0000003F << 2)           /*!< R 0x0  Count the sequence number out of BITMAP condition (0x663[3:2]).*/
#define BIT_BITMAP_SSNBK_COUNTER(x)     (((u8)((x) & 0x0000003F) << 2))
#define BIT_GET_BITMAP_SSNBK_COUNTER(x) ((u8)(((x >> 2) & 0x0000003F)))
#define BIT_BITMAP_EN                   ((u8)0x00000001 << 1)           /*!< R/W 0x0  1:Enable of counter and WMAC_BITMAP_CTL(0x663) 2.Disable function*/
#define BIT_BACAM_RPMEN                 ((u8)0x00000001 << 0)           /*!< R/W 0x0  1:Enable repeat mode*/
/** @} */

/** @defgroup REG_TX_RX_STATUS
  * @brief
  * @{
  */
#define BIT_MASK_RXPKT_TYPE   ((u8)0x0000003F << 2)           /*!< R 0x0  The type and subtype field of frame control of rx packet*/
#define BIT_RXPKT_TYPE(x)     (((u8)((x) & 0x0000003F) << 2))
#define BIT_GET_RXPKT_TYPE(x) ((u8)(((x >> 2) & 0x0000003F)))
#define BIT_TXACT_IND         ((u8)0x00000001 << 1)           /*!< R 0x0  Indicate MAC/PHY is busy to tx packet*/
#define BIT_RXACT_IND         ((u8)0x00000001 << 0)           /*!< R 0x0  Indicate MAC is busy to rx packet*/
/** @} */

/** @defgroup REG_WMAC_BITMAP_CTL
  * @brief
  * @{
  */
#define BIT_BITMAP_VO                ((u8)0x00000001 << 7)           /*!< W1S 0x0  When BIT_BITMAP_VO = 1,  HW will check received packet's sequence number by BIT_BITMAP_CONDITION, and clear the bit after occur one time which received the correct sequence number.*/
#define BIT_BITMAP_VI                ((u8)0x00000001 << 6)           /*!< W1S 0x0  When BIT_BITMAP_VI = 1,  HW will check received packet's sequence number by BIT_BITMAP_CONDITION, and clear the bit after occur one time which received the correct sequence number.*/
#define BIT_BITMAP_BE                ((u8)0x00000001 << 5)           /*!< W1S 0x0  When BIT_BITMAP_BE = 1,  HW will check received packet's sequence number by BIT_BITMAP_CONDITION, and clear the bit after occur one time which received the correct sequence number.*/
#define BIT_BITMAP_BK                ((u8)0x00000001 << 4)           /*!< W1S 0x0  When BIT_BITMAP_BK = 1,  HW will check received packet's sequence number by BIT_BITMAP_CONDITION, and clear the bit after occur one time which received the correct sequence number.*/
#define BIT_MASK_BITMAP_CONDITION    ((u8)0x00000003 << 2)           /*!< R/W 0x0  ADDBA condition: 0: HW start sequence - 64. 1: HW start sequence - 128. 2: HW start sequence - 256. 3: HW start sequence - 512.*/
#define BIT_BITMAP_CONDITION(x)      (((u8)((x) & 0x00000003) << 2))
#define BIT_GET_BITMAP_CONDITION(x)  ((u8)(((x >> 2) & 0x00000003)))
#define BIT_BITMAP_SSNBK_COUNTER_CLR ((u8)0x00000001 << 1)           /*!< W1C 0x0  Clear BIT_BITMAP_SSNBK_COUNTER.*/
#define BIT_BITMAP_FORCE             ((u8)0x00000001 << 0)           /*!< R/W 0x0  Under the BIT_BITMAP_EN = 1 condition. 1: Rx's packet always checks sequence number by BIT_BITMAP_CONDITION. 0: Disable*/
/** @} */

/** @defgroup REG_RXERR_RPT
  * @brief RX Error Report Register
  * @{
  */
#define BIT_MASK_RXERR_RPT_SEL_V1_3_0   ((u32)0x0000000F << 28)           /*!< R/W 0x0  Rx packet counter report selection bit3~bit0 RXERR_RPT_SEL[4:0]: Counter description 5'd0: OFDM MPDU OK counter 5'd1: OFDM MPDU Fail counter 5'd2: OFDM False Alarm counter 5'd3: CCK MPDU OK counter 5'd4: CCK MPDU Fail counter 5'd5: CCK False Alarm counter; 5'd6: HT MPDU OK counter 5'd7: HT MPDU Fail counter 5'd8: HT PPDU counter 5'd9: HT False Alarm counter 5'd10: Rx full drop packet counter 5'd11: RSVD 5'd12: user define 0 counter 5'd13: user define 1 counter 5'd14: user define 2 counter 5'd15: user define 3 counter 5'd16: VHT MPDU OK counter 5'd17: VHT MPDU Fail counter 5'd18: VHT PPDU counter 5'd19: VHT False Alarm counter 5'd23: invalid_pkt counter*/
#define BIT_RXERR_RPT_SEL_V1_3_0(x)     (((u32)((x) & 0x0000000F) << 28))
#define BIT_GET_RXERR_RPT_SEL_V1_3_0(x) ((u32)(((x >> 28) & 0x0000000F)))
#define BIT_RXERR_RPT_RST               ((u32)0x00000001 << 27)           /*!< W 0x0  Write "one" to set the counter to zero.*/
#define BIT_RXERR_RPT_SEL_V1_4          ((u32)0x00000001 << 26)           /*!< R/W 0x0  Rx packet counter report selection bit4*/
#define BIT_W1S                         ((u32)0x00000001 << 23)           /*!< R/W 0x0  Write One Setting, it is only valid for RXERR_RPT_SEL (4'd12 ~ 4'd15)*/
#define BIT_UD_SELECT_BSSID             ((u32)0x00000001 << 22)           /*!< R/W 0x0  Select BSSID: 0: Port 0 1: Port 1*/
#define BIT_MASK_UD_SUB_TYPE            ((u32)0x0000000F << 18)           /*!< R/W 0x0  User defined: SubType*/
#define BIT_UD_SUB_TYPE(x)              (((u32)((x) & 0x0000000F) << 18))
#define BIT_GET_UD_SUB_TYPE(x)          ((u32)(((x >> 18) & 0x0000000F)))
#define BIT_MASK_UD_TYPE                ((u32)0x00000003 << 16)           /*!< R/W 0x0  User defined: Type*/
#define BIT_UD_TYPE(x)                  (((u32)((x) & 0x00000003) << 16))
#define BIT_GET_UD_TYPE(x)              ((u32)(((x >> 16) & 0x00000003)))
#define BIT_MASK_RPT_COUNTER            ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  The reported counter value corresponding to Report type selected.*/
#define BIT_RPT_COUNTER(x)              (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_RPT_COUNTER(x)          ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_WMAC_TRXPTCL_CTL
  * @brief WMAC TX
  * @{
  */
#define BIT_BLK_EDCA_BBSLP                  ((u32)0x00000001 << 31)           /*!< R/W 0x0  Block EDCA Tx while BB in sleep state*/
#define BIT_BLK_EDCA_BBSBY                  ((u32)0x00000001 << 30)           /*!< R/W 0x0  Block EDCA Tx while BB in standby state*/
#define BIT_ACKTO_BLOCK_S_CH_EN             ((u32)0x00000001 << 27)           /*!< R/W 0x0  While in ACKTO duration, block scheduler top to TX*/
#define BIT_EIFS_BLOCK_SCH__EN              ((u32)0x00000001 << 26)           /*!< R/W 0x0  While in EIFS duration, block scheduler top to TX*/
#define BIT_PLCPCHK_RST_EIF_S               ((u32)0x00000001 << 25)           /*!< R/W 0x0  Reset EIFS counter while receive correct PLCP.*/
#define BIT_CCA_RST_EIFS                    ((u32)0x00000001 << 24)           /*!< R/W 0x0  Reset EIFS counter while CCA on*/
#define BIT_DIS_UPD_MYRXP_KTNAV             ((u32)0x00000001 << 23)           /*!< R/W 0x0  Do not update NAV, while receiving my packet.*/
#define BIT_EARLY_TXBA                      ((u32)0x00000001 << 22)           /*!< R/W 0x0  While phyrxon down, mac_rxactive on. Ignore mac rx busy, respond BA immediately.*/
#define BIT_MASK_RESP_CHNBUSY               ((u32)0x00000003 << 20)           /*!< R/W 0x03  Define channel busy condition in responder to determine RX busy Bit1: PHYRXON (OFDM_VBON/CCKCCA) Bit0: CCA (CCKCCA/OFDMCCA)*/
#define BIT_RESP_CHNBUSY(x)                 (((u32)((x) & 0x00000003) << 20))
#define BIT_GET_RESP_CHNBUSY(x)             ((u32)(((x >> 20) & 0x00000003)))
#define BIT_RESP_DCTS_EN                    ((u32)0x00000001 << 19)           /*!< R/W 0x0  Enable responder send dual CTS for responding Rx RTS*/
#define BIT_RESP_DCFE_EN                    ((u32)0x00000001 << 18)           /*!< R/W 0x0  Enable responder send dual CF-END for responding RX CF-END*/
#define BIT_RESP_SPLCPEN                    ((u32)0x00000001 << 17)           /*!< R/W 0x0  Enable responder send SPLCP CCK response for acknowledging Rx SPLCP CCK packet*/
#define BIT_RESP_SGIEN                      ((u32)0x00000001 << 16)           /*!< R/W 0x0  Enable responder send SGI HT-OFDM response for acknowledging Rx SGI HT-OFDM packet*/
#define BIT_RESP_LDPC_EN                    ((u32)0x00000001 << 15)           /*!< R/W 0x0  if rxpkt with ldpc, response pkt with ldpc*/
#define BIT_DIS_RESP_ACKINC_CA              ((u32)0x00000001 << 14)           /*!< R/W 0x0  Disable to response ack when cca goes high after SIFS*/
#define BIT_DIS_RESP_CTSINC_CA              ((u32)0x00000001 << 13)           /*!< R/W 0x0  8812 Disable to response cts when cca goes high after SIFS*/
#define BIT_MASK_R_WMAC_SECOND__CCA_TIMER   ((u32)0x00000007 << 10)           /*!< R/W 0x0  8812 The maximum time interval in us that secondary cca is pull high before primary cca When receive duplicated rts. When station response with cts, if the time that secondary cca pull high before primary cca is larger than this threshold, then secondary cca is judged to be interference, otherwise it is judged to the received RTS frame. default: 3"b0*/
#define BIT_R_WMAC_SECOND__CCA_TIMER(x)     (((u32)((x) & 0x00000007) << 10))
#define BIT_GET_R_WMAC_SECOND__CCA_TIMER(x) ((u32)(((x >> 10) & 0x00000007)))
#define BIT_MASK_RFMOD                      ((u32)0x00000003 << 7)            /*!< R/W 0x0  8812 RF_BW indication, Used to decide response duplicated cts txsc 2"b00: 20M, 2"b01: 40M, 2"b10: 80M e.g: when RF_BW= 80M, duplicated cts BW= 40M, txsc = 9 or 10 when RF_BW = 40M, duplicated cts BW = 40M, txsc = 0*/
#define BIT_RFMOD(x)                        (((u32)((x) & 0x00000003) << 7))
#define BIT_GET_RFMOD(x)                    ((u32)(((x >> 7) & 0x00000003)))
#define BIT_MASK_RESP_CTS_DYNB_W_SEL        ((u32)0x00000003 << 5)            /*!< R/W 0x0  8812 Response cts bw selection when dynamic rts frame is received 2"b00: current maximum bw indicated by secondary cca 2"b01: bw fall back by one level based on bw in 2"b00 if not reach 20M 2"b10: bw fall back by one level based on bw in 2"b01 if not reach 20M 2"b11: bw fall back by one level based on bw in 2"b10 if not reach 20M e.g, current maximum bw indicated by secondary_cca is 80M, when set to 2"b00, the response cts bw is 80M, when set to 2"b01, cts bw is 40M, when set to 2"b10 or 2"b11 , cts bw is 20M*/
#define BIT_RESP_CTS_DYNB_W_SEL(x)          (((u32)((x) & 0x00000003) << 5))
#define BIT_GET_RESP_CTS_DYNB_W_SEL(x)      ((u32)(((x >> 5) & 0x00000003)))
#define BIT_DLY_TX_WAIT_RXA_NTSEL           ((u32)0x00000001 << 4)            /*!< R/W 0x0  8188E/8812 In some Cases, the phy status may be received too late to be used in the response frame. Enable this bit to postpone the tx of response frame until the phy status is obtained. Otherwise, If the phy status unavailable for its delay, The IOREG value of 0x06D8[6] will be used as before.*/
#define BIT_TXRESP_BY_RXANT_SEL             ((u32)0x00000001 << 3)            /*!< R/W 0x0  8188E/8812 Enable responder send the response frame with the antenna selection information which from the phy status of the previous rx frame.*/
#define BIT_RESP_EARLY_TXAC_K_RWEPTKIP      ((u32)0x00000001 << 2)            /*!< R/W 0x0  Enable responder send ack without waiting for the rx completion when rx wep/tkip packet to satisfy the sifs requirement before tx response frame*/
#define BIT_MASK_ORIG_DCTS_CHK              ((u32)0x00000003 << 0)            /*!< R/W 0x0  Txok condition for dual CTS frame exchange: 2'b00: Either one Rx ok 2'b01: 1st one Rx ok 2'b10: 2nd one Rx ok 2'b11: both Rx ok*/
#define BIT_ORIG_DCTS_CHK(x)                (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_ORIG_DCTS_CHK(x)            ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_WMAC_TRXPTCL_CTL_H
  * @brief WMAC TX
  * @{
  */
#define BIT_MASK_ACKBA_TYPSEL                ((u32)0x0000000F << 28)           /*!< R/W 0x0  Determine response type for RX BA, and the definition as the bellow 1"b0: NAV 1"b1: Send ACK ACKBA_TYPESEL[0]: used for Basic BA ACKBA_TYPESEL[1]: used for Compression BA ACKBA_TYPESEL[2]: RSVD ACKBA_TYPESEL[3]: used for MTID BA*/
#define BIT_ACKBA_TYPSEL(x)                  (((u32)((x) & 0x0000000F) << 28))
#define BIT_GET_ACKBA_TYPSEL(x)              ((u32)(((x >> 28) & 0x0000000F)))
#define BIT_MASK_ACKBA_ACKPCHK               ((u32)0x0000000F << 24)           /*!< R/W 0x0  If set "1", then check ACK Policy of BA control field to determine whether send response or not. When this bit set to 1"b1 and a. ACK Policy of Rx BA control field is "0", then response type is controlled by ACLBA_TYPESEL. b. ACK Policy of Rx BA control field is "1", then don"t send response If set "0", then ignore the ACK policy of RX BA control field and response type controlled by ACKBA_TYPESEL ACKBA_ACKPCHK[0]: used for Basic BA ACKBA_ACKPCHK[1]: used for Compression BA ACKBA_ACKPCHK[2]: RSVD ACKBA_ACKPCHK[3]: used for MTID BA*/
#define BIT_ACKBA_ACKPCHK(x)                 (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_ACKBA_ACKPCHK(x)             ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_ACKBAR_TYPESEL              ((u32)0x000000FF << 16)           /*!< R/W 0x04  Determine response type for RX BAR, and the definition as the bellow 2"b00: NAV 2"b01: Send BA 2"b10: Send ACK ACKBAR_TYPESEL[1:0]: used for Basic BAR ACKBAR_TYPESEL[3:2]: used for Compression BAR ACKBAR_TYPESEL[5:4]: RSVD ACKBAR_TYPESEL[7:6]: used for MTID BAR*/
#define BIT_ACKBAR_TYPESEL(x)                (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_ACKBAR_TYPESEL(x)            ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_ACKBAR_ACKPCHK              ((u32)0x0000000F << 12)           /*!< R/W 0x02  If set "1", then check ACK Policy of BAR control field to determine whether send response or not. When this bit set to 1"b1 and a. ACK Policy of Rx BAR control field is "0", then response type is controlled by ACLBAR_TYPESEL. b. ACK Policy of Rx BAR control field is "1", then don"t send response If set "0", then ignore the ACK policy of RX BAR control field and response type controlled by ACKBA_TYPESEL ACKBA_ACKPCHK[0]: used for Basic BAR ACKBA_ACKPCHK[1]: used for Compression BAR ACKBA_ACKPCHK[2]: RSVD ACKBA_ACKPCHK[3]: used for MTID BAR*/
#define BIT_ACKBAR_ACKPCHK(x)                (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_ACKBAR_ACKPCHK(x)            ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_RXBA_IGNOREA2_V1                 ((u32)0x00000001 << 10)           /*!< R/W 0x0  Disable check A2 field of RX BA*/
#define BIT_EN_SAVE_ALL_TXOPADDR_V1          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_EN_TXCTS_TO_TXOPOWNER_INRXNAV_V1 ((u32)0x00000001 << 8)            /*!< R/W 0x0  together with bit41, implement 802.11ac txop owner function*/
#define BIT_DIS_TXBA_AMPDUFCSERR_V1          ((u32)0x00000001 << 7)            /*!< R/W 0x0  Disable to send BA for responding RX AMPDU with FCS error subframe*/
#define BIT_DIS_TXBA_RXBARINFULL_V1          ((u32)0x00000001 << 6)            /*!< R/W 0x0  Disable to send BA for responding RX control wrapper BAR dropped by rxpkbuffer full*/
#define BIT_DIS_TXCFE_INFULL_V1              ((u32)0x00000001 << 5)            /*!< R/W 0x0  Disable to send CF-END for responding RX control wrapper CF-END dropped by rxpktbuffer full. This bit is valid when RESP_DCFE_EN is set to 1"b1*/
#define BIT_DIS_TXCTS_INFULL_V1              ((u32)0x00000001 << 4)            /*!< R/W 0x0  Disable to send CTS for responding RX control wrapper RTS dropped by rxpktbuffer full*/
#define BIT_EN_TXACKBA_IN_TX_RDG_V1          ((u32)0x00000001 << 3)            /*!< R/W 0x0  If this bit is set, then MAC will Tx ACK/BA to respond  previous rx my unicast packets send by another STA during TX RDG*/
#define BIT_EN_TXACKBA_IN_TXOP_V1            ((u32)0x00000001 << 2)            /*!< R/W 0x0  If this bit is set, then MAC will Tx ACK/BA to respond previous rx my unitcast packets send by another STA during my TXOP*/
#define BIT_EN_TXCTS_IN_RXNAV_V1             ((u32)0x00000001 << 1)            /*!< R/W 0x0  Enable to send CTS in Rx NAV*/
#define BIT_EN_TXCTS_INTXOP_V1               ((u32)0x00000001 << 0)            /*!< R/W 0x0  Enable to send CTS for responding RX RTS during our TXOP period*/
/** @} */

/** @defgroup REG_CAMCMD
  * @brief CAM Command Register
  * @{
  */
#define BIT_SECCAM_POLLING        ((u32)0x00000001 << 31)          /*!< W 0x0  Security CAM Polling*/
#define BIT_SECCAM_CLR            ((u32)0x00000001 << 30)          /*!< W 0x0  Set to one to clear all valid bits in CAM. After reset will self clear to 0.*/
#define BIT_MFBCAM_CLR            ((u32)0x00000001 << 29)          /*!< W 0x0  Write "1" to clear all MFB value in CAM to 7"h7F. After reset will self clear to "0"*/
#define BIT_SECCAM_WE             ((u32)0x00000001 << 16)          /*!< R/W 0x0  Security CAM Write Enable*/
#define BIT_MASK_SECCAM_ADDR_V1   ((u32)0x000000FF << 0)           /*!< R/W 0x0  Security CAM Address Offset CAM address is organized into 8 double-words/entry.*/
#define BIT_SECCAM_ADDR_V1(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_SECCAM_ADDR_V1(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_CAMWRITE
  * @brief CAM Write Register
  * @{
  */
#define BIT_MASK_CAMW_DATA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Security CAM Write Content*/
#define BIT_CAMW_DATA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_CAMW_DATA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CAMREAD
  * @brief CAM Read Register
  * @{
  */
#define BIT_MASK_CAMR_DATA   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  Security CAM Read Content*/
#define BIT_CAMR_DATA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_CAMR_DATA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CAMDBG
  * @brief CAM Debug Register
  * @{
  */
#define BIT_SECCAM_INFO               ((u32)0x00000001 << 31)           /*!< R/W 0x0  Select TX/RX CAM Information. Set to 1 to retrieve latest Tx search result. Set to 0 to retrieve latest Rx search result.*/
#define BIT_SEC_KEYFOUND              ((u32)0x00000001 << 15)           /*!< R 0x0  Security Key Found in CAM 0: key not found 1: key found*/
#define BIT_MASK_CAMDBG_SEC_TYPE      ((u32)0x00000007 << 12)           /*!< R 0x0  */
#define BIT_CAMDBG_SEC_TYPE(x)        (((u32)((x) & 0x00000007) << 12))
#define BIT_GET_CAMDBG_SEC_TYPE(x)    ((u32)(((x >> 12) & 0x00000007)))
#define BIT_MASK_CAMDBG_MIC_KEY_IDX   ((u32)0x0000001F << 5)            /*!< R 0x0  */
#define BIT_CAMDBG_MIC_KEY_IDX(x)     (((u32)((x) & 0x0000001F) << 5))
#define BIT_GET_CAMDBG_MIC_KEY_IDX(x) ((u32)(((x >> 5) & 0x0000001F)))
#define BIT_MASK_CAMDBG_SEC_KEY_IDX   ((u32)0x0000001F << 0)            /*!< R 0x0  */
#define BIT_CAMDBG_SEC_KEY_IDX(x)     (((u32)((x) & 0x0000001F) << 0))
#define BIT_GET_CAMDBG_SEC_KEY_IDX(x) ((u32)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_SECCFG
  * @brief Security Configuration Register
  * @{
  */
#define BIT_RXDEC_BM_MGNT_V1  ((u32)0x00000001 << 19) /*!< R/W 0x0  decryption enable of rx multicast management pkt, 0x680[3] shall also be set valid*/
#define BIT_TXENC_BM_MGNT_V1  ((u32)0x00000001 << 18) /*!< R/W 0x0  encryption enable of tx multicast management pkt, 0x680[2] shall also be set valid*/
#define BIT_RXDEC_UNI_MGNT_V1 ((u32)0x00000001 << 17) /*!< R/W 0x0  decryption enable of rx unicast management pkt, 0x680[3] shall also be set valid*/
#define BIT_TXENC_UNI_MGNT_V1 ((u32)0x00000001 << 16) /*!< R/W 0x0  encryption enable of tx unicast management pkt, 0x680[2] shall also be set valid*/
#define BIT_DIS_GCLK_WAPI     ((u32)0x00000001 << 15) /*!< R/W 0x0  Disable gated clock control for WAPI engine*/
#define BIT_DIS_GCLK_AES      ((u32)0x00000001 << 14) /*!< R/W 0x0  Disable gated clock control for AES engine.*/
#define BIT_DIS_GCLK_TKIP     ((u32)0x00000001 << 13) /*!< R/W 0x0  not used*/
#define BIT_AES_SEL_QC_1      ((u32)0x00000001 << 12) /*!< R/W 0x0  1: use QC[7] to compute mic 0: not use QC[7] to compute mic*/
#define BIT_AES_SEL_QC_0      ((u32)0x00000001 << 11) /*!< R/W 0x0  1:use QC[7] to compute ctr 0: not use QC[7] to compute ctr*/
#define BIT_CHK_KEYID         ((u32)0x00000001 << 8)  /*!< R/W 0x0  If this bit is set to 1, key search engine need to check if key ID matched. If this bit is set to 0, then key ID table must be filled with 2"b00.*/
#define BIT_RXBCUSEDK         ((u32)0x00000001 << 7)  /*!< R/W 0x0  Force RX Broadcast packets Use Default Key If this bit is set to 1, use default key for RX key search when received packet is broadcast and multicast.*/
#define BIT_TXBCUSEDK         ((u32)0x00000001 << 6)  /*!< R/W 0x0  Force Tx Broadcast packets Use Default Key If this bit is set to 1, use default key for TX key search when transmitted packet is broadcast and multicast.*/
#define BIT_NOSKMC            ((u32)0x00000001 << 5)  /*!< R/W 0x0  No Key Search for Multicast Setting 1 to disable key search for multicast frames. Used in MBSSID AP mode. Software should manage security encryption and decryption.*/
#define BIT_SKBYA2            ((u32)0x00000001 << 4)  /*!< R/W 0x0  Search Key by A2 Setting 1 to search security CAM by address 2 for TX and search CAM by address 1 for RX. Setting 0 to search security CAM by address 1 for TX and search CAM by address 2 for RX. Used in MBSSID client mode.*/
#define BIT_RXDEC             ((u32)0x00000001 << 3)  /*!< R/W 0x0  Enable Rx Decryption Setting 1 to enable Rx hardware decryption.*/
#define BIT_TXENC             ((u32)0x00000001 << 2)  /*!< R/W 0x0  Enable Tx Encryption Setting to 1 to enable Tx hardware encryption.*/
#define BIT_RXUHUSEDK         ((u32)0x00000001 << 1)  /*!< R/W 0x0  Force RX Unicast Use Default Key If this bit is set to 1, use default key for RX key search when pairwise key is not found.*/
#define BIT_TXUHUSEDK         ((u32)0x00000001 << 0)  /*!< R/W 0x0  Force Tx Unicast Use Default Key If this bit is set to 1, use default key for TX key search when pairwise key is not found.*/
/** @} */

/** @defgroup REG_WOW_CTRL
  * @brief Wake On WLAN Control Register
  * @{
  */
#define BIT_WOWHCI       ((u16)0x00000001 << 5) /*!< R/W 0x0  This bit is set to allow wake host as wake on wlan event occurring*/
#define BIT_PSF_BSSIDSEL ((u16)0x00000001 << 4) /*!< R/W 0x0  8188E/8812 Select to check the BSSID of which port for the WMAC PSF NSARP function. 0: to check the BSSID of port0; 1: to check the BSSID of port1.*/
#define BIT_UWF          ((u16)0x00000001 << 3) /*!< R/W 0x0  Unicast Packet. 1: Enable to check packet"s DA match MAC address or not. 0: Disable. (default value)*/
#define BIT_MAGIC        ((u16)0x00000001 << 2) /*!< R/W 0x0  Magic Packet. This bit is valid when the PMEn bit of the PMR register is set. The RTL8192 will assert the PMEB signal to wakeup the operating system when a Magic Packet is received. Once the RTL8192 has been enabled for Magic Packet wakeup, it scans incoming packets addressed to the node for a data sequence. The correct sequence indicates to the controller that this is a Magic Packet frame. A Magic Packet frame must also meet the basic requirements: Frame Control + Duration/ID + Destination address + Address 2 + Address 3 + Sequence Control + data + CRC. The destination address may be the node ID of the receiving station or a multicast address, including the broadcast address. The specific sequence consists of 16 duplications of 6 byte ID registers, with no breaks or interrupts. This sequence can be located anywhere within the packet, but must be preceded by a synchronization stream, 6 bytes of FFh. The device will also accept a multicast address, as long as the 16 duplications of the IEEE address match the address of the ID registers. If the Node ID is 11h 22h 33h 44h 55h 66h, then the magic frame"s format is as follows: Frame Control + Duration/ID + Destination address + Address 2 + Address 3 + Sequence Control + MISC + FF FF FF FF FF FF + MISC + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + 11 22 33 44 55 66 + MISC + CRC.*/
#define BIT_WFMSK        ((u16)0x00000001 << 1) /*!< R/W 0x0  WoW function on or off.*/
/** @} */

/** @defgroup REG_PS_RX_INFO
  * @brief Power Save RX Information Register
  * @{
  */
#define BIT_RXCTRLIN0 ((u8)0x00000001 << 4) /*!< R/W 0x0  It is set to 1 if NIC received control frame with correct DA.*/
#define BIT_RXMGTIN0  ((u8)0x00000001 << 3) /*!< R/W 0x0  It is set to 1 if NIC received management frame with correct BSSID and DA (including unicast and BMC).*/
#define BIT_RXDATAIN2 ((u8)0x00000001 << 2) /*!< R/W 0x0  It is set to 1 if NIC received data frame with correct BSSID and DA (including unicast and BMC).*/
#define BIT_RXDATAIN1 ((u8)0x00000001 << 1) /*!< R/W 0x0  It is set to 1 if NIC received data frame with correct BSSID and DA (including unicast and BMC).*/
#define BIT_RXDATAIN0 ((u8)0x00000001 << 0) /*!< R/W 0x0  It is set to 1 if NIC received data frame with correct BSSID and DA (including unicast and BMC).*/
/** @} */

/** @defgroup REG_WMMPS_UAPSD_TID
  * @brief WMM Power Save UAPSD TID Register
  * @{
  */
#define BIT_WMMPS_UAPSD_TID7 ((u8)0x00000001 << 7) /*!< R/W 0x0  Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID7*/
#define BIT_WMMPS_UAPSD_TID6 ((u8)0x00000001 << 6) /*!< R/W 0x0  Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID6*/
#define BIT_WMMPS_UAPSD_TID5 ((u8)0x00000001 << 5) /*!< R/W 0x0  Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID5*/
#define BIT_WMMPS_UAPSD_TID4 ((u8)0x00000001 << 4) /*!< R/W 0x0  Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID4*/
#define BIT_WMMPS_UAPSD_TID3 ((u8)0x00000001 << 3) /*!< R/W 0x0  Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID3*/
#define BIT_WMMPS_UAPSD_TID2 ((u8)0x00000001 << 2) /*!< R/W 0x0  Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID2*/
#define BIT_WMMPS_UAPSD_TID1 ((u8)0x00000001 << 1) /*!< R/W 0x0  Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID1*/
#define BIT_WMMPS_UAPSD_TID0 ((u8)0x00000001 << 0) /*!< R/W 0x0  Disable interrupt 8051 when rx WMMPS UAPSD Qos data with TID0*/
/** @} */

/** @defgroup REG_LPNAV_CTRL
  * @brief Low Power NAV Control Register
  * @{
  */
#define BIT_LPNAV_EN           ((u32)0x00000001 << 31)           /*!< R/W 0x0  Low Power NAV Mode Enable: When this bit is set, enable MAC low power NAV mode*/
#define BIT_MASK_LPNAV_EARLY   ((u32)0x00007FFF << 16)           /*!< R/W 0x0  When in LPNAV mode, MAC will recall BB and RF into RX idle mode. The unit is us.*/
#define BIT_LPNAV_EARLY(x)     (((u32)((x) & 0x00007FFF) << 16))
#define BIT_GET_LPNAV_EARLY(x) ((u32)(((x >> 16) & 0x00007FFF)))
#define BIT_MASK_LPNAV_THR     ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  When protected NAV in the received frame is greater than this threshold value, then MAC enters into LPNAV mode. The time unit is 16us.*/
#define BIT_LPNAV_THR(x)       (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_LPNAV_THR(x)   ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_WKFMCAM_CMD
  * @brief Wakeup Frame CAM Number Register
  * @{
  */
#define BIT_MASK_WKFCAM_NUM_V1   ((u32)0x000000FF << 0)           /*!< R/W 0x0  Wakeup frame Mask CAM Number in the rxpktbuffer*/
#define BIT_WKFCAM_NUM_V1(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_WKFCAM_NUM_V1(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RXFLTER0
  * @brief RX Filter Map Group 0
  * @{
  */
#define BIT_CTRLFLT15EN ((u32)0x00000001 << 31) /*!< R/W 0x0  When set, frames with type=01 and subtype=1111 are received into RXFF*/
#define BIT_CTRLFLT14EN ((u32)0x00000001 << 30) /*!< R/W 0x0  When set, frames with type=01 and subtype=1110 are received into RXFF*/
#define BIT_CTRLFLT13EN ((u32)0x00000001 << 29) /*!< R/W 0x0  When set, frames with type=01 and subtype=1101 are received into RXFF.*/
#define BIT_CTRLFLT12EN ((u32)0x00000001 << 28) /*!< R/W 0x0  When set, frames with type=01 and subtype=1100 are received into RXFF.*/
#define BIT_CTRLFLT11EN ((u32)0x00000001 << 27) /*!< R/W 0x0  When set, frames with type=01 and subtype=1011 are received into RXFF*/
#define BIT_CTRLFLT10EN ((u32)0x00000001 << 26) /*!< R/W 0x0  When set, frames with type=01 and subtype=1010 are received into RXFF.*/
#define BIT_CTRLFLT9EN  ((u32)0x00000001 << 25) /*!< R/W 0x0  When set, frames with type=01 and subtype=1001 are received into RXFF*/
#define BIT_CTRLFLT8EN  ((u32)0x00000001 << 24) /*!< R/W 0x0  When set, frames with type=01 and subtype=1000 are received into RXFF*/
#define BIT_CTRLFLT7EN  ((u32)0x00000001 << 23) /*!< R/W 0x0  When set, frames with type=01 and subtype=0111 are received into RXFF*/
#define BIT_CTRLFLT6EN  ((u32)0x00000001 << 22) /*!< R/W 0x0  When set, frames with type=01 and subtype=0110 are received into RXFF.*/
#define BIT_CTRLFLT5EN  ((u32)0x00000001 << 21) /*!< R/W 0x0  When set, frames with type=01 and subtype=0101 are received into RXFF.*/
#define BIT_CTRLFLT4EN  ((u32)0x00000001 << 20) /*!< R/W 0x0  When set, frames with type=01 and subtype=0100 are received into RXFF.*/
#define BIT_CTRLFLT3EN  ((u32)0x00000001 << 19) /*!< R/W 0x0  When set, frames with type=01 and subtype=0011 are received into RXFF.*/
#define BIT_CTRLFLT2EN  ((u32)0x00000001 << 18) /*!< R/W 0x0  When set, frames with type=01 and subtype=0010 are received into RXFF.*/
#define BIT_CTRLFLT1EN  ((u32)0x00000001 << 17) /*!< R/W 0x0  When set, frames with type=01 and subtype=0001 are received into RXFF.*/
#define BIT_CTRLFLT0EN  ((u32)0x00000001 << 16) /*!< R/W 0x0  When set, frames with type=01 and subtype=0000 are received into RXFF.*/
#define BIT_MGTFLT15EN  ((u32)0x00000001 << 15) /*!< R/W 0x0  When set, frames with type=00 and subtype=1111 are received into RXFF.*/
#define BIT_MGTFLT14EN  ((u32)0x00000001 << 14) /*!< R/W 0x0  When set, frames with type=00 and subtype=1110 are received into RXFF.*/
#define BIT_MGTFLT13EN  ((u32)0x00000001 << 13) /*!< R/W 0x0  When set, frames with type=00 and subtype=1101 are received into RXFF.*/
#define BIT_MGTFLT12EN  ((u32)0x00000001 << 12) /*!< R/W 0x0  When set, frames with type=00 and subtype=1100 are received into RXFF.*/
#define BIT_MGTFLT11EN  ((u32)0x00000001 << 11) /*!< R/W 0x0  When set, frames with type=00 and subtype=1011 are received into RXFF.*/
#define BIT_MGTFLT10EN  ((u32)0x00000001 << 10) /*!< R/W 0x0  When set, frames with type=00 and subtype=1010 are received into RXFF*/
#define BIT_MGTFLT9EN   ((u32)0x00000001 << 9)  /*!< R/W 0x0  When set, frames with type=00 and subtype=1001 are received into RXFF.*/
#define BIT_MGTFLT8EN   ((u32)0x00000001 << 8)  /*!< R/W 0x0  When set, frames with type=00 and subtype=1000 are received into RXFF*/
#define BIT_MGTFLT7EN   ((u32)0x00000001 << 7)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0111 are received into RXFF.*/
#define BIT_MGTFLT6EN   ((u32)0x00000001 << 6)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0110 are received into RXFF.*/
#define BIT_MGTFLT5EN   ((u32)0x00000001 << 5)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0101 are received into RXFF*/
#define BIT_MGTFLT4EN   ((u32)0x00000001 << 4)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0100 are received into RXFF.*/
#define BIT_MGTFLT3EN   ((u32)0x00000001 << 3)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0011 are received into RXFF*/
#define BIT_MGTFLT2EN   ((u32)0x00000001 << 2)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0010 are received into RXFF*/
#define BIT_MGTFLT1EN   ((u32)0x00000001 << 1)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0001 are received into RXFF*/
#define BIT_MGTFLT0EN   ((u32)0x00000001 << 0)  /*!< R/W 0x0  When set, frames with type=00 and subtype=0000 are received into RXFF*/
/** @} */

/** @defgroup REG_RXFLTER2
  * @brief RX Filter Map Group 2
  * @{
  */
#define BIT_DATAFLT15EN ((u32)0x00000001 << 15) /*!< R/W 0x0  When set, frames with type=10 and subtype=1111 are received into RXFF*/
#define BIT_DATAFLT14EN ((u32)0x00000001 << 14) /*!< R/W 0x0  When set, frames with type=10 and subtype=1110 are received into RXFF*/
#define BIT_DATAFLT13EN ((u32)0x00000001 << 13) /*!< R/W 0x0  When set, frames with type=10 and subtype=1101 are received into RXFF.*/
#define BIT_DATAFLT12EN ((u32)0x00000001 << 12) /*!< R/W 0x0  When set, frames with type=10 and subtype=1100 are received into RXFF.*/
#define BIT_DATAFLT11EN ((u32)0x00000001 << 11) /*!< R/W 0x0  When set, frames with type=10 and subtype=1011 are received into RXFF.*/
#define BIT_DATAFLT10EN ((u32)0x00000001 << 10) /*!< R/W 0x0  When set, frames with type=10 and subtype=1010 are received into RXFF.*/
#define BIT_DATAFLT9EN  ((u32)0x00000001 << 9)  /*!< R/W 0x0  When set, frames with type=10 and subtype=1001 are received into RXFF*/
#define BIT_DATAFLT8EN  ((u32)0x00000001 << 8)  /*!< R/W 0x0  When set, frames with type=10 and subtype=1000 are received into RXFF*/
#define BIT_DATAFLT7EN  ((u32)0x00000001 << 7)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0111 are received into RXFF.*/
#define BIT_DATAFLT6EN  ((u32)0x00000001 << 6)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0110 are received into RXFF*/
#define BIT_DATAFLT5EN  ((u32)0x00000001 << 5)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0101 are received into RXFF*/
#define BIT_DATAFLT4EN  ((u32)0x00000001 << 4)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0100 are received into RXFF.*/
#define BIT_DATAFLT3EN  ((u32)0x00000001 << 3)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0011 are received into RXFF*/
#define BIT_DATAFLT2EN  ((u32)0x00000001 << 2)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0010 are received into RXFF.*/
#define BIT_DATAFLT1EN  ((u32)0x00000001 << 1)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0001 are received into RXFF.*/
#define BIT_DATAFLT0EN  ((u32)0x00000001 << 0)  /*!< R/W 0x0  When set, frames with type=10 and subtype=0000 are received into RXFF.*/
/** @} */

/** @defgroup REG_BCN_PSR_RPT0
  * @brief
  * @{
  */
#define BIT_MASK_DTIM_CNT      ((u32)0x000000FF << 24)           /*!< R 0x0  The DTIM count field of the TIM element of Rx beacon*/
#define BIT_DTIM_CNT(x)        (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_DTIM_CNT(x)    ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_DTIM_PERIOD   ((u32)0x000000FF << 16)           /*!< R 0x0  The DTIM period field of the TIM element of Rx beacon*/
#define BIT_DTIM_PERIOD(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_DTIM_PERIOD(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_HAS_MY_BC0         ((u32)0x00000001 << 15)           /*!< R 0x0  Indicate the TIM element of Beacon is DTIM*/
#define BIT_HAS_MYAID0         ((u32)0x00000001 << 14)           /*!< R 0x0  Indicate MACID0 AID is set to 1 in the bit map control field of the TIM element of Rx Beacon frame*/
#define BIT_RPT_VALID0         ((u32)0x00000001 << 13)           /*!< R 0x0  1 means tim report is vaild*/
#define BIT_MASK_PS_AID_0      ((u32)0x000007FF << 0)            /*!< R/W 0x0  AID0 for MACID0*/
#define BIT_PS_AID_0(x)        (((u32)((x) & 0x000007FF) << 0))
#define BIT_GET_PS_AID_0(x)    ((u32)(((x >> 0) & 0x000007FF)))
/** @} */

/** @defgroup REG_FLC_RPC
  * @brief FW LPS Condition -- Rx PKT Counter
  * @{
  */
#define BIT_MASK_FLC_RPC   ((u8)0x000000FF << 0)           /*!< R/W 0x0  Number of Rx PKT in the interval which is specified by FLC_TRPC. The Rx PKT type is specified by 0x6AE[2:0]*/
#define BIT_FLC_RPC(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_FLC_RPC(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_FLC_RPCT
  * @brief FLC_RPC Threshold
  * @{
  */
#define BIT_MASK_FLC_RPCT   ((u8)0x000000FF << 0)           /*!< R/W 0x0  Rx PKT number threshold*/
#define BIT_FLC_RPCT(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_FLC_RPCT(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_FLC_PTS
  * @brief PKT Type Selection of FLC_RPC T
  * @{
  */
#define BIT_CMF ((u8)0x00000001 << 2) /*!< R/W 0x0  Count Management Frame (1: Enable, 0:Disable)*/
#define BIT_CCF ((u8)0x00000001 << 1) /*!< R/W 0x0  Count Control Frame (1: Enable, 0:Disable)*/
#define BIT_CDF ((u8)0x00000001 << 0) /*!< R/W 0x0  Count Data Frame (1: Enable, 0:Disable)*/
/** @} */

/** @defgroup REG_FLC_TRPC
  * @brief Timer of FLC_RPC
  * @{
  */
#define BIT_FLC_RPCT_V1  ((u8)0x00000001 << 7)           /*!< R/W 0x0  When write "1" to this bit, FLC_TRPC will be enabled.*/
#define BIT_MODE         ((u8)0x00000001 << 6)           /*!< R/W 0x0  1 = Timer Mode 0 = Counter Mode*/
#define BIT_MASK_TRPCD   ((u8)0x0000003F << 0)           /*!< R/W 0x0  It specifies the time-out duration. (unit: 32 ms)*/
#define BIT_TRPCD(x)     (((u8)((x) & 0x0000003F) << 0))
#define BIT_GET_TRPCD(x) ((u8)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_RXPKTMON_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_DTIM_CNT       ((u32)0x000000FF << 24)           /*!< R 0x0  The DTIM count field of the TIM element of Rx beacon*/
#define BIT_DTIM_CNT(x)         (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_DTIM_CNT(x)     ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_RXBKQPKT_SEQ   ((u32)0x0000000F << 20)           /*!< R 0x0  The expected Rx BKQ packet index*/
#define BIT_RXBKQPKT_SEQ(x)     (((u32)((x) & 0x0000000F) << 20))
#define BIT_GET_RXBKQPKT_SEQ(x) ((u32)(((x >> 20) & 0x0000000F)))
#define BIT_MASK_RXBEQPKT_SEQ   ((u32)0x0000000F << 16)           /*!< R 0x0  The expected Rx BEQ packet index*/
#define BIT_RXBEQPKT_SEQ(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_RXBEQPKT_SEQ(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_RXVIQPKT_SEQ   ((u32)0x0000000F << 12)           /*!< R 0x0  The expected Rx VIQ packet index*/
#define BIT_RXVIQPKT_SEQ(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_RXVIQPKT_SEQ(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_RXVOQPKT_SEQ   ((u32)0x0000000F << 8)            /*!< R 0x0  The expected Rx VOQ packet index*/
#define BIT_RXVOQPKT_SEQ(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_RXVOQPKT_SEQ(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_RXBKQPKT_ERR        ((u32)0x00000001 << 7)            /*!< R 0x0  Indicate monitor find the Rx BKQ packet without incremental index*/
#define BIT_RXBEQPKT_ERR        ((u32)0x00000001 << 6)            /*!< R 0x0  Indicate monitor find the Rx BEQ packet without incremental index*/
#define BIT_RXVIQPKT_ERR        ((u32)0x00000001 << 5)            /*!< R 0x0  Indicate monitor find the Rx VIQ packet without incremental index*/
#define BIT_RXVOQPKT_ERR        ((u32)0x00000001 << 4)            /*!< R 0x0  Indicate monitor find the Rx VOQ packet without incremental index*/
#define BIT_RXDMA_MON_EN        ((u32)0x00000001 << 2)            /*!< R/W 0x0  Enable packet loss monitor function for Rx DMA. If this bit is set to 1, then MACRX append the incremental index to fragment field of sequence number field of rxmpdu restored to rxpkbuffer successfully*/
#define BIT_RXPKT_MON_RST       ((u32)0x00000001 << 1)            /*!< W 0x0  Reset the rx packet index counter*/
#define BIT_RXPKT_MON_EN        ((u32)0x00000001 << 0)            /*!< R/W 0x0  Enable packet loss monitor function for Rx packets. If this bit is set to 1, then MACRX uses fragment field of sequence number field of rxmpdu as the mpdu index and check if the index is incremental.*/
/** @} */

/** @defgroup REG_STATE_MON
  * @brief
  * @{
  */
#define BIT_MASK_STATE_SEL    ((u32)0x0000001F << 24)           /*!< R/W 0x0  WMAC FSM selection*/
#define BIT_STATE_SEL(x)      (((u32)((x) & 0x0000001F) << 24))
#define BIT_GET_STATE_SEL(x)  ((u32)(((x >> 24) & 0x0000001F)))
#define BIT_MASK_STATE_INFO   ((u32)0x000000FF << 8)            /*!< R 0x0  Report the other relation information about FSM*/
#define BIT_STATE_INFO(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_STATE_INFO(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_UPD_NXT_STATE     ((u32)0x00000001 << 7)            /*!< W 0x0  Update FSM to specified next state*/
#define BIT_MASK_CUR_STATE    ((u32)0x0000007F << 0)            /*!< R/W 0x0  Indicate the FSM current state*/
#define BIT_CUR_STATE(x)      (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_CUR_STATE(x)  ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_ERROR_EVT_CTL
  * @brief
  * @{
  */
#define BIT_MACRX_ERR_1     ((u32)0x00000001 << 17) /*!< R 0x0  Indicate Rx packet length >= 12K bytes*/
#define BIT_MACRX_ERR_0     ((u32)0x00000001 << 16) /*!< R 0x0  Indicate MAC Rx occurs halt event*/
#define BIT_PRETX_ERRHDL_EN ((u32)0x00000001 << 15) /*!< R/W 0x0  Pre tx error block enable signal*/
#define BIT_MACTX_ERR_4     ((u32)0x00000001 << 4)  /*!< R 0x0  Indicate pre tx error*/
#define BIT_MACTX_ERR_3     ((u32)0x00000001 << 3)  /*!< R 0x0  Indicate PHY Tx finish*/
#define BIT_MACTX_ERR_2     ((u32)0x00000001 << 2)  /*!< R 0x0  Indicate TXD FIFO underflow when MAC Tx cmpba*/
#define BIT_MACTX_ERR_1     ((u32)0x00000001 << 1)  /*!< R 0x0  Indicate TXD FIFO underflow*/
#define BIT_MACTX_ERR_0     ((u32)0x00000001 << 0)  /*!< R 0x0  Indicate PHY finish TX before MAC*/
/** @} */

/** @defgroup REG_RESPINFO
  * @brief
  * @{
  */
#define BIT_EN_TXRPTBUF_CLK          ((u32)0x00000001 << 31)           /*!< R/W 0x0  when set to 1,keep txrptbuf sram always have clock*/
#define BIT_MASK_INFO_INDEX_OFFSET   ((u32)0x00001FFF << 16)           /*!< R/W   Pre-macid information index address offset.*/
#define BIT_INFO_INDEX_OFFSET(x)     (((u32)((x) & 0x00001FFF) << 16))
#define BIT_GET_INFO_INDEX_OFFSET(x) ((u32)(((x >> 16) & 0x00001FFF)))
#define BIT_WMAC_SRCH_FIFOFULL       ((u32)0x00000001 << 15)           /*!< R/W 0x0  when set to 1, when fifofull, stop macid search;*/
#define BIT_DIS_INFOSRCH             ((u32)0x00000001 << 14)           /*!< R/W   when set to 1,disable to search information*/
#define BIT_DISABLE_B0               ((u32)0x00000001 << 13)           /*!< R/W   when set to 1,disable to check a2[0]*/
#define BIT_MASK_INFO_ADDR_OFFSET    ((u32)0x00001FFF << 0)            /*!< R/W   per-macid information address offset (Unit:8bytes).*/
#define BIT_INFO_ADDR_OFFSET(x)      (((u32)((x) & 0x00001FFF) << 0))
#define BIT_GET_INFO_ADDR_OFFSET(x)  ((u32)(((x >> 0) & 0x00001FFF)))
/** @} */

/** @defgroup REG_BT_COEX_TABLE_V1
  * @brief BT-Coexistence Control register
  * @{
  */
#define BIT_MASK_COEX_TABLE_1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  coexistence table, used at dual antenna & out of band*/
#define BIT_COEX_TABLE_1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_COEX_TABLE_1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BT_COEX_TABLE2_V1
  * @brief BT-Coexistence Control register
  * @{
  */
#define BIT_MASK_COEX_TABLE_2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  coexistence table, used at dual antenna & in band or single antenna*/
#define BIT_COEX_TABLE_2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_COEX_TABLE_2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BT_COEX_BREAK_TABLE
  * @brief BT-Coexistence Control register
  * @{
  */
#define BIT_MASK_BREAK_TABLE_2   ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  Table used to break BT activity, when new WLAN request is coming and BT is on transmitting or receiving*/
#define BIT_BREAK_TABLE_2(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_BREAK_TABLE_2(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_BREAK_TABLE_1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  Table used to break WLAN activity, when new BT request is coming and WLAN is on transmitting or receiving*/
#define BIT_BREAK_TABLE_1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BREAK_TABLE_1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BT_COEX_TABLE_H_V1
  * @brief BT-Coexistence Control register
  * @{
  */
#define BIT_PRI_MASK_RX_RESP_V1  ((u32)0x00000001 << 30)           /*!< R/W 0x0  Priority Mask for RX Response Packet*/
#define BIT_PRI_MASK_RXOFDM_V1   ((u32)0x00000001 << 29)           /*!< R/W 0x0  Priority Mask for RX OFDM*/
#define BIT_PRI_MASK_RXCCK_V1    ((u32)0x00000001 << 28)           /*!< R/W 0x0  Priority Mask for RX CCK*/
#define BIT_MASK_PRI_MASK_TXAC   ((u32)0x0000007F << 21)           /*!< R/W 0x0  Priority Mask for Tx Queue*/
#define BIT_PRI_MASK_TXAC(x)     (((u32)((x) & 0x0000007F) << 21))
#define BIT_GET_PRI_MASK_TXAC(x) ((u32)(((x >> 21) & 0x0000007F)))
#define BIT_MASK_PRI_MASK_NAV    ((u32)0x000000FF << 13)           /*!< R/W 0x0  Priority Mask for Tx NAV*/
#define BIT_PRI_MASK_NAV(x)      (((u32)((x) & 0x000000FF) << 13))
#define BIT_GET_PRI_MASK_NAV(x)  ((u32)(((x >> 13) & 0x000000FF)))
#define BIT_PRI_MASK_CCK_V1      ((u32)0x00000001 << 12)           /*!< R/W 0x0  Priority Mask for Tx CCK*/
#define BIT_PRI_MASK_OFDM_V1     ((u32)0x00000001 << 11)           /*!< R/W 0x0  Priority Mask for Tx OFDM*/
#define BIT_PRI_MASK_RTY_V1      ((u32)0x00000001 << 10)           /*!< R/W 0x0  Priority Mask for Tx Retry Packet*/
#define BIT_MASK_PRI_MASK_NUM    ((u32)0x0000000F << 6)            /*!< R/W 0x0  Priority Mask for Tx packet number*/
#define BIT_PRI_MASK_NUM(x)      (((u32)((x) & 0x0000000F) << 6))
#define BIT_GET_PRI_MASK_NUM(x)  ((u32)(((x >> 6) & 0x0000000F)))
#define BIT_MASK_PRI_MASK_TYPE   ((u32)0x0000000F << 2)            /*!< R/W 0x0  Priority Mask for Tx packet type [98]: Rx response [99]: Tx response [100]: beacon*/
#define BIT_PRI_MASK_TYPE(x)     (((u32)((x) & 0x0000000F) << 2))
#define BIT_GET_PRI_MASK_TYPE(x) ((u32)(((x >> 2) & 0x0000000F)))
#define BIT_OOB_V1               ((u32)0x00000001 << 1)            /*!< R/W 0x0  out of band indication (0: in band ; 1 : out of band)*/
#define BIT_ANT_SEL_V1           ((u32)0x00000001 << 0)            /*!< R/W 0x0  single or dual antenna selection (0: single; 1 : dual)*/
/** @} */

/** @defgroup REG_RXCMD_0
  * @brief
  * @{
  */
#define BIT_RXCMD_EN          ((u32)0x00000001 << 31)          /*!< R/W 0x1  RXCMD function enable*/
#define BIT_MASK_RXCMD_INFO   ((u32)0x7FFFFFFF << 0)           /*!< R/W 0x0  The Information is send to rxpktbuffer for host SW*/
#define BIT_RXCMD_INFO(x)     (((u32)((x) & 0x7FFFFFFF) << 0))
#define BIT_GET_RXCMD_INFO(x) ((u32)(((x >> 0) & 0x7FFFFFFF)))
/** @} */

/** @defgroup REG_RXCMD_1
  * @brief
  * @{
  */
#define BIT_MASK_RXCMD_PRD   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  Define the period unit in us to send the RXCMD_INFO to rxpktbuffer for host SW*/
#define BIT_RXCMD_PRD(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_RXCMD_PRD(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_RESP_TXINFO_CFG
  * @brief
  * @{
  */
#define BIT_MASK_RESP_MFB       ((u32)0x0000007F << 25)           /*!< R/W 0x0  MFB information in register for response packet*/
#define BIT_RESP_MFB(x)         (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_RESP_MFB(x)     ((u32)(((x >> 25) & 0x0000007F)))
#define BIT_MASK_ANTINF_SEL     ((u32)0x00000003 << 23)           /*!< R/W 0x0  Antsel information for response frame in register or ctrl info 00: Antsel_en always disable, 01:Antsel_en field follow ctrl info 1X:Antsel_en always enable*/
#define BIT_ANTINF_SEL(x)       (((u32)((x) & 0x00000003) << 23))
#define BIT_GET_ANTINF_SEL(x)   ((u32)(((x >> 23) & 0x00000003)))
#define BIT_MASK_ANTSEL_SEL     ((u32)0x00000003 << 21)           /*!< R/W 0x0  antenna select: 0: use rx phystatus antsel information; 1: use tx report antsel information; other: use register antsel information.*/
#define BIT_ANTSEL_SEL(x)       (((u32)((x) & 0x00000003) << 21))
#define BIT_GET_ANTSEL_SEL(x)   ((u32)(((x >> 21) & 0x00000003)))
#define BIT_MASK_RESP_TXPOWER   ((u32)0x00000007 << 18)           /*!< R/W 0x0  tx power setting when send response packet*/
#define BIT_RESP_TXPOWER(x)     (((u32)((x) & 0x00000007) << 18))
#define BIT_GET_RESP_TXPOWER(x) ((u32)(((x >> 18) & 0x00000007)))
#define BIT_MASK_RESP_TXANT     ((u32)0x0003FFFF << 0)            /*!< R/W 0x0  tx antenna information*/
#define BIT_RESP_TXANT(x)       (((u32)((x) & 0x0003FFFF) << 0))
#define BIT_GET_RESP_TXANT(x)   ((u32)(((x >> 0) & 0x0003FFFF)))
/** @} */

/** @defgroup REG_BBPSF_CTRL
  * @brief
  * @{
  */
#define BIT_BBPSF_MPDUCHKEN     ((u16)0x00000001 << 5)           /*!< R/W 0x0  This bit is set to 1 to enable MAC to inform BB enter power saving mode as rx unmatch my MACID unicast or unmatch my BSSID Broadcast/Mutlicast packets, for non_ampdu case. Only valid when BIT_BBPSF_MHCHKEN is set 1.*/
#define BIT_BBPSF_MHCHKEN       ((u16)0x00000001 << 4)           /*!< R/W 0x0  This bit is set to 1 to enable MAC to inform BB enter power saving mode as rx unmatch my MACID unicast or unmatch my BSSID Broadcast/Mutlicast packets*/
#define BIT_BBPSF_ERRCHKEN      ((u16)0x00000001 << 3)           /*!< R/W 0x0  This bit is set to 1 to enable MAC to inform BB enter power saving mode as rx FCS error packets number is large than the FCS error packet threshold defined by BBPSF_ERRTHR*/
#define BIT_MASK_BBPSF_ERRTHR   ((u16)0x00000007 << 0)           /*!< R/W 0x0  FCS error packet threshold 3'd0: 1 packets 3'd1: 2 packets 3'd2: 4 packets 3'd3: 6 packets 3'd4: 8 packets 3'd5: 10 packets 3'd6: 12 packets 3'd7: No FCS error threshold until 1st FCS ok packet detection*/
#define BIT_BBPSF_ERRTHR(x)     (((u16)((x) & 0x00000007) << 0))
#define BIT_GET_BBPSF_ERRTHR(x) ((u16)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_ASSOCIATED_BFMER0_INFO
  * @brief Associated Beamformer0 Info Register
  * @{
  */
#define BIT_MASK_R_WMAC_SOUNDING_RXADD_R0_V1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  MACID of the associated beamformer0 bit[31:0]*/
#define BIT_R_WMAC_SOUNDING_RXADD_R0_V1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_R_WMAC_SOUNDING_RXADD_R0_V1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_SOUNDING_CFG1
  * @brief
  * @{
  */
#define BIT_MASK_R_WMAC_TXCSI_AID0            ((u32)0x000001FF << 16)           /*!< R/W 0x0  P_AID of the associated bemaformer0*/
#define BIT_R_WMAC_TXCSI_AID0(x)              (((u32)((x) & 0x000001FF) << 16))
#define BIT_GET_R_WMAC_TXCSI_AID0(x)          ((u32)(((x >> 16) & 0x000001FF)))
#define BIT_MASK_R_WMAC_SOUNDING_RXADD_R0_H   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  MACID of the associated beamformer0 bit[47:32]*/
#define BIT_R_WMAC_SOUNDING_RXADD_R0_H(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_R_WMAC_SOUNDING_RXADD_R0_H(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_SOUNDING_CFG2
  * @brief
  * @{
  */
#define BIT_MASK_R_WMAC_SOUNDING_RXADD_R1_V2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  MACID of the associated beamformer1 bit[31:0]*/
#define BIT_R_WMAC_SOUNDING_RXADD_R1_V2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_R_WMAC_SOUNDING_RXADD_R1_V2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_SOUNDING_CFG3
  * @brief
  * @{
  */
#define BIT_MASK_R_WMAC_TXCSI_AID1               ((u32)0x000001FF << 16)           /*!< R/W 0x0  P_AID of the associated bemaformer1*/
#define BIT_R_WMAC_TXCSI_AID1(x)                 (((u32)((x) & 0x000001FF) << 16))
#define BIT_GET_R_WMAC_TXCSI_AID1(x)             ((u32)(((x >> 16) & 0x000001FF)))
#define BIT_MASK_R_WMAC_SOUNDING_RXADD_R1_H_V2   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  MACID of the associated beamformer1 bit[15:0]*/
#define BIT_R_WMAC_SOUNDING_RXADD_R1_H_V2(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_R_WMAC_SOUNDING_RXADD_R1_H_V2(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_SOUNDING_CFG0
  * @brief
  * @{
  */
#define BIT_MASK_R_WMAC_BFINFO_20M_1   ((u32)0x00000FFF << 16)           /*!< R/W 0x0  BF Info of the associated beamformer1 at BW=20M bit[18:16]: Nc index bit[21:19]: Nr index bit[23:22]: grouping bit[25:24]: codebook info bit[27:26]: coefficient size*/
#define BIT_R_WMAC_BFINFO_20M_1(x)     (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_R_WMAC_BFINFO_20M_1(x) ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_R_WMAC_BFINFO_20M_0   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  BF Info of the associated beamformer0 at BW=20M bit[2:0]: Nc index bit[5:3]: Nr index bit[7:6]: grouping bit[9:8]: codebook info bit[11:10]: coefficient size*/
#define BIT_R_WMAC_BFINFO_20M_0(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_R_WMAC_BFINFO_20M_0(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_TX_CSI_RPT_PARAM_BW80
  * @brief Tx CSI Report Parameter_BW80 Register
  * @{
  */
#define BIT_MASK_R_WMAC_BFINFO_80M_1   ((u32)0x00000FFF << 16)           /*!< R/W 0x0  BF Info of the associated beamformer1 at BW=80M bit[18:16]: Nc index bit[21:19]: Nr index bit[23:22]: grouping bit[25:24]: codebook info bit[27:26]: coefficient size*/
#define BIT_R_WMAC_BFINFO_80M_1(x)     (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_R_WMAC_BFINFO_80M_1(x) ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_R_WMAC_BFINFO_80M_0   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  BF Info of the associated beamformer0 at BW=80M bit[2:0]: Nc index bit[5:3]: Nr index bit[7:6]: grouping bit[9:8]: codebook info bit[11:10]: coefficient size*/
#define BIT_R_WMAC_BFINFO_80M_0(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_R_WMAC_BFINFO_80M_0(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/*==========REG_PAGE6 Register Address Definition==========*/
#define REG_WMAC_CR                         0x600
#define REG_WMAC_BWOPMODE                   0x603
#define REG_TCR                             0x604
#define REG_RCR                             0x608
#define REG_RXPKT_LIMIT                     0x60C
#define REG_RX_DLK_TIME                     0x60D
#define REG_SDIO_RXINT_LEN_TH               0x60E
#define REG_RX_DRVINFO_SZ                   0x60F
#define REG_MACID                           0x610
#define REG_MACID_H                         0x614
#define REG_BSSID                           0x618
#define REG_BSSID_H                         0x61C
#define REG_MAR                             0x620
#define REG_MAR_H                           0x624
#define REG_MBIDCAMCFG_1                    0x628
#define REG_MBIDCAM_CFG                     0x62C
#define REG_USTIME_EDCA                     0x638
#define REG_MAC_SPEC_SIFS                   0x63A
#define REG_RESP_SIFS_CCK                   0x63C
#define REG_RESP_SIFS_OFDM                  0x63E
#define REG_ACKTO                           0x640
#define REG_CTS2TO                          0x641
#define REG_EIFS                            0x642
#define REG_NAV_CTRL                        0x650
#define REG_BACAMCMD                        0x654
#define REG_BACAM_WD                        0x658
#define REG_BACAM_WD_H                      0x65C
#define REG_LBK_DLY                         0x660
#define REG_BITMAP_CMD                      0x661
#define REG_TX_RX_STATUS                    0x662
#define REG_WMAC_BITMAP_CTL                 0x663
#define REG_RXERR_RPT                       0x664
#define REG_WMAC_TRXPTCL_CTL                0x668
#define REG_WMAC_TRXPTCL_CTL_H              0x66C
#define REG_CAMCMD                          0x670
#define REG_CAMWRITE                        0x674
#define REG_CAMREAD                         0x678
#define REG_CAMDBG                          0x67C
#define REG_SECCFG                          0x680
#define REG_WOW_CTRL                        0x690
#define REG_PS_RX_INFO                      0x692
#define REG_WMMPS_UAPSD_TID                 0x693
#define REG_LPNAV_CTRL                      0x694
#define REG_WKFMCAM_CMD                     0x698
#define REG_RXFLTER0                        0x6A0
#define REG_RXFLTER2                        0x6A4
#define REG_BCN_PSR_RPT0                    0x6A8
#define REG_FLC_RPC                         0x6AC
#define REG_FLC_RPCT                        0x6AD
#define REG_FLC_PTS                         0x6AE
#define REG_FLC_TRPC                        0x6AF
#define REG_RXPKTMON_CTRL                   0x6B0
#define REG_STATE_MON                       0x6B4
#define REG_ERROR_EVT_CTL                   0x6B8
#define REG_RESPINFO                        0x6BC
#define REG_BT_COEX_TABLE_V1                0x6C0
#define REG_BT_COEX_TABLE2_V1               0x6C4
#define REG_BT_COEX_BREAK_TABLE             0x6C8
#define REG_BT_COEX_TABLE_H_V1              0x6CC
#define REG_RXCMD_0                         0x6D0
#define REG_RXCMD_1                         0x6D4
#define REG_RESP_TXINFO_CFG                 0x6D8
#define REG_BBPSF_CTRL                      0x6DC
#define REG_RESP_TXINFO_RATE                0x6DE
#define REG_P2P_RX_BCN_NOA                  0x6E0
#define REG_ASSOCIATED_BFMER0_INFO          0x6E4
#define REG_SOUNDING_CFG1                   0x6E8
#define REG_SOUNDING_CFG2                   0x6EC
#define REG_SOUNDING_CFG3                   0x6F0
#define REG_SOUNDING_CFG0                   0x6F4
#define REG_ANTCD_INFO                      0x6F8
#define REG_TX_CSI_RPT_PARAM_BW80           0x6FC

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