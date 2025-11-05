#ifndef RTK_802154_RADIO_H__
#define RTK_802154_RADIO_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include <ameba_soc.h>

#ifndef RTK_802154_HOST_IPC
#define RTK_802154_HOST_IPC 0
#endif
#ifndef RTK_802154_RADIO_IPC
#define RTK_802154_RADIO_IPC 0
#endif

#if RTK_802154_HOST_IPC || RTK_802154_RADIO_IPC
#ifdef CONFIG_AMEBASMART
#define RTK_802154_RADIO_IPC_HOST_TO_RADIO		IPC_NP_TO_AP
#define RTK_802154_RADIO_IPC_RADIO_TO_HOST		IPC_AP_TO_NP
#define RTK_802154_RADIO_IPC_HOST_TO_RADIO_CHAN		IPC_N2A_802154_TRAN
#define RTK_802154_RADIO_IPC_RADIO_TO_HOST_CHAN		IPC_A2N_802154_TRAN
#elif defined(CONFIG_AMEBALITE)
#define RTK_802154_RADIO_IPC_HOST_TO_RADIO		IPC_KM4_TO_DSP
#define RTK_802154_RADIO_IPC_RADIO_TO_HOST		IPC_DSP_TO_KM4
#define RTK_802154_RADIO_IPC_HOST_TO_RADIO_CHAN		IPC_M2D_802154_TRAN
#define RTK_802154_RADIO_IPC_RADIO_TO_HOST_CHAN		IPC_D2M_802154_TRAN
#else
#error "undefine 802154 radio IPC!!!!!!!!!!!"
#endif
#endif

#define RTK_802154_RADIO_COEX_PTA			0
#define RTK_802154_RADIO_COEX_CONCURRENT_RX 0
#define RTK_802154_RADIO_COEX_TDMA 			0
#define RTK_802154_RADIO_TASK_CTL_TDMA_INSTEAD_OF_IRQ        1

#if RTK_802154_RADIO_COEX_CONCURRENT_RX
#define RX_AGC_DONE_WORKAROUND 1  // need 802154 on first
#define RX_WORKAROUND_BY_DEBUG_PORT 1  // on when RTK_802154_RADIO_COEX_CONCURRENT_RX = 1
#else
#define RX_AGC_DONE_WORKAROUND 0
#define RX_WORKAROUND_BY_DEBUG_PORT 0
#endif

#define RTK_802154_RADIO_MP_INCLUDE			1
#define RTK_802154_RADIO_TX_CCA_CHECK_EDCCA 1
#define RTK_802154_RADIO_EDCCA_DECTECT_TIME	128
#define RTK_802154_RADIO_INVALID_DBM_VALUE	(-127)
#define RTK_802154_RADIO_MIN_ED_DBM_VALUE	(RTK_802154_RADIO_RECEIVE_SENSITIVITY - 10)
#define RTK_802154_RADIO_RX_INFO_ENABLE		1
/*only three cases:
RTK_802154_HOST_IPC 1 RTK_802154_RADIO_IPC 0, 802154 host ipc make, like amebalite km4
RTK_802154_HOST_IPC 0 RTK_802154_RADIO_IPC 1, 802154 radio ipc make, like amebalite hifi5
RTK_802154_HOST_IPC 0 RTK_802154_RADIO_IPC 0, like amebasmart ca32
*/
#if RTK_802154_HOST_IPC && RTK_802154_RADIO_IPC
#error "can't define RTK_802154_HOST_IPC and RTK_802154_RADIO_IPC as 1 at the same time!!!!!"
#endif

#if RTK_802154_HOST_IPC || RTK_802154_RADIO_IPC
#if !defined(RTK_802154_RADIO_IPC_HOST_TO_RADIO)\
	|| !defined(RTK_802154_RADIO_IPC_RADIO_TO_HOST)\
	|| !defined(RTK_802154_RADIO_IPC_HOST_TO_RADIO_CHAN)\
	|| !defined(RTK_802154_RADIO_IPC_RADIO_TO_HOST_CHAN)
#error "undefine 802154 radio IPC!!!!!!!!!!!"
#endif
#endif

