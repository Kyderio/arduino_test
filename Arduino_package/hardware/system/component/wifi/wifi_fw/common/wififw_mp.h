#ifndef __WIFIFW_MP_H__
#define __WIFIFW_MP_H__
/*--------------------Define MACRO--------------------------------------*/


/*--------------------Define Struct---------------------------------------*/


/*------------------------------Function declaration--------------------------*/
extern u8 wifi_mp_pg_trx_enable;
extern u8 wifi_mp_pg_trx_mode;

extern void wififw_mp_mac_enter_lps(void);
extern void wififw_mp_pg_trx_test(u8 wifi_mp_pg_trx_test_mode);
extern void wififw_mp_get_phy_reg_table(void);
#endif
