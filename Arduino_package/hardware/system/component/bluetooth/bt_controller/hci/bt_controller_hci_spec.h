#ifndef BT_CONTROLLER_HCI_SPEC_H
#define BT_CONTROLLER_HCI_SPEC_H

#include <bt_controller_addr.h>

#define BT_HCI_VERSION_1_0                      0
#define BT_HCI_VERSION_1_1                      1
#define BT_HCI_VERSION_1_2                      2
#define BT_HCI_VERSION_2_0                      3
#define BT_HCI_VERSION_2_1                      4
#define BT_HCI_VERSION_3_0                      5
#define BT_HCI_VERSION_4_0                      6
#define BT_HCI_VERSION_4_1                      7
#define BT_HCI_VERSION_4_2                      8
#define BT_HCI_VERSION_5_0                      9
#define BT_HCI_VERSION_5_1                      10
#define BT_HCI_VERSION_5_2                      11
#define BT_HCI_VERSION_5_3                      12
#define BT_HCI_VERSION_5_4                      13
#define BT_HCI_VERSION_6_0                      14

#define BT_HCI_H4_NONE                                          0x00    /* None of the known packet types */
#define BT_HCI_H4_CMD                                           0x01    /* HCI Command packet */
#define BT_HCI_H4_ACL                                           0x02    /* HCI ACL Data packet */
#define BT_HCI_H4_SCO                                           0x03    /* HCI Synchronous Data packet */
#define BT_HCI_H4_EVT                                           0x04    /* HCI Event packet */
#define BT_HCI_H4_ISO                                           0x05    /* HCI ISO Data packet */

/*============================= Error Codes =============================*/
#define BT_HCI_ERROR_SUCCESS                                    0x00
#define BT_HCI_ERROR_UNKNOWN_COMMAND                            0x01
#define BT_HCI_ERROR_HARDWARE_FAILURE                           0x03
#define BT_HCI_EERROR_CONNECTION_TIMEOUT                        0x08
#define BT_HCI_ERROR_CMD_DISALLOWED                             0x0C
#define BT_HCI_ERROR_CMD_INVALID_PARAMETERS                     0x12
#define BT_HCI_ERROR_UNSPECIFIC                                 0x1F
#define BT_HCI_ERROR_LL_RESPONSE_TIMEOUT                        0x22
#define BT_HCI_ERROR_LL_PORCEDURE_COLLISION                     0x23
#define BT_HCI_ERROR_LMP_PDU_NOT_ALLOWED                        0x24
#define BT_HCI_ERROR_INSTANT_PASSED                             0x28
#define BT_HCI_ERROR_DIFFERENT_TRANSACTION_COLLISION            0x2A
#define BT_HCI_ERROR_CONNECTION_FAILED_TO_ESTABLISH             0x3E


/*============================ HCI SUPPORTED COMMANDS DEFINE ===================*/
/*Reference core specification v6.0 */
#define COMMAND_00_HCI_INQUIRY                                                      BIT0
#define COMMAND_00_HCI_INQUIRY_CANCEL                                               BIT1
#define COMMAND_00_HCI_PERIODIC_INQUIRY_MODE                                        BIT2
#define COMMAND_00_HCI_EXIT_PERIODIC_INGUIRY_MODE                                   BIT3
#define COMMAND_00_HCI_CREATE_CONNECTION                                            BIT4
#define COMMAND_00_HCI_DISCONNECT                                                   BIT5
#define COMMAND_00_HCI_CREATE_CONNECTION_CANCEL                                     BIT7

#define COMMAND_01_HCI_ACCEPT_CONNECTION_REQUEST                                    BIT0
#define COMMAND_01_HCI_REJECT_CONNECTION_REQUEST                                    BIT1
#define COMMAND_01_HCI_LINK_KEY_REQUEST_REPLY                                       BIT2
#define COMMAND_01_HCI_LINK_KEY_REQUEST_NEGATIVE_REPLY                              BIT3
#define COMMAND_01_HCI_PIN_CODE_REQUSET_REPLY                                       BIT4
#define COMMAND_01_HCI_PIN_CODE_REQUSET_NEGATIVE_REPLY                              BIT5
#define COMMAND_01_HCI_CHANGE_CONNECTION_PACKET_TYPE                                BIT6
#define COMMAND_01_HCI_AUTHENTICATION_REQUEST                                       BIT7

#define COMMAND_02_HCI_SET_CONNECTION_ENCRYPTION                                    BIT0
#define COMMAND_02_HCI_CHANGE_CONNECTION_LINK_KEY                                   BIT1
#define COMMAND_02_HCI_LINK_KEY_SELECTION                                           BIT2
#define COMMAND_02_HCI_REMOTE_NAME_REQUEST                                          BIT3
#define COMMAND_02_HCI_REMOTE_NAME_REQUEST_CANCEL                                   BIT4
#define COMMAND_02_HCI_READ_REMOTE_SUPPORTED_FEATURES                               BIT5
#define COMMAND_02_HCI_READ_REMOTE_EXTENDED_FEATURES                                BIT6
#define COMMAND_02_HCI_READ_REMOTE_VERSION_INFORMATION                              BIT7

#define COMMAND_03_HCI_READ_CLOCK_OFFSET                                            BIT0
#define COMMAND_03_HCI_READ_LMP_HANDLE                                              BIT1

#define COMMAND_04_HCI_HOLD_MODE                                                    BIT1
#define COMMAND_04_HCI_SNIFF_MODE                                                   BIT2
#define COMMAND_04_HCI_EXIT_SNIFF_MODE                                              BIT3
#define COMMAND_04_HCI_QOS_SETUP                                                    BIT6
#define COMMAND_04_HCI_ROLE_DISCOVERY                                               BIT7

