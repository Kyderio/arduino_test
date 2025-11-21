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

#define WL_PROTOCOL_IRQ_PRIO	6
#define WL_DMA_IRQ_PRIO			6

#define PORT0_TXBCN_INT			(BIT_HS_TXBCN1_ERR_INT | BIT_HS_TXBCN1_OK_INT)
#define PORT1_TXBCN_INT			(BIT_HS_TXBCNERR9_INT | BIT_HS_TXBCNOK9_INT)

#define PORT1_BCN_EARLY_INT		BIT_HS_BCNERLY8_INT

#define BIT_RXFF_FULL_INT_EN            BIT_HS_RXFF_FULL_INT_EN
#define BIT_TIMEOUT0_INT_V1             BIT_HS_TIMEOUT0_INT_V1

#ifdef PHYSTS_WORK_AROUND
#define HIMR0_CFG		(u32)(BIT_HISR1_INT_EN | BIT_HISR2_INT_EN | BIT_HS_TXFF_FIFO_INT_EN | BIT_RXFF_FULL_INT_EN | BIT_HS_HCPWM_INT_EN | BIT_HS_TIMEOUT0_V1_INT_EN)
#else
#define HIMR0_CFG		(u32)(BIT_HISR1_INT_EN | BIT_HISR2_INT_EN | BIT_HS_TXFF_FIFO_INT_EN | BIT_RXFF_FULL_INT_EN | BIT_HS_HCPWM_INT_EN)
#endif

#define BIT_TWT_TIMER_A_INT       BIT_HS_PS_TIMER_A_INT_EN
#define BIT_TWT_TIMER_B_INT       BIT_HS_PS_TIMER_B_INT_EN
#define BIT_TWT_TIMER_C_INT       BIT_HS_PS_TIMER_C_INT_EN
#define BIT_TWT_TIMER_D_INT       BIT_HS_PS_TIMER_D_INT_EN
#define BIT_TWT_TIMER_E_INT       BIT_HS_PS_TIMER_E_INT_EN
#define BIT_TWT_TIMER_A_EARLY_INT BIT_HS_PS_TIMER_A_EARLY_INT_EN
#define BIT_TWT_TIMER_B_EARLY_INT BIT_HS_PS_TIMER_B_EARLY_INT_EN
#define BIT_TWT_TIMER_C_EARLY_INT BIT_HS_PS_TIMER_C_EARLY_INT_EN
#define BIT_TWT_TIMER_D_EARLY_INT BIT_HS_PS_TIMER_D_EARLY_INT_EN
#define BIT_TWT_TIMER_E_EARLY_INT BIT_HS_PS_TIMER_E_EARLY_INT_EN

#endif	/* _WIFI_HAL_INT_H_ */

