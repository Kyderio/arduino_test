#ifndef BT_CONTROLLER_LL_LE_H
#define BT_CONTROLLER_LL_LE_H

#include <bt_controller_ll_le_phy.h>
#include <bt_controller_ll_le_adv.h>
#include <bt_controller_ll_le_llcp.h>
#include <bt_controller_ll_le_conn.h>
#include <bt_controller_ll_le_peripheral.h>
#include <bt_controller_ll_le_chan.h>

#define BT_LL_LE_FEATURE_ENCRYPTION                             BIT0
#define BT_LL_LE_FEATURE_CONN_PARA_REQ_PROCEDURE                BIT1
#define BT_LL_LE_FEATURE_EXT_REJECT_IND                         BIT2
#define BT_LL_LE_FEATURE_PERIPHERAL_INIT_FEATURE_EXCHANGE       BIT3
#define BT_LL_LE_FEATURE_LE_PING                                BIT4
#define BT_LL_LE_FEATURE_LE_DATA_LENGTH_EXTENSION               BIT5
#define BT_LL_LE_FEATURE_LL_PRIVACY                             BIT6
#define BT_LL_LE_FEATURE_EXT_SCAN_FILTER_POLICY                 BIT7
#define BT_LL_LE_FEATURE_LE_2M_PHY                              BIT8
#define BT_LL_LE_FEATURE_STABLE_MODULATION_INDEX_TX             BIT9
#define BT_LL_LE_FEATURE_STABLE_MODULATION_INDEX_RX             BIT10
#define BT_LL_LE_FEATURE_LE_CODED_PHY                           BIT11
#define BT_LL_LE_FEATURE_LE_EXTENDED_ADV                        BIT12
#define BT_LL_LE_FEATURE_LE_PERIODIC_ADV                        BIT13
#define BT_LL_LE_FEATURE_LE_CHANNEL_SEL_2                       BIT14
#define BT_LL_LE_FEATURE_LE_POWER_CLASS_1                       BIT15
#define BT_LL_LE_FEATURE_MIN_NUM_USED_CHANNEL                   BIT16
#define BT_LL_LE_FEATURE_CONNECTION_CTE_REQUEST                 BIT17
#define BT_LL_LE_FEATURE_CONNECTION_CTE_RESPONSE                BIT18
#define BT_LL_LE_FEATURE_CONNECTIONLESS_CTE_TRANSMITTER         BIT19
#define BT_LL_LE_FEATURE_CONNECTIONLESS_CTE_RECEIVER            BIT20
#define BT_LL_LE_FEATURE_ANTENNA_SWITCH_AOD                     BIT21
#define BT_LL_LE_FEATURE_ANTENNA_SWITCH_AOA                     BIT22
#define BT_LL_LE_FEATURE_RECEIVE_CTE                            BIT23
#define BT_LL_LE_FEATURE_PAST_SENDER                            BIT24
#define BT_LL_LE_FEATURE_PAST_RECEIVER                          BIT25
#define BT_LL_LE_FEATURE_SLEEP_CLOCK_ACCURANCY_UPDATE           BIT26
#define BT_LL_LE_FEATURE_REMOTE_PUBLIC_KEY_VALIDATION           BIT27
#define BT_LL_LE_FEATURE_CIS_CENTRAL                            BIT28
#define BT_LL_LE_FEATURE_CIS_PERIPHERAL                         BIT29
#define BT_LL_LE_FEATURE_ISO_BROADCASTER                        BIT30
#define BT_LL_LE_FEATURE_SYNCHRONIZED_RECEIVER                  BIT31
#define BT_LL_LE_FEATURE_CIS_HOST_SUPPORT                       ((1 << 32) | BIT0)
#define BT_LL_LE_FEATURE_LE_POWER_CONTROL_REQUEST               ((1 << 32) | BIT1)
#define BT_LL_LE_FEATURE_LE_POWER_CONTROL_RESPONSE              ((1 << 32) | BIT2)
#define BT_LL_LE_FEATURE_LE_PATH_LOSS_MONITORING                ((1 << 32) | BIT3)
#define BT_LL_LE_FEATURE_LE_PA_ADI_SUPPORT                      ((1 << 32) | BIT4)
#define BT_LL_LE_FEATURE_CONNECTION_SUBRATING                   ((1 << 32) | BIT5)
#define BT_LL_LE_FEATURE_CONNECTION_SUBRATING_HOST_SUPPORT      ((1 << 32) | BIT6)
#define BT_LL_LE_FEATURE_CHANNEL_CLASSIFICATION                 ((1 << 32) | BIT7)
#define BT_LL_LE_FEATURE_ADV_CODING_SEL                         ((1 << 32) | BIT8)
#define BT_LL_LE_FEATURE_ADV_CODING_SEL_HOST_SUPPORT            ((1 << 32) | BIT9)
#define BT_LL_LE_FEATURE_PAWR_ADVERTISER                        ((1 << 32) | BIT11)
#define BT_LL_LE_FEATURE_PAWR_SCANNER                           ((1 << 32) | BIT12)

#define BT_LL_LE_FEATURE_MASK_FROM_PEER                         0x00000FEFF787CF2F
#define BT_LL_LE_FEATURE_BIT_MASK                               0xFFFFFFFFFFFFFFFF
#define BT_LL_LE_FEATURE_BIT_MASK_WITHOUT_BYTE0                 0xFFFFFFFFFFFFFF00
#define BT_LL_LE_FEATURE_HOST_MASK                              (BT_LL_LE_FEATURE_CIS_HOST_SUPPORT | BT_LL_LE_FEATURE_CONNECTION_SUBRATING_HOST_SUPPORT | BT_LL_LE_FEATURE_ADV_CODING_SEL_HOST_SUPPORT)


struct bt_controller_ll_le_manager {
	struct bt_controller_ll_le_adv_manager adv_manager;
	struct bt_controller_ll_le_conn_manger conn_manger;
	uint64_t feature_local;
};


bool bt_controller_ll_le_init(void);
void bt_controller_ll_le_reset(void);

#endif