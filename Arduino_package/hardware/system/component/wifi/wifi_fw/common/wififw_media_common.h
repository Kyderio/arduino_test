#ifndef __WIFIFW_MEDIA_COMMON_H__
#define __WIFIFW_MEDIA_COMMON_H__

/*--------------------Function declaration---------------------------------*/
extern u8 wififw_media_max_macid_num(void);
extern void wififw_media_set_status(u8 macid, u8 status);
extern bool wififw_media_get_status(u8 macid);
extern void wififw_media_macid_drop_action(u8 status, u8 macid);
extern void wififw_h2c_join_info(struct h2c_join_info *pbuf);

#endif  /* __WIFIFW_MEDIA_COMMON_H__ */

