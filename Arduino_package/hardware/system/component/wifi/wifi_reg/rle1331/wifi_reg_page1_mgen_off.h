#ifndef _RL6955_REG_PAGE1_MGEN_OFF_H_
#define _RL6955_REG_PAGE1_MGEN_OFF_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE1_MGEN_OFF
  * @brief REG_PAGE1_MGEN_OFF driver modules
  * @{
  */




/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE1_MGEN_OFF_Register_Definitions REG_PAGE1_MGEN_OFF Register Definitions
  * @{
  */

/** @defgroup REG_FISR1
  * @brief
  * @{
  */
#define BIT_FS_RADAR_SEG_END_INT   ((u32)0x00000001 << 22) /*!< RW1CB 0x0  */
#define BIT_FS_RADAR_OK_INT        ((u32)0x00000001 << 21) /*!< RW1CB 0x0  */
#define BIT_FS_RADAR_FAIL_INT      ((u32)0x00000001 << 20) /*!< RW1CB 0x0  */
#define BIT_FS_RADAR_TIMEOUT_INT   ((u32)0x00000001 << 19) /*!< RW1CB 0x0  */
#define BIT_FS_TBTT1_INT           ((u32)0x00000001 << 18) /*!< RW1CB 0x0  */
#define BIT_FS_TBTT_DISC_INT       ((u32)0x00000001 << 17) /*!< RW1CB 0x0  */
#define BIT_FS_TBTT_SYNC_2G_INT    ((u32)0x00000001 << 16) /*!< RW1CB 0x0  */
#define BIT_FS_TBTT_SYNC_5G_INT    ((u32)0x00000001 << 15) /*!< RW1CB 0x0  */
#define BIT_FS_TXBCNOK0_INT        ((u32)0x00000001 << 14) /*!< RW1CB 0x0  */
#define BIT_FS_TXBCNOK1_INT        ((u32)0x00000001 << 13) /*!< RW1CB 0x0  */
#define BIT_FS_TXBCNERR0_INT       ((u32)0x00000001 << 12) /*!< RW1CB 0x0  */
#define BIT_FS_TXBCNERR1_INT       ((u32)0x00000001 << 11) /*!< RW1CB 0x0  */
#define BIT_FS_TXBCNOK_DISC_INT    ((u32)0x00000001 << 10) /*!< RW1CB 0x0  */
#define BIT_FS_TXBCNOK_SYNC_INT    ((u32)0x00000001 << 9)  /*!< RW1CB 0x0  */
#define BIT_FS_TXBCNERR_DISC_INT   ((u32)0x00000001 << 8)  /*!< RW1CB 0x0  */
#define BIT_FS_TXBCNERR_SYNC_INT   ((u32)0x00000001 << 7)  /*!< RW1CB 0x0  */
#define BIT_FS_SDF_START_INT       ((u32)0x00000001 << 6)  /*!< RW1CB 0x0  */
#define BIT_FS_DWWIN_END_INT       ((u32)0x00000001 << 5)  /*!< RW1CB 0x0  */
#define BIT_FS_TXRPT_INT           ((u32)0x00000001 << 4)  /*!< RW1CB 0x0  */
#define BIT_FS_BCN_IE_0_HIT_INT    ((u32)0x00000001 << 3)  /*!< RW1CB 0x0  */
#define BIT_FS_BCN_IE_1_HIT_INT    ((u32)0x00000001 << 2)  /*!< RW1CB 0x0  */
#define BIT_FS_BC_TWT_PARA_CHG_INT ((u32)0x00000001 << 1)  /*!< RW1CB 0x0  */
#define BIT_FS_RSSI_MATCH_INT      ((u32)0x00000001 << 0)  /*!< RW1CB 0x0  */
/** @} */

/** @defgroup REG_FISR2
  * @brief
  * @{
  */
#define BIT_FS_WLBB_HIGH_PRI_INT              ((u32)0x00000001 << 29) /*!< RW1CB 0x0  */
#define BIT_FS_WLBB_LOW_PRI_INT               ((u32)0x00000001 << 28) /*!< RW1CB 0x0  */
#define BIT_FS_HIOE_CHN_BB_HW_INT             ((u32)0x00000001 << 27) /*!< RW1CB 0x0  */
#define BIT_FS_TRIG_LAT_AUDIO_CNT_INT         ((u32)0x00000001 << 26) /*!< RW1CB 0x0  */
#define BIT_FS_RXBCN_TSF_GT_THRES_INT         ((u32)0x00000001 << 25) /*!< RW1CB 0x0  */
#define BIT_FS_RXBCN_TIMEUP_CNT_INT           ((u32)0x00000001 << 24) /*!< RW1CB 0x0  */
#define BIT_FS_RXBCN_TIMEUP_CNT1_INT          ((u32)0x00000001 << 23) /*!< RW1CB 0x0  */
#define BIT_FS_RXBCN_TIME_UP_INT              ((u32)0x00000001 << 22) /*!< RW1CB 0x0  */
#define BIT_FS_RX_BCN_ERR_P0_INT              ((u32)0x00000001 << 21) /*!< RW1CB 0x0  */
#define BIT_FS_RX_BCN_OK_P0_INT               ((u32)0x00000001 << 20) /*!< RW1CB 0x0  */
#define BIT_FS_TIM_NO_HIT_INT                 ((u32)0x00000001 << 19) /*!< RW1CB 0x0  */
#define BIT_FS_TIM_HIT_INT                    ((u32)0x00000001 << 18) /*!< RW1CB 0x0  */
#define BIT_FS_HIOE_CHN_ON_INT                ((u32)0x00000001 << 17) /*!< RW1CB 0x0  */
#define BIT_FS_HIOE_CHN_OFF_INT               ((u32)0x00000001 << 16) /*!< RW1CB 0x0  */
#define BIT_FS_HIOE_CHN_MAC_HW1_INT           ((u32)0x00000001 << 15) /*!< RW1CB 0x0  */
#define BIT_FS_HIOE_CHN_MAC_HW0_INT           ((u32)0x00000001 << 14) /*!< RW1CB 0x0  */
#define BIT_FS_HIOE_CHN_BCN_MODE_INT          ((u32)0x00000001 << 13) /*!< RW1CB 0x0  */
#define BIT_FS_CCA2HIOE_TSFT_AVG_GT_THRES_INT ((u32)0x00000001 << 12) /*!< RW1CB 0x0  */
#define BIT_FS_EDCCA_IDLE_TOCNT_INT           ((u32)0x00000001 << 11) /*!< RW1CB 0x0  */
#define BIT_FS_RXBCN_CNT_END_INT              ((u32)0x00000001 << 10) /*!< RW1CB 0x0  */
#define BIT_FS_RXFTMREQ_INT                   ((u32)0x00000001 << 9)  /*!< RW1CB 0x0  If RXFTMREQ_INT_EN =1. When HW receive FTMREQ packet, it will generate interrupt to firmware.*/
#define BIT_FS_RXFTM_INT                      ((u32)0x00000001 << 8)  /*!< RW1CB 0x0  If RXFTM_INT_EN =1. When HW receive FTM and transmit ACK frame successfully, the BB generate FTM report. It will generate interrupt to firmware.*/
#define BIT_FS_TXFTM_INT                      ((u32)0x00000001 << 7)  /*!< RW1CB 0x0  If TXFTM_INT_EN =1. When HW transmit FTM and receive ACK frame successfully, the BB generate FTM report. It will generate interrupt to firmware.*/
#define BIT_FS_BTCMD_INT                      ((u32)0x00000001 << 6)  /*!< RW1CB 0x0  */
#define BIT_FS_BT_MAILBOX_INT                 ((u32)0x00000001 << 5)  /*!< RW1CB 0x0  */
#define BIT_FS_GNT_BT_BB_FALL_INT             ((u32)0x00000001 << 4)  /*!< RW1CB 0x0  */
#define BIT_FS_GNT_BT_BB_RISE_INT             ((u32)0x00000001 << 3)  /*!< RW1CB 0x0  */
#define BIT_FS_BT_GPIO_TOGGLE_INT             ((u32)0x00000001 << 2)  /*!< RW1CB 0x0  */
#define BIT_FS_FSM1_CHK_HANG_TO_INT           ((u32)0x00000001 << 1)  /*!< RW1CB 0x0  */
#define BIT_FS_FSM0_CHK_HANG_TO_INT           ((u32)0x00000001 << 0)  /*!< RW1CB 0x0  */
/** @} */

/** @defgroup REG_FISR3
  * @brief
  * @{
  */
#define BIT_FS_RXPLCP_CHKOK_INT            ((u32)0x00000001 << 24) /*!< RW1CB 0x0  RXPCLP check ok interrupt*/
#define BIT_FS_RXDONE0_INT                 ((u32)0x00000001 << 23) /*!< RW1CB 0x0  Rx Packet 0 done interrupt (for WOL release packet)*/
#define BIT_FS_RX_UCMD0_INT                ((u32)0x00000001 << 22) /*!< RW1CB 0x0  The interrupt is issued while receiving unicast data frame with More Data=0*/
#define BIT_FS_RX_UCMD1_INT                ((u32)0x00000001 << 21) /*!< RW1CB 0x0  The interrupt is issued while receiving unicast data frame with More Data=1*/
#define BIT_FS_RX_BCMD0_INT                ((u32)0x00000001 << 20) /*!< RW1CB 0x0  The interrupt is issued while receiving broadcast data frame with More Data=0*/
#define BIT_FS_RX_BCMD1_INT                ((u32)0x00000001 << 19) /*!< RW1CB 0x0  The interrupt is issued while receiving broadcast data frame with More Data=1*/
#define BIT_FS_RX_UAPSDMD1_INT             ((u32)0x00000001 << 18) /*!< RW1CB 0x0  Setting this bit indicates Rx pkt is matched with one of below: 1.) QoS Unicast data frame with MD=1, UAPSD=0 2.) NonQoS Unicast data frame with MD=1*/
#define BIT_FS_RX_UAPSDMD0_INT             ((u32)0x00000001 << 17) /*!< RW1CB 0x0  Setting this bit indicates Rx pkt is matched with one of below: 1.) QoS Unicast data frame with MD=0, UAPSD=0 2.) NonQoS Unicast data frame with MD=0*/
#define BIT_FS_EOSP_INT                    ((u32)0x00000001 << 16) /*!< RW1CB 0x0  EOSP_INT interrupt mask*/
#define BIT_FS_RXUCMD0_ACK_INT             ((u32)0x00000001 << 15) /*!< RW1CB 0x0  */
#define BIT_FS_RXUCMD1_ACK_INT             ((u32)0x00000001 << 14) /*!< RW1CB 0x0  */
#define BIT_FS_RXBCMD0_ACK_INT             ((u32)0x00000001 << 13) /*!< RW1CB 0x0  */
#define BIT_FS_RXBCMD1_ACK_INT             ((u32)0x00000001 << 12) /*!< RW1CB 0x0  */
#define BIT_FS_RX_MORE_TF0_INT             ((u32)0x00000001 << 11) /*!< RW1CB 0x0  */
#define BIT_FS_RX_MORE_TF1_INT             ((u32)0x00000001 << 10) /*!< RW1CB 0x0  */
#define BIT_FS_ERR_HAPPENED_INT            ((u32)0x00000001 << 9)  /*!< RW1CB 0x0  FWHW/ WMAC error status interrupt(0x4E2[15:0], 0x6B8[31:0]). WMAC error state will be recovered by HW, the others won't.*/
#define BIT_FS_P0_PKTIN_INT                ((u32)0x00000001 << 8)  /*!< RW1CB 0x0  port 0 packet assign to queue interrupt*/
#define BIT_FS_P1_PKTIN_INT                ((u32)0x00000001 << 7)  /*!< RW1CB 0x0  port 1 packet assign to queue interrupt*/
#define BIT_FS_TX_NULL1_P0_INT             ((u32)0x00000001 << 6)  /*!< RW1CB 0x0  TX null 1 packet done interrupt*/
#define BIT_FS_TX_NULL0_P0_INT             ((u32)0x00000001 << 5)  /*!< RW1CB 0x0  TX null 0 packet done interrupt*/
#define BIT_FS_TRIGGER_PKT_INT             ((u32)0x00000001 << 4)  /*!< RW1CB 0x0  tx TRIGGER_PKT interrupt*/
#define BIT_FS_RLS_FIFO_ALMOST_FULL_FW_INT ((u32)0x00000001 << 3)  /*!< RW1CB 0x0  */
#define BIT_FS_RLS_FIFO_FULL_FW_INT        ((u32)0x00000001 << 2)  /*!< RW1CB 0x0  */
#define BIT_FS_RLS_FIFO_VALID_FW_INT       ((u32)0x00000001 << 1)  /*!< RW1CB 0x0  */
#define BIT_FS_FW_CPUMGQ_RLS_INT           ((u32)0x00000001 << 0)  /*!< RW1CB 0x0  */
/** @} */

/** @defgroup REG_FW_DBG_1
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_1*/
#define BIT_FW_DBG_1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_2
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_2*/
#define BIT_FW_DBG_2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_3
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_3*/
#define BIT_FW_DBG_3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_4
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_4   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_4*/
#define BIT_FW_DBG_4(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_4(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_5
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_5   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_5*/
#define BIT_FW_DBG_5(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_5(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_6
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_6   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_6*/
#define BIT_FW_DBG_6(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_6(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_7
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_7   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_7*/
#define BIT_FW_DBG_7(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_7(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_8
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_8   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_8*/
#define BIT_FW_DBG_8(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_8(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BT_MAILBOX_DATA_IN_L
  * @brief
  * @{
  */
#define BIT_MASK_MAILBOX_DATA_IN_BT2WL_L   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  */
#define BIT_MAILBOX_DATA_IN_BT2WL_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MAILBOX_DATA_IN_BT2WL_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BT_MAILBOX_DATA_IN_H
  * @brief
  * @{
  */
#define BIT_MASK_MAILBOX_DATA_IN_BT2WL_H   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  */
#define BIT_MAILBOX_DATA_IN_BT2WL_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MAILBOX_DATA_IN_BT2WL_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BT_MAILBOX_CONTROL
  * @brief
  * @{
  */
#define BIT_MAILBOX_IN_RDY_INTEN   ((u32)0x00000001 << 17) /*!< R/W 0x0  Mailbox IN ready interrupt enable*/
#define BIT_MAILBOX_IN_RDY         ((u32)0x00000001 << 16) /*!< R 0x0  Mailbox ready BT2Wifi*/
#define BIT_MAILBOX_OUT_VLD_CLR    ((u32)0x00000001 << 7)  /*!< W1P 0x0  clear Mailbox ACK Wifi2BT*/
#define BIT_MAILBOX_OUTEMPTY_INTEN ((u32)0x00000001 << 1)  /*!< R/W 0x0  Mailbox OUT empty interrupt enable*/
#define BIT_MAILBOX_OUT_VLD_SET    ((u32)0x00000001 << 0)  /*!< R 0x0  Mailbox ACK Wifi2BT*/
/** @} */

/** @defgroup REG_BB_ACCESS_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_BB_WRITE_READ   ((u32)0x00000003 << 30)           /*!< R 0x0  00 : No Active Baseband cycle 01 : Baseband Write Access (auto return to 00 when access finished) 1X : Baseband Read Access (auto return to 00 when access finished)*/
#define BIT_BB_WRITE_READ(x)     (((u32)((x) & 0x00000003) << 30))
#define BIT_GET_BB_WRITE_READ(x) ((u32)(((x >> 30) & 0x00000003)))
#define BIT_MASK_BB_WRITE_EN     ((u32)0x0000000F << 16)           /*!< R 0x0  Byte Write Enable*/
#define BIT_BB_WRITE_EN(x)       (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BB_WRITE_EN(x)   ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BB_ADDR         ((u32)0x00003FFF << 2)            /*!< R 0x0  Baseband Access Write/Read Address (in DW unit)*/
#define BIT_BB_ADDR(x)           (((u32)((x) & 0x00003FFF) << 2))
#define BIT_GET_BB_ADDR(x)       ((u32)(((x >> 2) & 0x00003FFF)))
#define BIT_BB_ERRACC            ((u32)0x00000001 << 0)            /*!< R 0x0  Duplicate Access when previous cycle pending (write one clear)*/
/** @} */

/** @defgroup REG_BB_ACCESS_DATA
  * @brief
  * @{
  */
#define BIT_MASK_BB_DATA   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  Baseband Access Write/Read Data (in DW unit)*/
#define BIT_BB_DATA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BB_DATA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CSIFF_PTR
  * @brief CSI FIFO Read/write pointer
  * @{
  */
#define BIT_MASK_CSIPKT_RDPTR   ((u32)0x000007FF << 16)           /*!< R 0x0  The read pointer address of CSIBUFFER. The value is set to the physical LX bus address. 8byte unit*/
#define BIT_CSIPKT_RDPTR(x)     (((u32)((x) & 0x000007FF) << 16))
#define BIT_GET_CSIPKT_RDPTR(x) ((u32)(((x >> 16) & 0x000007FF)))
#define BIT_MASK_CSIPKT_WRPTR   ((u32)0x000007FF << 0)            /*!< R 0x0  The write pointer address of CSIBUFFER. The value is set to the physical LX bus address. 8byte unit*/
#define BIT_CSIPKT_WRPTR(x)     (((u32)((x) & 0x000007FF) << 0))
#define BIT_GET_CSIPKT_WRPTR(x) ((u32)(((x >> 0) & 0x000007FF)))
/** @} */

/** @defgroup REG_TXBD_FIFO_CFG0
  * @brief
  * @{
  */
#define BIT_MASK_SW_WR_TXBD_DATA   ((u32)0xFFFFFFFF << 0)           /*!< R/WP 0x0  SW write host address to TXBD FIFO*/
#define BIT_SW_WR_TXBD_DATA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_SW_WR_TXBD_DATA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TXRLS_FIFO_CFG0
  * @brief
  * @{
  */
#define BIT_MASK_DRV_RD_TXRLS_DATA   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  Driver read released host address from memory*/
#define BIT_DRV_RD_TXRLS_DATA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_DRV_RD_TXRLS_DATA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TXRLS_FIFO_CFG1
  * @brief
  * @{
  */
#define BIT_MASK_FW_RD_TXRLS_DATA   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  FW read released host address from memory*/
#define BIT_FW_RD_TXRLS_DATA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_RD_TXRLS_DATA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TXRPT_BUF_CFG0
  * @brief
  * @{
  */
#define BIT_MASK_SW_RD_TXRPT_DATA   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  FW read TXRPT data from memory*/
#define BIT_SW_RD_TXRPT_DATA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_SW_RD_TXRPT_DATA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_RXBD_FIFO_CFG0
  * @brief
  * @{
  */
#define BIT_MASK_SW_WR_RXBD_DATA   ((u32)0xFFFFFFFF << 0)           /*!< R/WP 0x0  SW write host address to RXBD FIFO*/
#define BIT_SW_WR_RXBD_DATA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_SW_WR_RXBD_DATA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CSIBD_FIFO_CFG0
  * @brief
  * @{
  */
#define BIT_MASK_SW_WR_CSIBD_DATA   ((u32)0xFFFFFFFF << 0)           /*!< R/WP 0x0  SW write host address to CSIBD FIFO*/
#define BIT_SW_WR_CSIBD_DATA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_SW_WR_CSIBD_DATA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CSIBD_RDATA
  * @brief
  * @{
  */
#define BIT_MASK_SW_RD_CSIBD_DATA   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  SW read released CSIBD host address from memory*/
#define BIT_SW_RD_CSIBD_DATA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_SW_RD_CSIBD_DATA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_RXBD_RDATA
  * @brief
  * @{
  */
#define BIT_MASK_SW_RD_RXBD_DATA   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  SW read released RXBD host address from memory*/
#define BIT_SW_RD_RXBD_DATA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_SW_RD_RXBD_DATA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_LOOPBACK
  * @brief
  * @{
  */
#define BIT_DELAY_LBK                  ((u32)0x00000001 << 10)          /*!< R/W 0x0  delay loop back mode*/
#define BIT_DIGLBK                     ((u32)0x00000001 << 9)           /*!< R/W 0x0  loop back mode*/
#define BIT_MASK_WMAC_LBK_START_ADDR   ((u32)0x000001FF << 0)           /*!< R/W 0x0  start address of delay loopback pkt in ext_rxpktbuf*/
#define BIT_WMAC_LBK_START_ADDR(x)     (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_WMAC_LBK_START_ADDR(x) ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_RXFF_PTR
  * @brief RX  FIFO Read/write pointer
  * @{
  */
#define BIT_MASK_RXPKT_RDPTR   ((u32)0x000007FF << 16)           /*!< R 0x0  The read pointer address of RXFF0. The value is set to the physical LX bus address. 8byte unit*/
#define BIT_RXPKT_RDPTR(x)     (((u32)((x) & 0x000007FF) << 16))
#define BIT_GET_RXPKT_RDPTR(x) ((u32)(((x >> 16) & 0x000007FF)))
#define BIT_MASK_RXPKT_WRPTR   ((u32)0x000007FF << 0)            /*!< R 0x0  The write pointer address of RXFF0. The value is set to the physical LX bus address. 8byte unit*/
#define BIT_RXPKT_WRPTR(x)     (((u32)((x) & 0x000007FF) << 0))
#define BIT_GET_RXPKT_WRPTR(x) ((u32)(((x >> 0) & 0x000007FF)))
/** @} */

/** @defgroup REG_BT_MAILBOX_DATA_OUT_L
  * @brief
  * @{
  */
#define BIT_MASK_MAILBOX_DATA_OUT_WL2BT_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MAILBOX_DATA_OUT_WL2BT_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MAILBOX_DATA_OUT_WL2BT_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BT_MAILBOX_DATA_OUT_H
  * @brief
  * @{
  */
#define BIT_MASK_MAILBOX_DATA_OUT_WL2BT_H   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MAILBOX_DATA_OUT_WL2BT_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MAILBOX_DATA_OUT_WL2BT_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BT_MAILBOX_INT
  * @brief
  * @{
  */
#define BIT_BT_MAILBOX_SYS_INT_EN ((u32)0x00000001 << 1) /*!< R/W 0x0  bt2wl and wl2bt mailbox interrupt mask*/
#define BIT_BT_MAILBOX_SYS_INT    ((u32)0x00000001 << 0) /*!< RW1CB 0x0  bt2wl and wl2bt mailbox interrupt, to system intr*/
/** @} */

/*==========REG_PAGE1_MGEN_OFF Register Address Definition==========*/
#define REG_FISR1                          0x12C
#define REG_FISR2                          0x134
#define REG_FISR3                          0x13C
#define REG_FW_DBG_1                       0x1B8
#define REG_FW_DBG_2                       0x1BC
#define REG_FW_DBG_3                       0x1C0
#define REG_FW_DBG_4                       0x1C4
#define REG_FW_DBG_5                       0x1100
#define REG_FW_DBG_6                       0x1104
#define REG_FW_DBG_7                       0x1108
#define REG_FW_DBG_8                       0x110C
#define REG_BT_MAILBOX_DATA_IN_L           0x1110
#define REG_BT_MAILBOX_DATA_IN_H           0x1114
#define REG_BT_MAILBOX_CONTROL             0x1118
#define REG_BB_ACCESS_CTRL                 0x111C
#define REG_BB_ACCESS_DATA                 0x1120
#define REG_CSIFF_PTR                      0x1128
#define REG_TXBD_FIFO_CFG0                 0x112C
#define REG_TXRLS_FIFO_CFG0                0x1130
#define REG_TXRLS_FIFO_CFG1                0x1134
#define REG_TXRPT_BUF_CFG0                 0x1138
#define REG_RXBD_FIFO_CFG0                 0x113C
#define REG_CSIBD_FIFO_CFG0                0x1140
#define REG_CSIBD_RDATA                    0x1144
#define REG_RXBD_RDATA                     0x1148
#define REG_LOOPBACK                       0x1154
#define REG_DUMMY_PAGE1_OFF                0x1158
#define REG_RXFF_PTR                       0x115C
#define REG_BT_MAILBOX_DATA_OUT_L          0x1160
#define REG_BT_MAILBOX_DATA_OUT_H          0x1164
#define REG_BT_MAILBOX_INT                 0x1168

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