#define RADIO_RX_DATA_DUMP 0
#define RX_RESET_TIME_DEBUG 0
#define MEASURE_RX_IPC_TIME 0
#define MEASURE_TX_ACK_TIME 0
#define MEASURE_TMDA_TIME 0
#define MEASURE_RX_ACK_WAIT_TIME_AFTER_TX 0
#if RTK_802154_RADIO_IPC
#define RADIO_TASK_PRIORITY (configMAX_PRIORITIES - 3)
#else
#define RADIO_TASK_PRIORITY (configMAX_PRIORITIES - 1)
#endif
#define RADIO_ACK_REQUEST_OFFSET           1         //< Byte containing the ACK request bit (+1 for the frame length byte).
#define RADIO_ACK_REQUEST_BIT              (1 << 5)  //< ACK request bit.
#define RADIO_FRAME_TYPE_OFFSET            1               //< Byte containing the frame type bits (+1 for the frame length byte).
#define RADIO_FRAME_TYPE_MASK              0x07            //< Mask of bits containing the frame type.
#define RADIO_FRAME_TYPE_ACK               0x02            //< Bits containing the ACK frame type.

/* Dtime from rtk_802154_radio_callback_handler to rtk_802154_radio_tx_frame 114-150 in ipc mode*/

/** @brief RADIO Clear Channel Assessment modes. */
typedef enum {
	RTK_802154_RADIO_CCA_MODE_ED             = 0,           /**< Energy Above Threshold. Will report busy whenever energy is detected above set threshold. */
	RTK_802154_RADIO_CCA_MODE_CARRIER,      /**< Carrier Seen. Will report busy whenever compliant IEEE 802.15.4 signal is seen. */
	RTK_802154_RADIO_CCA_MODE_CARRIER_AND_ED, /**< Energy Above Threshold AND Carrier Seen. */
	RTK_802154_RADIO_CCA_MODE_CARRIER_OR_ED,  /**< Energy Above Threshold OR Carrier Seen. */
	RTK_802154_RADIO_CCA_MODE_ED_TEST1,      /**< Energy Above Threshold test mode that will abort when first ED measurement over threshold is seen. No averaging. */
} rtk_802154_radio_cca_mode_t;

/** @brief RADIO task steps. */
typedef enum {
	RTK_802154_RADIO_TASK_STEP_INVALID,
	RTK_802154_RADIO_TASK_TX_STEP_PTA,
	RTK_802154_RADIO_TASK_TX_STEP_CCA,
	RTK_802154_RADIO_TASK_TX_STEP_TX,
	RTK_802154_RADIO_TASK_TX_STEP_SUCCESS,
	RTK_802154_RADIO_TASK_RX_STEP_CCA,
	RTK_802154_RADIO_TASK_RX_STEP_RX,
	RTK_802154_RADIO_TASK_RX_STEP_RX_START,
	RTK_802154_RADIO_TASK_RX_STEP_CRC_ERROR,
	RTK_802154_RADIO_TASK_RX_STEP_CRC_OK,
	RTK_802154_RADIO_TASK_CCA_STEP_END,
	RTK_802154_RADIO_TASK_ED_STEP_END,

	RTK_802154_RADIO_TASK_SLOT_SWITCH,
} rtk_802154_radio_task_setp_t;

/** @brief RADIO ctl ID. */
typedef enum {
	//radio task ctl
	RTK_802154_RADIO_FUNC_TASK_INVALID,
	RTK_802154_RADIO_FUNC_TASK_TERMINATE,/*set as 1 used in ipc*/
	RTK_802154_RADIO_FUNC_TX_EN,
	RTK_802154_RADIO_FUNC_CCA_TX_EN,
	RTK_802154_RADIO_FUNC_TX_ACK_EN,
	RTK_802154_RADIO_FUNC_RX_EN,
	RTK_802154_RADIO_FUNC_RX_ACK_EN,
	RTK_802154_RADIO_FUNC_RSSI_EN,
	RTK_802154_RADIO_FUNC_CCA_EN,
	RTK_802154_RADIO_FUNC_ED_EN,
	RTK_802154_RADIO_FUNC_CONTINUOUS_CARRIER_EN,
	RTK_802154_RADIO_FUNC_MP_TX_EN,
	RTK_802154_RADIO_FUNC_MP_RX_EN,
	RTK_802154_RADIO_FUNC_MP_RX_EN_2,//used for mp rx simulate normal rx, will hal_radio_rx_start/stop every receive
	RTK_802154_RADIO_FUNC_SLEEP_EN,

	//radio func
	RTK_802154_RADIO_FUNC_CHANNEL_SET,
	RTK_802154_RADIO_FUNC_BANDWIDTH_SET,
	RTK_802154_RADIO_FUNC_TXPOWER_SET,
	RTK_802154_RADIO_FUNC_RSSI_GET,
	RTK_802154_RADIO_FUNC_RX_PROCESSING_GET,
	RTK_802154_RADIO_FUNC_CCA_CONFIGURE,
	RTK_802154_RADIO_FUNC_RADIO_ON,
	RTK_802154_RADIO_FUNC_RADIO_OFF,
	RTK_802154_RADIO_FUNC_RADIO_INIT,
	RTK_802154_RADIO_FUNC_RADIO_DEINIT,
} rtk_802154_radio_func_t;