#define COMMAND_05_HCI_SWITCH_ROLE                                                  BIT0
#define COMMAND_05_HCI_READ_LINK_POLICY_SETTINGS                                    BIT1
#define COMMAND_05_HCI_WRITE_LINK_POLICY_SETTINGS                                   BIT2
#define COMMAND_05_HCI_READ_DEFAULT_LINK_POLICY_SETTINGS                            BIT3
#define COMMAND_05_HCI_WRITE_DEFAULT_LINK_POLICY_SETTINGS                           BIT4
#define COMMAND_05_HCI_FLOW_SPECIFICATION                                           BIT5
#define COMMAND_05_HCI_SET_EVENT_MASK                                               BIT6
#define COMMAND_05_HCI_RESET                                                        BIT7

#define COMMAND_06_HCI_SET_EVENT_FILTER                                             BIT0
#define COMMAND_06_HCI_FLUSH                                                        BIT1
#define COMMAND_06_HCI_READ_PIN_TYPE                                                BIT2
#define COMMAND_06_HCI_WRITE_PIN_TYPE                                               BIT3
#define COMMAND_06_HCI_READ_STORED_LINK_KEY                                         BIT5
#define COMMAND_06_HCI_WRITE_STORED_LINK_KEY                                        BIT6
#define COMMAND_06_HCI_DELETE_STORED_LINK_KEY                                       BIT7

#define COMMAND_07_HCI_WRITE_LOCAL_NAME                                             BIT0
#define COMMAND_07_HCI_READ_LOCAL_NAME                                              BIT1
#define COMMAND_07_HCI_READ_CONNECTION_ACCEPT_TIMEOUT                               BIT2
#define COMMAND_07_HCI_WRITE_CONNECTION_ACCEPT_TIMEOUT                              BIT3
#define COMMAND_07_HCI_READ_PAGE_TIMEOUT                                            BIT4
#define COMMAND_07_HCI_WRITE_PAGE_TIMEOUT                                           BIT5
#define COMMAND_07_HCI_READ_SCAN_ENABLE                                             BIT6
#define COMMAND_07_HCI_WRITE_SCAN_ENABLE                                            BIT7

#define COMMAND_08_HCI_READ_PAGE_SCAN_ACTIVITY                                      BIT0
#define COMMAND_08_HCI_WRITE_PAGE_SCAN_ACTIVITY                                     BIT1
#define COMMAND_08_HCI_READ_INQUIRY_SCAN_ACTIVITY                                   BIT2
#define COMMAND_08_HCI_WRITE_INQUIRY_SCAN_ACTIVITY                                  BIT3
#define COMMAND_08_HCI_READ_AUTHENTICATION_ENABLE                                   BIT4
#define COMMAND_08_HCI_WRITE_AUTHENTICATION_ENABLE                                  BIT5

#define COMMAND_09_HCI_READ_CLASS_OF_DEVICE                                         BIT0
#define COMMAND_09_HCI_WRITE_CLASS_OF_DEVICE                                        BIT1
#define COMMAND_09_HCI_READ_VOICE_SETTING                                           BIT2
#define COMMAND_09_HCI_WRITE_VOICE_SETTING                                          BIT3
#define COMMAND_09_HCI_READ_AUTOMATIC_FLUSH_TIMEOUT                                 BIT4
#define COMMAND_09_HCI_WRITE_AUTOMATIC_FLUSH_TIMEOUT                                BIT5
#define COMMAND_09_HCI_READ_NUM_BROADCAST_RETRANSMISSIONS                           BIT6
#define COMMAND_09_HCI_WRITE_NUM_BROADCAST_RETRANSMISSIONS                          BIT7

#define COMMAND_10_HCI_READ_HOLD_MODE_ACTIVITY                                      BIT0
#define COMMAND_10_HCI_WRITE_HOLD_MODE_ACTIVITY                                     BIT1
#define COMMAND_10_HCI_READ_TRANSMIT_POWER_LEVEL                                    BIT2
#define COMMAND_10_HCI_READ_SYCHRONOUS_FLOW_CONTROL_ENABLE                          BIT3
#define COMMAND_10_HCI_WRITE_SYCHRONOUS_FLOW_CONTROL_ENABLE                         BIT4
#define COMMAND_10_HCI_SET_CONTROLLER_TO_HOST_FLOW_CONTROL                          BIT5
#define COMMAND_10_HCI_HOST_BUFFER_SIZE                                             BIT6
#define COMMAND_10_HCI_HOST_NUMBER_OF_COMPLETED_PACKETS                             BIT7

#define COMMAND_11_HCI_READ_LINK_SUPERVISION_TIMEOUT                                BIT0
#define COMMAND_11_HCI_WRITE_LINK_SUPERVISION_TIMEOUT                               BIT1
#define COMMAND_11_HCI_READ_NUMBER_OF_SUPPORTED_IAC                                 BIT2
#define COMMAND_11_HCI_READ_CURRENT_IAC_LAP                                         BIT3
#define COMMAND_11_HCI_WRITE_CURRENT_IAC_LAP                                        BIT4

#define COMMAND_12_HCI_SET_AFH_HOST_CHANNEL_CLASSIFICATION                          BIT1
#define COMMAND_12_HCI_LE_CS_READ_REMOTE_FAE_TABLE                                  BIT2
#define COMMAND_12_HCI_LE_CS_WRITE_CACHED_REMOTE_FAE_TABLE                          BIT3
#define COMMAND_12_HCI_READ_INQUIRY_SCAN_TYPE                                       BIT4
#define COMMAND_12_HCI_WRITE_INQUIRY_SCAN_TYPE                                      BIT5
#define COMMAND_12_HCI_READ_INQUIRY_MODE                                            BIT6
#define COMMAND_12_HCI_WRITE_INQUIRY_MODE                                           BIT7

#define COMMAND_13_HCI_READ_PAGE_SCAN_TYPE                                          BIT0
#define COMMAND_13_HCI_WRITE_PAGE_SCAN_TYPE                                         BIT1
#define COMMAND_13_HCI_READ_AFH_CHANNEL_ASSESSMENT_MODE                             BIT2
#define COMMAND_13_HCI_WRITE_AFH_CHANNEL_ASSESSMENT_MODE                            BIT3

