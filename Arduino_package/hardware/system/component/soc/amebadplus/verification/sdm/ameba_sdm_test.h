#ifndef _AMEBA_SDM_TEST_H_
#define _AMEBA_SDM_TEST_H_

#define CLK_FREQ_DOWNLIMIT  104858	//32768Hz * 4 * 80% (+/-20%)
#define CLK_FREQ_UPLIMIT  157286	//32768Hz * 4 * 120%  (+/-20%)

typedef struct {
	int atmr_ms_min;
	int atmr_ms_max;
	int active_ms_min;
	int active_ms_max;
	int sleep_ms_min;
	int sleep_ms_max;
} SDM_TIM_SETTING;

#endif

