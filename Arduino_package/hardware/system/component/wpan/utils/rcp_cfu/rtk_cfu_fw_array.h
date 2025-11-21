#ifndef RTK_CFU_FW_ARRAY_H_
#define RTK_CFU_FW_ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RTK_CFU_FW_OFFER   0
#define RTK_CFU_FW_PAYLOAD 1
#define RTK_CFU_FW_CONFIG  2
#define RTK_CFU_FW_MAX     3

#define RTK_CFU_FW_8771H_PAYLOAD_NUM  4

extern uint8_t rtkcfu_8771h_config[];
extern uint16_t rtkcfu_8771h_config_length;
extern uint8_t *rtkcfu_8771h_bin[RTK_CFU_FW_MAX - 1][RTK_CFU_FW_8771H_PAYLOAD_NUM];
extern uint32_t rtkcfu_8771h_bin_length[RTK_CFU_FW_MAX - 1][RTK_CFU_FW_8771H_PAYLOAD_NUM];
extern char *rtkcfu_8771h_bin_name[RTK_CFU_FW_MAX - 1][RTK_CFU_FW_8771H_PAYLOAD_NUM];

#ifdef __cplusplus
}
#endif

#endif