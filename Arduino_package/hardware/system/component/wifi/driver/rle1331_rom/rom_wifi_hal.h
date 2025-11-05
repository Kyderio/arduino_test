#ifndef __ROM_WIFI_HAL_H__
#define __ROM_WIFI_HAL_H__

#include "rtw_wifi_constants.h"
#include "wifi_hal_reg.h"
#include "rom_wifi_hal_const.h"
#include "rom_hal_common.h"

#include "rom_wifi_hal_ax.h"
#include "rom_wifi_hal_bcn.h"
#include "rom_wifi_hal_debug.h"
#include "rom_wifi_hal_init.h"
#include "rom_wifi_hal_media_access.h"
#include "rom_wifi_hal_misc.h"
#include "rom_wifi_hal_rate.h"
#include "rom_wifi_hal_secure.h"
#include "rom_wifi_hal_tsf.h"
#include "rom_wifi_hal_txdesc.h"
#include "rom_wifi_hal_rxdesc.h"
#include "rom_wifi_hal_macid_cam.h"

//========================================================
//			BEACON definition
//========================================================
#define DRIVER_EARLY_INT_TIME           0x05 // 5ms

//========================================================
//			MACID CAM definition
//========================================================
#define MACID_CAM_BASE                  0x40023800

//========================================================
//			TXBD and RXBD definition
//========================================================
#define TX_Q_DESC_DEPTH         2
#define TX_Q_RLS_DEPTH          6
#define TX_Q_RPT_DEPTH          5
#define RX_Q_DESC_DEPTH         4
#define CSI_Q_DESC_DEPTH        2
#define RADAR_Q_DESC_DEPTH      1
#define TX_Q_DESC_NUM           (1 << TX_Q_DESC_DEPTH)	//should be power of 2, range is 2^1 ~ 2^6
#define RX_Q_DESC_NUM           (1 << RX_Q_DESC_DEPTH)	//should be power of 2, range is 2^1 ~ 2^6
#define CSI_Q_DESC_NUM          (1 << CSI_Q_DESC_DEPTH)	//should be power of 2, range is 2^1 ~ 2^6
#define RADAR_Q_DESC_NUM        (1 << RADAR_Q_DESC_DEPTH)	//should be power of 2, range is 2^1 ~ 2^6
#ifdef CONFIG_EXTRA_ALLOC_RXBUF
#define RXBD_BUFFER_SIZE        (256 * 7)                 //unit: bytes, should be multiple of 256
#endif
#define CSIBD_BUFFER_SIZE              (256 * 4)                 //unit: bytes, should be multiple of 256, seg_len max is 992
#define RADARBD_BUFFER_SIZE              (256 * 9)              //unit: bytes, should be multiple of 256

//========================================================
//			network type definition
//========================================================
#define NT_NO_LINK		0x0
#define NT_LINK_AD_HOC	0x1
#define NT_LINK_AP		0x2
#define NT_AS_AP		0x3
#define MSR			    (REG_CR + 2)

//========================================================
//			RATE definition
//========================================================
#define GEN_HT_RATE_IDX(MCS)            (0x10 | ((MCS) & 0xf))
#define GEN_VHT_RATE_IDX(SS, MCS)       (0x20 | ((MCS) & 0xf))
#define GEN_HE_RATE_IDX(SS, MCS)        (0x30 | ((MCS) & 0xf))

//========================================================
//			RSSI definition
//========================================================
#define translate_percentage_to_dbm(SignalStrengthIndex)	ROM_WIFI_HAL_RXDESC_Percentage2dbm(SignalStrengthIndex)

#endif //__ROM_WIFI_HAL_H__
