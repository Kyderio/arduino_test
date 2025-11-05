#ifndef _WIFI_SHARE_INFO_H_
#define _WIFI_SHARE_INFO_H_

/*********************** MACRO and STRUCT for txdesc sw_def field, shared by driver and fw *********************************************/
#define SWDEF_DRIVER_USE BIT(7)

//IPC BIT
#define WIFI_MP_PG_TRX_ENABLE		BIT7
#define WIFI_MP_PG_TRX_TEST_MODE	(BIT6|BIT5)

enum mp_pg_trx_mode_sel {
	MP_PG_NORMAL_TRX_TEST = 0,
	MP_PG_BCN_RX_TEST = 1,
	MP_PG_BCN_PCCA_RX_TEST = 2,
};

enum sw_define_func_id {
	MGNT_TX_DONE_RPT				= 0,
	EAPOL4_TX_DONE_RPT				= 2, //TX_DONE_TO_DRV[1] used for keepalive null
	RSVD
};

enum tx_done_polliing_result {
	TX_DONE_SUCCESS				= 0,
	TX_DONE_FAIL,
	TX_DONE_POLLING_TIMEOUT
};

struct shareinfo_txdone_rpt_ctl {
	u8 func_id : 2;
	u8 seq_num : 5;
	u8 driver_use : 1;	//bit7
};
struct shareinfo_txdone_rpt { /*the 4-th layer*/
	u8 seq_num 		: 5;
	u8 rsvd 		: 2;
	u8 tx_status 	: 1;
};

/*********************** MACRO and STRUCT for txrpt address, shared by driver and fw *********************************************/
#define SIZE_TXRPT_1K				1

#if SIZE_TXRPT_1K
#define TXRPT_POINTER_MASK			0x3F
#define TXRPT_START_OFFSET          0x680
#define CTRLINFO_MACID_NUM          32
#else   // TXRPT 2K SIZE
#define TXRPT_POINTER_MASK			0x7F
#define TXRPT_START_OFFSET          0x280
#define CTRLINFO_MACID_NUM          16
#endif

/*********************** MACRO and STRUCT for reserved page, shared by driver and fw *********************************************/

//For General Reserved Page Number(Beacon Queue is reserved page)
#define BCN0_NAN_SYNC_PAGE_NUM  0x02
#define BCN1_SOFTAP_PAGE_NUM    0x04
#define NAN_PAGE_NUM            0x02

//For fw used , more reserved page
//PS-Poll:1,Qos Null Data:1,PS Null Data:1,BT Qos Null Data:1,CSI Trig:1,ARP Rsp:1,CTS2SELF:1,0xFF:unavailable.
#define FW_USED_PAGE_NUM        0x07

/*********************** MACRO and STRUCT for shared reg, shared by driver and fw *********************************************/

/** @defgroup WIFI_BCN_INFO
  * @brief
  * @{
  */
#define BIT_SHARE_INFO_BCN_CCK_RATE(x)         (((u32)((x) & 0x00000001) << 31)) /*!< R/W  1: CCK rate */
#define BIT_GET_SHARE_INFO_BCN_CCK_RATE(x)     ((u32)(((x >> 31) & 0x00000001)))
#define BIT_SHARE_INFO_BCN_LEN(x)              (((u32)((x) & 0x0000FFFF) << 0)) /*!< R/W BCN length */
#define BIT_GET_SHARE_INFO_BCN_LEN(x)          ((u32)(((x >> 0) & 0x0000FFFF)))
#define BIT_SHARE_INFO_AP_TIM_OFFSET(x)        (((u32)((x) & 0x00007FFF) << 16)) /*!< BCN TIM IE offset */
#define BIT_GET_SHARE_INFO_AP_TIM_OFFSET(x)    ((u32)(((x >> 16) & 0x00007FFF)))
/** @} */

typedef struct {
	__IO uint32_t RECV_RSSI;		/*!<  Register,  Address offset: 0x050 */
	__IO uint16_t FA_CCK_OFDM[2];		/*!<  Register,  Address offset: 0x054 */
	__IO uint32_t REG_WIFI_0x58;		/*!<  Register,  Address offset: 0x058 */
	__IO uint8_t  TX_DONE_TO_DRV[4];	/*!<  Register,  Address offset: 0x05C. Array sort by function id. */
	__IO uint32_t REG_WIFI_0x60;		/*!<  Register,  Address offset: 0x060 */
	__IO uint16_t TX_DONE_TO_APP[2];	/*!<  Register,  Address offset: 0x064 */
	__IO uint8_t  MAC_AUTO_LPS[4];		/*!<  Reserved,  Address offset: 0x068. MAC_AUTO_LPS[3] is used for enable/disable MAC LPS. */
	__IO uint32_t REG_WIFI_0x6C;		/*!<  Reserved,  Address offset: 0x06C */
	__IO uint32_t REG_CANNOT_USE1[5];	/*!<  REG CANNOT USE,  Address offset: 0x070 ~ 0x80 */
	__IO uint32_t REG_WIFI_0x84;		/*!<  Register,  Address offset: 0x084 */
	__IO uint32_t WIFI_BCN_INFO;		/*!<  Register,  Address offset: 0x088. BIT(31) is used to indicate CCK rate. */
	__IO uint32_t REG_WIFI_0x8C;		/*!<  Register,  Address offset: 0x08C */
	__IO uint32_t REG_CANNOT_USE2;		/*!<  REG CANNOT USE,  Address offset: 0x090 */
	__IO uint32_t REG_WIFI_0x94;		/*!<  Register,  Address offset: 0x094 */
	__IO uint32_t REG_CANNOT_USE3[72];	/*!<  REG CANNOT USE,  Address offset: 0x098 ~ 0x1B4 */
	__IO uint32_t REG_WIFI_0x1B8;		/*!<  Register,  Address offset: 0x1B8 */
	__IO uint32_t REG_WIFI_0x1BC;		/*!<  Register,  Address offset: 0x1BC */
	__IO uint32_t REG_WIFI_0x1C0;		/*!<  Register,  Address offset: 0x1C0 */
	__IO uint8_t  FW_RSVD[2];			/*!<  Register,  Address offset: 0x1C4 ~ 0x1C5 */
	__IO uint8_t  BCN_RX_CNT;		/*!<  Register,  Address offset: 0x1C6 */
	__IO uint8_t  WOW_WAKE_REASON;		/*!<  Register,  Address offset: 0x1C7 */
	__IO uint32_t REG_CANNOT_USE4[974];	/*!<  REG CANNOT USE,  Address offset: 0x1C8 ~ 0x10FC */
	__IO uint32_t PG_POWER_MARK;		/*!<  Register,  Address offset: 0x1100 */
	__IO uint32_t REG_WIFI_0x1104;		/*!<  Register,  Address offset: 0x1104 */
	__IO uint8_t  PKT_IV_TXPN[8];		/*!<  Register,  Address offset: 0x1108 ~ 0x110C, total for 64 bytes. */
} WIFI_SHARE_INFO_BASE;

#define FA_CCK_IDX	0
#define FA_OFDM_IDX	1

#define WIFI_SHARE_INFO ((WIFI_SHARE_INFO_BASE *) (WIFI_REG_BASE + 0x50))

#endif /* _WIFI_SHARE_INFO_H_ */
