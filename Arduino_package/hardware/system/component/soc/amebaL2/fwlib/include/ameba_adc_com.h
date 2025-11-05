/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _RL6955_ADC_COM_H_
#define _RL6955_ADC_COM_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup ADC_COM
  * @brief ADC_COM driver modules
  * @{
  */


/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup ADC_COM_Register_Definitions ADC_COM Register Definitions
  * @{
  */

/** @defgroup ADC_COM_ADC_CTRL0
  * @brief
  * @{
  */
#define ADC_COM_MASK_REG_ASY_DELAY               ((u32)0x00000003 << 12)           /*!< R/W 2'b01  Asy SAR ADC compare time. Control the delay of the comparator. If the comparator fails to produce a result for a long time, it will force the output of the result. 00:Fast; 01: 10: 11:Slow:*/
#define ADC_COM_REG_ASY_DELAY(x)                 (((u32)((x) & 0x00000003) << 12))
#define ADC_COM_GET_REG_ASY_DELAY(x)             ((u32)(((x >> 12) & 0x00000003)))
#define ADC_COM_BIT_REG_HV5VPWR_OSEL33_1SEL5     ((u32)0x00000001 << 11)           /*!< R/W 1'b1  This Reg is used to inform Analog HV5V's PAD whether it is a true 5V voltage. It is flexible for some applications where the 5V PAD is connected to 3.3V. HV5V PAD power is 3.3V or 5V signal to Aphy.*/
#define ADC_COM_MASK_SEL_LDO2P5_VOL              ((u32)0x00000003 << 9)            /*!< R/W 'b01  00:2.125V 01:2.25V 10:2.375V 11:2.50V AIF default 01:2.25V*/
#define ADC_COM_SEL_LDO2P5_VOL(x)                (((u32)((x) & 0x00000003) << 9))
#define ADC_COM_GET_SEL_LDO2P5_VOL(x)            ((u32)(((x >> 9) & 0x00000003)))
#define ADC_COM_MASK_SEL_LDOAV09_VOL             ((u32)0x00000003 << 7)            /*!< R/W 'b10  AUX ADC 0.9V LDO voltage: 00:0.85V 01:0.9V 10:0.95V (default) 11:1.0V AIF default 10:0.95V;*/
#define ADC_COM_SEL_LDOAV09_VOL(x)               (((u32)((x) & 0x00000003) << 7))
#define ADC_COM_GET_SEL_LDOAV09_VOL(x)           ((u32)(((x >> 7) & 0x00000003)))
#define ADC_COM_BIT_SEL_INSWING_0SEL33V_1SEL18V  ((u32)0x00000001 << 6)            /*!< R/W 'b0  0:ADC Input Full swing is 3.3V; 1:ADC Input Full swing is 1.8V; AIF default 0; Each CH is independent*/
#define ADC_COM_BIT_SEL_INSWING_0SEL5V_1SEL1833V ((u32)0x00000001 << 5)            /*!< R/W 'b0  0 :ADC Input Full swing is 5V; 1: The input range depends on SEL_INSWING_0SEL33V_1SEL18V AIF default 0: Each CH is independent*/
#define ADC_COM_BIT_EN_ADC_CKS                   ((u32)0x00000001 << 4)            /*!< R/W 'b0  EN_ADC_CKS = 0,ADC_CKS=0 or 1,ADC always Stop to Sample State; EN_ADC_CKS = 1,ADC_CKS=1,ADC Sample State; EN_ADC_CKS = 1,ADC_CKS=0,ADC Sample Finish,ADC compare start; AIF default 1;*/
#define ADC_COM_BIT_EN_VREFP_LPF                 ((u32)0x00000001 << 3)            /*!< R/W 'b0  When 0.AUX ADC Reference LPF disable; When 1,AUX ADC Reference LPF enable; AIF default 1;*/
#define ADC_COM_BIT_EN_META                      ((u32)0x00000001 << 2)            /*!< R/W 'b1  EN_META = 1, When ADC compare not finish,force comparator to 0; EN_META = 0, Do nothing; AIF default 1;*/
#define ADC_COM_MASK_META_DELAY                  ((u32)0x00000003 << 0)            /*!< R/W 'b01  EN_META=1,When ADC compare not finish,force comparator to 0; META_DELAY select the delay to force comparator to 0; AIF default 01;*/
#define ADC_COM_META_DELAY(x)                    (((u32)((x) & 0x00000003) << 0))
#define ADC_COM_GET_META_DELAY(x)                ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup ADC_COM_ADC_CTRL1
  * @brief
  * @{
  */
#define ADC_COM_MASK_SEL_VREFP_VOL   ((u32)0x0000000F << 0)           /*!< R/W 4'b0100  AUX ADC Vrefp voltage: 0000:1.45V 0001:1.50V 0010:1.55V 0011:1.60V 0100:1.65V 0101:1.70V 0110:1.75V 0111:1.80V 1000:1.85V 1001:1.875V 1010:1.90V 1011:1.95V 1100:2.00V 1101:2.05V 1110:2.10V 1111:2.15V  Cs * VIN = 8C * Vrefp 3C * 5V = 8C * 1.875V 4C * 3.3V = 8C * 1.65V 8C * 1.8V = 8C * 1.8V AIF default 0100: 1.65V;*/
#define ADC_COM_SEL_VREFP_VOL(x)     (((u32)((x) & 0x0000000F) << 0))
#define ADC_COM_GET_SEL_VREFP_VOL(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup ADC_COM_CTC_CTRL
  * @brief
  * @{
  */
#define ADC_COM_MASK_SEL_LDO1P8_VOL          ((u32)0x00000003 << 8)           /*!< R/W 'b10  00:1.65V 01:1.70V 10:1.75V 11:1.80V AIF default 10:1.75V;*/
#define ADC_COM_SEL_LDO1P8_VOL(x)            (((u32)((x) & 0x00000003) << 8))
#define ADC_COM_GET_SEL_LDO1P8_VOL(x)        ((u32)(((x >> 8) & 0x00000003)))
#define ADC_COM_BIT_SEL_TOUCH_CUR_0V2I_1IBHN ((u32)0x00000001 << 7)           /*!< R/W 'b0  When 0 Touch compensate current can be VCVS current When 1 Touch compensate current use constant current AIF default 0: Use VCVS current*/
#define ADC_COM_BIT_EN_TOUCHCUR_CALI         ((u32)0x00000001 << 6)           /*!< R/W 'b0  1: Touch V2I Current Input Voltage use VDD_TOUCH 1.8V, not use Cm voltage, Can test Cm current for calibration; 0: Touch V2I Current Input Voltage use Cm voltage; AIF default 0: Not in Calibration state;*/
#define ADC_COM_BIT_EN_TOUCHCUR_2CM          ((u32)0x00000001 << 5)           /*!< R/W 1'b0  1: EN Touch Compensate Current to 2.2nF Cap CM; 0: Disable Touch Compensate Current to 2.2nF Cap CM; AIF default 1;*/
#define ADC_COM_BIT_EN_TOUCH_CKCM            ((u32)0x00000001 << 4)           /*!< R/W 1'b0  EN_TOUCH_CKCM=0,Or TOUCH_CKCM=0, Touch CM not reset to VLDO_1P8; EN_TOUCH_CKCM=1,And TOUCH_CKCM=1,Touch CM reset to VLDO_1P8; AIF default 1;*/
#define ADC_COM_BIT_CK_TOUCH_CM              ((u32)0x00000001 << 3)           /*!< R/W 1'b0  When 1,Touch Cm connect to VDD_Touch 1.8V; When 0,Touch Cm dis-connect to VDD_Touch 1.8V;*/
#define ADC_COM_BIT_EN_TOUCH_CHANNEL         ((u32)0x00000001 << 2)           /*!< R/W 1'b0  EN_TOUCH_CHANNEL =0,All Touch channel not work, Cs not to GND also not to CM; EN_TOUCH_CHANNEL =1,TOUCH_LANE_SEL<3:0>select Touch Lane to Cs and CM; AIF default 1;*/
#define ADC_COM_BIT_EN_TOUCH_CKCS            ((u32)0x00000001 << 1)           /*!< R/W 1'b0  EN_TOUCH_CKCS=0,OR TOUCH_CKCS=0,Touch CS reset to GND; EN_TOUCH_CKCS=1,And TOUCH_CKCS=1,Touch CS set to CM; AIF default 1;*/
#define ADC_COM_BIT_CK_TOUCH_CS              ((u32)0x00000001 << 0)           /*!< R/W 1'b0  When 0,Touch Cs to GND; When 1,Touch Cs to Cm;*/
/** @} */

/** @defgroup ADC_COM_POW_CTRL
  * @brief
  * @{
  */
#define ADC_COM_BIT_POW_ADC          ((u32)0x00000001 << 9) /*!< R/W 'b0  POW_ADC =0.AUX ADC off; POW_ADC =1,AUX ADC on; AIF default 1;*/
#define ADC_COM_BIT_POW_AUXADC_MBIAS ((u32)0x00000001 << 8) /*!< R/W 'b0  POW_ADC_MBIAS=0,AUX ADC and Touch bias current all off; POW_ADC_MBIAS=1,AUX ADC and Touch bias current on; AIF default 1;*/
#define ADC_COM_BIT_POW_LDO1P8       ((u32)0x00000001 << 7) /*!< R/W 'b0  1:Pow Touch LDO 1.8V VDD_TOUCH; 0:Off Touch LDO 1.8V VDD_TOUCH; AIF default 1:Pow on Touch LDO 1.8V;*/
#define ADC_COM_BIT_POW_LDO2P5       ((u32)0x00000001 << 6) /*!< R/W 'b0  1:AUX_ADC 2.5V LDO on; 0:AUX_ADC 2.5V LDO off; AIF default1;*/
#define ADC_COM_BIT_POW_LDOAV09      ((u32)0x00000001 << 5) /*!< R/W 'b0  1:AUX_ADC 0.9V LDO on; 0:AUX_ADC 0.9V LDO off; AIF default 1;*/
#define ADC_COM_BIT_POW_REFPGEN      ((u32)0x00000001 << 4) /*!< R/W 'b0  1:AUX_ADC Reference on; 0:AUX_ADC Reference off; AIF default1;*/
#define ADC_COM_BIT_POW_TOUCH_CMP    ((u32)0x00000001 << 3) /*!< R/W 'b0  1:Touch Comparator on; 0:Touch Comparator off; AIF default0;*/
#define ADC_COM_BIT_POW_TOUCH_CUR    ((u32)0x00000001 << 2) /*!< R/W 'b0  1:Touch compensate Current on; 0:Touch compensate Current off; AIF default0;*/
#define ADC_COM_BIT_VCCKOFF33V_B     ((u32)0x00000001 << 1) /*!< R/W 1'b0  When 0,Internal DVDD power off, All ADC and Touch off;*/
#define ADC_COM_BIT_VCCKOFFB_DV      ((u32)0x00000001 << 0) /*!< R/W 1'b0  When 0,Internal DVDD power off, All ADC and Touch off;*/
/** @} */

/** @defgroup ADC_COM_CTC_ONLY0
  * @brief
  * @{
  */
#define ADC_COM_MASK_TOUCH_LANE_SEL   ((u32)0x0000000F << 0)           /*!< R/W 4'b0  Touch Lane selection:  0000: lane0; ...... 1111: lane15;*/
#define ADC_COM_TOUCH_LANE_SEL(x)     (((u32)((x) & 0x0000000F) << 0))
#define ADC_COM_GET_TOUCH_LANE_SEL(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup ADC_COM_CTC_ONLY1
  * @brief
  * @{
  */
#define ADC_COM_MASK_SEL_TOUCH_CUR   ((u32)0x0000001F << 0)           /*!< R/W 'b01000  Touch compensate current: When Cm 1800mV example: 50uA+<4:0>*5uA:  Current = (50uA +<4:0>*5uA)*(Vcm/180K)/10uA;  AIF default 01000,current 80uA;*/
#define ADC_COM_SEL_TOUCH_CUR(x)     (((u32)((x) & 0x0000001F) << 0))
#define ADC_COM_GET_SEL_TOUCH_CUR(x) ((u32)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup ADC_COM_CTC_ONLY2
  * @brief
  * @{
  */
#define ADC_COM_MASK_SEL_TOUCHCMP_VREF   ((u32)0x00000007 << 0)           /*!< R/W 'b100  Touch Comparator Vref: 000:0.5V 001:0.525V 010:0.55V 011:0.575v 100:0.60V 101:0.625V 110:0.65V 111:0.675V AIF default 100:0.6V;*/
#define ADC_COM_SEL_TOUCHCMP_VREF(x)     (((u32)((x) & 0x00000007) << 0))
#define ADC_COM_GET_SEL_TOUCHCMP_VREF(x) ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup ADC_COM_DRV_CFG
  * @brief
  * @{
  */
#define ADC_COM_BIT_FORCE_CTC_CLK_EN      ((u32)0x00000001 << 3) /*!< R/W 0x0  In CTC decoupling mode, the CK_TOUCH_CS clock signal is continuously provided by the digital circuit.*/
#define ADC_COM_BIT_FORCE_CTC_DECOUPLE_EN ((u32)0x00000001 << 2) /*!< R/W 0x0  Enable CTC decoupling mode, the CTC interface signal will be controlled by software*/
#define ADC_COM_BIT_FORCE_ADC_POW_EN      ((u32)0x00000001 << 1) /*!< R/W 0x0  Enable ADC decoupling mode, the ADC power signal will be controlled by software*/
/** @} */

/** @defgroup ADC_COM_CTC_DECO
  * @brief
  * @{
  */
#define ADC_COM_BIT_CTC_CNT_TIMEOUT_CLR      ((u32)0x00000001 << 3) /*!< R/WA0 0h  intr crean signal*/
#define ADC_COM_BIT_CTC_CNT_TIMEOUT_EN       ((u32)0x00000001 << 2) /*!< R/W 1h  intr enable*/
#define ADC_COM_BIT_CTC_CNT_TIMEOUT_RAW_INTR ((u32)0x00000001 << 1) /*!< R 0h  raw intr*/
#define ADC_COM_BIT_CTC_CNT_TIMEOUT_INTR     ((u32)0x00000001 << 0) /*!< R 0h  An interrupt is triggered when the timer reaches the ch_Sc_times*/
/** @} */

/** @defgroup ADC_COM_POW_CNT0
  * @brief
  * @{
  */
#define ADC_COM_MASK_PWR_TO_CKCM_CNT   ((u32)0x00000FFF << 12)           /*!< R/W 12'h18f  The delay time between  pow_ldo1p8 and ck_touch_cm*/
#define ADC_COM_PWR_TO_CKCM_CNT(x)     (((u32)((x) & 0x00000FFF) << 12))
#define ADC_COM_GET_PWR_TO_CKCM_CNT(x) ((u32)(((x >> 12) & 0x00000FFF)))
#define ADC_COM_MASK_PWR_EN_LPF_CNT    ((u32)0x00000FFF << 0)            /*!< R/W 12'h18f  The delay time between  pow_mbias and en_vrefp_lpf*/
#define ADC_COM_PWR_EN_LPF_CNT(x)      (((u32)((x) & 0x00000FFF) << 0))
#define ADC_COM_GET_PWR_EN_LPF_CNT(x)  ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup ADC_COM_POW_CNT1
  * @brief
  * @{
  */
#define ADC_COM_MASK_PWR_ADC_CNT        ((u32)0x00000FFF << 12)           /*!< R/W 12'h31f  The delay time between  pow_adc and ck_ad*/
#define ADC_COM_PWR_ADC_CNT(x)          (((u32)((x) & 0x00000FFF) << 12))
#define ADC_COM_GET_PWR_ADC_CNT(x)      ((u32)(((x >> 12) & 0x00000FFF)))
#define ADC_COM_MASK_PWR_TO_ENADC_CKS   ((u32)0x00000FFF << 0)            /*!< R/W 12'h18f  The delay time between  pow_adc and en_adc_cks*/
#define ADC_COM_PWR_TO_ENADC_CKS(x)     (((u32)((x) & 0x00000FFF) << 0))
#define ADC_COM_GET_PWR_TO_ENADC_CKS(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup ADC_COM_ADC_CLK_HCNTx_DIV
  * @brief ADC Channel Clock Divider Register
  * @{
  */
#define ADC_COM_MASK_ADC_CLK_HCNTx   ((u32)0x00000FFF << 0)           /*!< R/W 12'd19  This field defines clock driver high level of  chn in ADC module.  high level =( bit_adc_clk_hcntx+1) * ip_clk period .  hcnt11-13 is rsvd.*/
#define ADC_COM_ADC_CLK_HCNTx(x)     (((u32)((x) & 0x00000FFF) << 0))
#define ADC_COM_GET_ADC_CLK_HCNTx(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup ADC_COM_ADC_CLK_COV
  * @brief
  * @{
  */
#define ADC_COM_BIT_ADC_COV_MODE    ((u32)0x00000001 << 31)           /*!< R/W 1'b0  0: convert time is 500ns 1: convert time is 700ns*/
#define ADC_COM_MASK_ADC_ISO_CNT    ((u32)0x0000000F << 26)           /*!< R/W 4'd0  Control the time of iso ch. if adc_iso_cnt is 0, iso_ch will disable*/
#define ADC_COM_ADC_ISO_CNT(x)      (((u32)((x) & 0x0000000F) << 26))
#define ADC_COM_GET_ADC_ISO_CNT(x)  ((u32)(((x >> 26) & 0x0000000F)))
#define ADC_COM_MASK_ADC_CLK_LCNT   ((u32)0x00000FFF << 0)            /*!< R/W 12'd23  This field defines clock driver lower level of  chn in ADC module.when source clock is 4M, the duration of low level need >=2 for timing req.(>=0.5us) lower level  =bit_adc_clk_lcnt* ip_clk period*/
#define ADC_COM_ADC_CLK_LCNT(x)     (((u32)((x) & 0x00000FFF) << 0))
#define ADC_COM_GET_ADC_CLK_LCNT(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup ADC_COM_ADC_VOL_LIST_0
  * @brief
  * @{
  */
#define ADC_COM_MASK_ADC_SEL_VREFP_VOL_7   ((u32)0x0000000F << 28)           /*!< R/W 4'b0100  Refer to adc_sel_vrefp_vol_0*/
#define ADC_COM_ADC_SEL_VREFP_VOL_7(x)     (((u32)((x) & 0x0000000F) << 28))
#define ADC_COM_GET_ADC_SEL_VREFP_VOL_7(x) ((u32)(((x >> 28) & 0x0000000F)))
#define ADC_COM_MASK_ADC_SEL_VREFP_VOL_6   ((u32)0x0000000F << 24)           /*!< R/W 4'b0100  Refer to adc_sel_vrefp_vol_0*/
#define ADC_COM_ADC_SEL_VREFP_VOL_6(x)     (((u32)((x) & 0x0000000F) << 24))
#define ADC_COM_GET_ADC_SEL_VREFP_VOL_6(x) ((u32)(((x >> 24) & 0x0000000F)))
#define ADC_COM_MASK_ADC_SEL_VREFP_VOL_5   ((u32)0x0000000F << 20)           /*!< R/W 4'b0100  Refer to adc_sel_vrefp_vol_0*/
#define ADC_COM_ADC_SEL_VREFP_VOL_5(x)     (((u32)((x) & 0x0000000F) << 20))
#define ADC_COM_GET_ADC_SEL_VREFP_VOL_5(x) ((u32)(((x >> 20) & 0x0000000F)))
#define ADC_COM_MASK_ADC_SEL_VREFP_VOL_4   ((u32)0x0000000F << 16)           /*!< R/W 4'b0100  Refer to adc_sel_vrefp_vol_0*/
#define ADC_COM_ADC_SEL_VREFP_VOL_4(x)     (((u32)((x) & 0x0000000F) << 16))
#define ADC_COM_GET_ADC_SEL_VREFP_VOL_4(x) ((u32)(((x >> 16) & 0x0000000F)))
#define ADC_COM_MASK_ADC_SEL_VREFP_VOL_3   ((u32)0x0000000F << 12)           /*!< R/W 4'b0100  Refer to adc_sel_vrefp_vol_0*/
#define ADC_COM_ADC_SEL_VREFP_VOL_3(x)     (((u32)((x) & 0x0000000F) << 12))
#define ADC_COM_GET_ADC_SEL_VREFP_VOL_3(x) ((u32)(((x >> 12) & 0x0000000F)))
#define ADC_COM_MASK_ADC_SEL_VREFP_VOL_2   ((u32)0x0000000F << 8)            /*!< R/W 4'b0100  Refer to adc_sel_vrefp_vol_0*/
#define ADC_COM_ADC_SEL_VREFP_VOL_2(x)     (((u32)((x) & 0x0000000F) << 8))
#define ADC_COM_GET_ADC_SEL_VREFP_VOL_2(x) ((u32)(((x >> 8) & 0x0000000F)))
#define ADC_COM_MASK_ADC_SEL_VREFP_VOL_1   ((u32)0x0000000F << 4)            /*!< R/W 4'b0100  Refer to adc_sel_vrefp_vol_0*/
#define ADC_COM_ADC_SEL_VREFP_VOL_1(x)     (((u32)((x) & 0x0000000F) << 4))
#define ADC_COM_GET_ADC_SEL_VREFP_VOL_1(x) ((u32)(((x >> 4) & 0x0000000F)))
#define ADC_COM_MASK_ADC_SEL_VREFP_VOL_0   ((u32)0x0000000F << 0)            /*!< R/W 4'b0100  AUX ADC Vrefp voltage: 0000:1.45V 0001:1.50V 0010:1.55V 0011:1.60V 0100:1.65V 0101:1.70V 0110:1.75V 0111:1.80V 1000:1.85V 1001:1.875V 1010:1.90V 1011:1.95V 1100:2.00V 1101:2.05V 1110:2.10V 1111:2.15V  Cs * VIN = 8C * Vrefp 3C * 5V = 8C * 1.875V 4C * 3.3V = 8C * 1.65V 8C * 1.8V = 8C * 1.8V AIF default 0100: 1.65V;*/
#define ADC_COM_ADC_SEL_VREFP_VOL_0(x)     (((u32)((x) & 0x0000000F) << 0))
#define ADC_COM_GET_ADC_SEL_VREFP_VOL_0(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup ADC_COM_ADC_VOL_LIST_1
  * @brief
  * @{
  */
#define ADC_COM_MASK_ADC_SEL_VREFP_VOL_15   ((u32)0x0000000F << 28)           /*!< R/W 4'b0100  Refer to adc_sel_vrefp_vol_0*/
#define ADC_COM_ADC_SEL_VREFP_VOL_15(x)     (((u32)((x) & 0x0000000F) << 28))
#define ADC_COM_GET_ADC_SEL_VREFP_VOL_15(x) ((u32)(((x >> 28) & 0x0000000F)))
#define ADC_COM_MASK_ADC_SEL_VREFP_VOL_14   ((u32)0x0000000F << 24)           /*!< R/W 4'b0100  Refer to adc_sel_vrefp_vol_0*/
#define ADC_COM_ADC_SEL_VREFP_VOL_14(x)     (((u32)((x) & 0x0000000F) << 24))
#define ADC_COM_GET_ADC_SEL_VREFP_VOL_14(x) ((u32)(((x >> 24) & 0x0000000F)))
#define ADC_COM_MASK_ADC_SEL_VREFP_VOL_13   ((u32)0x0000000F << 20)           /*!< R/W 4'b0100  Refer to adc_sel_vrefp_vol_0*/
#define ADC_COM_ADC_SEL_VREFP_VOL_13(x)     (((u32)((x) & 0x0000000F) << 20))
#define ADC_COM_GET_ADC_SEL_VREFP_VOL_13(x) ((u32)(((x >> 20) & 0x0000000F)))
#define ADC_COM_MASK_ADC_SEL_VREFP_VOL_12   ((u32)0x0000000F << 16)           /*!< R/W 4'b0100  Refer to adc_sel_vrefp_vol_0*/
#define ADC_COM_ADC_SEL_VREFP_VOL_12(x)     (((u32)((x) & 0x0000000F) << 16))
#define ADC_COM_GET_ADC_SEL_VREFP_VOL_12(x) ((u32)(((x >> 16) & 0x0000000F)))
#define ADC_COM_MASK_ADC_SEL_VREFP_VOL_11   ((u32)0x0000000F << 12)           /*!< R/W 4'b0100  Refer to adc_sel_vrefp_vol_0*/
#define ADC_COM_ADC_SEL_VREFP_VOL_11(x)     (((u32)((x) & 0x0000000F) << 12))
#define ADC_COM_GET_ADC_SEL_VREFP_VOL_11(x) ((u32)(((x >> 12) & 0x0000000F)))
#define ADC_COM_MASK_ADC_SEL_VREFP_VOL_10   ((u32)0x0000000F << 8)            /*!< R/W 4'b0100  Refer to adc_sel_vrefp_vol_0*/
#define ADC_COM_ADC_SEL_VREFP_VOL_10(x)     (((u32)((x) & 0x0000000F) << 8))
#define ADC_COM_GET_ADC_SEL_VREFP_VOL_10(x) ((u32)(((x >> 8) & 0x0000000F)))
#define ADC_COM_MASK_ADC_SEL_VREFP_VOL_9    ((u32)0x0000000F << 4)            /*!< R/W 4'b0100  Refer to adc_sel_vrefp_vol_0*/
#define ADC_COM_ADC_SEL_VREFP_VOL_9(x)      (((u32)((x) & 0x0000000F) << 4))
#define ADC_COM_GET_ADC_SEL_VREFP_VOL_9(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define ADC_COM_MASK_ADC_SEL_VREFP_VOL_8    ((u32)0x0000000F << 0)            /*!< R/W 4'b0100  Refer to adc_sel_vrefp_vol_0*/
#define ADC_COM_ADC_SEL_VREFP_VOL_8(x)      (((u32)((x) & 0x0000000F) << 0))
#define ADC_COM_GET_ADC_SEL_VREFP_VOL_8(x)  ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup ADC_COM_ADC_INSWING_SEL
  * @brief
  * @{
  */
#define ADC_COM_BIT_ADC_SEL_33VS18_V15 ((u32)0x00000001 << 31) /*!< R/W 'b0  Refer to adc_sel_33vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_33VS18_V14 ((u32)0x00000001 << 30) /*!< R/W 'b0  Refer to adc_sel_33vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_33VS18_V13 ((u32)0x00000001 << 29) /*!< R/W 'b0  Refer to adc_sel_33vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_33VS18_V12 ((u32)0x00000001 << 28) /*!< R/W 'b0  Refer to adc_sel_33vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_33VS18_V11 ((u32)0x00000001 << 27) /*!< R/W 'b0  Refer to adc_sel_33vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_33VS18_V10 ((u32)0x00000001 << 26) /*!< R/W 'b0  Refer to adc_sel_33vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_33VS18_V9  ((u32)0x00000001 << 25) /*!< R/W 'b0  Refer to adc_sel_33vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_33VS18_V8  ((u32)0x00000001 << 24) /*!< R/W 'b0  Refer to adc_sel_33vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_33VS18_V7  ((u32)0x00000001 << 23) /*!< R/W 'b0  Refer to adc_sel_33vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_33VS18_V6  ((u32)0x00000001 << 22) /*!< R/W 'b0  Refer to adc_sel_33vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_33VS18_V5  ((u32)0x00000001 << 21) /*!< R/W 'b0  Refer to adc_sel_33vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_33VS18_V4  ((u32)0x00000001 << 20) /*!< R/W 'b0  Refer to adc_sel_33vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_33VS18_V3  ((u32)0x00000001 << 19) /*!< R/W 'b0  Refer to adc_sel_33vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_33VS18_V2  ((u32)0x00000001 << 18) /*!< R/W 'b0  Refer to adc_sel_33vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_33VS18_V1  ((u32)0x00000001 << 17) /*!< R/W 'b0  Refer to adc_sel_33vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_33VS18_V0  ((u32)0x00000001 << 16) /*!< R/W 'b0  0:ADC Input Full swing is 3.3V; 1:ADC Input Full swing is 1.8V; AIF default 0; Each CH is independent*/
#define ADC_COM_BIT_ADC_SEL_5VS18_V15  ((u32)0x00000001 << 15) /*!< R/W 'b0  Refer to adc_sel_5vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_5VS18_V14  ((u32)0x00000001 << 14) /*!< R/W 'b0  Refer to adc_sel_5vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_5VS18_V13  ((u32)0x00000001 << 13) /*!< R/W 'b0  Refer to adc_sel_5vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_5VS18_V12  ((u32)0x00000001 << 12) /*!< R/W 'b0  Refer to adc_sel_5vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_5VS18_V11  ((u32)0x00000001 << 11) /*!< R/W 'b0  Refer to adc_sel_5vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_5VS18_V10  ((u32)0x00000001 << 10) /*!< R/W 'b0  Refer to adc_sel_5vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_5VS18_V9   ((u32)0x00000001 << 9)  /*!< R/W 'b0  Refer to adc_sel_5vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_5VS18_V8   ((u32)0x00000001 << 8)  /*!< R/W 'b0  Refer to adc_sel_5vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_5VS18_V7   ((u32)0x00000001 << 7)  /*!< R/W 'b0  Refer to adc_sel_5vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_5VS18_V6   ((u32)0x00000001 << 6)  /*!< R/W 'b0  Refer to adc_sel_5vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_5VS18_V5   ((u32)0x00000001 << 5)  /*!< R/W 'b0  Refer to adc_sel_5vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_5VS18_V4   ((u32)0x00000001 << 4)  /*!< R/W 'b0  Refer to adc_sel_5vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_5VS18_V3   ((u32)0x00000001 << 3)  /*!< R/W 'b0  Refer to adc_sel_5vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_5VS18_V2   ((u32)0x00000001 << 2)  /*!< R/W 'b0  Refer to adc_sel_5vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_5VS18_V1   ((u32)0x00000001 << 1)  /*!< R/W 'b0  Refer to adc_sel_5vs18_v0*/
#define ADC_COM_BIT_ADC_SEL_5VS18_V0   ((u32)0x00000001 << 0)  /*!< R/W 'b0  0 :ADC Input Full swing is 5V; 1: The input range depends on adc_sel_33vs18_v0 AIF default 0: Each CH is independent*/
/** @} */

/** @} */
/* Exported Types --------------------------------------------------------*/

/** @defgroup ADC_COM_Exported_Types ADC_COM Exported Types
  * @{
  */

/** @brief ADC_COM Register Declaration
  */

typedef struct {
	__IO uint32_t ADC_COM_ADC_CTRL0            ;  /*!< Register,  Address offset:0x000 */
	__IO uint32_t ADC_COM_ADC_CTRL1            ;  /*!< Register,  Address offset:0x004 */
	__IO uint32_t ADC_COM_CTC_CTRL             ;  /*!< Register,  Address offset:0x008 */
	__IO uint32_t ADC_COM_POW_CTRL             ;  /*!< Register,  Address offset:0x00C */
	__IO uint32_t ADC_COM_CTC_ONLY0            ;  /*!< Register,  Address offset:0x010 */
	__IO uint32_t ADC_COM_CTC_ONLY1            ;  /*!< Register,  Address offset:0x014 */
	__IO uint32_t ADC_COM_CTC_ONLY2            ;  /*!< Register,  Address offset:0x018 */
	__IO uint32_t ADC_COM_DRV_CFG              ;  /*!< Register,  Address offset:0x01C */
	__IO uint32_t ADC_COM_CTC_DECO             ;  /*!< Register,  Address offset:0x020 */
	__IO uint32_t ADC_COM_POW_CNT0             ;  /*!< Register,  Address offset:0x024 */
	__IO uint32_t ADC_COM_POW_CNT1             ;  /*!< Register,  Address offset:0x028 */
	__IO uint32_t RSVD0                        ;  /*!< Reserved,  Address offset:0x02C-0x02F */
	__IO uint32_t ADC_COM_ADC_CLK_HCNTx_DIV[16];  /*!< ADC CHANNEL CLOCK DIVIDER REGISTER,  Address offset:0x030-0x06C */
	__IO uint32_t ADC_COM_ADC_CLK_COV          ;  /*!< Register,  Address offset:0x070 */
	__IO uint32_t ADC_COM_ADC_VOL_LIST_0       ;  /*!< Register,  Address offset:0x074 */
	__IO uint32_t ADC_COM_ADC_VOL_LIST_1       ;  /*!< Register,  Address offset:0x078 */
	__IO uint32_t ADC_COM_ADC_INSWING_SEL      ;  /*!< Register,  Address offset:0x07C */
	__IO uint32_t ADC_COM_DUMMY                ;  /*!< DUMMY REGISTER,  Address offset:0x080 */
} ADC_COM_TypeDef;

/** @} */


// Do NOT modify any AUTO_GEN code above
/* AUTO_GEN_END */

/* MANUAL_GEN_START */

// Please add your definitions here

/* Exported Types ------------------------------------------------------------*/

/* Exported Constants --------------------------------------------------------*/
#define ADC_COM_BASE    CMP_REG_BASE
#define ADC_COM					((ADC_COM_TypeDef *)ADC_COM_BASE)

/** @defgroup ADC_Convert_Mode
  * @{
  */
#define ADC_CONV_500NS				((u8)0x0)
#define ADC_CONV_700NS				((u8)0x1)

#define IS_ADC_CONV_MODE(x)			((x) == ADC_CONV_500NS || \
																(x) == ADC_CONV_700NS)
/**
  * @}
  */

/* Exported Functions --------------------------------------------------------*/


/** @} */

/** @} */

// If other definitions do not need to be extracted to CHM document, add them here.
/* Other Definitions --------------------------------------------------------*/


/* MANUAL_GEN_END */

#endif