#define COMMAND_14_HCI_READ_LOCAL_VERSION_INFORMATION                               BIT3
#define COMMAND_14_HCI_READ_LOCAL_SUPPORTED_FEATURES                                BIT5
#define COMMAND_14_HCI_READ_LOCAL_EXTENDED_FEATURES                                 BIT6
#define COMMAND_14_HCI_READ_BUFFER_SIZE                                             BIT7

#define COMMAND_15_HCI_READ_BD_ADDR                                                 BIT1
#define COMMAND_15_HCI_READ_FAILED_CONTACK_COUNTER                                  BIT2
#define COMMAND_15_HCI_RESET_FAILED_CONTACK_COUNTER                                 BIT3
#define COMMAND_15_HCI_READ_LINK_QUALITY                                            BIT4
#define COMMAND_15_HCI_READ_RSSI                                                    BIT5
#define COMMAND_15_HCI_READ_AFH_CHANNEL_MAP                                         BIT6
#define COMMAND_15_HCI_READ_CLOCK                                                   BIT7

#define COMMAND_16_HCI_READ_LOOPBACK_MODE                                           BIT0
#define COMMAND_16_HCI_WRITE_LOOPBACK_MODE                                          BIT1
#define COMMAND_16_HCI_ENABLE_IMPLEMENTATION_UNDERTEST_MODE                         BIT2
#define COMMAND_16_HCI_SETUP_SYNCHRONOUS_CONNECTION_REQUEST                         BIT3
#define COMMAND_16_HCI_ACCEPT_SYNCHRONOUS_CONNECTION_REQUEST                        BIT4
#define COMMAND_16_HCI_REJECT_SYNCHRONOUS_CONNECTION_REQUEST                        BIT5
#define COMMAND_16_HCI_LE_CS_CREATE_CONFIG                                          BIT6
#define COMMAND_16_HCI_LE_CS_REMOVE_CONFIG                                          BIT7

#define COMMAND_17_HCI_READ_EXTENDED_INQUIRY_RESPONSE                               BIT0
#define COMMAND_17_HCI_WRITE_EXTENDED_INQUIRY_RESPONSE                              BIT1
#define COMMAND_17_HCI_REFRESH_ENCRYPTION_KEY                                       BIT2
#define COMMAND_17_HCI_SNIFF_SUBRATING                                              BIT4
#define COMMAND_17_HCI_READ_SIMPLE_PAIRING_MODE                                     BIT5
#define COMMAND_17_HCI_WRITE_SIMPLE_PAIRING_MODE                                    BIT6
#define COMMAND_17_HCI_READ_LOCAL_OOB_DATA                                          BIT7

#define COMMAND_18_HCI_READ_INQUIRY_RESPONSE_TRANSMIT_POWER_LEVEL                   BIT0
#define COMMAND_18_HCI_WRITE_INQUIRY_TRANSMIT_POWER_LEVEL                           BIT1
#define COMMAND_18_HCI_READ_DEFAULT_ERRONEOUS_DATA_REPORTING                        BIT2
#define COMMAND_18_HCI_WRITE_DEFAULT_ERRONEOUS_DATA_REPORTING                       BIT3
#define COMMAND_18_HCI_IO_CAPABILITY_REQUEST_REPLY                                  BIT7

#define COMMAND_19_HCI_USER_CONFIRMATION_REQUEST_REPLY                              BIT0
#define COMMAND_19_HCI_USER_CONFIRMATION_REQUEST_NAEGATIVE_REPLY                    BIT1
#define COMMAND_19_HCI_USER_PASSKEY_REQUEST_REPLY                                   BIT2
#define COMMAND_19_HCI_USER_PASSKEY_REQUEST_NEGATIVE_REPLY                          BIT3
#define COMMAND_19_HCI_REMOTE_OOB_DATA_REQUEST_REPLY                                BIT4
#define COMMAND_19_HCI_WRITE_SIMPLE_PAIRING_DEBUG_MODE                              BIT5
#define COMMAND_19_HCI_ENHANCED_FLUSH                                               BIT6
#define COMMAND_19_HCI_REMOTE_OOB_DATA_REQUEST_NEGATIVE_REPLY                       BIT7

#define COMMAND_20_HCI_SEND_KEYPRESS_NOTIFICATION                                   BIT2
#define COMMAND_20_HCI_IO_CAPABILITY_REQUEST_NEGATIVE_REPLY                         BIT3
#define COMMAND_20_HCI_READ_ENCRYPTION_KEY_SIZE                                     BIT4
#define COMMAND_20_HCI_LE_CS_READ_LOCAL_SUPPORTED_CAPABILITES                       BIT5
#define COMMAND_20_HCI_LE_CS_READ_REMOTE_SUPPORTED_CAPABILITES                      BIT6
#define COMMAND_20_HCI_LE_CS_WRITE_CACHED_REMOTE_SUPPORTED_CAPABILITIES             BIT7

#define COMMAND_22_HCI_SET_EVENT_MASK_PAGE_2                                        BIT2

#define COMMAND_23_HCI_READ_FLOW_CONTROL_MODE                                       BIT0
#define COMMAND_23_HCI_WRITE_FLOW_CONTROL_MODE                                      BIT1
#define COMMAND_23_HCI_READ_DATA_BLOCK_SIZE                                         BIT2
#define COMMAND_23_HCI_LE_CS_TEST                                                   BIT3
#define COMMAND_23_HCI_LE_S_TEST_END                                                BIT4

#define COMMAND_24_HCI_READ_ENHANCED_TRANSMIT_POWER_LEVEL                           BIT0
#define COMMAND_24_HCI_LE_CS_SECURITY_ENABLE                                        BIT1
#define COMMAND_24_HCI_READ_LE_HOST_SUPPORT                                         BIT5
#define COMMAND_24_HCI_WRITE_LE_HOST_SUPPORT                                        BIT6
#define COMMAND_24_HCI_LE_CS_SET_DEFAULT_SETTINGS                                   BIT7

