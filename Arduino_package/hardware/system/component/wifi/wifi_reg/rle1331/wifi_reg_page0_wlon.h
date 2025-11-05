#ifndef _RL6955_REG_PAGE0_WLON_H_
#define _RL6955_REG_PAGE0_WLON_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE0_WLON
  * @brief REG_PAGE0_WLON driver modules
  * @{
  */




/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE0_WLON_Register_Definitions REG_PAGE0_WLON Register Definitions
  * @{
  */

/** @defgroup REG_SYS_PWC_ISO_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_WL_SWR_STS_REQ_ACT   ((u16)0x00000007 << 13)           /*!< R/W 0x6  000: RSVD  001: state1  0.7/PC/PFM 010: state2  0.8/PC/PFM  011: state3  0.9/PC/PFM 100: state4  0.9/SLP/PFM  101: state5  0.9/SLP/PWM  110: state6  0.9/NORM/PWM  111: state7  1.0/NORM/PWM*/
#define BIT_WL_SWR_STS_REQ_ACT(x)     (((u16)((x) & 0x00000007) << 13))
#define BIT_GET_WL_SWR_STS_REQ_ACT(x) ((u16)(((x >> 13) & 0x00000007)))
#define BIT_MASK_WL_SWR_STS_REQ_LPS   ((u16)0x00000007 << 10)           /*!< R/W 0x2  000: RSVD 001: state1  0.7/PC/PFM 010: state2  0.8/PC/PFM  011: state3  0.9/PC/PFM 100: state4  0.9/SLP/PFM 101: state5  0.9/SLP/PWM  110: state6  0.9/NORM/PWM  111: state7  1.0/NORM/PWM*/
#define BIT_WL_SWR_STS_REQ_LPS(x)     (((u16)((x) & 0x00000007) << 10))
#define BIT_GET_WL_SWR_STS_REQ_LPS(x) ((u16)(((x >> 10) & 0x00000007)))
#define BIT_WL_SWR_STS_REQ_TRG        ((u16)0x00000001 << 9)            /*!< R/WA0 0x0  1:wl request switch regu status to active mode,which means selectl 0x00[11:9] as request 0:wl request switch regu status to lps mode,which means selectl 0x00[7:5] as request*/
#define BIT_MASK_WL_SWR_STS_REQ       ((u16)0x00000007 << 5)            /*!< R 0x6  the SWR request mode of wifi*/
#define BIT_WL_SWR_STS_REQ(x)         (((u16)((x) & 0x00000007) << 5))
#define BIT_GET_WL_SWR_STS_REQ(x)     ((u16)(((x >> 5) & 0x00000007)))
#define BIT_WL_PWR_SWITCH_DMY_EN      ((u16)0x00000001 << 4)            /*!< R/W 0x1  1:enable wl dummy load when wlan is switching power mode 0:disable wl dummy load when wlan is switching power mode*/
#define BIT_WL_POW_AFE_REQ            ((u16)0x00000001 << 3)            /*!< R/W 0x0  AFE power on request to afe_ctrl 1:request to turn on AFE pwr 0:turn off AFE pwr*/
#define BIT_WL_REQ_TO_ACT             ((u16)0x00000001 << 1)            /*!< R/W 0x0  notify system to act*/
#define BIT_WL_PWC_WLMAC_EN           ((u16)0x00000001 << 0)            /*!< R/W 0x0  1: Enable WLOFF power cut*/
/** @} */

/** @defgroup REG_WL_CLK_CTRL
  * @brief
  * @{
  */
#define BIT_BT_EN_WL_CK4M       ((u16)0x00000001 << 15) /*!< R/W 0x1  enable WL OSC 4M when bt is active*/
#define BIT_WLON_SWITCH_TSF_EN  ((u16)0x00000001 << 12) /*!< R/W 0x0  enable wlpmc switch TSF clock to MAC clock*/
#define BIT_WLOFF_SWITCH_TSF_EN ((u16)0x00000001 << 11) /*!< R/W 0x0  enable wlpmc switch TSF clock to 32K clock*/
#define BIT_WL_CKEN_IQDUMP      ((u16)0x00000001 << 10) /*!< R/W 0x0  0: disable clock for iqdump (LA MODE) 1: enable clock for iqdump (LA MODE) same clock source as security clock*/
#define BIT_TSF_IS_32K          ((u16)0x00000001 << 9)  /*!< R 0x0  WL TSF clock status: 0: MAC clock 1: 32K clock*/
#define BIT_WL_CKSL_CKTSF       ((u16)0x00000001 << 8)  /*!< R/W 0x0  1: TSF clock switch to 32.768KHz; 0: TSF clock switch to MAC clock*/
#define BIT_WL_CKTSF1_EN        ((u16)0x00000001 << 7)  /*!< R/W 0x0  1: enable port2 tsf clock; 0: gated*/
#define BIT_WL_CKTSF0_EN        ((u16)0x00000001 << 6)  /*!< R/W 0x0  1: enable port1 tsf clock; 0: gated*/
#define BIT_WL_FQSEL_CK32K      ((u16)0x00000001 << 5)  /*!< R/W 0x0  1:32K frequency select 32.768KHz 0:32K frequency select 32KHz*/
#define BIT_WL_CK32K_EN         ((u16)0x00000001 << 3)  /*!< R/W 0x0  1: enable 32k clock; 0: gated*/
#define BIT_WL_CKSEC_EN         ((u16)0x00000001 << 1)  /*!< R/W 0x0  1: enable MAC security engine clock; 0: gated*/
#define BIT_WL_CKMAC_EN         ((u16)0x00000001 << 0)  /*!< R/W 0x0  1: enable MAC clock; 0: gated*/
/** @} */

/** @defgroup REG_WL_FUNC_EN
  * @brief
  * @{
  */
#define BIT_WL_PON_WAIT_ALL ((u32)0x00000001 << 26) /*!< R/W 0x1  1:wait rdy for swr and xtal and pwc in the same state when power on to save time and power*/
#define BIT_WL_POF_WAIT_ALL ((u32)0x00000001 << 25) /*!< R/W 0x1  1:wait rdy for swr and xtal in the same state when power off to save time and power*/
#define BIT_WL_SEL_SW_SI    ((u32)0x00000001 << 24) /*!< R/W 0x0  indicate SW use indirect path to access WLRFC register*/
#define BIT_FEN_BB_RSTB     ((u32)0x00000001 << 17) /*!< R/W/ES 0x0  When this bit is set to 0, CCK and OFDM are disabled, and clock are gated. Otherwise, CCK and OFDM are enabled.*/
#define BIT_FEN_BB_GLB      ((u32)0x00000001 << 16) /*!< R/W 0x0  When this bit is set to 0 whole BB is reset. When this bit is set, BB is enabled.*/
#define BIT_FW_INIT_RDY     ((u32)0x00000001 << 7)  /*!< R/W 0x0  CPU fw initialize ready, set by CPU(txrpt info update,used in ptcl)*/
#define BIT_WL_FEN_WLON     ((u32)0x00000001 << 4)  /*!< R/W 0x0  1: enable WL partial ON; 0: reset*/
#define BIT_WL_FEN_WLOFF    ((u32)0x00000001 << 1)  /*!< R/W 0x0  1: enable WLOFF; 0: reset*/
#define BIT_WL_FEN_MAC_PMC  ((u32)0x00000001 << 0)  /*!< R/W 0x0  1: enable MAC PMC; 0: reset*/
/** @} */

/** @defgroup REG_CLKDIV_CKSEL
  * @brief
  * @{
  */
#define BIT_SW_EN_WL_CK4M       ((u32)0x00000001 << 24)           /*!< R/W 0x0  enable WL OSC 4M when cpu want to access wlon reg and wlpmc buffer*/
#define BIT_MASK_SEC_CLK_SEL    ((u32)0x00000003 << 20)           /*!< R/W 2'b00  11/10:40M 01:80M 00:160M*/
#define BIT_SEC_CLK_SEL(x)      (((u32)((x) & 0x00000003) << 20))
#define BIT_GET_SEC_CLK_SEL(x)  ((u32)(((x >> 20) & 0x00000003)))
#define BIT_MASK_MAC_CLK_SEL    ((u32)0x00000003 << 18)           /*!< R/W 2'b01  11/10:20M 01:40M 00:80M*/
#define BIT_MAC_CLK_SEL(x)      (((u32)((x) & 0x00000003) << 18))
#define BIT_GET_MAC_CLK_SEL(x)  ((u32)(((x >> 18) & 0x00000003)))
#define BIT_WL_CKDIV_SYNC_1SHOT ((u32)0x00000001 << 15)           /*!< R/W 0x0  1: sync 40M/80M clock  phase with PLL*/
#define BIT_MASK_WL_MAC_PHASE   ((u32)0x0000000F << 4)            /*!< R/W 0x0  40M MAC clock phase control*/
#define BIT_WL_MAC_PHASE(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_WL_MAC_PHASE(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_WL_SEC_PHASE   ((u32)0x0000000F << 0)            /*!< R/W 0x0  80M security clock phase control*/
#define BIT_WL_SEC_PHASE(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_WL_SEC_PHASE(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CPWM
  * @brief
  * @{
  */
#define BIT_CPWM_TOGGLING   ((u32)0x00000001 << 3)           /*!< R/WPD 0x0  Toggling bit : one bit sequence number bit. When this bit is toggled, interrupt is send to HISR.CPWMINT.*/
#define BIT_MASK_CPWM_MOD   ((u32)0x00000007 << 0)           /*!< R/W 0x0  The current power mode index.*/
#define BIT_CPWM_MOD(x)     (((u32)((x) & 0x00000007) << 0))
#define BIT_GET_CPWM_MOD(x) ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_RPWM
  * @brief
  * @{
  */
#define BIT_RPWM_TOGGLING   ((u16)0x00000001 << 15)          /*!< R/WPD 0x0  Toggling bit : one bit sequence number bit. When this bit is toggled, interrupt is send to FISR.RPWMINT.*/
#define BIT_MASK_RPWM_MOD   ((u16)0x00007FFF << 0)           /*!< R/W 0x0  The current power mode index.*/
#define BIT_RPWM_MOD(x)     (((u16)((x) & 0x00007FFF) << 0))
#define BIT_GET_RPWM_MOD(x) ((u16)(((x >> 0) & 0x00007FFF)))
/** @} */

/** @defgroup REG_SCOREBOARD_BT2WL_CTRL
  * @brief
  * @{
  */
#define BIT_HS_BT2L_STS_INT    ((u16)0x00000001 << 5)           /*!< RW1C 0x0  when bit31 toggles, this interrupt will be assert*/
#define BIT_HS_BT2L_STS_INT_EN ((u16)0x00000001 << 4)           /*!< R/W 0x0  when bit31 toggles, this interrupt will be assert*/
#define BIT_MASK_BT_MODE       ((u16)0x00000003 << 1)           /*!< R/W 0x0  Bluetooth Mode*/
#define BIT_BT_MODE(x)         (((u16)((x) & 0x00000003) << 1))
#define BIT_GET_BT_MODE(x)     ((u16)(((x >> 1) & 0x00000003)))
#define BIT_EN_BT              ((u16)0x00000001 << 0)           /*!< R/W 0x0  Enable PTA ( from BT side)*/
/** @} */

/** @defgroup REG_SCOREBOARD_BT2WL
  * @brief
  * @{
  */
#define BIT_MASK_RD_BT2WL_INFO   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  Read Data :  WL TO BT INFO, WLON Status Report*/
#define BIT_RD_BT2WL_INFO(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_RD_BT2WL_INFO(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_SCOREBOARD_WL2BT
  * @brief
  * @{
  */
#define BIT_MASK_RD_WL2BT_INFO   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  WLON Status Report TO BTON*/
#define BIT_RD_WL2BT_INFO(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_RD_WL2BT_INFO(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_XTAL_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_WL_XTAL_REQ        ((u32)0x00000007 << 23)           /*!< R 0x4  the xtal request mode of wifi*/
#define BIT_WL_XTAL_REQ(x)          (((u32)((x) & 0x00000007) << 23))
#define BIT_GET_WL_XTAL_REQ(x)      ((u32)(((x >> 23) & 0x00000007)))
#define BIT_WL_XTAL_REQ_TRG         ((u32)0x00000001 << 22)           /*!< R/WA0 0x0  1: wl request xtal status to active mode,which means selectl 0x30[6:5] as request 0: wl request xtal status to lps mode,which means selectl 0x30[4:3] as request*/
#define BIT_MASK_WL_XTAL_REQ_ACT    ((u32)0x00000007 << 19)           /*!< R/W 0x4  000:xtal off 001:xtal lps mode gating 40M 010:xtal lps mode enable 40M 011:xtal normal mode 100:xtal hp mode*/
#define BIT_WL_XTAL_REQ_ACT(x)      (((u32)((x) & 0x00000007) << 19))
#define BIT_GET_WL_XTAL_REQ_ACT(x)  ((u32)(((x >> 19) & 0x00000007)))
#define BIT_MASK_WL_XTAL_REQ_LPS    ((u32)0x00000007 << 16)           /*!< R/W 0x0  000:xtal off 001:xtal lps mode gating 40M 010:xtal lps mode enable 40M 011:xtal normal mode 100:xtal hp mode*/
#define BIT_WL_XTAL_REQ_LPS(x)      (((u32)((x) & 0x00000007) << 16))
#define BIT_GET_WL_XTAL_REQ_LPS(x)  ((u32)(((x >> 16) & 0x00000007)))
#define BIT_WL_MLDO_MODE_REQ_TRG    ((u32)0x00000001 << 6)            /*!< R/WA0 0x0  Write 1 to trigger switch LDO mode when wifi is active, pulse*/
#define BIT_MASK_WL_MLDO_MODE_REQ   ((u32)0x00000003 << 4)            /*!< R 0x3  The ldo request mode of wifi*/
#define BIT_WL_MLDO_MODE_REQ(x)     (((u32)((x) & 0x00000003) << 4))
#define BIT_GET_WL_MLDO_MODE_REQ(x) ((u32)(((x >> 4) & 0x00000003)))
#define BIT_MASK_WL_MLDO_MODE_LPS   ((u32)0x00000003 << 2)            /*!< R/W 0x0  00: analog LDO off    01: analog LDO off sleep 10: analog LDO normal -- dummy load 11: analog LDO normal -- no dummy load*/
#define BIT_WL_MLDO_MODE_LPS(x)     (((u32)((x) & 0x00000003) << 2))
#define BIT_GET_WL_MLDO_MODE_LPS(x) ((u32)(((x >> 2) & 0x00000003)))
#define BIT_MASK_WL_MLDO_MODE_ACT   ((u32)0x00000003 << 0)            /*!< R/W 0x3  00: analog LDO off    01: analog LDO off sleep 10: analog LDO normal -- dummy load 11: analog LDO normal -- no dummy load*/
#define BIT_WL_MLDO_MODE_ACT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_WL_MLDO_MODE_ACT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_WL_PMC_CTRL
  * @brief
  * @{
  */
#define BIT_WLBB_RESET_BY_PMC       ((u32)0x00000001 << 21)          /*!< R/W 0x1  1: release wlbb glb reset and restore wlbb retention dff by wlpmc 0:release wlbb glb reset and restore wlbb retention dff by sw or hioe*/
#define BIT_WL_BB_RETAIN_EN_TYPE_1  ((u32)0x00000001 << 20)          /*!< R/W 0x1  1 to 0:gen req to restore register in power on flow 0 to 1:gen req to backup register in power on flow default should be 1,otherwise there be unexpected leakage power when VCC is power off and VCCG is still on*/
#define BIT_WL_BB_SAVE_EN_TYPE_2    ((u32)0x00000001 << 19)          /*!< WA0 0x0  enable saving value of retention DFF when wlbb power off or pg,should be assert when reset is high*/
#define BIT_WL_BB_RESTORE_EN_TYPE_2 ((u32)0x00000001 << 18)          /*!< WA0 0x0  enable restoring value of retention DFF when wlbb power on,should be assert when reset is high*/
#define BIT_WL_SAVE_EN_TYPE_2       ((u32)0x00000001 << 17)          /*!< WA0 0x0  enable saving value of retention DFF when wlmac power off or pg,should be assert when reset is high*/
#define BIT_WL_RESTORE_EN_TYPE_2    ((u32)0x00000001 << 16)          /*!< WA0 0x0  enable restoring value of retention DFF when wlmac power on,should be assert when reset is high*/
#define BIT_WL_RETAIN_EN_TYPE_1     ((u32)0x00000001 << 15)          /*!< R/W 0x1  1 to 0:gen req to restore register in power on flow 0 to 1:gen req to backup register in power on flow default should be 1,otherwise there be unexpected leakage power when VCC is power off and VCCG is still on*/
#define BIT_WL_RETENTION_CELL_SEL   ((u32)0x00000001 << 14)          /*!< R/W 0x0  1:choose retention cell type I(U22 ULP),which is controlled by 0x20[15] 0:choose retention cell type II(RTKM),which is controlled by 0x20[17:16]*/
#define BIT_MASK_WL_PMC_TUTIME      ((u32)0x0000003F << 8)           /*!< R/W 0x1F  WL PMC FSM counting unit.*/
#define BIT_WL_PMC_TUTIME(x)        (((u32)((x) & 0x0000003F) << 8))
#define BIT_GET_WL_PMC_TUTIME(x)    ((u32)(((x >> 8) & 0x0000003F)))
#define BIT_WL_PMC_LPS              ((u32)0x00000001 << 2)           /*!< R/W 0x0  Inform WLAN PMC FSM to enter LPS mode.  (auto clear when ready)*/
#define BIT_WL_PMC_POFF             ((u32)0x00000001 << 1)           /*!< R/W 0x0  Inform WLAN PMC FSM to power OFF mode, include clock, isolation, power control for MAC only (clear when Power Ready)*/
#define BIT_WL_PMC_PON              ((u32)0x00000001 << 0)           /*!< R/W 0x0  Inform WLAN PMC FSM to power On mode, include clock, isolation, power control for MAC only (clear when Power Ready)*/
/** @} */

/** @defgroup REG_WL_PIN_FUNC_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_WL_DBG_SEL   ((u32)0x000000FF << 24)           /*!< R/W 0x0  WL debug select*/
#define BIT_WL_DBG_SEL(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_WL_DBG_SEL(x) ((u32)(((x >> 24) & 0x000000FF)))
/** @} */

/** @defgroup REG_P0_TBTT_TIMER
  * @brief
  * @{
  */
#define BIT_MASK_P0_ELY_BCNAGG_CNT   ((u32)0x0000007F << 24)           /*!< R 0x0  Unit: bcn_space the total time to next specified TBTT is (new_ely_agg_cnt - 1) * r_bcn_space(0x554) + (beacon_cnt_down - 1)* 1ms + (cnt_128us + 1)* 128us*/
#define BIT_P0_ELY_BCNAGG_CNT(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_P0_ELY_BCNAGG_CNT(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_P0_BCN_CNT_DOWN     ((u32)0x0000FFFF << 3)            /*!< R 0x0  Unit: 1ms beacon_cnt_down - 1*/
#define BIT_P0_BCN_CNT_DOWN(x)       (((u32)((x) & 0x0000FFFF) << 3))
#define BIT_GET_P0_BCN_CNT_DOWN(x)   ((u32)(((x >> 3) & 0x0000FFFF)))
#define BIT_MASK_P0_128US_CNT        ((u32)0x00000007 << 0)            /*!< R 0x0  Unit: 128us*/
#define BIT_P0_128US_CNT(x)          (((u32)((x) & 0x00000007) << 0))
#define BIT_GET_P0_128US_CNT(x)      ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_WL_PMC_DEBUG
  * @brief
  * @{
  */
#define BIT_SYSPLL_CLKRDY     ((u32)0x00000001 << 17) /*!< RO 0x0  */
#define BIT_LS_SYS_IS_OFF     ((u32)0x00000001 << 16) /*!< RO 0x0  */
#define BIT_LS_SYS_IS_LPS     ((u32)0x00000001 << 15) /*!< RO 0x0  */
#define BIT_LS_SYS_IS_ON      ((u32)0x00000001 << 14) /*!< RO 0x0  */
#define BIT_BT_IS_OFF         ((u32)0x00000001 << 13) /*!< RO 0x0  */
#define BIT_BT_IS_LPS         ((u32)0x00000001 << 12) /*!< RO 0x0  */
#define BIT_BT_IS_ON          ((u32)0x00000001 << 11) /*!< RO 0x0  */
#define BIT_WL_PLL_RDY        ((u32)0x00000001 << 10) /*!< RO 0x0  */
#define BIT_HIOE_CHN_OFF_DONE ((u32)0x00000001 << 9)  /*!< RO 0x0  */
#define BIT_HIOE_CHN_ON_DONE  ((u32)0x00000001 << 8)  /*!< RO 0x0  */
#define BIT_WLPOF_TSF_CLK_RDY ((u32)0x00000001 << 7)  /*!< RO 0x0  */
#define BIT_WLPON_TSF_CLK_RDY ((u32)0x00000001 << 6)  /*!< RO 0x0  */
#define BIT_WL_MLDO_RDY       ((u32)0x00000001 << 5)  /*!< RO 0x0  */
#define BIT_WL_XTAL_RDY       ((u32)0x00000001 << 4)  /*!< RO 0x0  */
#define BIT_WL_SWR_RDY        ((u32)0x00000001 << 3)  /*!< RO 0x0  */
#define BIT_WL_PON_RDY        ((u32)0x00000001 << 2)  /*!< RO 0x0  */
#define BIT_WL_PWC_RDY        ((u32)0x00000001 << 1)  /*!< RO 0x0  */
#define BIT_RDY2ACT           ((u32)0x00000001 << 0)  /*!< RO 0x0  */
/** @} */

/** @defgroup REG_DBG_PORT_REG
  * @brief
  * @{
  */
#define BIT_MASK_DEBUG_ST   ((u32)0xFFFFFFFF << 0)           /*!< RO 0x0  Debug signals, sel by 24[31:24]*/
#define BIT_DEBUG_ST(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_DEBUG_ST(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_LPS_CTRL
  * @brief
  * @{
  */
#define BIT_WL_LPS_OPT_SAVE_REG             ((u32)0x00000001 << 29)           /*!< R/W 0x0  LPS option to save retention FF 1: enable request to save retention FF 0: disable request to save retention FF*/
#define BIT_WL_LPS_MEMPM_AXBB               ((u32)0x00000001 << 25)           /*!< R/W 0x1  AXBB  FTC/SNPS memory power mode when enable LPS memory power mode  0 : normal 1 : NAP/LS*/
#define BIT_MASK_WL_LPS_MEMPM_MACON_WLPMC   ((u32)0x00000003 << 23)           /*!< R/W 2'b10  MAC ON  FTC memory power mode when enable LPS memory power mode(for WLPMC BUFFER) 00 : normal 01 : NAP 10 : RET 11 : SLP*/
#define BIT_WL_LPS_MEMPM_MACON_WLPMC(x)     (((u32)((x) & 0x00000003) << 23))
#define BIT_GET_WL_LPS_MEMPM_MACON_WLPMC(x) ((u32)(((x >> 23) & 0x00000003)))
#define BIT_WL_LPS_MEMPM_MACOFF             ((u32)0x00000001 << 21)           /*!< R/W 1'b1  MAC OFF  FTC memory power mode when enable LPS memory power mode (for RXPKTBUF/LLT/CISBUF/SR_TABLE) 0 : normal 1 : NAP/LS*/
#define BIT_MASK_WL_LPS_MEMPM_MACON         ((u32)0x00000003 << 19)           /*!< R/W 2'b10  MAC ON FTC memory power mode when enable LPS memory power mode (for EXT_RXPKTBUF/HIOE 4k) 00 : normal 01 : NAP 10 : RET 11 : SLP*/
#define BIT_WL_LPS_MEMPM_MACON(x)           (((u32)((x) & 0x00000003) << 19))
#define BIT_GET_WL_LPS_MEMPM_MACON(x)       ((u32)(((x >> 19) & 0x00000003)))
#define BIT_WL_LPS_MEMPM_MACOFF_TRXFIFO     ((u32)0x00000001 << 18)           /*!< R/W 0x1  MAC OFF  FTC/SNPS memory power mode when enable LPS memory power mode (for rxfifo/txfifo) 0 : normal 1 : NAP/LS*/
#define BIT_WL_LPS_MEMPM_MACOFF_DMAFIFO     ((u32)0x00000001 << 17)           /*!< R/W 0x1  MAC OFF SNPS memory power mode when enable LPS memory power mode(dmafifo) 0 : normal 1 : NAP*/
#define BIT_WL_LPS_OPT_EMACFUN              ((u32)0x00000001 << 10)           /*!< R/W 0x0  LPS option to reset WL MAC OFF block when enable WL MAC OFF power 1: not reset WL MAC OFF block 0: reset WL MAC OFF block*/
#define BIT_WL_LPS_OPT_EMACPWR              ((u32)0x00000001 << 8)            /*!< R/W 0x0  LPS option to enable WL MAC OFF block power 1: Enable WL MAC OFF block power  0: Disable WL MAC OFF block power*/
#define BIT_WL_LPS_OPT_GTSFOFF              ((u32)0x00000001 << 7)            /*!< R/W 0x0  LPS option to enable TSF CLK  in OFF domain 1: Enable tsf clk gating when lps cg 0: Disable tsf clk gating when lps cg*/
#define BIT_WL_LPS_MEMPM_EN                 ((u32)0x00000001 << 1)            /*!< R/W 0x0  enable LPS memory power mode control*/
#define BIT_WL_NRM_MEMPM_SL                 ((u32)0x00000001 << 0)            /*!< R/W 0x0  MAC memory power mode when BIT_WL_LPS_MEMPM_EN is 0, 0 : Normal 1 : SD*/
/** @} */

/** @defgroup REG_LPS_OFFLOAD_CTRL
  * @brief
  * @{
  */
#define BIT_HIOE_BYPASS_CHN_BCN_MODE ((u16)0x00000001 << 4) /*!< R/W 0x1  BYPASS HW trig hioe to do switch bcn mode to normal rx(enable ofdm) flow*/
#define BIT_HIOE_BYPASS_CHN_OFF      ((u16)0x00000001 << 3) /*!< R/W 0x1  BYPASS HW trig hioe to do rf off flow*/
#define BIT_HIOE_BYPASS_CHN_ON       ((u16)0x00000001 << 2) /*!< R/W 0x1  BYPASS HW trig hioe to do rf on flow*/
#define BIT_HW_AUTO_ENTER_LPS_EN     ((u16)0x00000001 << 1) /*!< R/W 0x0  enable HW enter lps after hioe_off_int rise when BIT_FS_RXBCN_LPS_EN=1*/
#define BIT_RXBCN_LPSOFFLOAD_EN      ((u16)0x00000001 << 0) /*!< R/W 0x0  enable lps offload flow when rxbcn frame in port0 acting as a non-AP STA.*/
/** @} */

/** @defgroup REG_AUTO_PMC_CTRL
  * @brief
  * @{
  */
#define BIT_WLPMC_POF_TRIG_CHN_OFF   ((u16)0x00000001 << 2) /*!< R/WA0 0x0  ONE pluse to trig hioe_chn_off*/
#define BIT_WLPMC_PON_TRIG_CHN_ON    ((u16)0x00000001 << 1) /*!< R/WA0 0x0  ONE pluse to trig hioe_chn_on, and start rxbcn_timer*/
#define BIT_SW_CONFIGURABLE_WLPMC_EN ((u16)0x00000001 << 0) /*!< R/W 0x0  enable programable wlpmc flow*/
/** @} */

/** @defgroup REG_AHB_WATCHDOG
  * @brief
  * @{
  */
#define BIT_MASK_WATCH_DOG_RECORD   ((u32)0x00003FFF << 2)           /*!< R 0x0  timeout register address*/
#define BIT_WATCH_DOG_RECORD(x)     (((u32)((x) & 0x00003FFF) << 2))
#define BIT_GET_WATCH_DOG_RECORD(x) ((u32)(((x >> 2) & 0x00003FFF)))
#define BIT_IO_TIMEOUT_FLAG         ((u32)0x00000001 << 1)           /*!< RW1C 0x0  AHB timeout flag*/
#define BIT_EN_WATCH_DOG            ((u32)0x00000001 << 0)           /*!< R/W 0x1  enable AHB timeout watchdog*/
/** @} */

/** @defgroup REG_FW_DBG_PON_1
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_PON_1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_PON_1*/
#define BIT_FW_DBG_PON_1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_PON_1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_PON_2
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_PON_2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_PON_2*/
#define BIT_FW_DBG_PON_2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_PON_2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_PON_3
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_PON_3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_PON_3*/
#define BIT_FW_DBG_PON_3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_PON_3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_PON_4
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_PON_4   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_PON_4*/
#define BIT_FW_DBG_PON_4(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_PON_4(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_PON_5
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_PON_5   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_PON_5*/
#define BIT_FW_DBG_PON_5(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_PON_5(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_PON_6
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_PON_6   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_PON_6*/
#define BIT_FW_DBG_PON_6(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_PON_6(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_PON_7
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_PON_7   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_PON_7*/
#define BIT_FW_DBG_PON_7(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_PON_7(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_PON_8
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_PON_8   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_PON_8*/
#define BIT_FW_DBG_PON_8(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_PON_8(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_PON_9
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_PON_9   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_PON_9*/
#define BIT_FW_DBG_PON_9(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_PON_9(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_PON_10
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_PON_10   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_PON_10*/
#define BIT_FW_DBG_PON_10(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_PON_10(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_PON_11
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_PON_11   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_PON_11*/
#define BIT_FW_DBG_PON_11(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_PON_11(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG_PON_12
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG_PON_12   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  FW_DBG_PON_12*/
#define BIT_FW_DBG_PON_12(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG_PON_12(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_SW_WLPMC_DEBUG
  * @brief
  * @{
  */
#define BIT_MASK_SW_WLPMC_DBG   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  */
#define BIT_SW_WLPMC_DBG(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_SW_WLPMC_DBG(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HW_WLPMC_DEBUG
  * @brief
  * @{
  */
#define BIT_MASK_HW_WLPMC_DBG   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  */
#define BIT_HW_WLPMC_DBG(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HW_WLPMC_DBG(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/*==========REG_PAGE0_WLON Register Address Definition==========*/
#define REG_SYS_PWC_ISO_CTRL               0x000
#define REG_WL_CLK_CTRL                    0x002
#define REG_WL_FUNC_EN                     0x004
#define REG_CLKDIV_CKSEL                   0x008
#define REG_CPWM                           0x00C
#define REG_RPWM                           0x010
#define REG_SCOREBOARD_BT2WL_CTRL          0x012
#define REG_SCOREBOARD_BT2WL               0x014
#define REG_SCOREBOARD_WL2BT               0x018
#define REG_XTAL_CTRL                      0x01C
#define REG_WL_PMC_CTRL                    0x020
#define REG_WL_PIN_FUNC_CTRL               0x024
#define REG_P0_TBTT_TIMER                  0x028
#define REG_WL_PMC_DEBUG                   0x02C
#define REG_DBG_PORT_REG                   0x030
#define REG_LPS_CTRL                       0x034
#define REG_LPS_OFFLOAD_CTRL               0x038
#define REG_AUTO_PMC_CTRL                  0x03A
#define REG_AHB_WATCHDOG                   0x03C
#define REG_DUMMY_PAGE0                    0x040
#define REG_FW_DBG_PON_1                   0x050
#define REG_FW_DBG_PON_2                   0x054
#define REG_FW_DBG_PON_3                   0x058
#define REG_FW_DBG_PON_4                   0x05C
#define REG_FW_DBG_PON_5                   0x060
#define REG_FW_DBG_PON_6                   0x064
#define REG_FW_DBG_PON_7                   0x068
#define REG_FW_DBG_PON_8                   0x06C
#define REG_FW_DBG_PON_9                   0x084
#define REG_FW_DBG_PON_10                  0x088
#define REG_FW_DBG_PON_11                  0x08C
#define REG_FW_DBG_PON_12                  0x094
#define REG_SW_WLPMC_DEBUG                 0x0A0
#define REG_HW_WLPMC_DEBUG                 0x0A4

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