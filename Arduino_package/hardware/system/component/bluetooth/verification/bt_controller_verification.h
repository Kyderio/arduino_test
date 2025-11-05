#ifndef BT_CONTROLLER_VERIFICATION_H
#define BT_CONTROLLER_VERIFICATION_H

#include <basic_types.h>
#include <osif.h>
#include <bt_debug.h>
#include <ameba.h>
#include <stdio.h>
#include <string.h>



#define BT_CONTROLLER_VERIFICATION_PREAMBLE_SIZE                    1
#define BT_CONTROLLER_VERIFICATION_ACCESS_ADDRESS_SIZE              4
#define BT_CONTROLLER_VERIFICATION_PDU_HEADER_SIZE                  2
#define BT_CONTROLLER_VERIFICATION_ADV_CHNL_PDU_PAYLOAD_MAX_SIZE    37
#define BT_CONTROLLER_VERIFICATION_CRC_SIZE                         3

#define BT_CONTROLLER_VERIFICATION_ADV_CHNL_PKT_MAX_SIZE            (BT_CONTROLLER_VERIFICATION_PREAMBLE_SIZE +  \
                                                                     BT_CONTROLLER_VERIFICATION_ACCESS_ADDRESS_SIZE + \
                                                                     BT_CONTROLLER_VERIFICATION_PDU_HEADER_SIZE + \
                                                                     BT_CONTROLLER_VERIFICATION_ADV_CHNL_PDU_PAYLOAD_MAX_SIZE)

#define BT_CONTROLLER_VERIFICATION_ADDR_SIZE                        6

#define BT_CONTROLLER_VERIFICATION_ADV_CHNL_BASE_SIZE               (BT_CONTROLLER_VERIFICATION_PREAMBLE_SIZE +  \
                                                                     BT_CONTROLLER_VERIFICATION_ACCESS_ADDRESS_SIZE + \
                                                                     BT_CONTROLLER_VERIFICATION_PDU_HEADER_SIZE + \
                                                                     BT_CONTROLLER_VERIFICATION_ADDR_SIZE)

#define BT_CONTROLLER_VERIFICATION_SCAN_REQ_PDU_SIZE                12
#define BT_CONTROLLER_VERIFICATION_SCAN_REQ_PKT_SIZE                (BT_CONTROLLER_VERIFICATION_PREAMBLE_SIZE + \
                                                                     BT_CONTROLLER_VERIFICATION_ACCESS_ADDRESS_SIZE + \
                                                                     BT_CONTROLLER_VERIFICATION_PDU_HEADER_SIZE + \
                                                                     BT_CONTROLLER_VERIFICATION_SCAN_REQ_PDU_SIZE)


#define BT_CONTROLLER_VERIFICATION_PREPARE_EVENT_TIME_US            (625)
#define BT_CONTROLLER_VERIFICATION_PROCEDURE_PREPARE_TIME_US        5000
#define BT_CONTROLLER_VERIFICATION_TIFS_US                          150

#define BT_CONTROLLER_VERIFICATION_ADV_RX_WIN                       (BT_RF_SHORT_READY_TIME_US + 20)

#define BT_CONTROLLER_VERIFICATION_ADV_INTERVAL_US                  62500

#define BT_CONTROLLER_VERIFICATION_US_TO_CNT(us)                    ((us) << 2)

#define BT_CONTROLLER_VERIFICATION_RX_DESCRIPTOR_SIZE               8

#define BT_CONTROLLER_VERIFICATION_SCAN_WINDOW_US                   60000
#define BT_CONTROLLER_VERIFICATION_SCAN_INTERVAL                    100000



void bt_controller_verification_freerun_timer_test(void);
void bt_controller_verification_unconn_ind_test(void);
void bt_controller_verification_conn_ind_test(void);
void bt_controller_verification_scan_test(void);

void bt_controller_verification_adv_chnl_set_fec_cfg(void);
void bt_controller_verification_adv_chnl_update_rf_info(uint8_t chnl_idx, uint8_t txgain);

uint8_t bt_controller_verification_construct_adv_pkt(uint8_t *pkt, uint8_t pdu_type);
bool bt_controller_verification_check_scan_req(uint8_t *pkt, uint32_t *instant);
uint8_t bt_controller_verification_construct_scan_req_pkt(uint8_t *pkt, uint8_t *padv_addr);
uint8_t *bt_controller_verification_check_adv_pkt(uint8_t *pkt, uint32_t *instant, uint8_t *pdu_type);

#endif