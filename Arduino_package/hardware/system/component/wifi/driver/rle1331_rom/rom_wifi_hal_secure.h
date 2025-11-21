#ifndef __ROM_WIFI_HAL_SECURE_H__
#define __ROM_WIFI_HAL_SECURE_H__

/************************** KEYCFG FORMAT ********************************/
#define KEYCFG_SEC_TYPE_OFFSET	2
#define KEYCFG_EXT_TYPE		BIT(5)
#define KEYCFG_MIC		BIT(6)	//indicate this entry is MIC key, used for sms4/gcm-sms4
#define KEYCFG_GRP		BIT(7)
#define KEYCFG_MGNT		BIT(8)
#define KEYCFG_RPT_MD		BIT(9)	// indicate repeater mode
#define KEYCFG_SPP_VALID	BIT(10)
#define KEYCFG_VALID		BIT(15)
#define KEYCFG_SET_MACID(x)	(((u32)((x) & 0x7F) << 25))
#define KEYCFG_GET_SEC_TYPE(x)  ((u8)(x >> KEYCFG_SEC_TYPE_OFFSET) & 0xf)

union key_cam_ctrl {
	struct {
		u32 keyid: 2;
		u32 type: 4;
		u32 mic: 1;
		u32 grp_bit: 1;
		u32 mgnt: 1;
		u32 rpt_md: 1;
		u32 spp_valid: 1;
		u32 rsvd0: 4;
		u32 valid: 1;
		u32 rsvd1: 9;
		u32 macid: 7;
	};
	u32 ctrl;
};

void ROM_WIFI_CAM_WRITE(u8 entry, u16 ctrl, u8 macid, u8 *key);

#endif //__ROM_WIFI_HAL_SECURE_H__
