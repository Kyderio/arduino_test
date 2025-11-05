#ifndef __WIFI_HAL_NAN_CTRL_H__
#define __WIFI_HAL_NAN_CTRL_H__

#ifdef CONFIG_NAN

#define NAN_ENTRY_SIZE  64
#define ReadNANrptByte(offset)         	(*(volatile u8 *)((u32)((0x40040000 + 0xA90)  + offset)))
#ifndef TU
#define TU  1024 /* 1 TU equals 1024 microseconds */
#endif

#define SAMPLING_TIME (TU)

#define START_LOC_NAN_ATTRI	82	//attri offset+tx desc len
#define START_LOC_A3			56	//A3 offset + tx desc len

#define NAN_RSSI_MIDDLE_DBM		(-75)
#define NAN_RSSI_CLOSE_DBM		(-60)
#define NAN_RSSI_MIDDLE_THRESHOLD_CNT	3
#define NAN_RSSI_CLOSE_THRESHOLD_CNT		1
#define NAN_HOPCOUNT_THRESHOLD			10
#define NAN_BEACON_DISCARD_THRESHOLD	(16*512*TU)
#define NAN_DEVICE_LIST_LIMIT_DMEM		5

#define NAN_SYNC_RETRY_LIMIT		3

#define NAN_5G_DW_OFFSET				(128*TU)
#define NAN_DW_DURATION				(16*TU)
#define NAN_SYNC_BCN_INTERVAL			(512*TU)
#define NAN_DISC_BCN_INTERVAL_MAX       (200*TU)
#define NAN_DISC_BCN_INTERVAL_MIN       (100*TU)
#define NAN_WARM_UP_TIME_DEFAULT        (120*1000*1000)
#define NAN_WARM_UP_START_TIME_OFFSET   (1000*TU)
#define SYNC_BCN_PER_HC_DELAY_US		(40*9)
#define NAN_DW0_PERIOD				(16*512*TU)
#define SYNC_BCN_PER_HC_DELAY_US        (40*9)

// Period for update Random Factor
#define RANDOM_FACTOR_UPDATE_PERIOD		(180*NAN_SYNC_BCN_INTERVAL)

// Period for update Master Preference
#define MASTER_PREF_UPDATE_PERIOD			(260*NAN_SYNC_BCN_INTERVAL)

#define MAX_ACTION_REQUEST_ENTRY_NUM	8

enum {
	NAN_EVENT_DW_EARLY  = 0,
	NAN_EVENT_DW_START = 1,
};

enum SDF_TXRPT {
	SDF_TXRPT_TXAREA_75 = BIT(0),
	SDF_TXRPT_TX_FAIL = BIT(1),
	SDF_TXRPT_TX_OK = BIT(2),
};


__STATIC_INLINE u16 wifi_hal_nan_get_slot(u64 TSF)
{
	u16 slot = 0;
	TSF /= TU;
	TSF %= DW0_INTERVAL;
	slot = TSF % NAN_SLOT;
	return slot;
}

/* note:
for smart, pstimer is 64bits, unit is 1us, no need consider overflow.
for costdown-IC, pstimer is 32bits, unit is 16us, need consider overflow */
__STATIC_INLINE u8 wifi_hal_nan_check_tsf_reset(u32 TSF1, u32 TSF2)
{
	u32 diff = (TSF1 > TSF2) ? (TSF1 - TSF2) : (TSF2 - TSF1);
	return (diff & BIT31) ? TRUE : FALSE;
}

__STATIC_INLINE u8 wifi_hal_nan_check_tsf_equal(u64 TSF1, u64 TSF2)
{
	u64  a, b;
	a = TSF1 / TU * TU;
	b = TSF2 / TU * TU;

	return (a == b) ? TRUE : FALSE;
}

void wifi_hal_nan_c2h_hdl(u8 *payload, u8 plen);

#endif
#endif
