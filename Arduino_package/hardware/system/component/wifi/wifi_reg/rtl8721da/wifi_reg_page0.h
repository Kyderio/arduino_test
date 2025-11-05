#ifndef _AMEBAD2_REG_PAGE0_H_
#define _AMEBAD2_REG_PAGE0_H_

/* AUTO_GEN_START */

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE0
* @brief REG_PAGE0 driver modules
* @{
*/

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE0_Register_Definitions REG_PAGE0 Register Definitions
 * @{
 *****************************************************************************/

/** @defgroup REG_SYS_PWC_ISO_CTRL
 * @brief
 * @{
 **/
#define BIT_WL_PWR_SWITCH_DMY_EN             ((u32)0x00000001 << 12)          /*!<R/W 1  1:enable wl_dummy_en when wlan is switching power mode 0:disable wl_dummy_en when wlan is switching power mode */
#define BIT_MASK_WL_SWR_STS_REQ_ACT          ((u32)0x00000007 << 9)          /*!<R/W 0x5  000: RSVD 001: state1 0.7/PC/PFM 010: state2 0.8/PC/PFM 011: state3 0.9/PC/PFM 100: state4 0.9/SLP/PFM 101: state5 0.9/SLP/PWM 110: state6 0.9/NORM/PWM 111: state7 1.0/NORM/PWM */
#define BIT_WL_SWR_STS_REQ_ACT(x)            (((u32)((x) & 0x00000007) << 9))
#define BIT_GET_WL_SWR_STS_REQ_ACT(x)        ((u32)(((x >> 9) & 0x00000007)))
#define BIT_ISO_MAC                          ((u32)0x00000001 << 8)          /*!<R/W 1  Isolation control for MAC, 1: isolation; 0: attach */
#define BIT_MASK_WL_SWR_STS_REQ_LPS          ((u32)0x00000007 << 5)          /*!<R/W 0x1  000: RSVD 001: state1 0.7/PC/PFM 010: state2 0.8/PC/PFM 011: state3 0.9/PC/PFM 100: state4 0.9/SLP/PFM 101: state5 0.9/SLP/PWM 110: state6 0.9/NORM/PWM 111: state7 1.0/NORM/PWM */
#define BIT_WL_SWR_STS_REQ_LPS(x)            (((u32)((x) & 0x00000007) << 5))
#define BIT_GET_WL_SWR_STS_REQ_LPS(x)        ((u32)(((x >> 5) & 0x00000007)))
#define BIT_WL_RETAIN_EN                     ((u32)0x00000001 << 2)          /*!<R/W 1  1 to 0:gen req to restore register in power on flow 1:gen req to backup register in power on flow */
#define BIT_SPC_MAC_EN                       ((u32)0x00000001 << 0)          /*!<R/W 0  1: Enable WLOFF power cut */
/** @} */

/** @defgroup REG_WL_CLK_CTRL
 * @brief
 * @{
 **/
#define BIT_WLON_SWITCH_TSF_EN               ((u32)0x00000001 << 12)          /*!<R/W 0  enable wlpmc switch TSF clock to MAC clock */
#define BIT_WLOFF_SWITCH_TSF_EN              ((u32)0x00000001 << 11)          /*!<R/W 0  enable wlpmc switch TSF clock to 32K clock */
#define BIT_WL_CKEN_IQDUMP                   ((u32)0x00000001 << 10)          /*!<R/W 0  0: disable clock for iqdump (LA MODE) 1: enable clock for iqdump (LA MODE) same clock source as security clock */
#define BIT_IS_SCH_CLK_INSLP_V2              ((u32)0x00000001 << 9)          /*!<RO 0  WL TSF clock status: 0: MAC clock 1: 32K clock */
#define BIT_TSF_CKSLP_SEL                    ((u32)0x00000001 << 8)          /*!<R/W 0  1: TSF clock switch to 32.768KHz; 0: TSF clock switch to MAC clock */
#define BIT_WL_CKTSF_EN                      ((u32)0x00000001 << 6)          /*!<R/W 0  1: enable tsf clock; 0: gated */
#define BIT_WL_FQSEL_CK32K                   ((u32)0x00000001 << 5)          /*!<R/W 0  1:32K frequency select 32.768KHz 0:32K frequency select 32KHz */
#define BIT_CKSL_CK32K                       ((u32)0x00000001 << 4)          /*!<R/W 0  1:select MAC internal 32K clk, 0:select MAC external 32K clk */
#define BIT_WL_CK32K_EN                      ((u32)0x00000001 << 3)          /*!<R/W 0  1: enable 32k clock; 0: gated */
#define BIT_WL_CKMCU_EN                      ((u32)0x00000001 << 2)          /*!<R/W 0  1: enable MCU engine clock; 0: gated */
#define BIT_WL_CKSEC_EN                      ((u32)0x00000001 << 1)          /*!<R/W 0  1: enable MAC security engine clock; 0: gated */
#define BIT_WL_CKMAC_EN                      ((u32)0x00000001 << 0)          /*!<R/W 0  1: enable MAC clock; 0: gated */
/** @} */

/** @defgroup REG_WL_FUNC_EN
 * @brief
 * @{
 **/
#define BIT_WL_SEL_SW_SI                     ((u32)0x00000001 << 24)          /*!<R/W 0  indicate SW use indirect path to access WLRFC register */
#define BIT_BB_SAVE_EN                       ((u32)0x00000001 << 18)          /*!<R/W 0  1 to 0:gen req to restore register in power on flow 1:gen req to backup register in power on flow */
#define BIT_FEN_BBRSTB_V2                    ((u32)0x00000001 << 17)          /*!<R/W 0  When this bit is set to “0”, CCK and OFDM are disabled, and clock are gated. Otherwise, CCK and OFDM are enabled. */
#define BIT_FEN_BB_GLB_RSTN_V2               ((u32)0x00000001 << 16)          /*!<R/W 0  When this bit is set to “0”, whole BB is reset. When this bit is set, BB is enabled. */
#define BIT_FEN_MLPLT                        ((u32)0x00000001 << 9)          /*!<R/W 0   */
#define BIT_RFAFE_HW33PDB                    ((u32)0x00000001 << 8)          /*!<R/W 0   */
#define BIT_FEN_WLON                         ((u32)0x00000001 << 4)          /*!<R/W 0  1: enable WL partial ON; 0: reset */
#define BIT_FEN_WLMCU                        ((u32)0x00000001 << 3)          /*!<R/W 0  1: enable WLMCU; 0: reset */
#define BIT_FEN_MACREG                       ((u32)0x00000001 << 2)          /*!<R/W 0  1: enable MAC REG; 0: reset */
#define BIT_FEN_WLOFF                        ((u32)0x00000001 << 1)          /*!<R/W 0  1: enable WLOFF; 0: reset */
#define BIT_FEN_MAC_PMC                      ((u32)0x00000001 << 0)          /*!<R/W 0  1: enable MAC PMC; 0: reset */
/** @} */

/** @defgroup REG_CLKDIV_CKSEL
 * @brief
 * @{
 **/
#define BIT_WL_CKRFC_EN                      ((u32)0x00000001 << 24)          /*!<R/W 0  1: enable WLRFC clock; 0: gated */
#define BIT_MASK_RFC_CLK_SEL                 ((u32)0x00000003 << 22)          /*!<R/W 2'b01  11/10:40M 01:80M 00:160M */
#define BIT_RFC_CLK_SEL(x)                   (((u32)((x) & 0x00000003) << 22))
#define BIT_GET_RFC_CLK_SEL(x)               ((u32)(((x >> 22) & 0x00000003)))
#define BIT_MASK_SEC_CLK_SEL                 ((u32)0x00000003 << 20)          /*!<R/W 2'b01  11/10:40M 01:80M 00:160M */
#define BIT_SEC_CLK_SEL(x)                   (((u32)((x) & 0x00000003) << 20))
#define BIT_GET_SEC_CLK_SEL(x)               ((u32)(((x >> 20) & 0x00000003)))
#define BIT_MASK_MAC_CLK_SEL                 ((u32)0x00000003 << 18)          /*!<R/W 2'b01  11/10:20M 01:40M 00:80M */
#define BIT_MAC_CLK_SEL(x)                   (((u32)((x) & 0x00000003) << 18))
#define BIT_GET_MAC_CLK_SEL(x)               ((u32)(((x >> 18) & 0x00000003)))
#define BIT_MASK_CPU_CLK_SEL                 ((u32)0x00000003 << 16)          /*!<R/W 0   */
#define BIT_CPU_CLK_SEL(x)                   (((u32)((x) & 0x00000003) << 16))
#define BIT_GET_CPU_CLK_SEL(x)               ((u32)(((x >> 16) & 0x00000003)))
#define BIT_WL_CLK_SYNC                      ((u32)0x00000001 << 15)          /*!<R/W 0  1: sync 40M/80M clock phase with PLL */
#define BIT_MASK_WL_RFC_PHASE                ((u32)0x0000000F << 8)          /*!<R/W 0  80M WLRFC clock phase control */
#define BIT_WL_RFC_PHASE(x)                  (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_WL_RFC_PHASE(x)              ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_WL_40M_PHASE                ((u32)0x0000000F << 4)          /*!<R/W 0  40M MAC clock phase control */
#define BIT_WL_40M_PHASE(x)                  (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_WL_40M_PHASE(x)              ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_WL_80M_PHASE                ((u32)0x0000000F << 0)          /*!<R/W 0  80M security clock phase control */
#define BIT_WL_80M_PHASE(x)                  (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_WL_80M_PHASE(x)              ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CPWM
 * @brief
 * @{
 **/
#define BIT_CPWM_TOGGLING                    ((u32)0x00000001 << 15)          /*!<R/W 0  Toggling bit : one bit sequence number bit. When this bit is toggled, interrupt is send to HISR.CPWMINT. */
#define BIT_MASK_CPWM_MOD                    ((u32)0x00007FFF << 0)          /*!<R/W 0  The current power mode index. */
#define BIT_CPWM_MOD(x)                      (((u32)((x) & 0x00007FFF) << 0))
#define BIT_GET_CPWM_MOD(x)                  ((u32)(((x >> 0) & 0x00007FFF)))
/** @} */

/** @defgroup REG_RPWM
 * @brief register for hrpwm
 * @{
 **/
#define BIT_RPWM_TOGGLING                    ((u32)0x00000001 << 15)          /*!<R/W 0  Toggling bit : one bit sequence number bit. When this bit is toggled, interrupt is send to FISR.RPWMINT. */
#define BIT_MASK_RPWM_MOD                    ((u32)0x00007FFF << 0)          /*!<R/W 0  The current power mode index. */
#define BIT_RPWM_MOD(x)                      (((u32)((x) & 0x00007FFF) << 0))
#define BIT_GET_RPWM_MOD(x)                  ((u32)(((x >> 0) & 0x00007FFF)))
/** @} */

/** @defgroup REG_RSV_CTRL
 * @brief
 * @{
 **/
#define BIT_MASK_HREG_DBG                    ((u32)0x00000FFF << 12)          /*!<RO 0  HREG Access Debug information */
#define BIT_HREG_DBG(x)                      (((u32)((x) & 0x00000FFF) << 12))
#define BIT_GET_HREG_DBG(x)                  ((u32)(((x >> 12) & 0x00000FFF)))
#define BIT_LOCK_REGALL_EN                   ((u32)0x00000001 << 7)          /*!<R/W 0  1:Enable ‘Locked All’ setting by Hardware, 0: Hardware Enable ‘Locked All’ denied. */
#define BIT_PRST_WLMAC                       ((u32)0x00000001 << 6)          /*!<R/W 0   */
#define BIT_WLOCK_1C_B6                      ((u32)0x00000001 << 5)          /*!<R/W 0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x001C[6]) */
#define BIT_WLOCK_40                         ((u32)0x00000001 << 4)          /*!<R/W 0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x0040h~0x0043h) */
#define BIT_WLOCK_08                         ((u32)0x00000001 << 3)          /*!<R/W 0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x0008h~0x000Bh) */
#define BIT_WLOCK_04                         ((u32)0x00000001 << 2)          /*!<R/W 0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x0004h~0x0007h) */
#define BIT_WLOCK_00                         ((u32)0x00000001 << 1)          /*!<R/W 0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x0000h~0x0003h) */
#define BIT_WLOCK_ALL                        ((u32)0x00000001 << 0)          /*!<R/W 0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x0000h~0x00FFh) */
/** @} */

/** @defgroup REG_WL_PMC_CTRL
 * @brief
 * @{
 **/
#define BIT_WLPON_OPT_EXCKN2A                ((u32)0x00000001 << 25)          /*!<R/W 1   */
#define BIT_WLPON_OPT_EXCKP2A                ((u32)0x00000001 << 24)          /*!<R/W 1  PON option to enable AFE clock */
#define BIT_MASK_WL_PMC_CNT_PAR              ((u32)0x0000003F << 8)          /*!<R/W 0x1F  WL PMC FSM counting unit. */
#define BIT_WL_PMC_CNT_PAR(x)                (((u32)((x) & 0x0000003F) << 8))
#define BIT_GET_WL_PMC_CNT_PAR(x)            ((u32)(((x >> 8) & 0x0000003F)))
#define BIT_CUR_PST_IS_LPS                   ((u32)0x00000001 << 4)          /*!<RO   indicate current WL power status is LPS mode */
#define BIT_WL_PMC_LPS_EN                    ((u32)0x00000001 << 2)          /*!<R/W 0  Inform WLAN PMC FSM to enter LPS mode. (auto clear when ready) */
#define BIT_WL_PMC_OFFMAC                    ((u32)0x00000001 << 1)          /*!<R/W 0  Inform WLAN PMC FSM to power OFF mode, include clock, isolation, power control for MAC only (clear when Power Ready) */
#define BIT_WL_PMC_ONMAC                     ((u32)0x00000001 << 0)          /*!<R/W 0  Inform WLAN PMC FSM to power On mode, include clock, isolation, power control for MAC only (clear when Power Ready) */
/** @} */

/** @defgroup REG_WL_SYSCONFIG
 * @brief
 * @{
 **/
#define BIT_DIS_TIMEOUT_IO                   ((u32)0x00000001 << 24)          /*!<R/W 0  Disabled timeout of IO wrapper */
#define BIT_MCU_WDT_MODE                     ((u32)0x00000001 << 21)          /*!<R/W 0   */
#define BIT_WLCPU_ANA_PORT_IDLE              ((u32)0x00000001 << 17)          /*!<R 0   */
#define BIT_WLCPU_MAC_PORT_IDLE              ((u32)0x00000001 << 16)          /*!<R 0   */
/** @} */

/** @defgroup REG_P0_TBTT_TIMER
 * @brief
 * @{
 **/
#define BIT_MASK_P0_ELY_BCNINT_CNT           ((u32)0x0000007F << 24)          /*!<R 0  Unit: bcn_space the total time to next specified TBTT is (new_ely_agg_cnt - 1) * r_bcn_space(0x554) + (beacon_cnt_down - 1)* 1ms + (cnt_128us + 1)* 128us */
#define BIT_P0_ELY_BCNINT_CNT(x)             (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_P0_ELY_BCNINT_CNT(x)         ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_P0_BCN_CNT_DOWN             ((u32)0x0000FFFF << 3)          /*!<R 0  Unit: 1ms beacon_cnt_down - 1 */
#define BIT_P0_BCN_CNT_DOWN(x)               (((u32)((x) & 0x0000FFFF) << 3))
#define BIT_GET_P0_BCN_CNT_DOWN(x)           ((u32)(((x >> 3) & 0x0000FFFF)))
#define BIT_MASK_P0_128US_CNT                ((u32)0x00000007 << 0)          /*!<R 0  Unit: 128us */
#define BIT_P0_128US_CNT(x)                  (((u32)((x) & 0x00000007) << 0))
#define BIT_GET_P0_128US_CNT(x)              ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_LPSOFFLOAD_CTL_BCUT
 * @brief
 * @{
 **/
#define BIT_R_BYPASS_HIOE_CHN_OFF_B          ((u32)0x00000001 << 3)          /*!<R/W 1  when set 1, bypass request to CHOFF of hioe */
#define BIT_R_BYPASS_HIOE_CHN_ON_B           ((u32)0x00000001 << 2)          /*!<R/W 1  when set 1, bypass request to CHON of hioe */
#define BIT_R_HW_AUTO_ENTER_LPS_EN_B         ((u32)0x00000001 << 1)          /*!<R/W 0  when set 1, enable hw auto enter lps when triggered by lpsoffload */
#define BIT_R_RXBCN_LPSOFFLOAD_EN_B          ((u32)0x00000001 << 0)          /*!<R/W 0  when set 1, enable lpsoffload function */
/** @} */

/** @defgroup REG_AFC_CTRL0
 * @brief
 * @{
 **/
#define BIT_POW_AFE_REQ                      ((u32)0x00000001 << 13)          /*!<R/W 0  AFE power on request to afe_ctrl 1:request to turn on AFE pwr 0:turn off AFE pwr */
#define BIT_MASK_WL_XTAL_REQ_ACT             ((u32)0x00000007 << 4)          /*!<R/W 0x4  000: xtal off 001: xtal lps mode gating 40M 010: xtal lps mode enable 40M 011: xtal normal mode 100：xtal hp mode */
#define BIT_WL_XTAL_REQ_ACT(x)               (((u32)((x) & 0x00000007) << 4))
#define BIT_GET_WL_XTAL_REQ_ACT(x)           ((u32)(((x >> 4) & 0x00000007)))
#define BIT_MASK_WL_XTAL_REQ_LPS             ((u32)0x00000007 << 1)          /*!<R/W 0x0  000: xtal off 001: xtal lps mode gating 40M 010: xtal lps mode enable 40M 011: xtal normal mode 100：xtal hp mode */
#define BIT_WL_XTAL_REQ_LPS(x)               (((u32)((x) & 0x00000007) << 1))
#define BIT_GET_WL_XTAL_REQ_LPS(x)           ((u32)(((x >> 1) & 0x00000007)))
/** @} */

/** @defgroup REG_FSIMR_V1
 * @brief
 * @{
 **/
#define BIT_FS_BTON_STS_UPDATE_INT_EN        ((u32)0x00000001 << 0)          /*!<R/W 0  BTON status update interrupt When 0x78[31] toggled, this interrupt is issue to indicate the status updated. */
/** @} */

/** @defgroup REG_FSISR_V1
 * @brief
 * @{
 **/
#define BIT_FS_BTON_STS_UPDATE_INT           ((u32)0x00000001 << 0)          /*!<RW1C 0  BTON status update interrupt When 0x78[31] toggled, this interrupt is issue to indicate the status updated. */
/** @} */

/** @defgroup REG_FW_DBG0
 * @brief
 * @{
 **/
#define BIT_MASK_FW_DBG0                     ((u32)0xFFFFFFFF << 0)          /*!<R/W 0  fw debug0 */
#define BIT_FW_DBG0(x)                       (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG0(x)                   ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG1
 * @brief
 * @{
 **/
#define BIT_MASK_FW_DBG1                     ((u32)0xFFFFFFFF << 0)          /*!<R/W 0  fw debug1 */
#define BIT_FW_DBG1(x)                       (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG1(x)                   ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG2
 * @brief
 * @{
 **/
#define BIT_MASK_FW_DBG2                     ((u32)0xFFFFFFFF << 0)          /*!<R/W 0  fw debug2 */
#define BIT_FW_DBG2(x)                       (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG2(x)                   ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG3
 * @brief
 * @{
 **/
#define BIT_MASK_FW_DBG3                     ((u32)0xFFFFFFFF << 0)          /*!<R/W 0  fw debug3 */
#define BIT_FW_DBG3(x)                       (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG3(x)                   ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG4
 * @brief
 * @{
 **/
#define BIT_MASK_FW_DBG4                     ((u32)0xFFFFFFFF << 0)          /*!<R/W 0  fw debug4 */
#define BIT_FW_DBG4(x)                       (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG4(x)                   ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG5
 * @brief
 * @{
 **/
#define BIT_MASK_FW_DBG5                     ((u32)0xFFFFFFFF << 0)          /*!<R/W 0  fw debug5 */
#define BIT_FW_DBG5(x)                       (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG5(x)                   ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG6
 * @brief
 * @{
 **/
#define BIT_MASK_FW_DBG6                     ((u32)0xFFFFFFFF << 0)          /*!<R/W 0  fw debug6 */
#define BIT_FW_DBG6(x)                       (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG6(x)                   ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG7
 * @brief
 * @{
 **/
#define BIT_MASK_FW_DBG7                     ((u32)0xFFFFFFFF << 0)          /*!<R/W 0  fw debug7 */
#define BIT_FW_DBG7(x)                       (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG7(x)                   ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_WL_PIN_FUNC_CTRL0
 * @brief
 * @{
 **/
#define BIT_MASK_WL_DBG_SEL                  ((u32)0x000000FF << 24)          /*!<R/W 0  WL debug select */
#define BIT_WL_DBG_SEL(x)                    (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_WL_DBG_SEL(x)                ((u32)(((x >> 24) & 0x000000FF)))
/** @} */

/** @defgroup REG_WL_BTCOEX_CTRL
 * @brief
 * @{
 **/
#define BIT_LTECOEX_DBGEN                    ((u32)0x00000001 << 20)          /*!<R/W 0   */
#define BIT_MASK_BTMODE_V1                   ((u32)0x00000003 << 17)          /*!<R/W 0  Bluetooth Mode */
#define BIT_BTMODE_V1(x)                     (((u32)((x) & 0x00000003) << 17))
#define BIT_GET_BTMODE_V1(x)                 ((u32)(((x >> 17) & 0x00000003)))
#define BIT_ENBT_V1                          ((u32)0x00000001 << 16)          /*!<R/W 0  Enable PTA ( from BT side) */
#define BIT_WL_DPDT1_IDV                     ((u32)0x00000001 << 3)          /*!<R/W 1   */
#define BIT_WL_DPDT1_MUX                     ((u32)0x00000001 << 2)          /*!<R/W 0   */
#define BIT_WL_DPDT0_IDV                     ((u32)0x00000001 << 1)          /*!<R/W 1   */
#define BIT_WL_DPDT0_MUX                     ((u32)0x00000001 << 0)          /*!<R/W 0   */
/** @} */

/** @defgroup REG_SCOREBOARD_RD_BT2WL
 * @brief
 * @{
 **/
#define BIT_MASK_RD_BT2WL_INFO               ((u32)0x000000FF << 24)          /*!<R 0  Read Data : WL TO BT INFO, WLON Status Report */
#define BIT_RD_BT2WL_INFO(x)                 (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_RD_BT2WL_INFO(x)             ((u32)(((x >> 24) & 0x000000FF)))
/** @} */

/** @defgroup REG_DBG_PORT_REG
 * @brief
 * @{
 **/
#define BIT_MASK_DEBUG_ST                    ((u32)0xFFFFFFFF << 0)          /*!<RO 0  Debug signals, sel by 70[31:24] */
#define BIT_DEBUG_ST(x)                      (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_DEBUG_ST(x)                  ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_WL_MCUFW_CTRL
 * @brief
 * @{
 **/
#define BIT_FW_INIT_RDY                      ((u32)0x00000001 << 15)          /*!<R/W 0  CPU fw initialize ready, set by CPU(txrpt info update,used in ptcl) */
/** @} */

/** @defgroup REG_FW_DBG8
 * @brief
 * @{
 **/
#define BIT_MASK_BLK_TST                     ((u32)0xFFFFFFFF << 0)          /*!<R/W 0  fw debug8 */
#define BIT_BLK_TST(x)                       (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BLK_TST(x)                   ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG9
 * @brief
 * @{
 **/
#define BIT_MASK_HOST_MSG_E1                 ((u32)0x0000FFFF << 16)          /*!<R/W 0  User Defined Message */
#define BIT_HOST_MSG_E1(x)                   (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_HOST_MSG_E1(x)               ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_HOST_MSG_E0                 ((u32)0x0000FFFF << 0)          /*!<R/W 0  User Defined Message */
#define BIT_HOST_MSG_E0(x)                   (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_HOST_MSG_E0(x)               ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_FW_DBG10
 * @brief
 * @{
 **/
#define BIT_MASK_HOST_MSG_E3                 ((u32)0x0000FFFF << 16)          /*!<R/W 0  User Defined Message */
#define BIT_HOST_MSG_E3(x)                   (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_HOST_MSG_E3(x)               ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_HOST_MSG_E2                 ((u32)0x0000FFFF << 0)          /*!<R/W 0  User Defined Message */
#define BIT_HOST_MSG_E2(x)                   (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_HOST_MSG_E2(x)               ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_LPS_CTRL
 * @brief
 * @{
 **/
#define BIT_WL_LPS_OPT_SAVE_REG              ((u32)0x00000001 << 29)          /*!<R/W 1  LPS option to save retention FF 1: enable request to save retention FF 0: disable request to save retention FF */
#define BIT_LPS_MEMPM_PHYON                  ((u32)0x00000001 << 28)          /*!<R/W 0   */
#define BIT_MASK_LPS_MEMPM_MACOFF_FTC_SHR    ((u32)0x00000003 << 23)          /*!<R/W 2'b11  MAC OFF FTC memory power mode when enable LPS memory power mode(for rxpktbuf/ txpktbuf low 24k[SHARE with system]) 00 : normal 01 : NAP 10 : RET 11 : SLP */
#define BIT_LPS_MEMPM_MACOFF_FTC_SHR(x)      (((u32)((x) & 0x00000003) << 23))
#define BIT_GET_LPS_MEMPM_MACOFF_FTC_SHR(x)  ((u32)(((x >> 23) & 0x00000003)))
#define BIT_MASK_LPS_MEMPM_MACOFF_FTC_TXRPT  ((u32)0x00000003 << 21)          /*!<R/W 2'b11  MAC OFF FTC memory power mode when enable LPS memory power mode (for txrptbuf) 00 : normal 01 : NAP 10 : RET 11 : SLP */
#define BIT_LPS_MEMPM_MACOFF_FTC_TXRPT(x)    (((u32)((x) & 0x00000003) << 21))
#define BIT_GET_LPS_MEMPM_MACOFF_FTC_TXRPT(x) ((u32)(((x >> 21) & 0x00000003)))
#define BIT_MASK_LPS_MEMPM_MACON_FTC_TXPKT   ((u32)0x00000003 << 19)          /*!<R/W 2'b11  MAC ON FTC memory power mode when enable LPS memory power mode (for txpktbuf high 8k) 00 : normal 01 : NAP 10 : RET 11 : SLP */
#define BIT_LPS_MEMPM_MACON_FTC_TXPKT(x)     (((u32)((x) & 0x00000003) << 19))
#define BIT_GET_LPS_MEMPM_MACON_FTC_TXPKT(x) ((u32)(((x >> 19) & 0x00000003)))
#define BIT_LPS_MEMPM_MACOFF_FTC             ((u32)0x00000001 << 18)          /*!<R/W 0x1  MAC OFF FTC/SNPS memory power mode when enable LPS memory power mode (for rxfifo/txfifo) 0 : normal 1 : NAP/LS */
#define BIT_LPS_MEMPM_MACOFF_SNPS            ((u32)0x00000001 << 17)          /*!<R/W 0x1  MAC OFF SNPS memory power mode when enable LPS memory power mode(txllt/rc4/txoqt/keysrch/rxbacam/dmafifo) 0 : normal 1 : NAP */
#define BIT_MASK_LPS_MEMPM_MACOFF_PG_FTC     ((u32)0x00000003 << 15)          /*!<R/W 2'b11  MAC OFF FTC memory power mode when enable LPS memory power mode(for rxcsibuf) 00 : normal 01 : NAP 10 : RET 11 : SLP */
#define BIT_LPS_MEMPM_MACOFF_PG_FTC(x)       (((u32)((x) & 0x00000003) << 15))
#define BIT_GET_LPS_MEMPM_MACOFF_PG_FTC(x)   ((u32)(((x >> 15) & 0x00000003)))
#define BIT_WL_LPS_OPT_EMACFUN               ((u32)0x00000001 << 10)          /*!<R/W 0  LPS option to reset WL MAC OFF block when enable WL MAC OFF power 1: not reset WL MAC OFF block 0: reset WL MAC OFF block */
#define BIT_WL_LPS_OPT_EPHYPWR               ((u32)0x00000001 << 9)          /*!<R/W 0  LPS option to enable WL BB block power 1: Enable WL BB block power 0: Disable WL BB block power */
#define BIT_WL_LPS_OPT_EMACPWR               ((u32)0x00000001 << 8)          /*!<R/W 0  LPS option to enable WL MAC OFF block power 1: Enable WL MAC OFF block power 0: Disable WL MAC OFF block power */
#define BIT_WL_LPS_MEMPM_EN                  ((u32)0x00000001 << 1)          /*!<R/W 0  enable LPS memory power mode control */
#define BIT_WL_NRM_MEMPM_SL                  ((u32)0x00000001 << 0)          /*!<R/W 0  MAC memory power mode when BIT_WL_LPS_MEMPM_EN is 0, 0 : Normal 1 : SD */
/** @} */

/** @defgroup REG_FW_DBG11
 * @brief
 * @{
 **/
#define BIT_MASK_FW_DBG11                    ((u32)0xFFFFFFFF << 0)          /*!<R/W 0  fw debug11 */
#define BIT_FW_DBG11(x)                      (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG11(x)                  ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_boot_reason
 * @brief
 * @{
 **/
#define BIT_WL_WDT_PLFM                      ((u32)0x00000001 << 1)          /*!<R/W 0  (not used) */
#define BIT_WL_WDT_MCU                       ((u32)0x00000001 << 0)          /*!<R/W 0  (not used) */
/** @} */

/** @defgroup REG_SCOREBOARD_CTRL
 * @brief
 * @{
 **/
#define BIT_BT_INT_EN                        ((u32)0x00000001 << 31)          /*!<W 0  For WL, write 1 to issue interrupt 1 : Issue one INT to BT 0 : Don't care */
#define BIT_MASK_WL2BT_INFO                  ((u32)0x0000007F << 24)          /*!<R/W 0  WLON Status Report TO BTON */
#define BIT_WL2BT_INFO(x)                    (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_WL2BT_INFO(x)                ((u32)(((x >> 24) & 0x0000007F)))
/** @} */

/** @defgroup REG_SYSON_FSM_MON_V1
 * @brief
 * @{
 **/
#define BIT_MASK_WLPMC_DEBUG_SEL             ((u32)0x0000000F << 24)          /*!<R/W 0  debug select signal for WL PMC */
#define BIT_WLPMC_DEBUG_SEL(x)               (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_WLPMC_DEBUG_SEL(x)           ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_WLPMC_DEBUG                 ((u32)0x0000FFFF << 0)          /*!<RO 0  debug signal of WL PMC */
#define BIT_WLPMC_DEBUG(x)                   (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_WLPMC_DEBUG(x)               ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_PMC_DBG_CTRL1
 * @brief
 * @{
 **/
#define BIT_PMC_WR_OVF                       ((u32)0x00000001 << 8)          /*!<RW1C 0  PMC Write Access Timer Overflow(no use) */
#define BIT_MASK_WLPMC_ERRINT                ((u32)0x000000FF << 0)          /*!<RW1C 0  WLPMC Error interrupt(tie 0) */
#define BIT_WLPMC_ERRINT(x)                  (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_WLPMC_ERRINT(x)              ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_PMC_DBG_CTRL2_V1
 * @brief
 * @{
 **/
#define BIT_MASK_SYSON_REG_ARB               ((u32)0x00000003 << 0)          /*!<R/W 0  HW PMC Access Register Time Out Control(no use) */
#define BIT_SYSON_REG_ARB(x)                 (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_SYSON_REG_ARB(x)             ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_SDM_IDR_CTRL0
 * @brief
 * @{
 **/
#define BIT_MASK_SDM_ADDR                    ((u32)0x0000003F << 0)          /*!<R/W 0  SDM register offset */
#define BIT_SDM_ADDR(x)                      (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_SDM_ADDR(x)                  ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_WL_CK32KGEN_RWD
 * @brief
 * @{
 **/
#define BIT_MASK_CK32GEN_RD                  ((u32)0xFFFFFFFF << 0)          /*!<RO 0   */
#define BIT_CK32GEN_RD(x)                    (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_CK32GEN_RD(x)                ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_SYS_CONFIG0
 * @brief
 * @{
 **/
#define BIT_IS_SCH_CLK_INSLP_V1              ((u32)0x00000001 << 8)          /*!<RO 0  WL TSF clock status: 0: MAC clock 1: 32K clock */
#define BIT_MASK_VENDOR_ID_V1                ((u32)0x0000000F << 4)          /*!<RO 4'b1000  Vendor ID [7:6] : Download FW version ; 00: TSMC , 01: SMIC, 10: UMC [5] ; 0 : Download FW , init BB and RF registers 1 : Do not download FW and do not init BB and RF registers [4] ; 0 : BT do not exist in IC 1 : BT exist in IC */
#define BIT_VENDOR_ID_V1(x)                  (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_VENDOR_ID_V1(x)              ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_PLL_CK_RDY                       ((u32)0x00000001 << 0)          /*!<RO 0  indicate AFE PLL clock is ready */
/** @} */


/*==========REG_PAGE0 Register Address Definition==========*/
#define REG_SYS_PWC_ISO_CTRL                         0x0000
#define REG_WL_CLK_CTRL                              0x0002
#define REG_WL_FUNC_EN                               0x0004
#define REG_CLKDIV_CKSEL                             0x0008
#define REG_CPWM                                     0x000C
#define REG_RPWM                                     0x0014
#define REG_RSV_CTRL                                 0x001C
#define REG_WL_PMC_CTRL                              0x0020
#define REG_WL_SYSCONFIG                             0x0024
#define REG_P0_TBTT_TIMER                            0x0028
#define REG_LPSOFFLOAD_CTL_BCUT                      0x002C
#define REG_AFC_CTRL0                                0x0030
#define REG_FSIMR_V1                                 0x0040
#define REG_FSISR_V1                                 0x0044
#define REG_FW_DBG0                                  0x0050	/* Refer to WIFI_SHARE_INFO->RECV_RSSI */
#define REG_FW_DBG1                                  0x0054	/* Refer to WIFI_SHARE_INFO->FA_CCK_OFDM */
#define REG_FW_DBG2                                  0x0058
#define REG_FW_DBG3                                  0x005C	/* Refer to WIFI_SHARE_INFO->TX_DONE_TO_DRV */
#define REG_FW_DBG4                                  0x0060
#define REG_FW_DBG5                                  0x0064	/* Refer to WIFI_SHARE_INFO->TX_DONE_TO_APP */
#define REG_FW_DBG6                                  0x0068	/* Refer to WIFI_SHARE_INFO->MAC_AUTO_LPS */
#define REG_FW_DBG7                                  0x006C
#define REG_WL_PIN_FUNC_CTRL0                        0x0070
#define REG_WL_BTCOEX_CTRL                           0x0074
#define REG_SCOREBOARD_RD_BT2WL                      0x0078
#define REG_DBG_PORT_REG                             0x007C
#define REG_WL_MCUFW_CTRL                            0x0080
#define REG_FW_DBG8                                  0x0084
#define REG_FW_DBG9                                  0x0088
#define REG_FW_DBG10                                 0x008C
#define REG_LPS_CTRL                                 0x0090
#define REG_FW_DBG11                                 0x0094
#define REG_BOOT_REASON                              0x0098
#define REG_SCOREBOARD_CTRL                          0x00A0
#define REG_SYSON_FSM_MON_V1                         0x00A4
#define REG_PMC_DBG_CTRL1                            0x00A8
#define REG_PMC_DBG_CTRL2_V1                         0x00AC
#define REG_SDM_IDR_CTRL0                            0x00E8
#define REG_WL_CK32KGEN_RWD                          0x00EC
#define REG_SYS_CONFIG0                              0x00F0

/** @} */

/* AUTO_GEN_END */

/* MANUAL_GEN_START */

//Please add your defination here

/* MANUAL_GEN_END */

/** @} */

/** @} */

#endif
