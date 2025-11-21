#ifndef _RL6955_REG_PAGE17_WMAC_H_
#define _RL6955_REG_PAGE17_WMAC_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE17_WMAC
  * @brief REG_PAGE17_WMAC driver modules
  * @{
  */




/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE17_WMAC_Register_Definitions REG_PAGE17_WMAC Register Definitions
  * @{
  */

/** @defgroup REG_TWT_BC_ID
  * @brief
  * @{
  */
#define BIT_MASK_BC_TWT_ID   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  twt id bitmap, each bit corresponding to a ID value, only latch the report of valid twt id*/
#define BIT_BC_TWT_ID(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BC_TWT_ID(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TWT_BC_RPT0
  * @brief
  * @{
  */
#define BIT_WMAC_BCN_TWT_PSR       ((u32)0x00000001 << 26)           /*!< R/W 0x0  when set, enable beacon twt broadcast ie parser*/
#define BIT_MASK_TWT_PERSISTENCE   ((u32)0x000000FF << 18)           /*!< R/W 0x0  persistence value, if persistence value in TWT IE is smaller than the reg value, will latch the twt id report*/
#define BIT_TWT_PERSISTENCE(x)     (((u32)((x) & 0x000000FF) << 18))
#define BIT_GET_TWT_PERSISTENCE(x) ((u32)(((x >> 18) & 0x000000FF)))
#define BIT_MASK_TWT_RPT_0         ((u32)0x0000FFFF << 0)            /*!< R/W/ES 0x0  specified twt id report*/
#define BIT_TWT_RPT_0(x)           (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_TWT_RPT_0(x)       ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_TWT_BC_RPT1
  * @brief
  * @{
  */
#define BIT_MASK_TWT_RPT_1   ((u32)0x0000FFFF << 0)           /*!< R/W/ES 0x0  specified twt id report*/
#define BIT_TWT_RPT_1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_TWT_RPT_1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_OPS_RPT_AND_N
  * @brief
  * @{
  */
#define BIT_MASK_MBSSID_N_MEM       ((u32)0x000000FF << 8)           /*!< R/W/ES 0x0  multi-bssid n value*/
#define BIT_MBSSID_N_MEM(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MBSSID_N_MEM(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_OPS_DURATION_RPT   ((u32)0x000000FF << 0)           /*!< R/W/ES 0x0  ops frame duration field report*/
#define BIT_OPS_DURATION_RPT(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_OPS_DURATION_RPT(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RX_CFG
  * @brief rx configure register
  * @{
  */
#define BIT_WMAC_BSS_COLOR_DISABLED ((u32)0x00000001 << 30) /*!< R/W 0x0  sw should set this bit when rx beacon from associated AP*/
#define BIT_VHTNDPA_SUAID_0_EN      ((u32)0x00000001 << 29) /*!< R/W 0x0  when set, ndpa that sta info use 0 as aid will check as fit when rx vht/he ndpa*/
#define BIT_MBA_RSVD_AID_EN         ((u32)0x00000001 << 28) /*!< R/W 0x0  when set, accept multi-sta ba tha use rsvd aid: 2045 in aid_tid_info as response, used in pre assocaition*/
#define BIT_TIM_NO_HIT_REJECT       ((u32)0x00000001 << 27) /*!< R/W 0x0  when set, reject tim no hit beacon*/
#define BIT_DIS_CHK_HENDP_LEN       ((u32)0x00000001 << 26) /*!< R/W 0x0  disable check HE NDP lsig length value*/
#define BIT_CHK_MGNT_BSSID          ((u32)0x00000001 << 25) /*!< R/W 0x0  enable check port0 management frame bssid*/
#define BIT_CHK_CTL_BSSID           ((u32)0x00000001 << 24) /*!< R/W 0x0  enable check port0 control packet bssid,except ack and cts*/
#define BIT_CHKBSSID_MGNT_P1        ((u32)0x00000001 << 23) /*!< R/W 0x0  enable check port1 management frame bssid*/
#define BIT_CHKBSSID_CTL_P1         ((u32)0x00000001 << 22) /*!< R/W 0x0  enable check port1 control frame bssid*/
#define BIT_CHKBSSID_DATA_P1        ((u32)0x00000001 << 21) /*!< R/W 0x0  enable check port1 data frame bssid*/
#define BIT_CHKBSSID_NAN_P2         ((u32)0x00000001 << 20) /*!< R/W 0x0  enable check port2 bssid*/
#define BIT_CHKBSSID_MGNT_P2        ((u32)0x00000001 << 19) /*!< R/W 0x0  when relay mode, enable check port2 management frame bssid*/
#define BIT_INTER_PPDU_REJECT       ((u32)0x00000001 << 18) /*!< R/W 0x0  enable reject inter ppdu*/
#define BIT_EN_MACH_UPD_LEN         ((u32)0x00000001 << 17) /*!< R/W 0x0  enable macrx_pktfifo_ctl update mpdu length in MACHDR_CHK state*/
#define BIT_SNIFFER_TB              ((u32)0x00000001 << 16) /*!< R/W 0x0  enable to receive TB PPDU for debug mode*/
#define BIT_RXPSF_INTER_MPDU        ((u32)0x00000001 << 5)  /*!< R/W 0x0  enable invalid packet check for inter ppdu, inter ppdu valid when plcp and mac header are inter bss*/
#define BIT_SUP_ADDR3_EN            ((u32)0x00000001 << 4)  /*!< R/W 0x0  when set, enable check supper address3*/
#define BIT_CHKBSSID_CTL_P2         ((u32)0x00000001 << 3)  /*!< R/W 0x0  when relay mode, enable check port2 control frame bssid*/
#define BIT_CHKBSSID_DATA_P2        ((u32)0x00000001 << 2)  /*!< R/W 0x0  when relay mode, enable check port2 data frame bssid*/
/** @} */

/** @defgroup REG_LA_EVENT_OPTION
  * @brief
  * @{
  */
#define BIT_MASK_LASTOP_FCS_ERROR   ((u32)0x00000003 << 3)           /*!< R/W 0x0  stop LA record when continue fcs error>= threshold 0:disable;1:4; 2:8;3:12*/
#define BIT_LASTOP_FCS_ERROR(x)     (((u32)((x) & 0x00000003) << 3))
#define BIT_GET_LASTOP_FCS_ERROR(x) ((u32)(((x >> 3) & 0x00000003)))
#define BIT_LASTOP_RX_FSM_HANG      ((u32)0x00000001 << 2)           /*!< R/W 0x0  stop LA record when RX FSM timeout*/
#define BIT_LASTOP_PLCP_ERROR       ((u32)0x00000001 << 1)           /*!< R/W 0x0  stop LA record when RX plcp error occur, include length error, parity error or crc8 error*/
#define BIT_LASTOP_RX_INCOMP        ((u32)0x00000001 << 0)           /*!< R/W 0x0  stop LA record when RX content is incompleted, include PLCP or PSDU are incompleted*/
/** @} */

/** @defgroup REG_AID
  * @brief aid register
  * @{
  */
#define BIT_MASK_AID11   ((u32)0x000007FF << 0)           /*!< R/W 0x0  specified the aid of the sta that mactx response using all ack*/
#define BIT_AID11(x)     (((u32)((x) & 0x000007FF) << 0))
#define BIT_GET_AID11(x) ((u32)(((x >> 0) & 0x000007FF)))
/** @} */

/** @defgroup REG_TRAN_BSSID0_L
  * @brief trasmitted bssid register0_l
  * @{
  */
#define BIT_MASK_WMAC_TRANSBSSID0_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  lower 32 bits of transmitted bssid0*/
#define BIT_WMAC_TRANSBSSID0_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_WMAC_TRANSBSSID0_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TRAN_BSSID0_H
  * @brief trasmitted bssid register0_h
  * @{
  */
#define BIT_MBSSID_IN_ORDER           ((u32)0x00000001 << 30)           /*!< R/W 0x0  transbssid direct mask, not change order*/
#define BIT_MASK_BSS_COLOR2           ((u32)0x0000003F << 24)           /*!< R/W 0x0  bss color of current BSS of port1*/
#define BIT_BSS_COLOR2(x)             (((u32)((x) & 0x0000003F) << 24))
#define BIT_GET_BSS_COLOR2(x)         ((u32)(((x >> 24) & 0x0000003F)))
#define BIT_EN_PARTAID                ((u32)0x00000001 << 23)           /*!< R/W 0x0  enable inter ppdu decision according to partial aid for VHT ppdu*/
#define BIT_EN_MBSSID                 ((u32)0x00000001 << 22)           /*!< R/W 0x0  enable multibssid function for transmitted bssid compare*/
#define BIT_MASK_BSS_COLOR0           ((u32)0x0000003F << 16)           /*!< R/W 0x0  bss color of current BSS of port0*/
#define BIT_BSS_COLOR0(x)             (((u32)((x) & 0x0000003F) << 16))
#define BIT_GET_BSS_COLOR0(x)         ((u32)(((x >> 16) & 0x0000003F)))
#define BIT_MASK_WMAC_TRANSBSSID0_H   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  higher 16 bits of transmitted bssid0*/
#define BIT_WMAC_TRANSBSSID0_H(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_WMAC_TRANSBSSID0_H(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MAC_PHY_CONTROL
  * @brief
  * @{
  */
#define BIT_ID_MATCH_MPDU            ((u32)0x00000001 << 21)           /*!< R/W 0x0  when set, per mpdu will trigger rx_id_match, else per ppdu trigger*/
#define BIT_MASK_ID_MATCH_CNT        ((u32)0x0000007F << 14)           /*!< R/W 7'h1f  rx macid match pulse counter, unit is mac clock*/
#define BIT_ID_MATCH_CNT(x)          (((u32)((x) & 0x0000007F) << 14))
#define BIT_GET_ID_MATCH_CNT(x)      ((u32)(((x >> 14) & 0x0000007F)))
#define BIT_MASK_INVALID_PKT_CNT     ((u32)0x000000FF << 6)            /*!< R/W 8'hf  invalid packet pulse counter, unit is mac clock*/
#define BIT_INVALID_PKT_CNT(x)       (((u32)((x) & 0x000000FF) << 6))
#define BIT_GET_INVALID_PKT_CNT(x)   ((u32)(((x >> 6) & 0x000000FF)))
#define BIT_MASK_RXPKT_OK_FAIL_CNT   ((u32)0x0000003F << 0)            /*!< R/W 6'h9  rxpkt ok or fail pulse counter, unit is mac clock*/
#define BIT_RXPKT_OK_FAIL_CNT(x)     (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_RXPKT_OK_FAIL_CNT(x) ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_GID_POS_EN_L
  * @brief VHT group id position enable register
  * @{
  */
#define BIT_MASK_GID_POSITION_EN_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  VHT group id position enable*/
#define BIT_GID_POSITION_EN_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_GID_POSITION_EN_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_GID_POS0
  * @brief VHT group id position0 register
  * @{
  */
#define BIT_MASK_GID_POSITION0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  VHT group id position0*/
#define BIT_GID_POSITION0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_GID_POSITION0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_GID_POS1
  * @brief VHT group id position1 register
  * @{
  */
#define BIT_MASK_GID_POSITION1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  VHT group id position1*/
#define BIT_GID_POSITION1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_GID_POSITION1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_GID_POS2
  * @brief VHT group id position2 register
  * @{
  */
#define BIT_MASK_GID_POSITION2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  VHT group id position2*/
#define BIT_GID_POSITION2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_GID_POSITION2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_GID_POS3
  * @brief VHT group id position3 register
  * @{
  */
#define BIT_MASK_GID_POSITION3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  VHT group id position3*/
#define BIT_GID_POSITION3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_GID_POSITION3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BSSCOLOR_BITMAP_L
  * @brief bss color bitmap register_l
  * @{
  */
#define BIT_MASK_BSSCOLOR_BITMAP_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  low 32bits bss color bitmap*/
#define BIT_BSSCOLOR_BITMAP_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BSSCOLOR_BITMAP_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BSSCOLOR_BITMAP_H
  * @brief bss color bitmap register_h
  * @{
  */
#define BIT_MASK_BSSCOLOR_BITMAP_H   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  high 32bits bss color bitmap*/
#define BIT_BSSCOLOR_BITMAP_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BSSCOLOR_BITMAP_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PBSSID_BITMAP_L
  * @brief partial bssid bitmap register_l
  * @{
  */
#define BIT_MASK_PARTIAL_BSSID_BITMAP_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  low 32bits partial bssid bitmap*/
#define BIT_PARTIAL_BSSID_BITMAP_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_PARTIAL_BSSID_BITMAP_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PBSSID_BITMAP_H
  * @brief partial bssid bitmap register_h
  * @{
  */
#define BIT_MASK_PARTIAL_BSSID_BITMAP_H   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  high 32bits partial bssid bitmap*/
#define BIT_PARTIAL_BSSID_BITMAP_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_PARTIAL_BSSID_BITMAP_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_SR_CFG0
  * @brief spatial reuse configure register0
  * @{
  */
#define BIT_SPRUSE_RSVD_EN   ((u32)0x00000001 << 3) /*!< R/W 0x0  enable spatia reuse when plcp header spratial reuse field vaule smaller than 14 or value is 15 and is srg ppdu*/
#define BIT_CTL_SRG_CHECK_EN ((u32)0x00000001 << 2) /*!< R/W 0x0  enable control packet srg ppdu check*/
#define BIT_SRG_CHECK_EN     ((u32)0x00000001 << 1) /*!< R/W 0x0  enable srg ppdu check*/
#define BIT_SR_EN            ((u32)0x00000001 << 0) /*!< R/W 0x0  enable spatial reuse function*/
/** @} */

/** @defgroup REG_SR_CFG1
  * @brief spatial reuse configure register1
  * @{
  */
#define BIT_MASK_NONSRG_OBSS_PD_MAX   ((u32)0x000000FF << 24)           /*!< R/W 0x0  the maximum value of non_SRG OBSS_PD*/
#define BIT_NONSRG_OBSS_PD_MAX(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_NONSRG_OBSS_PD_MAX(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_NONSRG_OBSS_PD_MIN   ((u32)0x000000FF << 16)           /*!< R/W 0x0  the minimum value of non_SRG OBSS_PD*/
#define BIT_NONSRG_OBSS_PD_MIN(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_NONSRG_OBSS_PD_MIN(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_SRG_OBSS_PD_MAX      ((u32)0x000000FF << 8)            /*!< R/W 0x0  the maximum value of OBSS_PD*/
#define BIT_SRG_OBSS_PD_MAX(x)        (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_SRG_OBSS_PD_MAX(x)    ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_SRG_OBSS_PD_MIN      ((u32)0x000000FF << 0)            /*!< R/W 0x0  the minimum value of OBSS_PD*/
#define BIT_SRG_OBSS_PD_MIN(x)        (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_SRG_OBSS_PD_MIN(x)    ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_MACTX_SR
  * @brief SR field configure
  * @{
  */
#define BIT_MASK_WMAC_WAIT_PHY_REF    ((u32)0x0000003F << 18)           /*!< R/W 0x10  mactx hang handle,wait phytxon timeout*/
#define BIT_WMAC_WAIT_PHY_REF(x)      (((u32)((x) & 0x0000003F) << 18))
#define BIT_GET_WMAC_WAIT_PHY_REF(x)  ((u32)(((x >> 18) & 0x0000003F)))
#define BIT_WMAC_SR_FIELD_EN          ((u32)0x00000001 << 17)           /*!< R/W 0x0  enable sr field reg cfg*/
#define BIT_WMAC_SR_VAL15_ALLOW       ((u32)0x00000001 << 16)           /*!< R/W 0x0  sr field can be the value 15*/
#define BIT_MASK_WMAC_PLCP_SR_FIELD   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  value of SR field*/
#define BIT_WMAC_PLCP_SR_FIELD(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_WMAC_PLCP_SR_FIELD(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MACTX_MISC
  * @brief misc ctrl cfg
  * @{
  */
#define BIT_TXTIME_CAL_DISGCLK      ((u32)0x00000001 << 30)           /*!< R/W 0x0  disable the clock gating of the txtime compute module*/
#define BIT_WMAC_CCK_LOCKED_CLK     ((u32)0x00000001 << 29)           /*!< R/W 0x1  indicate that the transmit freuqency and symbol clocks are derived from the same oscilator*/
#define BIT_MASK_WMAC_RST_BB_CNT    ((u32)0x00000007 << 26)           /*!< R/W 0x3  macclk cycle number of wmac_rst_bb signal*/
#define BIT_WMAC_RST_BB_CNT(x)      (((u32)((x) & 0x00000007) << 26))
#define BIT_GET_WMAC_RST_BB_CNT(x)  ((u32)(((x >> 26) & 0x00000007)))
#define BIT_SW_TXDFIFO_RDY          ((u32)0x00000001 << 11)           /*!< R/W/ES 0x0  sw read txd fifo ready*/
#define BIT_MASK_SW_TXDFIFO_ADDR    ((u32)0x0000007F << 4)            /*!< R/W 0x0  sw read txd fifo address,[6:1] is address, [0] : 0 read low 32bit; 1 read high 32bit;*/
#define BIT_SW_TXDFIFO_ADDR(x)      (((u32)((x) & 0x0000007F) << 4))
#define BIT_GET_SW_TXDFIFO_ADDR(x)  ((u32)(((x >> 4) & 0x0000007F)))
#define BIT_WMAC_FORCE_READ_TXDFIFO ((u32)0x00000001 << 3)            /*!< R/W 0x0  during tx procedure, force read txd fifo, which is only use at the situation when bb is hang.*/
#define BIT_WMAC_SW_RD              ((u32)0x00000001 << 2)            /*!< R/W 0x0  eanble sw read txdfifo*/
#define BIT_EOFPAD_EN               ((u32)0x00000001 << 0)            /*!< R/W 0x1  enable eof pad operation at the end of mpdu*/
/** @} */

/** @defgroup REG_MACTX_MHDR0
  * @brief MAC header configure
  * @{
  */
#define BIT_UPH_CAS_QOS_SEL                ((u32)0x00000001 << 31)           /*!< R/W 0x0  HTC field UPH+CAS format enable,only work in tb_ppdu*/
#define BIT_QNULL_ACK_POL_VAL              ((u32)0x00000001 << 30)           /*!< R/W 0x1  ack policy bit of tb qos null*/
#define BIT_WMAC_EN_HW_SSN                 ((u32)0x00000001 << 29)           /*!< R/W 0x1  enable the hw ssn for qos null frame*/
#define BIT_TB_QOSNULL_PWRMGT_VAL          ((u32)0x00000001 << 28)           /*!< R/W 0x0  the power bit in tb qos null, used during twt operation*/
#define BIT_TCR_BA_RSVD_VAL                ((u32)0x00000001 << 26)           /*!< R/W 0x0  multi-sta BA bactl rsvd filed value*/
#define BIT_MASK_QOS_NULL_TID_VAL          ((u32)0x0000000F << 22)           /*!< R/W 0x0  tid value of qos null*/
#define BIT_QOS_NULL_TID_VAL(x)            (((u32)((x) & 0x0000000F) << 22))
#define BIT_GET_QOS_NULL_TID_VAL(x)        ((u32)(((x >> 22) & 0x0000000F)))
#define BIT_MASK_WMAC_LEGACY_USTIMER       ((u32)0x0000001F << 17)           /*!< R/W 0xA  timer cnt before bb fetch txd for ofdm, for underflow setting*/
#define BIT_WMAC_LEGACY_USTIMER(x)         (((u32)((x) & 0x0000001F) << 17))
#define BIT_GET_WMAC_LEGACY_USTIMER(x)     ((u32)(((x >> 17) & 0x0000001F)))
#define BIT_MASK_WMAC_NON_LEGACY_USTIMER   ((u32)0x0000001F << 12)           /*!< R/W 0xD  timer cnt before bb fetch txd for he/vht/ht/cck, for underflow setting*/
#define BIT_WMAC_NON_LEGACY_USTIMER(x)     (((u32)((x) & 0x0000001F) << 12))
#define BIT_GET_WMAC_NON_LEGACY_USTIMER(x) ((u32)(((x >> 12) & 0x0000001F)))
#define BIT_MASK_BQR_PRIMCH                ((u32)0x00000007 << 9)            /*!< R/W 0x0  shift bqr bitmap to the allocated primary 20M channel*/
#define BIT_BQR_PRIMCH(x)                  (((u32)((x) & 0x00000007) << 9))
#define BIT_GET_BQR_PRIMCH(x)              ((u32)(((x >> 9) & 0x00000007)))
#define BIT_MASK_BQR_TID_VAL               ((u32)0x0000000F << 5)            /*!< R/W 0x0  bandwidth query report TID value*/
#define BIT_BQR_TID_VAL(x)                 (((u32)((x) & 0x0000000F) << 5))
#define BIT_GET_BQR_TID_VAL(x)             ((u32)(((x >> 5) & 0x0000000F)))
#define BIT_BSR_QOS_SEL                    ((u32)0x00000001 << 4)            /*!< R/W 0x0  HTC field BSR format enable,only work in tb_ppdu*/
#define BIT_BSR_VO_TID_SEL                 ((u32)0x00000001 << 3)            /*!< R/W 0x0  1: tid 7; 0: tid 6;*/
#define BIT_BSR_VI_TID_SEL                 ((u32)0x00000001 << 2)            /*!< R/W 0x0  1: tid 5; 0: tid 4;*/
#define BIT_BSR_BE_TID_SEL                 ((u32)0x00000001 << 1)            /*!< R/W 0x0  1: tid 2; 0: tid 1;*/
#define BIT_BSR_BK_TID_SEL                 ((u32)0x00000001 << 0)            /*!< R/W 0x0  1: tid 3; 0: tid 0;*/
/** @} */

/** @defgroup REG_MACTX_TXD_FIFO
  * @brief fifo do
  * @{
  */
#define BIT_MASK_SW_TXDFIFO_DOUT   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  sw read rxd_out*/
#define BIT_SW_TXDFIFO_DOUT(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_SW_TXDFIFO_DOUT(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_RXTRIG_TEST_COMM_0
  * @brief
  * @{
  */
#define BIT_MASK_RXTRIG_COMMON_0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  low 32bit of comm field in trigger frame of test mode*/
#define BIT_RXTRIG_COMMON_0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_RXTRIG_COMMON_0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_RXTRIG_TEST_COMM_1
  * @brief
  * @{
  */
#define BIT_MASK_RXTRIG_COMMON_1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  high32bit of comm field in trigger frame of test mode*/
#define BIT_RXTRIG_COMMON_1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_RXTRIG_COMMON_1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_RXTRIG_TEST_USER_0
  * @brief
  * @{
  */
#define BIT_MASK_RXTRIG_USERINFO_0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  low 32bit of user field in trigger frame of test mode*/
#define BIT_RXTRIG_USERINFO_0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_RXTRIG_USERINFO_0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_RXTRIG_TEST_USER_1
  * @brief
  * @{
  */
#define BIT_MASK_RXTRIG_USERINFO_1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  high 32bit of user field in trigger frame of test mode*/
#define BIT_RXTRIG_USERINFO_1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_RXTRIG_USERINFO_1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_RXTRIG_TEST_USER_2
  * @brief
  * @{
  */
#define BIT_MASK_RXTRIG_BSS_COLOR    ((u32)0x0000003F << 26)           /*!< R/W 0x0  */
#define BIT_RXTRIG_BSS_COLOR(x)      (((u32)((x) & 0x0000003F) << 26))
#define BIT_GET_RXTRIG_BSS_COLOR(x)  ((u32)(((x >> 26) & 0x0000003F)))
#define BIT_MASK_RXTRIG_MACID        ((u32)0x0000007F << 19)           /*!< R/W 0x0  macid*/
#define BIT_RXTRIG_MACID(x)          (((u32)((x) & 0x0000007F) << 19))
#define BIT_GET_RXTRIG_MACID(x)      ((u32)(((x >> 19) & 0x0000007F)))
#define BIT_RXTRIG_FCSCHK_EN         ((u32)0x00000001 << 18)           /*!< R/W 0x0  1:enable fcs check*/
#define BIT_RXTRIG_PORT_SEL          ((u32)0x00000001 << 17)           /*!< R/W 0x0  port sel*/
#define BIT_RXTRIG_EN                ((u32)0x00000001 << 16)           /*!< WA0 0x0  enable rx trigger test mode*/
#define BIT_MASK_RXTRIG_USERINFO_2   ((u32)0x000000FF << 0)            /*!< R/W 0x0  L*/
#define BIT_RXTRIG_USERINFO_2(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_RXTRIG_USERINFO_2(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RXTRIG_TEST_CTRL
  * @brief
  * @{
  */
#define BIT_RXTRIG_RU26_DIS        ((u32)0x00000001 << 31)          /*!< R/W 0x0  disable response to trigger frame when ru allocation addressed to me is 26-tone*/
#define BIT_UL_MU_DIS              ((u32)0x00000001 << 25)          /*!< R/W 0x0  Disable to respond UL response triggered by any trigger frame. Per port config.*/
#define BIT_UL_MU_DATA_DIS         ((u32)0x00000001 << 24)          /*!< R/W 0x0  Disable to respond UL data triggered by basic trigger frame. Per port config. (BA/ACK/BSR/BQR are still allowed to Tx)*/
#define BIT_MASK_RXTRIG_DURATION   ((u32)0x0000FFFF << 8)           /*!< R/W 0x0  duration of trigger frame*/
#define BIT_RXTRIG_DURATION(x)     (((u32)((x) & 0x0000FFFF) << 8))
#define BIT_GET_RXTRIG_DURATION(x) ((u32)(((x >> 8) & 0x0000FFFF)))
#define BIT_MASK_RXTRIG_STATUS     ((u32)0x000000FF << 0)           /*!< R 0x0  [7:4]:trig_cntr [3:0]:ctl_state*/
#define BIT_RXTRIG_STATUS(x)       (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_RXTRIG_STATUS(x)   ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_SIFS_TIMING_CTRL_CCK
  * @brief
  * @{
  */
#define BIT_MASK_R2T_SIFS_CCK   ((u32)0x000003FF << 10)           /*!< R/W 0x46  This register sets the SIFS time required for any immediate response for example Data-Ack. It is in unit of 100ns.(default:7.5us)*/
#define BIT_R2T_SIFS_CCK(x)     (((u32)((x) & 0x000003FF) << 10))
#define BIT_GET_R2T_SIFS_CCK(x) ((u32)(((x >> 10) & 0x000003FF)))
#define BIT_MASK_T2T_SIFS_CCK   ((u32)0x000003FF << 0)            /*!< R/W 0x46  This register sets the SIFS time required for consecutive TX events for example CTS-Data, or broadcast bursting. It is in unit of 100ns.(default:7.5us)*/
#define BIT_T2T_SIFS_CCK(x)     (((u32)((x) & 0x000003FF) << 0))
#define BIT_GET_T2T_SIFS_CCK(x) ((u32)(((x >> 0) & 0x000003FF)))
/** @} */

/** @defgroup REG_SIFS_TIMING_CTRL_OFDM
  * @brief
  * @{
  */
#define BIT_MASK_RX_AIR_END_TIME   ((u32)0x000000FF << 24)           /*!< R/W 0x3D  This register sets the time from cca fall to 6us. It is in unit of 100ns.(default:6us)*/
#define BIT_RX_AIR_END_TIME(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_RX_AIR_END_TIME(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_R2T_SIFS_OFDM     ((u32)0x000003FF << 10)           /*!< R/W 0x82  This register sets the SIFS time required for any immediate response for example Data-Ack. It is in unit of 100ns.(default:12.6us)*/
#define BIT_R2T_SIFS_OFDM(x)       (((u32)((x) & 0x000003FF) << 10))
#define BIT_GET_R2T_SIFS_OFDM(x)   ((u32)(((x >> 10) & 0x000003FF)))
#define BIT_MASK_T2T_SIFS_OFDM     ((u32)0x000003FF << 0)            /*!< R/W 0x82  This register sets the SIFS time required for consecutive TX events for example CTS-Data, or broadcast bursting. It is in unit of 100ns.(default:13us)*/
#define BIT_T2T_SIFS_OFDM(x)       (((u32)((x) & 0x000003FF) << 0))
#define BIT_GET_T2T_SIFS_OFDM(x)   ((u32)(((x >> 0) & 0x000003FF)))
/** @} */

/** @defgroup REG_AX_TB_TIMING_CTRL
  * @brief
  * @{
  */
#define BIT_RX_ACKMD_EN           ((u32)0x00000001 << 22)           /*!< R/W 0x0  receive ack frame will generate interrupt of ack_more_data=0/1*/
#define BIT_RX_MORE_TF_EN         ((u32)0x00000001 << 21)           /*!< R/W 0x0  receive trigger frame within my bssid but not addressed to me will generate interrupt of more_tf=0/1*/
#define BIT_TB_SIFS_USE_NORMAL    ((u32)0x00000001 << 20)           /*!< R/W 0x0  1:choose 0x179c sifs when rx trigger 0:choose 0x17A0[19:10] sifs when rx trigger*/
#define BIT_MASK_TB_SIFS_REF      ((u32)0x000003FF << 10)           /*!< R/W 0x7e  This register sets the for sifs time between cca falling edge of trigger frame and mactx_enable rising edge.It is in unit of 100ns.(default:12.6us)*/
#define BIT_TB_SIFS_REF(x)        (((u32)((x) & 0x000003FF) << 10))
#define BIT_GET_TB_SIFS_REF(x)    ((u32)(((x >> 10) & 0x000003FF)))
#define BIT_MASK_TB_TIMEOUT_REF   ((u32)0x000003FF << 0)            /*!< R/W 0x6A  This register sets the max time for tb data aggragation, It is in unit of 100ns.(default:12us)*/
#define BIT_TB_TIMEOUT_REF(x)     (((u32)((x) & 0x000003FF) << 0))
#define BIT_GET_TB_TIMEOUT_REF(x) ((u32)(((x >> 0) & 0x000003FF)))
/** @} */

/** @defgroup REG_SR_CONTROL_DBG
  * @brief
  * @{
  */
#define BIT_RXPPDU_SRG         ((u32)0x00000001 << 27)           /*!< R 0x0  the received pkt is an srg ppdu*/
#define BIT_SR_UPD_EN          ((u32)0x00000001 << 26)           /*!< R 0x0  the received pkt is allowed to update basic nav*/
#define BIT_SR_RESTRICTED      ((u32)0x00000001 << 25)           /*!< R 0x0  the spatial reuse type is restricted*/
#define BIT_MASK_SR_PD_TX      ((u32)0x000001FF << 16)           /*!< R 0x0  the value of received power level minus obss_pd_min*/
#define BIT_SR_PD_TX(x)        (((u32)((x) & 0x000001FF) << 16))
#define BIT_GET_SR_PD_TX(x)    ((u32)(((x >> 16) & 0x000001FF)))
#define BIT_MASK_SR_TIMER_TX   ((u32)0x0000FFFF << 0)            /*!< R 0x0  time can be used for spatial reuse*/
#define BIT_SR_TIMER_TX(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_SR_TIMER_TX(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_NAV_CTRL
  * @brief
  * @{
  */
#define BIT_WMAC_STOP_UPD_INTRANAV       ((u16)0x00000001 << 13)          /*!< R/W 0x0  disable updating intra nav*/
#define BIT_WMAC_STOP_UPD_BASICNAV       ((u16)0x00000001 << 12)          /*!< R/W 0x0  disable updating basic nav*/
#define BIT_WMAC_TF_UP_NAV_EN            ((u16)0x00000001 << 11)          /*!< R/W 0x1  1:enable updating intra nav when receiving trigger frame*/
#define BIT_SRCTRL_PLCP_EN               ((u16)0x00000001 << 10)          /*!< R/W 0x0  1:use txop_dur as sr_tx_timer*/
#define BIT_WMAC_INTRANAV_INTXOP         ((u16)0x00000001 << 9)           /*!< R/W 0x1  enable updating intra nav in my txop*/
#define BIT_WMAC_BASICNAV_INTXOP         ((u16)0x00000001 << 8)           /*!< R/W 0x1  enable updating basic nav in my txop*/
#define BIT_MASK_SR_USABLE_TIMER_THRES   ((u16)0x000000FF << 0)           /*!< R/W 0x4  If received pkt can operate spatial reuse,the min threshold for sr_timer_tx. unit:256us(default:1024us)*/
#define BIT_SR_USABLE_TIMER_THRES(x)     (((u16)((x) & 0x000000FF) << 0))
#define BIT_GET_SR_USABLE_TIMER_THRES(x) ((u16)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RESP_CONTROL
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_SIFS_BUSY_DELAY   ((u16)0x000003FF << 6)           /*!< R/W 0x1  start to check channel status after a period of delay start from edcca falling edge,unit:100ns*/
#define BIT_WMAC_SIFS_BUSY_DELAY(x)     (((u16)((x) & 0x000003FF) << 6))
#define BIT_GET_WMAC_SIFS_BUSY_DELAY(x) ((u16)(((x >> 6) & 0x000003FF)))
#define BIT_RESP_TX_WITH_FCSERR         ((u16)0x00000001 << 4)           /*!< R/W 0x0  1:if resp_chk_fcs is low and mactx starts to generate mpdu,will tx response with wrong crc32*/
#define BIT_RESP_CHK_FCS_ABORT_TX       ((u16)0x00000001 << 3)           /*!< R/W 0x0  1:if resp_chk_fcs is low when sifs reach,will not respond to the received packet*/
#define BIT_RESP_GI_LTF_USE_RX          ((u16)0x00000001 << 2)           /*!< R/W 0x0  1:will use gi ltf type in rxpkt*/
#define BIT_RESP_ERSU_USE_RX            ((u16)0x00000001 << 1)           /*!< R/W 0x1  enable response tx with ersu when rx ersu*/
#define BIT_RESP_DCM_USE_RX             ((u16)0x00000001 << 0)           /*!< R/W 0x1  enable response tx with dcm when rx dcm*/
/** @} */

/** @defgroup REG_NAV_STATUS
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_INTRA_NAV_DUR   ((u32)0x00003FFF << 16)           /*!< R 0x0  intra_nav*/
#define BIT_WMAC_INTRA_NAV_DUR(x)     (((u32)((x) & 0x00003FFF) << 16))
#define BIT_GET_WMAC_INTRA_NAV_DUR(x) ((u32)(((x >> 16) & 0x00003FFF)))
#define BIT_MASK_WMAC_BASIC_NAV_DUR   ((u32)0x00003FFF << 0)            /*!< R 0x0  basic_nav*/
#define BIT_WMAC_BASIC_NAV_DUR(x)     (((u32)((x) & 0x00003FFF) << 0))
#define BIT_GET_WMAC_BASIC_NAV_DUR(x) ((u32)(((x >> 0) & 0x00003FFF)))
/** @} */

/** @defgroup REG_RESP_CONTROL_1
  * @brief
  * @{
  */
#define BIT_RESP_CHK_TXNAV          ((u32)0x00000001 << 31)           /*!< R/W 0x0  check txnav when need to response*/
#define BIT_RESP_CHK_INTRA_NAV      ((u32)0x00000001 << 30)           /*!< R/W 0x1  check intra nav when need to response*/
#define BIT_RESP_CHK_BASIC_NAV      ((u32)0x00000001 << 29)           /*!< R/W 0x1  check basic nav when need to response*/
#define BIT_RESP_HTC_EN             ((u32)0x00000001 << 27)           /*!< R/W 0x0  enable appending htc  when need to response*/
#define BIT_RESP_RATE_DOWNGRADE     ((u32)0x00000001 << 26)           /*!< R/W 0x0  enable downgrade response rate from HE to VHT, VHT to HT, HE to HT when need to response*/
#define BIT_RESP_DCM_EN             ((u32)0x00000001 << 25)           /*!< R/W 0x1  enable using dcm need to response*/
#define BIT_RESP_DCM_ONLY_MCS0      ((u32)0x00000001 << 24)           /*!< R/W 0x0  limit response rate to MCS0 when response tx with HE DCM packet*/
#define BIT_RESP_TBPPDU_CHK_PWR     ((u32)0x00000001 << 23)           /*!< R/W 0x1  check tb ppdu tx power when rx trigger, if txpwr_ctrl send signal of abort,will not reply with tb ppdu*/
#define BIT_RESP_RXTRIG_CHK_INSIFS  ((u32)0x00000001 << 22)           /*!< R/W 0x1  check whether channel is idle during sifs, if csreq=1 in trigger frame, will not reply with tb ppdu*/
#define BIT_RESP_CHK_EDCCA          ((u32)0x00000001 << 21)           /*!< R/W 0x1  check edcca when response*/
#define BIT_RESP_CHK_BTCCA          ((u32)0x00000001 << 20)           /*!< R/W 0x0  check btcca when response*/
#define BIT_RESP_CHK_SEC_CCA20      ((u32)0x00000001 << 19)           /*!< R/W 0x0  check sec 20 cca when response*/
#define BIT_RESP_BMOD_WI_RTK_SIG    ((u32)0x00000001 << 18)           /*!< R/W 0x1  mac will tx response with b mode special preamble when receiving b mode with special preamble*/
#define BIT_RESP_TXACK_WITH_A1MATCH ((u32)0x00000001 << 17)           /*!< R/W 0x0  check if rx a1=r_macid0/1 with all bits matched*/
#define BIT_SIFS_ABORT_TB           ((u32)0x00000001 << 16)           /*!< R/W 0x0  abort ptcl generate tb cmd when sifs reach*/
#define BIT_MASK_RESP_GI_LTF        ((u32)0x00000007 << 13)           /*!< R/W 0x0  5:1x+0.8 4:1x+1.6 3:2x+0.8 2:2x+1.6 1:4x+0.8 0:4x+3.2 not support 1x+1.6 when response*/
#define BIT_RESP_GI_LTF(x)          (((u32)((x) & 0x00000007) << 13))
#define BIT_GET_RESP_GI_LTF(x)      ((u32)(((x >> 13) & 0x00000007)))
#define BIT_RESP_CHK_ZBCCA          ((u32)0x00000001 << 12)           /*!< R/W 0x0  check zigbee cca when response*/
#define BIT_RESP_CHK_EDCCA_PER20    ((u32)0x00000001 << 11)           /*!< R/W 0x0  check edcca_per20_bitmap_sifs[0] when tx response*/
#define BIT_DIS_CHK_TB_RESP         ((u32)0x00000001 << 9)            /*!< R/W 0x0  if tx tb and receive pgack ,consider as tx ok if this option is enabled*/
#define BIT_DIS_CHK_SMPDU_RESP      ((u32)0x00000001 << 8)            /*!< R/W 0x0  if tx smpdu and receive ack or mba,consider as tx ok if this option is enabled*/
#define BIT_CHK_AMPDU_RESP_MBA_ACK  ((u32)0x00000001 << 7)            /*!< R/W 0x0  if tx ampdu or tb data and receive mba_ack, consider as tx ok if this option is enabled*/
#define BIT_MASK_RESP_TXRATE        ((u32)0x0000007F << 0)            /*!< R/W 0x04  tx rate use to decide response rate*/
#define BIT_RESP_TXRATE(x)          (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_RESP_TXRATE(x)      ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_RESP_RATE_RRSR
  * @brief
  * @{
  */
#define BIT_MASK_RESP_RRSR_HE     ((u32)0x000000FF << 24)           /*!< R/W 0x1  Data Rate Control Table Register  BitMap to indicate the response/protection/expected_response rate to use in this BSS. All management and control response frames should obey the rates set in the bitmap. Each bit is mapped as the following:   HE 1SS MCS0~MCS7  Response rate must be less than or equal to the rate of the initiating frame. If none of the bits are set, no response is generated by Rtl8712. If both the legacy rates and HT rates are defined as Basic Rates, fill in only the legacy portion of the bitmap. If only HT rates are defined as Basic Rates, fill in both the legacy and HT portion of the bitmap.*/
#define BIT_RESP_RRSR_HE(x)       (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_RESP_RRSR_HE(x)   ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_RESP_RRSR_VHT    ((u32)0x000000FF << 16)           /*!< R/W 0x1  VHT 1SS MCS0~MCS7*/
#define BIT_RESP_RRSR_VHT(x)      (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_RESP_RRSR_VHT(x)  ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_RESP_RRSR_HT     ((u32)0x000000FF << 8)            /*!< R/W 0x1  HT 1SS MCS0~MCS7*/
#define BIT_RESP_RRSR_HT(x)       (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_RESP_RRSR_HT(x)   ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_RESP_RRSR_OFDM   ((u32)0x000000FF << 0)            /*!< R/W 0x1  {6M, 9M, 12M, 18M, 24M, 36M, 48M, 54M}*/
#define BIT_RESP_RRSR_OFDM(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_RESP_RRSR_OFDM(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RESP_RATE_RRSR_1
  * @brief
  * @{
  */
#define BIT_MASK_RRSR_SC         ((u32)0x00000003 << 8)           /*!< R/W 0x0  Response frame sub-channel configuration. Response frames (CTS, ACK, BA) are transmitted in the following condition. 00: Primary 20Mhz BW(0x483[3:0] = 0x8AC[5:2]). 01: Follow Rx packet BW mode. 10: Duplicate mode.*/
#define BIT_RRSR_SC(x)           (((u32)((x) & 0x00000003) << 8))
#define BIT_GET_RRSR_SC(x)       ((u32)(((x >> 8) & 0x00000003)))
#define BIT_MASK_RESP_RRSR_CCK   ((u32)0x0000000F << 4)           /*!< R/W 0x3  {1M, 2M, 5.5M, 11M }*/
#define BIT_RESP_RRSR_CCK(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_RESP_RRSR_CCK(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_RESP_RATE_EN    ((u32)0x0000000F << 0)           /*!< R/W 0xf  [0]:enable respnse rate of CCK and OFDM [1]:enable respnse rate of HT [2]:enable respnse rate of VHT [3]:enable respnse rate of HE*/
#define BIT_RESP_RATE_EN(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_RESP_RATE_EN(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_BEAMFORMING_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_WMAC_HE_CSI_RATE     ((u32)0x0000003F << 23)           /*!< R/W 0x30  HE CSI init rate(HE mode+ MCS)*/
#define BIT_WMAC_HE_CSI_RATE(x)       (((u32)((x) & 0x0000003F) << 23))
#define BIT_GET_WMAC_HE_CSI_RATE(x)   ((u32)(((x >> 23) & 0x0000003F)))
#define BIT_MASK_WMAC_VHT_CSI_RATE    ((u32)0x0000003F << 17)           /*!< R/W 0x20  VHT CSI init rate(VHT mode + MCS)*/
#define BIT_WMAC_VHT_CSI_RATE(x)      (((u32)((x) & 0x0000003F) << 17))
#define BIT_GET_WMAC_VHT_CSI_RATE(x)  ((u32)(((x >> 17) & 0x0000003F)))
#define BIT_MASK_WMAC_HT_CSI_RATE     ((u32)0x0000003F << 11)           /*!< R/W 0x10  HT CSI init rate(HT mode  + MCS)*/
#define BIT_WMAC_HT_CSI_RATE(x)       (((u32)((x) & 0x0000003F) << 11))
#define BIT_GET_WMAC_HT_CSI_RATE(x)   ((u32)(((x >> 11) & 0x0000003F)))
#define BIT_MASK_WMAC_OFDM_CSI_RATE   ((u32)0x0000003F << 5)            /*!< R/W 0x4  ODFM CSI INIT RATE*/
#define BIT_WMAC_OFDM_CSI_RATE(x)     (((u32)((x) & 0x0000003F) << 5))
#define BIT_GET_WMAC_OFDM_CSI_RATE(x) ((u32)(((x >> 5) & 0x0000003F)))
#define BIT_MASK_WMAC_MIMO_PARA_CNT   ((u32)0x00000007 << 2)            /*!< R/W 0x1  width of mimo_para_en,deafult:1(mac clk:20M,pluse width:100ns)*/
#define BIT_WMAC_MIMO_PARA_CNT(x)     (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_WMAC_MIMO_PARA_CNT(x) ((u32)(((x >> 2) & 0x00000007)))
#define BIT_WMAC_CSI_BFRP_STOPTX      ((u32)0x00000001 << 1)            /*!< R/W 0x1  stop tx when rx ndpa/ndp and wait for bfrp poll frame*/
#define BIT_WMAC_HE_NDPA_EN           ((u32)0x00000001 << 0)            /*!< R/W 0x0  Set to 1, MAC would inform BB of preparing to receive NDP if the received NDPA is valid.*/
/** @} */

/** @defgroup REG_BEAMFORMING_CTRL_1
  * @brief
  * @{
  */
#define BIT_CSI_LEN_ERR_FLAG           ((u32)0x00000001 << 30)           /*!< R 0x0  CSI length error*/
#define BIT_CLR_CSI_ERR_FLAG           ((u32)0x00000001 << 29)           /*!< WA0 0x0  clear tb csi_length error flag*/
#define BIT_CSI_LEN_RD_SEL             ((u32)0x00000001 << 28)           /*!< R/W 0x0  0:read csi rpt length form bb 1:read csi rpt length form mac*/
#define BIT_MASK_WMAC_CSI_WAIT_TIMER   ((u32)0x000000FF << 18)           /*!< R/W 0x42  set this timer after receiving BFRP or VHT/HE NDPA not solicit a CSI rpt frmae frame me,and should be cleared when receiving a BFRP addressed to me and tx CSI successfully. unit:256us,defult 16ms*/
#define BIT_WMAC_CSI_WAIT_TIMER(x)     (((u32)((x) & 0x000000FF) << 18))
#define BIT_GET_WMAC_CSI_WAIT_TIMER(x) ((u32)(((x >> 18) & 0x000000FF)))
#define BIT_MASK_CSI_LEN               ((u32)0x0003FFFF << 0)            /*!< R 0x0  csi rpt length choosed by 0x17c4[28]*/
#define BIT_CSI_LEN(x)                 (((u32)((x) & 0x0003FFFF) << 0))
#define BIT_GET_CSI_LEN(x)             ((u32)(((x >> 0) & 0x0003FFFF)))
/** @} */

/** @defgroup REG_LBK_CFG
  * @brief
  * @{
  */
#define BIT_MASK_MACLBK_RDY_PERIOD   ((u32)0x0000007F << 0)           /*!< R/W 0x12  tdrdy/rdrdy interval count*/
#define BIT_MACLBK_RDY_PERIOD(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_MACLBK_RDY_PERIOD(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_GID_POS_EN_H
  * @brief VHT group id position enable register
  * @{
  */
#define BIT_MASK_GID_POSITION_EN_H   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  VHT group id position enable*/
#define BIT_GID_POSITION_EN_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_GID_POSITION_EN_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TRX_PKTCNT_CTRL
  * @brief
  * @{
  */
#define BIT_TXPKTCNT_RST             ((u32)0x00000001 << 10)          /*!< R/W 0x0  Reset tx packet counter*/
#define BIT_TX_UDPKTCNT_SET          ((u32)0x00000001 << 9)           /*!< R/W 0x0  loading user define packet counter cfg*/
#define BIT_MASK_WMAC_TXPKTCNT_SEL   ((u32)0x00000007 << 6)           /*!< R/W 0x0  Tx packet counter selection  3'd0: counter 0 3'd1: counter 1 3'd2: counter 2 3'd3: counter 3 3'd4: counter 4 3'd5: counter 5 3'd6: counter 6 3'd7: counter 7*/
#define BIT_WMAC_TXPKTCNT_SEL(x)     (((u32)((x) & 0x00000007) << 6))
#define BIT_GET_WMAC_TXPKTCNT_SEL(x) ((u32)(((x >> 6) & 0x00000007)))
#define BIT_MASK_WMAC_TXPKTCNT_CFG   ((u32)0x0000003F << 0)           /*!< R/W 0x0  User define [5:2]:subtype [1:0]:type*/
#define BIT_WMAC_TXPKTCNT_CFG(x)     (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_WMAC_TXPKTCNT_CFG(x) ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_TRX_PKTCNT
  * @brief
  * @{
  */
#define BIT_MASK_RO_WMAC_TXPKTCNT_RPT   ((u32)0x01FFFFFF << 0)           /*!< R 0x0  Tx packet counter*/
#define BIT_RO_WMAC_TXPKTCNT_RPT(x)     (((u32)((x) & 0x01FFFFFF) << 0))
#define BIT_GET_RO_WMAC_TXPKTCNT_RPT(x) ((u32)(((x >> 0) & 0x01FFFFFF)))
/** @} */

/** @defgroup REG_TRXPKTCNT_CFG
  * @brief
  * @{
  */
#define BIT_MASK_PKTCNT_7_CFG   ((u32)0x0000000F << 28)           /*!< R/W 0x0  Packet counter 7 type config. If configured , counter 7 will count only for the selected type. bit[31] = 0:  Tx, bit[31]=1:  Rx. 4'b0000: Tx User Define MPDU 4'b0001: Tx HE SU MPDU 4'b0010: Tx HE SU PPDU 4'b0011: Tx HE TB MPDU 4'b0100: Tx HE TB PPDU 4'b1000: Rx packet full drop 4'b1001: Rx drop packet 4'b1010: Rx invalid packet 4'b1011: Rx total OK 4'b1100: Rx total Fail 4'b1101: Rx User Define OK 4'b1110: Rx CCK OK 4'b1111: Rx CCK Fail*/
#define BIT_PKTCNT_7_CFG(x)     (((u32)((x) & 0x0000000F) << 28))
#define BIT_GET_PKTCNT_7_CFG(x) ((u32)(((x >> 28) & 0x0000000F)))
#define BIT_MASK_PKTCNT_6_CFG   ((u32)0x0000000F << 24)           /*!< R/W 0x0  Packet counter 6 type config. If configured , counter 6 will count only for the selected type. bit[27] = 0:  Tx, bit[27]=1:  Rx. 4'b0000: Tx Total MPDU 4'b0001: Tx Total PPDU 4'b0010: Tx HT MPDU 4'b0011: Tx HT PPDU 4'b0100: Tx VHT SU MPDU 4'b0101: Tx VHT SU PPDU 4'b1000: Rx HE MU OK 4'b1001: Rx HE MU Fail 4'b1010: Rx HE MU PPDU 4'b1011: Rx packet full drop 4'b1100: Rx drop packet 4'b1101: Rx invalid packet 4'b1110: Rx total OK 4'b1111: Rx total Fail*/
#define BIT_PKTCNT_6_CFG(x)     (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_PKTCNT_6_CFG(x) ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_PKTCNT_5_CFG   ((u32)0x0000000F << 20)           /*!< R/W 0x0  Packet counter 5 type config. If configured , counter 5 will count only for the selected type. bit[23] = 0:  Tx, bit[23]=1:  Rx. 4'b0000: Tx HE TB MPDU 4'b0001: Tx HE TB PPDU 4'b0010: Tx Total MPDU 4'b0011: Tx Total PPDU 4'b1000: Rx HE SU OK 4'b1001: Rx HE SU Fail 4'b1010: Rx HE SU PPDU 4'b1011: Rx HE SU False Alarm 4'b1100: Rx HE MU OK 4'b1101: Rx HE MU Fail 4'b1110: Rx HE MU PPDU 4'b1111: Rx HE MU False Alarm*/
#define BIT_PKTCNT_5_CFG(x)     (((u32)((x) & 0x0000000F) << 20))
#define BIT_GET_PKTCNT_5_CFG(x) ((u32)(((x >> 20) & 0x0000000F)))
#define BIT_MASK_PKTCNT_4_CFG   ((u32)0x0000000F << 16)           /*!< R/W 0x0  Packet counter 4 type config. If configured , counter 4 will count only for the selected type. bit[19] = 0:  Tx, bit[19]=1:  Rx. 4'b0000: Tx HE SU MPDU 4'b0001: Tx HE SU PPDU 4'b0010: Tx HE TB MPDU 4'b0011: Tx HE TB PPDU 4'b1000: Rx VHT MU OK 4'b1001: Rx VHT MU Fail 4'b1010: Rx VHT MU PPDU 4'b1011: Rx VHT MU False Alarm 4'b1100: Rx HE SU OK 4'b1101: Rx HE SU Fail 4'b1110: Rx HE SU PPDU 4'b1111: Rx HE SU False Alarm*/
#define BIT_PKTCNT_4_CFG(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_PKTCNT_4_CFG(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_PKTCNT_3_CFG   ((u32)0x0000000F << 12)           /*!< R/W 0x0  Packet counter 3 type config. If configured , counter 3 will count only for the selected type. bit[15] = 0:  Tx, bit[15]=1:  Rx. 4'b0000: Tx VHT SU MPDU 4'b0001: Tx VHT SU PPDU 4'b0010: Tx HE SU MPDU 4'b0011: Tx HE SU PPDU 4'b1000: Rx VHT SU OK 4'b1001: Rx VHT SU Fail 4'b1010: Rx VHT SU PPDU 4'b1011: Rx VHT SU False Alarm 4'b1100: Rx VHT MU OK 4'b1101: Rx VHT MU Fail 4'b1110: Rx VHT MU PPDU 4'b1111: Rx VHT MU False Alarm*/
#define BIT_PKTCNT_3_CFG(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_PKTCNT_3_CFG(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_PKTCNT_2_CFG   ((u32)0x0000000F << 8)            /*!< R/W 0x0  Packet counter 2 type config. If configured , counter 2 will count only for the selected type.  bit[11] = 0:  Tx, bit[11]=1:  Rx. 4'b0000: Tx HT MPDU 4'b0001: Tx HT PPDU 4'b0010: Tx VHT SU MPDU 4'b0011: Tx VHT SU PPDU 4'b1000: Rx HT OK 4'b1001: Rx HT Fail 4'b1010: Rx HT PPDU 4'b1011: Rx HT False Alarm 4'b1100: Rx VHT SU OK 4'b1101: Rx VHT SU Fail 4'b1110: Rx VHT SU PPDU 4'B1111: Rx VHT SU False Alarm*/
#define BIT_PKTCNT_2_CFG(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_PKTCNT_2_CFG(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_PKTCNT_1_CFG   ((u32)0x0000000F << 4)            /*!< R/W 0x0  Packet counter 1 type config. If configured , counter 1 will count only for the selected type. bit[7] = 0:  Tx, bit[7]=1:  Rx. 4'b0000~4'b0111: Tx OFDM PPDU 4'b1000: Rx OFDM OK 4'b1001: Rx OFDM Fail 4'b1010: Rx OFDM False Alarm 4'b1011: Rx HT OK 4'b1100: Rx HT Fail 4'b1101: Rx HT PPDU 4'b1110: Rx HT False Alarm*/
#define BIT_PKTCNT_1_CFG(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_PKTCNT_1_CFG(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_PKTCNT_0_CFG   ((u32)0x0000000F << 0)            /*!< R/W 0x0  Packet counter 0 type config. If configured , counter 0 will count only for the selected type. bit[3] = 0:  Tx, bit[3]=1:  Rx. 4'b0000~4'b0111: Tx CCK PPDU 4'b1000: Rx CCK OK 4'b1001: Rx CCK Fail 4'b1010: Rx CCK False Alarm 4'b1011: Rx OFDM OK 4'b1100: Rx OFDM Fail 4'b1101: Rx OFDM False Alarm*/
#define BIT_PKTCNT_0_CFG(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_PKTCNT_0_CFG(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_REF_RESP_CTL
  * @brief
  * @{
  */
#define BIT_RESP_ACK_IGNORE_MACRX   ((u32)0x00000001 << 20)          /*!< R/W 0x0  when set, will response tx regardless of macrx active*/
#define BIT_RESP_ACK_NON_EOF        ((u32)0x00000001 << 19)          /*!< R/W 0x0  when set, will response tx ack to mgt frame with eof=0 in trigger frame*/
#define BIT_WMAC_STOP_RESPONSE      ((u32)0x00000001 << 18)          /*!< R/W 0x0  when set, will not resposne tx*/
#define BIT_WMAC_TXRAW_IGNOREA1     ((u32)0x00000001 << 17)          /*!< R/W 0x1  when set, will not check rx a1 of packet that is response to txraw*/
#define BIT_RESP_ACTRL_BQR_EN       ((u32)0x00000001 << 16)          /*!< R/W 0x1  when set, hw would update BQR info to A-CTRL*/
#define BIT_RESP_ACTRL_UPH_EN       ((u32)0x00000001 << 15)          /*!< R/W 0x1  when set, hw would update UPH info to A-CTRL*/
#define BIT_RESP_ACTRL_BSR_EN       ((u32)0x00000001 << 14)          /*!< R/W 0x1  when set, hw would update BSR info to A-CTRL*/
#define BIT_RESP_ACTRL_CAS_EN       ((u32)0x00000001 << 13)          /*!< R/W 0x1  when set, hw would update CAS info to A-CTRL*/
#define BIT_RESP_LDPC_SEL           ((u32)0x00000001 << 12)          /*!< R/W 0x1  1: follow ctrl reg 0x668[15]; 0: follow rx pkt, used when control info is not valid*/
#define BIT_RESP_DCM_SEL            ((u32)0x00000001 << 7)           /*!< R/W 0x0  1: follow ctrl reg 0x17b4[25]; 0: follow rx pkt, used when control info is not valid*/
#define BIT_RESP_BSR_FORMATE        ((u32)0x00000001 << 6)           /*!< R/W 0x0  0: queue size of QOS field us non-he formate; 1: queue size of QOS field us he formate,vaild when*/
#define BIT_MASK_RESP_NOMINAL_PAD   ((u32)0x00000003 << 4)           /*!< R/W 0x0  norminal packet padding:0:0us;1:8us;2:16us;Tpe is decided by nominal packet adding and pre-FEC padding factor*/
#define BIT_RESP_NOMINAL_PAD(x)     (((u32)((x) & 0x00000003) << 4))
#define BIT_GET_RESP_NOMINAL_PAD(x) ((u32)(((x >> 4) & 0x00000003)))
#define BIT_RESP_EARLY_START        ((u32)0x00000001 << 3)           /*!< R/W 0x0  when set,response satrt early when responsd to non-trigger frame*/
#define BIT_RESP_USE_EARLY_FCS      ((u32)0x00000001 << 2)           /*!< R/W 0x0  when set, use rx fifo fcs when response data that use wep/tkip*/
#define BIT_RESP_ALLACK_EN          ((u32)0x00000001 << 1)           /*!< R/W 0x0  when set, enable tx multi sta ba-all ack as response, used when control info is not valid*/
#define BIT_RESP_EARLY_START_TRIG   ((u32)0x00000001 << 0)           /*!< R/W 0x0  when set,response satrt early when rx trigger frame except basic trigger*/
/** @} */

/** @defgroup REG_TXPWR_CTL
  * @brief
  * @{
  */
#define BIT_TXPWR_FAST_MODE_EN ((u32)0x00000001 << 0) /*!< R/W 0x1  fast mode enable for txpwr_ctl, tie 1 for AMEBAD2*/
/** @} */

/** @defgroup REG_MASK_LA_TRX_DBG_L
  * @brief
  * @{
  */
#define BIT_MASK_LA_TRX_PATTERN_MASK_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  used for mask for debug port in iqdump*/
#define BIT_LA_TRX_PATTERN_MASK_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_LA_TRX_PATTERN_MASK_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MASK_LA_TRX_DBG_H
  * @brief
  * @{
  */
#define BIT_MASK_LA_TRX_PATTERN_MASK_H   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  used for mask for debug port in iqdump*/
#define BIT_LA_TRX_PATTERN_MASK_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_LA_TRX_PATTERN_MASK_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_REF_LA_TRX_DBG_L
  * @brief
  * @{
  */
#define BIT_MASK_LA_TRX_PATTERN_REF_L   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  used for mask for debug port in iqdump*/
#define BIT_LA_TRX_PATTERN_REF_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_LA_TRX_PATTERN_REF_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_REF_LA_TRX_DBG_H
  * @brief
  * @{
  */
#define BIT_MASK_LA_TRX_PATTERN_REF_H   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  used for mask for debug port in iqdump*/
#define BIT_LA_TRX_PATTERN_REF_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_LA_TRX_PATTERN_REF_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/*==========REG_PAGE17_WMAC Register Address Definition==========*/
#define REG_TWT_BC_ID                        0x1700
#define REG_TWT_BC_RPT0                      0x1704
#define REG_TWT_BC_RPT1                      0x1708
#define REG_OPS_RPT_AND_N                    0x170C
#define REG_RX_CFG                           0x1710
#define REG_LA_EVENT_OPTION                  0x1714
#define REG_AID                              0x1718
#define REG_TRAN_BSSID0_L                    0x171C
#define REG_TRAN_BSSID0_H                    0x1720
#define REG_MAC_PHY_CONTROL                  0x1724
#define REG_RSVD7                            0x1728
#define REG_GID_POS_EN_L                     0x172C
#define REG_GID_POS0                         0x1730
#define REG_GID_POS1                         0x1734
#define REG_GID_POS2                         0x1738
#define REG_GID_POS3                         0x173C
#define REG_BSSCOLOR_BITMAP_L                0x1740
#define REG_BSSCOLOR_BITMAP_H                0x1744
#define REG_PBSSID_BITMAP_L                  0x1748
#define REG_PBSSID_BITMAP_H                  0x174C
#define REG_SR_CFG0                          0x1750
#define REG_SR_CFG1                          0x1754
#define REG_MACTX_SR                         0x1758
#define REG_MACTX_MISC                       0x175C
#define REG_MACTX_MHDR0                      0x1760
#define REG_MACTX_MHDR1                      0x1764
#define REG_MACTX_TXD_FIFO                   0x1768
#define REG_RXTRIG_TEST_COMM_0               0x1780
#define REG_RXTRIG_TEST_COMM_1               0x1784
#define REG_RXTRIG_TEST_USER_0               0x1788
#define REG_RXTRIG_TEST_USER_1               0x178C
#define REG_RXTRIG_TEST_USER_2               0x1790
#define REG_RXTRIG_TEST_CTRL                 0x1794
#define REG_SIFS_TIMING_CTRL_CCK             0x1798
#define REG_SIFS_TIMING_CTRL_OFDM            0x179C
#define REG_AX_TB_TIMING_CTRL                0x17A0
#define REG_SR_CONTROL_DBG                   0x17A4
#define REG_NAV_CTRL                         0x17A8
#define REG_RESP_CONTROL                     0x17AA
#define REG_NAV_STATUS                       0x17B0
#define REG_RESP_CONTROL_1                   0x17B4
#define REG_RESP_RATE_RRSR                   0x17B8
#define REG_RESP_RATE_RRSR_1                 0x17BC
#define REG_BEAMFORMING_CTRL                 0x17C0
#define REG_BEAMFORMING_CTRL_1               0x17C4
#define REG_LBK_CFG                          0x17C8
#define REG_GID_POS_EN_H                     0x17CC
#define REG_TRX_PKTCNT_CTRL                  0x17D0
#define REG_TRX_PKTCNT                       0x17D4
#define REG_BEAMFORMING_MIMO_STATUS          0x17D8
#define REG_TRXPKTCNT_CFG                    0x17DC
#define REG_REF_RESP_CTL                     0x17E0
#define REG_TXPWR_CTL                        0x17E4
#define REG_DUMMY_PAGE17                     0x17E8
#define REG_RSVD9                            0x17EC
#define REG_MASK_LA_TRX_DBG_L                0x17F0
#define REG_MASK_LA_TRX_DBG_H                0x17F4
#define REG_REF_LA_TRX_DBG_L                 0x17F8
#define REG_REF_LA_TRX_DBG_H                 0x17FC

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