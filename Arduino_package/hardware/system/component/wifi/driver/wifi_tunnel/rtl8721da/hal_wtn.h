
#ifndef __HAL_WIFI_TUNNEL_H__
#define __HAL_WIFI_TUNNEL_H__

#include <rtw_wtn.h>

#define WIFI_TUNNEL_ADDRCAM_IDX_MAX               9
#define WIFI_TUNNEL_ADDRCAM_BIT_BCN               BIT(0)
#define WIFI_TUNNEL_ADDRCAM_BIT_PROBE_RSP         BIT(1)
#define WIFI_TUNNEL_ADDRCAM_BIT_STA               BIT(2)
#define WIFI_TUNNEL_ADDRCAM_BIT_PROBE_REQ         BIT(3)
#define WIFI_TUNNEL_ADDRCAM_BIT_OTHER_MGNT        BIT(4)
#define WIFI_TUNNEL_ADDRCAM_BIT_DATA_UC           BIT(5)
#define WIFI_TUNNEL_ADDRCAM_BIT_DATA_BCMC         BIT(6)
#define WIFI_TUNNEL_ADDRCAM_BIT_WIFI_TUNNEL_DL_UC BIT(7)
#define WIFI_TUNNEL_ADDRCAM_BIT_WIFI_TUNNEL_UL_UC BIT(8)


inline void wifi_tunnel_buf_dump(char *_titlestring, bool _idx_show, const u8 *_hexdata, int _hexdatalen)
{
	int __i;
	u8 *ptr = (u8 *)_hexdata;

	if (_titlestring) {
		RTK_LOGI(NOTAG, "%s len=%d T:%d", _titlestring, _hexdatalen, rtos_time_get_current_system_time_ms());
		if (_hexdatalen >= 16) {
			RTK_LOGI(NOTAG, "\n");
		}
	}

	for (__i = 0; __i < _hexdatalen; __i++) {
		if (((__i % 16) == 0) && (_hexdatalen >= 16)) {
			if (_idx_show) {
				RTK_LOGI(NOTAG, "0x%03X: ", __i);
			} else {
				RTK_LOGI(NOTAG, " ");
			}
		}
		RTK_LOGI(NOTAG, "%02X%s", ptr[__i], (((__i + 1) % 4) == 0) ? "  " : " ");
		if ((__i + 1 < _hexdatalen) && ((__i + 1) % 16) == 0) {
			RTK_LOGI(NOTAG, "\n");
		}
	}
	RTK_LOGI(NOTAG, "\n");
}

#endif //__HAL_WIFI_TUNNEL_H__
