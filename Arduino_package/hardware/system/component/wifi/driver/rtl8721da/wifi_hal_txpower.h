#ifndef _WIFI_HAL_TXPOWER_H_
#define _WIFI_HAL_TXPOWER_H_

/*refer to mp flow.pdf, p60
https://wiki.realtek.com/display/CWH/AmebaDPlus+Application+Note*/
RTW_PACK_STRUCT_BEGIN
struct efuse_pwridx_2g_t {
	u8 cck_grp[6];
	u8 bw40_grp[5];
	u8 ofdm_diff: 4;/*bit7~4*/
	u8 bw20_diff: 4;/*bit3~0*/

};
RTW_PACK_STRUCT_END

RTW_PACK_STRUCT_BEGIN
struct efuse_pwridx_5g_t {
	u8 bw40_grp[14];
	u8 ofdm_diff: 4;
	u8 bw20_diff: 4;
};
RTW_PACK_STRUCT_END


#endif