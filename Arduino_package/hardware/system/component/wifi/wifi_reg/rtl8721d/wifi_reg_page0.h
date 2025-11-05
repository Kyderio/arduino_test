#ifndef _project_name_REG_PAGE0_H_
#define _project_name_REG_PAGE0_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE0
  * @brief REG_PAGE0 driver modules
  * @{
  */


/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE0_Register_Definitions REG_PAGE0 Register Definitions
  * @{
  */

/** @defgroup REG_SYS_PWC_CTRL
  * @brief
  * @{
  */
#define BIT_ISO_AFE         ((u16)0x00000001 << 12) /*!< R/W 0x1  Isolation control for AFE, 1: isolation; 0: attach*/
#define BIT_ISO_MAC         ((u16)0x00000001 << 8)  /*!< R/W 0x1  Isolation control for MAC, 1: isolation; 0: attach*/
#define BIT_WL_SWR_REQ_1P1V ((u16)0x00000001 << 4)  /*!< R/W 0x0  1: wl request switch SWR vlotage to 1.1V  0: wl request switch SWR vlotage to 0.9V*/
#define BIT_LPC_MAC_EN      ((u16)0x00000001 << 1)  /*!< R/W 0x0  1: Enable MAC large power cut*/
#define BIT_SPC_MAC_EN      ((u16)0x00000001 << 0)  /*!< R/W 0x0  1: Enable MAC small power cut*/
/** @} */

/** @defgroup REG_WL_CLK_CTRL
  * @brief
  * @{
  */
#define BIT_IS_SCH_CLK_INSLP_V2 ((u16)0x00000001 << 9) /*!< RO 0x0  WL TSF clock status: 0: MAC clock 1: 32K clock*/
#define BIT_TSF_CKSLP_SEL       ((u16)0x00000001 << 8) /*!< R/W 0x0  1: TSF clock switch to 32.768KHz; 0: TSF clock switch to MAC clock*/
#define BIT_WL_FQSEL_CK32K      ((u16)0x00000001 << 5) /*!< R/W 0x0  1:32K frequency select 32.768KHz 0:32K frequency select 32KHz*/
#define BIT_CKSL_CK32K          ((u16)0x00000001 << 4) /*!< R/W 0x0  1:select MAC internal 32K clk, 0:select MAC external 32K clk*/
#define BIT_WL_CKMCU_EN         ((u16)0x00000001 << 2)          /*!<R/W 0  1: enable MCU engine clock; 0: gated */
#define BIT_WL_CKSEC_EN         ((u16)0x00000001 << 1) /*!< R/W 0x0  1: enable MAC security engine clock; 0: gated*/
#define BIT_WL_CKMAC_EN         ((u16)0x00000001 << 0) /*!< R/W 0x0  1: enable MAC clock; 0: gated*/
/** @} */

/** @defgroup REG_WL_FUNC_EN
  * @brief REG_WL_MAC_EN
  * @{
  */
#define BIT_DAI_RW_EN          ((u32)0x00000001 << 31) /*!< R/W 0x0  DAI讀寫enable*/
#define BIT_DAI_REG00_WREN     ((u32)0x00000001 << 30) /*!< R/W 0x0  DAI寫enable reg00.(ANAPAR_RF[7]為"1",需額外設定ANAPAR_RF[6] 為"1"才能寫入reg00)*/
#define BIT_RF_RSTB_V1         ((u32)0x00000001 << 25) /*!< R/W 0x0  Reset RF Module (low active)*/
#define BIT_FEN_BBRSTB_V2      ((u32)0x00000001 << 17) /*!< R/W 0x0  When this bit is set to "0", CCK and OFDM are disabled, and clock are gated. Otherwise, CCK and OFDM are enabled.*/
#define BIT_FEN_BB_GLB_RSTN_V2 ((u32)0x00000001 << 16) /*!< R/W 0x0  When this bit is set to "0", whole BB is reset. When this bit is set, BB is enabled.*/
#define BIT_FEN_WLON           ((u32)0x00000001 << 4)  /*!< RW 0x0  1: enable WL partial ON; 0: reset*/
#define BIT_FEN_WLOFF          ((u32)0x00000001 << 1)  /*!< RW 0x0  1: enable WLOFF; 0: reset*/
#define BIT_FEN_MAC_PMC        ((u32)0x00000001 << 0)  /*!< R/W 0x0  1: enable MAC PMC; 0: reset*/
/** @} */

/** @defgroup REG_CLKDIV
  * @brief
  * @{
  */
#define BIT_WL_CLK_SYNC         ((u32)0x00000001 << 15)          /*!< R/W 0x0  1: sync 40M/80M clock  phase with PLL*/
#define BIT_MASK_WL_40M_PHASE   ((u32)0x0000000F << 4)           /*!< R/W 0x0  40M MAC clock phase control*/
#define BIT_WL_40M_PHASE(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_WL_40M_PHASE(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_WL_80M_PHASE   ((u32)0x0000000F << 0)           /*!< R/W 0x0  80M security clock phase control*/
#define BIT_WL_80M_PHASE(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_WL_80M_PHASE(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_RSV_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_HREG_DBG   ((u32)0x00000FFF << 12)           /*!< RO 0x0  HREG Access Debug information*/
#define BIT_HREG_DBG(x)     (((u32)((x) & 0x00000FFF) << 12))
#define BIT_GET_HREG_DBG(x) ((u32)(((x >> 12) & 0x00000FFF)))
#define BIT_LOCK_ALL_EN     ((u32)0x00000001 << 7)            /*!< R/W 0x0  1:Enable 'Locked All' setting by Hardware, 0: Hardware Enable 'Locked All' denied.*/
#define BIT_WLOCK_1C_B6     ((u32)0x00000001 << 5)            /*!< R/W 0x0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x001C[6])*/
#define BIT_WLOCK_40        ((u32)0x00000001 << 4)            /*!< R/W 0x0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x0040h~0x0043h)*/
#define BIT_WLOCK_08        ((u32)0x00000001 << 3)            /*!< R/W 0x0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x0008h~0x000Bh)*/
#define BIT_WLOCK_04        ((u32)0x00000001 << 2)            /*!< R/W 0x0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x0004h~0x0007h)*/
#define BIT_WLOCK_00        ((u32)0x00000001 << 1)            /*!< R/W 0x0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x0000h~0x0003h)*/
#define BIT_WLOCK_ALL       ((u32)0x00000001 << 0)            /*!< R/W 0x0  1:Register Write Locked, 0: Register Accessible by SW/FW (offset:0x0000h~0x00FFh)*/
/** @} */

/** @defgroup REG_WL_PMC_CTRL
  * @brief
  * @{
  */
#define BIT_WLPON_OPT_EXCKP2A     ((u32)0x00000001 << 24)          /*!< R/W 0x1  PON option to enable AFE clock*/
#define BIT_MASK_WL_PMC_CNT_PAR   ((u32)0x0000003F << 8)           /*!< R/W 0x1F  WL PMC FSM counting unit.*/
#define BIT_WL_PMC_CNT_PAR(x)     (((u32)((x) & 0x0000003F) << 8))
#define BIT_GET_WL_PMC_CNT_PAR(x) ((u32)(((x >> 8) & 0x0000003F)))
#define BIT_CUR_PST_IS_LPS        ((u32)0x00000001 << 4)           /*!< RO   indicate current WL power status is LPS mode*/
#define BIT_WL_PMC_LPS_EN         ((u32)0x00000001 << 2)           /*!< R/W 0x0  Inform WLAN PMC FSM to enter LPS mode.  (auto clear when ready)*/
#define BIT_WL_PMC_OFFMAC         ((u32)0x00000001 << 1)           /*!< R/W 0x0  Inform WLAN PMC FSM to power OFF mode, include clock, isolation, power control for MAC only (clear when Power Ready)*/
#define BIT_WL_PMC_ONMAC          ((u32)0x00000001 << 0)           /*!< R/W 0x0  Inform WLAN PMC FSM to power On mode, include clock, isolation, power control for MAC only (clear when Power Ready)*/
/** @} */

/** @defgroup REG_WL_SYSCONFIG
  * @brief
  * @{
  */
#define BIT_DIS_TIMEOUT_IO ((u32)0x00000001 << 24) /*!< R/W 0x0  Disabled timeout of IO wrapper*/
/** @} */

/** @defgroup REG_AFC_CTRL0
  * @brief
  * @{
  */
#define BIT_CK40M_EN                 ((u32)0x00000001 << 31)           /*!< R/W 0x1  CKO40_PLL for BT_RFC*/
#define BIT_CK80M_EN                 ((u32)0x00000001 << 30)           /*!< R/W 0x1  CKO80_PLL for WL_RFC*/
#define BIT_MASK_REG_CP_BIA_2_0      ((u32)0x00000007 << 27)           /*!< R/W 3'b001  pll CP current selection 000 5uA 001 10uA 010 15uA 011 20uA 100 25uA 101 30uA 110 35uA 111 40uA*/
#define BIT_REG_CP_BIA_2_0(x)        (((u32)((x) & 0x00000007) << 27))
#define BIT_GET_REG_CP_BIA_2_0(x)    ((u32)(((x >> 27) & 0x00000007)))
#define BIT_REG_EN_MON               ((u32)0x00000001 << 26)           /*!< R/W 0x0  1:Enable 0:output "1"*/
#define BIT_REG_TESTEN               ((u32)0x00000001 << 25)           /*!< R/W 0x0  */
#define BIT_BTCK320M_PS              ((u32)0x00000001 << 24)           /*!< R/W 0x0  DEBUG*/
#define BIT_BTCK320M_EN              ((u32)0x00000001 << 23)           /*!< R/W 0x0  1:enable 0:?? (BT:BT_CLK_EN_PLL)*/
#define BIT_MASK_REG_PS_2_0          ((u32)0x00000007 << 20)           /*!< R/W 0x0  Phase swallow setting*/
#define BIT_REG_PS_2_0(x)            (((u32)((x) & 0x00000007) << 20))
#define BIT_GET_REG_PS_2_0(x)        ((u32)(((x >> 20) & 0x00000007)))
#define BIT_REG_PS_EN                ((u32)0x00000001 << 19)           /*!< R/W 0x1  Phase swallow enable*/
#define BIT_MASK_REG_MONCKSELH_2_0   ((u32)0x00000007 << 16)           /*!< R/W 0x0  ck_mon selection 000 - 160MHz, 001 - 80MHz, 010 - 40MHz,  011 - 640MHz, 100 - ck_200M_test, 101 - ck_ad 110 - ck_ad, 111 - ck_test*/
#define BIT_REG_MONCKSELH_2_0(x)     (((u32)((x) & 0x00000007) << 16))
#define BIT_GET_REG_MONCKSELH_2_0(x) ((u32)(((x >> 16) & 0x00000007)))
#define BIT_RF_PDN11                 ((u32)0x00000001 << 15)           /*!< R/W 0x0  0: PDN RF 11*/
#define BIT_POW_PLL_V2               ((u32)0x00000001 << 9)            /*!< R/W 0x0  power on pll*/
#define BIT_POW_AFE_LDO              ((u32)0x00000001 << 8)            /*!< R/W 0x0  Power on AFE power cut*/
#define BIT_WL_XTAL_ACTIVE_MODE      ((u32)0x00000001 << 7)            /*!< R/W 0x1  1:WL request XTAL to enter active mode 0:WL request XTAL to enter LPS mode*/
#define BIT_WL_XTAL_EN               ((u32)0x00000001 << 6)            /*!< R/W 0x0  1:WL enable XTAL  0:WL disable XTAL*/
#define BIT_XTAL_GATE_RF2            ((u32)0x00000001 << 4)            /*!< R/W 0x1  1: gated XTAL RF2 clock output*/
#define BIT_XTAL_GATE_RF1            ((u32)0x00000001 << 2)            /*!< R/W 0x1  1: gated XTAL RF1 clock output*/
#define BIT_XTAL_GATE_AFE_V1         ((u32)0x00000001 << 0)            /*!< R/W 0x1  1: Gated XTAL AFE clock output*/
/** @} */

/** @defgroup REG_AFE_CTRL1_V1
  * @brief
  * @{
  */
#define BIT_MASK_DIVN_2_0                 ((u32)0x00000007 << 29)           /*!< R/W 3'b110  SDM divider sel*/
#define BIT_DIVN_2_0(x)                   (((u32)((x) & 0x00000007) << 29))
#define BIT_GET_DIVN_2_0(x)               ((u32)(((x >> 29) & 0x00000007)))
#define BIT_MASK_BB_DBG_SEL_AFE_SDM_3_0   ((u32)0x0000000F << 25)           /*!< R/W 0x0  SDM debug selection*/
#define BIT_BB_DBG_SEL_AFE_SDM_3_0(x)     (((u32)((x) & 0x0000000F) << 25))
#define BIT_GET_BB_DBG_SEL_AFE_SDM_3_0(x) ((u32)(((x >> 25) & 0x0000000F)))
#define BIT_RFE_SEL_SDM                   ((u32)0x00000001 << 24)           /*!< R/W 0x1  pll referemce clk select 1:table 0:regesters*/
#define BIT_CK320M_AFE_EN                 ((u32)0x00000001 << 19)           /*!< R/W 0x0  1:enable 320M*/
#define BIT_EN_SYN                        ((u32)0x00000001 << 18)           /*!< R/W 0x0  1:AD/DA clock SYN 5M AD/DA clock*/
#define BIT_CK320M_EN                     ((u32)0x00000001 << 17)           /*!< R/W 0x0  1:Enable 0:output "1" clock gate*/
#define BIT_REG_FREF_EDGE                 ((u32)0x00000001 << 16)           /*!< R/W 0x0  pll referemce clk edge select 0:positive 1:negtive*/
#define BIT_CK5M_EN                       ((u32)0x00000001 << 15)           /*!< R/W 0x0  1:Enable 0:output "1"   5M clock enabel*/
#define BIT_REG_CP_OFFSET                 ((u32)0x00000001 << 14)           /*!< R/W 0x0  CP current offset 1: on 0:off*/
#define BIT_MASK_REG_RS_SET_2_0           ((u32)0x00000007 << 11)           /*!< R/W 3'b010  Set LPF rs 000 ~111 2k/4k/6k/8k/10k/12k/14k/16k*/
#define BIT_REG_RS_SET_2_0(x)             (((u32)((x) & 0x00000007) << 11))
#define BIT_GET_REG_RS_SET_2_0(x)         ((u32)(((x >> 11) & 0x00000007)))
#define BIT_MASK_REG_R3_SET_2_0           ((u32)0x00000007 << 8)            /*!< R/W 3'b110  Set LPF r3 000 ~111  4k/8k/12k/16k/18k/20k/24k/28k/32k*/
#define BIT_REG_R3_SET_2_0(x)             (((u32)((x) & 0x00000007) << 8))
#define BIT_GET_REG_R3_SET_2_0(x)         ((u32)(((x >> 8) & 0x00000007)))
#define BIT_MASK_REG_CS_SET_1_0           ((u32)0x00000003 << 6)            /*!< R/W 2'b10  Set LPF cs 00/01/10/11  20pF/30pF/40/50pF*/
#define BIT_REG_CS_SET_1_0(x)             (((u32)((x) & 0x00000003) << 6))
#define BIT_GET_REG_CS_SET_1_0(x)         ((u32)(((x >> 6) & 0x00000003)))
#define BIT_MASK_REG_CP_SET_1_0           ((u32)0x00000003 << 4)            /*!< R/W 2'b01  Set LPF cp 00/01/10/11  1pF/2pF/3pF/4pF*/
#define BIT_REG_CP_SET_1_0(x)             (((u32)((x) & 0x00000003) << 4))
#define BIT_GET_REG_CP_SET_1_0(x)         ((u32)(((x >> 4) & 0x00000003)))
#define BIT_MASK_REG_C3_SET_1_0           ((u32)0x00000003 << 2)            /*!< R/W 0x0  Set LPF c3 00/01/10/11  0.5pF/1pF/1.5pF/2pF*/
#define BIT_REG_C3_SET_1_0(x)             (((u32)((x) & 0x00000003) << 2))
#define BIT_GET_REG_C3_SET_1_0(x)         ((u32)(((x >> 2) & 0x00000003)))
#define BIT_REG_CK320_SEL                 ((u32)0x00000001 << 1)            /*!< R/W 0x0  Ck 320MHz enable*/
#define BIT_REG_DOGENB                    ((u32)0x00000001 << 0)            /*!< R/W 0x0  enable watch dog 0: enable 1:disable*/
/** @} */

/** @defgroup REG_AFE_CTRL2_V1
  * @brief
  * @{
  */
#define BIT_MASK_CK320M_PS_1_0        ((u32)0x00000FFF << 20)           /*!< R/W 0x0  DEBUG*/
#define BIT_CK320M_PS_1_0(x)          (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_CK320M_PS_1_0(x)      ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_REG_CP_IOFFSET_4_0   ((u32)0x0000001F << 25)           /*!< R/W 0x0  DEBUG*/
#define BIT_REG_CP_IOFFSET_4_0(x)     (((u32)((x) & 0x0000001F) << 25))
#define BIT_GET_REG_CP_IOFFSET_4_0(x) ((u32)(((x >> 25) & 0x0000001F)))
#define BIT_MASK_DIV_SBRB_1_0         ((u32)0x00000003 << 23)           /*!< R/W 0x0  DEBUG*/
#define BIT_DIV_SBRB_1_0(x)           (((u32)((x) & 0x00000003) << 23))
#define BIT_GET_DIV_SBRB_1_0(x)       ((u32)(((x >> 23) & 0x00000003)))
#define BIT_MASK_DITHER_3_0           ((u32)0x0000000F << 19)           /*!< R/W 0x0  Dither funtion*/
#define BIT_DITHER_3_0(x)             (((u32)((x) & 0x0000000F) << 19))
#define BIT_GET_DITHER_3_0(x)         ((u32)(((x >> 19) & 0x0000000F)))
#define BIT_MASK_F0N_2_0              ((u32)0x00000007 << 16)           /*!< R/W 0x0  SDM divider sel*/
#define BIT_F0N_2_0(x)                (((u32)((x) & 0x00000007) << 16))
#define BIT_GET_F0N_2_0(x)            ((u32)(((x >> 16) & 0x00000007)))
#define BIT_MASK_F0F_12_0             ((u32)0x00001FFF << 3)            /*!< R/W 0x0  SDM divider sel*/
#define BIT_F0F_12_0(x)               (((u32)((x) & 0x00001FFF) << 3))
#define BIT_GET_F0F_12_0(x)           ((u32)(((x >> 3) & 0x00001FFF)))
#define BIT_MASK_DIVN_5_3             ((u32)0x00000007 << 0)            /*!< R/W 3'b001  SDM divider sel*/
#define BIT_DIVN_5_3(x)               (((u32)((x) & 0x00000007) << 0))
#define BIT_GET_DIVN_5_3(x)           ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_AFE_CTRL3_V1
  * @brief
  * @{
  */
#define BIT_SEL_8715_LUT   ((u32)0x00000001 << 6)           /*!< R/W 0x0  1 -> 8 phase 500MHz 0 -> 6 phase 640MHz*/
#define BIT_ORDER_SDM      ((u32)0x00000001 << 5)           /*!< R/W 0x0  SDM order   1: 3th order  0: 2nd order*/
#define BIT_MASK_S_1_0     ((u32)0x00000003 << 3)           /*!< R/W 0x0  Driving control buffer  11:larger current*/
#define BIT_S_1_0(x)       (((u32)((x) & 0x00000003) << 3))
#define BIT_GET_S_1_0(x)   ((u32)(((x >> 3) & 0x00000003)))
#define BIT_GPO            ((u32)0x00000001 << 2)           /*!< R/W 0x0  */
#define BIT_GPE            ((u32)0x00000001 << 1)           /*!< R/W 0x0  gpe=1 and gpo=1=>output gpe=1 and gpo=0=>input*/
#define BIT_REG_CP_IDOUBLE ((u32)0x00000001 << 0)           /*!< R/W 0x0  1 for cp currnet double*/
/** @} */

/** @defgroup REG_FSIMR_V1
  * @brief
  * @{
  */
#define BIT_FS_PWMERR_INT_EN_V1 ((u32)0x00000001 << 1) /*!< R/W 0x0  Enable MCU Access Error interrupt source*/
/** @} */

/** @defgroup REG_FSISR_V1
  * @brief
  * @{
  */
#define BIT_FS_PWMERR_INT_V1 ((u32)0x00000001 << 1) /*!< R/W1C 0x0  MCU Access Error interrupt source Write 1 clear*/
/** @} */

/** @defgroup REG_FW_DBG0_V1
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  fw debug0*/
#define BIT_FW_DBG0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG1_V1
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  fw debug1*/
#define BIT_FW_DBG1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG2_V1
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  fw debug2*/
#define BIT_FW_DBG2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG3_V1
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  fw debug3*/
#define BIT_FW_DBG3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG4_V1
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG4   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  fw debug4*/
#define BIT_FW_DBG4(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG4(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG5_V1
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG5   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  fw debug5*/
#define BIT_FW_DBG5(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG5(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG6_V1
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG6   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  fw debug6*/
#define BIT_FW_DBG6(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG6(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_FW_DBG7_V1
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG7   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  fw debug7*/
#define BIT_FW_DBG7(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG7(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_WL_PIN_FUNC_CTRL0
  * @brief
  * @{
  */
#define BIT_MASK_WL_DBG_SEL   ((u32)0x000000FF << 24)           /*!< R/W 0x0  WL debug select*/
#define BIT_WL_DBG_SEL(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_WL_DBG_SEL(x) ((u32)(((x >> 24) & 0x000000FF)))
/** @} */

/** @defgroup REG_WL_PIN_FUNC_CTRL1
  * @brief
  * @{
  */
#define BIT_MASK_BTMODE_V1   ((u32)0x00000003 << 17)           /*!< R/W 0x0  Bluetooth Mode*/
#define BIT_BTMODE_V1(x)     (((u32)((x) & 0x00000003) << 17))
#define BIT_GET_BTMODE_V1(x) ((u32)(((x >> 17) & 0x00000003)))
#define BIT_ENBT_V1          ((u32)0x00000001 << 16)           /*!< R/W 0x0  Enable PTA ( from BT side)*/
/** @} */

/** @defgroup REG_DBG_PORT_REG
  * @brief
  * @{
  */
#define BIT_MASK_DEBUG_ST   ((u32)0xFFFFFFFF << 0)           /*!< RO 0x0  Debug signals, sel by 70[31:24]*/
#define BIT_DEBUG_ST(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_DEBUG_ST(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_WL_MCUFW_CTRL
  * @brief
  * @{
  */
#define BIT_FW_INIT_RDY ((u32)0x00000001 << 15) /*!< R/W 0x0  CPU fw initialize ready, set by CPU*/
/** @} */

/** @defgroup REG_FW_DBG8
  * @brief
  * @{
  */
#define BIT_MASK_FW_DBG8   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  fw debug8*/
#define BIT_FW_DBG8(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_FW_DBG8(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HOST_MSG0
  * @brief
  * @{
  */
#define BIT_MASK_HOST_MSG_E1   ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  User Defined Message*/
#define BIT_HOST_MSG_E1(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_HOST_MSG_E1(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_HOST_MSG_E0   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  User Defined Message*/
#define BIT_HOST_MSG_E0(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_HOST_MSG_E0(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_HOST_MSG1
  * @brief
  * @{
  */
#define BIT_MASK_HOST_MSG_E3   ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  User Defined Message*/
#define BIT_HOST_MSG_E3(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_HOST_MSG_E3(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_HOST_MSG_E2   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  User Defined Message*/
#define BIT_HOST_MSG_E2(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_HOST_MSG_E2(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_LPS_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_LPS_MEMPM_MACOFF   ((u32)0x00000003 << 26)           /*!< R/W 0x0  MAC OFF memory power mode when enable LPS memory power mode 00 : normal 01 : LS 10 : DS 11 : SD*/
#define BIT_LPS_MEMPM_MACOFF(x)     (((u32)((x) & 0x00000003) << 26))
#define BIT_GET_LPS_MEMPM_MACOFF(x) ((u32)(((x >> 26) & 0x00000003)))
#define BIT_MASK_LPS_MEMPM_MACON    ((u32)0x00000003 << 24)           /*!< R/W 0x0  MAC ON memory power mode when enable LPS memory power mode 00 : normal 01 : LS 10 : DS 11 : SD*/
#define BIT_LPS_MEMPM_MACON(x)      (((u32)((x) & 0x00000003) << 24))
#define BIT_GET_LPS_MEMPM_MACON(x)  ((u32)(((x >> 24) & 0x00000003)))
#define BIT_WL_LPS_OPT_SWR_0P9      ((u32)0x00000001 << 13)           /*!< R/W 0x0  LPS option to set SWR voltage 0.9V 1: set SWR voltage 0.9V 0: set SWR voltage 1.1V*/
#define BIT_WL_LPS_OPT_LP_XTAL      ((u32)0x00000001 << 12)           /*!< R/W 0x0  LPS option to set XTAL low power mode when enable XTAL 1: set XTAL low power mode 0: set XTAL active mode*/
#define BIT_WL_LPS_OPT_DIS_XTAL     ((u32)0x00000001 << 11)           /*!< R/W 0x0  LPS option to disable XTAL 1: disable XTAL 0: enable XTAL*/
#define BIT_WL_LPS_OPT_EMACFUN      ((u32)0x00000001 << 10)           /*!< R/W 0x0  LPS option to reset WL MAC OFF block when enable WL MAC OFF power 1: not reset WL MAC OFF block 0: reset WL MAC OFF block*/
#define BIT_WL_LPS_OPT_EPHYPWR      ((u32)0x00000001 << 9)            /*!< R/W 0x0  LPS option to enable WL BB block power 1: Enable WL BB block power  0: Disable WL BB block power*/
#define BIT_WL_LPS_OPT_EMACPWR      ((u32)0x00000001 << 8)            /*!< R/W 0x0  LPS option to enable WL MAC OFF block power 1: Enable WL MAC OFF block power  0: Disable WL MAC OFF block power*/
#define BIT_WL_LPS_MEMPM_EN         ((u32)0x00000001 << 1)            /*!< R/W 0x0  enable LPS memory power mode control*/
#define BIT_WL_NRM_MEMPM_SL         ((u32)0x00000001 << 0)            /*!< R/W 0x1  MAC memory power mode when BIT_WL_LPS_MEMPM_EN is 0, 0 : Normal 1 : SD*/
/** @} */

/** @defgroup REG_RPWM2
  * @brief
  * @{
  */
#define BIT_MASK_RPWM2     ((u32)0x0000FFFF << 16)           /*!< RO 0x0  Host Request Power State. This register is a direct bus signal from each HCI block HRPWM register. When bit 31 is toggled, RPWMINT is issued to MCU.*/
#define BIT_RPWM2(x)       (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_RPWM2(x)   ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_MASK_RPWM_V1   ((u32)0x000000FF << 0)            /*!< RO 0x0  Host Request Power State. This register is a direct bus signal from each HCI block HRPWM register. When bit 7 is toggled, RPWMINT is issued to MCU.*/
#define BIT_RPWM_V1(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_RPWM_V1(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_SYSON_FSM_MON_V1
  * @brief
  * @{
  */
#define BIT_MASK_WLPMC_DEBUG_SEL   ((u32)0x0000000F << 24)           /*!< R/W 0x0  debug select signal for WL PMC*/
#define BIT_WLPMC_DEBUG_SEL(x)     (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_WLPMC_DEBUG_SEL(x) ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_WLPMC_DEBUG       ((u32)0x0000FFFF << 0)            /*!< RO 0x0  debug signal of WL PMC*/
#define BIT_WLPMC_DEBUG(x)         (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_WLPMC_DEBUG(x)     ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_SCOREBOARD_RD_BT2WL
  * @brief
  * @{
  */
#define BIT_BT_INT_EN                    ((u32)0x00000001 << 31)           /*!< R/W 0x0  For WL, write 1 to issue interrupt  1 : Issue one INT to BT 0 : Don't care*/
#define BIT_MASK_RD_WR_WIFI_BT_INFO_V1   ((u32)0x0000007F << 24)           /*!< R/W 0x0  Read Data : From BTON Status Report INFO  Write Data : To BT INFO, WLON Status Report*/
#define BIT_RD_WR_WIFI_BT_INFO_V1(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_RD_WR_WIFI_BT_INFO_V1(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_BT2WL_STS_IMR                ((u32)0x00000001 << 16)           /*!< R/W 0x0  BT2WL_STS[7] toggle interrupt mask*/
#define BIT_BT2WL_STS_ISR                ((u32)0x00000001 << 15)           /*!< R/W1C 0x0  BT2WL_STS[7] toggle interrupt status*/
#define BIT_PMC_WR_OVF                   ((u32)0x00000001 << 8)            /*!< R/W1C 0x0  PMC Write Access Timer Overflow*/
#define BIT_MASK_WLPMC_ERRINT            ((u32)0x000000FF << 0)            /*!< R/W1C 0x0  WLPMC Error interrupt*/
#define BIT_WLPMC_ERRINT(x)              (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_WLPMC_ERRINT(x)          ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_PMC_DBG_CTRL2_V1
  * @brief
  * @{
  */
#define BIT_MASK_SYSON_REG_ARB   ((u32)0x00000003 << 0)           /*!< R/W 0x0  HW PMC Access Register Time Out Control*/
#define BIT_SYSON_REG_ARB(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_SYSON_REG_ARB(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_HIMR0
  * @brief
  * @{
  */
#define BIT_RXDES_UNAVAIL_MSK       ((u32)0x00000001 << 30) /*!< R/W 0x0  Rx Descriptor Unavailable interrupt mask*/
#define BIT_WLMCU_ERR_MSK           ((u32)0x00000001 << 29) /*!< R/W 0x0  dw8051 error interrupt mask*/
#define BIT_EVTQ_DONE_MSK           ((u32)0x00000001 << 28) /*!< R/W 0x0  event queue done interrupt mask for NAN*/
#define BIT_EVTQ_START_MSK          ((u32)0x00000001 << 27) /*!< R/W 0x0  event queue start interrupt mask for NAN*/
#define BIT_FWMSG_MSK               ((u32)0x00000001 << 26) /*!< R/W 0x0  FW message interrupt mask*/
#define BIT_HCPWM2_MSK              ((u32)0x00000001 << 25) /*!< R/W 0x0  CPWM2 interrupt mask*/
#define BIT_HCPWM_MSK               ((u32)0x00000001 << 24) /*!< R/W 0x0  CPWM interrupt mask*/
#define BIT_RXFF_FULL_MSK           ((u32)0x00000001 << 23) /*!< R/W 0x0  Rxpktbuffer full interrupt mask*/
#define BIT_RDE_ERR_MSK             ((u32)0x00000001 << 22) /*!< R/W 0x0  Rxdma error interrupt mask*/
#define BIT_TDE_ERR_MSK             ((u32)0x00000001 << 21) /*!< R/W 0x0  Txdma error interrupt mask*/
#define BIT_TXBCN0_ERR_MSK          ((u32)0x00000001 << 20) /*!< R/W 0x0  port0 TX beacon error interrupt mask*/
#define BIT_TXBCN0_OK_MSK           ((u32)0x00000001 << 19) /*!< R/W 0x0  port0 TX beacon ok interrupt mask*/
#define BIT_TXFF_FIFO_MSK           ((u32)0x00000001 << 18) /*!< R/W 0x0  txpktbuffer full interrupt mask*/
#define BIT_TSF_BIT32_TOGGLE_MSK_V2 ((u32)0x00000001 << 17) /*!< R/W 0x0  Enable TSF_BIT32_TOGGLE interrupt source*/
#define BIT_TIMEOUT2_MSK            ((u32)0x00000001 << 16) /*!< R/W 0x0  Enable Timer2 interrupt source*/
#define BIT_TIMEOUT1_MSK_V1         ((u32)0x00000001 << 15) /*!< R/W 0x0  Enable Timer1 interrupt source*/
#define BIT_TIMEOUT0_MSK_V1         ((u32)0x00000001 << 14) /*!< R/W 0x0  Enable Timer0 interrupt source*/
#define BIT_CTWEND_MSK_V1           ((u32)0x00000001 << 13) /*!< R/W 0x0  Client traffic window end interrupt mask for P2P*/
#define BIT_DWWIN_END_MSK           ((u32)0x00000001 << 12) /*!< R/W 0x0  discovery window end interrupt mask for NAN*/
#define BIT_ATIMEND1_MSK_V1         ((u32)0x00000001 << 11) /*!< R/W 0x0  port1  atimend interrupt mask*/
#define BIT_ATIMEND0_MSK            ((u32)0x00000001 << 10) /*!< R/W 0x0  port0  atimend interrupt mask*/
#define BIT_BCNERLY9_MSK            ((u32)0x00000001 << 9)  /*!< R/W 0x0  port2 beacon early interrupt mask*/
#define BIT_BCNERLY8_MSK            ((u32)0x00000001 << 8)  /*!< R/W 0x0  port1 beacon early interrupt mask*/
#define BIT_BCNERLY7_MSK            ((u32)0x00000001 << 7)  /*!< R/W 0x0  port0 BSSID7 beacon early interrupt mask,  only valid under MBSSID mode*/
#define BIT_BCNERLY6_MSK            ((u32)0x00000001 << 6)  /*!< R/W 0x0  port0 BSSID6 beacon early interrupt mask,  only valid under MBSSID mode*/
#define BIT_BCNERLY5_MSK            ((u32)0x00000001 << 5)  /*!< R/W 0x0  port0 BSSID5 beacon early interrupt mask,  only valid under MBSSID mode*/
#define BIT_BCNERLY4_MSK            ((u32)0x00000001 << 4)  /*!< R/W 0x0  port0 BSSID4 beacon early interrupt mask,  only valid under MBSSID mode*/
#define BIT_BCNERLY3_MSK            ((u32)0x00000001 << 3)  /*!< R/W 0x0  port0 BSSID3 beacon early interrupt mask,  only valid under MBSSID mode*/
#define BIT_BCNERLY2_MSK            ((u32)0x00000001 << 2)  /*!< R/W 0x0  port0 BSSID2 beacon early interrupt mask,  only valid under MBSSID mode*/
#define BIT_BCNERLY1_MSK            ((u32)0x00000001 << 1)  /*!< R/W 0x0  port0 BSSID1 beacon early interrupt mask,  only valid under MBSSID mode*/
#define BIT_BCNERLY0_MSK            ((u32)0x00000001 << 0)  /*!< R/W 0x0  port 0 root BSSID beacon early interrupt mask*/
/** @} */

/** @defgroup REG_HISR0
  * @brief
  * @{
  */
#define BIT_RXDES_UNAVAIL_INT    ((u32)0x00000001 << 30) /*!< R/W1C 0x0  Rx Descriptor Unavailable*/
#define BIT_WLMCU_ERR_INT        ((u32)0x00000001 << 29) /*!< R/W1C 0x0  dw8051 error interrupt*/
#define BIT_EVTQ_DONE_INT        ((u32)0x00000001 << 28) /*!< R/W1C 0x0  event queue done interrupt for NAN*/
#define BIT_EVTQ_START_INT_V1    ((u32)0x00000001 << 27) /*!< R/W1C 0x0  event queue start interrupt for NAN*/
#define BIT_FWMSG_INT            ((u32)0x00000001 << 26) /*!< R/W1C 0x0  FW message interrupt*/
#define BIT_HCPWM2_INT           ((u32)0x00000001 << 25) /*!< R/W1C 0x0  CPWM2 interrupt*/
#define BIT_HCPWM_INT            ((u32)0x00000001 << 24) /*!< R/W1C 0x0  CPWM interrupt*/
#define BIT_RXFF_FULL_INT        ((u32)0x00000001 << 23) /*!< R/W1C 0x0  Rxpktbuffer full interrupt*/
#define BIT_RDE_ERR_INT          ((u32)0x00000001 << 22) /*!< R/W1C 0x0  Rxdma error interrupt*/
#define BIT_TDE_ERR_INT          ((u32)0x00000001 << 21) /*!< R/W1C 0x0  Txdma error interrupt*/
#define BIT_TXBCN0_ERR_INT       ((u32)0x00000001 << 20) /*!< R/W1C 0x0  port0 TX beacon error interrupt*/
#define BIT_TXBCN0_OK_INT        ((u32)0x00000001 << 19) /*!< R/W1C 0x0  port0 TX beacon ok interrupt*/
#define BIT_TXFF_FIFO_INT        ((u32)0x00000001 << 18) /*!< R/W1C 0x0  txpktbuffer full interrupt*/
#define BIT_TSF_BIT32_TOGGLE_INT ((u32)0x00000001 << 17) /*!< R/W1C 0x0  TSF_BIT32_TOGGLE interrupt*/
#define BIT_TIMEOUT2_INT         ((u32)0x00000001 << 16) /*!< R/W1C 0x0  Timer2 interrupt*/
#define BIT_TIMEOUT1_INT_V1      ((u32)0x00000001 << 15) /*!< R/W1C 0x0  Timer1 interrupt*/
#define BIT_TIMEOUT0_INT_V1      ((u32)0x00000001 << 14) /*!< R/W1C 0x0  Timer0 interrupt*/
#define BIT_CTWEND_INT           ((u32)0x00000001 << 13) /*!< R/W1C 0x0  Client traffic window end interrupt  for P2P*/
#define BIT_DWWIN_END_INT_V1     ((u32)0x00000001 << 12) /*!< R/W1C 0x0  discovery window end interrupt for NAN*/
#define BIT_ATIMEND1_INT         ((u32)0x00000001 << 11) /*!< R/W1C 0x0  port1 atimend interrupt*/
#define BIT_ATIMEND0_INT         ((u32)0x00000001 << 10) /*!< R/W1C 0x0  port0 atimend interrupt*/
#define BIT_BCNERLY9_INT         ((u32)0x00000001 << 9)  /*!< R/W1C 0x0  port2 beacon early interrupt*/
#define BIT_BCNERLY8_INT         ((u32)0x00000001 << 8)  /*!< R/W1C 0x0  port1 beacon early interrupt*/
#define BIT_BCNERLY7_INT         ((u32)0x00000001 << 7)  /*!< R/W1C 0x0  port0 BSSID7 beacon early interrupt ,  only valid under MBSSID mode*/
#define BIT_BCNERLY6_INT         ((u32)0x00000001 << 6)  /*!< R/W1C 0x0  port0 BSSID6 beacon early interrupt ,  only valid under MBSSID mode*/
#define BIT_BCNERLY5_INT         ((u32)0x00000001 << 5)  /*!< R/W1C 0x0  port0 BSSID5 beacon early interrupt ,  only valid under MBSSID mode*/
#define BIT_BCNERLY4_INT         ((u32)0x00000001 << 4)  /*!< R/W1C 0x0  port0 BSSID4 beacon early interrupt,  only valid under MBSSID mode*/
#define BIT_BCNERLY3_INT         ((u32)0x00000001 << 3)  /*!< R/W1C 0x0  port0 BSSID3 beacon early interrupt ,  only valid under MBSSID mode*/
#define BIT_BCNERLY2_INT         ((u32)0x00000001 << 2)  /*!< R/W1C 0x0  port0 BSSID2 beacon early interrupt,  only valid under MBSSID mode*/
#define BIT_BCNERLY1_INT         ((u32)0x00000001 << 1)  /*!< R/W1C 0x0  port0 BSSID1 beacon early interrupt ,  only valid under MBSSID mode*/
#define BIT_BCNERLY0_INT         ((u32)0x00000001 << 0)  /*!< R/W1C 0x0  This interrupt is issued at the time set by DRVERLYINT register before TBTT time  for port 0 root bssid*/
/** @} */

/** @defgroup REG_SDM_IDR_CTRL0
  * @brief
  * @{
  */
#define BIT_MASK_SDM_ADDR   ((u32)0x0000003F << 0)           /*!< R/W 0x0  SDM register offset*/
#define BIT_SDM_ADDR(x)     (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_SDM_ADDR(x) ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_SDM_IDR_CTRL1
  * @brief
  * @{
  */
#define BIT_MASK_SDM_DATA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  SDM register data, support byte write*/
#define BIT_SDM_DATA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_SDM_DATA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_SYS_CONFIG0
  * @brief
  * @{
  */
#define BIT_IS_SCH_CLK_INSLP_V1 ((u32)0x00000001 << 8)           /*!< RO   WL TSF clock status: 0: MAC clock 1: 32K clock*/
#define BIT_MASK_VENDOR_ID_V1   ((u32)0x0000000F << 4)           /*!< RO 4'b1000  Vendor ID [7:6] : Download FW version ;  00: TSMC , 01: SMIC, 10: UMC [5] ; 0 : Download FW , init BB and RF registers          1 : Do not download FW and do not init BB and RF registers [4] ; 0 : BT do not exist in IC          1 : BT exist in IC*/
#define BIT_VENDOR_ID_V1(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_VENDOR_ID_V1(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_PLL_CK_RDY          ((u32)0x00000001 << 0)           /*!< RO   indicate AFE PLL clock is ready*/
/** @} */

/*==========REG_PAGE0 Register Address Definition==========*/
#define REG_SYS_PWC_CTRL                 0x000
#define REG_WL_CLK_CTRL                  0x002
#define REG_WL_FUNC_EN                   0x004
#define REG_CLKDIV                       0x008
#define REG_RSV_CTRL                     0x01C
#define REG_WL_PMC_CTRL                  0x020
#define REG_WL_SYSCONFIG                 0x024
#define REG_AFC_CTRL0                    0x030
#define REG_AFE_CTRL1_V1                 0x034
#define REG_AFE_CTRL2_V1                 0x038
#define REG_AFE_CTRL3_V1                 0x03C
#define REG_FSIMR_V1                     0x040
#define REG_FSISR_V1                     0x044
#define REG_FW_DBG0_V1                   0x050
#define REG_FW_DBG1_V1                   0x054
#define REG_FW_DBG2_V1                   0x058
#define REG_FW_DBG3_V1                   0x05C
#define REG_FW_DBG4_V1                   0x060
#define REG_FW_DBG5_V1                   0x064
#define REG_FW_DBG6_V1                   0x068
#define REG_FW_DBG7_V1                   0x06C
#define REG_WL_PIN_FUNC_CTRL0            0x070
#define REG_WL_PIN_FUNC_CTRL1            0x074
#define REG_DBG_PORT_REG                 0x07C
#define REG_WL_MCUFW_CTRL                0x080
#define REG_FW_DBG8                      0x084
#define REG_HOST_MSG0                    0x088
#define REG_HOST_MSG1                    0x08C
#define REG_LPS_CTRL                     0x090
#define REG_RPWM2                        0x09C
#define REG_SYSON_FSM_MON_V1             0x0A4
#define REG_SCOREBOARD_RD_BT2WL          0x0A8
#define REG_PMC_DBG_CTRL2_V1             0x0AC
#define REG_HIMR0                        0x0B0
#define REG_HISR0                        0x0B4
#define REG_SDM_IDR_CTRL0                0x0E8
#define REG_SDM_IDR_CTRL1                0x0EC
#define REG_SYS_CONFIG0                  0x0F0

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