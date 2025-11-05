#ifndef __ROM_WIFI_HAL_H__
#define __ROM_WIFI_HAL_H__

#include "rtw_wifi_constants.h"

#include "wifi_hal_reg.h"
#include "rom_wifi_hal_const.h"
#include "rom_hal_common.h"

#include "rom_wifi_hal_bcn.h"
#include "rom_wifi_hal_debug.h"
#include "rom_wifi_hal_init.h"
#include "rom_wifi_hal_media_access.h"
#include "rom_wifi_hal_misc.h"
#include "rom_wifi_hal_rate.h"
#include "rom_wifi_hal_secure.h"
#include "rom_wifi_hal_tsf.h"
#include "rom_wifi_hal_txdesc.h"
#include "rom_wifi_hal_txpower.h"
#include "rom_wifi_hal_rxdesc.h"

#define DRIVER_EARLY_INT_TIME         0x05 // 5ms
#define BCN_DMA_ATIME_INT_TIME        0x02 // 2ms

// for 8721D
// TX 32K, RX 16K, Page size 128B for TX, 8B for RX
#define PAGE_SIZE_TX                  128
#define PAGE_SIZE_RX                  8

#define RX_DMA_SIZE                   0x4000	// 16K
#define RX_DMA_RESERVED_SIZE          0x80	// 128B, reserved for tx report
#define RX_DMA_BOUNDARY               (RX_DMA_SIZE - RX_DMA_RESERVED_SIZE - 1)

// Note: We will divide number of page equally for each queue other than public queue!
#define LPS_OFFLOAD_PAGE_NUM      0x13  /*reuse with BCNQ0/BCN1/NAN PAGE NUM*/

#define GENERAL_RSVD_PAGE_NUM         (u8)(BCN0_NAN_SYNC_PAGE_NUM + BCN1_SOFTAP_PAGE_NUM + NAN_PAGE_NUM)
#define FW_USED_OFFSET          (u8)((GENERAL_RSVD_PAGE_NUM > LPS_OFFLOAD_PAGE_NUM) ? GENERAL_RSVD_PAGE_NUM : LPS_OFFLOAD_PAGE_NUM)

#define TX_TOTAL_PAGE_NUMBER      (0xFF - FW_USED_OFFSET - FW_USED_PAGE_NUM)
#define TX_PAGE_BOUNDARY          (TX_TOTAL_PAGE_NUMBER + 1)

#define WMM_NORMAL_TX_TOTAL_PAGE_NUMBER	TX_TOTAL_PAGE_NUMBER
#define WMM_NORMAL_TX_PAGE_BOUNDARY			(WMM_NORMAL_TX_TOTAL_PAGE_NUMBER + 1)

// For Normal Chip Setting
// (HPQ + LPQ + NPQ + PUBQ) shall be TX_TOTAL_PAGE_NUMBER_8721D
#define NORMAL_PAGE_NUM_HPQ				0x0C
#define NORMAL_PAGE_NUM_LPQ				0x02
#define NORMAL_PAGE_NUM_NPQ				0x02

// Note: For Normal Chip Setting, modify later
#define WMM_NORMAL_PAGE_NUM_HPQ			0x30
#define WMM_NORMAL_PAGE_NUM_LPQ			0x20
#define WMM_NORMAL_PAGE_NUM_NPQ			0x20

//========================================================
//			TXBD and RXBD definition
//========================================================
#ifdef CONFIG_MP_INCLUDED	// For MP Tx no idle
#define TX_VIQ_DESC_NUM         4
#define TX_VOQ_DESC_NUM         4
#define TX_BKQ_DESC_NUM         4
#define TX_BEQ_DESC_NUM         32
#else
#define TX_VIQ_DESC_NUM         4
#define TX_VOQ_DESC_NUM         4
#define TX_BKQ_DESC_NUM         4
#define TX_BEQ_DESC_NUM         4
#if defined(CONFIG_REPEATER) && CONFIG_REPEATER
#undef	TX_BEQ_DESC_NUM
#define TX_BEQ_DESC_NUM         32
#endif
#endif

#define TX_BCNQ_DESC_NUM        4

#define TX_MGQ_DESC_NUM         4
#define TX_H0Q_DESC_NUM         4  // Increase Tx Hi Queue for BMcast Packets in SoftAP mode
#define TX_H1Q_DESC_NUM         2
#define TX_H2Q_DESC_NUM         2
#define TX_H3Q_DESC_NUM         2
#define TX_H4Q_DESC_NUM         2
#define TX_H5Q_DESC_NUM         2
#define TX_H6Q_DESC_NUM         2
#define TX_H7Q_DESC_NUM         2
#define RX_Q_DESC_NUM           4  //16 Reduce rx desc number due to memory limitation
#if defined(CONFIG_REPEATER) && CONFIG_REPEATER
#undef	RX_Q_DESC_NUM
#define RX_Q_DESC_NUM           16  //16 Reduce rx desc number due to memory limitation
#endif
#define SET_VIQ_DES_NUM     (TX_VIQ_DESC_NUM<<16)
#define SET_VOQ_DES_NUM     (TX_VOQ_DESC_NUM)
#define SET_RXQ_DES_NUM     (RX_Q_DESC_NUM<<16)
#define SET_MGQ_DES_NUM     (TX_MGQ_DESC_NUM)
#define SET_BKQ_DES_NUM     (TX_BKQ_DESC_NUM<<16)
#define SET_BEQ_DES_NUM     (TX_BEQ_DESC_NUM)
#define SET_H1Q_DES_NUM     (TX_H1Q_DESC_NUM<<16)
#define SET_H0Q_DES_NUM     (TX_H0Q_DESC_NUM)
#define SET_H3Q_DES_NUM     (TX_H3Q_DESC_NUM<<16)
#define SET_H2Q_DES_NUM     (TX_H2Q_DESC_NUM)
#define SET_H5Q_DES_NUM     (TX_H5Q_DESC_NUM<<16)
#define SET_H4Q_DES_NUM     (TX_H4Q_DESC_NUM)
#define SET_H7Q_DES_NUM     (TX_H7Q_DESC_NUM<<16)
#define SET_H6Q_DES_NUM     (TX_H6Q_DESC_NUM)

#define TX_DESC_MODE        1

#define MAX_TXBD_SEQMENT_NUM    ((TX_DESC_MODE)? (4*TX_DESC_MODE): 2)
#define TXBD_SEGMENT_SIZE		8

//Network Type
#define NT_NO_LINK				0x0
#define NT_LINK_AD_HOC			0x1
#define NT_LINK_AP				0x2
#define NT_AS_AP				0x3

#define QUEUE_LOW				1
#define QUEUE_NORMAL			2
#define QUEUE_HIGH				3

#define MSR						(REG_CR + 2)

// Only use CCK 1M rate for ACK
#define RATE_RRSR_CCK_ONLY_1M		0xFFFF1
#define RATE_RRSR_WITHOUT_CCK		0xFFFF0

#define translate_percentage_to_dbm(SignalStrengthIndex)	ROM_WIFI_HAL_RXDESC_Percentage2dbm(SignalStrengthIndex)

#define CONTROL_INFO_ENTRY_SIZE     0x28
#define CONTROL_INFO_BASE           0x40040000
#define RATE_MASK	                0x7F
#endif
