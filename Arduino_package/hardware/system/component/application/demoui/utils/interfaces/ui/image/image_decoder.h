/*
 * Copyright (c) 2022 Realtek, LLC.
 * All rights reserved.
 *
 * Licensed under the Realtek License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License from Realtek
 *
 * Unless reqUired by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @addtogroup graphic
 * @{
 *
 * @brief Declares APIs for LVGL extra Library.
 *
 * @since 1.0
 * @version 1.0
 *
 */

/**
 * @file image_decoder.h
 *
 * @brief Defines the structures and interfaces for the image decoder.
 *
 * @since 1.0
 * @version 1.0
 *
 */

#ifndef AMEBA_APPS_PANGU_UTILS_IMAGE_DECODER_H
#define AMEBA_APPS_PANGU_UTILS_IMAGE_DECODER_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Indicates Image info.
 *
 * @since 1.0
 * @version 1.0
 */
typedef struct {
	int32_t type;
	int32_t color_type;
	int32_t w;
	int32_t h;
	unsigned char *data;
	int32_t alpha;
} ImageInfo;

void ImageDecoder_Init(void);

/**
 * @brief Load the compress image to get the image info with a special color depth
 *
 * @param file_name Indicates the file name of the compress image.
 * @param info Indicates the double pointer to image information.
 * @param color_depth Indicates the color depth to image information.
 *
 * @since 1.0
 * @version 1.0
 */
void ImageDecoder_LoadImage(const char *file_name, ImageInfo **info, int32_t color_depth);

#ifdef __cplusplus
}
#endif

#endif // AMEBA_APPS_PANGU_UTILS_IMAGE_DECODER_H
/** @} */