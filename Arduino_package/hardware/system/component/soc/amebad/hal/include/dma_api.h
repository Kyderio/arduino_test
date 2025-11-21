/** mbed Microcontroller Library
  ******************************************************************************
  * @file    dma_api.h
  * @author
  * @version V1.0.0
  * @brief   This file provides mbed GDMA API
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2015, Realtek Semiconductor Corp.
  * All rights reserved.
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  ******************************************************************************
  */
#ifndef MBED_GDMA_API_H
#define MBED_GDMA_API_H

#include "device.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup dma DMA
 *  @ingroup    hal
 *  @brief      dma functions
 *  @{
 */

///@name Ameba Common
///@{
typedef struct gdma_s gdma_t;

typedef u32(*dma_irq_handler)(void *);
/**
 *  @brief Initial the GDMA
 *  @param dma_obj: the GDMA object
 *  @param handler: the callback function for a DMA transfer complete.
 *  @param id: the argument of the callback function.
 *  @retval None
 *
 */
void dma_memcpy_init(gdma_t *dma_obj, dma_irq_handler handler, uint32_t id);

/**
 *  @brief De-Initial the GDMA
 *  @param dma_obj: the GDMA object
 *  @retval None
 *
 */
void dma_memcpy_deinit(gdma_t *dma_obj);

/**
 *  @brief To do a memory copy by DMA
 *  @param dma_obj: the GDMA object
 *  @param dst: destination memory address
 *  @param src: source memory address
 *  @param len: copy data length
 *  @retval None
 */
void dma_memcpy(gdma_t *dma_obj, void *dst, void *src, uint32_t len);

///@}

/**@}*/

#ifdef __cplusplus
}
#endif

#endif  // end of "#define MBED_GDMA_API_H"
