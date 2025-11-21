#ifndef _RTW_11D_H_
#define _RTW_11D_H_

#define DOT11D_COUNTRY_CODE_LEN		3
#define DOT11D_MAX_COUNTRY		10

struct dot11d_country {
	/*If it is a country, the first two octets of this string is the two character country code as described in document ISO 3166-1*/
	u16 cnt;
	char country[DOT11D_COUNTRY_CODE_LEN];
};

struct dot11d_priv {
	/* 11d learning result */
	struct dot11d_country learned; /* learned country */

	/* learned statistics */
	struct dot11d_country country_all[DOT11D_MAX_COUNTRY];
	u16 total_country;
};


bool wifi_get_country_code_info(u8 *country_code, u8 *channel_plan, u8 *power_limit);
#endif

