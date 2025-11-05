#ifndef _PHL_H_
#define _PHL_H_
#include <phl_def.h>

#define REGULATION_CHPLAN_VERSION 70
#define REGULATION_COUNTRY_VERSION 45

void rtw_phl_com_init(void);
void rtw_phl_com_deinit(void);

#if (PHYDM_VERSION == 3)/*ax ic : AmebaSmart, AmebaLite*/
bool rtw_phl_query_regulation(struct rtw_regulation_info *info);
#else/*non-ax ic, not use halbb and halrf, don't need the functions below*/
#endif/*(PHYDM_VERSION == 3)*/

#endif
