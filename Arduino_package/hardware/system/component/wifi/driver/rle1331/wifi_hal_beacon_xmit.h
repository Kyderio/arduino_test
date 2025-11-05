#ifndef __WIFI_HAL_BEACON_XMIT_H__
#define __WIFI_HAL_BEACON_XMIT_H__

#define BEACON_BUFFER_LEN	400
#define BEACON_BUFFER_NUM	2
#define BEACON_BUFFER_IS_BUSY		BIT0

struct beacon_xmit_buffer {
	u8 *buffer;
	u32 buffer_len;
	u8 buffer_flag;	/*0: current buffer can be used by SW; 1: current buffer is occupied by mac, cannot be used */
};

struct bcn_xmit_priv {
	struct beacon_xmit_buffer buf[BEACON_BUFFER_NUM];
	u8 idx;
#ifdef CONFIG_NAN
	struct beacon_xmit_buffer nan_buf[BEACON_BUFFER_NUM];	// 0 is SYNC_BCN, 1 is DISC_BCN
#endif
};

void wifi_hal_beacon_xmit_init(void);
void wifi_hal_beacon_xmit_deinit(void);
void wifi_hal_beacon_buffer_update(u8 alloc);
void wifi_hal_beacon_content_update(u32 offset, u8 *buf, u32 buflen);
int wifi_hal_beacon_xmit(struct xmit_frame *pmgntframe);
#endif //__WIFI_HAL_BEACON_XMIT_H__
