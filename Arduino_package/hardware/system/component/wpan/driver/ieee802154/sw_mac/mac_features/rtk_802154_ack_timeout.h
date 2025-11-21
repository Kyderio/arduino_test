/* Copyright (c) 2018, Realtek
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this
 *      list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *
 *   3. Neither the name of Realtek nor the names of its
 *      contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef RTK_802154_ACK_TIMEOUT_H__
#define RTK_802154_ACK_TIMEOUT_H__

#include <stdbool.h>
#include <stdint.h>

#include "rtk_802154_const.h"
#include "rtk_802154_types.h"
#include "mac_features/rtk_802154_frame_parser.h"

/**
 * @defgroup rtk_802154_csma_ca 802.15.4 driver ACK timeout support
 * @{
 * @ingroup rtk_802154
 * @brief ACK timeout feature.
 */

/**
 * @brief Sets the timeout time for the ACK timeout feature.
 *
 * @param[in]  time  Timeout time in microseconds.
 *                   The default value is defined in rtk_802154_config.h.
 */
void rtk_802154_ack_timeout_time_set(uint32_t time);

/**
 * @brief Aborts a started ACK timeout procedure.
 *
 * @param[in]  term_lvl  Termination level set by the request for aborting the ongoing operation.
 * @param[in]  req_orig  Module that originates the abort request.
 *
 * If the ACK timeout procedure is not running during the call, this function does nothing.
 *
 * @retval  true   ACK timeout procedure han been stopped.
 */
bool rtk_802154_ack_timeout_abort(rtk_802154_term_t term_lvl, req_originator_t req_orig);

/**
 * @brief Handles a transmitted event.
 *
 * @param[in]  p_parser_data  Pointer to the buffer that contains the transmitted frame.
 */
void rtk_802154_ack_timeout_transmitted_hook(const rtk_802154_frame_parser_data_t *p_parser_data);

/**
 * @brief Handles a TX failed event.
 *
 * @param[in]  p_frame  Pointer to the buffer that contains a frame that was not transmitted.
 * @param[in]  error    Cause of failed transmission.
 *
 * @retval  true   TX failed event is to be propagated to the MAC layer.
 * @retval  false  TX failed event is not to be propagated to the MAC layer. It is handled
 *                 internally in the ACK timeout module.
 */
bool rtk_802154_ack_timeout_tx_failed_hook(const uint8_t *p_frame, rtk_802154_tx_error_t error);

/**
 * @brief Handles a TX frame end event.
 *
 * @param[in]  p_frame  Pointer to the buffer that contains a frame being transmitted.
 *
 * @retval  true   TX frame end event is to be propagated to the MAC layer.
 * @retval  false  TX frame end event is not to be propagated to the MAC layer. It is handled
 *                 internally in the ACK timeout module.
 */
bool rtk_802154_ack_timeout_tx_frame_end_hook(const uint8_t *p_frame);

/**
 * @brief Handles a RX ACK started event.
 *
 */
void rtk_802154_ack_timeout_rx_ack_started_hook(void);

/**
 *@}
 **/

#endif // RTK_802154_CSMA_CA_H__
