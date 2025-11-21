#ifndef RTK_OT_SETTINGS_TMP_H_
#define RTK_OT_SETTINGS_TMP_H_

#include "ameba_soc.h"
#include <openthread/instance.h>
#include "lib/spinel/radio_spinel_metrics.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
	key_boot_time            = 1,
	key_radio_spinel_metrics = 2,
};

int rtk_ot_settings_tmp_get(uint16_t key, int index, uint8_t *value, uint16_t *value_length, bool *found);
int rtk_ot_settings_tmp_set(uint16_t key, const uint8_t *value, uint16_t value_length);
int rtk_ot_settings_tmp_add(uint16_t key, const uint8_t *value, uint16_t value_length);
int rtk_ot_settings_tmp_init(void);
int rtk_ot_settings_tmp_deinit(void);
int rtk_ot_settings_tmp_delete(uint16_t key, int index, bool *found);
int rtk_ot_settings_tmp_wipe(void);
int rtk_ot_save_radio_spinel_metrics(const otRadioSpinelMetrics metrics);
int rtk_ot_restore_radio_spinel_metrics(otRadioSpinelMetrics metrics, bool *found);

#ifdef __cplusplus
}
#endif

#endif