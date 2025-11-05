#ifndef _RL6955_REG_TXPWR_H_
#define _RL6955_REG_TXPWR_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_TXPWR
  * @brief REG_TXPWR driver modules
  * @{
  */




/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_TXPWR_Register_Definitions REG_TXPWR Register Definitions
  * @{
  */

/** @defgroup REG_AX_PWR_RATE_CTRL
  * @brief
  * @{
  */
#define BIT_TXPWCTRL_CLR                   ((u32)0x00000001 << 31)           /*!< R/W 0x0  (RTL_only)  1: clr txpwr, sync rst*/
#define BIT_MASK_FORCE_MODE_IDX            ((u32)0x00000007 << 28)           /*!< R/W 0x0  Force txpwbb from specific source 0:FOCRE_NONE (normal) 1:FORCE_PWR_BY_RATE 2:FORCE_MACID 3:FORCE_PWR_LIM 4:FORCE_PWR_RU_LIM 5:FORCE_COEXIST*/
#define BIT_FORCE_MODE_IDX(x)              (((u32)((x) & 0x00000007) << 28))
#define BIT_GET_FORCE_MODE_IDX(x)          ((u32)(((x >> 28) & 0x00000007)))
#define BIT_MASK_TXAGC_OFDM_REF            ((u32)0x000001FF << 19)           /*!< R/W 40h  S(9.2) ofdm ref dbm*/
#define BIT_TXAGC_OFDM_REF(x)              (((u32)((x) & 0x000001FF) << 19))
#define BIT_GET_TXAGC_OFDM_REF(x)          ((u32)(((x >> 19) & 0x000001FF)))
#define BIT_MASK_TXAGC_CCK_REF             ((u32)0x000001FF << 10)           /*!< R/W 40h  S(9.2) cck ref dbm*/
#define BIT_TXAGC_CCK_REF(x)               (((u32)((x) & 0x000001FF) << 10))
#define BIT_GET_TXAGC_CCK_REF(x)           ((u32)(((x >> 10) & 0x000001FF)))
#define BIT_FORCE_PWR_BY_RATE_EN           ((u32)0x00000001 << 9)            /*!< R/W 0x0  force pwr by rate value_en*/
#define BIT_MASK_FORCE_PWR_BY_RATE_VALUE   ((u32)0x000001FF << 0)            /*!< R/W 0x0  S(9.2) force pwr by rate value (txagc_ref+pwby_rate_tbl)*/
#define BIT_FORCE_PWR_BY_RATE_VALUE(x)     (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_FORCE_PWR_BY_RATE_VALUE(x) ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_AX_PWR_RATE_OFST_CTRL
  * @brief
  * @{
  */
#define BIT_TXAGC_TBL_RD                  ((u32)0x00000001 << 26)           /*!< R/W 0x0  (RTL_only)  1:indirecr read enable*/
#define BIT_MASK_TXAGC_TBL_RA             ((u32)0x0000003F << 20)           /*!< R/W 0x0  (RTL_only)  indirect read of addr of pwby_rate*/
#define BIT_TXAGC_TBL_RA(x)               (((u32)((x) & 0x0000003F) << 20))
#define BIT_GET_TXAGC_TBL_RA(x)           ((u32)(((x >> 20) & 0x0000003F)))
#define BIT_MASK_TXAGC_CCK_HT_OFFSET      ((u32)0x0000000F << 16)           /*!< R/W 0x0  S(4.1)CCK-HT pwr offset*/
#define BIT_TXAGC_CCK_HT_OFFSET(x)        (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_TXAGC_CCK_HT_OFFSET(x)    ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_TXAGC_LEGACY_HT_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  S(4.1)LEG-HT pwr offset*/
#define BIT_TXAGC_LEGACY_HT_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_TXAGC_LEGACY_HT_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_TXAGC_HT_HT_OFFSET       ((u32)0x0000000F << 8)            /*!< R/W 0x0  (RTL_only)  S(4.1) HT-HT pwr bias = 0*/
#define BIT_TXAGC_HT_HT_OFFSET(x)         (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_TXAGC_HT_HT_OFFSET(x)     ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_TXAGC_VHT_HT_OFFSET      ((u32)0x0000000F << 4)            /*!< R/W 0x0  S(4.1)VHT-HT pwr offset*/
#define BIT_TXAGC_VHT_HT_OFFSET(x)        (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_TXAGC_VHT_HT_OFFSET(x)    ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_TXAGC_HE_HT_OFFSET       ((u32)0x0000000F << 0)            /*!< R/W 0x0  S(4.1)HE-HT pwr offset*/
#define BIT_TXAGC_HE_HT_OFFSET(x)         (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_TXAGC_HE_HT_OFFSET(x)     ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_CTRL
  * @brief
  * @{
  */
#define BIT_FORCE_TF_DCM_EN                  ((u32)0x00000001 << 26)           /*!< R/W 0x0  (RTL_only)  1:Force input TF dcm  =  R_force_TF_dcm_value*/
#define BIT_FORCE_TF_DCM_VALUE               ((u32)0x00000001 << 25)           /*!< R/W 0x0  (RTL_only)  Force input TF dcm value*/
#define BIT_FORCE_NORM_RSP_HE_TB_EN_ON       ((u32)0x00000001 << 24)           /*!< R/W 0x0  (RTL_only)  1:Norm resp always  In HE_TB*/
#define BIT_FORCE_PWR_BY_LIMIT_EN            ((u32)0x00000001 << 23)           /*!< R/W 0x0  (RTL_only)  1: Force pwlim_BF0=  force_pwby_limit_bfoff_value (0xd210[17:9])*/
#define BIT_FORCE_PWBY_LIMIT_BF1_EN          ((u32)0x00000001 << 22)           /*!< R/W 0x0  (RTL_only)  1: Force pwlim_BF1=  force_pwby_limit_bfon_value (0xd210[8:0])*/
#define BIT_TXAGC_PWLIM_BF0_EN               ((u32)0x00000001 << 21)           /*!< R/W 1h  (RTL_only)  None BF pwr limit enable*/
#define BIT_TXAGC_PWLIM_BF1_EN               ((u32)0x00000001 << 20)           /*!< R/W 1h  (RTL_only)   BF pwr limit enable*/
#define BIT_MASK_TXAGC_BW20_BW40_OFFSET      ((u32)0x0000000F << 16)           /*!< R/W 0x0  S(4.1)BW20  - BW40 pwr offset*/
#define BIT_TXAGC_BW20_BW40_OFFSET(x)        (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_TXAGC_BW20_BW40_OFFSET(x)    ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_TXAGC_BW40_BW40_OFFSET      ((u32)0x0000000F << 12)           /*!< R/W 0x0  (RTL_only)  S(4.1)BW40  - BW40 pwr offset*/
#define BIT_TXAGC_BW40_BW40_OFFSET(x)        (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_TXAGC_BW40_BW40_OFFSET(x)    ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_TXAGC_BW80_BW40_OFFSET      ((u32)0x0000000F << 8)            /*!< R/W 0x0  S(4.1)BW80  - BW40 pwr offset*/
#define BIT_TXAGC_BW80_BW40_OFFSET(x)        (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_TXAGC_BW80_BW40_OFFSET(x)    ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_TXAGC_BW160_BW40_OFFSET     ((u32)0x0000000F << 4)            /*!< R/W 0x0  S(4.1)BW160  - BW40 pwr offset*/
#define BIT_TXAGC_BW160_BW40_OFFSET(x)       (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_TXAGC_BW160_BW40_OFFSET(x)   ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_TXAGC_BW80_80_BW40_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  S(4.1) BW80+80  - BW40 pwr offset*/
#define BIT_TXAGC_BW80_80_BW40_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_TXAGC_BW80_80_BW40_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_CTRL
  * @brief
  * @{
  */
#define BIT_TXAGC_PWBY_MACID_EN             ((u32)0x00000001 << 29)           /*!< R/W 1h  (RTL_only)  1:enable pwby_macid*/
#define BIT_FORCE_CCA_PWR_TH_VALUE_EN       ((u32)0x00000001 << 28)           /*!< R/W 0x0  1:Force CCA_PWR_TH value_en*/
#define BIT_MASK_FORCE_CCA_PWR_TH_VALUE     ((u32)0x000000FF << 20)           /*!< R/W 0x0  S(8.1)Force CCA_PWR_TH value*/
#define BIT_FORCE_CCA_PWR_TH_VALUE(x)       (((u32)((x) & 0x000000FF) << 20))
#define BIT_GET_FORCE_CCA_PWR_TH_VALUE(x)   ((u32)(((x >> 20) & 0x000000FF)))
#define BIT_FORCE_CCA_PWR_TH_EN             ((u32)0x00000001 << 17)           /*!< R/W 0x0  (RTL_only)  1:Force output  CCA_PWR_TH_en*/
#define BIT_FORCE_PWR_BY_MACID_EN           ((u32)0x00000001 << 16)           /*!< R/W 0x0  1:Force output  Pwby_macid_en*/
#define BIT_MASK_FORCE_PWR_BY_MACID_VALUE   ((u32)0x000000FF << 8)            /*!< R/W 0x0  S(8.1)Force Pwby_macid_value*/
#define BIT_FORCE_PWR_BY_MACID_VALUE(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_FORCE_PWR_BY_MACID_VALUE(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_FORCE_PWR_BY_MACID_VALUE_EN     ((u32)0x00000001 << 7)            /*!< R/W 1h  (RTL_only)  1:Force output  Pwby_macid_value*/
#define BIT_TXPWLIM_TBL_RD                  ((u32)0x00000001 << 6)            /*!< R/W 0x0  (RTL_only)  1: pwr lim tbl indirect read en*/
#define BIT_MASK_TXPWLIM_TBL_RA             ((u32)0x0000003F << 0)            /*!< R/W 0x0  (RTL_only)  pwr lim tbl indirect read addr*/
#define BIT_TXPWLIM_TBL_RA(x)               (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_TXPWLIM_TBL_RA(x)           ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_AX_PWR_BF_CTRL
  * @brief
  * @{
  */
#define BIT_TXAGC_BF_PWBOOST_EN                   ((u32)0x00000001 << 31)           /*!< R/W 1h  1:TxBF will cal pwr boost to BB 0:TxBF pwboost =0 & Pwlim use BF1_pwlim*/
#define BIT_MASK_HE_ER_SU_PWR_REDUCE_VAL          ((u32)0x0000003F << 19)           /*!< R/W Ch  (RTL_only) S(6.2) 3dB=0xC*/
#define BIT_HE_ER_SU_PWR_REDUCE_VAL(x)            (((u32)((x) & 0x0000003F) << 19))
#define BIT_GET_HE_ER_SU_PWR_REDUCE_VAL(x)        ((u32)(((x >> 19) & 0x0000003F)))
#define BIT_HE_ER_SU_PWR_REDUCE_EN                ((u32)0x00000001 << 18)           /*!< R/W 0x0  1:HE_ER_SU pwr lim output will minus 3dB*/
#define BIT_MASK_FORCE_PWR_BY_LIMIT_BFOFF_VALUE   ((u32)0x000001FF << 9)            /*!< R/W 0x0  S(9.2) force_pwby_limit_BF0_en=1 is valid*/
#define BIT_FORCE_PWR_BY_LIMIT_BFOFF_VALUE(x)     (((u32)((x) & 0x000001FF) << 9))
#define BIT_GET_FORCE_PWR_BY_LIMIT_BFOFF_VALUE(x) ((u32)(((x >> 9) & 0x000001FF)))
#define BIT_MASK_FORCE_PWBY_LIMIT_BFON_VALUE      ((u32)0x000001FF << 0)            /*!< R/W 0x0  S(9.2) force_pwby_limit_BF1_en=1 is valid*/
#define BIT_FORCE_PWBY_LIMIT_BFON_VALUE(x)        (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_FORCE_PWBY_LIMIT_BFON_VALUE(x)    ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_REG
  * @brief
  * @{
  */
#define BIT_MASK_TXPWR_REG3   ((u32)0x000000FF << 24)           /*!< R/W 0x0  S(8.1)pwr by macid  when  Pwmode=5 from MAC*/
#define BIT_TXPWR_REG3(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_TXPWR_REG3(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_TXPWR_REG2   ((u32)0x000000FF << 16)           /*!< R/W 0x0  S(8.1)pwr by macid  when  Pwmode=4 from MAC*/
#define BIT_TXPWR_REG2(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_TXPWR_REG2(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_TXPWR_REG1   ((u32)0x000000FF << 8)            /*!< R/W 0x0  S(8.1)pwr by macid  when  Pwmode=3 from MAC*/
#define BIT_TXPWR_REG1(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_TXPWR_REG1(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_TXPWR_REG0   ((u32)0x000000FF << 0)            /*!< R/W 0x0  S(8.1)pwr by macid  when  Pwmode=2 from MAC*/
#define BIT_TXPWR_REG0(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_TXPWR_REG0(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_REG2
  * @brief
  * @{
  */
#define BIT_TXPWBY_MACID_TBL_RD        ((u32)0x00000001 << 31)           /*!< R/W 0x0  (RTL_only)  1:Pwby_macid indirect read*/
#define BIT_MASK_TXPWBY_MACID_TBL_RA   ((u32)0x0000007F << 24)           /*!< R/W 0x0  (RTL_only)  Pwby_macid indirect read addr*/
#define BIT_TXPWBY_MACID_TBL_RA(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXPWBY_MACID_TBL_RA(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_TXPWR_REG5_EN              ((u32)0x00000001 << 21)           /*!< R/W 0x0  pwr by macid en  when  Pwmode=7 from MAC*/
#define BIT_TXPWR_REG4_EN              ((u32)0x00000001 << 20)           /*!< R/W 0x0  pwr by macid en  when  Pwmode=6 from MAC*/
#define BIT_TXPWR_REG3_EN              ((u32)0x00000001 << 19)           /*!< R/W 0x0  pwr by macid en  when  Pwmode=5 from MAC*/
#define BIT_TXPWR_REG2_EN              ((u32)0x00000001 << 18)           /*!< R/W 0x0  pwr by macid en   when pwmode=4 from MAC*/
#define BIT_TXPWR_REG1_EN              ((u32)0x00000001 << 17)           /*!< R/W 0x0  pwr by macid en  when  Pwmode=3 from MAC*/
#define BIT_TXPWR_REG0_EN              ((u32)0x00000001 << 16)           /*!< R/W 0x0  pwr by macid en  when  Pwmode=2 from MAC*/
#define BIT_MASK_TXPWR_REG5            ((u32)0x000000FF << 8)            /*!< R/W 0x0  S(8.1)pwr by macid  when  Pwmode=7 from MAC*/
#define BIT_TXPWR_REG5(x)              (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_TXPWR_REG5(x)          ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_TXPWR_REG4            ((u32)0x000000FF << 0)            /*!< R/W 0x0  S(8.1)pwr by macid  when  Pwmode=6 from MAC*/
#define BIT_TXPWR_REG4(x)              (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_TXPWR_REG4(x)          ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_RU_LMT_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_LTE                     ((u32)0x000001FF << 19)           /*!< R/W 4h  S(9.2) Coexist LTE pwr dbm*/
#define BIT_TXAGC_LTE(x)                       (((u32)((x) & 0x000001FF) << 19))
#define BIT_GET_TXAGC_LTE(x)                   ((u32)(((x >> 19) & 0x000001FF)))
#define BIT_TXPWRU_LIM_EN                      ((u32)0x00000001 << 18)           /*!< R/W 1h  (RTL_only)  1:Ru lim indirect read*/
#define BIT_TXPWRU_LIM_TBL_RD                  ((u32)0x00000001 << 17)           /*!< R/W 0x0  (RTL_only)  1:Ru lim indirect read*/
#define BIT_MASK_TXPWRU_LIM_TBL_RA             ((u32)0x0000003F << 11)           /*!< R/W 0x0  (RTL_only)  Ru lim indirect read addr*/
#define BIT_TXPWRU_LIM_TBL_RA(x)               (((u32)((x) & 0x0000003F) << 11))
#define BIT_GET_TXPWRU_LIM_TBL_RA(x)           ((u32)(((x >> 11) & 0x0000003F)))
#define BIT_FORCE_PWR_BY_RU_LIMIT_EN           ((u32)0x00000001 << 10)           /*!< R/W 0x0  1: RU_lim = force_pwby_ru_limit_value*/
#define BIT_FORCE_PWR_BY_RU_LIMIT_EN_VALUE     ((u32)0x00000001 << 9)            /*!< R/W 1h  (ru lim val is valid in HE_TB)*/
#define BIT_MASK_FORCE_PWR_BY_RU_LIMIT_VALUE   ((u32)0x000001FF << 0)            /*!< R/W 0x0  Force RU lim_val enable*/
#define BIT_FORCE_PWR_BY_RU_LIMIT_VALUE(x)     (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_FORCE_PWR_BY_RU_LIMIT_VALUE(x) ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_AX_PWR_COEXT_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_CCK_NORM_TERM     ((u32)0x0000007F << 18)           /*!< R/W 7Ah  (RTL_only) u(6.4) Map txpwbb to txpwmac   0x7A=20log(20/11)=2.625*/
#define BIT_CCK_NORM_TERM(x)       (((u32)((x) & 0x0000007F) << 18))
#define BIT_GET_CCK_NORM_TERM(x)   ((u32)(((x >> 18) & 0x0000007F)))
#define BIT_MASK_TXPWMAC_MAX_BND   ((u32)0x0000003F << 12)           /*!< R/W 3Fh  (RTL_only)  u(6.0) txpwr mac max bnd dB*/
#define BIT_TXPWMAC_MAX_BND(x)     (((u32)((x) & 0x0000003F) << 12))
#define BIT_GET_TXPWMAC_MAX_BND(x) ((u32)(((x >> 12) & 0x0000003F)))
#define BIT_MASK_TXAGC_BT          ((u32)0x000001FF << 3)            /*!< R/W 4h  S(9.2) Coexist BT pwr dbm*/
#define BIT_TXAGC_BT(x)            (((u32)((x) & 0x000001FF) << 3))
#define BIT_GET_TXAGC_BT(x)        ((u32)(((x >> 3) & 0x000001FF)))
#define BIT_TXAGC_LTE_EN           ((u32)0x00000001 << 2)            /*!< R/W 1h  Coexist LTE_en*/
#define BIT_TXAGC_BT_EN            ((u32)0x00000001 << 1)            /*!< R/W 1h  Coexist BT_en*/
/** @} */

/** @defgroup REG_AX_PWR_SWING_LEG_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_TXBIAS_LEGACY_BELOW_TH_VAL      ((u32)0x00000003 << 29)           /*!< R/W 0x0  Bbswing , txbias mcs below th sel this*/
#define BIT_TXBIAS_LEGACY_BELOW_TH_VAL(x)        (((u32)((x) & 0x00000003) << 29))
#define BIT_GET_TXBIAS_LEGACY_BELOW_TH_VAL(x)    ((u32)(((x >> 29) & 0x00000003)))
#define BIT_MASK_TXBIAS_LEGACY_OV_TH_VAL         ((u32)0x00000003 << 27)           /*!< R/W 0x0  Bbswing ,txbias  mcs ov th sel this*/
#define BIT_TXBIAS_LEGACY_OV_TH_VAL(x)           (((u32)((x) & 0x00000003) << 27))
#define BIT_GET_TXBIAS_LEGACY_OV_TH_VAL(x)       ((u32)(((x >> 27) & 0x00000003)))
#define BIT_MASK_TXBBSWING_LEGACY_BELOW_TH_VAL   ((u32)0x0000000F << 23)           /*!< R/W 0x0  Bbswing ,txbias  mcs below th sel this*/
#define BIT_TXBBSWING_LEGACY_BELOW_TH_VAL(x)     (((u32)((x) & 0x0000000F) << 23))
#define BIT_GET_TXBBSWING_LEGACY_BELOW_TH_VAL(x) ((u32)(((x >> 23) & 0x0000000F)))
#define BIT_MASK_TXBBSWING_LEGACY_OV_TH_VAL      ((u32)0x0000000F << 19)           /*!< R/W 0x0  Bbswing ,txbias  mcs ov th sel this*/
#define BIT_TXBBSWING_LEGACY_OV_TH_VAL(x)        (((u32)((x) & 0x0000000F) << 19))
#define BIT_GET_TXBBSWING_LEGACY_OV_TH_VAL(x)    ((u32)(((x >> 19) & 0x0000000F)))
#define BIT_MASK_TXBBSWING_TXBIAS_LEGACY_TH      ((u32)0x0000000F << 15)           /*!< R/W 0x0  0~4 Bbswing txbias mcs th*/
#define BIT_TXBBSWING_TXBIAS_LEGACY_TH(x)        (((u32)((x) & 0x0000000F) << 15))
#define BIT_GET_TXBBSWING_TXBIAS_LEGACY_TH(x)    ((u32)(((x >> 15) & 0x0000000F)))
#define BIT_MASK_TXBIAS_CCK_BELOW_TH_VAL         ((u32)0x00000003 << 13)           /*!< R/W 0x0  Bbswing ,txbias mcs below th sel this*/
#define BIT_TXBIAS_CCK_BELOW_TH_VAL(x)           (((u32)((x) & 0x00000003) << 13))
#define BIT_GET_TXBIAS_CCK_BELOW_TH_VAL(x)       ((u32)(((x >> 13) & 0x00000003)))
#define BIT_MASK_TXBIAS_CCK_OV_TH_VAL            ((u32)0x00000003 << 11)           /*!< R/W 0x0  Bbswing ,txbias  mcs ov th sel this*/
#define BIT_TXBIAS_CCK_OV_TH_VAL(x)              (((u32)((x) & 0x00000003) << 11))
#define BIT_GET_TXBIAS_CCK_OV_TH_VAL(x)          ((u32)(((x >> 11) & 0x00000003)))
#define BIT_MASK_TXBBSWING_CCK_BELOW_TH_VAL      ((u32)0x0000000F << 7)            /*!< R/W 0x0  Bbswing ,txbias  mcs below th sel this*/
#define BIT_TXBBSWING_CCK_BELOW_TH_VAL(x)        (((u32)((x) & 0x0000000F) << 7))
#define BIT_GET_TXBBSWING_CCK_BELOW_TH_VAL(x)    ((u32)(((x >> 7) & 0x0000000F)))
#define BIT_MASK_TXBBSWING_CCK_OV_TH_VAL         ((u32)0x0000000F << 3)            /*!< R/W 0x0  Bbswing ,txbias mcs ov th sel this*/
#define BIT_TXBBSWING_CCK_OV_TH_VAL(x)           (((u32)((x) & 0x0000000F) << 3))
#define BIT_GET_TXBBSWING_CCK_OV_TH_VAL(x)       ((u32)(((x >> 3) & 0x0000000F)))
#define BIT_MASK_TXBBSWING_TXBIAS_CCK_TH         ((u32)0x00000007 << 0)            /*!< R/W 0x0  0~4  Bbswing txbias mcs th*/
#define BIT_TXBBSWING_TXBIAS_CCK_TH(x)           (((u32)((x) & 0x00000007) << 0))
#define BIT_GET_TXBBSWING_TXBIAS_CCK_TH(x)       ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_AX_PWR_SWING_VHT_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_TXBIAS_VHT_OV_TH_VAL         ((u32)0x00000003 << 30)           /*!< R/W 0x0  Bbswing ,txbias  mcs ov th sel this*/
#define BIT_TXBIAS_VHT_OV_TH_VAL(x)           (((u32)((x) & 0x00000003) << 30))
#define BIT_GET_TXBIAS_VHT_OV_TH_VAL(x)       ((u32)(((x >> 30) & 0x00000003)))
#define BIT_MASK_TXBBSWING_VHT_BELOW_TH_VAL   ((u32)0x0000000F << 26)           /*!< R/W 0x0  Bbswing ,txbias  mcs below th sel this*/
#define BIT_TXBBSWING_VHT_BELOW_TH_VAL(x)     (((u32)((x) & 0x0000000F) << 26))
#define BIT_GET_TXBBSWING_VHT_BELOW_TH_VAL(x) ((u32)(((x >> 26) & 0x0000000F)))
#define BIT_MASK_TXBBSWING_VHT_OV_TH_VAL      ((u32)0x0000000F << 22)           /*!< R/W 0x0  Bbswing ,txbias  mcs ov th sel this*/
#define BIT_TXBBSWING_VHT_OV_TH_VAL(x)        (((u32)((x) & 0x0000000F) << 22))
#define BIT_GET_TXBBSWING_VHT_OV_TH_VAL(x)    ((u32)(((x >> 22) & 0x0000000F)))
#define BIT_MASK_TXBBSWING_TXBIAS_VHT_TH      ((u32)0x0000000F << 18)           /*!< R/W 0x0  0~12 Bbswing txbias mcs th*/
#define BIT_TXBBSWING_TXBIAS_VHT_TH(x)        (((u32)((x) & 0x0000000F) << 18))
#define BIT_GET_TXBBSWING_TXBIAS_VHT_TH(x)    ((u32)(((x >> 18) & 0x0000000F)))
#define BIT_MASK_TXBIAS_HT_BELOW_TH_VAL       ((u32)0x00000003 << 16)           /*!< R/W 0x0  Bbswing ,txbias mcs below th sel this*/
#define BIT_TXBIAS_HT_BELOW_TH_VAL(x)         (((u32)((x) & 0x00000003) << 16))
#define BIT_GET_TXBIAS_HT_BELOW_TH_VAL(x)     ((u32)(((x >> 16) & 0x00000003)))
#define BIT_MASK_TXBIAS_HT_OV_TH_VAL          ((u32)0x00000003 << 14)           /*!< R/W 0x0  Bbswing ,txbias  mcs ov th sel this*/
#define BIT_TXBIAS_HT_OV_TH_VAL(x)            (((u32)((x) & 0x00000003) << 14))
#define BIT_GET_TXBIAS_HT_OV_TH_VAL(x)        ((u32)(((x >> 14) & 0x00000003)))
#define BIT_MASK_TXBBSWING_HT_BELOW_TH_VAL    ((u32)0x0000000F << 10)           /*!< R/W 0x0  Bbswing ,txbias  mcs below th sel this*/
#define BIT_TXBBSWING_HT_BELOW_TH_VAL(x)      (((u32)((x) & 0x0000000F) << 10))
#define BIT_GET_TXBBSWING_HT_BELOW_TH_VAL(x)  ((u32)(((x >> 10) & 0x0000000F)))
#define BIT_MASK_TXBBSWING_HT_OV_TH_VAL       ((u32)0x0000000F << 6)            /*!< R/W 0x0  Bbswing ,txbias mcs ov th sel this*/
#define BIT_TXBBSWING_HT_OV_TH_VAL(x)         (((u32)((x) & 0x0000000F) << 6))
#define BIT_GET_TXBBSWING_HT_OV_TH_VAL(x)     ((u32)(((x >> 6) & 0x0000000F)))
#define BIT_MASK_TXBBSWING_TXBIAS_HT_TH       ((u32)0x0000000F << 2)            /*!< R/W 0x0  0~8 Bbswing txbias mcs th*/
#define BIT_TXBBSWING_TXBIAS_HT_TH(x)         (((u32)((x) & 0x0000000F) << 2))
#define BIT_GET_TXBBSWING_TXBIAS_HT_TH(x)     ((u32)(((x >> 2) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SWING_HE_CTRL
  * @brief
  * @{
  */
#define BIT_DPD_BY_RATE_OFF_LEGACY_BELOW_TH_VAL ((u32)0x00000001 << 28)           /*!< R/W 0x0  Bbswing ,txbias  mcs below th sel this*/
#define BIT_DPD_BY_RATE_OFF_LEGACY_OV_TH_VAL    ((u32)0x00000001 << 27)           /*!< R/W 0x0  Bbswing ,txbias  mcs ov th sel this*/
#define BIT_MASK_DPD_BY_RATE_OFF_LEGACY_TH      ((u32)0x0000000F << 23)           /*!< R/W 0x0  4~8 Bbswing txbias mcs th*/
#define BIT_DPD_BY_RATE_OFF_LEGACY_TH(x)        (((u32)((x) & 0x0000000F) << 23))
#define BIT_GET_DPD_BY_RATE_OFF_LEGACY_TH(x)    ((u32)(((x >> 23) & 0x0000000F)))
#define BIT_DPD_BY_RATE_OFF_CCK_BELOW_TH_VAL    ((u32)0x00000001 << 22)           /*!< R/W 0x0  Bbswing ,txbias  mcs below th sel this*/
#define BIT_DPD_BY_RATE_OFF_CCK_OV_TH_VAL       ((u32)0x00000001 << 21)           /*!< R/W 0x0  Bbswing ,txbias  mcs ov th sel this*/
#define BIT_MASK_DPD_BY_RATE_OFF_CCK_TH         ((u32)0x00000007 << 18)           /*!< R/W 0x0  0~4 Bbswing txbias mcs th*/
#define BIT_DPD_BY_RATE_OFF_CCK_TH(x)           (((u32)((x) & 0x00000007) << 18))
#define BIT_GET_DPD_BY_RATE_OFF_CCK_TH(x)       ((u32)(((x >> 18) & 0x00000007)))
#define BIT_MASK_TXBIAS_HE_BELOW_TH_VAL         ((u32)0x00000003 << 16)           /*!< R/W 0x0  Bbswing ,txbias  mcs below th sel this*/
#define BIT_TXBIAS_HE_BELOW_TH_VAL(x)           (((u32)((x) & 0x00000003) << 16))
#define BIT_GET_TXBIAS_HE_BELOW_TH_VAL(x)       ((u32)(((x >> 16) & 0x00000003)))
#define BIT_MASK_TXBIAS_HE_OV_TH_VAL            ((u32)0x00000003 << 14)           /*!< R/W 0x0  Bbswing ,txbias  mcs ov th sel this*/
#define BIT_TXBIAS_HE_OV_TH_VAL(x)              (((u32)((x) & 0x00000003) << 14))
#define BIT_GET_TXBIAS_HE_OV_TH_VAL(x)          ((u32)(((x >> 14) & 0x00000003)))
#define BIT_MASK_TXBBSWING_HE_BELOW_TH_VAL      ((u32)0x0000000F << 10)           /*!< R/W 0x0  Bbswing ,txbias  mcs below th sel this*/
#define BIT_TXBBSWING_HE_BELOW_TH_VAL(x)        (((u32)((x) & 0x0000000F) << 10))
#define BIT_GET_TXBBSWING_HE_BELOW_TH_VAL(x)    ((u32)(((x >> 10) & 0x0000000F)))
#define BIT_MASK_TXBBSWING_HE_OV_TH_VAL         ((u32)0x0000000F << 6)            /*!< R/W 0x0  Bbswing ,txbias  mcs ov th sel this*/
#define BIT_TXBBSWING_HE_OV_TH_VAL(x)           (((u32)((x) & 0x0000000F) << 6))
#define BIT_GET_TXBBSWING_HE_OV_TH_VAL(x)       ((u32)(((x >> 6) & 0x0000000F)))
#define BIT_MASK_TXBBSWING_TXBIAS_HE_TH         ((u32)0x0000000F << 2)            /*!< R/W 0x0  0~12   Bbswing txbias mcs th*/
#define BIT_TXBBSWING_TXBIAS_HE_TH(x)           (((u32)((x) & 0x0000000F) << 2))
#define BIT_GET_TXBBSWING_TXBIAS_HE_TH(x)       ((u32)(((x >> 2) & 0x0000000F)))
#define BIT_MASK_TXBIAS_VHT_BELOW_TH_VAL        ((u32)0x00000003 << 0)            /*!< R/W 0x0  Bbswing ,txbias   mcs ov th sel this*/
#define BIT_TXBIAS_VHT_BELOW_TH_VAL(x)          (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_TXBIAS_VHT_BELOW_TH_VAL(x)      ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_AX_PWR_SWING_OTHER_CTRL0
  * @brief
  * @{
  */
#define BIT_CFIR_BY_RATE_OFF_LEGACY_BELOW_TH_VAL ((u32)0x00000001 << 28)           /*!< R/W 0x0  dpd by rate off mcs below th sel this*/
#define BIT_CFIR_BY_RATE_OFF_LEGACY_OV_TH_VAL    ((u32)0x00000001 << 27)           /*!< R/W 0x0  dpd by rate off mcs ov th sel this*/
#define BIT_MASK_CFIR_BY_RATE_OFF_LEGACY_TH      ((u32)0x0000000F << 23)           /*!< R/W 0x0  4~8  dpd by rate off mcs ov th*/
#define BIT_CFIR_BY_RATE_OFF_LEGACY_TH(x)        (((u32)((x) & 0x0000000F) << 23))
#define BIT_GET_CFIR_BY_RATE_OFF_LEGACY_TH(x)    ((u32)(((x >> 23) & 0x0000000F)))
#define BIT_CFIR_BY_RATE_OFF_CCK_BELOW_TH_VAL    ((u32)0x00000001 << 22)           /*!< R/W 0x0  dpd by rate off mcs below th sel this*/
#define BIT_CFIR_BY_RATE_OFF_CCK_OV_TH_VAL       ((u32)0x00000001 << 21)           /*!< R/W 0x0  dpd by rate off mcs ov th sel this*/
#define BIT_MASK_CFIR_BY_RATE_OFF_CCK_TH         ((u32)0x00000007 << 18)           /*!< R/W 0x0  0~4 dpd by rate off mcs th*/
#define BIT_CFIR_BY_RATE_OFF_CCK_TH(x)           (((u32)((x) & 0x00000007) << 18))
#define BIT_GET_CFIR_BY_RATE_OFF_CCK_TH(x)       ((u32)(((x >> 18) & 0x00000007)))
#define BIT_DPD_BY_RATE_OFF_HE_BELOW_TH_VAL      ((u32)0x00000001 << 17)           /*!< R/W 0x0  cfir by rate_off   mcs  below th sel this*/
#define BIT_DPD_BY_RATE_OFF_HE_OV_TH_VAL         ((u32)0x00000001 << 16)           /*!< R/W 0x0  cfir by rate_off   mcs  ov th sel this*/
#define BIT_MASK_DPD_BY_RATE_OFF_HE_TH           ((u32)0x0000000F << 12)           /*!< R/W 0x0  0~12 cfir by rate_off   mcs th*/
#define BIT_DPD_BY_RATE_OFF_HE_TH(x)             (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_DPD_BY_RATE_OFF_HE_TH(x)         ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_DPD_BY_RATE_OFF_VHT_BELOW_TH_VAL     ((u32)0x00000001 << 11)           /*!< R/W 0x0  cfir by rate_off   mcs  below th sel this*/
#define BIT_DPD_BY_RATE_OFF_VHT_OV_TH_VAL        ((u32)0x00000001 << 10)           /*!< R/W 0x0  cfir by rate_off   mcs  ov th sel this*/
#define BIT_MASK_DPD_BY_RATE_OFF_VHT_TH          ((u32)0x0000000F << 6)            /*!< R/W 0x0  0~12 cfir by rate_off   mcs th*/
#define BIT_DPD_BY_RATE_OFF_VHT_TH(x)            (((u32)((x) & 0x0000000F) << 6))
#define BIT_GET_DPD_BY_RATE_OFF_VHT_TH(x)        ((u32)(((x >> 6) & 0x0000000F)))
#define BIT_DPD_BY_RATE_OFF_HT_BELOW_TH_VAL      ((u32)0x00000001 << 5)            /*!< R/W 0x0  cfir by rate_off   mcs  below th sel this*/
#define BIT_DPD_BY_RATE_OFF_HT_OV_TH_VAL         ((u32)0x00000001 << 4)            /*!< R/W 0x0  cfir by rate_off   mcs  ov th sel this*/
#define BIT_MASK_DPD_BY_RATE_OFF_HT_TH           ((u32)0x0000000F << 0)            /*!< R/W 0x0  0~8 cfir by rate_off   mcs th*/
#define BIT_DPD_BY_RATE_OFF_HT_TH(x)             (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_DPD_BY_RATE_OFF_HT_TH(x)         ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SWING_OTHER_CTRL1
  * @brief
  * @{
  */
#define BIT_CFIR_BY_RATE_OFF_SR_DONT_APPLY    ((u32)0x00000001 << 30)           /*!< R/W 0x0  (RTL_only)  1:Disable at SR*/
#define BIT_DPD_BY_RATE_OFF_SR_DONT_APPLY     ((u32)0x00000001 << 29)           /*!< R/W 0x0  (RTL_only)  1:Disable at SR*/
#define BIT_TXBBSWING_TXBIAS_SR_DONT_APPLY    ((u32)0x00000001 << 28)           /*!< R/W 0x0  (RTL_only)  1:Disable at SR*/
#define BIT_CFIR_BY_RATE_OFF_HE_BELOW_TH_VAL  ((u32)0x00000001 << 17)           /*!< R/W 0x0  dpd by rate off mcs below th sel this*/
#define BIT_CFIR_BY_RATE_OFF_HE_OV_TH_VAL     ((u32)0x00000001 << 16)           /*!< R/W 0x0  dpd by rate off mcs ov th sel this*/
#define BIT_MASK_CFIR_BY_RATE_OFF_HE_TH       ((u32)0x0000000F << 12)           /*!< R/W 0x0  0~12  dpd by rate off mcs ov th*/
#define BIT_CFIR_BY_RATE_OFF_HE_TH(x)         (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CFIR_BY_RATE_OFF_HE_TH(x)     ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_CFIR_BY_RATE_OFF_VHT_BELOW_TH_VAL ((u32)0x00000001 << 11)           /*!< R/W 0x0  dpd by rate off mcs below th sel this*/
#define BIT_CFIR_BY_RATE_OFF_VHT_OV_TH_VAL    ((u32)0x00000001 << 10)           /*!< R/W 0x0  dpd by rate off mcs ov th sel this*/
#define BIT_MASK_CFIR_BY_RATE_OFF_VHT_TH      ((u32)0x0000000F << 6)            /*!< R/W 0x0  0~12  dpd by rate off mcs ov th*/
#define BIT_CFIR_BY_RATE_OFF_VHT_TH(x)        (((u32)((x) & 0x0000000F) << 6))
#define BIT_GET_CFIR_BY_RATE_OFF_VHT_TH(x)    ((u32)(((x >> 6) & 0x0000000F)))
#define BIT_CFIR_BY_RATE_OFF_HT_BELOW_TH_VAL  ((u32)0x00000001 << 5)            /*!< R/W 0x0  dpd by rate off mcs below th sel this*/
#define BIT_CFIR_BY_RATE_OFF_HT_OV_TH_VAL     ((u32)0x00000001 << 4)            /*!< R/W 0x0  dpd by rate off mcs ov th sel this*/
#define BIT_MASK_CFIR_BY_RATE_OFF_HT_TH       ((u32)0x0000000F << 0)            /*!< R/W 0x0  0~8  dpd by rate off mcs ov th*/
#define BIT_CFIR_BY_RATE_OFF_HT_TH(x)         (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CFIR_BY_RATE_OFF_HT_TH(x)     ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_CTRL0
  * @brief
  * @{
  */
#define BIT_SR_PWCTRL_DBG_EN                 ((u32)0x00000001 << 31)           /*!< R/W 1h  (RTL_only)  0:saving pwr*/
#define BIT_MASK_SR_RATE_TBL_RD_MCS_TXDIFF   ((u32)0x0000001F << 20)           /*!< R/W 0x0  (RTL_only)  Rd MEM idx 0~47*/
#define BIT_SR_RATE_TBL_RD_MCS_TXDIFF(x)     (((u32)((x) & 0x0000001F) << 20))
#define BIT_GET_SR_RATE_TBL_RD_MCS_TXDIFF(x) ((u32)(((x >> 20) & 0x0000001F)))
#define BIT_SR_RATE_MAP_TBL_RD_MCS_SEL       ((u32)0x00000001 << 19)           /*!< R/W 0x0  (RTL_only)  1:cckle 0~11 0:ht/vht/he 0~11*/
#define BIT_TXPWSFORCE_OFF                   ((u32)0x00000001 << 18)           /*!< R/W 0x0  (RTL_only)  1:force sr mode off*/
#define BIT_TXPWSTA_UL_FORCE_OFF             ((u32)0x00000001 << 17)           /*!< R/W 0x0  (RTL_only)  1:force sta mode off*/
#define BIT_SR_TXPWPD_WITH_PD_MACID          ((u32)0x00000001 << 16)           /*!< R/W 1h  (RTL_only)   1:txpwPD from internal buffer 0: from MAC*/
#define BIT_SR_RATE_MAP_TBL_RD               ((u32)0x00000001 << 15)           /*!< R/W 0x0  (RTL_only)  1:indirect read of addr*/
#define BIT_MASK_SR_RATE_MAP_TBL_RD_MCS      ((u32)0x0000000F << 11)           /*!< R/W 0x0  (RTL_only)  indirect read of addr*/
#define BIT_SR_RATE_MAP_TBL_RD_MCS(x)        (((u32)((x) & 0x0000000F) << 11))
#define BIT_GET_SR_RATE_MAP_TBL_RD_MCS(x)    ((u32)(((x >> 11) & 0x0000000F)))
#define BIT_TXPWCTRL_NORM_RESP_DBG_EN        ((u32)0x00000001 << 10)           /*!< R/W 1h  (RTL_only)  0:dbg clk off for saving pwr*/
#define BIT_TXAGC_PSEUDO_PWEN                ((u32)0x00000001 << 9)            /*!< R/W 0x0  (RTL_only)  1:  force on norm resp out txpwbb*/
#define BIT_MASK_TXAGC_PSEUDO_PWR            ((u32)0x000001FF << 0)            /*!< R/W 0x0  (RTL_only)  S(9.2) force norm resp out txpwbb*/
#define BIT_TXAGC_PSEUDO_PWR(x)              (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_TXAGC_PSEUDO_PWR(x)          ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_AX_PWR_SR_CTRL1
  * @brief
  * @{
  */
#define BIT_MASK_MCS_TH_HE        ((u32)0x0000000F << 24)           /*!< R/W 0x0  SR  MCS0~MCS11*/
#define BIT_MCS_TH_HE(x)          (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_MCS_TH_HE(x)      ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_MCS_TH_VHT       ((u32)0x0000000F << 20)           /*!< R/W 0x0  SR  MCS0~MCS11*/
#define BIT_MCS_TH_VHT(x)         (((u32)((x) & 0x0000000F) << 20))
#define BIT_GET_MCS_TH_VHT(x)     ((u32)(((x >> 20) & 0x0000000F)))
#define BIT_MASK_MCS_TH_HT_MOD8   ((u32)0x0000000F << 16)           /*!< R/W 0x0  SR  MCS0~MCS7*/
#define BIT_MCS_TH_HT_MOD8(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS_TH_HT_MOD8(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS_TH_LEGACY    ((u32)0x0000000F << 12)           /*!< R/W 0x0  SR  4~11*/
#define BIT_MCS_TH_LEGACY(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS_TH_LEGACY(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS_TH_CCK       ((u32)0x0000000F << 8)            /*!< R/W 0x0  SR  0~3*/
#define BIT_MCS_TH_CCK(x)         (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS_TH_CCK(x)     ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_TXPWR_REF        ((u32)0x0000007F << 0)            /*!< R/W 0x0  SR txpwr ref(txpwmcs diff)*/
#define BIT_TXPWR_REF(x)          (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXPWR_REF(x)      ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_UL_CTRL0
  * @brief
  * @{
  */
#define BIT_BYPASS_ABORT_TX_FLAG   ((u32)0x00000001 << 29)           /*!< R/W 0x0  1: force off abort_tx flag STA_UL*/
#define BIT_MASK_PL_TOLER_RANGE    ((u32)0x000001FF << 20)           /*!< R/W 0x0  U(9.2) STA_UL*/
#define BIT_PL_TOLER_RANGE(x)      (((u32)((x) & 0x000001FF) << 20))
#define BIT_GET_PL_TOLER_RANGE(x)  ((u32)(((x >> 20) & 0x000001FF)))
#define BIT_MASK_PWR_BB_MIN_DBM    ((u32)0x000001FF << 9)            /*!< R/W 1FCh  S(9.2)  STA_UL*/
#define BIT_PWR_BB_MIN_DBM(x)      (((u32)((x) & 0x000001FF) << 9))
#define BIT_GET_PWR_BB_MIN_DBM(x)  ((u32)(((x >> 9) & 0x000001FF)))
#define BIT_MASK_PWR_ERROR_TOLER   ((u32)0x000000FF << 0)            /*!< R/W FFh  S(9.2)  STA_UL*/
#define BIT_PWR_ERROR_TOLER(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_PWR_ERROR_TOLER(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_UL_CTRL1
  * @brief
  * @{
  */
#define BIT_MASK_MACID3   ((u32)0x0000007F << 24)           /*!< R/W 0x0  STA_UL*/
#define BIT_MACID3(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_MACID3(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_MACID2   ((u32)0x0000007F << 16)           /*!< R/W 0x0  STA_UL*/
#define BIT_MACID2(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_MACID2(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_MACID1   ((u32)0x0000007F << 8)            /*!< R/W 0x0  STA_UL*/
#define BIT_MACID1(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_MACID1(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_MACID0   ((u32)0x0000007F << 0)            /*!< R/W 0x0  STA_UL*/
#define BIT_MACID0(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_MACID0(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_UL_CTRL2
  * @brief
  * @{
  */
#define BIT_MASK_CFO_COMP_SR          ((u32)0x00000007 << 24)           /*!< R/W 7h  (RTL_only)  STA_UL  no need to set*/
#define BIT_CFO_COMP_SR(x)            (((u32)((x) & 0x00000007) << 24))
#define BIT_GET_CFO_COMP_SR(x)        ((u32)(((x >> 24) & 0x00000007)))
#define BIT_MASK_CFO_COMP_NORM_RESP   ((u32)0x00000007 << 20)           /*!< R/W 7h  (RTL_only)  STA_UL  no need to set*/
#define BIT_CFO_COMP_NORM_RESP(x)     (((u32)((x) & 0x00000007) << 20))
#define BIT_GET_CFO_COMP_NORM_RESP(x) ((u32)(((x >> 20) & 0x00000007)))
#define BIT_MASK_CFO_COMP4            ((u32)0x00000007 << 16)           /*!< R/W 6h  (RTL_only)  STA_UL Default 6 no need to set*/
#define BIT_CFO_COMP4(x)              (((u32)((x) & 0x00000007) << 16))
#define BIT_GET_CFO_COMP4(x)          ((u32)(((x >> 16) & 0x00000007)))
#define BIT_MASK_CFO_COMP3            ((u32)0x00000007 << 12)           /*!< R/W 7h  STA_UL*/
#define BIT_CFO_COMP3(x)              (((u32)((x) & 0x00000007) << 12))
#define BIT_GET_CFO_COMP3(x)          ((u32)(((x >> 12) & 0x00000007)))
#define BIT_MASK_CFO_COMP2            ((u32)0x00000007 << 8)            /*!< R/W 7h  STA_UL*/
#define BIT_CFO_COMP2(x)              (((u32)((x) & 0x00000007) << 8))
#define BIT_GET_CFO_COMP2(x)          ((u32)(((x >> 8) & 0x00000007)))
#define BIT_MASK_CFO_COMP1            ((u32)0x00000007 << 4)            /*!< R/W 7h  STA_UL*/
#define BIT_CFO_COMP1(x)              (((u32)((x) & 0x00000007) << 4))
#define BIT_GET_CFO_COMP1(x)          ((u32)(((x >> 4) & 0x00000007)))
#define BIT_MASK_CFO_COMP0            ((u32)0x00000007 << 0)            /*!< R/W 7h  STA_UL*/
#define BIT_CFO_COMP0(x)              (((u32)((x) & 0x00000007) << 0))
#define BIT_GET_CFO_COMP0(x)          ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_AX_PWR_UL_CTRL3
  * @brief
  * @{
  */
#define BIT_TF_RDY_TXBF_FORCE_OFF             ((u32)0x00000001 << 22)           /*!< R/W 1h  (RTL_only)  Jorden Sta_UL doesnt have TxBF*/
#define BIT_FORCE_PL_UPPEEN_EQUL_N_TX_DIVIDE2 ((u32)0x00000001 << 21)           /*!< R/W 0x0  (RTL_only)  1:PL_uppeen = is N_tx/2*/
#define BIT_FORCE_N_TX_DIVIDE2_OFF            ((u32)0x00000001 << 20)           /*!< R/W 0x0  (RTL_only)  1:force off N_tx/2*/
#define BIT_MASK_STA_PWCTRL_PWRMAX_LIM_MAX    ((u32)0x000001FF << 11)           /*!< R/W FFh  (RTL_only)   S(9.2) Limit pwr from norm resp*/
#define BIT_STA_PWCTRL_PWRMAX_LIM_MAX(x)      (((u32)((x) & 0x000001FF) << 11))
#define BIT_GET_STA_PWCTRL_PWRMAX_LIM_MAX(x)  ((u32)(((x >> 11) & 0x000001FF)))
#define BIT_MASK_STA_PWCTRL_PWRMAX_LIM_MIN    ((u32)0x000001FF << 0)            /*!< R/W 100h  (RTL_only)   S(9.2)  Limit pwr from norm resp*/
#define BIT_STA_PWCTRL_PWRMAX_LIM_MIN(x)      (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_STA_PWCTRL_PWRMAX_LIM_MIN(x)  ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_AX_PWR_UL_CTRL4
  * @brief
  * @{
  */
#define BIT_MASK_STA_PWCTRL_RPL_LIM_MIN           ((u32)0x000003FF << 16)           /*!< R/W 248h  (RTL_only)  S(10.2)  Min=-110 (-440) Limit RPL*/
#define BIT_STA_PWCTRL_RPL_LIM_MIN(x)             (((u32)((x) & 0x000003FF) << 16))
#define BIT_GET_STA_PWCTRL_RPL_LIM_MIN(x)         ((u32)(((x >> 16) & 0x000003FF)))
#define BIT_MASK_STA_PWCTRL_RSSI_TARGET_LIM_MAX   ((u32)0x000000FF << 8)            /*!< R/W 0x0  (RTL_only)  S(8.0) Max:0 Limit RSSI_Target*/
#define BIT_STA_PWCTRL_RSSI_TARGET_LIM_MAX(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_STA_PWCTRL_RSSI_TARGET_LIM_MAX(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_STA_PWCTRL_RSSI_TARGET_LIM_MIN   ((u32)0x000000FF << 0)            /*!< R/W 92h  (RTL_only)  S(8.0) Min=-110 Limit RSSI_Target*/
#define BIT_STA_PWCTRL_RSSI_TARGET_LIM_MIN(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_STA_PWCTRL_RSSI_TARGET_LIM_MIN(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_UL_CTRL5
  * @brief
  * @{
  */
#define BIT_SR_TXPWRESP_RDY               ((u32)0x00000001 << 28)          /*!< R/W 0x0  (RTL_only)  1: trig when SR_txpwresp_rdy_force_on*/
#define BIT_SR_TXPWPD_RDY                 ((u32)0x00000001 << 27)          /*!< R/W 0x0  (RTL_only)  1: trig when SR_txpwpd_rdy_force_on*/
#define BIT_SR_TXPWRATE_RDY               ((u32)0x00000001 << 26)          /*!< R/W 0x0  (RTL_only)  1: trig when SR_txpwrate_rdy_force_on*/
#define BIT_TF_RDY                        ((u32)0x00000001 << 25)          /*!< R/W 0x0  (RTL_only)  1: trig when TF_rdy_force_on*/
#define BIT_TXCTRL_INFO_RDY               ((u32)0x00000001 << 24)          /*!< R/W 0x0  (RTL_only)  1: trig when TxCtrl_info_rdy_force_on*/
#define BIT_FORCE_PL_UPPEEN_VAL           ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_FORCE_PL_UPPEEN_ON            ((u32)0x00000001 << 22)          /*!< R/W 0x0  (RTL_only)  1 : PL_uppeen = force_PL_uppeen_val*/
#define BIT_SR_TXPWRESP_RDY_FORCE_ON      ((u32)0x00000001 << 15)          /*!< R/W 0x0  (RTL_only)  1:force off SR resp trigger*/
#define BIT_SR_TXPWPD_RDY_FORCE_ON        ((u32)0x00000001 << 14)          /*!< R/W 0x0  (RTL_only)  1:force off SR MCS flow trigger*/
#define BIT_SR_TXPWRATE_RDY_FORCE_ON      ((u32)0x00000001 << 13)          /*!< R/W 0x0  (RTL_only)  1:force off SR PD flow trigger*/
#define BIT_TF_RDY_FORCE_ON               ((u32)0x00000001 << 12)          /*!< R/W 0x0  (RTL_only)  1:force off TF trigger*/
#define BIT_TXCTRL_INFO_RDY_FORCE_ON      ((u32)0x00000001 << 11)          /*!< R/W 0x0  (RTL_only)  1:force off norm resp trigger*/
#define BIT_STA_PWCTRL_DBG_EN             ((u32)0x00000001 << 10)          /*!< R/W 0x0  (RTL_only) 0: pwr saving*/
#define BIT_MASK_STA_PWCTRL_RPL_LIM_MAX   ((u32)0x000003FF << 0)           /*!< R/W 0x0  (RTL_only)  S(10.2) Max:0 Limit RPL*/
#define BIT_STA_PWCTRL_RPL_LIM_MAX(x)     (((u32)((x) & 0x000003FF) << 0))
#define BIT_GET_STA_PWCTRL_RPL_LIM_MAX(x) ((u32)(((x >> 0) & 0x000003FF)))
/** @} */

/** @defgroup REG_AX_PWR_UL_CTRL6
  * @brief
  * @{
  */
#define BIT_MASK_STA_PWCTRL_AP_TXPWR_LIM_MIN   ((u32)0x0000007F << 24)           /*!< R/W 6Ch  (RTL_only)  S(7.0 ) MIN=-20  Limit  AP TXPWR*/
#define BIT_STA_PWCTRL_AP_TXPWR_LIM_MIN(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_STA_PWCTRL_AP_TXPWR_LIM_MIN(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_STA_PWCTRL_AP_TXPWR_LIM_MAX   ((u32)0x0000007F << 16)           /*!< R/W 28h  (RTL_only)  S(7.0 ) MAX=+40 Limit  AP TXPWR*/
#define BIT_STA_PWCTRL_AP_TXPWR_LIM_MAX(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_STA_PWCTRL_AP_TXPWR_LIM_MAX(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_TXPWFORCE_RATE_EN                  ((u32)0x00000001 << 12)           /*!< R/W 0x0  (RTL_only)   No use*/
#define BIT_MASK_TXPWFORCE_RATE                ((u32)0x00000FFF << 0)            /*!< R/W 0x0  (RTL_only)   No use*/
#define BIT_TXPWFORCE_RATE(x)                  (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_TXPWFORCE_RATE(x)              ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_AX_PWR_NORM_FORCE0
  * @brief
  * @{
  */
#define BIT_FORCE_MACID_EN               ((u32)0x00000001 << 30)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_MASK_FORCE_MACID_VALUE       ((u32)0x0000007F << 23)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_MACID_VALUE(x)         (((u32)((x) & 0x0000007F) << 23))
#define BIT_GET_FORCE_MACID_VALUE(x)     ((u32)(((x >> 23) & 0x0000007F)))
#define BIT_FORCE_BW80P80_EN_EN          ((u32)0x00000001 << 22)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_BW80P80_EN_VALUE       ((u32)0x00000001 << 21)           /*!< R/W 1h  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_RF_BW_IDX_EN           ((u32)0x00000001 << 20)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_MASK_FORCE_RF_BW_IDX_VALUE   ((u32)0x00000003 << 18)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_RF_BW_IDX_VALUE(x)     (((u32)((x) & 0x00000003) << 18))
#define BIT_GET_FORCE_RF_BW_IDX_VALUE(x) ((u32)(((x >> 18) & 0x00000003)))
#define BIT_FORCE_DCM_EN                 ((u32)0x00000001 << 17)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_DCM_VALUE              ((u32)0x00000001 << 16)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_DBW_IDX_EN             ((u32)0x00000001 << 15)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_MASK_FORCE_DBW_IDX_VALUE     ((u32)0x00000003 << 13)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_DBW_IDX_VALUE(x)       (((u32)((x) & 0x00000003) << 13))
#define BIT_GET_FORCE_DBW_IDX_VALUE(x)   ((u32)(((x >> 13) & 0x00000003)))
#define BIT_FORCE_MAX_RATE_EN            ((u32)0x00000001 << 12)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_MASK_FORCE_MAX_RATE_VALUE    ((u32)0x00000FFF << 0)            /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_MAX_RATE_VALUE(x)      (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_FORCE_MAX_RATE_VALUE(x)  ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_AX_PWR_NORM_FORCE1
  * @brief
  * @{
  */
#define BIT_TXAGC_BF_PWBOOST_FORCE_VAL_EN     ((u32)0x00000001 << 29)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_MASK_TXAGC_BF_PWBOOST_FORCE_VAL   ((u32)0x0000001F << 24)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_TXAGC_BF_PWBOOST_FORCE_VAL(x)     (((u32)((x) & 0x0000001F) << 24))
#define BIT_GET_TXAGC_BF_PWBOOST_FORCE_VAL(x) ((u32)(((x >> 24) & 0x0000001F)))
#define BIT_FORCE_HE_ER_SU_EN_EN              ((u32)0x00000001 << 23)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_FORCE_HE_ER_SU_EN_VALUE           ((u32)0x00000001 << 22)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_MACID_CCA_TH_EN_EN          ((u32)0x00000001 << 21)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_FORCE_MACID_CCA_TH_EN_VALUE       ((u32)0x00000001 << 20)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_BT_GRANT_EN                 ((u32)0x00000001 << 19)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_FORCE_BT_GRANT_VALUE              ((u32)0x00000001 << 18)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_RX_LTE_EN                   ((u32)0x00000001 << 17)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_FORCE_RX_LTE_VALUE                ((u32)0x00000001 << 16)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_TXBF_EN_EN                  ((u32)0x00000001 << 15)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_FORCE_TXBF_EN_VALUE               ((u32)0x00000001 << 14)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_TXSC_EN                     ((u32)0x00000001 << 13)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_MASK_FORCE_TXSC_VALUE             ((u32)0x0000000F << 9)            /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_TXSC_VALUE(x)               (((u32)((x) & 0x0000000F) << 9))
#define BIT_GET_FORCE_TXSC_VALUE(x)           ((u32)(((x >> 9) & 0x0000000F)))
#define BIT_FORCE_NTX_EN                      ((u32)0x00000001 << 6)            /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_FORCE_NTX_VALUE                   ((u32)0x00000001 << 5)            /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_PWMODE_EN                   ((u32)0x00000001 << 3)            /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_MASK_FORCE_PWMODE_VALUE           ((u32)0x00000007 << 0)            /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_PWMODE_VALUE(x)             (((u32)((x) & 0x00000007) << 0))
#define BIT_GET_FORCE_PWMODE_VALUE(x)         ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_AX_PWR_SR_FORCE0
  * @brief
  * @{
  */
#define BIT_FORCE_SR_RESP_DCM_EN                ((u32)0x00000001 << 30)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_FORCE_SR_RESP_DCM_VALUE             ((u32)0x00000001 << 29)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_SR_RATE_DCM_EN                ((u32)0x00000001 << 28)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_FORCE_SR_RATE_DCM_VALUE             ((u32)0x00000001 << 27)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_SR_TXPWPD_EN                  ((u32)0x00000001 << 26)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_MASK_FORCE_SR_TXPWPD_VALUE          ((u32)0x0000003F << 20)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_SR_TXPWPD_VALUE(x)            (((u32)((x) & 0x0000003F) << 20))
#define BIT_GET_FORCE_SR_TXPWPD_VALUE(x)        ((u32)(((x >> 20) & 0x0000003F)))
#define BIT_FORCE_SR_RATE_IDX_EN                ((u32)0x00000001 << 19)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_MASK_FORCE_SR_RATE_IDX_VALUE        ((u32)0x00000FFF << 7)            /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_SR_RATE_IDX_VALUE(x)          (((u32)((x) & 0x00000FFF) << 7))
#define BIT_GET_FORCE_SR_RATE_IDX_VALUE(x)      ((u32)(((x >> 7) & 0x00000FFF)))
#define BIT_FORCE_SR_TXPWTOLERANCE_EN           ((u32)0x00000001 << 6)            /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_MASK_FORCE_SR_TXPWTOLERANCE_VALUE   ((u32)0x0000003F << 0)            /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_SR_TXPWTOLERANCE_VALUE(x)     (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_FORCE_SR_TXPWTOLERANCE_VALUE(x) ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_FORCE1
  * @brief
  * @{
  */
#define BIT_FORCE_RPL_EN                        ((u32)0x00000001 << 29)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_MASK_FORCE_RPL_VALUE                ((u32)0x000001FF << 20)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_RPL_VALUE(x)                  (((u32)((x) & 0x000001FF) << 20))
#define BIT_GET_FORCE_RPL_VALUE(x)              ((u32)(((x >> 20) & 0x000001FF)))
#define BIT_FORCE_SR_RESP_RATE_IDX_EN           ((u32)0x00000001 << 19)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_MASK_FORCE_SR_RESP_RATE_IDX_VALUE   ((u32)0x00000FFF << 7)            /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_SR_RESP_RATE_IDX_VALUE(x)     (((u32)((x) & 0x00000FFF) << 7))
#define BIT_GET_FORCE_SR_RESP_RATE_IDX_VALUE(x) ((u32)(((x >> 7) & 0x00000FFF)))
#define BIT_FORCE_SR_RESP_TXPWPD_EN             ((u32)0x00000001 << 6)            /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_MASK_FORCE_SR_RESP_TXPWPD_VALUE     ((u32)0x0000003F << 0)            /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_SR_RESP_TXPWPD_VALUE(x)       (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_FORCE_SR_RESP_TXPWPD_VALUE(x)   ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_FORCE2
  * @brief
  * @{
  */
#define BIT_FORCE_TF_AP_TX_PWR_EN           ((u32)0x00000001 << 31)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_MASK_FORCE_TF_AP_TX_PWR_VALUE   ((u32)0x0000003F << 25)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_TF_AP_TX_PWR_VALUE(x)     (((u32)((x) & 0x0000003F) << 25))
#define BIT_GET_FORCE_TF_AP_TX_PWR_VALUE(x) ((u32)(((x >> 25) & 0x0000003F)))
#define BIT_FORCE_TF_RATE_IDX_EN            ((u32)0x00000001 << 24)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_MASK_FORCE_TF_RATE_IDX_VALUE    ((u32)0x00000FFF << 12)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_TF_RATE_IDX_VALUE(x)      (((u32)((x) & 0x00000FFF) << 12))
#define BIT_GET_FORCE_TF_RATE_IDX_VALUE(x)  ((u32)(((x >> 12) & 0x00000FFF)))
#define BIT_FORCE_RPL_UPPEEN_EN             ((u32)0x00000001 << 11)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_FORCE_RPL_UPPEEN_VALUE          ((u32)0x00000001 << 10)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_RPL_UPPEEN                ((u32)0x00000001 << 9)            /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_MASK_FORCE_RPL_UPPEVALUE        ((u32)0x000001FF << 0)            /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_RPL_UPPEVALUE(x)          (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_FORCE_RPL_UPPEVALUE(x)      ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_AX_PWR_UL_FORCE0
  * @brief
  * @{
  */
#define BIT_FORCE_RU_ALLOC_EN                 ((u32)0x00000001 << 24)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_MASK_FORCE_RU_ALLOC_VALUE         ((u32)0x000000FF << 16)           /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_RU_ALLOC_VALUE(x)           (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_FORCE_RU_ALLOC_VALUE(x)       ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_FORCE_TF_MACID_EN                 ((u32)0x00000001 << 15)           /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_MASK_FORCE_TF_MACID_VALUE         ((u32)0x0000007F << 8)            /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_TF_MACID_VALUE(x)           (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_FORCE_TF_MACID_VALUE(x)       ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_FORCE_TF_RSSI_TARGET_EN           ((u32)0x00000001 << 7)            /*!< R/W 0x0  (RTL_only)   Force input from MAC en*/
#define BIT_MASK_FORCE_TF_RSSI_TARGET_VALUE   ((u32)0x0000007F << 0)            /*!< R/W 0x0  (RTL_only)   Force input from MAC*/
#define BIT_FORCE_TF_RSSI_TARGET_VALUE(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_FORCE_TF_RSSI_TARGET_VALUE(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_NORM_FORCE2
  * @brief
  * @{
  */
#define BIT_MASK_RU_NORM_RU242          ((u32)0x000003FF << 20)           /*!< R/W 0x0  (RTL_only) S(10.4) RU_lim tbl -RU norm,0x0=0dB*/
#define BIT_RU_NORM_RU242(x)            (((u32)((x) & 0x000003FF) << 20))
#define BIT_GET_RU_NORM_RU242(x)        ((u32)(((x >> 20) & 0x000003FF)))
#define BIT_FORCE_OUT_CCA_PWR_TH_EN_ON  ((u32)0x00000001 << 18)           /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_FORCE_OUT_CCA_PWR_TH_EN     ((u32)0x00000001 << 17)           /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_CCA_PWR_TH_ON     ((u32)0x00000001 << 16)           /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_MASK_FORCE_OUT_CCA_PWR_TH   ((u32)0x000000FF << 8)            /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_FORCE_OUT_CCA_PWR_TH(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_TXPWCTRL_DBG_SEL       ((u32)0x0000003F << 0)            /*!< R/W 0x0  (RTL_only)  dbg port address*/
#define BIT_TXPWCTRL_DBG_SEL(x)         (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_TXPWCTRL_DBG_SEL(x)     ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_AX_PWR_UL_FORCE1
  * @brief
  * @{
  */
#define BIT_FORCE_OUT_CFO_COMP_ON         ((u32)0x00000001 << 31)           /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_MASK_FORCE_OUT_CFO_COMP       ((u32)0x00000007 << 28)           /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_CFO_COMP(x)         (((u32)((x) & 0x00000007) << 28))
#define BIT_GET_FORCE_OUT_CFO_COMP(x)     ((u32)(((x >> 28) & 0x00000007)))
#define BIT_FORCE_OUT_ABORT_TX_IDX_ON     ((u32)0x00000001 << 27)           /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_MASK_FORCE_OUT_ABORT_TX_IDX   ((u32)0x00000003 << 25)           /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_ABORT_TX_IDX(x)     (((u32)((x) & 0x00000003) << 25))
#define BIT_GET_FORCE_OUT_ABORT_TX_IDX(x) ((u32)(((x >> 25) & 0x00000003)))
#define BIT_FORCE_OUT_MIN_TX_PWFLAG_ON    ((u32)0x00000001 << 24)           /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_FORCE_OUT_MIN_TX_PWFLAG       ((u32)0x00000001 << 23)           /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_UPH_ON              ((u32)0x00000001 << 22)           /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_MASK_FORCE_OUT_UPH            ((u32)0x0000001F << 17)           /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_UPH(x)              (((u32)((x) & 0x0000001F) << 17))
#define BIT_GET_FORCE_OUT_UPH(x)          ((u32)(((x >> 17) & 0x0000001F)))
#define BIT_FORCE_OUT_STA_TXPWMAC_ON      ((u32)0x00000001 << 16)           /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_MASK_FORCE_OUT_STA_TXPWMAC    ((u32)0x0000003F << 10)           /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_STA_TXPWMAC(x)      (((u32)((x) & 0x0000003F) << 10))
#define BIT_GET_FORCE_OUT_STA_TXPWMAC(x)  ((u32)(((x >> 10) & 0x0000003F)))
#define BIT_FORCE_OUT_STA_TXPWBB_ON       ((u32)0x00000001 << 9)            /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_MASK_FORCE_OUT_STA_TXPWBB     ((u32)0x000001FF << 0)            /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_STA_TXPWBB(x)       (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_FORCE_OUT_STA_TXPWBB(x)   ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_AX_PWR_NORM_FORCE3
  * @brief
  * @{
  */
#define BIT_FORCE_OUT_TXAGC_BBSWING_ON              ((u32)0x00000001 << 31)           /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_MASK_FORCE_OUT_TXAGC_BBSWING            ((u32)0x0000000F << 27)           /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_TXAGC_BBSWING(x)              (((u32)((x) & 0x0000000F) << 27))
#define BIT_GET_FORCE_OUT_TXAGC_BBSWING(x)          ((u32)(((x >> 27) & 0x0000000F)))
#define BIT_FORCE_OUT_TXBIAS_ON                     ((u32)0x00000001 << 26)           /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_MASK_FORCE_OUT_TXBIAS                   ((u32)0x00000003 << 24)           /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_TXBIAS(x)                     (((u32)((x) & 0x00000003) << 24))
#define BIT_GET_FORCE_OUT_TXBIAS(x)                 ((u32)(((x >> 24) & 0x00000003)))
#define BIT_FORCE_OUT_TXPWBFON_BOOST_DB_SEG0_ON     ((u32)0x00000001 << 23)           /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_MASK_FORCE_OUT_TXPWBFON_BOOST_DB_SEG0   ((u32)0x0000001F << 18)           /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_TXPWBFON_BOOST_DB_SEG0(x)     (((u32)((x) & 0x0000001F) << 18))
#define BIT_GET_FORCE_OUT_TXPWBFON_BOOST_DB_SEG0(x) ((u32)(((x >> 18) & 0x0000001F)))
#define BIT_FORCE_OUT_TXPWBB_ON                     ((u32)0x00000001 << 17)           /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_MASK_FORCE_OUT_TXPWBB                   ((u32)0x000001FF << 8)            /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_TXPWBB(x)                     (((u32)((x) & 0x000001FF) << 8))
#define BIT_GET_FORCE_OUT_TXPWBB(x)                 ((u32)(((x >> 8) & 0x000001FF)))
#define BIT_FORCE_OUT_TXPWMAC_ON                    ((u32)0x00000001 << 6)            /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_MASK_FORCE_OUT_TXPWMAC                  ((u32)0x0000003F << 0)            /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_TXPWMAC(x)                    (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_FORCE_OUT_TXPWMAC(x)                ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_AX_PWR_NORM_FORCE4
  * @brief
  * @{
  */
#define BIT_BT_GRANT_WL_FORCE_OFF           ((u32)0x00000001 << 31)           /*!< R/W 0x0  (RTL_only)   Force off grant_wl*/
#define BIT_BT_GRANT_TX_FORCE_OFF           ((u32)0x00000001 << 30)           /*!< R/W 0x0  (RTL_only)   Force off grant_tx*/
#define BIT_BT_GRANT_RX_FORCE_OFF           ((u32)0x00000001 << 29)           /*!< R/W 0x0  (RTL_only)   Force off grant_rx*/
#define BIT_BT_GRANT_WL_VAL                 ((u32)0x00000001 << 28)           /*!< R/W 0x0  (RTL_only)   grant_wl flag=0 means coexist act*/
#define BIT_BT_GRANT_TX_VAL                 ((u32)0x00000001 << 27)           /*!< R/W 1h  (RTL_only)   grant_rx flag=1 means coexist act*/
#define BIT_BT_GRANT_RX_VAL                 ((u32)0x00000001 << 26)           /*!< R/W 1h  (RTL_only)   grant_rx flag=1 means coexist act*/
#define BIT_FORCE_OUT_SR_DCM_ON             ((u32)0x00000001 << 25)           /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_FORCE_OUT_SR_DCM                ((u32)0x00000001 << 24)           /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_SR_MCS_ON             ((u32)0x00000001 << 23)           /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_MASK_FORCE_OUT_SR_MCS           ((u32)0x00000FFF << 11)           /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_SR_MCS(x)             (((u32)((x) & 0x00000FFF) << 11))
#define BIT_GET_FORCE_OUT_SR_MCS(x)         ((u32)(((x >> 11) & 0x00000FFF)))
#define BIT_FORCE_OUT_SR_PD_THREHOLD_ON     ((u32)0x00000001 << 10)           /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_MASK_FORCE_OUT_SR_PD_THREHOLD   ((u32)0x0000003F << 4)            /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_SR_PD_THREHOLD(x)     (((u32)((x) & 0x0000003F) << 4))
#define BIT_GET_FORCE_OUT_SR_PD_THREHOLD(x) ((u32)(((x >> 4) & 0x0000003F)))
#define BIT_FORCE_OUT_CFIR_BY_RATE_OFF_ON   ((u32)0x00000001 << 3)            /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_FORCE_OUT_CFIR_BY_RATE_OFF      ((u32)0x00000001 << 2)            /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
#define BIT_FORCE_OUT_DPD_BY_RATE_OFF_ON    ((u32)0x00000001 << 1)            /*!< R/W 0x0  (RTL_only)   Force output to MAC en*/
#define BIT_FORCE_OUT_DPD_BY_RATE_OFF       ((u32)0x00000001 << 0)            /*!< R/W 0x0  (RTL_only)   Force output to MAC*/
/** @} */

/** @defgroup REG_AX_PWR_RSVD0
  * @brief
  * @{
  */
#define BIT_RU_PWR_LIM_MUX_EN    ((u32)0x00000001 << 31)           /*!< R/W 0x0  1:by_rate->macid_lim->RU_lim 0:by_rate->macid->BF0_pwlim->RU_lim*/
#define BIT_RU_NORM_EN           ((u32)0x00000001 << 30)           /*!< R/W 0x0  (RTL_only) RU_norm_enable (RTL_ONLY TEST )*/
#define BIT_MASK_RU_NORM_RU106   ((u32)0x000003FF << 20)           /*!< R/W 39h  (RTL_only) S(10.4) RU_lim tbl -RU norm,0x39=3.5625dB*/
#define BIT_RU_NORM_RU106(x)     (((u32)((x) & 0x000003FF) << 20))
#define BIT_GET_RU_NORM_RU106(x) ((u32)(((x >> 20) & 0x000003FF)))
#define BIT_MASK_RU_NORM_RU52    ((u32)0x000003FF << 10)           /*!< R/W 6Bh  (RTL_only) S(10.4) RU_lim tbl -RU norm,0x6b=6.6875dB*/
#define BIT_RU_NORM_RU52(x)      (((u32)((x) & 0x000003FF) << 10))
#define BIT_GET_RU_NORM_RU52(x)  ((u32)(((x >> 10) & 0x000003FF)))
#define BIT_MASK_RU_NORM_RU26    ((u32)0x000003FF << 0)            /*!< R/W 9Bh  (RTL_only) S(10.4) RU_lim tbl -RU norm ,0x9b=9.6875dB*/
#define BIT_RU_NORM_RU26(x)      (((u32)((x) & 0x000003FF) << 0))
#define BIT_GET_RU_NORM_RU26(x)  ((u32)(((x >> 0) & 0x000003FF)))
/** @} */

/** @defgroup REG_AX_PWR_RSVD1
  * @brief
  * @{
  */
#define BIT_STA_UL_LOG_NORM_EN                         ((u32)0x00000001 << 31)          /*!< R/W 1h  1:sta ul txpwr log norm en  0:log norm=10log(ntx)-10log(dbw)*/
#define BIT_STA_UL_INI_UPD_PHASE_DIS                   ((u32)0x00000001 << 30)          /*!< R/W 0x0  1:tst non eco bug*/
#define BIT_SRAM_RST_FORCE_VAL                         ((u32)0x00000001 << 16)          /*!< R/W 0x0  rst sram by cr*/
#define BIT_SRAM_RST_FORCE_ON                          ((u32)0x00000001 << 15)          /*!< R/W 0x0  1:rst sram by cr*/
#define BIT_MCS2TXINFO_EN                              ((u32)0x00000001 << 14)          /*!< R/W 0x0  1:txinfo_bbswing=MCS*/
#define BIT_MASK_FORCE_OUT_PWRCOM_CH20_WITH_DATA_VAL   ((u32)0x000000FF << 6)           /*!< R/W 0x0  1:force out off*/
#define BIT_FORCE_OUT_PWRCOM_CH20_WITH_DATA_VAL(x)     (((u32)((x) & 0x000000FF) << 6))
#define BIT_GET_FORCE_OUT_PWRCOM_CH20_WITH_DATA_VAL(x) ((u32)(((x >> 6) & 0x000000FF)))
#define BIT_FORCE_OUT_PWRCOM_CH20_WITH_DATA_ON         ((u32)0x00000001 << 5)           /*!< R/W 0x0  1:force out on*/
#define BIT_STA_UL_MU_OFF_DIS                          ((u32)0x00000001 << 4)           /*!< R/W 0x0  1:MU do sta_ul*/
#define BIT_PWRCOM_CH20_WITH_DATA_BIT_REV              ((u32)0x00000001 << 3)           /*!< R/W 0x0  bit rev,txpwlim*/
#define BIT_PWRCOM_CH20_WITH_DATA_BIT_INV              ((u32)0x00000001 << 2)           /*!< R/W 0x0  bit inv,txpwlim*/
#define BIT_FUNC_RST_FORCE_VAL                         ((u32)0x00000001 << 1)           /*!< R/W 1h  func rst from txpwctrl _CR*/
#define BIT_FUNC_RST_FORCE_ON                          ((u32)0x00000001 << 0)           /*!< R/W 0x0  Don't obey func rst from MAC*/
/** @} */

/** @defgroup REG_AX_PWR_RSVD2
  * @brief
  * @{
  */
#define BIT_MASK_STA_UL_LOG_NORM_BW160_1TX   ((u32)0x000000FF << 24)           /*!< R/W 0x0  s(8,2) sta ul txpwr log norm*/
#define BIT_STA_UL_LOG_NORM_BW160_1TX(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_STA_UL_LOG_NORM_BW160_1TX(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_STA_UL_LOG_NORM_BW80_1TX    ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8,2) sta ul txpwr log norm*/
#define BIT_STA_UL_LOG_NORM_BW80_1TX(x)      (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_STA_UL_LOG_NORM_BW80_1TX(x)  ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_STA_UL_LOG_NORM_BW40_1TX    ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8,2) sta ul txpwr log norm*/
#define BIT_STA_UL_LOG_NORM_BW40_1TX(x)      (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_STA_UL_LOG_NORM_BW40_1TX(x)  ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_STA_UL_LOG_NORM_BW20_1TX    ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8,2) sta ul txpwr log norm*/
#define BIT_STA_UL_LOG_NORM_BW20_1TX(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_STA_UL_LOG_NORM_BW20_1TX(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_RSVD3
  * @brief
  * @{
  */
#define BIT_MASK_STA_UL_LOG_NORM_BW160_2TX   ((u32)0x000000FF << 24)           /*!< R/W 0x0  s(8,2) sta ul txpwr log norm*/
#define BIT_STA_UL_LOG_NORM_BW160_2TX(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_STA_UL_LOG_NORM_BW160_2TX(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_STA_UL_LOG_NORM_BW80_2TX    ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8,2) sta ul txpwr log norm*/
#define BIT_STA_UL_LOG_NORM_BW80_2TX(x)      (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_STA_UL_LOG_NORM_BW80_2TX(x)  ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_STA_UL_LOG_NORM_BW40_2TX    ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8,2) sta ul txpwr log norm*/
#define BIT_STA_UL_LOG_NORM_BW40_2TX(x)      (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_STA_UL_LOG_NORM_BW40_2TX(x)  ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_STA_UL_LOG_NORM_BW20_2TX    ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8,2) sta ul txpwr log norm*/
#define BIT_STA_UL_LOG_NORM_BW20_2TX(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_STA_UL_LOG_NORM_BW20_2TX(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_RSVD4
  * @brief
  * @{
  */
#define BIT_MASK_TXBIAS_HT_TH_1       ((u32)0x0000000F << 27)           /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_HT_TH_1(x)         (((u32)((x) & 0x0000000F) << 27))
#define BIT_GET_TXBIAS_HT_TH_1(x)     ((u32)(((x >> 27) & 0x0000000F)))
#define BIT_MASK_TXBIAS_HT_TH_0       ((u32)0x0000000F << 23)           /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_HT_TH_0(x)         (((u32)((x) & 0x0000000F) << 23))
#define BIT_GET_TXBIAS_HT_TH_0(x)     ((u32)(((x >> 23) & 0x0000000F)))
#define BIT_MASK_TXBIAS_LEGACY_TH_2   ((u32)0x0000000F << 17)           /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_LEGACY_TH_2(x)     (((u32)((x) & 0x0000000F) << 17))
#define BIT_GET_TXBIAS_LEGACY_TH_2(x) ((u32)(((x >> 17) & 0x0000000F)))
#define BIT_MASK_TXBIAS_LEGACY_TH_1   ((u32)0x0000000F << 13)           /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_LEGACY_TH_1(x)     (((u32)((x) & 0x0000000F) << 13))
#define BIT_GET_TXBIAS_LEGACY_TH_1(x) ((u32)(((x >> 13) & 0x0000000F)))
#define BIT_MASK_TXBIAS_LEGACY_TH_0   ((u32)0x0000000F << 9)            /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_LEGACY_TH_0(x)     (((u32)((x) & 0x0000000F) << 9))
#define BIT_GET_TXBIAS_LEGACY_TH_0(x) ((u32)(((x >> 9) & 0x0000000F)))
#define BIT_MASK_TXBIAS_CCK_TH_2      ((u32)0x00000007 << 6)            /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_CCK_TH_2(x)        (((u32)((x) & 0x00000007) << 6))
#define BIT_GET_TXBIAS_CCK_TH_2(x)    ((u32)(((x >> 6) & 0x00000007)))
#define BIT_MASK_TXBIAS_CCK_TH_1      ((u32)0x00000007 << 3)            /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_CCK_TH_1(x)        (((u32)((x) & 0x00000007) << 3))
#define BIT_GET_TXBIAS_CCK_TH_1(x)    ((u32)(((x >> 3) & 0x00000007)))
#define BIT_MASK_TXBIAS_CCK_TH_0      ((u32)0x00000007 << 0)            /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_CCK_TH_0(x)        (((u32)((x) & 0x00000007) << 0))
#define BIT_GET_TXBIAS_CCK_TH_0(x)    ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_AX_PWR_RSVD5
  * @brief
  * @{
  */
#define BIT_MASK_TXBIAS_CCK_REGION_3   ((u32)0x00000003 << 30)           /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_CCK_REGION_3(x)     (((u32)((x) & 0x00000003) << 30))
#define BIT_GET_TXBIAS_CCK_REGION_3(x) ((u32)(((x >> 30) & 0x00000003)))
#define BIT_MASK_TXBIAS_CCK_REGION_2   ((u32)0x00000003 << 28)           /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_CCK_REGION_2(x)     (((u32)((x) & 0x00000003) << 28))
#define BIT_GET_TXBIAS_CCK_REGION_2(x) ((u32)(((x >> 28) & 0x00000003)))
#define BIT_MASK_TXBIAS_HE_TH_2        ((u32)0x0000000F << 24)           /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_HE_TH_2(x)          (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_TXBIAS_HE_TH_2(x)      ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_TXBIAS_HE_TH_1        ((u32)0x0000000F << 20)           /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_HE_TH_1(x)          (((u32)((x) & 0x0000000F) << 20))
#define BIT_GET_TXBIAS_HE_TH_1(x)      ((u32)(((x >> 20) & 0x0000000F)))
#define BIT_MASK_TXBIAS_HE_TH_0        ((u32)0x0000000F << 16)           /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_HE_TH_0(x)          (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_TXBIAS_HE_TH_0(x)      ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_TXBIAS_VHT_TH_2       ((u32)0x0000000F << 12)           /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_VHT_TH_2(x)         (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_TXBIAS_VHT_TH_2(x)     ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_TXBIAS_VHT_TH_1       ((u32)0x0000000F << 8)            /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_VHT_TH_1(x)         (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_TXBIAS_VHT_TH_1(x)     ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_TXBIAS_VHT_TH_0       ((u32)0x0000000F << 4)            /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_VHT_TH_0(x)         (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_TXBIAS_VHT_TH_0(x)     ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_TXBIAS_HT_TH_2        ((u32)0x0000000F << 0)            /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_HT_TH_2(x)          (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_TXBIAS_HT_TH_2(x)      ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_RSVD6
  * @brief
  * @{
  */
#define BIT_MASK_TXBIAS_HE_REGION_3       ((u32)0x00000003 << 14)           /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_HE_REGION_3(x)         (((u32)((x) & 0x00000003) << 14))
#define BIT_GET_TXBIAS_HE_REGION_3(x)     ((u32)(((x >> 14) & 0x00000003)))
#define BIT_MASK_TXBIAS_HE_REGION_2       ((u32)0x00000003 << 12)           /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_HE_REGION_2(x)         (((u32)((x) & 0x00000003) << 12))
#define BIT_GET_TXBIAS_HE_REGION_2(x)     ((u32)(((x >> 12) & 0x00000003)))
#define BIT_MASK_TXBIAS_VHT_REGION_3      ((u32)0x00000003 << 10)           /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_VHT_REGION_3(x)        (((u32)((x) & 0x00000003) << 10))
#define BIT_GET_TXBIAS_VHT_REGION_3(x)    ((u32)(((x >> 10) & 0x00000003)))
#define BIT_MASK_TXBIAS_VHT_REGION_2      ((u32)0x00000003 << 8)            /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_VHT_REGION_2(x)        (((u32)((x) & 0x00000003) << 8))
#define BIT_GET_TXBIAS_VHT_REGION_2(x)    ((u32)(((x >> 8) & 0x00000003)))
#define BIT_MASK_TXBIAS_HT_REGION_3       ((u32)0x00000003 << 6)            /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_HT_REGION_3(x)         (((u32)((x) & 0x00000003) << 6))
#define BIT_GET_TXBIAS_HT_REGION_3(x)     ((u32)(((x >> 6) & 0x00000003)))
#define BIT_MASK_TXBIAS_HT_REGION_2       ((u32)0x00000003 << 4)            /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_HT_REGION_2(x)         (((u32)((x) & 0x00000003) << 4))
#define BIT_GET_TXBIAS_HT_REGION_2(x)     ((u32)(((x >> 4) & 0x00000003)))
#define BIT_MASK_TXBIAS_LEGACY_REGION_3   ((u32)0x00000003 << 2)            /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_LEGACY_REGION_3(x)     (((u32)((x) & 0x00000003) << 2))
#define BIT_GET_TXBIAS_LEGACY_REGION_3(x) ((u32)(((x >> 2) & 0x00000003)))
#define BIT_MASK_TXBIAS_LEGACY_REGION_2   ((u32)0x00000003 << 0)            /*!< R/W 0x0  txbias region*/
#define BIT_TXBIAS_LEGACY_REGION_2(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_TXBIAS_LEGACY_REGION_2(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_AX_PWR_RSVD7
  * @brief
  * @{
  */
#define BIT_EN_BF_FORCE_ON                 ((u32)0x00000001 << 28)           /*!< R/W 0x0  */
#define BIT_MASK_STA_UL_UPH_OFFSET         ((u32)0x000000FF << 20)           /*!< R/W 0x0  */
#define BIT_STA_UL_UPH_OFFSET(x)           (((u32)((x) & 0x000000FF) << 20))
#define BIT_GET_STA_UL_UPH_OFFSET(x)       ((u32)(((x >> 20) & 0x000000FF)))
#define BIT_MASK_STA_UL_PWRMAX_OFFSET      ((u32)0x000000FF << 12)           /*!< R/W 0x0  */
#define BIT_STA_UL_PWRMAX_OFFSET(x)        (((u32)((x) & 0x000000FF) << 12))
#define BIT_GET_STA_UL_PWRMAX_OFFSET(x)    ((u32)(((x >> 12) & 0x000000FF)))
#define BIT_MASK_STA_UL_FORCE_PWPATH_VAL   ((u32)0x000001FF << 2)            /*!< R/W 0x0  */
#define BIT_STA_UL_FORCE_PWPATH_VAL(x)     (((u32)((x) & 0x000001FF) << 2))
#define BIT_GET_STA_UL_FORCE_PWPATH_VAL(x) ((u32)(((x >> 2) & 0x000001FF)))
#define BIT_STA_UL_FORCE_PWPATH_ON         ((u32)0x00000001 << 1)            /*!< R/W 0x0  */
#define BIT_STA_UL_FORCE_PWPATH_FROM_TXPWR ((u32)0x00000001 << 0)            /*!< R/W 0x0  */
/** @} */

/** @defgroup REG_AX_PWR_RSVD8
  * @brief
  * @{
  */
#define BIT_MASK_RU52_ALLOC_LV1           ((u32)0x0000000F << 28)           /*!< R/W 4h  txpwr by ru limit RU_id level 1 when DBW20M and RU52*/
#define BIT_RU52_ALLOC_LV1(x)             (((u32)((x) & 0x0000000F) << 28))
#define BIT_GET_RU52_ALLOC_LV1(x)         ((u32)(((x >> 28) & 0x0000000F)))
#define BIT_MASK_RU52_ALLOC_LV0           ((u32)0x0000000F << 24)           /*!< R/W 2h  txpwr by ru limit RU_id level 0 when DBW20M and RU52*/
#define BIT_RU52_ALLOC_LV0(x)             (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_RU52_ALLOC_LV0(x)         ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_RU26_ALLOC_LV1           ((u32)0x0000000F << 20)           /*!< R/W 9h  txpwr by ru limit RU_id level 1 when DBW20M and RU26*/
#define BIT_RU26_ALLOC_LV1(x)             (((u32)((x) & 0x0000000F) << 20))
#define BIT_GET_RU26_ALLOC_LV1(x)         ((u32)(((x >> 20) & 0x0000000F)))
#define BIT_MASK_RU26_ALLOC_LV0           ((u32)0x0000000F << 16)           /*!< R/W 2h  txpwr by ru limit RU_id level 0 when DBW20M and RU26*/
#define BIT_RU26_ALLOC_LV0(x)             (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_RU26_ALLOC_LV0(x)         ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_AP_TX_PWBIAS_STA_UL      ((u32)0x0000007F << 8)            /*!< R/W 0x0  */
#define BIT_AP_TX_PWBIAS_STA_UL(x)        (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_AP_TX_PWBIAS_STA_UL(x)    ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_AP_TX_PWBIAS_NORM_RESP   ((u32)0x0000007F << 0)            /*!< R/W 0x0  */
#define BIT_AP_TX_PWBIAS_NORM_RESP(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_AP_TX_PWBIAS_NORM_RESP(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_BY_RATE_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_CCK11M    ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_CCK11M(x)      (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_CCK11M(x)  ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_CCK5P5M   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_CCK5P5M(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_CCK5P5M(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_CCK2M     ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_CCK2M(x)       (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_CCK2M(x)   ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_CCK1M     ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_CCK1M(x)       (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_CCK1M(x)   ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_BY_RATE_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_LEGACY18M   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_LEGACY18M(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_LEGACY18M(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_LEGACY12M   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_LEGACY12M(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_LEGACY12M(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_LEGACY9M    ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_LEGACY9M(x)      (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_LEGACY9M(x)  ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_LEGACY6M    ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_LEGACY6M(x)      (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_LEGACY6M(x)  ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_BY_RATE_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_LEGACY54M   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_LEGACY54M(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_LEGACY54M(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_LEGACY48M   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_LEGACY48M(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_LEGACY48M(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_LEGACY36M   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_LEGACY36M(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_LEGACY36M(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_LEGACY24M   ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_LEGACY24M(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_LEGACY24M(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_BY_RATE_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_NONLEGACY_MCS3_NSS1   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS3_NSS1(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_NONLEGACY_MCS3_NSS1(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS2_NSS1   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS2_NSS1(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_NONLEGACY_MCS2_NSS1(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS1_NSS1   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS1_NSS1(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_NONLEGACY_MCS1_NSS1(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS0_NSS1   ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS0_NSS1(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_NONLEGACY_MCS0_NSS1(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_BY_RATE_TABLE4
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_NONLEGACY_MCS7_NSS1   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS7_NSS1(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_NONLEGACY_MCS7_NSS1(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS6_NSS1   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS6_NSS1(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_NONLEGACY_MCS6_NSS1(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS5_NSS1   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS5_NSS1(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_NONLEGACY_MCS5_NSS1(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS4_NSS1   ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS4_NSS1(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_NONLEGACY_MCS4_NSS1(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_BY_RATE_TABLE5
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_NONLEGACY_MCS11_1NSS   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS11_1NSS(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_NONLEGACY_MCS11_1NSS(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS10_1NSS   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS10_1NSS(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_NONLEGACY_MCS10_1NSS(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS9_NSS1    ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS9_NSS1(x)      (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_NONLEGACY_MCS9_NSS1(x)  ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS8_NSS1    ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS8_NSS1(x)      (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_NONLEGACY_MCS8_NSS1(x)  ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_BY_RATE_TABLE6
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_DCM_MCS4_NSS1   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_DCM_MCS4_NSS1(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_DCM_MCS4_NSS1(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_DCM_MCS3_NSS1   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_DCM_MCS3_NSS1(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_DCM_MCS3_NSS1(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_DCM_MCS1_NSS1   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_DCM_MCS1_NSS1(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_DCM_MCS1_NSS1(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_DCM_MCS0_NSS1   ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_DCM_MCS0_NSS1(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_DCM_MCS0_NSS1(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_BY_RATE_TABLE7
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_NONLEGACY_MCS3_2NSS   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS3_2NSS(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_NONLEGACY_MCS3_2NSS(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS2_2NSS   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS2_2NSS(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_NONLEGACY_MCS2_2NSS(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS1_2NSS   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS1_2NSS(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_NONLEGACY_MCS1_2NSS(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS0_2NSS   ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS0_2NSS(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_NONLEGACY_MCS0_2NSS(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_BY_RATE_TABLE8
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_NONLEGACY_MCS7_2NSS   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS7_2NSS(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_NONLEGACY_MCS7_2NSS(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS6_2NSS   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS6_2NSS(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_NONLEGACY_MCS6_2NSS(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS5_2NSS   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS5_2NSS(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_NONLEGACY_MCS5_2NSS(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS4_2NSS   ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS4_2NSS(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_NONLEGACY_MCS4_2NSS(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_BY_RATE_TABLE9
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_NONLEGACY_MCS11_2NSS   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS11_2NSS(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_NONLEGACY_MCS11_2NSS(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS10_2NSS   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS10_2NSS(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_NONLEGACY_MCS10_2NSS(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS9_2NSS    ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS9_2NSS(x)      (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_NONLEGACY_MCS9_2NSS(x)  ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_MCS8_2NSS    ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_MCS8_2NSS(x)      (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_NONLEGACY_MCS8_2NSS(x)  ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_BY_RATE_TABLE10
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_NONLEGACY_DCM_MCS4_2NSS   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_DCM_MCS4_2NSS(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_NONLEGACY_DCM_MCS4_2NSS(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_DCM_MCS3_2NSS   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_DCM_MCS3_2NSS(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_NONLEGACY_DCM_MCS3_2NSS(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_DCM_MCS1_2NSS   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_DCM_MCS1_2NSS(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_NONLEGACY_DCM_MCS1_2NSS(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_NONLEGACY_DCM_MCS0_2NSS   ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_NONLEGACY_DCM_MCS0_2NSS(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_NONLEGACY_DCM_MCS0_2NSS(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_CCK_BF_1TX_BW40M   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_CCK_BF_1TX_BW40M(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_CCK_BF_1TX_BW40M(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_CCK_DUP_1TX        ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_CCK_DUP_1TX(x)          (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_CCK_DUP_1TX(x)      ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_CCK_BF_1TX_BW20M   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_CCK_BF_1TX_BW20M(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_CCK_BF_1TX_BW20M(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_CCK_1TX            ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_CCK_1TX(x)              (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_CCK_1TX(x)          ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW20_0           ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW20_0(x)             (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW20_0(x)         ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW20_0              ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW20_0(x)                (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_1TX_BW20_0(x)            ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_LEGACY_NON_DUP_BF_1TX   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_LEGACY_NON_DUP_BF_1TX(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_LEGACY_NON_DUP_BF_1TX(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_LEGACY_NON_DUP_1TX      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_LEGACY_NON_DUP_1TX(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_LEGACY_NON_DUP_1TX(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW20_2   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW20_2(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW20_2(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW20_2      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW20_2(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_1TX_BW20_2(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW20_1   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW20_1(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW20_1(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW20_1      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW20_1(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_1TX_BW20_1(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW20_4   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW20_4(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW20_4(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW20_4      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW20_4(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_1TX_BW20_4(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW20_3   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW20_3(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW20_3(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW20_3      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW20_3(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_1TX_BW20_3(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE4
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW20_6   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW20_6(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW20_6(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW20_6      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW20_6(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_1TX_BW20_6(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW20_5   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW20_5(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW20_5(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW20_5      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW20_5(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_1TX_BW20_5(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE5
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW40_0   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW40_0(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW40_0(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW40_0      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW40_0(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_1TX_BW40_0(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW20_7   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW20_7(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW20_7(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW20_7      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW20_7(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_1TX_BW20_7(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE6
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW40_2   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW40_2(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW40_2(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW40_2      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW40_2(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_1TX_BW40_2(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW40_1   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW40_1(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW40_1(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW40_1      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW40_1(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_1TX_BW40_1(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE7
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW80_0   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW80_0(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW80_0(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW80_0      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW80_0(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_1TX_BW80_0(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW40_3   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW40_3(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW40_3(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW40_3      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW40_3(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_1TX_BW40_3(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE8
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW160_0   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW160_0(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW160_0(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW160_0      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW160_0(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_1TX_BW160_0(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW80_1    ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW80_1(x)      (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW80_1(x)  ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW80_1       ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW80_1(x)         (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_1TX_BW80_1(x)     ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE9
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW40_2P5   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW40_2P5(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW40_2P5(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW40_2P5      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW40_2P5(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_1TX_BW40_2P5(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BF_BW40_0P5   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BF_BW40_0P5(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_1TX_BF_BW40_0P5(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_1TX_BW40_0P5      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_1TX_BW40_0P5(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_1TX_BW40_0P5(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE10
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_CCK_BF_2TX_BW40M   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_CCK_BF_2TX_BW40M(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_CCK_BF_2TX_BW40M(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_CCK_2TX_BW40M      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_CCK_2TX_BW40M(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_CCK_2TX_BW40M(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_CCK_BF_2TX_BW20M   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_CCK_BF_2TX_BW20M(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_CCK_BF_2TX_BW20M(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_CCK_2TX_BW20M      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_CCK_2TX_BW20M(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_CCK_2TX_BW20M(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE11
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW20_0           ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW20_0(x)             (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW20_0(x)         ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW20_0              ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW20_0(x)                (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_2TX_BW20_0(x)            ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_LEGACY_NON_DUP_BF_2TX   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_LEGACY_NON_DUP_BF_2TX(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_LEGACY_NON_DUP_BF_2TX(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_LEGACY_NON_DUP_2TX      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_LEGACY_NON_DUP_2TX(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_LEGACY_NON_DUP_2TX(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE12
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW20_2   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW20_2(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW20_2(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW20_2      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW20_2(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_2TX_BW20_2(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW20_1   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW20_1(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW20_1(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW20_1      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW20_1(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_2TX_BW20_1(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE13
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW20_4   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW20_4(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW20_4(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW20_4      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW20_4(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_2TX_BW20_4(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW20_3   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW20_3(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW20_3(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW20_3      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW20_3(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_2TX_BW20_3(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE14
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW20_6   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW20_6(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW20_6(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW20_6      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW20_6(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_2TX_BW20_6(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW20_5   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW20_5(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW20_5(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW20_5      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW20_5(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_2TX_BW20_5(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE15
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW40_0   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW40_0(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW40_0(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW40_0      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW40_0(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_2TX_BW40_0(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW20_7   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW20_7(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW20_7(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW20_7      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW20_7(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_2TX_BW20_7(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE16
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW40_2   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW40_2(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW40_2(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW40_2      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW40_2(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_2TX_BW40_2(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW40_1   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW40_1(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW40_1(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW40_1      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW40_1(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_2TX_BW40_1(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE17
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW80_0   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW80_0(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW80_0(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW80_0      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW80_0(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_2TX_BW80_0(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW40_3   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW40_3(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW40_3(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW40_3      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW40_3(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_2TX_BW40_3(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE18
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW160_0   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW160_0(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW160_0(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW160_0      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW160_0(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_2TX_BW160_0(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW80_1    ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW80_1(x)      (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW80_1(x)  ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW80_1       ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW80_1(x)         (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_2TX_BW80_1(x)     ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_LMT_TABLE19
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW40_2P5   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW40_2P5(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW40_2P5(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW40_2P5      ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW40_2P5(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_MAX_2TX_BW40_2P5(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BF_BW40_0P5   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BF_BW40_0P5(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_MAX_2TX_BF_BW40_0P5(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_MAX_2TX_BW40_0P5      ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_MAX_2TX_BW40_0P5(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_MAX_2TX_BW40_0P5(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_RU_LMT_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_RU_LIM_0TX_RU26_BW160_3   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU26_BW160_3(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_RU_LIM_0TX_RU26_BW160_3(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_RU_LIM_0TX_RU26_BW160_2   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU26_BW160_2(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_RU_LIM_0TX_RU26_BW160_2(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_RU_LIM_0TX_RU26_BW160_1   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU26_BW160_1(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_RU_LIM_0TX_RU26_BW160_1(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_RU26_LV0            ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_RU26_LV0(x)              (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_RU26_LV0(x)          ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_RU_LMT_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_RU_LIM_0TX_RU26_BW160_7   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU26_BW160_7(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_RU_LIM_0TX_RU26_BW160_7(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_RU_LIM_0TX_RU26_BW160_6   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU26_BW160_6(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_RU_LIM_0TX_RU26_BW160_6(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_RU_LIM_0TX_RU26_BW160_5   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU26_BW160_5(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_RU_LIM_0TX_RU26_BW160_5(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_RU_LIM_0TX_RU26_BW160_4   ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU26_BW160_4(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_RU_LIM_0TX_RU26_BW160_4(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_RU_LMT_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_RU_LIM_0TX_RU52_BW160_3   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU52_BW160_3(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_RU_LIM_0TX_RU52_BW160_3(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_RU_LIM_0TX_RU52_BW160_2   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU52_BW160_2(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_RU_LIM_0TX_RU52_BW160_2(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_RU_LIM_0TX_RU52_BW160_1   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU52_BW160_1(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_RU_LIM_0TX_RU52_BW160_1(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_RU52_LV0            ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_RU52_LV0(x)              (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_RU52_LV0(x)          ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_RU_LMT_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_RU_LIM_0TX_RU52_BW160_7   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU52_BW160_7(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_RU_LIM_0TX_RU52_BW160_7(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_RU_LIM_0TX_RU52_BW160_6   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU52_BW160_6(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_RU_LIM_0TX_RU52_BW160_6(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_RU_LIM_0TX_RU52_BW160_5   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU52_BW160_5(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_RU_LIM_0TX_RU52_BW160_5(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_RU_LIM_0TX_RU52_BW160_4   ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU52_BW160_4(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_RU_LIM_0TX_RU52_BW160_4(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_RU_LMT_TABLE4
  * @brief
  * @{
  */
#define BIT_MASK_RU_LIM_0TX_RU106_BW160_3   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU106_BW160_3(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_RU_LIM_0TX_RU106_BW160_3(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_RU_LIM_0TX_RU106_BW160_2   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU106_BW160_2(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_RU_LIM_0TX_RU106_BW160_2(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_RU_LIM_0TX_RU106_BW160_1   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU106_BW160_1(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_RU_LIM_0TX_RU106_BW160_1(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_RU106_LV0            ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_RU106_LV0(x)              (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_RU106_LV0(x)          ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_RU_LMT_TABLE5
  * @brief
  * @{
  */
#define BIT_MASK_RU_LIM_0TX_RU106_BW160_7   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU106_BW160_7(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_RU_LIM_0TX_RU106_BW160_7(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_RU_LIM_0TX_RU106_BW160_6   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU106_BW160_6(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_RU_LIM_0TX_RU106_BW160_6(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_RU_LIM_0TX_RU106_BW160_5   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU106_BW160_5(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_RU_LIM_0TX_RU106_BW160_5(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_RU_LIM_0TX_RU106_BW160_4   ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_0TX_RU106_BW160_4(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_RU_LIM_0TX_RU106_BW160_4(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_RU_LMT_TABLE6
  * @brief
  * @{
  */
#define BIT_MASK_TXAGC_RU52_LV2   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_RU52_LV2(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_TXAGC_RU52_LV2(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_TXAGC_RU52_LV1   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_RU52_LV1(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXAGC_RU52_LV1(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_RU26_LV2   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_RU26_LV2(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_RU26_LV2(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_RU26_LV1   ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_RU26_LV1(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_RU26_LV1(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_RU_LMT_TABLE7
  * @brief
  * @{
  */
#define BIT_MASK_RU_LIM_1TX_RU26_BW160_7   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU26_BW160_7(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_RU_LIM_1TX_RU26_BW160_7(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_RU_LIM_1TX_RU26_BW160_6   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU26_BW160_6(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_RU_LIM_1TX_RU26_BW160_6(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_TXAGC_RU242_LV0           ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_RU242_LV0(x)             (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXAGC_RU242_LV0(x)         ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXAGC_RU106_LV1           ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_TXAGC_RU106_LV1(x)             (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXAGC_RU106_LV1(x)         ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_RU_LMT_TABLE8
  * @brief
  * @{
  */
#define BIT_MASK_RU_LIM_1TX_RU52_BW160_3   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU52_BW160_3(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_RU_LIM_1TX_RU52_BW160_3(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_RU_LIM_1TX_RU52_BW160_2   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU52_BW160_2(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_RU_LIM_1TX_RU52_BW160_2(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_RU_LIM_1TX_RU52_BW160_1   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU52_BW160_1(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_RU_LIM_1TX_RU52_BW160_1(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_RU_LIM_1TX_RU52_BW160_0   ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU52_BW160_0(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_RU_LIM_1TX_RU52_BW160_0(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_RU_LMT_TABLE9
  * @brief
  * @{
  */
#define BIT_MASK_RU_LIM_1TX_RU52_BW160_7   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU52_BW160_7(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_RU_LIM_1TX_RU52_BW160_7(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_RU_LIM_1TX_RU52_BW160_6   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU52_BW160_6(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_RU_LIM_1TX_RU52_BW160_6(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_RU_LIM_1TX_RU52_BW160_5   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU52_BW160_5(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_RU_LIM_1TX_RU52_BW160_5(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_RU_LIM_1TX_RU52_BW160_4   ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU52_BW160_4(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_RU_LIM_1TX_RU52_BW160_4(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_RU_LMT_TABLE10
  * @brief
  * @{
  */
#define BIT_MASK_RU_LIM_1TX_RU106_BW160_3   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU106_BW160_3(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_RU_LIM_1TX_RU106_BW160_3(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_RU_LIM_1TX_RU106_BW160_2   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU106_BW160_2(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_RU_LIM_1TX_RU106_BW160_2(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_RU_LIM_1TX_RU106_BW160_1   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU106_BW160_1(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_RU_LIM_1TX_RU106_BW160_1(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_RU_LIM_1TX_RU106_BW160_0   ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU106_BW160_0(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_RU_LIM_1TX_RU106_BW160_0(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_RU_LMT_TABLE11
  * @brief
  * @{
  */
#define BIT_MASK_RU_LIM_1TX_RU106_BW160_7   ((u32)0x0000007F << 24)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU106_BW160_7(x)     (((u32)((x) & 0x0000007F) << 24))
#define BIT_GET_RU_LIM_1TX_RU106_BW160_7(x) ((u32)(((x >> 24) & 0x0000007F)))
#define BIT_MASK_RU_LIM_1TX_RU106_BW160_6   ((u32)0x0000007F << 16)           /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU106_BW160_6(x)     (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_RU_LIM_1TX_RU106_BW160_6(x) ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_MASK_RU_LIM_1TX_RU106_BW160_5   ((u32)0x0000007F << 8)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU106_BW160_5(x)     (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_RU_LIM_1TX_RU106_BW160_5(x) ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_RU_LIM_1TX_RU106_BW160_4   ((u32)0x0000007F << 0)            /*!< R/W 0x0  s(7.1)*/
#define BIT_RU_LIM_1TX_RU106_BW160_4(x)     (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_RU_LIM_1TX_RU106_BW160_4(x) ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLEx
  * @brief
  * @{
  */
#define BIT_MACIDx_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACIDx_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACIDx_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACIDx_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACIDx_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACIDx_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACIDx_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACIDx_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACIDx_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACIDx_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACIDx_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACIDx_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE0
  * @brief
  * @{
  */
#define BIT_MACID0_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID0_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID0_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID0_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID0_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID0_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID0_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID0_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID0_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID0_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID0_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID0_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE1
  * @brief
  * @{
  */
#define BIT_MACID1_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID1_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID1_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID1_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID1_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID1_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID1_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID1_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID1_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID1_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID1_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID1_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE2
  * @brief
  * @{
  */
#define BIT_MACID2_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID2_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID2_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID2_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID2_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID2_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID2_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID2_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID2_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID2_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID2_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID2_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE3
  * @brief
  * @{
  */
#define BIT_MACID3_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID3_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID3_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID3_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID3_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID3_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID3_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID3_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID3_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID3_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID3_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID3_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE4
  * @brief
  * @{
  */
#define BIT_MACID4_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID4_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID4_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID4_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID4_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID4_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID4_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID4_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID4_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID4_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID4_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID4_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE5
  * @brief
  * @{
  */
#define BIT_MACID5_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID5_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID5_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID5_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID5_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID5_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID5_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID5_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID5_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID5_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID5_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID5_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE6
  * @brief
  * @{
  */
#define BIT_MACID6_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID6_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID6_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID6_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID6_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID6_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID6_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID6_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID6_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID6_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID6_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID6_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE7
  * @brief
  * @{
  */
#define BIT_MACID7_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID7_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID7_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID7_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID7_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID7_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID7_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID7_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID7_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID7_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID7_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID7_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE8
  * @brief
  * @{
  */
#define BIT_MACID8_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID8_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID8_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID8_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID8_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID8_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID8_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID8_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID8_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID8_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID8_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID8_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE9
  * @brief
  * @{
  */
#define BIT_MACID9_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID9_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID9_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID9_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID9_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID9_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID9_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID9_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID9_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID9_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID9_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID9_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE10
  * @brief
  * @{
  */
#define BIT_MACID10_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID10_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID10_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID10_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID10_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID10_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID10_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID10_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID10_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID10_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID10_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID10_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE11
  * @brief
  * @{
  */
#define BIT_MACID11_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID11_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID11_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID11_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID11_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID11_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID11_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID11_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID11_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID11_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID11_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID11_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE12
  * @brief
  * @{
  */
#define BIT_MACID12_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID12_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID12_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID12_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID12_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID12_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID12_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID12_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID12_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID12_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID12_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID12_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE13
  * @brief
  * @{
  */
#define BIT_MACID13_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID13_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID13_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID13_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID13_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID13_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID13_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID13_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID13_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID13_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID13_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID13_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE14
  * @brief
  * @{
  */
#define BIT_MACID14_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID14_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID14_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID14_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID14_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID14_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID14_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID14_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID14_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID14_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID14_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID14_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE15
  * @brief
  * @{
  */
#define BIT_MACID15_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID15_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID15_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID15_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID15_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID15_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID15_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID15_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID15_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID15_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID15_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID15_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE16
  * @brief
  * @{
  */
#define BIT_MACID16_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID16_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID16_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID16_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID16_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID16_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID16_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID16_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID16_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID16_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID16_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID16_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE17
  * @brief
  * @{
  */
#define BIT_MACID17_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID17_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID17_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID17_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID17_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID17_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID17_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID17_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID17_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID17_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID17_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID17_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE18
  * @brief
  * @{
  */
#define BIT_MACID18_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID18_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID18_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID18_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID18_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID18_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID18_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID18_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID18_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID18_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID18_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID18_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE19
  * @brief
  * @{
  */
#define BIT_MACID19_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID19_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID19_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID19_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID19_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID19_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID19_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID19_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID19_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID19_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID19_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID19_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE20
  * @brief
  * @{
  */
#define BIT_MACID20_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID20_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID20_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID20_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID20_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID20_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID20_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID20_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID20_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID20_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID20_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID20_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE21
  * @brief
  * @{
  */
#define BIT_MACID21_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID21_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID21_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID21_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID21_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID21_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID21_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID21_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID21_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID21_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID21_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID21_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE22
  * @brief
  * @{
  */
#define BIT_MACID22_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID22_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID22_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID22_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID22_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID22_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID22_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID22_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID22_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID22_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID22_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID22_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE23
  * @brief
  * @{
  */
#define BIT_MACID23_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID23_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID23_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID23_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID23_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID23_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID23_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID23_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID23_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID23_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID23_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID23_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE24
  * @brief
  * @{
  */
#define BIT_MACID24_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID24_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID24_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID24_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID24_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID24_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID24_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID24_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID24_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID24_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID24_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID24_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE25
  * @brief
  * @{
  */
#define BIT_MACID25_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID25_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID25_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID25_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID25_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID25_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID25_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID25_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID25_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID25_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID25_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID25_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE26
  * @brief
  * @{
  */
#define BIT_MACID26_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID26_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID26_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID26_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID26_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID26_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID26_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID26_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID26_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID26_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID26_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID26_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE27
  * @brief
  * @{
  */
#define BIT_MACID27_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID27_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID27_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID27_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID27_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID27_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID27_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID27_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID27_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID27_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID27_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID27_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE28
  * @brief
  * @{
  */
#define BIT_MACID28_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID28_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID28_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID28_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID28_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID28_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID28_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID28_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID28_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID28_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID28_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID28_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE29
  * @brief
  * @{
  */
#define BIT_MACID29_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID29_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID29_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID29_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID29_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID29_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID29_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID29_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID29_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID29_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID29_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID29_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE30
  * @brief
  * @{
  */
#define BIT_MACID30_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID30_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID30_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID30_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID30_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID30_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID30_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID30_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID30_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID30_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID30_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID30_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE31
  * @brief
  * @{
  */
#define BIT_MACID31_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID31_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID31_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID31_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID31_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID31_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID31_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID31_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID31_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID31_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID31_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID31_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE32
  * @brief
  * @{
  */
#define BIT_MACID32_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID32_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID32_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID32_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID32_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID32_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID32_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID32_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID32_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID32_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID32_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID32_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE33
  * @brief
  * @{
  */
#define BIT_MACID33_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID33_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID33_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID33_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID33_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID33_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID33_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID33_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID33_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID33_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID33_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID33_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE34
  * @brief
  * @{
  */
#define BIT_MACID34_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID34_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID34_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID34_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID34_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID34_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID34_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID34_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID34_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID34_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID34_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID34_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE35
  * @brief
  * @{
  */
#define BIT_MACID35_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID35_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID35_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID35_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID35_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID35_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID35_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID35_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID35_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID35_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID35_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID35_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE36
  * @brief
  * @{
  */
#define BIT_MACID36_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID36_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID36_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID36_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID36_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID36_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID36_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID36_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID36_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID36_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID36_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID36_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE37
  * @brief
  * @{
  */
#define BIT_MACID37_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID37_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID37_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID37_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID37_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID37_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID37_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID37_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID37_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID37_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID37_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID37_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE38
  * @brief
  * @{
  */
#define BIT_MACID38_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID38_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID38_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID38_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID38_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID38_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID38_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID38_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID38_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID38_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID38_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID38_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE39
  * @brief
  * @{
  */
#define BIT_MACID39_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID39_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID39_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID39_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID39_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID39_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID39_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID39_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID39_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID39_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID39_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID39_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE40
  * @brief
  * @{
  */
#define BIT_MACID40_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID40_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID40_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID40_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID40_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID40_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID40_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID40_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID40_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID40_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID40_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID40_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE41
  * @brief
  * @{
  */
#define BIT_MACID41_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID41_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID41_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID41_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID41_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID41_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID41_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID41_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID41_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID41_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID41_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID41_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE42
  * @brief
  * @{
  */
#define BIT_MACID42_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID42_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID42_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID42_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID42_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID42_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID42_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID42_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID42_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID42_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID42_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID42_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE43
  * @brief
  * @{
  */
#define BIT_MACID43_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID43_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID43_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID43_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID43_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID43_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID43_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID43_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID43_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID43_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID43_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID43_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE44
  * @brief
  * @{
  */
#define BIT_MACID44_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID44_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID44_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID44_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID44_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID44_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID44_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID44_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID44_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID44_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID44_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID44_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE45
  * @brief
  * @{
  */
#define BIT_MACID45_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID45_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID45_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID45_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID45_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID45_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID45_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID45_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID45_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID45_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID45_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID45_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE46
  * @brief
  * @{
  */
#define BIT_MACID46_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID46_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID46_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID46_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID46_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID46_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID46_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID46_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID46_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID46_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID46_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID46_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE47
  * @brief
  * @{
  */
#define BIT_MACID47_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID47_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID47_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID47_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID47_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID47_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID47_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID47_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID47_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID47_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID47_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID47_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE48
  * @brief
  * @{
  */
#define BIT_MACID48_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID48_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID48_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID48_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID48_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID48_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID48_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID48_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID48_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID48_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID48_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID48_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE49
  * @brief
  * @{
  */
#define BIT_MACID49_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID49_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID49_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID49_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID49_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID49_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID49_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID49_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID49_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID49_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID49_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID49_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE50
  * @brief
  * @{
  */
#define BIT_MACID50_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID50_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID50_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID50_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID50_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID50_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID50_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID50_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID50_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID50_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID50_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID50_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE51
  * @brief
  * @{
  */
#define BIT_MACID51_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID51_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID51_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID51_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID51_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID51_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID51_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID51_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID51_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID51_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID51_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID51_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE52
  * @brief
  * @{
  */
#define BIT_MACID52_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID52_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID52_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID52_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID52_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID52_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID52_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID52_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID52_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID52_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID52_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID52_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE53
  * @brief
  * @{
  */
#define BIT_MACID53_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID53_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID53_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID53_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID53_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID53_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID53_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID53_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID53_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID53_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID53_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID53_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE54
  * @brief
  * @{
  */
#define BIT_MACID54_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID54_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID54_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID54_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID54_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID54_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID54_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID54_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID54_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID54_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID54_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID54_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE55
  * @brief
  * @{
  */
#define BIT_MACID55_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID55_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID55_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID55_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID55_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID55_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID55_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID55_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID55_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID55_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID55_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID55_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE56
  * @brief
  * @{
  */
#define BIT_MACID56_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID56_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID56_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID56_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID56_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID56_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID56_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID56_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID56_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID56_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID56_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID56_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE57
  * @brief
  * @{
  */
#define BIT_MACID57_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID57_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID57_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID57_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID57_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID57_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID57_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID57_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID57_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID57_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID57_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID57_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE58
  * @brief
  * @{
  */
#define BIT_MACID58_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID58_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID58_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID58_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID58_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID58_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID58_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID58_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID58_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID58_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID58_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID58_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE59
  * @brief
  * @{
  */
#define BIT_MACID59_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID59_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID59_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID59_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID59_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID59_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID59_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID59_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID59_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID59_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID59_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID59_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE60
  * @brief
  * @{
  */
#define BIT_MACID60_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID60_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID60_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID60_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID60_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID60_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID60_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID60_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID60_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID60_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID60_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID60_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE61
  * @brief
  * @{
  */
#define BIT_MACID61_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID61_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID61_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID61_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID61_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID61_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID61_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID61_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID61_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID61_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID61_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID61_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE62
  * @brief
  * @{
  */
#define BIT_MACID62_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID62_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID62_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID62_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID62_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID62_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID62_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID62_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID62_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID62_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID62_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID62_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE63
  * @brief
  * @{
  */
#define BIT_MACID63_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID63_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID63_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID63_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID63_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID63_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID63_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID63_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID63_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID63_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID63_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID63_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE64
  * @brief
  * @{
  */
#define BIT_MACID64_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID64_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID64_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID64_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID64_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID64_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID64_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID64_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID64_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID64_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID64_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID64_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE65
  * @brief
  * @{
  */
#define BIT_MACID65_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID65_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID65_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID65_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID65_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID65_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID65_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID65_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID65_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID65_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID65_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID65_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE66
  * @brief
  * @{
  */
#define BIT_MACID66_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID66_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID66_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID66_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID66_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID66_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID66_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID66_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID66_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID66_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID66_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID66_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE67
  * @brief
  * @{
  */
#define BIT_MACID67_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID67_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID67_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID67_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID67_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID67_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID67_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID67_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID67_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID67_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID67_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID67_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE68
  * @brief
  * @{
  */
#define BIT_MACID68_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID68_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID68_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID68_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID68_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID68_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID68_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID68_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID68_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID68_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID68_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID68_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE69
  * @brief
  * @{
  */
#define BIT_MACID69_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID69_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID69_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID69_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID69_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID69_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID69_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID69_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID69_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID69_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID69_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID69_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE70
  * @brief
  * @{
  */
#define BIT_MACID70_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID70_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID70_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID70_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID70_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID70_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID70_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID70_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID70_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID70_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID70_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID70_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE71
  * @brief
  * @{
  */
#define BIT_MACID71_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID71_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID71_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID71_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID71_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID71_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID71_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID71_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID71_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID71_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID71_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID71_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE72
  * @brief
  * @{
  */
#define BIT_MACID72_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID72_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID72_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID72_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID72_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID72_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID72_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID72_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID72_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID72_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID72_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID72_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE73
  * @brief
  * @{
  */
#define BIT_MACID73_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID73_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID73_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID73_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID73_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID73_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID73_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID73_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID73_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID73_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID73_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID73_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE74
  * @brief
  * @{
  */
#define BIT_MACID74_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID74_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID74_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID74_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID74_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID74_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID74_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID74_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID74_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID74_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID74_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID74_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE75
  * @brief
  * @{
  */
#define BIT_MACID75_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID75_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID75_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID75_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID75_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID75_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID75_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID75_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID75_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID75_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID75_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID75_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE76
  * @brief
  * @{
  */
#define BIT_MACID76_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID76_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID76_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID76_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID76_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID76_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID76_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID76_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID76_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID76_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID76_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID76_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE77
  * @brief
  * @{
  */
#define BIT_MACID77_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID77_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID77_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID77_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID77_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID77_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID77_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID77_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID77_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID77_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID77_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID77_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE78
  * @brief
  * @{
  */
#define BIT_MACID78_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID78_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID78_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID78_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID78_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID78_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID78_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID78_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID78_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID78_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID78_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID78_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE79
  * @brief
  * @{
  */
#define BIT_MACID79_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID79_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID79_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID79_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID79_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID79_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID79_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID79_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID79_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID79_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID79_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID79_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE80
  * @brief
  * @{
  */
#define BIT_MACID80_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID80_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID80_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID80_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID80_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID80_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID80_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID80_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID80_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID80_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID80_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID80_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE81
  * @brief
  * @{
  */
#define BIT_MACID81_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID81_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID81_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID81_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID81_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID81_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID81_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID81_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID81_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID81_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID81_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID81_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE82
  * @brief
  * @{
  */
#define BIT_MACID82_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID82_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID82_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID82_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID82_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID82_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID82_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID82_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID82_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID82_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID82_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID82_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE83
  * @brief
  * @{
  */
#define BIT_MACID83_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID83_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID83_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID83_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID83_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID83_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID83_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID83_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID83_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID83_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID83_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID83_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE84
  * @brief
  * @{
  */
#define BIT_MACID84_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID84_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID84_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID84_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID84_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID84_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID84_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID84_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID84_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID84_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID84_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID84_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE85
  * @brief
  * @{
  */
#define BIT_MACID85_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID85_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID85_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID85_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID85_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID85_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID85_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID85_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID85_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID85_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID85_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID85_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE86
  * @brief
  * @{
  */
#define BIT_MACID86_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID86_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID86_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID86_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID86_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID86_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID86_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID86_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID86_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID86_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID86_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID86_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE87
  * @brief
  * @{
  */
#define BIT_MACID87_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID87_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID87_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID87_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID87_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID87_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID87_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID87_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID87_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID87_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID87_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID87_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE88
  * @brief
  * @{
  */
#define BIT_MACID88_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID88_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID88_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID88_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID88_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID88_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID88_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID88_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID88_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID88_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID88_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID88_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE89
  * @brief
  * @{
  */
#define BIT_MACID89_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID89_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID89_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID89_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID89_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID89_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID89_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID89_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID89_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID89_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID89_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID89_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE90
  * @brief
  * @{
  */
#define BIT_MACID90_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID90_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID90_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID90_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID90_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID90_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID90_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID90_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID90_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID90_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID90_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID90_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE91
  * @brief
  * @{
  */
#define BIT_MACID91_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID91_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID91_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID91_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID91_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID91_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID91_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID91_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID91_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID91_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID91_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID91_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE92
  * @brief
  * @{
  */
#define BIT_MACID92_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID92_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID92_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID92_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID92_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID92_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID92_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID92_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID92_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID92_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID92_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID92_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE93
  * @brief
  * @{
  */
#define BIT_MACID93_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID93_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID93_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID93_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID93_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID93_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID93_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID93_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID93_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID93_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID93_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID93_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE94
  * @brief
  * @{
  */
#define BIT_MACID94_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID94_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID94_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID94_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID94_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID94_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID94_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID94_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID94_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID94_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID94_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID94_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE95
  * @brief
  * @{
  */
#define BIT_MACID95_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID95_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID95_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID95_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID95_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID95_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID95_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID95_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID95_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID95_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID95_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID95_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE96
  * @brief
  * @{
  */
#define BIT_MACID96_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID96_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID96_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID96_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID96_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID96_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID96_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID96_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID96_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID96_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID96_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID96_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE97
  * @brief
  * @{
  */
#define BIT_MACID97_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID97_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID97_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID97_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID97_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID97_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID97_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID97_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID97_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID97_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID97_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID97_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE98
  * @brief
  * @{
  */
#define BIT_MACID98_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID98_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID98_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID98_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID98_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID98_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID98_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID98_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID98_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID98_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID98_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID98_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE99
  * @brief
  * @{
  */
#define BIT_MACID99_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID99_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID99_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID99_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID99_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID99_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID99_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID99_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID99_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID99_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID99_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID99_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE100
  * @brief
  * @{
  */
#define BIT_MACID100_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID100_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID100_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID100_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID100_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID100_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID100_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID100_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID100_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID100_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID100_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID100_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE101
  * @brief
  * @{
  */
#define BIT_MACID101_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID101_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID101_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID101_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID101_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID101_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID101_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID101_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID101_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID101_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID101_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID101_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE102
  * @brief
  * @{
  */
#define BIT_MACID102_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID102_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID102_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID102_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID102_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID102_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID102_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID102_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID102_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID102_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID102_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID102_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE103
  * @brief
  * @{
  */
#define BIT_MACID103_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID103_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID103_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID103_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID103_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID103_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID103_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID103_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID103_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID103_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID103_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID103_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE104
  * @brief
  * @{
  */
#define BIT_MACID104_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID104_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID104_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID104_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID104_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID104_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID104_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID104_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID104_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID104_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID104_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID104_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE105
  * @brief
  * @{
  */
#define BIT_MACID105_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID105_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID105_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID105_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID105_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID105_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID105_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID105_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID105_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID105_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID105_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID105_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE106
  * @brief
  * @{
  */
#define BIT_MACID106_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID106_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID106_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID106_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID106_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID106_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID106_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID106_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID106_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID106_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID106_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID106_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE107
  * @brief
  * @{
  */
#define BIT_MACID107_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID107_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID107_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID107_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID107_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID107_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID107_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID107_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID107_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID107_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID107_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID107_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE108
  * @brief
  * @{
  */
#define BIT_MACID108_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID108_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID108_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID108_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID108_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID108_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID108_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID108_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID108_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID108_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID108_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID108_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE109
  * @brief
  * @{
  */
#define BIT_MACID109_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID109_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID109_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID109_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID109_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID109_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID109_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID109_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID109_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID109_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID109_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID109_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE110
  * @brief
  * @{
  */
#define BIT_MACID110_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID110_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID110_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID110_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID110_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID110_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID110_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID110_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID110_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID110_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID110_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID110_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE111
  * @brief
  * @{
  */
#define BIT_MACID111_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID111_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID111_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID111_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID111_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID111_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID111_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID111_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID111_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID111_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID111_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID111_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE112
  * @brief
  * @{
  */
#define BIT_MACID112_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID112_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID112_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID112_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID112_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID112_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID112_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID112_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID112_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID112_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID112_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID112_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE113
  * @brief
  * @{
  */
#define BIT_MACID113_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID113_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID113_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID113_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID113_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID113_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID113_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID113_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID113_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID113_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID113_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID113_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE114
  * @brief
  * @{
  */
#define BIT_MACID114_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID114_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID114_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID114_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID114_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID114_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID114_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID114_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID114_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID114_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID114_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID114_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE115
  * @brief
  * @{
  */
#define BIT_MACID115_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID115_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID115_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID115_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID115_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID115_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID115_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID115_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID115_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID115_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID115_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID115_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE116
  * @brief
  * @{
  */
#define BIT_MACID116_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID116_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID116_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID116_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID116_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID116_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID116_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID116_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID116_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID116_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID116_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID116_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE117
  * @brief
  * @{
  */
#define BIT_MACID117_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID117_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID117_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID117_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID117_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID117_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID117_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID117_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID117_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID117_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID117_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID117_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE118
  * @brief
  * @{
  */
#define BIT_MACID118_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID118_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID118_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID118_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID118_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID118_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID118_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID118_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID118_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID118_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID118_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID118_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE119
  * @brief
  * @{
  */
#define BIT_MACID119_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID119_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID119_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID119_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID119_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID119_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID119_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID119_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID119_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID119_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID119_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID119_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE120
  * @brief
  * @{
  */
#define BIT_MACID120_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID120_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID120_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID120_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID120_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID120_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID120_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID120_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID120_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID120_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID120_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID120_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE121
  * @brief
  * @{
  */
#define BIT_MACID121_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID121_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID121_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID121_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID121_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID121_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID121_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID121_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID121_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID121_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID121_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID121_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE122
  * @brief
  * @{
  */
#define BIT_MACID122_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID122_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID122_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID122_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID122_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID122_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID122_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID122_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID122_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID122_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID122_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID122_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE123
  * @brief
  * @{
  */
#define BIT_MACID123_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID123_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID123_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID123_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID123_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID123_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID123_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID123_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID123_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID123_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID123_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID123_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE124
  * @brief
  * @{
  */
#define BIT_MACID124_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID124_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID124_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID124_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID124_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID124_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID124_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID124_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID124_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID124_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID124_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID124_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE125
  * @brief
  * @{
  */
#define BIT_MACID125_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID125_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID125_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID125_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID125_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID125_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID125_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID125_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID125_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID125_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID125_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID125_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE126
  * @brief
  * @{
  */
#define BIT_MACID126_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID126_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID126_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID126_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID126_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID126_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID126_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID126_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID126_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID126_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID126_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID126_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_MACID_LMT_TABLE127
  * @brief
  * @{
  */
#define BIT_MACID127_CCA_PWR_TH_EN     ((u32)0x00000001 << 26)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID127_TXPWR1_EN         ((u32)0x00000001 << 25)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MACID127_TXPWR0_EN         ((u32)0x00000001 << 24)           /*!< R/W 0x0  u(1.0)*/
#define BIT_MASK_MACID127_CCA_PWR_TH   ((u32)0x000000FF << 16)           /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID127_CCA_PWR_TH(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_MACID127_CCA_PWR_TH(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_MACID127_TXPWR1       ((u32)0x000000FF << 8)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID127_TXPWR1(x)         (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_MACID127_TXPWR1(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MACID127_TXPWR0       ((u32)0x000000FF << 0)            /*!< R/W 0x0  s(8.1)*/
#define BIT_MACID127_TXPWR0(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MACID127_TXPWR0(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCSx_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_MCSx_TXDIFF_5DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_5DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCSx_TXDIFF_5DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCSx_TXDIFF_4DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_4DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCSx_TXDIFF_4DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCSx_TXDIFF_3DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_3DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCSx_TXDIFF_3DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCSx_TXDIFF_2DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_2DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCSx_TXDIFF_2DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCSx_TXDIFF_1DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_1DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCSx_TXDIFF_1DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCSx_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_MCSx_TXDIFF_10DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_10DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCSx_TXDIFF_10DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCSx_TXDIFF_9DB_MCS_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_9DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCSx_TXDIFF_9DB_MCS_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCSx_TXDIFF_8DB_MCS_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_8DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCSx_TXDIFF_8DB_MCS_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCSx_TXDIFF_7DB_MCS_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_7DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCSx_TXDIFF_7DB_MCS_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCSx_TXDIFF_6DB_MCS_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_6DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCSx_TXDIFF_6DB_MCS_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCSx_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_MCSx_TXDIFF_15DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_15DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCSx_TXDIFF_15DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCSx_TXDIFF_14DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_14DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCSx_TXDIFF_14DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCSx_TXDIFF_13DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_13DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCSx_TXDIFF_13DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCSx_TXDIFF_12DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_12DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCSx_TXDIFF_12DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCSx_TXDIFF_11DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_11DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCSx_TXDIFF_11DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCSx_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_MCSx_TXDIFF_20DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_20DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCSx_TXDIFF_20DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCSx_TXDIFF_19DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_19DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCSx_TXDIFF_19DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCSx_TXDIFF_18DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_18DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCSx_TXDIFF_18DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCSx_TXDIFF_17DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_17DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCSx_TXDIFF_17DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCSx_TXDIFF_16DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCSx_TXDIFF_16DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCSx_TXDIFF_16DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS0_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_MCS0_TXDIFF_5DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_5DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS0_TXDIFF_5DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS0_TXDIFF_4DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_4DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS0_TXDIFF_4DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS0_TXDIFF_3DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_3DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS0_TXDIFF_3DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS0_TXDIFF_2DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_2DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS0_TXDIFF_2DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS0_TXDIFF_1DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_1DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS0_TXDIFF_1DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS0_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_MCS0_TXDIFF_10DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_10DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS0_TXDIFF_10DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS0_TXDIFF_9DB_MCS_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_9DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS0_TXDIFF_9DB_MCS_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS0_TXDIFF_8DB_MCS_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_8DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS0_TXDIFF_8DB_MCS_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS0_TXDIFF_7DB_MCS_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_7DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS0_TXDIFF_7DB_MCS_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS0_TXDIFF_6DB_MCS_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_6DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS0_TXDIFF_6DB_MCS_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS0_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_MCS0_TXDIFF_15DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_15DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS0_TXDIFF_15DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS0_TXDIFF_14DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_14DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS0_TXDIFF_14DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS0_TXDIFF_13DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_13DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS0_TXDIFF_13DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS0_TXDIFF_12DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_12DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS0_TXDIFF_12DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS0_TXDIFF_11DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_11DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS0_TXDIFF_11DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS0_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_MCS0_TXDIFF_20DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_20DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS0_TXDIFF_20DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS0_TXDIFF_19DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_19DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS0_TXDIFF_19DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS0_TXDIFF_18DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_18DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS0_TXDIFF_18DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS0_TXDIFF_17DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_17DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS0_TXDIFF_17DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS0_TXDIFF_16DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS0_TXDIFF_16DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS0_TXDIFF_16DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS1_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_MCS1_TXDIFF_5DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_5DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS1_TXDIFF_5DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS1_TXDIFF_4DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_4DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS1_TXDIFF_4DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS1_TXDIFF_3DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_3DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS1_TXDIFF_3DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS1_TXDIFF_2DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_2DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS1_TXDIFF_2DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS1_TXDIFF_1DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_1DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS1_TXDIFF_1DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS1_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_MCS1_TXDIFF_10DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_10DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS1_TXDIFF_10DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS1_TXDIFF_9DB_MCS_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_9DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS1_TXDIFF_9DB_MCS_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS1_TXDIFF_8DB_MCS_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_8DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS1_TXDIFF_8DB_MCS_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS1_TXDIFF_7DB_MCS_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_7DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS1_TXDIFF_7DB_MCS_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS1_TXDIFF_6DB_MCS_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_6DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS1_TXDIFF_6DB_MCS_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS1_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_MCS1_TXDIFF_15DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_15DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS1_TXDIFF_15DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS1_TXDIFF_14DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_14DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS1_TXDIFF_14DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS1_TXDIFF_13DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_13DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS1_TXDIFF_13DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS1_TXDIFF_12DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_12DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS1_TXDIFF_12DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS1_TXDIFF_11DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_11DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS1_TXDIFF_11DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS1_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_MCS1_TXDIFF_20DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_20DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS1_TXDIFF_20DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS1_TXDIFF_19DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_19DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS1_TXDIFF_19DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS1_TXDIFF_18DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_18DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS1_TXDIFF_18DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS1_TXDIFF_17DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_17DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS1_TXDIFF_17DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS1_TXDIFF_16DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS1_TXDIFF_16DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS1_TXDIFF_16DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS2_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_MCS2_TXDIFF_5DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_5DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS2_TXDIFF_5DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS2_TXDIFF_4DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_4DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS2_TXDIFF_4DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS2_TXDIFF_3DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_3DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS2_TXDIFF_3DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS2_TXDIFF_2DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_2DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS2_TXDIFF_2DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS2_TXDIFF_1DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_1DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS2_TXDIFF_1DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS2_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_MCS2_TXDIFF_10DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_10DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS2_TXDIFF_10DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS2_TXDIFF_9DB_MCS_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_9DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS2_TXDIFF_9DB_MCS_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS2_TXDIFF_8DB_MCS_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_8DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS2_TXDIFF_8DB_MCS_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS2_TXDIFF_7DB_MCS_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_7DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS2_TXDIFF_7DB_MCS_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS2_TXDIFF_6DB_MCS_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_6DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS2_TXDIFF_6DB_MCS_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS2_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_MCS2_TXDIFF_15DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_15DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS2_TXDIFF_15DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS2_TXDIFF_14DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_14DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS2_TXDIFF_14DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS2_TXDIFF_13DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_13DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS2_TXDIFF_13DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS2_TXDIFF_12DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_12DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS2_TXDIFF_12DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS2_TXDIFF_11DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_11DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS2_TXDIFF_11DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS2_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_MCS2_TXDIFF_20DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_20DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS2_TXDIFF_20DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS2_TXDIFF_19DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_19DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS2_TXDIFF_19DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS2_TXDIFF_18DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_18DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS2_TXDIFF_18DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS2_TXDIFF_17DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_17DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS2_TXDIFF_17DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS2_TXDIFF_16DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS2_TXDIFF_16DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS2_TXDIFF_16DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS3_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_MCS3_TXDIFF_5DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_5DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS3_TXDIFF_5DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS3_TXDIFF_4DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_4DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS3_TXDIFF_4DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS3_TXDIFF_3DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_3DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS3_TXDIFF_3DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS3_TXDIFF_2DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_2DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS3_TXDIFF_2DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS3_TXDIFF_1DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_1DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS3_TXDIFF_1DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS3_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_MCS3_TXDIFF_10DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_10DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS3_TXDIFF_10DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS3_TXDIFF_9DB_MCS_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_9DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS3_TXDIFF_9DB_MCS_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS3_TXDIFF_8DB_MCS_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_8DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS3_TXDIFF_8DB_MCS_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS3_TXDIFF_7DB_MCS_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_7DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS3_TXDIFF_7DB_MCS_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS3_TXDIFF_6DB_MCS_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_6DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS3_TXDIFF_6DB_MCS_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS3_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_MCS3_TXDIFF_15DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_15DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS3_TXDIFF_15DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS3_TXDIFF_14DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_14DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS3_TXDIFF_14DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS3_TXDIFF_13DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_13DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS3_TXDIFF_13DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS3_TXDIFF_12DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_12DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS3_TXDIFF_12DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS3_TXDIFF_11DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_11DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS3_TXDIFF_11DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS3_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_MCS3_TXDIFF_20DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_20DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS3_TXDIFF_20DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS3_TXDIFF_19DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_19DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS3_TXDIFF_19DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS3_TXDIFF_18DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_18DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS3_TXDIFF_18DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS3_TXDIFF_17DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_17DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS3_TXDIFF_17DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS3_TXDIFF_16DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS3_TXDIFF_16DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS3_TXDIFF_16DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS4_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_MCS4_TXDIFF_5DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_5DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS4_TXDIFF_5DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS4_TXDIFF_4DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_4DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS4_TXDIFF_4DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS4_TXDIFF_3DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_3DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS4_TXDIFF_3DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS4_TXDIFF_2DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_2DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS4_TXDIFF_2DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS4_TXDIFF_1DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_1DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS4_TXDIFF_1DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS4_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_MCS4_TXDIFF_10DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_10DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS4_TXDIFF_10DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS4_TXDIFF_9DB_MCS_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_9DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS4_TXDIFF_9DB_MCS_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS4_TXDIFF_8DB_MCS_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_8DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS4_TXDIFF_8DB_MCS_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS4_TXDIFF_7DB_MCS_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_7DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS4_TXDIFF_7DB_MCS_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS4_TXDIFF_6DB_MCS_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_6DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS4_TXDIFF_6DB_MCS_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS4_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_MCS4_TXDIFF_15DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_15DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS4_TXDIFF_15DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS4_TXDIFF_14DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_14DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS4_TXDIFF_14DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS4_TXDIFF_13DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_13DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS4_TXDIFF_13DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS4_TXDIFF_12DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_12DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS4_TXDIFF_12DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS4_TXDIFF_11DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_11DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS4_TXDIFF_11DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS4_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_MCS4_TXDIFF_20DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_20DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS4_TXDIFF_20DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS4_TXDIFF_19DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_19DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS4_TXDIFF_19DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS4_TXDIFF_18DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_18DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS4_TXDIFF_18DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS4_TXDIFF_17DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_17DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS4_TXDIFF_17DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS4_TXDIFF_16DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS4_TXDIFF_16DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS4_TXDIFF_16DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS5_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_MCS5_TXDIFF_5DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_5DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS5_TXDIFF_5DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS5_TXDIFF_4DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_4DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS5_TXDIFF_4DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS5_TXDIFF_3DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_3DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS5_TXDIFF_3DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS5_TXDIFF_2DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_2DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS5_TXDIFF_2DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS5_TXDIFF_1DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_1DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS5_TXDIFF_1DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS5_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_MCS5_TXDIFF_10DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_10DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS5_TXDIFF_10DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS5_TXDIFF_9DB_MCS_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_9DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS5_TXDIFF_9DB_MCS_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS5_TXDIFF_8DB_MCS_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_8DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS5_TXDIFF_8DB_MCS_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS5_TXDIFF_7DB_MCS_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_7DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS5_TXDIFF_7DB_MCS_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS5_TXDIFF_6DB_MCS_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_6DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS5_TXDIFF_6DB_MCS_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS5_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_MCS5_TXDIFF_15DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_15DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS5_TXDIFF_15DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS5_TXDIFF_14DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_14DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS5_TXDIFF_14DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS5_TXDIFF_13DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_13DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS5_TXDIFF_13DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS5_TXDIFF_12DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_12DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS5_TXDIFF_12DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS5_TXDIFF_11DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_11DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS5_TXDIFF_11DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS5_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_MCS5_TXDIFF_20DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_20DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS5_TXDIFF_20DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS5_TXDIFF_19DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_19DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS5_TXDIFF_19DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS5_TXDIFF_18DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_18DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS5_TXDIFF_18DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS5_TXDIFF_17DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_17DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS5_TXDIFF_17DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS5_TXDIFF_16DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS5_TXDIFF_16DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS5_TXDIFF_16DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS6_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_MCS6_TXDIFF_5DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_5DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS6_TXDIFF_5DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS6_TXDIFF_4DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_4DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS6_TXDIFF_4DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS6_TXDIFF_3DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_3DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS6_TXDIFF_3DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS6_TXDIFF_2DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_2DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS6_TXDIFF_2DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS6_TXDIFF_1DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_1DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS6_TXDIFF_1DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS6_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_MCS6_TXDIFF_10DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_10DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS6_TXDIFF_10DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS6_TXDIFF_9DB_MCS_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_9DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS6_TXDIFF_9DB_MCS_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS6_TXDIFF_8DB_MCS_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_8DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS6_TXDIFF_8DB_MCS_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS6_TXDIFF_7DB_MCS_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_7DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS6_TXDIFF_7DB_MCS_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS6_TXDIFF_6DB_MCS_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_6DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS6_TXDIFF_6DB_MCS_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS6_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_MCS6_TXDIFF_15DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_15DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS6_TXDIFF_15DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS6_TXDIFF_14DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_14DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS6_TXDIFF_14DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS6_TXDIFF_13DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_13DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS6_TXDIFF_13DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS6_TXDIFF_12DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_12DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS6_TXDIFF_12DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS6_TXDIFF_11DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_11DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS6_TXDIFF_11DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS6_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_MCS6_TXDIFF_20DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_20DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS6_TXDIFF_20DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS6_TXDIFF_19DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_19DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS6_TXDIFF_19DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS6_TXDIFF_18DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_18DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS6_TXDIFF_18DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS6_TXDIFF_17DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_17DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS6_TXDIFF_17DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS6_TXDIFF_16DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS6_TXDIFF_16DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS6_TXDIFF_16DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS7_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_MCS7_TXDIFF_5DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_5DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS7_TXDIFF_5DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS7_TXDIFF_4DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_4DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS7_TXDIFF_4DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS7_TXDIFF_3DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_3DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS7_TXDIFF_3DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS7_TXDIFF_2DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_2DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS7_TXDIFF_2DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS7_TXDIFF_1DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_1DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS7_TXDIFF_1DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS7_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_MCS7_TXDIFF_10DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_10DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS7_TXDIFF_10DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS7_TXDIFF_9DB_MCS_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_9DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS7_TXDIFF_9DB_MCS_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS7_TXDIFF_8DB_MCS_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_8DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS7_TXDIFF_8DB_MCS_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS7_TXDIFF_7DB_MCS_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_7DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS7_TXDIFF_7DB_MCS_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS7_TXDIFF_6DB_MCS_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_6DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS7_TXDIFF_6DB_MCS_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS7_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_MCS7_TXDIFF_15DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_15DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS7_TXDIFF_15DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS7_TXDIFF_14DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_14DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS7_TXDIFF_14DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS7_TXDIFF_13DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_13DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS7_TXDIFF_13DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS7_TXDIFF_12DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_12DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS7_TXDIFF_12DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS7_TXDIFF_11DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_11DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS7_TXDIFF_11DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS7_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_MCS7_TXDIFF_20DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_20DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS7_TXDIFF_20DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS7_TXDIFF_19DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_19DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS7_TXDIFF_19DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS7_TXDIFF_18DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_18DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS7_TXDIFF_18DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS7_TXDIFF_17DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_17DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS7_TXDIFF_17DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS7_TXDIFF_16DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS7_TXDIFF_16DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS7_TXDIFF_16DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS8_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_MCS8_TXDIFF_5DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_5DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS8_TXDIFF_5DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS8_TXDIFF_4DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_4DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS8_TXDIFF_4DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS8_TXDIFF_3DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_3DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS8_TXDIFF_3DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS8_TXDIFF_2DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_2DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS8_TXDIFF_2DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS8_TXDIFF_1DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_1DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS8_TXDIFF_1DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS8_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_MCS8_TXDIFF_10DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_10DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS8_TXDIFF_10DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS8_TXDIFF_9DB_MCS_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_9DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS8_TXDIFF_9DB_MCS_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS8_TXDIFF_8DB_MCS_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_8DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS8_TXDIFF_8DB_MCS_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS8_TXDIFF_7DB_MCS_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_7DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS8_TXDIFF_7DB_MCS_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS8_TXDIFF_6DB_MCS_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_6DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS8_TXDIFF_6DB_MCS_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS8_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_MCS8_TXDIFF_15DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_15DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS8_TXDIFF_15DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS8_TXDIFF_14DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_14DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS8_TXDIFF_14DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS8_TXDIFF_13DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_13DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS8_TXDIFF_13DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS8_TXDIFF_12DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_12DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS8_TXDIFF_12DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS8_TXDIFF_11DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_11DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS8_TXDIFF_11DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS8_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_MCS8_TXDIFF_20DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_20DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS8_TXDIFF_20DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS8_TXDIFF_19DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_19DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS8_TXDIFF_19DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS8_TXDIFF_18DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_18DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS8_TXDIFF_18DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS8_TXDIFF_17DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_17DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS8_TXDIFF_17DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS8_TXDIFF_16DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS8_TXDIFF_16DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS8_TXDIFF_16DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS9_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_MCS9_TXDIFF_5DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_5DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS9_TXDIFF_5DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS9_TXDIFF_4DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_4DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS9_TXDIFF_4DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS9_TXDIFF_3DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_3DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS9_TXDIFF_3DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS9_TXDIFF_2DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_2DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS9_TXDIFF_2DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS9_TXDIFF_1DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_1DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS9_TXDIFF_1DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS9_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_MCS9_TXDIFF_10DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_10DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS9_TXDIFF_10DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS9_TXDIFF_9DB_MCS_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_9DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS9_TXDIFF_9DB_MCS_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS9_TXDIFF_8DB_MCS_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_8DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS9_TXDIFF_8DB_MCS_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS9_TXDIFF_7DB_MCS_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_7DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS9_TXDIFF_7DB_MCS_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS9_TXDIFF_6DB_MCS_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_6DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS9_TXDIFF_6DB_MCS_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS9_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_MCS9_TXDIFF_15DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_15DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS9_TXDIFF_15DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS9_TXDIFF_14DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_14DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS9_TXDIFF_14DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS9_TXDIFF_13DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_13DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS9_TXDIFF_13DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS9_TXDIFF_12DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_12DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS9_TXDIFF_12DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS9_TXDIFF_11DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_11DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS9_TXDIFF_11DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS9_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_MCS9_TXDIFF_20DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_20DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS9_TXDIFF_20DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS9_TXDIFF_19DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_19DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS9_TXDIFF_19DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS9_TXDIFF_18DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_18DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS9_TXDIFF_18DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS9_TXDIFF_17DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_17DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS9_TXDIFF_17DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS9_TXDIFF_16DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS9_TXDIFF_16DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS9_TXDIFF_16DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS10_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_MCS10_TXDIFF_5DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_5DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS10_TXDIFF_5DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS10_TXDIFF_4DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_4DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS10_TXDIFF_4DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS10_TXDIFF_3DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_3DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS10_TXDIFF_3DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS10_TXDIFF_2DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_2DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS10_TXDIFF_2DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS10_TXDIFF_1DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_1DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS10_TXDIFF_1DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS10_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_MCS10_TXDIFF_10DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_10DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS10_TXDIFF_10DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS10_TXDIFF_9DB_MCS_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_9DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS10_TXDIFF_9DB_MCS_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS10_TXDIFF_8DB_MCS_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_8DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS10_TXDIFF_8DB_MCS_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS10_TXDIFF_7DB_MCS_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_7DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS10_TXDIFF_7DB_MCS_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS10_TXDIFF_6DB_MCS_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_6DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS10_TXDIFF_6DB_MCS_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS10_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_MCS10_TXDIFF_15DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_15DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS10_TXDIFF_15DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS10_TXDIFF_14DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_14DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS10_TXDIFF_14DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS10_TXDIFF_13DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_13DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS10_TXDIFF_13DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS10_TXDIFF_12DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_12DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS10_TXDIFF_12DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS10_TXDIFF_11DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_11DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS10_TXDIFF_11DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS10_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_MCS10_TXDIFF_20DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_20DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS10_TXDIFF_20DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS10_TXDIFF_19DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_19DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS10_TXDIFF_19DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS10_TXDIFF_18DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_18DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS10_TXDIFF_18DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS10_TXDIFF_17DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_17DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS10_TXDIFF_17DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS10_TXDIFF_16DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS10_TXDIFF_16DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS10_TXDIFF_16DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS11_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_MCS11_TXDIFF_5DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_5DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS11_TXDIFF_5DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS11_TXDIFF_4DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_4DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS11_TXDIFF_4DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS11_TXDIFF_3DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_3DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS11_TXDIFF_3DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS11_TXDIFF_2DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_2DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS11_TXDIFF_2DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS11_TXDIFF_1DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_1DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS11_TXDIFF_1DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS11_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_MCS11_TXDIFF_10DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_10DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS11_TXDIFF_10DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS11_TXDIFF_9DB_MCS_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_9DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS11_TXDIFF_9DB_MCS_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS11_TXDIFF_8DB_MCS_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_8DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS11_TXDIFF_8DB_MCS_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS11_TXDIFF_7DB_MCS_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_7DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS11_TXDIFF_7DB_MCS_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS11_TXDIFF_6DB_MCS_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_6DB_MCS_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS11_TXDIFF_6DB_MCS_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS11_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_MCS11_TXDIFF_15DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_15DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS11_TXDIFF_15DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS11_TXDIFF_14DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_14DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS11_TXDIFF_14DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS11_TXDIFF_13DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_13DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS11_TXDIFF_13DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS11_TXDIFF_12DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_12DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS11_TXDIFF_12DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS11_TXDIFF_11DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_11DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS11_TXDIFF_11DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_SR_MCS11_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_MCS11_TXDIFF_20DB_MCS_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_20DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_MCS11_TXDIFF_20DB_MCS_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_MCS11_TXDIFF_19DB_MCS_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_19DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_MCS11_TXDIFF_19DB_MCS_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_MCS11_TXDIFF_18DB_MCS_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_18DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_MCS11_TXDIFF_18DB_MCS_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_MCS11_TXDIFF_17DB_MCS_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_17DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_MCS11_TXDIFF_17DB_MCS_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_MCS11_TXDIFF_16DB_MCS_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0) mcs0~11*/
#define BIT_MCS11_TXDIFF_16DB_MCS_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_MCS11_TXDIFF_16DB_MCS_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCKxM_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_CCKxM_TXDIFF_5DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_5DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCKxM_TXDIFF_5DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCKxM_TXDIFF_4DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_4DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCKxM_TXDIFF_4DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCKxM_TXDIFF_3DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_3DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCKxM_TXDIFF_3DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCKxM_TXDIFF_2DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_2DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCKxM_TXDIFF_2DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCKxM_TXDIFF_1DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_1DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCKxM_TXDIFF_1DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCKxM_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_CCKxM_TXDIFF_10DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_10DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCKxM_TXDIFF_10DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCKxM_TXDIFF_9DB_RATE_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_9DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCKxM_TXDIFF_9DB_RATE_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCKxM_TXDIFF_8DB_RATE_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_8DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCKxM_TXDIFF_8DB_RATE_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCKxM_TXDIFF_7DB_RATE_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_7DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCKxM_TXDIFF_7DB_RATE_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCKxM_TXDIFF_6DB_RATE_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_6DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCKxM_TXDIFF_6DB_RATE_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCKxM_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_CCKxM_TXDIFF_15DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_15DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCKxM_TXDIFF_15DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCKxM_TXDIFF_14DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_14DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCKxM_TXDIFF_14DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCKxM_TXDIFF_13DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_13DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCKxM_TXDIFF_13DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCKxM_TXDIFF_12DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_12DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCKxM_TXDIFF_12DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCKxM_TXDIFF_11DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_11DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCKxM_TXDIFF_11DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCKxM_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_CCKxM_TXDIFF_20DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_20DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCKxM_TXDIFF_20DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCKxM_TXDIFF_19DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_19DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCKxM_TXDIFF_19DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCKxM_TXDIFF_18DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_18DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCKxM_TXDIFF_18DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCKxM_TXDIFF_17DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_17DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCKxM_TXDIFF_17DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCKxM_TXDIFF_16DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCKxM_TXDIFF_16DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCKxM_TXDIFF_16DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCK1M_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_CCK1M_TXDIFF_5DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_5DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCK1M_TXDIFF_5DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCK1M_TXDIFF_4DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_4DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCK1M_TXDIFF_4DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCK1M_TXDIFF_3DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_3DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCK1M_TXDIFF_3DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCK1M_TXDIFF_2DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_2DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCK1M_TXDIFF_2DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCK1M_TXDIFF_1DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_1DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCK1M_TXDIFF_1DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCK1M_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_CCK1M_TXDIFF_10DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_10DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCK1M_TXDIFF_10DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCK1M_TXDIFF_9DB_RATE_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_9DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCK1M_TXDIFF_9DB_RATE_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCK1M_TXDIFF_8DB_RATE_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_8DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCK1M_TXDIFF_8DB_RATE_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCK1M_TXDIFF_7DB_RATE_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_7DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCK1M_TXDIFF_7DB_RATE_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCK1M_TXDIFF_6DB_RATE_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_6DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCK1M_TXDIFF_6DB_RATE_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCK1M_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_CCK1M_TXDIFF_15DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_15DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCK1M_TXDIFF_15DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCK1M_TXDIFF_14DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_14DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCK1M_TXDIFF_14DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCK1M_TXDIFF_13DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_13DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCK1M_TXDIFF_13DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCK1M_TXDIFF_12DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_12DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCK1M_TXDIFF_12DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCK1M_TXDIFF_11DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_11DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCK1M_TXDIFF_11DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCK1M_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_CCK1M_TXDIFF_20DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_20DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCK1M_TXDIFF_20DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCK1M_TXDIFF_19DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_19DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCK1M_TXDIFF_19DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCK1M_TXDIFF_18DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_18DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCK1M_TXDIFF_18DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCK1M_TXDIFF_17DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_17DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCK1M_TXDIFF_17DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCK1M_TXDIFF_16DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK1M_TXDIFF_16DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCK1M_TXDIFF_16DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCK2M_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_CCK2M_TXDIFF_5DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_5DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCK2M_TXDIFF_5DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCK2M_TXDIFF_4DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_4DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCK2M_TXDIFF_4DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCK2M_TXDIFF_3DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_3DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCK2M_TXDIFF_3DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCK2M_TXDIFF_2DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_2DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCK2M_TXDIFF_2DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCK2M_TXDIFF_1DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_1DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCK2M_TXDIFF_1DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCK2M_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_CCK2M_TXDIFF_10DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_10DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCK2M_TXDIFF_10DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCK2M_TXDIFF_9DB_RATE_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_9DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCK2M_TXDIFF_9DB_RATE_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCK2M_TXDIFF_8DB_RATE_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_8DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCK2M_TXDIFF_8DB_RATE_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCK2M_TXDIFF_7DB_RATE_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_7DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCK2M_TXDIFF_7DB_RATE_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCK2M_TXDIFF_6DB_RATE_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_6DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCK2M_TXDIFF_6DB_RATE_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCK2M_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_CCK2M_TXDIFF_15DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_15DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCK2M_TXDIFF_15DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCK2M_TXDIFF_14DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_14DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCK2M_TXDIFF_14DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCK2M_TXDIFF_13DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_13DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCK2M_TXDIFF_13DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCK2M_TXDIFF_12DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_12DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCK2M_TXDIFF_12DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCK2M_TXDIFF_11DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_11DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCK2M_TXDIFF_11DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCK2M_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_CCK2M_TXDIFF_20DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_20DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCK2M_TXDIFF_20DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCK2M_TXDIFF_19DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_19DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCK2M_TXDIFF_19DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCK2M_TXDIFF_18DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_18DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCK2M_TXDIFF_18DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCK2M_TXDIFF_17DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_17DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCK2M_TXDIFF_17DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCK2M_TXDIFF_16DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK2M_TXDIFF_16DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCK2M_TXDIFF_16DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCK5P5M_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_CCK5P5M_TXDIFF_5DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_5DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCK5P5M_TXDIFF_5DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCK5P5M_TXDIFF_4DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_4DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCK5P5M_TXDIFF_4DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCK5P5M_TXDIFF_3DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_3DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCK5P5M_TXDIFF_3DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCK5P5M_TXDIFF_2DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_2DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCK5P5M_TXDIFF_2DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCK5P5M_TXDIFF_1DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_1DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCK5P5M_TXDIFF_1DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCK5P5M_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_CCK5P5M_TXDIFF_10DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_10DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCK5P5M_TXDIFF_10DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCK5P5M_TXDIFF_9DB_RATE_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_9DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCK5P5M_TXDIFF_9DB_RATE_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCK5P5M_TXDIFF_8DB_RATE_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_8DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCK5P5M_TXDIFF_8DB_RATE_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCK5P5M_TXDIFF_7DB_RATE_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_7DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCK5P5M_TXDIFF_7DB_RATE_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCK5P5M_TXDIFF_6DB_RATE_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_6DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCK5P5M_TXDIFF_6DB_RATE_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCK5P5M_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_CCK5P5M_TXDIFF_15DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_15DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCK5P5M_TXDIFF_15DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCK5P5M_TXDIFF_14DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_14DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCK5P5M_TXDIFF_14DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCK5P5M_TXDIFF_13DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_13DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCK5P5M_TXDIFF_13DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCK5P5M_TXDIFF_12DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_12DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCK5P5M_TXDIFF_12DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCK5P5M_TXDIFF_11DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_11DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCK5P5M_TXDIFF_11DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCK5P5M_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_CCK5P5M_TXDIFF_20DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_20DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCK5P5M_TXDIFF_20DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCK5P5M_TXDIFF_19DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_19DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCK5P5M_TXDIFF_19DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCK5P5M_TXDIFF_18DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_18DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCK5P5M_TXDIFF_18DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCK5P5M_TXDIFF_17DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_17DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCK5P5M_TXDIFF_17DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCK5P5M_TXDIFF_16DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK5P5M_TXDIFF_16DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCK5P5M_TXDIFF_16DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCK11M_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_CCK11M_TXDIFF_5DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_5DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCK11M_TXDIFF_5DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCK11M_TXDIFF_4DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_4DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCK11M_TXDIFF_4DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCK11M_TXDIFF_3DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_3DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCK11M_TXDIFF_3DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCK11M_TXDIFF_2DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_2DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCK11M_TXDIFF_2DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCK11M_TXDIFF_1DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_1DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCK11M_TXDIFF_1DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCK11M_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_CCK11M_TXDIFF_10DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_10DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCK11M_TXDIFF_10DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCK11M_TXDIFF_9DB_RATE_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_9DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCK11M_TXDIFF_9DB_RATE_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCK11M_TXDIFF_8DB_RATE_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_8DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCK11M_TXDIFF_8DB_RATE_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCK11M_TXDIFF_7DB_RATE_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_7DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCK11M_TXDIFF_7DB_RATE_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCK11M_TXDIFF_6DB_RATE_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_6DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCK11M_TXDIFF_6DB_RATE_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCK11M_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_CCK11M_TXDIFF_15DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_15DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCK11M_TXDIFF_15DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCK11M_TXDIFF_14DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_14DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCK11M_TXDIFF_14DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCK11M_TXDIFF_13DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_13DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCK11M_TXDIFF_13DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCK11M_TXDIFF_12DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_12DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCK11M_TXDIFF_12DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCK11M_TXDIFF_11DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_11DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCK11M_TXDIFF_11DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_CCK11M_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_CCK11M_TXDIFF_20DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_20DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_CCK11M_TXDIFF_20DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_CCK11M_TXDIFF_19DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_19DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_CCK11M_TXDIFF_19DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_CCK11M_TXDIFF_18DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_18DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CCK11M_TXDIFF_18DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CCK11M_TXDIFF_17DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_17DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CCK11M_TXDIFF_17DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CCK11M_TXDIFF_16DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  cck 0~3, 0-cck1M,1=cck2M,2=cck5p5M,3=cck11M*/
#define BIT_CCK11M_TXDIFF_16DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CCK11M_TXDIFF_16DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACYxM_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_LEGACYxM_TXDIFF_5DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_5DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACYxM_TXDIFF_5DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACYxM_TXDIFF_4DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_4DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACYxM_TXDIFF_4DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACYxM_TXDIFF_3DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_3DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACYxM_TXDIFF_3DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACYxM_TXDIFF_2DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_2DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACYxM_TXDIFF_2DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACYxM_TXDIFF_1DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_1DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACYxM_TXDIFF_1DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACYxM_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_LEGACYxM_TXDIFF_10DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_10DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACYxM_TXDIFF_10DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACYxM_TXDIFF_9DB_RATE_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_9DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACYxM_TXDIFF_9DB_RATE_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACYxM_TXDIFF_8DB_RATE_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_8DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACYxM_TXDIFF_8DB_RATE_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACYxM_TXDIFF_7DB_RATE_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_7DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACYxM_TXDIFF_7DB_RATE_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACYxM_TXDIFF_6DB_RATE_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_6DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACYxM_TXDIFF_6DB_RATE_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACYxM_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_LEGACYxM_TXDIFF_15DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_15DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACYxM_TXDIFF_15DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACYxM_TXDIFF_14DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_14DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACYxM_TXDIFF_14DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACYxM_TXDIFF_13DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_13DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACYxM_TXDIFF_13DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACYxM_TXDIFF_12DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_12DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACYxM_TXDIFF_12DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACYxM_TXDIFF_11DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_11DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACYxM_TXDIFF_11DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACYxM_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_LEGACYxM_TXDIFF_20DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_20DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACYxM_TXDIFF_20DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACYxM_TXDIFF_19DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_19DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACYxM_TXDIFF_19DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACYxM_TXDIFF_18DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_18DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACYxM_TXDIFF_18DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACYxM_TXDIFF_17DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_17DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACYxM_TXDIFF_17DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACYxM_TXDIFF_16DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACYxM_TXDIFF_16DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACYxM_TXDIFF_16DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY6M_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY6M_TXDIFF_5DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_5DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY6M_TXDIFF_5DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY6M_TXDIFF_4DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_4DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY6M_TXDIFF_4DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY6M_TXDIFF_3DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_3DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY6M_TXDIFF_3DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY6M_TXDIFF_2DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_2DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY6M_TXDIFF_2DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY6M_TXDIFF_1DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_1DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY6M_TXDIFF_1DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY6M_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY6M_TXDIFF_10DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_10DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY6M_TXDIFF_10DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY6M_TXDIFF_9DB_RATE_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_9DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY6M_TXDIFF_9DB_RATE_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY6M_TXDIFF_8DB_RATE_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_8DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY6M_TXDIFF_8DB_RATE_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY6M_TXDIFF_7DB_RATE_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_7DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY6M_TXDIFF_7DB_RATE_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY6M_TXDIFF_6DB_RATE_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_6DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY6M_TXDIFF_6DB_RATE_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY6M_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY6M_TXDIFF_15DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_15DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY6M_TXDIFF_15DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY6M_TXDIFF_14DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_14DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY6M_TXDIFF_14DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY6M_TXDIFF_13DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_13DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY6M_TXDIFF_13DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY6M_TXDIFF_12DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_12DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY6M_TXDIFF_12DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY6M_TXDIFF_11DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_11DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY6M_TXDIFF_11DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY6M_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY6M_TXDIFF_20DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_20DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY6M_TXDIFF_20DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY6M_TXDIFF_19DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_19DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY6M_TXDIFF_19DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY6M_TXDIFF_18DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_18DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY6M_TXDIFF_18DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY6M_TXDIFF_17DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_17DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY6M_TXDIFF_17DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY6M_TXDIFF_16DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY6M_TXDIFF_16DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY6M_TXDIFF_16DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY9M_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY9M_TXDIFF_5DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_5DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY9M_TXDIFF_5DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY9M_TXDIFF_4DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_4DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY9M_TXDIFF_4DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY9M_TXDIFF_3DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_3DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY9M_TXDIFF_3DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY9M_TXDIFF_2DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_2DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY9M_TXDIFF_2DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY9M_TXDIFF_1DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_1DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY9M_TXDIFF_1DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY9M_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY9M_TXDIFF_10DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_10DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY9M_TXDIFF_10DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY9M_TXDIFF_9DB_RATE_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_9DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY9M_TXDIFF_9DB_RATE_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY9M_TXDIFF_8DB_RATE_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_8DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY9M_TXDIFF_8DB_RATE_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY9M_TXDIFF_7DB_RATE_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_7DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY9M_TXDIFF_7DB_RATE_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY9M_TXDIFF_6DB_RATE_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_6DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY9M_TXDIFF_6DB_RATE_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY9M_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY9M_TXDIFF_15DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_15DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY9M_TXDIFF_15DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY9M_TXDIFF_14DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_14DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY9M_TXDIFF_14DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY9M_TXDIFF_13DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_13DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY9M_TXDIFF_13DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY9M_TXDIFF_12DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_12DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY9M_TXDIFF_12DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY9M_TXDIFF_11DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_11DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY9M_TXDIFF_11DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY9M_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY9M_TXDIFF_20DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_20DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY9M_TXDIFF_20DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY9M_TXDIFF_19DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_19DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY9M_TXDIFF_19DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY9M_TXDIFF_18DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_18DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY9M_TXDIFF_18DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY9M_TXDIFF_17DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_17DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY9M_TXDIFF_17DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY9M_TXDIFF_16DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY9M_TXDIFF_16DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY9M_TXDIFF_16DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY12M_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY12M_TXDIFF_5DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_5DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY12M_TXDIFF_5DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY12M_TXDIFF_4DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_4DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY12M_TXDIFF_4DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY12M_TXDIFF_3DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_3DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY12M_TXDIFF_3DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY12M_TXDIFF_2DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_2DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY12M_TXDIFF_2DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY12M_TXDIFF_1DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_1DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY12M_TXDIFF_1DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY12M_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY12M_TXDIFF_10DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_10DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY12M_TXDIFF_10DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY12M_TXDIFF_9DB_RATE_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_9DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY12M_TXDIFF_9DB_RATE_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY12M_TXDIFF_8DB_RATE_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_8DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY12M_TXDIFF_8DB_RATE_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY12M_TXDIFF_7DB_RATE_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_7DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY12M_TXDIFF_7DB_RATE_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY12M_TXDIFF_6DB_RATE_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_6DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY12M_TXDIFF_6DB_RATE_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY12M_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY12M_TXDIFF_15DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_15DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY12M_TXDIFF_15DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY12M_TXDIFF_14DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_14DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY12M_TXDIFF_14DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY12M_TXDIFF_13DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_13DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY12M_TXDIFF_13DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY12M_TXDIFF_12DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_12DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY12M_TXDIFF_12DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY12M_TXDIFF_11DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_11DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY12M_TXDIFF_11DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY12M_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY12M_TXDIFF_20DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_20DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY12M_TXDIFF_20DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY12M_TXDIFF_19DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_19DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY12M_TXDIFF_19DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY12M_TXDIFF_18DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_18DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY12M_TXDIFF_18DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY12M_TXDIFF_17DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_17DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY12M_TXDIFF_17DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY12M_TXDIFF_16DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY12M_TXDIFF_16DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY12M_TXDIFF_16DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY18M_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY18M_TXDIFF_5DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_5DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY18M_TXDIFF_5DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY18M_TXDIFF_4DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_4DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY18M_TXDIFF_4DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY18M_TXDIFF_3DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_3DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY18M_TXDIFF_3DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY18M_TXDIFF_2DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_2DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY18M_TXDIFF_2DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY18M_TXDIFF_1DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_1DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY18M_TXDIFF_1DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY18M_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY18M_TXDIFF_10DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_10DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY18M_TXDIFF_10DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY18M_TXDIFF_9DB_RATE_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_9DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY18M_TXDIFF_9DB_RATE_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY18M_TXDIFF_8DB_RATE_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_8DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY18M_TXDIFF_8DB_RATE_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY18M_TXDIFF_7DB_RATE_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_7DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY18M_TXDIFF_7DB_RATE_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY18M_TXDIFF_6DB_RATE_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_6DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY18M_TXDIFF_6DB_RATE_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY18M_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY18M_TXDIFF_15DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_15DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY18M_TXDIFF_15DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY18M_TXDIFF_14DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_14DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY18M_TXDIFF_14DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY18M_TXDIFF_13DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_13DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY18M_TXDIFF_13DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY18M_TXDIFF_12DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_12DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY18M_TXDIFF_12DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY18M_TXDIFF_11DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_11DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY18M_TXDIFF_11DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY18M_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY18M_TXDIFF_20DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_20DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY18M_TXDIFF_20DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY18M_TXDIFF_19DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_19DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY18M_TXDIFF_19DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY18M_TXDIFF_18DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_18DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY18M_TXDIFF_18DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY18M_TXDIFF_17DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_17DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY18M_TXDIFF_17DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY18M_TXDIFF_16DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY18M_TXDIFF_16DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY18M_TXDIFF_16DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY24M_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY24M_TXDIFF_5DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_5DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY24M_TXDIFF_5DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY24M_TXDIFF_4DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_4DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY24M_TXDIFF_4DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY24M_TXDIFF_3DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_3DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY24M_TXDIFF_3DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY24M_TXDIFF_2DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_2DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY24M_TXDIFF_2DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY24M_TXDIFF_1DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_1DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY24M_TXDIFF_1DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY24M_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY24M_TXDIFF_10DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_10DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY24M_TXDIFF_10DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY24M_TXDIFF_9DB_RATE_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_9DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY24M_TXDIFF_9DB_RATE_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY24M_TXDIFF_8DB_RATE_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_8DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY24M_TXDIFF_8DB_RATE_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY24M_TXDIFF_7DB_RATE_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_7DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY24M_TXDIFF_7DB_RATE_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY24M_TXDIFF_6DB_RATE_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_6DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY24M_TXDIFF_6DB_RATE_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY24M_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY24M_TXDIFF_15DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_15DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY24M_TXDIFF_15DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY24M_TXDIFF_14DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_14DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY24M_TXDIFF_14DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY24M_TXDIFF_13DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_13DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY24M_TXDIFF_13DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY24M_TXDIFF_12DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_12DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY24M_TXDIFF_12DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY24M_TXDIFF_11DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_11DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY24M_TXDIFF_11DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY24M_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY24M_TXDIFF_20DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_20DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY24M_TXDIFF_20DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY24M_TXDIFF_19DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_19DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY24M_TXDIFF_19DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY24M_TXDIFF_18DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_18DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY24M_TXDIFF_18DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY24M_TXDIFF_17DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_17DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY24M_TXDIFF_17DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY24M_TXDIFF_16DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY24M_TXDIFF_16DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY24M_TXDIFF_16DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY36M_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY36M_TXDIFF_5DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_5DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY36M_TXDIFF_5DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY36M_TXDIFF_4DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_4DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY36M_TXDIFF_4DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY36M_TXDIFF_3DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_3DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY36M_TXDIFF_3DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY36M_TXDIFF_2DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_2DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY36M_TXDIFF_2DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY36M_TXDIFF_1DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_1DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY36M_TXDIFF_1DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY36M_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY36M_TXDIFF_10DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_10DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY36M_TXDIFF_10DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY36M_TXDIFF_9DB_RATE_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_9DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY36M_TXDIFF_9DB_RATE_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY36M_TXDIFF_8DB_RATE_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_8DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY36M_TXDIFF_8DB_RATE_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY36M_TXDIFF_7DB_RATE_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_7DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY36M_TXDIFF_7DB_RATE_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY36M_TXDIFF_6DB_RATE_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_6DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY36M_TXDIFF_6DB_RATE_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY36M_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY36M_TXDIFF_15DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_15DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY36M_TXDIFF_15DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY36M_TXDIFF_14DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_14DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY36M_TXDIFF_14DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY36M_TXDIFF_13DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_13DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY36M_TXDIFF_13DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY36M_TXDIFF_12DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_12DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY36M_TXDIFF_12DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY36M_TXDIFF_11DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_11DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY36M_TXDIFF_11DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY36M_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY36M_TXDIFF_20DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_20DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY36M_TXDIFF_20DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY36M_TXDIFF_19DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_19DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY36M_TXDIFF_19DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY36M_TXDIFF_18DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_18DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY36M_TXDIFF_18DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY36M_TXDIFF_17DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_17DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY36M_TXDIFF_17DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY36M_TXDIFF_16DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY36M_TXDIFF_16DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY36M_TXDIFF_16DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY48M_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY48M_TXDIFF_5DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_5DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY48M_TXDIFF_5DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY48M_TXDIFF_4DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_4DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY48M_TXDIFF_4DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY48M_TXDIFF_3DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_3DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY48M_TXDIFF_3DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY48M_TXDIFF_2DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_2DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY48M_TXDIFF_2DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY48M_TXDIFF_1DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_1DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY48M_TXDIFF_1DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY48M_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY48M_TXDIFF_10DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_10DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY48M_TXDIFF_10DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY48M_TXDIFF_9DB_RATE_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_9DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY48M_TXDIFF_9DB_RATE_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY48M_TXDIFF_8DB_RATE_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_8DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY48M_TXDIFF_8DB_RATE_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY48M_TXDIFF_7DB_RATE_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_7DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY48M_TXDIFF_7DB_RATE_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY48M_TXDIFF_6DB_RATE_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_6DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY48M_TXDIFF_6DB_RATE_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY48M_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY48M_TXDIFF_15DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_15DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY48M_TXDIFF_15DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY48M_TXDIFF_14DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_14DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY48M_TXDIFF_14DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY48M_TXDIFF_13DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_13DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY48M_TXDIFF_13DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY48M_TXDIFF_12DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_12DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY48M_TXDIFF_12DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY48M_TXDIFF_11DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_11DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY48M_TXDIFF_11DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY48M_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY48M_TXDIFF_20DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_20DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY48M_TXDIFF_20DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY48M_TXDIFF_19DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_19DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY48M_TXDIFF_19DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY48M_TXDIFF_18DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_18DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY48M_TXDIFF_18DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY48M_TXDIFF_17DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_17DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY48M_TXDIFF_17DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY48M_TXDIFF_16DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY48M_TXDIFF_16DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY48M_TXDIFF_16DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY54M_TXDIFF_TABLE0
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY54M_TXDIFF_5DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_5DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY54M_TXDIFF_5DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY54M_TXDIFF_4DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_4DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY54M_TXDIFF_4DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY54M_TXDIFF_3DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_3DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY54M_TXDIFF_3DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY54M_TXDIFF_2DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_2DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY54M_TXDIFF_2DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY54M_TXDIFF_1DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_1DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY54M_TXDIFF_1DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY54M_TXDIFF_TABLE1
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY54M_TXDIFF_10DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_10DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY54M_TXDIFF_10DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY54M_TXDIFF_9DB_RATE_OFFSET    ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_9DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY54M_TXDIFF_9DB_RATE_OFFSET(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY54M_TXDIFF_8DB_RATE_OFFSET    ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_8DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY54M_TXDIFF_8DB_RATE_OFFSET(x)  ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY54M_TXDIFF_7DB_RATE_OFFSET    ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_7DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY54M_TXDIFF_7DB_RATE_OFFSET(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY54M_TXDIFF_6DB_RATE_OFFSET    ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_6DB_RATE_OFFSET(x)      (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY54M_TXDIFF_6DB_RATE_OFFSET(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY54M_TXDIFF_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY54M_TXDIFF_15DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_15DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY54M_TXDIFF_15DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY54M_TXDIFF_14DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_14DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY54M_TXDIFF_14DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY54M_TXDIFF_13DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_13DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY54M_TXDIFF_13DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY54M_TXDIFF_12DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_12DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY54M_TXDIFF_12DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY54M_TXDIFF_11DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_11DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY54M_TXDIFF_11DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_LEGACY54M_TXDIFF_TABLE3
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY54M_TXDIFF_20DB_RATE_OFFSET   ((u32)0x0000000F << 16)           /*!< R/W 0x0  U(4.0) legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_20DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_LEGACY54M_TXDIFF_20DB_RATE_OFFSET(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_LEGACY54M_TXDIFF_19DB_RATE_OFFSET   ((u32)0x0000000F << 12)           /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_19DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 12))
#define BIT_GET_LEGACY54M_TXDIFF_19DB_RATE_OFFSET(x) ((u32)(((x >> 12) & 0x0000000F)))
#define BIT_MASK_LEGACY54M_TXDIFF_18DB_RATE_OFFSET   ((u32)0x0000000F << 8)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_18DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_LEGACY54M_TXDIFF_18DB_RATE_OFFSET(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_LEGACY54M_TXDIFF_17DB_RATE_OFFSET   ((u32)0x0000000F << 4)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_17DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_LEGACY54M_TXDIFF_17DB_RATE_OFFSET(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_LEGACY54M_TXDIFF_16DB_RATE_OFFSET   ((u32)0x0000000F << 0)            /*!< R/W 0x0  U(4.0)  legacy 4~11,4=legacy6M,5=legacy9M,6=legacy12M,7=legacy18M,8=legacy24M,9=legacy36M,10=legacy48M,11=legacy54M*/
#define BIT_LEGACY54M_TXDIFF_16DB_RATE_OFFSET(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_LEGACY54M_TXDIFF_16DB_RATE_OFFSET(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_TCM_WRAPPER_CR12
  * @brief
  * @{
  */
#define BIT_MASK_FORCE_PWRSR_TXPWR_PD_VAL    ((u32)0x0000003F << 26)           /*!< R/W 0x0  */
#define BIT_FORCE_PWRSR_TXPWR_PD_VAL(x)      (((u32)((x) & 0x0000003F) << 26))
#define BIT_GET_FORCE_PWRSR_TXPWR_PD_VAL(x)  ((u32)(((x >> 26) & 0x0000003F)))
#define BIT_MASK_FORCE_PWRCOM_RU_ALLOC_VAL   ((u32)0x000000FF << 18)           /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_RU_ALLOC_VAL(x)     (((u32)((x) & 0x000000FF) << 18))
#define BIT_GET_FORCE_PWRCOM_RU_ALLOC_VAL(x) ((u32)(((x >> 18) & 0x000000FF)))
#define BIT_MASK_FORCE_PWRUL_RPL_VAL         ((u32)0x000001FF << 9)            /*!< R/W 0x0  */
#define BIT_FORCE_PWRUL_RPL_VAL(x)           (((u32)((x) & 0x000001FF) << 9))
#define BIT_GET_FORCE_PWRUL_RPL_VAL(x)       ((u32)(((x >> 9) & 0x000001FF)))
#define BIT_MASK_FORCE_PWRUL_RPL_UP_VAL      ((u32)0x000001FF << 0)            /*!< R/W 0x0  */
#define BIT_FORCE_PWRUL_RPL_UP_VAL(x)        (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_FORCE_PWRUL_RPL_UP_VAL(x)    ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_AX_PWR_TCM_WRAPPER_CR13
  * @brief
  * @{
  */
#define BIT_MASK_FORCE_PWRSR_TXPWR_TOLER_VAL      ((u32)0x0000003F << 22)           /*!< R/W 0x0  */
#define BIT_FORCE_PWRSR_TXPWR_TOLER_VAL(x)        (((u32)((x) & 0x0000003F) << 22))
#define BIT_GET_FORCE_PWRSR_TXPWR_TOLER_VAL(x)    ((u32)(((x >> 22) & 0x0000003F)))
#define BIT_MASK_FORCE_PWRUL_TAR_RSSI_VAL         ((u32)0x0000007F << 15)           /*!< R/W 0x0  */
#define BIT_FORCE_PWRUL_TAR_RSSI_VAL(x)           (((u32)((x) & 0x0000007F) << 15))
#define BIT_GET_FORCE_PWRUL_TAR_RSSI_VAL(x)       ((u32)(((x >> 15) & 0x0000007F)))
#define BIT_MASK_FORCE_PWRCOM_MACID_VAL           ((u32)0x0000007F << 8)            /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_MACID_VAL(x)             (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_FORCE_PWRCOM_MACID_VAL(x)         ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_FORCE_PWRRU_CH20_WITH_DATA_VAL   ((u32)0x000000FF << 0)            /*!< R/W 0x0  */
#define BIT_FORCE_PWRRU_CH20_WITH_DATA_VAL(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_FORCE_PWRRU_CH20_WITH_DATA_VAL(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_TCM_WRAPPER_CR14
  * @brief
  * @{
  */
#define BIT_MASK_FORCE_PWRCOM_CTRL_VAL          ((u32)0x00000007 << 29)           /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_CTRL_VAL(x)            (((u32)((x) & 0x00000007) << 29))
#define BIT_GET_FORCE_PWRCOM_CTRL_VAL(x)        ((u32)(((x >> 29) & 0x00000007)))
#define BIT_MASK_FORCE_PWRANT_NSTS_VAL          ((u32)0x00000007 << 26)           /*!< R/W 0x0  */
#define BIT_FORCE_PWRANT_NSTS_VAL(x)            (((u32)((x) & 0x00000007) << 26))
#define BIT_GET_FORCE_PWRANT_NSTS_VAL(x)        ((u32)(((x >> 26) & 0x00000007)))
#define BIT_MASK_FORCE_MACID_PWR_MODE_VAL       ((u32)0x00000007 << 23)           /*!< R/W 0x0  */
#define BIT_FORCE_MACID_PWR_MODE_VAL(x)         (((u32)((x) & 0x00000007) << 23))
#define BIT_GET_FORCE_MACID_PWR_MODE_VAL(x)     ((u32)(((x >> 23) & 0x00000007)))
#define BIT_MASK_FORCE_PWRCOM_TXSC_VAL          ((u32)0x0000000F << 19)           /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_TXSC_VAL(x)            (((u32)((x) & 0x0000000F) << 19))
#define BIT_GET_FORCE_PWRCOM_TXSC_VAL(x)        ((u32)(((x >> 19) & 0x0000000F)))
#define BIT_MASK_FORCE_PWRCOM_PPDU_TYPE_VAL     ((u32)0x0000000F << 15)           /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_PPDU_TYPE_VAL(x)       (((u32)((x) & 0x0000000F) << 15))
#define BIT_GET_FORCE_PWRCOM_PPDU_TYPE_VAL(x)   ((u32)(((x >> 15) & 0x0000000F)))
#define BIT_MASK_FORCE_OUT_PWRCOM_MAX_MCS_VAL   ((u32)0x0000000F << 11)           /*!< R/W 0x0  */
#define BIT_FORCE_OUT_PWRCOM_MAX_MCS_VAL(x)     (((u32)((x) & 0x0000000F) << 11))
#define BIT_GET_FORCE_OUT_PWRCOM_MAX_MCS_VAL(x) ((u32)(((x >> 11) & 0x0000000F)))
#define BIT_MASK_FORCE_PWRCOM_MCS_VAL           ((u32)0x0000001F << 6)            /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_MCS_VAL(x)             (((u32)((x) & 0x0000001F) << 6))
#define BIT_GET_FORCE_PWRCOM_MCS_VAL(x)         ((u32)(((x >> 6) & 0x0000001F)))
#define BIT_MASK_FORCE_PWRUL_AP_TX_PWR_VAL      ((u32)0x0000003F << 0)            /*!< R/W 0x0  */
#define BIT_FORCE_PWRUL_AP_TX_PWR_VAL(x)        (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_FORCE_PWRUL_AP_TX_PWR_VAL(x)    ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_AX_PWR_TCM_WRAPPER_CR15
  * @brief
  * @{
  */
#define BIT_FORCE_MACID_CCA_TH_ALLOW_VAL           ((u32)0x00000001 << 20)          /*!< R/W 0x0  */
#define BIT_MASK_FORCE_PWRCOM_PRECODING_MODE_IDX   ((u32)0x00000003 << 7)           /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_PRECODING_MODE_IDX(x)     (((u32)((x) & 0x00000003) << 7))
#define BIT_GET_FORCE_PWRCOM_PRECODING_MODE_IDX(x) ((u32)(((x >> 7) & 0x00000003)))
#define BIT_MASK_FORCE_PWRCOM_DBW_IDX_VAL          ((u32)0x00000003 << 5)           /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_DBW_IDX_VAL(x)            (((u32)((x) & 0x00000003) << 5))
#define BIT_GET_FORCE_PWRCOM_DBW_IDX_VAL(x)        ((u32)(((x >> 5) & 0x00000003)))
#define BIT_MASK_FORCE_PWRCOM_CBW_IDX_VAL          ((u32)0x00000003 << 3)           /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_CBW_IDX_VAL(x)            (((u32)((x) & 0x00000003) << 3))
#define BIT_GET_FORCE_PWRCOM_CBW_IDX_VAL(x)        ((u32)(((x >> 3) & 0x00000003)))
/** @} */

/** @defgroup REG_AX_PWR_TCM_WRAPPER_CR16
  * @brief
  * @{
  */
#define BIT_FORCE_PWRUL_RPL_ON                 ((u32)0x00000001 << 30) /*!< R/W 0x0  */
#define BIT_FORCE_PWRUL_AP_TX_PWR_ON           ((u32)0x00000001 << 29) /*!< R/W 0x0  */
#define BIT_FORCE_PWRTSSI_FAST_MODE_EN_VAL     ((u32)0x00000001 << 28) /*!< R/W 0x0  */
#define BIT_FORCE_PWRTSSI_FAST_MODE_EN_ON      ((u32)0x00000001 << 27) /*!< R/W 0x0  */
#define BIT_FORCE_PWRSR_TXPWR_TOLER_ON         ((u32)0x00000001 << 26) /*!< R/W 0x0  */
#define BIT_FORCE_PWRSR_TXPWR_PD_ON            ((u32)0x00000001 << 25) /*!< R/W 0x0  */
#define BIT_FORCE_PWRRU_CH20_WITH_DATA_ON      ((u32)0x00000001 << 23) /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_TXSC_ON               ((u32)0x00000001 << 22) /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_STBC_EN_VAL           ((u32)0x00000001 << 21) /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_STBC_EN_ON            ((u32)0x00000001 << 20) /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_RX_LTE_VAL            ((u32)0x00000001 << 19) /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_RX_LTE_ON             ((u32)0x00000001 << 18) /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_RU_ALLOC_ON           ((u32)0x00000001 << 17) /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_PRECODING_MODE_IDX_ON ((u32)0x00000001 << 16) /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_PPDU_TYPE_ON          ((u32)0x00000001 << 15) /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_MCS_ON                ((u32)0x00000001 << 14) /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_MACID_ON              ((u32)0x00000001 << 13) /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_DCM_VAL               ((u32)0x00000001 << 12) /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_DCM_ON                ((u32)0x00000001 << 11) /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_DBW_IDX_ON            ((u32)0x00000001 << 10) /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_CTRL_ON               ((u32)0x00000001 << 7)  /*!< R/W 0x0  */
#define BIT_FORCE_PWRCOM_CBW_IDX_ON            ((u32)0x00000001 << 6)  /*!< R/W 0x0  */
#define BIT_FORCE_PWRANT_NSTS_ON               ((u32)0x00000001 << 5)  /*!< R/W 0x0  */
#define BIT_FORCE_PWRANT_NDP_EN_VAL            ((u32)0x00000001 << 4)  /*!< R/W 0x0  */
#define BIT_FORCE_PWRANT_NDP_EN_ON             ((u32)0x00000001 << 3)  /*!< R/W 0x0  */
#define BIT_FORCE_PWRANT_ACTIVE_TX_EN_VAL      ((u32)0x00000001 << 2)  /*!< R/W 0x0  */
#define BIT_FORCE_PWRANT_ACTIVE_TX_EN_ON       ((u32)0x00000001 << 1)  /*!< R/W 0x0  */
#define BIT_FORCE_OUT_PWRCOM_MAX_MCS_ON        ((u32)0x00000001 << 0)  /*!< R/W 0x0  */
/** @} */

/** @defgroup REG_AX_PWR_TCM_WRAPPER_CR17
  * @brief
  * @{
  */
#define BIT_FORCE_ANT_SEL_A                             ((u32)0x00000001 << 13)           /*!< R/W 0x0  */
#define BIT_FORCE_PATH_EN                               ((u32)0x00000001 << 12)           /*!< R/W 0x1  */
#define BIT_MASK_FORCE_PATH_MAP_A                       ((u32)0x00000003 << 10)           /*!< R/W 0x0  */
#define BIT_FORCE_PATH_MAP_A(x)                         (((u32)((x) & 0x00000003) << 10))
#define BIT_GET_FORCE_PATH_MAP_A(x)                     ((u32)(((x >> 10) & 0x00000003)))
#define BIT_TSSI_CTRL_MAC_PWRCOM_CH20_WITH_DATA_BIT_REV ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_TSSI_CTRL_MAC_PWRCOM_CH20_WITH_DATA_BIT_INV ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_SR_MCS_MASK_DIS                             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_PWRRU_CH20_WITH_DATA_HANG_PROOF_EN          ((u32)0x00000001 << 6)            /*!< R/W 0x1  */
#define BIT_MUMIMO_APPLY_PWRLIMBF_EN                    ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_HERU_MASK_DIS                               ((u32)0x00000001 << 4)            /*!< R/W 0x0  */
#define BIT_HERU_CH20_WITH_DATA_FROM_F2P_DIS            ((u32)0x00000001 << 3)            /*!< R/W 0x0  */
#define BIT_FORCE_PWRUL_TAR_RSSI_ON                     ((u32)0x00000001 << 2)            /*!< R/W 0x0  */
#define BIT_FORCE_PWRUL_RPL_UP_ON                       ((u32)0x00000001 << 1)            /*!< R/W 0x0  */
#define BIT_FORCE_PWRUL_RPL_UP_EN_VAL                   ((u32)0x00000001 << 0)            /*!< R/W 0x0  */
/** @} */

/** @defgroup REG_AX_PWR_TCM_WRAPPER_CR18
  * @brief
  * @{
  */
#define BIT_TXPWACK_CTRL_MAC_CLR                          ((u32)0x00000001 << 29)           /*!< R/W 0x0  clear txpwr ack ctrl state*/
#define BIT_RU_ALLOC_DBW160_FIX_EN                        ((u32)0x00000001 << 28)           /*!< R/W 0x0  */
#define BIT_PWTSSICT_TX_BANDEDGE_CFG_FORCE_OUT_ON         ((u32)0x00000001 << 27)           /*!< R/W 0x0  */
#define BIT_PWTSSICT_TSSI_FAST_MODE_EN_FORCE_OUT_VAL      ((u32)0x00000001 << 24)           /*!< R/W 0x0  */
#define BIT_PWTSSICT_TSSI_FAST_MODE_EN_FORCE_OUT_ON       ((u32)0x00000001 << 23)           /*!< R/W 0x0  */
#define BIT_PWTSSICT_PWOFST_SEG0_DB_FORCE_OUT_ON          ((u32)0x00000001 << 21)           /*!< R/W 0x0  */
#define BIT_MAC_DEF_LEGACY_RATE_IDX_BEGIN_AT_4_ON         ((u32)0x00000001 << 20)           /*!< R/W 0x0  */
#define BIT_MASK_PWTSSICT_TX_BANDEDGE_CFG_FORCE_OUT_VAL   ((u32)0x00000003 << 18)           /*!< R/W 0x0  */
#define BIT_PWTSSICT_TX_BANDEDGE_CFG_FORCE_OUT_VAL(x)     (((u32)((x) & 0x00000003) << 18))
#define BIT_GET_PWTSSICT_TX_BANDEDGE_CFG_FORCE_OUT_VAL(x) ((u32)(((x >> 18) & 0x00000003)))
#define BIT_MASK_PWTSSICT_PWOFST_SEG0_DB_FORCE_OUT_VAL    ((u32)0x000001FF << 0)            /*!< R/W 0x0  */
#define BIT_PWTSSICT_PWOFST_SEG0_DB_FORCE_OUT_VAL(x)      (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_PWTSSICT_PWOFST_SEG0_DB_FORCE_OUT_VAL(x)  ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_AX_PWR_TSSI_TABLE2
  * @brief
  * @{
  */
#define BIT_MASK_BANDEDGE_NONZERO_CFG_SBW20   ((u32)0x000000FF << 0)           /*!< R/W 0x0  */
#define BIT_BANDEDGE_NONZERO_CFG_SBW20(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_BANDEDGE_NONZERO_CFG_SBW20(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_TSSI_TABLE5
  * @brief
  * @{
  */
#define BIT_MASK_BANDEDGE_ZERO_CFG_SBW20   ((u32)0x000000FF << 24)           /*!< R/W 0x0  */
#define BIT_BANDEDGE_ZERO_CFG_SBW20(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_BANDEDGE_ZERO_CFG_SBW20(x) ((u32)(((x >> 24) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_TSSI_TABLE7
  * @brief
  * @{
  */
#define BIT_MASK_BMODE_INIT_OFST_SEG0_DB   ((u32)0x000000FF << 24)           /*!< R/W 0x0  */
#define BIT_BMODE_INIT_OFST_SEG0_DB(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_BMODE_INIT_OFST_SEG0_DB(x) ((u32)(((x >> 24) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_TSSI_TABLE8
  * @brief
  * @{
  */
#define BIT_MASK_CBW_SUB20_0   ((u32)0x000000FF << 0)           /*!< R/W 0x0  */
#define BIT_CBW_SUB20_0(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_CBW_SUB20_0(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_TSSI_TABLE10
  * @brief
  * @{
  */
#define BIT_MASK_CH_COMB_OFST_BANDEDGE_NONZERO_BW40    ((u32)0x000000FF << 24)           /*!< R/W 0x0  */
#define BIT_CH_COMB_OFST_BANDEDGE_NONZERO_BW40(x)      (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_CH_COMB_OFST_BANDEDGE_NONZERO_BW40(x)  ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_CH_COMB_OFST_BANDEDGE_NONZERO_BW20    ((u32)0x000000FF << 16)           /*!< R/W 0x0  */
#define BIT_CH_COMB_OFST_BANDEDGE_NONZERO_BW20(x)      (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_CH_COMB_OFST_BANDEDGE_NONZERO_BW20(x)  ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_CH_COMB_OFST_BANDEDGE_NONZERO_BW160   ((u32)0x000000FF << 8)            /*!< R/W 0x0  */
#define BIT_CH_COMB_OFST_BANDEDGE_NONZERO_BW160(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_CH_COMB_OFST_BANDEDGE_NONZERO_BW160(x) ((u32)(((x >> 8) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_TSSI_TABLE11
  * @brief
  * @{
  */
#define BIT_MASK_CH_COMB_OFST_BANDEDGE_ZERO_BW40      ((u32)0x000000FF << 24)           /*!< R/W 0x0  */
#define BIT_CH_COMB_OFST_BANDEDGE_ZERO_BW40(x)        (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_CH_COMB_OFST_BANDEDGE_ZERO_BW40(x)    ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_CH_COMB_OFST_BANDEDGE_ZERO_BW20      ((u32)0x000000FF << 16)           /*!< R/W 0x0  */
#define BIT_CH_COMB_OFST_BANDEDGE_ZERO_BW20(x)        (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_CH_COMB_OFST_BANDEDGE_ZERO_BW20(x)    ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_CH_COMB_OFST_BANDEDGE_ZERO_BW160     ((u32)0x000000FF << 8)            /*!< R/W 0x0  */
#define BIT_CH_COMB_OFST_BANDEDGE_ZERO_BW160(x)       (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_CH_COMB_OFST_BANDEDGE_ZERO_BW160(x)   ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_CH_COMB_OFST_BANDEDGE_NONZERO_BW80   ((u32)0x000000FF << 0)            /*!< R/W 0x0  */
#define BIT_CH_COMB_OFST_BANDEDGE_NONZERO_BW80(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_CH_COMB_OFST_BANDEDGE_NONZERO_BW80(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_TSSI_TABLE12
  * @brief
  * @{
  */
#define BIT_MASK_F_PWR_OFST_OUT_SEG0_DB            ((u32)0x000000FF << 24)           /*!< R/W 0x0  */
#define BIT_F_PWR_OFST_OUT_SEG0_DB(x)              (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_F_PWR_OFST_OUT_SEG0_DB(x)          ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_CH_COMB_OFST_BANDEDGE_ZERO_BW80   ((u32)0x000000FF << 0)            /*!< R/W 0x0  */
#define BIT_CH_COMB_OFST_BANDEDGE_ZERO_BW80(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_CH_COMB_OFST_BANDEDGE_ZERO_BW80(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_TSSI_TABLE13
  * @brief
  * @{
  */
#define BIT_MASK_HEER_INIT_OFST_SEG0_DB   ((u32)0x000000FF << 16)           /*!< R/W 0x0  */
#define BIT_HEER_INIT_OFST_SEG0_DB(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_HEER_INIT_OFST_SEG0_DB(x) ((u32)(((x >> 16) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_TSSI_TABLE14
  * @brief
  * @{
  */
#define BIT_MASK_HESU_INIT_OFST_SEG0_DB   ((u32)0x000000FF << 16)           /*!< R/W 0x0  */
#define BIT_HESU_INIT_OFST_SEG0_DB(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_HESU_INIT_OFST_SEG0_DB(x) ((u32)(((x >> 16) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_TSSI_TABLE15
  * @brief
  * @{
  */
#define BIT_MASK_HETB_INIT_OFST_SEG0_DB           ((u32)0x000000FF << 16)           /*!< R/W 0x0  */
#define BIT_HETB_INIT_OFST_SEG0_DB(x)             (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_HETB_INIT_OFST_SEG0_DB(x)         ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_HETB_INIT_OFST_ATHESTF_SEG0_DB   ((u32)0x000000FF << 8)            /*!< R/W 0x0  */
#define BIT_HETB_INIT_OFST_ATHESTF_SEG0_DB(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_HETB_INIT_OFST_ATHESTF_SEG0_DB(x) ((u32)(((x >> 8) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_TSSI_TABLE16
  * @brief
  * @{
  */
#define BIT_MASK_LEGACY_INIT_OFST_SEG0_DB   ((u32)0x000000FF << 16)           /*!< R/W 0x0  */
#define BIT_LEGACY_INIT_OFST_SEG0_DB(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_LEGACY_INIT_OFST_SEG0_DB(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_HT_INIT_OFST_SEG0_DB       ((u32)0x000000FF << 0)            /*!< R/W 0x0  */
#define BIT_HT_INIT_OFST_SEG0_DB(x)         (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_HT_INIT_OFST_SEG0_DB(x)     ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_TSSI_TABLE17
  * @brief
  * @{
  */
#define BIT_MASK_BANDEDGE_CFG                    ((u32)0x00000003 << 30)           /*!< R/W 0x0  */
#define BIT_BANDEDGE_CFG(x)                      (((u32)((x) & 0x00000003) << 30))
#define BIT_GET_BANDEDGE_CFG(x)                  ((u32)(((x >> 30) & 0x00000003)))
#define BIT_MASK_F_RATE_IDX                      ((u32)0x0000000F << 26)           /*!< R/W 0x0  */
#define BIT_F_RATE_IDX(x)                        (((u32)((x) & 0x0000000F) << 26))
#define BIT_GET_F_RATE_IDX(x)                    ((u32)(((x >> 26) & 0x0000000F)))
#define BIT_MASK_F_FORMAT                        ((u32)0x0000000F << 22)           /*!< R/W 0x0  */
#define BIT_F_FORMAT(x)                          (((u32)((x) & 0x0000000F) << 22))
#define BIT_GET_F_FORMAT(x)                      ((u32)(((x >> 22) & 0x0000000F)))
#define BIT_MASK_BANDEDGE_NONLEGACY_RATEIDX_TH   ((u32)0x0000000F << 18)           /*!< R/W 7h  */
#define BIT_BANDEDGE_NONLEGACY_RATEIDX_TH(x)     (((u32)((x) & 0x0000000F) << 18))
#define BIT_GET_BANDEDGE_NONLEGACY_RATEIDX_TH(x) ((u32)(((x >> 18) & 0x0000000F)))
#define BIT_MASK_BANDEDGE_LEGACY_RATEIDX_TH      ((u32)0x0000000F << 14)           /*!< R/W 7h  */
#define BIT_BANDEDGE_LEGACY_RATEIDX_TH(x)        (((u32)((x) & 0x0000000F) << 14))
#define BIT_GET_BANDEDGE_LEGACY_RATEIDX_TH(x)    ((u32)(((x >> 14) & 0x0000000F)))
#define BIT_MASK_TSSI_CTRL_MAC_DBG_SEL           ((u32)0x0000003F << 8)            /*!< R/W 0x0  */
#define BIT_TSSI_CTRL_MAC_DBG_SEL(x)             (((u32)((x) & 0x0000003F) << 8))
#define BIT_GET_TSSI_CTRL_MAC_DBG_SEL(x)         ((u32)(((x >> 8) & 0x0000003F)))
#define BIT_MASK_VHT_INIT_OFST_SEG0_DB           ((u32)0x000000FF << 0)            /*!< R/W 0x0  */
#define BIT_VHT_INIT_OFST_SEG0_DB(x)             (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_VHT_INIT_OFST_SEG0_DB(x)         ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_AX_PWR_TSSI_TABLE18
  * @brief
  * @{
  */
#define BIT_F_HEER_BANDEDGE_IND_VAL     ((u32)0x00000001 << 30)          /*!< R/W 0x0  */
#define BIT_F_HEER_BANDEDGE_IND_EN      ((u32)0x00000001 << 29)          /*!< R/W 0x0  */
#define BIT_F_FORMAT_EN                 ((u32)0x00000001 << 28)          /*!< R/W 0x0  */
#define BIT_F_FAST_MODE_COMP_INIT_EN    ((u32)0x00000001 << 27)          /*!< R/W 0x1  */
#define BIT_F_DBW_EN                    ((u32)0x00000001 << 26)          /*!< R/W 0x0  */
#define BIT_F_CBW_EN                    ((u32)0x00000001 << 24)          /*!< R/W 0x0  */
#define BIT_F_BMODE_OFST_OUT_EN         ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_F_BMODE_BANDEDGE_IND_VAL    ((u32)0x00000001 << 19)          /*!< R/W 0x0  */
#define BIT_F_BMODE_BANDEDGE_IND_EN     ((u32)0x00000001 << 18)          /*!< R/W 0x0  */
#define BIT_F_BANDEDGE_CFG_SUSTBC_EN    ((u32)0x00000001 << 17)          /*!< R/W 0x1  */
#define BIT_F_BANDEDGE_CFG_SUDCM_EN     ((u32)0x00000001 << 16)          /*!< R/W 0x1  */
#define BIT_F_BANDEDGE_CFG_SUBF_EN      ((u32)0x00000001 << 15)          /*!< R/W 0x0  */
#define BIT_F_BANDEDGE_CFG_NDP_EN       ((u32)0x00000001 << 14)          /*!< R/W 0x0  */
#define BIT_F_BANDEDGE_CFG_HETB_EN      ((u32)0x00000001 << 12)          /*!< R/W 0x0  */
#define BIT_MASK_F_PRECODING_MODE_IDX   ((u32)0x00000003 << 8)           /*!< R/W 0x0  */
#define BIT_F_PRECODING_MODE_IDX(x)     (((u32)((x) & 0x00000003) << 8))
#define BIT_GET_F_PRECODING_MODE_IDX(x) ((u32)(((x >> 8) & 0x00000003)))
#define BIT_MASK_F_DBW                  ((u32)0x00000003 << 6)           /*!< R/W 0x0  */
#define BIT_F_DBW(x)                    (((u32)((x) & 0x00000003) << 6))
#define BIT_GET_F_DBW(x)                ((u32)(((x >> 6) & 0x00000003)))
#define BIT_MASK_F_CBW                  ((u32)0x00000003 << 4)           /*!< R/W 0x0  */
#define BIT_F_CBW(x)                    (((u32)((x) & 0x00000003) << 4))
#define BIT_GET_F_CBW(x)                ((u32)(((x >> 4) & 0x00000003)))
#define BIT_MASK_F_TXSC                 ((u32)0x0000000F << 0)           /*!< R/W 0x0  */
#define BIT_F_TXSC(x)                   (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_F_TXSC(x)               ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_AX_PWR_TSSI_TABLE19
  * @brief
  * @{
  */
#define BIT_F_IS_SU_STBC            ((u32)0x00000001 << 31) /*!< R/W 0x0  */
#define BIT_F_IS_SU_DCM_EN          ((u32)0x00000001 << 30) /*!< R/W 0x0  */
#define BIT_F_IS_SU_DCM             ((u32)0x00000001 << 29) /*!< R/W 0x0  */
#define BIT_F_IS_NDP_EN             ((u32)0x00000001 << 28) /*!< R/W 0x0  */
#define BIT_F_IS_NDP                ((u32)0x00000001 << 27) /*!< R/W 0x0  */
#define BIT_F_HT_OFST_OUT_EN        ((u32)0x00000001 << 26) /*!< R/W 0x0  */
#define BIT_F_HT_BANDEDGE_IND_VAL   ((u32)0x00000001 << 22) /*!< R/W 0x0  */
#define BIT_F_HT_BANDEDGE_IND_EN    ((u32)0x00000001 << 21) /*!< R/W 0x0  */
#define BIT_F_HETB_OFST_OUT_EN      ((u32)0x00000001 << 20) /*!< R/W 0x0  */
#define BIT_F_HETB_BANDEDGE_IND_VAL ((u32)0x00000001 << 16) /*!< R/W 0x0  */
#define BIT_F_HETB_BANDEDGE_IND_EN  ((u32)0x00000001 << 15) /*!< R/W 0x0  */
#define BIT_F_HESU_OFST_OUT_EN      ((u32)0x00000001 << 14) /*!< R/W 0x0  */
#define BIT_F_HESU_BANDEDGE_IND_VAL ((u32)0x00000001 << 10) /*!< R/W 0x0  */
#define BIT_F_HESU_BANDEDGE_IND_EN  ((u32)0x00000001 << 9)  /*!< R/W 0x0  */
#define BIT_F_HEER_OFST_OUT_EN      ((u32)0x00000001 << 2)  /*!< R/W 0x0  */
/** @} */

/** @defgroup REG_AX_PWR_TSSI_TABLE20
  * @brief
  * @{
  */
#define BIT_TSSI_CTRL_MAC_USE_NORMAL_RATE_IDX_ONLY ((u32)0x00000001 << 22) /*!< R/W 0x0  */
#define BIT_TSSI_CTRL_MAC_DBG_DIS                  ((u32)0x00000001 << 21) /*!< R/W 0x0  */
#define BIT_TSSI_CTRL_MAC_CLR                      ((u32)0x00000001 << 20) /*!< R/W 0x0  */
#define BIT_HETB_PWR_MSR_MODE                      ((u32)0x00000001 << 19) /*!< R/W 0x1  */
#define BIT_F_VHT_OFST_OUT_EN                      ((u32)0x00000001 << 18) /*!< R/W 0x0  */
#define BIT_F_VHT_BANDEDGE_IND_VAL                 ((u32)0x00000001 << 14) /*!< R/W 0x0  */
#define BIT_F_VHT_BANDEDGE_IND_EN                  ((u32)0x00000001 << 13) /*!< R/W 0x0  */
#define BIT_F_TXSC_EN                              ((u32)0x00000001 << 12) /*!< R/W 0x0  */
#define BIT_F_TSSI_CTRL_OUT_EN                     ((u32)0x00000001 << 11) /*!< R/W 0x0  */
#define BIT_F_TSSI_CTRL_FAST_MODE_IDX_EN           ((u32)0x00000001 << 10) /*!< R/W 0x0  */
#define BIT_F_TSSI_CTRL_FAST_MODE_IDX              ((u32)0x00000001 << 9)  /*!< R/W 0x0  */
#define BIT_F_RATE_IDX_EN                          ((u32)0x00000001 << 8)  /*!< R/W 0x0  */
#define BIT_F_PRECODING_MODE_IDX_EN                ((u32)0x00000001 << 7)  /*!< R/W 0x0  */
#define BIT_F_LEGACY_OFST_OUT_EN                   ((u32)0x00000001 << 6)  /*!< R/W 0x0  */
#define BIT_F_LEGACY_BANDEDGE_IND_VAL              ((u32)0x00000001 << 2)  /*!< R/W 0x0  */
#define BIT_F_LEGACY_BANDEDGE_IND_EN               ((u32)0x00000001 << 1)  /*!< R/W 0x0  */
#define BIT_F_IS_SU_STBC_EN                        ((u32)0x00000001 << 0)  /*!< R/W 0x0  */
/** @} */

/*==========REG_TXPWR Register Address Definition==========*/
#define REG_AX_PWR_RATE_CTRL                        0xD200
#define REG_AX_PWR_RATE_OFST_CTRL                   0xD204
#define REG_AX_PWR_LMT_CTRL                         0xD208
#define REG_AX_PWR_MACID_CTRL                       0xD20C
#define REG_AX_PWR_BF_CTRL                          0xD210
#define REG_AX_PWR_MACID_REG                        0xD214
#define REG_AX_PWR_MACID_REG2                       0xD218
#define REG_AX_PWR_RU_LMT_CTRL                      0xD21C
#define REG_AX_PWR_COEXT_CTRL                       0xD220
#define REG_AX_PWR_SWING_LEG_CTRL                   0xD224
#define REG_AX_PWR_SWING_VHT_CTRL                   0xD228
#define REG_AX_PWR_SWING_HE_CTRL                    0xD22C
#define REG_AX_PWR_SWING_OTHER_CTRL0                0xD230
#define REG_AX_PWR_SWING_OTHER_CTRL1                0xD234
#define REG_AX_PWR_SR_CTRL0                         0xD238
#define REG_AX_PWR_SR_CTRL1                         0xD23C
#define REG_AX_PWR_UL_CTRL0                         0xD240
#define REG_AX_PWR_UL_CTRL1                         0xD244
#define REG_AX_PWR_UL_CTRL2                         0xD248
#define REG_AX_PWR_UL_CTRL3                         0xD24C
#define REG_AX_PWR_UL_CTRL4                         0xD250
#define REG_AX_PWR_UL_CTRL5                         0xD254
#define REG_AX_PWR_UL_CTRL6                         0xD258
#define REG_AX_PWR_NORM_FORCE0                      0xD25C
#define REG_AX_PWR_NORM_FORCE1                      0xD260
#define REG_AX_PWR_SR_FORCE0                        0xD264
#define REG_AX_PWR_SR_FORCE1                        0xD268
#define REG_AX_PWR_SR_FORCE2                        0xD26C
#define REG_AX_PWR_UL_FORCE0                        0xD270
#define REG_AX_PWR_NORM_FORCE2                      0xD274
#define REG_AX_PWR_UL_FORCE1                        0xD278
#define REG_AX_PWR_NORM_FORCE3                      0xD27C
#define REG_AX_PWR_NORM_FORCE4                      0xD280
#define REG_AX_PWR_RSVD0                            0xD284
#define REG_AX_PWR_RSVD1                            0xD288
#define REG_AX_PWR_RSVD2                            0xD28C
#define REG_AX_PWR_RSVD3                            0xD290
#define REG_AX_PWR_RSVD4                            0xD294
#define REG_AX_PWR_RSVD5                            0xD298
#define REG_AX_PWR_RSVD6                            0xD29C
#define REG_AX_PWR_RSVD7                            0xD2A0
#define REG_AX_PWR_RSVD8                            0xD2A4
#define REG_AX_PWR_BY_RATE_TABLE0                   0xD2C0
#define REG_AX_PWR_BY_RATE_TABLE1                   0xD2C4
#define REG_AX_PWR_BY_RATE_TABLE2                   0xD2C8
#define REG_AX_PWR_BY_RATE_TABLE3                   0xD2CC
#define REG_AX_PWR_BY_RATE_TABLE4                   0xD2D0
#define REG_AX_PWR_BY_RATE_TABLE5                   0xD2D4
#define REG_AX_PWR_BY_RATE_TABLE6                   0xD2D8
#define REG_AX_PWR_BY_RATE_TABLE7                   0xD2DC
#define REG_AX_PWR_BY_RATE_TABLE8                   0xD2E0
#define REG_AX_PWR_BY_RATE_TABLE9                   0xD2E4
#define REG_AX_PWR_BY_RATE_TABLE10                  0xD2E8
#define REG_AX_PWR_LMT_TABLE0                       0xD2EC
#define REG_AX_PWR_LMT_TABLE1                       0xD2F0
#define REG_AX_PWR_LMT_TABLE2                       0xD2F4
#define REG_AX_PWR_LMT_TABLE3                       0xD2F8
#define REG_AX_PWR_LMT_TABLE4                       0xD2FC
#define REG_AX_PWR_LMT_TABLE5                       0xD300
#define REG_AX_PWR_LMT_TABLE6                       0xD304
#define REG_AX_PWR_LMT_TABLE7                       0xD308
#define REG_AX_PWR_LMT_TABLE8                       0xD30C
#define REG_AX_PWR_LMT_TABLE9                       0xD310
#define REG_AX_PWR_LMT_TABLE10                      0xD314
#define REG_AX_PWR_LMT_TABLE11                      0xD318
#define REG_AX_PWR_LMT_TABLE12                      0xD31C
#define REG_AX_PWR_LMT_TABLE13                      0xD320
#define REG_AX_PWR_LMT_TABLE14                      0xD324
#define REG_AX_PWR_LMT_TABLE15                      0xD328
#define REG_AX_PWR_LMT_TABLE16                      0xD32C
#define REG_AX_PWR_LMT_TABLE17                      0xD330
#define REG_AX_PWR_LMT_TABLE18                      0xD334
#define REG_AX_PWR_LMT_TABLE19                      0xD338
#define REG_AX_PWR_RU_LMT_TABLE0                    0xD33C
#define REG_AX_PWR_RU_LMT_TABLE1                    0xD340
#define REG_AX_PWR_RU_LMT_TABLE2                    0xD344
#define REG_AX_PWR_RU_LMT_TABLE3                    0xD348
#define REG_AX_PWR_RU_LMT_TABLE4                    0xD34C
#define REG_AX_PWR_RU_LMT_TABLE5                    0xD350
#define REG_AX_PWR_RU_LMT_TABLE6                    0xD354
#define REG_AX_PWR_RU_LMT_TABLE7                    0xD358
#define REG_AX_PWR_RU_LMT_TABLE8                    0xD35C
#define REG_AX_PWR_RU_LMT_TABLE9                    0xD360
#define REG_AX_PWR_RU_LMT_TABLE10                   0xD364
#define REG_AX_PWR_RU_LMT_TABLE11                   0xD368
#define REG_AX_PWR_MACID_LMT_TABLE0                 0xD36C
#define REG_AX_PWR_MACID_LMT_TABLE1                 0xD370
#define REG_AX_PWR_MACID_LMT_TABLE2                 0xD374
#define REG_AX_PWR_MACID_LMT_TABLE3                 0xD378
#define REG_AX_PWR_MACID_LMT_TABLE4                 0xD37C
#define REG_AX_PWR_MACID_LMT_TABLE5                 0xD380
#define REG_AX_PWR_MACID_LMT_TABLE6                 0xD384
#define REG_AX_PWR_MACID_LMT_TABLE7                 0xD388
#define REG_AX_PWR_MACID_LMT_TABLE8                 0xD38C
#define REG_AX_PWR_MACID_LMT_TABLE9                 0xD390
#define REG_AX_PWR_MACID_LMT_TABLE10                0xD394
#define REG_AX_PWR_MACID_LMT_TABLE11                0xD398
#define REG_AX_PWR_MACID_LMT_TABLE12                0xD39C
#define REG_AX_PWR_MACID_LMT_TABLE13                0xD3A0
#define REG_AX_PWR_MACID_LMT_TABLE14                0xD3A4
#define REG_AX_PWR_MACID_LMT_TABLE15                0xD3A8
#define REG_AX_PWR_MACID_LMT_TABLE16                0xD3AC
#define REG_AX_PWR_MACID_LMT_TABLE17                0xD3B0
#define REG_AX_PWR_MACID_LMT_TABLE18                0xD3B4
#define REG_AX_PWR_MACID_LMT_TABLE19                0xD3B8
#define REG_AX_PWR_MACID_LMT_TABLE20                0xD3BC
#define REG_AX_PWR_MACID_LMT_TABLE21                0xD3C0
#define REG_AX_PWR_MACID_LMT_TABLE22                0xD3C4
#define REG_AX_PWR_MACID_LMT_TABLE23                0xD3C8
#define REG_AX_PWR_MACID_LMT_TABLE24                0xD3CC
#define REG_AX_PWR_MACID_LMT_TABLE25                0xD3D0
#define REG_AX_PWR_MACID_LMT_TABLE26                0xD3D4
#define REG_AX_PWR_MACID_LMT_TABLE27                0xD3D8
#define REG_AX_PWR_MACID_LMT_TABLE28                0xD3DC
#define REG_AX_PWR_MACID_LMT_TABLE29                0xD3E0
#define REG_AX_PWR_MACID_LMT_TABLE30                0xD3E4
#define REG_AX_PWR_MACID_LMT_TABLE31                0xD3E8
#define REG_AX_PWR_MACID_LMT_TABLE32                0xD3EC
#define REG_AX_PWR_MACID_LMT_TABLE33                0xD3F0
#define REG_AX_PWR_MACID_LMT_TABLE34                0xD3F4
#define REG_AX_PWR_MACID_LMT_TABLE35                0xD3F8
#define REG_AX_PWR_MACID_LMT_TABLE36                0xD3FC
#define REG_AX_PWR_MACID_LMT_TABLE37                0xD400
#define REG_AX_PWR_MACID_LMT_TABLE38                0xD404
#define REG_AX_PWR_MACID_LMT_TABLE39                0xD408
#define REG_AX_PWR_MACID_LMT_TABLE40                0xD40C
#define REG_AX_PWR_MACID_LMT_TABLE41                0xD410
#define REG_AX_PWR_MACID_LMT_TABLE42                0xD414
#define REG_AX_PWR_MACID_LMT_TABLE43                0xD418
#define REG_AX_PWR_MACID_LMT_TABLE44                0xD41C
#define REG_AX_PWR_MACID_LMT_TABLE45                0xD420
#define REG_AX_PWR_MACID_LMT_TABLE46                0xD424
#define REG_AX_PWR_MACID_LMT_TABLE47                0xD428
#define REG_AX_PWR_MACID_LMT_TABLE48                0xD42C
#define REG_AX_PWR_MACID_LMT_TABLE49                0xD430
#define REG_AX_PWR_MACID_LMT_TABLE50                0xD434
#define REG_AX_PWR_MACID_LMT_TABLE51                0xD438
#define REG_AX_PWR_MACID_LMT_TABLE52                0xD43C
#define REG_AX_PWR_MACID_LMT_TABLE53                0xD440
#define REG_AX_PWR_MACID_LMT_TABLE54                0xD444
#define REG_AX_PWR_MACID_LMT_TABLE55                0xD448
#define REG_AX_PWR_MACID_LMT_TABLE56                0xD44C
#define REG_AX_PWR_MACID_LMT_TABLE57                0xD450
#define REG_AX_PWR_MACID_LMT_TABLE58                0xD454
#define REG_AX_PWR_MACID_LMT_TABLE59                0xD458
#define REG_AX_PWR_MACID_LMT_TABLE60                0xD45C
#define REG_AX_PWR_MACID_LMT_TABLE61                0xD460
#define REG_AX_PWR_MACID_LMT_TABLE62                0xD464
#define REG_AX_PWR_MACID_LMT_TABLE63                0xD468
#define REG_AX_PWR_MACID_LMT_TABLE64                0xD46C
#define REG_AX_PWR_MACID_LMT_TABLE65                0xD470
#define REG_AX_PWR_MACID_LMT_TABLE66                0xD474
#define REG_AX_PWR_MACID_LMT_TABLE67                0xD478
#define REG_AX_PWR_MACID_LMT_TABLE68                0xD47C
#define REG_AX_PWR_MACID_LMT_TABLE69                0xD480
#define REG_AX_PWR_MACID_LMT_TABLE70                0xD484
#define REG_AX_PWR_MACID_LMT_TABLE71                0xD488
#define REG_AX_PWR_MACID_LMT_TABLE72                0xD48C
#define REG_AX_PWR_MACID_LMT_TABLE73                0xD490
#define REG_AX_PWR_MACID_LMT_TABLE74                0xD494
#define REG_AX_PWR_MACID_LMT_TABLE75                0xD498
#define REG_AX_PWR_MACID_LMT_TABLE76                0xD49C
#define REG_AX_PWR_MACID_LMT_TABLE77                0xD4A0
#define REG_AX_PWR_MACID_LMT_TABLE78                0xD4A4
#define REG_AX_PWR_MACID_LMT_TABLE79                0xD4A8
#define REG_AX_PWR_MACID_LMT_TABLE80                0xD4AC
#define REG_AX_PWR_MACID_LMT_TABLE81                0xD4B0
#define REG_AX_PWR_MACID_LMT_TABLE82                0xD4B4
#define REG_AX_PWR_MACID_LMT_TABLE83                0xD4B8
#define REG_AX_PWR_MACID_LMT_TABLE84                0xD4BC
#define REG_AX_PWR_MACID_LMT_TABLE85                0xD4C0
#define REG_AX_PWR_MACID_LMT_TABLE86                0xD4C4
#define REG_AX_PWR_MACID_LMT_TABLE87                0xD4C8
#define REG_AX_PWR_MACID_LMT_TABLE88                0xD4CC
#define REG_AX_PWR_MACID_LMT_TABLE89                0xD4D0
#define REG_AX_PWR_MACID_LMT_TABLE90                0xD4D4
#define REG_AX_PWR_MACID_LMT_TABLE91                0xD4D8
#define REG_AX_PWR_MACID_LMT_TABLE92                0xD4DC
#define REG_AX_PWR_MACID_LMT_TABLE93                0xD4E0
#define REG_AX_PWR_MACID_LMT_TABLE94                0xD4E4
#define REG_AX_PWR_MACID_LMT_TABLE95                0xD4E8
#define REG_AX_PWR_MACID_LMT_TABLE96                0xD4EC
#define REG_AX_PWR_MACID_LMT_TABLE97                0xD4F0
#define REG_AX_PWR_MACID_LMT_TABLE98                0xD4F4
#define REG_AX_PWR_MACID_LMT_TABLE99                0xD4F8
#define REG_AX_PWR_MACID_LMT_TABLE100               0xD4FC
#define REG_AX_PWR_MACID_LMT_TABLE101               0xD500
#define REG_AX_PWR_MACID_LMT_TABLE102               0xD504
#define REG_AX_PWR_MACID_LMT_TABLE103               0xD508
#define REG_AX_PWR_MACID_LMT_TABLE104               0xD50C
#define REG_AX_PWR_MACID_LMT_TABLE105               0xD510
#define REG_AX_PWR_MACID_LMT_TABLE106               0xD514
#define REG_AX_PWR_MACID_LMT_TABLE107               0xD518
#define REG_AX_PWR_MACID_LMT_TABLE108               0xD51C
#define REG_AX_PWR_MACID_LMT_TABLE109               0xD520
#define REG_AX_PWR_MACID_LMT_TABLE110               0xD524
#define REG_AX_PWR_MACID_LMT_TABLE111               0xD528
#define REG_AX_PWR_MACID_LMT_TABLE112               0xD52C
#define REG_AX_PWR_MACID_LMT_TABLE113               0xD530
#define REG_AX_PWR_MACID_LMT_TABLE114               0xD534
#define REG_AX_PWR_MACID_LMT_TABLE115               0xD538
#define REG_AX_PWR_MACID_LMT_TABLE116               0xD53C
#define REG_AX_PWR_MACID_LMT_TABLE117               0xD540
#define REG_AX_PWR_MACID_LMT_TABLE118               0xD544
#define REG_AX_PWR_MACID_LMT_TABLE119               0xD548
#define REG_AX_PWR_MACID_LMT_TABLE120               0xD54C
#define REG_AX_PWR_MACID_LMT_TABLE121               0xD550
#define REG_AX_PWR_MACID_LMT_TABLE122               0xD554
#define REG_AX_PWR_MACID_LMT_TABLE123               0xD558
#define REG_AX_PWR_MACID_LMT_TABLE124               0xD55C
#define REG_AX_PWR_MACID_LMT_TABLE125               0xD560
#define REG_AX_PWR_MACID_LMT_TABLE126               0xD564
#define REG_AX_PWR_MACID_LMT_TABLE127               0xD568
#define REG_AX_PWR_SR_MCS0_TXDIFF_TABLE0            0xD56C
#define REG_AX_PWR_SR_MCS0_TXDIFF_TABLE1            0xD570
#define REG_AX_PWR_SR_MCS0_TXDIFF_TABLE2            0xD574
#define REG_AX_PWR_SR_MCS0_TXDIFF_TABLE3            0xD578
#define REG_AX_PWR_SR_MCS1_TXDIFF_TABLE0            0xD57C
#define REG_AX_PWR_SR_MCS1_TXDIFF_TABLE1            0xD580
#define REG_AX_PWR_SR_MCS1_TXDIFF_TABLE2            0xD584
#define REG_AX_PWR_SR_MCS1_TXDIFF_TABLE3            0xD588
#define REG_AX_PWR_SR_MCS2_TXDIFF_TABLE0            0xD58C
#define REG_AX_PWR_SR_MCS2_TXDIFF_TABLE1            0xD590
#define REG_AX_PWR_SR_MCS2_TXDIFF_TABLE2            0xD594
#define REG_AX_PWR_SR_MCS2_TXDIFF_TABLE3            0xD598
#define REG_AX_PWR_SR_MCS3_TXDIFF_TABLE0            0xD59C
#define REG_AX_PWR_SR_MCS3_TXDIFF_TABLE1            0xD5A0
#define REG_AX_PWR_SR_MCS3_TXDIFF_TABLE2            0xD5A4
#define REG_AX_PWR_SR_MCS3_TXDIFF_TABLE3            0xD5A8
#define REG_AX_PWR_SR_MCS4_TXDIFF_TABLE0            0xD5AC
#define REG_AX_PWR_SR_MCS4_TXDIFF_TABLE1            0xD5B0
#define REG_AX_PWR_SR_MCS4_TXDIFF_TABLE2            0xD5B4
#define REG_AX_PWR_SR_MCS4_TXDIFF_TABLE3            0xD5B8
#define REG_AX_PWR_SR_MCS5_TXDIFF_TABLE0            0xD5BC
#define REG_AX_PWR_SR_MCS5_TXDIFF_TABLE1            0xD5C0
#define REG_AX_PWR_SR_MCS5_TXDIFF_TABLE2            0xD5C4
#define REG_AX_PWR_SR_MCS5_TXDIFF_TABLE3            0xD5C8
#define REG_AX_PWR_SR_MCS6_TXDIFF_TABLE0            0xD5CC
#define REG_AX_PWR_SR_MCS6_TXDIFF_TABLE1            0xD5D0
#define REG_AX_PWR_SR_MCS6_TXDIFF_TABLE2            0xD5D4
#define REG_AX_PWR_SR_MCS6_TXDIFF_TABLE3            0xD5D8
#define REG_AX_PWR_SR_MCS7_TXDIFF_TABLE0            0xD5DC
#define REG_AX_PWR_SR_MCS7_TXDIFF_TABLE1            0xD5E0
#define REG_AX_PWR_SR_MCS7_TXDIFF_TABLE2            0xD5E4
#define REG_AX_PWR_SR_MCS7_TXDIFF_TABLE3            0xD5E8
#define REG_AX_PWR_SR_MCS8_TXDIFF_TABLE0            0xD5EC
#define REG_AX_PWR_SR_MCS8_TXDIFF_TABLE1            0xD5F0
#define REG_AX_PWR_SR_MCS8_TXDIFF_TABLE2            0xD5F4
#define REG_AX_PWR_SR_MCS8_TXDIFF_TABLE3            0xD5F8
#define REG_AX_PWR_SR_MCS9_TXDIFF_TABLE0            0xD5FC
#define REG_AX_PWR_SR_MCS9_TXDIFF_TABLE1            0xD600
#define REG_AX_PWR_SR_MCS9_TXDIFF_TABLE2            0xD604
#define REG_AX_PWR_SR_MCS9_TXDIFF_TABLE3            0xD608
#define REG_AX_PWR_SR_MCS10_TXDIFF_TABLE0           0xD60C
#define REG_AX_PWR_SR_MCS10_TXDIFF_TABLE1           0xD610
#define REG_AX_PWR_SR_MCS10_TXDIFF_TABLE2           0xD614
#define REG_AX_PWR_SR_MCS10_TXDIFF_TABLE3           0xD618
#define REG_AX_PWR_SR_MCS11_TXDIFF_TABLE0           0xD61C
#define REG_AX_PWR_SR_MCS11_TXDIFF_TABLE1           0xD620
#define REG_AX_PWR_SR_MCS11_TXDIFF_TABLE2           0xD624
#define REG_AX_PWR_SR_MCS11_TXDIFF_TABLE3           0xD628
#define REG_AX_PWR_CCK1M_TXDIFF_TABLE0              0xD62C
#define REG_AX_PWR_CCK1M_TXDIFF_TABLE1              0xD630
#define REG_AX_PWR_CCK1M_TXDIFF_TABLE2              0xD634
#define REG_AX_PWR_CCK1M_TXDIFF_TABLE3              0xD638
#define REG_AX_PWR_CCK2M_TXDIFF_TABLE0              0xD63C
#define REG_AX_PWR_CCK2M_TXDIFF_TABLE1              0xD640
#define REG_AX_PWR_CCK2M_TXDIFF_TABLE2              0xD644
#define REG_AX_PWR_CCK2M_TXDIFF_TABLE3              0xD648
#define REG_AX_PWR_CCK5P5M_TXDIFF_TABLE0            0xD64C
#define REG_AX_PWR_CCK5P5M_TXDIFF_TABLE1            0xD650
#define REG_AX_PWR_CCK5P5M_TXDIFF_TABLE2            0xD654
#define REG_AX_PWR_CCK5P5M_TXDIFF_TABLE3            0xD658
#define REG_AX_PWR_CCK11M_TXDIFF_TABLE0             0xD65C
#define REG_AX_PWR_CCK11M_TXDIFF_TABLE1             0xD660
#define REG_AX_PWR_CCK11M_TXDIFF_TABLE2             0xD664
#define REG_AX_PWR_CCK11M_TXDIFF_TABLE3             0xD668
#define REG_AX_PWR_LEGACY6M_TXDIFF_TABLE0           0xD66C
#define REG_AX_PWR_LEGACY6M_TXDIFF_TABLE1           0xD670
#define REG_AX_PWR_LEGACY6M_TXDIFF_TABLE2           0xD674
#define REG_AX_PWR_LEGACY6M_TXDIFF_TABLE3           0xD678
#define REG_AX_PWR_LEGACY9M_TXDIFF_TABLE0           0xD67C
#define REG_AX_PWR_LEGACY9M_TXDIFF_TABLE1           0xD680
#define REG_AX_PWR_LEGACY9M_TXDIFF_TABLE2           0xD684
#define REG_AX_PWR_LEGACY9M_TXDIFF_TABLE3           0xD688
#define REG_AX_PWR_LEGACY12M_TXDIFF_TABLE0          0xD68C
#define REG_AX_PWR_LEGACY12M_TXDIFF_TABLE1          0xD690
#define REG_AX_PWR_LEGACY12M_TXDIFF_TABLE2          0xD694
#define REG_AX_PWR_LEGACY12M_TXDIFF_TABLE3          0xD698
#define REG_AX_PWR_LEGACY18M_TXDIFF_TABLE0          0xD69C
#define REG_AX_PWR_LEGACY18M_TXDIFF_TABLE1          0xD6A0
#define REG_AX_PWR_LEGACY18M_TXDIFF_TABLE2          0xD6A4
#define REG_AX_PWR_LEGACY18M_TXDIFF_TABLE3          0xD6A8
#define REG_AX_PWR_LEGACY24M_TXDIFF_TABLE0          0xD6AC
#define REG_AX_PWR_LEGACY24M_TXDIFF_TABLE1          0xD6B0
#define REG_AX_PWR_LEGACY24M_TXDIFF_TABLE2          0xD6B4
#define REG_AX_PWR_LEGACY24M_TXDIFF_TABLE3          0xD6B8
#define REG_AX_PWR_LEGACY36M_TXDIFF_TABLE0          0xD6BC
#define REG_AX_PWR_LEGACY36M_TXDIFF_TABLE1          0xD6C0
#define REG_AX_PWR_LEGACY36M_TXDIFF_TABLE2          0xD6C4
#define REG_AX_PWR_LEGACY36M_TXDIFF_TABLE3          0xD6C8
#define REG_AX_PWR_LEGACY48M_TXDIFF_TABLE0          0xD6CC
#define REG_AX_PWR_LEGACY48M_TXDIFF_TABLE1          0xD6D0
#define REG_AX_PWR_LEGACY48M_TXDIFF_TABLE2          0xD6D4
#define REG_AX_PWR_LEGACY48M_TXDIFF_TABLE3          0xD6D8
#define REG_AX_PWR_LEGACY54M_TXDIFF_TABLE0          0xD6DC
#define REG_AX_PWR_LEGACY54M_TXDIFF_TABLE1          0xD6E0
#define REG_AX_PWR_LEGACY54M_TXDIFF_TABLE2          0xD6E4
#define REG_AX_PWR_LEGACY54M_TXDIFF_TABLE3          0xD6E8
#define REG_AX_PWR_TCM_WRAPPER_CR12                 0xD830
#define REG_AX_PWR_TCM_WRAPPER_CR13                 0xD834
#define REG_AX_PWR_TCM_WRAPPER_CR14                 0xD838
#define REG_AX_PWR_TCM_WRAPPER_CR15                 0xD83C
#define REG_AX_PWR_TCM_WRAPPER_CR16                 0xD840
#define REG_AX_PWR_TCM_WRAPPER_CR17                 0xD844
#define REG_AX_PWR_TCM_WRAPPER_CR18                 0xD848
#define REG_AX_PWR_TSSI_TABLE2                      0xD910
#define REG_AX_PWR_TSSI_TABLE5                      0xD91C
#define REG_AX_PWR_TSSI_TABLE7                      0xD924
#define REG_AX_PWR_TSSI_TABLE8                      0xD928
#define REG_AX_PWR_TSSI_TABLE10                     0xD930
#define REG_AX_PWR_TSSI_TABLE11                     0xD934
#define REG_AX_PWR_TSSI_TABLE12                     0xD938
#define REG_AX_PWR_TSSI_TABLE13                     0xD93C
#define REG_AX_PWR_TSSI_TABLE14                     0xD940
#define REG_AX_PWR_TSSI_TABLE15                     0xD944
#define REG_AX_PWR_TSSI_TABLE16                     0xD948
#define REG_AX_PWR_TSSI_TABLE17                     0xD94C
#define REG_AX_PWR_TSSI_TABLE18                     0xD950
#define REG_AX_PWR_TSSI_TABLE19                     0xD954
#define REG_AX_PWR_TSSI_TABLE20                     0xD958

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