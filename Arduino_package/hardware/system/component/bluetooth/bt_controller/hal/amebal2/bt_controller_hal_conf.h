#ifndef BT_CONTROLLER_PLATFORM_CONF_H
#define BT_CONTROLLER_PLATFORM_CONF_H

//HCI Version
#define BT_CONTROLLER_CONFIG_LL_VERSION                         BT_HCI_VERSION_5_4
#define BT_CONTROLLER_CONFIG_LL_HCI_REVISION                    0x000A
#define BT_CONTROLLER_CONFIG_LL_LMP_SUB_VERSION                 0x6955

//Memory Configuration
#define BT_CONTROLLER_CONFIG_HCI_CMD_NUM                        4
#define BT_CONTROLLER_CONFIG_ACL_DATA_TX_NUM                    4

#define BT_CONTROLLER_CONFIG_HCI_EVENT_NUM                      4
#define BT_CONTROLLER_CONFIG_ACL_DATA_RX_NUM                    4

#define BT_CONTROLLER_CONFIG_ACL_DATA_SIZE                      1024


//Scheduler Configuration
#define BT_CONTROLLER_CONFIG_MAX_PROCEDURE_NUM                  10

//Clk Configuration
#define BT_CONTROLLER_CONFIG_SLEEP_CLK_32768                    1


//LL FEATURE Configuration
#define BT_CONTROLLER_CONFIG_LL_FEAT_BT42_LE_DATA_LENGTH_EXTENSION              0
#define BT_CONTROLLER_CONFOG_LL_FEAT_BT42_SECURE_CONNECTION                     1
#define BT_CONTROLLER_CONFIG_LL_FEAT_BT42_LE_LINK_LAYER_PRIVACY                 0
#define BT_CONTROLLER_CONFIG_LL_FEAT_BT42_EXTENDED_SCAN_FILTER_POLICY           0

#define BT_CONTROLLER_CONFIG_LL_FEAT_BT50_LE_2M_PHY                             0
#define BT_CONTROLLER_CONFIG_LL_FEAT_BT50_LE_CODED_PHY                          0
#define BT_CONTROLLER_CONFIG_LL_FEAT_BT50_LE_EXT_ADV                            0
#define BT_CONTROLLER_CONFIG_LL_FEAT_BT50_LE_CHANNEL_SEL_ALOG_2                 0
#define BT_CONTROLLER_CONFIG_LL_FEAT_BT50_LE_PERIODIC_ADV                       0

//LL Configuration
#define BT_CONTROLLER_CONFIG_LE_EXT_ADV_MAX_SET                  3

#ifndef BT_CONTROLLER_CONFIG_LE_ACL_DATA_MAX_NUM_PER_LINK
#define BT_CONTROLLER_CONFIG_LE_ACL_DATA_MAX_NUM_PER_LINK         5
#endif

#ifndef BT_CONTROLLER_CONFIG_LE_MAX_CONN_NUM
#define BT_CONTROLLER_CONFIG_LE_MAX_CONN_NUM                     1
#endif

#ifndef BT_CONTROLLER_CONFIG_LE_CTRL_CTX_MAX_MUM_PER_LINK
#define BT_CONTROLLER_CONFIG_LE_CTRL_CTX_MAX_MUM_PER_LINK                       4
#endif

#endif