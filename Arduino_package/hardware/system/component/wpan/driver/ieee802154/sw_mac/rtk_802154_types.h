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

#ifndef RTK_802154_TYPES_H__
#define RTK_802154_TYPES_H__

#include <stdint.h>

/**
 * @defgroup rtk_802154_types Type definitions used in the 802.15.4 driver
 * @{
 * @ingroup rtk_802154
 * @brief Definitions of types used in the 802.15.4 driver.
 */

/**
 * @brief States of the driver.
 */
typedef uint8_t rtk_802154_state_t;

#define RTK_802154_STATE_INVALID            0x01 // !< Radio in an invalid state.
#define RTK_802154_STATE_SLEEP              0x02 // !< Radio in the sleep state.
#define RTK_802154_STATE_RECEIVE            0x03 // !< Radio in the receive state.
#define RTK_802154_STATE_TRANSMIT           0x04 // !< Radio in the transmit state.
#define RTK_802154_STATE_ENERGY_DETECTION   0x05 // !< Radio in the energy detection state.
#define RTK_802154_STATE_CCA                0x06 // !< Radio in the CCA state.
#define RTK_802154_STATE_CONTINUOUS_CARRIER 0x07 // !< Radio in the continuous carrier state.

/**
 * @brief Errors reported during the frame transmission.
 */
typedef uint8_t rtk_802154_tx_error_t;

#define RTK_802154_TX_ERROR_NONE            0x00 // !< There is no transmit error.
#define RTK_802154_TX_ERROR_BUSY_CHANNEL    0x01 // !< CCA reported busy channel before the transmission.
#define RTK_802154_TX_ERROR_INVALID_ACK     0x02 // !< Received ACK frame is other than expected.
#define RTK_802154_TX_ERROR_NO_MEM          0x03 // !< No receive buffer is available to receive an ACK.
#define RTK_802154_TX_ERROR_TIMESLOT_ENDED  0x04 // !< Radio timeslot ended during the transmission procedure.
#define RTK_802154_TX_ERROR_NO_ACK          0x05 // !< ACK frame was not received during the timeout period.
#define RTK_802154_TX_ERROR_ABORTED         0x06 // !< Procedure was aborted by another operation.
#define RTK_802154_TX_ERROR_TIMESLOT_DENIED 0x07 // !< Transmission did not start due to a denied timeslot request.
#define RTK_802154_TX_ERROR_KEY_ID_INVALID      0x08 // !< Transmission did not start due to invalid key ID in frame's security header.
#define RTK_802154_TX_ERROR_FRAME_COUNTER_ERROR 0x09 // !< Transmission did not start due a frame counter error.

/**
 * @brief Possible errors during the frame reception.
 */
typedef uint8_t rtk_802154_rx_error_t;

#define RTK_802154_RX_ERROR_NONE                    0x00 // !< There is no receive error.
#define RTK_802154_RX_ERROR_INVALID_FRAME           0x01 // !< Received a malformed frame.
#define RTK_802154_RX_ERROR_INVALID_FCS             0x02 // !< Received a frame with an invalid checksum.
#define RTK_802154_RX_ERROR_INVALID_DEST_ADDR       0x03 // !< Received a frame with a mismatched destination address.
#define RTK_802154_RX_ERROR_RUNTIME                 0x04 // !< Runtime error occurred (for example, CPU was held for too long).
#define RTK_802154_RX_ERROR_TIMESLOT_ENDED          0x05 // !< Radio timeslot ended during the frame reception.
#define RTK_802154_RX_ERROR_ABORTED                 0x06 // !< Procedure was aborted by another operation.
#define RTK_802154_RX_ERROR_DELAYED_TIMESLOT_DENIED 0x07 // !< Delayed reception request was rejected due to a denied timeslot request.
#define RTK_802154_RX_ERROR_DELAYED_TIMEOUT         0x08 // !< Delayed reception timeslot ended.
#define RTK_802154_RX_ERROR_INVALID_LENGTH          0x09 // !< Received a frame with invalid length.
#define RTK_802154_RX_ERROR_DELAYED_ABORTED         0x0A // !< Delayed operation in the ongoing state was aborted by other request.

/**
 * @brief Possible errors during the energy detection.
 */
