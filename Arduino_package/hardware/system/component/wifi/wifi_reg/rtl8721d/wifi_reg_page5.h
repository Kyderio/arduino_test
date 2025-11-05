#ifndef _project_name_REG_PAGE5_H_
#define _project_name_REG_PAGE5_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE5
  * @brief REG_PAGE5 driver modules
  * @{
  */


/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE5_Register_Definitions REG_PAGE5 Register Definitions
  * @{
  */

/** @defgroup REG_EDCA_VO_PARAM
  * @brief
  * @{
  */
#define BIT_MASK_TXOPLIMIT   ((u32)0x000007FF << 16)           /*!< R/W 0x2f  TXOP Limit An unsigned integer in units of 32 microseconds. Value of zero indicates that a single MSDU or MMPDU in addition to a protection frame exchange can be transmitted at any rate. Default: BK = 0h; BE = 0h; VI = 5Eh; VO = 2Fh.*/
#define BIT_TXOPLIMIT(x)     (((u32)((x) & 0x000007FF) << 16))
#define BIT_GET_TXOPLIMIT(x) ((u32)(((x >> 16) & 0x000007FF)))
#define BIT_MASK_CW          ((u32)0x000000FF << 8)            /*!< R/W 0x32  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h.*/
#define BIT_CW(x)            (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_CW(x)        ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_AIFS        ((u32)0x000000FF << 0)            /*!< R/W 0x24  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch.*/
#define BIT_AIFS(x)          (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_AIFS(x)      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_EDCA_VI_PARAM
  * @brief
  * @{
  */
#define BIT_MASK_TXOPLIMIT   ((u32)0x000007FF << 16)           /*!< R/W 0x5e  TXOP Limit An unsigned integer in units of 32 microseconds. Value of zero indicates that a single MSDU or MMPDU in addition to a protection frame exchange can be transmitted at any rate. Default: BK = 0h; BE = 0h; VI = 5Eh; VO = 2Fh.*/
#define BIT_TXOPLIMIT(x)     (((u32)((x) & 0x000007FF) << 16))
#define BIT_GET_TXOPLIMIT(x) ((u32)(((x >> 16) & 0x000007FF)))
#define BIT_MASK_CW          ((u32)0x000000FF << 8)            /*!< R/W 0x43  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h.*/
#define BIT_CW(x)            (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_CW(x)        ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_AIFS        ((u32)0x000000FF << 0)            /*!< R/W 0x26  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch.*/
#define BIT_AIFS(x)          (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_AIFS(x)      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_EDCA_BE_PARAM
  * @brief
  * @{
  */
#define BIT_MASK_TXOPLIMIT   ((u32)0x000007FF << 16)           /*!< R/W 0x00  TXOP Limit An unsigned integer in units of 32 microseconds. Value of zero indicates that a single MSDU or MMPDU in addition to a protection frame exchange can be transmitted at any rate. Default: BK = 0h; BE = 0h; VI = 5Eh; VO = 2Fh.*/
#define BIT_TXOPLIMIT(x)     (((u32)((x) & 0x000007FF) << 16))
#define BIT_GET_TXOPLIMIT(x) ((u32)(((x >> 16) & 0x000007FF)))
#define BIT_MASK_CW          ((u32)0x000000FF << 8)            /*!< R/W 0xa4  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h.*/
#define BIT_CW(x)            (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_CW(x)        ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_AIFS        ((u32)0x000000FF << 0)            /*!< R/W 0x2b  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch.*/
#define BIT_AIFS(x)          (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_AIFS(x)      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_EDCA_BK_PARAM
  * @brief
  * @{
  */
#define BIT_MASK_TXOPLIMIT   ((u32)0x000007FF << 16)           /*!< R/W 0x00  TXOP Limit An unsigned integer in units of 32 microseconds. Value of zero indicates that a single MSDU or MMPDU in addition to a protection frame exchange can be transmitted at any rate. Default: BK = 0h; BE = 0h; VI = 5Eh; VO = 2Fh.*/
#define BIT_TXOPLIMIT(x)     (((u32)((x) & 0x000007FF) << 16))
#define BIT_GET_TXOPLIMIT(x) ((u32)(((x >> 16) & 0x000007FF)))
#define BIT_MASK_CW          ((u32)0x000000FF << 8)            /*!< R/W 0xa5  ECWmin and ECWmax encode the values of Cwmin and Cwmax respectively in an exponent form. Ex: Cwmax = 2^(ECWmax)-1 Default: BK = Ah/5h; BE = Ah/5h; VI = 5h/4h; VO = 4h/3h.*/
#define BIT_CW(x)            (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_CW(x)        ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_AIFS        ((u32)0x000000FF << 0)            /*!< R/W 0x49  Arbitrary Inter frame space In unit of microsecond. AIFS indicates the time a non-AP QSTA should defer before either invoking a backoff or starting a transmission Default: BK = 49h; BE = 25h; VI = 1Ch; VO = 1Ch.*/
#define BIT_AIFS(x)          (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_AIFS(x)      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BCN_CFG_PIFS
  * @brief
  * @{
  */
#define BIT_MASK_BCNCW_MAX   ((u16)0x0000000F << 12)           /*!< R/W 0x4  Beacon Contention Window MAX Defines the contention window value for back off before transmitting beacon frame. This field is set to 0 in AP mode to indicate no back off window. In ad hoc mode, its default value is 6. 26-1 = 63 time slots.*/
#define BIT_BCNCW_MAX(x)     (((u16)((x) & 0x0000000F) << 12))
#define BIT_GET_BCNCW_MAX(x) ((u16)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_BCNCW_MIN   ((u16)0x0000000F << 8)            /*!< R/W 0x4  Beacon Contention Window Defines the contention window value for back off before transmitting beacon frame. This field is set to 0 in AP mode to indicate no back off window. In ad hoc mode, its default value is 6. 26-1 = 63 time slots.*/
#define BIT_BCNCW_MIN(x)     (((u16)((x) & 0x0000000F) << 8))
#define BIT_GET_BCNCW_MIN(x) ((u16)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_BCNIFS      ((u16)0x000000FF << 0)            /*!< R/W 0x13  Beacon Interframe Space In units of microseconds, this register defines the medium idle time required before transmitting beacon (AP mode) or entering random back off window.*/
#define BIT_BCNIFS(x)        (((u16)((x) & 0x000000FF) << 0))
#define BIT_GET_BCNIFS(x)    ((u16)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_PIFS
  * @brief
  * @{
  */
#define BIT_MASK_PIFS   ((u8)0x000000FF << 0)           /*!< R/W 0x1c  PIFS time. It is only used in AP mode and in units of us.*/
#define BIT_PIFS(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_PIFS(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RDG_PIFS
  * @brief
  * @{
  */
#define BIT_MASK_RDG_PIFS   ((u8)0x000000FF << 0)           /*!< R/W 0x28  */
#define BIT_RDG_PIFS(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_RDG_PIFS(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_SIFS
  * @brief
  * @{
  */
#define BIT_MASK_SIFS_OFDM_TRX   ((u32)0x000000FF << 24)           /*!< R/W 0x10  This register sets the SIFS time required in NAV protection period after receiving any immediate response. for example Ack-Data or RTS/CTS-Data. It is in unit of us.*/
#define BIT_SIFS_OFDM_TRX(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_SIFS_OFDM_TRX(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_SIFS_CCK_TRX    ((u32)0x000000FF << 16)           /*!< R/W 0x10  This register sets the SIFS time required in NAV protection period after receiving any immediate response. for example Ack-Data or RTS/CTS-Data. It is in unit of us.*/
#define BIT_SIFS_CCK_TRX(x)      (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_SIFS_CCK_TRX(x)  ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_SIFS_OFDM_CTX   ((u32)0x000000FF << 8)            /*!< R/W 0x10  This register sets the SIFS time required for consecutive TX events for example CTS2S-Data, or broadcast bursting. It is in unit of us.*/
#define BIT_SIFS_OFDM_CTX(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_SIFS_OFDM_CTX(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_SIFS_CCK_CTX    ((u32)0x000000FF << 0)            /*!< R/W 0x10  This register sets the SIFS time required for consecutive TX events for example CTS2S-Data, or broadcast bursting. It is in unit of us.*/
#define BIT_SIFS_CCK_CTX(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_SIFS_CCK_CTX(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TSFTR_SYN_OFFSET
  * @brief
  * @{
  */
#define BIT_MASK_TSFTR_SNC_OFFSET   ((u16)0x0000FFFF << 0)           /*!< R/W 0xfe00  tsft sync. Offset (bcn0 sync to bcn1 offset or bcn1sync to bcn0 offset).  Unit : 32us*/
#define BIT_TSFTR_SNC_OFFSET(x)     (((u16)((x) & 0x0000FFFF) << 0))
#define BIT_GET_TSFTR_SNC_OFFSET(x) ((u16)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_AGGR_BREAK_TIME
  * @brief
  * @{
  */
#define BIT_MASK_AGGR_BK_TIME   ((u8)0x000000FF << 0)           /*!< R/W 0x14  Hw will break aggr. In sifs condition*/
#define BIT_AGGR_BK_TIME(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_AGGR_BK_TIME(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_SLOT
  * @brief
  * @{
  */
#define BIT_MASK_SLOT   ((u16)0x000000FF << 0)           /*!< R/W 0x09  This register sets the slot time value mentioned in 802.11 specification. It is in units of us. Default: 9h.*/
#define BIT_SLOT(x)     (((u16)((x) & 0x000000FF) << 0))
#define BIT_GET_SLOT(x) ((u16)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_NOA_OFF_ERLY_TIME
  * @brief
  * @{
  */
#define BIT_MASK_NOA_OFF_ERLY_TIME   ((u16)0x000000FF << 0)           /*!< R/W 0x5  NOA off early interval, Time unit is TU.*/
#define BIT_NOA_OFF_ERLY_TIME(x)     (((u16)((x) & 0x000000FF) << 0))
#define BIT_GET_NOA_OFF_ERLY_TIME(x) ((u16)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_PS_TIMER_CTRL
  * @brief
  * @{
  */
#define BIT_PS_TIMER_B_EN_V1             ((u8)0x00000001 << 7)           /*!< R/W 0x0  Enable PS_TIMER_B*/
#define BIT_MASK_PS_TIMER_B_TSF_SEL_V1   ((u8)0x00000003 << 4)           /*!< R/W 0x0  0 for port 0, 1 for port1, 2 for port2*/
#define BIT_PS_TIMER_B_TSF_SEL_V1(x)     (((u8)((x) & 0x00000003) << 4))
#define BIT_GET_PS_TIMER_B_TSF_SEL_V1(x) ((u8)(((x >> 4) & 0x00000003)))
#define BIT_PS_TIMER_A_EN_V1             ((u8)0x00000001 << 3)           /*!< R/W 0x0  Enable PS_TIMER_A*/
#define BIT_MASK_PS_TIMER_A_TSF_SEL_V1   ((u8)0x00000003 << 0)           /*!< R/W 0x0  0 for port 0, 1 for port1, 2 for port2*/
#define BIT_PS_TIMER_A_TSF_SEL_V1(x)     (((u8)((x) & 0x00000003) << 0))
#define BIT_GET_PS_TIMER_A_TSF_SEL_V1(x) ((u8)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_TXPAUSE_TXPTCL_DISTXREQ_CTRL
  * @brief
  * @{
  */
#define BIT_DIS_BT_CCA           ((u32)0x00000001 << 31)          /*!< R/W 0x0  Disable BT_CCA*/
#define BIT_DIS_TXREQ_CLR_CPUMGQ ((u32)0x00000001 << 30)          /*!< R/W 0x0  1: if this queue can't own channel ,txcmd will be cleared 0:Only TX_finish can clear txreq*/
#define BIT_DIS_TXREQ_CLR_HI     ((u32)0x00000001 << 29)          /*!< R/W 0x0  0: if this queue can't own channel ,txcmd will be cleared 1:Only TX_finish can clear txreq*/
#define BIT_DIS_TXREQ_CLR_MGQ    ((u32)0x00000001 << 28)          /*!< R/W 0x0  1: if this queue can't own channel ,txcmd will be cleared 0:Only TX_finish can clear txreq*/
#define BIT_DIS_TXREQ_CLR_VO     ((u32)0x00000001 << 27)          /*!< R/W 0x0  0: if this queue can't own channel ,txcmd will be cleared 1:Only TX_finish can clear txreq*/
#define BIT_DIS_TXREQ_CLR_VI     ((u32)0x00000001 << 26)          /*!< R/W 0x0  0: if this queue can't own channel ,txcmd will be cleared 1:Only TX_finish can clear txreq*/
#define BIT_DIS_TXREQ_CLR_BE     ((u32)0x00000001 << 25)          /*!< R/W 0x0  0: if this queue can't own channel ,txcmd will be cleared 1:Only TX_finish can clear txreq*/
#define BIT_DIS_TXREQ_CLR_BK     ((u32)0x00000001 << 24)          /*!< R/W 0x0  0: if this queue can't own channel ,txcmd will be cleared 1:Only TX_finish can clear txreq*/
#define BIT_STOP_CPUMGQ          ((u32)0x00000001 << 23)          /*!< R/W 0x0  Stop CPUMGQ Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_MAC_STOPBCNQ         ((u32)0x00000001 << 22)          /*!< R/W 0x0  Stop BCNQ Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_MAC_STOPHIQ          ((u32)0x00000001 << 21)          /*!< R/W 0x0  Stop High Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_MAC_STOPMGQ          ((u32)0x00000001 << 20)          /*!< R/W 0x0  Stop Management Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_MAC_STOPBK           ((u32)0x00000001 << 19)          /*!< R/W 0x0  Stop BK Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_MAC_STOPBE           ((u32)0x00000001 << 18)          /*!< R/W 0x0  Stop BE Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_MAC_STOPVI           ((u32)0x00000001 << 17)          /*!< R/W 0x0  Stop VI Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_MAC_STOPVO           ((u32)0x00000001 << 16)          /*!< R/W 0x0  Stop VO Queue Write a 1 to this bit via software to immediately stop the transmission of packet from this queue including retry attempts.*/
#define BIT_DIS_EDCCA            ((u32)0x00000001 << 15)          /*!< R /W 0x0  Disable EDCCA function 是否要將PHY_EDCCA 加入到 block TX 的條件式內 0: PHY_EDCCA 可以擋住TX (default) 1: PHY_EDCCA 不可以擋住TX*/
#define BIT_DIS_CCA              ((u32)0x00000001 << 14)          /*!< R/W 0x0  Disable CCA*/
#define BIT_LSIG_TXOP_TXCMD_NAV  ((u32)0x00000001 << 13)          /*!< R/W 0x1  Set LSIG_TXOP from TXCMD_NAV field*/
#define BIT_SIFS_BK_EN           ((u32)0x00000001 << 12)          /*!< R /W 0x1  SIFS Break Check Criteria enable for AMPDU aggregation*/
#define BIT_MASK_TXQ_NAV_MSK     ((u32)0x0000000F << 8)           /*!< R/W 0xF  1: Queue BKF must wait TX Nav finished  0: Queue not need wait*/
#define BIT_TXQ_NAV_MSK(x)       (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_TXQ_NAV_MSK(x)   ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_DIS_CW               ((u32)0x00000001 << 7)           /*!< R/W 0x0  When this bit is set, disable CW.*/
#define BIT_NAV_END_TXOP         ((u32)0x00000001 << 6)           /*!< R/W 0x0  1: In txop mode, Nav protect all txop  0: In txop mode, Nav protect to next pkt*/
#define BIT_RDG_END_TXOP         ((u32)0x00000001 << 5)           /*!< R/W 0x0  1: In tx RDG mode, Nav protect all txop  0: In tx RDG mode, Nav protect to next pkt*/
#define BIT_MGTQ_TXOP_EN         ((u32)0x00000001 << 3)           /*!< R/W 0x1  When this bit is set, MGTQ may sent packets by using ACQ TXOP.*/
#define BIT_MGTQ_RTSMF_EN        ((u32)0x00000001 << 2)           /*!< R/W 0x1  When this bit is set, MTGQ will be TX, not wait until RTS or MF transaction finished.*/
#define BIT_HIQ_RTSMF_EN         ((u32)0x00000001 << 1)           /*!< R/W 0x1  When this bit is set, HIQ will be TX, not wait until RTS or MF transaction finished.*/
#define BIT_BCN_RTSMF_EN         ((u32)0x00000001 << 0)           /*!< R/W 0x1  When this bit is set, BCNQ will be TX, not wait until RTS or MF transaction finished.*/
/** @} */

/** @defgroup REG_RD_CTRL
  * @brief
  * @{
  */
#define BIT_DIS_TX_OVER_BCNQ     ((u16)0x00000001 << 14) /*!< R/W   1: Tx Packet with ignoring Beacon Area time 0: Disable*/
#define BIT_EDCCA_MSK_CNTDOWN_EN ((u16)0x00000001 << 11) /*!< R/W 0x1  1: disable EDCCA count down, 0: enable EDCCA count down AC backoff 是否需要參考PHY_EDCCA 0: 不參考PHY_EDCCA 1: 參考PHY_EDCCA (default, PHY_EDCCA=1時停止backoff)*/
#define BIT_DIS_TXOP_CFE         ((u16)0x00000001 << 10) /*!< R/W 0x0  Disable TXOP_CFE function*/
#define BIT_DIS_LSIG_CFE         ((u16)0x00000001 << 9)  /*!< R /W 0x0  Disable LSIG_TXOP CF-END function*/
#define BIT_DIS_STBC_CFE         ((u16)0x00000001 << 8)  /*!< R /W 0x0  Disable STBC CF-END function*/
#define BIT_BKQ_RD_INIT_EN       ((u16)0x00000001 << 7)  /*!< R/W 0x0  Enable BKQ RD initiator function*/
#define BIT_BEQ_RD_INIT_EN       ((u16)0x00000001 << 6)  /*!< R/W 0x0  Enable BEQ RD initiator function*/
#define BIT_VIQ_RD_INIT_EN       ((u16)0x00000001 << 5)  /*!< R/W 0x0  Enable VIQ RD initiator function*/
#define BIT_VOQ_RD_INIT_EN       ((u16)0x00000001 << 4)  /*!< R/W 0x0  Enable VOQ RD initiator function*/
#define BIT_BKQ_RD_RESP_EN       ((u16)0x00000001 << 3)  /*!< R/W 0x1  Enable BKQ RD responder function*/
#define BIT_BEQ_RD_RESP_EN       ((u16)0x00000001 << 2)  /*!< R/W 0x1  Enable BEQ RD responder function*/
#define BIT_VIQ_RD_RESP_EN       ((u16)0x00000001 << 1)  /*!< R/W 0x1  Enable VIQ RD responder function*/
#define BIT_VOQ_RD_RESP_EN       ((u16)0x00000001 << 0)  /*!< R/W 0x1  Enable VOQ RD responder function*/
/** @} */

/** @defgroup REG_MBSSID_CTRL
  * @brief
  * @{
  */
#define BIT_MBID_BCNQ7_EN ((u8)0x00000001 << 7) /*!< R/W 0x1  When enable, auto MBSSID for virtual interface 7 is enable.*/
#define BIT_MBID_BCNQ6_EN ((u8)0x00000001 << 6) /*!< R/W 0x1  When enable, auto MBSSID for virtual interface 6 is enable.*/
#define BIT_MBID_BCNQ5_EN ((u8)0x00000001 << 5) /*!< R/W 0x1  When enable, auto MBSSID for virtual interface 5 is enable.*/
#define BIT_MBID_BCNQ4_EN ((u8)0x00000001 << 4) /*!< R/W 0x1  When enable, auto MBSSID for virtual interface 4 is enable.*/
#define BIT_MBID_BCNQ3_EN ((u8)0x00000001 << 3) /*!< R/W 0x1  When enable, auto MBSSID for virtual interface 3 is enable.*/
#define BIT_MBID_BCNQ2_EN ((u8)0x00000001 << 2) /*!< R/W 0x1  When enable, auto MBSSID for virtual interface 2 is enable.*/
#define BIT_MBID_BCNQ1_EN ((u8)0x00000001 << 1) /*!< R/W 0x1  When enable, auto MBSSID for virtual interface 1 is enable.*/
#define BIT_MBID_BCNQ0_EN ((u8)0x00000001 << 0) /*!< R/W 0x1  When enable, auto MBSSID for root interface is enable.*/
/** @} */

/** @defgroup REG_P2PPS_CTRL
  * @brief
  * @{
  */
#define BIT_P2P_CTW_ALLSTASLEEP ((u8)0x00000001 << 7) /*!< R/W 0x0  It indicates that the state from CTWindow End to BcnEarly 1: Sleep  0: Wake*/
#define BIT_P2P_DISTX_SEL       ((u8)0x00000001 << 6) /*!< R/W 0x0  1: dis_txtime is the entire NOA duration 0: dis_txime is configured by 0x531[7:0] and 0x5B7[7:0]*/
#define BIT_PWR_MGT_EN          ((u8)0x00000001 << 5) /*!< R/W 0x0  A main switch for P2P PowerSaving 1: Enable 0: Disable*/
#define BIT_P2P_BCN_AREA_EN     ((u8)0x00000001 << 4) /*!< R/W 0x0  The condition that beacon related. 1: Enable 0: Disable*/
#define BIT_P2P_CTWND_EN        ((u8)0x00000001 << 3) /*!< R/W 0x0  The condition that CTWindow period 1: Enable 0: Disable*/
#define BIT_P2P_NOA1_EN         ((u8)0x00000001 << 2) /*!< R/W 0x0  The condition that NOA1 1: Enable 0: Disable*/
#define BIT_P2P_NOA0_EN         ((u8)0x00000001 << 1) /*!< R/W 0x0  The condition that NOA0 1: Enable 0: Disable*/
#define BIT_P2P_BCN_SEL         ((u8)0x00000001 << 0) /*!< R/W 0x1  use bcn1 or bcn2 tstt to compare NOA setting 0: bcn2 1: bcn1*/
/** @} */

/** @defgroup REG_PKT_LIFETIME_CTRL
  * @brief
  * @{
  */
#define BIT_EN_P2P_CTWND1          ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_EN_BKF_CLR_TXREQ       ((u32)0x00000001 << 22)          /*!< R/W 0x1  */
#define BIT_EN_TSFBIT32_RST_P2P    ((u32)0x00000001 << 21)          /*!< R/W 0x1  */
#define BIT_EN_BCN_TX_BTCCA        ((u32)0x00000001 << 20)          /*!< R/W 0x0  1: Enable Beacon Tx at TBTT if BT_CCA is enabled 0: Disable*/
#define BIT_DIS_PKT_TX_ATIM        ((u32)0x00000001 << 19)          /*!< R/W 0x1  1: Disable AC Queue Packet Tx in ATIM (only valid at Nettype: Adhoc/AP) 0: Enable AC Queue packet Tx in ATIM*/
#define BIT_DIS_BCN_DIS_CTN        ((u32)0x00000001 << 18)          /*!< R/W 0x1  Disable the Beacon queue disable contention,when set to 0 enable the force beacon function.*/
#define BIT_EN_NAVEND_RST_TXOP     ((u32)0x00000001 << 17)          /*!< R/W 0x0  When set this bit, TXOP will be reset while NAV end.*/
#define BIT_EN_FILTER_CCA          ((u32)0x00000001 << 16)          /*!< R/W 0x0  Enable CCA filter threshold*/
#define BIT_MASK_CCA_FILTER_THRS   ((u32)0x000000FF << 8)           /*!< R/W 0xA  If PHY_CCA signal width is bigger than this threshold, this PHY_CCA signal is valid for MAC. Unit: us*/
#define BIT_CCA_FILTER_THRS(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_CCA_FILTER_THRS(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_EDCCA_THRS        ((u32)0x000000FF << 0)           /*!< R/W 0x8F  EDCCA threshold value, edcca over this threshold will cause bkf_rst Bit[7]: PHY_EDCCA為1時,當timer timeout時擋住TX Bit[6:0]: timer (單位:32us)*/
#define BIT_EDCCA_THRS(x)          (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_EDCCA_THRS(x)      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_P2PPS_SPEC_STATE
  * @brief
  * @{
  */
#define BIT_SPEC_POWER_STATE       ((u8)0x00000001 << 7) /*!< R   1: On, 0: Off*/
#define BIT_SPEC_CTWINDOW_ON       ((u8)0x00000001 << 6) /*!< R   The time from TBTT <-> CTWEND (with BCNDMATIM early time)*/
#define BIT_SPEC_BEACON_AREA_ON    ((u8)0x00000001 << 5) /*!< R   The time is from TBTT to BeaconTx or Timeout*/
#define BIT_SPEC_CTWIN_EARLY_DISTX ((u8)0x00000001 << 4) /*!< R   ctwin_early_distx*/
#define BIT_SPEC_NOA1_OFF_PERIOD   ((u8)0x00000001 << 3) /*!< R   Spec time*/
#define BIT_SPEC_FORCE_DOZE1       ((u8)0x00000001 << 2) /*!< R   If NoA_Count == 1, this value is 1. else 0.*/
#define BIT_SPEC_NOA0_OFF_PERIOD   ((u8)0x00000001 << 1) /*!< R   Spec time*/
#define BIT_SPEC_FORCE_DOZE0       ((u8)0x00000001 << 0) /*!< R   If NoA_Count == 1, this value is 1. else 0.*/
/** @} */

/** @defgroup REG_PS_TIMER_A_V2
  * @brief
  * @{
  */
#define BIT_MASK_PS_TIMER_A_V2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  When the lower 4 bytes of TSF(that select by reg 0x51F[1:0]) matches the content of this register, the PS_TIMER_A_INT interrupt is issued*/
#define BIT_PS_TIMER_A_V2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_PS_TIMER_A_V2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_P2PON_DIS_TXTIME
  * @brief
  * @{
  */
#define BIT_MASK_P2PON_DIS_TXTIME   ((u32)0x000000FF << 0)           /*!< R/W 0x0  The time of the disable TX period after the P2P RF on interrupt occur. Unit: 64us.*/
#define BIT_P2PON_DIS_TXTIME(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_P2PON_DIS_TXTIME(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_PS_TIMER_B_V2
  * @brief
  * @{
  */
#define BIT_MASK_PS_TIMER_B_V2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  When the lower 4 bytes of TSF(that select by reg 0x51F[5:4]) matches the content of this register, the PS_TIMER_B_INT interrupt is issued*/
#define BIT_PS_TIMER_B_V2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_PS_TIMER_B_V2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NOA0_TBTT_PROHIBIT
  * @brief
  * @{
  */
#define BIT_TBTT_DIG                    ((u32)0x00000001 << 20)          /*!< R/W 0x0  Notify BB to adjust DIG when MACTX around TBTT, so that beacon will have a larger chance of txok*/
#define BIT_MASK_TBTT_HOLD_TIME_AP      ((u32)0x00000FFF << 8)           /*!< R/W 0xc8  TBTT_prohibit_hold time for AP mode, unit is 32 us*/
#define BIT_TBTT_HOLD_TIME_AP(x)        (((u32)((x) & 0x00000FFF) << 8))
#define BIT_GET_TBTT_HOLD_TIME_AP(x)    ((u32)(((x >> 8) & 0x00000FFF)))
#define BIT_MASK_TBTT_HOLD_TIME_INFRA   ((u32)0x0000000F << 4)           /*!< R/W 0x01  TBTT_prohibit_hold time for infrastructure mode , unit is 2 ms*/
#define BIT_TBTT_HOLD_TIME_INFRA(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_TBTT_HOLD_TIME_INFRA(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_TBTT_PROHIBIT_SETUP    ((u32)0x0000000F << 0)           /*!< R/W 0x02  TBTT_prohibit_setup, unit is 32us*/
#define BIT_TBTT_PROHIBIT_SETUP(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_TBTT_PROHIBIT_SETUP(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_P2PPS_STATE
  * @brief
  * @{
  */
#define BIT_POWER_STATE       ((u8)0x00000001 << 7) /*!< RO   1: On, 0: Off.  (It is including early time. )*/
#define BIT_CTWINDOW_ON       ((u8)0x00000001 << 6) /*!< RO   Spec time and Beacon Early Time to TBTT Time.  (It is including early time. )*/
#define BIT_BEACON_AREA_ON    ((u8)0x00000001 << 5) /*!< RO   The time is from HOLD Time to BeaconTx or Timeout. (It is including early time. )*/
#define BIT_CTWIN_EARLY_DISTX ((u8)0x00000001 << 4) /*!< RO   ctwin_early_distx.  (It is including early time. )*/
#define BIT_NOA1_OFF_PERIOD   ((u8)0x00000001 << 3) /*!< RO   Spec time but exclude BCNDMATIM time for wake.  (It is including early time. )*/
#define BIT_FORCE_DOZE1       ((u8)0x00000001 << 2) /*!< RO   If NoA_Count == 1, this value is 1. else 0. (It is including early time. )*/
#define BIT_NOA0_OFF_PERIOD   ((u8)0x00000001 << 1) /*!< RO   Spec time but exclude BCNDMATIM time for wake.  (It is including early time. )*/
#define BIT_FORCE_DOZE0       ((u8)0x00000001 << 0) /*!< RO   If NoA_Count == 1, this value is 1. else 0.  (It is including early time. )*/
/** @} */

/** @defgroup REG_RD_NAV_NXT
  * @brief
  * @{
  */
#define BIT_MASK_RD_NAV_PROT_NXT   ((u16)0x0000FFFF << 0)           /*!< R/W 0x180  In RDG mode ,NAV setting which protects next packets*/
#define BIT_RD_NAV_PROT_NXT(x)     (((u16)((x) & 0x0000FFFF) << 0))
#define BIT_GET_RD_NAV_PROT_NXT(x) ((u16)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_NAV_PROT_LEN
  * @brief
  * @{
  */
#define BIT_MASK_NAV_PROT_LEN   ((u16)0x0000FFFF << 0)           /*!< R/W 0x40  In TXOP mode ,NAV setting which protects next packets*/
#define BIT_NAV_PROT_LEN(x)     (((u16)((x) & 0x0000FFFF) << 0))
#define BIT_GET_NAV_PROT_LEN(x) ((u16)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_FTM_SETTING
  * @brief
  * @{
  */
#define BIT_FTM_PTT_TSF_R2T_SEL_V1 ((u32)0x00000001 << 24)          /*!< R/W 0x0  */
#define BIT_FTM_PTT_TSF_T2R_SEL_V1 ((u32)0x00000001 << 20)          /*!< R/W 0x0  */
#define BIT_FTM_PTT_TSF_SEL_V1     ((u32)0x00000001 << 16)          /*!< R/W 0x0  */
#define BIT_MASK_FTM_PTT           ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  partial tsf timer setting*/
#define BIT_FTM_PTT(x)             (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_FTM_PTT(x)         ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_FTM_TSF_CNT
  * @brief
  * @{
  */
#define BIT_MASK_FTM_TSF_R2T   ((u32)0x0000FFFF << 16)           /*!< R   R2T latch count sync tsf timer*/
#define BIT_FTM_TSF_R2T(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_FTM_TSF_R2T(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_FTM_TSF_T2R   ((u32)0x0000FFFF << 0)            /*!< R   T2R latch count sync tsf timer*/
#define BIT_FTM_TSF_T2R(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_FTM_TSF_T2R(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BCN_CTRL
  * @brief
  * @{
  */
#define BIT_DIS_RX_BSSID_FIT ((u8)0x00000001 << 6) /*!< R/W 0x0  0:HW will handle rx_beacon 1:HW will ignore rx_beacon_pk*/
#define BIT_DIS_TSF_UDT      ((u8)0x00000001 << 4) /*!< R/W 0x1  When set, disable port 0 TSF update when beacon frames or probe response frames are received.*/
#define BIT_EN_BCN_FUNCTION  ((u8)0x00000001 << 3) /*!< R/W 0x0  When this bit is set, TSF and other beacon related functions are then enabled.*/
#define BIT_EN_TXBCN_RPT     ((u8)0x00000001 << 2) /*!< R/W 0x1  When this bit is set, then BCNERR and BCNOK interrupt is issued in ad hoc and AP mode.*/
/** @} */

/** @defgroup REG_BCN_CTRL1
  * @brief
  * @{
  */
#define BIT_DIS_RX_BSSID_FIT1 ((u8)0x00000001 << 6) /*!< R/W 0x0  0:HW will handle rx_beacon 1:HW will ignore rx_beacon_pk*/
#define BIT_DIS_TSF1_UDT      ((u8)0x00000001 << 4) /*!< R/W 0x1  When set, disable port 1 TSF update when beacon frames or probe response frames are received.*/
#define BIT_EN_BCN1_FUNCTION  ((u8)0x00000001 << 3) /*!< R/W 0x0  When this bit is set, TSF and other beacon related functions are then enabled.*/
#define BIT_EN_TXBCN1_RPT     ((u8)0x00000001 << 2) /*!< R/W 0x1  When this bit is set, then BCNERR and BCNOK interrupt is issued in ad hoc and AP mode.*/
/** @} */

/** @defgroup REG_MBID_NUM
  * @brief
  * @{
  */
#define BIT_EN_PRE_DL_BEACON    ((u8)0x00000001 << 3)           /*!< R/W 0x0  If set 1, hw will enable pre_download beacon*/
#define BIT_MASK_MBID_BCN_NUM   ((u8)0x00000007 << 0)           /*!< R/W 0x0  The number of virtual interface number excluding the root number.*/
#define BIT_MBID_BCN_NUM(x)     (((u8)((x) & 0x00000007) << 0))
#define BIT_GET_MBID_BCN_NUM(x) ((u8)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_DUAL_TSF_RST
  * @brief
  * @{
  */
#define BIT_P2P_PWR_RST1   ((u8)0x00000001 << 6) /*!< W   rst p2p circuit NOA 1*/
#define BIT_SCHEDULER_RST  ((u8)0x00000001 << 5) /*!< W   Write this bit reset scheduler*/
#define BIT_P2P_PWR_RST0   ((u8)0x00000001 << 4) /*!< W   rst p2p circuit NOA 0*/
#define BIT_TSFTR1_SYNC_EN ((u8)0x00000001 << 3) /*!< W   write this bit,  bcn1 will sync to bcn0 with TSFTF_SYN_OFFSET*/
#define BIT_TSFTR_SYNC_EN  ((u8)0x00000001 << 2) /*!< W   write this bit,  bcn0 will sync to bcn1 with TSFTF_SYN_OFFSET*/
#define BIT_TSFTR1_RST     ((u8)0x00000001 << 1) /*!< W   write this bit , bcn1  tsft will auto reset*/
#define BIT_TSFTR_RST      ((u8)0x00000001 << 0) /*!< W   write this bit , bcn0  tsft will auto reset*/
/** @} */

/** @defgroup REG_PORT0_BCN_SPACE
  * @brief
  * @{
  */
#define BIT_MASK_BCN_SPACE1   ((u32)0x0000FFFF << 16)           /*!< R/W 0x64  Unit is ms. When MBSSID is disable, this field is "0". When MBSSID is enabled, this register is the beacon space between root and first virtual interval.*/
#define BIT_BCN_SPACE1(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_BCN_SPACE1(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_BCN_SPACE0   ((u32)0x0000FFFF << 0)            /*!< R/W 0x64  Unit is ms. When MBSSID is disable, this field is the beacon interval. When MBSSID is enable, this register is the beacon space of root.*/
#define BIT_BCN_SPACE0(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BCN_SPACE0(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_ATIMWND0_P0_BCN_ERLY_DMA_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_DRVERLYITV   ((u8)0x000000FF << 0)           /*!< R/W 0x05  Time to send interrupt to notify driver to change beacon content. Time unit is TU. The register also is shared by P2P-CTW and P2P-NoA (from NoA-Absent to NoA-On). It is used to wake up early at DriverEarlyTime*/
#define BIT_DRVERLYITV(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_DRVERLYITV(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BCNDMATIM
  * @brief
  * @{
  */
#define BIT_MASK_BCNDMATIM   ((u8)0x000000FF << 0)           /*!< R/W 0x03  Indicates the time before TBTT to perform beacon queue DMA. This register is shared by the time to assert ATIM window end interrupt. Measured in units of "TU" before TBTT and before ATIM window end.*/
#define BIT_BCNDMATIM(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_BCNDMATIM(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_ATIMWND
  * @brief
  * @{
  */
#define BIT_MASK_ATIMWND0   ((u16)0x0000FFFF << 0)           /*!< R/W 0x02  ATIM window width of root VAP in units of TU.*/
#define BIT_ATIMWND0(x)     (((u16)((x) & 0x0000FFFF) << 0))
#define BIT_GET_ATIMWND0(x) ((u16)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_USTIME_TSF
  * @brief
  * @{
  */
#define BIT_MASK_USTIME_TSF_V1   ((u8)0x000000FF << 0)           /*!< R/W 0x64  Set the microsecond time unit used by MAC TSF clock.*/
#define BIT_USTIME_TSF_V1(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_USTIME_TSF_V1(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BCN_MAX_ERR
  * @brief
  * @{
  */
#define BIT_MASK_BCN_MAX_ERR   ((u8)0x000000FF << 0)           /*!< R/W 0x10  When beacon TX error counter goes over this threshold, Beacon will transmit within PIFS.*/
#define BIT_BCN_MAX_ERR(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_BCN_MAX_ERR(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RXTSF_OFFSET_CCK
  * @brief
  * @{
  */
#define BIT_MASK_CCK_RXTSF_OFFSET   ((u8)0x000000FF << 0)           /*!< R/W 0x0F  The Datapath of  CCK RX_tsf*/
#define BIT_CCK_RXTSF_OFFSET(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_CCK_RXTSF_OFFSET(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RXTSF_OFFSET_OFDM
  * @brief
  * @{
  */
#define BIT_MASK_OFDM_RXTSF_OFFSET   ((u8)0x000000FF << 0)           /*!< R/W 0x0F  The Datapath of  OFDM RX_tsf*/
#define BIT_OFDM_RXTSF_OFFSET(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_OFDM_RXTSF_OFFSET(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TSFTR0_L
  * @brief
  * @{
  */
#define BIT_MASK_TSF0_TIMER_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x1  TSFT TIMER Low 32bit for port 0*/
#define BIT_TSF0_TIMER_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_TSF0_TIMER_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TSFTR0_H
  * @brief
  * @{
  */
#define BIT_MASK_TSF0_TIMER_H   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  TSFT TIMER  High 32bit for port 0*/
#define BIT_TSF0_TIMER_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_TSF0_TIMER_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TSFTR1_L
  * @brief
  * @{
  */
#define BIT_MASK_TSF1_TIMER_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x1  TSFT TIMER Low 32bit for port 1*/
#define BIT_TSF1_TIMER_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_TSF1_TIMER_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TSFTR1_H
  * @brief
  * @{
  */
#define BIT_MASK_TSF1_TIMER_H   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  TSFT TIMER  High 32bit for port 1*/
#define BIT_TSF1_TIMER_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_TSF1_TIMER_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ATIMWND1_V1
  * @brief
  * @{
  */
#define BIT_MASK_ATIMWND1_V2   ((u16)0x0000FFFF << 0)           /*!< R/W 0x02  ATIM window width for VAP1 in units of TU.*/
#define BIT_ATIMWND1_V2(x)     (((u16)((x) & 0x0000FFFF) << 0))
#define BIT_GET_ATIMWND1_V2(x) ((u16)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_CTWND
  * @brief
  * @{
  */
#define BIT_MASK_CTWND   ((u8)0x000000FF << 0)           /*!< R/W 0x0a  CTWindow width in units of TU.*/
#define BIT_CTWND(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_CTWND(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BCNIVLCUNT
  * @brief
  * @{
  */
#define BIT_MASK_BCNIVLCUNT   ((u8)0x0000007F << 0)           /*!< R/W 0x7f  Be used in multiple BCNIVL early INT. When this counter =1, multiple BCNIVL early INT will be triggered.*/
#define BIT_BCNIVLCUNT(x)     (((u8)((x) & 0x0000007F) << 0))
#define BIT_GET_BCNIVLCUNT(x) ((u8)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_BCNDROPCTRL
  * @brief
  * @{
  */
#define BIT_BEACON_DROP_EN         ((u8)0x00000001 << 7)           /*!< R/W 0x0  */
#define BIT_MASK_BEACON_DROP_IVL   ((u8)0x0000007F << 0)           /*!< R/W 0x0  */
#define BIT_BEACON_DROP_IVL(x)     (((u8)((x) & 0x0000007F) << 0))
#define BIT_GET_BEACON_DROP_IVL(x) ((u8)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_HGQ_TIMEOUT_PERIOD
  * @brief
  * @{
  */
#define BIT_MASK_HGQ_TIMEOUT_PERIOD   ((u8)0x000000FF << 0)           /*!< R/W 0x10  When hgq empty for this period, close atim window. And this will block hgq dma for pcie. TU: 32us*/
#define BIT_HGQ_TIMEOUT_PERIOD(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_HGQ_TIMEOUT_PERIOD(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TXCMD_TIMEOUT_PERIOD
  * @brief
  * @{
  */
#define BIT_MASK_TXCMD_TIMEOUT_PERIOD   ((u8)0x000000FF << 0)           /*!< R/W 0xFF  When 40M/80M TX CMD ready and secondary_CCA_20/secondary_CCA_40 set for this period, then the TX CMD will be cleared.  TU: 1us*/
#define BIT_TXCMD_TIMEOUT_PERIOD(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_TXCMD_TIMEOUT_PERIOD(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_MISC_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_DIS_SECONDARY_CCA   ((u8)0x00000003 << 0)           /*!< R/W 0x0  Bit 0 : 1=Disable secondary CCA 20M, 0=Enable secondary CCA 20M. Bit 1 : 1=Disable secondary CCA 40M, 0=Enable secondary CCA 40M.*/
#define BIT_DIS_SECONDARY_CCA(x)     (((u8)((x) & 0x00000003) << 0))
#define BIT_GET_DIS_SECONDARY_CCA(x) ((u8)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_TSFTR2_L
  * @brief
  * @{
  */
#define BIT_MASK_TSF2_TIMER_L   ((u32)0xFFFFFFFF << 0)           /*!< R   TSFT TIMER Low 32bit for port 2*/
#define BIT_TSF2_TIMER_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_TSF2_TIMER_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TSFTR2_H
  * @brief
  * @{
  */
#define BIT_MASK_TSF2_TIMER_H   ((u32)0xFFFFFFFF << 0)           /*!< R   TSFT TIMER  High 32bit for port 2*/
#define BIT_TSF2_TIMER_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_TSF2_TIMER_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PS_TIMER0
  * @brief
  * @{
  */
#define BIT_MASK_PSTIMER0_INT   ((u32)0x07FFFFFF << 5)           /*!< R/W 0x00  When the lower 4 bytes of TSFTR0  matches the content of this register, the FW PS_TimeOut0 interrupt is issued.*/
#define BIT_PSTIMER0_INT(x)     (((u32)((x) & 0x07FFFFFF) << 5))
#define BIT_GET_PSTIMER0_INT(x) ((u32)(((x >> 5) & 0x07FFFFFF)))
/** @} */

/** @defgroup REG_PS_TIMER1
  * @brief
  * @{
  */
#define BIT_MASK_PSTIMER1_INT   ((u32)0x07FFFFFF << 5)           /*!< R/W 0x00  When the lower 4 bytes of TSFTR0 matches the content of this register, the FW PS_TimeOut1 interrupt is issued.*/
#define BIT_PSTIMER1_INT(x)     (((u32)((x) & 0x07FFFFFF) << 5))
#define BIT_GET_PSTIMER1_INT(x) ((u32)(((x >> 5) & 0x07FFFFFF)))
/** @} */

/** @defgroup REG_PS_TIMER2
  * @brief
  * @{
  */
#define BIT_MASK_PSTIMER2_INT   ((u32)0x07FFFFFF << 5)           /*!< R/W 0x00  When the lower 4 bytes of TSFTR0 matches the content of this register, the FW PS_TimeOut2 interrupt is issued.*/
#define BIT_PSTIMER2_INT(x)     (((u32)((x) & 0x07FFFFFF) << 5))
#define BIT_GET_PSTIMER2_INT(x) ((u32)(((x >> 5) & 0x07FFFFFF)))
/** @} */

/** @defgroup REG_TBTT_CTN_AREA
  * @brief
  * @{
  */
#define BIT_MASK_TBTT_CTN_AREA   ((u16)0x000000FF << 0)           /*!< R/W 0x60  TBTT contention area,Time unit is 32us*/
#define BIT_TBTT_CTN_AREA(x)     (((u16)((x) & 0x000000FF) << 0))
#define BIT_GET_TBTT_CTN_AREA(x) ((u16)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_FORCE_BCN_IFS
  * @brief
  * @{
  */
#define BIT_MASK_FORCE_BCN_IFS   ((u8)0x000000FF << 0)           /*!< R/W 0x20  when 0x528 Bit18 set to 0 and TBTT contention area end,force tx beacon use this IFS*/
#define BIT_FORCE_BCN_IFS(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_FORCE_BCN_IFS(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_DRVERLYINT_V1
  * @brief
  * @{
  */
#define BIT_MASK_PRE_BCN_DMATIM   ((u8)0x000000FF << 0)           /*!< R/W 0x06  when 0x552[3] is set, hw will enable pre_download beacon. this register Indicates the time before TBTT to perform beacon queue DMA.*/
#define BIT_PRE_BCN_DMATIM(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_PRE_BCN_DMATIM(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TXOP_MIN
  * @brief
  * @{
  */
#define BIT_NAV_BLK_HGQ     ((u16)0x00000001 << 15)          /*!< R/W 0x0  rxnav block HGQ*/
#define BIT_NAV_BLK_MGQ     ((u16)0x00000001 << 14)          /*!< R/W 0x0  rxnav block MGQ*/
#define BIT_MASK_TXOP_MIN   ((u16)0x00003FFF << 0)           /*!< R/W 0x0f  When BIT_NOT_CROSS_TXOP =1, the remainder of TXOP < BIT_TXOP_MIN => Don't generate TxCMD packet(Stop tx packet in this TxOp)*/
#define BIT_TXOP_MIN(x)     (((u16)((x) & 0x00003FFF) << 0))
#define BIT_GET_TXOP_MIN(x) ((u16)(((x >> 0) & 0x00003FFF)))
/** @} */

/** @defgroup REG_PRE_BKF_TIME
  * @brief
  * @{
  */
#define BIT_MASK_PRE_BKF_TIME   ((u8)0x000000FF << 0)           /*!< R/W 0x0f  */
#define BIT_PRE_BKF_TIME(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_PRE_BKF_TIME(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_CROSS_TXOP_CTRL
  * @brief
  * @{
  */
#define BIT_NOPKT_END_RTSMF ((u8)0x00000001 << 7)           /*!< R/W 0x1  1-->enable exit rts hold mode when there is no corresponding ac pkt to tx*/
#define BIT_MASK_PRETX_US   ((u8)0x0000000F << 3)           /*!< R/W 0x6  For wep/tkip, enable security engine earlier than mactx by this amount of time. Unit is microsecond (us)*/
#define BIT_PRETX_US(x)     (((u8)((x) & 0x0000000F) << 3))
#define BIT_GET_PRETX_US(x) ((u8)(((x >> 3) & 0x0000000F)))
#define BIT_DTIM_BYPASS     ((u8)0x00000001 << 2)           /*!< R/W 0x0  */
#define BIT_RTS_NAV_TXOP    ((u8)0x00000001 << 1)           /*!< R/W 0x0  NAV of RTS and CTS2SELF protect all TXOP time*/
#define BIT_NOT_CROSS_TXOP  ((u8)0x00000001 << 0)           /*!< R/W 0x0  BIT_NOT_CROSS_TXOP is enable register for 0x590[13:0] (BIT_TXOP_MIN) condition.*/
/** @} */

/** @defgroup REG_FREERUN_CNT_L
  * @brief
  * @{
  */
#define BIT_MASK_FREERUN_CNT_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  free run counter low 32bit, unit is us*/
#define BIT_FREERUN_CNT_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FREERUN_CNT_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FREERUN_CNT_H
  * @brief
  * @{
  */
#define BIT_MASK_FREERUN_CNT_H   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  free run counter high 32bit, unit is us*/
#define BIT_FREERUN_CNT_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FREERUN_CNT_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_ATIMWND2
  * @brief
  * @{
  */
#define BIT_MASK_ATIMWND2   ((u8)0x000000FF << 0)           /*!< R/W 0x02  ATIM window width in units of TU.*/
#define BIT_ATIMWND2(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_ATIMWND2(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_ATIMWND3
  * @brief
  * @{
  */
#define BIT_MASK_ATIMWND3   ((u8)0x000000FF << 0)           /*!< R/W 0x02  ATIM window width in units of TU.*/
#define BIT_ATIMWND3(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_ATIMWND3(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_ATIMWND4
  * @brief
  * @{
  */
#define BIT_MASK_ATIMWND4   ((u8)0x000000FF << 0)           /*!< R/W 0x02  ATIM window width in units of TU.*/
#define BIT_ATIMWND4(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_ATIMWND4(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_ATIMWND5
  * @brief
  * @{
  */
#define BIT_MASK_ATIMWND5   ((u8)0x000000FF << 0)           /*!< R/W 0x02  ATIM window width in units of TU.*/
#define BIT_ATIMWND5(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_ATIMWND5(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_ATIMWND6
  * @brief
  * @{
  */
#define BIT_MASK_ATIMWND6   ((u8)0x000000FF << 0)           /*!< R/W 0x02  ATIM window width in units of TU.*/
#define BIT_ATIMWND6(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_ATIMWND6(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_ATIMWND7
  * @brief
  * @{
  */
#define BIT_MASK_ATIMWND7   ((u8)0x000000FF << 0)           /*!< R/W 0x02  ATIM window width in units of TU.*/
#define BIT_ATIMWND7(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_ATIMWND7(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_ATIMUGT
  * @brief
  * @{
  */
#define BIT_MASK_ATIM_URGENT   ((u8)0x000000FF << 0)           /*!< R/W 0x01  Indicates the time before ATIM Window end . When BSSID[n] (n=0~7) has HIQ packet to send, HW only DMA BSSID[n]'s HIQ packet in this interval. (unit : TU)*/
#define BIT_ATIM_URGENT(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_ATIM_URGENT(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_HIQ_NO_LMT_EN
  * @brief
  * @{
  */
#define BIT_HIQ_NO_LMT_EN_VAP7 ((u8)0x00000001 << 7) /*!< R/W 0x0  1: Packet in Hi Queue Tx immediately (No constraint for ATIM Period) 0: Disable*/
#define BIT_HIQ_NO_LMT_EN_VAP6 ((u8)0x00000001 << 6) /*!< R/W 0x0  1: Packet in Hi Queue Tx immediately (No constraint for ATIM Period) 0: Disable*/
#define BIT_HIQ_NO_LMT_EN_VAP5 ((u8)0x00000001 << 5) /*!< R/W 0x0  1: Packet in Hi Queue Tx immediately (No constraint for ATIM Period) 0: Disable*/
#define BIT_HIQ_NO_LMT_EN_VAP4 ((u8)0x00000001 << 4) /*!< R/W 0x0  1: Packet in Hi Queue Tx immediately (No constraint for ATIM Period) 0: Disable*/
#define BIT_HIQ_NO_LMT_EN_VAP3 ((u8)0x00000001 << 3) /*!< R/W 0x0  1: Packet in Hi Queue Tx immediately (No constraint for ATIM Period) 0: Disable*/
#define BIT_HIQ_NO_LMT_EN_VAP2 ((u8)0x00000001 << 2) /*!< R/W 0x0  1: Packet in Hi Queue Tx immediately (No constraint for ATIM Period) 0: Disable*/
#define BIT_HIQ_NO_LMT_EN_VAP1 ((u8)0x00000001 << 1) /*!< R/W 0x0  1: Packet in Hi Queue Tx immediately (No constraint for ATIM Period) 0: Disable*/
#define BIT_HIQ_NO_LMT_EN_ROOT ((u8)0x00000001 << 0) /*!< R/W 0x0  1: Packet in Hi Queue Tx immediately (No constraint for ATIM Period) 0: Disable*/
/** @} */

/** @defgroup REG_DTIM_COUNTER_ROOT
  * @brief
  * @{
  */
#define BIT_MASK_DTIM_COUNT_ROOT   ((u8)0x000000FF << 0)           /*!< R/W 0x0  */
#define BIT_DTIM_COUNT_ROOT(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_DTIM_COUNT_ROOT(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_DTIM_COUNTER_VAP1
  * @brief
  * @{
  */
#define BIT_MASK_DTIM_COUNT_VAP1   ((u8)0x000000FF << 0)           /*!< R/W 0x0  */
#define BIT_DTIM_COUNT_VAP1(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_DTIM_COUNT_VAP1(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_DTIM_COUNTER_VAP2
  * @brief
  * @{
  */
#define BIT_MASK_DTIM_COUNT_VAP2   ((u8)0x000000FF << 0)           /*!< R/W 0x0  */
#define BIT_DTIM_COUNT_VAP2(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_DTIM_COUNT_VAP2(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_DTIM_COUNTER_VAP3
  * @brief
  * @{
  */
#define BIT_MASK_DTIM_COUNT_VAP3   ((u8)0x000000FF << 0)           /*!< R/W 0x0  */
#define BIT_DTIM_COUNT_VAP3(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_DTIM_COUNT_VAP3(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_DTIM_COUNTER_VAP4
  * @brief
  * @{
  */
#define BIT_MASK_DTIM_COUNT_VAP4   ((u8)0x000000FF << 0)           /*!< R/W 0x0  */
#define BIT_DTIM_COUNT_VAP4(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_DTIM_COUNT_VAP4(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_DTIM_COUNTER_VAP5
  * @brief
  * @{
  */
#define BIT_MASK_DTIM_COUNT_VAP5   ((u8)0x000000FF << 0)           /*!< R/W 0x0  */
#define BIT_DTIM_COUNT_VAP5(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_DTIM_COUNT_VAP5(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_DTIM_COUNTER_VAP6
  * @brief
  * @{
  */
#define BIT_MASK_DTIM_COUNT_VAP6   ((u8)0x000000FF << 0)           /*!< R/W 0x0  */
#define BIT_DTIM_COUNT_VAP6(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_DTIM_COUNT_VAP6(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_DTIM_COUNTER_VAP7
  * @brief
  * @{
  */
#define BIT_MASK_DTIM_COUNT_VAP7   ((u8)0x000000FF << 0)           /*!< R/W 0x0  */
#define BIT_DTIM_COUNT_VAP7(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_DTIM_COUNT_VAP7(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_DIS_ATIM
  * @brief
  * @{
  */
#define BIT_DIS_ATIM_VAP7 ((u8)0x00000001 << 7) /*!< R/W 0x0  */
#define BIT_DIS_ATIM_VAP6 ((u8)0x00000001 << 6) /*!< R/W 0x0  */
#define BIT_DIS_ATIM_VAP5 ((u8)0x00000001 << 5) /*!< R/W 0x0  */
#define BIT_DIS_ATIM_VAP4 ((u8)0x00000001 << 4) /*!< R/W 0x0  */
#define BIT_DIS_ATIM_VAP3 ((u8)0x00000001 << 3) /*!< R/W 0x0  */
#define BIT_DIS_ATIM_VAP2 ((u8)0x00000001 << 2) /*!< R/W 0x0  */
#define BIT_DIS_ATIM_VAP1 ((u8)0x00000001 << 1) /*!< R/W 0x0  */
#define BIT_DIS_ATIM_ROOT ((u8)0x00000001 << 0) /*!< R/W 0x0  */
/** @} */

/** @defgroup REG_EARLY_128US
  * @brief
  * @{
  */
#define BIT_MASK_EARLY_128US_2ST   ((u8)0x00000007 << 3)           /*!< R/W 0x0  the BCN EARLY interrupt find tune with unit 128us. The Total Early time of BCN early interrupt is the 0x558 x 1ms + EARLY_128us x 128us. For port 1*/
#define BIT_EARLY_128US_2ST(x)     (((u8)((x) & 0x00000007) << 3))
#define BIT_GET_EARLY_128US_2ST(x) ((u8)(((x >> 3) & 0x00000007)))
#define BIT_MASK_EARLY_128US       ((u8)0x00000007 << 0)           /*!< R/W 0x0  the BCN EARLY interrupt find tune with unit 128us. The Total Early time of BCN early interrupt is the 0x558 x 1ms + EARLY_128us x 128us. For port 0*/
#define BIT_EARLY_128US(x)         (((u8)((x) & 0x00000007) << 0))
#define BIT_GET_EARLY_128US(x)     ((u8)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_TBTT_HOLD_PREDICT_P1
  * @brief
  * @{
  */
#define BIT_DIS_BCN_3RD                 ((u8)0x00000001 << 7)           /*!< R/W 0x0  set 1 to mask the beacon early interrupt of port2*/
#define BIT_DIS_BCN_2ST                 ((u8)0x00000001 << 6)           /*!< R/W 0x0  set 1 to mask the beacon early interrupt of port1*/
#define BIT_DIS_BCN_1ST                 ((u8)0x00000001 << 5)           /*!< R/W 0x0  set 1 to mask the beacon early interrupt of port0*/
#define BIT_MASK_TBTT_HOLD_PREDICT_P1   ((u8)0x0000001F << 0)           /*!< R/W 0x2  the predicted hold time after tbtt for beacon tx of port1, unit is 32us*/
#define BIT_TBTT_HOLD_PREDICT_P1(x)     (((u8)((x) & 0x0000001F) << 0))
#define BIT_GET_TBTT_HOLD_PREDICT_P1(x) ((u8)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_MULTI_BCN_CS
  * @brief
  * @{
  */
#define BIT_TSFTR3_SYNC_EN      ((u8)0x00000001 << 7)           /*!< W   write this bit,  bcn2 will sync to bcn1 with TSFTF_SYN_OFFSET*/
#define BIT_TSFTR2_SYNC_EN      ((u8)0x00000001 << 5)           /*!< W   write this bit,  bcn1 will sync to bcn2 with TSFTF_SYN_OFFSET*/
#define BIT_TSFTR2_RST          ((u8)0x00000001 << 4)           /*!< W   write this bit , bcn2  tsft will auto reset*/
#define BIT_MASK_MULTI_BCN_CS   ((u8)0x0000000F << 0)           /*!< R   indicate which port is tx beacon*/
#define BIT_MULTI_BCN_CS(x)     (((u8)((x) & 0x0000000F) << 0))
#define BIT_GET_MULTI_BCN_CS(x) ((u8)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_TSFT_SHIFT
  * @brief
  * @{
  */
#define BIT_EN_FREECNT_V2        ((u32)0x00000001 << 13)          /*!< R/W 0x0  enable freerun tsft*/
#define BIT_RESET_FREECNT_P      ((u32)0x00000001 << 12)          /*!< W   reset pulse of freerun tsft*/
#define BIT_MASK_P1_TSFT_SHIFT   ((u32)0x0000003F << 6)           /*!< R/W 0x0  bit shift vaule of p1 tsft for hci*/
#define BIT_P1_TSFT_SHIFT(x)     (((u32)((x) & 0x0000003F) << 6))
#define BIT_GET_P1_TSFT_SHIFT(x) ((u32)(((x >> 6) & 0x0000003F)))
#define BIT_MASK_P0_TSFT_SHIFT   ((u32)0x0000003F << 0)           /*!< R/W 0x0  bit shift vaule of p0 tsft for hci*/
#define BIT_P0_TSFT_SHIFT(x)     (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_P0_TSFT_SHIFT(x) ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_P2POFF_DIS_TXTIME
  * @brief
  * @{
  */
#define BIT_MASK_P2POFF_DIS_TXTIME   ((u8)0x000000FF << 0)           /*!< R/W 0x0  The time of the disable TX period after the P2P RF off interrupt occur. Unit: 64us.*/
#define BIT_P2POFF_DIS_TXTIME(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_P2POFF_DIS_TXTIME(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_PTA_TRXBCN_CTRL
  * @brief
  * @{
  */
#define BIT_PTA_RXBCN_PRI_MASK       ((u32)0x00000001 << 31)           /*!< R/W 0x1  */
#define BIT_PTA_RXBCN_EN             ((u32)0x00000001 << 30)           /*!< R/W 0x1  */
#define BIT_PTA_RXBCN_DIR            ((u32)0x00000001 << 29)           /*!< R/W 0x1  */
#define BIT_MASK_PTA_RXBCN_DUR   ((u32)0x000001FF << 20)           /*!< R/W 0x60  */
#define BIT_PTA_RXBCN_DUR(x)         (((u32)((x) & 0x000001FF) << 20))
#define BIT_GET_PTA_RXBCN_DUR(x)     ((u32)(((x >> 20) & 0x000001FF)))
#define BIT_MASK_PTA_RXBCN_TIME      ((u32)0x0000007F << 13)           /*!< R/W 0x6  */
#define BIT_PTA_RXBCN_TIME(x)        (((u32)((x) & 0x0000007F) << 13))
#define BIT_GET_PTA_RXBCN_TIME(x)    ((u32)(((x >> 13) & 0x0000007F)))
#define BIT_PTA_PRETX_EN             ((u32)0x00000001 << 12)           /*!< R/W 0x1  */
#define BIT_MASK_PTA_PRETX_TIME      ((u32)0x00000FFF << 0)            /*!< R/W 0x64  WIFI TX shall wait settle time when antenna is switched from BT to WIFI, if the BT use the same RFAFE as WIFI. Unit: 1us*/
#define BIT_PTA_PRETX_TIME(x)        (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_PTA_PRETX_TIME(x)    ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_ACMHWCTRL
  * @brief
  * @{
  */
#define BIT_BEQ_ACM_STATUS ((u8)0x00000001 << 7) /*!< R   This bit indicates if the used_time >= admitted_time of AC BE when HW ACM. 0: BEQ ACM Not Exceed. 1: BEQ ACM Exceed. Default: 0h*/
#define BIT_VIQ_ACM_STATUS ((u8)0x00000001 << 6) /*!< R   This bit indicates if the used_time >= admitted_time of AC VI when HW ACM. 0: VIQ ACM Not Exceed. 1: VIQ ACM Exceed. Default: 0h*/
#define BIT_VOQ_ACM_STATUS ((u8)0x00000001 << 5) /*!< R   This bit indicates if the used_time >= admitted_time of AC VO when HW ACM. 0: VOQ ACM Not Exceed. 1: VOQ ACM Exceed. Default: 0h*/
#define BIT_BEQ_ACM_EN     ((u8)0x00000001 << 3) /*!< R/W 0x0  Set this bit to enable ACM of BE queue. 1: Enable 0: Disable Default: 0h*/
#define BIT_VIQ_ACM_EN     ((u8)0x00000001 << 2) /*!< R/W 0x0  Set this bit to enable ACM of VI queue. 1: Enable 0: Disable Default: 0h.*/
#define BIT_VOQ_ACM_EN     ((u8)0x00000001 << 1) /*!< R/W 0x0  Set this bit to enable ACM of VO queue. 1: Enable 0: Disable Default: 0h.*/
#define BIT_ACMHWEN        ((u8)0x00000001 << 0) /*!< R/W 0x0  Set this bit to enable hardware to take control of ACM. 1: Hardware Control 0: Software Control Default: 0h.*/
/** @} */

/** @defgroup REG_ACMRSTCTRL
  * @brief
  * @{
  */
#define BIT_BE_ACM_RESET_USED_TIME ((u8)0x00000001 << 2) /*!< W   When HwEn is enabled, software set this bit to inform hardware to reset used_time to 0. Read this bit is always 0.*/
#define BIT_VI_ACM_RESET_USED_TIME ((u8)0x00000001 << 1) /*!< W   When HwEn is enabled, software set this bit to inform hardware to reset used_time to 0. Read this bit is always 0.*/
#define BIT_VO_ACM_RESET_USED_TIME ((u8)0x00000001 << 0) /*!< W   When HwEn is enabled, software set this bit to inform hardware to reset used_time to 0. Read this bit is always 0.*/
/** @} */

/** @defgroup REG_ACMAVG
  * @brief
  * @{
  */
#define BIT_MASK_AVGPERIOD   ((u16)0x0000FFFF << 0)           /*!< R/W 0x00  In unit of 32 us. It is the value Dot11EDCAAveragingPeriod in SPEC. HW will recalculate used_time every this period. Max is 2 sec*/
#define BIT_AVGPERIOD(x)     (((u16)((x) & 0x0000FFFF) << 0))
#define BIT_GET_AVGPERIOD(x) ((u16)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_VO_ADMTIME
  * @brief
  * @{
  */
#define BIT_MASK_VO_ADMITTED_TIME   ((u16)0x0000FFFF << 0)           /*!< R/W 0x00  Admitted_time of VO queue. In unit of 32 microsecond.  Calculated and set by driver.*/
#define BIT_VO_ADMITTED_TIME(x)     (((u16)((x) & 0x0000FFFF) << 0))
#define BIT_GET_VO_ADMITTED_TIME(x) ((u16)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_VI_ADMTIME
  * @brief
  * @{
  */
#define BIT_MASK_VI_ADMITTED_TIME   ((u16)0x0000FFFF << 0)           /*!< R/W 0x00  Admitted_time of VI queue. In unit of 32 microsecond.  Calculated and set by driver.*/
#define BIT_VI_ADMITTED_TIME(x)     (((u16)((x) & 0x0000FFFF) << 0))
#define BIT_GET_VI_ADMITTED_TIME(x) ((u16)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BE_ADMTIME
  * @brief
  * @{
  */
#define BIT_MASK_BE_ADMITTED_TIME   ((u32)0x0000FFFF << 0)           /*!< R/W 0x00  Admitted_time of BE queue. In unit of 32 microsecond.  Calculated and set by driver.*/
#define BIT_BE_ADMITTED_TIME(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BE_ADMITTED_TIME(x) ((u32)(((x >> 0) & 0x0000FFFF)))
#define BIT_MASK_MHDR_NAV_OFFSET    ((u32)0x000000FF << 0)           /*!< R/W 0x00  NDPA NAV compensation value*/
#define BIT_MHDR_NAV_OFFSET(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MHDR_NAV_OFFSET(x)  ((u32)(((x >> 0) & 0x000000FF)))
#define BIT_DIS_NDPA_NAV_CHK_V1     ((u32)0x00000001 << 0)           /*!< R/W 0x0  1-->tx NDPA/NDP can cross TBTT,0-->tx NDPA/NDP can't cross TBTT*/
/** @} */

/** @defgroup REG_EDCA_RANDOM_GEN
  * @brief
  * @{
  */
#define BIT_MASK_RANDOM_GEN   ((u32)0x00FFFFFF << 0)           /*!< R/W 0xe21051  Random number generator polynomial*/
#define BIT_RANDOM_GEN(x)     (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_RANDOM_GEN(x) ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_TXCMD_NOA_SEL
  * @brief
  * @{
  */
#define BIT_MASK_EVTQ_EARLY      ((u8)0x00000007 << 5)           /*!< R/W 0x1  the early time of evtq tx window. unit is TU*/
#define BIT_EVTQ_EARLY(x)        (((u8)((x) & 0x00000007) << 5))
#define BIT_GET_EVTQ_EARLY(x)    ((u8)(((x >> 5) & 0x00000007)))
#define BIT_NOA_SEL              ((u8)0x00000001 << 4)           /*!< R/W 0x1  TX NoA packet select 0: NoA0 , 1:NoA1. To control the register setting for which NOA. (register 0x05E0[103:0])*/
#define BIT_MASK_TXCMD_SEG_SEL   ((u8)0x0000000F << 0)           /*!< R/W 0x1  [HW Debug Info] To select which one TXCMD Segment.*/
#define BIT_TXCMD_SEG_SEL(x)     (((u8)((x) & 0x0000000F) << 0))
#define BIT_GET_TXCMD_SEG_SEL(x) ((u8)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_DRVERLYINT2
  * @brief
  * @{
  */
#define BIT_MASK_TSF_DIFF_P1P2   ((u32)0x0000FFFF << 16)           /*!< R   the difference of beacon count down value between port0 and port1, unit is TU*/
#define BIT_TSF_DIFF_P1P2(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_TSF_DIFF_P1P2(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_TXPAUSE1        ((u32)0x000000FF << 8)            /*!< R/W 0x0  same as 0x522[7:0], allow FW/DR to control pause jointly*/
#define BIT_TXPAUSE1(x)          (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_TXPAUSE1(x)      ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_DRVERLYITV2     ((u32)0x000000FF << 0)            /*!< R/W 0x05  Time to send interrupt to notify driver to change beacon content. Time unit is TU.  It is used to wake up early at DriverEarlyTime. For port 2*/
#define BIT_DRVERLYITV2(x)       (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_DRVERLYITV2(x)   ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_NAN_SETTING
  * @brief
  * @{
  */
#define BIT_EN_MULTI_BCN                 ((u32)0x00000001 << 31)           /*!< R/W 0x1  enable multiple beacons of port0~port2*/
#define BIT_ENP2P_DW_AREA                ((u32)0x00000001 << 30)           /*!< R/W 0x0  DW condition for P2P,for port2*/
#define BIT_MASK_TBTT_PROHIBIT_HOLD_P2   ((u32)0x00000FFF << 18)           /*!< R/W 0x100  the predicted hold time after tbtt for beacon tx of port2, unit is 32us*/
#define BIT_TBTT_PROHIBIT_HOLD_P2(x)     (((u32)((x) & 0x00000FFF) << 18))
#define BIT_GET_TBTT_PROHIBIT_HOLD_P2(x) ((u32)(((x >> 18) & 0x00000FFF)))
#define BIT_MASK_BCN_PORT_PRI            ((u32)0x00000003 << 16)           /*!< R/W 0x1  the priority of port0 and port2. 10: port2 has higher priority than port0; 01:port0 has higher priority than port2. 00: port0 and port2 have the same priority*/
#define BIT_BCN_PORT_PRI(x)              (((u32)((x) & 0x00000003) << 16))
#define BIT_GET_BCN_PORT_PRI(x)          ((u32)(((x >> 16) & 0x00000003)))
#define BIT_MASK_DRVERLYITV1             ((u32)0x000000FF << 8)            /*!< R/W 0x05  Time to send interrupt to notify driver to change beacon content. Time unit is TU.  It is used to wake up early at DriverEarlyTime.  For port1*/
#define BIT_DRVERLYITV1(x)               (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_DRVERLYITV1(x)           ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_DIS_RX_BSSID_FIT2            ((u32)0x00000001 << 6)            /*!< R/W 0x0  0:HW will handle rx_beacon 1:HW will ignore rx_beacon_pk. For port2*/
#define BIT_DIS_TSF2_UDT                 ((u32)0x00000001 << 4)            /*!< R/W 0x1  When set, disable port 2 TSF update when beacon frames or probe response frames are received.*/
#define BIT_EN_BCN2_FUNCTION             ((u32)0x00000001 << 3)            /*!< R/W 0x0  When this bit is set, TSF and other beacon related functions are then enabled, for port2*/
/** @} */

/** @defgroup REG_NAN_BCNSPACE
  * @brief
  * @{
  */
#define BIT_MASK_BCN_SPACE4   ((u32)0x0000FFFF << 16)           /*!< R/W 0x200  discovery beacon space*/
#define BIT_BCN_SPACE4(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_BCN_SPACE4(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_BCN_SPACE3   ((u32)0x0000FFFF << 0)            /*!< R/W 0x64  sync beacon space*/
#define BIT_BCN_SPACE3(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BCN_SPACE3(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_NAN_SETTING1
  * @brief
  * @{
  */
#define BIT_MASK_SYNCBCN_RXNUM   ((u32)0x0000001F << 27)           /*!< R/W 0x0  if DW is permitted to end early, the number of rx sync beacons is defined in this register*/
#define BIT_SYNCBCN_RXNUM(x)     (((u32)((x) & 0x0000001F) << 27))
#define BIT_GET_SYNCBCN_RXNUM(x) ((u32)(((x >> 27) & 0x0000001F)))
#define BIT_DW_END_EARLY         ((u32)0x00000001 << 26)           /*!< R/W 0x0  when set, the DW window end earlier than spec definition.  When sync bcn and SDF had tx, and rx enough sync bcns defined by 0x5DC[31:27]. DW can early end*/
#define BIT_MASK_NAN_ROLE        ((u32)0x00000003 << 24)           /*!< R/W 0x0  the role of NAN device, including  master, no-master sync, and no-master no-sync.*/
#define BIT_NAN_ROLE(x)          (((u32)((x) & 0x00000003) << 24))
#define BIT_GET_NAN_ROLE(x)      ((u32)(((x >> 24) & 0x00000003)))
#define BIT_MASK_MSLOT_EVTQ      ((u32)0x000000FF << 16)           /*!< R/W 0x0  evtq packet will tx in the m-th SLOT of the m-th DWs*/
#define BIT_MSLOT_EVTQ(x)        (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MSLOT_EVTQ(x)    ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MDW_EVTQ        ((u32)0x000000FF << 8)            /*!< R/W 0x0  evtq packet will tx in the m-th SLOT of the m-th DWs*/
#define BIT_MDW_EVTQ(x)          (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MDW_EVTQ(x)      ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_HC              ((u32)0x000000FF << 0)            /*!< R/W 0x1  the hop count to anchor master*/
#define BIT_HC(x)                (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_HC(x)            ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_NOA_PARAM
  * @brief
  * @{
  */
#define BIT_MASK_NOA_DURATION_V1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x00001000  The maximum duration in units of microseconds that the P2P Group Owner shall remain absent following the start of a Notice of Absence interval.*/
#define BIT_NOA_DURATION_V1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_NOA_DURATION_V1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NOA_PARAM_1
  * @brief
  * @{
  */
#define BIT_MASK_NOA_INTERVAL_V1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x00003000  The length of the Notice of Absence interval in units of microseconds.*/
#define BIT_NOA_INTERVAL_V1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_NOA_INTERVAL_V1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NOA_PARAM_2
  * @brief
  * @{
  */
#define BIT_MASK_NOA_START_TIME_V1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x00001000  The start time for the schedule expressed in terms of the lower 4 bytes of the TSF timer.*/
#define BIT_NOA_START_TIME_V1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_NOA_START_TIME_V1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NOA_PARAM_3
  * @brief
  * @{
  */
#define BIT_MASK_NOA_COUNT_V3   ((u8)0x000000FF << 0)           /*!< R/W 0x03  indicates the number of absence intervals*/
#define BIT_NOA_COUNT_V3(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_NOA_COUNT_V3(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_NOA_SUBIE
  * @brief
  * @{
  */
#define BIT_MORE_NOA_DESC    ((u32)0x00000001 << 19)          /*!< RO   Set to 1 to indicate that there are more than two descriptors.*/
#define BIT_NOA_DESC1_VALID  ((u32)0x00000001 << 18)          /*!< RO   Set to 1 to indicate that NoA Descriptor1 are valid*/
#define BIT_NOA_DESC0_VALID  ((u32)0x00000001 << 17)          /*!< RO   Set to 1 to indicate that NoA Descriptor0 are valid*/
#define BIT_NOA_HEAD_VALID   ((u32)0x00000001 << 16)          /*!< RO   Set to 1 to indicate that index and CTWindow are valid*/
#define BIT_NOA_OPP_PS       ((u32)0x00000001 << 15)          /*!< RO   Set to 1 to indicate that the P2P Group Owner is using opportunistic power save.*/
#define BIT_MASK_NOA_CTW     ((u32)0x0000007F << 8)           /*!< RO   CTWindow duration*/
#define BIT_NOA_CTW(x)       (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_NOA_CTW(x)   ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_NOA_INDEX   ((u32)0x000000FF << 0)           /*!< RO   Identifies an instance of Notice of Absence timing.*/
#define BIT_NOA_INDEX(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_NOA_INDEX(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_SCH_DBG
  * @brief
  * @{
  */
#define BIT_MASK_SCH_DBG   ((u32)0xFFFFFFFF << 0)           /*!< R   Scheduler debug signals*/
#define BIT_SCH_DBG(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_SCH_DBG(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_SCH_TXCMD
  * @brief
  * @{
  */
#define BIT_MASK_SCH_TXCMD   ((u32)0xFFFFFFFF << 0)           /*!< R   Scheduler TXCMD Content*/
#define BIT_SCH_TXCMD(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_SCH_TXCMD(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/*==========REG_PAGE5 Register Address Definition==========*/
#define REG_EDCA_VO_PARAM                          0x500
#define REG_EDCA_VI_PARAM                          0x504
#define REG_EDCA_BE_PARAM                          0x508
#define REG_EDCA_BK_PARAM                          0x50C
#define REG_BCN_CFG_PIFS                           0x510
#define REG_PIFS                                   0x512
#define REG_RDG_PIFS                               0x513
#define REG_SIFS                                   0x514
#define REG_TSFTR_SYN_OFFSET                       0x518
#define REG_AGGR_BREAK_TIME                        0x51A
#define REG_SLOT                                   0x51B
#define REG_NOA_OFF_ERLY_TIME                      0x51D
#define REG_PS_TIMER_CTRL                          0x51F
#define REG_TXPAUSE_TXPTCL_DISTXREQ_CTRL           0x520
#define REG_RD_CTRL                                0x524
#define REG_MBSSID_CTRL                            0x526
#define REG_P2PPS_CTRL                             0x527
#define REG_PKT_LIFETIME_CTRL                      0x528
#define REG_P2PPS_SPEC_STATE                       0x52B
#define REG_PS_TIMER_A_V2                          0x52C
#define REG_P2PON_DIS_TXTIME                       0x531
#define REG_PS_TIMER_B_V2                          0x534
#define REG_NOA0_TBTT_PROHIBIT                     0x540
#define REG_P2PPS_STATE                            0x543
#define REG_RD_NAV_NXT                             0x544
#define REG_NAV_PROT_LEN                           0x546
#define REG_FTM_SETTING                            0x548
#define REG_FTM_TSF_CNT                            0x54C
#define REG_BCN_CTRL                               0x550
#define REG_BCN_CTRL1                              0x551
#define REG_MBID_NUM                               0x552
#define REG_DUAL_TSF_RST                           0x553
#define REG_PORT0_BCN_SPACE                        0x554
#define REG_ATIMWND0_P0_BCN_ERLY_DMA_CTRL          0x558
#define REG_BCNDMATIM                              0x559
#define REG_ATIMWND                                0x55A
#define REG_USTIME_TSF                             0x55C
#define REG_BCN_MAX_ERR                            0x55D
#define REG_RXTSF_OFFSET_CCK                       0x55E
#define REG_RXTSF_OFFSET_OFDM                      0x55F
#define REG_TSFTR0_L                               0x560
#define REG_TSFTR0_H                               0x564
#define REG_TSFTR1_L                               0x568
#define REG_TSFTR1_H                               0x56C
#define REG_ATIMWND1_V1                            0x570
#define REG_CTWND                                  0x572
#define REG_BCNIVLCUNT                             0x573
#define REG_BCNDROPCTRL                            0x574
#define REG_HGQ_TIMEOUT_PERIOD                     0x575
#define REG_TXCMD_TIMEOUT_PERIOD                   0x576
#define REG_MISC_CTRL                              0x577
#define REG_TSFTR2_L                               0x578
#define REG_TSFTR2_H                               0x57C
#define REG_PS_TIMER0                              0x580
#define REG_PS_TIMER1                              0x584
#define REG_PS_TIMER2                              0x588
#define REG_TBTT_CTN_AREA                          0x58C
#define REG_FORCE_BCN_IFS                          0x58E
#define REG_DRVERLYINT_V1                          0x58F
#define REG_TXOP_MIN                               0x590
#define REG_PRE_BKF_TIME                           0x592
#define REG_CROSS_TXOP_CTRL                        0x593
#define REG_FREERUN_CNT_L                          0x594
#define REG_FREERUN_CNT_H                          0x598
#define REG_ATIMWND2                               0x5A0
#define REG_ATIMWND3                               0x5A1
#define REG_ATIMWND4                               0x5A2
#define REG_ATIMWND5                               0x5A3
#define REG_ATIMWND6                               0x5A4
#define REG_ATIMWND7                               0x5A5
#define REG_ATIMUGT                                0x5A6
#define REG_HIQ_NO_LMT_EN                          0x5A7
#define REG_DTIM_COUNTER_ROOT                      0x5A8
#define REG_DTIM_COUNTER_VAP1                      0x5A9
#define REG_DTIM_COUNTER_VAP2                      0x5AA
#define REG_DTIM_COUNTER_VAP3                      0x5AB
#define REG_DTIM_COUNTER_VAP4                      0x5AC
#define REG_DTIM_COUNTER_VAP5                      0x5AD
#define REG_DTIM_COUNTER_VAP6                      0x5AE
#define REG_DTIM_COUNTER_VAP7                      0x5AF
#define REG_DIS_ATIM                               0x5B0
#define REG_EARLY_128US                            0x5B1
#define REG_TBTT_HOLD_PREDICT_P1                   0x5B2
#define REG_MULTI_BCN_CS                           0x5B3
#define REG_TSFT_SHIFT                             0x5B4
#define REG_P2POFF_DIS_TXTIME                      0x5B7
#define REG_PTA_TRXBCN_CTRL                        0x5B8
#define REG_ACMHWCTRL                              0x5C0
#define REG_ACMRSTCTRL                             0x5C1
#define REG_ACMAVG                                 0x5C2
#define REG_VO_ADMTIME                             0x5C4
#define REG_VI_ADMTIME                             0x5C6
#define REG_BE_ADMTIME                             0x5C8
#define REG_EDCA_RANDOM_GEN                        0x5CC
#define REG_TXCMD_NOA_SEL                          0x5CF
#define REG_DRVERLYINT2                            0x5D0
#define REG_NAN_SETTING                            0x5D4
#define REG_NAN_BCNSPACE                           0x5D8
#define REG_NAN_SETTING1                           0x5DC
#define REG_NOA_PARAM                              0x5E0
#define REG_NOA_PARAM_1                            0x5E4
#define REG_NOA_PARAM_2                            0x5E8
#define REG_NOA_PARAM_3                            0x5EC
#define REG_NOA_SUBIE                              0x5ED
#define REG_SCH_DBG                                0x5F4
#define REG_SCH_TXCMD                              0x5F8
#define REG_PAGE5_DUMMY                            0x5FC

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