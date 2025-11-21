#ifndef RTK_OT_SETTINGS_FILE_H_
#define RTK_OT_SETTINGS_FILE_H_

#include "ameba_soc.h"

#ifdef __cplusplus
extern "C" {
#endif

int rtk_ot_settings_file_get(const char *file_base_name, uint16_t key_in, int index_in, uint8_t *value, uint16_t *value_length, bool *found);
int rtk_ot_settings_file_set(const char *file_base_name, uint16_t key_in, const uint8_t *value, uint16_t value_length);
int rtk_ot_settings_file_add(const char *file_base_name, uint16_t key_in, const uint8_t *value, uint16_t value_length);
int rtk_ot_settings_file_delete(const char *file_base_name, uint16_t key_in, int index_in, bool *found);
int rtk_ot_settings_file_wipe(const char *file_base_name);
int rtk_ot_settings_file_init(const char *file_base_name);
int rtk_ot_settings_file_deinit(const char *file_base_name);

#ifdef __cplusplus
}
#endif

#endif