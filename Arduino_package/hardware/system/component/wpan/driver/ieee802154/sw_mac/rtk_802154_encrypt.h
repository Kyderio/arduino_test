/*
 * Copyright (c) 2021 - 2022, Realtek
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of Realtek nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef RTK_802154_ENCRYPT_H_
#define RTK_802154_ENCRYPT_H_

#include <stdbool.h>
#include <stdint.h>

#include "mac_features/rtk_802154_frame_parser.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Transmission setup hook for the encryption module.
 *
 * This hook prepares encryption data for provided frame.
 *
 * @param[in]  p_frame          Pointer to the buffer that contains the PHR and PSDU
 *                              of the transmitted frame.
 * @param[in]  p_params         Pointer to the transmission parameters.
 * @param[in]  notify_function  Function to be called to notify transmission failure.
 *
 * @retval  true         Encryption was prepared successfully.
 * @retval  false        Encryption prepare failed.
 */
bool rtk_802154_encrypt_ack_prepare(const rtk_802154_frame_parser_data_t *p_parser_data);
bool rtk_802154_encrypt_tx_setup(const rtk_802154_frame_parser_data_t *p_parser_data);
bool rtk_802154_encrypt_process_aesccm(const uint8_t *p_data, const bool need_backup);

#endif /* RTK_802154_ENCRYPT_H_ */
