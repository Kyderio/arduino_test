#ifndef _project_name_REG_PAGE4_H_
#define _project_name_REG_PAGE4_H_





/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE4_Register_Definitions REG_PAGE4 Register Definitions
  * @{
  */

/** @defgroup REG_QUEUELIST_INFO0
  * @brief
  * @{
  */
#define BIT_MASK_TAIL_PKT_V1   ((u32)0x000000FF << 16)           /*!< RO 0x0  The head page of the last packet of Queue[Index] (Index set in 0x414[4:0])*/
#define BIT_TAIL_PKT_V1(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_TAIL_PKT_V1(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_PKT_NUM_V1    ((u32)0x000000FF << 8)            /*!< RO 0x0  packet number of queue[Index](Index set in 0x414[4:0])*/
#define BIT_PKT_NUM_V1(x)      (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_PKT_NUM_V1(x)  ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_HEAD_PKT_V1   ((u32)0x000000FF << 0)            /*!< RO 0xFF  The head page of the first packet of Queue[Index] (Index set in 0x414[4:0])*/
#define BIT_HEAD_PKT_V1(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_HEAD_PKT_V1(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_QUEUELIST_INFO1
  * @brief
  * @{
  */
#define BIT_MASK_QUEUEAC_V1      ((u32)0x00000003 << 8)           /*!< RO 0x0  AC type of Queue [index] (Index set in 0x414[4:0]).*/
#define BIT_QUEUEAC_V1(x)        (((u32)((x) & 0x00000003) << 8))
#define BIT_GET_QUEUEAC_V1(x)    ((u32)(((x >> 8) & 0x00000003)))
#define BIT_MASK_QUEUEMACID_V1   ((u32)0x0000007F << 0)           /*!< RO 0x0  MacID of head pkt of Queue [index] (Index set in 0x414[4:0])*/
#define BIT_QUEUEMACID_V1(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_QUEUEMACID_V1(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_QUEUELIST_INFO2_V1
  * @brief
  * @{
  */
#define BIT_MASK_ACQ_STOP      ((u32)0x0000FFFF << 5)           /*!< RO 0x0  When this bit is raised, AC queue 15~0 is stop. Report by MAC.*/
#define BIT_ACQ_STOP(x)        (((u32)((x) & 0x0000FFFF) << 5))
#define BIT_GET_ACQ_STOP(x)    ((u32)(((x >> 5) & 0x0000FFFF)))
#define BIT_MASK_QINFO_INDEX   ((u32)0x0000001F << 0)           /*!< R/W 0x0  Set index then the Queue information show at REG 0x400 ~ REG 0x407  N = 0~0xF If Set N : Show ACQN information If Set 0x10 : Show MGQ information If Set 0x11 : Show HIQ information If Set 0x12 : Show BCNQ information If Set 0x13 : Show CMDQ information*/
#define BIT_QINFO_INDEX(x)     (((u32)((x) & 0x0000001F) << 0))
#define BIT_GET_QINFO_INDEX(x) ((u32)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_TXPKT_EMPTY_V1
  * @brief
  * @{
  */
#define BIT_BCNQ2_EMPTY      ((u32)0x00000001 << 31) /*!< RO 0x1  When this bit is raised, beacon queue for port2 is empty. Report by MAC.*/
#define BIT_BCNQ1_EMPTY      ((u32)0x00000001 << 30) /*!< RO 0x1  When this bit is raised, beacon queue for port1 is empty. Report by MAC.*/
#define BIT_BCNQ0_EMPTY      ((u32)0x00000001 << 29) /*!< RO 0x1  When this bit is raised, beacon queue for port0 is empty. Report by MAC.*/
#define BIT_EVTQ_EMPTY       ((u32)0x00000001 << 28) /*!< RO 0x1  When this bit is raised, event queue is empty. Report by MAC.*/
#define BIT_BCNQ_EMPTY_V2    ((u32)0x00000001 << 27) /*!< RO 0x1  When this bit is raised, beacon queue is empty. Report by MAC.*/
#define BIT_HQQ_EMPTY_V2     ((u32)0x00000001 << 26) /*!< RO 0x1  When this bit is raised, High queue is empty. Report by MAC.*/
#define BIT_MQQ_EMPTY_V3     ((u32)0x00000001 << 25) /*!< RO 0x1  When this bit is raised, MGQ queue is empty. Report by MAC.*/
#define BIT_MGQ_CPU_EMPTY_V2 ((u32)0x00000001 << 24) /*!< RO 0x1  When this bit is raised, MGQ queue poll by cpu is empty. Report by MAC.*/
#define BIT_AC7Q_EMPTY       ((u32)0x00000001 << 23)  /*!< RO 0x1  When this bit is raised, AC7 queue is empty. Report by MAC.*/
#define BIT_AC6Q_EMPTY       ((u32)0x00000001 << 22)  /*!< RO 0x1  When this bit is raised, AC6 queue is empty. Report by MAC.*/
#define BIT_AC5Q_EMPTY       ((u32)0x00000001 << 21)  /*!< RO 0x1  When this bit is raised, AC5 queue is empty. Report by MAC.*/
#define BIT_AC4Q_EMPTY       ((u32)0x00000001 << 20)  /*!< RO 0x1  When this bit is raised, AC4 queue is empty. Report by MAC.*/
#define BIT_AC3Q_EMPTY       ((u32)0x00000001 << 19)  /*!< RO 0x1  When this bit is raised, AC3 queue is empty. Report by MAC.*/
#define BIT_AC2Q_EMPTY       ((u32)0x00000001 << 18)  /*!< RO 0x1  When this bit is raised, AC2 queue is empty. Report by MAC.*/
#define BIT_AC1Q_EMPTY       ((u32)0x00000001 << 17)  /*!< RO 0x1  When this bit is raised, AC1 queue is empty. Report by MAC.*/
#define BIT_AC0Q_EMPTY       ((u32)0x00000001 << 16)  /*!< RO 0x1  When this bit is raised, AC0 queue is empty. Report by MAC.*/
#define BIT_MASK_BCNQ_PKT_NUM   ((u32)0x000000FF << 8)           /*!< RO 0x0  the number of packet in bcnq*/
#define BIT_BCNQ_PKT_NUM(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_BCNQ_PKT_NUM(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_BCNQ_HEAD_PG   ((u32)0x000000FF << 0)           /*!< RO 0x0  The head page of the first packet of Bcnq*/
#define BIT_BCNQ_HEAD_PG(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_BCNQ_HEAD_PG(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_CPU_MGQ_INFO
  * @brief
  * @{
  */
#define BIT_BCN_POLL2       ((u32)0x00000001 << 31) /*!< W   Polling BCN Queue2 Packet*/
#define BIT_BCN_POLL1       ((u32)0x00000001 << 30) /*!< W   Polling BCN Queue1 Packet*/
#define BIT_CPUMGT_POLL_SET ((u32)0x00000001 << 29) /*!< W   Polling to set CPU MGT Queue packet*/
#define BIT_BCN_POLL        ((u32)0x00000001 << 28) /*!< W   Polling BCN Queue Packet*/
#define BIT_CPUMGT_POLL_CLR ((u32)0x00000001 << 27) /*!< W   Polling to clear CPU MGT Queue packet*/
#define BIT_EVTQ_VALID      ((u32)0x00000001 << 26) /*!< R/W   Driver write this bit to inform HW eventq packet is valid. When evntq tx timeout or tx ok, this bit will be clear by HW*/
#define BIT_CPUMGQ_FW_NUM   ((u32)0x00000001 << 8)  /*!< RO 0x0  The total cpu mgq fw number in TxPktbuffer*/
/** @} */

/** @defgroup REG_FWHW_TXQ_CTRL
  * @brief
  * @{
  */
#define BIT_RTS_LIMIT_IN_OFDM   ((u32)0x00000001 << 23)          /*!< R/W 0x0  Rts rate will not down to cck rate*/
#define BIT_EN_BCNQ_DL          ((u32)0x00000001 << 22)          /*!< R/W 0x1  1: ptcl consider there is bcn pkt in TXBUF when bcn pkt first be transferd in; 0: mask bcn pkt num in bcn queue*/
#define BIT_EN_RD_RESP_NAV_BK   ((u32)0x00000001 << 21)          /*!< R/W 0x1  Control the RD responder NAV criteria for TX. When this bit is clear, RD responder may aggregates only according to the number of MPDUs existing in the TXPKTBUF, the limit of aggregation size and number, and also the break time. When this bit is set, RD responder will be under the RX NAV criteria for RD response sequence. No excess NAV is allowed*/
#define BIT_EN_WR_FREE_TAIL     ((u32)0x00000001 << 20)          /*!< R/W 0x1  1: Drive write Bcnq_boundary, Hw will set free_tail in Boundary-1 0: no update*/
#define BIT_TXRPT_DIS           ((u32)0x00000001 << 19)          /*!< R/W 0x0  when this bit is enabled, HW will not generate txrpt for driver's fixed rate packets*/
#define BIT_EN_RTY_BK_COND      ((u32)0x00000001 << 16)          /*!< R/W 0x0  AMPDU aggregation mode with retry MPDUs and new MPDUs. When this bit is enabled, if new MPDU's data rate is not the same as retry MPDUs' fallback data rate, the aggregation will be broken.*/
#define BIT_MASK_EN_QUEUE_RPT   ((u32)0x000000FF << 8)           /*!< R/W 0x3F  8723A/8812 1: HW will report tx_status  0: no report BIT0: BK Queue BIT1: BE Queue BIT2: VI Queue BIT3: VO Queue BIT4: MGT Queue BIT5: HI Queue BIT6: BCN Queue BIT7: CPU_MGT Queue*/
#define BIT_EN_QUEUE_RPT(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_EN_QUEUE_RPT(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_EN_RTY_BK           ((u32)0x00000001 << 7)           /*!< R/W 0x1  AMPDU aggregation mode with retry MPDUs and new MPDUs. When this bit is clear, an AMPDU aggregates retried MPDU and new MPDU. All the aggregation criteria is still the same with normal AMPDU operation.*/
#define BIT_EN_USE_INI_RAT      ((u32)0x00000001 << 6)           /*!< R/W 0x0  0: If Txdesc's USE RATE = 0 and this field is equal to 0, the datarate of TXRPT SRAM is used as tx pkt's datarate. (ECO flow) 1: TXInfo's datarate is used as tx pkt's datarate.*/
#define BIT_EN_RTS_NAV_BK       ((u32)0x00000001 << 5)           /*!< R/W 0x0  Control The RTS NAV criteria for TX. When this bit is clear, TX may aggregates only according to the number of MPDUs existing in the TXPKTBUF, the limit of aggregation size and number, and also the break time.  When this bit is set, TX will be under the RTS NAV criteria. No excess RTS NAV is allowed.*/
#define BIT_DIS_SSN_CHECK       ((u32)0x00000001 << 4)           /*!< R/W 0x0  Disable checker the SSN rule when generating AMPDU TX cmd.*/
#define BIT_MACID_MATCH_RTS     ((u32)0x00000001 << 3)           /*!< R/W 0x0  Enable the packet that follow the RTS have same MACID*/
#define BIT_EN_EVTQ_RPT         ((u32)0x00000001 << 2)           /*!< R/W 0x1  1: HW will report tx_status  0: no report*/
#define BIT_HWSEQ_EVTQ_EN       ((u32)0x00000001 << 1)           /*!< R/W 0x0  When this bit enable and EN_HWSEQ of TXDESC, MAC will overwrite MACHDR SEQ according to TXDESC QSEL*/
/** @} */

/** @defgroup REG_HWSEQ_CTRL
  * @brief
  * @{
  */
#define BIT_HWSEQ_CPUM_EN ((u8)0x00000001 << 7) /*!< R/W 0x0  When this bit enable and EN_HWSEQ of TXDESC, MAC will overwrite MACHDR SEQ according to TXDESC QSEL*/
#define BIT_HWSEQ_BCN_EN  ((u8)0x00000001 << 6) /*!< R/W 0x0  When this bit enable, MAC will overwrite MACHDR SEQ according to TXDESC QSEL*/
#define BIT_HWSEQ_HI_EN   ((u8)0x00000001 << 5) /*!< R/W 0x0  When this bit enable and EN_HWSEQ of TXDESC, MAC will overwrite MACHDR SEQ according to TXDESC QSEL*/
#define BIT_HWSEQ_MGT_EN  ((u8)0x00000001 << 4) /*!< R/W 0x0  When this bit enable and EN_HWSEQ of TXDESC, MAC will overwrite MACHDR SEQ according to TXDESC QSEL*/
#define BIT_HWSEQ_BK_EN   ((u8)0x00000001 << 3) /*!< R/W 0x0  When this bit enable and EN_HWSEQ of TXDESC, MAC will overwrite MACHDR SEQ according to TXDESC QSEL*/
#define BIT_HWSEQ_BE_EN   ((u8)0x00000001 << 2) /*!< R/W 0x0  When this bit enable and EN_HWSEQ of TXDESC, MAC will overwrite MACHDR SEQ according to TXDESC QSEL*/
#define BIT_HWSEQ_VI_EN   ((u8)0x00000001 << 1) /*!< R/W 0x0  When this bit enable and EN_HWSEQ of TXDESC, MAC will overwrite MACHDR SEQ according to TXDESC QSEL*/
#define BIT_HWSEQ_VO_EN   ((u8)0x00000001 << 0) /*!< R/W 0x0  When this bit enable and EN_HWSEQ of TXDESC, MAC will overwrite MACHDR SEQ according to TXDESC QSEL*/
/** @} */

/** @defgroup REG_BNDY_LIFETIME_TAIL
  * @brief
  * @{
  */
#define BIT_MASK_MGQ_PGBNDY_V2   ((u16)0x000000FF << 8)           /*!< R/W 0xF6  TXDMA will pull CPU MGQ Pkt in this address.*/
#define BIT_MGQ_PGBNDY_V2(x)     (((u16)((x) & 0x000000FF) << 8))
#define BIT_GET_MGQ_PGBNDY_V2(x) ((u16)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_BCNQ_PGBNDY     ((u16)0x000000FF << 0)           /*!< R/W 0xF6  TXDMA will pull BCNQ Pkt in this address.*/
#define BIT_BCNQ_PGBNDY(x)       (((u16)((x) & 0x000000FF) << 0))
#define BIT_GET_BCNQ_PGBNDY(x)   ((u16)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_LIFETIME_EN
  * @brief
  * @{
  */
#define BIT_BT_INT_CPU     ((u8)0x00000001 << 7) /*!< R/W 0x0  BT Interrupt to MCU 1: Enable 0: Disable*/
#define BIT_BT_INT_PTA     ((u8)0x00000001 << 6) /*!< R/W 0x0  BT Interrupt to PTA Circuit 1: Enable 0: Disable*/
#define BIT_SPERPT_ENTRY   ((u8)0x00000001 << 5) /*!< R/W 0x1  8812 SPERPT Entry Count 1: Entry1 ~ Entry15 0: Entry8 ~ Entry15*/
#define BIT_EN_CTRL_RTYBIT ((u8)0x00000001 << 4) /*!< R/W 0x1  1: Enable HW write retry bit in MAC header. 0: Disable HW write retry bit in MAC header. Restriction : When NAVUSEHDR field of tx descriptor value = 0, the register is invaild.*/
#define BIT_LIFETIME_BK_EN ((u8)0x00000001 << 3) /*!< R/W 0x0  Enable BK queue lifetime function*/
#define BIT_LIFETIME_BE_EN ((u8)0x00000001 << 2) /*!< R/W 0x0  Enable BE queue lifetime function*/
#define BIT_LIFETIME_VI_EN ((u8)0x00000001 << 1) /*!< R/W 0x0  Enable VI queue lifetime function*/
#define BIT_LIFETIME_VO_EN ((u8)0x00000001 << 0) /*!< R/W 0x0  Enable VO queue lifetime function*/
/** @} */

/** @defgroup REG_FW_FREE_TAIL
  * @brief
  * @{
  */
#define BIT_MASK_FW_FREE_TAIL   ((u8)0x000000FF << 0)           /*!< RO 0xF5  Free Tail Page Number*/
#define BIT_FW_FREE_TAIL(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_FW_FREE_TAIL(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RETRY_LIMIT_SIFS
  * @brief
  * @{
  */
#define BIT_MASK_SRL                   ((u32)0x0000003F << 24)           /*!< R/W 0x20  Short Retry Limit*/
#define BIT_SRL(x)                     (((u32)((x) & 0x0000003F) << 24))
#define BIT_GET_SRL(x)                 ((u32)(((x >> 24) & 0x0000003F)))
#define BIT_MASK_LRL                   ((u32)0x0000003F << 16)           /*!< R/W 0x20  Long Retry Limit*/
#define BIT_LRL(x)                     (((u32)((x) & 0x0000003F) << 16))
#define BIT_GET_LRL(x)                 ((u32)(((x >> 16) & 0x0000003F)))
#define BIT_MASK_SPEC_SIFS_OFDM_PTCL   ((u32)0x000000FF << 8)            /*!< R/W 0x16  The spec SIFS value for NAV(duration) calculation (Protocol circuit calcuate data packet NAV of TxPktBuf)*/
#define BIT_SPEC_SIFS_OFDM_PTCL(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_SPEC_SIFS_OFDM_PTCL(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_SPEC_SIFS_CCK_PTCL    ((u32)0x000000FF << 0)            /*!< R/W 0x16  The spec SIFS value for  NAV(duration)  calculation (Protocol circuit calcuate data packet NAV of TxPktBuf)*/
#define BIT_SPEC_SIFS_CCK_PTCL(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_SPEC_SIFS_CCK_PTCL(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TXBF_CTRL
  * @brief
  * @{
  */
#define BIT_ENABLE_NDPA       ((u32)0x00000001 << 31)           /*!< R/W 0x0  Set '1' for MAC to enable sending NDPA or NDP Announcement MPDU*/
#define BIT_NDPA_PARA         ((u32)0x00000001 << 30)           /*!< R/W 0x0  1: NDPA rate and BW use reg0x45f settings 0: NDPA rate and BW use NDP settings in Tx descriptor*/
#define BIT_PROP_TXBF         ((u32)0x00000001 << 29)           /*!< R/W 0x0  1: enable proprietary beamforming; 0: disable proprietary beamforming*/
#define BIT_EN_NDPA_INT       ((u32)0x00000001 << 28)           /*!< R/W 0x0  1: enable ndpa interrupt; 0: disable ndpa interrupt*/
#define BIT_TXBF1_80M         ((u32)0x00000001 << 27)           /*!< R/W 0x0  TxBF status of beamformee1 xBW=80M*/
#define BIT_TXBF1_40M         ((u32)0x00000001 << 26)           /*!< R/W 0x0  TxBF status of beamformee1 xBW=40M*/
#define BIT_TXBF1_20M         ((u32)0x00000001 << 25)           /*!< R/W 0x0  TxBF status of beamformee1 xBW=20M*/
#define BIT_MASK_TXBF1_AID    ((u32)0x000001FF << 16)           /*!< R/W 0x0  P_AID[8:0] of the associated beamformee1*/
#define BIT_TXBF1_AID(x)      (((u32)((x) & 0x000001FF) << 16))
#define BIT_GET_TXBF1_AID(x)  ((u32)(((x >> 16) & 0x000001FF)))
#define BIT_DIS_NDP_BFEN      ((u32)0x00000001 << 15)           /*!< R/W 0x1  option to disable beamforming for ndp/ndpa packet*/
#define BIT_TXBCN_NOBLOCK_NDP ((u32)0x00000001 << 14)           /*!< R/W 0x1  beacon packet will not block NDP packet*/
#define BIT_TXBF0_80M         ((u32)0x00000001 << 11)           /*!< R/W 0x0  TxBF status of beamformee0 xBW=80M*/
#define BIT_TXBF0_40M         ((u32)0x00000001 << 10)           /*!< R/W 0x0  TxBF status of beamformee0 xBW=40M*/
#define BIT_TXBF0_20M         ((u32)0x00000001 << 9)            /*!< R/W 0x0  TxBF status of beamformee0 xBW=20M*/
#define BIT_MASK_TXBF0_AID    ((u32)0x000001FF << 0)            /*!< R/W 0x0  P_AID[8:0] of the associated beamformee0*/
#define BIT_TXBF0_AID(x)      (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_TXBF0_AID(x)  ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_DARFRC
  * @brief
  * @{
  */
#define BIT_MASK_DARF_RC4_V2   ((u32)0x0000001F << 24)           /*!< R/W 0x4  Data Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR.*/
#define BIT_DARF_RC4_V2(x)     (((u32)((x) & 0x0000001F) << 24))
#define BIT_GET_DARF_RC4_V2(x) ((u32)(((x >> 24) & 0x0000001F)))
#define BIT_MASK_DARF_RC3_V2   ((u32)0x0000001F << 16)           /*!< R/W 0x3  Data Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR.*/
#define BIT_DARF_RC3_V2(x)     (((u32)((x) & 0x0000001F) << 16))
#define BIT_GET_DARF_RC3_V2(x) ((u32)(((x >> 16) & 0x0000001F)))
#define BIT_MASK_DARF_RC2_V2   ((u32)0x0000001F << 8)            /*!< R/W 0x2  Data Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR.*/
#define BIT_DARF_RC2_V2(x)     (((u32)((x) & 0x0000001F) << 8))
#define BIT_GET_DARF_RC2_V2(x) ((u32)(((x >> 8) & 0x0000001F)))
#define BIT_MASK_DARF_RC1_V2   ((u32)0x0000001F << 0)            /*!< R/W 0x1  Data Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR.*/
#define BIT_DARF_RC1_V2(x)     (((u32)((x) & 0x0000001F) << 0))
#define BIT_GET_DARF_RC1_V2(x) ((u32)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_DARFRCH
  * @brief
  * @{
  */
#define BIT_MASK_DARF_RC8_V3   ((u32)0x0000001F << 24)           /*!< R/W 0x8  Data Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR.*/
#define BIT_DARF_RC8_V3(x)     (((u32)((x) & 0x0000001F) << 24))
#define BIT_GET_DARF_RC8_V3(x) ((u32)(((x >> 24) & 0x0000001F)))
#define BIT_MASK_DARF_RC7_V3   ((u32)0x0000001F << 16)           /*!< R/W 0x7  Data Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR.*/
#define BIT_DARF_RC7_V3(x)     (((u32)((x) & 0x0000001F) << 16))
#define BIT_GET_DARF_RC7_V3(x) ((u32)(((x >> 16) & 0x0000001F)))
#define BIT_MASK_DARF_RC6_V3   ((u32)0x0000001F << 8)            /*!< R/W 0x6  Data Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR.*/
#define BIT_DARF_RC6_V3(x)     (((u32)((x) & 0x0000001F) << 8))
#define BIT_GET_DARF_RC6_V3(x) ((u32)(((x >> 8) & 0x0000001F)))
#define BIT_MASK_DARF_RC5_V3   ((u32)0x0000001F << 0)            /*!< R/W 0x5  Data Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR.*/
#define BIT_DARF_RC5_V3(x)     (((u32)((x) & 0x0000001F) << 0))
#define BIT_GET_DARF_RC5_V3(x) ((u32)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_RARFRC
  * @brief
  * @{
  */
#define BIT_MASK_RARF_RC4   ((u32)0x0000001F << 24)           /*!< R/W 0x4  RTS Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR.*/
#define BIT_RARF_RC4(x)     (((u32)((x) & 0x0000001F) << 24))
#define BIT_GET_RARF_RC4(x) ((u32)(((x >> 24) & 0x0000001F)))
#define BIT_MASK_RARF_RC3   ((u32)0x0000001F << 16)           /*!< R/W 0x3  RTS Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR.*/
#define BIT_RARF_RC3(x)     (((u32)((x) & 0x0000001F) << 16))
#define BIT_GET_RARF_RC3(x) ((u32)(((x >> 16) & 0x0000001F)))
#define BIT_MASK_RARF_RC2   ((u32)0x0000001F << 8)            /*!< R/W 0x2  RTS Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR.*/
#define BIT_RARF_RC2(x)     (((u32)((x) & 0x0000001F) << 8))
#define BIT_GET_RARF_RC2(x) ((u32)(((x >> 8) & 0x0000001F)))
#define BIT_MASK_RARF_RC1   ((u32)0x0000001F << 0)            /*!< R/W 0x1  RTS Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR.*/
#define BIT_RARF_RC1(x)     (((u32)((x) & 0x0000001F) << 0))
#define BIT_GET_RARF_RC1(x) ((u32)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_RARFRCH
  * @brief
  * @{
  */
#define BIT_MASK_RARF_RC8_V1   ((u32)0x0000001F << 24)           /*!< R/W 0x8  RTS Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR.*/
#define BIT_RARF_RC8_V1(x)     (((u32)((x) & 0x0000001F) << 24))
#define BIT_GET_RARF_RC8_V1(x) ((u32)(((x >> 24) & 0x0000001F)))
#define BIT_MASK_RARF_RC7_V1   ((u32)0x0000001F << 16)           /*!< R/W 0x7  RTS Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR.*/
#define BIT_RARF_RC7_V1(x)     (((u32)((x) & 0x0000001F) << 16))
#define BIT_GET_RARF_RC7_V1(x) ((u32)(((x >> 16) & 0x0000001F)))
#define BIT_MASK_RARF_RC6_V1   ((u32)0x0000001F << 8)            /*!< R/W 0x6  RTS Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR.*/
#define BIT_RARF_RC6_V1(x)     (((u32)((x) & 0x0000001F) << 8))
#define BIT_GET_RARF_RC6_V1(x) ((u32)(((x >> 8) & 0x0000001F)))
#define BIT_MASK_RARF_RC5_V1   ((u32)0x0000001F << 0)            /*!< R/W 0x5  RTS Auto Rate Fallback Retry Count After the number of retry, HW will fall back the rate to the next enabled MAC in ARFR.*/
#define BIT_RARF_RC5_V1(x)     (((u32)((x) & 0x0000001F) << 0))
#define BIT_GET_RARF_RC5_V1(x) ((u32)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_RRSR
  * @brief
  * @{
  */
#define BIT_MASK_RRSR_RSC      ((u32)0x00000003 << 21)           /*!< R/W 0x3  Response frame sub-channel configuration. Response frames (CTS, ACK, BA) are transmitted in the following condition. 00: Primary 20Mhz BW(0x483[3:0] = 0x8AC[5:2]). 01: Follow Rx packet BW mode. 10: Duplicate mode. 11: Reserved.*/
#define BIT_RRSR_RSC(x)        (((u32)((x) & 0x00000003) << 21))
#define BIT_GET_RRSR_RSC(x)    ((u32)(((x >> 21) & 0x00000003)))
#define BIT_MASK_RRSC_BITMAP   ((u32)0x000FFFFF << 0)            /*!< R/W 0x3  BitMap to indicate the response/protection/expected_response rate to use in this BSS. All management and control response frames should obey the rates set in the bitmap. Each bit is mapped as the following:   Bit[0:3] = {1M, 2M, 5.5M, 11M } Bit[4:11] = {6M, 9M, 12M, 18M, 24M, 36M, 48M, 54M} Bit[12:19] = HT MCS0~MCS7  Response rate must be less than or equal to the rate of the initiating frame. If none of the bits are set, no response is generated by Rtl8712. If both the legacy rates and HT rates are defined as Basic Rates, fill in only the legacy portion of the bitmap. If only HT rates are defined as Basic Rates, fill in both the legacy and HT portion of the bitmap.   Default: 1h.*/
#define BIT_RRSC_BITMAP(x)     (((u32)((x) & 0x000FFFFF) << 0))
#define BIT_GET_RRSC_BITMAP(x) ((u32)(((x >> 0) & 0x000FFFFF)))
/** @} */

/** @defgroup REG_ARFR0
  * @brief
  * @{
  */
#define BIT_MASK_ARFRL0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Proposed compact format in two double-words: Bit[0:3]: CCK rate {1, 2, 5.5, 11} Bit[4:11]: Legacy OFDM {6, 9, 12, 18, 24, 36, 48, 54}     For VHT,  Bit[12:21]: 1SS MCS0~9; Bit[22:31]: 2SS MCS0~9                 Bit[32:41]: 3SS MCS0~9; Bit[42:51]: 4SS MCS0~9      For HT,  Bit[12:19]: MCS0~7; Bit[22:29]: MCS8~15 Bit[32:39]: MCS16~23; Bit[42:49]: MCS24~31   For mixed,  Bit[12:19]: HT MCS0~7, Bit[20:21]: VHT1SS MCS8~9; Bit[22:29]: HT MCS8~15, Bit[30:31]: VHT 2SS MCS8~9; Bit[32:39]: HT MCS16~23, Bit[40:41]: VHT 3SS MCS8~9; Bit[42:49]: HT MCS24~31, Bit[50:51]: VHT 4SS MCS8~9 Bit[52:61]: RSVD Bit[62:63]: VHT/HT selection. 0:HT, 1:VHT, 2:mixed-mode*/
#define BIT_ARFRL0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_ARFRL0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ARFRH0
  * @brief
  * @{
  */
#define BIT_MASK_ARFRH0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  The definition is the same as ARFR0. The content is [63:32] of 0x444h.*/
#define BIT_ARFRH0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_ARFRH0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ARFR1
  * @brief
  * @{
  */
#define BIT_MASK_ARFRL1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Data Auto Rate Fallback Table Register 1, indexed by RATid in TXDESC. The definition is the same as ARFR0.*/
#define BIT_ARFRL1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_ARFRL1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ARFRH1
  * @brief
  * @{
  */
#define BIT_MASK_ARFRH1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  The definition is the same as ARFR0. The content is [63:32] of 0x44Ch.*/
#define BIT_ARFRH1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_ARFRH1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CCK_CHECK
  * @brief
  * @{
  */
#define BIT_CHECK_CCK_EN              ((u8)0x00000001 << 7) /*!< R/W 0x0  If this bit is set, HW check Tx pkt's data rate. When data rate is CCK rate, modify the rate to NON_CCK_RATE.*/
#define BIT_EN_BCN_PKT_REL            ((u8)0x00000001 << 6) /*!< R/W 0x0  If this bit is set, the BCN pkt will be set to non-valid after BCN TX.*/
#define BIT_BCN_PORT_SEL              ((u8)0x00000001 << 5) /*!< R/W 0x0  This bit use to select BCN on port 1 or port 0. This just useful in USB/SDIO interface.*/
#define BIT_MOREDATA_BYPASS           ((u8)0x00000001 << 4) /*!< R/W 0x0  If this bit is set, the moredata bit will controlled by DES, otherwise controlled by PTCL according TXPKTBUF status.*/
#define BIT_EN_CLR_CMD_REL_BCN_PKT    ((u8)0x00000001 << 3) /*!< R/W 0x0  If this bit is set, the BCN pkt will be set to non-valid when scheduler clear TX BCN CMD even non-TX.*/
#define BIT_EN_SET_MOREDATA           ((u8)0x00000001 << 2) /*!< R/W 0x1  1:Under MACID release mode, the moredata field of MAC header will be overwrited by txcmd. 0:Disable*/
#define BIT_R_DIS_CLEAR_MACID_RELEASE ((u8)0x00000001 << 1) /*!< R/W 0x0  1:Disable clear MACID release mode. 0:Enable*/
#define BIT_R_MACID_RELEASE_EN        ((u8)0x00000001 << 0) /*!< R/W 0x1  1:Enable MACID release mode 0:Disable*/
/** @} */

/** @defgroup REG_BCNQ2_HEAD
  * @brief
  * @{
  */
#define BIT_MASK_BCNQ2_HEAD   ((u8)0x000000FF << 0)           /*!< R/W 0xF6  TXDMA will pull BCNQ2 Pkt in this address.*/
#define BIT_BCNQ2_HEAD(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_BCNQ2_HEAD(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AMPDU_MAX_TIME
  * @brief
  * @{
  */
#define BIT_MASK_AMPDU_MAX_TIME   ((u8)0x000000FF << 0)           /*!< R/W 0x64  AMPDU duration limit in the unit of 32us.*/
#define BIT_AMPDU_MAX_TIME(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_AMPDU_MAX_TIME(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BCNQ1_BDNY
  * @brief
  * @{
  */
#define BIT_MASK_BCNQ1_HEAD   ((u8)0x000000FF << 0)           /*!< R/W 0xF6  TXDMA will pull BCNQ 1 Pkt in this address.*/
#define BIT_BCNQ1_HEAD(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_BCNQ1_HEAD(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AMPDU_MAX_LENGTH
  * @brief
  * @{
  */
#define BIT_MASK_AMPDU_MAX_LENGTH   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0xFFFFFFFF  AMPDUlength limit (unit: Bytes)*/
#define BIT_AMPDU_MAX_LENGTH(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_AMPDU_MAX_LENGTH(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_WMAC_LBK_BUF_HD
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_LBK_BUF_HEAD   ((u8)0x000000FF << 0)           /*!< R/W 0xF6  In delay MAC LBK mode, this register indicate the LBK BUF head page. When this buffer size is not enough for LBK packet length, LBK test may fail.  In ARP/NS mode, this register indicate the ARP/NS response packet head page.*/
#define BIT_WMAC_LBK_BUF_HEAD(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_WMAC_LBK_BUF_HEAD(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TX_HANG_CTRL
  * @brief
  * @{
  */
#define BIT_EN_GNT_BT_AWAKE   ((u8)0x00000001 << 3) /*!< R/W 0x0  */
#define BIT_DIS_RELEASE_RETRY ((u8)0x00000001 << 2) /*!< R/W 0x0  when release one packet for a macid, retry should happen on the same ACQ. Set 1 to remove this requirement*/
#define BIT_DIS_OQT_BLOCK     ((u8)0x00000001 << 1) /*!< R/W 0x0  If this bit is set, the OQT will not block by all AC queues occupied by other MACID.*/
#define BIT_SEARCH_QUEUE_EN   ((u8)0x00000001 << 0) /*!< R/W 0x0  Search queue request enable in ptcl idle:0 disable; 1 enable*/
/** @} */

/** @defgroup REG_NDPA_OPT_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_R_NDPA_RATE   ((u8)0x0000003F << 2)           /*!< R/W 0x4  NDPA tx rate setting, from CCK 1M to VHT NSS2 MCS9*/
#define BIT_R_NDPA_RATE(x)     (((u8)((x) & 0x0000003F) << 2))
#define BIT_GET_R_NDPA_RATE(x) ((u8)(((x >> 2) & 0x0000003F)))
#define BIT_MASK_NDPA_BW       ((u8)0x00000003 << 0)           /*!< R/W 0x0  NDPA bandwidth setting  3: 160M 2: 80M 1: 40M 0: 20M*/
#define BIT_NDPA_BW(x)         (((u8)((x) & 0x00000003) << 0))
#define BIT_GET_NDPA_BW(x)     ((u8)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_RD_RESP_PKT_TH
  * @brief
  * @{
  */
#define BIT_MASK_RD_RESP_PKT_TH_V1   ((u8)0x0000003F << 0)           /*!< R/W 0x3  When RD_CTRL responder enables, and the granted AC queue packet number is beyond this threshold, then responder will carry More PPDU =1 and piggyback data frames back.*/
#define BIT_RD_RESP_PKT_TH_V1(x)     (((u8)((x) & 0x0000003F) << 0))
#define BIT_GET_RD_RESP_PKT_TH_V1(x) ((u8)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_CMDQ_INFO
  * @brief
  * @{
  */
#define BIT_MASK_PKT_NUM_CMDQ_V2   ((u32)0x000000FF << 24)           /*!< RO 0x0  The total CMDQ pkt number in TxPktbuffer*/
#define BIT_PKT_NUM_CMDQ_V2(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_PKT_NUM_CMDQ_V2(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_TAIL_PKT_CMDQ     ((u32)0x000000FF << 16)           /*!< RO 0xFF  The head page of the last packet of CMDQ.*/
#define BIT_TAIL_PKT_CMDQ(x)       (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_TAIL_PKT_CMDQ(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_PKT_NUM_CMDQ      ((u32)0x000000FF << 8)            /*!< RO 0x0  The total CMDQ pkt number in TxPktbuffer*/
#define BIT_PKT_NUM_CMDQ(x)        (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_PKT_NUM_CMDQ(x)    ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_HEAD_PKT_CMDQ     ((u32)0x000000FF << 0)            /*!< RO 0xFF  The head page of the first packet of CMDQ.*/
#define BIT_HEAD_PKT_CMDQ(x)       (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_HEAD_PKT_CMDQ(x)   ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TXRPT_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_SPC_READ_PTR    ((u32)0x0000000F << 24)           /*!< R/W 0x0  Special Type TXRPT Read Pointer (ex. CCX / SW-Defined)*/
#define BIT_SPC_READ_PTR(x)      (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_SPC_READ_PTR(x)  ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_SPC_WRITE_PTR   ((u32)0x0000000F << 16)           /*!< RO   Special Type TXRPT Write Pointer (ex. CCX / SW-Defined)*/
#define BIT_SPC_WRITE_PTR(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_SPC_WRITE_PTR(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_AC_READ_PTR     ((u32)0x0000000F << 8)            /*!< R/W 0x0  Normal AC Type TXRPT Read Pointer*/
#define BIT_AC_READ_PTR(x)       (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_AC_READ_PTR(x)   ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_AC_WRITE_PTR    ((u32)0x0000000F << 0)            /*!< RO 0x0  Normal AC Type TXRPT Write Pointer*/
#define BIT_AC_WRITE_PTR(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_AC_WRITE_PTR(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_INIRTS_RATE_SEL
  * @brief
  * @{
  */
#define BIT_LEAG_RTS_BW_DUP ((u8)0x00000001 << 5) /*!< R/W 0x0  If this bit is set, leag rate RTS use Duplicate in 40M BW / 80M BW.*/
/** @} */

/** @defgroup REG_BASIC_CFEND_RATE
  * @brief
  * @{
  */
#define BIT_MASK_BASIC_CFEND_RATE   ((u8)0x0000001F << 0)           /*!< R/W 0x4  The initial rate for basic CFEND frame transmitted as EDCA originator. The response control frame shall be selected by the definition of 802.11n.*/
#define BIT_BASIC_CFEND_RATE(x)     (((u8)((x) & 0x0000001F) << 0))
#define BIT_GET_BASIC_CFEND_RATE(x) ((u8)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_STBC_CFEND_RATE
  * @brief
  * @{
  */
#define BIT_MASK_STBC_CFEND_RATE   ((u8)0x0000001F << 0)           /*!< R/W 0xc  The initial rate for STBC CFEND frame transmitted as EDCA originator. The response control frame shall be selected by the definition of 802.11n.*/
#define BIT_STBC_CFEND_RATE(x)     (((u8)((x) & 0x0000001F) << 0))
#define BIT_GET_STBC_CFEND_RATE(x) ((u8)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_DATA_SC
  * @brief
  * @{
  */
#define BIT_MASK_TXSC_40M   ((u8)0x0000000F << 4)           /*!< R/W 0x0  Value of Data frame Tx sub-carrier mode 40MHz*/
#define BIT_TXSC_40M(x)     (((u8)((x) & 0x0000000F) << 4))
#define BIT_GET_TXSC_40M(x) ((u8)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_TXSC_20M   ((u8)0x0000000F << 0)           /*!< R/W 0x0  Value of Data frame Tx sub-carrier mode 20MHz*/
#define BIT_TXSC_20M(x)     (((u8)((x) & 0x0000000F) << 0))
#define BIT_GET_TXSC_20M(x) ((u8)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_MACID_SLEEP3
  * @brief
  * @{
  */
#define BIT_MASK_MACID103_96_PKTSLEEP   ((u8)0x000000FF << 0)           /*!< R/W 0x0  Macid 103~Macid 96 Packet Sleep (per bit controlled)*/
#define BIT_MACID103_96_PKTSLEEP(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID103_96_PKTSLEEP(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_MACID_SLEEP4
  * @brief
  * @{
  */
#define BIT_MASK_MACID119_104_PKTSLEEP   ((u16)0x0000FFFF << 0)           /*!< R/W 0x0  Macid 119~Macid 104 Packet Sleep (per bit controlled)*/
#define BIT_MACID119_104_PKTSLEEP(x)     (((u16)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MACID119_104_PKTSLEEP(x) ((u16)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MACID_SLEEP5
  * @brief
  * @{
  */
#define BIT_MASK_MACID127_120_PKTSLEEP   ((u8)0x000000FF << 0)           /*!< R/W 0x0  Macid 127~Macid 120 Packet Sleep (per bit controlled)*/
#define BIT_MACID127_120_PKTSLEEP(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID127_120_PKTSLEEP(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_MACID_SLEEP1
  * @brief
  * @{
  */
#define BIT_MASK_MACID63_32_PKTSLEEP   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Macid 63~Macid 32 Packet Sleep (per bit controlled)*/
#define BIT_MACID63_32_PKTSLEEP(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MACID63_32_PKTSLEEP(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ARFR2
  * @brief
  * @{
  */
#define BIT_MASK_ARFRL2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Data Auto Rate Fallback Table Register 2 indexed by RATid in TXDESC. The definition is the same as ARFR0.*/
#define BIT_ARFRL2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_ARFRL2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ARFRH2
  * @brief
  * @{
  */
#define BIT_MASK_ARFRH2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  The definition is the same as ARFR0. The content is [63:32] of 0x48Ch.*/
#define BIT_ARFRH2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_ARFRH2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ARFR3
  * @brief
  * @{
  */
#define BIT_MASK_ARFRL3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Data Auto Rate Fallback Table Register 3 indexed by RATid in TXDESC. The definition is the same as ARFR0.*/
#define BIT_ARFRL3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_ARFRL3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ARFRH3
  * @brief
  * @{
  */
#define BIT_MASK_ARFRH3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  The definition is the same as ARFR0. The content is [63:32] of 0x494h.*/
#define BIT_ARFRH3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_ARFRH3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ARFR4
  * @brief
  * @{
  */
#define BIT_MASK_ARFRL4   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Data Auto Rate Fallback Table Register 4 indexed by RATid in TXDESC. The definition is the same as ARFR0.*/
#define BIT_ARFRL4(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_ARFRL4(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ARFRH4
  * @brief
  * @{
  */
#define BIT_MASK_ARFRH4   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  The definition is the same as ARFR0. The content is [63:32] of 0x49Ch.*/
#define BIT_ARFRH4(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_ARFRH4(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ARFR5
  * @brief
  * @{
  */
#define BIT_MASK_ARFRL5   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Data Auto Rate Fallback Table Register 5 indexed by RATid in TXDESC. The definition is the same as ARFR0.*/
#define BIT_ARFRL5(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_ARFRL5(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ARFRH5
  * @brief
  * @{
  */
#define BIT_MASK_ARFRH5   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  The definition is the same as ARFR0. The content is [63:32] of 0x4A4h.*/
#define BIT_ARFRH5(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_ARFRH5(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TXRPT_START_OFFSET
  * @brief
  * @{
  */
#define BIT_MASK_LOC_SWPS_RPT_CTRL   ((u32)0x000000FF << 24)           /*!< R/W 0x2B  Start offset Location of SWPS report. Unit: 128bytes*/
#define BIT_LOC_SWPS_RPT_CTRL(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_LOC_SWPS_RPT_CTRL(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_LOC_BCN_RPT         ((u32)0x000000FF << 16)           /*!< R/W 0x11  Start offset Location of Beacon report. Unit: 128bytes*/
#define BIT_LOC_BCN_RPT(x)           (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_LOC_BCN_RPT(x)       ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_LOC_TXRPT           ((u32)0x000000FF << 8)            /*!< R/W 0x12  Start offset Location of Tx report. Unit: 128bytes*/
#define BIT_LOC_TXRPT(x)             (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_LOC_TXRPT(x)         ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_LOC_SRFF            ((u32)0x000000FF << 0)            /*!< R/W 0x10  Start offset Location of Special Report FIFO. Unit: 128bytes*/
#define BIT_LOC_SRFF(x)              (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_LOC_SRFF(x)          ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TRY_CNT_IDX
  * @brief
  * @{
  */
#define BIT_MASK_INDEX_15   ((u32)0x000000FF << 24)           /*!< R/W 0x40  For trying necessary count index 15 value*/
#define BIT_INDEX_15(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_INDEX_15(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_INDEX_14   ((u32)0x000000FF << 16)           /*!< R/W 0x40  For trying necessary count index 14 value*/
#define BIT_INDEX_14(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_INDEX_14(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_INDEX_13   ((u32)0x000000FF << 8)            /*!< R/W 0x40  For trying necessary count index 13 value*/
#define BIT_INDEX_13(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_INDEX_13(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_INDEX_12   ((u32)0x000000FF << 0)            /*!< R/W 0x40  For trying necessary count index 12 value*/
#define BIT_INDEX_12(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_INDEX_12(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_POWER_STAGE1
  * @brief
  * @{
  */
#define BIT_PTA_WL_PRI_MASK_CPU_MGQ ((u32)0x00000001 << 31)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has CPU_MGQ packet*/
#define BIT_PTA_WL_PRI_MASK_BCNQ    ((u32)0x00000001 << 30)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has BCNQ packet*/
#define BIT_PTA_WL_PRI_MASK_HIQ     ((u32)0x00000001 << 29)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has HIQ packet*/
#define BIT_PTA_WL_PRI_MASK_MGQ     ((u32)0x00000001 << 28)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has MGQ packet*/
#define BIT_PTA_WL_PRI_MASK_BK      ((u32)0x00000001 << 27)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has BKQ packet*/
#define BIT_PTA_WL_PRI_MASK_BE      ((u32)0x00000001 << 26)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has BEQ packet*/
#define BIT_PTA_WL_PRI_MASK_VI      ((u32)0x00000001 << 25)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has VIQ packet*/
#define BIT_PTA_WL_PRI_MASK_VO      ((u32)0x00000001 << 24)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has VOQ packet*/
#define BIT_MASK_POWER_STAGE1       ((u32)0x00FFFFFF << 0)           /*!< R/W 0x0  User define Power Satge1*/
#define BIT_POWER_STAGE1(x)         (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_POWER_STAGE1(x)     ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_POWER_STAGE2
  * @brief
  * @{
  */
#define BIT_MASK_EVTQ_TXRPT     ((u32)0x00000007 << 27)           /*!< RO 0x0  Tx status of event queue packet. [2]:tx ok; [1]:tx fail; [0]:tx ok in 75% of DW window*/
#define BIT_EVTQ_TXRPT(x)       (((u32)((x) & 0x00000007) << 27))
#define BIT_GET_EVTQ_TXRPT(x)   ((u32)(((x >> 27) & 0x00000007)))
#define BIT_PTA_WL_PRI_MASK_EVT ((u32)0x00000001 << 25)           /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has EVTQ packet*/
#define BIT_CTRL_PKT_POW_ADJ    ((u32)0x00000001 << 24)           /*!< R/W 0x0  */
#define BIT_MASK_POWER_STAGE2   ((u32)0x00FFFFFF << 0)            /*!< R/W 0x0  User define Power Satge2*/
#define BIT_POWER_STAGE2(x)     (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_POWER_STAGE2(x) ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_SW_AMPDU_BURST_MODE_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_EVTQ_HEAD      ((u32)0x000000FF << 24)           /*!< R/W 0xF6  TXDMA will pull event queue Pkt in this address.*/
#define BIT_EVTQ_HEAD(x)        (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_EVTQ_HEAD(x)    ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_TOTAL_LEN_TH   ((u32)0x00000FFF << 8)            /*!< R/W 0x400  aggregation  length over threshold then fetch pad packet in early mode*/
#define BIT_TOTAL_LEN_TH(x)     (((u32)((x) & 0x00000FFF) << 8))
#define BIT_GET_TOTAL_LEN_TH(x) ((u32)(((x >> 8) & 0x00000FFF)))
#define BIT_WEP_PRETX_EN        ((u32)0x00000001 << 7)            /*!< R/W 0x0  Enable pretx for WEP/TKIP, to allow a slower security clock*/
#define BIT_PRE_TX_CMD          ((u32)0x00000001 << 6)            /*!< R/W 0x1  enable pre tx cmd to use aggr more packet*/
#define BIT_MASK_NUM_SCL_EN     ((u32)0x00000003 << 4)            /*!< R/W 0x0  SW MPDU Burst mode select 00: each length field for 1 MPDU 01: each length field is the summation of 2 MPDUs 10: each length field is the summation of 3 MPDUs 11: each length field is the summation of 4 MPDUs  Note: the total MPDU number is no more than 15.*/
#define BIT_NUM_SCL_EN(x)       (((u32)((x) & 0x00000003) << 4))
#define BIT_GET_NUM_SCL_EN(x)   ((u32)(((x >> 4) & 0x00000003)))
#define BIT_BK_EN               ((u32)0x00000001 << 3)            /*!< R/W 0x0  AMPDU burst mode enable for AC_BK queue*/
#define BIT_BE_EN               ((u32)0x00000001 << 2)            /*!< R/W 0x0  AMPDU burst mode enable for AC_BE queue*/
#define BIT_VI_EN               ((u32)0x00000001 << 1)            /*!< R/W 0x0  AMPDU burst mode enable for AC_VI queue*/
#define BIT_VO_EN               ((u32)0x00000001 << 0)            /*!< R/W 0x0  AMPDU burst mode enable for AC_VO queue*/
/** @} */

/** @defgroup REG_PKT_LIFE_TIME
  * @brief
  * @{
  */
#define BIT_MASK_PKT_LIFTIME_BEBK   ((u32)0x0000FFFF << 16)           /*!< R/W 0x1000  BE/BK packet lifetime unit: 256us*/
#define BIT_PKT_LIFTIME_BEBK(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_PKT_LIFTIME_BEBK(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_PKT_LIFTIME_VOVI   ((u32)0x0000FFFF << 0)            /*!< R/W 0x1000  VO/VI packet lifetime unit: 256us*/
#define BIT_PKT_LIFTIME_VOVI(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_PKT_LIFTIME_VOVI(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_STBC_SETTING
  * @brief
  * @{
  */
#define BIT_MASK_CDEND_TXTIME_L   ((u8)0x0000000F << 4)           /*!< R/W 0x4  Cfend packet txtime*/
#define BIT_CDEND_TXTIME_L(x)     (((u8)((x) & 0x0000000F) << 4))
#define BIT_GET_CDEND_TXTIME_L(x) ((u8)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_NESS             ((u8)0x00000003 << 2)           /*!< R/W 0x0  NESS*/
#define BIT_NESS(x)               (((u8)((x) & 0x00000003) << 2))
#define BIT_GET_NESS(x)           ((u8)(((x >> 2) & 0x00000003)))
#define BIT_MASK_STBC_CFEND       ((u8)0x00000003 << 0)           /*!< R/W 0x0  CFEND STBC*/
#define BIT_STBC_CFEND(x)         (((u8)((x) & 0x00000003) << 0))
#define BIT_GET_STBC_CFEND(x)     ((u8)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_STBC_SETTING2
  * @brief
  * @{
  */
#define BIT_MASK_CDEND_TXTIME_H   ((u8)0x0000001F << 0)           /*!< R/W 0x3  Cfend packet txtime*/
#define BIT_CDEND_TXTIME_H(x)     (((u8)((x) & 0x0000001F) << 0))
#define BIT_GET_CDEND_TXTIME_H(x) ((u8)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_QUEUE_CTRL
  * @brief
  * @{
  */
#define BIT_FORCE_RND_PRI     ((u8)0x00000001 << 6) /*!< R/W 0x0  0: Queue list priority change to old flow 1: Use queue list priority*/
#define BIT_PTA_EDCCA_EN      ((u8)0x00000001 << 5) /*!< R/W 0x0  0 : wl_tx signal to PTA does not consider EDCCA 1 : wl_tx signal to PTA consider EDCCA*/
#define BIT_PTA_WL_TX_EN      ((u8)0x00000001 << 4) /*!< R/W 0x0  enable WL PTA (should be set in init MAC)*/
#define BIT_USE_DATA_BW       ((u8)0x00000001 << 3) /*!< R/W 0x0  1 : Use des2_data_bw for this packet 0 :  在des1_cca_rts = 2'b10, follow ch_bw_status來決定要不要更新update_bw*/
#define BIT_TRI_PKT_INT_MODE1 ((u8)0x00000001 << 2) /*!< R/W 0x1  If trigger frame is transmitted into txpktbuf and tx-ok, HW generates interrupt 1: Enable 0: Disable*/
#define BIT_TRI_PKT_INT_MODE0 ((u8)0x00000001 << 1) /*!< R/W 0x0  If trigger frame is transmitted into txpktbuf, HW generates interrupt 1: Enable 0: Disable*/
#define BIT_ACQ_MODE_SEL      ((u8)0x00000001 << 0) /*!< R/W 0x0  1: Enable 4AC Mode(only use band0) 0: Enable ACQ0~19 Mode*/
/** @} */

/** @defgroup REG_SINGLE_AMPDU_CTRL
  * @brief
  * @{
  */
#define BIT_EN_SINGLE_APMDU ((u8)0x00000001 << 7) /*!< R/W 0x0  If this bit is set, Enable single sub-frame APMDU.*/
/** @} */

/** @defgroup REG_PROT_MODE_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_RTS_MAX_AGG_NUM   ((u32)0x0000003F << 24)           /*!< R/W 0xc  In RTS frame exchange sequence, the maximum aggregation packet number limit is defined by this register.*/
#define BIT_RTS_MAX_AGG_NUM(x)     (((u32)((x) & 0x0000003F) << 24))
#define BIT_GET_RTS_MAX_AGG_NUM(x) ((u32)(((x >> 24) & 0x0000003F)))
#define BIT_MASK_MAX_AGG_NUM       ((u32)0x0000003F << 16)           /*!< R/W 0x14  the maximum aggregation packet number limit*/
#define BIT_MAX_AGG_NUM(x)         (((u32)((x) & 0x0000003F) << 16))
#define BIT_GET_MAX_AGG_NUM(x)     ((u32)(((x >> 16) & 0x0000003F)))
#define BIT_MASK_RTS_TXTIME_TH     ((u32)0x000000FF << 8)            /*!< R/W 0x1  RTS packet txtime threshold*/
#define BIT_RTS_TXTIME_TH(x)       (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_RTS_TXTIME_TH(x)   ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_RTS_LEN_TH        ((u32)0x000000FF << 0)            /*!< R/W 0x1  RTS packet Length threshold*/
#define BIT_RTS_LEN_TH(x)          (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_RTS_LEN_TH(x)      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BAR_MODE_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_BAR_RTY_LMT         ((u32)0x00000003 << 16)           /*!< R/W 0x2  BAR retry limit*/
#define BIT_BAR_RTY_LMT(x)           (((u32)((x) & 0x00000003) << 16))
#define BIT_GET_BAR_RTY_LMT(x)       ((u32)(((x >> 16) & 0x00000003)))
#define BIT_MASK_BAR_PKT_TXTIME_TH   ((u32)0x000000FF << 8)            /*!< R/W 0xFF  BAR pkt txtime thrs*/
#define BIT_BAR_PKT_TXTIME_TH(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_BAR_PKT_TXTIME_TH(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_BAR_EN_V1                ((u32)0x00000001 << 6)            /*!< R/W 0x1  Enable BAR*/
#define BIT_MASK_BAR_PKTNUM_TH_V1    ((u32)0x0000003F << 0)            /*!< R/W 0x3F  BAR Pktnum Thrs*/
#define BIT_BAR_PKTNUM_TH_V1(x)      (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_BAR_PKTNUM_TH_V1(x)  ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_RA_TRY_RATE_AGG_LMT
  * @brief
  * @{
  */
#define BIT_MASK_RA_TRY_RATE_AGG_LMT_V1   ((u8)0x0000003F << 0)           /*!< R/W 0x1  The aggregation packet number limit for try up rate of rate adaptive when descriptor Try bit is set.*/
#define BIT_RA_TRY_RATE_AGG_LMT_V1(x)     (((u8)((x) & 0x0000003F) << 0))
#define BIT_GET_RA_TRY_RATE_AGG_LMT_V1(x) ((u8)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_MACID_SLEEP2
  * @brief
  * @{
  */
#define BIT_MASK_MACID95_64PKTSLEEP   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Macid 95~Macid 64 Packet Sleep (per bit controlled)*/
#define BIT_MACID95_64PKTSLEEP(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MACID95_64PKTSLEEP(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MACID_SLEEP
  * @brief
  * @{
  */
#define BIT_MASK_MACID31_0PKTSLEEP   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Macid 31~Macid 0 Packet Sleep (per bit controlled)*/
#define BIT_MACID31_0PKTSLEEP(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MACID31_0PKTSLEEP(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HW_SEQ0
  * @brief
  * @{
  */
#define BIT_MASK_HW_SSN_SEQ0   ((u16)0x00000FFF << 0)           /*!< R/W 0x0  When TXDESC HWSEQEN is set, MAC will overwrite SEQ control by this register. Before DRV hand over the SEQ control to HW, DRV may set the current SEQ to this register. When DRV will take back the SEQ control from HW, DRV may get the current sequence from this register.*/
#define BIT_HW_SSN_SEQ0(x)     (((u16)((x) & 0x00000FFF) << 0))
#define BIT_GET_HW_SSN_SEQ0(x) ((u16)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HW_SEQ1
  * @brief
  * @{
  */
#define BIT_MASK_HW_SSN_SEQ1   ((u16)0x00000FFF << 0)           /*!< R/W 0x0  When TXDESC HWSEQEN is set, MAC will overwrite SEQ control by this register. Before DRV hand over the SEQ control to HW, DRV may set the current SEQ to this register. When DRV will take back the SEQ control from HW, DRV may get the current sequence from this register.*/
#define BIT_HW_SSN_SEQ1(x)     (((u16)((x) & 0x00000FFF) << 0))
#define BIT_GET_HW_SSN_SEQ1(x) ((u16)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HW_SEQ2
  * @brief
  * @{
  */
#define BIT_MASK_HW_SSN_SEQ2   ((u16)0x00000FFF << 0)           /*!< R/W 0x0  When TXDESC HWSEQEN is set, MAC will overwrite SEQ control by this register. Before DRV hand over the SEQ control to HW, DRV may set the current SEQ to this register. When DRV will take back the SEQ control from HW, DRV may get the current sequence from this register.*/
#define BIT_HW_SSN_SEQ2(x)     (((u16)((x) & 0x00000FFF) << 0))
#define BIT_GET_HW_SSN_SEQ2(x) ((u16)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HW_SEQ3
  * @brief
  * @{
  */
#define BIT_MASK_HW_SSN_SEQ3   ((u16)0x00000FFF << 0)           /*!< R/W 0x0  When TXDESC HWSEQEN is set, MAC will overwrite SEQ control by this register. Before DRV hand over the SEQ control to HW, DRV may set the current SEQ to this register. When DRV will take back the SEQ control from HW, DRV may get the current sequence from this register.*/
#define BIT_HW_SSN_SEQ3(x)     (((u16)((x) & 0x00000FFF) << 0))
#define BIT_GET_HW_SSN_SEQ3(x) ((u16)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_BIT_TX_NULL
  * @brief
  * @{
  */
#define BIT_TX_NULL_1 ((u16)0x00000001 << 1) /*!< RO 0x0  Null 1 packet tx ok indicator*/
#define BIT_TX_NULL_0 ((u16)0x00000001 << 0) /*!< RO 0x0  Null 0 packet tx ok indicator*/
/** @} */

/** @defgroup REG_PTCL_ERR_STATUS_V1
  * @brief
  * @{
  */
#define BIT_MASK_PTCL_TOTAL_PG_V4      ((u16)0x000000FF << 8)           /*!< RO 0x0  Total Page in PTCL*/
#define BIT_PTCL_TOTAL_PG_V4(x)        (((u16)((x) & 0x000000FF) << 8))
#define BIT_GET_PTCL_TOTAL_PG_V4(x)    ((u16)(((x >> 8) & 0x000000FF)))
#define BIT_PTCL_TOTAL_PG_8            ((u16)0x00000001 << 7)           /*!< RO 0x0  Total Page in PTCL*/
#define BIT_PTCL_RATE_TABLE_INVALID_V1 ((u16)0x00000001 << 6)           /*!< R/W1C 0x0  When packets do rate fallback process, if rate table all invalid, it will cause this ERROR FLAG.*/
#define BIT_TXTIMEOUT_ERR              ((u16)0x00000001 << 5)           /*!< R/W1C 0x0  TX time over 2 sec(Calcuate to generate TxCMD time)*/
#define BIT_NULLPAGE_ERR               ((u16)0x00000001 << 4)           /*!< R/W1C 0x0  packet report current page is NULL*/
#define BIT_CONTENTION_ERR             ((u16)0x00000001 << 3)           /*!< R/W1C 0x0  packet contention error, cause by current page is NULL*/
#define BIT_HEADNULL_ERR               ((u16)0x00000001 << 2)           /*!< R/W1C 0x0  packet assign to queue, but start page is NULL*/
#define BIT_OVERFLOW_ERR               ((u16)0x00000001 << 1)           /*!< R/W1C 0x0  packet queue total page overflow || current page is NULL but packet queue  total page not empty == overflow*/
#define BIT_QUEUE_INDEX_ERR            ((u16)0x00000001 << 0)           /*!< R/W1C 0x0  packet assign queue error by queue_index = 0*/
/** @} */

/** @defgroup REG_HQMGQ_DROP
  * @brief
  * @{
  */
#define BIT_HIQ_DROP          ((u8)0x00000001 << 7) /*!< R/W 0x0  HIQ drop per macid with MACID_DROP register.*/
#define BIT_MGQ_DROP          ((u8)0x00000001 << 6) /*!< R/W 0x0  MGQ drop per macid with MACID_DROP register.*/
#define BIT_CLR_HGQ_REQ_BLOCK ((u8)0x00000001 << 5) /*!< R/W 0x1  enable clear hgq_req_block signal when hgq dma fail*/
/** @} */

/** @defgroup REG_PRECNT_CTRL
  * @brief
  * @{
  */
#define BIT_EN_PRECNT        ((u16)0x00000001 << 11)          /*!< R/W 0x0  If BIT_EN_PRECNT = 1, enable PRECNT function If BIT_EN_PRECNT = 0, disable PRECNT function*/
#define BIT_MASK_PRECNT_TH   ((u16)0x000007FF << 0)           /*!< R/W 0x230  If BIT_EN_PRECNT = 1, the BIT_PRECNT_TH will count down after PHYTXON signal asserting every transmission in pre-tx mode.(Default: 7us)*/
#define BIT_PRECNT_TH(x)     (((u16)((x) & 0x000007FF) << 0))
#define BIT_GET_PRECNT_TH(x) ((u16)(((x >> 0) & 0x000007FF)))
/** @} */

/** @defgroup REG_BT_POLLUTE_PKTCNT_V1
  * @brief
  * @{
  */
#define BIT_MASK_BT_POLLUTE_PKT_CNT   ((u32)0x0000FFFF << 0)           /*!< R/W1C 0x0  When BT pollute pkt generate, BIT_BT_POLLUTE_PKTCNT will count this type packets.write bit15 to clear*/
#define BIT_BT_POLLUTE_PKT_CNT(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BT_POLLUTE_PKT_CNT(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_DROP_PKT_NUM
  * @brief
  * @{
  */
#define BIT_MASK_DROP_PKT_NUM   ((u32)0x0000FFFF << 0)           /*!< R/W1C 0x0  Statistic the number of dropped packets*/
#define BIT_DROP_PKT_NUM(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_DROP_PKT_NUM(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_TX_RPT_INFO_L32
  * @brief
  * @{
  */
#define BIT_MASK_AC_TX_RPT_INFO_L32   ((u32)0xFFFFFFFF << 0)           /*!< RO 0x44332211  TX RPT information,low 32bit*/
#define BIT_AC_TX_RPT_INFO_L32(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_AC_TX_RPT_INFO_L32(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TX_RPT_INFO_H32
  * @brief
  * @{
  */
#define BIT_MASK_AC_TX_RPT_INFO_H32   ((u32)0xFFFFFFFF << 0)           /*!< RO 0x88776655  TX RPT information,high 32bit*/
#define BIT_AC_TX_RPT_INFO_H32(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_AC_TX_RPT_INFO_H32(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_DUMMY_PAGE4_V1
  * @brief
  * @{
  */
#define BIT_MASK_RSVD_PAGE4_V1   ((u16)0x0000FFFF << 0)           /*!< R/W 0x0  For SW use*/
#define BIT_RSVD_PAGE4_V1(x)     (((u16)((x) & 0x0000FFFF) << 0))
#define BIT_GET_RSVD_PAGE4_V1(x) ((u16)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_DUMMY_PAGE4_1
  * @brief
  * @{
  */
#define BIT_MASK_RSVD_PAGE4_V4   ((u16)0x00000FFF << 4)           /*!< R/W 0xFFF  For SW use*/
#define BIT_RSVD_PAGE4_V4(x)     (((u16)((x) & 0x00000FFF) << 4))
#define BIT_GET_RSVD_PAGE4_V4(x) ((u16)(((x >> 4) & 0x00000FFF)))
#define BIT_EN_BCN_TRXRPT_V2     ((u16)0x00000001 << 1)           /*!< R/W 0x1  If this bit is set, PTCL will write BCN TRXRPT when BCNOK/BCNERR INT.  FW have clear this bit before enter LPS 32K mode.*/
/** @} */

/** @defgroup REG_BF0_TIME_SETTING_V1
  * @brief
  * @{
  */
#define BIT_BF0_TIMER_SET           ((u32)0x00000001 << 31)           /*!< R/W 0x0  write 1 to set beamforming 0 timer to BIT_bf0_lifetime*/
#define BIT_BF0_TIMER_CLR           ((u32)0x00000001 << 30)           /*!< R/W 0x0  write 1 to clear beamforming 0 timer to 0*/
#define BIT_BF0_UPDATE_EN           ((u32)0x00000001 << 29)           /*!< R/W 0x0  1: when tx ndp ok/fail, enable to update beamforming 0 timer*/
#define BIT_BF0_TIMER_EN            ((u32)0x00000001 << 28)           /*!< R/W 0x0  beamforming 0 timer enable*/
#define BIT_MASK_BF0_PRETIME_OVER   ((u32)0x00000FFF << 16)           /*!< R/W 0xFFF  beamforming 0 pre timeout time*/
#define BIT_BF0_PRETIME_OVER(x)     (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_BF0_PRETIME_OVER(x) ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_BF0_LIFETIME       ((u32)0x0000FFFF << 0)            /*!< R/W 0xFFFF  beamforming 0 life time*/
#define BIT_BF0_LIFETIME(x)         (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BF0_LIFETIME(x)     ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BF1_TIME_SETTING_V1
  * @brief
  * @{
  */
#define BIT_BF1_TIMER_SET           ((u32)0x00000001 << 31)           /*!< R/W 0x0  write 1 to set beamforming 0 timer to BIT_bf1_lifetime*/
#define BIT_BF1_TIMER_CLR           ((u32)0x00000001 << 30)           /*!< R/W 0x0  write 1 to clear beamforming 1 timer to 0*/
#define BIT_BF1_UPDATE_EN           ((u32)0x00000001 << 29)           /*!< R/W 0x0  1: when tx ndp ok/fail, enable to update beamforming 1 timer*/
#define BIT_BF1_TIMER_EN            ((u32)0x00000001 << 28)           /*!< R/W 0x0  beamforming 1 timer enable*/
#define BIT_MASK_BF1_PRETIME_OVER   ((u32)0x00000FFF << 16)           /*!< R/W 0xFFF  beamforming 1 pre timeout time*/
#define BIT_BF1_PRETIME_OVER(x)     (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_BF1_PRETIME_OVER(x) ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_BF1_LIFETIME       ((u32)0x0000FFFF << 0)            /*!< R/W 0xFFFF  beamforming 1 life time*/
#define BIT_BF1_LIFETIME(x)         (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BF1_LIFETIME(x)     ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BF_TIMEOUT_EN_V1
  * @brief
  * @{
  */
#define BIT_BF1_TIMEOUT_EN ((u32)0x00000001 << 1) /*!< R/W 0x1  1: when beamforming 1 timer count to 0,then disable beamforming 1*/
#define BIT_BF0_TIMEOUT_EN ((u32)0x00000001 << 0) /*!< R/W 0x1  1: when beamforming 0 timer count to 0,then disable beamforming 0*/
/** @} */

/** @defgroup REG_MACID_RELEASE0_V1
  * @brief
  * @{
  */
#define BIT_MASK_MACID31_0_RELEASE   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Macid31~Macid0 Release(per bit controlled)*/
#define BIT_MACID31_0_RELEASE(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MACID31_0_RELEASE(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MACID_RELEASE1_V1
  * @brief
  * @{
  */
#define BIT_MASK_MACID63_32_RELEASE   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Macid63~Macid32 Release(per bit controlled)*/
#define BIT_MACID63_32_RELEASE(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MACID63_32_RELEASE(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MACID_RELEASE2_V1
  * @brief
  * @{
  */
#define BIT_MASK_MACID95_64_RELEASE   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Macid95~Macid64 Release(per bit controlled)*/
#define BIT_MACID95_64_RELEASE(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MACID95_64_RELEASE(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MACID_RELEASE3_V1
  * @brief
  * @{
  */
#define BIT_MASK_MACID127_96_RELEASE   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Macid127~Macid96 Release(per bit controlled)*/
#define BIT_MACID127_96_RELEASE(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MACID127_96_RELEASE(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MACID_RELEASE_SETTING_V1
  * @brief
  * @{
  */
#define BIT_MACID_VALUE         ((u32)0x00000001 << 7)           /*!< R/W 0x0  write this field to set REG_macid_release[BIT_macid_offset] = BIT_macid_value*/
#define BIT_MASK_MACID_OFFSET   ((u32)0x0000007F << 0)           /*!< R/W 0x0  write this field to set REG_macid_release[BIT_macid_offset] = BIT_macid_value*/
#define BIT_MACID_OFFSET(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_MACID_OFFSET(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_FAST_EDCA_VOVI_SETTING_V1
  * @brief
  * @{
  */
#define BIT_MASK_VI_FAST_EDCA_TO       ((u32)0x000000FF << 24)           /*!< R/W 0x8  vi queue fast edca timeout value*/
#define BIT_VI_FAST_EDCA_TO(x)         (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_VI_FAST_EDCA_TO(x)     ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_VI_THRESHOLD_SEL           ((u32)0x00000001 << 23)           /*!< R/W 0x0  1: use all vi queue pktnum compare to pktnum_threshold; 0: use single macid pktnum compare to pktnum_threshold;*/
#define BIT_MASK_VI_FAST_EDCA_PKT_TH   ((u32)0x0000007F << 16)           /*!< R/W 0x4  vi queue fast edca pkt number threshold*/
#define BIT_VI_FAST_EDCA_PKT_TH(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_VI_FAST_EDCA_PKT_TH(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_VO_FAST_EDCA_TO_V1    ((u32)0x0000FFFF << 0)            /*!< R/W 0x8  vo queue fast edca timeout value*/
#define BIT_VO_FAST_EDCA_TO_V1(x)      (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_VO_FAST_EDCA_TO_V1(x)  ((u32)(((x >> 0) & 0x0000FFFF)))
#define BIT_VO_THRESHOLD_SEL           ((u32)0x00000001 << 7)            /*!< R/W 0x0  1: use all vo queue pktnum compare to pktnum_threshold; 0: use single macid pktnum compare to pktnum_threshold;*/
#define BIT_MASK_VO_FAST_EDCA_PKT_TH   ((u32)0x0000007F << 0)            /*!< R/W 0x4  vo queue fast edca pkt number threshold*/
#define BIT_VO_FAST_EDCA_PKT_TH(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_VO_FAST_EDCA_PKT_TH(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_FAST_EDCA_BEBK_SETTING_V1
  * @brief
  * @{
  */
#define BIT_MASK_BK_FAST_EDCA_TO       ((u32)0x000000FF << 24)           /*!< R/W 0x8  bk queue fast edca timeout value*/
#define BIT_BK_FAST_EDCA_TO(x)         (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_BK_FAST_EDCA_TO(x)     ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_BK_THRESHOLD_SEL           ((u32)0x00000001 << 23)           /*!< R/W 0x0  1: use all bk queue pktnum compare to pktnum_threshold; 0: use single macid pktnum compare to pktnum_threshold;*/
#define BIT_MASK_BK_FAST_EDCA_PKT_TH   ((u32)0x0000007F << 16)           /*!< R/W 0x4  bk queue fast edca pkt number threshold*/
#define BIT_BK_FAST_EDCA_PKT_TH(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_BK_FAST_EDCA_PKT_TH(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_BE_FAST_EDCA_TO_V1    ((u32)0x0000FFFF << 0)            /*!< R/W 0x8  be queue fast edca timeout value*/
#define BIT_BE_FAST_EDCA_TO_V1(x)      (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BE_FAST_EDCA_TO_V1(x)  ((u32)(((x >> 0) & 0x0000FFFF)))
#define BIT_BE_THRESHOLD_SEL           ((u32)0x00000001 << 7)            /*!< R/W 0x0  1: use all be queue pktnum compare to pktnum_threshold; 0: use single macid pktnum compare to pktnum_threshold;*/
#define BIT_MASK_BE_FAST_EDCA_PKT_TH   ((u32)0x0000007F << 0)            /*!< R/W 0x4  be queue fast edca pkt number threshold*/
#define BIT_BE_FAST_EDCA_PKT_TH(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_BE_FAST_EDCA_PKT_TH(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_R_MACID_RELEASE_SUCCESS_0_V1
  * @brief
  * @{
  */
#define BIT_MASK_R_MACID_RELEASE_SUCCESS_0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  macid0~31 release status. Set by HW and cleared by SW (by writing 247C[7:0] with corresponding MACID)*/
#define BIT_R_MACID_RELEASE_SUCCESS_0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_R_MACID_RELEASE_SUCCESS_0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_R_MACID_RELEASE_SUCCESS_1_V1
  * @brief
  * @{
  */
#define BIT_MASK_R_MACID_RELEASE_SUCCESS_1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  macid32~63 release status. Set by HW and cleared by SW (by writing 247C[7:0] with corresponding MACID)*/
#define BIT_R_MACID_RELEASE_SUCCESS_1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_R_MACID_RELEASE_SUCCESS_1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_R_MACID_RELEASE_SUCCESS_2_V1
  * @brief
  * @{
  */
#define BIT_MASK_R_MACID_RELEASE_SUCCESS_2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  macid64~95 release status. Set by HW and cleared by SW (by writing 247C[7:0] with corresponding MACID)*/
#define BIT_R_MACID_RELEASE_SUCCESS_2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_R_MACID_RELEASE_SUCCESS_2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_R_MACID_RELEASE_SUCCESS_3_V1
  * @brief
  * @{
  */
#define BIT_MASK_R_MACID_RELEASE_SUCCESS_3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  macid96~127 release status. Set by HW and cleared by SW (by writing 247C[7:0] with corresponding MACID)*/
#define BIT_R_MACID_RELEASE_SUCCESS_3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_R_MACID_RELEASE_SUCCESS_3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_R_MACID_RELEASE_SUCCESS_CLEAR_OFFSET_V1
  * @brief
  * @{
  */
#define BIT_MASK_R_MACID_RELEASE_SUCCESS_CLEAR_OFFSET   ((u32)0x0000007F << 0)           /*!< R/W 0x0  HW will set 0x2460~0x246C if one packet was released successfully for a given macid. SW use this register to reset the status.*/
#define BIT_R_MACID_RELEASE_SUCCESS_CLEAR_OFFSET(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_R_MACID_RELEASE_SUCCESS_CLEAR_OFFSET(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_NAN_INFO0
  * @brief
  * @{
  */
#define BIT_MASK_NAN_INFO0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  used for information exchange between driver and FW in NAN feature*/
#define BIT_NAN_INFO0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_NAN_INFO0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NAN_INFO1
  * @brief
  * @{
  */
#define BIT_MASK_NAN_INFO1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  used for information exchange between driver and FW in NAN feature*/
#define BIT_NAN_INFO1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_NAN_INFO1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NAN_INFO2
  * @brief
  * @{
  */
#define BIT_MASK_NAN_INFO2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  used for information exchange between driver and FW in NAN feature*/
#define BIT_NAN_INFO2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_NAN_INFO2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NAN_INFO3
  * @brief
  * @{
  */
#define BIT_MASK_NAN_INFO3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  used for information exchange between driver and FW in NAN feature*/
#define BIT_NAN_INFO3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_NAN_INFO3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NAN_INFO4
  * @brief
  * @{
  */
#define BIT_MASK_NAN_INFO4   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  used for information exchange between driver and FW in NAN feature*/
#define BIT_NAN_INFO4(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_NAN_INFO4(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NAN_INFO5
  * @brief
  * @{
  */
#define BIT_MASK_NAN_INFO5   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  used for information exchange between driver and FW in NAN feature*/
#define BIT_NAN_INFO5(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_NAN_INFO5(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NAN_INFO6
  * @brief
  * @{
  */
#define BIT_MASK_NAN_INFO6   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  used for information exchange between driver and FW in NAN feature*/
#define BIT_NAN_INFO6(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_NAN_INFO6(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NAN_INFO7
  * @brief
  * @{
  */
#define BIT_MASK_NAN_INFO7   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  used for information exchange between driver and FW in NAN feature*/
#define BIT_NAN_INFO7(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_NAN_INFO7(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NAN_INFO8
  * @brief
  * @{
  */
#define BIT_MASK_NAN_INFO8   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  used for information exchange between driver and FW in NAN feature*/
#define BIT_NAN_INFO8(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_NAN_INFO8(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NAN_INFO9
  * @brief
  * @{
  */
#define BIT_MASK_NAN_INFO9   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  used for information exchange between driver and FW in NAN feature*/
#define BIT_NAN_INFO9(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_NAN_INFO9(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CHNL_INFO_CTRL_V1
  * @brief
  * @{
  */
#define BIT_CHNL_REF_RXNAV ((u32)0x00000001 << 7) /*!< R/W 0x0  Busy time reference RXNAV (ATM)*/
#define BIT_CHNL_REF_VBON  ((u32)0x00000001 << 6) /*!< R/W 0x0  Busy time reference vbon (ATM)*/
#define BIT_CHNL_REF_EDCA  ((u32)0x00000001 << 5) /*!< R/W 0x0  Busy time reference EDCCA (ATM)*/
#define BIT_CHNL_REF_CCA   ((u32)0x00000001 << 4) /*!< R/W 0x0  Busy time reference CCA (ATM)*/
#define BIT_RST_CHNL_BUSY  ((u32)0x00000001 << 3) /*!< W 0x0  Write "one" to set the counter to zero. (channel busy time) (ATM)*/
#define BIT_RST_CHNL_IDLE  ((u32)0x00000001 << 2) /*!< W 0x0  Write "one" to set the counter to zero. (channel idle time)*/
#define BIT_CHNL_INFO_RST  ((u32)0x00000001 << 1) /*!< R/W 0x0  0: stop counter (no clear counter) (ATM) 1: start count (no clear counter)*/
#define BIT_ATM_AIRTIME_EN ((u32)0x00000001 << 0) /*!< R/W 0x0  0 : If this bit disable, no need to count air time (ATM) 1 : If this bit enable, count air time and paste to TXRPT*/
/** @} */

/** @defgroup REG_CHNL_IDLE_TIME_V1
  * @brief
  * @{
  */
#define BIT_MASK_CHNL_IDLE_TIME   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Unit: us (ATM)*/
#define BIT_CHNL_IDLE_TIME(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_CHNL_IDLE_TIME(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CHNL_BUSY_TIME_V1
  * @brief
  * @{
  */
#define BIT_MASK_CHNL_BUSY_TIME   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Unit: us (ATM)*/
#define BIT_CHNL_BUSY_TIME(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_CHNL_BUSY_TIME(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_SWPS_CTRL_V1
  * @brief
  * @{
  */
#define BIT_MASK_SWPS_RPT_LENGTH     ((u16)0x0000007F << 8)           /*!< R/W 0x0  Control report length, the value represents the max macid in report. Value could be 0~127. 0: report MACID0 127: report MACID0~127 Example:  0, report body is 16 bytes 127, report body is 2048 bytes*/
#define BIT_SWPS_RPT_LENGTH(x)       (((u16)((x) & 0x0000007F) << 8))
#define BIT_GET_SWPS_RPT_LENGTH(x)   ((u16)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_MACID_SWPS_EN_SEL   ((u16)0x00000003 << 2)           /*!< R/W 0x0  Select for MACID SWPS Enable bit in MACID_SWPS_EN (0x24FC) 2'b 00: MACID 0~31 2'b 01: MACID 32~63 2'b 10: MACID 64~95 2'b 11: MACID 96~127*/
#define BIT_MACID_SWPS_EN_SEL(x)     (((u16)((x) & 0x00000003) << 2))
#define BIT_GET_MACID_SWPS_EN_SEL(x) ((u16)(((x >> 2) & 0x00000003)))
#define BIT_SWPS_MANUALL_POLLING     ((u16)0x00000001 << 1)           /*!< W 0x0  Write 1 to always generate SWPS packet even when schedule no update content.*/
#define BIT_SWPS_EN                  ((u16)0x00000001 << 0)           /*!< R/W 0x0  SWPS function on-off switch. Control all HW behavior(Schedule, WMAC).*/
/** @} */

/** @defgroup REG_SWPS_PKT_TH_V1
  * @brief
  * @{
  */
#define BIT_MASK_SWPS_PKT_TH   ((u16)0x0000FFFF << 0)           /*!< R/W 0x0  The pkt threshold for HW to generate SWPS report. If pkt with SWPS seq Txok+Txdrop match this register. SWPS report will be generated. unit: packet number, 0:disable,close count*/
#define BIT_SWPS_PKT_TH(x)     (((u16)((x) & 0x0000FFFF) << 0))
#define BIT_GET_SWPS_PKT_TH(x) ((u16)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_SWPS_TIME_TH_V1
  * @brief
  * @{
  */
#define BIT_MASK_SWPS_PSTIME_TH   ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  The time threshold for HW to collecting consecutive PS state change(01) of different MACIDs in a short time in one report. If timer timeout, SWPS report will be generated. unit: 32us, 0: disable, close count, means every state change 0 to 1 will be reported by different report.*/
#define BIT_SWPS_PSTIME_TH(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_SWPS_PSTIME_TH(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_SWPS_TIME_TH     ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  The time threshold for HW to generate SWPS report. If timer timeout, SWPS report will be generated. unit: 32us, 0: disable, close count.*/
#define BIT_SWPS_TIME_TH(x)       (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_SWPS_TIME_TH(x)   ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MACID_SWPS_EN_V1
  * @brief
  * @{
  */
#define BIT_MASK_MACID_SWPS_EN   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Represent for different MACID SWPS Enable setting by MACID_SWPS_EN_SEL (0x24F4 [3:2]) 2'b 00: MACID 0~31 2'b 01: MACID 32~63 2'b 10: MACID 64~95 2'b 11: MACID 96~127*/
#define BIT_MACID_SWPS_EN(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MACID_SWPS_EN(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/*==========REG_PAGE4 Register Address Definition==========*/
#define REG_QUEUELIST_INFO0                                  0x400
#define REG_QUEUELIST_INFO1                                  0x404
#define REG_QUEUELIST_INFO2_V1                               0x414
#define REG_TXPKT_EMPTY_V1                                   0x418
#define REG_CPU_MGQ_INFO                                     0x41C
#define REG_FWHW_TXQ_CTRL                                    0x420
#define REG_HWSEQ_CTRL                                       0x423
#define REG_BNDY_LIFETIME_TAIL                               0x424
#define REG_LIFETIME_EN                                      0x426
#define REG_FW_FREE_TAIL                                     0x427
#define REG_RETRY_LIMIT_SIFS                                 0x428
#define REG_TXBF_CTRL                                        0x42C
#define REG_DARFRC                                           0x430
#define REG_DARFRCH                                          0x434
#define REG_RARFRC                                           0x438
#define REG_RARFRCH                                          0x43C
#define REG_RRSR                                             0x440
#define REG_RSVD_4                                           0x443
#define REG_ARFR0                                            0x444
#define REG_ARFRH0                                           0x448
#define REG_ARFR1                                            0x44C
#define REG_ARFRH1                                           0x450
#define REG_CCK_CHECK                                        0x454
#define REG_BCNQ2_HEAD                                       0x455
#define REG_AMPDU_MAX_TIME                                   0x456
#define REG_BCNQ1_BDNY                                       0x457
#define REG_AMPDU_MAX_LENGTH                                 0x458
#define REG_WMAC_LBK_BUF_HD                                  0x45D
#define REG_TX_HANG_CTRL                                     0x45E
#define REG_NDPA_OPT_CTRL                                    0x45F
#define REG_RSVD_6                                           0x460
#define REG_RD_RESP_PKT_TH                                   0x463
#define REG_CMDQ_INFO                                        0x464
#define REG_TXRPT_CTRL                                       0x47C
#define REG_INIRTS_RATE_SEL                                  0x480
#define REG_BASIC_CFEND_RATE                                 0x481
#define REG_STBC_CFEND_RATE                                  0x482
#define REG_DATA_SC                                          0x483
#define REG_MACID_SLEEP3                                     0x484
#define REG_MACID_SLEEP4                                     0x485
#define REG_MACID_SLEEP5                                     0x487
#define REG_MACID_SLEEP1                                     0x488
#define REG_ARFR2                                            0x48C
#define REG_ARFRH2                                           0x490
#define REG_ARFR3                                            0x494
#define REG_ARFRH3                                           0x498
#define REG_ARFR4                                            0x49C
#define REG_ARFRH4                                           0x4A0
#define REG_ARFR5                                            0x4A4
#define REG_ARFRH5                                           0x4A8
#define REG_TXRPT_START_OFFSET                               0x4AC
#define REG_TRY_CNT_IDX                                      0x4B0
#define REG_POWER_STAGE1                                     0x4B4
#define REG_POWER_STAGE2                                     0x4B8
#define REG_SW_AMPDU_BURST_MODE_CTRL                         0x4BC
#define REG_PKT_LIFE_TIME                                    0x4C0
#define REG_STBC_SETTING                                     0x4C4
#define REG_STBC_SETTING2                                    0x4C5
#define REG_QUEUE_CTRL                                       0x4C6
#define REG_SINGLE_AMPDU_CTRL                                0x4C7
#define REG_PROT_MODE_CTRL                                   0x4C8
#define REG_BAR_MODE_CTRL                                    0x4CC
#define REG_RA_TRY_RATE_AGG_LMT                              0x4CF
#define REG_MACID_SLEEP2                                     0x4D0
#define REG_MACID_SLEEP                                      0x4D4
#define REG_HW_SEQ0                                          0x4D8
#define REG_HW_SEQ1                                          0x4DA
#define REG_HW_SEQ2                                          0x4DC
#define REG_HW_SEQ3                                          0x4DE
#define REG_BIT_TX_NULL                                      0x4E0
#define REG_PTCL_ERR_STATUS_V1                               0x4E2
#define REG_HQMGQ_DROP                                       0x4E4
#define REG_PRECNT_CTRL                                      0x4E5
#define REG_RSVD_8                                           0x4E7
#define REG_BT_POLLUTE_PKTCNT_V1                             0x4E8
#define REG_DROP_PKT_NUM                                     0x4EC
#define REG_TX_RPT_INFO_L32                                  0x4F0
#define REG_TX_RPT_INFO_H32                                  0x4F4
#define REG_DUMMY_PAGE4_V1                                   0x4FC
#define REG_DUMMY_PAGE4_1                                    0x4FE
#define REG_RSVD_11                                          0x1420
#define REG_RSVD_21                                          0x1454
#define REG_RSVD_35                                          0x14AC
#define REG_BF0_TIME_SETTING_V1                              0x2428
#define REG_BF1_TIME_SETTING_V1                              0x242C
#define REG_BF_TIMEOUT_EN_V1                                 0x2430
#define REG_MACID_RELEASE0_V1                                0x2434
#define REG_MACID_RELEASE1_V1                                0x2438
#define REG_MACID_RELEASE2_V1                                0x243C
#define REG_MACID_RELEASE3_V1                                0x2440
#define REG_MACID_RELEASE_SETTING_V1                         0x2444
#define REG_FAST_EDCA_VOVI_SETTING_V1                        0x2448
#define REG_FAST_EDCA_BEBK_SETTING_V1                        0x244C
#define REG_R_MACID_RELEASE_SUCCESS_0_V1                     0x2460
#define REG_R_MACID_RELEASE_SUCCESS_1_V1                     0x2464
#define REG_R_MACID_RELEASE_SUCCESS_2_V1                     0x2468
#define REG_R_MACID_RELEASE_SUCCESS_3_V1                     0x246C
#define REG_R_MACID_RELEASE_SUCCESS_CLEAR_OFFSET_V1          0x247C
#define REG_NAN_INFO0                                        0x2480
#define REG_NAN_INFO1                                        0x2484
#define REG_NAN_INFO2                                        0x2488
#define REG_NAN_INFO3                                        0x248C
#define REG_NAN_INFO4                                        0x2490
#define REG_NAN_INFO5                                        0x2494
#define REG_NAN_INFO6                                        0x2498
#define REG_NAN_INFO7                                        0x249C
#define REG_NAN_INFO8                                        0x24A0
#define REG_NAN_INFO9                                        0x24A4
#define REG_CHNL_INFO_CTRL_V1                                0x24D0
#define REG_CHNL_IDLE_TIME_V1                                0x24D4
#define REG_CHNL_BUSY_TIME_V1                                0x24D8
#define REG_SWPS_CTRL_V1                                     0x24F4
#define REG_SWPS_PKT_TH_V1                                   0x24F6
#define REG_SWPS_TIME_TH_V1                                  0x24F8
#define REG_MACID_SWPS_EN_V1                                 0x24FC

/** @} */


/* AUTO_GEN_END */

/* MANUAL_GEN_START */


#endif