#ifndef _RL6955_REG_PAGE5_ON_H_
#define _RL6955_REG_PAGE5_ON_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE5_ON
  * @brief REG_PAGE5_ON driver modules
  * @{
  */




/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE5_ON_Register_Definitions REG_PAGE5_ON Register Definitions
  * @{
  */

/** @defgroup REG_EDCA_VO_PARAM
  * @brief
  * @{
  */
#define BIT_MASK_TXOPLIMIT_VO   ((u32)0x000007FF << 16)           /*!< R/W 0x2f  TXOP Limit An unsigned integer in units of 32 microseconds. Value of zero indicates that a single MSDU or MMPDU in addition to a protection frame exchange can be transmitted at any rate. Default: BK = 0h; BE = 0h; VI = 5Eh; VO = 2Fh.*/
#define BIT_TXOPLIMIT_VO(x)     (((u32)((x) & 0x000007FF) << 16))
#define BIT_GET_TXOPLIMIT_VO(x) ((u32)(((x >> 16) & 0x000007FF)))
#define BIT_MASK_CW_VO          ((u32)0x000000FF << 8)            /*!< R/W 0x32  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h.*/
#define BIT_CW_VO(x)            (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_CW_VO(x)        ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_AIFS_VO        ((u32)0x000000FF << 0)            /*!< R/W 0x24  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch.*/
#define BIT_AIFS_VO(x)          (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_AIFS_VO(x)      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_EDCA_VI_PARAM
  * @brief
  * @{
  */
#define BIT_MASK_TXOPLIMIT_VI   ((u32)0x000007FF << 16)           /*!< R/W 0x5e  TXOP Limit An unsigned integer in units of 32 microseconds. Value of zero indicates that a single MSDU or MMPDU in addition to a protection frame exchange can be transmitted at any rate. Default: BK = 0h; BE = 0h; VI = 5Eh; VO = 2Fh.*/
#define BIT_TXOPLIMIT_VI(x)     (((u32)((x) & 0x000007FF) << 16))
#define BIT_GET_TXOPLIMIT_VI(x) ((u32)(((x >> 16) & 0x000007FF)))
#define BIT_MASK_CW_VI          ((u32)0x000000FF << 8)            /*!< R/W 0x43  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h.*/
#define BIT_CW_VI(x)            (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_CW_VI(x)        ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_AIFS_VI        ((u32)0x000000FF << 0)            /*!< R/W 0x26  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch.*/
#define BIT_AIFS_VI(x)          (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_AIFS_VI(x)      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_EDCA_BE_PARAM
  * @brief
  * @{
  */
#define BIT_MASK_TXOPLIMIT_BE   ((u32)0x000007FF << 16)           /*!< R/W 0x00  TXOP Limit An unsigned integer in units of 32 microseconds. Value of zero indicates that a single MSDU or MMPDU in addition to a protection frame exchange can be transmitted at any rate. Default: BK = 0h; BE = 0h; VI = 5Eh; VO = 2Fh.*/
#define BIT_TXOPLIMIT_BE(x)     (((u32)((x) & 0x000007FF) << 16))
#define BIT_GET_TXOPLIMIT_BE(x) ((u32)(((x >> 16) & 0x000007FF)))
#define BIT_MASK_CW_BE          ((u32)0x000000FF << 8)            /*!< R/W 0xa4  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h.*/
#define BIT_CW_BE(x)            (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_CW_BE(x)        ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_AIFS_BE        ((u32)0x000000FF << 0)            /*!< R/W 0x2b  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch.*/
#define BIT_AIFS_BE(x)          (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_AIFS_BE(x)      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_EDCA_BK_PARAM
  * @brief
  * @{
  */
#define BIT_MASK_TXOPLIMIT_BK   ((u32)0x000007FF << 16)           /*!< R/W 0x00  TXOP Limit An unsigned integer in units of 32 microseconds. Value of zero indicates that a single MSDU or MMPDU in addition to a protection frame exchange can be transmitted at any rate. Default: BK = 0h; BE = 0h; VI = 5Eh; VO = 2Fh.*/
#define BIT_TXOPLIMIT_BK(x)     (((u32)((x) & 0x000007FF) << 16))
#define BIT_GET_TXOPLIMIT_BK(x) ((u32)(((x >> 16) & 0x000007FF)))
#define BIT_MASK_CW_BK          ((u32)0x000000FF << 8)            /*!< R/W 0xa5  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h.*/
#define BIT_CW_BK(x)            (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_CW_BK(x)        ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_AIFS_BK        ((u32)0x000000FF << 0)            /*!< R/W 0x49  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch.*/
#define BIT_AIFS_BK(x)          (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_AIFS_BK(x)      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BCN_MGQ_PARAM
  * @brief
  * @{
  */
#define BIT_MASK_MGQ_CW      ((u32)0x000000FF << 24)           /*!< R/W 0x32  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h.*/
#define BIT_MGQ_CW(x)        (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_MGQ_CW(x)    ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_MGQ_AIFS    ((u32)0x000000FF << 16)           /*!< R/W 0x24  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch*/
#define BIT_MGQ_AIFS(x)      (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MGQ_AIFS(x)  ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_BCNCW_MAX   ((u32)0x0000000F << 12)           /*!< R/W 0x4  Beacon Contention Window MAX Defines the contention window value for back off before transmitting beacon frame. This field is set to 0 in AP mode to indicate no back off window. In ad hoc mode, its default value is 6. 26-1 = 63 time slots.*/
#define BIT_BCNCW_MAX(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_BCNCW_MAX(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_BCNCW_MIN   ((u32)0x0000000F << 8)            /*!< R/W 0x4  Beacon Contention Window Defines the contention window value for back off before transmitting beacon frame. This field is set to 0 in AP mode to indicate no back off window. In ad hoc mode, its default value is 6. 26-1 = 63 time slots.*/
#define BIT_BCNCW_MIN(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_BCNCW_MIN(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_BCNIFS      ((u32)0x000000FF << 0)            /*!< R/W 0x13  Beacon Interframe Space In units of microseconds, this register defines the medium idle time required before transmitting beacon (AP mode) or entering random back off window.*/
#define BIT_BCNIFS(x)        (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_BCNIFS(x)    ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TX_QUEUE_CTRL
  * @brief
  * @{
  */
#define BIT_DISCW              ((u32)0x00000001 << 31)           /*!< R/W 0x0  When this bit is set, disable CW.*/
#define BIT_EN_BKF_CLR_TXREQ   ((u32)0x00000001 << 30)           /*!< R/W 0x1  when gen tx command done, while will backoff is invalid, then tx command will be cleared*/
#define BIT_DIS_TXREQ_CLR_HGQ  ((u32)0x00000001 << 29)           /*!< R/W 0x0  1: if this queue can't own channel ,txcmd will be cleared 0:Only TX_finish can clear txreq*/
#define BIT_DIS_TXREQ_CLR_MGQ  ((u32)0x00000001 << 28)           /*!< R/W 0x0  1: if this queue can't own channel ,txcmd will be cleared 0:Only TX_finish can clear txreq*/
#define BIT_DIS_TXREQ_CLR_BK   ((u32)0x00000001 << 27)           /*!< R/W 0x0  0: if this queue can't own channel ,txcmd will be cleared 1:Only TX_finish can clear txreq*/
#define BIT_DIS_TXREQ_CLR_BE   ((u32)0x00000001 << 26)           /*!< R/W 0x0  0: if this queue can't own channel ,txcmd will be cleared 1:Only TX_finish can clear txreq*/
#define BIT_DIS_TXREQ_CLR_VI   ((u32)0x00000001 << 25)           /*!< R/W 0x0  0: if this queue can't own channel ,txcmd will be cleared 1:Only TX_finish can clear txreq*/
#define BIT_DIS_TXREQ_CLR_VO   ((u32)0x00000001 << 24)           /*!< R/W 0x0  0: if this queue can't own channel ,txcmd will be cleared 1:Only TX_finish can clear txreq*/
#define BIT_MAC_STOPRDQ        ((u32)0x00000001 << 23)           /*!< R/W 0x0  Stop BCNQ Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_MAC_STOPEVTQ       ((u32)0x00000001 << 22)           /*!< R/W 0x0  Stop BCNQ Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_MAC_STOPBCNQ       ((u32)0x00000001 << 21)           /*!< R/W 0x0  Stop BCNQ Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_MAC_STOPHGQ        ((u32)0x00000001 << 20)           /*!< R/W 0x0  Stop High Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_MAC_STOPMGQ        ((u32)0x00000001 << 19)           /*!< R/W 0x0  Stop Management Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_MAC_STOPBK         ((u32)0x00000001 << 18)           /*!< R/W 0x0  Stop BK Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_MAC_STOPBE         ((u32)0x00000001 << 17)           /*!< R/W 0x0  Stop BE Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_MAC_STOPVI         ((u32)0x00000001 << 16)           /*!< R/W 0x0  Stop VI Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_MAC_STOPVO         ((u32)0x00000001 << 15)           /*!< R/W 0x0  Stop VO Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_MASK_TXNAVMASK     ((u32)0x0000000F << 11)           /*!< R/W 0xF  1: Queue BKF must wait TX Nav finished  0: Queue not need wait*/
#define BIT_TXNAVMASK(x)       (((u32)((x) & 0x0000000F) << 11))
#define BIT_GET_TXNAVMASK(x)   ((u32)(((x >> 11) & 0x0000000F)))
#define BIT_EN_NAVEND_RST_TXOP ((u32)0x00000001 << 10)           /*!< R/W 0x0  When set this bit, TXOP will be reset while NAV end.*/
#define BIT_DIS_TXOP_CFEND     ((u32)0x00000001 << 9)            /*!< R/W 0x0  Disable TXOP_CFE function*/
#define BIT_EN_TBTT_OVER_BT    ((u32)0x00000001 << 8)            /*!< R/W 0x0  1: Enable Beacon Tx at TBTT if BT_CCA is enabled 0: Disable*/
#define BIT_DIS_TXOVER_BCN     ((u32)0x00000001 << 7)            /*!< R/W 0x0  1: Tx Packet with ignoring Beacon Area time 0: Disable*/
#define BIT_DIS_BCN_DIS_CTN    ((u32)0x00000001 << 6)            /*!< R/W 0x1  Disable the Beacon queue disable contention,when set to 0 enable the force beacon function.*/
#define BIT_EN_BCNERR_INCCA    ((u32)0x00000001 << 5)            /*!< R/W 0x0  eneble force tx becon ignore CCA in disable contention area*/
#define BIT_EN_BCNERR_INEDCCA  ((u32)0x00000001 << 4)            /*!< R/W 0x0  eneble force tx becon ignore EDCCA in disable contention area*/
#define BIT_EN_MGQ_INTXOP      ((u32)0x00000001 << 3)            /*!< R/W 0x1  When this bit is set, MGTQ may sent packets by using ACQ TXOP.*/
#define BIT_EN_MGQ_INRTSMF     ((u32)0x00000001 << 2)            /*!< R/W 0x1  When this bit is set, MTGQ will be TX, not wait until RTS or MF transaction finished.*/
#define BIT_EN_HGQ_INRTSMF     ((u32)0x00000001 << 1)            /*!< R/W 0x1  When this bit is set, High Q will be TX, not wait until RTS or MF transaction finished.*/
#define BIT_EN_BCNQ_INRTSMF    ((u32)0x00000001 << 0)            /*!< R/W 0x1  When this bit is set, BCNQ will be TX, not wait until RTS or MF transaction finished.*/
/** @} */

/** @defgroup REG_CCA_EDCCA_FILTER
  * @brief
  * @{
  */
#define BIT_MASK_PIFS              ((u32)0x000000FF << 24)           /*!< R/W 0x1c  PIFS time. It is only used in AP mode and in units of us.*/
#define BIT_PIFS(x)                (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_PIFS(x)            ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_EN_CW_TIMER_STAT       ((u32)0x00000001 << 23)           /*!< R/W 0x0  1: enable contention time statistic of ACQ*/
#define BIT_EN_CW_TIMER_TXCLR      ((u32)0x00000001 << 22)           /*!< R/W 0x0  1: clear cw timer when any queue tx 0: don't clear cw timer when other queue tx*/
#define BIT_EN_FILTER_CCA          ((u32)0x00000001 << 16)           /*!< R/W 0x0  Enable CCA filter threshold*/
#define BIT_MASK_CCA_FILTER_THRS   ((u32)0x000000FF << 8)            /*!< R/W 0xA  If PHY_CCA signal width is bigger than this threshold, this PHY_CCA signal is valid for MAC. Unit: us*/
#define BIT_CCA_FILTER_THRS(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_CCA_FILTER_THRS(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_EDCCA_THRS        ((u32)0x000000FF << 0)            /*!< R/W 0x8F  EDCCA threshold value, edcca over this threshold will cause bkf_rst Bit[7]: PHY_EDCCA為1時,當timer timeout時擋住TX Bit[6:0]: timer (單位:32us)*/
#define BIT_EDCCA_THRS(x)          (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_EDCCA_THRS(x)      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BK_TBTT_AREA_CTRL
  * @brief
  * @{
  */
#define BIT_EN_SIFS_BK                      ((u32)0x00000001 << 30)           /*!< R/W 0x1  SIFS Break Check Criteria enable for AMPDU aggregation, for normal AGGR case*/
#define BIT_MASK_TBTT_CTN_AREA              ((u32)0x0000003F << 24)           /*!< R/W 0x30  TBTT contention area,Time unit is 128us,for PORT 1 / 2*/
#define BIT_TBTT_CTN_AREA(x)                (((u32)((x) & 0x0000003F) << 24))
#define BIT_GET_TBTT_CTN_AREA(x)            ((u32)(((x >> 24) & 0x0000003F)))
#define BIT_EN_TXOP_SIFS_BK                 ((u32)0x00000001 << 23)           /*!< R/W 0x1  SIFS Break Check Criteria enable for AMPDU aggregation, VALID when TXOP or RTS HOLD*/
#define BIT_TXOP_FAIL_BREAK                 ((u32)0x00000001 << 22)           /*!< R/W 0x0  1: if tx pkt fail in txop, then tx cfend to end txop*/
#define BIT_TBTT_AREA_BLK_4AC               ((u32)0x00000001 << 21)           /*!< R/W 0x1  When set this bit, 4AC backoff is disabled on TBTT setup period*/
#define BIT_EN_TBTT_AREA_FOR_BB             ((u32)0x00000001 << 20)           /*!< R/W 0x0  enable notify bb that mac p0 is in tbtt area*/
#define BIT_MASK_TBTT_PROHIBIT_HOLD         ((u32)0x00000FFF << 8)            /*!< R/W 0xc8  TBTT_prohibit_hold time for AP mode, unit is 32 us*/
#define BIT_TBTT_PROHIBIT_HOLD(x)           (((u32)((x) & 0x00000FFF) << 8))
#define BIT_GET_TBTT_PROHIBIT_HOLD(x)       ((u32)(((x >> 8) & 0x00000FFF)))
#define BIT_MASK_TBTT_PROHIBIT_HOLD_INFRA   ((u32)0x0000000F << 4)            /*!< R/W 0x01  TBTT_prohibit_hold time for infrastructure mode , unit is 2 ms*/
#define BIT_TBTT_PROHIBIT_HOLD_INFRA(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_TBTT_PROHIBIT_HOLD_INFRA(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_TBTT_PROHIBIT_SETUP        ((u32)0x0000000F << 0)            /*!< R/W 0x02  TBTT_prohibit_setup, unit is 32us; If en nan-CG, this value should be set to 0x06.*/
#define BIT_TBTT_PROHIBIT_SETUP(x)          (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_TBTT_PROHIBIT_SETUP(x)      ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_TXOP_PRE_BKF
  * @brief
  * @{
  */
#define BIT_NAV_END_TXOP        ((u32)0x00000001 << 31)           /*!< R/W 0x0  1: In txop mode, Nav protect all txop  0: In txop mode, Nav protect to next pkt*/
#define BIT_NOPKT_END_RTSMF     ((u32)0x00000001 << 30)           /*!< R/W 0x1  1: enable exit rts hold mode when there is no corresponding ac pkt to tx*/
#define BIT_RTS_NAV_TXOP        ((u32)0x00000001 << 29)           /*!< R/W 0x0  enable RTS NAV protect all txop*/
#define BIT_NOT_CROSS_TXOP      ((u32)0x00000001 << 28)           /*!< R/W 0x0  1:tx pkt cross tbtt is prohibited 0:tx pkt cross tbtt is permitted*/
#define BIT_NAV_BLK_HGQ         ((u32)0x00000001 << 27)           /*!< R/W 0x0  rxnav block HGQ*/
#define BIT_NAV_BLK_MGQ         ((u32)0x00000001 << 26)           /*!< R/W 0x0  rxnav block MGQ*/
#define BIT_MASK_PRE_BKF_TIME   ((u32)0x000000FF << 16)           /*!< R/W 0x0f  when bkf timer count down this value, sel queue and gen txcmd will start. Unit: 1us*/
#define BIT_PRE_BKF_TIME(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_PRE_BKF_TIME(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_NAV_NXT_TIME   ((u32)0x000000FF << 8)            /*!< R/W 0x40  In TXOP mode ,NAV setting which protects next packets*/
#define BIT_NAV_NXT_TIME(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_NAV_NXT_TIME(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_TXOP_MIN       ((u32)0x000000FF << 0)            /*!< R/W 0x0f  if txop counter is more than this value, than tx pkt is considered not cross tbtt. Unit: 1us*/
#define BIT_TXOP_MIN(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_TXOP_MIN(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TSFT_BCN_P0_P1_CTRL
  * @brief
  * @{
  */
#define BIT_SCHEDULER_RST           ((u32)0x00000001 << 31)           /*!< WA0 0x0  Write this bit reset scheduler, ioreg_txfail*/
#define BIT_BYPASS_ADJ_TBTT_AREA    ((u32)0x00000001 << 30)           /*!< R/W 0x0  0: Fixed an issue where tbtt_area kept pulling higher caused by tbtt_int miss  1: follow the original practice*/
#define BIT_EN_FREECNT              ((u32)0x00000001 << 25)           /*!< R/W 0x0  enable freerun tsft*/
#define BIT_RESET_FREECNT_P         ((u32)0x00000001 << 24)           /*!< WA0 0x0  reset pulse of freerun tsft*/
#define BIT_EN_MULTI_BCN            ((u32)0x00000001 << 20)           /*!< R/W 0x1  enable multiple beacons of port0~port2*/
#define BIT_MASK_MULTI_BCN_CS       ((u32)0x0000000F << 16)           /*!< RO 0x0  indicate which port is tx beacon*/
#define BIT_MULTI_BCN_CS(x)         (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MULTI_BCN_CS(x)     ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_EN_AUTO_MASK_RXPRSP_UPD ((u32)0x00000001 << 15)           /*!< R/W 0x1  valid when BIT_EN_RXPRSP_UPD = 1 1: auto disable RXPRSP's tsft update when rx probe response frame during bcn_early to tbtt(for STA mode - P0)*/
#define BIT_EN_RXPRSP_UPD           ((u32)0x00000001 << 14)           /*!< R/W 0x1  1: enable update tsft when RX probe response frame. (for STA mode - P0)*/
#define BIT_P1_AUTO_SYNC_TSFT0_EN   ((u32)0x00000001 << 13)           /*!< R/W 0x1  when P0 + P1 is concurrent mode, need to assert 1: sync P1's TSFT = P0's TSFT + TSFTF_SYN_OFFSET each time 0: P1's TSFT = P0's TSFT*/
#define BIT_P1_DIS_BCN              ((u32)0x00000001 << 11)           /*!< R/W 0x0  set 1 to mask the beacon early interrupt of port1*/
#define BIT_P1_EN_BCNQ              ((u32)0x00000001 << 8)            /*!< R/W 0x0  When this bit is set, TSF and other beacon related functions are then enabled. 0x700(MACID1)的enable开关*/
#define BIT_P0_TSFT_EN              ((u32)0x00000001 << 5)            /*!< R/W 0x0  1: enable P0 TSFT counter, when NAN function is disable, P1 used P0 TSFT counter*/
#define BIT_P0_TSFT_RST             ((u32)0x00000001 << 4)            /*!< WA0 0x0  write this bit, bcn0 tsft will auto reset, reset to 1*/
#define BIT_P0_DIS_BCN              ((u32)0x00000001 << 3)            /*!< R/W 0x0  set 1 to mask the beacon early interrupt of port0*/
#define BIT_P0_DIS_RX_BSSID_FIT     ((u32)0x00000001 << 2)            /*!< R/W 0x0  0:HW will handle rx_beacon 1:HW will ignore rx_beacon_pk*/
#define BIT_P0_DIS_TSF_UPT          ((u32)0x00000001 << 1)            /*!< R/W 0x1  When set, disable port 0 TSF update when beacon frames or probe response frames are received.*/
#define BIT_P0_EN_BCNQ              ((u32)0x00000001 << 0)            /*!< R/W 0x0  enable beacon function. When this bit is set, TSF and other beacon related functions are then enabled. 0x610(MACID)的enable开关*/
/** @} */

/** @defgroup REG_PORT_BCN_SPACE
  * @brief
  * @{
  */
#define BIT_MASK_BCNSPACE_P1   ((u32)0x00000FFF << 16)           /*!< R/W 0x64  Unit is ms. the beacon space of port1*/
#define BIT_BCNSPACE_P1(x)     (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_BCNSPACE_P1(x) ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_BCNSPACE_P0   ((u32)0x00000FFF << 0)            /*!< R/W 0x64  Unit is ms. the beacon space of port0*/
#define BIT_BCNSPACE_P0(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_BCNSPACE_P0(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_P0_BCN_ERLY_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_ELY_BCNINT_CNT_P0   ((u32)0x0000007F << 24)           /*!< R/WOPD 0x7f  Be used in multiple BCNIVL early INT. When this counter =1, multiple BCNIVL early INT will be triggered.*/
#define BIT_ELY_BCNINT_CNT_P0(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_ELY_BCNINT_CNT_P0(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_ELY_IGNORE_LSB           ((u32)0x00000001 << 14)           /*!< R/W 0x1  1:add1ms, add128us, add32us only check tsft[10], tsft[7], tsft[5], ignore LSB 0: add1ms, add128us, add32us check tsft[9:0], tsft[6:0], tsft[4:0] when active*/
#define BIT_MASK_ELY_32US_P0         ((u32)0x0000003F << 8)            /*!< R/W 0x0  the BCN EARLY interrupt find tune with unit 32us. The Total Early time of BCN early interrupt is the ERLYINTTIM x 1ms - EARLY_32us x 32us.*/
#define BIT_ELY_32US_P0(x)           (((u32)((x) & 0x0000003F) << 8))
#define BIT_GET_ELY_32US_P0(x)       ((u32)(((x >> 8) & 0x0000003F)))
#define BIT_MASK_ERLYINTTIM_P0       ((u32)0x000000FF << 0)            /*!< R/W 0x05  Time to send interrupt to notify driver to change beacon content. Time unit is TU. It is used to wake up early at DriverEarlyTime*/
#define BIT_ERLYINTTIM_P0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_ERLYINTTIM_P0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_P1_BCN_ERLY_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_ELY_32US_P1     ((u32)0x0000003F << 8)           /*!< R/W 0x0  the BCN EARLY interrupt find tune with unit 32us. The Total Early time of BCN early interrupt is the ERLYINTTIM x 1ms - EARLY_32us x 32us.*/
#define BIT_ELY_32US_P1(x)       (((u32)((x) & 0x0000003F) << 8))
#define BIT_GET_ELY_32US_P1(x)   ((u32)(((x >> 8) & 0x0000003F)))
#define BIT_MASK_ERLYINTTIM_P1   ((u32)0x000000FF << 0)           /*!< R/W 0x05  Time to send interrupt to notify driver to change beacon content. Time unit is TU. It is used to wake up early at DriverEarlyTime*/
#define BIT_ERLYINTTIM_P1(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_ERLYINTTIM_P1(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RXBCN_DELAY_TXPAUSE
  * @brief
  * @{
  */
#define BIT_MASK_OFDM_RXTSF_OFFSET   ((u32)0x00000FFF << 20)           /*!< R/W 0x0F  The Datapath of  OFDM RX_tsf, unit: us*/
#define BIT_OFDM_RXTSF_OFFSET(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_OFDM_RXTSF_OFFSET(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_CCK_RXTSF_OFFSET    ((u32)0x00000FFF << 8)            /*!< R/W 0x0F  The Datapath of  CCK RX_tsf, unit: us*/
#define BIT_CCK_RXTSF_OFFSET(x)      (((u32)((x) & 0x00000FFF) << 8))
#define BIT_GET_CCK_RXTSF_OFFSET(x)  ((u32)(((x >> 8) & 0x00000FFF)))
#define BIT_MASK_RXTRIG_DELAY        ((u32)0x000000FF << 0)            /*!< R/W 0x0  add compensation of RX trigger's TSFT. Unit: us*/
#define BIT_RXTRIG_DELAY(x)          (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_RXTRIG_DELAY(x)      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BCNDROP_TIME
  * @brief
  * @{
  */
#define BIT_MASK_CMD_TIMER                  ((u32)0x000000FF << 16)           /*!< R/W 0xFF  When 40M/80M TX CMD ready and secondary_CCA_20/secondary_CCA_40 set for this period, then the TX CMD will be cleared.  TU: 1us*/
#define BIT_CMD_TIMER(x)                    (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_CMD_TIMER(x)                ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_HGQ_EMPTY_TIMEOUT_PERIOD   ((u32)0x000000FF << 8)            /*!< R/W 0x10  When hgq empty for this period, close atim window. And this will block hgq dma for pcie, unless 0x524[12] set enable. TU: 32us*/
#define BIT_HGQ_EMPTY_TIMEOUT_PERIOD(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_HGQ_EMPTY_TIMEOUT_PERIOD(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_BCN_DROP_EN                     ((u32)0x00000001 << 7)            /*!< R/W 0x0  enable beacon drop function*/
#define BIT_MASK_BCN_DROP_IVL               ((u32)0x0000007F << 0)            /*!< R/W 0x0  indicate the timeout of beacon drop*/
#define BIT_BCN_DROP_IVL(x)                 (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_BCN_DROP_IVL(x)             ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_DTIM_ATIM
  * @brief
  * @{
  */
#define BIT_EN_HGQ_NOLIMIT     ((u32)0x00000001 << 31)           /*!< R/W 0x0  enable no limit mode of hgq*/
#define BIT_EN_EVTQ_NOLIMIT    ((u32)0x00000001 << 30)           /*!< R/W 0x0  enable no limit mode of evtq*/
#define BIT_MASK_ATIMWND       ((u32)0x0000003F << 24)           /*!< R/W 0x02  ATIM window width of P1 TX hgq in units of TU.*/
#define BIT_ATIMWND(x)         (((u32)((x) & 0x0000003F) << 24))
#define BIT_GET_ATIMWND(x)     ((u32)(((x >> 24) & 0x0000003F)))
#define BIT_MASK_ATIM_URGENT   ((u32)0x0000003F << 16)           /*!< R/W 0x01  Indicates the time before ATIM Window end. (unit : TU)*/
#define BIT_ATIM_URGENT(x)     (((u32)((x) & 0x0000003F) << 16))
#define BIT_GET_ATIM_URGENT(x) ((u32)(((x >> 16) & 0x0000003F)))
#define BIT_DIS_ATIM           ((u32)0x00000001 << 15)           /*!< R/W 0x0  1: disable assert ATIM*/
#define BIT_DIS_AC_IN_ATIM     ((u32)0x00000001 << 14)           /*!< R/W 0x1  1: Disable AC Queue Packet Tx in ATIM (only valid at Nettype: Adhoc/AP) 0: Enable AC Queue packet Tx in ATIM*/
#define BIT_EN_PTCL_CLR_ATIM   ((u32)0x00000001 << 13)           /*!< R/W 0x1  1: enable fw_clr_sch_atim signal to clear atimon (means this is the last hgq packet)*/
#define BIT_EN_EVTQ_INRTSMF    ((u32)0x00000001 << 9)            /*!< R/W 0x1  When this bit is set, Event Q will be TX, not wait until RTS or MF transaction finished.*/
#define BIT_DTIM_BYPASS        ((u32)0x00000001 << 8)            /*!< R/W 0x0  1: dtim counter will keep 0*/
#define BIT_MASK_DTIM_COUNT    ((u32)0x000000FF << 0)            /*!< R/W 0x0  init dtim value, act on the port of apmode*/
#define BIT_DTIM_COUNT(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_DTIM_COUNT(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_CMD_SEL_EDCA_RANDOM_GEN
  * @brief
  * @{
  */
#define BIT_MASK_TXCMD_SEL   ((u32)0x0000000F << 24)           /*!< R/W 0x1  [HW Debug Info]To select which one TXCMD Segment. For example, 可以在0x5CF[3:0]填 0 or 6  讀取 0x5F8[7:0] : Tx Agg 0x5F9[7:0] : Tx Rate*/
#define BIT_TXCMD_SEL(x)     (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_TXCMD_SEL(x) ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_RAND_SET    ((u32)0x00FFFFFF << 0)            /*!< R/W 0xe21051  Random number generator polynomial*/
#define BIT_RAND_SET(x)      (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_RAND_SET(x)  ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_PTA_TRXBCN_CTRL
  * @brief
  * @{
  */
#define BIT_PTA_RXBCN_PRI_MASK    ((u32)0x00000001 << 31)           /*!< R/W 0x1  */
#define BIT_PTA_RXBCN_EN          ((u32)0x00000001 << 30)           /*!< R/W 0x1  */
#define BIT_MASK_PTA_RXBCN_DUR    ((u32)0x000000FF << 16)           /*!< R/W 0x60  unit: 32us. Period of wl_rxbcn*/
#define BIT_PTA_RXBCN_DUR(x)      (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_PTA_RXBCN_DUR(x)  ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_PTA_RXBCN_TIME   ((u32)0x0000000F << 12)           /*!< R/W 0x6  unit: 32us. Assert wl_rxbcn before TBTT*/
#define BIT_PTA_RXBCN_TIME(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_PTA_RXBCN_TIME(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_PTA_CNT_EN            ((u32)0x00000001 << 9)            /*!< R/W 0x1  When change mode, need to count down before exit BT_MODE*/
#define BIT_MASK_TXPAUSE1         ((u32)0x000001FF << 0)            /*!< R/W 0x0  same as 0x514[23:15], allow FW/DR to control pause jointly*/
#define BIT_TXPAUSE1(x)           (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_TXPAUSE1(x)       ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_PS_TIMER_A
  * @brief
  * @{
  */
#define BIT_MASK_PS_TIMER_A   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  When the TSF matches the content of this register, the PS_TIMER_A_INT interrupt is issued. Unit:16us*/
#define BIT_PS_TIMER_A(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_PS_TIMER_A(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PS_TIMER_B
  * @brief
  * @{
  */
#define BIT_MASK_PS_TIMER_B   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  When the TSF matches the content of this register, the PS_TIMER_B_INT interrupt is issued. Unit:16us*/
#define BIT_PS_TIMER_B(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_PS_TIMER_B(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PS_TIMER_C
  * @brief
  * @{
  */
#define BIT_MASK_PS_TIMER_C   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  When the TSF matches the content of this register, the PS_TIMER_C_INT interrupt is issued. Unit:16us*/
#define BIT_PS_TIMER_C(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_PS_TIMER_C(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PS_TIMER_TWT_CRTL0
  * @brief
  * @{
  */
#define BIT_PS_TIMER_A_EN             ((u32)0x00000001 << 31)           /*!< R/W 0x0  Enable PS_TIMER_A*/
#define BIT_MASK_PS_TIMER_A_TSF_SEL   ((u32)0x00000003 << 29)           /*!< R/W 0x0  0 for port 0, 1 for freerun, 2 for p2 backup*/
#define BIT_PS_TIMER_A_TSF_SEL(x)     (((u32)((x) & 0x00000003) << 29))
#define BIT_GET_PS_TIMER_A_TSF_SEL(x) ((u32)(((x >> 29) & 0x00000003)))
#define BIT_PS_TIMER_B_EN             ((u32)0x00000001 << 28)           /*!< R/W 0x0  Enable PS_TIMER_B*/
#define BIT_MASK_PS_TIMER_B_TSF_SEL   ((u32)0x00000003 << 26)           /*!< R/W 0x0  0 for port 0, 1 for freerun, 2 for p2 backup*/
#define BIT_PS_TIMER_B_TSF_SEL(x)     (((u32)((x) & 0x00000003) << 26))
#define BIT_GET_PS_TIMER_B_TSF_SEL(x) ((u32)(((x >> 26) & 0x00000003)))
#define BIT_PS_TIMER_C_EN             ((u32)0x00000001 << 25)           /*!< R/W 0x0  Enable PS_TIMER_C*/
#define BIT_MASK_PS_TIMER_C_TSF_SEL   ((u32)0x00000003 << 23)           /*!< R/W 0x0  0 for port 0, 1 for freerun, 2 for p2 backup*/
#define BIT_PS_TIMER_C_TSF_SEL(x)     (((u32)((x) & 0x00000003) << 23))
#define BIT_GET_PS_TIMER_C_TSF_SEL(x) ((u32)(((x >> 23) & 0x00000003)))
#define BIT_PS_TIMER_D_EN             ((u32)0x00000001 << 22)           /*!< R/W 0x0  Enable PS_TIMER_D*/
#define BIT_MASK_PS_TIMER_D_TSF_SEL   ((u32)0x00000003 << 20)           /*!< R/W 0x0  0 for port 0, 1 for freerun, 2 for p2 backup*/
#define BIT_PS_TIMER_D_TSF_SEL(x)     (((u32)((x) & 0x00000003) << 20))
#define BIT_GET_PS_TIMER_D_TSF_SEL(x) ((u32)(((x >> 20) & 0x00000003)))
#define BIT_PS_TIMER_E_EN             ((u32)0x00000001 << 19)           /*!< R/W 0x0  Enable PS_TIMER_E*/
#define BIT_MASK_PS_TIMER_E_TSF_SEL   ((u32)0x00000003 << 17)           /*!< R/W 0x0  0 for port 0, 1 for freerun, 2 for p2 backup*/
#define BIT_PS_TIMER_E_TSF_SEL(x)     (((u32)((x) & 0x00000003) << 17))
#define BIT_GET_PS_TIMER_E_TSF_SEL(x) ((u32)(((x >> 17) & 0x00000003)))
#define BIT_MASK_PS_ELY_TIMER_A       ((u32)0x000000FF << 0)            /*!< R/W 0x0  It is used to wake up early at PS_Timer_A_Early Time.  Time unit is 32us.*/
#define BIT_PS_ELY_TIMER_A(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_PS_ELY_TIMER_A(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RXBCN_TSFT_STATISTIC
  * @brief
  * @{
  */
#define BIT_GET_TSFT_OFFSET_EN        ((u32)0x00000001 << 31)           /*!< R/W 0x0  1: Enable Enable get TSFT offset function*/
#define BIT_UPD_TSFT_EARLY            ((u32)0x00000001 << 30)           /*!< R/W 0x1  0: don't update TSFT when the following scenarios occur: tim_no_hit, |TSFT - rxbcn.timestamp| <= BIT_RXBCN_TSFT_THRES, and r_wait_rxbcn_finish = 1 1: update TSFT*/
#define BIT_MASK_RXBCN_TSFT_THRES     ((u32)0x00001FFF << 16)           /*!< R/W 0x0  used for LPS MAC, if |TSFT - rxbcn.timestamp| > BIT_RXBCN_TSFT_THRES, need to wait fcsok. Else, update TSFT at wmac_rxtsf_rdy (before fcsok) unit is 1us,max is 8ms*/
#define BIT_RXBCN_TSFT_THRES(x)       (((u32)((x) & 0x00001FFF) << 16))
#define BIT_GET_RXBCN_TSFT_THRES(x)   ((u32)(((x >> 16) & 0x00001FFF)))
#define BIT_EN_RXBCN_GT_THRES_CNT     ((u32)0x00000001 << 7)            /*!< R/W 0x0  enable the counter of BIT_RXBCN_GT_THRES_CNT*/
#define BIT_CLR_RXBCN_GT_THRES_CNT    ((u32)0x00000001 << 6)            /*!< WA0 0x0  clear the BIT_RXBCN_GT_THRES_CNT to 0*/
#define BIT_MASK_RXBCN_GT_THRES_CNT   ((u32)0x0000003F << 0)            /*!< RO 0x0  valid when BIT_EN_RXBCN_GT_THRES_CNT = 1.  counter the number of beacon with the |TSFT - rxbcn.timestamp| exceed the threshold*/
#define BIT_RXBCN_GT_THRES_CNT(x)     (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_RXBCN_GT_THRES_CNT(x) ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_TM_CFG
  * @brief
  * @{
  */
#define BIT_MASK_TM_TX_PATH_TIME_OFFSET   ((u32)0x000000FF << 24)           /*!< R/W 0x0  Compensate the time, from PHYTXON rising edge to transmit antenna connector. unit: 1us*/
#define BIT_TM_TX_PATH_TIME_OFFSET(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_TM_TX_PATH_TIME_OFFSET(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_TM_RX_PATH_TIME_OFFSET   ((u32)0x000003FF << 14)           /*!< R/W 0x0  Compensate the time, from receive antenna connector to DATAON rising edge. unit: 1us*/
#define BIT_TM_RX_PATH_TIME_OFFSET(x)     (((u32)((x) & 0x000003FF) << 14))
#define BIT_GET_TM_RX_PATH_TIME_OFFSET(x) ((u32)(((x >> 14) & 0x000003FF)))
#define BIT_MASK_RX_AIR_TIME              ((u32)0x000000FF << 4)            /*!< R/W 0x6  This register sets the time from cca fall to 6us.  unit: 1us. (default:6us)*/
#define BIT_RX_AIR_TIME(x)                (((u32)((x) & 0x000000FF) << 4))
#define BIT_GET_RX_AIR_TIME(x)            ((u32)(((x >> 4) & 0x000000FF)))
#define BIT_TM_TSFT_PORT_SEL              ((u32)0x00000001 << 3)            /*!< R/W 0x0  selected TM timer port 0: port0; 1: freerun*/
#define BIT_RXTM_EN                       ((u32)0x00000001 << 2)            /*!< R/W 0x0  1: HW will parsing rx packet, to find TM frame*/
#define BIT_RXTMREQ_EN                    ((u32)0x00000001 << 1)            /*!< R/W 0x0  1: HW will parsing rx packet, to find TM request frame*/
#define BIT_TM_FUNC_EN                    ((u32)0x00000001 << 0)            /*!< R/W 0x0  1: Enable Timing Measurement function*/
/** @} */

/** @defgroup REG_AX_MUEDCA_VO_PARAM
  * @brief
  * @{
  */
#define BIT_MASK_MUEDCA_VO_PARAM_TIMER   ((u32)0x000007FF << 16)           /*!< R/W 0x00  MU EDCA TIMER, in units of 1ms Note: SPEC: The MU EDCA Timer field (8b) indicates the duration of time, in units of 8 TUs*/
#define BIT_MUEDCA_VO_PARAM_TIMER(x)     (((u32)((x) & 0x000007FF) << 16))
#define BIT_GET_MUEDCA_VO_PARAM_TIMER(x) ((u32)(((x >> 16) & 0x000007FF)))
#define BIT_MASK_MUEDCA_VO_PARAM_CW      ((u32)0x000000FF << 8)            /*!< R/W 0x43  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h.*/
#define BIT_MUEDCA_VO_PARAM_CW(x)        (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MUEDCA_VO_PARAM_CW(x)    ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MUEDCA_VO_PARAM_AIFS    ((u32)0x000000FF << 0)            /*!< R/W 0x1C  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch.*/
#define BIT_MUEDCA_VO_PARAM_AIFS(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MUEDCA_VO_PARAM_AIFS(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_MUEDCA_VI_PARAM
  * @brief
  * @{
  */
#define BIT_MASK_MUEDCA_VI_PARAM_TIMER   ((u32)0x000007FF << 16)           /*!< R/W 0x00  MU EDCA TIMER, in units of 1ms Note: SPEC: The MU EDCA Timer field (8b) indicates the duration of time, in units of 8 TUs*/
#define BIT_MUEDCA_VI_PARAM_TIMER(x)     (((u32)((x) & 0x000007FF) << 16))
#define BIT_GET_MUEDCA_VI_PARAM_TIMER(x) ((u32)(((x >> 16) & 0x000007FF)))
#define BIT_MASK_MUEDCA_VI_PARAM_CW      ((u32)0x000000FF << 8)            /*!< R/W 0x54  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h.*/
#define BIT_MUEDCA_VI_PARAM_CW(x)        (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MUEDCA_VI_PARAM_CW(x)    ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MUEDCA_VI_PARAM_AIFS    ((u32)0x000000FF << 0)            /*!< R/W 0x1C  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch.*/
#define BIT_MUEDCA_VI_PARAM_AIFS(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MUEDCA_VI_PARAM_AIFS(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_MUEDCA_BE_PARAM
  * @brief
  * @{
  */
#define BIT_MASK_MUEDCA_BE_PARAM_TIMER   ((u32)0x000007FF << 16)           /*!< R/W 0x00  MU EDCA TIMER, in units of 1ms Note: SPEC: The MU EDCA Timer field (8b) indicates the duration of time, in units of 8 TUs*/
#define BIT_MUEDCA_BE_PARAM_TIMER(x)     (((u32)((x) & 0x000007FF) << 16))
#define BIT_GET_MUEDCA_BE_PARAM_TIMER(x) ((u32)(((x >> 16) & 0x000007FF)))
#define BIT_MASK_MUEDCA_BE_PARAM_CW      ((u32)0x000000FF << 8)            /*!< R/W 0xA5  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h.*/
#define BIT_MUEDCA_BE_PARAM_CW(x)        (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MUEDCA_BE_PARAM_CW(x)    ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MUEDCA_BE_PARAM_AIFS    ((u32)0x000000FF << 0)            /*!< R/W 0x25  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch.*/
#define BIT_MUEDCA_BE_PARAM_AIFS(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MUEDCA_BE_PARAM_AIFS(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_MUEDCA_BK_PARAM
  * @brief
  * @{
  */
#define BIT_MASK_MUEDCA_BK_PARAM_TIMER   ((u32)0x000007FF << 16)           /*!< R/W 0x00  MU EDCA TIMER, in units of 1ms Note: SPEC: The MU EDCA Timer field (8b) indicates the duration of time, in units of 8 TUs*/
#define BIT_MUEDCA_BK_PARAM_TIMER(x)     (((u32)((x) & 0x000007FF) << 16))
#define BIT_GET_MUEDCA_BK_PARAM_TIMER(x) ((u32)(((x >> 16) & 0x000007FF)))
#define BIT_MASK_MUEDCA_BK_PARAM_CW      ((u32)0x000000FF << 8)            /*!< R/W 0xA5  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h.*/
#define BIT_MUEDCA_BK_PARAM_CW(x)        (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MUEDCA_BK_PARAM_CW(x)    ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MUEDCA_BK_PARAM_AIFS    ((u32)0x000000FF << 0)            /*!< R/W 0x49  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch.*/
#define BIT_MUEDCA_BK_PARAM_AIFS(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MUEDCA_BK_PARAM_AIFS(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_TB_MUEDCA_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_TB_TIMER_CNT_INI   ((u32)0x0000001F << 27)           /*!< R/W 0x14  the initial value of th_timer, unit: us*/
#define BIT_TB_TIMER_CNT_INI(x)     (((u32)((x) & 0x0000001F) << 27))
#define BIT_GET_TB_TIMER_CNT_INI(x) ((u32)(((x >> 27) & 0x0000001F)))
#define BIT_HE_TB_PPDU_ONLY_EN      ((u32)0x00000001 << 26)           /*!< R/W 0x0  asserted if the TWT is trigger-enabled TWT*/
#define BIT_TB_TXPAUSE              ((u32)0x00000001 << 25)           /*!< R/W 0x1  valid if BIT_HE_TB_PPSU_ONLY_EN = 1; select pause edca or not during TWT-SP; default is 1, pause. A TWT requesting STA should not transmit frames to the TWT responding STA outside of negotiated TWT SPs and should not transmit frames that are not contained within HE TB PPDUs to the TWT responding STA within trigger-enabled TWT SPs*/
#define BIT_DIS_UPD_BEAM_CHG        ((u32)0x00000001 << 2)            /*!< R/W 0x1  1: txcmd_beam_change TIE 0 0: first PPDU in TXOP will assert txcmd_beam_change*/
#define BIT_SET_MUEDCATIMER_TF      ((u32)0x00000001 << 1)            /*!< R/W 0x0  1: enable HW updating MUEDCATimer after Tx HE TB PPDU 0: disable HW updating MUEDCATimer after Tx HE TB PPDU*/
#define BIT_MUEDCA_EN               ((u32)0x00000001 << 0)            /*!< R/W 0x1  1: enable HW updating MUEDCATimer 0: disable HW updating MUEDCATimer*/
/** @} */

/** @defgroup REG_CCA_NAV_CHK
  * @brief
  * @{
  */
#define BIT_SR_CTN_CHK_NAV     ((u32)0x00000001 << 11) /*!< R/W 0x1  When BASIC or INTRA NAV > 0  in the AIFS/Backoff before active TX 0: Can backoff, can TX 1: Cannot backoff, cannot TX*/
#define BIT_SR_CTN_CHK_ZGBTCCA ((u32)0x00000001 << 10) /*!< R/W 0x1  When  ~GNT_WL(BT/ZigBee)  assert in the AIFS/Backoff before active TX 0: Can backoff, can TX 1: Cannot backoff, cannot TX*/
#define BIT_SR_CTN_CHK_EDCCA   ((u32)0x00000001 << 9)  /*!< R/W 0x1  When EDCCA assert in the AIFS/Backoff before active TX 0: Can backoff, can TX 1: Cannot backoff, cannot TX*/
#define BIT_SR_CTN_CHK_CCA_S20 ((u32)0x00000001 << 8)  /*!< R/W 0x1  When EDCCA assert in the AIFS/Backoff before active TX 0: Can backoff, can TX 1: Cannot backoff, cannot TX*/
#define BIT_CTN_CHK_INTRA_NAV  ((u32)0x00000001 << 5)  /*!< R/W 0x1  When INTRA NAV > 0  in the AIFS/Backoff before active TX 0: Can backoff, can TX 1: Cannot backoff, cannot TX*/
#define BIT_CTN_CHK_BASIC_NAV  ((u32)0x00000001 << 4)  /*!< R/W 0x1  When BASIC NAV > 0  in the AIFS/Backoff before active TX 0: Can backoff, can TX 1: Cannot backoff, cannot TX*/
#define BIT_CTN_CHK_ZGBTCCA    ((u32)0x00000001 << 3)  /*!< R/W 0x1  When ~GNT_WL(BT/ZigBee) assert in the AIFS/Backoff before active TX 0: Can backoff, can TX 1: Cannot backoff, cannot TX*/
#define BIT_CTN_CHK_EDCCA      ((u32)0x00000001 << 2)  /*!< R/W 0x1  When EDCCA assert in the AIFS/Backoff before active TX 0: Can backoff, can TX 1: Cannot backoff, cannot TX*/
#define BIT_CTN_CHK_CCA_S20    ((u32)0x00000001 << 1)  /*!< R/W 0x1  When SECONDARY_CCA_20 assert in the AIFS/Backoff before active TX 0: Can backoff, can TX 1: Can backoff, cannot TX*/
#define BIT_CTN_CHK_CCA_P20    ((u32)0x00000001 << 0)  /*!< R/W 0x1  When CCA assert in the AIFS/Backoff before active TX 0: Can backoff, can TX 1: Cannot backoff, cannot TX*/
/** @} */

/** @defgroup REG_POF_BCNELY_AGG_TBTT
  * @brief
  * @{
  */
#define BIT_EN_P0_TBTT_CNT             ((u32)0x00000001 << 24)          /*!< R/W 0x0  enable the tbtt counter function.*/
#define BIT_MASK_P0_TBTT_CNT_THRS      ((u32)0x0000003F << 8)           /*!< R/W 0x0  P0's TBTT counter threshold . Valid when  BIT_EN_P0_TBTT_CNT = 1. when tbtt_cnt >= BIT_P0_TBTT_CNT_THRS, assert p0_tbtt_agg_int. UNIT: 16*/
#define BIT_P0_TBTT_CNT_THRS(x)        (((u32)((x) & 0x0000003F) << 8))
#define BIT_GET_P0_TBTT_CNT_THRS(x)    ((u32)(((x >> 8) & 0x0000003F)))
#define BIT_EN_POF_ELY_AGG             ((u32)0x00000001 << 7)           /*!< R/W 0x0  update bcn_ely_agg initial value of P0 to BIT_INI_POF_ELY_AGG_CNT 1: enable 0: disable*/
#define BIT_MASK_INI_POF_ELY_AGG_CNT   ((u32)0x0000001F << 0)           /*!< R/W 0x3  bcn_ely_agg initial value of P0. Valid when BIT_EN_POF_ELY_AGG = 1*/
#define BIT_INI_POF_ELY_AGG_CNT(x)     (((u32)((x) & 0x0000001F) << 0))
#define BIT_GET_INI_POF_ELY_AGG_CNT(x) ((u32)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_LPSOFFLOAD_RXBCN_DIFF_CFG0
  * @brief
  * @{
  */
#define BIT_EN_TSFT_AVG_CAL                  ((u32)0x00000001 << 31)           /*!< R/W 0x0  1: calculate the average value of deltaTSFT(latch hioe_int_chn_on and  cca_up) in specified period*/
#define BIT_EN_BCNELY_LATCH_TSFT             ((u32)0x00000001 << 30)           /*!< R/W 0x0  1: latch TSFT to BIT_TSFT_AT_HIOE_RFON (0x153C) when P0's bcn_early int asserted*/
#define BIT_MASK_TSFT_AVG_CAL_PRD            ((u32)0x0000000F << 24)           /*!< R/W 0x7  2^(BIT_TSFT_AVG_CAL_PERIOD), default is 128 times*/
#define BIT_TSFT_AVG_CAL_PRD(x)              (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_TSFT_AVG_CAL_PRD(x)          ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_TSFT_AVG_GT_THRES_CNT_MAX   ((u32)0x0000000F << 16)           /*!< R/W 0x1  The max times of the BIT_TSFT_AVG_VALUE greater than BIT_TSFT_AVG_THRES, if the BIT_TSFT_AVG_VALUE exceeds the BIT_TSFT_AVG_THRES several times in a row, and the number exceeds the BIT_TSFT_AVG_GT_THRES_CNT_MAX, generate an interrupt*/
#define BIT_TSFT_AVG_GT_THRES_CNT_MAX(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_TSFT_AVG_GT_THRES_CNT_MAX(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_TSFT_AVG_THRES              ((u32)0x0000007F << 0)            /*!< R/W 0x40  The threshold of deltaTSFT(latch hioe_int_chn_on and  cca_up), unit 32us*/
#define BIT_TSFT_AVG_THRES(x)                (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TSFT_AVG_THRES(x)            ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_TSFT_AVG_VALUE
  * @brief
  * @{
  */
#define BIT_MASK_GNT_BT_CNT              ((u32)0x00000FFF << 20)           /*!< R/W 0x64  WIFI TX shall wait settle time when antenna is switched from BT to WIFI/RADAR, if the BT use the same RFAFE as WIFI. Unit: 1us*/
#define BIT_GNT_BT_CNT(x)                (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_GNT_BT_CNT(x)            ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_TSFT_AVG_GT_THRES_CNT   ((u32)0x0000000F << 16)           /*!< RO 0x0  statistic the times of the BIT_TSFT_AVG_VALUE than BIT_TSFT_AVG_THRES*/
#define BIT_TSFT_AVG_GT_THRES_CNT(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_TSFT_AVG_GT_THRES_CNT(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_TSFT_AVG_VALUE          ((u32)0x0000FFFF << 0)            /*!< RO 0x0  the average value of deltaTSFT(latch hioe_int_chn_on and  cca_up) in specified period*/
#define BIT_TSFT_AVG_VALUE(x)            (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_TSFT_AVG_VALUE(x)        ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_NAN_P2_CFG0
  * @brief
  * @{
  */
#define BIT_FCSOK_CHK_BSSID      ((u32)0x00000001 << 28)           /*!< R/W 0x1  1:HW will check bssid when fcsok*/
#define BIT_MASK_BCNSPACE_P2_1   ((u32)0x00000FFF << 16)           /*!< R/W 0x200  Unit is ms. the beacon space of port2 sync beacon. default is 512ms*/
#define BIT_BCNSPACE_P2_1(x)     (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_BCNSPACE_P2_1(x) ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_BCNSPACE_P2_0   ((u32)0x00000FFF << 0)            /*!< R/W 0x64  Unit is ms. the beacon space of port2 disc beacon. default is 100ms*/
#define BIT_BCNSPACE_P2_0(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_BCNSPACE_P2_0(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_NAN_P2_CFG1
  * @brief
  * @{
  */
#define BIT_P2_TSFT_BACKUP_EN        ((u32)0x00000001 << 31)           /*!< R/W 0x0  1:en tsft backup*/
#define BIT_UPD_TSFT_DIS_CHK_TA      ((u32)0x00000001 << 30)           /*!< R/W 0x0  1: don't check TA_FIT when update NAN tsft*/
#define BIT_MASK_ELY_32US_P2         ((u32)0x0000003F << 24)           /*!< R/W 0x0  the BCN EARLY interrupt find tune with unit 32us. The Total Early time of BCN early interrupt is the ERLYINTTIM x 1ms - EARLY_32us x 32us.*/
#define BIT_ELY_32US_P2(x)           (((u32)((x) & 0x0000003F) << 24))
#define BIT_GET_ELY_32US_P2(x)       ((u32)(((x >> 24) & 0x0000003F)))
#define BIT_MASK_ERLYINTTIM_P2       ((u32)0x000000FF << 16)           /*!< R/W 0x05  Time to send interrupt to notify driver to change beacon content. Time unit is TU. It is used to wake up early at DriverEarlyTime*/
#define BIT_ERLYINTTIM_P2(x)         (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_ERLYINTTIM_P2(x)     ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_BCN_OFFSET_5G_NAN   ((u32)0x000000FF << 8)            /*!< R/W 0x80  Unit is ms. the tbtt offset between 2.4G sync beacon and 5G sync bcn. Default is 128ms*/
#define BIT_BCN_OFFSET_5G_NAN(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_BCN_OFFSET_5G_NAN(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_P2_TSFT_AUTO_SYNC_EN     ((u32)0x00000001 << 7)            /*!< R/W 0x1  1: enable HW auto tsft sync, when sync beacon frames are received, auto update RX.timestamp + RX path delay to TSFT_P2_0*/
#define BIT_SW_SYNC_P2_TSFT          ((u32)0x00000001 << 6)            /*!< WA0 0x0  When write this bit, TSFT P2_0 will sync to TSFT P2_1 without TSFTF_SYN_OFFSET, need co-work with BIT_P2_DIS_TSF_UPT = 1*/
#define BIT_P2_TSFT_RST              ((u32)0x00000001 << 5)            /*!< WA0 0x0  write this bit, bcn2 tsft will reset to 1*/
#define BIT_MASK_P2_DIS_BCN          ((u32)0x00000003 << 3)            /*!< R/W 0x0  set 1 to mask the beacon early interrupt of port2 [0]: for NAN disc beacon [1]: for NAN sync beacon*/
#define BIT_P2_DIS_BCN(x)            (((u32)((x) & 0x00000003) << 3))
#define BIT_GET_P2_DIS_BCN(x)        ((u32)(((x >> 3) & 0x00000003)))
#define BIT_P2_DIS_RX_BSSID_FIT      ((u32)0x00000001 << 2)            /*!< R/W 0x0  0:HW will handle rx_beacon 1:HW will ignore rx_beacon_pk*/
#define BIT_P2_DIS_TSF_UPT           ((u32)0x00000001 << 1)            /*!< R/W 0x1  When set, disable clint 2 TSF update when beacon frames or probe response frames are received.*/
#define BIT_P2_EN_BCNQ               ((u32)0x00000001 << 0)            /*!< R/W 0x0  When this bit is set, TSF and other beacon related functions are then enabled. BIT_P2_EN_BCNQ = 1 also means turning on the NAN feature*/
/** @} */

/** @defgroup REG_NAN_CFG
  * @brief
  * @{
  */
#define BIT_MASK_TBTT_HOLD_PREDICT   ((u32)0x0000001F << 27)           /*!< R/W 0x2  the predicted hold time after tbtt for P0 RX beacon, unit is 1ms*/
#define BIT_TBTT_HOLD_PREDICT(x)     (((u32)((x) & 0x0000001F) << 27))
#define BIT_GET_TBTT_HOLD_PREDICT(x) ((u32)(((x >> 27) & 0x0000001F)))
#define BIT_MASK_SYNCBCN_DELAY       ((u32)0x00003FFF << 13)           /*!< R/W 0x168  r_HC * r_SLOTTIME * 8'd40 (unit:us) default: r_HC = 1, r_SLOTTIME = 9, => 360us max is 16ms (DW)*/
#define BIT_SYNCBCN_DELAY(x)         (((u32)((x) & 0x00003FFF) << 13))
#define BIT_GET_SYNCBCN_DELAY(x)     ((u32)(((x >> 13) & 0x00003FFF)))
#define BIT_MASK_NAN_ROLE            ((u32)0x00000003 << 11)           /*!< R/W 0x0  the role of NAN device:  2'b00: master 2'b01: no-master sync 2'b10: no-master no-sync.*/
#define BIT_NAN_ROLE(x)              (((u32)((x) & 0x00000003) << 11))
#define BIT_GET_NAN_ROLE(x)          ((u32)(((x >> 11) & 0x00000003)))
#define BIT_MASK_BCN_PORT_PRI        ((u32)0x00000007 << 8)            /*!< R/W 0x1  the priority of ports  000: no priority 001: port2 sync bcn has higher priority than P0/P1, P2 sync > P0/P1 010: port0 has higher priority than P2 sync bcn, P0 > P2 sync > P1 011: port1 has higher priority than P2 sync bcn, P1 > P2 sync > P0 100: port0 and port1 has higher priority than P2 sync bcn, P0/P1 > P2 sync*/
#define BIT_BCN_PORT_PRI(x)          (((u32)((x) & 0x00000007) << 8))
#define BIT_GET_BCN_PORT_PRI(x)      ((u32)(((x >> 8) & 0x00000007)))
#define BIT_EN_PORT_ROND             ((u32)0x00000001 << 7)            /*!< R/W 0x0  1: enable round-robin of P2 disc beacon and P0/1 beacon*/
#define BIT_TBTT_INT_CLR_P2_BCNREQ   ((u32)0x00000001 << 6)            /*!< R/W 0x1  1: tbtt int can clear bcnely_req when arbitration fail*/
#define BIT_EVTQ_VLD                 ((u32)0x00000001 << 5)            /*!< R/W 0x1  1: enable EVTQ TX*/
#define BIT_EN_5G_NAN                ((u32)0x00000001 << 4)            /*!< R/W 0x0  1: enable 5G NAN mode 0: only 2.4G NAN*/
#define BIT_MASK_EVTQ_EARLY          ((u32)0x0000000F << 0)            /*!< R/W 0x1  the early time of evtq tx window. unit is TU*/
#define BIT_EVTQ_EARLY(x)            (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_EVTQ_EARLY(x)        ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_EDCA_REF_CFG
  * @brief
  * @{
  */
#define BIT_EN_EDCA_REF             ((u32)0x00000001 << 31)          /*!< R/W 0x0  When this bit set 1, enable EDCA REF function*/
#define BIT_EN_RANDOM_SHIFT_TX      ((u32)0x00000001 << 30)          /*!< R/W 0x1  When this bit set 1, enable random shift TX function*/
#define BIT_EN_INTERCOL_EDCA_REF    ((u32)0x00000001 << 29)          /*!< R/W 0x0  When this bit set 1, enable inter-collision edca_ref*/
#define BIT_SCH_CNT_RST             ((u32)0x00000001 << 28)          /*!< WA0 0x0  write "1" to set the BIT_EDCA_REF_STS_CNT to zero*/
#define BIT_MASK_EDCA_REF_STS_CNT   ((u32)0x0000FFFF << 0)           /*!< RO 0x0  */
#define BIT_EDCA_REF_STS_CNT(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_EDCA_REF_STS_CNT(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_PS_TIMER_TWT_CRTL1
  * @brief
  * @{
  */
#define BIT_MASK_PS_ELY_TIMER_E   ((u32)0x000000FF << 24)           /*!< R/W 0x0  It is used to wake up early at PS_Timer_E_Early Time.  Time unit is 32us.*/
#define BIT_PS_ELY_TIMER_E(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_PS_ELY_TIMER_E(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_PS_ELY_TIMER_D   ((u32)0x000000FF << 16)           /*!< R/W 0x0  It is used to wake up early at PS_Timer_D_Early Time.  Time unit is 32us.*/
#define BIT_PS_ELY_TIMER_D(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_PS_ELY_TIMER_D(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_PS_ELY_TIMER_C   ((u32)0x000000FF << 8)            /*!< R/W 0x0  It is used to wake up early at PS_Timer_C_Early Time.  Time unit is 32us.*/
#define BIT_PS_ELY_TIMER_C(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_PS_ELY_TIMER_C(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_PS_ELY_TIMER_B   ((u32)0x000000FF << 0)            /*!< R/W 0x0  It is used to wake up early at PS_Timer_B_Early Time.  Time unit is 32us.*/
#define BIT_PS_ELY_TIMER_B(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_PS_ELY_TIMER_B(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_PS_TIMER_D
  * @brief
  * @{
  */
#define BIT_MASK_PS_TIMER_D   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  When the TSF matches the content of this register, the PS_TIMER_B_INT interrupt is issued. Unit:16us*/
#define BIT_PS_TIMER_D(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_PS_TIMER_D(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PS_TIMER_E
  * @brief
  * @{
  */
#define BIT_MASK_PS_TIMER_E   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  When the TSF matches the content of this register, the PS_TIMER_C_INT interrupt is issued. Unit:16us*/
#define BIT_PS_TIMER_E(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_PS_TIMER_E(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_AUDIO_CFG
  * @brief
  * @{
  */
#define BIT_MASK_PATH_DELAY_NS_CCK    ((u32)0x000003FF << 22)           /*!< R/W 0x0  the NS part of RX CCK1M PATH DELAY*/
#define BIT_PATH_DELAY_NS_CCK(x)      (((u32)((x) & 0x000003FF) << 22))
#define BIT_GET_PATH_DELAY_NS_CCK(x)  ((u32)(((x >> 22) & 0x000003FF)))
#define BIT_MASK_PATH_DELAY_NS_OFDM   ((u32)0x000003FF << 12)           /*!< R/W 0x0  the NS part of RX OFDM6M PATH DELAY*/
#define BIT_PATH_DELAY_NS_OFDM(x)     (((u32)((x) & 0x000003FF) << 12))
#define BIT_GET_PATH_DELAY_NS_OFDM(x) ((u32)(((x >> 12) & 0x000003FF)))
#define BIT_TSFT_DIFF_P0_EN           ((u32)0x00000001 << 9)            /*!< R/W 0x1  1:get tsft difference between local tsft and update value when update tsft*/
#define BIT_NEW_RX_NSCNT_EN           ((u32)0x00000001 << 8)            /*!< R/W 0x0  1: enable the new ns counter of rx 0: follow old ns counter as tx*/
#define BIT_MASK_MAC_CLK_PRD          ((u32)0x000000FF << 0)            /*!< R/W 0x19  set the period of MAC CLK, default 40M - 25ns*/
#define BIT_MAC_CLK_PRD(x)            (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MAC_CLK_PRD(x)        ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_IGNORE_EDCCA_NAV_CFG
  * @brief
  * @{
  */
#define BIT_MASK_IGN_RXNAV_TH       ((u32)0x0000003F << 24)           /*!< R/W 0xf  indicate the threshold of rxnav ignored, unit: 1ms*/
#define BIT_IGN_RXNAV_TH(x)         (((u32)((x) & 0x0000003F) << 24))
#define BIT_GET_IGN_RXNAV_TH(x)     ((u32)(((x >> 24) & 0x0000003F)))
#define BIT_MASK_IGN_RXNAV_TXTIME   ((u32)0x0000001F << 18)           /*!< R/W 0x5  indicate the tx times of ignore rxnav tx*/
#define BIT_IGN_RXNAV_TXTIME(x)     (((u32)((x) & 0x0000001F) << 18))
#define BIT_GET_IGN_RXNAV_TXTIME(x) ((u32)(((x >> 18) & 0x0000001F)))
#define BIT_IGN_RXNAV_TXOK          ((u32)0x00000001 << 17)           /*!< R/W 0x0  1: only de-ignore rxnav when tx ok/drop*/
#define BIT_IGNORE_RXNAV            ((u32)0x00000001 << 16)           /*!< R/W 0x1  1: backoff ignore rxnav when reach threshold*/
#define BIT_MASK_IGN_EDCCA_TH       ((u32)0x0000003F << 8)            /*!< R/W 0xf  indicate the threshold of edcca ignored, unit: 1ms*/
#define BIT_IGN_EDCCA_TH(x)         (((u32)((x) & 0x0000003F) << 8))
#define BIT_GET_IGN_EDCCA_TH(x)     ((u32)(((x >> 8) & 0x0000003F)))
#define BIT_MASK_IGN_EDCCA_TXTIME   ((u32)0x0000001F << 2)            /*!< R/W 0x5  indicate the tx times of ignore edcca tx*/
#define BIT_IGN_EDCCA_TXTIME(x)     (((u32)((x) & 0x0000001F) << 2))
#define BIT_GET_IGN_EDCCA_TXTIME(x) ((u32)(((x >> 2) & 0x0000001F)))
#define BIT_IGN_EDCCA_TXOK          ((u32)0x00000001 << 1)            /*!< R/W 0x0  1: only de-ignore edcca when tx ok/drop*/
#define BIT_IGNORE_EDCCA            ((u32)0x00000001 << 0)            /*!< R/W 0x1  1: backoff ignore edcca when reach threshold*/
/** @} */

/*==========REG_PAGE5_ON Register Address Definition==========*/
#define REG_EDCA_VO_PARAM                       0x500
#define REG_EDCA_VI_PARAM                       0x504
#define REG_EDCA_BE_PARAM                       0x508
#define REG_EDCA_BK_PARAM                       0x50C
#define REG_BCN_MGQ_PARAM                       0x510
#define REG_TX_QUEUE_CTRL                       0x514
#define REG_CCA_EDCCA_FILTER                    0x518
#define REG_BK_TBTT_AREA_CTRL                   0x51C
#define REG_TXOP_PRE_BKF                        0x520
#define REG_TSFT_BCN_P0_P1_CTRL                 0x524
#define REG_PORT_BCN_SPACE                      0x528
#define REG_P0_BCN_ERLY_CTRL                    0x52C
#define REG_P1_BCN_ERLY_CTRL                    0x530
#define REG_RXBCN_DELAY_TXPAUSE                 0x534
#define REG_BCNDROP_TIME                        0x538
#define REG_DTIM_ATIM                           0x53C
#define REG_CMD_SEL_EDCA_RANDOM_GEN             0x540
#define REG_PTA_TRXBCN_CTRL                     0x544
#define REG_PS_TIMER_A                          0x548
#define REG_PS_TIMER_B                          0x54C
#define REG_PS_TIMER_C                          0x550
#define REG_PS_TIMER_TWT_CRTL0                  0x554
#define REG_RXBCN_TSFT_STATISTIC                0x558
#define REG_TM_CFG                              0x55C
#define REG_AX_MUEDCA_VO_PARAM                  0x560
#define REG_AX_MUEDCA_VI_PARAM                  0x564
#define REG_AX_MUEDCA_BE_PARAM                  0x568
#define REG_AX_MUEDCA_BK_PARAM                  0x56C
#define REG_AX_TB_MUEDCA_CTRL                   0x570
#define REG_CCA_NAV_CHK                         0x574
#define REG_POF_BCNELY_AGG_TBTT                 0x578
#define REG_LPSOFFLOAD_RXBCN_DIFF_CFG0          0x57C
#define REG_TSFT_AVG_VALUE                      0x580
#define REG_NAN_P2_CFG0                         0x584
#define REG_NAN_P2_CFG1                         0x588
#define REG_NAN_CFG                             0x58C
#define REG_EDCA_REF_CFG                        0x590
#define REG_PS_TIMER_TWT_CRTL1                  0x594
#define REG_PS_TIMER_D                          0x598
#define REG_PS_TIMER_E                          0x59C
#define REG_AUDIO_CFG                           0x1500
#define REG_IGNORE_EDCCA_NAV_CFG                0x1504

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