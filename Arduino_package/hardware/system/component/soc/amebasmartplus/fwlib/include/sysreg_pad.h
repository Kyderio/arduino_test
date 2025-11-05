/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _SYSREG_PAD_H_
#define _SYSREG_PAD_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup PAD
  * @brief PAD driver modules
  * @{
  */

/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup PAD_Register_Definitions PAD Register Definitions
  * @{
  */

/** @defgroup REG_Px
  * @brief GPIO group control
  * @{
  */
#define PAD_BIT_Px_DIS    ((u32)0x00000001 << 15)          /*!< R/W 0h  PAD shutdown, only when the whole group's dis signals are all 1, the PAD SHDN will pull down to shutdown the group pad. 1. disable pad 0. enable pad*/
#define PAD_BIT_Px_SR     ((u32)0x00000001 << 13)          /*!< R/W 1h  PAD srew rate control*/
#define PAD_BIT_Px_SMT    ((u32)0x00000001 << 12)          /*!< R/W 1h  PAD Schmit control*/
#define PAD_BIT_Px_E2     ((u32)0x00000001 << 11)          /*!< R/W 1h  PAD driving ability control. 0: low 1: high  The actual driving current is depend on pad type.*/
#define PAD_BIT_Px_PUPDC  ((u32)0x00000001 << 10)          /*!< R/W 0h  Some pad may have two type of PU/PD resistor, this bit can select it. 1: small resistor 0: big resistor*/
#define PAD_MASK_Px_SEL   ((u32)0x000000FF << 0)           /*!< R/W/ES 0h  PAD pinmux function ID selection*/
#define PAD_Px_SEL(x)     (((u32)((x) & 0x000000FF) << 0))
#define PAD_GET_Px_SEL(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_PAD_AUD_PAD_CTRL
  * @brief
  * @{
  */
#define PAD_MASK_GPIOC_IE   ((u32)0x001FFFFF << 0)           /*!< R/W 0h  Audio share pad input enable.*/
#define PAD_GPIOC_IE(x)     (((u32)((x) & 0x001FFFFF) << 0))
#define PAD_GET_GPIOC_IE(x) ((u32)(((x >> 0) & 0x001FFFFF)))
/** @} */

/** @defgroup REG_PAD_SDIO_PAD_CTRL
  * @brief
  * @{
  */
#define PAD_BIT_GPIOG_P5E ((u32)0x00000001 << 7) /*!< R/W 0h  SDIO pad drive control. All SDIO pad share the same parameter.*/
#define PAD_BIT_GPIOG_P4E ((u32)0x00000001 << 6) /*!< R/W 1h  SDIO pad drive control. All SDIO pad share the same parameter.*/
#define PAD_BIT_GPIOG_P3E ((u32)0x00000001 << 5) /*!< R/W 1h  SDIO pad drive control. All SDIO pad share the same parameter.*/
#define PAD_BIT_GPIOG_P2E ((u32)0x00000001 << 4) /*!< R/W 1h  SDIO pad drive control. All SDIO pad share the same parameter.*/
#define PAD_BIT_GPIOG_N5E ((u32)0x00000001 << 3) /*!< R/W 0h  SDIO pad drive control. All SDIO pad share the same parameter.*/
#define PAD_BIT_GPIOG_N4E ((u32)0x00000001 << 2) /*!< R/W 1h  SDIO pad drive control. All SDIO pad share the same parameter.*/
#define PAD_BIT_GPIOG_N3E ((u32)0x00000001 << 1) /*!< R/W 1h  SDIO pad drive control. All SDIO pad share the same parameter.*/
#define PAD_BIT_GPIOG_N2E ((u32)0x00000001 << 0) /*!< R/W 1h  SDIO pad drive control. All SDIO pad share the same parameter.*/
/** @} */

/** @defgroup REG_PAD_PU_1
  * @brief
  * @{
  */
#define PAD_MASK_PA_PU   ((u32)0xFFFFFFFF << 0)           /*!< R/W 2000h  PAD pull up enable when system is in active.*/
#define PAD_PA_PU(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define PAD_GET_PA_PU(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PAD_PU_2
  * @brief
  * @{
  */
#define PAD_MASK_PB_PU   ((u32)0xFFFFFFFF << 0)           /*!< R/W 01C00000h  PAD pull up enable when system is in active.*/
#define PAD_PB_PU(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define PAD_GET_PB_PU(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PAD_PU_3
  * @brief
  * @{
  */
#define PAD_MASK_PC_PU   ((u32)0xFFFFFFFF << 0)           /*!< R/W 40h  PAD pull up enable when system is in active.*/
#define PAD_PC_PU(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define PAD_GET_PC_PU(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PAD_PD_1
  * @brief
  * @{
  */
#define PAD_MASK_PA_PD   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0h  PAD pull down enable when system is in active.*/
#define PAD_PA_PD(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define PAD_GET_PA_PD(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PAD_PD_2
  * @brief
  * @{
  */
#define PAD_MASK_PB_PD   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0h  PAD pull down enable when system is in active.*/
#define PAD_PB_PD(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define PAD_GET_PB_PD(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PAD_PD_3
  * @brief
  * @{
  */
#define PAD_MASK_PC_PD   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0h  PAD pull down enable when system is in active.*/
#define PAD_PC_PD(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define PAD_GET_PC_PD(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PAD_PU_SLP_1
  * @brief
  * @{
  */
#define PAD_MASK_PA_PU_SLP   ((u32)0xFFFFFFFF << 0)           /*!< R/W 2000h  PAD pull up enable when system is in sleep.*/
#define PAD_PA_PU_SLP(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define PAD_GET_PA_PU_SLP(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PAD_PU_SLP_2
  * @brief
  * @{
  */
#define PAD_MASK_PB_PU_SLP   ((u32)0xFFFFFFFF << 0)           /*!< R/W 01C00000h  PAD pull up enable when system is in sleep.*/
#define PAD_PB_PU_SLP(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define PAD_GET_PB_PU_SLP(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PAD_PU_SLP_3
  * @brief
  * @{
  */
#define PAD_MASK_PC_PU_SLP   ((u32)0xFFFFFFFF << 0)           /*!< R/W 40h  PAD pull up enable when system is in sleep.*/
#define PAD_PC_PU_SLP(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define PAD_GET_PC_PU_SLP(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PAD_PD_SLP_1
  * @brief
  * @{
  */
#define PAD_MASK_PA_PD_SLP   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0h  PAD pull down enable when system is in sleep.*/
#define PAD_PA_PD_SLP(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define PAD_GET_PA_PD_SLP(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PAD_PD_SLP_2
  * @brief
  * @{
  */
#define PAD_MASK_PB_PD_SLP   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0h  PAD pull down enable when system is in sleep.*/
#define PAD_PB_PD_SLP(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define PAD_GET_PB_PD_SLP(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_PAD_PD_SLP_3
  * @brief
  * @{
  */
#define PAD_MASK_PC_PD_SLP   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0h  PAD pull down enable when system is in sleep.*/
#define PAD_PC_PD_SLP(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define PAD_GET_PC_PD_SLP(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_VOLTAGE_PROBE_OE
  * @brief
  * @{
  */
#define PAD_BIT_VPROB_CA7_OE         ((u32)0x00000001 << 0)  /*!< R/W/ES 0h  */
#define PAD_BIT_VPROB_DDRPHY0_OE     ((u32)0x00000001 << 1)  /*!< R/W 0h  */
#define PAD_BIT_VPROB_DDRPHY1_OE     ((u32)0x00000001 << 2)  /*!< R/W 0h  */
#define PAD_BIT_VPROB_LEFT_OE        ((u32)0x00000001 << 3)  /*!< R/W 0h  */
#define PAD_BIT_VPROB_RIGHTBOTTOM_OE ((u32)0x00000001 << 4)  /*!< R/W 0h  */
#define PAD_BIT_VPROB_RIGHTTOP_OE    ((u32)0x00000001 << 5)  /*!< R/W 0h  */
#define PAD_BIT_VPROB_LP_SYSON_OE    ((u32)0x00000001 << 6)  /*!< R/W 0h  */
#define PAD_BIT_VPROB_WIFI_OE        ((u32)0x00000001 << 7)  /*!< R/W 0h  */
#define PAD_BIT_VPROB_DDRC_OE        ((u32)0x00000001 << 8)  /*!< R/W 0h  */
#define PAD_BIT_VPROB_NP_OE          ((u32)0x00000001 << 9)  /*!< R/W 0h  */
#define PAD_BIT_VPROB_EN0            ((u32)0x00000001 << 10) /*!< R/W 0h  */
#define PAD_BIT_VPROB_TOPLEFT_OE     ((u32)0x00000001 << 11) /*!< R/W 0h  add in MP*/
/** @} */

/** @defgroup REG_DBG_PORT_CTRL
  * @brief
  * @{
  */
#define PAD_BIT_DBG_PORT_EN     ((u32)0x00000001 << 31)          /*!< R/W 0h  enable dbgmux function*/
#define PAD_BIT_DBG_PORT_EN2    ((u32)0x00000001 << 30)          /*!< R/WA0 0h  Write this bit to trigger all GPIO pad's FUNC ID changes to debug port function. After writing this bit, the sel bits in every pad register will change to FUNC debug port value. And this bit will be cleared by HW.*/
#define PAD_MASK_DBG_PORT_SEL   ((u32)0x000000FF << 0)           /*!< R/W 0h  select the debug port's specific connection with different IP. The specific relationship is refered to the dbg port spec.*/
#define PAD_DBG_PORT_SEL(x)     (((u32)((x) & 0x000000FF) << 0))
#define PAD_GET_DBG_PORT_SEL(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_DBG_GPIO_MAP_0
  * @brief
  * @{
  */
#define PAD_MASK_GPIO_DMUX_SEL3   ((u32)0x0000001F << 24)           /*!< R/W 3h  */
#define PAD_GPIO_DMUX_SEL3(x)     (((u32)((x) & 0x0000001F) << 24))
#define PAD_GET_GPIO_DMUX_SEL3(x) ((u32)(((x >> 24) & 0x0000001F)))
#define PAD_MASK_GPIO_DMUX_SEL2   ((u32)0x0000001F << 16)           /*!< R/W 2h  */
#define PAD_GPIO_DMUX_SEL2(x)     (((u32)((x) & 0x0000001F) << 16))
#define PAD_GET_GPIO_DMUX_SEL2(x) ((u32)(((x >> 16) & 0x0000001F)))
#define PAD_MASK_GPIO_DMUX_SEL1   ((u32)0x0000001F << 8)            /*!< R/W 1h  */
#define PAD_GPIO_DMUX_SEL1(x)     (((u32)((x) & 0x0000001F) << 8))
#define PAD_GET_GPIO_DMUX_SEL1(x) ((u32)(((x >> 8) & 0x0000001F)))
#define PAD_MASK_GPIO_DMUX_SEL0   ((u32)0x0000001F << 0)            /*!< R/W 0h  */
#define PAD_GPIO_DMUX_SEL0(x)     (((u32)((x) & 0x0000001F) << 0))
#define PAD_GET_GPIO_DMUX_SEL0(x) ((u32)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_DBG_GPIO_MAP_1
  * @brief
  * @{
  */
#define PAD_MASK_GPIO_DMUX_SEL7   ((u32)0x0000001F << 24)           /*!< R/W 7h  */
#define PAD_GPIO_DMUX_SEL7(x)     (((u32)((x) & 0x0000001F) << 24))
#define PAD_GET_GPIO_DMUX_SEL7(x) ((u32)(((x >> 24) & 0x0000001F)))
#define PAD_MASK_GPIO_DMUX_SEL6   ((u32)0x0000001F << 16)           /*!< R/W 6h  */
#define PAD_GPIO_DMUX_SEL6(x)     (((u32)((x) & 0x0000001F) << 16))
#define PAD_GET_GPIO_DMUX_SEL6(x) ((u32)(((x >> 16) & 0x0000001F)))
#define PAD_MASK_GPIO_DMUX_SEL5   ((u32)0x0000001F << 8)            /*!< R/W 5h  */
#define PAD_GPIO_DMUX_SEL5(x)     (((u32)((x) & 0x0000001F) << 8))
#define PAD_GET_GPIO_DMUX_SEL5(x) ((u32)(((x >> 8) & 0x0000001F)))
#define PAD_MASK_GPIO_DMUX_SEL4   ((u32)0x0000001F << 0)            /*!< R/W 4h  */
#define PAD_GPIO_DMUX_SEL4(x)     (((u32)((x) & 0x0000001F) << 0))
#define PAD_GET_GPIO_DMUX_SEL4(x) ((u32)(((x >> 0) & 0x0000001F)))
/** @} */

/** @defgroup REG_PINMUX_SUB_CTRL
  * @brief
  * @{
  */
#define PAD_MASK_FLASH_PG1B_SE      ((u32)0x0000000F << 12)           /*!< R/W 0xd  When TestMode 13 , using 1bit mode to pg MCM flash using ext pin . [0] : if 1 , ext spi_data0 pin fix to input ,  if 0 ext spi_data0 pin fix to output [1] : if 1 , ext spi_data1 pin fix to input ,  if 0 ext spi_data1 pin fix to output [2] : if 1 , ext spi_data2 pin fix to input ,  if 0 ext spi_data2 pin fix to output [3] : if 1 , ext spi_data3 pin fix to input ,  if 0 ext spi_data3 pin fix to output default is : 1101  which only data1 using as output.*/
#define PAD_FLASH_PG1B_SE(x)        (((u32)((x) & 0x0000000F) << 12))
#define PAD_GET_FLASH_PG1B_SE(x)    ((u32)(((x >> 12) & 0x0000000F)))
#define PAD_BIT_TRANS_GATE_EN       ((u32)0x00000001 << 10)           /*!< R/W 0h  */
#define PAD_BIT_TRANS_GATE_HWPDN    ((u32)0x00000001 << 9)            /*!< R/W 1h  */
#define PAD_MASK_AUX_TEST_SUBMODE   ((u32)0x00000007 << 5)            /*!< R/W 0h  000: aux adc test 001: flash pll 010: i2s pll 011: i2s signal 100: debug clock 101: power*/
#define PAD_AUX_TEST_SUBMODE(x)     (((u32)((x) & 0x00000007) << 5))
#define PAD_GET_AUX_TEST_SUBMODE(x) ((u32)(((x >> 5) & 0x00000007)))
#define PAD_MASK_SWR_TEST_SEL       ((u32)0x00000003 << 0)            /*!< R/W 0h  00/11: swr core test out 01: aud/psram swr test out 10: ddr mem swr test out*/
#define PAD_SWR_TEST_SEL(x)         (((u32)((x) & 0x00000003) << 0))
#define PAD_GET_SWR_TEST_SEL(x)     ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_SWD_SDD_CTRL
  * @brief
  * @{
  */
#define PAD_BIT_SDD_PMUX_EN ((u32)0x00000001 << 2) /*!< R/W 0x0  1: Enable SDIO pinmux enable function 0: Disable*/
#define PAD_BIT_SWD_PMUX_EN ((u32)0x00000001 << 0) /*!< R/W 0x1  1: Enable SWD pinmux enable function 0: Disable SWD_LOC is valid only when this bit is 1.*/
/** @} */

/*==========PAD Register Address Definition==========*/
#define REG_PAD_AUD_PAD_CTRL           0x140
#define REG_PAD_SDIO_PAD_CTRL          0x144
#define REG_PAD_PU_1                   0x180
#define REG_PAD_PU_2                   0x184
#define REG_PAD_PU_3                   0x188
#define REG_PAD_PD_1                   0x190
#define REG_PAD_PD_2                   0x194
#define REG_PAD_PD_3                   0x198
#define REG_PAD_PU_SLP_1               0x1A0
#define REG_PAD_PU_SLP_2               0x1A4
#define REG_PAD_PU_SLP_3               0x1A8
#define REG_PAD_PD_SLP_1               0x1B0
#define REG_PAD_PD_SLP_2               0x1B4
#define REG_PAD_PD_SLP_3               0x1B8
#define REG_VOLTAGE_PROBE_OE           0x1DC
#define REG_PAD_EXTRA_CTRL             0x1E0
#define REG_DBG_PORT_CTRL              0x1E4
#define REG_DBG_GPIO_MAP_0             0x1E8
#define REG_DBG_GPIO_MAP_1             0x1EC
#define REG_PINMUX_SUB_CTRL            0x1F0
#define REG_DBG_PORT_VAL               0x1F4
#define REG_SWD_SDD_CTRL               0x1F8

/** @} */


// Do NOT modify any AUTO_GEN code above
/* AUTO_GEN_END */

/* MANUAL_GEN_START */

//Please add your defination here


/* MANUAL_GEN_END */

#endif