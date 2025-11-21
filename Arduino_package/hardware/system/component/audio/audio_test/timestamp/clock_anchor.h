
/*
 * Copyright (c) 2025 Realtek, LLC.
 * All rights reserved.
 *
 * Licensed under the Realtek License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License from Realtek
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AUDIO_TEST_AUDIO_CLOCK_ANCHOR_H
#define AUDIO_TEST_AUDIO_CLOCK_ANCHOR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct RTClockAnchor RTClockAnchor;

/**
 * @brief Create RTClockAnchor.
 */
struct RTClockAnchor *RTClockAnchor_Create(void);

/**
 * @brief Destory RTClockAnchor.
 *
 * @param anchor The RTClockAnchor object pointer.
 * @since 1.0
 * @version 1.0
 */
void RTClockAnchor_Destory(struct RTClockAnchor *anchor);

/**
 * @brief Set starting media timestamp to RTClockAnchor.
 *
 * @param starting_media_us the start media time in us.
 * @since 1.0
 * @version 1.0
 */
void RTClockAnchor_SetStartingMediaTime(struct RTClockAnchor *anchor, int64_t starting_media_us);

/**
 * @brief Reset media timestamp and system timestamp in RTClockAnchor.
 *
 * @since 1.0
 * @version 1.0
 */
void RTClockAnchor_ClearAnchor(struct RTClockAnchor *anchor);

/**
 * @brief update media timestamp and system timestamp in RTClockAnchor.
 * @param media_us the anchor media time in us.
 * @param system_us the anchor system time in us.
 * @since 1.0
 * @version 1.0
 */
void RTClockAnchor_UpdateAnchor(struct RTClockAnchor *anchor, int64_t media_us, int64_t system_us, int64_t max_media_us);

/**
 * @brief update max media timestamp in RTClockAnchor.
 * @param max_media_us the anchor media time in us.
 * @since 1.0
 * @version 1.0
 */
void RTClockAnchor_UpdateMaxMediaTime(struct RTClockAnchor *anchor, int64_t max_media_us);

/**
 * @brief get media timestamp in RTClockAnchor according to system timestamp.
 * @param system_us the system time in us.
 * @param media_us the pointer of media_us, framework will fill media time in this pointer address.
 * @return Returns a value listed below: \n
 * status_t | Description
 * ----------------------| -----------------------
 * OSAL_OK | the operation is successful.
 * OSAL_ERR_INVALID_OPERATION | operation not permitted.
 * OSAL_ERR_INVALID_PARAM | the parameter is not valid.
 * @since 1.0
 * @version 1.0
 */
status_t RTClockAnchor_GetMediaTime(struct RTClockAnchor *anchor, int64_t system_us, int64_t *media_us);

/**
 * @brief get system timestamp in RTClockAnchor according to media timestamp.
 * @param media_us the media time in us.
 * @param system_us the pointer of system time, framework will fill system time in this pointer address.
 * @return Returns a value listed below: \n
 * status_t | Description
 * ----------------------| -----------------------
 * OSAL_OK | the operation is successful.
 * OSAL_ERR_INVALID_OPERATION | operation not permitted.
 * OSAL_ERR_INVALID_PARAM | the parameter is not valid.
 * @since 1.0
 * @version 1.0
 */
status_t RTClockAnchor_GetSystemTime(struct RTClockAnchor *anchor, int64_t media_us, int64_t *system_us);

#ifdef __cplusplus
}
#endif
#endif // AUDIO_CLOCK_ANCHOR_H
/** @} */