#define COMMAND_25_HCI_LE_SET_EVENT_MASK                                            BIT0
#define COMMAND_25_HCI_LE_READ_BUFFER_SIZE_V1                                       BIT1
#define COMMAND_25_HCI_LE_READ_LOCAL_SUPPORTED_FEATURES_PAGE_0                      BIT2
#define COMMAND_25_HCI_LE_SET_RANDOM_ADDRESS                                        BIT4
#define COMMAND_25_HCI_LE_SET_ADVERTISING_PARAMETERS                                BIT5
#define COMMAND_25_HCI_LE_READ_ADVERTISING_PHYSICAL_CHANNEL_TX_POWER                BIT6
#define COMMAND_25_HCI_LE_SET_ADVERTISING_DATA                                      BIT7

#define COMMAND_26_HCI_LE_SET_RESPONSE_DATA                                         BIT0
#define COMMAND_26_HCI_LE_SET_ADVERTISING_ENABLE                                    BIT1
#define COMMAND_26_HCI_LE_SET_SCAN_PARAMETERS                                       BIT2
#define COMMAND_26_HCI_LE_SET_SCAN_ENABLE                                           BIT3
#define COMMAND_26_HCI_LE_CREATE_CONNECTION                                         BIT4
#define COMMAND_26_HCI_LE_CREATE_CONNECTION_CANCEL                                  BIT5
#define COMMAND_26_HCI_LE_READ_FILTER_ACCEPT_LIST_SIZE                              BIT6
#define COMMAND_26_HCI_LE_CLEAR_FILTER_ACCEPT_LIST                                  BIT7

#define COMMAND_27_HCI_LE_ADD_DEVICE_TO_FILTER_ACCEPT_LIST                          BIT0
#define COMMAND_27_HCI_LE_REMOVE_DEVICE_FROM_FILTER_ACCEPT_LIST                     BIT1
#define COMMAND_27_HCI_LE_CONNECTION_UPDATE                                         BIT2
#define COMMAND_27_HCI_LE_SET_HOST_CHANNEL_CLASSIFICATION                           BIT3
#define COMMAND_27_HCI_LE_READ_CHANNEL_MAP                                          BIT4
#define COMMAND_27_HCI_LE_READ_REMOTE_FEATURES_PAGE_0                               BIT5
#define COMMAND_27_HCI_LE_ENCRYPT                                                   BIT6
#define COMMAND_27_HCI_LE_RAND                                                      BIT7

#define COMMAND_28_HCI_LE_ENABLE_ENCRYPTION                                         BIT0
#define COMMAND_28_HCI_LE_LONG_TERM_KEY_REQUEST_REPLY                               BIT1
#define COMMAND_28_HCI_LE_LONG_TERM_KEY_REQUEST_NEGATIVE_REPLY                      BIT2
#define COMMAND_28_HCI_LE_READ_SUPPORTED_STATES                                     BIT3
#define COMMAND_28_HCI_LE_RECEIVER_TEST_V1                                          BIT4
#define COMMAND_28_HCI_LE_TRANSMITTER_TEST_V1                                       BIT5
#define COMMAND_28_HCI_LE_TEST_END                                                  BIT6
#define COMMAND_28_HCI_LE_ENABLE_MONITORING_ADVERTISER                              BIT7

#define COMMAND_29_HCI_LE_CS_SET_CHANNEL_CLASSIFICATION                             BIT0
#define COMMAND_29_HCI_LE_CS_SET_PROCEDURE_PARAMETERS                               BIT1
#define COMMAND_29_HCI_LE_CS_PROCEDURE_ENABLE                                       BIT2
#define COMMAND_29_HCI_ENHANCED_SETUP_SYNCHRONOUS_CONNECTION                        BIT3
#define COMMAND_29_HCI_ENHANCED_ACCEPT_SYNCHRONOUS_CONNECTION                       BIT4
#define COMMAND_29_HCI_READ_LOCAL_SUPPORTED_CODEC_V1                                BIT5
#define COMMAND_29_HCI_SET_MWS_CHANNEL_PARAMETERS                                   BIT6
#define COMMAND_29_HCI_SET_EXTERNAL_FRAME_CONFIGURATION                             BIT7

#define COMMAND_30_HCI_SET_MWS_SIGNALING                                            BIT0
#define COMMAND_30_HCI_SET_MWS_TRANSPORT_LAYER                                      BIT1
#define COMMAND_30_HCI_SET_MWS_SCAN_FREQUENCY_TABLE                                 BIT2
#define COMMAND_30_HCI_GET_MWS_TRANSPORT_LAYER_CONFIGURATION                        BIT3
#define COMMAND_30_HCI_SET_MWS_PATTERN_CONFIGURATION                                BIT4
#define COMMAND_30_HCI_SET_TRIGGERED_CLOCK_CAPTURE                                  BIT5
#define COMMAND_30_HCI_TRUNCATED_PAGE                                               BIT6
#define COMMAND_30_HCI_TRUNCATED_PAGE_CANCEL                                        BIT7

#define COMMAND_31_HCI_SET_CONNECTIONLESS_PERIPHERAL_BROADCAST                      BIT0
#define COMMAND_31_HCI_SET_CONNECTIONLESS_PERIPHERAL_BROADCAST_RECEIVE              BIT1
#define COMMAND_31_HCI_START_SYNCHRONIZATION_TRAIN                                  BIT2
#define COMMAND_31_HCI_RECEIVE_SYNCHRONIZATION_TRAIN                                BIT3
#define COMMAND_31_HCI_SET_RESERVED_LT_ADDR                                         BIT4
#define COMMAND_31_HCI_DELETE_RESERVED_LT_ADDR                                      BIT5
#define COMMAND_31_HCI_SET_CONNECTIONLESS_PERIPHERAL_BROADCAST_DATA                 BIT6
#define COMMAND_31_HCI_READ_SYNCHRONIZATION_TRAIN_PARAMETERS                        BIT7

