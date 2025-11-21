#ifndef _project_name_REG_PAGE1_H_
#define _project_name_REG_PAGE1_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE1
  * @brief REG_PAGE1 driver modulesq
  * @{
  */


/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE1_Register_Definitions REG_PAGE1 Register Definitions
  * @{
  */

/** @defgroup REG_CR
  * @brief
  * @{
  */
#define BIT_BIST_H32BIT_SEL ((u32)0x00000001 << 29)           /*!< R/W 0x0  When set to 1,  0x170/0x17C is High 32bits of bist results, otherwise 0x170/0x17C is Low 32bits of bist results*/
#define BIT_MASK_LBMODE     ((u32)0x0000001F << 24)           /*!< R/W 0x0  [4]dual-mac lbk, [3] no buffer, 1: no delay, 0: delay; [2] dmalbk, [1] no_txphy, [0] diglbk. 00000: Normal 01011: Single MAC Direct loopback (no HW encryption/decryption) 00011: Single MAC Delay Loopback (with HW encryption/decryption)*/
#define BIT_LBMODE(x)       (((u32)((x) & 0x0000001F) << 24))
#define BIT_GET_LBMODE(x)   ((u32)(((x >> 24) & 0x0000001F)))
#define BIT_MASK_NETYPE1    ((u32)0x00000003 << 18)           /*!< R/W 0x0  Network Type for Port 1 00: No link 01: Link in ad hoc network 10: Link in infrastructure network 11 : AP mode Default: 00b.*/
#define BIT_NETYPE1(x)      (((u32)((x) & 0x00000003) << 18))
#define BIT_GET_NETYPE1(x)  ((u32)(((x >> 18) & 0x00000003)))
#define BIT_MASK_NETYPE0    ((u32)0x00000003 << 16)           /*!< R/W 0x0  Network Type for port 0 00: No link 01: Link in ad hoc network 10: Link in infrastructure network 11 : AP mode Default: 00b.*/
#define BIT_NETYPE0(x)      (((u32)((x) & 0x00000003) << 16))
#define BIT_GET_NETYPE0(x)  ((u32)(((x >> 16) & 0x00000003)))
#define BIT_I2C_MAILBOX_EN  ((u32)0x00000001 << 12)           /*!< R/W 0x0  Enable I2C mailbox*/
#define BIT_32K_CAL_TMR_EN  ((u32)0x00000001 << 10)           /*!< R/W 0x0  Enable 32k NCO*/
#define BIT_MAC_SEC_EN      ((u32)0x00000001 << 9)            /*!< R/W 0x0  Enable MAC security engine When this bit is clear, security engine is reset*/
#define BIT_ENSWBCN         ((u32)0x00000001 << 8)            /*!< R/W 0x0  Enable SW TX beacon 0 = disable, beacon is DMAed from host memory by HW at BCNDMAINT 1 = enable, beacon is polled to DMA to TXBUF. In both case, as long as a beacon frame is set in BCN page, MAC will automatically sent beacon frame automatically.*/
#define BIT_MACRXEN         ((u32)0x00000001 << 7)            /*!< R/W 0x0  MAC Receiver Enable. When set to 1, and the receive state machine is idle, the receive machine becomes active. This bit will read back as 1 whenever the receive state machine is active. After initial power-up, software must ensure that the receiver has completely reset before setting this bit. 1: Enable 0: Disable Default: 0b.*/
#define BIT_MACTXEN         ((u32)0x00000001 << 6)            /*!< R/W 0x0  MAC Transmitter Enable. When set to 1, and the transmit state machine is idle, the transmit state machine becomes active. This bit will read back as 1 whenever the transmit state machine is active. After initial power-up, software must ensure that the transmitter has completely reset before setting this bit. 1: Enable 0: Disable Default: 0b.*/
#define BIT_SCHEDULE_EN     ((u32)0x00000001 << 5)            /*!< R/W 0x0  Schedule Enable.*/
#define BIT_PROTOCOL_EN     ((u32)0x00000001 << 4)            /*!< R/W 0x0  protocol Block Function Enable.*/
#define BIT_RXDMA_EN        ((u32)0x00000001 << 3)            /*!< R/W 0x0  RXDMA Function Enable*/
#define BIT_TXDMA_EN        ((u32)0x00000001 << 2)            /*!< R/W 0x0  TXDMA Function Enable*/
#define BIT_HCI_RXDMA_EN    ((u32)0x00000001 << 1)            /*!< R/W 0x0  HCI to RXDMA Interface Enable*/
#define BIT_HCI_TXDMA_EN    ((u32)0x00000001 << 0)            /*!< R/W 0x0  HCI to TXDMA Interface Enable*/
/** @} */

/** @defgroup REG_PG_SIZE
  * @brief
  * @{
  */
#define BIT_MASK_DBG_FIFO_SEL   ((u32)0x000000FF << 16)           /*!< R/W 0x0  TXFF: 0x69; RXFF: 0xa5; TXRPT: 0x7F*/
#define BIT_DBG_FIFO_SEL(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_DBG_FIFO_SEL(x) ((u32)(((x >> 16) & 0x000000FF)))
/** @} */

/** @defgroup REG_TSF_CLK_STATE
  * @brief
  * @{
  */
#define BIT_TSF_CLK_STABLE ((u32)0x00000001 << 15) /*!< R 0x0  Indicate that TSF 32k/40M is stable 1: TSF is stable in 32k 0: TSF is stable in 40M*/
/** @} */

/** @defgroup REG_TXDMA_PQ_MAP
  * @brief
  * @{
  */
#define BIT_MASK_TXDMA_HIQ_MAP_V1   ((u32)0x00000007 << 19)           /*!< R/W 0x0  000: Extra queue 001: Low priority queue 010: normal priority queue 011: high priority queue 100: Extra queue 1 101: Extra queue 2*/
#define BIT_TXDMA_HIQ_MAP_V1(x)     (((u32)((x) & 0x00000007) << 19))
#define BIT_GET_TXDMA_HIQ_MAP_V1(x) ((u32)(((x >> 19) & 0x00000007)))
#define BIT_MASK_TXDMA_MGQ_MAP_V1   ((u32)0x00000007 << 16)           /*!< R/W 0x0  000: Extra queue 001: Low priority queue 010: normal priority queue 011: high priority queue 100: Extra queue 1 101: Extra queue 2*/
#define BIT_TXDMA_MGQ_MAP_V1(x)     (((u32)((x) & 0x00000007) << 16))
#define BIT_GET_TXDMA_MGQ_MAP_V1(x) ((u32)(((x >> 16) & 0x00000007)))
#define BIT_MASK_TXDMA_BKQ_MAP_V1   ((u32)0x00000007 << 13)           /*!< R/W 0x0  000: Extra queue 001: Low priority queue 010: normal priority queue 011: high priority queue 100: Extra queue 1 101: Extra queue 2*/
#define BIT_TXDMA_BKQ_MAP_V1(x)     (((u32)((x) & 0x00000007) << 13))
#define BIT_GET_TXDMA_BKQ_MAP_V1(x) ((u32)(((x >> 13) & 0x00000007)))
#define BIT_MASK_TXDMA_BEQ_MAP_V1   ((u32)0x00000007 << 10)           /*!< R/W 0x0  000: Extra queue 001: Low priority queue 010: normal priority queue 011: high priority queue 100: Extra queue 1 101: Extra queue 2*/
#define BIT_TXDMA_BEQ_MAP_V1(x)     (((u32)((x) & 0x00000007) << 10))
#define BIT_GET_TXDMA_BEQ_MAP_V1(x) ((u32)(((x >> 10) & 0x00000007)))
#define BIT_MASK_TXDMA_VIQ_MAP_V1   ((u32)0x00000007 << 7)            /*!< R/W 0x0  000: Extra queue 001: Low priority queue 010: normal priority queue 011: high priority queue 100: Extra queue 1 101: Extra queue 2*/
#define BIT_TXDMA_VIQ_MAP_V1(x)     (((u32)((x) & 0x00000007) << 7))
#define BIT_GET_TXDMA_VIQ_MAP_V1(x) ((u32)(((x >> 7) & 0x00000007)))
#define BIT_MASK_TXDMA_VOQ_MAP_V1   ((u32)0x00000007 << 4)            /*!< R/W 0x0  000: Extra queue 001: Low priority queue 010: normal priority queue 011: high priority queue 100: Extra queue 1 101: Extra queue 2*/
#define BIT_TXDMA_VOQ_MAP_V1(x)     (((u32)((x) & 0x00000007) << 4))
#define BIT_GET_TXDMA_VOQ_MAP_V1(x) ((u32)(((x >> 4) & 0x00000007)))
#define BIT_RXDMA_AGG_EN            ((u32)0x00000001 << 2)            /*!< R/W 0x0  When this bit is set, then RXDMA will inform host to receive RX packets, when packet page number in RXFF exceeds the threshold set in RXDMA_AGG_PG_TH register. When this bit is set, then page size of receive packet buffer shall be set larger than 64 bytes/page*/
#define BIT_RXSHFT_EN               ((u32)0x00000001 << 1)            /*!< R/W 0x0  When this bit is set, RX shift to fit alignment is enabled.*/
#define BIT_RXDMA_ARBBW_EN          ((u32)0x00000001 << 0)            /*!< R/W 0x0  Enable RXDMA Arbitrator priority for Host interface.*/
/** @} */

/** @defgroup REG_TRXFF_BNDY
  * @brief
  * @{
  */
#define BIT_MASK_RXFF0_BNDY     ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  This register sets the upper boundary of RXFF0. The unit is 1 byte. The available memory space in RXPKTBUF for RXFF0 is configurable. The value is set to the physical LX bus address.*/
#define BIT_RXFF0_BNDY(x)       (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_RXFF0_BNDY(x)   ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_RXFFOVFL_RSV   ((u32)0x0000000F << 8)            /*!< R/W 0xF  RXFIFO overflow Threshold, unit : 8bytes RXFFOVFL threshold = RXFF BNDY - RXFFOVFL_RSV -8B If RXFIFOVF threshold assert, device will generate interrupt to driver. The value  >= Rx descriptor + PHY status + 4*8bytes to set.*/
#define BIT_RXFFOVFL_RSV(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_RXFFOVFL_RSV(x) ((u32)(((x >> 8) & 0x0000000F)))
/** @} */

/** @defgroup REG_PTA_I2C_MBOX
  * @brief
  * @{
  */
#define BIT_MASK_I2C_M_STATUS     ((u32)0x0000000F << 8)           /*!< R 0x0  Read these can get the I2C_M_STATUS of PTA_I2C's OUTPUT.*/
#define BIT_I2C_M_STATUS(x)       (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_I2C_M_STATUS(x)   ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_I2C_M_BUS_GNT    ((u32)0x00000007 << 4)           /*!< R/W 0x0  Use this bit to control PTA_I2C's BUS_GNT. 100 for gnt_txdata, 010 for gnt_txack,  001 for gnt_rxstatus.*/
#define BIT_I2C_M_BUS_GNT(x)      (((u32)((x) & 0x00000007) << 4))
#define BIT_GET_I2C_M_BUS_GNT(x)  ((u32)(((x >> 4) & 0x00000007)))
#define BIT_I2C_GNT_FW            ((u32)0x00000001 << 3)           /*!< R/W 0x0  Use this bit to control PTA_I2C_GNT_FW input. 1 for FW I2C bus arbiter,  0 for HW as I2C bus arbiter.*/
#define BIT_MASK_I2C_DATA_RATE    ((u32)0x00000003 << 1)           /*!< R/W 0x0  Use these bit to control PTA_I2C I2C interface data rate. SCL = clk / 2^(3 + I2C_DATA_RATE)*/
#define BIT_I2C_DATA_RATE(x)      (((u32)((x) & 0x00000003) << 1))
#define BIT_GET_I2C_DATA_RATE(x)  ((u32)(((x >> 1) & 0x00000003)))
#define BIT_I2C_SW_CONTROL_UNLOCK ((u32)0x00000001 << 0)           /*!< R/W 0x0  If this bit is set, PTA_I2C use 118H and 119H to control PTA_I2C*/
/** @} */

/** @defgroup REG_RXFF_PTR
  * @brief
  * @{
  */
#define BIT_MASK_RXFF0_RDPTR   ((u32)0x0000FFFF << 16)           /*!< R 0x0  The read pointer address of RXFF0. The value is set to the physical LX bus address.*/
#define BIT_RXFF0_RDPTR(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_RXFF0_RDPTR(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_RXFF0_WTPTR   ((u32)0x0000FFFF << 0)            /*!< R 0x0  The write pointer address of RXFF0. The value is set to the physical LX bus address.*/
#define BIT_RXFF0_WTPTR(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_RXFF0_WTPTR(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_FEIMR
  * @brief
  * @{
  */
#define BIT_H2C_OK_INT_MSK               ((u32)0x00000001 << 31) /*!< R/W 0x0  H2C TXDMA OK INT mask*/
#define BIT_H2C_CMD_FULL_INT_MSK         ((u32)0x00000001 << 30) /*!< R/W 0x0  H2C queue full interrupt mask*/
#define BIT_PWR_INT_127_MSK_V1           ((u32)0x00000001 << 29) /*!< R/W 0x0  MACID 127 power bit change interrupt mask*/
#define BIT_PWR_INT_126_MSK              ((u32)0x00000001 << 28) /*!< R/W 0x0  MACID 126 power bit change interrupt mask*/
#define BIT_WLANINT2_1_WIRED_MAILBOX_MSK ((u32)0x00000001 << 27) /*!< R/W 0x0  */
#define BIT_PWR_INT_95TO64_MSK_V1        ((u32)0x00000001 << 26) /*!< R/W 0x0  MACID 95~64 power bit change interrupt mask*/
#define BIT_WLANINT2_SCORE_BOARD_MSK     ((u32)0x00000001 << 25) /*!< R/W 0x0  MACID 63~32 power bit change interrupt mask*/
#define BIT_WLANINT2_GNT_BT_FALL_MSK     ((u32)0x00000001 << 24) /*!< R/W 0x0  MACID 31~0 power bit change interrupt mask*/
#define BIT_WLANINT2_GNT_BT_RISE_MSK     ((u32)0x00000001 << 23) /*!< R/W 0x0  */
#define BIT_BF0_TIMEOUT_INT_MSK          ((u32)0x00000001 << 21) /*!< R/W 0x0  Beamformer Wait user0's CSI report timeout interrupt mask*/
#define BIT_BF1_TIMEOUT_INT_MSK          ((u32)0x00000001 << 20) /*!< R/W 0x0  Beamformer Wait user1's CSI report timeout interrupt mask*/
#define BIT_EVTQ_TXDONE_INT_MSK          ((u32)0x00000001 << 19) /*!< R/W 0x0  Event queue TX done interrupt mask, for NAN*/
#define BIT_EVTQ_START_INT_MSK           ((u32)0x00000001 << 18) /*!< R/W 0x0  Event queue start interrupt mask, for NAN*/
#define BIT_TXBCN2_OK_INT_MSK            ((u32)0x00000001 << 17) /*!< R/W 0x0  Port 2 TX beacon ok interrupt mask, for NAN*/
#define BIT_TXBCN2_ERR_INT_MSK           ((u32)0x00000001 << 16) /*!< R/W 0x0  Port 2 TX beacon error interrupt mask, for NAN*/
#define BIT_DWWIN_END_INT_MSK            ((u32)0x00000001 << 15) /*!< R/W 0x0  Discovery window end interrupt mask, for NAN*/
#define BIT_BCN2_EARLY_INT_MSK           ((u32)0x00000001 << 14) /*!< R/W 0x0  Port 2 Beacon early interrupt mask, for NAN*/
#define BIT_TBTT1_INT_MSK                ((u32)0x00000001 << 13) /*!< R/W 0x0  Port1 TBTT interrupt mask*/
#define BIT_PSTIMERB_INT_MSK             ((u32)0x00000001 << 12) /*!< R/W 0x0  Timer B timeout interrupt mask, for NAN*/
#define BIT_PSTIMERA_INT_MSK             ((u32)0x00000001 << 11) /*!< R/W 0x0  Timer A timeout interrupt mask, for NAN*/
#define BIT_P2P_RFOFF_EARLY_INT_MSK      ((u32)0x00000001 << 10) /*!< R/W 0x0  P2P NoA RF off time early interrupt mask*/
#define BIT_MACID_RELEASE_INT_MSK        ((u32)0x00000001 << 9)  /*!< R/W 0x0  Interrupt mask for releasing one packet for MACID which is in low power mode*/
#define BIT_NANRPT_DONE_INT_MSK          ((u32)0x00000001 << 8)  /*!< R/W 0x0  Interrupt mask for WMAC finish parsing NAN beacon and writing the report to TXRPTBUF*/
#define BIT_FTM_PTT_INT_MSK_V1           ((u32)0x00000001 << 7)  /*!< R/W 0x0  FTM related interrupt mask*/
#define BIT_RXFTMREQ_OK_INT_MSK          ((u32)0x00000001 << 6)  /*!< R/W 0x0  RX FTM request frame ok interrupt mask*/
#define BIT_RXFTM_INT_MSK_V1             ((u32)0x00000001 << 5)  /*!< R/W 0x0  RX FTM frame and response TXOK interrupt mask*/
#define BIT_TXFTM_INT_MSK_V1             ((u32)0x00000001 << 4)  /*!< R/W 0x0  TX FTM frame ok interrupt mask*/
#define BIT_LTECOEX_INT_MSK              ((u32)0x00000001 << 3)  /*!< R/W 0x0  LTE coexistence interrupt mask*/
#define BIT_MAILBOX_INT_MSK              ((u32)0x00000001 << 2)  /*!< R/W 0x0  Mailbox INT mask , from TOP pin i2c_int*/
#define BIT_FLC_DRUTO_INT_MSK            ((u32)0x00000001 << 1)  /*!< R/W 0x0  FLC_CNT timeout interrupt mask, related to register 0x6AC*/
#define BIT_FLC_PKTTH_INT_MSK            ((u32)0x00000001 << 0)  /*!< R/W 0x0  FLC packet counter reach threshold interrupt mask, related to register 0x6AC*/
/** @} */

/** @defgroup REG_FEISR
  * @brief
  * @{
  */
#define BIT_H2C_OK_INT                   ((u32)0x00000001 << 31) /*!< R/W1C 0x0  H2C TXDMA OK INT*/
#define BIT_H2C_CMD_FULL_INT             ((u32)0x00000001 << 30) /*!< R/W1C 0x0  H2C queue full interrupt*/
#define BIT_PWR_INT_127_V2               ((u32)0x00000001 << 29) /*!< R/W1C 0x0  MACID 127 power bit change interrupt*/
#define BIT_PWR_INT_126                  ((u32)0x00000001 << 28) /*!< R/W1C 0x0  MACID 126 power bit change interrupt*/
#define BIT_WLANINT2_1_WIRED_MAILBOX     ((u32)0x00000001 << 27) /*!< R/W1C 0x0  */
#define BIT_PWR_INT_95TO64_V1            ((u32)0x00000001 << 26) /*!< R/W1C 0x0  MACID 95~64 power bit change interrupt*/
#define BIT_WLANINT2_SCORE_BOARD         ((u32)0x00000001 << 25) /*!< R/W1C 0x0  */
#define BIT_WLANINT2_GNT_BT_FALL         ((u32)0x00000001 << 24) /*!< R/W1C 0x0  */
#define BIT_WLANINT2_GNT_BT_RISE         ((u32)0x00000001 << 23) /*!< R/W 0x0  */
#define BIT_BF0_TIMEOUT_INT              ((u32)0x00000001 << 21) /*!< R/W1C 0x0  Beamformer Wait user0's CSI report timeout interrupt*/
#define BIT_BF1_TIMEOUT_INT              ((u32)0x00000001 << 20) /*!< R/W1C 0x0  Beamformer Wait user1's CSI report timeout interrupt*/
#define BIT_EVTQ_TXDONE_INT              ((u32)0x00000001 << 19) /*!< R/W1C 0x0  Event queue TX done interrupt, for NAN*/
#define BIT_EVTQ_START_INT               ((u32)0x00000001 << 18) /*!< R/W1C 0x0  Event queue start interrupt, for NAN*/
#define BIT_TXBCN2_OK_INT                ((u32)0x00000001 << 17) /*!< R/W1C 0x0  Port 2 TX beacon ok interrupt, for NAN*/
#define BIT_TXBCN2_ERR_INT               ((u32)0x00000001 << 16) /*!< R/W1C 0x0  Port 2 TX beacon error interrupt, for NAN*/
#define BIT_DWWIN_END_INT                ((u32)0x00000001 << 15) /*!< R/W1C 0x0  Discovery window end interrupt, for NAN*/
#define BIT_BCN2_EARLY_INT               ((u32)0x00000001 << 14) /*!< R/W1C 0x0  Port 2 Beacon early interrupt, for NAN*/
#define BIT_TBTT1_INT                    ((u32)0x00000001 << 13) /*!< R/W1C 0x0  Port1 TBTT interrupt*/
#define BIT_PSTIMERB_INT                 ((u32)0x00000001 << 12) /*!< R/W1C 0x0  Timer B timeout interrupt, for NAN*/
#define BIT_PSTIMERA_INT                 ((u32)0x00000001 << 11) /*!< R/W1C 0x0  Timer A timeout interrupt, for NAN*/
#define BIT_P2P_RFOFF_EARLY_INT          ((u32)0x00000001 << 10) /*!< R/W1C 0x0  P2P NoA RF off time early interrupt*/
#define BIT_MACID_RELEASE_INT            ((u32)0x00000001 << 9)  /*!< R/W1C 0x0  When release one packet for MACID which is in low power mode, this interrupt will be triggered.*/
#define BIT_NANRPT_DONE_INT              ((u32)0x00000001 << 8)  /*!< R/W1C 0x0  When WMAC finish parsing NAN beacon and writing the report to TXRPTBUF, this interrupt will be triggered.*/
#define BIT_FTM_PTT_INT_V1               ((u32)0x00000001 << 7)  /*!< R/W1C 0x0  FTM related interrupt*/
#define BIT_RXFTMREQ_OK_INT              ((u32)0x00000001 << 6)  /*!< R/W1C 0x0  RX FTM request frame ok interrupt*/
#define BIT_RXFTM_INT_V1                 ((u32)0x00000001 << 5)  /*!< R/W1C 0x0  RX FTM frame and response TXOK interrupt*/
#define BIT_TXFTM_INT_V1                 ((u32)0x00000001 << 4)  /*!< R/W1C 0x0  TX FTM frame ok interrupt*/
#define BIT_LTECOEX_INT                  ((u32)0x00000001 << 3)  /*!< R/W1C 0x0  LTE coexistence interrupt*/
#define BIT_MAILBOX_INT                  ((u32)0x00000001 << 2)  /*!< R/W1C 0x0  Mailbox INT from TOP pin i2c_int*/
#define BIT_FLC_DRUTO_INT                ((u32)0x00000001 << 1)  /*!< R/W1C 0x0  FLC_CNT timeout interrupt, related to register 0x6AC*/
#define BIT_FLC_PKTTH_INT                ((u32)0x00000001 << 0)  /*!< R/W1C 0x0  FLC packet counter reach threshold interrupt, related to register 0x6AC*/
/** @} */

/** @defgroup REG_CPWM
  * @brief
  * @{
  */
#define BIT_CPWM_TOGGLING   ((u32)0x00000001 << 31)           /*!< R/W 0x0  Toggling bit : one bit sequence number bit. When this bit is toggled, interrupt is send to HISR.CPWMINT.*/
#define BIT_MASK_CPWM_MOD   ((u32)0x0000007F << 24)           /*!< R/W 0x0  The current power mode index.*/
#define BIT_CPWM_MOD(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_CPWM_MOD(x) ((u32)(((x >> 24) & 0x0000007F)))
/** @} */

/** @defgroup REG_FWIMR
  * @brief
  * @{
  */
#define BIT_PCIE_BCNDMAERR_INT_MSK ((u32)0x00000001 << 31) /*!< R/W 0x0  PCIE BCN DMA error interrupt mask*/
#define BIT_SOUND_DONE_INT_MSK     ((u32)0x00000001 << 30) /*!< R/W 0x0  sounding finish interrupt mask for a beamformer*/
#define BIT_TRY_DONE_INT_MSK       ((u32)0x00000001 << 29) /*!< R/W 0x0  TRY_FINISH interrupt mask*/
#define BIT_TXRPT_CNT_FULL_INT_MSK ((u32)0x00000001 << 28) /*!< R/W 0x0  TXRPT HW statistic counter full interrupt mask*/
#define BIT_WLACTOFF_INT_MSK       ((u32)0x00000001 << 27) /*!< R/W 0x0  Enable interrupt source from WL_ACT_MASK_ON de-assertion for bt coexistence function*/
#define BIT_WLACTON_INT_MSK        ((u32)0x00000001 << 26) /*!< R/W 0x0  Enable interrupt source from WL_ACT_MASK_ON assertion for bt coexistence function*/
#define BIT_TXPKTIN_INT_MSK        ((u32)0x00000001 << 25) /*!< R/W 0x0  Interrupt mask for a packet is written into TXPKTBUF*/
#define BIT_TXBCNOK_INT_MSK        ((u32)0x00000001 << 24) /*!< R/W 0x0  TX beacon OK interrupt mask*/
#define BIT_TXBCNERR_INT_MSK       ((u32)0x00000001 << 23) /*!< R/W 0x0  TX beacon Error interrupt mask*/
#define BIT_RX_UMD0_INT_MSK        ((u32)0x00000001 << 22) /*!< R/W 0x0  Enable interrupt source from receiving unicast data frame with More Data=0*/
#define BIT_RX_UMD1_INT_MSK        ((u32)0x00000001 << 21) /*!< R/W 0x0  Enable interrupt source from receiving unicast data frame with More Data=1*/
#define BIT_RX_BMD0_INT_MSK        ((u32)0x00000001 << 20) /*!< R/W 0x0  Enable interrupt source from receiving broadcast data frame with More Data=0*/
#define BIT_RX_BMD1_INT_MSK        ((u32)0x00000001 << 19) /*!< R/W 0x0  Enable interrupt source from receiving broadcast data frame with More Data=1*/
#define BIT_BCN_RX_INT_INT_MSK     ((u32)0x00000001 << 18) /*!< R/W 0x0  RX beacon OK interrupt mask*/
#define BIT_TBTTINT_INT_MSK        ((u32)0x00000001 << 17) /*!< R/W 0x0  The exact TBTT time interrupt mask.*/
#define BIT_BCNERLY_INT_MSK        ((u32)0x00000001 << 16) /*!< R/W 0x0  Beacon early interrupt mask*/
#define BIT_BCNDMA7_INT_MSK        ((u32)0x00000001 << 15) /*!< R/W 0x0  BCNDMA interrupt mask for MBSSID 7 When enable MBSSID mode*/
#define BIT_BCNDMA6_INT_MSK        ((u32)0x00000001 << 14) /*!< R/W 0x0  BCNDMA interrupt mask for MBSSID 6 When enable MBSSID mode*/
#define BIT_BCNDMA5_INT_MSK        ((u32)0x00000001 << 13) /*!< R/W 0x0  BCNDMA interrupt mask for MBSSID 5 When enable MBSSID mode*/
#define BIT_BCNDMA4_INT_MSK        ((u32)0x00000001 << 12) /*!< R/W 0x0  BCNDMA interrupt mask for MBSSID 4 When enable MBSSID mode*/
#define BIT_BCNDMA3_INT_MSK        ((u32)0x00000001 << 11) /*!< R/W 0x0  BCNDMA interrupt mask for MBSSID 3 When enable MBSSID mode*/
#define BIT_BCNDMA2_INT_MSK        ((u32)0x00000001 << 10) /*!< R/W 0x0  BCNDMA interrupt mask for MBSSID 2 When enable MBSSID mode*/
#define BIT_BCNDMA1_INT_MSK        ((u32)0x00000001 << 9)  /*!< R/W 0x0  BCNDMA interrupt mask for MBSSID 1 When enable MBSSID mode*/
#define BIT_BCNDMA0_INT_MSK        ((u32)0x00000001 << 8)  /*!< R/W 0x0  BCNDMA interrupt mask for MBSSID 0 When enable MBSSID mode or the root BSSID BCNDMA interrupt mask*/
#define BIT_LP_STBY_INT_MSK        ((u32)0x00000001 << 7)  /*!< R/W 0x0  Lower Power Standby Interrupt mask*/
#define BIT_CTWENDINT_INT_MSK      ((u32)0x00000001 << 6)  /*!< R/W 0x0  CTWindow End interrupt mask*/
#define BIT_HRCV_INT_MSK           ((u32)0x00000001 << 5)  /*!< R/W 0x0  Host to CPU Message Interrupt mask*/
#define BIT_H2CCMD_INT_MSK         ((u32)0x00000001 << 4)  /*!< R/W 0x0  Host To CPU Message Interrupt mask*/
#define BIT_RXDONE_INT_MSK         ((u32)0x00000001 << 3)  /*!< R/W 0x0  Rx Packet done interrupt mask*/
#define BIT_ERRORHDL_INT_MSK       ((u32)0x00000001 << 2)  /*!< R/W 0x0  FWHW/ TXDMA/ RXDMA/ WMAC error status interrupt mask*/
#define BIT_TXCCX_INT_MSK          ((u32)0x00000001 << 1)  /*!< R/W 0x0  CCX PKT TX Report Interrupt mask*/
#define BIT_TXCLOSE_INT_MSK        ((u32)0x00000001 << 0)  /*!< R/W 0x0  TX Finish (Ack/BA process Finish) Interrupt mask*/
/** @} */

/** @defgroup REG_FWISR
  * @brief
  * @{
  */
#define BIT_PCIE_BCNDMAERR_INT ((u32)0x00000001 << 31) /*!< R/W1C 0x0  PCIE BCN DMA error interrupt*/
#define BIT_SOUND_DONE_INT     ((u32)0x00000001 << 30) /*!< R/W1C 0x0  For a beamformer, this interrupt is issued at the time after sounding finish*/
#define BIT_TRY_DONE_INT       ((u32)0x00000001 << 29) /*!< R/W1C 0x0  When TRY_FINISH is deasserted, this interrupt is issued to inform MCU*/
#define BIT_TXRPT_CNT_FULL_INT ((u32)0x00000001 << 28) /*!< R/W1C 0x0  This interrupt is issued if any of the TXRPT HW statistic counter is full.*/
#define BIT_WLACTOFF_INT       ((u32)0x00000001 << 27) /*!< R/W1C 0x0  Interrupt source from WL_ACT_MASK_ON, de-assertion for bt coexistence function*/
#define BIT_WLACTON_INT        ((u32)0x00000001 << 26) /*!< R/W1C 0x0  Interrupt source from WL_ACT_MASK_ON, assertion for bt coexistence function*/
#define BIT_TXPKTIN_INT        ((u32)0x00000001 << 25) /*!< R/W1C 0x0  When a packet is written into TXPKTBUF, this interrupt is issued to inform MCU.*/
#define BIT_TXBCNOK_INT        ((u32)0x00000001 << 24) /*!< R/W1C 0x0  TX beacon OK interrupt*/
#define BIT_TXBCNERR_INT       ((u32)0x00000001 << 23) /*!< R/W1C 0x0  TX beacon Error interrupt*/
#define BIT_RX_UMD0_INT        ((u32)0x00000001 << 22) /*!< R/W1C 0x0  interrupt source from receiving unicast data frame with More Data=0*/
#define BIT_RX_UMD1_INT        ((u32)0x00000001 << 21) /*!< R/W1C 0x0  interrupt source from receiving unicast data frame with More Data=1*/
#define BIT_RX_BMD0_INT        ((u32)0x00000001 << 20) /*!< R/W1C 0x0  interrupt source from receiving broadcast data frame with More Data=0*/
#define BIT_RX_BMD1_INT        ((u32)0x00000001 << 19) /*!< R/W1C 0x0  interrupt source from receiving broadcast data frame with More Data=1*/
#define BIT_BCN_RX_INT_INT     ((u32)0x00000001 << 18) /*!< R/W1C 0x0  RX beacon OK interrupt*/
#define BIT_TBTTINT_INT        ((u32)0x00000001 << 17) /*!< R/W1C 0x0  The exact TBTT time interrupt. In MBSSID mode, 8 TBTTINT interrupts are integrated to this single interrupt signal. Write one clear.*/
#define BIT_BCNERLY_INT        ((u32)0x00000001 << 16) /*!< R/W1C 0x0  This interrupt is issued at the time set by DRVERLYINT register before TBTT time.*/
#define BIT_BCNDMA7_INT        ((u32)0x00000001 << 15) /*!< R/W1C 0x0  When BCNDMA interval arrives before TBTT7, this interrupt informs MCU to prepare related beacon tasks.*/
#define BIT_BCNDMA6_INT        ((u32)0x00000001 << 14) /*!< R/W1C 0x0  When BCNDMA interval arrives before TBTT6, this interrupt informs MCU to prepare related beacon tasks.*/
#define BIT_BCNDMA5_INT        ((u32)0x00000001 << 13) /*!< R/W1C 0x0  When BCNDMA interval arrives before TBTT5, this interrupt informs MCU to prepare related beacon tasks.*/
#define BIT_BCNDMA4_INT        ((u32)0x00000001 << 12) /*!< R/W1C 0x0  When BCNDMA interval arrives before TBTT4, this interrupt informs MCU to prepare related beacon tasks.*/
#define BIT_BCNDMA3_INT        ((u32)0x00000001 << 11) /*!< R/W1C 0x0  When BCNDMA interval arrives before TBTT3, this interrupt informs MCU to prepare related beacon tasks.*/
#define BIT_BCNDMA2_INT        ((u32)0x00000001 << 10) /*!< R/W1C 0x0  When BCNDMA interval arrives before TBTT2, this interrupt informs MCU to prepare related beacon tasks.*/
#define BIT_BCNDMA1_INT        ((u32)0x00000001 << 9)  /*!< R/W1C 0x0  When BCNDMA interval arrives before TBTT1, this interrupt informs MCU to prepare related beacon tasks.*/
#define BIT_BCNDMA0_INT        ((u32)0x00000001 << 8)  /*!< R/W1C 0x0  When BCNDMA interval arrives before TBTT0, this interrupt informs MCU to prepare related beacon tasks.*/
#define BIT_LP_STBY_INT        ((u32)0x00000001 << 7)  /*!< R/W1C 0x0  Lower Power Standby Interrupt*/
#define BIT_CTWENDINT_INT      ((u32)0x00000001 << 6)  /*!< R/W1C 0x0  CTWindow End interrupt.*/
#define BIT_HRCV_INT           ((u32)0x00000001 << 5)  /*!< R/W1C 0x0  Host to CPU Message Interrupt, generated on writing to 0x1CF*/
#define BIT_H2CCMD_INT         ((u32)0x00000001 << 4)  /*!< R/W1C 0x0  Host To CPU Message Interrupt*/
#define BIT_RXDONE_INT         ((u32)0x00000001 << 3)  /*!< R/W1C 0x0  Rx Packet done for 8051*/
#define BIT_ERRORHDL_INT       ((u32)0x00000001 << 2)  /*!< R/W1C 0x0  FWHW/ TXDMA/ RXDMA/ WMAC error status interrupt*/
#define BIT_TXCCX_INT          ((u32)0x00000001 << 1)  /*!< R/W1C 0x0  CCX PKT TX Report Interrupt*/
#define BIT_TXCLOSE_INT        ((u32)0x00000001 << 0)  /*!< R/W1C 0x0  TX Finish (Ack/BA process Finish) Interrupt.*/
/** @} */

/** @defgroup REG_FTIMR
  * @brief
  * @{
  */
#define BIT_FS_GTINT6_INT_MSK         ((u32)0x00000001 << 31) /*!< R/W 0x0  General Timer[6] interrupt*/
#define BIT_TX_NULL1_INT_MSK          ((u32)0x00000001 << 30) /*!< R/W 0x0  TX null 1 packet done interrupt mask*/
#define BIT_TX_NULL0_INT_MSK          ((u32)0x00000001 << 29) /*!< R/W 0x0  TX null 0 packet done interrupt mask*/
#define BIT_MTI_BCNIVLEAR_INT_MSK     ((u32)0x00000001 << 28) /*!< R/W 0x0  Multiple beacon interval early interrupt. When BCNIVLCOUNT=1, it will be issued.*/
#define BIT_ATIM_INT_MSK              ((u32)0x00000001 << 27) /*!< R/W 0x0  ATIM Window End interrupt mask for Port0*/
#define BIT_WWLAN_INT_MSK             ((u32)0x00000001 << 26) /*!< R/W 0x0  WWLAN event interrupt mask*/
#define BIT_C2H_W_READY_MSK           ((u32)0x00000001 << 25) /*!< R/W 0x0  Indicating the C2H register ready for write, 1: ready*/
#define BIT_TRL_MTR_INT_MSK           ((u32)0x00000001 << 24) /*!< R/W 0x0  Thermal meter interrupt mask*/
#define BIT_CLR_PS_STATUS_MSK         ((u32)0x00000001 << 23) /*!< R/W 0x0  Interrupt mask for Rx pkt matching with one of below: 1.) QoS Unicast data frame with MD=0, UAPSD=0 2.) NonQoS Unicast data frame with MD=0*/
#define BIT_RETRIEVE_BUFFERED_INT_MSK ((u32)0x00000001 << 22) /*!< R/W 0x0  Interrupt mask for Rx pkt is matching with one of below: 1.) QoS Unicast data frame with MD=1, UAPSD=0 2.) NonQoS Unicast data frame with MD=1*/
#define BIT_RPWM2INT_MSK              ((u32)0x00000001 << 21) /*!< R/W 0x0  RPWM2 INT mask*/
#define BIT_TSF_BIT32_TOGGLE_INT_MSK  ((u32)0x00000001 << 20) /*!< R/W 0x0  TSF Timer BIT32 toggle indication interrupt mask*/
#define BIT_TRIGGER_PKT_MSK           ((u32)0x00000001 << 19) /*!< R/W 0x0  Interrupt mask for pkt Tx ok which TriggerPkt bit of TXDESC is equal to 1*/
#define BIT_FW_BTCMD_INT_MSK          ((u32)0x00000001 << 18) /*!< R/W 0x0  Interrupt mask for BT sending command via BTCOEX Interface*/
#define BIT_P2P_RFOFF_INT_MSK         ((u32)0x00000001 << 17) /*!< R/W 0x0  P2P NoA RF off time indication interrupt mask*/
#define BIT_P2P_RFON_INT_MSK          ((u32)0x00000001 << 16) /*!< R/W 0x0  P2P NoA RF on time indication interrupt mask*/
#define BIT_TX_BCN1ERR_INT_MSK        ((u32)0x00000001 << 15) /*!< R/W 0x0  Port 1 Tx BCN error interrupt mask*/
#define BIT_TX_BCN1OK_INT_MSK         ((u32)0x00000001 << 14) /*!< R/W 0x0  Port 1 TxBCN1 OK interrupt mask*/
#define BIT_FT_ATIMEND_E_MSK          ((u32)0x00000001 << 13) /*!< R/W 0x0  ATIM Window End interrupt mask for Port1*/
#define BIT_BCNDMAINT_E_MSK_V1        ((u32)0x00000001 << 12) /*!< R/W 0x0  Beacon DMA Interrupt mask for Port1*/
#define BIT_FS_GTINT5_INT_MSK         ((u32)0x00000001 << 11) /*!< R/W 0x0  General Timer[5] interrupt mask*/
#define BIT_EOSP_INT_MSK              ((u32)0x00000001 << 10) /*!< R/W 0x0  Receiving Unicast, A1 matched QoS data type (including QoS NULL) packet interrupt mask*/
#define BIT_RX_BCN_E_INT_MSK          ((u32)0x00000001 << 9)  /*!< R/W 0x0  interrupt mask for receiving beacon matching BSSID1*/
#define BIT_RPWMINT_MSK               ((u32)0x00000001 << 8)  /*!< R/W 0x0  RPWM INT  mask*/
#define BIT_PSTIMER_INT_MSK           ((u32)0x00000001 << 7)  /*!< R/W 0x0  Enable PSTimer interrupt source*/
#define BIT_TIMEOUT1_INT_MSK          ((u32)0x00000001 << 6)  /*!< R/W 0x0  Enable Timer1 interrupt source*/
#define BIT_TIMEOUT0_INT_MSK          ((u32)0x00000001 << 5)  /*!< R/W 0x0  Enable Timer0 interrupt source*/
#define BIT_FS_GTINT4_INT_MSK         ((u32)0x00000001 << 4)  /*!< R/W 0x0  General Timer[4] interrupt mask*/
#define BIT_FS_GTINT3_INT_MSK         ((u32)0x00000001 << 3)  /*!< R/W 0x0  General Timer[3] interrupt mask*/
#define BIT_FS_GTINT2_INT_MSK         ((u32)0x00000001 << 2)  /*!< R/W 0x0  General Timer[2] interrupt mask*/
#define BIT_FS_GTINT1_INT_MSK         ((u32)0x00000001 << 1)  /*!< R/W 0x0  General Timer[1] interrupt mask*/
#define BIT_FS_GTINT0_INT_MSK         ((u32)0x00000001 << 0)  /*!< R/W 0x0  General Timer[0] interrupt mask*/
/** @} */

/** @defgroup REG_FTISR
  * @brief
  * @{
  */
#define BIT_FS_GTINT6_INT           ((u32)0x00000001 << 31) /*!< R/W1C 0x0  General Timer[6] interrupt*/
#define BIT_TX_NULL1_INT            ((u32)0x00000001 << 30) /*!< R/W1C 0x0  TX null 1 packet done interrupt mask*/
#define BIT_TX_NULL0_INT            ((u32)0x00000001 << 29) /*!< R/W1C 0x0  TX null 0 packet done interrupt mask*/
#define BIT_MTI_BCNIVLEAR_INT       ((u32)0x00000001 << 28) /*!< R/W1C 0x0  Multiple beacon interval early interrupt. When BCNIVLCOUNT=1, it will be issued.*/
#define BIT_ATIM_INT                ((u32)0x00000001 << 27) /*!< R/W1C 0x0  This interrupt is issued when it is at the time ATIM ms before ATIMWND expiring*/
#define BIT_WWLAN_INT               ((u32)0x00000001 << 26) /*!< R/W1C 0x0  HW detect WWLAN event.*/
#define BIT_C2H_W_READY             ((u32)0x00000001 << 25) /*!< R/WIC 0x0  Indicating the C2H register ready for write, 1: ready*/
#define BIT_TRL_MTR_INT             ((u32)0x00000001 << 24) /*!< R/WIC 0x0  Thermal meter interrupt*/
#define BIT_CLR_PS_STATUS           ((u32)0x00000001 << 23) /*!< R/WIC 0x0  Setting this bit indicates Rx pkt is matched with one of below: 1.) QoS Unicast data frame with MD=0, UAPSD=0 2.) NonQoS Unicast data frame with MD=0*/
#define BIT_RETRIEVE_BUFFERED_INT   ((u32)0x00000001 << 22) /*!< R/WIC 0x0  Setting this bit indicates Rx pkt is matched with one of below: 1.) QoS Unicast data frame with MD=1, UAPSD=0 2.) NonQoS Unicast data frame with MD=1*/
#define BIT_RPWM2INT                ((u32)0x00000001 << 21) /*!< R/WIC 0x0  RPWM2 INT Status. Write 1 clear.*/
#define BIT_TSF_BIT32_TOGGLE_INT_V1 ((u32)0x00000001 << 20) /*!< R/WIC 0x0  TSF Timer BIT32 toggle indication interrupt*/
#define BIT_TRIGGER_PKT             ((u32)0x00000001 << 19) /*!< R/WIC 0x0  Setting this bit indicates that the pkt is Tx ok which TriggerPkt bit of TXDESC is equal to 1*/
#define BIT_FW_BTCMD_INT            ((u32)0x00000001 << 18) /*!< R/WIC 0x0  When BT sends command via BTCOEX Intf, this interrupt is issued.*/
#define BIT_P2P_RFOFF_INT           ((u32)0x00000001 << 17) /*!< R/WIC 0x0  P2P NoA RF off time indication interrupt*/
#define BIT_P2P_RFON_INT            ((u32)0x00000001 << 16) /*!< R/WIC 0x0  P2P NoA RF on time indication interrupt*/
#define BIT_TX_BCN1ERR_INT          ((u32)0x00000001 << 15) /*!< R/WIC 0x0  Port 1 Tx BCN error interrupt*/
#define BIT_TX_BCN1OK_INT           ((u32)0x00000001 << 14) /*!< R/WIC 0x0  Port 1TxBCN1 OK interrupt*/
#define BIT_FT_ATIMEND_E            ((u32)0x00000001 << 13) /*!< R/WIC 0x0  ATIM Window End Extension for Win7This is used to indicate that ATIM window has ended of port 1.  Driver can configure the time to assert this interrupt with BcnDMATIM register.*/
#define BIT_BCNDMAINT_E_V1          ((u32)0x00000001 << 12) /*!< R/WIC 0x0  Beacon DMA Interrupt Extension for Win7 Setting this bit indicates it is time to prepare to receiving Beacon of port 1 client port.*/
#define BIT_FS_GTINT5_INT           ((u32)0x00000001 << 11) /*!< R/WIC 0x0  General Timer[5] interrupt*/
#define BIT_EOSP_INT                ((u32)0x00000001 << 10) /*!< R/WIC 0x0  When Unicast, A1 matched QoS data type (including QoS NULL) received, this interrupt is issued to MCU.*/
#define BIT_RX_BCN_E_INT            ((u32)0x00000001 << 9)  /*!< R/WIC 0x0  When receiving beacon matching BSSID1, this interrupt is issued.*/
#define BIT_RPWMINT                 ((u32)0x00000001 << 8)  /*!< R/WIC 0x0  RPWM INT Status. Write 1 clear.*/
#define BIT_PSTIMER_INT             ((u32)0x00000001 << 7)  /*!< R/WIC 0x0  Enable PSTimer interrupt source*/
#define BIT_TIMEOUT1_INT            ((u32)0x00000001 << 6)  /*!< R/WIC 0x0  Enable Timer1 interrupt source*/
#define BIT_TIMEOUT0_INT            ((u32)0x00000001 << 5)  /*!< R/WIC 0x0  Enable Timer0 interrupt source*/
#define BIT_FS_GTINT4_INT           ((u32)0x00000001 << 4)  /*!< R/WIC 0x0  General Timer[4] interrupt*/
#define BIT_FS_GTINT3_INT           ((u32)0x00000001 << 3)  /*!< R/WIC 0x0  General Timer[3] interrupt*/
#define BIT_FS_GTINT2_INT           ((u32)0x00000001 << 2)  /*!< R/WIC 0x0  General Timer[2] interrupt*/
#define BIT_FS_GTINT1_INT           ((u32)0x00000001 << 1)  /*!< R/WIC 0x0  General Timer[1] interrupt*/
#define BIT_FS_GTINT0_INT           ((u32)0x00000001 << 0)  /*!< R/WIC 0x0  General Timer[0] interrupt*/
/** @} */

/** @defgroup REG_PKTBUF_DBG_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_PKTBUF_WRITE_EN   ((u32)0x000000FF << 24)           /*!< R/W 0x0  8 bits for 8 bytes write enable*/
#define BIT_PKTBUF_WRITE_EN(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_PKTBUF_WRITE_EN(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_TXPKTBUF_DBG           ((u32)0x00000001 << 23)           /*!< R/W 0x0  0: enable read TXPKTBUF,and read back equal 0x1 which indicates HW done 1: enable write TXPKTBUF,and read back equal 0x0 which indicates HW done*/
#define BIT_TXRPTBUF_DBG_V2        ((u32)0x00000001 << 20)           /*!< R/W 0x0  0: enable read TXRPTBUF,and read back equal 0x1 which indicates HW done 1: enable write TXRPTBUF,and read back equal 0x0 which indicates HW done*/
#define BIT_RXPKTBUF_DBG           ((u32)0x00000001 << 16)           /*!< R/W 0x0  0: enable read RXPKTBUF,and read back equal 0x1 which indicates HW done 1: enable write RXPKTBUF,and read back equal 0x0 which indicates HW done*/
#define BIT_MASK_PKTBUF_DBG_ADDR   ((u32)0x00001FFF << 0)            /*!< R/W 0x0  TXRPTBUF/TXPKTBUF/RXPKTBUF Address,  unit: 8bytes*/
#define BIT_PKTBUF_DBG_ADDR(x)     (((u32)((x) & 0x00001FFF) << 0))
#define BIT_GET_PKTBUF_DBG_ADDR(x) ((u32)(((x >> 0) & 0x00001FFF)))
/** @} */

/** @defgroup REG_PKTBUF_DBG_DATA_L
  * @brief
  * @{
  */
#define BIT_MASK_PKTBUF_DBG_DATA_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  The data read from TX or RX Packet buffer.*/
#define BIT_PKTBUF_DBG_DATA_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_PKTBUF_DBG_DATA_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PKTBUF_DBG_DATA_H
  * @brief
  * @{
  */
#define BIT_MASK_PKTBUF_DBG_DATA_H   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  The data read from TX or RX Packet buffer.*/
#define BIT_PKTBUF_DBG_DATA_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_PKTBUF_DBG_DATA_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CPWM2
  * @brief
  * @{
  */
#define BIT_MASK_L0S_TO_RCVY_NUM   ((u32)0x000000FF << 16)           /*!< R/W 0x0  Number of L0S to recovery of PCIE*/
#define BIT_L0S_TO_RCVY_NUM(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_L0S_TO_RCVY_NUM(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_CPWM2_TOGGLING         ((u32)0x00000001 << 15)           /*!< R/W 0x0  Toggling bit : one bit sequence number bit. When this bit is toggled, interrupt is send to HISRE.CPWMINT.*/
#define BIT_MASK_CPWM2_MOD         ((u32)0x00007FFF << 0)            /*!< R/W 0x0  The current power mode index.*/
#define BIT_CPWM2_MOD(x)           (((u32)((x) & 0x00007FFF) << 0))
#define BIT_GET_CPWM2_MOD(x)       ((u32)(((x >> 0) & 0x00007FFF)))
/** @} */

/** @defgroup REG_TC0_CTRL
  * @brief
  * @{
  */
#define BIT_TC0INT_EN      ((u32)0x00000001 << 26)          /*!< R/W 0x0  When write "1" to this bit, Counter 0 starts counting down. This is a one-bit pulse.*/
#define BIT_TC0MODE        ((u32)0x00000001 << 25)          /*!< R/W 0x0  Timer/Counter 0 mode  0=counter mode 1=timer mode*/
#define BIT_TC0EN          ((u32)0x00000001 << 24)          /*!< R/W 0x0  Timer/Counter 0 enable*/
#define BIT_MASK_TC0DATA   ((u32)0x00FFFFFF << 0)           /*!< R/W 0x0  Timer/Counter 0 data register. It specifies the time-out duration.*/
#define BIT_TC0DATA(x)     (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_TC0DATA(x) ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_TC1_CTRL
  * @brief
  * @{
  */
#define BIT_TC1INT_EN      ((u32)0x00000001 << 26)          /*!< R/W 0x0  When write "1" to this bit, Counter 1 starts counting down. This is a one-bit pulse.*/
#define BIT_TC1MODE        ((u32)0x00000001 << 25)          /*!< R/W 0x0  Timer/Counter 1 mode  0=counter mode 1=timer mode*/
#define BIT_TC1EN          ((u32)0x00000001 << 24)          /*!< R/W 0x0  Timer/Counter 1 enable*/
#define BIT_MASK_TC1DATA   ((u32)0x00FFFFFF << 0)           /*!< R/W 0x0  Timer/Counter 1 data register. It specifies the time-out duration.*/
#define BIT_TC1DATA(x)     (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_TC1DATA(x) ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_TC2_CTRL
  * @brief
  * @{
  */
#define BIT_TC2INT_EN      ((u32)0x00000001 << 26)          /*!< R/W 0x0  When write "1" to this bit, Counter 2 starts counting down. This is a one-bit pulse.*/
#define BIT_TC2MODE        ((u32)0x00000001 << 25)          /*!< R/W 0x0  Timer/Counter 2 mode  0=counter mode 1=timer mode*/
#define BIT_TC2EN          ((u32)0x00000001 << 24)          /*!< R/W 0x0  Timer/Counter 2 enable*/
#define BIT_MASK_TC2DATA   ((u32)0x00FFFFFF << 0)           /*!< R/W 0x0  Timer/Counter 2 data register. It specifies the time-out duration.*/
#define BIT_TC2DATA(x)     (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_TC2DATA(x) ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_TC3_CTRL
  * @brief
  * @{
  */
#define BIT_TC3INT_EN      ((u32)0x00000001 << 26)          /*!< R/W 0x0  When write "1" to this bit, Counter 3 starts counting down. This is a one-bit pulse.*/
#define BIT_TC3MODE        ((u32)0x00000001 << 25)          /*!< R/W 0x0  Timer/Counter 3 mode  0=counter mode 1=timer mode*/
#define BIT_TC3EN          ((u32)0x00000001 << 24)          /*!< R/W 0x0  Timer/Counter 3 enable*/
#define BIT_MASK_TC3DATA   ((u32)0x00FFFFFF << 0)           /*!< R/W 0x0  Timer/Counter 3 data register. It specifies the time-out duration.*/
#define BIT_TC3DATA(x)     (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_TC3DATA(x) ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_TC4_CTRL
  * @brief
  * @{
  */
#define BIT_TC4INT_EN      ((u32)0x00000001 << 26)          /*!< R/W 0x0  When write "1" to this bit, Counter 1 starts counting down. This is a one-bit pulse.*/
#define BIT_TC4MODE        ((u32)0x00000001 << 25)          /*!< R/W 0x0  Timer/Counter 4mode  0=counter mode 1=timer mode*/
#define BIT_TC4EN          ((u32)0x00000001 << 24)          /*!< R/W 0x0  Timer/Counter 4 enable*/
#define BIT_MASK_TC4DATA   ((u32)0x00FFFFFF << 0)           /*!< R/W 0x0  Timer/Counter 4 data register. It specifies the time-out duration.*/
#define BIT_TC4DATA(x)     (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_TC4DATA(x) ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_TCUNIT_BASE
  * @brief
  * @{
  */
#define BIT_MASK_TCUNIT_BASE   ((u32)0x00003FFF << 0)           /*!< R/W 0x0  The register set the number of clocks that equals to the base time unit of timer/counter. The clock domain is 32K clock domain.*/
#define BIT_TCUNIT_BASE(x)     (((u32)((x) & 0x00003FFF) << 0))
#define BIT_GET_TCUNIT_BASE(x) ((u32)(((x >> 0) & 0x00003FFF)))
/** @} */

/** @defgroup REG_TC5_CTRL
  * @brief
  * @{
  */
#define BIT_TC5INT_EN      ((u32)0x00000001 << 26)          /*!< R/W 0x0  When write "1" to this bit, Counter 5 starts counting down. This is a one-bit pulse.*/
#define BIT_TC5MODE        ((u32)0x00000001 << 25)          /*!< R/W 0x0  Timer/Counter 5 mode  0=counter mode 1=timer mode*/
#define BIT_TC5EN          ((u32)0x00000001 << 24)          /*!< R/W 0x0  Timer/Counter 5 enable*/
#define BIT_MASK_TC5DATA   ((u32)0x00FFFFFF << 0)           /*!< R/W 0x0  Timer/Counter 5 data register. It specifies the time-out duration.*/
#define BIT_TC5DATA(x)     (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_TC5DATA(x) ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_TC6_CTRL
  * @brief
  * @{
  */
#define BIT_TC6INT_EN      ((u32)0x00000001 << 26)          /*!< R/W 0x0  When write "1" to this bit, Counter 6 starts counting down. This is a one-bit pulse.*/
#define BIT_TC6MODE        ((u32)0x00000001 << 25)          /*!< R/W 0x0  Timer/Counter 6 mode  0=counter mode 1=timer mode*/
#define BIT_TC6EN          ((u32)0x00000001 << 24)          /*!< R/W 0x0  Timer/Counter 6 enable*/
#define BIT_MASK_TC6DATA   ((u32)0x00FFFFFF << 0)           /*!< R/W 0x0  Timer/Counter 6 data register. It specifies the time-out duration.*/
#define BIT_TC6DATA(x)     (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_TC6DATA(x) ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_MBIST_DRF_FAIL
  * @brief
  * @{
  */
#define BIT_MASK_WLON_MBIST_DRF_FAIL       ((u32)0x00000003 << 30)           /*!< R 0x0  0x100[29]= 0,  MBIST DRF Fail bit 0~bit1 of WLAN partial-on Memory;  0x100[29]= 1,  0x0*/
#define BIT_WLON_MBIST_DRF_FAIL(x)         (((u32)((x) & 0x00000003) << 30))
#define BIT_GET_WLON_MBIST_DRF_FAIL(x)     ((u32)(((x >> 30) & 0x00000003)))
#define BIT_MASK_WLOFF_MBIST_DRF_FAIL      ((u32)0x00003FFF << 16)           /*!< R 0x0  0x100[29]= 0,  MBIST DRF Fail bit 0~bit13 of WLAN partial-off Memory;  0x100[29]= 1,  0x0*/
#define BIT_WLOFF_MBIST_DRF_FAIL(x)        (((u32)((x) & 0x00003FFF) << 16))
#define BIT_GET_WLOFF_MBIST_DRF_FAIL(x)    ((u32)(((x >> 16) & 0x00003FFF)))
#define BIT_MASK_PCIE_MBIST_DRF_FAIL_V1    ((u32)0x0000001F << 11)           /*!< R 0x0  0x100[29]= 0,  MBIST DRF Fail bit 0~bit4 of PCIE Memory;  0x100[29]= 1,  0x0*/
#define BIT_PCIE_MBIST_DRF_FAIL_V1(x)      (((u32)((x) & 0x0000001F) << 11))
#define BIT_GET_PCIE_MBIST_DRF_FAIL_V1(x)  ((u32)(((x >> 11) & 0x0000001F)))
#define BIT_MASK_USB_MBIST_DRF_FAIL_V1     ((u32)0x0000007F << 4)            /*!< R 0x0  0x100[29]= 0,  MBIST DRF Fail bit 4~bit10 of USB Memory;  0x100[29]= 1,  0x0*/
#define BIT_USB_MBIST_DRF_FAIL_V1(x)       (((u32)((x) & 0x0000007F) << 4))
#define BIT_GET_USB_MBIST_DRF_FAIL_V1(x)   ((u32)(((x >> 4) & 0x0000007F)))
#define BIT_MASK_USB_WLON_MBIST_DRF_FAIL   ((u32)0x0000000F << 0)            /*!< R 0x0  0x100[29]= 0,  MBIST DRF Fail bit 0~bit3 of USB Memory;  0x100[29]= 1,  MBIST DRF Fail bit 2~bit5 of Wlan partial-on Memory*/
#define BIT_USB_WLON_MBIST_DRF_FAIL(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_USB_WLON_MBIST_DRF_FAIL(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_MBIST_START_PAUSE
  * @brief
  * @{
  */
#define BIT_MASK_WLON_MBIST_START_PAUSE_V1    ((u32)0x00000003 << 9)           /*!< R 0x0  MBIST Start Pause of Wlan Partial-on Memory*/
#define BIT_WLON_MBIST_START_PAUSE_V1(x)      (((u32)((x) & 0x00000003) << 9))
#define BIT_GET_WLON_MBIST_START_PAUSE_V1(x)  ((u32)(((x >> 9) & 0x00000003)))
#define BIT_MASK_WLOFF_MBIST_START_PAUSE_V1   ((u32)0x0000001F << 4)           /*!< R 0x0  MBIST Start Pause of Wlan Partial-off Memory*/
#define BIT_WLOFF_MBIST_START_PAUSE_V1(x)     (((u32)((x) & 0x0000001F) << 4))
#define BIT_GET_WLOFF_MBIST_START_PAUSE_V1(x) ((u32)(((x >> 4) & 0x0000001F)))
#define BIT_MASK_PCIE_MBIST_START_PAUSE_V2    ((u32)0x00000003 << 2)           /*!< R 0x0  MBIST Start Pause of PCIE Memory*/
#define BIT_PCIE_MBIST_START_PAUSE_V2(x)      (((u32)((x) & 0x00000003) << 2))
#define BIT_GET_PCIE_MBIST_START_PAUSE_V2(x)  ((u32)(((x >> 2) & 0x00000003)))
#define BIT_MASK_USB_MBIST_START_PAUSE_V2     ((u32)0x00000003 << 0)           /*!< R 0x0  MBIST Start Pause of USB Memory*/
#define BIT_USB_MBIST_START_PAUSE_V2(x)       (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_USB_MBIST_START_PAUSE_V2(x)   ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_MBIST_DONE
  * @brief
  * @{
  */
#define BIT_MASK_WLON_MBIST_DONE_V1    ((u32)0x00000003 << 9)           /*!< R 0x0  MBIST Done of Wlan Partial-on Memory*/
#define BIT_WLON_MBIST_DONE_V1(x)      (((u32)((x) & 0x00000003) << 9))
#define BIT_GET_WLON_MBIST_DONE_V1(x)  ((u32)(((x >> 9) & 0x00000003)))
#define BIT_MASK_WLOFF_MBIST_DONE_V1   ((u32)0x0000001F << 4)           /*!< R 0x0  MBIST Done of Wlan Partial-off Memory*/
#define BIT_WLOFF_MBIST_DONE_V1(x)     (((u32)((x) & 0x0000001F) << 4))
#define BIT_GET_WLOFF_MBIST_DONE_V1(x) ((u32)(((x >> 4) & 0x0000001F)))
#define BIT_MASK_PCIE_MBIST_DONE_V2    ((u32)0x00000003 << 2)           /*!< R 0x0  MBIST Done of PCIE Memory*/
#define BIT_PCIE_MBIST_DONE_V2(x)      (((u32)((x) & 0x00000003) << 2))
#define BIT_GET_PCIE_MBIST_DONE_V2(x)  ((u32)(((x >> 2) & 0x00000003)))
#define BIT_MASK_USB_MBIST_DONE_V2     ((u32)0x00000003 << 0)           /*!< R 0x0  MBIST Done of USB Memory*/
#define BIT_USB_MBIST_DONE_V2(x)       (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_USB_MBIST_DONE_V2(x)   ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_MBIST_NRML_FAIL
  * @brief
  * @{
  */
#define BIT_MASK_WLON_MBIST_NRML_FAIL       ((u32)0x00000003 << 30)           /*!< R 0x0  0x100[29]= 0,  MBIST NRML Fail bit 0~bit1 of WLAN partial-on Memory;  0x100[29]= 1,  0x0*/
#define BIT_WLON_MBIST_NRML_FAIL(x)         (((u32)((x) & 0x00000003) << 30))
#define BIT_GET_WLON_MBIST_NRML_FAIL(x)     ((u32)(((x >> 30) & 0x00000003)))
#define BIT_MASK_WLOFF_MBIST_NRML_FAIL      ((u32)0x00003FFF << 16)           /*!< R 0x0  0x100[29]= 0,  MBIST NRML Fail bit 0~bit13 of WLAN partial-off Memory;  0x100[29]= 1,  0x0*/
#define BIT_WLOFF_MBIST_NRML_FAIL(x)        (((u32)((x) & 0x00003FFF) << 16))
#define BIT_GET_WLOFF_MBIST_NRML_FAIL(x)    ((u32)(((x >> 16) & 0x00003FFF)))
#define BIT_MASK_PCIE_MBIST_NRML_FAIL       ((u32)0x0000001F << 11)           /*!< R 0x0  0x100[29]= 0,  MBIST NRML Fail bit 0~bit4 of PCIE Memory;  0x100[29]= 1,  0x0*/
#define BIT_PCIE_MBIST_NRML_FAIL(x)         (((u32)((x) & 0x0000001F) << 11))
#define BIT_GET_PCIE_MBIST_NRML_FAIL(x)     ((u32)(((x >> 11) & 0x0000001F)))
#define BIT_MASK_USB_MBIST_NRML_FAIL        ((u32)0x0000007F << 4)            /*!< R 0x0  0x100[29]= 0,  MBIST NRML Fail bit 4~bit10 of USB Memory;  0x100[29]= 1,  0x0*/
#define BIT_USB_MBIST_NRML_FAIL(x)          (((u32)((x) & 0x0000007F) << 4))
#define BIT_GET_USB_MBIST_NRML_FAIL(x)      ((u32)(((x >> 4) & 0x0000007F)))
#define BIT_MASK_USB_WLON_MBIST_NRML_FAIL   ((u32)0x0000000F << 0)            /*!< R 0x0  0x100[29]= 0,  MBIST NRML Fail bit 0~bit3 of USB Memory;  0x100[29]= 1,  MBIST NRML Fail bit 2~bit5 of Wlan partial-on Memory*/
#define BIT_USB_WLON_MBIST_NRML_FAIL(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_USB_WLON_MBIST_NRML_FAIL(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AES_DECRPT_DATA
  * @brief
  * @{
  */
#define BIT_MASK_IPS_CFG_ADDR   ((u32)0x000000FF << 0)           /*!< R/W 0x0  Configuration Address of IPS Controller*/
#define BIT_IPS_CFG_ADDR(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_IPS_CFG_ADDR(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AES_DECRPT_CFG
  * @brief
  * @{
  */
#define BIT_MASK_IPS_CFG_DATA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Configuration Write/Read Data of IPS Controller*/
#define BIT_IPS_CFG_DATA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_IPS_CFG_DATA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIST_READ_BIST_RPT_V1
  * @brief
  * @{
  */
#define BIT_MASK_MBIST_READ_BIST_RPT   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  MBIST read bist report*/
#define BIT_MBIST_READ_BIST_RPT(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIST_READ_BIST_RPT(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MACCLKFRQ
  * @brief
  * @{
  */
#define BIT_MASK_MACCLK_FREQ_LOW32   ((u32)0xFFFFFFFF << 0)           /*!< R/W 32'd40000000  low 32 bit of  frequency value of MAC clk, used for 32k circuit, the total bit of frequency value is 42*/
#define BIT_MACCLK_FREQ_LOW32(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MACCLK_FREQ_LOW32(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TMETER
  * @brief
  * @{
  */
#define BIT_MASK_NCO_OUTCLK_FREQ      ((u32)0x000FFFFF << 12)           /*!< R/W 0x0  set to 'd32000 to generate internal 32K clock set to 'd32768 to generate interal 32.768K clock*/
#define BIT_NCO_OUTCLK_FREQ(x)        (((u32)((x) & 0x000FFFFF) << 12))
#define BIT_GET_NCO_OUTCLK_FREQ(x)    ((u32)(((x >> 12) & 0x000FFFFF)))
#define BIT_MASK_MACCLK_FREQ_HIGH10   ((u32)0x000003FF << 0)            /*!< R/W 0x0  high 10 bit of  frequency value of MAC clk, used for 32k circuit,the total bit of frequency value is 42*/
#define BIT_MACCLK_FREQ_HIGH10(x)     (((u32)((x) & 0x000003FF) << 0))
#define BIT_GET_MACCLK_FREQ_HIGH10(x) ((u32)(((x >> 0) & 0x000003FF)))
/** @} */

/** @defgroup REG_OSC_32K_CTRL
  * @brief
  * @{
  */
#define BIT_32K_CLK_OUT_RDY           ((u32)0x00000001 << 12)          /*!< R 0x0  indicate the output clk of 32k calibration circuit is ready*/
#define BIT_MASK_MONITOR_CYCLE_LOG2   ((u32)0x0000000F << 8)           /*!< R/W 0x9  result of log2(monitor cycle), monitor cycle is the computing cycle for 32k calibration circuit*/
#define BIT_MONITOR_CYCLE_LOG2(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MONITOR_CYCLE_LOG2(x) ((u32)(((x >> 8) & 0x0000000F)))
/** @} */

/** @defgroup REG_32K_CAL_REG0
  * @brief
  * @{
  */
#define BIT_MASK_FREQVALUE_UNREGCLK   ((u32)0x00FFFFFF << 8)           /*!< R   the calculated frequency value of unregulated clk of  32k calibration circuit*/
#define BIT_FREQVALUE_UNREGCLK(x)     (((u32)((x) & 0x00FFFFFF) << 8))
#define BIT_GET_FREQVALUE_UNREGCLK(x) ((u32)(((x >> 8) & 0x00FFFFFF)))
#define BIT_CAL32K_DBGMOD             ((u32)0x00000001 << 7)           /*!< R/W 0x0  Selection for debug output*/
#define BIT_MASK_NCO_THRS             ((u32)0x0000007F << 0)           /*!< R/W 0x2  threshold value of starting recalculating the frequency of unregulated clk of  32k calibration circuit*/
#define BIT_NCO_THRS(x)               (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_NCO_THRS(x)           ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_C2HEVT
  * @brief
  * @{
  */
#define BIT_MASK_C2HEVT_MSG_V1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_C2HEVT_MSG_V1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_C2HEVT_MSG_V1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_C2HEVT_1
  * @brief
  * @{
  */
#define BIT_MASK_C2HEVT_MSG_1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_C2HEVT_MSG_1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_C2HEVT_MSG_1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_C2HEVT_2
  * @brief
  * @{
  */
#define BIT_MASK_C2HEVT_MSG_2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_C2HEVT_MSG_2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_C2HEVT_MSG_2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_C2HEVT_3
  * @brief
  * @{
  */
#define BIT_MASK_C2HEVT_MSG_3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_C2HEVT_MSG_3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_C2HEVT_MSG_3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MISC_CTRL_V1
  * @brief
  * @{
  */
#define BIT_MASK_PHYWR_SETUP_CNT      ((u32)0x0000000F << 28)           /*!< R/W 0x5  Write PHYREG Setup time,  in unit of MAC clock*/
#define BIT_PHYWR_SETUP_CNT(x)        (((u32)((x) & 0x0000000F) << 28))
#define BIT_GET_PHYWR_SETUP_CNT(x)    ((u32)(((x >> 28) & 0x0000000F)))
#define BIT_MASK_PHYWR_HOLD_CNT       ((u32)0x0000000F << 24)           /*!< R/W 0x1  Write PHYREG Hold time,  in unit of MAC clock*/
#define BIT_PHYWR_HOLD_CNT(x)         (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_PHYWR_HOLD_CNT(x)     ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_TXBUF_WKCAM_OFFSET   ((u32)0x00001FFF << 8)            /*!< R/W 0x0  Wakeup CAM offset in TXPKTBUFF,   unit:  8 bytes*/
#define BIT_TXBUF_WKCAM_OFFSET(x)     (((u32)((x) & 0x00001FFF) << 8))
#define BIT_GET_TXBUF_WKCAM_OFFSET(x) ((u32)(((x >> 8) & 0x00001FFF)))
#define BIT_MASK_PHYRD_WAIT_CNT       ((u32)0x0000000F << 4)            /*!< R/W 0x4  Stable time for  PHYREG read data,  in unit of MAC clock*/
#define BIT_PHYRD_WAIT_CNT(x)         (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_PHYRD_WAIT_CNT(x)     ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_H2CQ_PRI             ((u32)0x00000003 << 0)            /*!< R/W 0x0  H2C queue priority for PCIE TXDMA 0x0:  Beacon >  Multicast >  Management > H2C > 4AC 0x1:  Beacon >  Multicast > H2C > Management > 4AC 0x2:  Beacon >  H2C > Multicast >  Management > 4AC 0x3:  H2C > Beacon >  Multicast > Management > 4AC*/
#define BIT_H2CQ_PRI(x)               (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_H2CQ_PRI(x)           ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_SW_DEFINED_PAGE1
  * @brief
  * @{
  */
#define BIT_MASK_SW_DEFINED_PAGE1_V1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_SW_DEFINED_PAGE1_V1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_SW_DEFINED_PAGE1_V1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_SW_DEFINED_PAGE2
  * @brief
  * @{
  */
#define BIT_MASK_SW_DEFINED_PAGE2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_SW_DEFINED_PAGE2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_SW_DEFINED_PAGE2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MCUTST_I
  * @brief
  * @{
  */
#define BIT_MASK_MCUDMSG_I   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_MCUDMSG_I(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MCUDMSG_I(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MCUTST_II
  * @brief
  * @{
  */
#define BIT_MASK_MCUDMSG_II   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_MCUDMSG_II(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MCUDMSG_II(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FMETHR
  * @brief
  * @{
  */
#define BIT_FMSG_INT      ((u32)0x00000001 << 31)          /*!< R/W 0x0  Toggle this bit will generate C2H interrupt to Host*/
#define BIT_MASK_FW_MSG   ((u32)0x7FFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_FW_MSG(x)     (((u32)((x) & 0x7FFFFFFF) << 0))
#define BIT_GET_FW_MSG(x) ((u32)(((x >> 0) & 0x7FFFFFFF)))
/** @} */

/** @defgroup REG_HMETFR
  * @brief
  * @{
  */
#define BIT_MASK_HRCV_MSG   ((u32)0x000000FF << 24)           /*!< R/W 0x0  Host Recover Message, Host Write This Byte will generate interrupt to 8051 (0x0134h[5])*/
#define BIT_HRCV_MSG(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_HRCV_MSG(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_INT_BOX3        ((u32)0x00000001 << 3)            /*!< R/W 0x0  MSG_BOX_3 Valid. Enable when the Entry is write, Clear when the Entry is Read by 8051.*/
#define BIT_INT_BOX2        ((u32)0x00000001 << 2)            /*!< R/W 0x0  MSG_BOX_2 Valid. Enable when the Entry is write, Clear when the Entry is Read by 8051.*/
#define BIT_INT_BOX1        ((u32)0x00000001 << 1)            /*!< R/W 0x0  MSG_BOX_1 Valid. Enable when the Entry is write, Clear when the Entry is Read by 8051.*/
#define BIT_INT_BOX0        ((u32)0x00000001 << 0)            /*!< R/W 0x0  MSG_BOX_0 Valid. Enable when the Entry is write, Clear when the Entry is Read by 8051.*/
/** @} */

/** @defgroup REG_HMEBOX0
  * @brief
  * @{
  */
#define BIT_MASK_HOST_MSG_0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_HOST_MSG_0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HOST_MSG_0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HMEBOX1
  * @brief
  * @{
  */
#define BIT_MASK_HOST_MSG_1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_HOST_MSG_1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HOST_MSG_1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HMEBOX2
  * @brief
  * @{
  */
#define BIT_MASK_HOST_MSG_2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_HOST_MSG_2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HOST_MSG_2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HMEBOX3
  * @brief
  * @{
  */
#define BIT_MASK_HOST_MSG_3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_HOST_MSG_3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HOST_MSG_3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_LLT_IND_ACCESS
  * @brief
  * @{
  */
#define BIT_MASK_LLTE_RWM       ((u32)0x00000003 << 30)           /*!< R/W 0x0  00 : No Active LLT access cycle 01 : LLT Entry Write Access (auto return to 00 when access finished) 1X : LLT Entry Read Access (auto return to 00 when access finished)*/
#define BIT_LLTE_RWM(x)         (((u32)((x) & 0x00000003) << 30))
#define BIT_GET_LLTE_RWM(x)     ((u32)(((x >> 30) & 0x00000003)))
#define BIT_MASK_LLTINI_PDATA   ((u32)0x000000FF << 16)           /*!< R/W 0x0  LLT Entry Write/Read DATA for MCU (Read Data will be valid for next access, when Read Access indicator clear to "0")*/
#define BIT_LLTINI_PDATA(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_LLTINI_PDATA(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_LLTINI_ADDR    ((u32)0x000000FF << 8)            /*!< R/W 0x0  LLT Entry Access Offset*/
#define BIT_LLTINI_ADDR(x)      (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_LLTINI_ADDR(x)  ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_LLTINI_HDATA   ((u32)0x000000FF << 0)            /*!< R/W 0x0  LLT Entry Write/Read DATA for HCI (Read Data will be valid for next access, when Read Access indicator clear to "0")*/
#define BIT_LLTINI_HDATA(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_LLTINI_HDATA(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_GENTST
  * @brief
  * @{
  */
#define BIT_MASK_GENTST   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Dummy register for MAC I/O REG Read/Write Access TEST*/
#define BIT_GENTST(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_GENTST(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BB_ACCESS_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_BB_WRITE_READ    ((u32)0x00000003 << 30)           /*!< R/W 0x0  00 : No Active Baseband cycle 01 : Baseband Write Access (auto return to 00 when access finished) 1X : Baseband Read Access (auto return to 00 when access finished)*/
#define BIT_BB_WRITE_READ(x)      (((u32)((x) & 0x00000003) << 30))
#define BIT_GET_BB_WRITE_READ(x)  ((u32)(((x >> 30) & 0x00000003)))
#define BIT_MASK_BB_WRITE_EN_V1   ((u32)0x0000000F << 16)           /*!< R/W 0x0  Byte Write Enable*/
#define BIT_BB_WRITE_EN_V1(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BB_WRITE_EN_V1(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BB_ADDR_V1       ((u32)0x00000FFF << 2)            /*!< R/W 0x0  Baseband Access Write/Read Address (in DW unit)*/
#define BIT_BB_ADDR_V1(x)         (((u32)((x) & 0x00000FFF) << 2))
#define BIT_GET_BB_ADDR_V1(x)     ((u32)(((x >> 2) & 0x00000FFF)))
#define BIT_BB_ERRACC             ((u32)0x00000001 << 0)            /*!< R/W 0x0  Duplicate Access when previous cycle pending (write one clear)*/
/** @} */

/** @defgroup REG_BB_ACCESS_DATA
  * @brief
  * @{
  */
#define BIT_MASK_BB_DATA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Baseband Access Write/Read Data (in DW unit)*/
#define BIT_BB_DATA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BB_DATA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HMEBOX_E0
  * @brief
  * @{
  */
#define BIT_MASK_HMEBOX_E0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_HMEBOX_E0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HMEBOX_E0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HMEBOX_E1
  * @brief
  * @{
  */
#define BIT_MASK_HMEBOX_E1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_HMEBOX_E1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HMEBOX_E1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HMEBOX_E2
  * @brief
  * @{
  */
#define BIT_MASK_HMEBOX_E2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_HMEBOX_E2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HMEBOX_E2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HMEBOX_E3
  * @brief
  * @{
  */
#define BIT_MASK_HMEBOX_E3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  User Defined Message*/
#define BIT_HMEBOX_E3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HMEBOX_E3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/*==========REG_PAGE1 Register Address Definition==========*/
#define REG_CR                              0x100
#define REG_PG_SIZE                         0x104
#define REG_TSF_CLK_STATE                   0x108
#define REG_TXDMA_PQ_MAP                    0x10C
#define REG_TRXFF_BNDY                      0x114
#define REG_PTA_I2C_MBOX                    0x118
#define REG_RXFF_PTR                        0x11C
#define REG_FEIMR                           0x120
#define REG_FEISR                           0x124
#define REG_CPWM                            0x12C
#define REG_FWIMR                           0x130
#define REG_FWISR                           0x134
#define REG_FTIMR                           0x138
#define REG_FTISR                           0x13C
#define REG_PKTBUF_DBG_CTRL                 0x140
#define REG_PKTBUF_DBG_DATA_L               0x144
#define REG_PKTBUF_DBG_DATA_H               0x148
#define REG_CPWM2                           0x14C
#define REG_TC0_CTRL                        0x150
#define REG_TC1_CTRL                        0x154
#define REG_TC2_CTRL                        0x158
#define REG_TC3_CTRL                        0x15C
#define REG_TC4_CTRL                        0x160
#define REG_TCUNIT_BASE                     0x164
#define REG_TC5_CTRL                        0x168
#define REG_TC6_CTRL                        0x16C
#define REG_MBIST_DRF_FAIL                  0x170
#define REG_MBIST_START_PAUSE               0x174
#define REG_MBIST_DONE                      0x178
#define REG_MBIST_NRML_FAIL                 0x17C
#define REG_AES_DECRPT_DATA                 0x180
#define REG_AES_DECRPT_CFG                  0x184
#define REG_MBIST_READ_BIST_RPT_V1          0x188
#define REG_MACCLKFRQ                       0x18C
#define REG_TMETER                          0x190
#define REG_OSC_32K_CTRL                    0x194
#define REG_32K_CAL_REG0                    0x198
#define REG_C2HEVT                          0x1A0
#define REG_C2HEVT_1                        0x1A4
#define REG_C2HEVT_2                        0x1A8
#define REG_C2HEVT_3                        0x1AC
#define REG_MISC_CTRL_V1                    0x1B0
#define REG_SW_DEFINED_PAGE1                0x1B8
#define REG_SW_DEFINED_PAGE2                0x1BC
#define REG_MCUTST_I                        0x1C0
#define REG_MCUTST_II                       0x1C4
#define REG_FMETHR                          0x1C8
#define REG_HMETFR                          0x1CC
#define REG_HMEBOX0                         0x1D0
#define REG_HMEBOX1                         0x1D4
#define REG_HMEBOX2                         0x1D8
#define REG_HMEBOX3                         0x1DC
#define REG_LLT_IND_ACCESS                  0x1E0
#define REG_GENTST                          0x1E4
#define REG_BB_ACCESS_CTRL                  0x1E8
#define REG_BB_ACCESS_DATA                  0x1EC
#define REG_HMEBOX_E0                       0x1F0
#define REG_HMEBOX_E1                       0x1F4
#define REG_HMEBOX_E2                       0x1F8
#define REG_HMEBOX_E3                       0x1FC

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