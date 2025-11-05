#ifndef __WPAS_STD_MAIN_H_
#define __WPAS_STD_MAIN_H_

#include "drivers/driver.h"

int start_wpa_supplicant(char *iface_name);
int stop_wpa_supplicant(void);
void wpas_std_test_cmd(char *item, int msg_len);

#endif /* __WPAS_STD_MAIN_H_ */
