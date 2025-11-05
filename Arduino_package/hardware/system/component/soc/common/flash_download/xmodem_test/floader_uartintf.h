/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _FLOADER_UARTINTF_H_
#define _FLOADER_UARTINTF_H_

/**
 * @brief Calculated by transmitting one frame (1034 bytes) of data at a baud rate of 115200,
 * the longest write frame is about 89ms. 1034 * 10bit /115200 = 89ms, When uart transfers 1byte,
 * we need to add start and stop bits, a total of 10 bits.
 *
 */
#define FRAME_TIMEOUT 150000

void loguart_ReadData(struct RecvStatus *prs, u32 size, uint32_t time_out);

u32 loguart_Irq(void *data);

void loguart_Init(struct RecvStatus *prs, u32 baud_rate);

#endif