typedef uint8_t rtk_802154_ed_error_t;

#define RTK_802154_ED_ERROR_ABORTED 0x01 // !< Procedure was aborted by another operation.

/**
 * @brief Possible errors during the CCA procedure.
 */
typedef uint8_t rtk_802154_cca_error_t;

#define RTK_802154_CCA_ERROR_ABORTED 0x01 // !< Procedure was aborted by another operation.

/**
 * @brief Possible errors during sleep procedure call.
 */
typedef uint8_t rtk_802154_sleep_error_t;

#define RTK_802154_SLEEP_ERROR_NONE 0x00 // !< There is no error.
#define RTK_802154_SLEEP_ERROR_BUSY 0x01 // !< The driver cannot enter the sleep state due to the ongoing operation.

/**
 * @brief Termination level selected for a particular request.
 *
 * Each request can terminate an ongoing operation. This type selects which operation should be
 * aborted by a given request.
 */
typedef uint8_t rtk_802154_term_t;

#define RTK_802154_TERM_NONE   0x00 // !< Request is skipped if another operation is ongoing.
#define RTK_802154_TERM_802154 0x01 // !< Request terminates the ongoing 802.15.4 operation.

/**
 * @brief Types of data that can be set in an ACK message.
 */
typedef uint8_t rtk_802154_ack_data_t;

#define RTK_802154_ACK_DATA_PENDING_BIT 0x00
#define RTK_802154_ACK_DATA_IE          0x01

/**
 * @brief Methods of source address matching.
 *
 * You can use one of the following methods that can be set during the initialization phase
 * by calling @ref rtk_802154_src_matching_method:
 *   - For Thread: @ref RTK_802154_SRC_ADDR_MATCH_THREAD -- The pending bit is set only for the addresses found in the list.
 *   - For Zigbee: @ref RTK_802154_SRC_ADDR_MATCH_ZIGBEE -- The pending bit is cleared only for the short addresses found in the list.\n
 *     This method does not set pending bit in non-command and non-data-request frames.
 *   - For standard-compliant implementation: @ref RTK_802154_SRC_ADDR_MATCH_ALWAYS_1 -- The pending bit is always set to 1.\n
 *     This requires an empty data frame with AR set to 0 to be transmitted immediately afterwards.
 */
typedef uint8_t rtk_802154_src_addr_match_t;

#define RTK_802154_SRC_ADDR_MATCH_THREAD   0x00 // !< Implementation for the Thread protocol.
#define RTK_802154_SRC_ADDR_MATCH_ZIGBEE   0x01 // !< Implementation for the Zigbee protocol.
#define RTK_802154_SRC_ADDR_MATCH_ALWAYS_1 0x02 // !< Standard compliant implementation.

/**
 * @brief RSSI measurement results.
 */

#define RTK_802154_RSSI_INVALID INT8_MAX

/**
 * @brief Mode of triggering receive request to Coex arbiter.
 *
 * Possible values:
 * - @ref RTK_802154_COEX_RX_REQUEST_MODE_ENERGY_DETECTION,
 * - @ref RTK_802154_COEX_RX_REQUEST_MODE_PREAMBLE,
 * - @ref RTK_802154_COEX_RX_REQUEST_MODE_DESTINED
 */
typedef uint8_t rtk_802154_coex_rx_request_mode_t;

#define RTK_802154_COEX_RX_REQUEST_MODE_ENERGY_DETECTION 0x01 // !< Coex requests to arbiter in receive mode upon energy detected.
#define RTK_802154_COEX_RX_REQUEST_MODE_PREAMBLE         0x02 // !< Coex requests to arbiter in receive mode upon preamble reception.
#define RTK_802154_COEX_RX_REQUEST_MODE_DESTINED         0x03 // !< Coex requests to arbiter in receive mode upon detection that frame is addressed to this device.

/**
 * @brief Mode of triggering transmit request to Coex arbiter.
 *
 * Possible values:
 * - @ref RTK_802154_COEX_TX_REQUEST_MODE_FRAME_READY,
 * - @ref RTK_802154_COEX_TX_REQUEST_MODE_CCA_START,
 * - @ref RTK_802154_COEX_TX_REQUEST_MODE_CCA_DONE
 */
typedef uint8_t rtk_802154_coex_tx_request_mode_t;

