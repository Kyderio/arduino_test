#ifndef _RL6955_REG_PAGE5_OFF_H_
#define _RL6955_REG_PAGE5_OFF_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE5_OFF
  * @brief REG_PAGE5_OFF driver modules
  * @{
  */




/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE5_OFF_Register_Definitions REG_PAGE5_OFF Register Definitions
  * @{
  */

/** @defgroup REG_SIFS
  * @brief
  * @{
  */
#define BIT_MASK_SIFS_TRX_OFDM     ((u32)0x0000001F << 24)           /*!< R/W 0xE  This register sets the SIFS time required in NAV protection period after receiving any immediate response. for example Ack-Data or RTS/CTS-Data. It is in unit of us.*/
#define BIT_SIFS_TRX_OFDM(x)       (((u32)((x) & 0x0000001F) << 24))
#define BIT_GET_SIFS_TRX_OFDM(x)   ((u32)(((x >> 24) & 0x0000001F)))
#define BIT_MASK_SIFS_TRX_CCK      ((u32)0x0000001F << 16)           /*!< R/W 0xA  This register sets the SIFS time required in NAV protection period after receiving any immediate response. for example Ack-Data or RTS/CTS-Data. It is in unit of us.*/
#define BIT_SIFS_TRX_CCK(x)        (((u32)((x) & 0x0000001F) << 16))
#define BIT_GET_SIFS_TRX_CCK(x)    ((u32)(((x >> 16) & 0x0000001F)))
#define BIT_MASK_SIFS_CONTX_OFDM   ((u32)0x0000001F << 8)            /*!< R/W 0xE  This register sets the SIFS time required for consecutive TX events for example CTS2S-Data, or broadcast bursting. It is in unit of us.*/
#define BIT_SIFS_CONTX_OFDM(x)     (((u32)((x) & 0x0000001F) << 8))
#define BIT_GET_SIFS_CONTX_OFDM(x) ((u32)(((x >> 8) & 0x0000001F)))
#define BIT_MASK_SIFS_CONTX_CCK    ((u32)0x0000001F << 0)            /*!< R/W 0xA  This register sets the SIFS time required for consecutive TX events for example CTS2S-Data, or broadcast bursting. It is in unit of us.*/
#define BIT_SIFS_CONTX_CCK(x)      (((u32)((x) & 0x0000001F) << 0))
#define BIT_GET_SIFS_CONTX_CCK(x)  ((u32)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_TSFT_SYN_OFFSET_SLOT
  * @brief
  * @{
  */
#define BIT_MASK_MAX_BCNERR     ((u32)0x0000003F << 24)           /*!< R/W 0x10  When beacon TX error counter goes over this threshold, Beacon will transmit within PIFS. Unit is 4*/
#define BIT_MAX_BCNERR(x)       (((u32)((x) & 0x0000003F) << 24))
#define BIT_GET_MAX_BCNERR(x)   ((u32)(((x >> 24) & 0x0000003F)))
#define BIT_MASK_SLOTTIME       ((u32)0x0000001F << 18)           /*!< R/W 0x09  This register sets the slot time value mentioned in 802.11 specification. It is in units of us. Default: 0x9*/
#define BIT_SLOTTIME(x)         (((u32)((x) & 0x0000001F) << 18))
#define BIT_GET_SLOTTIME(x)     ((u32)(((x >> 18) & 0x0000001F)))
#define BIT_MASK_SIFS_TIME_BK   ((u32)0x0000001F << 12)           /*!< R/W 0x3  Hw will break aggr. In sifs condition*/
#define BIT_SIFS_TIME_BK(x)     (((u32)((x) & 0x0000001F) << 12))
#define BIT_GET_SIFS_TIME_BK(x) ((u32)(((x >> 12) & 0x0000001F)))
#define BIT_MASK_2TSFT_OFFSET   ((u32)0x00000FFF << 0)            /*!< R/W 0x190  tsft sync. Offset (bcn0 sync to bcn1 offset or bcn1 sync to bcn0 offset).  Unit : 128us, default is 50ms*/
#define BIT_2TSFT_OFFSET(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_2TSFT_OFFSET(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_FTM_CTRL
  * @brief
  * @{
  */
#define BIT_FTM_PTT_TSF_R2T_SEL ((u32)0x00000001 << 24)          /*!< R/W 0x0  0:R2T latch count sync tsf of port 0 1: R2T latch count sync tsf of port 1*/
#define BIT_FTM_PTT_TSF_T2R_SEL ((u32)0x00000001 << 20)          /*!< R/W 0x0  0:T2R latch count sync tsf of port 0 1: T2R latch count sync tsf of port 1*/
#define BIT_FTM_PTT_TSF_SEL     ((u32)0x00000001 << 16)          /*!< R/W 0x0  0: sync tsf of port 0 1: sync tsf of port 1*/
#define BIT_MASK_FTM_PTT        ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  partial tsf timer setting*/
#define BIT_FTM_PTT(x)          (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_FTM_PTT(x)      ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_FTM_TSF_CNT
  * @brief
  * @{
  */
#define BIT_MASK_SCH_FTM_T2_TSFT   ((u32)0x0000FFFF << 16)           /*!< RO 0x0  R2T latch count sync tsf timer*/
#define BIT_SCH_FTM_T2_TSFT(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_SCH_FTM_T2_TSFT(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_SCH_FTM_T1_TSFT   ((u32)0x0000FFFF << 0)            /*!< RO 0x0  T2R latch count sync tsf timer*/
#define BIT_SCH_FTM_T1_TSFT(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_SCH_FTM_T1_TSFT(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_P0_TSFTR_L
  * @brief
  * @{
  */
#define BIT_MASK_P0_TSF_TIMER_L   ((u32)0xFFFFFFFF << 0)           /*!< R/WOPD 0x1  low 32bits of port0's tsft*/
#define BIT_P0_TSF_TIMER_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_P0_TSF_TIMER_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_P0_TSFTR_H
  * @brief
  * @{
  */
#define BIT_MASK_P0_TSF_TIMER_H   ((u32)0xFFFFFFFF << 0)           /*!< R/WOPD 0x0  high 32bits of port0's tsft*/
#define BIT_P0_TSF_TIMER_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_P0_TSF_TIMER_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FREERUN_CNT_L
  * @brief
  * @{
  */
#define BIT_MASK_FREERUN_CNT_TIMER_L   ((u32)0xFFFFFFFF << 0)           /*!< R/WOPD 0x1  LOW 32bits of freerun cnt*/
#define BIT_FREERUN_CNT_TIMER_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FREERUN_CNT_TIMER_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FREERUN_CNT_H
  * @brief
  * @{
  */
#define BIT_MASK_FREERUN_CNT_TIMER_H   ((u32)0xFFFFFFFF << 0)           /*!< R/WOPD 0x0  high 32bits of freerun cnt*/
#define BIT_FREERUN_CNT_TIMER_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FREERUN_CNT_TIMER_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_P2_TSFTR_L
  * @brief
  * @{
  */
#define BIT_MASK_P2_TSF_TIMER_L   ((u32)0xFFFFFFFF << 0)           /*!< R/WOPD 0x1  low 32bits of port2's tsft (NAN)*/
#define BIT_P2_TSF_TIMER_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_P2_TSF_TIMER_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_P2_TSFTR_H
  * @brief
  * @{
  */
#define BIT_MASK_P2_TSF_TIMER_H   ((u32)0xFFFFFFFF << 0)           /*!< R/WOPD 0x0  high 32bits of port2's tsft (NAN)*/
#define BIT_P2_TSF_TIMER_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_P2_TSF_TIMER_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_NDPA_NAV
  * @brief
  * @{
  */
#define BIT_DIS_NDPA_NAV_CHK       ((u32)0x00000001 << 24)           /*!< R/W 0x0  1-->tx NDPA/NDP can cross TBTT,0-->tx NDPA/NDP can't cross TBTT*/
#define BIT_MASK_MHDR_NAV_OFFSET   ((u32)0x000000FF << 16)           /*!< R/W 0x0  NDPA NAV compensation value*/
#define BIT_MHDR_NAV_OFFSET(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MHDR_NAV_OFFSET(x) ((u32)(((x >> 16) & 0x000000FF)))
/** @} */

/** @defgroup REG_RX_TSFT_DIFF
  * @brief
  * @{
  */
#define BIT_RXBCN_TIME_VLD         ((u32)0x00000001 << 13)          /*!< RW1C 0x0  1: indicate [12:0] is valid. Write 1 to clear this bit*/
#define BIT_RXBCN_TIME_DIFF_DIR    ((u32)0x00000001 << 12)          /*!< RO   1: wmac_rx_tsf > TSFT 0: wmac_rx_tsf <= TSFT*/
#define BIT_MASK_RXBCN_TIME_DIFF   ((u32)0x00000FFF << 0)           /*!< RO   unit:32us wmac_rx_tsf - TSFT. [12] is the sign bit*/
#define BIT_RXBCN_TIME_DIFF(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_RXBCN_TIME_DIFF(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_TM_TSFT_T1_T3
  * @brief
  * @{
  */
#define BIT_MASK_SCH_TM_TSFT_T1_T3   ((u32)0x00FFFFFF << 0)           /*!< RO 0x0  T1: Latch tsft timer of Tx TM frame, unit: 1us T3: Latch tsft timer of Tx ACK frame, unit: 1us*/
#define BIT_SCH_TM_TSFT_T1_T3(x)     (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_SCH_TM_TSFT_T1_T3(x) ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_TM_TSFT_T2_T4
  * @brief
  * @{
  */
#define BIT_MASK_SCH_TM_TSFT_T2_T4   ((u32)0x00FFFFFF << 0)           /*!< RO 0x0  T2: Latch tsft timer of Rx TM frame, unit: 1us T4: Latch tsft timer of Rx ACK frame, unit: 1us*/
#define BIT_SCH_TM_TSFT_T2_T4(x)     (((u32)((x) & 0x00FFFFFF) << 0))
#define BIT_GET_SCH_TM_TSFT_T2_T4(x) ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup REG_TSFT_HIOE_RFON_L
  * @brief
  * @{
  */
#define BIT_MASK_TSFT_AT_HIOE_RFON_L   ((u32)0xFFFFFFFF << 0)           /*!< RO 0x0  when hioe_int_chn_on asserted, latch the tsft[31:0] (select port by 0x1520[0])*/
#define BIT_TSFT_AT_HIOE_RFON_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_TSFT_AT_HIOE_RFON_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TSFT_HIOE_RFON_H
  * @brief
  * @{
  */
#define BIT_MASK_TSFT_AT_HIOE_RFON_H   ((u32)0xFFFFFFFF << 0)           /*!< RO 0x0  when hioe_int_chn_on asserted, latch the tsft[63:32] (select port by 0x1520[0])*/
#define BIT_TSFT_AT_HIOE_RFON_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_TSFT_AT_HIOE_RFON_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TSFT_BCN_CCAUP_L
  * @brief
  * @{
  */
#define BIT_MASK_TSFT_AT_BCN_CCA_UP_L   ((u32)0xFFFFFFFF << 0)           /*!< RO 0x0  when CCA asserted, latch the tsft[31:0] (select port by 0x1520[0]).  updated to this register after judging that it is a beacon frame*/
#define BIT_TSFT_AT_BCN_CCA_UP_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_TSFT_AT_BCN_CCA_UP_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TSFT_BCN_CCAUP_H
  * @brief
  * @{
  */
#define BIT_MASK_TSFT_AT_BCN_CCA_UP_H   ((u32)0xFFFFFFFF << 0)           /*!< RO 0x0  when CCA asserted, latch the tsft[63:32] (select port by 0x1520[0]).  updated to this register after judging that it is a beacon frame*/
#define BIT_TSFT_AT_BCN_CCA_UP_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_TSFT_AT_BCN_CCA_UP_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_TXOP_BREAK_CFG
  * @brief
  * @{
  */
#define BIT_EN_TXOP_BREAK          ((u32)0x00000001 << 8)           /*!< R/W 0x0  1: enable TXOP break gen_cmd and TXOP abort TX*/
#define BIT_MASK_TXOP_BRK_MARGIN   ((u32)0x000000FF << 0)           /*!< R/W 0x0  extra transtime during TXOP, unit: 2us if data_transtime + BIT_TXOP_BRK_MARGIN*2 exceed the remaining TXOP count, will abort this TX*/
#define BIT_TXOP_BRK_MARGIN(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_TXOP_BRK_MARGIN(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_P2_TSFT_BACKUP_L
  * @brief
  * @{
  */
#define BIT_MASK_P2_TSF_BACKUP_L   ((u32)0xFFFFFFFF << 0)           /*!< RO 0x1  low 32bits of port2's tsft_backup (NAN)*/
#define BIT_P2_TSF_BACKUP_L(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_P2_TSF_BACKUP_L(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_P2_TSFT_BACKUP_H
  * @brief
  * @{
  */
#define BIT_MASK_P2_TSF_BACKUP_H   ((u32)0xFFFFFFFF << 0)           /*!< RO 0x0  high 32bits of port2's tsft_backup (NAN)*/
#define BIT_P2_TSF_BACKUP_H(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_P2_TSF_BACKUP_H(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_SCHEDULER_DBG
  * @brief
  * @{
  */
#define BIT_MASK_DBG_SCHEDULER   ((u32)0xFFFFFFFF << 0)           /*!< RO 0x0  */
#define BIT_DBG_SCHEDULER(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_DBG_SCHEDULER(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_SCH_TXCMD
  * @brief
  * @{
  */
#define BIT_MASK_SCH_TXCMD   ((u32)0xFFFFFFFF << 0)           /*!< RO 0x0  Scheduler TXCMD Content*/
#define BIT_SCH_TXCMD(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_SCH_TXCMD(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_RADAR_CFG
  * @brief
  * @{
  */
#define BIT_RADAR_REQ             ((u32)0x00000001 << 31)           /*!< R/W 0x0  asserted when need to tx radar pkt,FW set, SW clear*/
#define BIT_MASK_GNT_RADAR_CNT    ((u32)0x00000FFF << 16)           /*!< R/W 0x64  Need to wait some time when detect the posedge or negedge of gnt_radar, unit:us*/
#define BIT_GNT_RADAR_CNT(x)      (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_GNT_RADAR_CNT(x)  ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_RADAR_LIFETIME   ((u32)0x0000FFFF << 0)            /*!< R/W 0x8000  Radar packet lifetime, unit:32us*/
#define BIT_RADAR_LIFETIME(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_RADAR_LIFETIME(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_AUDIO_INT_CFG
  * @brief
  * @{
  */
#define BIT_AUDIO_SEL_P0              ((u32)0x00000001 << 31)           /*!< R/W 0x1  1: select P0's TSFT to trigger audio latch count*/
#define BIT_MASK_AUDIO_TRIG_UNIT      ((u32)0x00000007 << 28)           /*!< R/W 0x2  0: trigger audio latch period is 1ms 1: period is 2ms 2: period is 4ms 3: period is 8ms ...... 6: period is 64ms 7: period is 128ms*/
#define BIT_AUDIO_TRIG_UNIT(x)        (((u32)((x) & 0x00000007) << 28))
#define BIT_GET_AUDIO_TRIG_UNIT(x)    ((u32)(((x >> 28) & 0x00000007)))
#define BIT_MASK_AUDIO_STR_PLAY_SEL   ((u32)0x00000007 << 25)           /*!< R/W 0x0  select ps_timer interrput for audio start play function 1: select ps_timer_a int 2: select ps_timer_b int 3: select ps_timer_c int 4: select ps_timer_d int 5: select ps_timer_e int else: TIE0*/
#define BIT_AUDIO_STR_PLAY_SEL(x)     (((u32)((x) & 0x00000007) << 25))
#define BIT_GET_AUDIO_STR_PLAY_SEL(x) ((u32)(((x >> 25) & 0x00000007)))
/** @} */

/** @defgroup REG_P0_UPDATETSFT_DIFF
  * @brief
  * @{
  */
#define BIT_TSFT_DIFF_VLD       ((u32)0x00000001 << 31)           /*!< RW1C 0x0  1: indicate [20:0] is valid. 0: wmac_rx_tsf <= TSFT*/
#define BIT_TSFT_DIFF_US_DIR    ((u32)0x00000001 << 20)           /*!< RO   1: update_tsft_us > TSFT_us 0: update_tsft_us <= TSFT_us*/
#define BIT_MASK_TSFT_DIFF_US   ((u32)0x000000FF << 12)           /*!< RO   unit:1us update_tsft_us - TSFT. [20] is the sign bit if diff >=255, this value would be 8'hff*/
#define BIT_TSFT_DIFF_US(x)     (((u32)((x) & 0x000000FF) << 12))
#define BIT_GET_TSFT_DIFF_US(x) ((u32)(((x >> 12) & 0x000000FF)))
#define BIT_TSFT_DIFF_NS_DIR    ((u32)0x00000001 << 10)           /*!< RO   1: update_tsft_ns > TSFT_ns 0: update_tsft_ns <= TSFT_ns*/
#define BIT_MASK_TSFT_DIFF_NS   ((u32)0x000003FF << 0)            /*!< RO   unit:1ns update_tsft_ns - TSFT. [10] is the sign bit*/
#define BIT_TSFT_DIFF_NS(x)     (((u32)((x) & 0x000003FF) << 0))
#define BIT_GET_TSFT_DIFF_NS(x) ((u32)(((x >> 0) & 0x000003FF)))
/** @} */

/** @defgroup REG_AUDIO_LAT_TSFT
  * @brief
  * @{
  */
#define BIT_MASK_AUDIO_LAT_TSFT_US   ((u32)0x003FFFFF << 10)           /*!< RO   low 22bits of audio latch tsft_us*/
#define BIT_AUDIO_LAT_TSFT_US(x)     (((u32)((x) & 0x003FFFFF) << 10))
#define BIT_GET_AUDIO_LAT_TSFT_US(x) ((u32)(((x >> 10) & 0x003FFFFF)))
#define BIT_MASK_AUDIO_LAT_TSFT_NS   ((u32)0x000003FF << 0)            /*!< RO   audio latch tsft_ns*/
#define BIT_AUDIO_LAT_TSFT_NS(x)     (((u32)((x) & 0x000003FF) << 0))
#define BIT_GET_AUDIO_LAT_TSFT_NS(x) ((u32)(((x >> 0) & 0x000003FF)))
/** @} */

/*==========REG_PAGE5_OFF Register Address Definition==========*/
#define REG_SIFS                          0x5A0
#define REG_TSFT_SYN_OFFSET_SLOT          0x5A4
#define REG_FTM_CTRL                      0x5A8
#define REG_FTM_TSF_CNT                   0x5AC
#define REG_P0_TSFTR_L                    0x5B0
#define REG_P0_TSFTR_H                    0x5B4
#define REG_FREERUN_CNT_L                 0x5B8
#define REG_FREERUN_CNT_H                 0x5BC
#define REG_P2_TSFTR_L                    0x5C0
#define REG_P2_TSFTR_H                    0x5C4
#define REG_NDPA_NAV                      0x5C8
#define REG_RX_TSFT_DIFF                  0x5CC
#define REG_TM_TSFT_T1_T3                 0x5D0
#define REG_TM_TSFT_T2_T4                 0x5D4
#define REG_TSFT_HIOE_RFON_L              0x5D8
#define REG_TSFT_HIOE_RFON_H              0x5DC
#define REG_TSFT_BCN_CCAUP_L              0x5E0
#define REG_TSFT_BCN_CCAUP_H              0x5E4
#define REG_TXOP_BREAK_CFG                0x5E8
#define REG_P2_TSFT_BACKUP_L              0x5EC
#define REG_P2_TSFT_BACKUP_H              0x5F0
#define REG_SCHEDULER_DBG                 0x5F4
#define REG_SCH_TXCMD                     0x5F8
#define REG_RADAR_CFG                     0x5FC
#define REG_AUDIO_INT_CFG                 0x15A0
#define REG_P0_UPDATETSFT_DIFF            0x15A4
#define REG_AUDIO_LAT_TSFT                0x15A8

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