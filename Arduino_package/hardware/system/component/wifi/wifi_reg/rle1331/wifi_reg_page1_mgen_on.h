#ifndef _RL6955_REG_PAGE1_MGEN_ON_H_
#define _RL6955_REG_PAGE1_MGEN_ON_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE1_MGEN_ON
  * @brief REG_PAGE1_MGEN_ON driver modules
  * @{
  */




/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE1_MGEN_ON_Register_Definitions REG_PAGE1_MGEN_ON Register Definitions
  * @{
  */

/** @defgroup REG_CR
  * @brief MAC TOP Function enable
  * @{
  */
#define BIT_MASK_NETYPE1   ((u32)0x00000003 << 18)           /*!< R/W 0x0  Network Type for Port 1 00: No link 01: Link in ad hoc network 10: Link in infrastructure network 11:AP mode Default:00b.*/
#define BIT_NETYPE1(x)     (((u32)((x) & 0x00000003) << 18))
#define BIT_GET_NETYPE1(x) ((u32)(((x >> 18) & 0x00000003)))
#define BIT_MASK_NETYPE0   ((u32)0x00000003 << 16)           /*!< R/W 0x0  Network Type for port 0 00: No link 01: Link in ad hoc network 10: Link in infrastructure network 11:AP mode Default:00b.*/
#define BIT_NETYPE0(x)     (((u32)((x) & 0x00000003) << 16))
#define BIT_GET_NETYPE0(x) ((u32)(((x >> 16) & 0x00000003)))
#define BIT_MAC_SEC_EN     ((u32)0x00000001 << 9)            /*!< R/W 0x0  Enable MAC security engine When this bit is clear, security engine is reset*/
#define BIT_MACRXEN        ((u32)0x00000001 << 7)            /*!< R/W 0x0  MAC Receiver Enable. When set to 1, and the receive state machine is idle, the receive machine becomes active. This bit will read back as 1 whenever the receive state machine is active. After initial power-up, software must ensure that the receiver has completely reset before setting this bit. 1: Enable 0: Disable Default: 0b.*/
#define BIT_MACTXEN        ((u32)0x00000001 << 6)            /*!< R/W 0x0  MAC Transmitter Enable. When set to 1, and the transmit state machine is idle, the transmit state machine becomes active. This bit will read back as 1 whenever the transmit state machine is active. After initial power-up, software must ensure that the transmitter has completely reset before setting this bit. 1: Enable 0: Disable Default: 0b.*/
#define BIT_SCHEDULE_EN    ((u32)0x00000001 << 5)            /*!< R/W 0x0  Schedule Enable.*/
#define BIT_PTCL_EN        ((u32)0x00000001 << 4)            /*!< R/W 0x0  protocol Block Function Enable.(FW2HW)*/
#define BIT_RXDMA_EN       ((u32)0x00000001 << 3)            /*!< R/W 0x0  RXDMA Function Enable*/
#define BIT_TXDMA_EN       ((u32)0x00000001 << 2)            /*!< R/W 0x0  TXDMA Function Enable*/
#define BIT_HCI_RXDMA_EN   ((u32)0x00000001 << 1)            /*!< R/W 0x0  HCI to RXDMA Interface Enable*/
#define BIT_HCI_TXDMA_EN   ((u32)0x00000001 << 0)            /*!< R/W 0x0  HCI to TXDMA Interface Enable*/
/** @} */

/** @defgroup REG_BB_RFC_ATR
  * @brief BB/RFC REG Access Time Register
  * @{
  */
#define BIT_MASK_PHYRE_CNT         ((u32)0x000000FF << 24)           /*!< R/W 0x5  */
#define BIT_PHYRE_CNT(x)           (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_PHYRE_CNT(x)       ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_PHYWR_SETUP_CNT   ((u32)0x000000FF << 16)           /*!< R/W 0x5  the timing WDATA stable before WE for host/cpu access BB/RFC REG*/
#define BIT_PHYWR_SETUP_CNT(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_PHYWR_SETUP_CNT(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_PHYWR_HOLD_CNT    ((u32)0x000000FF << 8)            /*!< R/W 0x4  the timing WDATA stable after WE for host/cpu access BB/RFC REG*/
#define BIT_PHYWR_HOLD_CNT(x)      (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_PHYWR_HOLD_CNT(x)  ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_PHYRD_WAIT_CNT    ((u32)0x000000FF << 0)            /*!< R/W 0x4  the timing RDATA stable after ADDR for host/cpu access BB/RFC REG*/
#define BIT_PHYRD_WAIT_CNT(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_PHYRD_WAIT_CNT(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_EXT_IMR_WLPMC_EN
  * @brief
  * @{
  */
#define BIT_PS_ELY_TIMER_E_EXT_WLPMC_FS_EN ((u32)0x00000001 << 9) /*!< R/W 0x0  */
#define BIT_PS_ELY_TIMER_D_EXT_WLPMC_FS_EN ((u32)0x00000001 << 8) /*!< R/W 0x0  */
#define BIT_PS_ELY_TIMER_C_EXT_WLPMC_FS_EN ((u32)0x00000001 << 7) /*!< R/W 0x0  */
#define BIT_PS_ELY_TIMER_B_EXT_WLPMC_FS_EN ((u32)0x00000001 << 6) /*!< R/W 0x0  */
#define BIT_PS_ELY_TIMER_A_EXT_WLPMC_FS_EN ((u32)0x00000001 << 5) /*!< R/W 0x0  */
#define BIT_PS_ELY_TIMER_E_EXT_WLPMC_EN    ((u32)0x00000001 << 4) /*!< R/W 0x0  */
#define BIT_PS_ELY_TIMER_D_EXT_WLPMC_EN    ((u32)0x00000001 << 3) /*!< R/W 0x0  */
#define BIT_PS_ELY_TIMER_C_EXT_WLPMC_EN    ((u32)0x00000001 << 2) /*!< R/W 0x0  */
#define BIT_PS_ELY_TIMER_B_EXT_WLPMC_EN    ((u32)0x00000001 << 1) /*!< R/W 0x0  */
#define BIT_PS_ELY_TIMER_A_EXT_WLPMC_EN    ((u32)0x00000001 << 0) /*!< R/W 0x0  */
/** @} */

/** @defgroup REG_EXT_IMR_SW_EN
  * @brief
  * @{
  */
#define BIT_EDCCA_ILDE_TOCNT_INT_EXT_SW_EN   ((u32)0x00000001 << 13) /*!< R/W 0x0  when edcca is low after tbtt, start timer,when timeout for few times,set this interrupt*/
#define BIT_HIOE_CHN_BCN_MODE_INT_EXT_SW_EN  ((u32)0x00000001 << 12) /*!< R/W 0x0  hioe_chn_bcn_mode done interrupt*/
#define BIT_HIOE_CHN_MAC_HW0_SW_EN           ((u32)0x00000001 << 11) /*!< R/W 0x0  hioe_chn_mac_hw0 done interrupt*/
#define BIT_HIOE_CHN_MAC_HW1_SW_EN           ((u32)0x00000001 << 10) /*!< R/W 0x0  hioe_chn_mac_hw1 done interrupt*/
#define BIT_HIOE_CHN_OFF_INT_EXT_SW_EN       ((u32)0x00000001 << 9)  /*!< R/W 0x0  hioe_chn_off done interrupt*/
#define BIT_HIOE_CHN_ON_INT_EXT_SW_EN        ((u32)0x00000001 << 8)  /*!< R/W 0x0  hioe_chn_on done interrupt*/
#define BIT_TIM_NO_HIT_INT_EXT_SW_EN         ((u32)0x00000001 << 7)  /*!< R/W 0x0  when no my aid or aid is 0(0x16DC[8]) or my bssid is not in tim element(0x16DB[31]),generate this interrupt*/
#define BIT_RX_BCN_OK_P0_INT_EXT_SW_EN       ((u32)0x00000001 << 6)  /*!< R/W 0x0  When this bit is enable, the interrupt is issued when RX beacon frame occurs in port0.*/
#define BIT_RX_BCN_ERR_P0_INT_EXT_SW_EN      ((u32)0x00000001 << 5)  /*!< R/W 0x0  When this bit is enable, the interrupt is issued when RX beacon frame with fcs error occurs in port0.*/
#define BIT_RXBCN_TIMEUP_INT_EXT_SW_EN       ((u32)0x00000001 << 4)  /*!< R/W 0x0  When this bit is enable, the interrupt is issued when RX beacon frame timeout occurs in port0.*/
#define BIT_RXBCN_TSF_GT_THRES_INT_EXT_SW_EN ((u32)0x00000001 << 3)  /*!< R/W 0x0  The interrupt is issued when difference of tsft in beacon frame of port0 is greater than threshold*/
#define BIT_TBTT0_INT_EXT_SW_EN              ((u32)0x00000001 << 2)  /*!< R/W 0x0  the interrupt  from the exact TBTT time for P0 MBSSID0.*/
#define BIT_BCNELY0_AGGR_INT_EXT_SW_EN       ((u32)0x00000001 << 1)  /*!< R/W 0x0  port 0 Beacon early aggregation interrupt*/
#define BIT_BCNERLY0_INT_EXT_SW_EN           ((u32)0x00000001 << 0)  /*!< R/W 0x0  This interrupt is issued at the time set by DRVERLYINT register before TBTT0_MB0 time.*/
/** @} */

/** @defgroup REG_HIMR0
  * @brief
  * @{
  */
#define BIT_HS_TRIG_LAT_AUDIO_CNT_INT_EN ((u32)0x00000001 << 23) /*!< R/W 0x0  */
#define BIT_HS_C2H_MSG_INT_EN            ((u32)0x00000001 << 22) /*!< R/W 0x0  */
#define BIT_HS_CPWM_INT_EN               ((u32)0x00000001 << 21) /*!< R/W 0x0  */
#define BIT_HS_BCNELY0_INT_EN            ((u32)0x00000001 << 20) /*!< R/W 0x0  */
#define BIT_HS_BCNELY1_INT_EN            ((u32)0x00000001 << 19) /*!< R/W 0x0  */
#define BIT_HS_BCNELY_DISC_INT_EN        ((u32)0x00000001 << 18) /*!< R/W 0x0  */
#define BIT_HS_BCNELY_SYNC_2G_INT_EN     ((u32)0x00000001 << 17) /*!< R/W 0x0  */
#define BIT_HS_BCNELY_SYNC_5G_INT_EN     ((u32)0x00000001 << 16) /*!< R/W 0x0  */
#define BIT_HS_BCNELY0_AGGR_INT_EN       ((u32)0x00000001 << 15) /*!< R/W 0x0  */
#define BIT_HS_TBTT0_INT_EN              ((u32)0x00000001 << 14) /*!< R/W 0x0  */
#define BIT_HS_TBTT1_INT_EN              ((u32)0x00000001 << 13) /*!< R/W 0x0  */
#define BIT_HS_TBTT_DISC_INT_EN          ((u32)0x00000001 << 12) /*!< R/W 0x0  */
#define BIT_HS_TBTT_SYNC_2G_INT_EN       ((u32)0x00000001 << 11) /*!< R/W 0x0  */
#define BIT_HS_TBTT_SYNC_5G_INT_EN       ((u32)0x00000001 << 10) /*!< R/W 0x0  */
#define BIT_HS_TXBCNOK0_INT_EN           ((u32)0x00000001 << 9)  /*!< R/W 0x0  */
#define BIT_HS_TXBCNOK1_INT_EN           ((u32)0x00000001 << 8)  /*!< R/W 0x0  */
#define BIT_HS_TXBCNERR0_INT_EN          ((u32)0x00000001 << 7)  /*!< R/W 0x0  */
#define BIT_HS_TXBCNERR1_INT_EN          ((u32)0x00000001 << 6)  /*!< R/W 0x0  */
#define BIT_HS_TXBCNOK_DISC_INT_EN       ((u32)0x00000001 << 5)  /*!< R/W 0x0  */
#define BIT_HS_TXBCNOK_SYNC_INT_EN       ((u32)0x00000001 << 4)  /*!< R/W 0x0  */
#define BIT_HS_TXBCNERR_DISC_INT_EN      ((u32)0x00000001 << 3)  /*!< R/W 0x0  */
#define BIT_HS_TXBCNERR_SYNC_INT_EN      ((u32)0x00000001 << 2)  /*!< R/W 0x0  */
#define BIT_HS_SDF_START_INT_EN          ((u32)0x00000001 << 1)  /*!< R/W 0x0  */
#define BIT_HS_DWWIN_END_INT_EN          ((u32)0x00000001 << 0)  /*!< R/W 0x0  */
/** @} */

/** @defgroup REG_HISR0
  * @brief
  * @{
  */
#define BIT_HS_TRIG_LAT_AUDIO_CNT_INT ((u32)0x00000001 << 23) /*!< RW1CB 0x0  */
#define BIT_HS_C2H_MSG_INT            ((u32)0x00000001 << 22) /*!< RW1CB 0x0  */
#define BIT_HS_CPWM_INT               ((u32)0x00000001 << 21) /*!< RW1CB 0x0  */
#define BIT_HS_BCNELY0_INT            ((u32)0x00000001 << 20) /*!< RW1CB 0x0  */
#define BIT_HS_BCNELY1_INT            ((u32)0x00000001 << 19) /*!< RW1CB 0x0  */
#define BIT_HS_BCNELY_DISC_INT        ((u32)0x00000001 << 18) /*!< RW1CB 0x0  */
#define BIT_HS_BCNELY_SYNC_2G_INT     ((u32)0x00000001 << 17) /*!< RW1CB 0x0  */
#define BIT_HS_BCNELY_SYNC_5G_INT     ((u32)0x00000001 << 16) /*!< RW1CB 0x0  */
#define BIT_HS_BCNELY0_AGGR_INT       ((u32)0x00000001 << 15) /*!< RW1CB 0x0  */
#define BIT_HS_TBTT0_INT              ((u32)0x00000001 << 14) /*!< RW1CB 0x0  */
#define BIT_HS_TBTT1_INT              ((u32)0x00000001 << 13) /*!< RW1CB 0x0  */
#define BIT_HS_TBTT_DISC_INT          ((u32)0x00000001 << 12) /*!< RW1CB 0x0  */
#define BIT_HS_TBTT_SYNC_2G_INT       ((u32)0x00000001 << 11) /*!< RW1CB 0x0  */
#define BIT_HS_TBTT_SYNC_5G_INT       ((u32)0x00000001 << 10) /*!< RW1CB 0x0  */
#define BIT_HS_TXBCNOK0_INT           ((u32)0x00000001 << 9)  /*!< RW1CB 0x0  */
#define BIT_HS_TXBCNOK1_INT           ((u32)0x00000001 << 8)  /*!< RW1CB 0x0  */
#define BIT_HS_TXBCNERR0_INT          ((u32)0x00000001 << 7)  /*!< RW1CB 0x0  */
#define BIT_HS_TXBCNERR1_INT          ((u32)0x00000001 << 6)  /*!< RW1CB 0x0  */
#define BIT_HS_TXBCNOK_DISC_INT       ((u32)0x00000001 << 5)  /*!< RW1CB 0x0  */
#define BIT_HS_TXBCNOK_SYNC_INT       ((u32)0x00000001 << 4)  /*!< RW1CB 0x0  */
#define BIT_HS_TXBCNERR_DISC_INT      ((u32)0x00000001 << 3)  /*!< RW1CB 0x0  */
#define BIT_HS_TXBCNERR_SYNC_INT      ((u32)0x00000001 << 2)  /*!< RW1CB 0x0  */
#define BIT_HS_SDF_START_INT          ((u32)0x00000001 << 1)  /*!< RW1CB 0x0  */
#define BIT_HS_DWWIN_END_INT          ((u32)0x00000001 << 0)  /*!< RW1CB 0x0  */
/** @} */

/** @defgroup REG_HIMR1
  * @brief
  * @{
  */
#define BIT_HS_RXFF_FULL_INT_EN                  ((u32)0x00000001 << 31) /*!< R/W 0x0  */
#define BIT_HS_RXTMREQ_INT_EN                    ((u32)0x00000001 << 30) /*!< R/W 0x0  */
#define BIT_HS_RXTM_INT_EN                       ((u32)0x00000001 << 29) /*!< R/W 0x0  */
#define BIT_HS_TXTM_INT_EN                       ((u32)0x00000001 << 28) /*!< R/W 0x0  */
#define BIT_HS_TXRPT_INT_EN                      ((u32)0x00000001 << 27) /*!< R/W 0x0  */
#define BIT_HS_BCN_IE_0_HIT_INT_EN               ((u32)0x00000001 << 26) /*!< R/W 0x0  */
#define BIT_HS_BCN_IE_1_HIT_INT_EN               ((u32)0x00000001 << 25) /*!< R/W 0x0  */
#define BIT_HS_BC_TWT_PARA_CHG_INT_EN            ((u32)0x00000001 << 24) /*!< R/W 0x0  */
#define BIT_HS_RSSI_MATCH_INT_EN                 ((u32)0x00000001 << 23) /*!< R/W 0x0  */
#define BIT_HS_OPS_TIM_HIT_INT_EN                ((u32)0x00000001 << 22) /*!< R/W 0x0  */
#define BIT_HS_RXUC_BBYE_OK_INT_EN               ((u32)0x00000001 << 21) /*!< R/W 0x0  */
#define BIT_HS_RXBD_RD_WR_ERR_INT_EN             ((u32)0x00000001 << 20) /*!< R/W 0x0  */
#define BIT_HS_RXBD_ADDR_UNALIGN_ERR_INT_EN      ((u32)0x00000001 << 19) /*!< R/W 0x0  */
#define BIT_HS_TXBD_RD_WR_ERR_INT_EN             ((u32)0x00000001 << 18) /*!< R/W 0x0  */
#define BIT_HS_TXBD_ADDR_UNALIGN_ERR_INT_EN      ((u32)0x00000001 << 17) /*!< R/W 0x0  */
#define BIT_HS_SETRXBD_UNAVAIL_INT_EN            ((u32)0x00000001 << 16) /*!< R/W 0x0  */
#define BIT_HS_SETCSIBD_UNAVAIL_INT_EN           ((u32)0x00000001 << 15) /*!< R/W 0x0  */
#define BIT_HS_SETRXBD_USED_FIFO_NONZERO_INT_EN  ((u32)0x00000001 << 14) /*!< R/W 0x0  */
#define BIT_HS_SETCSIBD_USED_FIFO_NONZERO_INT_EN ((u32)0x00000001 << 13) /*!< R/W 0x0  */
#define BIT_HS_RLS_BCNQ0_INT_EN                  ((u32)0x00000001 << 12) /*!< R/W 0x0  */
#define BIT_HS_RLS_BCNQ1_INT_EN                  ((u32)0x00000001 << 11) /*!< R/W 0x0  */
#define BIT_HS_RLS_FIFO_ALMOST_FULL_DRV_INT_EN   ((u32)0x00000001 << 10) /*!< R/W 0x0  */
#define BIT_HS_RLS_FIFO_FULL_DRV_INT_EN          ((u32)0x00000001 << 9)  /*!< R/W 0x0  */
#define BIT_HS_RLS_FIFO_VALID_DRV_INT_EN         ((u32)0x00000001 << 8)  /*!< R/W 0x0  */
#define BIT_HS_WLAN_RX_STOP_INT_EN               ((u32)0x00000001 << 7)  /*!< R/W 0x0  */
#define BIT_HS_WLAN_RX_START_INT_EN              ((u32)0x00000001 << 6)  /*!< R/W 0x0  */
#define BIT_HS_WLAN_TX_STOP_INT_EN               ((u32)0x00000001 << 5)  /*!< R/W 0x0  */
#define BIT_HS_WLAN_TX_START_INT_EN              ((u32)0x00000001 << 4)  /*!< R/W 0x0  */
#define BIT_HS_BT_RX_STOP_INT_EN                 ((u32)0x00000001 << 3)  /*!< R/W 0x0  */
#define BIT_HS_BT_RX_START_INT_EN                ((u32)0x00000001 << 2)  /*!< R/W 0x0  */
#define BIT_HS_BT_TX_STOP_INT_EN                 ((u32)0x00000001 << 1)  /*!< R/W 0x0  */
#define BIT_HS_BT_TX_START_INT_EN                ((u32)0x00000001 << 0)  /*!< R/W 0x0  */
/** @} */

/** @defgroup REG_HISR1
  * @brief
  * @{
  */
#define BIT_HS_RXFF_FULL_INT                  ((u32)0x00000001 << 31) /*!< RW1CB 0x0  */
#define BIT_HS_RXTMREQ_INT                    ((u32)0x00000001 << 30) /*!< RW1CB 0x0  */
#define BIT_HS_RXTM_INT                       ((u32)0x00000001 << 29) /*!< RW1CB 0x0  */
#define BIT_HS_TXTM_INT                       ((u32)0x00000001 << 28) /*!< RW1CB 0x0  */
#define BIT_HS_TXRPT_INT                      ((u32)0x00000001 << 27) /*!< RW1CB 0x0  */
#define BIT_HS_BCN_IE_0_HIT_INT               ((u32)0x00000001 << 26) /*!< RW1CB 0x0  */
#define BIT_HS_BCN_IE_1_HIT_INT               ((u32)0x00000001 << 25) /*!< RW1CB 0x0  */
#define BIT_HS_BC_TWT_PARA_CHG_INT            ((u32)0x00000001 << 24) /*!< RW1CB 0x0  */
#define BIT_HS_RSSI_MATCH_INT                 ((u32)0x00000001 << 23) /*!< RW1CB 0x0  */
#define BIT_HS_OPS_TIM_HIT_INT                ((u32)0x00000001 << 22) /*!< RW1CB 0x0  */
#define BIT_HS_RXUC_BBYE_OK_INT               ((u32)0x00000001 << 21) /*!< RW1CB 0x0  */
#define BIT_HS_RXBD_RD_WR_ERR_INT             ((u32)0x00000001 << 20) /*!< RW1CB 0x0  */
#define BIT_HS_RXBD_ADDR_UNALIGN_ERR_INT      ((u32)0x00000001 << 19) /*!< RW1CB 0x0  */
#define BIT_HS_TXBD_RD_WR_ERR_INT             ((u32)0x00000001 << 18) /*!< RW1CB 0x0  */
#define BIT_HS_TXBD_ADDR_UNALIGN_ERR_INT      ((u32)0x00000001 << 17) /*!< RW1CB 0x0  */
#define BIT_HS_SETRXBD_UNAVAIL_INT            ((u32)0x00000001 << 16) /*!< RW1CB 0x0  */
#define BIT_HS_SETCSIBD_UNAVAIL_INT           ((u32)0x00000001 << 15) /*!< RW1CB 0x0  */
#define BIT_HS_SETRXBD_USED_FIFO_NONZERO_INT  ((u32)0x00000001 << 14) /*!< RW1CB 0x0  */
#define BIT_HS_SETCSIBD_USED_FIFO_NONZERO_INT ((u32)0x00000001 << 13) /*!< RW1CB 0x0  */
#define BIT_HS_RLS_BCNQ0_INT                  ((u32)0x00000001 << 12) /*!< RW1CB 0x0  */
#define BIT_HS_RLS_BCNQ1_INT                  ((u32)0x00000001 << 11) /*!< RW1CB 0x0  */
#define BIT_HS_RLS_FIFO_ALMOST_FULL_DRV_INT   ((u32)0x00000001 << 10) /*!< RW1CB 0x0  */
#define BIT_HS_RLS_FIFO_FULL_DRV_INT          ((u32)0x00000001 << 9)  /*!< RW1CB 0x0  */
#define BIT_HS_RLS_FIFO_VALID_DRV_INT         ((u32)0x00000001 << 8)  /*!< RW1CB 0x0  */
#define BIT_HS_WLAN_RX_STOP_INT               ((u32)0x00000001 << 7)  /*!< RW1CB 0x0  */
#define BIT_HS_WLAN_RX_START_INT              ((u32)0x00000001 << 6)  /*!< RW1CB 0x0  */
#define BIT_HS_WLAN_TX_STOP_INT               ((u32)0x00000001 << 5)  /*!< RW1CB 0x0  */
#define BIT_HS_WLAN_TX_START_INT              ((u32)0x00000001 << 4)  /*!< RW1CB 0x0  */
#define BIT_HS_BT_RX_STOP_INT                 ((u32)0x00000001 << 3)  /*!< RW1CB 0x0  */
#define BIT_HS_BT_RX_START_INT                ((u32)0x00000001 << 2)  /*!< RW1CB 0x0  */
#define BIT_HS_BT_TX_STOP_INT                 ((u32)0x00000001 << 1)  /*!< RW1CB 0x0  */
#define BIT_HS_BT_TX_START_INT                ((u32)0x00000001 << 0)  /*!< RW1CB 0x0  */
/** @} */

/** @defgroup REG_FIMR0
  * @brief
  * @{
  */
#define BIT_FISR1_INT_EN               ((u32)0x00000001 << 30) /*!< R/W 0x0  FISR1 Indicator*/
#define BIT_FISR2_INT_EN               ((u32)0x00000001 << 29) /*!< R/W 0x0  FISR2 Indicator*/
#define BIT_FISR3_INT_EN               ((u32)0x00000001 << 28) /*!< R/W 0x0  FISR3 Indicator*/
#define BIT_FS_GTINT_EN5_INT_EN        ((u32)0x00000001 << 27) /*!< R/W 0x0  General Timer[5] interrupt*/
#define BIT_FS_GTINT_EN4_INT_EN        ((u32)0x00000001 << 26) /*!< R/W 0x0  General Timer[4] interrupt*/
#define BIT_FS_BT2WL_SCOREBOARD_INT_EN ((u32)0x00000001 << 25) /*!< R/W 0x0  */
#define BIT_FS_TBTT0_INT_EN            ((u32)0x00000001 << 24) /*!< R/W 0x0  */
#define BIT_FS_RPWM_INT_EN             ((u32)0x00000001 << 23) /*!< R/W 0x0  */
#define BIT_FS_H2C_MSG_INT_EN          ((u32)0x00000001 << 22) /*!< R/W 0x0  */
#define BIT_FS_P0_TBTT_AGG_INT_EN      ((u32)0x00000001 << 21) /*!< R/W 0x0  the interrupt  from the multiplt TBTT times for P0.*/
#define BIT_FS_BCNELY0_INT_EN          ((u32)0x00000001 << 20) /*!< R/W 0x0  */
#define BIT_FS_BCNELY1_INT_EN          ((u32)0x00000001 << 19) /*!< R/W 0x0  */
#define BIT_FS_BCNELY0_AGGR_INT_EN     ((u32)0x00000001 << 18) /*!< R/W 0x0  */
#define BIT_FS_BCNELY_DISC_INT_EN      ((u32)0x00000001 << 17) /*!< R/W 0x0  */
#define BIT_FS_BCNELY_SYNC_2G_INT_EN   ((u32)0x00000001 << 16) /*!< R/W 0x0  */
#define BIT_FS_BCNELY_SYNC_5G_INT_EN   ((u32)0x00000001 << 15) /*!< R/W 0x0  */
#define BIT_FS_FTM_PTT_INT_EN          ((u32)0x00000001 << 14) /*!< R/W 0x0  */
#define BIT_FS_PS_ELY_TIMER_E_INT_EN   ((u32)0x00000001 << 13) /*!< R/W 0x0  */
#define BIT_FS_PS_ELY_TIMER_D_INT_EN   ((u32)0x00000001 << 12) /*!< R/W 0x0  */
#define BIT_FS_PS_ELY_TIMER_C_INT_EN   ((u32)0x00000001 << 11) /*!< R/W 0x0  */
#define BIT_FS_PS_ELY_TIMER_B_INT_EN   ((u32)0x00000001 << 10) /*!< R/W 0x0  */
#define BIT_FS_PS_ELY_TIMER_A_INT_EN   ((u32)0x00000001 << 9)  /*!< R/W 0x0  */
#define BIT_FS_PS_TIMER_E_INT_EN       ((u32)0x00000001 << 8)  /*!< R/W 0x0  */
#define BIT_FS_PS_TIMER_D_INT_EN       ((u32)0x00000001 << 7)  /*!< R/W 0x0  */
#define BIT_FS_PS_TIMER_C_INT_EN       ((u32)0x00000001 << 6)  /*!< R/W 0x0  */
#define BIT_FS_PS_TIMER_B_INT_EN       ((u32)0x00000001 << 5)  /*!< R/W 0x0  */
#define BIT_FS_PS_TIMER_A_INT_EN       ((u32)0x00000001 << 4)  /*!< R/W 0x0  */
#define BIT_FS_GTINT_EN3_INT_EN        ((u32)0x00000001 << 3)  /*!< R/W 0x0  General Timer[3] interrupt*/
#define BIT_FS_GTINT_EN2_INT_EN        ((u32)0x00000001 << 2)  /*!< R/W 0x0  General Timer[2] interrupt*/
#define BIT_FS_GTINT_EN1_INT_EN        ((u32)0x00000001 << 1)  /*!< R/W 0x0  General Timer[1] interrupt*/
#define BIT_FS_GTINT_EN0_INT_EN        ((u32)0x00000001 << 0)  /*!< R/W 0x0  General Timer[0] interrupt*/
/** @} */

/** @defgroup REG_FISR0
  * @brief
  * @{
  */
#define BIT_FISR1_INT               ((u32)0x00000001 << 30) /*!< RW1CB 0x0  FISR1 Indicator*/
#define BIT_FISR2_INT               ((u32)0x00000001 << 29) /*!< RW1CB 0x0  FISR2 Indicator*/
#define BIT_FISR3_INT               ((u32)0x00000001 << 28) /*!< RW1CB 0x0  FISR3 Indicator*/
#define BIT_FS_GTINT5_INT           ((u32)0x00000001 << 27) /*!< RW1CB 0x0  General Timer[5] interrupt*/
#define BIT_FS_GTINT4_INT           ((u32)0x00000001 << 26) /*!< RW1CB 0x0  General Timer[4] interrupt*/
#define BIT_FS_BT2WL_SCOREBOARD_INT ((u32)0x00000001 << 25) /*!< RW1CB 0x0  */
#define BIT_FS_TBTT0_INT            ((u32)0x00000001 << 24) /*!< RW1CB 0x0  */
#define BIT_FS_RPWM_INT             ((u32)0x00000001 << 23) /*!< RW1CB 0x0  */
#define BIT_FS_H2C_MSG_INT          ((u32)0x00000001 << 22) /*!< RW1CB 0x0  */
#define BIT_FS_P0_TBTT_AGG_INT      ((u32)0x00000001 << 21) /*!< RW1CB 0x0  the interrupt  from the multiplt TBTT times for P0.*/
#define BIT_FS_BCNELY0_INT          ((u32)0x00000001 << 20) /*!< RW1CB 0x0  */
#define BIT_FS_BCNELY1_INT          ((u32)0x00000001 << 19) /*!< RW1CB 0x0  */
#define BIT_FS_BCNELY0_AGGR_INT     ((u32)0x00000001 << 18) /*!< RW1CB 0x0  */
#define BIT_FS_BCNELY_DISC_INT      ((u32)0x00000001 << 17) /*!< RW1CB 0x0  */
#define BIT_FS_BCNELY_SYNC_2G_INT   ((u32)0x00000001 << 16) /*!< RW1CB 0x0  */
#define BIT_FS_BCNELY_SYNC_5G_INT   ((u32)0x00000001 << 15) /*!< RW1CB 0x0  */
#define BIT_FS_FTM_PTT_INT          ((u32)0x00000001 << 14) /*!< RW1CB 0x0  */
#define BIT_FS_PS_ELY_TIMER_E_INT   ((u32)0x00000001 << 13) /*!< RW1CB 0x0  */
#define BIT_FS_PS_ELY_TIMER_D_INT   ((u32)0x00000001 << 12) /*!< RW1CB 0x0  */
#define BIT_FS_PS_ELY_TIMER_C_INT   ((u32)0x00000001 << 11) /*!< RW1CB 0x0  */
#define BIT_FS_PS_ELY_TIMER_B_INT   ((u32)0x00000001 << 10) /*!< RW1CB 0x0  */
#define BIT_FS_PS_ELY_TIMER_A_INT   ((u32)0x00000001 << 9)  /*!< RW1CB 0x0  */
#define BIT_FS_PS_TIMER_E_INT       ((u32)0x00000001 << 8)  /*!< RW1CB 0x0  */
#define BIT_FS_PS_TIMER_D_INT       ((u32)0x00000001 << 7)  /*!< RW1CB 0x0  */
#define BIT_FS_PS_TIMER_C_INT       ((u32)0x00000001 << 6)  /*!< RW1CB 0x0  */
#define BIT_FS_PS_TIMER_B_INT       ((u32)0x00000001 << 5)  /*!< RW1CB 0x0  */
#define BIT_FS_PS_TIMER_A_INT       ((u32)0x00000001 << 4)  /*!< RW1CB 0x0  */
#define BIT_FS_GTINT3_INT           ((u32)0x00000001 << 3)  /*!< RW1CB 0x0  General Timer[3] interrupt*/
#define BIT_FS_GTINT2_INT           ((u32)0x00000001 << 2)  /*!< RW1CB 0x0  General Timer[2] interrupt*/
#define BIT_FS_GTINT1_INT           ((u32)0x00000001 << 1)  /*!< RW1CB 0x0  General Timer[1] interrupt*/
#define BIT_FS_GTINT0_INT           ((u32)0x00000001 << 0)  /*!< RW1CB 0x0  General Timer[0] interrupt*/
/** @} */

/** @defgroup REG_FIMR1
  * @brief
  * @{
  */
#define BIT_FS_RADAR_SEG_END_INT_EN   ((u32)0x00000001 << 22) /*!< R/W 0x0  */
#define BIT_FS_RADAR_OK_INT_EN        ((u32)0x00000001 << 21) /*!< R/W 0x0  */
#define BIT_FS_RADAR_FAIL_INT_EN      ((u32)0x00000001 << 20) /*!< R/W 0x0  */
#define BIT_FS_RADAR_TIMEOUT_INT_EN   ((u32)0x00000001 << 19) /*!< R/W 0x0  */
#define BIT_FS_TBTT1_INT_EN           ((u32)0x00000001 << 18) /*!< R/W 0x0  */
#define BIT_FS_TBTT_DISC_INT_EN       ((u32)0x00000001 << 17) /*!< R/W 0x0  */
#define BIT_FS_TBTT_SYNC_2G_INT_EN    ((u32)0x00000001 << 16) /*!< R/W 0x0  */
#define BIT_FS_TBTT_SYNC_5G_INT_EN    ((u32)0x00000001 << 15) /*!< R/W 0x0  */
#define BIT_FS_TXBCNOK0_INT_EN        ((u32)0x00000001 << 14) /*!< R/W 0x0  */
#define BIT_FS_TXBCNOK1_INT_EN        ((u32)0x00000001 << 13) /*!< R/W 0x0  */
#define BIT_FS_TXBCNERR0_INT_EN       ((u32)0x00000001 << 12) /*!< R/W 0x0  */
#define BIT_FS_TXBCNERR1_INT_EN       ((u32)0x00000001 << 11) /*!< R/W 0x0  */
#define BIT_FS_TXBCNOK_DISC_INT_EN    ((u32)0x00000001 << 10) /*!< R/W 0x0  */
#define BIT_FS_TXBCNOK_SYNC_INT_EN    ((u32)0x00000001 << 9)  /*!< R/W 0x0  */
#define BIT_FS_TXBCNERR_DISC_INT_EN   ((u32)0x00000001 << 8)  /*!< R/W 0x0  */
#define BIT_FS_TXBCNERR_SYNC_INT_EN   ((u32)0x00000001 << 7)  /*!< R/W 0x0  */
#define BIT_FS_SDF_START_INT_EN       ((u32)0x00000001 << 6)  /*!< R/W 0x0  */
#define BIT_FS_DWWIN_END_INT_EN       ((u32)0x00000001 << 5)  /*!< R/W 0x0  */
#define BIT_FS_TXRPT_INT_EN           ((u32)0x00000001 << 4)  /*!< R/W 0x0  */
#define BIT_FS_BCN_IE_0_HIT_INT_EN    ((u32)0x00000001 << 3)  /*!< R/W 0x0  */
#define BIT_FS_BCN_IE_1_HIT_INT_EN    ((u32)0x00000001 << 2)  /*!< R/W 0x0  */
#define BIT_FS_BC_TWT_PARA_CHG_INT_EN ((u32)0x00000001 << 1)  /*!< R/W 0x0  */
#define BIT_FS_RSSI_MATCH_INT_EN      ((u32)0x00000001 << 0)  /*!< R/W 0x0  */
/** @} */

/** @defgroup REG_FIMR2
  * @brief
  * @{
  */
#define BIT_FS_WLBB_HIGH_PRI_INT_EN              ((u32)0x00000001 << 29) /*!< R/W 0x0  */
#define BIT_FS_WLBB_LOW_PRI_INT_EN               ((u32)0x00000001 << 28) /*!< R/W 0x0  */
#define BIT_FS_HIOE_CHN_BB_HW_INT_EN             ((u32)0x00000001 << 27) /*!< R/W 0x0  */
#define BIT_FS_TRIG_LAT_AUDIO_CNT_INT_EN         ((u32)0x00000001 << 26) /*!< R/W 0x0  */
#define BIT_FS_RXBCN_TSF_GT_THRES_INT_EN         ((u32)0x00000001 << 25) /*!< R/W 0x0  */
#define BIT_FS_RXBCN_TIMEUP_CNT_INT_EN           ((u32)0x00000001 << 24) /*!< R/W 0x0  */
#define BIT_FS_RXBCN_TIMEUP_CNT1_INT_EN          ((u32)0x00000001 << 23) /*!< R/W 0x0  */
#define BIT_FS_RXBCN_TIME_UP_INT_EN              ((u32)0x00000001 << 22) /*!< R/W 0x0  */
#define BIT_FS_RX_BCN_ERR_P0_INT_EN              ((u32)0x00000001 << 21) /*!< R/W 0x0  */
#define BIT_FS_RX_BCN_OK_P0_INT_EN               ((u32)0x00000001 << 20) /*!< R/W 0x0  */
#define BIT_FS_TIM_NO_HIT_INT_EN                 ((u32)0x00000001 << 19) /*!< R/W 0x0  */
#define BIT_FS_TIM_HIT_INT_EN                    ((u32)0x00000001 << 18) /*!< R/W 0x0  */
#define BIT_FS_HIOE_CHN_ON_INT_EN                ((u32)0x00000001 << 17) /*!< R/W 0x0  */
#define BIT_FS_HIOE_CHN_OFF_INT_EN               ((u32)0x00000001 << 16) /*!< R/W 0x0  */
#define BIT_FS_HIOE_CHN_MAC_HW1_INT_EN           ((u32)0x00000001 << 15) /*!< R/W 0x0  */
#define BIT_FS_HIOE_CHN_MAC_HW0_INT_EN           ((u32)0x00000001 << 14) /*!< R/W 0x0  */
#define BIT_FS_HIOE_CHN_BCN_MODE_INT_EN          ((u32)0x00000001 << 13) /*!< R/W 0x0  */
#define BIT_FS_CCA2HIOE_TSFT_AVG_GT_THRES_INT_EN ((u32)0x00000001 << 12) /*!< R/W 0x0  */
#define BIT_FS_EDCCA_IDLE_TOCNT_INT_EN           ((u32)0x00000001 << 11) /*!< R/W 0x0  */
#define BIT_FS_RXBCN_CNT_END_INT_EN              ((u32)0x00000001 << 10) /*!< R/W 0x0  */
#define BIT_FS_RXFTMREQ_INT_EN                   ((u32)0x00000001 << 9)  /*!< R/W 0x0  */
#define BIT_FS_RXFTM_INT_EN                      ((u32)0x00000001 << 8)  /*!< R/W 0x0  */
#define BIT_FS_TXFTM_INT_EN                      ((u32)0x00000001 << 7)  /*!< R/W 0x0  */
#define BIT_FS_BTCMD_INT_EN                      ((u32)0x00000001 << 6)  /*!< R/W 0x0  */
#define BIT_FS_BT_MAILBOX_INT_EN                 ((u32)0x00000001 << 5)  /*!< R/W 0x0  */
#define BIT_FS_GNT_BT_BB_FALL_INT_EN             ((u32)0x00000001 << 4)  /*!< R/W 0x0  */
#define BIT_FS_GNT_BT_BB_RISE_INT_EN             ((u32)0x00000001 << 3)  /*!< R/W 0x0  */
#define BIT_FS_BT_GPIO_TOGGLE_INT_EN             ((u32)0x00000001 << 2)  /*!< R/W 0x0  */
#define BIT_FS_FSM1_CHK_HANG_TO_INT_EN           ((u32)0x00000001 << 1)  /*!< R/W 0x0  */
#define BIT_FS_FSM0_CHK_HANG_TO_INT_EN           ((u32)0x00000001 << 0)  /*!< R/W 0x0  */
/** @} */

/** @defgroup REG_FIMR3
  * @brief
  * @{
  */
#define BIT_FS_RXPLCP_CHKOK_INT_EN            ((u32)0x00000001 << 24) /*!< R/W 0x0  RXPCLP check ok interrupt*/
#define BIT_FS_RXDONE0_INT_EN                 ((u32)0x00000001 << 23) /*!< R/W 0x0  Rx Packet 0 done interrupt (for WOL release packet)*/
#define BIT_FS_RX_UCMD0_INT_EN                ((u32)0x00000001 << 22) /*!< R/W 0x0  The interrupt is issued while receiving unicast data frame with More Data=0*/
#define BIT_FS_RX_UCMD1_INT_EN                ((u32)0x00000001 << 21) /*!< R/W 0x0  The interrupt is issued while receiving unicast data frame with More Data=1*/
#define BIT_FS_RX_BCMD0_INT_EN                ((u32)0x00000001 << 20) /*!< R/W 0x0  The interrupt is issued while receiving broadcast data frame with More Data=0*/
#define BIT_FS_RX_BCMD1_INT_EN                ((u32)0x00000001 << 19) /*!< R/W 0x0  The interrupt is issued while receiving broadcast data frame with More Data=1*/
#define BIT_FS_RX_UAPSDMD1_INT_EN             ((u32)0x00000001 << 18) /*!< R/W 0x0  Setting this bit indicates Rx pkt is matched with one of below: 1.) QoS Unicast data frame with MD=1, UAPSD=0 2.) NonQoS Unicast data frame with MD=1*/
#define BIT_FS_RX_UAPSDMD0_INT_EN             ((u32)0x00000001 << 17) /*!< R/W 0x0  Setting this bit indicates Rx pkt is matched with one of below: 1.) QoS Unicast data frame with MD=0, UAPSD=0 2.) NonQoS Unicast data frame with MD=0*/
#define BIT_FS_EOSP_INT_EN                    ((u32)0x00000001 << 16) /*!< R/W 0x0  EOSP_INT interrupt mask*/
#define BIT_FS_RXUCMD0_ACK_INT_EN             ((u32)0x00000001 << 15) /*!< R/W 0x0  */
#define BIT_FS_RXUCMD1_ACK_INT_EN             ((u32)0x00000001 << 14) /*!< R/W 0x0  */
#define BIT_FS_RXBCMD0_ACK_INT_EN             ((u32)0x00000001 << 13) /*!< R/W 0x0  */
#define BIT_FS_RXBCMD1_ACK_INT_EN             ((u32)0x00000001 << 12) /*!< R/W 0x0  */
#define BIT_FS_RX_MORE_TF0_INT_EN             ((u32)0x00000001 << 11) /*!< R/W 0x0  */
#define BIT_FS_RX_MORE_TF1_INT_EN             ((u32)0x00000001 << 10) /*!< R/W 0x0  */
#define BIT_FS_ERR_HAPPENED_INT_EN            ((u32)0x00000001 << 9)  /*!< R/W 0x0  FWHW/ WMAC error status interrupt(0x4E2[15:0], 0x6B8[31:0]). WMAC error state will be recovered by HW, the others won't.*/
#define BIT_FS_P0_PKTIN_INT_EN                ((u32)0x00000001 << 8)  /*!< R/W 0x0  port 0 packet assign to queue interrupt*/
#define BIT_FS_P1_PKTIN_INT_EN                ((u32)0x00000001 << 7)  /*!< R/W 0x0  port 1 packet assign to queue interrupt*/
#define BIT_FS_TX_NULL1_P0_INT_EN             ((u32)0x00000001 << 6)  /*!< R/W 0x0  TX null 1 packet done interrupt*/
#define BIT_FS_TX_NULL0_P0_INT_EN             ((u32)0x00000001 << 5)  /*!< R/W 0x0  TX null 0 packet done interrupt*/
#define BIT_FS_TRIGGER_PKT_INT_EN             ((u32)0x00000001 << 4)  /*!< R/W 0x0  tx TRIGGER_PKT interrupt*/
#define BIT_FS_RLS_FIFO_ALMOST_FULL_FW_INT_EN ((u32)0x00000001 << 3)  /*!< R/W 0x0  */
#define BIT_FS_RLS_FIFO_FULL_FW_INT_EN        ((u32)0x00000001 << 2)  /*!< R/W 0x0  */
#define BIT_FS_RLS_FIFO_VALID_FW_INT_EN       ((u32)0x00000001 << 1)  /*!< R/W 0x0  */
#define BIT_FS_FW_CPUMGQ_RLS_INT_EN           ((u32)0x00000001 << 0)  /*!< R/W 0x0  */
/** @} */

/** @defgroup REG_TC4_CTRL
  * @brief Counter 4 CONTROL
  * @{
  */
#define BIT_TC4START       ((u32)0x00000001 << 26)          /*!< WA0 0x0  When write "1" to this bit, Counter 0 starts counting down. This is a one-bit pulse.*/
#define BIT_TC4MODE        ((u32)0x00000001 << 25)          /*!< R/W 0x0  Timer/Counter 4 mode  0=counter mode 1=timer mode*/
#define BIT_TC4EN          ((u32)0x00000001 << 24)          /*!< R/W 0x0  Timer/Counter 4 enable*/
#define BIT_MASK_TC4DATA   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  Timer/Counter 4 data register. It specifies the time-out duration.*/
#define BIT_TC4DATA(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_TC4DATA(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_TC5_CTRL
  * @brief Counter 5 CONTROL
  * @{
  */
#define BIT_TC5START       ((u32)0x00000001 << 26)          /*!< WA0 0x0  When write "1" to this bit, Counter 0 starts counting down. This is a one-bit pulse.*/
#define BIT_TC5MODE        ((u32)0x00000001 << 25)          /*!< R/W 0x0  Timer/Counter 5 mode  0=counter mode 1=timer mode*/
#define BIT_TC5EN          ((u32)0x00000001 << 24)          /*!< R/W 0x0  Timer/Counter 5 enable*/
#define BIT_MASK_TC5DATA   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  Timer/Counter 5 data register. It specifies the time-out duration.*/
#define BIT_TC5DATA(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_TC5DATA(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_TC0_CTRL
  * @brief Counter 0 CONTROL
  * @{
  */
#define BIT_TC0START       ((u32)0x00000001 << 26)          /*!< WA0 0x0  When write "1" to this bit, Counter 0 starts counting down. This is a one-bit pulse.*/
#define BIT_TC0MODE        ((u32)0x00000001 << 25)          /*!< R/W 0x0  Timer/Counter 0 mode  0=counter mode 1=timer mode*/
#define BIT_TC0EN          ((u32)0x00000001 << 24)          /*!< R/W 0x0  Timer/Counter 0 enable*/
#define BIT_MASK_TC0DATA   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  Timer/Counter 0 data register. It specifies the time-out duration.*/
#define BIT_TC0DATA(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_TC0DATA(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_TC1_CTRL
  * @brief Counter 1 data
  * @{
  */
#define BIT_TC1START       ((u32)0x00000001 << 26)          /*!< WA0 0x0  When write "1" to this bit, Counter 1 starts counting down. This is a one-bit pulse.*/
#define BIT_TC1MODE        ((u32)0x00000001 << 25)          /*!< R/W 0x0  Timer/Counter 1 mode  0=counter mode 1=timer mode*/
#define BIT_TC1EN          ((u32)0x00000001 << 24)          /*!< R/W 0x0  Timer/Counter 1 enable*/
#define BIT_MASK_TC1DATA   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  Timer/Counter 1 data register. It specifies the time-out duration.*/
#define BIT_TC1DATA(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_TC1DATA(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_TC2_CTRL
  * @brief Counter 2 data
  * @{
  */
#define BIT_TC2START       ((u32)0x00000001 << 26)          /*!< WA0 0x0  When write "1" to this bit, Counter 2 starts counting down. This is a one-bit pulse.*/
#define BIT_TC2MODE        ((u32)0x00000001 << 25)          /*!< R/W 0x0  Timer/Counter 2 mode  0=counter mode 1=timer mode*/
#define BIT_TC2EN          ((u32)0x00000001 << 24)          /*!< R/W 0x0  Timer/Counter 2 enable*/
#define BIT_MASK_TC2DATA   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  Timer/Counter 2 data register. It specifies the time-out duration.*/
#define BIT_TC2DATA(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_TC2DATA(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_TC3_CTRL
  * @brief Counter 3 data
  * @{
  */
#define BIT_TC3START       ((u32)0x00000001 << 26)          /*!< WA0 0x0  When write "1" to this bit, Counter 3 starts counting down. This is a one-bit pulse.*/
#define BIT_TC3MODE        ((u32)0x00000001 << 25)          /*!< R/W 0x0  Timer/Counter 3 mode  0=counter mode 1=timer mode*/
#define BIT_TC3EN          ((u32)0x00000001 << 24)          /*!< R/W 0x0  Timer/Counter 3 enable*/
#define BIT_MASK_TC3DATA   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  Timer/Counter 3 data register. It specifies the time-out duration.*/
#define BIT_TC3DATA(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_TC3DATA(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_HW_IOE_CR_CH0
  * @brief
  * @{
  */
#define BIT_HIOE_ACTIVE_CH0          ((u32)0x00000001 << 31)           /*!< R 0x0  indicate HIOE engine is active*/
#define BIT_HIOE_RESTORE_REQ_CH0     ((u32)0x00000001 << 25)           /*!< R/W/ES 0x0  WLOFF REG restore request, clear by hw*/
#define BIT_HIOE_BACKUP_REQ_CH0      ((u32)0x00000001 << 24)           /*!< R/W/ES 0x0  WLOFF REG backup request, clear by hw*/
#define BIT_MASK_HIOE_END_ADDR_CH0   ((u32)0x00000FFF << 12)           /*!< R/W 0x0  HIOE command end address in txpktbuffer, unit:8byte*/
#define BIT_HIOE_END_ADDR_CH0(x)     (((u32)((x) & 0x00000FFF) << 12))
#define BIT_GET_HIOE_END_ADDR_CH0(x) ((u32)(((x >> 12) & 0x00000FFF)))
#define BIT_MASK_HIOE_STR_ADDR_CH0   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  HIOE command start address in txpktbuffer, unit:8byte*/
#define BIT_HIOE_STR_ADDR_CH0(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_HIOE_STR_ADDR_CH0(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HW_IOE_CR_CHN_ON
  * @brief HW IO Engine Configure Register_CHN_ON
  * @{
  */
#define BIT_HIOE_ACTIVE_CHN_ON          ((u32)0x00000001 << 31)           /*!< R 0x0  indicate HIOE engine is active, used for wlan power on flow*/
#define BIT_HIOE_RESTORE_REQ_CHN_ON     ((u32)0x00000001 << 25)           /*!< R 0x0  WLOFF REG restore request, clear by hw*/
#define BIT_MASK_HIOE_END_ADDR_CHN_ON   ((u32)0x00000FFF << 12)           /*!< R/W 0x0  HIOE command end address in txpktbuffer, unit:8byte*/
#define BIT_HIOE_END_ADDR_CHN_ON(x)     (((u32)((x) & 0x00000FFF) << 12))
#define BIT_GET_HIOE_END_ADDR_CHN_ON(x) ((u32)(((x >> 12) & 0x00000FFF)))
#define BIT_MASK_HIOE_STR_ADDR_CHN_ON   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  HIOE command start address in txpktbuffer, unit:8byte*/
#define BIT_HIOE_STR_ADDR_CHN_ON(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_HIOE_STR_ADDR_CHN_ON(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HW_IOE_CR_CHN_OFF
  * @brief HW IO Engine Configure Register_CHN_OFF
  * @{
  */
#define BIT_HIOE_ACTIVE_CHN_OFF          ((u32)0x00000001 << 31)           /*!< R 0x0  indicate HIOE engine is active, used for wlan power off flow*/
#define BIT_HIOE_RESTORE_REQ_CHN_OFF     ((u32)0x00000001 << 25)           /*!< R 0x0  WLOFF REG restore request, clear by hw*/
#define BIT_MASK_HIOE_END_ADDR_CHN_OFF   ((u32)0x00000FFF << 12)           /*!< R/W 0x0  HIOE command end address in txpktbuffer, unit:8byte*/
#define BIT_HIOE_END_ADDR_CHN_OFF(x)     (((u32)((x) & 0x00000FFF) << 12))
#define BIT_GET_HIOE_END_ADDR_CHN_OFF(x) ((u32)(((x >> 12) & 0x00000FFF)))
#define BIT_MASK_HIOE_STR_ADDR_CHN_OFF   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  HIOE command start address in txpktbuffer, unit:8byte*/
#define BIT_HIOE_STR_ADDR_CHN_OFF(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_HIOE_STR_ADDR_CHN_OFF(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HW_IOE_CR_CHN_MAC_HW0
  * @brief
  * @{
  */
#define BIT_HIOE_ACTIVE_CHN_MAC_HW0          ((u32)0x00000001 << 31)           /*!< R 0x0  indicate HIOE CHN_MAC_HW0 is active*/
#define BIT_HIOE_RESTORE_REQ_CHN_MAC_HW0     ((u32)0x00000001 << 25)           /*!< R 0x0  hw hang trig hioe reset wmac request, clear by hw*/
#define BIT_MASK_HIOE_END_ADDR_CHN_MAC_HW0   ((u32)0x00000FFF << 12)           /*!< R/W 0x0  HIOE command end address in txpktbuffer, unit:8byte*/
#define BIT_HIOE_END_ADDR_CHN_MAC_HW0(x)     (((u32)((x) & 0x00000FFF) << 12))
#define BIT_GET_HIOE_END_ADDR_CHN_MAC_HW0(x) ((u32)(((x >> 12) & 0x00000FFF)))
#define BIT_MASK_HIOE_STR_ADDR_CHN_MAC_HW0   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  HIOE command start address in txpktbuffer, unit:8byte*/
#define BIT_HIOE_STR_ADDR_CHN_MAC_HW0(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_HIOE_STR_ADDR_CHN_MAC_HW0(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HW_IOE_CR_CHN_MAC_HW1
  * @brief
  * @{
  */
#define BIT_HIOE_ACTIVE_CHN_MAC_HW1          ((u32)0x00000001 << 31)           /*!< R 0x0  indicate HIOE CHN_MAC_HW1 is active*/
#define BIT_HIOE_RESTORE_REQ_CHN_MAC_HW1     ((u32)0x00000001 << 25)           /*!< R 0x0  hw hang trig hioe reset wmac request, clear by hw*/
#define BIT_MASK_HIOE_END_ADDR_CHN_MAC_HW1   ((u32)0x00000FFF << 12)           /*!< R/W 0x0  HIOE command end address in txpktbuffer, unit:8byte*/
#define BIT_HIOE_END_ADDR_CHN_MAC_HW1(x)     (((u32)((x) & 0x00000FFF) << 12))
#define BIT_GET_HIOE_END_ADDR_CHN_MAC_HW1(x) ((u32)(((x >> 12) & 0x00000FFF)))
#define BIT_MASK_HIOE_STR_ADDR_CHN_MAC_HW1   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  HIOE command start address in txpktbuffer, unit:8byte*/
#define BIT_HIOE_STR_ADDR_CHN_MAC_HW1(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_HIOE_STR_ADDR_CHN_MAC_HW1(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HW_IOE_CR_CHN_BCN_MODE
  * @brief
  * @{
  */
#define BIT_HIOE_ACTIVE_CHN_BCN_MODE          ((u32)0x00000001 << 31)           /*!< R 0x0  indicate HIOE CHN_bcn_mode is active*/
#define BIT_HIOE_RESTORE_REQ_CHN_BCN_MODE     ((u32)0x00000001 << 25)           /*!< R 0x0  BB/RF enable OFDM mode request, clear by hw*/
#define BIT_MASK_HIOE_END_ADDR_CHN_BCN_MODE   ((u32)0x00000FFF << 12)           /*!< R/W 0x0  HIOE command end address in txpktbuffer, unit:8byte*/
#define BIT_HIOE_END_ADDR_CHN_BCN_MODE(x)     (((u32)((x) & 0x00000FFF) << 12))
#define BIT_GET_HIOE_END_ADDR_CHN_BCN_MODE(x) ((u32)(((x >> 12) & 0x00000FFF)))
#define BIT_MASK_HIOE_STR_ADDR_CHN_BCN_MODE   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  HIOE command start address in txpktbuffer, unit:8byte*/
#define BIT_HIOE_STR_ADDR_CHN_BCN_MODE(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_HIOE_STR_ADDR_CHN_BCN_MODE(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HW_IOE_CR_CHN_BB_HW
  * @brief HW IO Engine Configure Register_CHN_BB_HW
  * @{
  */
#define BIT_HIOE_ACTIVE_CHN_BB_HW          ((u32)0x00000001 << 31)           /*!< R 0x0  indicate HIOE engine is active*/
#define BIT_HIOE_BB_HIGH_TRIG_CHN_BB_EN    ((u32)0x00000001 << 27)           /*!< R/W 0x0  enable bb high pri int to to trig hioe to do bb reset when break happened*/
#define BIT_HIOE_BB_LOW_TRIG_CHN_BB_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  enable bb low pri int to to trig hioe to do bb reset when break happened*/
#define BIT_HIOE_RESTORE_REQ_CHN_BB_HW     ((u32)0x00000001 << 25)           /*!< R 0x0  WLOFF REG restore request, clear by hw*/
#define BIT_MASK_HIOE_END_ADDR_CHN_BB_HW   ((u32)0x00000FFF << 12)           /*!< R/W 0x0  HIOE command end address in txpktbuffer, unit:8byte*/
#define BIT_HIOE_END_ADDR_CHN_BB_HW(x)     (((u32)((x) & 0x00000FFF) << 12))
#define BIT_GET_HIOE_END_ADDR_CHN_BB_HW(x) ((u32)(((x >> 12) & 0x00000FFF)))
#define BIT_MASK_HIOE_STR_ADDR_CHN_BB_HW   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  HIOE command start address in txpktbuffer, unit:8byte*/
#define BIT_HIOE_STR_ADDR_CHN_BB_HW(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_HIOE_STR_ADDR_CHN_BB_HW(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_RXBCN_TIMER_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_RXBCN_TIMEUP_THRES        ((u32)0x0000FFFF << 16)           /*!< R/WPD 0x1F40  threshold for rxbcn timeout,UNIT:us default:8ms*/
#define BIT_RXBCN_TIMEUP_THRES(x)          (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_RXBCN_TIMEUP_THRES(x)      ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_RXBCN_TIMEUP_THRES_INIT   ((u32)0x0000FFFF << 0)            /*!< R 0x0  HW auto update threshold for rxbcn timeout,UNIT:us*/
#define BIT_RXBCN_TIMEUP_THRES_INIT(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_RXBCN_TIMEUP_THRES_INIT(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_RXBCN_TIMEUP_COUNTER_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_RXBCN_TIMEUP_COUNT1         ((u32)0x0000007F << 24)           /*!< R 0x0  rxbcn timeup counter1*/
#define BIT_RXBCN_TIMEUP_COUNT1(x)           (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_RXBCN_TIMEUP_COUNT1(x)       ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_RXBCN_TIMEUP_COUNT1_CLR          ((u32)0x00000001 << 23)           /*!< WA0 0x0  clear rxbcn timeup counter1*/
#define BIT_MASK_RXBCN_TIMEUP_COUNT1_THRES   ((u32)0x0000007F << 16)           /*!< R/W 0x1E  threshold for rxbcn timeup counter,when 0x17C[30:24] equals to this value,generate interrupt*/
#define BIT_RXBCN_TIMEUP_COUNT1_THRES(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_RXBCN_TIMEUP_COUNT1_THRES(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_CLK_TSF_IS32K                    ((u32)0x00000001 << 15)           /*!< R 0x0  Which Clock is Used by TSF Clock 1: 32K Clock 0: MAC Clock*/
#define BIT_WAIT_RXBCN_FINISH                ((u32)0x00000001 << 14)           /*!< R/W 0x0  when rxbcn frame,turn off rf or generate interrupt ablout rxbcn after beacon fcs is parsered*/
#define BIT_MASK_RXBCN_TIMEUP_COUNT          ((u32)0x0000000F << 10)           /*!< R 0x0  rxbcn timeup counter*/
#define BIT_RXBCN_TIMEUP_COUNT(x)            (((u32)((x) & 0x0000000F) << 10))
#define BIT_GET_RXBCN_TIMEUP_COUNT(x)        ((u32)(((x >> 10) & 0x0000000F)))
#define BIT_RXBCN_TIMEUP_COUNT_CLR           ((u32)0x00000001 << 9)            /*!< WA0 0x0  clear rxbcn timeup counter*/
#define BIT_MASK_RXBCN_TIMEUP_COUNT_THRES    ((u32)0x0000000F << 5)            /*!< R/W 0x3  threshold for rxbcn timeout counter,when 0x17C[13:10] equals to this value,generate interrupt*/
#define BIT_RXBCN_TIMEUP_COUNT_THRES(x)      (((u32)((x) & 0x0000000F) << 5))
#define BIT_GET_RXBCN_TIMEUP_COUNT_THRES(x)  ((u32)(((x >> 5) & 0x0000000F)))
/** @} */

/** @defgroup REG_RXBCN_COUNTER_CTRL1
  * @brief
  * @{
  */
#define BIT_EN_RXBCN_CNT                   ((u32)0x00000001 << 31)           /*!< R/W 0x0  1: statistic the number of RXBCN in specified period*/
#define BIT_MASK_RXBCN_CNT_PRD             ((u32)0x0000000F << 24)           /*!< R/W 0x7  2^(RXBCN_CNT_PRD), default is 128 times*/
#define BIT_RXBCN_CNT_PRD(x)               (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_RXBCN_CNT_PRD(x)           ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_RXBCN_TIMEUP_ADJSP_DOWN   ((u32)0x00000007 << 20)           /*!< R/W 0x1  the adjust step of the rxbcn timeup period adjustment when decrease the period. UNIT: (2^RXBCN_TIMEUP_ADJSP_DOWN)*32US*/
#define BIT_RXBCN_TIMEUP_ADJSP_DOWN(x)     (((u32)((x) & 0x00000007) << 20))
#define BIT_GET_RXBCN_TIMEUP_ADJSP_DOWN(x) ((u32)(((x >> 20) & 0x00000007)))
#define BIT_MASK_RXBCN_TIMEUP_ADJSP_UP     ((u32)0x00000007 << 16)           /*!< R/W 0x1  the adjust step of the rxbcn timeup period adjustment when increase the period.  UNIT: (2^RXBCN_TIMEUP_ADJSP_UP)*32US*/
#define BIT_RXBCN_TIMEUP_ADJSP_UP(x)       (((u32)((x) & 0x00000007) << 16))
#define BIT_GET_RXBCN_TIMEUP_ADJSP_UP(x)   ((u32)(((x >> 16) & 0x00000007)))
#define BIT_MASK_RXBCN_THRES_LOW           ((u32)0x000000FF << 8)            /*!< R/W 0x0  lower limit of rxbcn. If the RXBCN.COUNTER < THRES_LOW, RXBCN timeup period + (2^RXBCN_TIMEUP_ADJSP_UP)*32US*/
#define BIT_RXBCN_THRES_LOW(x)             (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_RXBCN_THRES_LOW(x)         ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_RXBCN_THRES_HIGH          ((u32)0x000000FF << 0)            /*!< R/W 0x0  upper limit of rxbcn. If the RXBCN.COUNTER > THRES_HIGH, RXBCN timeup period - (2^RXBCN_TIMEUP_ADJSP_DOWN)*32US*/
#define BIT_RXBCN_THRES_HIGH(x)            (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_RXBCN_THRES_HIGH(x)        ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RXBCN_COUNTER_CTRL2
  * @brief
  * @{
  */
#define BIT_MASK_RXBCN_CNT          ((u32)0x000000FF << 24)           /*!< R 0x0  statistic the times of RXBCN in RXBCN_CNT_PRD*/
#define BIT_RXBCN_CNT(x)            (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_RXBCN_CNT(x)        ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_RXBCN_TIMEUP_MIN   ((u32)0x00000FFF << 12)           /*!< R/W 0x40  lower limit of bcn_timeup. If the bcn_timeup less than RXBCN_TIMRUP_MIN, use the RXBCN_TIMRUP_MIN as bcn_timeup. UNIT: 32US. Default is 2ms*/
#define BIT_RXBCN_TIMEUP_MIN(x)     (((u32)((x) & 0x00000FFF) << 12))
#define BIT_GET_RXBCN_TIMEUP_MIN(x) ((u32)(((x >> 12) & 0x00000FFF)))
#define BIT_MASK_RXBCN_TIMEUP_MAX   ((u32)0x00000FFF << 0)            /*!< R/W 0x1E0  upper limit of bcn_timeup. If the bcn_timeup greater than RXBCN_TIMRUP_MAX, use the RXBCN_TIMRUP_MAX as bcn_timeup. UNIT: 32US. Default is 15ms*/
#define BIT_RXBCN_TIMEUP_MAX(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_RXBCN_TIMEUP_MAX(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_RFOFF_BY_EDCCA_CTRL0
  * @brief
  * @{
  */
#define BIT_MASK_EDCCA_IDLE_TO_CNT           ((u32)0x0000000F << 28)           /*!< R 0x0  indicate how many times edcca idle timeout happens*/
#define BIT_EDCCA_IDLE_TO_CNT(x)             (((u32)((x) & 0x0000000F) << 28))
#define BIT_GET_EDCCA_IDLE_TO_CNT(x)         ((u32)(((x >> 28) & 0x0000000F)))
#define BIT_MASK_EDCCA_IDLE_TIMER            ((u32)0x000000FF << 20)           /*!< R 0x0  edcca idle timeout timer,unit:4us*/
#define BIT_EDCCA_IDLE_TIMER(x)              (((u32)((x) & 0x000000FF) << 20))
#define BIT_GET_EDCCA_IDLE_TIMER(x)          ((u32)(((x >> 20) & 0x000000FF)))
#define BIT_MASK_EDCCA_CHK_AREA0_CNT_THRES   ((u32)0x0000000F << 16)           /*!< R/W 0x3  EDCCA_IDLE timeout counter treshold in area0,when timeout counter greater than threshold, generate interrupt*/
#define BIT_EDCCA_CHK_AREA0_CNT_THRES(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_EDCCA_CHK_AREA0_CNT_THRES(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_EDCCA_CHK_AREA0_TO_THRES    ((u32)0x000000FF << 8)            /*!< R/W 0x4  EDCCA_IDLE timeout threshold in area0,unit:4us,default:16us*/
#define BIT_EDCCA_CHK_AREA0_TO_THRES(x)      (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_EDCCA_CHK_AREA0_TO_THRES(x)  ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_EDCCA_CHK_AREA0_START       ((u32)0x000000FF << 0)            /*!< R/W 0x4  EDCCA_IDLE_area0 end time,start form TBTT,unit:256us,default:1.024ms*/
#define BIT_EDCCA_CHK_AREA0_START(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_EDCCA_CHK_AREA0_START(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RFOFF_BY_EDCCA_CTRL1
  * @brief
  * @{
  */
#define BIT_RFOFF_EDCCA_EN                   ((u32)0x00000001 << 31)           /*!< R/W 0x0  enable function of rf off by edcca idle timeout*/
#define BIT_RFOFF_EDCCA_SEL_EDCCA            ((u32)0x00000001 << 30)           /*!< R/W 0x0  1:sel edcca as instruction*/
#define BIT_RFOFF_EDCCA_SEL_CCA              ((u32)0x00000001 << 29)           /*!< R/W 0x0  1:sel cca as instruction*/
#define BIT_RFOFF_EDCCA_SEL_NAV              ((u32)0x00000001 << 28)           /*!< R/W 0x0  1:sel nav as instruction*/
#define BIT_MASK_EDCCA_CHK_AREA1_CNT_THRES   ((u32)0x0000000F << 16)           /*!< R/W 0x2  EDCCA_IDLE timeout counter treshold in area1,when timeout counter greater than threshold, generate interrupt*/
#define BIT_EDCCA_CHK_AREA1_CNT_THRES(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_EDCCA_CHK_AREA1_CNT_THRES(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_EDCCA_CHK_AREA1_TO_THRES    ((u32)0x000000FF << 8)            /*!< R/W 0x4  EDCCA_IDLE timeout threshold in area1,unit:4us,default:16us*/
#define BIT_EDCCA_CHK_AREA1_TO_THRES(x)      (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_EDCCA_CHK_AREA1_TO_THRES(x)  ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_EDCCA_CHK_AREA1_START       ((u32)0x000000FF << 0)            /*!< R/W 0x24  EDCCA_IDLE_area1 start time,start form TBTT,unit:256us,default:9.216ms*/
#define BIT_EDCCA_CHK_AREA1_START(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_EDCCA_CHK_AREA1_START(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RFOFF_BY_EDCCA_CTRL2
  * @brief
  * @{
  */
#define BIT_EDCCA_STATUS                     ((u32)0x00000001 << 30)           /*!< R 0x0  indicate edcca or edcca|cca status of channel*/
#define BIT_MASK_EDCCA_CHK_AREA2_CNT_THRES   ((u32)0x0000000F << 16)           /*!< R/W 0x1  EDCCA_IDLE timeout counter treshold in AREA2,when timeout counter greater than threshold, generate interrupt*/
#define BIT_EDCCA_CHK_AREA2_CNT_THRES(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_EDCCA_CHK_AREA2_CNT_THRES(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_EDCCA_CHK_AREA2_TO_THRES    ((u32)0x000000FF << 8)            /*!< R/W 0x4  EDCCA_IDLE timeout threshold in AREA2,unit:4us,default:16us*/
#define BIT_EDCCA_CHK_AREA2_TO_THRES(x)      (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_EDCCA_CHK_AREA2_TO_THRES(x)  ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_EDCCA_CHK_AREA2_START       ((u32)0x000000FF << 0)            /*!< R/W 0x3B  EDCCA_IDLE_AREA2 start time,start form TBTT,unit:256us,default:15.104ms*/
#define BIT_EDCCA_CHK_AREA2_START(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_EDCCA_CHK_AREA2_START(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_PERIODIC_CCA_CTRL_0
  * @brief
  * @{
  */
#define BIT_POWER_WAIT_AAGC_DONE ((u32)0x00000001 << 30)           /*!< R/W 0x1  set1:when cca rsie up before power detect done,wait aagc_done to reenter power detect*/
#define BIT_MASK_RSSI_OFFSET     ((u32)0x000000FF << 22)           /*!< R/W 0x0  S(8,0), offset for beacon rssi(signed)*/
#define BIT_RSSI_OFFSET(x)       (((u32)((x) & 0x000000FF) << 22))
#define BIT_GET_RSSI_OFFSET(x)   ((u32)(((x >> 22) & 0x000000FF)))
#define BIT_MASK_RSSI_MEAN       ((u32)0x00000003 << 20)           /*!< R/W 0x2  RSSI LATCH mean by 1cycle/2cycle/4 cycle/8cycle*/
#define BIT_RSSI_MEAN(x)         (((u32)((x) & 0x00000003) << 20))
#define BIT_GET_RSSI_MEAN(x)     ((u32)(((x >> 20) & 0x00000003)))
#define BIT_MASK_RSSI_HIT        ((u32)0x00000003 << 18)           /*!< R/W 0x2  RSSI hit with 1cycle/2cycle/4cycle/8cylce*/
#define BIT_RSSI_HIT(x)          (((u32)((x) & 0x00000003) << 18))
#define BIT_GET_RSSI_HIT(x)      ((u32)(((x >> 18) & 0x00000003)))
#define BIT_MASK_POWER_BIAS_N    ((u32)0x0000007F << 11)           /*!< R/W 0x5  Power calculated by aagc model compared with r_rssi_backup minus r_power_bias_n(unsigned)*/
#define BIT_POWER_BIAS_N(x)      (((u32)((x) & 0x0000007F) << 11))
#define BIT_GET_POWER_BIAS_N(x)  ((u32)(((x >> 11) & 0x0000007F)))
#define BIT_MASK_POWER_BIAS_P    ((u32)0x0000007F << 4)            /*!< R/W 0x5  Power calculated by aagc model compared with r_rssi_backup plus r_power_bias_p(unsigned)*/
#define BIT_POWER_BIAS_P(x)      (((u32)((x) & 0x0000007F) << 4))
#define BIT_GET_POWER_BIAS_P(x)  ((u32)(((x >> 4) & 0x0000007F)))
#define BIT_MASK_POWER_PERIOD    ((u32)0x00000007 << 1)            /*!< R/W 0x1  Period time for calculate power 0:0.8us /1:1.6us /2:2.4us 3:3.2us /4:4.0us /5:4.8us 6:5.6us /7:6.4us*/
#define BIT_POWER_PERIOD(x)      (((u32)((x) & 0x00000007) << 1))
#define BIT_GET_POWER_PERIOD(x)  ((u32)(((x >> 1) & 0x00000007)))
#define BIT_PERIODIC_CCA         ((u32)0x00000001 << 0)            /*!< R/W 0x0  Enable or disable periodic cca function  when rxbcn*/
/** @} */

/** @defgroup REG_PERIODIC_CCA_CTRL_1
  * @brief
  * @{
  */
#define BIT_EN_BCN_UPT_RSSI              ((u32)0x00000001 << 31)           /*!< R/W 0x0  update rssi_backup when rx bcn with address match*/
#define BIT_MASK_PHYSTATUS_PERIOD        ((u32)0x00000003 << 19)           /*!< R/W 0x1  Period time for cca end to data on end and phystatus upload and RF settling 0:1us /1:2us /2:3us/ 3:4us*/
#define BIT_PHYSTATUS_PERIOD(x)          (((u32)((x) & 0x00000003) << 19))
#define BIT_GET_PHYSTATUS_PERIOD(x)      ((u32)(((x >> 19) & 0x00000003)))
#define BIT_MAC_BREAK_BB_SEL             ((u32)0x00000001 << 18)           /*!< R/W 0x0  0: use BBRST=0 (function disable) to break bb 1:not break bb*/
#define BIT_MASK_RSSI_BACKUP             ((u32)0x0000007F << 11)           /*!< R/W/ES 0x32  Backup rssi (unsigned)*/
#define BIT_RSSI_BACKUP(x)               (((u32)((x) & 0x0000007F) << 11))
#define BIT_GET_RSSI_BACKUP(x)           ((u32)(((x >> 11) & 0x0000007F)))
#define BIT_MASK_CCA_WAIT_PERIOD         ((u32)0x00000007 << 8)            /*!< R/W 0x2  Wait time for CCK CCA 0:5us /1:10us /2:15us 3:20us /4:25us /5:30us 6:35us /7:40us*/
#define BIT_CCA_WAIT_PERIOD(x)           (((u32)((x) & 0x00000007) << 8))
#define BIT_GET_CCA_WAIT_PERIOD(x)       ((u32)(((x >> 8) & 0x00000007)))
#define BIT_MASK_STANDBY_PERIOD_PWROK    ((u32)0x0000000F << 4)            /*!< R/W 0x3  Period time for RF standby if power is match 0:30us/1:35us /1:40us/ 2:45us/ 3:50us 4:55us /5:60us.. 14:105us/ 15:110us*/
#define BIT_STANDBY_PERIOD_PWROK(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_STANDBY_PERIOD_PWROK(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_STANDBY_PERIOD_PWRMIS   ((u32)0x0000000F << 0)            /*!< R/W 0x5  Period time for RF standby if power is mismatch 0:30us/1:35us /1:40us/ 2:45us/ 3:50us 4:55us /5:60us.. 14:105us/ 15:110us*/
#define BIT_STANDBY_PERIOD_PWRMIS(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_STANDBY_PERIOD_PWRMIS(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_PERIODIC_CCA_CTRL_2
  * @brief
  * @{
  */
#define BIT_MASK_IGI_OFFSET          ((u32)0x0000000F << 19)           /*!< R/W 0x6  S(4,0), offset for beacon rssi(unsigned)*/
#define BIT_IGI_OFFSET(x)            (((u32)((x) & 0x0000000F) << 19))
#define BIT_GET_IGI_OFFSET(x)        ((u32)(((x >> 19) & 0x0000000F)))
#define BIT_MASK_RSSI_GAP            ((u32)0x0000007F << 12)           /*!< R/W 0x0  if the difference of average rssi between state of power monitor and state of wait cca is too large(>=r_rssi_gap),the cca will be thought as false alarm*/
#define BIT_RSSI_GAP(x)              (((u32)((x) & 0x0000007F) << 12))
#define BIT_GET_RSSI_GAP(x)          ((u32)(((x >> 12) & 0x0000007F)))
#define BIT_MASK_RF_SETTLE2_PERIOD   ((u32)0x0000003F << 6)            /*!< R/W 0x5  settling time for RF if BB & RF is already enabled, 0:0us, 1:0.2us, 2:0.4us and so on*/
#define BIT_RF_SETTLE2_PERIOD(x)     (((u32)((x) & 0x0000003F) << 6))
#define BIT_GET_RF_SETTLE2_PERIOD(x) ((u32)(((x >> 6) & 0x0000003F)))
#define BIT_MASK_RF_SETTLE1_PERIOD   ((u32)0x0000003F << 0)            /*!< R/W 0xa  settling time for RF if BB & RF is enabled form standby mode, 0:0us, 1:0.2us, 2:0.4us and so on*/
#define BIT_RF_SETTLE1_PERIOD(x)     (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_RF_SETTLE1_PERIOD(x) ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_PERIODIC_CCA_CTRL_3
  * @brief
  * @{
  */
#define BIT_MASK_IGI_BACKUP_ADDR         ((u32)0x0000FFFF << 16)           /*!< R/W 0x1d70  Reg address for igi information (for amebad,igi reg is set in BB reg 0x1d70)*/
#define BIT_IGI_BACKUP_ADDR(x)           (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_IGI_BACKUP_ADDR(x)       ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_PERIODIC_CCA_SFD_RSTBB       ((u32)0x00000001 << 15)           /*!< R/W 0x0  1:mac check sfd fail will rstbb 0:mac check sfd fail will not rstbb*/
#define BIT_PERIODIC_CCA_SFD_SEL         ((u32)0x00000001 << 14)           /*!< R/W 0x0  0:check sfd of long plcp of received beacon 1:check sfd of short plcp of received beacon*/
#define BIT_PERIODIC_CCA_SFD_CHK_EN      ((u32)0x00000001 << 13)           /*!< R/W 0x0  Enable check long plcp preamble or short preamble*/
#define BIT_MASK_PERIODIC_CCA_BCN_LEN    ((u32)0x000003FF << 3)            /*!< R/W 0x0  Supposed Length of beacon, unit:byte If set to 0, not check length of beacon*/
#define BIT_PERIODIC_CCA_BCN_LEN(x)      (((u32)((x) & 0x000003FF) << 3))
#define BIT_GET_PERIODIC_CCA_BCN_LEN(x)  ((u32)(((x >> 3) & 0x000003FF)))
#define BIT_PERIODIC_CCA_RATE_CMP_EN     ((u32)0x00000001 << 2)            /*!< R/W 0x0  1:enable rate compare when periodic cca 0:disable rate compare when periodic cca*/
#define BIT_MASK_PERIODIC_CCA_RATE_SEL   ((u32)0x00000003 << 0)            /*!< R/W 0x0  If rate mismatch, break bb  0:CCK 1M; 1:CCK 2M; 2:CCK 5.5M; 3:CCK11M*/
#define BIT_PERIODIC_CCA_RATE_SEL(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_PERIODIC_CCA_RATE_SEL(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_PERIODIC_SHUTDOWN_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_SHUTDOWN_PERIOD   ((u32)0x0000000F << 1)           /*!< R/W 0x2  Period time for RF shutdown if power is match 0:60us /1:80us/ 2:100us/ 3:120us 4:140us /5:160us.. 14:340us/ 15:360us*/
#define BIT_SHUTDOWN_PERIOD(x)     (((u32)((x) & 0x0000000F) << 1))
#define BIT_GET_SHUTDOWN_PERIOD(x) ((u32)(((x >> 1) & 0x0000000F)))
#define BIT_PERIODIC_SHUTDOWN      ((u32)0x00000001 << 0)           /*!< R/W 0x0  Enable or disable periodic shutdown BB&RF*/
/** @} */

/** @defgroup REG_H2C_PTR
  * @brief Host mailbox Read/write pointer
  * @{
  */
#define BIT_MASK_H2C_FW_RDPTR    ((u32)0x0000000F << 8)           /*!< W/R 0x0  When FW is noticed by the interrupt generated by 0x1CC[15:0],it will read this read pointer first then read H2C ram unit read pointer equals to write pointer,and update this read pointer in the end*/
#define BIT_H2C_FW_RDPTR(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_H2C_FW_RDPTR(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_H2C_DRV_WTPTR   ((u32)0x0000000F << 0)           /*!< R/WPD 0x0  Host Write This Byte will generate interrupt to FW,and fw will read ram for h2c message according to this pointer*/
#define BIT_H2C_DRV_WTPTR(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_H2C_DRV_WTPTR(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_C2H_PTR
  * @brief fw mailbox Read/write pointer
  * @{
  */
#define BIT_MASK_C2H_DRV_RDPTR   ((u32)0x0000000F << 8)           /*!< W/R 0x0  When HOST is noticed by the interrupt generated by 0x1CC[15:0],it will read this read pointer first then read C2H ram unit read pointer equals to write pointer,and update this read pointer in the end*/
#define BIT_C2H_DRV_RDPTR(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_C2H_DRV_RDPTR(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_C2H_FW_WTPTR    ((u32)0x0000000F << 0)           /*!< R/WPD 0x0  FW Write This Byte will generate interrupt to HOST,and HOST will read ram for h2c message according to this pointer*/
#define BIT_C2H_FW_WTPTR(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_C2H_FW_WTPTR(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CHK_HANG_0
  * @brief
  * @{
  */
#define BIT_STATE0_CHK_ENABLE           ((u32)0x00000001 << 20)           /*!< R/W 0x0  function enable of check hang of state_0*/
#define BIT_MASK_STATE0_CHK_HANG_VAL    ((u32)0x000000FF << 12)           /*!< R/W 0x0  when r_state0_chk_enable is set, if state_0 is the value is equal to r_state0_chk_hang, starts state0_timeout_timer*/
#define BIT_STATE0_CHK_HANG_VAL(x)      (((u32)((x) & 0x000000FF) << 12))
#define BIT_GET_STATE0_CHK_HANG_VAL(x)  ((u32)(((x >> 12) & 0x000000FF)))
#define BIT_MASK_STATE0_TIMEOUT_THRES   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  timeout threshold of state0_timeout_timer, unit:16us*/
#define BIT_STATE0_TIMEOUT_THRES(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_STATE0_TIMEOUT_THRES(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_CHK_HANG_1
  * @brief
  * @{
  */
#define BIT_STATE1_CHK_ENABLE           ((u32)0x00000001 << 20)           /*!< R/W 0x0  function enable of check hang of state_1*/
#define BIT_MASK_STATE1_CHK_HANG_VAL    ((u32)0x000000FF << 12)           /*!< R/W 0x0  when r_state1_chk_enable is set, if state_1 is the value is equal to r_state1_chk_hang, starts state1_timeout_timer*/
#define BIT_STATE1_CHK_HANG_VAL(x)      (((u32)((x) & 0x000000FF) << 12))
#define BIT_GET_STATE1_CHK_HANG_VAL(x)  ((u32)(((x >> 12) & 0x000000FF)))
#define BIT_MASK_STATE1_TIMEOUT_THRES   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  timeout threshold of state0_timeout_timer, unit:16us*/
#define BIT_STATE1_TIMEOUT_THRES(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_STATE1_TIMEOUT_THRES(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_TXRLS_FIFO_CFG2
  * @brief
  * @{
  */
#define BIT_EN_FWPKT_DYN_RLS                 ((u32)0x00000001 << 31)           /*!< R/W 0x0  1: enable fw packet dynamic release*/
#define BIT_MASK_TXRLS_ALMOST_FULL_GAP_FW    ((u32)0x00000007 << 28)           /*!< R/W 0x2  TXRLS fifo almost full threshold. Gen interrupt when available TXRLS FIFO entries smaller than the reg.  for fw packet*/
#define BIT_TXRLS_ALMOST_FULL_GAP_FW(x)      (((u32)((x) & 0x00000007) << 28))
#define BIT_GET_TXRLS_ALMOST_FULL_GAP_FW(x)  ((u32)(((x >> 28) & 0x00000007)))
#define BIT_RLS_FIFO_VALID_FW                ((u32)0x00000001 << 27)           /*!< R 0x0  1: Release fifo is unempty,fw can read release fifo*/
#define BIT_MASK_TXRLS_DEPTH_FW              ((u32)0x00000007 << 24)           /*!< R/W 0x2  2^N, N max is 6. default is 4*/
#define BIT_TXRLS_DEPTH_FW(x)                (((u32)((x) & 0x00000007) << 24))
#define BIT_GET_TXRLS_DEPTH_FW(x)            ((u32)(((x >> 24) & 0x00000007)))
#define BIT_MASK_TXRLS_OFFSET_FW             ((u32)0x000000FF << 16)           /*!< R/W 0x18  start address of TXRLS FIFO, for fw packet dynamic release FW packet default is static release, if EN_FWPKT_DYN_RLS = 1, need to change all FIFO REG offset*/
#define BIT_TXRLS_OFFSET_FW(x)               (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_TXRLS_OFFSET_FW(x)           ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_TXRLS_ALMOST_FULL_GAP_DRV   ((u32)0x0000000F << 12)           /*!< R/W 0x4  TXRLS fifo almost full threshold. Gen interrupt when available TXRLS FIFO entries smaller than the reg.  for driver packet*/
#define BIT_TXRLS_ALMOST_FULL_GAP_DRV(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_TXRLS_ALMOST_FULL_GAP_DRV(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_RLS_FIFO_VALID_DRV               ((u32)0x00000001 << 11)           /*!< R 0x0  1: Release fifo is unempty,driver can read release fifo*/
#define BIT_MASK_TXRLS_DEPTH_DRV             ((u32)0x00000007 << 8)            /*!< R/W 0x4  2^N, N max is 6. default is 16*/
#define BIT_TXRLS_DEPTH_DRV(x)               (((u32)((x) & 0x00000007) << 8))
#define BIT_GET_TXRLS_DEPTH_DRV(x)           ((u32)(((x >> 8) & 0x00000007)))
#define BIT_MASK_TXRLS_OFFSET_DRV            ((u32)0x000000FF << 0)            /*!< R/W 0x8  start address of TXRLS FIFO, for driver packet*/
#define BIT_TXRLS_OFFSET_DRV(x)              (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_TXRLS_OFFSET_DRV(x)          ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TXRPT_BUF_CFG1
  * @brief
  * @{
  */
#define BIT_CLR_TXRPT_RW_PTR    ((u32)0x00000001 << 12)          /*!< R/W 0x0  1: clear r/w ptr of txrpt fifo*/
#define BIT_TXRPT_FIFO_VALID_SW ((u32)0x00000001 << 11)          /*!< R 0x0  1: Release fifo is unempty,driver can read release fifo*/
#define BIT_MASK_TXRPT_DEPTH    ((u32)0x00000007 << 8)           /*!< R/W 0x5  2^N, N max is 6. default is 32*/
#define BIT_TXRPT_DEPTH(x)      (((u32)((x) & 0x00000007) << 8))
#define BIT_GET_TXRPT_DEPTH(x)  ((u32)(((x >> 8) & 0x00000007)))
#define BIT_MASK_TXRPT_OFFSET   ((u32)0x000000FF << 0)           /*!< R/W 0x18  start address of TXRPT BUF*/
#define BIT_TXRPT_OFFSET(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_TXRPT_OFFSET(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RXBD_FIFO_CFG1
  * @brief
  * @{
  */
#define BIT_MASK_CSIBD_FULL_THRESHOD   ((u32)0x0000000F << 28)           /*!< R/W 0x3  csibd fifo almost full threshold. Gen interrupt when available csibd numbers smaller than the reg*/
#define BIT_CSIBD_FULL_THRESHOD(x)     (((u32)((x) & 0x0000000F) << 28))
#define BIT_GET_CSIBD_FULL_THRESHOD(x) ((u32)(((x >> 28) & 0x0000000F)))
#define BIT_MASK_RXBD_FULL_THRESHOD    ((u32)0x0000000F << 24)           /*!< R/W 0x3  rxbd fifo almost full threshold. Gen interrupt when available rxbd numbers smaller than the reg*/
#define BIT_RXBD_FULL_THRESHOD(x)      (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_RXBD_FULL_THRESHOD(x)  ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_CSIBD_SIZE            ((u32)0x0000001F << 19)           /*!< R/W 0x1  one rxbd corresponding host memory size,unit 256byts*/
#define BIT_CSIBD_SIZE(x)              (((u32)((x) & 0x0000001F) << 19))
#define BIT_GET_CSIBD_SIZE(x)          ((u32)(((x >> 19) & 0x0000001F)))
#define BIT_MASK_RXBD_SIZE             ((u32)0x0000001F << 14)           /*!< R/W 0x7  one rxbd corresponding host memory size,unit 256byts*/
#define BIT_RXBD_SIZE(x)               (((u32)((x) & 0x0000001F) << 14))
#define BIT_GET_RXBD_SIZE(x)           ((u32)(((x >> 14) & 0x0000001F)))
#define BIT_MASK_CSIBD_DEPTH           ((u32)0x00000007 << 11)           /*!< R/W 0x3  2^N, N max is 6.default is 8*/
#define BIT_CSIBD_DEPTH(x)             (((u32)((x) & 0x00000007) << 11))
#define BIT_GET_CSIBD_DEPTH(x)         ((u32)(((x >> 11) & 0x00000007)))
#define BIT_MASK_RXBD_DEPTH            ((u32)0x00000007 << 8)            /*!< R/W 0x3  2^N, N max is 6.default is 8*/
#define BIT_RXBD_DEPTH(x)              (((u32)((x) & 0x00000007) << 8))
#define BIT_GET_RXBD_DEPTH(x)          ((u32)(((x >> 8) & 0x00000007)))
#define BIT_MASK_RXBD_OFFSET           ((u32)0x000000FF << 0)            /*!< R/W 0x38  start address of RXBD FIFO*/
#define BIT_RXBD_OFFSET(x)             (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_RXBD_OFFSET(x)         ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TXLLT_CFG
  * @brief
  * @{
  */
#define BIT_AUTO_INIT_LLT       ((u32)0x00000001 << 31)          /*!< R/W/ES 0x0  */
#define BIT_MASK_LLT_BOUNDARY   ((u32)0x000000FF << 0)           /*!< R/WPD 0x3F  boundary of LLT and the limit size of LLT.  The default is 64.*/
#define BIT_LLT_BOUNDARY(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_LLT_BOUNDARY(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TRXFF_BNDY
  * @brief FIFO Boundary control register
  * @{
  */
#define BIT_MASK_RXPKTENDADDR   ((u32)0x000007FF << 16)           /*!< R/W 0x37F  This register sets the upper boundary of RXFF0. The unit is 8 byte. The available memory space in RXPKTBUF for RXFF0 is configurable.*/
#define BIT_RXPKTENDADDR(x)     (((u32)((x) & 0x000007FF) << 16))
#define BIT_GET_RXPKTENDADDR(x) ((u32)(((x >> 16) & 0x000007FF)))
#define BIT_MASK_RXFFOVFL_RSV   ((u32)0x0000000F << 8)            /*!< R/W 0xF  Use this register to set reserved entries number of rxpktbuffer for overflow judgment. The rxpktbuffer overflow will be pre-asserted if the left entries count meets the value set here.*/
#define BIT_RXFFOVFL_RSV(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_RXFFOVFL_RSV(x) ((u32)(((x >> 8) & 0x0000000F)))
/** @} */

/** @defgroup REG_TXBD_FIFO_CFG1
  * @brief
  * @{
  */
#define BIT_MASK_AVL_TXBD_NUM   ((u32)0x0000007F << 11)           /*!< R 0x0  available txbd num in txbd fifo*/
#define BIT_AVL_TXBD_NUM(x)     (((u32)((x) & 0x0000007F) << 11))
#define BIT_GET_AVL_TXBD_NUM(x) ((u32)(((x >> 11) & 0x0000007F)))
#define BIT_MASK_TXBD_DEPTH     ((u32)0x00000007 << 8)            /*!< R/W 0x3  2^N, N max is 6.default is 8*/
#define BIT_TXBD_DEPTH(x)       (((u32)((x) & 0x00000007) << 8))
#define BIT_GET_TXBD_DEPTH(x)   ((u32)(((x >> 8) & 0x00000007)))
#define BIT_MASK_TXBD_OFFSET    ((u32)0x000000FF << 0)            /*!< R/W 0x0  start address of TXBD FIFO*/
#define BIT_TXBD_OFFSET(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_TXBD_OFFSET(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_HIMR2
  * @brief
  * @{
  */
#define BIT_HS_RADAR_SEG_END_INT_EN  ((u32)0x00000001 << 13) /*!< R/W 0x0  */
#define BIT_HS_RADAR_OK_INT_EN       ((u32)0x00000001 << 12) /*!< R/W 0x0  */
#define BIT_HS_RADAR_FAIL_INT_EN     ((u32)0x00000001 << 11) /*!< R/W 0x0  */
#define BIT_HS_RADAR_TIMEOUT_INT_EN  ((u32)0x00000001 << 10) /*!< R/W 0x0  */
#define BIT_HS_PS_ELY_TIMER_E_INT_EN ((u32)0x00000001 << 9)  /*!< R/W 0x0  */
#define BIT_HS_PS_ELY_TIMER_D_INT_EN ((u32)0x00000001 << 8)  /*!< R/W 0x0  */
#define BIT_HS_PS_ELY_TIMER_C_INT_EN ((u32)0x00000001 << 7)  /*!< R/W 0x0  */
#define BIT_HS_PS_ELY_TIMER_B_INT_EN ((u32)0x00000001 << 6)  /*!< R/W 0x0  */
#define BIT_HS_PS_ELY_TIMER_A_INT_EN ((u32)0x00000001 << 5)  /*!< R/W 0x0  */
#define BIT_HS_PS_TIMER_E_INT_EN     ((u32)0x00000001 << 4)  /*!< R/W 0x0  */
#define BIT_HS_PS_TIMER_D_INT_EN     ((u32)0x00000001 << 3)  /*!< R/W 0x0  */
#define BIT_HS_PS_TIMER_C_INT_EN     ((u32)0x00000001 << 2)  /*!< R/W 0x0  */
#define BIT_HS_PS_TIMER_B_INT_EN     ((u32)0x00000001 << 1)  /*!< R/W 0x0  */
#define BIT_HS_PS_TIMER_A_INT_EN     ((u32)0x00000001 << 0)  /*!< R/W 0x0  */
/** @} */

/** @defgroup REG_HISR2
  * @brief
  * @{
  */
#define BIT_HS_RADAR_SEG_END_INT  ((u32)0x00000001 << 13) /*!< RW1CB 0x0  */
#define BIT_HS_RADAR_OK_INT       ((u32)0x00000001 << 12) /*!< RW1CB 0x0  */
#define BIT_HS_RADAR_FAIL_INT     ((u32)0x00000001 << 11) /*!< RW1CB 0x0  */
#define BIT_HS_RADAR_TIMEOUT_INT  ((u32)0x00000001 << 10) /*!< RW1CB 0x0  */
#define BIT_HS_PS_ELY_TIMER_E_INT ((u32)0x00000001 << 9)  /*!< RW1CB 0x0  */
#define BIT_HS_PS_ELY_TIMER_D_INT ((u32)0x00000001 << 8)  /*!< RW1CB 0x0  */
#define BIT_HS_PS_ELY_TIMER_C_INT ((u32)0x00000001 << 7)  /*!< RW1CB 0x0  */
#define BIT_HS_PS_ELY_TIMER_B_INT ((u32)0x00000001 << 6)  /*!< RW1CB 0x0  */
#define BIT_HS_PS_ELY_TIMER_A_INT ((u32)0x00000001 << 5)  /*!< RW1CB 0x0  */
#define BIT_HS_PS_TIMER_E_INT     ((u32)0x00000001 << 4)  /*!< RW1CB 0x0  */
#define BIT_HS_PS_TIMER_D_INT     ((u32)0x00000001 << 3)  /*!< RW1CB 0x0  */
#define BIT_HS_PS_TIMER_C_INT     ((u32)0x00000001 << 2)  /*!< RW1CB 0x0  */
#define BIT_HS_PS_TIMER_B_INT     ((u32)0x00000001 << 1)  /*!< RW1CB 0x0  */
#define BIT_HS_PS_TIMER_A_INT     ((u32)0x00000001 << 0)  /*!< RW1CB 0x0  */
/** @} */

/** @defgroup REG_MACIDCAM_ADDR0
  * @brief
  * @{
  */
#define BIT_MASK_BACAM_CFG_ADDR_START      ((u32)0x000000FF << 24)           /*!< R/W 0xCC  Start address of bacam for ba cfg, which should be 0x1b8[18:11] + 0x1b8[23:19] + 4*2*0x1b8[23:19]*/
#define BIT_BACAM_CFG_ADDR_START(x)        (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_BACAM_CFG_ADDR_START(x)    ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_KEYCAM_CFG_ENTRY_NUM      ((u32)0x0000001F << 19)           /*!< R/W 0xF  Total entry numbers for key cfg cam, 1 entry=8byte=2 key cfg*/
#define BIT_KEYCAM_CFG_ENTRY_NUM(x)        (((u32)((x) & 0x0000001F) << 19))
#define BIT_GET_KEYCAM_CFG_ENTRY_NUM(x)    ((u32)(((x >> 19) & 0x0000001F)))
#define BIT_MASK_KEYCAM_CFG_ADDR_START     ((u32)0x000000FF << 11)           /*!< R/W 0x45  Start address of keycam for key cfg, which should be 10*2*0x1b8[2:0] + 0x1b8[10:3]*/
#define BIT_KEYCAM_CFG_ADDR_START(x)       (((u32)((x) & 0x000000FF) << 11))
#define BIT_GET_KEYCAM_CFG_ADDR_START(x)   ((u32)(((x >> 11) & 0x000000FF)))
#define BIT_MASK_CTRLINFO_CAM_ADDR_START   ((u32)0x000000FF << 3)            /*!< R/W 0x9  Start address of ctrl info cam, which should be 3*0x1b8[2:0]*/
#define BIT_CTRLINFO_CAM_ADDR_START(x)     (((u32)((x) & 0x000000FF) << 3))
#define BIT_GET_CTRLINFO_CAM_ADDR_START(x) ((u32)(((x >> 3) & 0x000000FF)))
#define BIT_MASK_CRC5_CAM_ENTRY_NUM        ((u32)0x00000007 << 0)            /*!< R/W 0x3  Crc5 entry number for either A1,A2 and A3, 1 entry =8byte=10 crc5 should greater than 0, default is 3,which means the max macid number is 30.*/
#define BIT_CRC5_CAM_ENTRY_NUM(x)          (((u32)((x) & 0x00000007) << 0))
#define BIT_GET_CRC5_CAM_ENTRY_NUM(x)      ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_MACIDCAM_ADDR1
  * @brief
  * @{
  */
#define BIT_KEYCAM_SIZE_256_EN             ((u32)0x00000001 << 18)           /*!< R/W 0x0  1: key size in keycam is 256bit 0: key size in keycam depend on ex_sectype in keycam cfg*/
#define BIT_MASK_RXFILTER_CFG_ENTRY_NUM    ((u32)0x0000001F << 13)           /*!< R/W 0x6  Total entry numbers for rx filter cfg cam, 1 entry=8byte=2 rx filter cfg*/
#define BIT_RXFILTER_CFG_ENTRY_NUM(x)      (((u32)((x) & 0x0000001F) << 13))
#define BIT_GET_RXFILTER_CFG_ENTRY_NUM(x)  ((u32)(((x >> 13) & 0x0000001F)))
#define BIT_MASK_RXFILTER_CFG_ADDR_START   ((u32)0x000000FF << 5)            /*!< R/W 0xF9  Start address of rxfilter cam, which should be 0x1b8[31:24] + 0x1bc[4:0] + 2*0x1bc[4:0]*/
#define BIT_RXFILTER_CFG_ADDR_START(x)     (((u32)((x) & 0x000000FF) << 5))
#define BIT_GET_RXFILTER_CFG_ADDR_START(x) ((u32)(((x >> 5) & 0x000000FF)))
#define BIT_MASK_BACAM_CFG_ENTRY_NUM       ((u32)0x0000001F << 0)            /*!< R/W 0xF  Total entry numbers for rxba cfg cam,1 entry=8byte=2 BA cfg*/
#define BIT_BACAM_CFG_ENTRY_NUM(x)         (((u32)((x) & 0x0000001F) << 0))
#define BIT_GET_BACAM_CFG_ENTRY_NUM(x)     ((u32)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_STATE_DEBUG_CONTROL
  * @brief
  * @{
  */
#define BIT_MASK_STATE_DBG_SEL_1   ((u32)0x0000003F << 10)           /*!< R/W 0x0  select state machine 1 for debug  port*/
#define BIT_STATE_DBG_SEL_1(x)     (((u32)((x) & 0x0000003F) << 10))
#define BIT_GET_STATE_DBG_SEL_1(x) ((u32)(((x >> 10) & 0x0000003F)))
#define BIT_MASK_STATE_DBG_SEL_0   ((u32)0x0000003F << 4)            /*!< R/W 0x0  select state machine 0 for debug  port*/
#define BIT_STATE_DBG_SEL_0(x)     (((u32)((x) & 0x0000003F) << 4))
#define BIT_GET_STATE_DBG_SEL_0(x) ((u32)(((x >> 4) & 0x0000003F)))
#define BIT_STATE_DBG_EN_1         ((u32)0x00000001 << 3)            /*!< R/W 0x0  enable state machine 1 for debug  port*/
#define BIT_STATE_DBG_EN_0         ((u32)0x00000001 << 2)            /*!< R/W 0x0  enable state machine 1 for debug  port*/
#define BIT_MASK_MAC_DBG_SHIFT     ((u32)0x00000003 << 0)            /*!< R/W 0x0  MACDEBUG[31:0] byte shift control signal 2'b00: MACDEBUG[31:0] 2'b01:{MACDEBUG[7:0],MACDEBUG[31:8]} 2'b10:{MACDEBUG[15:0],MACDEBUG[31:16]} 2'b11:{MACDEBUG[23:0],MACDEBUG[31:24]}*/
#define BIT_MAC_DBG_SHIFT(x)       (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_MAC_DBG_SHIFT(x)   ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/*==========REG_PAGE1_MGEN_ON Register Address Definition==========*/
#define REG_CR                                 0x100
#define REG_BB_RFC_ATR                         0x104
#define REG_EXT_IMR_WLPMC_EN                   0x108
#define REG_EXT_IMR_SW_EN                      0x10C
#define REG_HIMR0                              0x110
#define REG_HISR0                              0x114
#define REG_HIMR1                              0x118
#define REG_HISR1                              0x11C
#define REG_FIMR0                              0x120
#define REG_FISR0                              0x124
#define REG_FIMR1                              0x128
#define REG_FIMR2                              0x130
#define REG_FIMR3                              0x138
#define REG_TC4_CTRL                           0x140
#define REG_TC5_CTRL                           0x144
#define REG_TC0_CTRL                           0x148
#define REG_TC1_CTRL                           0x14C
#define REG_TC2_CTRL                           0x150
#define REG_TC3_CTRL                           0x154
#define REG_HW_IOE_CR_CH0                      0x158
#define REG_HW_IOE_CR_CHN_ON                   0x160
#define REG_HW_IOE_CR_CHN_OFF                  0x164
#define REG_HW_IOE_CR_CHN_MAC_HW0              0x168
#define REG_HW_IOE_CR_CHN_MAC_HW1              0x16C
#define REG_HW_IOE_CR_CHN_BCN_MODE             0x170
#define REG_HW_IOE_CR_CHN_BB_HW                0x174
#define REG_RXBCN_TIMER_CTRL                   0x178
#define REG_RXBCN_TIMEUP_COUNTER_CTRL          0x17C
#define REG_RXBCN_COUNTER_CTRL1                0x180
#define REG_RXBCN_COUNTER_CTRL2                0x184
#define REG_RFOFF_BY_EDCCA_CTRL0               0x188
#define REG_RFOFF_BY_EDCCA_CTRL1               0x18C
#define REG_RFOFF_BY_EDCCA_CTRL2               0x190
#define REG_PERIODIC_CCA_CTRL_0                0x194
#define REG_PERIODIC_CCA_CTRL_1                0x198
#define REG_PERIODIC_CCA_CTRL_2                0x19C
#define REG_PERIODIC_CCA_CTRL_3                0x1A0
#define REG_PERIODIC_SHUTDOWN_CTRL             0x1A4
#define REG_H2C_PTR                            0x1A8
#define REG_C2H_PTR                            0x1AC
#define REG_CHK_HANG_0                         0x1B0
#define REG_CHK_HANG_1                         0x1B4
#define REG_TXRLS_FIFO_CFG2                    0x1C8
#define REG_TXRPT_BUF_CFG1                     0x1CC
#define REG_RXBD_FIFO_CFG1                     0x1D0
#define REG_TXLLT_CFG                          0x1D4
#define REG_TRXFF_BNDY                         0x1D8
#define REG_TXBD_FIFO_CFG1                     0x1DC
#define REG_HIMR2                              0x1E0
#define REG_HISR2                              0x1E4
#define REG_MACIDCAM_ADDR0                     0x1E8
#define REG_MACIDCAM_ADDR1                     0x1EC
#define REG_DUMMY_PAGE1_ON                     0x1F0
#define REG_STATE_DEBUG_CONTROL                0x1F4

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