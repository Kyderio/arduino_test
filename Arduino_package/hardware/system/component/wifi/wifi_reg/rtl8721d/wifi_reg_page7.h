#ifndef _project_name_REG_PAGE7_H_
#define _project_name_REG_PAGE7_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE7
  * @brief REG_PAGE7 driver modules
  * @{
  */


/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE7_Register_Definitions REG_PAGE7 Register Definitions
  * @{
  */

/** @defgroup REG_MACID1
  * @brief
  * @{
  */
#define BIT_MASK_MACID1_0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  MAC Identification Number Register for port 1*/
#define BIT_MACID1_0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MACID1_0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MACID1_1
  * @brief
  * @{
  */
#define BIT_MASK_MACID1_1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  MAC Identification Number Register for port 1*/
#define BIT_MACID1_1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MACID1_1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BSSID1
  * @brief
  * @{
  */
#define BIT_MASK_BSSID1_0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Basic Station Set Identification for port 1.*/
#define BIT_BSSID1_0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BSSID1_0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BSSID1_1
  * @brief
  * @{
  */
#define BIT_MASK_BSSID1_1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  Basic Station Set Identification for port 1.*/
#define BIT_BSSID1_1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BSSID1_1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BCN_PSR_RPT1
  * @brief
  * @{
  */
#define BIT_MASK_DTIM_CNT1      ((u32)0x000000FF << 24)           /*!< R 0x0  DTIM count*/
#define BIT_DTIM_CNT1(x)        (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_DTIM_CNT1(x)    ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_DTIM_PERIOD1   ((u32)0x000000FF << 16)           /*!< R 0x0  DTIM Period*/
#define BIT_DTIM_PERIOD1(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_DTIM_PERIOD1(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_DTIM1               ((u32)0x00000001 << 15)           /*!< R 0x0  when set to 1 ,indicate DTIM beacon*/
#define BIT_TIM1                ((u32)0x00000001 << 14)           /*!< R 0x0  when set to 1 , indicate tim beacon*/
#define BIT_MASK_PS_AID_1       ((u32)0x000007FF << 0)            /*!< R/W 0x0  AID1 for MACID1*/
#define BIT_PS_AID_1(x)         (((u32)((x) & 0x000007FF) << 0))
#define BIT_GET_PS_AID_1(x)     ((u32)(((x >> 0) & 0x000007FF)))
/** @} */

/** @defgroup REG_ASSOCIATED_BFMEE_SEL
  * @brief
  * @{
  */
#define BIT_MASK_RD_BF_SEL   ((u32)0x00000007 << 29)           /*!< R/W 0x0  Beamformee CSI report parameter access 3'd0: {22'b0,bw20_cb0[1:0],bw20_ng0[1:0],bw20_nr0[2:0],bw20_nc0[2:0]} ; 3'd1: {22'b0,bw40_cb0[1:0],bw40_ng0[1:0],bw40_nr0[2:0],bw40_nc0[2:0]} ; 3'd2: {22'b0,bw80_cb0[1:0],bw80_ng0[1:0],bw80_nr0[2:0],bw80_nc0[2:0]} ; 3'd3:  register 0x714; 3'd4: {22'b0,bw20_cb1[1:0],bw20_ng1[1:0],bw20_nr1[2:0],bw20_nc1[2:0]} ; 3'd5: {22'b0,bw40_cb1[1:0],bw40_ng1[1:0],bw40_nr1[2:0],bw40_nc1[2:0]} ; 3'd6: {22'b0,bw80_cb1[1:0],bw80_ng1[1:0],bw80_nr1[2:0],bw80_nc1[2:0]} ; 3'd7:  register 0x714;*/
#define BIT_RD_BF_SEL(x)     (((u32)((x) & 0x00000007) << 29))
#define BIT_GET_RD_BF_SEL(x) ((u32)(((x >> 29) & 0x00000007)))
#define BIT_TXUSER_ID1       ((u32)0x00000001 << 25)           /*!< R/W   If enabled, NDPA would be sent to beamformee1.*/
#define BIT_MASK_AID1        ((u32)0x000001FF << 16)           /*!< R/W   P_AID of the target beamformee1*/
#define BIT_AID1(x)          (((u32)((x) & 0x000001FF) << 16))
#define BIT_GET_AID1(x)      ((u32)(((x >> 16) & 0x000001FF)))
#define BIT_TXUSER_ID0       ((u32)0x00000001 << 9)            /*!< R/W 0x0  If enabled, NDPA would be sent to beamformee0.*/
#define BIT_MASK_AID0        ((u32)0x000001FF << 0)            /*!< R/W 0x0  P_AID of the target beamformee0*/
#define BIT_AID0(x)          (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_AID0(x)      ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_SND_PTCL_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_NDP_RX_STANDBY_TIMER   ((u32)0x000000FF << 24)           /*!< R/W 0x20  A timeout value for MAC to leave NDP_Rx_standby_state and go back to normal Rx mode. (unit: us)*/
#define BIT_NDP_RX_STANDBY_TIMER(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_NDP_RX_STANDBY_TIMER(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_R_WMAC_VHT_CATEGORY    ((u32)0x000000FF << 8)            /*!< R/W 0x02  used as csi report  offset*/
#define BIT_R_WMAC_VHT_CATEGORY(x)      (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_R_WMAC_VHT_CATEGORY(x)  ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_R_WMAC_USE_NSTS             ((u32)0x00000001 << 7)            /*!< R/W 1  0  1: use Nsts as Nr, 0: use register value as Nr*/
#define BIT_R_DISABLE_CHECK_VHTSIGB_CRC ((u32)0x00000001 << 6)            /*!< R/W 0x0  1: disable, 0: enable*/
#define BIT_R_DISABLE_CHECK_VHTSIGA_CRC ((u32)0x00000001 << 5)            /*!< R/W 0x0  1: disable, 0: enable*/
#define BIT_R_WMAC_BFPARAM_SEL          ((u32)0x00000001 << 4)            /*!< R/W 0x0  1: use beamforming nc/nr/ng parameter from register 0x6F4 0: use beamforming nc/nr/ng parameter from tx report buffer*/
#define BIT_R_WMAC_CSISEQ_SEL           ((u32)0x00000001 << 3)            /*!< R/W 0x0  By which the sequence number of CSI frame is controlled 1: non-QoS SEQ number 0: counter*/
#define BIT_R_WMAC_CSI_WITHHTC_EN       ((u32)0x00000001 << 2)            /*!< R/W 0x0  Set to '1', CSI frame would carry HTC in MAC header.*/
#define BIT_R_WMAC_HT_NDPA_EN           ((u32)0x00000001 << 1)            /*!< R/W 0x0  Set to '1', MAC would inform BB of preparing to receive NDP if the received NDP Announcement MPDU is valid.*/
#define BIT_R_WMAC_VHT_NDPA_EN          ((u32)0x00000001 << 0)            /*!< R/W 0x0  Set to '1', MAC would inform BB of preparing to receive NDP if the received NDPA is valid*/
/** @} */

/** @defgroup REG_RX_CSI_RPT_INFO_H
  * @brief
  * @{
  */
#define BIT_WRITE_ENABLE                 ((u32)0x00000001 << 31)          /*!< R/W 0x0  Access flag. '0' for read. '1' for write, 0x72C[15:0] must be sett before this bit is set*/
#define BIT_MASK_VHTHT_MIMO_CTRL_FIELD   ((u32)0x00FFFFFF << 1)           /*!< R 0x0  when 'read': [24:1]: currently received VHT MIMO Control field  or [16:1]: currently received HT MIMO Control field*/
#define BIT_VHTHT_MIMO_CTRL_FIELD(x)     (((u32)((x) & 0x00FFFFFF) << 1))
#define BIT_GET_VHTHT_MIMO_CTRL_FIELD(x) ((u32)(((x >> 1) & 0x00FFFFFF)))
#define BIT_CSI_INTRRUPT_STATUS          ((u32)0x00000001 << 0)           /*!< R 0x0  sounding status: '0': fail; '1': success;*/
/** @} */

/** @defgroup REG_PWR_INT_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_SEQNUM_MID   ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  the sequence number for the selected mid for power bit*/
#define BIT_SEQNUM_MID(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_SEQNUM_MID(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_R_WMAC_PWR_INT_EN ((u32)0x00000001 << 7)            /*!< R/W 0x0  enable rx pkt fc column power bit int for FISR*/
#define BIT_MASK_REF_MID      ((u32)0x0000007F << 0)            /*!< R/W 0x0  the selected mid to check the seqnumber of the power bit*/
#define BIT_REF_MID(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_REF_MID(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_RX_CSI_RPT_INFO_V1
  * @brief
  * @{
  */
#define BIT_WRITE_USERID          ((u32)0x00000001 << 12)           /*!< W 0x0  write 0: id0; 1: id1*/
#define BIT_MASK_WRITE_BW         ((u32)0x00000003 << 10)           /*!< W 0x0  set bw*/
#define BIT_WRITE_BW(x)           (((u32)((x) & 0x00000003) << 10))
#define BIT_GET_WRITE_BW(x)       ((u32)(((x >> 10) & 0x00000003)))
#define BIT_MASK_WRITE_CB         ((u32)0x00000003 << 8)            /*!< W 0x0  set codebook*/
#define BIT_WRITE_CB(x)           (((u32)((x) & 0x00000003) << 8))
#define BIT_GET_WRITE_CB(x)       ((u32)(((x >> 8) & 0x00000003)))
#define BIT_MASK_WRITE_GROUPING   ((u32)0x00000003 << 6)            /*!< W 0x0  set group bit*/
#define BIT_WRITE_GROUPING(x)     (((u32)((x) & 0x00000003) << 6))
#define BIT_GET_WRITE_GROUPING(x) ((u32)(((x >> 6) & 0x00000003)))
#define BIT_MASK_WRITE_NR         ((u32)0x00000007 << 3)            /*!< W 0x0  set Nr index*/
#define BIT_WRITE_NR(x)           (((u32)((x) & 0x00000007) << 3))
#define BIT_GET_WRITE_NR(x)       ((u32)(((x >> 3) & 0x00000007)))
#define BIT_MASK_WRITE_NC         ((u32)0x00000007 << 0)            /*!< W 0x0  set Nc index*/
#define BIT_WRITE_NC(x)           (((u32)((x) & 0x00000007) << 0))
#define BIT_GET_WRITE_NC(x)       ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_POWER_MGT_0_V1
  * @brief
  * @{
  */
#define BIT_MASK_POWER_MGT_0   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  MICID 31 ~ 0 power bit value*/
#define BIT_POWER_MGT_0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_POWER_MGT_0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_POWER_MGT_1_V1
  * @brief
  * @{
  */
#define BIT_MASK_POWER_MGT_1   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  MICID 63 ~ 32 power bit value*/
#define BIT_POWER_MGT_1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_POWER_MGT_1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_POWER_MGT_2_V1
  * @brief
  * @{
  */
#define BIT_MASK_POWER_MGT_2   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  MICID 95 ~ 64 power bit value*/
#define BIT_POWER_MGT_2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_POWER_MGT_2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_POWER_MGT_3_V1
  * @brief
  * @{
  */
#define BIT_MASK_POWER_MGT_3   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  MICID 127 ~ 96 power bit value*/
#define BIT_POWER_MGT_3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_POWER_MGT_3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PLCP_HEADER
  * @brief
  * @{
  */
#define BIT_R_WMAC_PLCP_MON_SEL          ((u32)0x00000001 << 31)           /*!< R/W 0x0  TX/RX PLCP header rpt monitor selector,1--TX,0--RX*/
#define BIT_MASK_R_WMAC_PLCP_RDSIG_SEL   ((u32)0x00000007 << 28)           /*!< R/W 0x0  select 24bit data of PLCP header rpt to monitor*/
#define BIT_R_WMAC_PLCP_RDSIG_SEL(x)     (((u32)((x) & 0x00000007) << 28))
#define BIT_GET_R_WMAC_PLCP_RDSIG_SEL(x) ((u32)(((x >> 28) & 0x00000007)))
#define BIT_MASK_PLCP_RPT_OUT_HIGH       ((u32)0x0000000F << 24)           /*!< R 0x0  highest 4 bit of PLCP header rpt*/
#define BIT_PLCP_RPT_OUT_HIGH(x)         (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_PLCP_RPT_OUT_HIGH(x)     ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_RO_WMAC_PLCP_RDSIG      ((u32)0x00FFFFFF << 0)            /*!< R 0x0  24bit data of PLCP header rpt to monitor selected by 0x740[30:28]*/
#define BIT_RO_WMAC_PLCP_RDSIG(x)        (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_RO_WMAC_PLCP_RDSIG(x)    ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_TXDRXDMONITOR
  * @brief
  * @{
  */
#define BIT_MASK_RO_TXDRXD   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  monitor 32bit of ppdu data*/
#define BIT_RO_TXDRXD(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_RO_TXDRXD(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TXDRXDMONITOR_CTL
  * @brief
  * @{
  */
#define BIT_R_WMAC_TXDRXD_NUMSEL ((u32)0x00000001 << 1) /*!< R/W 0x0  moniotr first/second ppdu data after PLCP header,1--second,0--first*/
#define BIT_R_WMAC_TXDRXD_TRXSEL ((u32)0x00000001 << 0) /*!< R/W 0x0  select TXD/RXD monitor,1--TX,0--RX*/
/** @} */

/** @defgroup REG_WMAC_RTX_CTX_SUBTYPE_CFG
  * @brief
  * @{
  */
#define BIT_MASK_RO_WMAC_SWAES_RD_31_0   ((u32)0x00FFFFFF << 8)           /*!< R 0x0  Refer to 0x760[0]*/
#define BIT_RO_WMAC_SWAES_RD_31_0(x)     (((u32)((x) & 0x00FFFFFF) << 8))
#define BIT_GET_RO_WMAC_SWAES_RD_31_0(x) ((u32)(((x >> 8) & 0x00FFFFFF)))
#define BIT_MASK_R_WMAC_CTX_SUBTYPE      ((u32)0x0000000F << 4)           /*!< R/W 0x7  when write:ctx subyte, when read: ro_WMAC_SWAES_RD[7:4]*/
#define BIT_R_WMAC_CTX_SUBTYPE(x)        (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_R_WMAC_CTX_SUBTYPE(x)    ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_R_WMAC_RTX_SUBTYPE      ((u32)0x0000000F << 0)           /*!< R/W 0x6  when write:rtx subyte, when read: ro_WMAC_SWAES_RD[3:0]*/
#define BIT_R_WMAC_RTX_SUBTYPE(x)        (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_R_WMAC_RTX_SUBTYPE(x)    ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_WMAC_SWAES_RD0_V1
  * @brief
  * @{
  */
#define BIT_MASK_RO_WMAC_SWAES_RD_63_32   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  Refer to 0x760[0]*/
#define BIT_RO_WMAC_SWAES_RD_63_32(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_RO_WMAC_SWAES_RD_63_32(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_WMAC_SWAES_RD1_V1
  * @brief
  * @{
  */
#define BIT_MASK_RO_WMAC_SWAES_RD_95_64   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  Refer to 0x760[0]*/
#define BIT_RO_WMAC_SWAES_RD_95_64(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_RO_WMAC_SWAES_RD_95_64(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_WMAC_SWAES_RD3_V1
  * @brief
  * @{
  */
#define BIT_MASK_RO_WMAC_SWAES_RD_95_64   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  Refer to 0x760[0]*/
#define BIT_RO_WMAC_SWAES_RD_95_64(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_RO_WMAC_SWAES_RD_95_64(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_WMAC_SWAES_CFG
  * @brief
  * @{
  */
#define BIT_SWAES_REQ        ((u16)0x00000001 << 7) /*!< R 0x0  software aes engine request polling*/
#define BIT_CLR_SWAES_REQ    ((u16)0x00000001 << 6) /*!< R/W 0x0  Clear software aes engine request*/
#define BIT_R_WMAC_SWAES_WE  ((u16)0x00000001 << 3) /*!< R/W 0x0  Write enable of register ro_WMAC_SWAES_RD*/
#define BIT_R_WMAC_SWAES_SEL ((u16)0x00000001 << 0) /*!< R/W 0x0  When R_WMAC_SWAES_SEL =1,the content of register 0750-075F used to be aes engine data in or data out . When R_WMAC_SWAES_SEL =0, the content of register 0754-075F used to be aes engine security key*/
/** @} */

/** @defgroup REG_BT_COEX_V2
  * @brief
  * @{
  */
#define BIT_GNT_BT_POLARITY        ((u16)0x00000001 << 12)          /*!< R/W 0x0  grant both choose GNT_BT  polarity: 0 : deassert GNT_BT  signal as PTA grant both WiFI and BT. 1 : assert GNT_BT signal as PTA grant both WiFi and BT.*/
#define BIT_GNT_BT_BYPASS_PRIORITY ((u16)0x00000001 << 8)           /*!< R/W 0x0  1: enable GNT_BT_BYPASS_PRIORITY  0 : disable*/
#define BIT_MASK_TIMER             ((u16)0x000000FF << 0)           /*!< R/W 0x0  8 bit timer register : Arbitration window of bt trx request ( in the unit of us)*/
#define BIT_TIMER(x)               (((u16)((x) & 0x000000FF) << 0))
#define BIT_GET_TIMER(x)           ((u16)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BT_COEX
  * @brief
  * @{
  */
#define BIT_R_GNT_BT_RFC_SW     ((u32)0x00000001 << 12)          /*!< R/W 0x0  SW control BT RF*/
#define BIT_R_GNT_BT_RFC_SW_EN  ((u32)0x00000001 << 11)          /*!< R/W 0x0  SW control BT RF enable*/
#define BIT_R_GNT_BT_BB_SW      ((u32)0x00000001 << 10)          /*!< R/W 0x0  SW control BT baseband*/
#define BIT_R_GNT_BT_BB_SW_EN   ((u32)0x00000001 << 9)           /*!< R/W 0x0  SW control BT baseband enable*/
#define BIT_R_BT_CNT_THREN      ((u32)0x00000001 << 8)           /*!< R/W 0x0  BT count threshold enable*/
#define BIT_MASK_R_BT_CNT_THR   ((u32)0x000000FF << 0)           /*!< R/W 0x0  BT count threshold*/
#define BIT_R_BT_CNT_THR(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_R_BT_CNT_THR(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_WLAN_ACT_MASK_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_WACTMSK_OFF_DUR   ((u32)0x000000FF << 8)           /*!< R/W 0x0  WLAN will reserve channel for BT during MASK OFF duration. Unit 0.625ms*/
#define BIT_WACTMSK_OFF_DUR(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_WACTMSK_OFF_DUR(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_WACTMSK_ON_DUR    ((u32)0x000000FF << 0)           /*!< R/W 0x0  WLAN can block BT during MASK On duration. Unit 0.625ms*/
#define BIT_WACTMSK_ON_DUR(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_WACTMSK_ON_DUR(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_WLAN_ACT_MASK_CTRL_1
  * @brief
  * @{
  */
#define BIT_WLRX_TER_BY_CTL       ((u16)0x00000001 << 11) /*!< R/W 0x0  When wlan receive a control packet without fit address, whether the signal indicating wlan rx can be terminated as soon as the address check finish is not only controlled by r_WLRX_TER_BY_AD, but also should be refereed to this bit. 1: enable; 0: disable*/
#define BIT_WLRX_TER_BY_AD        ((u16)0x00000001 << 10) /*!< R/W 0x0  When wlan receive the packet without fit address, the signal indicating wlan rx can be terminated as soon as the address check finish. This feature can be enabled by this bit. 1: enable; 0: disable*/
#define BIT_ANT_DIVERSITY_SEL     ((u16)0x00000001 << 9)  /*!< R/W 0x0  Antenna diversity for 2 antenna mode: MAC_ANT_SEL = GNT_BT ^ ANT_DIVERDITY_SEL.*/
#define BIT_ANTSEL_FOR_BT_CTRL_EN ((u16)0x00000001 << 8)  /*!< R/W 0x0  Enable the control of antenna selection through GNT_BT: GNT_BT=1: ANT_SEL for BT device; GNT_BT=0: ANT_SEL for WL device*/
#define BIT_WLACT_LOW_GNTWL_EN    ((u16)0x00000001 << 2)  /*!< R/W 0x0  When WLACT_LOW_GNTWL_EN = 1, the TRX of WLAN are blocked according to the BTCOEX table arbitration during MASK OFF duration. WLACT_LOW_GNTWL_EN = 0, the TRX of WLAN are paused during MASK OFF duration..*/
#define BIT_WLACT_HIGH_GNTBT_EN   ((u16)0x00000001 << 1)  /*!< R/W 0x0  When WLACT_HIGH_GNTBT_EN = 1, the TRX of WLAN are blocked according to the BTCOEX table arbitration during MASK ON duration. When WLACT_HIGH_ GNTBT_EN = 0, the TRX of WLAN are not paused during MASK OFF duration.*/
#define BIT_WLACT_SYNC_BT_EN      ((u16)0x00000001 << 0)  /*!< R/W 0x0  When WLACT_SYNC_BT_EN = 1, WL_ACT is asserted only when WLACT_MASK_ON state starts (WACTMSK_OFF_DUR timeout), and when BT_PRI is low or wait until BT_PRI goes low. Similarly, WL_ACT is de-asserted only when WLACT_MASK_FF state starts (WACTMSK_ON_DUR timeout), and when BT_PRI is high or wait until BT_PRI goes low.*/
/** @} */

/** @defgroup REG_BT_COEX_ENHANCED_INTR_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_BT_STAT_DELAY      ((u16)0x0000000F << 12)           /*!< R/W 0x0  For CSR, BT_PRI and BT_STAT go high form low at the same time. Thus, BT_STAT need delay BT_STAT_DELAY time to trigger hardware. Unit: 1us*/
#define BIT_BT_STAT_DELAY(x)        (((u16)((x) & 0x0000000F) << 12))
#define BIT_GET_BT_STAT_DELAY(x)    ((u16)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_BT_TRX_INIT_DE     ((u16)0x0000000F << 8)            /*!< R/W 0x0  After BT_PRI asserting for BT_TRX_INIT_DETECT us, if BT_STAT is low, then BT will receive packets; otherwise, if BT goes high, BT will TX data. Unit 4us.*/
#define BIT_BT_TRX_INIT_DE(x)       (((u16)((x) & 0x0000000F) << 8))
#define BIT_GET_BT_TRX_INIT_DE(x)   ((u16)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_BT_PRI_DETECT_TO   ((u16)0x0000000F << 4)            /*!< R/W 0x0  After BT_PRI asserting, if BT_STAT is asserted within this TO duration, BT will initiate high priority activities; otherwise, if BT_STAT is not asserted within this duration, it would be low priority activities. Units 1us.*/
#define BIT_BT_PRI_DETECT_TO(x)     (((u16)((x) & 0x0000000F) << 4))
#define BIT_GET_BT_PRI_DETECT_TO(x) ((u16)(((x >> 4) & 0x0000000F)))
#define BIT_STATIS_BT_RST           ((u16)0x00000001 << 3)            /*!< W1C 0x0  Reset BT_ACT_STATISTICS Counters. Write "1" pulse*/
#define BIT_STATIS_BT_EN            ((u16)0x00000001 << 2)            /*!< R/W 0x0  When this bit is set, the BT_ACT_STATISTICS counters starts counting*/
#define BIT_WL_ACT_MASK_ENABLE      ((u16)0x00000001 << 1)            /*!< R/W 0x0  Enable WLAN_ACT Mask Function (related to 0x768h-0x76Dh)*/
#define BIT_ENHANCED_BT_ENABLE      ((u16)0x00000001 << 0)            /*!< R/W 0x0  Enable Enhanced BT Interface (we suggest to use with BT mode 2)*/
/** @} */

/** @defgroup REG_BT_ENHANCED_CTRL0
  * @brief
  * @{
  */
#define BIT_MASK_STATIS_BT_HI_RX   ((u32)0x0000FFFF << 16)           /*!< R 0x0  Counters for BT high priority TX. It counts up when STATIS_BT_EN is set. This counter will reset when STTIS_BT_RST is written by 1 pulse. This counter cannot wrap around when overflow occurs. Under overflow, this counter is kept with 0xFFFF.*/
#define BIT_STATIS_BT_HI_RX(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_STATIS_BT_HI_RX(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_STATIS_BT_HI_TX   ((u32)0x0000FFFF << 0)            /*!< R 0x0  Counters for BT high priority TX. It counts up when STATIS_BT_EN is set. This counter will reset when STTIS_BT_RST is written by 1 pulse. This counter cannot wrap around when overflow occurs. Under overflow, this counter is kept with 0xFFFF.*/
#define BIT_STATIS_BT_HI_TX(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_STATIS_BT_HI_TX(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BT_ENHANCED_CTRL1
  * @brief
  * @{
  */
#define BIT_MASK_STATIS_BT_LO_RX   ((u32)0x0000FFFF << 16)           /*!< R 0x0  Counters for BT high priority TX. It counts up when STATIS_BT_EN is set. This counter will reset when STTIS_BT_RST is written by 1 pulse. This counter cannot wrap around when overflow occurs. Under overflow, this counter is kept with 0xFFFF.*/
#define BIT_STATIS_BT_LO_RX(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_STATIS_BT_LO_RX(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_STATIS_BT_LO_TX   ((u32)0x0000FFFF << 0)            /*!< R 0x0  Counters for BT high priority TX. It counts up when STATIS_BT_EN is set. This counter will reset when STTIS_BT_RST is written by 1 pulse. This counter cannot wrap around when overflow occurs. Under overflow, this counter is kept with 0xFFFF.*/
#define BIT_STATIS_BT_LO_TX(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_STATIS_BT_LO_TX(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BT_PROPRI
  * @brief
  * @{
  */
#define BIT_MASK_BT_CMD_RPT                  ((u32)0x0000FFFF << 16)           /*!< R 0x0  bt state and bt priority at different stage*/
#define BIT_BT_CMD_RPT(x)                    (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_BT_CMD_RPT(x)                ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_RPT_FROM_BT                 ((u32)0x000000FF << 8)            /*!< R 0x0  bt state at different stage*/
#define BIT_RPT_FROM_BT(x)                   (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_RPT_FROM_BT(x)               ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_BT_HID_ISR_SET              ((u32)0x00000003 << 6)            /*!< R/W 0x0  When EN_BT_PROFILE_OR_HID is set "1", hardware also need to check this value to trigger an interrupt. 0: default, TX and RX 1: TX 2: RX 3: Reserved*/
#define BIT_BT_HID_ISR_SET(x)                (((u32)((x) & 0x00000003) << 6))
#define BIT_GET_BT_HID_ISR_SET(x)            ((u32)(((x >> 6) & 0x00000003)))
#define BIT_TDMA_BT_START_NOTIFY             ((u32)0x00000001 << 5)            /*!< R/W 0x0  When the control of TDMA mode is firmware and firmware also receive signal that NULL packet for BT had sent, firmware can fill this bit to notify HW PTA to pull WLAN_ACT to low and the interval is Tbt*/
#define BIT_ENABLE_TDMA_FW_MODE              ((u32)0x00000001 << 4)            /*!< R/W 0x0  0: default, PTA TDMA mode is hardware mode. 1: enable firmware mode.*/
#define BIT_ENABLE_PTA_TDMA_MODE             ((u32)0x00000001 << 3)            /*!< R/W 0x0  0: default, disable PTA TDMA mode 1: enable TDMA mode: a. WLAN_ACT default is high. b. Hardware mode: When NULL packet for BT had sent, hardware will notify PTA to start TDMA mode. Firmware mode: When NULL packet for BT had sent, hardware will trigger an interrupt to notify firmware. Then, firmware need to set TDMA_BT_START_NOTIFY to notify PTA to start TDMA mode.*/
#define BIT_ENABLE_COEXIST_TAB_IN_TDMA       ((u32)0x00000001 << 2)            /*!< R/W 0x0  0: default, no matter which WLAN_ACT is high or low, PTA doesn't execute co-exist table scheme 1: enable, When WLAN_ACT is high, PTA execute xo-exist table scheme*/
#define BIT_GPIO2_GPIO3_EX_ANGE_OR_NO_BT_CCA ((u32)0x00000001 << 1)            /*!< R/W 0x0  Enable GPIO2 and GPIO3 exchange. (Note: need to enable mode2 and enhance 3 wire) If Enable RTK BT mode, set this bit to 1 to disable granting to BT device when arbitration*/
#define BIT_RTK_BT_ENABLE                    ((u32)0x00000001 << 0)            /*!< R/W 0x0  Enable RTK BT mode*/
/** @} */

/** @defgroup REG_BT_STATUS_REPORT_REGISTER
  * @brief
  * @{
  */
#define BIT_MASK_BT_PROFILE          ((u32)0x000000FF << 24)           /*!< R 0x0  When WLAN received CMD_ID 0x3, it will recorder to this.*/
#define BIT_BT_PROFILE(x)            (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_BT_PROFILE(x)        ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_BT_POWER            ((u32)0x000000FF << 16)           /*!< R 0x0  When WLAN received CMD_ID 0x2, it will recorder to this*/
#define BIT_BT_POWER(x)              (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_BT_POWER(x)          ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_BT_PREDECT_STATUS   ((u32)0x000000FF << 8)            /*!< R 0x0  When WLAN received CMD_ID 0x0, it will recorder to this*/
#define BIT_BT_PREDECT_STATUS(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_BT_PREDECT_STATUS(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_BT_CMD_INFO         ((u32)0x000000FF << 0)            /*!< R/W 0x0  command information from BT*/
#define BIT_BT_CMD_INFO(x)           (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_BT_CMD_INFO(x)       ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BT_INTERRUPT_CONTROL_REGISTER
  * @brief
  * @{
  */
#define BIT_EN_MAC_NULL_PKT_NOTIFY   ((u32)0x00000001 << 31)           /*!< R/W 0x0  When MAC had sent NULL packet for BT and firmware also set nav_for_bt bit, hardware triggers an interrupt to notify firmware. 0: Disable 1: Enable*/
#define BIT_EN_WLAN_RPT_AND_BT_QUERY ((u32)0x00000001 << 30)           /*!< R/W 0x0  Enable two interrupt: 1) PTA sent the report packet successfully 2) PTA sent a query packet 0: Disable 1: Enable*/
#define BIT_EN_BT_STSTUS_RPT         ((u32)0x00000001 << 29)           /*!< R/W 0x0  When WLAN receive cmd_id "0", hardware trigger an interrupt to notify firmware. 0: Disable 1: Enable*/
#define BIT_EN_BT_POWER              ((u32)0x00000001 << 28)           /*!< R/W 0x0  When WLAN received the packet including BT Power and check register "BT_STATUS_RPT", if data contents aren't the same, hardware can trigger an interrupt to notify firmware. 0: Disable 1: Enable*/
#define BIT_EN_BT_CHANNEL            ((u32)0x00000001 << 27)           /*!< R/W 0x0  When WLAN received the packet including BT channel number, hardware can trigger an interrupt to notify firmware. 0: Disable 1: Enable*/
#define BIT_EN_BT_SLOT_CHANGE        ((u32)0x00000001 << 26)           /*!< R/W 0x0  When WLAN received the packet including that BT had multi-slots, hardware can trigger an interrupt to notify firmware. 0: Disable 1: Enable*/
#define BIT_EN_BT_PROFILE_OR_HID     ((u32)0x00000001 << 25)           /*!< R/W 0x0  Enable two interrupt 1) When WLAN received the packet including that WLAN specific profile and check register "BT_STATUS_RPT", if data contents aren't the same, hardware can trigger an interrupt to notify firmware. 2) When WLAN received the report packet including HID information, hardware will trigger an interrupt to notify firmware. 0: Disable 1: Enable*/
#define BIT_WLAN_RPT_NOTIFY          ((u32)0x00000001 << 24)           /*!< R/W 0x0  When firmware had prepared packet to send to BT, it need to set this bit to notify hardware that it can transmit. 0: There isn't a valid packet in register" WLAN_RPT_ PKT". 1: There is a valid packet in register" WLAN_RPT_ PKT".*/
#define BIT_MASK_WLAN_RPT_DATA       ((u32)0x000000FF << 16)           /*!< R/W 0x0  Data contents, When the report packet had sent, hardware will clear this register.*/
#define BIT_WLAN_RPT_DATA(x)         (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_WLAN_RPT_DATA(x)     ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_CMD_ID              ((u32)0x000000FF << 8)            /*!< R/W 0x0  Command id: 0x80~FF*/
#define BIT_CMD_ID(x)                (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_CMD_ID(x)            ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_BT_DATA             ((u32)0x000000FF << 0)            /*!< R 0x0  When WLAN received the packet BT sent, hardware will place data to this register in addition to CMD_ID 0x0 ~ 0x3.*/
#define BIT_BT_DATA(x)               (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_BT_DATA(x)           ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_WLAN_REPORT_TIME_OUT_CONTROL_REGISTER
  * @brief
  * @{
  */
#define BIT_MASK_WLAN_RPT_TO   ((u8)0x000000FF << 0)           /*!< R/W 0x0  When WLANＨW received query packet, HW timer counts. If timer equals to WLAN_RPT_TO and HW can"t send packet, it will give up query packet at this time. When BT sent another query packet, WLAN HW need to send the previous packet and it shouldn't trigger an interrupt to firmware. Unit: 4us.*/
#define BIT_WLAN_RPT_TO(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_WLAN_RPT_TO(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BT_ISOLATION_TABLE_REGISTER_REGISTER
  * @brief
  * @{
  */
#define BIT_MASK_ISOLATION_CHK_0   ((u32)0x007FFFFF << 1)           /*!< R/W 0x0  0: leave PTA 1: enter PTA*/
#define BIT_ISOLATION_CHK_0(x)     (((u32)((x) & 0x007FFFFF) << 1))
#define BIT_GET_ISOLATION_CHK_0(x) ((u32)(((x >> 1) & 0x007FFFFF)))
#define BIT_ISOLATION_EN           ((u32)0x00000001 << 0)           /*!< R/W 0x0  Isolation table enable bit. 0: disable 1: enable*/
/** @} */

/** @defgroup REG_BT_ISOLATION_TABLE_REGISTER_REGISTER_1
  * @brief
  * @{
  */
#define BIT_MASK_ISOLATION_CHK_1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  0: leave PTA 1: enter PTA*/
#define BIT_ISOLATION_CHK_1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_ISOLATION_CHK_1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BT_ISOLATION_TABLE_REGISTER_REGISTER_2
  * @brief
  * @{
  */
#define BIT_MASK_ISOLATION_CHK_2   ((u32)0x00FFFFFF << 0)           /*!< R/W 0x0  0: leave PTA 1: enter PTA*/
#define BIT_ISOLATION_CHK_2(x)     (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_ISOLATION_CHK_2(x) ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_BT_INTERRUPT_STATUS_REGISTER
  * @brief
  * @{
  */
#define BIT_BT_HID_ISR              ((u8)0x00000001 << 7) /*!< R/W1C 0x0  When WLAN received the report packet including HID information, hardware will trigger an interrupt to notify firmware*/
#define BIT_BT_QUERY_ISR            ((u8)0x00000001 << 6) /*!< R/W1C 0x0  When WLAN received a query packet, hardware triggers an interrupt to notify firmware*/
#define BIT_MAC_NULL_PKT_NOTIFY_ISR ((u8)0x00000001 << 5) /*!< R/W1C 0x0  When MAC had sent NULL packet for BT and firmware also set nav_for_bt bit, hardware triggers an interrupt to notify firmware*/
#define BIT_WLAN_RPT_ISR            ((u8)0x00000001 << 4) /*!< R/W1C 0x0  When PTA sent the report packet successfully, hardware triggers an interrupt to notify firmware.*/
#define BIT_BT_POWER_ISR            ((u8)0x00000001 << 3) /*!< R/W1C 0x0  When WLAN received the packet including BT Power and check register "BT_STATUS_RPT", if data contents aren't the same, hardware can trigger an interrupt to notify firmware*/
#define BIT_BT_CHANNEL_ISR          ((u8)0x00000001 << 2) /*!< R/W1C 0x0  When WLAN received the packet including BT channel number, hardware can trigger an interrupt to notify firmware.*/
#define BIT_BT_SLOT_CHANGE_ISR      ((u8)0x00000001 << 1) /*!< R/W1C 0x0  When WLAN received the packet including that BT had multi-slots, hardware can trigger an interrupt to notify firmware*/
#define BIT_BT_PROFILE_ISR          ((u8)0x00000001 << 0) /*!< R/W1C 0x0  When WLAN received the packet including that WLAN specific profile and check register "BT_STATUS_RPT", if data contents aren't the same, hardware can trigger an interrupt to notify firmware.*/
/** @} */

/** @defgroup REG_BT_TDMA_TIME_REGISTER
  * @brief
  * @{
  */
#define BIT_MASK_BT_TIME              ((u32)0x03FFFFFF << 6)           /*!< R/W 0x0  The time is that WLAN_ACT is low. Unit: us*/
#define BIT_BT_TIME(x)                (((u32)((x) & 0x03FFFFFF) << 6))
#define BIT_GET_BT_TIME(x)            ((u32)(((x >> 6) & 0x03FFFFFF)))
#define BIT_MASK_BT_RPT_SAMPLE_RATE   ((u32)0x0000003F << 0)           /*!< R/W 0x0  When wifi detected the raising edge of BT report packet, wifi need to counter BT_RPT_SAMPLE_RATE. Then hw could detect which is high or low. Uint: 20 ns*/
#define BIT_BT_RPT_SAMPLE_RATE(x)     (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_BT_RPT_SAMPLE_RATE(x) ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_BT_ACT_REGISTER
  * @brief
  * @{
  */
#define BIT_MASK_BT_EISR_EN    ((u32)0x000000FF << 16)           /*!< R/W 0x0  BT eisr enable*/
#define BIT_BT_EISR_EN(x)      (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_BT_EISR_EN(x)  ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_BT_ACT_FALLING_ISR ((u32)0x00000001 << 10)           /*!< R/W1C 0x0  When BT_ACT signal is falling edge, it will trigger an interrupt.*/
#define BIT_BT_ACT_RISING_ISR  ((u32)0x00000001 << 9)            /*!< R/W1C 0x0  When BT_ACT signal is raising edge, it will trigger an interrupt*/
#define BIT_TDMA_TO_ISR        ((u32)0x00000001 << 8)            /*!< R/W1C 0x0  When BT_TIME expired, it will trigger an interrupt.*/
#define BIT_MASK_BT_CH         ((u32)0x0000007F << 0)            /*!< R 0x7f  When hardware receive cm_id "1", it will recorder to this.*/
#define BIT_BT_CH(x)           (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_BT_CH(x)       ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_LTR_IDLE_LATENCY_V2
  * @brief
  * @{
  */
#define BIT_MASK_LTR_IDLE_LATENCY   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x88e088e0  LTR idle latency.*/
#define BIT_LTR_IDLE_LATENCY(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_LTR_IDLE_LATENCY(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_LTR_ACTIVE_LATENCY_V2
  * @brief
  * @{
  */
#define BIT_MASK_LTR_ACTIVE_LATENCY   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x880b880b  LTR Active latency.*/
#define BIT_LTR_ACTIVE_LATENCY(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_LTR_ACTIVE_LATENCY(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_OBFF_CTRL
  * @brief
  * @{
  */
#define BIT_ODFF_EN_WAKE                   ((u32)0x00000001 << 31)           /*!< R/W 0x0  */
#define BIT_CFG_OBFF_AUTOACT               ((u32)0x00000001 << 30)           /*!< R/W 0x0  */
#define BIT_MASK_OBFF_STATE                ((u32)0x00000003 << 28)           /*!< RO   Internal OBFF state.0: idle,1: OBFF,2: CPU ACTIVE.*/
#define BIT_OBFF_STATE(x)                  (((u32)((x) & 0x00000003) << 28))
#define BIT_GET_OBFF_STATE(x)              ((u32)(((x >> 28) & 0x00000003)))
#define BIT_CFG_OBFF_AUTOIDLE              ((u32)0x00000001 << 27)           /*!< R/W 0x0  Obff state go to obff idle when LTR idle being sending*/
#define BIT_CFG_BLOCKINT_EN                ((u32)0x00000001 << 26)           /*!< R/W 0x1  Enable interrupt blocking function by OBFF state*/
#define BIT_MASK_CFG_WK_MAX_PLS_2_0        ((u32)0x00000007 << 23)           /*!< R/W 0x4  The max space between 2 successive edge of WAKE# .*/
#define BIT_CFG_WK_MAX_PLS_2_0(x)          (((u32)((x) & 0x00000007) << 23))
#define BIT_GET_CFG_WK_MAX_PLS_2_0(x)      ((u32)(((x >> 23) & 0x00000007)))
#define BIT_MASK_CFG_WK_MIN_PLS_2_0        ((u32)0x00000007 << 20)           /*!< R/W 0x4  The min space between 2 successive edge of WAKE# .*/
#define BIT_CFG_WK_MIN_PLS_2_0(x)          (((u32)((x) & 0x00000007) << 20))
#define BIT_GET_CFG_WK_MIN_PLS_2_0(x)      ((u32)(((x >> 20) & 0x00000007)))
#define BIT_MASK_CFG_WK_MAX_F2F_2_0        ((u32)0x00000007 << 17)           /*!< R/W 0x4  The max space between 2 successive falling edge of WAKE# .*/
#define BIT_CFG_WK_MAX_F2F_2_0(x)          (((u32)((x) & 0x00000007) << 17))
#define BIT_GET_CFG_WK_MAX_F2F_2_0(x)      ((u32)(((x >> 17) & 0x00000007)))
#define BIT_MASK_CFG_WK_MIN_F2F_2_0        ((u32)0x00000007 << 14)           /*!< R/W 0x4  The min space between 2 successive falling edge of WAKE# .*/
#define BIT_CFG_WK_MIN_F2F_2_0(x)          (((u32)((x) & 0x00000007) << 14))
#define BIT_GET_CFG_WK_MIN_F2F_2_0(x)      ((u32)(((x >> 14) & 0x00000007)))
#define BIT_CFG_TXBLOCK_EN                 ((u32)0x00000001 << 13)           /*!< R/W 0x1  Block tx hardware beacon*/
#define BIT_MASK_OBFF_INT_TIME_ID_2_0      ((u32)0x00000007 << 10)           /*!< R/W 0x2  When interrupt com, delay timeout value index. 0: 12.8us; 1: 102.4us; 2: 204.8us; 3: 819.2 us; 4: 1.638ms; 5: 52ms; 6: 104ms; 7: always block until cpu active window*/
#define BIT_OBFF_INT_TIME_ID_2_0(x)        (((u32)((x) & 0x00000007) << 10))
#define BIT_GET_OBFF_INT_TIME_ID_2_0(x)    ((u32)(((x >> 10) & 0x00000007)))
#define BIT_MASK_OBFF_TIMER_ID_MEDIA_2_0   ((u32)0x00000007 << 7)            /*!< R/W 0x4  When media rate rx packet in , delay rx dma timeout value index. 0: no delay,1: 12.8us; 2: 102.4us; 3: 204.8us; 4: 819.2 us; 5: 1.638ms; 6: 52ms; 7: always block until obff or cpu active window*/
#define BIT_OBFF_TIMER_ID_MEDIA_2_0(x)     (((u32)((x) & 0x00000007) << 7))
#define BIT_GET_OBFF_TIMER_ID_MEDIA_2_0(x) ((u32)(((x >> 7) & 0x00000007)))
#define BIT_MASK_OBFF_TIME_ID_LOW_2_0      ((u32)0x00000007 << 4)            /*!< R/W 0x3  When low rate rx packet in , delay rx dma timeout value index. 0: 12.8us; 1: 102.4us; 2: 204.8us; 3: 819.2 us; 4: 1.638ms; 5: 52ms; 6: 104ms; 7: always block until obff or cpu active window*/
#define BIT_OBFF_TIME_ID_LOW_2_0(x)        (((u32)((x) & 0x00000007) << 4))
#define BIT_GET_OBFF_TIME_ID_LOW_2_0(x)    ((u32)(((x >> 4) & 0x00000007)))
#define BIT_APP_CPU_ACT                    ((u32)0x00000001 << 3)            /*!< R/W 0x0  Application set obff state to CPU ACTIVE. Need assert with APP_INIT in the same cycle. PULSE*/
#define BIT_APP_OBFF                       ((u32)0x00000001 << 2)            /*!< R/W 0x0  Application set obff state to OBFF. Need assert with APP_INIT in the same cycle. PULSE*/
#define BIT_APP_IDLE                       ((u32)0x00000001 << 1)            /*!< R/W 0x0  Application set obff state to idle. Need assert with APP_INIT in the same cycle. PULSE*/
#define BIT_APP_INIT                       ((u32)0x00000001 << 0)            /*!< R/W 0x0  */
/** @} */

/** @defgroup REG_LTR_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_LTR_RPBACC_ID_HIGH      ((u32)0x00000007 << 25)           /*!< R/W 3'b101  Threshold to send ltr act msg after accumulating high rate rx payload page number.*/
#define BIT_LTR_RPBACC_ID_HIGH(x)        (((u32)((x) & 0x00000007) << 25))
#define BIT_GET_LTR_RPBACC_ID_HIGH(x)    ((u32)(((x >> 25) & 0x00000007)))
#define BIT_MASK_LTR_RPBACC_ID_MEDIA     ((u32)0x00000007 << 22)           /*!< R/W 3'b101  Threshold to send ltr act msg after accumulating media rate rx payload page number.*/
#define BIT_LTR_RPBACC_ID_MEDIA(x)       (((u32)((x) & 0x00000007) << 22))
#define BIT_GET_LTR_RPBACC_ID_MEDIA(x)   ((u32)(((x >> 22) & 0x00000007)))
#define BIT_MASK_LTR_RPBACC_ID_LOW       ((u32)0x00000007 << 19)           /*!< R/W 3'b101  Threshold to send ltr act msg after accumulating low rate rx payload page number.*/
#define BIT_LTR_RPBACC_ID_LOW(x)         (((u32)((x) & 0x00000007) << 19))
#define BIT_GET_LTR_RPBACC_ID_LOW(x)     ((u32)(((x >> 19) & 0x00000007)))
#define BIT_RPBACC_CLRBLOCK              ((u32)0x00000001 << 18)           /*!< R/W 0x1  Clear rx dma and int block after rx packet page large than threshold*/
#define BIT_LTR_RPBACC_EN                ((u32)0x00000001 << 17)           /*!< R/W 0x1  Enable gen ltr active msg according to occupied pages in rx packet buffer*/
#define BIT_MASK_LTR_SPACE_ID            ((u32)0x00000003 << 15)           /*!< R/W 2'b10  Ltr space index.0:h100(for test),1:h3000(300us),2:h5000(512us),3:h9000(921us)*/
#define BIT_LTR_SPACE_ID(x)              (((u32)((x) & 0x00000003) << 15))
#define BIT_GET_LTR_SPACE_ID(x)          ((u32)(((x >> 15) & 0x00000003)))
#define BIT_MASK_LTR_IDLE_TIMER_ID_2_0   ((u32)0x00000007 << 12)           /*!< R/W 3'b010  Send ltr idle message after trx state machine in idle for more than this time. 0:2 us,1: 13us,2 :100us,3: 800us,4:1.13ms,5:2.25ms,6: 6ms*/
#define BIT_LTR_IDLE_TIMER_ID_2_0(x)     (((u32)((x) & 0x00000007) << 12))
#define BIT_GET_LTR_IDLE_TIMER_ID_2_0(x) ((u32)(((x >> 12) & 0x00000007)))
#define BIT_MASK_BLKHWBCN_TIMER_ID       ((u32)0x00000007 << 9)            /*!< R/W 3'b011  Use obff block timer to send ltr active*/
#define BIT_BLKHWBCN_TIMER_ID(x)         (((u32)((x) & 0x00000007) << 9))
#define BIT_GET_BLKHWBCN_TIMER_ID(x)     ((u32)(((x >> 9) & 0x00000007)))
#define BIT_OBFF_LTRIDLE_EN              ((u32)0x00000001 << 8)            /*!< R/W 0x1  Send LTR idle message in obff or cpu active window*/
#define BIT_CFG_DELAY_LTR_ACT            ((u32)0x00000001 << 7)            /*!< R/W 0x1  Use obff block timer to send ltr active*/
#define BIT_CFG_CTS_LTRACT               ((u32)0x00000001 << 6)            /*!< R/W 0x1  CTS direct to send ltr active*/
#define BIT_LTRIDLE_NO_SNOOP             ((u32)0x00000001 << 5)            /*!< R/W 0x0  Calculating ltr active message sending timing according to no snoop or snoop latency.*/
#define BIT_LTRACT_EN_INCPUACT           ((u32)0x00000001 << 4)            /*!< R/W 0x0  Send LTR active in OBFF or CPU active window.*/
#define BIT_APP_REQ_LTRACT               ((u32)0x00000001 << 3)            /*!< R 0x0  Driver or cpu direct LTR active message. A message with LTR_ACTIVE_LATENCY will be sent. AUTO CLEAR*/
#define BIT_APP_REQ_LTRIDLE              ((u32)0x00000001 << 2)            /*!< R 0x0  Driver or cpu direct LTR idle message. A message with LTR_IDLE_LATENCY will be sent. AUTO CLEAR*/
#define BIT_LTR_HW_EN                    ((u32)0x00000001 << 1)            /*!< R/W 0x1  Enable hardware LTR message*/
#define BIT_LTR_EN                       ((u32)0x00000001 << 0)            /*!< R/W 0x0  Enable LTR message*/
/** @} */

/** @defgroup REG_LTR_CTRL2
  * @brief
  * @{
  */
#define BIT_MASK_OBFF_TIMER_ID_HIGH   ((u32)0x00000007 << 29)           /*!< R/W 3'b100  When media rate rx packet in , delay rx dma timeout value index. 0: no delay,1: 12.8us; 2: 102.4us; 3: 204.8us; 4: 819.2 us; 5: 1.638ms; 6: 52ms; 7: always block until obff or cpu active window*/
#define BIT_OBFF_TIMER_ID_HIGH(x)     (((u32)((x) & 0x00000007) << 29))
#define BIT_GET_OBFF_TIMER_ID_HIGH(x) ((u32)(((x >> 29) & 0x00000007)))
#define BIT_MASK_HIGH_RATE_BDRY       ((u32)0x0000007F << 16)           /*!< R/W 7'b1000000  High, media, low rate boundary*/
#define BIT_HIGH_RATE_BDRY(x)         (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_HIGH_RATE_BDRY(x)     ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_LOW_RATE_BDRY        ((u32)0x0000007F << 9)            /*!< R/W 7'b0100000  High, media, low rate boundary*/
#define BIT_LOW_RATE_BDRY(x)          (((u32)((x) & 0x0000007F) << 9))
#define BIT_GET_LOW_RATE_BDRY(x)      ((u32)(((x >> 9) & 0x0000007F)))
#define BIT_MASK_HIGH_RATE_TRIGS      ((u32)0x00000003 << 7)            /*!< R/W 2'b01  High rate rx ltr trigger point select: 0 plcp ready;1: rx a1 latch OK; 2: fcs ready.*/
#define BIT_HIGH_RATE_TRIGS(x)        (((u32)((x) & 0x00000003) << 7))
#define BIT_GET_HIGH_RATE_TRIGS(x)    ((u32)(((x >> 7) & 0x00000003)))
#define BIT_MASK_MEDIA_RATE_TRIGS     ((u32)0x00000003 << 5)            /*!< R/W 2'b01  Media rate rx ltr trigger point select: 0 plcp ready;1: rx a1 latch OK; 2: fcs ready.*/
#define BIT_MEDIA_RATE_TRIGS(x)       (((u32)((x) & 0x00000003) << 5))
#define BIT_GET_MEDIA_RATE_TRIGS(x)   ((u32)(((x >> 5) & 0x00000003)))
#define BIT_MASK_LOW_RATE_TRIGS       ((u32)0x00000003 << 3)            /*!< R/W 2'b01  Low rate rx ltr trigger point select: 0 plcp ready;1: rx a1 latch OK; 2: fcs ready.*/
#define BIT_LOW_RATE_TRIGS(x)         (((u32)((x) & 0x00000003) << 3))
#define BIT_GET_LOW_RATE_TRIGS(x)     ((u32)(((x >> 3) & 0x00000003)))
#define BIT_MASK_RX_EXHAUST_ID        ((u32)0x00000007 << 0)            /*!< R/W 3'b010  When rx page less than this threshold, release obff block rx.*/
#define BIT_RX_EXHAUST_ID(x)          (((u32)((x) & 0x00000007) << 0))
#define BIT_GET_RX_EXHAUST_ID(x)      ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_ANTTRN_CTR_V1
  * @brief
  * @{
  */
#define BIT_MASK_TRAIN_STA_ADDR_1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  The Address of the trained station. Only available when ADDR2_MATCH_EN = 1*/
#define BIT_TRAIN_STA_ADDR_1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_TRAIN_STA_ADDR_1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ANTTRN_CTR 1_V1
  * @brief
  * @{
  */
#define BIT_APPEND_MACID_IN_RESP_EN ((u32)0x00000001 << 18)          /*!< R/W 0x0  Whether to append MACID in the rx descriptor of rx response packet*/
#define BIT_ADDR2_MATCH_EN          ((u32)0x00000001 << 17)          /*!< R/W 0x0  Enable the comparison of ADDR2 for the rx packet..*/
#define BIT_ANTTRN_EN               ((u32)0x00000001 << 16)          /*!< R/W 0x0  Enable the antenna training function*/
#define BIT_MASK_TRAIN_STA_ADDR_2   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  The Address of the trained station. Only available when ADDR2_MATCH_EN = 1*/
#define BIT_TRAIN_STA_ADDR_2(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_TRAIN_STA_ADDR_2(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_WMAC_PKTCNT_RWD
  * @brief
  * @{
  */
#define BIT_MASK_PKTCNT_BSSIDMAP   ((u32)0x0000000F << 4)           /*!< R/W 0x0  To decide this counter is for which MBSSID (16組), default : 0 for counter 0 1 for counter 1 2 for counter 2 3 for counter 3 4 for counter 4 5 for counter 5 6 for counter 6 7 for counter 7*/
#define BIT_PKTCNT_BSSIDMAP(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_PKTCNT_BSSIDMAP(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_PKTCNT_CNTRST          ((u32)0x00000001 << 1)           /*!< R/W 0x0  Write 1 to reset Counter   after DRV read all counters , DRV set this bit and HW return 0 after reset*/
#define BIT_PKTCNT_CNTEN           ((u32)0x00000001 << 0)           /*!< R/W 0x0  1 : enable counter  0 : disable counter*/
/** @} */

/** @defgroup REG_WMAC_PKTCNT_CTRL
  * @brief
  * @{
  */
#define BIT_RESPONSE_FSM_IDLE        ((u32)0x00000001 << 26)          /*!< R 0x0  indicate txctl fsm is idle*/
#define BIT_MACTX_IDLE               ((u32)0x00000001 << 25)          /*!< R 0x0  indicate mactx fsm is idle*/
#define BIT_RX_IS_IDLE               ((u32)0x00000001 << 24)          /*!< R 0x0  indicate macrx is idle*/
#define BIT_WMAC_PKTCNT_TRST         ((u32)0x00000001 << 9)           /*!< R/W 0x0  Write 1 to reset all counter of all interface  DRV set this bit and HW return 0 after reset*/
#define BIT_WMAC_PKTCNT_FEN          ((u32)0x00000001 << 8)           /*!< R/W 0x0  Packet counter function enable*/
#define BIT_MASK_WMAC_PKTCNT_CFGAD   ((u32)0x000000FF << 0)           /*!< R/W 0x0  Packet counter configure register read/write address*/
#define BIT_WMAC_PKTCNT_CFGAD(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_WMAC_PKTCNT_CFGAD(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_WL2LTECOEX_INDIRECT_ACCESS_CTRL
  * @brief
  * @{
  */
#define BIT_LTECOEX_ACCESS_START    ((u32)0x00000001 << 31)           /*!< R/W/C   The bit is set for issue a read/write operation, so the corresponding I/O value must be written at the same time. i.e., read/write bit, dummy bits, LTECOEX register address, and LTECOEX write data when write. Note:  1. Before this bit set, FW has to check the ready bit is 1'b1. 2. When the ready_bit == 1, the ltecoex_access_start write 1 is valid. Otherwise, the write is invalid 3. The write 1 internally is a one cycle pulse when the write is valid*/
#define BIT_LTECOEX_WRITE_MODE      ((u32)0x00000001 << 30)           /*!< R/W   0: read operation 1: write operation Note: this field be protected not to be written when ready bit is 0*/
#define BIT_LTECOEX_READY_BIT       ((u32)0x00000001 << 29)           /*!< RO   When FW poll this bit is 1, FW can start to issue a ltecoex access command. Note This bit is 1 when  1. cpu reset release. 2. LTECOEX2WL_inf assert ready bit Otherwise, when LTECOEX_Access_Start  (bit 31) set as 1. this bit is cleared.*/
#define BIT_MASK_WRITE_BYTE_EN      ((u32)0x0000000F << 16)           /*!< R/W   Write byte enable when write operation*/
#define BIT_WRITE_BYTE_EN(x)        (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_WRITE_BYTE_EN(x)    ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LTECOEX_REG_ADDR   ((u32)0x0000FFFF << 0)            /*!< R/W   LTECOEX register address field Note: this field be protected not to be written when ready bit is 0*/
#define BIT_LTECOEX_REG_ADDR(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_LTECOEX_REG_ADDR(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_WL2LTECOEX_INDIRECT_ACCESS_WRITE_DATA
  * @brief
  * @{
  */
#define BIT_MASK_LTECOEX_W_DATA   ((u32)0xFFFFFFFF << 0)           /*!< R/W   LTECOEX write data Note: this field be protected not to be written when ready bit is 0*/
#define BIT_LTECOEX_W_DATA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_LTECOEX_W_DATA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_WL2LTECOEX_INDIRECT_ACCESS_READ_DATA
  * @brief
  * @{
  */
#define BIT_MASK_LTECOEX_R_DATA   ((u32)0xFFFFFFFF << 0)           /*!< R/W   LTECOEX read data Note: this field be protected not to be written when ready bit is 0*/
#define BIT_LTECOEX_R_DATA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_LTECOEX_R_DATA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_WMAC_FTM_CTL
  * @brief
  * @{
  */
#define BIT_MASK_RX_STOPRXDMA_RXPOINT   ((u32)0x0000FFFF << 16)           /*!< RO 0x0  When BIT_RXFTMREQ_STOPRXDMAEN =1 || BIT_RXFTM_STOPRXDMAEN = 1,  and display Rx point info by FTM or FTMREQ.  Unit is byte.(8703B only)*/
#define BIT_RX_STOPRXDMA_RXPOINT(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_RX_STOPRXDMA_RXPOINT(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_RXFTM_TXACK_SC              ((u32)0x00000001 << 6)            /*!< R/W 0x0  When HW receive FTM pkt, HW will use RX FTM SC as response ACK TXSC.*/
#define BIT_RXFTM_TXACK_BW              ((u32)0x00000001 << 5)            /*!< R/W 0x0  When HW receive FTM pkt, HW will use RX FTM BW as response ACK TXBW.*/
#define BIT_RXFTM_STOPRXDMAEN           ((u32)0x00000001 << 4)            /*!< R/W 0x0  If BIT_RXFTM_STOPRXDMAEN = 1 and fined FTM frame,  HW will stop RXDMA and display BIT_RX_STOP_RXDMA =1. (8703B only)*/
#define BIT_RXFTM_EN                    ((u32)0x00000001 << 3)            /*!< R/W 0x0  If BIT_FTM_TYPE = 1 && BIT_RXFTM_EN=1,   HW will parsing rx packet, to find FTM frame.*/
#define BIT_RXFTMREQ_STOPRXDMAEN        ((u32)0x00000001 << 2)            /*!< R/W 0x0  If BIT_RXFTMREQ_STOPRXDMAEN = 1 and fined FTM  request frame, HW will stop RXDMA and display BIT_RX_STOP_RXDMA =1. (8703B only)*/
#define BIT_RXFTMREQ_EN                 ((u32)0x00000001 << 1)            /*!< R/W 0x0  If BIT_FTM_TYPE = 1 && BIT_RXFTMREQ_EN=1,  HW will parsing rx packet, to find FTM request frame.*/
#define BIT_FTM_EN                      ((u32)0x00000001 << 0)            /*!< R/W 0x0  Fine timing measurement function; 0: Disable 1:enable*/
/** @} */

/** @defgroup REG_OFDM_CCK_LEN_MASK
  * @brief
  * @{
  */
#define BIT_MASK_R_OFDM_LEN_V1   ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  rx ofdm len over this len to drop pkt(not for ht/vht)*/
#define BIT_R_OFDM_LEN_V1(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_R_OFDM_LEN_V1(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_R_CCK_LEN       ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  rx cck len over this length to drop pkt*/
#define BIT_R_CCK_LEN(x)         (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_R_CCK_LEN(x)     ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_FA_FILTER1
  * @brief
  * @{
  */
#define BIT_MASK_R_WMAC_RXFIFO_FULL_TH   ((u32)0x000000FF << 24)           /*!< R/W 0x0  csi report mac pause bb almost full threshold*/
#define BIT_R_WMAC_RXFIFO_FULL_TH(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_R_WMAC_RXFIFO_FULL_TH(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_R_WMAC_SRCH_TXPRT_UA1        ((u32)0x00000001 << 20)           /*!< R/W 0x0  when this bit is set 1, use tx A1 to search txrpt when rx  ack/cts, when BIT_r_WMAC_SRCH_TXRPT_TYPE is set 0, BIT_r_WMAC_SRCH_TXRPT_UA1 should be set 1*/
#define BIT_R_WMAC_SRCH_TXRPT_TYPE       ((u32)0x00000001 << 19)           /*!< R/W 0x0  for rx ack/cts pkt not to search txrpt buffer macid*/
#define BIT_R_WMAC_SRCH_TXRPT_PERPKT     ((u32)0x00000001 << 17)           /*!< R/W 0x0  enable search txrpt buffer for macid every pkt*/
#define BIT_R_WMAC_SRCH_TXPRT_MID        ((u32)0x00000001 << 16)           /*!< R/W 0x0  enable search txrpt buffer for macid*/
#define BIT_R_WMAC_RX_PAUSE_EN           ((u32)0x00000001 << 15)           /*!< R/W 0x0  pause macrx*/
#define BIT_R_WMAC_TX_PAUSE_EN           ((u32)0x00000001 << 14)           /*!< R/W 0x0  pause mactx*/
#define BIT_R_WMAC_FIL_SECERR_V1         ((u32)0x00000001 << 13)           /*!< R/W 0x0  sec len error drop(sec len is zero)*/
#define BIT_R_WMAC_FIL_CTLPKTLEN_V1      ((u32)0x00000001 << 12)           /*!< R/W 0x0  drop the rx pkt if the rx ctrl pkt len large than r_WMAC_RX_FIL_LEN*/
#define BIT_R_WMAC_FIL_FCTYPE_V1         ((u32)0x00000001 << 11)           /*!< R/W 0x0  drop the ofdm pkt if the rx ofdm leg pkt fc type is 2'b11*/
#define BIT_R_WMAC_FIL_FCPROVER_V1       ((u32)0x00000001 << 10)           /*!< R/W 0x0  drop the ofdm pkt if the rx ofdm leg pkt fc version illegal*/
#define BIT_R_WMAC_CHK_OFDM_LEN_V1       ((u32)0x00000001 << 1)            /*!< R/W 0x0  enable to check ofdm len*/
#define BIT_R_WMAC_CHK_CCK_LEN_V1        ((u32)0x00000001 << 0)            /*!< R/W 0x0  enable to check rx cck len*/
/** @} */

/** @defgroup REG_FA_FILTER2
  * @brief
  * @{
  */
#define BIT_R_WMAC_RXHANG_EN         ((u32)0x00000001 << 31)          /*!< R/W 0x0  function enable of new deadlock condition*/
#define BIT_DEL_MESH_TYPE_V1         ((u32)0x00000001 << 17)          /*!< R/W 0x0  drop rx mesh type when BIT_r_WMAC_FIL_FCTYPE is 1*/
#define BIT_MASK_R_WMAC_RX_FIL_LEN   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  use with BIT_r_WMAC_FIL_CTLPKTLEN, control packet with length over this threshold will be dropped*/
#define BIT_R_WMAC_RX_FIL_LEN(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_R_WMAC_RX_FIL_LEN(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_NAN_FUN
  * @brief
  * @{
  */
#define BIT_MASK_R_WMAC_ATTRI_ID1        ((u32)0x000000FF << 24)           /*!< R/W 0x0  the NAN attribute whose ID is r_WMAC_ATTRI_ID1 will be written into NAN beacon report*/
#define BIT_R_WMAC_ATTRI_ID1(x)          (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_R_WMAC_ATTRI_ID1(x)      ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_R_WMAC_ATTRI_ID0        ((u32)0x000000FF << 16)           /*!< R/W 0x0  the NAN attribute whose ID is r_WMAC_ATTRI_ID0 will be written into NAN beacon report*/
#define BIT_R_WMAC_ATTRI_ID0(x)          (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_R_WMAC_ATTRI_ID0(x)      ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_R_WMAC_ATTRI_IDI_VLD    ((u32)0x0000001F << 8)            /*!< R/W 0x0  valid flag bitmap of r_WMAC_ATTRI_IDi*/
#define BIT_R_WMAC_ATTRI_IDI_VLD(x)      (((u32)((x) & 0x0000001F) << 8))
#define BIT_GET_R_WMAC_ATTRI_IDI_VLD(x)  ((u32)(((x >> 8) & 0x0000001F)))
#define BIT_MASK_R_TXRPT_NAN_ENTRY_NUM   ((u32)0x00000007 << 4)            /*!< R/W 0x0  number of NAN beacon report entry in txrptbuffer*/
#define BIT_R_TXRPT_NAN_ENTRY_NUM(x)     (((u32)((x) & 0x00000007) << 4))
#define BIT_GET_R_TXRPT_NAN_ENTRY_NUM(x) ((u32)(((x >> 4) & 0x00000007)))
#define BIT_MASK_R_NAN_ENTRY_SIZE        ((u32)0x00000007 << 1)            /*!< R/W 0x0  size of one NAN beacon report entry, unit is 8byte*/
#define BIT_R_NAN_ENTRY_SIZE(x)          (((u32)((x) & 0x00000007) << 1))
#define BIT_GET_R_NAN_ENTRY_SIZE(x)      ((u32)(((x >> 1) & 0x00000007)))
#define BIT_R_WMAC_RXNANPSR_EN           ((u32)0x00000001 << 0)            /*!< R/W 0x0  parse enable of rx NAN sync beacon*/
/** @} */

/** @defgroup REG_NAN_CTL
  * @brief
  * @{
  */
#define BIT_MASK_R_TXRPT_NAN_ENTRY_FLAG   ((u32)0x000000FF << 24)           /*!< R/W 0x0  indicate NAN beacon report(i) in txrptbuffer is valid, it is set by HW and clear by FW*/
#define BIT_R_TXRPT_NAN_ENTRY_FLAG(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_R_TXRPT_NAN_ENTRY_FLAG(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_R_WMAC_ATTRI_ID4         ((u32)0x000000FF << 16)           /*!< R/W 0x0  the NAN attribute whose ID is r_WMAC_ATTRI_ID4 will be written into NAN beacon report*/
#define BIT_R_WMAC_ATTRI_ID4(x)           (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_R_WMAC_ATTRI_ID4(x)       ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_R_WMAC_ATTRI_ID3         ((u32)0x000000FF << 8)            /*!< R/W 0x0  the NAN attribute whose ID is r_WMAC_ATTRI_ID3 will be written into NAN beacon report*/
#define BIT_R_WMAC_ATTRI_ID3(x)           (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_R_WMAC_ATTRI_ID3(x)       ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_R_WMAC_ATTRI_ID2         ((u32)0x000000FF << 0)            /*!< R/W 0x0  the NAN attribute whose ID is r_WMAC_ATTRI_ID2 will be written into NAN beacon report*/
#define BIT_R_WMAC_ATTRI_ID2(x)           (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_R_WMAC_ATTRI_ID2(x)       ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RX_NAN_ADDR_FILTER
  * @brief
  * @{
  */
#define BIT_R_RX_NAN_ADDR_FILTER_EN        ((u32)0x00000001 << 13)          /*!< R/W 0x0  enable of rx nan beacon address filter*/
#define BIT_MASK_R_NAN_START_ADDR_OFFSET   ((u32)0x00001FFF << 0)           /*!< R/W 0x0  Start offset Location of NAN beacon report FIFO. Unit: 8bytes*/
#define BIT_R_NAN_START_ADDR_OFFSET(x)     (((u32)((x) & 0x00001FFF) << 0))
#define BIT_GET_R_NAN_START_ADDR_OFFSET(x) ((u32)(((x >> 0) & 0x00001FFF)))
/** @} */

/** @defgroup REG_NAN_ADDR
  * @brief
  * @{
  */
#define BIT_MASK_R_RX_NAN_ADDR_FILTER   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  bitmap for rx nan beacon address filter*/
#define BIT_R_RX_NAN_ADDR_FILTER(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_R_RX_NAN_ADDR_FILTER(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_RXA1_MASK
  * @brief
  * @{
  */
#define BIT_MASK_R_RX_NAN_ADDR_FILTER   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  r_WMAC_RXA1_MASK, indicate the masked bits of rx A1*/
#define BIT_R_RX_NAN_ADDR_FILTER(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_R_RX_NAN_ADDR_FILTER(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_DUMP_FUNC
  * @brief
  * @{
  */
#define BIT_DMA_IQD_WROVER           ((u32)0x00000001 << 31)           /*!< R 0x0  dump signal addr has round up*/
#define BIT_MASK_DUMP_ADDR_LATCH     ((u32)0x0000FFFF << 15)           /*!< R 0x0  dump finish addr in txpktbuffer*/
#define BIT_DUMP_ADDR_LATCH(x)       (((u32)((x) & 0x0000FFFF) << 15))
#define BIT_GET_DUMP_ADDR_LATCH(x)   ((u32)(((x >> 15) & 0x0000FFFF)))
#define BIT_MASK_R_TRIG_TIME_SEL     ((u32)0x0000007F << 8)            /*!< R/W 0x0  dump ok time to finish dump signal(unit is 1us)*/
#define BIT_R_TRIG_TIME_SEL(x)       (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_R_TRIG_TIME_SEL(x)   ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_R_MAC_TRIG_SEL      ((u32)0x00000003 << 6)            /*!< R/W 0x0  dump bb ADC sel mac strigger even 2'b00 : rxpkt ok trig dump ok 2'b01 : rxpkt_fauil trig dump ok 2'b10 : rxpkt cca rise edge to trig dump ok*/
#define BIT_R_MAC_TRIG_SEL(x)        (((u32)((x) & 0x00000003) << 6))
#define BIT_GET_R_MAC_TRIG_SEL(x)    ((u32)(((x >> 6) & 0x00000003)))
#define BIT_R_MAC_TRIG_REG           ((u32)0x00000001 << 5)            /*!< R/W 0x0  dump bb ADC sel mac strigger even write this reg to 1 to trig dump finish*/
#define BIT_MASK_R_LEVEL_PULSE_SEL   ((u32)0x00000003 << 3)            /*!< R/W 0x0  if dump bb ADC signal : [3] for sel mac trigger event if dump mac dbg signal [4:3] : 2'b00 : level signal match [4:3] : 2'b01 : posedge match [4:3] : 2'b10 : negdge match*/
#define BIT_R_LEVEL_PULSE_SEL(x)     (((u32)((x) & 0x00000003) << 3))
#define BIT_GET_R_LEVEL_PULSE_SEL(x) ((u32)(((x >> 3) & 0x00000003)))
#define BIT_R_EN_LA_MAC              ((u32)0x00000001 << 2)            /*!< R/W 0x0  enable dump mac dbg signal*/
#define BIT_R_EN_IQDUMP              ((u32)0x00000001 << 1)            /*!< R/W 0x0  enable dump bb ADC signal*/
#define BIT_R_IQDATA_DUMP            ((u32)0x00000001 << 0)            /*!< R/W 0x0  enable data dump for txpktbuffer high 64K*/
/** @} */

/** @defgroup REG_MASK_LA_MAC
  * @brief
  * @{
  */
#define BIT_MASK_R_WMAC_MASK_LA_MAC   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  dump mac dbg signal mask bit(bit set to 1 is to check this bit)*/
#define BIT_R_WMAC_MASK_LA_MAC(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_R_WMAC_MASK_LA_MAC(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MATCH_REF_MAC
  * @brief
  * @{
  */
#define BIT_MASK_R_WMAC_MATCH_REF_MAC   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  for dump mac dbg signal  as the ref signal*/
#define BIT_R_WMAC_MATCH_REF_MAC(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_R_WMAC_MATCH_REF_MAC(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_LA_DUMP_FUNC_EXT
  * @brief
  * @{
  */
#define BIT_MASK_RX_BCN_TIMER                ((u32)0x0000FFFF << 16)           /*!< R 0x0  rx beacon is over,start to be timer*/
#define BIT_RX_BCN_TIMER(x)                  (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_RX_BCN_TIMER(x)              ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_R_LA_MAC_TIMEOUT_UNIT_SEL   ((u32)0x00000003 << 10)           /*!< R/W 0x0  used in dumping mac debug signal, time unit selector for timeout threshold,  2'b00-->1us,2'b01-->32us,2'b10-->1ms,2'b11-->RSVD*/
#define BIT_R_LA_MAC_TIMEOUT_UNIT_SEL(x)     (((u32)((x) & 0x00000003) << 10))
#define BIT_GET_R_LA_MAC_TIMEOUT_UNIT_SEL(x) ((u32)(((x >> 10) & 0x00000003)))
#define BIT_MASK_R_LA_MAC_TIMEOUT_VALUE      ((u32)0x0000003F << 4)            /*!< R/W 0x0  used in dumping mac debug signal, value of timeout threshold defined in 0x7CE[3],unit is selected by 0x7CE[11:10]*/
#define BIT_R_LA_MAC_TIMEOUT_VALUE(x)        (((u32)((x) & 0x0000003F) << 4))
#define BIT_GET_R_LA_MAC_TIMEOUT_VALUE(x)    ((u32)(((x >> 4) & 0x0000003F)))
#define BIT_R_LEVEL_PULSE_SEL_EXT            ((u32)0x00000001 << 3)            /*!< R/W 0x0  used in dumping mac debug signal, extended trigger condition selector 1 --> trigger condition is timeout of duration of MAC DEBUG signal keeping on reference value,reference value is set by 0x7C8[31:0], bit mask is set by 0x7C4[31:0] 0 --> trigger condition refers to 0x7C0[4:3]*/
#define BIT_MASK_R_TIME_UNIT_SEL             ((u32)0x00000007 << 0)            /*!< R/W 0x0  time unit of dumping ok time(0x7C0[14:8]) to finish dump signal, related with the frequency of dma_rdrdy(from BB)                             ------------------------------------------                             r_time_unit_sel  |  frequency of dma_rdrdy                             ------------------------------------------                             3'b000               |  80MHz                             3'b001               |  40MHz                             3'b010               |  20MHz                             3'b011               |  10MHz                             3'b100               |  5MHz                             3'b101               |  2.5MHz                             3'b110               |  1.25MHz*/
#define BIT_R_TIME_UNIT_SEL(x)               (((u32)((x) & 0x00000007) << 0))
#define BIT_GET_R_TIME_UNIT_SEL(x)           ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/*==========REG_PAGE7 Register Address Definition==========*/
#define REG_MACID1                                          0x700
#define REG_MACID1_1                                        0x704
#define REG_BSSID1                                          0x708
#define REG_BSSID1_1                                        0x70C
#define REG_BCN_PSR_RPT1                                    0x710
#define REG_ASSOCIATED_BFMEE_SEL                            0x714
#define REG_SND_PTCL_CTRL                                   0x718
#define REG_RX_CSI_RPT_INFO_H                               0x71C
#define REG_PWR_INT_CTRL                                    0x728
#define REG_RX_CSI_RPT_INFO_V1                              0x72C
#define REG_POWER_MGT_0_V1                                  0x730
#define REG_POWER_MGT_1_V1                                  0x734
#define REG_POWER_MGT_2_V1                                  0x738
#define REG_POWER_MGT_3_V1                                  0x73C
#define REG_PLCP_HEADER                                     0x740
#define REG_TXDRXDMONITOR                                   0x744
#define REG_TXDRXDMONITOR_CTL                               0x748
#define REG_WMAC_RTX_CTX_SUBTYPE_CFG                        0x750
#define REG_WMAC_SWAES_RD0_V1                               0x754
#define REG_WMAC_SWAES_RD1_V1                               0x758
#define REG_WMAC_SWAES_RD3_V1                               0x75C
#define REG_WMAC_SWAES_CFG                                  0x760
#define REG_BT_COEX_V2                                      0x762
#define REG_BT_COEX                                         0x764
#define REG_WLAN_ACT_MASK_CTRL                              0x768
#define REG_WLAN_ACT_MASK_CTRL_1                            0x76C
#define REG_BT_COEX_ENHANCED_INTR_CTRL                      0x76E
#define REG_BT_ENHANCED_CTRL0                               0x770
#define REG_BT_ENHANCED_CTRL1                               0x774
#define REG_BT_PROPRI                                       0x778
#define REG_BT_STATUS_REPORT_REGISTER                       0x77C
#define REG_BT_INTERRUPT_CONTROL_REGISTER                   0x780
#define REG_WLAN_REPORT_TIME_OUT_CONTROL_REGISTER           0x784
#define REG_BT_ISOLATION_TABLE_REGISTER_REGISTER            0x785
#define REG_BT_ISOLATION_TABLE_REGISTER_REGISTER_1          0x788
#define REG_BT_ISOLATION_TABLE_REGISTER_REGISTER_2          0x78C
#define REG_BT_INTERRUPT_STATUS_REGISTER                    0x78F
#define REG_BT_TDMA_TIME_REGISTER                           0x790
#define REG_BT_ACT_REGISTER                                 0x794
#define REG_LTR_IDLE_LATENCY_V2                             0x798
#define REG_LTR_ACTIVE_LATENCY_V2                           0x79C
#define REG_OBFF_CTRL                                       0x7A0
#define REG_LTR_CTRL                                        0x7A4
#define REG_LTR_CTRL2                                       0x7A8
#define REG_ANTTRN_CTR_V1                                   0x7B0
#define REG_ANTTRN_CTR 1_V1                                 0x7B4
#define REG_WMAC_PKTCNT_RWD                                 0x7B8
#define REG_WMAC_PKTCNT_CTRL                                0x7BC
#define REG_WL2LTECOEX_INDIRECT_ACCESS_CTRL                 0x7C0
#define REG_WL2LTECOEX_INDIRECT_ACCESS_WRITE_DATA           0x7C4
#define REG_WL2LTECOEX_INDIRECT_ACCESS_READ_DATA            0x7C8
#define REG_WMAC_FTM_CTL                                    0x7CC
#define REG_OFDM_CCK_LEN_MASK                               0x7D0
#define REG_FA_FILTER1                                      0x7D4
#define REG_FA_FILTER2                                      0x7D8
#define REG_NAN_FUN                                         0x7DC
#define REG_NAN_CTL                                         0x7E0
#define REG_RX_NAN_ADDR_FILTER                              0x7E4
#define REG_NAN_ADDR                                        0x7E8
#define REG_RXA1_MASK                                       0x7EC
#define REG_DUMP_FUNC                                       0x7F0
#define REG_MASK_LA_MAC                                     0x7F4
#define REG_MATCH_REF_MAC                                   0x7F8
#define REG_LA_DUMP_FUNC_EXT                                0x7FC

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