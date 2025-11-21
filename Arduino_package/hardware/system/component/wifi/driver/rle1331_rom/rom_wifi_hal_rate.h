#ifndef __ROM_WIFI_HAL_RATE_H__
#define __ROM_WIFI_HAL_RATE_H__

#ifdef IS_LEGACY_MODE_RATE
#undef IS_LEGACY_MODE_RATE
#undef IS_HT_MODE_RATE
#undef IS_VHT_MODE_RATE
#undef IS_HE_MODE_RATE
#endif
#define IS_LEGACY_MODE_RATE(desc_rate)	(((desc_rate >> 4) & 0x3) == HAL_LEGACY_MODE)
#define IS_HT_MODE_RATE(desc_rate)	(((desc_rate >> 4) & 0x3) == HAL_HT_MODE)
#define IS_VHT_MODE_RATE(desc_rate)	(((desc_rate >> 4) & 0x3) == HAL_VHT_MODE)
#define IS_HE_MODE_RATE(desc_rate)	(((desc_rate >> 4) & 0x3) == HAL_HE_MODE)

u16 ROM_WIFI_MRateToHwRate(u8 rate);
u8 ROM_WIFI_HwRateToMRate(u16 rate);

#endif
