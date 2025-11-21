#ifndef __ROM_WIFI_HAL_SECURE_H__
#define __ROM_WIFI_HAL_SECURE_H__

#define KEYCFG_SEC_TYPE_OFFSET	2
#define KEYCFG_MIC		BIT(5)
#define KEYCFG_GRP		BIT(6)
#define KEYCFG_RPT_MD		BIT(8)	// indicate repeater mode
#define KEYCFG_EXT_TYPE		BIT(9)
#define KEYCFG_VALID		BIT(15)

void ROM_WIFI_CAM_WRITE(u8 entry, u16 ctrl, u8 *mac, u8 *key);

#endif
