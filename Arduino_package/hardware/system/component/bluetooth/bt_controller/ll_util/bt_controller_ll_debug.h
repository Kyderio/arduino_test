#ifndef BT_CONTROLLER_LL_DEBUG_H
#define BT_CONTROLLER_LL_DEBUG_H

#include <basic_types.h>
#include <osif.h>
#include <bt_debug.h>
#include <ameba.h>
#include <stdio.h>
#include <string.h>

#define BT_CONTROLLER_DUMP_TIME_ENABLE                              1
#define BT_CONTROLLER_DUMP_MAX_CNT                                  30

#define BT_CONTROLLER_DUMP_ADV_EVENT                                0
#define BT_CONTROLLER_DUMP_TX_TARGET                                1
#define BT_CONTROLLER_DUMP_RX_TARGET                                2
#define BT_CONTROLLER_DUMP_ISR_START                                3
#define BT_CONTROLLER_DUMP_ISR_END                                  4
#define BT_CONTROLLER_DUMP_SCAN_EVENT                               5
#define BT_CONTROLLER_DUMP_RXDMA_OK                                 6
#define BT_CONTROLLER_DUMP_RX_FAIL                                  7
#define BT_CONTROLLER_DUMP_CANCEL_RX                                8
#define BT_CONTROLLER_DUMP_RX_TIMEOUT                               9
#define BT_CONTROLLER_DUMP_TX_OK                                    10
#define BT_CONTROLLER_DUMP_TX_FAIL                                  11
#define BT_CONTROLLER_DUMP_TX_CANCEL                                12
#define BT_CONTROLLER_DUMP_ISR                                      13
#define BT_CONTROLLER_DUMP_RX_PKT                                   14
#define BT_CONTROLLER_DUMP_CHANNEL                                  15

#define BT_CONTROLLER_DUMP_LOOP_CNT                                 10

void bt_controller_verification_dump_param(uint8_t type, uint32_t param);
void bt_controller_verification_dump_pkt(uint8_t *pkt);
void bt_controller_verification_debug(void);
void bt_controller_scan_dump_pkt(void);
#endif