#define COMMAND_32_HCI_WRITE_SYCHRONIZATION_TRAIN_PARAMETERS                        BIT0
#define COMMAND_32_HCI_REMOTE_OOB_EXTENDED_DATA_REQUEST_REPLY                       BIT1
#define COMMAND_32_HCI_READ_SECURE_CONNECTIONS_HOST_SUPPORT                         BIT2
#define COMMAND_32_HCI_WRITE_SECURE_CONNECTIONS_HOST_SUPPORT                        BIT3
#define COMMAND_32_HCI_READ_AUTHENTICATED_PAYLOAD_TIMEOUT                           BIT4
#define COMMAND_32_HCI_WRITE_AUTHENTICATED_PAYLOAD_TIMEOUT                          BIT5
#define COMMAND_32_HCI_READ_LOCAL_OOB_EXTENDED_DATA                                 BIT6
#define COMMAND_32_HCI_WRITE_SECURE_CONNECTIONS_TEST_MODE                           BIT7

#define COMMAND_33_HCI_READ_EXTENDED_PAGE_TIMEOUT                                   BIT0
#define COMMAND_33_HCI_WRITE_EXTENDED_PAGE_TIMEOUT                                  BIT1
#define COMMAND_33_HCI_READ_EXTENDED_INQUIRY_LENGTH                                 BIT2
#define COMMAND_33_HCI_WRITE_EXTENDED_INQUIRT_LENGTH                                BIT3
#define COMMAND_33_HCI_LE_REMOTE_CONNECTION_PARAMETER_REQUEST_REPLY                 BIT4
#define COMMAND_33_HCI_LE_REMOTE_CONNECTION_PATRAMETER_REQUEST_NEGATIVE_REPLY       BIT5
#define COMMAND_33_HCI_LE_SET_DATA_LENGTH                                           BIT6
#define COMMAND_33_HCI_LE_READ_SUGGESTED_DEFAULT_DATA_LENGTH                        BIT7

#define COMMAND_34_HCI_LE_WRITE_SUGGESTED_DEFAULT_DATA_LENGTH                       BIT0
#define COMMAND_34_HCI_LE_READ_LOCAL_P_256_PUBLIC_KEY                               BIT1
#define COMMAND_34_HCI_LE_GENERATE_DHKEY_V1                                         BIT2
#define COMMAND_34_HCI_LE_ADD_DEVICE_TO_RESOLVING_LIST                              BIT3
#define COMMAND_34_HCI_LE_REMOVE_DEVICE_FROM_RESOLVING_LIST                         BIT4
#define COMMAND_34_HCI_LE_CLEAR_RESOLVING_LIST                                      BIT5
#define COMMAND_34_HCI_LE_READ_RESOLVING_LIST_SIZE                                  BIT6
#define COMMAND_34_HCI_LE_READ_PEER_RESOLVABLE_ADDRESS                              BIT7

#define COMMAND_35_HCI_LE_READ_LOCAL_RESOLVABLE_ADDRESS                             BIT0
#define COMMAND_35_HCI_LE_SET_ADDRESS_RESOLUTION_ENABLE                             BIT1
#define COMMAND_35_HCI_LE_SET_RESOLUABLE_PRIVATE_ADDRESS_TIMEOUT                    BIT2
#define COMMAND_35_HCI_LE_READ_MAXIMUM_DATA_LENGTH                                  BIT3
#define COMMAND_35_HCI_LE_READ_PH                                                   BIT4
#define COMMAND_35_HCI_LE_SET_DEFAULT_PHY                                           BIT5
#define COMMAND_35_HCI_LE_SET_PHY                                                   BIT6
#define COMMAND_35_HCI_LE_RECEIVER_TEST_V2                                          BIT7

#define COMMAND_36_HCI_LE_TRANSMITTER_TEST_V2                                       BIT0
#define COMMAND_36_HCI_LE_SET_ADVERTISING_SET_RANDOM_ADDRESS                        BIT1
#define COMMAND_36_HCI_LE_SET_EXTENDED_ADVERTISING_PARAMETER_V1                     BIT2
#define COMMAND_36_HCI_LE_SET_EXTENDED_ADVERTISING_DATA                             BIT3
#define COMMAND_36_HCI_LE_SET_EXTENDED_SCAN_RESPONSE_DATA                           BIT4
#define COMMAND_36_HCI_LE_SET_EXTENDED_ADVERTISING_ENABLE                           BIT5
#define COMMAND_36_HCI_LE_READ_MAXIMUM_ADVERTISING_DATA_LENGTH                      BIT6
#define COMMAND_36_HCI_LE_READ_NUMBER_OF_SUPPORT_ADVERTISING_SET                    BIT7

#define COMMAND_37_HCI_LE_REMOVE_ADVERTISING_SET                                    BIT0
#define COMMAND_37_HCI_LE_CLEAR_ADVERTISING_SET                                     BIT1
#define COMMAND_37_HCI_LE_SET_PERIODIC_ADVERTISING_PARAMETER_V1                     BIT2
#define COMMAND_37_HCI_LE_SET_PERIODIC_ADVERTISING_DATA                             BIT3
#define COMMAND_37_HCI_LE_SET_PERIODIC_ADVERTISING_ENABLE                           BIT4
#define COMMAND_37_HCI_LE_SET_EXTENDED_SCAN_PARAMETERS                              BIT5
#define COMMAND_37_HCI_LE_SET_EXTENDED_SCAN_ENABLE                                  BIT6
#define COMMAND_37_HCI_LE_EXTENDED_CREATE_CONNECTION_V1                             BIT7