/* total 128 byte, last two byte used for lqi and used flag
	byte0 byte1......byte126,byte127
	len,  .. .....   crc,    crc
->  len,  .. .....   lqi,    rssi	*/

#if RTK_802154_RADIO_MP_INCLUDE
typedef struct rtk_802154_radio_mp {
	uint32_t tx_pkt_cnt;//total tx pkt cnt, continus: 0
	uint32_t tx_pkt_num;//the num of pkt has been transmitted
	uint32_t tx_pkt_len;//max 127 + 2(crc)
	uint32_t tx_psdu_type;
	uint32_t tx_pkt_intv;
	uint32_t rx_crc_ok_cnt;//total cnt, continus: 0, terminate rx if match
	uint32_t rx_crc_fail_cnt;//total cnt, continus: 0, terminate rx if match
	uint32_t rx_sfd_not_found_cnt;//total cnt, continus: 0, terminate rx if match
	uint32_t rx_len_illegal_cnt;//total cnt, continus: 0, terminate rx if match
	uint32_t rx_cca_cnt;//total cnt, continus: 0, terminate rx if match
	uint8_t tx_payload[128];//127 + 1(length)
} rtk_802154_radio_mp_t;
extern rtk_802154_radio_mp_t rtk_802154_radio_mp_obj;
#endif

typedef struct rtk_802154_radio_ctl {
	volatile uint8_t *tx_packet;
	uint8_t *rx_packet;
	volatile uint32_t ed_time;
	volatile rtk_802154_radio_func_t radio_task_ctl;
	volatile rtk_802154_radio_func_t radio_task_state;
#if	RTK_802154_RADIO_COEX_PTA
	rtk_802154_radio_func_t radio_coex_expected_next_task_ctl;
#endif
	volatile uint8_t channel;
#if !RTK_802154_RADIO_RX_INFO_ENABLE
	volatile uint8_t radio_rx_processing: 1;
#endif
}
rtk_802154_radio_ctl_t;
#if	RTK_802154_RADIO_COEX_TDMA
extern volatile bool g_radio_coex_tdma_wpan_slot;
#endif

