/********************************************************************************
*
* RtPlc.h
*
* Update Time: 2021/12/27
*
********************************************************************************/

#ifndef RS_PLC_H
#define RS_PLC_H

#include <string.h>
#include <stdio.h>
#include "stdlib.h"

#include "vox_mem.h"
#include "vox_math.h"


#ifdef __cplusplus
extern "C" {
#endif

#define PLC_MAX_LOSS_NUM              2
#define PLC_MAX_LOSS_FRAMES           9600

enum {
	RTAUDIOPLC_FORMAT_INVALID           = 0xFFFFFFFFu,
	RTAUDIOPLC_FORMAT_PCM_16_BIT        = 0x2u,
	RTAUDIOPLC_FORMAT_PCM_32_BIT        = 0x4u,
	RTAUDIOPLC_FORMAT_PCM_FLOAT         = 0x5u,
};

/**
 * @brief Init the plc algorithm.
 *
 * @param lost_frames is the frame length that losses.
 * @param format is the format of data to do plc.
 * @since 1.0
 * @version 1.0
 */
void RTAudioPlc_Init(int32_t lost_frames, int32_t format);

/**
 * @brief Calculate the window buffer.
 *
 * @param lost_frames is the frame length that losses.
 * @param format is the format of data to do plc.
 * @since 1.0
 * @version 1.0
 */
void RTAudioPlc_CalWin(int32_t lost_frames);

/**
 * @brief Destroy the plc algorithm engine.
 *
 * @since 1.0
 * @version 1.0
 */
void RTAudioPlc_Destroy(void);

/**
 * @brief Process plc algorithm.
 *
 * @param p_pre_buf is the pointer of previous buffer.
 * @param p_post_buf is the pointer of postpone buffer.
 * @param p_out_buf is the pointer of output buffer.
 * @param sw_frame_len is the frame length that losses.
 * @param sw_soss_nums is the count of sw_frame_len that is lost, currently only support 1.
 * @since 1.0
 * @version 1.0
 */
void RTAudioPlc_Process(int8_t *pre_buf, int8_t *post_buf, int8_t *out_buf, int32_t lost_frames, int32_t lost_nums);

/**
 * @brief insert samples to buffer when left sample and right sample is known.
 *
 * @param pre_sample is left sample's pointer known.
 * @param post_sample is right sample's pointer known.
 * @param insert_buf is buffer to insert samples.
 * @param insert_buf_frame_count is samples frames to insert.
 * @param channels is buffer channels.
 * @param bits is buffer bits.
 * @return Returns a value listed below: \n
 * int32_t | Description
 * ----------------------| -----------------------
 * OSAL_OK | the operation is successful.
 * OSAL_ERR_INVALID_OPERATION | the config value is not proper.
 * @since 1.0
 * @version 1.0
 */
int32_t RTAudioPlc_LinearInsert(int8_t *pre_sample, int8_t *post_sample, int8_t *insert_buf, int32_t insert_buf_frame_count, uint32_t channels,
								uint32_t bits);

#ifdef __cplusplus
}
#endif

#endif