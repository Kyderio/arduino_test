/* mbed Microcontroller Library
 *******************************************************************************
 * Copyright (c) 2015, Realtek Semiconductor Corp.
 * All rights reserved.
 *
 * This module is a confidential and proprietary property of RealTek and
 * possession or use of this module requires written permission of RealTek.
 *******************************************************************************
 */

#ifndef ETHERNET_EX_API_H
#define ETHERNET_EX_API_H

#include "device.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup ethernet_ex ETHERNET_EX
 *  @ingroup    hal
 *  @brief      ethernet extended functions
 *  @{
 */
/// the size (unit: Bytes) of each Tx descriptor
#define ETH_TX_DESC_SIZE	20  // 20 Bytes
/// the size (unit: Bytes) of each Rx descriptor
#define ETH_RX_DESC_SIZE	16  // 16 Bytes
/// the size of the packet buffer
#define ETH_PKT_BUF_SIZE	1600

/**
  \brief  The function type of the Ethernet MAC controller interrupt callback function.
*/
typedef void (*ethernet_callback)(uint32_t event, uint32_t data);

/**
 *  @brief To hook a callback function for Ethernet MAC controller interrupt.
 *
 *  @param[in]  callback The callback function.
 *
 *  @returns    void
 */
void ethernet_irq_hook(ethernet_callback callback);

/**
 *  @brief To set the Tx/Rx descriptor number.
 *
 *  @param[in]  txdescCnt The specified Tx descriptor number.
 *  @param[in]  rxdescCnt The specified Rx descriptor number.
 *
 *  @returns    void.
 */
void ethernet_set_descnum(uint8_t txdescCnt, uint8_t rxdescCnt);

/**
 *  @brief To set the start address of Tx/Rx descriptor ring and Tx/Rx packet buffer.
 *
 *  @param[in]  TxDescAddr The start address of Tx descriptor ring.
 *  @param[in]  RxDescAddr The start address of Rx descriptor ring.
 *  @param[in]  pTxPktBuf The start address of Tx packet buffer.
 *  @param[in]  pRxPktBuf The start address of Rx packet buffer.
 *
 *  @returns    void.
 */
void ethernet_trx_pre_setting(uint8_t *TxDescAddr, uint8_t *RxDescAddr, uint8_t *pTxPktBuf, uint8_t *pRxPktBuf);

#ifdef __cplusplus
}
#endif

#endif  // #ifndef ETHERNET_EX_API_H

