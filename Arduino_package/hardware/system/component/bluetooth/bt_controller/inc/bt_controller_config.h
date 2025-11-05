#ifndef BT_CONTROLLER_CONFIG_H
#define BT_CONTROLLER_CONFIG_H

//BT LL Version
#define BT_LL_VERSION                                               BT_CONTROLLER_CONFIG_LL_VERSION
#define BT_LL_HCI_REVISION                                          BT_CONTROLLER_CONFIG_LL_HCI_REVISION
#define BT_LL_LMP_SUB_VERSION                                       BT_CONTROLLER_CONFIG_LL_LMP_SUB_VERSION
#define BT_LL_COMPANY_ID                                            0x005D

//HCI Configuration
#define BT_LL_HCI_CMD_NUM                                           BT_CONTROLLER_CONFIG_HCI_CMD_NUM
#define BT_LL_HCI_CMD_SIZE                                          256

#define BT_LL_HCI_EVT_NUM                                           BT_CONTROLLER_CONFIG_HCI_EVENT_NUM
#define BT_LL_HCI_EVT_SIZE                                          256

#define BT_LL_ACL_DATA_TX_NUM                                       BT_CONTROLLER_CONFIG_ACL_DATA_TX_NUM
#define BT_LL_ACL_DATA_SIZE                                         BT_CONTROLLER_CONFIG_ACL_DATA_SIZE

#define BT_LL_ACL_DATA_RX_NUM                                       BT_CONTROLLER_CONFIG_ACL_DATA_RX_NUM


//Scheduler Configuration
#define BT_LL_SCHE_MAX_PROCEDURE_NUM                                BT_CONTROLLER_CONFIG_MAX_PROCEDURE_NUM


//Thread Priority
#define BT_CONTROLLER_PRIORITY_LOW                                  3
#define BT_CONTROLLER_PRIORITY_MIDDLE                               4
#define BT_CONTROLLER_PRIORITY_HIGH                                 5

//LL Configuration
#if (BT_LL_FEATURE_BT50_LE_EXT_ADV == 1)
#define BT_LL_LE_ADV_SET_NUM                                        BT_CONTROLLER_CONFIG_LE_EXT_ADV_MAX_SET
#else
#define BT_LL_LE_ADV_SET_NUM                                        1
#endif

#if (BT_LL_FEATURE_BT42_LE_LINK_LAYER_PRIVACY == 1)
#define BT_LL_LE_RESOLVING_LIST_SIZE                                 16
#else
#define BT_LL_LE_RESOLVING_LIST_SIZE                                0
#endif
#define BT_LL_LE_MAX_CONN_NUM                                       BT_CONTROLLER_CONFIG_LE_MAX_CONN_NUM

#define BT_LL_LE_ACL_DATA_TOTAL_NUM                                 (BT_CONTROLLER_CONFIG_LE_ACL_DATA_MAX_NUM_PER_LINK * BT_CONTROLLER_CONFIG_LE_MAX_CONN_NUM)

#define BT_LL_LE_CTRL_CTX_MAX_NUM_PER_LINK                          BT_CONTROLLER_CONFIG_LE_CTRL_CTX_MAX_MUM_PER_LINK
#endif