#define RTK_802154_COEX_TX_REQUEST_MODE_FRAME_READY 0x01 // !< Coex requests to arbiter in transmit mode when the frame is ready to be transmitted.
#define RTK_802154_COEX_TX_REQUEST_MODE_CCA_START   0x02 // !< Coex requests to arbiter in transmit mode before CCA is started.
#define RTK_802154_COEX_TX_REQUEST_MODE_CCA_DONE    0x03 // !< Coex requests to arbiter in transmit mode after CCA is finished.

/**
 * @brief Mode of handling Interframe spacing.
 *
 * Possible values:
 * - @ref RTK_802154_IFS_MODE_DISABLED,
 * - @ref RTK_802154_IFS_MODE_MATCHING_ADDRESSES,
 * - @ref RTK_802154_IFS_MODE_ALWAYS
 */
typedef uint8_t rtk_802154_ifs_mode_t;

#define RTK_802154_IFS_MODE_DISABLED           0x00 // !< Interframe spacing is never inserted.
#define RTK_802154_IFS_MODE_MATCHING_ADDRESSES 0x01 // !< Interframe spacing is inserted only on matching addresses.
#define RTK_802154_IFS_MODE_ALWAYS             0x02 // !< Interframe spacing is always inserted.

/**
 * @brief Function pointer used for notifying about transmission failure.
 */
typedef void (* rtk_802154_transmit_failed_notification_t)(const uint8_t        *p_frame,
		rtk_802154_tx_error_t error);

/**
 * @brief Possible errors during key handling.
 */
typedef uint8_t rtk_802154_security_error_t;

#define RTK_802154_SECURITY_ERROR_NONE                   0x00 // !< There is no error.
#define RTK_802154_SECURITY_ERROR_STORAGE_FULL           0x01 // !< The key storage is full - removal of stored keys is needed.
#define RTK_802154_SECURITY_ERROR_KEY_NOT_FOUND          0x02 // !< The provided key was not found inside the storage.
#define RTK_802154_SECURITY_ERROR_ALREADY_PRESENT        0x03 // !< The storage already has the key of the same ID.
#define RTK_802154_SECURITY_ERROR_TYPE_NOT_SUPPORTED     0x04 // !< The provided key type is not supported.
#define RTK_802154_SECURITY_ERROR_MODE_NOT_SUPPORTED     0x05 // !< The provided key id mode is not supported.
#define RTK_802154_SECURITY_ERROR_FRAME_COUNTER_OVERFLOW 0x06 // !< The associated frame counter overflowed.

/**
 * @brief Types of keys which can be used with the nRF 802.15.4 Radio Driver.
 *
 * Possible values:
 * - @ref RTK_802154_KEY_CLEARTEXT,
 *
 */
typedef uint32_t rtk_802154_key_type_t;

#define RTK_802154_KEY_CLEARTEXT 0x00 // !< Key stored in clear text.

/**
 * @brief Type holding the value of Key Id Mode of the key stored in nRF 802.15.4 Radio Driver.
 */
typedef uint8_t rtk_802154_key_id_mode_t;

/**
 * @brief Type holding the value of Key Id for the keys stored in nRF 802.15.4 Radio Driver.
 */
typedef struct {
	uint8_t                 *p_key_id; // !< Pointer to the Key Id field
	rtk_802154_key_id_mode_t mode;     // !< Key Id Mode (0..3)
} rtk_802154_key_id_t;

/**
 * @brief Type of structure holding a 802.15.4 MAC Security Key.
 */
typedef struct {
	rtk_802154_key_id_t   id;                       // !< Key Id of the key.
	union {
		uint8_t *p_cleartext_key;                   // !< Pointer to the cleartext representation of the key.
	}                     value;                    // !< Union holding different representations of the key.
	rtk_802154_key_type_t type;                     // !< @ref rtk_802154_key_type_t type of the key used.
	uint32_t              frame_counter;            // !< Frame counter to use in case @ref use_global_frame_counter is set to false.
	uint8_t               use_global_frame_counter: 1; // !< Whether to use the global frame counter instead of the one defined in this structure.
} rtk_802154_key_t;

/**
 *@}
 **/

#endif // RTK_802154_TYPES_H__
