/**
 * Copyright (c) 2018 - 2022, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/* PURPOSE: Header to combine osif dependent files with stack
*/

#ifndef ZB_OSIF_PLATFORM_H__
#define ZB_OSIF_PLATFORM_H__

#define ZB_INTERRUPT_SAFE_CALLBACKS
#define ZB_USE_NVRAM
#define ZB_NVRAM_RADIO_OFF_DURING_TRANSACTION

/* trace */
#ifdef ZB_TRACE_LEVEL
#define ZB_BINARY_TRACE
#ifdef ZB_BINARY_TRACE
#define ZB_HAVE_SERIAL_SINGLE
#endif
#define ZB_TRACE_OVER_USART
#define ZB_TRACE_TO_PORT
#define ZB_TRAFFIC_DUMP_ON
#define ZB_TRAF_DUMP_V2
#endif  /* ZB_TRACE_LEVEL */

#if defined ZB_TRACE_OVER_USART && defined ZB_TRACE_LEVEL
//#define ZB_SERIAL_FOR_TRACE
#endif /* ZB_TRACE_OVER_USART && ZB_TRACE_LEVEL */

#ifdef ZB_SERIAL_FOR_TRACE
void zb_osif_serial_flush(void);
#if defined CONFIG_ZB_ASYNC_TRACE_CONTROL || defined ZB_MULTI_TEST
#define ZB_OSIF_SERIAL_FLUSH()          zb_osif_serial_flush()
#else /* CONFIG_ZB_ASYNC_TRACE_CONTROL || defined ZB_MULTI_TEST */
#define ZB_OSIF_SERIAL_FLUSH()
#endif /* CONFIG_ZB_ASYNC_TRACE_CONTROL || defined ZB_MULTI_TEST */
#else /* ZB_SERIAL_FOR_TRACE */
#define ZB_OSIF_SERIAL_FLUSH()
#endif /* ZB_SERIAL_FOR_TRACE */


#define ZB_SOFT_SECURITY
#define ZB_HW_ZB_AES128

#ifdef ZB_HW_ZB_AES128
void zb_osif_aes128_hw_encrypt(zb_uint8_t *key, zb_uint8_t *msg, zb_uint8_t *c);
#define hw_aes128                       zb_osif_aes128_hw_encrypt
#endif /* ZB_HW_ZB_AES128 */


void zb_osif_init(void);
#define ZB_PLATFORM_INIT()              zb_osif_init()

void zb_osif_abort(void);
#define ZB_ABORT                        zb_osif_abort

#define ZB_GO_IDLE()

/* Read the NCP firmware version. This function may be redefined by the application. */
zb_uint32_t zb_osif_get_fw_version(void);
#define NCP_FW_VERSION                  zb_osif_get_fw_version()

/* Read the ZBOSS stack version in NCP firmware. This value is defined in zb_vendor.h. */
#define NCP_STACK_VERSION               ZB_STACK_VERSION

/* Read the NCP protocol version. This function may be redefined by the application. */
zb_uint32_t zb_osif_get_ncp_protocol_version(void);
#define NCP_PROTOCOL_VERSION            zb_osif_get_ncp_protocol_version()


void zb_osif_timer_init(void);
zb_uint32_t zb_osif_timer_get(void);

void zb_osif_timer_stop(void);
#define ZB_STOP_HW_TIMER()              zb_osif_timer_stop()

void zb_osif_timer_start(void);
#define ZB_START_HW_TIMER()             zb_osif_timer_start()

zb_bool_t zb_osif_timer_is_on(void);
#define ZB_CHECK_TIMER_IS_ON()          zb_osif_timer_is_on()


void zb_osif_enable_all_inter(void);
void zb_osif_disable_all_inter(void);

#ifdef ZB_STACK_REGRESSION_TESTING_API

#define ZB_ENABLE_ALL_INTER()                          \
  ZB_REGRESSION_TESTS_API().osif_interrupts_balance++; \
  zb_osif_enable_all_inter()
#define ZB_DISABLE_ALL_INTER()                         \
  ZB_REGRESSION_TESTS_API().osif_interrupts_balance--; \
  zb_osif_disable_all_inter()

#else /* ZB_STACK_REGRESSION_TESTING_API */

#define ZB_ENABLE_ALL_INTER()           zb_osif_enable_all_inter()
#define ZB_DISABLE_ALL_INTER()          zb_osif_disable_all_inter()

