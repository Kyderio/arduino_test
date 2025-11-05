/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _AMEBA_RXI300_H_
#define _AMEBA_RXI300_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup RXI300
  * @brief RXI300 driver modules
  * @{
  */

/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup RXI300_Register_Definitions RXI300 Register Definitions
  * @{
  */

/** @defgroup PPC1_REG
  * @brief PPC1 configure register
  * @{
  */
#define RXI300_BIT_CAP_TOUCH       ((u32)0x00000001 << 10) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_ADC_ADC_COMP    ((u32)0x00000001 << 9)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_GPIO_A_B_C      ((u32)0x00000001 << 8)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_TIMER_0_3_BASIC ((u32)0x00000001 << 7)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_PMC_TIMER_1     ((u32)0x00000001 << 6)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_IPC_P0          ((u32)0x00000001 << 5)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_UART_LOG        ((u32)0x00000001 << 4)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_UART2           ((u32)0x00000001 << 3)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_UART1           ((u32)0x00000001 << 2)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_UART0           ((u32)0x00000001 << 1)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_LP_SYSON        ((u32)0x00000001 << 0)  /*!< R/W 1h  1: Non-secure attribution 0: Secure attribution*/
/** @} */

/** @defgroup PPC2_REG
  * @brief PPC2 configure register
  * @{
  */
#define RXI300_BIT_SPIC_USER_MODE             ((u32)0x00000001 << 22) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_QSPI_USER_MODE             ((u32)0x00000001 << 21) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_PSRAM_SPIC_USERMODE        ((u32)0x00000001 << 20) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_PSRAM_PHY                  ((u32)0x00000001 << 19) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_PPE_CFG                    ((u32)0x00000001 << 18) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_MJPEG_CFG                  ((u32)0x00000001 << 17) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_I2C1                       ((u32)0x00000001 << 16) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_I2C0                       ((u32)0x00000001 << 15) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_TIMER_6_10_PULSE_PWM_TIMER ((u32)0x00000001 << 14) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_RSIP                       ((u32)0x00000001 << 13) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_P0                         ((u32)0x00000001 << 12) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_I3C0                       ((u32)0x00000001 << 11) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_LCDC_CFG                   ((u32)0x00000001 << 10) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_SPI1                       ((u32)0x00000001 << 9)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_SPI0                       ((u32)0x00000001 << 8)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_SPORT_I2S                  ((u32)0x00000001 << 7)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_SDIO_DEVICE_CFG            ((u32)0x00000001 << 6)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_USB_CFG                    ((u32)0x00000001 << 5)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_DVP_CFG                    ((u32)0x00000001 << 4)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_CAN1                       ((u32)0x00000001 << 3)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_CAN0                       ((u32)0x00000001 << 2)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_GDMA0_CFG                  ((u32)0x00000001 << 1)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_RMII_CFG                   ((u32)0x00000001 << 0)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
/** @} */

/** @defgroup PPC3_REG
  * @brief PPC3 configure register
  * @{
  */
#define RXI300_BIT_TIMER_4_5_BASIC  ((u32)0x00000001 << 22) /*!< R/W 0h  1: Non-secure attribution 2: Secure attribution*/
#define RXI300_BIT_PMC_TIMER_0      ((u32)0x00000001 << 21) /*!< R/W 0h  1: Non-secure attribution 1: Secure attribution*/
#define RXI300_BIT_DBG_TIMER        ((u32)0x00000001 << 20) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_IPC_P1           ((u32)0x00000001 << 19) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_UART_BT          ((u32)0x00000001 << 18) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_HP_SYSON         ((u32)0x00000001 << 17) /*!< R/W 1h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_OTPC_CFG         ((u32)0x00000001 << 16) /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_TRNG_PORT1_PORT2 ((u32)0x00000001 << 8)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_P1               ((u32)0x00000001 << 7)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_SHA_KEY_MANAGE   ((u32)0x00000001 << 6)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_AES_KEY_MANAGE   ((u32)0x00000001 << 5)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_AES_SHA_DMA      ((u32)0x00000001 << 4)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_SHA_CFG          ((u32)0x00000001 << 3)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_AES_CFG          ((u32)0x00000001 << 2)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_PKE_CFG          ((u32)0x00000001 << 1)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
#define RXI300_BIT_WIFI_CFG         ((u32)0x00000001 << 0)  /*!< R/W 0h  1: Non-secure attribution 0: Secure attribution*/
/** @} */

/** @defgroup PPC_LOCK
  * @brief PPC Lock register
  * @{
  */
#define RXI300_BIT_LOCK ((u32)0x00000001 << 0) /*!< R/W 0h  PPC lock register. When writing 1'b1 to this bit, PPC will be locked. Note: It can not be written to 1'b0 again until system reset to prevent modification. When PPC is locked, you can not program PPC registers unless system reset.*/
/** @} */

/** @defgroup DISCONNECT_PLFM1
  * @brief Disconnect platform register1
  * @{
  */
#define RXI300_BIT_DISCONNECT_PLFM1 ((u32)0x00000001 << 0) /*!< R/W 0h  Platform1-to-platform0 peripheral path are 0x0: connect                                                                                                                                                                                                                                       0x1: disconnect When writing 1'b1 to this bit, the register willl be locked. NOTE: It can not be written to 1'b0 again until system reset to prevent modification.When this regitster is locked, you can not program this register unless system reset.*/
/** @} */

/** @defgroup RESET_CONTROL
  * @brief Reset flow control register
  * @{
  */
#define RXI300_BIT_TIMEOUT_TRIGGER_N ((u32)0x00000001 << 1) /*!< R/W 1h  Trigger all timeout monitors in platform0 to block transaction from platform1. 0x0: trigger timeout                                                                                                                                                                                                                                       0x1: idle NOTE: The register is not a write-1-clear register. User should set this register to 0x1(idle) after timeout is triggered.*/
#define RXI300_BIT_P1_MASTER_DISABLE ((u32)0x00000001 << 0) /*!< R/W 0h  Master enable signal. All master agent  of platform1-to-platform are 0x0: enable                                                                                                                                                                                                                                          0x1: disable*/
/** @} */

/** @defgroup RESET_STATUS
  * @brief Reset flow status register
  * @{
  */
#define RXI300_BIT_PLFM1_SLV_OSW   ((u32)0x00000001 << 8) /*!< RO 0h  Write  transaction number of KM4TZ which remains in platform1 slaves.The platform1 slaves are 0x0: idle                                                                                                                                                                                                                                                  0x1: has at least one write OST*/
#define RXI300_BIT_PLFM1_SLV_OSR   ((u32)0x00000001 << 7) /*!< RO 0h  Read transaction number of KM4TZ which remains in platform1 slaves.The platform1 slaves are 0x0: idle                                                                                                                                                                                                                                                  0x1: has at least one read OST*/
#define RXI300_BIT_TMO_TRIG_PLFM1  ((u32)0x00000001 << 6) /*!< RO 0h  Status of AES_SHA/SIC/OTPC/WIFI timeout monitor.The timeout is 0x0: disable                                                                                                                                                                                                                                            0x1: enable*/
#define RXI300_BIT_TMO_TRIG_WIFI   ((u32)0x00000001 << 5) /*!< RO 0h  Status of WIFI  timeout monitor.The timeout is 0x0: disable                                                                                                                                                                                                                                            0x0: enable*/
#define RXI300_BIT_TMO_TRIG_KM4    ((u32)0x00000001 << 4) /*!< RO 0h  Status of CPU domain timeout monitor.The timeout is 0x0: disable                                                                                                                                                                                                                                            0x1: enable*/
#define RXI300_BIT_MST_STAT_OTHERS ((u32)0x00000001 << 2) /*!< RO 1h  Status of AES_SHA/SIC/OTPC/WIFI  master agent. The master is 0x0: idle                                                                                                                                                                                                                                                  0x1: active*/
#define RXI300_BIT_MST_STAT_WIFI   ((u32)0x00000001 << 1) /*!< RO 1h  Status of WIFI master agent. The master is 0x0: idle                                                                                                                                                                                                                                                  0x1: active*/
#define RXI300_BIT_MST_STAT_KM4NS  ((u32)0x00000001 << 0) /*!< RO 1h  Status of KM4NS master agent. The master is 0x0: idle                                                                                                                                                                                                                                                  0x1: active*/
/** @} */

/** @defgroup ELR_PLD0_S
  * @brief Error log payload register0
  * @{
  */
#define RXI300_MASK_ELR_BSTINDEX_S   ((u32)0x000000FF << 24)           /*!< R 0h  Burst index of the error request.*/
#define RXI300_ELR_BSTINDEX_S(x)     (((u32)((x) & 0x000000FF) << 24))
#define RXI300_GET_ELR_BSTINDEX_S(x) ((u32)(((x >> 24) & 0x000000FF)))
#define RXI300_MASK_ELR_BSTLEN_S     ((u32)0x000000FF << 16)           /*!< R 0h  Burst Length of the error request.*/
#define RXI300_ELR_BSTLEN_S(x)       (((u32)((x) & 0x000000FF) << 16))
#define RXI300_GET_ELR_BSTLEN_S(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define RXI300_MASK_ELR_BSTTYPE_S    ((u32)0x00000007 << 11)           /*!< R 0h  BurstSeq of the error request.*/
#define RXI300_ELR_BSTTYPE_S(x)      (((u32)((x) & 0x00000007) << 11))
#define RXI300_GET_ELR_BSTTYPE_S(x)  ((u32)(((x >> 11) & 0x00000007)))
#define RXI300_MASK_ELR_CMD_S        ((u32)0x00000007 << 8)            /*!< R 0h  CMD of the error request. 0x1: Write command 0x2: Read command*/
#define RXI300_ELR_CMD_S(x)          (((u32)((x) & 0x00000007) << 8))
#define RXI300_GET_ELR_CMD_S(x)      ((u32)(((x >> 8) & 0x00000007)))
#define RXI300_MASK_ELR_SRC_S        ((u32)0x000000FF << 0)            /*!< R 0h  Error source of the error request. 0x10: secure default slave of P0S0                                                                                                                                                                                                0x11: secure default slave of P0S1-12~P0S1-16 0x12: secure default slave of P0S1-5~P0S1-7                                                                                                                                                                                               0x13: secure default slave of P0S1-1~P0S1-4, P0S1-8~P0S1-11                                                                                                                                                                                            0x14: secure default slave of P0S1-0                                                                                                                                                                                                0x15: secure default slave of P0S1-22                                                                                                                                                                                              0x16: secure default slave of P0S1-19~P0S1-21,  P0S2                                                                                                                                                                                                 0x17: secure default slave of P0S1-17, P0S1-18                                                                                                                                                                               0x20: secure default slave of P2S0                                                                                                                                                                                      0x21: secure default slave of P3S0                                                                                                                                                                                                0x22: secure default slave of P4S0*/
#define RXI300_ELR_SRC_S(x)          (((u32)((x) & 0x000000FF) << 0))
#define RXI300_GET_ELR_SRC_S(x)      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup ELR_PLD1_S
  * @brief Error log payload register1
  * @{
  */
#define RXI300_MASK_ELR_LOCK_S    ((u32)0x00000003 << 30)           /*!< R 0h  AxLock of the error request.*/
#define RXI300_ELR_LOCK_S(x)      (((u32)((x) & 0x00000003) << 30))
#define RXI300_GET_ELR_LOCK_S(x)  ((u32)(((x >> 30) & 0x00000003)))
#define RXI300_MASK_ELR_CACHE_S   ((u32)0x0000000F << 26)           /*!< R 0h  AxCache of the error request.*/
#define RXI300_ELR_CACHE_S(x)     (((u32)((x) & 0x0000000F) << 26))
#define RXI300_GET_ELR_CACHE_S(x) ((u32)(((x >> 26) & 0x0000000F)))
#define RXI300_MASK_ELR_PROT_S    ((u32)0x00000007 << 23)           /*!< R 0h  AxProt of the error request.*/
#define RXI300_ELR_PROT_S(x)      (((u32)((x) & 0x00000007) << 23))
#define RXI300_GET_ELR_PROT_S(x)  ((u32)(((x >> 23) & 0x00000007)))
#define RXI300_MASK_ELR_SIZE_S    ((u32)0x00000007 << 16)           /*!< R 0h  Size of the error request.*/
#define RXI300_ELR_SIZE_S(x)      (((u32)((x) & 0x00000007) << 16))
#define RXI300_GET_ELR_SIZE_S(x)  ((u32)(((x >> 16) & 0x00000007)))
/** @} */

/** @defgroup ELR_ID_S
  * @brief Error log ID information register
  * @{
  */
#define RXI300_MASK_ELR_ID_S   ((u32)0xFFFFFFFF << 0)           /*!< R 0h  Tagid of the error request. 8'b00000???: M0 access error 8'b000100??: M1 access error 8'b0100????: M2 access error 8'b000101??: M3 access error 8'b0101000?: M4 access error 8'b0001100?: M5 access error 8'b01100???: M6 access error     8'b001?????: M7 access error 8'b1101????: M8 access error 8'b11100???: M9 access error 8'b1111000?: M10 access error 8'b101?????: M11 access error*/
#define RXI300_ELR_ID_S(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define RXI300_GET_ELR_ID_S(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup ELR_ADR0_S
  * @brief Error log addrress register0
  * @{
  */
#define RXI300_MASK_ELR_ADR0_S   ((u32)0xFFFFFFFF << 0)           /*!< R 0h  Address[31:0] of the error request.*/
#define RXI300_ELR_ADR0_S(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define RXI300_GET_ELR_ADR0_S(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup ELR_ADR1_S
  * @brief Error log addrress register1
  * @{
  */
#define RXI300_MASK_ELR_ADR1_S   ((u32)0xFFFFFFFF << 32)           /*!< R 0h  Address[63:32] of the error request.*/
#define RXI300_ELR_ADR1_S(x)     (((u32)((x) & 0xFFFFFFFF) << 32))
#define RXI300_GET_ELR_ADR1_S(x) ((u32)(((x >> 32) & 0xFFFFFFFF)))
/** @} */

/** @defgroup ELR_CODE_S
  * @brief Error code register
  * @{
  */
#define RXI300_MASK_ELR_CODE_S   ((u32)0x000000FF << 0)           /*!< R 0h  The error code of error request, if it's 0, indicates that there is no error request.  8'h00: No error 8'h02: Secure fault error*/
#define RXI300_ELR_CODE_S(x)     (((u32)((x) & 0x000000FF) << 0))
#define RXI300_GET_ELR_CODE_S(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup ELR_INTR_CLR_S
  * @brief Error log clear register
  * @{
  */
#define RXI300_BIT_ELR_INTR_CLR_S ((u32)0x00000001 << 0) /*!< W 0h  Error log interrupt clear. Writing 1'b1 to the register will trigger a 1-cycle pulse interrupt clear. It has to write 1'b1 to this register every time when the error exception occurs. Note that this register is write-only, the return value of reading this register is meaningless.*/
/** @} */

/** @defgroup NAME
  * @brief RXI300 design name register
  * @{
  */
#define RXI300_MASK_NAME   ((u32)0xFFFFFFFF << 0)           /*!< R 00052300h  The design name of RXI-300.*/
#define RXI300_NAME(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define RXI300_GET_NAME(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup VER
  * @brief RXI300 design version register
  * @{
  */
#define RXI300_MASK_VER   ((u32)0xFFFFFFFF << 0)           /*!< R 00000300h  The design version of RXI-300.*/
#define RXI300_VER(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define RXI300_GET_VER(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup RVE
  * @brief RXI300 design reversion register
  * @{
  */
#define RXI300_MASK_REV   ((u32)0xFFFFFFFF << 0)           /*!< R 3h  The design reversion of RXI-300.*/
#define RXI300_REV(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define RXI300_GET_REV(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup INST
  * @brief RXI300 design instance number register
  * @{
  */
#define RXI300_MASK_INST   ((u32)0xFFFFFFFF << 0)           /*!< R 0h  The design instance number of RXI-300.*/
#define RXI300_INST(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define RXI300_GET_INST(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup IMPL_Y
  * @brief RXI300 implementation year register
  * @{
  */
#define RXI300_MASK_IMPL_Y   ((u32)0xFFFFFFFF << 0)           /*!< R 2025h  The implementatin year of RXI-300. Reset value depends on implementation date.*/
#define RXI300_IMPL_Y(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define RXI300_GET_IMPL_Y(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup IMPL_D
  * @brief RXI300 implementation date register
  * @{
  */
#define RXI300_MASK_IMPL_D   ((u32)0xFFFFFFFF << 0)           /*!< R 03211627h  The implementatin date of RXI-300. Reset value depends on implementation date.*/
#define RXI300_IMPL_D(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define RXI300_GET_IMPL_D(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup DEV
  * @brief RXI300 developer register
  * @{
  */
#define RXI300_MASK_DEV   ((u32)0xFFFFFFFF << 0)           /*!< R 05207433h  The developer of RXI-300.*/
#define RXI300_DEV(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define RXI300_GET_DEV(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup PRO_NUM
  * @brief RXI300 project number register
  * @{
  */
#define RXI300_MASK_PRO_NUM   ((u32)0xFFFFFFFF << 0)           /*!< R 00006955h  The project number of RXI-300.*/
#define RXI300_PRO_NUM(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define RXI300_GET_PRO_NUM(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup IDAU_BAx
  * @brief Base address registerx in IDAU
  * @{
  */
#define RXI300_MASK_IDAU_BAx   ((u32)0x0000FFFF << 12)           /*!< R/W 0h  It's the base address of region x which can be set as non-secure.                                                                                                        [27:12]: base address of region x*/
#define RXI300_IDAU_BAx(x)     (((u32)((x) & 0x0000FFFF) << 12))
#define RXI300_GET_IDAU_BAx(x) ((u32)(((x >> 12) & 0x0000FFFF)))
/** @} */

/** @defgroup IDAU_LAx
  * @brief Top address registerx   in IDAU
  * @{
  */
#define RXI300_MASK_IDAU_LAx   ((u32)0x0000FFFF << 12)           /*!< R/W 0h  It's the top address of region x which can be set as non-secure. [27:12]: top address of region x*/
#define RXI300_IDAU_LAx(x)     (((u32)((x) & 0x0000FFFF) << 12))
#define RXI300_GET_IDAU_LAx(x) ((u32)(((x >> 12) & 0x0000FFFF)))
/** @} */

/** @defgroup IDAU_CTRL
  * @brief Enable control register in IDAU
  * @{
  */
#define RXI300_MASK_IDAU_WRITE_CTRL    ((u32)0x0000003F << 16)           /*!< R/W 0h  Region entry enable After setting WRITE_CTRL bits as 1, corresponding regions is set as write-forbidden.Note that if WRITE_CTRL bits are not enabled, the region remains secure even if ba*i/la*i is set. [16]: enable entry for ba0/la0 0: disable  1: enable                                                                                                                                                                                                                                                     [17]: enable entry for ba1/la1 0: disable  1: enable                                                                                                                                                                                                                                              [18]: enable entry for ba2/la2 0: disable  1: enable [19]: enable entry for ba3/la3 0: disable  1: enable                                                                                                                                                                                                                                                 [20]: enable entry for ba4/la4 0: disable  1: enable                                                                                                                                                                                                                                               [21]: enable entry for ba5/la5 0: disable  1: enable*/
#define RXI300_IDAU_WRITE_CTRL(x)      (((u32)((x) & 0x0000003F) << 16))
#define RXI300_GET_IDAU_WRITE_CTRL(x)  ((u32)(((x >> 16) & 0x0000003F)))
#define RXI300_MASK_IDAU_SECURE_CTRL   ((u32)0x0000003F << 0)            /*!< R/W 0h  Region entry enable After setting SECURE_CTRL bits as 1, corresponding regions is set as non-secure.Note that if SECURE_CTRL bits are not enabled, the region remains secure even if ba*i/la*i is set. [0]: enable entry for ba0/la0 0: disable  1: enable                                                                                                                                                                                                                                                 [1]: enable entry for ba1/la1 0: disable  1: enable                                                                                                                                                                                                                                                  [2]: enable entry for ba2/la2 0: disable  1: enable [3]: enable entry for ba3/la3 0: disable  1: enable                                                                                                                                                                                                                                                 [4]: enable entry for ba4/la4 0: disable  1: enable                                                                                                                                                                                                                                                  [5]: enable entry for ba5/la5 0: disable  1: enable*/
#define RXI300_IDAU_SECURE_CTRL(x)     (((u32)((x) & 0x0000003F) << 0))
#define RXI300_GET_IDAU_SECURE_CTRL(x) ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup IDAU_LOCK
  * @brief Lock control register in IDAU
  * @{
  */
#define RXI300_BIT_IDAU_LOCK ((u32)0x00000001 << 0) /*!< R/W 0h  Lock write transfer for all registers in IDAU (including lock register itself) until system reset if it is ebabled. [0]: lock bit for all register in IDAU                                                                                                                                                                                                              0: disable lock  1: enable lock*/
/** @} */

/** @defgroup IDAU1_BAx
  * @brief Base address registerx in IDAU
  * @{
  */
#define RXI300_MASK_IDAU1_BAx   ((u32)0x0000FFFF << 12)           /*!< R/W 0h  It's the base address of region x which can be set as non-secure.                                                                                                        [27:12]: base address of region x*/
#define RXI300_IDAU1_BAx(x)     (((u32)((x) & 0x0000FFFF) << 12))
#define RXI300_GET_IDAU1_BAx(x) ((u32)(((x >> 12) & 0x0000FFFF)))
/** @} */

/** @defgroup IDAU1_LAx
  * @brief Top address registerx   in IDAU
  * @{
  */
#define RXI300_MASK_IDAU1_LAx   ((u32)0x0000FFFF << 12)           /*!< R/W FF000h  It's the top address of region x which can be set as non-secure. [27:12]: top address of region x*/
#define RXI300_IDAU1_LAx(x)     (((u32)((x) & 0x0000FFFF) << 12))
#define RXI300_GET_IDAU1_LAx(x) ((u32)(((x >> 12) & 0x0000FFFF)))
/** @} */

/** @defgroup IDAU1_CTRL
  * @brief Enable control register in IDAU
  * @{
  */
#define RXI300_MASK_WRITE_CTRL    ((u32)0x0000003F << 16)           /*!< R/W 0h  Region entry enable After setting WRITE_CTRL bits as 1, corresponding regions is set as write-forbidden.Note that if WRITE_CTRL bits are not enabled, the region remains secure even if ba*i/la*i is set. [16]: enable entry for ba0/la0 0: disable  1: enable                                                                                                                                                                                                                                                     [17]: enable entry for ba1/la1 0: disable  1: enable                                                                                                                                                                                                                                              [18]: enable entry for ba2/la2 0: disable  1: enable [19]: enable entry for ba3/la3 0: disable  1: enable                                                                                                                                                                                                                                                 [20]: enable entry for ba4/la4 0: disable  1: enable                                                                                                                                                                                                                                               [21]: enable entry for ba5/la5 0: disable  1: enable*/
#define RXI300_WRITE_CTRL(x)      (((u32)((x) & 0x0000003F) << 16))
#define RXI300_GET_WRITE_CTRL(x)  ((u32)(((x >> 16) & 0x0000003F)))
#define RXI300_MASK_SECURE_CTRL   ((u32)0x0000003F << 0)            /*!< R/W 0h  Region entry enable After setting SECURE_CTRL bits as 1, corresponding regions is set as non-secure.Note that if SECURE_CTRL bits are not enabled, the region remains secure even if ba*i/la*i is set. [0]: enable entry for ba0/la0 0: disable  1: enable                                                                                                                                                                                                                                                 [1]: enable entry for ba1/la1 0: disable  1: enable                                                                                                                                                                                                                                                  [2]: enable entry for ba2/la2 0: disable  1: enable [3]: enable entry for ba3/la3 0: disable  1: enable                                                                                                                                                                                                                                                 [4]: enable entry for ba4/la4 0: disable  1: enable                                                                                                                                                                                                                                                  [5]: enable entry for ba5/la5 0: disable  1: enable*/
#define RXI300_SECURE_CTRL(x)     (((u32)((x) & 0x0000003F) << 0))
#define RXI300_GET_SECURE_CTRL(x) ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup IDAU1_LOCK
  * @brief Lock control register in IDAU
  * @{
  */
#define RXI300_BIT_IDAU_LOCK ((u32)0x00000001 << 0) /*!< R/W 0h  Lock write transfer for all registers in IDAU (including lock register itself) until system reset if it is ebabled. [0]: lock bit for all register in IDAU                                                                                                                                                                                                              0: disable lock  1: enable lock*/
/** @} */

/** @defgroup IDAU2_BAx
  * @brief Base address registerx in IDAU
  * @{
  */
#define RXI300_MASK_IDAU2_BAx   ((u32)0x0000FFFF << 12)           /*!< R/W 0h  It's the base address of region x which can be set as non-secure.           [27:12]: base address of region x*/
#define RXI300_IDAU2_BAx(x)     (((u32)((x) & 0x0000FFFF) << 12))
#define RXI300_GET_IDAU2_BAx(x) ((u32)(((x >> 12) & 0x0000FFFF)))
/** @} */

/** @defgroup IDAU2_LAx
  * @brief Top address registerx   in IDAU
  * @{
  */
#define RXI300_MASK_IDAU2_LAx   ((u32)0x0000FFFF << 12)           /*!< R/W 0FFFF000h  It's the top address of region x which can be set as non-secure. [27:12]: top address of region x*/
#define RXI300_IDAU2_LAx(x)     (((u32)((x) & 0x0000FFFF) << 12))
#define RXI300_GET_IDAU2_LAx(x) ((u32)(((x >> 12) & 0x0000FFFF)))
/** @} */

/** @defgroup IDAU2_CTRL
  * @brief Enable control register in IDAU
  * @{
  */
#define RXI300_MASK_WRITE_CTRL    ((u32)0x0000003F << 16)           /*!< R/W 0h  Region entry enable After setting WRITE_CTRL bits as 1, corresponding regions is set as write-forbidden.Note that if WRITE_CTRL bits are not enabled, the region remains secure even if ba*i/la*i is set. [16]: enable entry for ba0/la0 0: disable  1: enable                                                                                                                                                                                                                                                     [17]: enable entry for ba1/la1 0: disable  1: enable                                                                                                                                                                                                                                              [18]: enable entry for ba2/la2 0: disable  1: enable [19]: enable entry for ba3/la3 0: disable  1: enable                                                                                                                                                                                                                                                 [20]: enable entry for ba4/la4 0: disable  1: enable                                                                                                                                                                                                                                               [21]: enable entry for ba5/la5 0: disable  1: enable*/
#define RXI300_WRITE_CTRL(x)      (((u32)((x) & 0x0000003F) << 16))
#define RXI300_GET_WRITE_CTRL(x)  ((u32)(((x >> 16) & 0x0000003F)))
#define RXI300_MASK_SECURE_CTRL   ((u32)0x0000003F << 0)            /*!< R/W 0h  Region entry enable After setting SECURE_CTRL bits as 1, corresponding regions is set as non-secure.Note that if SECURE_CTRL bits are not enabled, the region remains secure even if ba*i/la*i is set. [0]: enable entry for ba0/la0 0: disable  1: enable                                                                                                                                                                                                                                                 [1]: enable entry for ba1/la1 0: disable  1: enable                                                                                                                                                                                                                                                  [2]: enable entry for ba2/la2 0: disable  1: enable [3]: enable entry for ba3/la3 0: disable  1: enable                                                                                                                                                                                                                                                 [4]: enable entry for ba4/la4 0: disable  1: enable                                                                                                                                                                                                                                                  [5]: enable entry for ba5/la5 0: disable  1: enable*/
#define RXI300_SECURE_CTRL(x)     (((u32)((x) & 0x0000003F) << 0))
#define RXI300_GET_SECURE_CTRL(x) ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup IDAU2_LOCK
  * @brief Lock control register in IDAU
  * @{
  */
#define RXI300_BIT_IDAU_LOCK ((u32)0x00000001 << 0) /*!< R/W 0h  Lock write transfer for all registers in IDAU (including lock register itself) until system reset if it is ebabled. [0]: lock bit for all register in IDAU                                                                                                                                                                                                              0: disable lock  1: enable lock  [31:1] reserved*/
/** @} */

/** @defgroup ARB_R_CTRL0
  * @brief The read arbitration control0
  * @{
  */
#define RXI300_MASK_HPERI_TO_SPIC_ARB   ((u32)0x000000FF << 24)           /*!< R/W 55h  Read arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: WIFI/AES_SHA/OTPC/SIC 0x1: GDMA And the following shows bit field of each slots: [0]: slot 0 of arbiter [1]: slot 1 of arbiter [2]: slot 2 of arbiter [3]: slot 3 of arbiter [4]: slot 4 of arbiter [5]: slot 5 of arbiter [6]: slot 6 of arbiter [7]: slot 7 of arbiter*/
#define RXI300_HPERI_TO_SPIC_ARB(x)     (((u32)((x) & 0x000000FF) << 24))
#define RXI300_GET_HPERI_TO_SPIC_ARB(x) ((u32)(((x >> 24) & 0x000000FF)))
#define RXI300_MASK_CPU_TO_SRAM_ARB     ((u32)0x000000FF << 16)           /*!< R/W 55h  Read arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: KM4TZ 0x1: KM4NS And the following shows bit field of each slots: [0]: slot 0 of arbiter [1]: slot 1 of arbiter [2]: slot 2 of arbiter [3]: slot 3 of arbiter [4]: slot 4 of arbiter [5]: slot 5 of arbiter [6]: slot 6 of arbiter [7]: slot 7 of arbiter*/
#define RXI300_CPU_TO_SRAM_ARB(x)       (((u32)((x) & 0x000000FF) << 16))
#define RXI300_GET_CPU_TO_SRAM_ARB(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define RXI300_MASK_CPU_TO_PSRAM_ARB    ((u32)0x000000FF << 8)            /*!< R/W 55h  Read arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: KM4TZ 0x1: KM4NS And the following shows bit field of each slots: [0]: slot 0 of arbiter [1]: slot 1 of arbiter [2]: slot 2 of arbiter [3]: slot 3 of arbiter [4]: slot 4 of arbiter [5]: slot 5 of arbiter [6]: slot 6 of arbiter [7]: slot 7 of arbiter*/
#define RXI300_CPU_TO_PSRAM_ARB(x)      (((u32)((x) & 0x000000FF) << 8))
#define RXI300_GET_CPU_TO_PSRAM_ARB(x)  ((u32)(((x >> 8) & 0x000000FF)))
#define RXI300_MASK_CPU_TO_SPIC_ARB     ((u32)0x000000FF << 0)            /*!< R/W 55h  Read arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: KM4TZ 0x1: KM4NS And the following shows bit field of each slots: [0]: slot 0 of arbiter [1]: slot 1 of arbiter [2]: slot 2 of arbiter [3]: slot 3 of arbiter [4]: slot 4 of arbiter [5]: slot 5 of arbiter [6]: slot 6 of arbiter [7]: slot 7 of arbiter*/
#define RXI300_CPU_TO_SPIC_ARB(x)       (((u32)((x) & 0x000000FF) << 0))
#define RXI300_GET_CPU_TO_SPIC_ARB(x)   ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup ARB_R_CTRL1
  * @brief The read arbitration control1
  * @{
  */
#define RXI300_MASK_HPERI_TO_PSRAM_ARB   ((u32)0x3FFFFFFF << 0)           /*!< R/W 23444688h  Read arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: WIFI/AES_SHA/OTPC/SIC 0x1: USB 0x2: DVP 0x3: RMII 0x4: GDMA And the following shows bit field of each slots: [2:0]: slot 0 of arbiter [5:3]: slot 1 of arbiter [8:6]: slot 2 of arbiter [11:9]: slot 3 of arbiter [14:12]: slot 4 of arbiter [17:15]: slot 5 of arbiter [20:18]: slot 6 of arbiter [23:21]: slot 7 of arbiter  [26:24]: slot 8 of arbiter [29:27]: slot 9 of arbiter*/
#define RXI300_HPERI_TO_PSRAM_ARB(x)     (((u32)((x) & 0x3FFFFFFF) << 0))
#define RXI300_GET_HPERI_TO_PSRAM_ARB(x) ((u32)(((x >> 0) & 0x3FFFFFFF)))
/** @} */

/** @defgroup ARB_R_CTRL2
  * @brief The read arbitration control2
  * @{
  */
#define RXI300_MASK_HPERI_TO_SRAM_ARB   ((u32)0x3FFFFFFF << 0)           /*!< R/W 23444688h  Read arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: WIFI/AES_SHA/OTPC/SIC 0x1: USB 0x2: DVP 0x3: RMII 0x4: GDMA And the following shows bit field of each slots: [2:0]: slot 0 of arbiter [5:3]: slot 1 of arbiter [8:6]: slot 2 of arbiter [11:9]: slot 3 of arbiter [14:12]: slot 4 of arbiter [17:15]: slot 5 of arbiter [20:18]: slot 6 of arbiter [23:21]: slot 7 of arbiter  [26:24]: slot 8 of arbiter [29:27]: slot 9 of arbiter*/
#define RXI300_HPERI_TO_SRAM_ARB(x)     (((u32)((x) & 0x3FFFFFFF) << 0))
#define RXI300_GET_HPERI_TO_SRAM_ARB(x) ((u32)(((x >> 0) & 0x3FFFFFFF)))
/** @} */

/** @defgroup ARB_R_CTRL3
  * @brief The read arbitration control3
  * @{
  */
#define RXI300_MASK_SHPERI_TO_SRAM_ARB   ((u32)0x0000FFFF << 16)           /*!< R/W 4924h  Read arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: MJPEG 0x1: LCDC                                                                                                                                                                                                  0x2: PPE And the following shows bit field of each slots: [1:0]: slot 0 of arbiter [3:2]: slot 1 of arbiter [5:4]: slot 2 of arbiter [7:6]: slot 3 of arbiter [9:8]: slot 4 of arbiter [11:10]: slot 5 of arbiter [13:12]: slot 6 of arbiter [15:14]: slot 7 of arbiter*/
#define RXI300_SHPERI_TO_SRAM_ARB(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define RXI300_GET_SHPERI_TO_SRAM_ARB(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define RXI300_MASK_SPIC_FINAL_ARB       ((u32)0x0000FFFF << 0)            /*!< R/W 4924h  Read arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: CPU_TO_SPIC_ARB group 0x1: HPERI_TO_SPIC_ARB group                                                                                                                                                       0x2: SHPERI_TO_SPIC_ARB group And the following shows bit field of each slots: [1:0]: slot 0 of arbiter [3:2]: slot 1 of arbiter [5:4]: slot 2 of arbiter [7:6]: slot 3 of arbiter [9:8]: slot 4 of arbiter [11:10]: slot 5 of arbiter [13:12]: slot 6 of arbiter [15:14]: slot 7 of arbiter*/
#define RXI300_SPIC_FINAL_ARB(x)         (((u32)((x) & 0x0000FFFF) << 0))
#define RXI300_GET_SPIC_FINAL_ARB(x)     ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup ARB_R_CTRL4
  * @brief The read arbitration control4
  * @{
  */
#define RXI300_MASK_SRAM_SUB_ARB         ((u32)0x0000FFFF << 16)           /*!< R/W 4924h  Read arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: CPU_TO_SRAM_ARB group 0x1: HPERI_TO_SRAM_ARB group                                                                                                                                                       0x2: SHPERI_TO_SRAM_ARB group And the following shows bit field of each slots: [1:0]: slot 0 of arbiter [3:2]: slot 1 of arbiter [5:4]: slot 2 of arbiter [7:6]: slot 3 of arbiter [9:8]: slot 4 of arbiter [11:10]: slot 5 of arbiter [13:12]: slot 6 of arbiter [15:14]: slot 7 of arbiter*/
#define RXI300_SRAM_SUB_ARB(x)           (((u32)((x) & 0x0000FFFF) << 16))
#define RXI300_GET_SRAM_SUB_ARB(x)       ((u32)(((x >> 16) & 0x0000FFFF)))
#define RXI300_MASK_SRAM_FINAL_ARB       ((u32)0x000000FF << 8)            /*!< R/W 55h  Read arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: WIFI 0x1: SRAM_SUB_ARB group And the following shows bit field of each slots: [0]: slot 0 of arbiter [1]: slot 1 of arbiter [2]: slot 2 of arbiter [3]: slot 3 of arbiter [4]: slot 4 of arbiter [5]: slot 5 of arbiter [6]: slot 6 of arbiter [7]: slot 7 of arbiter*/
#define RXI300_SRAM_FINAL_ARB(x)         (((u32)((x) & 0x000000FF) << 8))
#define RXI300_GET_SRAM_FINAL_ARB(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define RXI300_MASK_SHPERI_TO_SPIC_ARB   ((u32)0x000000FF << 0)            /*!< R/W 55h  Read arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: MJPEG 0x1: PPE And the following shows bit field of each slots: [0]: slot 0 of arbiter [1]: slot 1 of arbiter [2]: slot 2 of arbiter [3]: slot 3 of arbiter [4]: slot 4 of arbiter [5]: slot 5 of arbiter [6]: slot 6 of arbiter [7]: slot 7 of arbiter*/
#define RXI300_SHPERI_TO_SPIC_ARB(x)     (((u32)((x) & 0x000000FF) << 0))
#define RXI300_GET_SHPERI_TO_SPIC_ARB(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup ARB_R_CTRL5
  * @brief The read arbitration control5
  * @{
  */
#define RXI300_MASK_PSRAM_FINAL_ARB   ((u32)0x3FFFFFFF << 0)           /*!< R/W 23444688h  Read arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: CPU_TO_PSRAM_ARB group 0x1: HPERI_TO_PSRAM_ARB group 0x2: MJPEG 0x3: LCDC 0x4: PPE                                                                                                                                                                                                       And the following shows bit field of each slots: [2:0]: slot 0 of arbiter [5:3]: slot 1 of arbiter [8:6]: slot 2 of arbiter [11:9]: slot 3 of arbiter [14:12]: slot 4 of arbiter [17:15]: slot 5 of arbiter [20:18]: slot 6 of arbiter [23:21]: slot 7 of arbiter  [26:24]: slot 8 of arbiter [29:27]: slot 9 of arbiter*/
#define RXI300_PSRAM_FINAL_ARB(x)     (((u32)((x) & 0x3FFFFFFF) << 0))
#define RXI300_GET_PSRAM_FINAL_ARB(x) ((u32)(((x >> 0) & 0x3FFFFFFF)))
/** @} */

/** @defgroup ARB_W_CTRL0
  * @brief The write arbitration control0
  * @{
  */
#define RXI300_MASK_HPERI_TO_SPIC_ARB   ((u32)0x000000FF << 24)           /*!< R/W 55h  Write arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: WIFI/AES_SHA/OTPC/SIC 0x1:GDMA And the following shows bit field of each slots: [0]: slot 0 of arbiter [1]: slot 1 of arbiter [2]: slot 2 of arbiter [3]: slot 3 of arbiter [4]: slot 4 of arbiter [5]: slot 5 of arbiter [6]: slot 6 of arbiter [7]: slot 7 of arbiter*/
#define RXI300_HPERI_TO_SPIC_ARB(x)     (((u32)((x) & 0x000000FF) << 24))
#define RXI300_GET_HPERI_TO_SPIC_ARB(x) ((u32)(((x >> 24) & 0x000000FF)))
#define RXI300_MASK_CPU_TO_SRAM_ARB     ((u32)0x000000FF << 16)           /*!< R/W 55h  Write arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: KM4TZ 0x1: KM4NS And the following shows bit field of each slots: [0]: slot 0 of arbiter [1]: slot 1 of arbiter [2]: slot 2 of arbiter [3]: slot 3 of arbiter [4]: slot 4 of arbiter [5]: slot 5 of arbiter [6]: slot 6 of arbiter [7]: slot 7 of arbiter*/
#define RXI300_CPU_TO_SRAM_ARB(x)       (((u32)((x) & 0x000000FF) << 16))
#define RXI300_GET_CPU_TO_SRAM_ARB(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define RXI300_MASK_CPU_TO_PSRAM_ARB    ((u32)0x000000FF << 8)            /*!< R/W 55h  Write arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: KM4TZ 0x1: KM4NS And the following shows bit field of each slots: [0]: slot 0 of arbiter [1]: slot 1 of arbiter [2]: slot 2 of arbiter [3]: slot 3 of arbiter [4]: slot 4 of arbiter [5]: slot 5 of arbiter [6]: slot 6 of arbiter [7]: slot 7 of arbiter*/
#define RXI300_CPU_TO_PSRAM_ARB(x)      (((u32)((x) & 0x000000FF) << 8))
#define RXI300_GET_CPU_TO_PSRAM_ARB(x)  ((u32)(((x >> 8) & 0x000000FF)))
#define RXI300_MASK_CPU_TO_SPIC_ARB     ((u32)0x000000FF << 0)            /*!< R/W 55h  Write arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: KM4TZ 0x1: KM4NS And the following shows bit field of each slots: [0]: slot 0 of arbiter [1]: slot 1 of arbiter [2]: slot 2 of arbiter [3]: slot 3 of arbiter [4]: slot 4 of arbiter [5]: slot 5 of arbiter [6]: slot 6 of arbiter [7]: slot 7 of arbiter*/
#define RXI300_CPU_TO_SPIC_ARB(x)       (((u32)((x) & 0x000000FF) << 0))
#define RXI300_GET_CPU_TO_SPIC_ARB(x)   ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup ARB_W_CTRL1
  * @brief The write arbitration control1
  * @{
  */
#define RXI300_MASK_HPERI_TO_PSRAM_ARB   ((u32)0x3FFFFFFF << 0)           /*!< R/W 23444688h  Write arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: WIFI/AES_SHA/OTPC/SIC 0x1: USB 0x2: DVP 0x3: RMII 0x4: GDMA And the following shows bit field of each slots: [2:0]: slot 0 of arbiter [5:3]: slot 1 of arbiter [8:6]: slot 2 of arbiter [11:9]: slot 3 of arbiter [14:12]: slot 4 of arbiter [17:15]: slot 5 of arbiter [20:18]: slot 6 of arbiter [23:21]: slot 7 of arbiter  [26:24]: slot 8 of arbiter [29:27]: slot 9 of arbiter*/
#define RXI300_HPERI_TO_PSRAM_ARB(x)     (((u32)((x) & 0x3FFFFFFF) << 0))
#define RXI300_GET_HPERI_TO_PSRAM_ARB(x) ((u32)(((x >> 0) & 0x3FFFFFFF)))
/** @} */

/** @defgroup ARB_W_CTRL2
  * @brief The write arbitration control2
  * @{
  */
#define RXI300_MASK_HPERI_TO_SRAM_ARB   ((u32)0x3FFFFFFF << 0)           /*!< R/W 23444688h  Write arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: WIFI/AES_SHA/OTPC/SIC 0x1: USB 0x2: DVP 0x3: RMII 0x4: GDMA And the following shows bit field of each slots: [2:0]: slot 0 of arbiter [5:3]: slot 1 of arbiter [8:6]: slot 2 of arbiter [11:9]: slot 3 of arbiter [14:12]: slot 4 of arbiter [17:15]: slot 5 of arbiter [20:18]: slot 6 of arbiter [23:21]: slot 7 of arbiter  [26:24]: slot 8 of arbiter [29:27]: slot 9 of arbiter*/
#define RXI300_HPERI_TO_SRAM_ARB(x)     (((u32)((x) & 0x3FFFFFFF) << 0))
#define RXI300_GET_HPERI_TO_SRAM_ARB(x) ((u32)(((x >> 0) & 0x3FFFFFFF)))
/** @} */

/** @defgroup ARB_W_CTRL3
  * @brief The write arbitration control3
  * @{
  */
#define RXI300_MASK_SHPERI_TO_SRAM_ARB   ((u32)0x0000FFFF << 16)           /*!< R/W 4924h  Write arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: MJPEG 0x1: LCDC                                                                                                                                                                                                  0x2: PPE And the following shows bit field of each slots: [1:0]: slot 0 of arbiter [3:2]: slot 1 of arbiter [5:4]: slot 2 of arbiter [7:6]: slot 3 of arbiter [9:8]: slot 4 of arbiter [11:10]: slot 5 of arbiter [13:12]: slot 6 of arbiter [15:14]: slot 7 of arbiter*/
#define RXI300_SHPERI_TO_SRAM_ARB(x)     (((u32)((x) & 0x0000FFFF) << 16))
#define RXI300_GET_SHPERI_TO_SRAM_ARB(x) ((u32)(((x >> 16) & 0x0000FFFF)))
#define RXI300_MASK_SPIC_FINAL_ARB       ((u32)0x0000FFFF << 0)            /*!< R/W 4924h  Write arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: CPU_TO_SPIC_ARB group 0x1: HPERI_TO_SPIC_ARB group                                                                                                                                                       0x2: SHPERI_TO_SPIC_ARB group And the following shows bit field of each slots: [1:0]: slot 0 of arbiter [3:2]: slot 1 of arbiter [5:4]: slot 2 of arbiter [7:6]: slot 3 of arbiter [9:8]: slot 4 of arbiter [11:10]: slot 5 of arbiter [13:12]: slot 6 of arbiter [15:14]: slot 7 of arbiter*/
#define RXI300_SPIC_FINAL_ARB(x)         (((u32)((x) & 0x0000FFFF) << 0))
#define RXI300_GET_SPIC_FINAL_ARB(x)     ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup ARB_W_CTRL4
  * @brief The write arbitration control4
  * @{
  */
#define RXI300_MASK_SRAM_SUB_ARB         ((u32)0x0000FFFF << 16)           /*!< R/W 4924h  Write arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: CPU_TO_SRAM_ARB group 0x1: HPERI_TO_SRAM_ARB group                                                                                                                                                       0x2: SHPERI_TO_SRAM_ARB group And the following shows bit field of each slots: [1:0]: slot 0 of arbiter [3:2]: slot 1 of arbiter [5:4]: slot 2 of arbiter [7:6]: slot 3 of arbiter [9:8]: slot 4 of arbiter [11:10]: slot 5 of arbiter [13:12]: slot 6 of arbiter [15:14]: slot 7 of arbiter*/
#define RXI300_SRAM_SUB_ARB(x)           (((u32)((x) & 0x0000FFFF) << 16))
#define RXI300_GET_SRAM_SUB_ARB(x)       ((u32)(((x >> 16) & 0x0000FFFF)))
#define RXI300_MASK_SRAM_FINAL_ARB       ((u32)0x000000FF << 8)            /*!< R/W 55h  Write arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: WIFI 0x1: SRAM_SUB_ARB group And the following shows bit field of each slots: [0]: slot 0 of arbiter [1]: slot 1 of arbiter [2]: slot 2 of arbiter [3]: slot 3 of arbiter [4]: slot 4 of arbiter [5]: slot 5 of arbiter [6]: slot 6 of arbiter [7]: slot 7 of arbiter*/
#define RXI300_SRAM_FINAL_ARB(x)         (((u32)((x) & 0x000000FF) << 8))
#define RXI300_GET_SRAM_FINAL_ARB(x)     ((u32)(((x >> 8) & 0x000000FF)))
#define RXI300_MASK_SHPERI_TO_SPIC_ARB   ((u32)0x000000FF << 0)            /*!< R/W 55h  Write arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: MJPEG 0x1: PPE And the following shows bit field of each slots: [0]: slot 0 of arbiter [1]: slot 1 of arbiter [2]: slot 2 of arbiter [3]: slot 3 of arbiter [4]: slot 4 of arbiter [5]: slot 5 of arbiter [6]: slot 6 of arbiter [7]: slot 7 of arbiter*/
#define RXI300_SHPERI_TO_SPIC_ARB(x)     (((u32)((x) & 0x000000FF) << 0))
#define RXI300_GET_SHPERI_TO_SPIC_ARB(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup ARB_W_CTRL5
  * @brief The write arbitration control5
  * @{
  */
#define RXI300_MASK_PSRAM_FINAL_ARB   ((u32)0x3FFFFFFF << 0)           /*!< R/W 23444688h  write  arbitration control register. Each slot should be set by a port number. The port number represents a master group.The master group is shown as following: 0x0: CPU_TO_PSRAM_ARB group 0x1: HPERI_TO_PSRAM_ARB group 0x2: MJPEG 0x3: LCDC 0x4: PPE                                                                                                                                                                                                       And the following shows bit field of each slots: [2:0]: slot 0 of arbiter [5:3]: slot 1 of arbiter [8:6]: slot 2 of arbiter [11:9]: slot 3 of arbiter [14:12]: slot 4 of arbiter [17:15]: slot 5 of arbiter [20:18]: slot 6 of arbiter [23:21]: slot 7 of arbiter  [26:24]: slot 8 of arbiter [29:27]: slot 9 of arbiter*/
#define RXI300_PSRAM_FINAL_ARB(x)     (((u32)((x) & 0x3FFFFFFF) << 0))
#define RXI300_GET_PSRAM_FINAL_ARB(x) ((u32)(((x >> 0) & 0x3FFFFFFF)))
/** @} */

/** @defgroup SRAMC_CONFIG
  * @brief
  * @{
  */
#define RXI300_BIT_ERR_RESP_DISABLE ((u32)0x00000001 << 31)          /*!< R/W 0h  0x0: enable error response of SRAMC 0x1: disable error response of SRAMC*/
#define RXI300_MASK_RD_WEIGHT       ((u32)0x000001FF << 0)           /*!< R/W 2h  RD weight of SRAMC*/
#define RXI300_RD_WEIGHT(x)         (((u32)((x) & 0x000001FF) << 0))
#define RXI300_GET_RD_WEIGHT(x)     ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup ELR_PLD0
  * @brief Error log payload register0
  * @{
  */
#define RXI300_MASK_ELR_BSTINDEX   ((u32)0x000000FF << 24)           /*!< R 0h  Burst index of the error request.*/
#define RXI300_ELR_BSTINDEX(x)     (((u32)((x) & 0x000000FF) << 24))
#define RXI300_GET_ELR_BSTINDEX(x) ((u32)(((x >> 24) & 0x000000FF)))
#define RXI300_MASK_ELR_BSTLEN     ((u32)0x000000FF << 16)           /*!< R 0h  Burst Length of the error request.*/
#define RXI300_ELR_BSTLEN(x)       (((u32)((x) & 0x000000FF) << 16))
#define RXI300_GET_ELR_BSTLEN(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define RXI300_MASK_ELR_BSTTYPE    ((u32)0x00000007 << 11)           /*!< R 0h  BurstSeq of the error request.*/
#define RXI300_ELR_BSTTYPE(x)      (((u32)((x) & 0x00000007) << 11))
#define RXI300_GET_ELR_BSTTYPE(x)  ((u32)(((x >> 11) & 0x00000007)))
#define RXI300_MASK_ELR_CMD        ((u32)0x00000007 << 8)            /*!< R 0h  CMD of the error request. 0x1: Write command 0x2: Read command*/
#define RXI300_ELR_CMD(x)          (((u32)((x) & 0x00000007) << 8))
#define RXI300_GET_ELR_CMD(x)      ((u32)(((x >> 8) & 0x00000007)))
#define RXI300_MASK_ELR_SRC        ((u32)0x000000FF << 0)            /*!< R 0h  Error source of the error request. 0x00: Address hole default slave of M0,M8 group                                                                                                                                                   0x01: Address hole default slave of M1, M3, M5,  M7, M9-M11 group 0x02: Address hole default slave of M2, M4, M6                                                                                                                          0x03: Address hole default slave of P3S0 group                                                                                                                            0x40: master timeout of KM4NS                                                                                                                                                          0x41: master timeout of PLFM1_MST(M9-M11)                                                                                                                                             0x42: master timeout of WIFI                                                                                                                                                           0x43: slave timeout of KM4TZ to PLFM1                                                                                                                                        0x50: slave timeout of SRAMC*/
#define RXI300_ELR_SRC(x)          (((u32)((x) & 0x000000FF) << 0))
#define RXI300_GET_ELR_SRC(x)      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup ELR_PLD1
  * @brief Error log payload register1
  * @{
  */
#define RXI300_MASK_ELR_LOCK    ((u32)0x00000003 << 30)           /*!< R 0h  AxLock of the error request.*/
#define RXI300_ELR_LOCK(x)      (((u32)((x) & 0x00000003) << 30))
#define RXI300_GET_ELR_LOCK(x)  ((u32)(((x >> 30) & 0x00000003)))
#define RXI300_MASK_ELR_CACHE   ((u32)0x0000000F << 26)           /*!< R 0h  AxCache of the error request.*/
#define RXI300_ELR_CACHE(x)     (((u32)((x) & 0x0000000F) << 26))
#define RXI300_GET_ELR_CACHE(x) ((u32)(((x >> 26) & 0x0000000F)))
#define RXI300_MASK_ELR_PROT    ((u32)0x00000007 << 23)           /*!< R 0h  AxProt of the error request.*/
#define RXI300_ELR_PROT(x)      (((u32)((x) & 0x00000007) << 23))
#define RXI300_GET_ELR_PROT(x)  ((u32)(((x >> 23) & 0x00000007)))
#define RXI300_MASK_ELR_SIZE    ((u32)0x00000007 << 16)           /*!< R 0h  Size of the error request.*/
#define RXI300_ELR_SIZE(x)      (((u32)((x) & 0x00000007) << 16))
#define RXI300_GET_ELR_SIZE(x)  ((u32)(((x >> 16) & 0x00000007)))
/** @} */

/** @defgroup ELR_ID
  * @brief Error log ID information register
  * @{
  */
#define RXI300_MASK_ELR_ID   ((u32)0xFFFFFFFF << 0)           /*!< R 0h  Tagid of the error request. 8'b00000???: M0 access error 8'b000100??: M1 access error 8'b0100????: M2 access error 8'b000101??: M3 access error 8'b0101000?: M4 access error 8'b0001100?: M5 access error 8'b01100???: M6 access error     8'b001?????: M7 access error 8'b1101????: M8 access error 8'b11100???: M9 access error 8'b1111000?: M10 access error 8'b101?????: M11 access error*/
#define RXI300_ELR_ID(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define RXI300_GET_ELR_ID(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup ELR_ADR0
  * @brief Error log addrress register0
  * @{
  */
#define RXI300_MASK_ELR_ADR0   ((u32)0xFFFFFFFF << 0)           /*!< R 0h  Address[31:0] of the error request.*/
#define RXI300_ELR_ADR0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define RXI300_GET_ELR_ADR0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup ELR_ADR1
  * @brief Error log addrress register1
  * @{
  */
#define RXI300_MASK_ELR_ADR1   ((u32)0xFFFFFFFF << 32)           /*!< R 0h  Address[63:32] of the error request.*/
#define RXI300_ELR_ADR1(x)     (((u32)((x) & 0xFFFFFFFF) << 32))
#define RXI300_GET_ELR_ADR1(x) ((u32)(((x >> 32) & 0xFFFFFFFF)))
/** @} */

/** @defgroup ELR_CODE
  * @brief Error code register
  * @{
  */
#define RXI300_MASK_ELR_CODE   ((u32)0x000000FF << 0)           /*!< R 0h  The error code of error request, if it's 0, indicates that there is no error request.  8'h00: No error 8'h01: Address hole error    8'h2C: AXI master agent wdata timeout 8'h2D: AXI master agent write response timeout      8'h2E: AXI master agent write response timeout    8'h30: AXI SRAM controller grant timeout      8'h38: AXI slave agent arready timeout  8'h39: AXI slave agent rvalid timeout     8'h3A: AXI slave agent arready timeout  8'h3B: AXI slave agent wready timeout  8'h3C: AXI slave agent bvalid timeout*/
#define RXI300_ELR_CODE(x)     (((u32)((x) & 0x000000FF) << 0))
#define RXI300_GET_ELR_CODE(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup ELR_INTR_CLR
  * @brief Error log clear register
  * @{
  */
#define RXI300_BIT_ELR_INTR_CLR ((u32)0x00000001 << 0) /*!< W 0h  Error log interrupt clear. Writing 1'b1 to the register will trigger a 1-cycle pulse interrupt clear. It has to write 1'b1 to this register every time when the error exception occurs. Note that this register is write-only, the return value of reading this register is meaningless.*/
/** @} */

/** @defgroup TIMEOUT_GUARD_EN
  * @brief Timeout guardian enable register
  * @{
  */
#define RXI300_BIT_GUARDIAN_MODE_EN_PLFM1_SLV ((u32)0x00000001 << 4) /*!< R/W 0h  The enable of platform1 slave timeout monitor                                                                                                                                   0x0: Disable timeout check  0x1: Enable timeoute check*/
#define RXI300_BIT_GUARDIAN_MODE_EN_WIFI      ((u32)0x00000001 << 3) /*!< R/W 0h  The enable of WIFI timeout monitor                                                                                                                                   0x0: Disable timeout check  0x1: Enable timeoute check*/
#define RXI300_BIT_GUARDIAN_MODE_EN_PLFM1_MST ((u32)0x00000001 << 2) /*!< R/W 0h  The enable of SIC/OTPC/ARS_SHA/GDMA timeout monitor                                                                                                                                   0x0: Disable timeout check  0x1: Enable timeoute check*/
#define RXI300_BIT_GUARDIAN_MODE_EN_KM4NS     ((u32)0x00000001 << 1) /*!< R/W 0h  The enable of KM4NS timeout monitor                                                                                                                                   0x0: Disable timeout check  0x0: Enable timeoute check*/
#define RXI300_BIT_GUARDIAN_MODE_EN_SRAMC     ((u32)0x00000001 << 0) /*!< R/W 0h  The enable of SRAMC timeout monitor                                                                                                                                   0x0: Disable timeout check  0x1: Enable timeoute check*/
/** @} */

/** @defgroup TIMEOUT_CLEAN_N
  * @brief Timeout clear register
  * @{
  */
#define RXI300_BIT_TMO_CLEAR_N_PLFM1_SLV ((u32)0x00000001 << 4) /*!< R/W0 1h  The register can only written to 0 when a platform1 time out occures, and automatically clear this register by hardware*/
#define RXI300_BIT_TMO_CLEAR_N_WIFI      ((u32)0x00000001 << 3) /*!< R/W0 1h  The register can only written to 0 when a WIFI time out occures, and automatically clear this register by hardware*/
#define RXI300_BIT_TMO_CLEAR_N_PLFM1_MST ((u32)0x00000001 << 2) /*!< R/W0 1h  The register can only written to 0 when a SIC/OTPC/ARS_SHA/GDMA time out occures, and automatically clear this register by hardware*/
#define RXI300_BIT_TMO_CLEAR_N_KM4NS     ((u32)0x00000001 << 1) /*!< R/W0 1h  The register can only written to 0 when a KM4NS time out occures, and automatically clear this register by hardware*/
#define RXI300_BIT_TMO_CLEAR_N_SRAMC     ((u32)0x00000001 << 0) /*!< R/W0 1h  The register can only written to 0 when a SRAMC time out occures, and automatically clear this register by hardware*/
/** @} */

/** @defgroup TIMEOUT_MON_CFG0
  * @brief Timeout monitor configuration register0
  * @{
  */
#define RXI300_MASK_GRADE       ((u32)0x0000000F << 16)           /*!< R/W Fh  Timeout grade                                                                                                                                                                                                                                      Timeout total cycle = [256*(2^(grade-1) +1)*threshold] - inaccurate                                                                                                       Note1: the range of inaccurate = 0 ~ [256*(2^(grade-1) +1)-2]                                                                                              Note2: If threshold is 0x0, the Timeout_total_cycle is always 1*/
#define RXI300_GRADE(x)         (((u32)((x) & 0x0000000F) << 16))
#define RXI300_GET_GRADE(x)     ((u32)(((x >> 16) & 0x0000000F)))
#define RXI300_MASK_THRESHOLD   ((u32)0x000000FF << 0)            /*!< R/W FFh  Timeout threshold*/
#define RXI300_THRESHOLD(x)     (((u32)((x) & 0x000000FF) << 0))
#define RXI300_GET_THRESHOLD(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup TIMEOUT_MON_CFG1
  * @brief Timeout monitor configuration register0
  * @{
  */
#define RXI300_MASK_GRADE       ((u32)0x0000000F << 16)           /*!< R/W Fh  Timeout grade                                                                                                                                                                                                                                      Timeout total cycle = [256*(2^(grade-1) +1)*threshold] - inaccurate                                                                                                       Note1: the range of inaccurate = 0 ~ [256*(2^(grade-1) +1)-2]                                                                                              Note2: If threshold is 0x0, the Timeout_total_cycle is always 1*/
#define RXI300_GRADE(x)         (((u32)((x) & 0x0000000F) << 16))
#define RXI300_GET_GRADE(x)     ((u32)(((x >> 16) & 0x0000000F)))
#define RXI300_MASK_THRESHOLD   ((u32)0x000000FF << 0)            /*!< R/W FFh  Timeout threshold*/
#define RXI300_THRESHOLD(x)     (((u32)((x) & 0x000000FF) << 0))
#define RXI300_GET_THRESHOLD(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @} */
/* Exported Types --------------------------------------------------------*/

/** @defgroup RXI300_Exported_Types RXI300 Exported Types
  * @{
  */

/** @brief RXI300 Port
  */
typedef struct {
	__IO uint32_t PPC1_REG;  /*!< PPC1 CONFIGURE REGISTER */
	__IO uint32_t PPC2_REG;  /*!< PPC2 CONFIGURE REGISTER */
	__IO uint32_t PPC3_REG;  /*!< PPC3 CONFIGURE REGISTER */
	__IO uint32_t PPC_LOCK;  /*!< PPC LOCK REGISTER */
} PPC_TypeDef;

/** @brief RXI300 Port
  */
typedef struct {
	__IO uint32_t IDAU_BAx;  /*!< BASE ADDRESS REGISTERx IN IDAU Register */
	__IO uint32_t IDAU_LAx;  /*!< TOP ADDRESS REGISTERx   IN IDAU Register */
} MPC_EntryTypeDef;

/** @brief RXI300 Register Declaration
  */

typedef struct {
	PPC_TypeDef PPC                             ;  /*!< RXI300 IP have 1 ports,  Address offset:0x000-0x00C */
	__IO uint32_t DISCONNECT_PLFM1              ;  /*!< DISCONNECT PLATFORM REGISTER1 Register,  Address offset:0x010 */
	__IO uint32_t RESET_CONTROL                 ;  /*!< RESET FLOW CONTROL REGISTER,  Address offset:0x014 */
	__IO uint32_t RSVD0[2]                      ;  /*!< Reserved,  Address offset:0x018-0x01F */
	__I  uint32_t RESET_STATUS                  ;  /*!< RESET FLOW STATUS REGISTER,  Address offset:0x020 */
	__IO uint32_t RSVD1[55]                     ;  /*!< Reserved,  Address offset:0x024-0x0FF */
	__I  uint32_t ELR_PLD0_S                    ;  /*!< ERROR LOG PAYLOAD REGISTER0 Register,  Address offset:0x100 */
	__I  uint32_t ELR_PLD1_S                    ;  /*!< ERROR LOG PAYLOAD REGISTER1 Register,  Address offset:0x104 */
	__I  uint32_t ELR_ID_S                      ;  /*!< ERROR LOG ID INFORMATION REGISTER,  Address offset:0x108 */
	__I  uint32_t ELR_ADR0_S                    ;  /*!< ERROR LOG ADDRRESS REGISTER0 Register,  Address offset:0x10C */
	__I  uint32_t ELR_ADR1_S                    ;  /*!< ERROR LOG ADDRRESS REGISTER1 Register,  Address offset:0x110 */
	__IO uint32_t RSVD2[7]                      ;  /*!< Reserved,  Address offset:0x114-0x12F */
	__I  uint32_t ELR_CODE_S                    ;  /*!< ERROR CODE REGISTER,  Address offset:0x130 */
	__IO uint32_t RSVD3[2]                      ;  /*!< Reserved,  Address offset:0x134-0x13B */
	__O  uint32_t ELR_INTR_CLR_S                ;  /*!< ERROR LOG CLEAR REGISTER,  Address offset:0x13C */
	__IO uint32_t RSVD4[48]                     ;  /*!< Reserved,  Address offset:0x140-0x1FF */
	__I  uint32_t NAME                          ;  /*!< RXI300 DESIGN NAME REGISTER,  Address offset:0x200 */
	__I  uint32_t VER                           ;  /*!< RXI300 DESIGN VERSION REGISTER,  Address offset:0x204 */
	__I  uint32_t RVE                           ;  /*!< RXI300 DESIGN REVERSION REGISTER,  Address offset:0x208 */
	__I  uint32_t INST                          ;  /*!< RXI300 DESIGN INSTANCE NUMBER REGISTER,  Address offset:0x20C */
	__I  uint32_t IMPL_Y                        ;  /*!< RXI300 IMPLEMENTATION YEAR REGISTER,  Address offset:0x210 */
	__I  uint32_t IMPL_D                        ;  /*!< RXI300 IMPLEMENTATION DATE REGISTER,  Address offset:0x214 */
	__I  uint32_t DEV                           ;  /*!< RXI300 DEVELOPER REGISTER,  Address offset:0x218 */
	__I  uint32_t PRO_NUM                       ;  /*!< RXI300 PROJECT NUMBER REGISTER,  Address offset:0x21C */
	__IO uint32_t RSVD5[120]                    ;  /*!< Reserved,  Address offset:0x220-0x3FF */
	MPC_EntryTypeDef MPC_Entry[6]               ;  /*!< RXI300 IP have 6 ports,  Address offset:0x400-0x42C */
	__IO uint32_t RSVD6[4]                      ;  /*!< Reserved,  Address offset:0x430-0x43F */
	__IO uint32_t IDAU_CTRL                     ;  /*!< ENABLE CONTROL REGISTER IN IDAU Register,  Address offset:0x440 */
	__IO uint32_t IDAU_LOCK                     ;  /*!< LOCK CONTROL REGISTER IN IDAU Register,  Address offset:0x444 */
	__IO uint32_t RSVD7[46]                     ;  /*!< Reserved,  Address offset:0x448-0x4FF */
	MPC_EntryTypeDef MPC1_Entry[6]              ;  /*!< RXI300 IP have 6 ports,  Address offset:0x500-0x52C */
	__IO uint32_t RSVD8[4]                      ;  /*!< Reserved,  Address offset:0x530-0x53F */
	__IO uint32_t IDAU1_CTRL                    ;  /*!< ENABLE CONTROL REGISTER IN IDAU Register,  Address offset:0x540 */
	__IO uint32_t IDAU1_LOCK                    ;  /*!< LOCK CONTROL REGISTER IN IDAU Register,  Address offset:0x544 */
	__IO uint32_t RSVD9[46]                     ;  /*!< Reserved,  Address offset:0x548-0x5FF */
	MPC_EntryTypeDef MPC2_Entry[6]              ;  /*!< RXI300 IP have 6 ports,  Address offset:0x600-0x62C */
	__IO uint32_t RSVD10[4]                     ;  /*!< Reserved,  Address offset:0x630-0x63F */
	__IO uint32_t IDAU2_CTRL                    ;  /*!< ENABLE CONTROL REGISTER IN IDAU Register,  Address offset:0x640 */
	__IO uint32_t IDAU2_LOCK                    ;  /*!< LOCK CONTROL REGISTER IN IDAU Register,  Address offset:0x644 */
	__IO uint32_t RSVD11[622]                   ;  /*!< Reserved,  Address offset:0x648-0xFFF */
	__IO uint32_t ARB_R_CTRL0                   ;  /*!< THE READ ARBITRATION CONTROL0 Register,  Address offset:0x1000 */
	__IO uint32_t ARB_R_CTRL1                   ;  /*!< THE READ ARBITRATION CONTROL1 Register,  Address offset:0x1004 */
	__IO uint32_t ARB_R_CTRL2                   ;  /*!< THE READ ARBITRATION CONTROL2 Register,  Address offset:0x1008 */
	__IO uint32_t ARB_R_CTRL3                   ;  /*!< THE READ ARBITRATION CONTROL3 Register,  Address offset:0x100C */
	__IO uint32_t ARB_R_CTRL4                   ;  /*!< THE READ ARBITRATION CONTROL4 Register,  Address offset:0x1010 */
	__IO uint32_t ARB_R_CTRL5                   ;  /*!< THE READ ARBITRATION CONTROL5 Register,  Address offset:0x1014 */
	__IO uint32_t RSVD12[10]                    ;  /*!< Reserved,  Address offset:0x1018-0x103F */
	__IO uint32_t ARB_W_CTRL0                   ;  /*!< THE WRITE ARBITRATION CONTROL0 Register,  Address offset:0x1040 */
	__IO uint32_t ARB_W_CTRL1                   ;  /*!< THE WRITE ARBITRATION CONTROL1 Register,  Address offset:0x1044 */
	__IO uint32_t ARB_W_CTRL2                   ;  /*!< THE WRITE ARBITRATION CONTROL2 Register,  Address offset:0x1048 */
	__IO uint32_t ARB_W_CTRL3                   ;  /*!< THE WRITE ARBITRATION CONTROL3 Register,  Address offset:0x104C */
	__IO uint32_t ARB_W_CTRL4                   ;  /*!< THE WRITE ARBITRATION CONTROL4 Register,  Address offset:0x1050 */
	__IO uint32_t ARB_W_CTRL5                   ;  /*!< THE WRITE ARBITRATION CONTROL5 Register,  Address offset:0x1054 */
	__IO uint32_t SRAMC_CONFIG                  ;  /*!< Register,  Address offset:0x1058 */
	__IO uint32_t RSVD13[41]                    ;  /*!< Reserved,  Address offset:0x105C-0x10FF */
	__I  uint32_t ELR_PLD0                      ;  /*!< ERROR LOG PAYLOAD REGISTER0 Register,  Address offset:0x1100 */
	__I  uint32_t ELR_PLD1                      ;  /*!< ERROR LOG PAYLOAD REGISTER1 Register,  Address offset:0x1104 */
	__I  uint32_t ELR_ID                        ;  /*!< ERROR LOG ID INFORMATION REGISTER,  Address offset:0x1108 */
	__I  uint32_t ELR_ADR0                      ;  /*!< ERROR LOG ADDRRESS REGISTER0 Register,  Address offset:0x110C */
	__I  uint32_t ELR_ADR1                      ;  /*!< ERROR LOG ADDRRESS REGISTER1 Register,  Address offset:0x1110 */
	__IO uint32_t RSVD14[7]                     ;  /*!< Reserved,  Address offset:0x1114-0x112F */
	__I  uint32_t ELR_CODE                      ;  /*!< ERROR CODE REGISTER,  Address offset:0x1130 */
	__IO uint32_t RSVD15[2]                     ;  /*!< Reserved,  Address offset:0x1134-0x113B */
	__O  uint32_t ELR_INTR_CLR                  ;  /*!< ERROR LOG CLEAR REGISTER,  Address offset:0x113C */
	__IO uint32_t RSVD16[112]                   ;  /*!< Reserved,  Address offset:0x1140-0x12FF */
	__IO uint32_t TIMEOUT_GUARD_EN              ;  /*!< TIMEOUT GUARDIAN ENABLE REGISTER,  Address offset:0x1300 */
	__IO uint32_t RSVD17[15]                    ;  /*!< Reserved,  Address offset:0x1304-0x133F */
	__IO uint32_t TIMEOUT_CLEAN_N               ;  /*!< TIMEOUT CLEAR REGISTER,  Address offset:0x1340 */
	__IO uint32_t RSVD18[15]                    ;  /*!< Reserved,  Address offset:0x1344-0x137F */
	__IO uint32_t TIMEOUT_MON_CFG0              ;  /*!< TIMEOUT MONITOR CONFIGURATION REGISTER0 Register,  Address offset:0x1380 */
	__IO uint32_t TIMEOUT_MON_CFG1              ;  /*!< TIMEOUT MONITOR CONFIGURATION REGISTER0 Register,  Address offset:0x1384 */
} RXI300_TypeDef;

/** @} */


// Do NOT modify any AUTO_GEN code above
/* AUTO_GEN_END */

/* MANUAL_GEN_START */

//Please add your defination here

/* MANUAL_GEN_END */

/** @} */

/** @} */

#endif