#define COMMAND_38_HCI_LE_PERIODIC_ADVERTISING_CREATE_SYNC                          BIT0
#define COMMAND_38_HCI_LE_PERIODIC_ADVERTISING_CREATE_SYNC_CANCEL                   BIT1
#define COMMAND_38_HCI_LE_PERIODIC_ADVERTISING_TERMINATE_SYNC                       BIT2
#define COMMAND_38_HCI_LE_ADD_DEVICE_TO_PERIODIC_ADVERTISING_LIST                   BIT3
#define COMMAND_38_HCI_LE_REMOVE_DEVICE_FROM_PERIODIC_ADVERTISER_LIST               BIT4
#define COMMAND_38_HCI_LE_CLEAR_PERIODIC_ADVERTISER_LIST                            BIT5
#define COMMAND_38_HCI_LE_READ_PERIODIC_ADVERTISER_LIST_SIZE                        BIT6
#define COMMAND_38_HCI_LE_READ_TRANSMIT_POWER                                       BIT7

#define COMMAND_39_HCI_LE_READ_RF_COMPENSATION                                      BIT0
#define COMMAND_39_HCI_LE_WRITE_RF_COMPENSATION                                     BIT1
#define COMMAND_39_HCI_LE_SET_PRIVACY_MODE                                          BIT2
#define COMMAND_39_HCI_LE_RECEIVE_TEST_V3                                           BIT3
#define COMMAND_39_HCI_LE_TRANSMIT_TEST_V3                                          BIT4
#define COMMAND_39_HCI_LE_SET_CONNECTIONLESS_CTE_TRANSMIT_PARAMETERS                BIT5
#define COMMAND_39_HCI_LE_SET_CONNECTIONLESS_CTE_TRANSMIT_ENABLE                    BIT6
#define COMMAND_39_HCI_LE_SET_CONNECTIONLESS_IQ_SAMPLING_ENABLE                     BIT7

#define COMMAND_40_HCI_LE_SET_CONNECTION_CTE_RECEIVE_PARAMETERS                     BIT0
#define COMMAND_40_HCI_LE_SET_CONNECTION_CTE_TRANSMIT_PARAMETERS                    BIT1
#define COMMAND_40_HCI_LE_CONNECTION_CTE_REQUEST_ENABLE                             BIT2
#define COMMAND_40_HCI_LE_CONNECTION_CTE_RESPONSE_ENABLE                            BIT3
#define COMMAND_40_HCI_LE_READ_ANTENNA_INFORMATION                                  BIT4
#define COMMAND_40_HCI_LE_SET_PERIODIC_ADVERTISING_RECEIVE_ENABLE                   BIT5
#define COMMAND_40_HCI_LE_PERIODIC_ADVERTISING_SYNC_TRANSFER                        BIT6
#define COMMAND_40_HCI_LE_PERIODIC_ADVERTISING_SET_INFO_TRANSFER                    BIT7

#define COMMAND_41_HCI_LE_SET_PERIODIC_ADVERTISING_SYNC_TRANSFER_PARAMETERS         BIT0
#define COMMAND_41_HCI_LE_SET_DEFAULT_PERIODIC_ADVERTISING_SYNC_TRANSFER_PARAMETERS BIT1
#define COMMAND_41_HCI_LE_GENERATE_DHKEY_V2                                         BIT2
#define COMMAND_41_HCI_READ_LOCAL_SIMPLE_PAIRING_OPTIONS                            BIT3
#define COMMAND_41_HCI_LE_MODIFY_SLEEP_CLOCK_ACCURACY                               BIT4
#define COMMAND_41_HCI_LE_READ_BUFFER_SIZE_V2                                       BIT5
#define COMMAND_41_HCI_LE_READ_ISO_TX_SYNC                                          BIT6
#define COMMAND_41_HCI_LE_SET_CIG_PARAMETERS                                        BIT7

#define COMMAND_42_HCI_LE_SET_CIG_PARAMETERS_TEST                                   BIT0
#define COMMAND_42_HCI_LE_CREATE_CIS                                                BIT1
#define COMMAND_42_HCI_LE_REMOVE_CIG                                                BIT2
#define COMMAND_42_HCI_LE_ACCEPT_CIS_REQUEST                                        BIT3
#define COMMAND_42_HCI_LE_REJECT_CIS_REQUEST                                        BIT4
#define COMMAND_42_HCI_LE_CREATE_BIG                                                BIT5
#define COMMAND_42_HCI_LE_CREATE_BIG_TEST                                           BIT6
#define COMMAND_42_HCI_LE_TERMINATE_BIG                                             BIT7

#define COMMAND_43_HCI_BIG_CREATE_SYNC                                              BIT0
#define COMMAND_43_HCI_LE_BIG_TERMINATE_SYNC                                        BIT1
#define COMMAND_43_HCI_LE_REQUEST_PEER_SCA                                          BIT2
#define COMMAND_43_HCI_LE_SETUP_ISO_DATA_PATH                                       BIT3
#define COMMAND_43_HCI_LE_REMOVE_ISO_DATA_PATH                                      BIT4
#define COMMAND_43_HCI_LE_ISO_TRANSMIT_TEST                                         BIT5
#define COMMAND_43_HCI_LE_ISO_RECEIVE_TEST                                          BIT6
#define COMMAND_43_HCI_LE_ISO_READ_TEST_COUNTERS                                    BIT7

#define COMMAND_44_HCI_LE_ISO_TEST_END                                              BIT0
#define COMMAND_44_HCI_LE_SET_HOST_FEATURE_V1                                       BIT1
#define COMMAND_44_HCI_LE_READ_ISO_LINK_QUALITY                                     BIT2
#define COMMAND_44_HCI_LE_ENHANCED_READ_TRANSMIT_POWER_LEVEL                        BIT3
#define COMMAND_44_HCI_LE_READ_REMOTE_TRANSMIT_POWER_LEVEL                          BIT4
#define COMMAND_44_HCI_LE_SET_PATH_LOSS_REPORTING_PARAMETERS                        BIT5
#define COMMAND_44_HCI_LE_SET_PATH_LOSS_REPORTING_ENABLE                            BIT6
#define COMMAND_44_HCI_LE_SET_TRANSMIT_POWER_REPORTING_ENABLE                       BIT7