#endif  /* ZB_STACK_REGRESSION_TESTING_API */

#define ZB_OSIF_GLOBAL_LOCK()           ZB_DISABLE_ALL_INTER()
#define ZB_OSIF_GLOBAL_UNLOCK()         ZB_ENABLE_ALL_INTER()


#ifdef ZB_USE_SLEEP
void zb_osif_sleep_init(void);
zb_uint32_t zb_osif_sleep(zb_uint32_t sleep_tmo);
zb_bool_t zb_osif_is_sleeping(void);
#endif /* ZB_USE_SLEEP */



#ifdef ZB_MACSPLIT_TRANSPORT_USERIAL
#define ZB_TRANSPORT_NONBLOCK_ITERATION() (zb_macsplit_transport_recv_bytes(),0)
#else /* ZB_MACSPLIT_TRANSPORT_USERIAL */
#define ZB_TRANSPORT_NONBLOCK_ITERATION() 0
#endif /* ZB_MACSPLIT_TRANSPORT_USERIAL */


#ifdef CONFIG_ZB_HAVE_SERIAL
#define ZB_HAVE_SERIAL
#define ZB_HAVE_ASYNC_SERIAL
#endif  /* CONFIG_ZB_HAVE_SERIAL */

#ifdef CONFIG_ZB_USE_LEDS
#define ZB_USE_LEDS
#define ZB_N_LEDS 4
#endif /* CONFIG_ZB_USE_LEDS */

#ifdef CONFIG_ZB_USE_DIMMABLE_LED
#define ZB_USE_DIMMABLE_LED
#endif /* CONFIG_ZB_USE_DIMMABLE_LED */

#ifdef CONFIG_ZB_USE_BUTTONS
#define ZB_USE_BUTTONS
#define ZB_N_BUTTONS 4
#endif /* CONFIG_ZB_USE_BUTTONS */


/** @addtogroup special_nordic_functions
 * @{
 */

/**
 * @brief Read IEEE long address from FICR registers.
 *
 * @param[out] ieee_eui64  Pointer to a long address structure to be filled.
 * 								@cond NORDIC_NCS_SPECIAL_FUNCTIONS
 * 								This structure is filled with the EUI-64 assigned by Nordic Semiconductor. Refer to the Configuring Zigbee in nRF Connect SDK ("IEEE 802.15.4 EUI-64 configuration" section) if you want to change it.
 * 								@endcond
 * 								@cond NORDIC_NRF5_SPECIAL_FUNCTIONS
 * 								The 24 oldest bits are filled in by the ZIGBEE_VENDOR_OUI macro and the remainder is taken from the FICR register.
 * 								@endcond
 */
void zb_osif_get_ieee_eui64(zb_ieee_addr_t ieee_eui64);

/**@brief Function which waits for event -- essential implementation of sleep on NRF52
 */
void zb_osif_wait_for_event(void);

/**@brief Function which tries to sleep down the MCU
 *
 * Function is defined as weak; to be redefined if someone wants to implement their own
 * going-to-sleep policy.
 */
void zb_osif_go_idle(void);

/**@brief Function which disables all Zigbee stack-related peripherals
 *
 * Function is defined as weak; to be redefined if someone wants to implement their own
 * going-to-deep-sleep policy/share resources between Zigbee stack and other components.
 */
void zb_osif_periph_disable(void);

/**@brief Function which enables back all Zigbee stack-related peripherals
 *
 * Function is defined as weak; to be redefined if someone wants to implement their own
 * going-to-deep-sleep policy/share resources between Zigbee stack and other components.
 */
void zb_osif_periph_enable(void);

/**@brief Function which tries to put the device into deep sleep mode, caused by an empty Zigbee stack scheduler queue.
 *
 * Function is defined as weak; to be redefined if someone wants to implement their own
 * going-to-deep-sleep policy.
 */
zb_uint32_t zb_osif_sleep(zb_uint32_t sleep_tmo);

/**@brief Function which is called after zb_osif_sleep
 *        finished and ZBOSS timer is reenabled.
 *
 * Function is defined as weak; to be redefined if someone
 * wants to implement their own going-to-deep-sleep policy/share resources
 * between Zigbee stack and other components.
 */
void zb_osif_wake_up(void);

/**
 * @}
 */

#endif /* ZB_OSIF_PLATFORM_H__ */
