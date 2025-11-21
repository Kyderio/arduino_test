#include "ameba_soc.h"
//#include "ameba_ft_adc_dac_qa_test.h"


_LONG_CALL_ void gpio_test_qa();

void example_audio_ft_test(void);
//void example_audio_dmic_ft_test(void);

void ADC_TEST_QATest(void);

#ifdef CONFIG_WLAN
/*
 * WLAN
 */
#define QA_TEST_AP "WL-HWSD"
#define QA_TEST_PASSWORD "12345678"
#define QA_TEST_SECURITY_TYPE	RTW_SECURITY_WPA2_AES_PSK
#define DEFAULT_PIN_CNT 4

#define WIFI_TEST_DONE_2G BIT0
/** @} */

void wifi_mp_ctx_thread(void);
#endif
/*------------------ Memory Test Fucntions -----------------------------*/
void qa_param_thread(u32 *param);