#define COMMAND_45_HCI_LE_TRANSMITTER_TEST_V4                                       BIT0
#define COMMAND_45_HCI_SET_ECOSYSTEM_BASE_INTERVAL                                  BIT1
#define COMMAND_45_HCI_READ_LOCAL_SUPPORTED_CODECS_V2                               BIT2
#define COMMAND_45_HCI_READ_LOCAL_SUPPORTED_CODEC_CAPALITIES                        BIT3
#define COMMAND_45_HCI_READ_LOCAL_SUPPORTED_CONTROLLER_DELAY                        BIT4
#define COMMAND_45_HCI_CONFIGURE_DATA_PATH                                          BIT5
#define COMMAND_45_HCI_LE_SET_DATA_RELATED_ADDRESS_CHANGES                          BIT6
#define COMMAND_45_HCI_SET_MIN_ENCRYPTION_KEY_SIZE                                  BIT7

#define COMMAND_46_HCI_LE_SET_DEFAULT_SUBRATE_COMMAND                               BIT0
#define COMMAND_46_HCI_LE_SUBRATE_REQUEST_COMMAND                                   BIT1
#define COMMAND_46_HCI_LE_SET_EXTENDED_ADVERTISING_PARAMETERS_V2                    BIT2
#define COMMAND_46_HCI_LE_SET_DECISION_DATA                                         BIT3
#define COMMAND_46_HCI_LE_DECISION_INSTRICTIONS                                     BIT4
#define COMMAND_46_HCI_LE_SET_PERIODIC_ADVERTISING_SIBEVENT_DATA                    BIT5
#define COMMAND_46_HCI_LE_SET_PERIODIC_ADVERTISING_RESPONSE_DATA                    BIT6
#define COMMAND_46_HCI_LE_SET_PERIODIC_SYNC_SUBEVENT                                BIT7

#define COMMAND_47_HCI_LE_EXTENDED_CREATE_CONNECTIONS_V2                            BIT0
#define COMMAND_47_HCI_LE_SET_PERIODIC_ADVERTISING_PARAMETERS_V2                    BIT1
#define COMMAND_47_HCI_LE_READ_ALL_LOCAL_SUPPORTED_FEATURES                         BIT2
#define COMMAND_47_HCI_LE_READ_ALL_REMOTE_FEATURES                                  BIT3
#define COMMAND_47_HCI_LE_SET_HOST_FEATURE_V2                                       BIT4
#define COMMAND_47_HCI_LE_ADD_DEVICE_TO_MONITORED_ADVERTISERS_LIST                  BIT5
#define COMMAND_47_HCI_EL_REMOVE_DEVICE_FROM_MONITORED_ADVERTISERS_LIST             BIT6
#define COMMAND_47_HCI_LE_CLEAR_MONITORED_ADVERTISERS_LIST                          BIT7

#define COMMAND_48_HCI_LE_READ_MONITORED_ADVERTISERS_LIST_SIZE                      BIT0
#define COMMAND_48_HCI_LE_FRAME_SPACE_UPDATE                                        BIT1


//BT 6.0 Spec
#define BT_HCI_LE_EXT_ADV_PROP_CONNECTABLE                                  BIT0
#define BT_HCI_LE_EXT_ADV_PROP_SCANNABLE                                    BIT1
#define BT_HCI_LE_EXT_ADV_PROP_DIRECT                                       BIT2
#define BT_HCI_LE_EXT_ADV_PROP_HIGH_DUTY_DIRECT                             BIT3
#define BT_HCI_LE_EXT_ADV_PROP_LEGACY                                       BIT4
#define BT_HCI_LE_EXT_ADV_PROP_ANONYNOUS                                    BIT5
#define BT_HCI_LE_EXT_ADV_PROP_TX_POWER                                     BIT6
#define BT_HCI_LE_EXT_ADV_PROP_USE_DECISION_PDU                             BIT7
#define BT_HCI_LE_EXT_ADV_PROP_ADVA_DECISION_PDU                            BIT8
#define BT_HCI_LE_EXT_ADV_PROP_ADI_DECISION_PDU                             BIT9



#define BT_OGF(opcode)                                          ((opcode >> 10) & 0x3F)
#define BT_OCF(opcode)                                          ((opcode) & 0x3FF)

#define BT_OP(ogf, ocf)                                         ((ocf) | ((ogf) << 10))

/* Command Group Opcode */
#define BT_OGF_BASEBAND                                         0x03
#define BT_OGF_INFO                                             0x04
#define BT_OGF_LE                                               0x08

//HCI CMD
#define BT_HCI_OP_SET_EVENT_MASK                BT_OP(BT_OGF_BASEBAND, 0x0001) /* 0x0c01 */
struct bt_hci_cp_set_event_mask {
	uint8_t  events[8];
} __attribute__((packed));

#define BT_HCI_OP_RESET                         BT_OP(BT_OGF_BASEBAND, 0x0003) /* 0x0c03 */

#define BT_HCI_OP_READ_LOCAL_VERSION_INFO       BT_OP(BT_OGF_INFO, 0x0001) /* 0x1001 */
struct bt_hci_rp_read_local_version_info {
	uint8_t  status;
	uint8_t  hci_version;
	uint16_t hci_revision;
	uint8_t  lmp_version;
	uint16_t manufacturer;
	uint16_t lmp_subversion;
} __attribute__((packed));

#define BT_HCI_OP_READ_SUPPORTED_COMMANDS       BT_OP(BT_OGF_INFO, 0x0002) /* 0x1002 */
struct bt_hci_rp_read_supported_commands {
	uint8_t  status;
	uint8_t  commands[64];
} __attribute__((packed));

