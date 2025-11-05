/******************************************************************************
 *
 * Copyright(c) 2015 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 ******************************************************************************/
#ifndef _WIFI_HAL_INT_H_
#define _WIFI_HAL_INT_H_

#define WL_PROTOCOL_IRQ_PRIO	INT_PRI_LOWEST
#define WL_DMA_IRQ_PRIO			INT_PRI_LOWEST

#define PORT0_TXBCN_INT			(BIT_TXBCN0_ERR_INT | BIT_TXBCN0_OK_INT)
#define PORT1_TXBCN_INT			(BIT_TX_BCN1ERR_INT | BIT_TX_BCN1OK_INT)

#define PORT1_BCN_EARLY_INT		BIT_BCNERLY8_INT

#define BIT_SETMGDOK_EN			BIT_AXI_MGDOK_ISR
#define BIT_SETHIGHDOK_EN		BIT_AXI_HIGHDOK_ISR
#define BIT_SETBKDOK_EN			BIT_AXI_BKDOK_ISR
#define BIT_SETBEDOK_EN			BIT_AXI_BEDOK_ISR
#define BIT_SETVIDOK_EN			BIT_AXI_VIDOK_ISR
#define BIT_SETVODOK_EN			BIT_AXI_VODOK_ISR

#define BIT_SETRXOK_EN					BIT_AXI_RXDMA_OK_IMR
#define BIT_SET_RDY_EN					BIT_AXI_RDU_IMR
#define BIT_RXFF_FULL_INT_EN 			BIT_RXFF_FULL_MSK
#define REG_AXI_INTERRUPT_MASK 			REG_DMA_IMR_V1
#define REG_AXI_INTERRUPT				REG_DMA_ISR_V1


#endif	/* _WIFI_HAL_INT_H_ */

