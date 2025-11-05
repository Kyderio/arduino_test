/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _RL7005_CAPTOUCH_H_
#define _RL7005_CAPTOUCH_H_

/** @addtogroup CAPTOUCH
  * @verbatim
  *****************************************************************************************
  * Introduction
  *****************************************************************************************
  * CAPTOUCH:
  *		- Base Address: CAPTOUCH_DEV
  *		- Clock source : 32.768KHz
  *		- Scan interval timer: 1.024KHz(32.768KHz/32)
  *		- Debounce Timer: Configurable
  *		- Channel: 9
  *		- IRQ: CapTouch_IRQ
  *
  *****************************************************************************************
  * How to use Normal CapTouch
  *****************************************************************************************
  *      To use the normal CapTouch mode, the following steps are mandatory:
  *
  *      1. Enable CapTouch peripheral clock
  *
  *      2. Configure the CapTouch pinmux.
  *
  *      3. Init Captouch parameters:
  *			CapTouch_StructInit(CapTouch_InitTypeDef* CapTouch_InitStruct)
  *
  *      4. Init Hardware use step3 parameters:
  *			CapTouch_Init(CAPTOUCH_TypeDef *CapTouch, CapTouch_InitTypeDef* CapTouch_InitStruct)
  *
  *      5. Enable the NVIC and the corresponding interrupt using following function if you need
  *			to use interrupt mode.
  *			CapTouch_INTConfig(): CapTouch IRQ Enable set
  *			CapTouch_INTMask(): CapTouch IRQ mask set
  *			InterruptRegister(): register the captouch irq handler
  *			InterruptEn(): Enable the NVIC interrupt
  *
  *      6. Enable CapTouch module using CapTouch_Cmd().
  *
  *****************************************************************************************
  * @endverbatim
  */

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup CAPTOUCH
  * @brief CAPTOUCH driver modules
  * @{
  */

/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup CAPTOUCH_Register_Definitions CAPTOUCH Register Definitions
  * @{
  */

/** @defgroup CT_CTC_CTRL
  * @brief Captouch Control Register
  * @{
  */
#define CT_BIT_BASELINE_INI ((u32)0x00000001 << 2) /*!< R/W/EC 1h  1: Baseline initial function enable, HW will clear this bit to "0" after baseline initial*/
#define CT_BIT_MODE         ((u32)0x00000001 << 1) /*!< R/W 0h  0: Comparator mode 1: SAR ADC mode*/
#define CT_BIT_ENABLE       ((u32)0x00000001 << 0) /*!< R/W 0h  0: CTC disable 1: CTC enable*/
/** @} */

/** @defgroup CT_SCAN_PERIOD
  * @brief Scan Parameters Register
  * @{
  */
#define CT_MASK_SAMPLE_AVE_CTRL   ((u32)0x00000007 << 29)           /*!< R/W 3'd2  ADC sampled number for average function (SAR ADC mode) average number=2^(sample_ave_ctrl+1)*/
#define CT_SAMPLE_AVE_CTRL(x)     (((u32)((x) & 0x00000007) << 29))
#define CT_GET_SAMPLE_AVE_CTRL(x) ((u32)(((x >> 29) & 0x00000007)))
#define CT_MASK_SLEEP_TIME_CNT    ((u32)0x01FFFFFF << 0)            /*!< R/W 25'hc34ff  clk40M When this register is set to 0, HW will scan continuously and have no sleep time.*/
#define CT_SLEEP_TIME_CNT(x)      (((u32)((x) & 0x01FFFFFF) << 0))
#define CT_GET_SLEEP_TIME_CNT(x)  ((u32)(((x >> 0) & 0x01FFFFFF)))
/** @} */

/** @defgroup CT_ETC_CTRL
  * @brief Environment Tracking Control Register
  * @{
  */
#define CT_MASK_BASELINE_UPD_STEP    ((u32)0x0000000F << 12)           /*!< R/W 1h  Baseline update step for all channel*/
#define CT_BASELINE_UPD_STEP(x)      (((u32)((x) & 0x0000000F) << 12))
#define CT_GET_BASELINE_UPD_STEP(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define CT_MASK_BASELINE_WT_FACTOR   ((u32)0x0000000F << 8)            /*!< R/W 2h  Baseline update weight factor (ETC_factor_th) for all channel ETC_factor_th=2^baseline_wt_factor*/
#define CT_BASELINE_WT_FACTOR(x)     (((u32)((x) & 0x0000000F) << 8))
#define CT_GET_BASELINE_WT_FACTOR(x) ((u32)(((x >> 8) & 0x0000000F)))
#define CT_MASK_ETC_SCAN_INTERVAL    ((u32)0x0000007F << 1)            /*!< R/W 2h  ETC update interval between scan period (sleep time) for all channel Interval=(etc_scan_interval+1)*scan_period*/
#define CT_ETC_SCAN_INTERVAL(x)      (((u32)((x) & 0x0000007F) << 1))
#define CT_GET_ETC_SCAN_INTERVAL(x)  ((u32)(((x >> 1) & 0x0000007F)))
#define CT_BIT_ETC_FUNC_CTRL         ((u32)0x00000001 << 0)            /*!< R/W 0h  Environmental cap tracking calibration function 0: Disable 1: Enable*/
/** @} */

/** @defgroup CT_FIFO_STATUS
  * @brief FIFO Status Register
  * @{
  */
#define CT_BIT_AFIFO_CLEAR        ((u32)0x00000001 << 16)           /*!< WA0 0x0  clear the FIFO data*/
#define CT_MASK_AFIFO_FULL_LVL    ((u32)0x0000003F << 10)           /*!< R/W 0x0  user define the full level for afifo, the valid value is from 0 to 63*/
#define CT_AFIFO_FULL_LVL(x)      (((u32)((x) & 0x0000003F) << 10))
#define CT_GET_AFIFO_FULL_LVL(x)  ((u32)(((x >> 10) & 0x0000003F)))
#define CT_MASK_AFIFO_VALID_CNT   ((u32)0x0000007F << 3)            /*!< R 0h  FIFO valid cnt(push unit number which can be read)*/
#define CT_AFIFO_VALID_CNT(x)     (((u32)((x) & 0x0000007F) << 3))
#define CT_GET_AFIFO_VALID_CNT(x) ((u32)(((x >> 3) & 0x0000007F)))
#define CT_BIT_AFIFO_OVER_LVL     ((u32)0x00000001 << 2)            /*!< R 0x0  0: FIFO not over level 1: FIFO over level*/
#define CT_BIT_AFIFO_EMPTY        ((u32)0x00000001 << 1)            /*!< R 0x1  0: FIFO not empty 1: FIFO empty*/
#define CT_BIT_AFIFO_FULL         ((u32)0x00000001 << 0)            /*!< R 0x0  0: FIFO not oveflow (not full) 1: FIFO overflow(full)*/
/** @} */

/** @defgroup CT_FIFO_READ
  * @brief FIFO Read Register
  * @{
  */
#define CT_BIT_AFIFO_RD_DATA_VLD ((u32)0x00000001 << 31)          /*!< R 0h  Read data from raw code FIFO valid*/
#define CT_BIT_FIFO_MODE         ((u32)0x00000001 << 30)          /*!< R/W 0x0  Controls the write type of FIFO data 1:filtered data 0: raw data*/
#define CT_MASK_AFIFO_RD_DATA    ((u32)0x000FFFFF << 0)           /*!< RP 0h  Read data from FIFO [15:0] : data [19:16] : channel number*/
#define CT_AFIFO_RD_DATA(x)      (((u32)((x) & 0x000FFFFF) << 0))
#define CT_GET_AFIFO_RD_DATA(x)  ((u32)(((x >> 0) & 0x000FFFFF)))
/** @} */

/** @defgroup CT_INTERRUPT_ENABLE0
  * @brief Interrupt Enable Register
  * @{
  */
#define CT_BIT_SCAN_END_INTR_EN        ((u32)0x00000001 << 23) /*!< R/W 0h  sample scan finish enable*/
#define CT_BIT_AFIFO_OVERLVL_INTR_EN   ((u32)0x00000001 << 21) /*!< R/W 0h  Raw code FIFO over level enable*/
#define CT_BIT_OVER_N_NOISE_TH_INTR_EN ((u32)0x00000001 << 20) /*!< R/W 0h  Negative noise threshold overflow enable*/
#define CT_BIT_AFIFO_OVERFLOW_INTR_EN  ((u32)0x00000001 << 19) /*!< R/W 0h  Raw code FIFO overflow enable*/
#define CT_BIT_OVER_P_NOISE_TH_INTR_EN ((u32)0x00000001 << 18) /*!< R/W 0h  Positive noise threshold overflow enable*/
/** @} */

/** @defgroup CT_INTERRUPT_ENABLE1
  * @brief Interrupt Enable Register
  * @{
  */
#define CT_MASK_TOUCH_RELEASE_INTR_EN   ((u32)0x0000FFFF << 16)           /*!< R/W 0h  Channelx single touch release enable, x is 0~8*/
#define CT_TOUCH_RELEASE_INTR_EN(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define CT_GET_TOUCH_RELEASE_INTR_EN(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define CT_MASK_TOUCH_PRESS_INTR_EN     ((u32)0x0000FFFF << 0)            /*!< R/W 0h  Channelx single touch press enable, x is 0~8*/
#define CT_TOUCH_PRESS_INTR_EN(x)       (((u32)((x) & 0x0000FFFF) << 0))
#define CT_GET_TOUCH_PRESS_INTR_EN(x)   ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup CT_INTERRUPT_STATUS0
  * @brief interrupt status register
  * @{
  */
#define CT_BIT_SCAN_END_INTR        ((u32)0x00000001 << 23) /*!< R 0h  sample scan finish interrupt*/
#define CT_BIT_AFIFO_OVERLVL_INTR   ((u32)0x00000001 << 21) /*!< R 0h  Raw code FIFO over level interrupt*/
#define CT_BIT_OVER_N_NOISE_TH_INTR ((u32)0x00000001 << 20) /*!< R 0h  Negative noise threshold overflow interrupt*/
#define CT_BIT_AFIFO_OVERFLOW_INTR  ((u32)0x00000001 << 19) /*!< R 0h  Raw code FIFO overflow interrupt*/
#define CT_BIT_OVER_P_NOISE_TH_INTR ((u32)0x00000001 << 18) /*!< R 0h  Positive noise threshold overflow interrupt*/
/** @} */

/** @defgroup CT_INTERRUPT_STATUS1
  * @brief interrupt status register
  * @{
  */
#define CT_MASK_TOUCH_RELEASE_INTR   ((u32)0x0000FFFF << 16)           /*!< R 0h  Channelx single touch release interrupt, x is  0~8*/
#define CT_TOUCH_RELEASE_INTR(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define CT_GET_TOUCH_RELEASE_INTR(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define CT_MASK_TOUCH_PRESS_INTR     ((u32)0x0000FFFF << 0)            /*!< R 0h  Channelx single touch press interrupt, x is  0~8*/
#define CT_TOUCH_PRESS_INTR(x)       (((u32)((x) & 0x0000FFFF) << 0))
#define CT_GET_TOUCH_PRESS_INTR(x)   ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup CT_RAW_INTERRUPT_STATUS0
  * @brief Raw Interrupt Status Register
  * @{
  */
#define CT_BIT_SCAN_END        ((u32)0x00000001 << 23) /*!< R 0h  sample scan finish raw interrupt*/
#define CT_BIT_AFIFO_OVERLVL   ((u32)0x00000001 << 21) /*!< R 0h  Raw code FIFO over level raw interrupt*/
#define CT_BIT_OVER_N_NOISE_TH ((u32)0x00000001 << 20) /*!< R 0h  Negative noise threshold overflow raw interrupt*/
#define CT_BIT_AFIFO_OVERFLOW  ((u32)0x00000001 << 19) /*!< R 0h  Raw code FIFO overflow raw interrupt*/
#define CT_BIT_OVER_P_NOISE_TH ((u32)0x00000001 << 18) /*!< R 0h  Positive noise threshold overflow raw interrupt*/
/** @} */

/** @defgroup CT_RAW_INTERRUPT_STATUS1
  * @brief Raw Interrupt Status Register
  * @{
  */
#define CT_MASK_TOUCH_RELEASE   ((u32)0x0000FFFF << 16)           /*!< R 0h  Channelx single touch release raw interrupt, x is 0~8*/
#define CT_TOUCH_RELEASE(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define CT_GET_TOUCH_RELEASE(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define CT_MASK_TOUCH_PRESS     ((u32)0x0000FFFF << 0)            /*!< R 0h  Channelx single touch press raw interrupt, x is  0~8*/
#define CT_TOUCH_PRESS(x)       (((u32)((x) & 0x0000FFFF) << 0))
#define CT_GET_TOUCH_PRESS(x)   ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup CT_INTERRUPT_ALL_CLR
  * @brief Interrupt All Clear Register
  * @{
  */
#define CT_BIT_INTR_ALL_CLR ((u32)0x00000001 << 0) /*!< R/WA0 0h  Write "1" to this register to clear the combined interrupts, all individual interrupts, interrupt status register and raw interrupt status register.*/
/** @} */

/** @defgroup CT_INTERRUPT_STATUS_CLR0
  * @brief Interrupt Clear Register
  * @{
  */
#define CT_BIT_SCAN_END_CLR        ((u32)0x00000001 << 23) /*!< R/WA0 0h  sample scan finish raw interrupt and related register*/
#define CT_BIT_AFIFO_OVERLVL_CLR   ((u32)0x00000001 << 21) /*!< R/WA0 0h  Clear raw code FIFO over level raw interrupt and related register*/
#define CT_BIT_OVER_N_NOISE_TH_CLR ((u32)0x00000001 << 20) /*!< R/WA0 0h  Clear negative noise threshold overflow interrupt and related register*/
#define CT_BIT_AFIFO_OVERFLOW_CLR  ((u32)0x00000001 << 19) /*!< R/WA0 0h  Clear raw code FIFO overflow interrupt and related register*/
#define CT_BIT_OVER_P_NOISE_TH_CLR ((u32)0x00000001 << 18) /*!< R/WA0 0h  Clear positive noise threshold overflow interrupt and related register*/
/** @} */

/** @defgroup CT_INTERRUPT_STATUS_CLR1
  * @brief Interrupt Clear Register
  * @{
  */
#define CT_MASK_TOUCH_RELEASE_CLR   ((u32)0x0000FFFF << 16)           /*!< R/WA0 0h  Clear channelx single touch release interrupt and related register*/
#define CT_TOUCH_RELEASE_CLR(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define CT_GET_TOUCH_RELEASE_CLR(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define CT_MASK_TOUCH_PRESS_CLR     ((u32)0x0000FFFF << 0)            /*!< R/WA0 0h  Clear channelx single touch press interrupt and related register*/
#define CT_TOUCH_PRESS_CLR(x)       (((u32)((x) & 0x0000FFFF) << 0))
#define CT_GET_TOUCH_PRESS_CLR(x)   ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup CT_PRS
  * @brief PRS Select Register
  * @{
  */
#define CT_MASK_PRS_LPSR_SEED   ((u32)0x0000000F << 3)           /*!< R/W 1h  lpsr seed. it can't be 0.*/
#define CT_PRS_LPSR_SEED(x)     (((u32)((x) & 0x0000000F) << 3))
#define CT_GET_PRS_LPSR_SEED(x) ((u32)(((x >> 3) & 0x0000000F)))
#define CT_MASK_PRS_SIZE        ((u32)0x00000003 << 1)           /*!< R/W 0h  00: lpsr width is 2 01: lpsr width is 3 10: lpsr width is 4*/
#define CT_PRS_SIZE(x)          (((u32)((x) & 0x00000003) << 1))
#define CT_GET_PRS_SIZE(x)      ((u32)(((x >> 1) & 0x00000003)))
#define CT_BIT_PRS_EN           ((u32)0x00000001 << 0)           /*!< R/W 0h  PRS enable*/
/** @} */

/** @defgroup CT_DEBUG_SEL
  * @brief Debug Select Register
  * @{
  */
#define CT_MASK_DBG_SEL   ((u32)0x00000007 << 0)           /*!< R/W 0h  Debug information selection 0: dbg_clkrst 1: dbg_apbslv 2: dbg_ctrl 3: dbg_decision 4: dbg_adc_arb Others: dbg_clkrst*/
#define CT_DBG_SEL(x)     (((u32)((x) & 0x00000007) << 0))
#define CT_GET_DBG_SEL(x) ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup CT_DEBUG_PORT
  * @brief Debug Register
  * @{
  */
#define CT_MASK_DBG_PORT   ((u32)0xFFFFFFFF << 0)           /*!< R 0h  Debug port output value,depend on dbg_sel value*/
#define CT_DBG_PORT(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define CT_GET_DBG_PORT(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup CT_ECO_USE0
  * @brief ECO USE0 Register
  * @{
  */
#define CT_MASK_ECO_USE0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0h  For ECO use*/
#define CT_ECO_USE0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define CT_GET_ECO_USE0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup CT_ECO_USE1
  * @brief ECO USE1 Register
  * @{
  */
#define CT_MASK_ECO_USE1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0h  For ECO use*/
#define CT_ECO_USE1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define CT_GET_ECO_USE1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup CT_CTC_COMP_VERSION
  * @brief Version Register
  * @{
  */
#define CT_MASK_COMP_VERSION   ((u32)0xFFFFFFFF << 0)           /*!< R/W 20250310h  CTC version number*/
#define CT_COMP_VERSION(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define CT_GET_COMP_VERSION(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup CT_SNR_INF
  * @brief Signal Noise Ratio Register
  * @{
  */
#define CT_MASK_SNR_NOISE_DATA   ((u32)0x0000FFFF << 16)           /*!< RP 0x0  Noise peak to peak signal raw data for SNR monitor*/
#define CT_SNR_NOISE_DATA(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define CT_GET_SNR_NOISE_DATA(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define CT_MASK_SNR_NOISE_CH     ((u32)0x0000000F << 0)            /*!< R/W 0h  Specify which channel you want to read the snr_noise_data data*/
#define CT_SNR_NOISE_CH(x)       (((u32)((x) & 0x0000000F) << 0))
#define CT_GET_SNR_NOISE_CH(x)   ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup CT_CHx_CTRL
  * @brief Channel x Control Register
  * @{
  */
#define CT_MASK_CHx_SC_TIMES   ((u32)0x0000FFFF << 16)           /*!< R/W 16'd400  0~65536 times,  Only used in SAR ADC mode.When the counter reaches the set value, the switching capacitor action is stopped immediately and the voltage sampling is performed after the ADC is ready.The actual value will be one more due to the counter.*/
#define CT_CHx_SC_TIMES(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define CT_GET_CHx_SC_TIMES(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define CT_MASK_CHx_CMP_TH     ((u32)0x00000007 << 8)            /*!< R/W 3'b110  0.5V~0.7V,it has 8 data gear selections. Only used in comparator mode, triggered when the voltage reaches the comparator threshold*/
#define CT_CHx_CMP_TH(x)       (((u32)((x) & 0x00000007) << 8))
#define CT_GET_CHx_CMP_TH(x)   ((u32)(((x >> 8) & 0x00000007)))
#define CT_MASK_CHx_VCCS_G     ((u32)0x0000001F << 3)            /*!< R/W 5'b00100  Compensate current source gear selection. (1/180K) *(50uA+5uA*<4:0>) /10uA*/
#define CT_CHx_VCCS_G(x)       (((u32)((x) & 0x0000001F) << 3))
#define CT_GET_CHx_VCCS_G(x)   ((u32)(((x >> 3) & 0x0000001F)))
#define CT_MASK_CHx_VCCS_SEL   ((u32)0x00000003 << 1)            /*!< R/W 1h  chx_VCCS_sel:   00: SEL_TOUCH_CUR_0V2I_1IBHN, EN_TOUCHCUR_CALI disable ,use default (off mode) 01: SEL_TOUCH_CUR_0V2I_1IBHN = 0; EN_TOUCHCUR_CALI = 0 (normal mode) 10: SEL_TOUCH_CUR_0V2I_1IBHN = 0; EN_TOUCHCUR_CALI = 1 (calibration mode) 11: SEL_TOUCH_CUR_0V2I_1IBHN = 1; EN_TOUCHCUR_CALI = 0 (debug mode)*/
#define CT_CHx_VCCS_SEL(x)     (((u32)((x) & 0x00000003) << 1))
#define CT_GET_CHx_VCCS_SEL(x) ((u32)(((x >> 1) & 0x00000003)))
/** @} */

/** @defgroup CT_CHx_NOISE_TH
  * @brief Channel x Noise Threshold Register
  * @{
  */
#define CT_MASK_CHx_N_ENT   ((u32)0x0000FFFF << 16)           /*!< R/W 28h  The environmental negative noise threshold: the negative maximum capacitance change of raw data that is still considered an environment change.*/
#define CT_CHx_N_ENT(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define CT_GET_CHx_N_ENT(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define CT_MASK_CHx_P_ENT   ((u32)0x0000FFFF << 0)            /*!< R/W 28h  The environmental positive noise threshold: the positive maximum capacitance change of raw data that is still considered an environment change.*/
#define CT_CHx_P_ENT(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define CT_GET_CHx_P_ENT(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup CT_CHx_TOUCH_TH
  * @brief Channel x Threshold Register
  * @{
  */
#define CT_MASK_CHx_A_TOUCH_TH   ((u32)0x0000FFFF << 16)           /*!< R/W/ES 0h  Absolute threshold data of touch judgement for channel x. It can be updated by HW when baseline initial function or ETC function enabled, a_touch_th=baseline-d_touch_th, manual tuning when ETC disabled, (0x0~0xFFF). Recommended data=80%*signal*/
#define CT_CHx_A_TOUCH_TH(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define CT_GET_CHx_A_TOUCH_TH(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define CT_MASK_CHx_D_TOUCH_TH   ((u32)0x0000FFFF << 0)            /*!< R/W 64h  Difference threshold data of touch judgement for channel x. It needs to be configured during development, (0x0~0xFFF) (0~4095).  Init number=0x64 Recommend data=80%*(signal-baseline)*/
#define CT_CHx_D_TOUCH_TH(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define CT_GET_CHx_D_TOUCH_TH(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup CT_CHx_BASELINE_DBC
  * @brief Channel x
  * @{
  */
#define CT_MASK_CHx_BASELINE        ((u32)0x0000FFFF << 16)           /*!< R/W/ES 0h  Digital baseline data of channel x. Init number=0x0 It can be initialed by HW when baseline initial function enabled, and can be updated automatically by HW when ETC function enabled. It could be configured by manual tuning.*/
#define CT_CHx_BASELINE(x)          (((u32)((x) & 0x0000FFFF) << 16))
#define CT_GET_CHx_BASELINE(x)      ((u32)(((x >> 16) & 0x0000FFFF)))
#define CT_MASK_CHx_DEBOUNCE_TIME   ((u32)0x00000003 << 1)            /*!< R/W 0h  2'b00: 2 times 2'b01: 3 times 2'b10: 4 times 2'b11: 5 times*/
#define CT_CHx_DEBOUNCE_TIME(x)     (((u32)((x) & 0x00000003) << 1))
#define CT_GET_CHx_DEBOUNCE_TIME(x) ((u32)(((x >> 1) & 0x00000003)))
#define CT_BIT_CHx_DEBOUNCE_EN      ((u32)0x00000001 << 0)            /*!< R/W 0h  0: Disable 1: Enable*/
/** @} */

/** @defgroup CT_CTC_SETTLE_CTRL
  * @brief Captouch Settle Control Register
  * @{
  */
#define CT_MASK_SETTLE_CNT_CHN_CHG   ((u32)0x0000000F << 4)           /*!< R/W 1h  settle count for sample data from chn switch, the unit is sample clock. 0 means no need to settle*/
#define CT_SETTLE_CNT_CHN_CHG(x)     (((u32)((x) & 0x0000000F) << 4))
#define CT_GET_SETTLE_CNT_CHN_CHG(x) ((u32)(((x >> 4) & 0x0000000F)))
#define CT_MASK_SETTLE_CNT           ((u32)0x0000000F << 0)           /*!< R/W 0h  settle count for sample data from ADC to captouch, the unit is sample clock. 0 means no need to settle*/
#define CT_SETTLE_CNT(x)             (((u32)((x) & 0x0000000F) << 0))
#define CT_GET_SETTLE_CNT(x)         ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup CT_CTC_FILTER_CTRL0
  * @brief Captouch Filter Control0 Register
  * @{
  */
#define CT_BIT_IIR_K_ACC_EN    ((u32)0x00000001 << 12)          /*!< R/W 0h  enable accelerated touch response.*/
#define CT_MASK_IIR_K_ACC      ((u32)0x0000000F << 8)           /*!< R/W 3h  iir filter coef. the range is 0~11.*/
#define CT_IIR_K_ACC(x)        (((u32)((x) & 0x0000000F) << 8))
#define CT_GET_IIR_K_ACC(x)    ((u32)(((x >> 8) & 0x0000000F)))
#define CT_MASK_IIR_K_NORMAL   ((u32)0x0000000F << 4)           /*!< R/W 5h  iir filter coef*/
#define CT_IIR_K_NORMAL(x)     (((u32)((x) & 0x0000000F) << 4))
#define CT_GET_IIR_K_NORMAL(x) ((u32)(((x >> 4) & 0x0000000F)))
#define CT_MASK_MED_COEF       ((u32)0x00000003 << 2)           /*!< R/W 0x1  Median filter coefficient,for raw data 00:disable 01:coef is 3 10:coef is 5 11:coef is 7*/
#define CT_MED_COEF(x)         (((u32)((x) & 0x00000003) << 2))
#define CT_GET_MED_COEF(x)     ((u32)(((x >> 2) & 0x00000003)))
#define CT_BIT_IIR_EN          ((u32)0x00000001 << 1)           /*!< R/W 0x0  Enable ctc iir function,for raw data*/
#define CT_BIT_FLT_EN          ((u32)0x00000001 << 0)           /*!< R/W 0x0  Enable ctc filter function(global),for raw data*/
/** @} */

/** @defgroup CT_CTC_FILTER_CTRL1
  * @brief Captouch Filter Control1 Register
  * @{
  */
#define CT_MASK_NOTCH_COEF_FIR   ((u32)0x0000FFFF << 16)           /*!< R/W 16'h2000  The coefficient of the sliding filter.The divisor.*/
#define CT_NOTCH_COEF_FIR(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define CT_GET_NOTCH_COEF_FIR(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define CT_MASK_NOTCH_COEF       ((u32)0x0000000F << 0)            /*!< R/W 4h  The coefficient of the sliding filter.The window width factor 0,1: disable 2-8: useful*/
#define CT_NOTCH_COEF(x)         (((u32)((x) & 0x0000000F) << 0))
#define CT_GET_NOTCH_COEF(x)     ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup CT_CTC_NOISE_CNT
  * @brief Captouch Noise Cnt Register
  * @{
  */
#define CT_MASK_NOISE_CNT   ((u32)0x00000FFF << 0)           /*!< R/W 12'd200  This parameter is used to set the refresh time of the noise data.The counter is updated after the data has been processed to the last channel*/
#define CT_NOISE_CNT(x)     (((u32)((x) & 0x00000FFF) << 0))
#define CT_GET_NOISE_CNT(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup CT_CTC_DIV_HCNT
  * @brief Captouch Div Hcnt Control Register
  * @{
  */
#define CT_MASK_CTC_CLK_HCNT   ((u32)0x000001FF << 0)           /*!< R/W 9'd4  This field defines sample clock driver high level of  chn.  high level = (ctc_clk_hcnt +1)* ip_clk period*/
#define CT_CTC_CLK_HCNT(x)     (((u32)((x) & 0x000001FF) << 0))
#define CT_GET_CTC_CLK_HCNT(x) ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup CT_CTC_DIV_LCNT0
  * @brief Captouch Div Lcnt Control Register
  * @{
  */
#define CT_MASK_CTC_CLK_LCNT2   ((u32)0x000001FF << 18)           /*!< R/W 9'd5  This field defines sample clock driver  lower level of  chn.  lower level  = ctc_clk_lcnt2 * ip_clk period*/
#define CT_CTC_CLK_LCNT2(x)     (((u32)((x) & 0x000001FF) << 18))
#define CT_GET_CTC_CLK_LCNT2(x) ((u32)(((x >> 18) & 0x000001FF)))
#define CT_MASK_CTC_CLK_LCNT1   ((u32)0x000001FF << 9)            /*!< R/W 9'd5  This field defines sample clock driver lower  level of  chn. lower level  = ctc_clk_lcnt1 * ip_clk period*/
#define CT_CTC_CLK_LCNT1(x)     (((u32)((x) & 0x000001FF) << 9))
#define CT_GET_CTC_CLK_LCNT1(x) ((u32)(((x >> 9) & 0x000001FF)))
#define CT_MASK_CTC_CLK_LCNT0   ((u32)0x000001FF << 0)            /*!< R/W 9'd5  This field defines  sample clock driver lower level of  chn lower level  = ctc_clk_lcnt0 * ip_clk period*/
#define CT_CTC_CLK_LCNT0(x)     (((u32)((x) & 0x000001FF) << 0))
#define CT_GET_CTC_CLK_LCNT0(x) ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup CT_CTC_DIV_LCNT1
  * @brief Captouch Div Lcnt Control Register
  * @{
  */
#define CT_MASK_CTC_CLK_LCNT5   ((u32)0x000001FF << 18)           /*!< R/W 9'd5  This field defines sample clock driver  lower level of  chn.  lower level  = ctc_clk_lcnt2 * ip_clk period*/
#define CT_CTC_CLK_LCNT5(x)     (((u32)((x) & 0x000001FF) << 18))
#define CT_GET_CTC_CLK_LCNT5(x) ((u32)(((x >> 18) & 0x000001FF)))
#define CT_MASK_CTC_CLK_LCNT4   ((u32)0x000001FF << 9)            /*!< R/W 9'd5  This field defines sample clock driver lower  level of  chn. lower level  = ctc_clk_lcnt1 * ip_clk period*/
#define CT_CTC_CLK_LCNT4(x)     (((u32)((x) & 0x000001FF) << 9))
#define CT_GET_CTC_CLK_LCNT4(x) ((u32)(((x >> 9) & 0x000001FF)))
#define CT_MASK_CTC_CLK_LCNT3   ((u32)0x000001FF << 0)            /*!< R/W 9'd5  This field defines  sample clock driver lower level of  chn lower level  = ctc_clk_lcnt0 * ip_clk period*/
#define CT_CTC_CLK_LCNT3(x)     (((u32)((x) & 0x000001FF) << 0))
#define CT_GET_CTC_CLK_LCNT3(x) ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup CT_CTC_DIV_LCNT2
  * @brief Captouch Div Lcnt Control Register
  * @{
  */
#define CT_MASK_CTC_CLK_LCNT6   ((u32)0x000001FF << 0)           /*!< R/W 9'd5  This field defines  sample clock driver lower level of  chn lower level  = ctc_clk_lcnt0 * ip_clk period*/
#define CT_CTC_CLK_LCNT6(x)     (((u32)((x) & 0x000001FF) << 0))
#define CT_GET_CTC_CLK_LCNT6(x) ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup CT_CTC_DMA
  * @brief Captouch  DMA Register
  * @{
  */
#define CT_MASK_RXDMA_MSIZE   ((u32)0x00000007 << 4)           /*!< R/W 0x0  ctc rxdma burst size. When fifo reach certain entry depth , controller will req dma operation. 0: 1 entry 1: 4 2: 8 N: 2**(N+1) Note: this setting must be same with GDMA burst len , or  fifo will underflow or overflow.*/
#define CT_RXDMA_MSIZE(x)     (((u32)((x) & 0x00000007) << 4))
#define CT_GET_RXDMA_MSIZE(x) ((u32)(((x >> 4) & 0x00000007)))
#define CT_BIT_RXDMA_EN       ((u32)0x00000001 << 0)           /*!< R/W 0x0  1:enable ctc rxdma Note: ctc dma interface must used GDMA as flow control , IP flow control is not support .*/
/** @} */

/** @defgroup CT_CTC_CM_CNT
  * @brief
  * @{
  */
#define CT_MASK_CTC_CM_CNT   ((u32)0x00000FFF << 0)           /*!< R/W 12'h18f  This field controls the time it takes for the power supply (Vd) to charge the capacitor Cm when each channel of Captouch starts working. Charging Time = (ctc_cm_cnt +1) * ip_clk_period.*/
#define CT_CTC_CM_CNT(x)     (((u32)((x) & 0x00000FFF) << 0))
#define CT_GET_CTC_CM_CNT(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup CT_CTC_CONF
  * @brief Captouch  Configuration Register
  * @{
  */
#define CT_BIT_CTC_SW_TRIG       ((u32)0x00000001 << 8)           /*!< R/W 0h  This bit controls the ctc module to do a conversion. Every time this bit is set to 1, ctc module would switch to a new channel and do one conversion. Therefore, this bit could be used as a start-convert event which is controlled by software. Every time a conversion is done, software MUST clear this bit manually. The interval between clearing and restart this bit must exceed one sample clock period. 0: disable the analog module and analog mux. 1: enable the analog module and analog mux. And then start a new channel conversion.*/
#define CT_MASK_CTC_CVLIST_LEN   ((u32)0x0000000F << 4)           /*!< R/W 0h  This field defines the number of items in the ctc conversion channel list.*/
#define CT_CTC_CVLIST_LEN(x)     (((u32)((x) & 0x0000000F) << 4))
#define CT_GET_CTC_CVLIST_LEN(x) ((u32)(((x >> 4) & 0x0000000F)))
#define CT_BIT_OV_MODE           ((u32)0x00000001 << 0)           /*!< R/W 0x1  sample mode 0-All sample conversions done in staggered sequence 1-All sample conversions done in regular sequence*/
/** @} */

/** @defgroup CT_CTC_CHSW_LIST_0
  * @brief Captouch Channel Switch List 0 Register
  * @{
  */
#define CT_MASK_CTC_CHSW_7   ((u32)0x0000000F << 28)           /*!< R/W 0h  This field defines the number 7 channel to do a conversion when a conversion event takes place.*/
#define CT_CTC_CHSW_7(x)     (((u32)((x) & 0x0000000F) << 28))
#define CT_GET_CTC_CHSW_7(x) ((u32)(((x >> 28) & 0x0000000F)))
#define CT_MASK_CTC_CHSW_6   ((u32)0x0000000F << 24)           /*!< R/W 0h  This field defines the number 6 channel to do a conversion when a conversion event takes place.*/
#define CT_CTC_CHSW_6(x)     (((u32)((x) & 0x0000000F) << 24))
#define CT_GET_CTC_CHSW_6(x) ((u32)(((x >> 24) & 0x0000000F)))
#define CT_MASK_CTC_CHSW_5   ((u32)0x0000000F << 20)           /*!< R/W 0h  This field defines the number 5 channel to do a conversion when a conversion event takes place.*/
#define CT_CTC_CHSW_5(x)     (((u32)((x) & 0x0000000F) << 20))
#define CT_GET_CTC_CHSW_5(x) ((u32)(((x >> 20) & 0x0000000F)))
#define CT_MASK_CTC_CHSW_4   ((u32)0x0000000F << 16)           /*!< R/W 0h  This field defines the number 4 channel to do a conversion when a conversion event takes place.*/
#define CT_CTC_CHSW_4(x)     (((u32)((x) & 0x0000000F) << 16))
#define CT_GET_CTC_CHSW_4(x) ((u32)(((x >> 16) & 0x0000000F)))
#define CT_MASK_CTC_CHSW_3   ((u32)0x0000000F << 12)           /*!< R/W 0h  This field defines the number 3 channel to do a conversion when a conversion event takes place.*/
#define CT_CTC_CHSW_3(x)     (((u32)((x) & 0x0000000F) << 12))
#define CT_GET_CTC_CHSW_3(x) ((u32)(((x >> 12) & 0x0000000F)))
#define CT_MASK_CTC_CHSW_2   ((u32)0x0000000F << 8)            /*!< R/W 0h  This field defines the number 2 channel to do a conversion when a conversion event takes place.*/
#define CT_CTC_CHSW_2(x)     (((u32)((x) & 0x0000000F) << 8))
#define CT_GET_CTC_CHSW_2(x) ((u32)(((x >> 8) & 0x0000000F)))
#define CT_MASK_CTC_CHSW_1   ((u32)0x0000000F << 4)            /*!< R/W 0h  This field defines the number 1 channel to do a conversion when a conversion event takes place.*/
#define CT_CTC_CHSW_1(x)     (((u32)((x) & 0x0000000F) << 4))
#define CT_GET_CTC_CHSW_1(x) ((u32)(((x >> 4) & 0x0000000F)))
#define CT_MASK_CTC_CHSW_0   ((u32)0x0000000F << 0)            /*!< R/W 0h  This field defines the number 0 channel to do a conversion when a conversion event takes place.*/
#define CT_CTC_CHSW_0(x)     (((u32)((x) & 0x0000000F) << 0))
#define CT_GET_CTC_CHSW_0(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup CT_CTC_CHSW_LIST_1
  * @brief Captouch Channel Switch List 1 Register
  * @{
  */
#define CT_MASK_CTC_CHSW_15   ((u32)0x0000000F << 28)           /*!< R/W 0h  This field defines the number 15 channel to do a conversion when a conversion event takes place.*/
#define CT_CTC_CHSW_15(x)     (((u32)((x) & 0x0000000F) << 28))
#define CT_GET_CTC_CHSW_15(x) ((u32)(((x >> 28) & 0x0000000F)))
#define CT_MASK_CTC_CHSW_14   ((u32)0x0000000F << 24)           /*!< R/W 0h  This field defines the number 14 channel to do a conversion when a conversion event takes place.*/
#define CT_CTC_CHSW_14(x)     (((u32)((x) & 0x0000000F) << 24))
#define CT_GET_CTC_CHSW_14(x) ((u32)(((x >> 24) & 0x0000000F)))
#define CT_MASK_CTC_CHSW_13   ((u32)0x0000000F << 20)           /*!< R/W 0h  This field defines the number 13 channel to do a conversion when a conversion event takes place.*/
#define CT_CTC_CHSW_13(x)     (((u32)((x) & 0x0000000F) << 20))
#define CT_GET_CTC_CHSW_13(x) ((u32)(((x >> 20) & 0x0000000F)))
#define CT_MASK_CTC_CHSW_12   ((u32)0x0000000F << 16)           /*!< R/W 0h  This field defines the number 12 channel to do a conversion when a conversion event takes place.*/
#define CT_CTC_CHSW_12(x)     (((u32)((x) & 0x0000000F) << 16))
#define CT_GET_CTC_CHSW_12(x) ((u32)(((x >> 16) & 0x0000000F)))
#define CT_MASK_CTC_CHSW_11   ((u32)0x0000000F << 12)           /*!< R/W 0h  This field defines the number 11 channel to do a conversion when a conversion event takes place.*/
#define CT_CTC_CHSW_11(x)     (((u32)((x) & 0x0000000F) << 12))
#define CT_GET_CTC_CHSW_11(x) ((u32)(((x >> 12) & 0x0000000F)))
#define CT_MASK_CTC_CHSW_10   ((u32)0x0000000F << 8)            /*!< R/W 0h  This field defines the number 10 channel to do a conversion when a conversion event takes place.*/
#define CT_CTC_CHSW_10(x)     (((u32)((x) & 0x0000000F) << 8))
#define CT_GET_CTC_CHSW_10(x) ((u32)(((x >> 8) & 0x0000000F)))
#define CT_MASK_CTC_CHSW_9    ((u32)0x0000000F << 4)            /*!< R/W 0h  This field defines the number 9 channel to do a conversion when a conversion event takes place.*/
#define CT_CTC_CHSW_9(x)      (((u32)((x) & 0x0000000F) << 4))
#define CT_GET_CTC_CHSW_9(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define CT_MASK_CTC_CHSW_8    ((u32)0x0000000F << 0)            /*!< R/W 0h  This field defines the number 8 channel to do a conversion when a conversion event takes place.*/
#define CT_CTC_CHSW_8(x)      (((u32)((x) & 0x0000000F) << 0))
#define CT_GET_CTC_CHSW_8(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @} */
/* Exported Types --------------------------------------------------------*/

/** @defgroup CAPTOUCH_Exported_Types CAPTOUCH Exported Types
  * @{
  */

/** @brief CAPTOUCH Port
  */
typedef struct {
	__IO uint32_t CT_CHx_SNR_INF     ;  /*!< SIGNAL x NOISE RATIO REGISTER */
	__IO uint32_t CT_CHx_CTRL        ;  /*!< CHANNEL x CONTROL REGISTER */
	__IO uint32_t CT_CHx_NOISE_TH    ;  /*!< CHANNEL x NOISE THRESHOLD REGISTER */
	__IO uint32_t CT_CHx_TOUCH_TH    ;  /*!< CHANNEL x THRESHOLD REGISTER */
	__IO uint32_t CT_CHx_BASELINE_DBC;  /*!< CHANNEL x Register */
	__IO uint32_t CT_CHx_PROC_DATA_  ;  /*!< CHANNEL x PROCESS REGISTER */
	__IO uint32_t CT_CHx_DATA_INF    ;  /*!< CHANNEL x DTOUCH REGISTER */
} CT_CH_TypeDef;

/** @brief CAPTOUCH Register Declaration
  */

typedef struct {
	__IO uint32_t CT_CTC_CTRL             ;  /*!< CAPTOUCH CONTROL REGISTER,  Address offset:0x000 */
	__IO uint32_t CT_SCAN_PERIOD          ;  /*!< SCAN PARAMETERS REGISTER,  Address offset:0x004 */
	__IO uint32_t CT_ETC_CTRL             ;  /*!< ENVIRONMENT TRACKING CONTROL REGISTER,  Address offset:0x008 */
	__IO uint32_t CT_FIFO_STATUS          ;  /*!< FIFO STATUS REGISTER,  Address offset:0x00C */
	__IO uint32_t CT_FIFO_READ            ;  /*!< FIFO READ REGISTER,  Address offset:0x010 */
	__IO uint32_t CT_INTERRUPT_ENABLE0    ;  /*!< INTERRUPT ENABLE REGISTER,  Address offset:0x014 */
	__IO uint32_t CT_INTERRUPT_ENABLE1    ;  /*!< INTERRUPT ENABLE REGISTER,  Address offset:0x018 */
	__I  uint32_t CT_INTERRUPT_STATUS0    ;  /*!< INTERRUPT STATUS REGISTER,  Address offset:0x01C */
	__I  uint32_t CT_INTERRUPT_STATUS1    ;  /*!< INTERRUPT STATUS REGISTER,  Address offset:0x020 */
	__I  uint32_t CT_RAW_INTERRUPT_STATUS0;  /*!< RAW INTERRUPT STATUS REGISTER,  Address offset:0x024 */
	__I  uint32_t CT_RAW_INTERRUPT_STATUS1;  /*!< RAW INTERRUPT STATUS REGISTER,  Address offset:0x028 */
	__IO uint32_t CT_INTERRUPT_ALL_CLR    ;  /*!< INTERRUPT ALL CLEAR REGISTER,  Address offset:0x02C */
	__IO uint32_t CT_INTERRUPT_STATUS_CLR0;  /*!< INTERRUPT CLEAR REGISTER,  Address offset:0x030 */
	__IO uint32_t CT_INTERRUPT_STATUS_CLR1;  /*!< INTERRUPT CLEAR REGISTER,  Address offset:0x034 */
	__IO uint32_t CT_PRS                  ;  /*!< PRS SELECT REGISTER,  Address offset:0x038 */
	__IO uint32_t RSVD0                   ;  /*!< Reserved,  Address offset:0x03C-0x03F */
	__IO uint32_t CT_DEBUG_SEL            ;  /*!< DEBUG SELECT REGISTER,  Address offset:0x040 */
	__I  uint32_t CT_DEBUG_PORT           ;  /*!< DEBUG REGISTER,  Address offset:0x044 */
	__IO uint32_t CT_ECO_USE0             ;  /*!< ECO USE0 REGISTER,  Address offset:0x048 */
	__IO uint32_t CT_ECO_USE1             ;  /*!< ECO USE1 REGISTER,  Address offset:0x04C */
	__IO uint32_t CT_CTC_COMP_VERSION     ;  /*!< VERSION REGISTER,  Address offset:0x050 */
	__IO uint32_t CT_SNR_INF              ;  /*!< SIGNAL NOISE RATIO REGISTER,  Address offset:0x054 */
	__IO uint32_t RSVD1[42]               ;  /*!< Reserved,  Address offset:0x058-0x0FF */
	CT_CH_TypeDef CT_CH[16]               ;  /*!< CAPTOUCH IP have 16 ports,  Address offset:0x100-0x2BC */
	__IO uint32_t RSVD2[16]               ;  /*!< Reserved,  Address offset:0x2C0-0x2FF */
	__IO uint32_t CT_CTC_SETTLE_CTRL      ;  /*!< CAPTOUCH SETTLE CONTROL REGISTER,  Address offset:0x300 */
	__IO uint32_t CT_CTC_FILTER_CTRL0     ;  /*!< CAPTOUCH FILTER CONTROL0 REGISTER,  Address offset:0x304 */
	__IO uint32_t CT_CTC_FILTER_CTRL1     ;  /*!< CAPTOUCH FILTER CONTROL1 REGISTER,  Address offset:0x308 */
	__IO uint32_t CT_CTC_NOISE_CNT        ;  /*!< CAPTOUCH NOISE CNT REGISTER,  Address offset:0x30C */
	__IO uint32_t CT_CTC_DIV_HCNT         ;  /*!< CAPTOUCH DIV HCNT CONTROL REGISTER,  Address offset:0x310 */
	__IO uint32_t CT_CTC_DIV_LCNT0        ;  /*!< CAPTOUCH DIV LCNT CONTROL REGISTER,  Address offset:0x314 */
	__IO uint32_t CT_CTC_DIV_LCNT1        ;  /*!< CAPTOUCH DIV LCNT CONTROL REGISTER,  Address offset:0x318 */
	__IO uint32_t CT_CTC_DIV_LCNT2        ;  /*!< CAPTOUCH DIV LCNT CONTROL REGISTER,  Address offset:0x31C */
	__IO uint32_t CT_CTC_DMA              ;  /*!< CAPTOUCH  DMA REGISTER,  Address offset:0x320 */
	__IO uint32_t CT_CTC_CM_CNT           ;  /*!< Register,  Address offset:0x324 */
	__IO uint32_t CT_CTC_CONF             ;  /*!< CAPTOUCH  CONFIGURATION REGISTER,  Address offset:0x328 */
	__IO uint32_t CT_CTC_CHSW_LIST_0      ;  /*!< CAPTOUCH CHANNEL SWITCH LIST 0 REGISTER,  Address offset:0x32C */
	__IO uint32_t CT_CTC_CHSW_LIST_1      ;  /*!< CAPTOUCH CHANNEL SWITCH LIST 1 REGISTER,  Address offset:0x330 */
	__IO uint32_t CT_CTC_DUMMY            ;  /*!< CAPTOUCH DUMMY REGISTER,  Address offset:0x334 */
} CAPTOUCH_TypeDef;

/** @} */


// Do NOT modify any AUTO_GEN code above
/* AUTO_GEN_END */

/* MANUAL_GEN_START */

//Please add your definition here

/* Exported types --------------------------------------------------------*/
/** @addtogroup CAPTOUCH_Exported_Types CAPTOUCH Exported Types
  * @{
  */

/**
  * @brief  CapTouch Channel Init Structure Definition
  */
typedef struct {

	u16 CT_DiffThrehold;		/*!< Difference threshold data of touch judgement for channelx :
							1. Configured during development; (0x0~0xFFF) (0~4095)
							2. Init number=0x0, need to be configured
							3. recommend data=80%*(signal-baseline); */

	u16 CT_ETCNNoiseThr;		/*!< Specify negetive noise threshold of ETC.
							This parameter must be set to a value in the 0x1-0xfff range.
							The noise threshold indicates the raw data of the maximum capacitance change
							caused by environmental change. The CTC system provides configurable
							positive noise threshold and negative noise threshold for optimal calibration.
							The recommend value of noise threshold is 40%* touch threshold. Users need
							tune the two noise thresholds for different applications and noise environment.*/

	u16 CT_ETCPNoiseThr;		/*!< Specify positive threshold of ETC.
							This parameter must be set to a value in the 0x1-0xfff range. */

	u8 CT_ChDbcTime;	/*!< Specify channel debounce time
  										This parameter can be a value of @ref CapTouch_Debounce_Time. */

	u8 CT_ChDbcEn;	/*!< Specify channel debounce enable or not */

} CapTouch_CHInitTypeDef;

/**
  * @brief  CapTouch Init Structure Definition
  */
typedef struct {
	u32 CT_SampleCnt;			/*!< Specify sample cnt for average function,sample cnt = 2*exp(CT_SampleCnt+2).
							This parameter can be a value of 0x0-0x7*/

	u32 CT_ScanInterval;		/*!< Specify scan interval of every key.
							This parameter must be set to a value in the 0x1-0xfff range. */

	u16 CT_SampFreqKHz;		/*!< Specify CapTouch sample frequency in KHz.
							This parameter must be set to a value in the 40-4000 range. */

	u8 CT_FreqSwitchStep;		/*!< Specify step value among CapTouch Lcnt0-Lcnt6.
							This parameter must be set to a value in the 0-100 range. */

	u8 CT_CvlistLen;	/*!< Number of valid items in CTC conversion channel list is (CT_CvlistLen + 1).
									This parameter can be set to 0-15 */

	u8 CT_Cvlist[16];	/*!< Specify CTC channel conversion order. Each member should be the channel index. */


	u8 CT_MedCoef;			/*!< Specify coefficient of median filter .
							This parameter must be a value of @ref CapTouch_Med_Flt_Coef. */

	u8 CT_IIRCoefNorm;			/*!< Specify normal coefficient of IIR filter .
							This parameter must be set to a value in the 0x0-0xB range. */

	u8 CT_IIRCoefAccel;			/*!< Specify accelerate coefficient of IIR filter .
							This parameter must be set to a value in the 0x0-0xB range. */

	u32 CT_ETCStep;				/*!< Specify baseline update setp of ETC.
							This parameter must be set to a value in the 0x0-0xfff range. */

	u32 CT_ETCFactor;			/*!< Specify CapTouch ETC Factor.
							This parameter must be set to a value in the 0x0-0xf range. */

	u32 CT_ETCScanInterval;		/*!< Specify ETC scan interval
							This parameter can be set to a value in the 0x1-0x7f range*/

	u8 CT_CTCMode; 		/*!< Specify CapTouch mode
							This parameter can be a value of  @ref CapTouch_CTC_Mode. */
	CapTouch_CHInitTypeDef CT_Channel[16];			/*!< Specify the initialization parameters for each channel */

} CapTouch_InitTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup CAPTOUCH_Exported_Constants CAPTOUCH Exported Constants
  * @{
  */

/** @defgroup CapTouch_Peripheral_Definitions
  * @{
  */
#define IS_CAPTOUCH_ALL_PERIPH(PERIPH) ((PERIPH) == CAPTOUCH_DEV)

/**
  * @}
  */

/** @defgroup CapTouch_INT0_Operation
  * @{
  */

#define CT_ALL_INT_EN0		(CT_BIT_OVER_P_NOISE_TH_INTR_EN | \
													CT_BIT_AFIFO_OVERFLOW_INTR_EN | \
													CT_BIT_OVER_N_NOISE_TH_INTR_EN | \
													CT_BIT_AFIFO_OVERLVL_INTR_EN | \
													CT_BIT_SCAN_END_INTR_EN)

#define IS_CT_INT_EN0(IT)				(((IT) & ~CT_ALL_INT_EN0) == 0)
#define IS_CT_INT_CLR0(IT)			(((IT) & ~CT_ALL_INT_EN0) == 0)
/**
  * @}
  */

/** @defgroup CapTouch_INT1_Operation
  * @{
  */
#define CT_CHX_PRESS_INT(x)			BIT(x)
#define CT_CHX_RELEASE_INT(x)		BIT((x) + 16)

#define CT_ALL_INT_EN1					(u32)(0xFFFFFFFF)

/**
  * @}
  */

/** @defgroup CapTouch_Chn_Selection
  * @{
  */
#define CTC_CH0							((u8)0x00)
#define CTC_CH1							((u8)0x01)
#define CTC_CH2							((u8)0x02)
#define CTC_CH3							((u8)0x03)
#define CTC_CH4							((u8)0x04)
#define CTC_CH5							((u8)0x05)
#define CTC_CH6							((u8)0x06)
#define CTC_CH7							((u8)0x07)
#define CTC_CH8							((u8)0x08)
#define CTC_CH9							((u8)0x09)
#define CTC_CH10						((u8)0x0A)
#define CTC_CH11						((u8)0x0B)
#define CTC_CH12						((u8)0x0C)
#define CTC_CH13						((u8)0x0D)
#define CTC_CH14						((u8)0x0E)
#define CTC_CH15						((u8)0x0F)

#define CT_CHANNEL_NUM					(16)
#define IS_CT_CHANNEL(CHANNEL_NUM)		(CHANNEL_NUM < CT_CHANNEL_NUM)
/**
  * @}
  */

/** @defgroup CapTouch_Chn_Pad_Selection
  * @{
  */
#define CTC_CH0_PIN						(_PB_17)
#define CTC_CH1_PIN						(_PB_18)
#define CTC_CH2_PIN						(_PB_19)
#define CTC_CH3_PIN						(_PB_20)
#define CTC_CH4_PIN						(_PB_21)
#define CTC_CH5_PIN						(_PB_23)
#define CTC_CH6_PIN						(_PB_24)
#define CTC_CH7_PIN						(_PB_25)
#define CTC_CH8_PIN						(_PB_26)
#define CTC_CH9_PIN						(_PB_27)
#define CTC_CH10_PIN					(_PB_28)
#define CTC_CH11_PIN					(_PB_29)
#define CTC_CH12_PIN					(_PB_30)
#define CTC_CH13_PIN					(_PB_31)
#define CTC_CH14_PIN					(_PC_10)
#define CTC_CH15_PIN					(_PC_11)
/**
  * @}
  */

/** @defgroup CapTouch_Noise_Threshold_Type
  * @{
  */
#define  P_NOISE_THRES					0
#define  N_NOISE_THRES					1
/**
  * @}
  */

/** @defgroup CTC_Data_Setting
  * @{
  */
#define CTC_GET_CH_NUM(x) ((u32)(((x >> 16) & 0x0000000F)))
#define CTC_GET_DATA(x)   ((u32)(((x >> 0) & 0x0000FFFF)))
/**
  * @}
  */

/** @defgroup CapTouch_RXDMA_Setting
  * @{
  */
#define CTC_RXDMA_MSIZE_1			((u8)0x0)
#define CTC_RXDMA_MSIZE_4			((u8)0x1)
#define CTC_RXDMA_MSIZE_8			((u8)0x2)
#define CTC_RXDMA_MSIZE_16		((u8)0x3)
#define CTC_RXDMA_MSIZE_32		((u8)0x4)

#define IS_CTC_RXDMA_MSIZE(x)		((x) == CTC_RXDMA_MSIZE_1 || \
									(x) == CTC_RXDMA_MSIZE_4 || \
									(x) == CTC_RXDMA_MSIZE_8 || \
									(x) == CTC_RXDMA_MSIZE_16 || \
									(x) == CTC_RXDMA_MSIZE_32)
/**
  * @}
  */

/** @defgroup CapTouch_Med_Flt_Coef
  * @{
  */
#define CTC_MED_3				((u8)0x1)
#define CTC_MED_5				((u8)0x2)
#define CTC_MED_7				((u8)0x3)
#define CTC_MED_DIS				((u8)0x0)

#define IS_MED_COEF(x)			((x) == CTC_MED_3 || \
								(x) == CTC_MED_5 || \
								(x) == CTC_MED_7 || \
								(x) == CTC_MED_DIS)
/**
  * @}
  */

/** @defgroup CapTouch_CTC_Mode
  * @{
  */
#define CTC_COMP_MODE						((u8)0x0)
#define CTC_SAR_ADC_MODE				((u8)0x1)

#define IS_CTC_MODE(x)			((x) == CTC_COMP_MODE || \
														(x) == CTC_SAR_ADC_MODE)
/**
  * @}
  */

/** @defgroup CapTouch_Debounce_Time
  * @{
  */
#define CTC_DBC_2TIMES					((u8)0x0)
#define CTC_DBC_3TIMES					((u8)0x1)
#define CTC_DBC_4TIMES					((u8)0x2)
#define CTC_DBC_5TIMES					((u8)0x3)

#define IS_CTC_DBC_TIME(x)			((x) == CTC_DBC_2TIMES || \
																(x) == CTC_DBC_3TIMES || \
																(x) == CTC_DBC_4TIMES || \
																(x) == CTC_DBC_5TIMES)
/**
  * @}
  */

/** @defgroup CapTouch_CHSW_List
  * @{
  */
#define CTC_SHIFT_CHSW0(x)						(4*x)
#define CTC_SHIFT_CHSW1(x)						(4*(x - 8))
/**
  * @}
  */

/** @defgroup CapTouch_FIFO_Data_Type
  * @{
  */
#define CTC_FIFO_RAW_MODE				((u8)0x0)
#define CTC_FIFO_FILTER_MODE		((u8)0x1)

#define IS_CAPTOUCH_FIFOTYPE(x)			((x) == CTC_FIFO_RAW_MODE || \
																		(x) == CTC_FIFO_FILTER_MODE)
/**
  * @}
  */

/** @defgroup CapTouch_Notch_Window_Width
  * @{
  */
#define CTC_NOTCH_DIS					((u8)0x00)
#define CTC_NOTCH_WIND2				((u8)0x02)
#define CTC_NOTCH_WIND3				((u8)0x03)
#define CTC_NOTCH_WIND4				((u8)0x04)
#define CTC_NOTCH_WIND5				((u8)0x05)
#define CTC_NOTCH_WIND6				((u8)0x06)
#define CTC_NOTCH_WIND7				((u8)0x07)
#define CTC_NOTCH_WIND8				((u8)0x08)

#define IS_CT_NOTCH_WIND(x)		((x) <= CTC_NOTCH_WIND8)
/**
  * @}
  */

/** @defgroup CapTouch_Notch_Coef
  * @{
  */
#define CTC_NOTCH_WIND2_COEF				((u16)0x4000) // 16384
#define CTC_NOTCH_WIND3_COEF				((u16)0x2AAA) // 10922
#define CTC_NOTCH_WIND4_COEF				((u16)0x2000) // 8192
#define CTC_NOTCH_WIND5_COEF				((u16)0x199A) // 6554
#define CTC_NOTCH_WIND6_COEF				((u16)0x1555) // 5461
#define CTC_NOTCH_WIND7_COEF				((u16)0x1249) // 4681
#define CTC_NOTCH_WIND8_COEF				((u16)0x1000) // 4096

#define IS_CT_NOTCH_WIND(x)		((x) <= CTC_NOTCH_WIND8)
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
void CapTouch_StructInit(CapTouch_InitTypeDef *CapTouch_InitStruct);
void CapTouch_Init(CAPTOUCH_TypeDef *CapTouch, CapTouch_InitTypeDef *CapTouch_InitStruct);
void CapTouch_Cmd(CAPTOUCH_TypeDef *CapTouch, u8 NewState);

void CapTouch_INTConfig0(CAPTOUCH_TypeDef *CapTouch, uint32_t CapTouch_IT, u8 newState);
void CapTouch_INTConfig1(CAPTOUCH_TypeDef *CapTouch, uint32_t CapTouch_IT, u8 newState);
void CapTouch_INTClearPendingBit0(CAPTOUCH_TypeDef *CapTouch, u32 CapTouch_IT);
void CapTouch_INTClearPendingBit1(CAPTOUCH_TypeDef *CapTouch, u32 CapTouch_IT);
u32 CapTouch_GetRawISR0(CAPTOUCH_TypeDef *CapTouch);
u32 CapTouch_GetRawISR1(CAPTOUCH_TypeDef *CapTouch);
u32 CapTouch_GetISR0(CAPTOUCH_TypeDef *CapTouch);
u32 CapTouch_GetISR1(CAPTOUCH_TypeDef *CapTouch);

void CapTouch_SetClk(CAPTOUCH_TypeDef *CapTouch, u16 SampFreqKHz, u8 LcntStep);
void CapTouch_SetCMCnt(CAPTOUCH_TypeDef *CapTouch, u16 Count);
void CapTouch_SetScanInterval(CAPTOUCH_TypeDef *CapTouch, u32 IntervalMs);
void CapTouch_SetChDiffThres(CAPTOUCH_TypeDef *CapTouch, u8 Channel, u16 Threshold);
u32 CapTouch_GetChDiffThres(CAPTOUCH_TypeDef *CapTouch, u8 Channel);
u32 CapTouch_GetChAbsThres(CAPTOUCH_TypeDef *CapTouch, u8 Channel);
void CapTouch_SetNNoiseThres(CAPTOUCH_TypeDef *CapTouch, u8 Channel, u16 Threshold);
void CapTouch_SetPNoiseThres(CAPTOUCH_TypeDef *CapTouch, u8 Channel, u16 Threshold);
void CapTouch_SetNoiseCnt(CAPTOUCH_TypeDef *CapTouch, u16 Count);

u32 CapTouch_GetNoiseThres(CAPTOUCH_TypeDef *CapTouch, u8 Channel, u8 type);
u32 CapTouch_GetChBaseline(CAPTOUCH_TypeDef *CapTouch, u8 Channel);
u32 CapTouch_GetChNoise(CAPTOUCH_TypeDef *CapTouch, u8 Channel);
u32 CapTouch_Read(CAPTOUCH_TypeDef *CapTouch);
void CapTouch_ClearFIFO(CAPTOUCH_TypeDef *CapTouch);
void CapTouch_SetFifoMode(CAPTOUCH_TypeDef *CapTouch, u8 DataType);
int CapTouch_ReceiveBuf(CAPTOUCH_TypeDef *CapTouch, u32 *pBuf, u32 Len);

void CapTouch_FilterCmd(CAPTOUCH_TypeDef *CapTouch, u8 NewState);
void CapTouch_FilterIIRCmd(CAPTOUCH_TypeDef *CapTouch, u8 NewState);
void CapTouch_FilterIIRConfig(CAPTOUCH_TypeDef *CapTouch, u8 AccelEn, u8 CoefNorm, u8 CoefAccel);
void CapTouch_FilterNotchConfig(CAPTOUCH_TypeDef *CapTouch, u8 WindowWidth);
void CapTouch_SetMedCoef(CAPTOUCH_TypeDef *CapTouch, u8 MedCoef);
void CapTouch_SetFifoLevel(CAPTOUCH_TypeDef *CapTouch, u8 Level);

void CapTouch_RXDMAConfig(CAPTOUCH_TypeDef *CapTouch, u32 RxDmaBurstSize);
void CapTouch_RXDMACmd(CAPTOUCH_TypeDef *CapTouch, u32 NewState);
u8 CapTouch_RXGDMA_Init(CAPTOUCH_TypeDef *CapTouch, GDMA_InitTypeDef *GDMA_InitStruct,
						void *CallbackData, IRQ_FUN CallbackFunc, u8 *pRxBuf, u32 RxCount);

void CapTouch_PRSCmd(CAPTOUCH_TypeDef *CapTouch, u8 NewState);

/* MANUAL_GEN_END */

#endif