#define BT_HCI_OP_READ_LOCAL_FEATURES           BT_OP(BT_OGF_INFO, 0x0003) /* 0x1003 */
struct bt_hci_rp_read_local_features {
	uint8_t  status;
	uint8_t  features[8];
} __attribute__((packed));

#define BT_HCI_OP_READ_BD_ADDR                  BT_OP(BT_OGF_INFO, 0x0009) /* 0x1009 */
struct bt_hci_rp_read_bd_addr {
	uint8_t   status;
	uint8_t   bdaddr[BT_ADDR_SIZE];
} __attribute__((packed));

#define BT_HCI_OP_LE_SET_EVENT_MASK             BT_OP(BT_OGF_LE, 0x0001) /* 0x2001 */
struct bt_hci_cp_le_set_event_mask {
	uint8_t events[8];
} __attribute__((packed));

#define BT_HCI_OP_LE_READ_BUFFER_SIZE           BT_OP(BT_OGF_LE, 0x0002) /* 0x2002 */
struct bt_hci_rp_le_read_buffer_size {
	uint8_t  status;
	uint16_t le_max_len;
	uint8_t  le_max_num;
} __attribute__((packed));

#define BT_HCI_OP_LE_READ_LOCAL_FEATURES        BT_OP(BT_OGF_LE, 0x0003) /* 0x2003 */
struct bt_hci_rp_le_read_local_features {
	uint8_t  status;
	uint8_t  features[8];
} __attribute__((packed));

#define BT_HCI_OP_LE_SET_ADV_PARAM              BT_OP(BT_OGF_LE, 0x0006) /* 0x2006 */
struct bt_hci_cp_le_set_adv_param {
	uint16_t     min_interval;
	uint16_t     max_interval;
	uint8_t      type;
	uint8_t      own_addr_type;
	struct bt_le_addr_t direct_addr;
	uint8_t      channel_map;
	uint8_t      filter_policy;
} __attribute__((packed));

#define BT_HCI_OP_LE_SET_ADV_DATA               BT_OP(BT_OGF_LE, 0x0008) /* 0x2008 */
struct bt_hci_cp_le_set_adv_data {
	uint8_t  len;
	uint8_t  data[31];
} __attribute__((packed));

#define BT_HCI_OP_LE_SET_SCAN_RSP_DATA          BT_OP(BT_OGF_LE, 0x0009) /* 0x2009 */
struct bt_hci_cp_le_set_scan_rsp_data {
	uint8_t  len;
	uint8_t  data[31];
} __attribute__((packed));

#define BT_HCI_OP_LE_SET_ADV_ENABLE             BT_OP(BT_OGF_LE, 0x000a) /* 0x200a */
struct bt_hci_cp_le_set_adv_enable {
	uint8_t  enable;
} __attribute__((packed));

#define BT_HCI_OP_LE_READ_REMOTE_FEATURES       BT_OP(BT_OGF_LE, 0x0016) /* 0x2016 */
struct bt_hci_cp_le_read_remote_features {
	uint16_t  handle;
} __attribute__((packed));

#define BT_HCI_OP_LE_RAND                       BT_OP(BT_OGF_LE, 0x0018) /* 0x2018 */
struct bt_hci_rp_le_rand {
	uint8_t  status;
	uint8_t  rand[8];
} __attribute__((packed));

#define BT_HCI_OP_LE_READ_RL_SIZE               BT_OP(BT_OGF_LE, 0x002a) /* 0x202a */
struct bt_hci_rp_le_read_rl_size {
	uint8_t  status;
	uint8_t  rl_size;
} __attribute__((packed));

#define BT_HCI_OP_LE_SET_RPA_TIMEOUT            BT_OP(BT_OGF_LE, 0x002e) /* 0x202e */
struct bt_hci_cp_le_set_rpa_timeout {
	uint16_t rpa_timeout;
} __attribute__((packed));

//HCI EVENT
#define BT_HCI_EVT_DISCONNECT_COMPLETE             0x05
struct bt_hci_evt_disconnect_complete {
	uint8_t  status;
	uint16_t handle;
	uint8_t  reason;
} __attribute__((packed));

#define BT_HCI_EVT_CMD_COMPLETE                 0x0E
struct bt_hci_evt_cmd_complete {
	uint8_t  ncmd;
	uint16_t opcode;
} __attribute__((packed));

struct bt_hci_evt_cc_status {
	uint8_t  status;
} __attribute__((packed));

#define BT_HCI_EVT_CMD_STATUS                   0x0F
struct bt_hci_evt_cmd_status {
	uint8_t  status;
	uint8_t  ncmd;
	uint16_t opcode;
} __attribute__((packed));

#define BT_HCI_EVT_LE_META_EVENT                0x3E
struct bt_hci_evt_le_meta_event {
	uint8_t  subevent;
} __attribute__((packed));

#define BT_HCI_EVT_LE_CONNECTION_COMPLETE             0x01
struct bt_hci_evt_le_connnection_complete {
	uint8_t      status;
	uint16_t     handle;
	uint8_t      role;
	struct bt_le_addr_t peer_addr;
	uint16_t     interval;
	uint16_t     latency;
	uint16_t     supversion_timeout;
	uint8_t      clock_accuracy;
} __attribute__((packed));

#define BT_HCI_EVT_LE_ENHANCED_CONNECTION_COMPLETE         0x0A
struct bt_hci_evt_le_enhanced_connection_complete {
	uint8_t      status;
	uint16_t     handle;
	uint8_t      role;
	struct bt_le_addr_t peer_addr;
	uint8_t    local_rpa[BT_ADDR_SIZE];
	uint8_t    peer_rpa[BT_ADDR_SIZE];
	uint16_t     interval;
	uint16_t     latency;
	uint16_t     supversion_timeout;
	uint8_t      clock_accuracy;
} __attribute__((packed));

#endif
