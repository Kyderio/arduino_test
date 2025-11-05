#ifndef __AMEBAGREEN2_WIFI_EQC_H
#define __AMEBAGREEN2_WIFI_EQC_H

#ifdef __cplusplus
extern "C" {
#endif


int eqc_wifi_connect_ping(void);
int wifi_start_softap(u8 is_5g);

#ifdef __cplusplus
}
#endif

#endif