#ifndef RX_DAGC_H
#define RX_DAGC_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <arm_neon.h>
#include "rtl8730A_radio_trx_api.h"

#if SBD_SYM_THREE
#define RX_AGC_DIN_BUF_NUM 192
#else
#define RX_AGC_DIN_BUF_NUM 256
#endif

struct rx_dagc {
	int32_t din_buf_re[RX_AGC_DIN_BUF_NUM] __attribute__((aligned(64)));
	int32_t din_buf_im[RX_AGC_DIN_BUF_NUM] __attribute__((aligned(64)));
	int32_t pwr_acc;
	int32_t gain;
	int32_t target_level;
};

void rx_dagc_reset(struct rx_dagc *obj);
void rx_dagc_init(struct rx_dagc *obj);
void rx_dagc_run(struct rx_dagc *obj);
void rx_dagc_test(void);


#ifdef  __cplusplus
}
#endif

#endif