void rtk_802154_radio_task_terminate(void);
void rtk_802154_radio_task_enable(rtk_802154_radio_func_t radio_func);
void rtk_802154_radio_tx_enable(rtk_802154_radio_func_t radio_func, uint8_t *pkt_ptr);
void rtk_802154_radio_ed_enable(rtk_802154_radio_func_t radio_func, uint32_t time_us);
void rtk_802154_radio_channel_set(uint8_t channel);
void rtk_802154_radio_bw_set(uint8_t bw);
void rtk_802154_radio_cca_configure(void);
void rtk_802154_radio_txpower_set(int8_t txpower);
int8_t rtk_802154_radio_rssi_value_get(void);
#if !RTK_802154_RADIO_RX_INFO_ENABLE
bool rtk_802154_radio_rx_processing(void);
#endif
void rtk_802154_radio_on(void);
void rtk_802154_radio_off(void);
void rtk_802154_radio_task_init(void);
void rtk_802154_radio_task_deinit(void);
void rtk_802154_radio_callback_handler(rtk_802154_radio_task_setp_t callback_step, uint32_t data, uint32_t data_len);
bool rtk_802154_radio_task_state_mismatch(rtk_802154_radio_func_t state);
#if RTK_802154_HOST_IPC
uint32_t rtk_802154_radio_func_ipc(rtk_802154_radio_func_t func, uint32_t data, uint32_t data_len);
#else
bool rtk_802154_radio_task_ctl_mismatch(rtk_802154_radio_func_t ctl);
bool rtk_802154_radio_ack_requested(const uint8_t *p_frame);
bool rtk_802154_radio_frame_type_ack(const uint8_t *p_frame);
bool rtk_802154_radio_rx_frame(rtk_802154_radio_func_t radio_func);
bool rtk_802154_radio_tx_cca_check(void);
int8_t rtk_802154_radio_energy_detect(void);
void rtk_802154_radio_tx_frame(rtk_802154_radio_func_t radio_func, uint8_t *tx_frame);
void rtk_802154_radio_rx_start_callback(uint8_t *frame);
/*static void rtk_802154_radio_rssi_task(rtk_802154_radio_func_t radio_func);
static void rtk_802154_radio_cca_task(rtk_802154_radio_func_t radio_func);
static void rtk_802154_radio_continuous_carrier_task(rtk_802154_radio_func_t radio_func);
static void rtk_802154_radio_ed_task(rtk_802154_radio_func_t radio_func);
static void rtk_802154_radio_sleep_task(rtk_802154_radio_func_t radio_func);
static void rtk_802154_radio_rx_task(rtk_802154_radio_func_t radio_func);
static void rtk_802154_radio_mp_tx_task(rtk_802154_radio_func_t radio_func);
static void rtk_802154_radio_tx_task(rtk_802154_radio_func_t radio_func);*/
void rtk_802154_radio_task_entry(void *param);
#endif
#if !RTK_802154_HOST_IPC
#ifdef CONFIG_AMEBASMART
//amebasmart wpan mac core RTC timer #define TIMER10_REG_BASE         0x4100A400 /*!< TIM COUNTER Register,  Address offset: 0x14 */
#define RTK_802154_RADIO_RTC_TIMER_COUNT_REG 0x4100A414
//amebasmart wpan mac core RTC timer #define TIMER10_REG_BASE         0x4100A400 /*!< TIM AUTO-RELOAD REGISTER,  Address offset: 0x1C */
#define RTK_802154_RADIO_RTC_TIMER_RELOAD_REG 0x4100A41C
#elif defined(CONFIG_AMEBALITE)
//amebalite wpan mac core RTC timer #define TIMER10_REG_BASE         0x41019400 /*!< TIM COUNTER Register,  Address offset: 0x14 */
#define RTK_802154_RADIO_RTC_TIMER_COUNT_REG 0x41019414
//amebalite wpan mac core RTC timer #define TIMER10_REG_BASE         0x41019400 /*!< TIM AUTO-RELOAD REGISTER,  Address offset: 0x1C */
#define RTK_802154_RADIO_RTC_TIMER_RELOAD_REG 0x4101941C
#else
#error "undefine 802154 radio RTC_TIMER_REG!!!!!!!!!!!"
#endif
extern uint32_t rtc_timer_raload;
static inline uint32_t rtk_802154_radio_timestamp_get(void)
{
	//return (*((volatile uint32_t *)(RTK_802154_RADIO_RTC_TIMER_COUNT_REG)));
	return HAL_READ32(RTK_802154_RADIO_RTC_TIMER_COUNT_REG, 0);
}

static inline uint32_t rtk_802154_radio_timereload_get(void)
{
	//return (*((volatile uint32_t *)(RTK_802154_RADIO_RTC_TIMER_RELOAD_REG)));
	return HAL_READ32(RTK_802154_RADIO_RTC_TIMER_RELOAD_REG, 0);
}

static inline uint32_t rtk_802154_radio_time_duration_us_get(const uint32_t start_timestamp)
{
	//duration must smaller than rtk_802154_radio_timereload_get
	uint32_t duration;
	uint32_t current_timestamp = rtk_802154_radio_timestamp_get();
	if (current_timestamp < start_timestamp) {
		duration = rtc_timer_raload - start_timestamp + current_timestamp;
	} else {
		duration = current_timestamp - start_timestamp;
	}
	return duration;
}
#endif

#if RTK_802154_RADIO_RX_INFO_ENABLE
#ifdef CONFIG_AMEBASMART
//r_zigbee_tx_ok_cnt   0x6F4
//r_zigbee_rx_cca_ok_cnt  0x6F8
#define RTK_802154_RADIO_RX_INFO_REG 0x400106F4
#elif defined(CONFIG_AMEBALITE)
//r_zigbee_tx_ok_cnt   0x6F4
//r_zigbee_rx_cca_ok_cnt  0x6F8
#define RTK_802154_RADIO_RX_INFO_REG 0x400106F4
#else
#error "undefine 802154 radio RX_INFO_REG!!!!!!!!!!!"
#endif
static inline uint32_t rtk_802154_radio_rx_info_get(void)
{
	return HAL_READ32(RTK_802154_RADIO_RX_INFO_REG, 0);
}

static inline uint32_t rtk_802154_radio_rx_info_timestamp_get(void)
{
	return HAL_READ32(RTK_802154_RADIO_RX_INFO_REG, 4);
}

static inline void rtk_802154_radio_rx_info_set(uint32_t data)
{
	HAL_WRITE32(RTK_802154_RADIO_RX_INFO_REG, 0, data);
}

static inline void rtk_802154_radio_rx_info_timestamp_set(uint32_t data)
{
	HAL_WRITE32(RTK_802154_RADIO_RX_INFO_REG, 4, data);
}
#endif
#endif //RTK_802154_RADIO_H__
