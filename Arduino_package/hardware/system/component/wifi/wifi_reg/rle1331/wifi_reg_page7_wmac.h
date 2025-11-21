#ifndef _RL6955_REG_PAGE7_WMAC_H_
#define _RL6955_REG_PAGE7_WMAC_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE7_WMAC
  * @brief REG_PAGE7_WMAC driver modules
  * @{
  */




/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE7_WMAC_Register_Definitions REG_PAGE7_WMAC Register Definitions
  * @{
  */

/** @defgroup REG_MACID1
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_MACID1_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  MAC Identification Number Register for port 1. relay mode as soft ap macid*/
#define BIT_WMAC_MACID1_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_WMAC_MACID1_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MACID1_1
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_MACID1_H   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  MAC Identification Number Register for port 1. relay mode as soft ap macid*/
#define BIT_WMAC_MACID1_H(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_WMAC_MACID1_H(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_WMAC_FSM_RESET
  * @brief
  * @{
  */
#define BIT_MACRX_RST          ((u32)0x00000001 << 5) /*!< WA0 0x0  write 1 to RESET FSM of macrx*/
#define BIT_MACTX_CTL_RST      ((u32)0x00000001 << 4) /*!< WA0 0x0  write 1 to RESET FSM of mactx_ctl*/
#define BIT_LPS_CTRL_POFF_RST  ((u32)0x00000001 << 3) /*!< WA0 0x0  write 1 to RESET FSM of wmac_tlps_ctrl_poff*/
#define BIT_TRXPTCL_RXTRIG_RST ((u32)0x00000001 << 2) /*!< WA0 0x0  write 1 to RESET FSM of wmac_trxptcl_rxtig*/
#define BIT_TRXPTCL_TXCTL_RST  ((u32)0x00000001 << 1) /*!< WA0 0x0  write 1 to RESET FSM of wmac_trxptcl_txctl*/
#define BIT_TRXPTCL_RESP_RST   ((u32)0x00000001 << 0) /*!< WA0 0x0  write 1 to RESET FSM of wmac_trxptcl_resp*/
/** @} */

/** @defgroup REG_CLM_NLM
  * @brief
  * @{
  */
#define BIT_MASK_CCA_IDUNMATCH_CNT   ((u32)0x0000FFFF << 16)           /*!< R 0x0  not my packet counter*/
#define BIT_CCA_IDUNMATCH_CNT(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_CCA_IDUNMATCH_CNT(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_IDUNMATCH_CNT_CLR        ((u32)0x00000001 << 1)            /*!< WA0 0x0  write 1 to reset cca_idunmatch_cnt*/
#define BIT_MACID_STATIC_SEL         ((u32)0x00000001 << 0)            /*!< R/W 0x0  1:statistic a1 match packet;0:statistic a1 match packet,my bss bc and mc packet*/
/** @} */

/** @defgroup REG_MACID2
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_MACID2_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  MAC Identification Number Register for port 2. relay mode, enable r_P2_WTNAP, as relay ap addr*/
#define BIT_WMAC_MACID2_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_WMAC_MACID2_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MACID2_1
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_MACID2_H   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  MAC Identification Number Register for port 2 relay mode, enable r_P2_WTNAP, as relay ap addr*/
#define BIT_WMAC_MACID2_H(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_WMAC_MACID2_H(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_SND_PTCL_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_NDP_TIMER          ((u32)0x000000FF << 24)           /*!< R/W 0x42  A timeout value for MAC to leave NDP_Rx_standby_state and go back to normal Rx mode. (unit: 2us)*/
#define BIT_WMAC_NDP_TIMER(x)            (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_WMAC_NDP_TIMER(x)        ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_WMAC_CHK_RPTPOLL_A2_DIS      ((u32)0x00000001 << 23)           /*!< R/W 0x0  1: For any A1-matched BF Rpt Poll, send back VHT-CB 0: If A1-matched BF Rpt Poll's A2 fails to match the previous receiving NDPA's A2, do not send VHT-CB*/
#define BIT_WMAC_CSI_CHKSUM_DIS          ((u32)0x00000001 << 14)           /*!< R/W 0x0  1:Disable check 16bit checksum value of csi report from BB   0:Enable check 16bit checksum value of csi report from BB*/
#define BIT_WMAC_USE_NSTS                ((u32)0x00000001 << 7)            /*!< R/W 0x1  1: use Nsts as Nr, 0: use register value as Nr*/
#define BIT_MASK_WMAC_DIS_VHT_PLCP_CHK   ((u32)0x00000003 << 5)            /*!< R/W 0x0  [6]:1: disable check vhtsigb crc [5]:1: disable check vhtsiga crc*/
#define BIT_WMAC_DIS_VHT_PLCP_CHK(x)     (((u32)((x) & 0x00000003) << 5))
#define BIT_GET_WMAC_DIS_VHT_PLCP_CHK(x) ((u32)(((x >> 5) & 0x00000003)))
#define BIT_WMAC_HT_NDPA_EN              ((u32)0x00000001 << 1)            /*!< R/W 0x0  Set to 1, MAC would inform BB of preparing to receive NDP if the received NDP Announcement MPDU is valid.*/
#define BIT_WMAC_VHT_NDPA_EN             ((u32)0x00000001 << 0)            /*!< R/W 0x0  Set to 1, MAC would inform BB of preparing to receive NDP if the received NDPA is valid.*/
/** @} */

/** @defgroup REG_BEAMFORM_STATUS
  * @brief
  * @{
  */
#define BIT_WMAC_CHECK_SOUNDING_SEQ ((u32)0x00000001 << 30) /*!< R/W 0x0  Set to 1,MAC would check sounding sequence number of received CSI report  and transmitted NDPA*/
/** @} */

/** @defgroup REG_ZB_STATISTIC_0
  * @brief
  * @{
  */
#define BIT_STATIS_ZB_RSTB ((u32)0x00000001 << 0) /*!< WA0 0x0  */
/** @} */

/** @defgroup REG_ZB_STATISTIC_1
  * @brief
  * @{
  */
#define BIT_MASK_STATIS_ZG_L   ((u32)0xFFFFFFFF << 0)           /*!< R   for statistic*/
#define BIT_STATIS_ZG_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_STATIS_ZG_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ZB_STATISTIC_2
  * @brief
  * @{
  */
#define BIT_MASK_STATIS_ZG_H   ((u32)0xFFFFFFFF << 0)           /*!< R   for statistic*/
#define BIT_STATIS_ZG_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_STATIS_ZG_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ZB_COEX_TABLE_1
  * @brief
  * @{
  */
#define BIT_MASK_ZB_COEX_TABLE_1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  coexistence table between WLAN and Zigbee,  selected by BIT_COEX_TABLE_SEL = 0*/
#define BIT_ZB_COEX_TABLE_1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_ZB_COEX_TABLE_1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ZB_COEX_TABLE_2
  * @brief
  * @{
  */
#define BIT_MASK_ZB_COEX_TABLE_2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  coexistence table between WLAN and Zigbee,  selected by BIT_COEX_TABLE_SEL = 1*/
#define BIT_ZB_COEX_TABLE_2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_ZB_COEX_TABLE_2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ZB_BREAK_TABLE
  * @brief
  * @{
  */
#define BIT_MASK_ZB_BREAK_TABLE_H   ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  Table used to break ZB activity, when new WLAN request is coming and ZB is on transmitting or receiving*/
#define BIT_ZB_BREAK_TABLE_H(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_ZB_BREAK_TABLE_H(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_ZB_BREAK_TABLE_L   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  Table used to break WLAN activity, when new ZB request is coming and WLAN is on transmitting or receiving*/
#define BIT_ZB_BREAK_TABLE_L(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_ZB_BREAK_TABLE_L(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_EXT_ZB_DETEC_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_ZB_TRX_DETECT   ((u32)0x000000FF << 24)           /*!< R/W 0x40  Valid if BIT_ZIGBEE_MODE = 1 & BIT_EXT_ZIGBEE_MODE = 0 (external mode, directional PRIORITY)  After ZB_PRI_DETECT_TIME duration, if ZB_PRIORITY is low or goes low during ZB_TRX_INIT_DETECT_TIME, Zigbee will receive packets; otherwise, if ZG_PRIORITY is high or goes high, ZB will TX data. Unit 1us.*/
#define BIT_ZB_TRX_DETECT(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_ZB_TRX_DETECT(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_ZB_PRI_DETECT   ((u32)0x000000FF << 16)           /*!< R/W 0xC8  Valid if BIT_ZIGBEE_MODE = 1 & BIT_EXT_ZIGBEE_MODE = 0 (external mode, directional PRIORITY)  After ZB_REQUEST asserting, if ZG_PRIORITY is asserted within this ZB_PRI_DETECT_TIME duration, ZG will initiate high priority activities; otherwise, if ZB_PRIORITY is not asserted within this duration, it would be low priority activities. Units 1us. (0-255us)*/
#define BIT_ZB_PRI_DETECT(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_ZB_PRI_DETECT(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_ZB_CNT_THR      ((u32)0x000000FF << 8)            /*!< R/W 0x0  ZB count threshold, unit: us*/
#define BIT_ZB_CNT_THR(x)        (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_ZB_CNT_THR(x)    ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_ZB_ARB_TIME     ((u32)0x000000FF << 0)            /*!< R/W 0x0  8 bit timer register : Arbitration window of ZB trx request (unit: us)*/
#define BIT_ZB_ARB_TIME(x)       (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_ZB_ARB_TIME(x)   ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RADAR_COEX
  * @brief
  * @{
  */
#define BIT_MASK_RADAR_BT_COEX_TABLE    ((u32)0x000000FF << 24)           /*!< R/W 0x0  COEX table of radar & BT, radar force wl_tx = 1, wl_pri = 1*/
#define BIT_RADAR_BT_COEX_TABLE(x)      (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_RADAR_BT_COEX_TABLE(x)  ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_RADAR_BT_BREAK_TABLE   ((u32)0x000000FF << 16)           /*!< R/W 0x0  BREAK table of radar & BT, radar force wl_tx = 1, wl_pri = 1*/
#define BIT_RADAR_BT_BREAK_TABLE(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_RADAR_BT_BREAK_TABLE(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_RADAR_ZB_COEX_TABLE    ((u32)0x000000FF << 8)            /*!< R/W 0x0  COEX table of radar & ZB, radar force wl_tx = 1, wl_pri = 1*/
#define BIT_RADAR_ZB_COEX_TABLE(x)      (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_RADAR_ZB_COEX_TABLE(x)  ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_RADAR_ZB_BREAK_TABLE   ((u32)0x000000FF << 0)            /*!< R/W 0x0  BREAK table of radar & ZB, radar force wl_tx = 1, wl_pri = 1*/
#define BIT_RADAR_ZB_BREAK_TABLE(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_RADAR_ZB_BREAK_TABLE(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BT_COEX_SW_CFG
  * @brief
  * @{
  */
#define BIT_GNT_WL_RX_SW        ((u32)0x00000001 << 17) /*!< R/W 0x0  SW control GNT_WL_RX*/
#define BIT_GNT_WL_RX_SW_EN     ((u32)0x00000001 << 16) /*!< R/W 0x0  SW control GNT_WL_RX enable*/
#define BIT_GNT_WL_TX_SW        ((u32)0x00000001 << 15) /*!< R/W 0x0  SW control GNT_WL_TX*/
#define BIT_GNT_WL_TX_SW_EN     ((u32)0x00000001 << 14) /*!< R/W 0x0  SW control GNT_WL_TX enable*/
#define BIT_GNT_WL_SW           ((u32)0x00000001 << 13) /*!< R/W 0x0  SW control GNT_WL*/
#define BIT_GNT_WL_SW_EN        ((u32)0x00000001 << 12) /*!< R/W 0x0  SW control GNT_WL enable*/
#define BIT_GNT_WL_RFC_SW       ((u32)0x00000001 << 11) /*!< R/W 0x0  SW control GNT_WL_RFC*/
#define BIT_GNT_WL_RFC_SW_EN    ((u32)0x00000001 << 10) /*!< R/W 0x0  SW control GNT_WL_RFC enable*/
#define BIT_GNT_RADAR_SW        ((u32)0x00000001 << 9)  /*!< R/W 0x0  SW control GNT_RADAR*/
#define BIT_GNT_RADAR_SW_EN     ((u32)0x00000001 << 8)  /*!< R/W 0x0  SW control GNT_RADAR enable*/
#define BIT_GNT_RADAR_RFC_SW    ((u32)0x00000001 << 7)  /*!< R/W 0x0  SW control GNT_RADAR_RFC*/
#define BIT_GNT_RADAR_RFC_SW_EN ((u32)0x00000001 << 6)  /*!< R/W 0x0  SW control GNT_RADAR_RFC enable*/
#define BIT_GNT_BT_RX_SW        ((u32)0x00000001 << 5)  /*!< R/W 0x0  SW control GNT_BT_RX*/
#define BIT_GNT_BT_RX_SW_EN     ((u32)0x00000001 << 4)  /*!< R/W 0x0  SW control GNT_BT_RX enable*/
#define BIT_GNT_BT_TX_SW        ((u32)0x00000001 << 3)  /*!< R/W 0x0  SW control GNT_BT_TX*/
#define BIT_GNT_BT_TX_SW_EN     ((u32)0x00000001 << 2)  /*!< R/W 0x0  SW control GNT_BT_TX enable*/
#define BIT_GNT_BT_AFE_SW       ((u32)0x00000001 << 1)  /*!< R/W 0x1  SW control BT AFE*/
#define BIT_GNT_BT_AFE_SW_EN    ((u32)0x00000001 << 0)  /*!< R/W 0x1  SW control BT AFE enable*/
/** @} */

/** @defgroup REG_WMAC_SWAES_CFG
  * @brief
  * @{
  */
#define BIT_BTCOEX_SW_RST      ((u32)0x00000001 << 31)           /*!< R/W 0x0  */
#define BIT_GNT_BOTH_POL       ((u32)0x00000001 << 28)           /*!< R/W 0x0  grant both choose GNT_BT  polarity: 0 : deassert GNT_BT  signal as PTA grant both WiFI and BT. 1 : assert GNT_BT signal as PTA grant both WiFi and BT.*/
#define BIT_BT_ARB_INST_EN     ((u32)0x00000001 << 24)           /*!< R/W 0x0  1: enable GNT_BT_BYPASS_PRIORITY  0 : disable*/
#define BIT_MASK_BT_ARB_TIME   ((u32)0x000000FF << 16)           /*!< R/W 0x0  8 bit timer register : Arbitration window of bt trx request ( in the unit of us)*/
#define BIT_BT_ARB_TIME(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_BT_ARB_TIME(x) ((u32)(((x >> 16) & 0x000000FF)))
/** @} */

/** @defgroup REG_BT_COEX_ENH
  * @brief
  * @{
  */
#define BIT_ZIGBEE_EN         ((u32)0x00000001 << 31)          /*!< R/W 0x0  Enable ZigBee function*/
#define BIT_ZIGBEE_MODE       ((u32)0x00000001 << 30)          /*!< R/W 0x0  0: SOC 1: external*/
#define BIT_EXT_ZIGBEE_MODE   ((u32)0x00000001 << 29)          /*!< R/W 0x0  The mode of external ZigBee 1: static PRIORITY 0: directional PRIORITY*/
#define BIT_COEX_TABLE_SEL    ((u32)0x00000001 << 28)          /*!< R/W 0x1  Select coexistence table for WLAN & ZB 0: BIT_COEX_TABLE_WL_ZB_1 1: BIT_COEX_TABLE_WL_ZB_2*/
#define BIT_EXT_ZB_GNT_POLAR  ((u32)0x00000001 << 27)          /*!< R/W 0x1  Select the polar of ZB_GRANT, for extarnal ZB 0: low active 1: high active*/
#define BIT_ZB_ARB_INST_EN    ((u32)0x00000001 << 26)          /*!< R/W 0x0  1: enable the time limit of ZigBee request (zb_pri | zb_rx | zb_tx), PTA is valid during ( <=BIT_ZB_ARB_TIME) 0: disable  Co-work with BIT_ZB_ARB_TIME*/
#define BIT_ZB_CNT_THREN      ((u32)0x00000001 << 25)          /*!< R/W 0x0  ZB count threshold enable, for statistics co-work with BIT_ZB_CNT_THR*/
#define BIT_ZB_STATISTIC_EN   ((u32)0x00000001 << 24)          /*!< R/W 0x0  enable statistic of ZB*/
#define BIT_GNT_ZB_BB_SW_EN   ((u32)0x00000001 << 23)          /*!< R/W 0x0  Enable SW control gnt_zb_bb*/
#define BIT_GNT_ZB_BB_SW      ((u32)0x00000001 << 22)          /*!< R/W 0x0  SW value*/
#define BIT_GNT_ZB_RFC_SW_EN  ((u32)0x00000001 << 21)          /*!< R/W 0x0  Enable SW control gnt_zb_rfc*/
#define BIT_GNT_ZB_RFC_SW     ((u32)0x00000001 << 20)          /*!< R/W 0x0  SW value*/
#define BIT_GNT_ZB_EXT_SW_EN  ((u32)0x00000001 << 19)          /*!< R/W 0x0  Enable SW control gnt_zb_o of external ZigBee*/
#define BIT_GNT_ZB_EXT_SW     ((u32)0x00000001 << 18)          /*!< R/W 0x0  SW value,  external ZigBee*/
#define BIT_EXT_ZB_REQ_POLAR  ((u32)0x00000001 << 17)          /*!< R/W 0x1  Select the polar of ZB_REQUEST, for static mode external ZB 0: low active 1: high active*/
#define BIT_DIS_BT_DONT_CARE  ((u32)0x00000001 << 16)          /*!< R/W 0x1  */
#define BIT_DIS_ZB_DONT_CARE  ((u32)0x00000001 << 15)          /*!< R/W 0x1  */
#define BIT_BTG_LNA1_GAIN_SEL ((u32)0x00000001 << 14)          /*!< R/W 0x1  */
#define BIT_GNT_BT_RFC_SW     ((u32)0x00000001 << 12)          /*!< R/W 0x1  SW control BT RF*/
#define BIT_GNT_BT_RFC_SW_EN  ((u32)0x00000001 << 11)          /*!< R/W 0x1  SW control BT RF enable*/
#define BIT_GNT_BT_BB_SW      ((u32)0x00000001 << 10)          /*!< R/W 0x1  SW control BT baseband*/
#define BIT_GNT_BT_BB_SW_EN   ((u32)0x00000001 << 9)           /*!< R/W 0x1  SW control BT baseband enable*/
#define BIT_BT_CNT_THREN      ((u32)0x00000001 << 8)           /*!< R/W 0x0  BT count threshold enable*/
#define BIT_MASK_BT_CNT_THR   ((u32)0x000000FF << 0)           /*!< R/W 0x0  BT count threshold*/
#define BIT_BT_CNT_THR(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_BT_CNT_THR(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_WLAN_ACT_MASK_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_PTA_GNT_INFO           ((u32)0x00001FFF << 19)           /*!< R 0x0  [0]: gnt_wl [1]: gnt_bt_bb [2]: gnt_bt_rfc [3]: gnt_zb_bb [4]: gnt_zb_rfc [5]: gnt_wl_tx [6]: gnt_wl_rx [7]: gnt_bt_tx [8]: gnt_bt_rx [9]: gnt_bt_afe [10]: gnt_wl_rfc [11]: gnt_radar [12]: gnt_radar_rfc*/
#define BIT_PTA_GNT_INFO(x)             (((u32)((x) & 0x00001FFF) << 19))
#define BIT_GET_PTA_GNT_INFO(x)         ((u32)(((x >> 19) & 0x00001FFF)))
#define BIT_MASK_WLAN_ACT_MASK_CTRL_L   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  [15:8]: WLAN will reserve channel for BT during MASK OFF duration. Unit 0.625ms [7:0]: WLAN can block BT during MASK On duration. Unit 0.625ms*/
#define BIT_WLAN_ACT_MASK_CTRL_L(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_WLAN_ACT_MASK_CTRL_L(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_WLAN_ACT_MASK_CTRL_1
  * @brief
  * @{
  */
#define BIT_STATIS_BT_RSTB              ((u16)0x00000001 << 12)          /*!< WA0 0x0  */
#define BIT_WLRX_TER_BY_CTL             ((u16)0x00000001 << 11)          /*!< R/W 0x0  When wlan receive a control packet without fit address, whether the signal indicating wlan rx can be terminated as soon as the address check finish is not only controlled by r_WLRX_TER_BY_AD, but also should be refereed to this bit.  1: enable; 0: disable*/
#define BIT_WLRX_TER_BY_AD              ((u16)0x00000001 << 10)          /*!< R/W 0x0  When wlan receive the packet without fit address, the signal indicating wlan rx can be terminated as soon as the address check finish. This feature can be enabled by this bit.  1: en*/
#define BIT_MASK_WLAN_ACT_MASK_CTRL_H   ((u16)0x000003FF << 0)           /*!< R/W 0x0  [9]: Antenna diversity for 2 antenna mode: MAC_ANT_SEL = GNT_BT ^ ANT_DIVERDITY_SEL [8]: Enable the control of antenna selection through GNT_BT:GNT_BT=1: ANT_SEL for BT device; GNT_BT=0: ANT_SEL for WL device. [7:3]:RSVD [2]:When WLACT_LOW_GNTWL_EN = 1, the TRX of WLAN are blocked according to the BTCOEX table arbitration during MASK OFF duration. WLACT_LOW_GNTWL_EN = 0, the TRX of WLAN are paused during MASK OFF duration.. [1]:When WLACT_HIGH_GNTBT_EN = 1, the TRX of WLAN are blocked according to the BTCOEX table arbitration during MASK ON duration. When WLACT_HIGH_ GNTBT_EN = 0, the TRX of WLAN are not paused during MASK OFF duration. [0]:When NAV update is beyond this value, then NAV update is aborted. When this field is 0x00, NAV_UPPER function is disable. The unit is 128us.*/
#define BIT_WLAN_ACT_MASK_CTRL_H(x)     (((u16)((x) & 0x000003FF) << 0))
#define BIT_GET_WLAN_ACT_MASK_CTRL_H(x) ((u16)(((x >> 0) & 0x000003FF)))
/** @} */

/** @defgroup REG_BT_COEX_ENHANCED_INTR_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_BT_STAT_DELAY        ((u16)0x0000000F << 12)           /*!< R/W 0x0  For CSR, BT_PRI and BT_STAT go high form low at the same time. Thus, BT_STAT  need delay BT_STAT_DELAY time to trigger hardware. Unit: 1us*/
#define BIT_BT_STAT_DELAY(x)          (((u16)((x) & 0x0000000F) << 12))
#define BIT_GET_BT_STAT_DELAY(x)      ((u16)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_BT_TRX_INIT_DETECT   ((u16)0x0000000F << 8)            /*!< R/W 0x0  After BT_PRI asserting for BT_TRX_INIT_DETECT us,  if BT_STAT is low, then BT will receive packets; otherwise, if BT goes high, BT will TX data. Unit 4us.*/
#define BIT_BT_TRX_INIT_DETECT(x)     (((u16)((x) & 0x0000000F) << 8))
#define BIT_GET_BT_TRX_INIT_DETECT(x) ((u16)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_BT_PRI_DETECT_TO     ((u16)0x0000000F << 4)            /*!< R/W 0x0  After BT_PRI asserting, if BT_STAT is asserted within this TO duration, BT will initiate high priority activities; otherwise, if BT_STAT is not asserted within this duration, it would be low priority activities. Units 1us.*/
#define BIT_BT_PRI_DETECT_TO(x)       (((u16)((x) & 0x0000000F) << 4))
#define BIT_GET_BT_PRI_DETECT_TO(x)   ((u16)(((x >> 4) & 0x0000000F)))
#define BIT_GRANTALL_WLMASK           ((u16)0x00000001 << 3)            /*!< R/W 0x0  grant all mask*/
#define BIT_STATIS_BT_EN              ((u16)0x00000001 << 2)            /*!< R/W 0x0  When this bit is set, the BT_ACT_STATISTICS counters starts counting*/
#define BIT_EN_WL_ACT_MASK            ((u16)0x00000001 << 1)            /*!< R/W 0x0  Enable WLAN_ACT Mask Function (related to 0x768h-0x76Dh)*/
#define BIT_ENHBT                     ((u16)0x00000001 << 0)            /*!< R/W 0x0  Enable Enhanced BT Interface (we suggest to use with BT mode 2)*/
/** @} */

/** @defgroup REG_BT_ENHANCED_CTRL0
  * @brief
  * @{
  */
#define BIT_MASK_STATIS_BT0   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  */
#define BIT_STATIS_BT0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_STATIS_BT0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BT_ENHANCED_CTRL1
  * @brief
  * @{
  */
#define BIT_MASK_STATIS_BT1   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  */
#define BIT_STATIS_BT1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_STATIS_BT1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BT_PROPRI
  * @brief
  * @{
  */
#define BIT_MASK_BT_CMD_RPT    ((u32)0x0000FFFF << 16)           /*!< R 0x0  */
#define BIT_BT_CMD_RPT(x)      (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_BT_CMD_RPT(x)  ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_RPT_FROM_BT   ((u32)0x000000FF << 8)            /*!< R 0x0  */
#define BIT_RPT_FROM_BT(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_RPT_FROM_BT(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_BT_PROPRI     ((u32)0x000000FF << 0)            /*!< R/W 0x0  [7:6]: When EN_BT_PROFILE_OR_HID is set "1", hardware also need to checkthis value to trigger an interrupt. 0: default, TX and RX; 1: TX; 2: RX; 3: Reserved [5]: When the control of TDMA mode is firmware and firmware also receive signal that NULL packet for BT had sent, firmware can fill this bit to notify HW PTA to pull WLAN_ACT to low and the interval is Tbt [4]: 0: default, PTA TDMA mode is hardware mode. 1: enable firmware mode. [3]:0: default, disable PTA TDMA mode; 1: enable TDMA mode: a. WLAN_ACT default is high. b. Hardware mode: When NULL packet for BT had sent, hardware will notify PTA to start TDMA mode. Firmware mode: When NULL packet for BT had sent, hardware will trigger an interrupt to notify firmware. Then, firmware need to set TDMA_BT_START_NOTIFY to notify PTA to start TDMA mode [2]: 0: default, no matter which WLAN_ACT is high or low, PTA doesn't execute co-exist table scheme; 1: enable, When WLAN_ACT is high, PTA execute xo-exist table scheme [1]: Enable GPIO2 and GPIO3 exchange. (Note: need to enable mode2 and enhance 3 wire) If Enable RTK BT mode, set this bit to 1 to disable granting to BT device when arbitration [0]: Enable RTK BT mode*/
#define BIT_BT_PROPRI(x)       (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_BT_PROPRI(x)   ((u32)(((x >> 0) & 0x000000FF)))
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
#define BIT_MASK_BT_PRETECT_STATUS   ((u32)0x000000FF << 8)            /*!< R 0x0  When WLAN received CMD_ID 0x0, it will recorder to this*/
#define BIT_BT_PRETECT_STATUS(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_BT_PRETECT_STATUS(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_CMD_INFO            ((u32)0x000000FF << 0)            /*!< R 0x0  command information from BT*/
#define BIT_CMD_INFO(x)              (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_CMD_INFO(x)          ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BT_INTERRUPT_CONTROL_REGISTER
  * @brief
  * @{
  */
#define BIT_MASK_BT_FUNC_EN      ((u32)0x0000007F << 25)           /*!< R/W 0x0  [31]: When firmware had prepared packet to send to BT, it need to set this bit to notify hardware that it can transmit. 0: There isn't a valid packet in register" WLAN_RPT_ PKT". 1: There is a valid packet in register" WLAN_RPT_ PKT". [30]: Enable two interrupt:1) PTA sent the report packet successfully; 2) PTA sent a query packet 0: Disable 1: Enable [29]: When MAC had sent NULL packet for BT and firmware also set nav_for_bt bit, hardware triggers an interrupt to notify firmware. 0: Disable 1: Enable [28]: When WLAN receive cmd_id "0", hardware trigger an interrupt to notify firmware. 0: Disable 1: Enable [27]: When WLAN received the packet including BT Power and check register "BT_STATUS_RPT", if data contents aren't the same, hardware can trigger an interrupt to notify firmware. 0: Disable 1: Enable [26]: When WLAN received the packet including BT channel number, hardware can trigger an interrupt to notify firmware. 0: Disable 1: Enable [25]: When WLAN received the packet including that BT had multi-slots, hardware can trigger an interrupt to notify firmware. 0: Disable 1: Enable*/
#define BIT_BT_FUNC_EN(x)        (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_BT_FUNC_EN(x)    ((u32)(((x >> 25) & 0x0000007F)))
#define BIT_WLAN_RPT_NOTIFY      ((u32)0x00000001 << 24)           /*!< R/W/ES 0x0  [24]:Enable two interrupt 1) When WLAN received the packet including that WLAN specific profile and check register "BT_STATUS_RPT", if data contents aren't the same, hardware can trigger an interrupt to notify firmware. 2) When WLAN received the report packet including HID information, hardware will trigger an interrupt to notify firmware. 0: Disable 1: Enable*/
#define BIT_MASK_WLAN_RPT_DATA   ((u32)0x000000FF << 16)           /*!< R/W/ES 0x0  Data contents, When the report packet had sent, hardware will clear this register.*/
#define BIT_WLAN_RPT_DATA(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_WLAN_RPT_DATA(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_TO_BT_CMDID     ((u32)0x000000FF << 8)            /*!< R/W 0x0  Command id: 0x80~FF*/
#define BIT_TO_BT_CMDID(x)       (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_TO_BT_CMDID(x)   ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_BT_DATA         ((u32)0x000000FF << 0)            /*!< R 0x0  When WLAN received the packet BT sent, hardware will place data to this register in addition to CMD_ID 0x0 ~ 0x3.*/
#define BIT_BT_DATA(x)           (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_BT_DATA(x)       ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_WLAN_REPORT_TIME_OUT_CONTROL_REGISTER
  * @brief
  * @{
  */
#define BIT_MASK_CHAN_TABLE0   ((u32)0x007FFFFF << 9)           /*!< R/W 0x0  0: leave PTA 1: enter PTA*/
#define BIT_CHAN_TABLE0(x)     (((u32)((x) & 0x007FFFFF) << 9))
#define BIT_GET_CHAN_TABLE0(x) ((u32)(((x >> 9) & 0x007FFFFF)))
#define BIT_ISO_EN             ((u32)0x00000001 << 8)           /*!< R/W 0x0  Isolation table enable bit. 0: disable 1: enable*/
#define BIT_MASK_BT_RPT_TO     ((u32)0x000000FF << 0)           /*!< R/W 0x0  When WLANＨW received query packet, HW timer counts. If timer equals to WLAN_RPT_TO and HW can"t send packet, it will give up query packet at this time. When BT sent another query packet, WLAN HW need to send the previous packet and it shouldn't trigger an interrupt to firmware. Unit: 4us.*/
#define BIT_BT_RPT_TO(x)       (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_BT_RPT_TO(x)   ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BT_ISOLATION_TABLE_REGISTER_REGISTER_1
  * @brief
  * @{
  */
#define BIT_MASK_CHAN_TABLE1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  0: leave PTA 1: enter PTA*/
#define BIT_CHAN_TABLE1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_CHAN_TABLE1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BT_ISOLATION_TABLE_REGISTER_REGISTER_2
  * @brief
  * @{
  */
#define BIT_BT_ISR_STS7        ((u32)0x00000001 << 31)          /*!< RW1C 0x0  When WLAN received the report packet including HID information, hardware will trigger an interrupt to notify firmware*/
#define BIT_BT_ISR_STS6        ((u32)0x00000001 << 30)          /*!< RW1C 0x0  When WLAN received a query packet, hardware triggers an interrupt to notify firmware*/
#define BIT_BT_ISR_STS5        ((u32)0x00000001 << 29)          /*!< RW1C 0x0  When MAC had sent NULL packet for BT and firmware also set nav_for_bt bit, hardware triggers an interrupt to notify firmware*/
#define BIT_BT_ISR_STS4        ((u32)0x00000001 << 28)          /*!< RW1C 0x0  When PTA sent the report packet successfully, hardware triggers an interrupt to notify firmware.*/
#define BIT_BT_ISR_STS3        ((u32)0x00000001 << 27)          /*!< RW1C 0x0  When WLAN received the packet including BT Power and check register "BT_STATUS_RPT", if data contents aren't the same, hardware can trigger an interrupt to notify firmware*/
#define BIT_BT_ISR_STS2        ((u32)0x00000001 << 26)          /*!< RW1C 0x0  When WLAN received the packet including BT channel number, hardware can trigger an interrupt to notify firmware.*/
#define BIT_BT_ISR_STS1        ((u32)0x00000001 << 25)          /*!< RW1C 0x0  When WLAN received the packet including that BT had multi-slots, hardware can trigger an interrupt to notify firmware*/
#define BIT_BT_ISR_STS0        ((u32)0x00000001 << 24)          /*!< RW1C 0x0  When WLAN received the packet including that WLAN specific profile and check register "BT_STATUS_RPT", if data contents aren't the same, hardware can trigger an interrupt to notify firmware.*/
#define BIT_MASK_CHAN_TABLE2   ((u32)0x00FFFFFF << 0)           /*!< R/W 0x0  0: leave PTA 1: enter PTA*/
#define BIT_CHAN_TABLE2(x)     (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_CHAN_TABLE2(x) ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_BT_TDMA_TIME_REGISTER
  * @brief
  * @{
  */
#define BIT_MASK_BT_TIME   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  [31:6]: The time is that WLAN_ACT is low. Unit: us [5:0]: When wifi detected the raising edge of BT report packet, wifi need to counter BT_RPT_SAMPLE_RATE. Then hw could detect which is high or low. Uint: 20 ns*/
#define BIT_BT_TIME(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BT_TIME(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BT_ACT_REGISTER
  * @brief
  * @{
  */
#define BIT_BT_BLE_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  Decide the GNT_BT_TX / RX  0: GNT_BT_TX = GNT_BT & BT_TX ;  GNT_BT_RX = GNT_BT & BT_RX 1: GNT_BT_TX = GNT_BT & (BT_TX | BT_BLE) ;  GNT_BT_RX = GNT_BT & (BT_RX | BT_BLE)*/
#define BIT_MASK_BT_EISR_EN   ((u32)0x000000FF << 16)           /*!< R/W 0x0  BT eisr enable*/
#define BIT_BT_EISR_EN(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_BT_EISR_EN(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_BT_EISR_STS7      ((u32)0x00000001 << 15)           /*!< RW1C 0x0  */
#define BIT_BT_EISR_STS6      ((u32)0x00000001 << 14)           /*!< RW1C 0x0  */
#define BIT_BT_EISR_STS5      ((u32)0x00000001 << 13)           /*!< RW1C 0x0  */
#define BIT_BT_EISR_STS4      ((u32)0x00000001 << 12)           /*!< RW1C 0x0  */
#define BIT_BT_EISR_STS3      ((u32)0x00000001 << 11)           /*!< RW1C 0x0  */
#define BIT_BT_EISR_STS2      ((u32)0x00000001 << 10)           /*!< RW1C 0x0  [10]: When BT_ACT signal is falling edge, it will trigger an interrupt.*/
#define BIT_BT_EISR_STS1      ((u32)0x00000001 << 9)            /*!< RW1C 0x0  [9]: When BT_ACT signal is raising edge, it will trigger an interrupt*/
#define BIT_BT_EISR_STS0      ((u32)0x00000001 << 8)            /*!< RW1C 0x0  [8]: When BT_TIME expired, it will trigger an interrupt.*/
#define BIT_MASK_BT_CH        ((u32)0x0000007F << 0)            /*!< R 0x7f  When hardware receive cm_id "1", it will recorder to this.*/
#define BIT_BT_CH(x)          (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_BT_CH(x)      ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_VENDOR_CFG
  * @brief
  * @{
  */
#define BIT_RX_VENDOR_ADV_EN     ((u32)0x00000001 << 25)           /*!< R/W 0x0  */
#define BIT_TX_VENDOR_ADV_EN     ((u32)0x00000001 << 24)           /*!< R/W 0x0  */
#define BIT_MASK_WMAC_OPT_SIG2   ((u32)0x000000FF << 16)           /*!< R/W 0x0  */
#define BIT_WMAC_OPT_SIG2(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_WMAC_OPT_SIG2(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_WMAC_OPT_SIG1   ((u32)0x000000FF << 8)            /*!< R/W 0x0  */
#define BIT_WMAC_OPT_SIG1(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_WMAC_OPT_SIG1(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_WMAC_INI_SIG    ((u32)0x000000FF << 0)            /*!< R/W 0x1  */
#define BIT_WMAC_INI_SIG(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_WMAC_INI_SIG(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_VENDOR_TSFT_CTL
  * @brief
  * @{
  */
#define BIT_RX_VENDOR_TSFT_EN          ((u32)0x00000001 << 26)           /*!< R/W 0x0  vendor tsft emable for rx*/
#define BIT_MASK_RX_VENDOR_NS_OFFSET   ((u32)0x000003FF << 16)           /*!< R/W 0x0  vendor ns offset for rx*/
#define BIT_RX_VENDOR_NS_OFFSET(x)     (((u32)((x) & 0x000003FF) << 16))
#define BIT_GET_RX_VENDOR_NS_OFFSET(x) ((u32)(((x >> 16) & 0x000003FF)))
#define BIT_TX_VENDOR_TSFT_EN          ((u32)0x00000001 << 10)           /*!< R/W 0x0  vendor tsft emable for tx*/
#define BIT_MASK_TX_VENDOR_NS_OFFSET   ((u32)0x000003FF << 0)            /*!< R/W 0x0  vendor ns offset for tx*/
#define BIT_TX_VENDOR_NS_OFFSET(x)     (((u32)((x) & 0x000003FF) << 0))
#define BIT_GET_TX_VENDOR_NS_OFFSET(x) ((u32)(((x >> 0) & 0x000003FF)))
/** @} */

/** @defgroup REG_TCR_TSFT_OFS
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_TCR_TSFT_NS_OFS   ((u32)0x3FFFFFFF << 0)           /*!< R/W 0x0  tcr_tsft_ns_ofs*/
#define BIT_WMAC_TCR_TSFT_NS_OFS(x)     (((u32)((x) & 0x3FFFFFFF) << 0))
#define BIT_GET_WMAC_TCR_TSFT_NS_OFS(x) ((u32)(((x >> 0) & 0x3FFFFFFF)))
/** @} */

/** @defgroup REG_ANTTRN_CTR_1_V1
  * @brief
  * @{
  */
#define BIT_APPEND_MACID_IN_RESP_EN ((u32)0x00000001 << 1) /*!< R/W 0x0  Whether to append MACID in the rx descriptor of rx response packet*/
#define BIT_ANTTRN_ENABLE           ((u32)0x00000001 << 0) /*!< R/W 0x0  Enable the antenna training function*/
/** @} */

/** @defgroup REG_IQ_DUMP
  * @brief
  * @{
  */
#define BIT_DMA_IQD_WROVER         ((u32)0x00000001 << 31)           /*!< R 0x0  */
#define BIT_MASK_DUMP_ADDR_LATCH   ((u32)0x00007FFF << 16)           /*!< R 0x0  */
#define BIT_DUMP_ADDR_LATCH(x)     (((u32)((x) & 0x00007FFF) << 16))
#define BIT_GET_DUMP_ADDR_LATCH(x) ((u32)(((x >> 16) & 0x00007FFF)))
#define BIT_MACDBG_TRIG_IQDUMP     ((u32)0x00000001 << 15)           /*!< R/W 0x0  Enable dump bb ADC signal trigger from MAC debug port which controled by r_LEVEL_PULSE_SEL.*/
#define BIT_MASK_TRIG_TIME_SEL     ((u32)0x0000007F << 8)            /*!< R/W 0x0  dump ok time to finish dump signal(unit is 1us)*/
#define BIT_TRIG_TIME_SEL(x)       (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TRIG_TIME_SEL(x)   ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MAC_TRIG_REG           ((u32)0x00000001 << 5)            /*!< R/W 0x0  dump bb ADC sel mac strigger even write this reg to 1 to trig dump finish*/
#define BIT_MASK_LEVEL_PULSE_SEL   ((u32)0x00000003 << 3)            /*!< R/W 0x0  if dump bb ADC signal : [3] for sel mac trigger event if dump mac dbg signal [4:3] : 2'b00 : level signal match [4:3] : 2'b01 : posedge match [4:3] : 2'b10 : negdge match*/
#define BIT_LEVEL_PULSE_SEL(x)     (((u32)((x) & 0x00000003) << 3))
#define BIT_GET_LEVEL_PULSE_SEL(x) ((u32)(((x >> 3) & 0x00000003)))
#define BIT_EN_LA_MAC              ((u32)0x00000001 << 2)            /*!< R/W/ES 0x0  enable dump mac dbg signal*/
#define BIT_EN_IQDUMP              ((u32)0x00000001 << 1)            /*!< R/W/ES 0x0  enable dump bb ADC signal*/
#define BIT_IQDATA_DUMP            ((u32)0x00000001 << 0)            /*!< R/W 0x0  enable data dump for txpktbuffer high 64K*/
/** @} */

/** @defgroup REG_MASK_LA_MAC
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_MASK_LA_MAC   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_WMAC_MASK_LA_MAC(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_WMAC_MASK_LA_MAC(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MATCH_REF_MAC
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_MATCH_REF_MAC   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_WMAC_MATCH_REF_MAC(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_WMAC_MATCH_REF_MAC(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_WMAC_FTM_CTL
  * @brief
  * @{
  */
#define BIT_MASK_SEL_DEBUG_DATA            ((u32)0x00000003 << 30)           /*!< R/W 0x0  */
#define BIT_SEL_DEBUG_DATA(x)              (((u32)((x) & 0x00000003) << 30))
#define BIT_GET_SEL_DEBUG_DATA(x)          ((u32)(((x >> 30) & 0x00000003)))
#define BIT_EN_TIMEOUT                     ((u32)0x00000001 << 29)           /*!< R/W 0x0  Set this bit to 1 to reset mdpk read pointer*/
#define BIT_EN_RE_START                    ((u32)0x00000001 << 28)           /*!< R/W 0x0  Before setting 0x7C0[1:0] =2'b11, set this bit to 1 to enable MDPK access mode*/
#define BIT_MASK_LA_MAC_TIMEOUT_UNIT_SEL   ((u32)0x00000003 << 26)           /*!< R/W 0x0  LA mode triggered by mac debug port timeout value unit selection. 2'b00: 1us, 2'b01:32us, 2'b10: 1ms, 2'b11:RSVD*/
#define BIT_LA_MAC_TIMEOUT_UNIT_SEL(x)     (((u32)((x) & 0x00000003) << 26))
#define BIT_GET_LA_MAC_TIMEOUT_UNIT_SEL(x) ((u32)(((x >> 26) & 0x00000003)))
#define BIT_MASK_LA_MAC_TIMEOUT_VALUE      ((u32)0x0000003F << 20)           /*!< R/W 0x0  LA mode triggered by mac debug port timeout value, available with non-zero value.*/
#define BIT_LA_MAC_TIMEOUT_VALUE(x)        (((u32)((x) & 0x0000003F) << 20))
#define BIT_GET_LA_MAC_TIMEOUT_VALUE(x)    ((u32)(((x >> 20) & 0x0000003F)))
#define BIT_LEVEL_PULSE_SEL_EXT            ((u32)0x00000001 << 19)           /*!< R/W 0x0  LA mode triggered by mac debug port timeout event*/
#define BIT_MASK_TRIG_TIME_UNIT_SEL        ((u32)0x00000007 << 16)           /*!< R/W 0x0  Select trigger time unit of 0x7C0[14:8]. 3'b000 : 1us , 3'b001 : 2us ,  3'b010 : 4us ,  3'b011 : 8us , 3'b100 : 16us ,  3'b101 : 32us , 3'b110 : 64us, 3'b111 : RSV*/
#define BIT_TRIG_TIME_UNIT_SEL(x)          (((u32)((x) & 0x00000007) << 16))
#define BIT_GET_TRIG_TIME_UNIT_SEL(x)      ((u32)(((x >> 16) & 0x00000007)))
#define BIT_EN_TXD_DEBUG                   ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_EN_RXD_DEBUG                   ((u32)0x00000001 << 14)           /*!< R/W 0x0  */
#define BIT_TRX_TRIG_SEL_DEBUG             ((u32)0x00000001 << 13)           /*!< R/W 0x0  */
#define BIT_TRX_TRIG_SEL_PATT              ((u32)0x00000001 << 12)           /*!< R/W 0x0  */
#define BIT_EN_IQD_LEN_BREAK               ((u32)0x00000001 << 11)           /*!< R/W 0x0  */
#define BIT_MASK_IQD_LENGTH_REF            ((u32)0x00000007 << 8)            /*!< R/W 0x0  */
#define BIT_IQD_LENGTH_REF(x)              (((u32)((x) & 0x00000007) << 8))
#define BIT_GET_IQD_LENGTH_REF(x)          ((u32)(((x >> 8) & 0x00000007)))
#define BIT_TRX_TRIG_SEL_WMAC              ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_WMAC_RXFTM_TXACK_SC            ((u32)0x00000001 << 6)            /*!< R/W 0x0  When HW receive FTM pkt, HW will use RX FTM BW as response ACK TXBW.*/
#define BIT_WMAC_RXFTM_TXACK_BWEQ          ((u32)0x00000001 << 5)            /*!< R/W 0x0  When HW receive FTM pkt, HW will use RX FTM SC as response ACK TXSC.*/
#define BIT_WMAC_RXFTM_EN                  ((u32)0x00000001 << 3)            /*!< R/W 0x0  If BIT_FTM_TYPE = 1 && BIT_RXFTM_EN=1,   HW will parsing rx packet, to find FTM request frame.*/
#define BIT_WMAC_RXFTM_BYDRV               ((u32)0x00000001 << 2)            /*!< R/W 0x0  If set this bit to 1,Rx FTMREQ/FTM can be receive into rxpktbuffer.*/
#define BIT_WMAC_RXFTMREQ_EN               ((u32)0x00000001 << 1)            /*!< R/W 0x0  If BIT_FTM_TYPE = 1 && BIT_RXFTMREQ_EN=1,  HW will parsing rx packet, to find FTM request frame.*/
#define BIT_WMAC_FTM_FUNC_EN               ((u32)0x00000001 << 0)            /*!< R/W 0x0  Fine timing measurement function; 0: Disable 1:enable*/
/** @} */

/** @defgroup REG_WMAC_TRIG_SEL
  * @brief
  * @{
  */
#define BIT_SW_TRIG_STOP_MAC    ((u32)0x00000001 << 3)           /*!< R/W 0x0  during TXD_DEBUG or RXD_DEBUG mode, set CR 0->1 will trig iqdump stop*/
#define BIT_MASK_MAC_TRIG_SEL   ((u32)0x00000007 << 0)           /*!< R/W 0x0  dump bb ADC sel mac strigger even 2'b00 : rxpkt ok trig dump ok 2'b01 : rxpkt_fauil trig dump ok 2'b10 : rxpkt cca rise edge to trig dump ok 2'b11: rx type match*/
#define BIT_MAC_TRIG_SEL(x)     (((u32)((x) & 0x00000007) << 0))
#define BIT_GET_MAC_TRIG_SEL(x) ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_WMAC_OPTION_FUNCTION_1
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_RXFIFO_FULL_TH   ((u32)0x000000FF << 24)           /*!< R/W 0x0  csi buffer full window size*/
#define BIT_WMAC_RXFIFO_FULL_TH(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_WMAC_RXFIFO_FULL_TH(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_WMAC_RX_SYNCFIFO_SYNC      ((u32)0x00000001 << 23)           /*!< R/W 0x1  */
#define BIT_WMAC_DELIM_CHKREJ          ((u32)0x00000001 << 22)           /*!< R/W 0x0  1:state is delim check rx error to jump to error state 0:state is delim check rx_error_to_end to jump to error state*/
#define BIT_WMAC_SRCH_TXRPT_REF_DROP   ((u32)0x00000001 << 21)           /*!< R/W 0x0  when this bit is set 1, reference macid drop information when macid search*/
#define BIT_WMAC_SRCH_TXRPT_PERPKT     ((u32)0x00000001 << 16)           /*!< R/W 0x0  enable search txrpt buffer for macid every pkt*/
#define BIT_WMAC_SRCH_TXRPT_MID        ((u32)0x00000001 << 15)           /*!< R/W 0x1  enable search txrpt buffer for macid*/
#define BIT_WMAC_PFIN_TOEN             ((u32)0x00000001 << 14)           /*!< R/W 0x0  rx fifo fsm flush state timeout to error stage*/
#define BIT_WMAC_FIL_SECERR            ((u32)0x00000001 << 13)           /*!< R/W 0x1  sec len error drop(sec len is zero)*/
#define BIT_WMAC_FIL_CTLPKTLEN         ((u32)0x00000001 << 12)           /*!< R/W 0x0  drop the rx pkt if the rx ctrl pkt len large than r_WMAC_RX_FIL_LEN*/
#define BIT_WMAC_FIL_FCTYPE            ((u32)0x00000001 << 11)           /*!< R/W 0x0  drop the ofdm pkt if the rx ofdm leg pkt fc type is 2'b11*/
#define BIT_WMAC_FIL_FCPROVER          ((u32)0x00000001 << 10)           /*!< R/W 0x0  drop the ofdm pkt if the rx ofdm leg pkt fc version illegal*/
#define BIT_WMAC_TCR_MPAR_NDP          ((u32)0x00000001 << 6)            /*!< R/W 0x0  nop ok check bb ndp vld & mac rx ndp check ok*/
/** @} */

/** @defgroup REG_RX_FILTER_FUNCTION
  * @brief
  * @{
  */
#define BIT_WMAC_RXHANG_EN              ((u32)0x00000001 << 31)          /*!< R/W 0x0  Force read error content from fifo to solve rxhang.*/
#define BIT_WMAC_MHRDDY_LATCH           ((u32)0x00000001 << 30)          /*!< R/W 0x0  enable mac header ready latch when state is not wait fcs or error*/
#define BIT_WMAC_MHRDDY_CLR             ((u32)0x00000001 << 29)          /*!< R/W 0x0  enable mac header start to clear mac header ready latch signal*/
#define BIT_RXPKTCTL_FSM_BASED_MPDURDY1 ((u32)0x00000001 << 28)          /*!< R/W 0x1  Adjust mpdu_rdy timing to solve FSM behavier error.*/
#define BIT_WMAC_DIS_VHT_PLCP_CHK_MU    ((u32)0x00000001 << 27)          /*!< R/W 0x0  Disable check sigb crc value of MU plcp header.*/
#define BIT_CHK_DELIMIT_LEN             ((u32)0x00000001 << 26)          /*!< R/W 0x0  Drop mpdu if delimeter mpdu length smaller than mac header length + 4.*/
#define BIT_RXPKTCTL_FSM_BASED_MPDURDY  ((u32)0x00000001 << 24)          /*!< R/W 0x0  when this bit is set 1, rxpktfifo_ctl FSM jumps based on mpdu_valid(all MPDU data has been transferred to rxpktbuffer), when this bit is set 0, rxpktfifo_ctl FSM jumps based on fcs_valid(all MPDU data has been parsed by rx_parser)*/
#define BIT_WMAC_RXFIL_FEND             ((u32)0x00000001 << 22)          /*!< R/W 0x0  when this bit set 1,icvmic_valid signal is cleared when icvmic_rdy is valid(ICV/MIC is parsed)*/
#define BIT_WMAC_MPDURDY_CLR            ((u32)0x00000001 << 21)          /*!< R/W 0x0  when the bit is set 1,  the last MPDU which will be transferred to rxpktfifo is ready and error occurs, mpdu_rdy signal is also valid(is means all MPDU data has been transferred to rxpktbuffer)*/
#define BIT_PHYSTS_RPT_ONCE             ((u32)0x00000001 << 20)          /*!< R/W 0x0  keep original physts rx design, only use the last physts (rx after data_on fall).*/
#define BIT_NOT_WAIT_LAST_PHYSTS        ((u32)0x00000001 << 19)          /*!< R/W 0x0  last mpdu don't wait last physts, use the current physts in  physts buffer*/
#define BIT_WMAC_RXFIL_FCSE             ((u32)0x00000001 << 18)          /*!< R/W 0x0  If rx pkt is not ampdu and rejected,  reset rxpkt_ctl FSM immediately after parsing header*/
#define BIT_WMAC_RXFIL_MESH_DEL         ((u32)0x00000001 << 17)          /*!< R/W 0x0  drop the ofdm pkt if the rx ofdm leg pkt fc type is 2'b11*/
#define BIT_MASK_WMAC_RXFIL_LEN         ((u32)0x0000FFFF << 0)           /*!< R/W 0x41  use with 0x7D4[12]*/
#define BIT_WMAC_RXFIL_LEN(x)           (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_WMAC_RXFIL_LEN(x)       ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_WMAC_OPTION_FUNCTION_3
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_TXNDP_SIGB   ((u32)0x001FFFFF << 0)           /*!< R/W 0x1845A5  SIGB for NDP packet when BW =40MHz*/
#define BIT_WMAC_TXNDP_SIGB(x)     (((u32)((x) & 0x001FFFFF) << 0))
#define BIT_GET_WMAC_TXNDP_SIGB(x) ((u32)(((x >> 0) & 0x001FFFFF)))
/** @} */

/** @defgroup REG_WMAC_CMD_SEL
  * @brief
  * @{
  */
#define BIT_MASK_MAC_CMD_SHIFT   ((u32)0x0000000F << 2)           /*!< R/W 0x0  */
#define BIT_MAC_CMD_SHIFT(x)     (((u32)((x) & 0x0000000F) << 2))
#define BIT_GET_MAC_CMD_SHIFT(x) ((u32)(((x >> 2) & 0x0000000F)))
#define BIT_MASK_MAC_CMD_SEL     ((u32)0x00000003 << 0)           /*!< R/W 0x0  */
#define BIT_MAC_CMD_SEL(x)       (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_MAC_CMD_SEL(x)   ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_WMAC_DBG_SHIFT
  * @brief
  * @{
  */
#define BIT_MASK_MACTX_CMD_SHIFT   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  */
#define BIT_MACTX_CMD_SHIFT(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MACTX_CMD_SHIFT(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_WSEC_OPTION
  * @brief
  * @{
  */
#define BIT_RXDEC_UNI_MGNT         ((u32)0x00000001 << 20)           /*!< R/W 0x1  decryption enable of rx unicast management pkt, 0x680[3] shall also be set valid*/
#define BIT_TXENC_UNI_MGNT         ((u32)0x00000001 << 19)           /*!< R/W 0x1  encryption enable of tx unicast management pkt, 0x680[2] shall also be set valid*/
#define BIT_WMAC_SEC_MASKIV        ((u32)0x00000001 << 18)           /*!< R/W 0x0  MASK IV[15:8] for GCMP security*/
#define BIT_MASK_WMAC_SEC_PN_SEL   ((u32)0x00000003 << 16)           /*!< R/W 0x0  Security GCMP  header PN selection*/
#define BIT_WMAC_SEC_PN_SEL(x)     (((u32)((x) & 0x00000003) << 16))
#define BIT_GET_WMAC_SEC_PN_SEL(x) ((u32)(((x >> 16) & 0x00000003)))
#define BIT_WAPI_FC_NOMASK         ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_WAPI_QC_NOMASK         ((u32)0x00000001 << 14)           /*!< R/W 0x0  */
#define BIT_GCM_WAPI_FC_NOMASK     ((u32)0x00000001 << 13)           /*!< R/W 0x0  */
/** @} */

/*==========REG_PAGE7_WMAC Register Address Definition==========*/
#define REG_MACID1                                          0x700
#define REG_MACID1_1                                        0x704
#define REG_WMAC_FSM_RESET                                  0x708
#define REG_CLM_NLM                                         0x70C
#define REG_MACID2                                          0x710
#define REG_MACID2_1                                        0x714
#define REG_SND_PTCL_CTRL                                   0x718
#define REG_BEAMFORM_STATUS                                 0x71C
#define REG_ZB_STATISTIC_0                                  0x720
#define REG_ZB_STATISTIC_1                                  0x724
#define REG_ZB_STATISTIC_2                                  0x728
#define REG_ZB_COEX_TABLE_1                                 0x740
#define REG_ZB_COEX_TABLE_2                                 0x744
#define REG_ZB_BREAK_TABLE                                  0x748
#define REG_EXT_ZB_DETEC_CTRL                               0x74C
#define REG_RADAR_COEX                                      0x758
#define REG_BT_COEX_SW_CFG                                  0x75C
#define REG_WMAC_SWAES_CFG                                  0x760
#define REG_BT_COEX_ENH                                     0x764
#define REG_WLAN_ACT_MASK_CTRL                              0x768
#define REG_WLAN_ACT_MASK_CTRL_1                            0x76C
#define REG_BT_COEX_ENHANCED_INTR_CTRL                      0x76E
#define REG_BT_ENHANCED_CTRL0                               0x770
#define REG_BT_ENHANCED_CTRL1                               0x774
#define REG_BT_PROPRI                                       0x778
#define REG_BT_STATUS_REPORT_REGISTER                       0x77C
#define REG_BT_INTERRUPT_CONTROL_REGISTER                   0x780
#define REG_WLAN_REPORT_TIME_OUT_CONTROL_REGISTER           0x784
#define REG_BT_ISOLATION_TABLE_REGISTER_REGISTER_1          0x788
#define REG_BT_ISOLATION_TABLE_REGISTER_REGISTER_2          0x78C
#define REG_BT_TDMA_TIME_REGISTER                           0x790
#define REG_BT_ACT_REGISTER                                 0x794
#define REG_VENDOR_CFG                                      0x7A4
#define REG_VENDOR_TSFT_CTL                                 0x7A8
#define REG_TCR_TSFT_OFS                                    0x7B0
#define REG_ANTTRN_CTR_1_V1                                 0x7B4
#define REG_WMAC_PKTCNT_RWD                                 0x7B8
#define REG_WMAC_PKTCNT_CTRL                                0x7BC
#define REG_IQ_DUMP                                         0x7C0
#define REG_MASK_LA_MAC                                     0x7C4
#define REG_MATCH_REF_MAC                                   0x7C8
#define REG_WMAC_FTM_CTL                                    0x7CC
#define REG_WMAC_TRIG_SEL                                   0x7D0
#define REG_WMAC_OPTION_FUNCTION_1                          0x7D4
#define REG_RX_FILTER_FUNCTION                              0x7D8
#define REG_WMAC_OPTION_FUNCTION_3                          0x7E0
#define REG_WMAC_CMD_SEL                                    0x7E4
#define REG_WMAC_DBG_SHIFT                                  0x7E8
#define REG_WSEC_OPTION                                     0x7EC

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