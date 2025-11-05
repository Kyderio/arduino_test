
/* PURPOSE: On/off switch device definition
*/
#ifndef ZB_CUS_ON_OFF_SWITCH_H
#define ZB_CUS_ON_OFF_SWITCH_H

#include "zb_ha_device_config.h"
#include "zb_ha_on_off_switch.h"

#define ZB_CUS_ON_OFF_SWITCH_DEVICE_ID        ZB_HA_ON_OFF_SWITCH_DEVICE_ID
#define ZB_CUS_ON_OFF_SWITCH_DEVICE_VER       ZB_HA_DEVICE_VER_ON_OFF_SWITCH
#define ZB_CUS_ON_OFF_SWITCH_IN_CLUSTER_NUM   2 /*!< On/Off switch IN clusters number */
#define ZB_CUS_ON_OFF_SWITCH_OUT_CLUSTER_NUM  2 /*!< On/Off switch OUT clusters number */


#define ZB_CUS_ON_OFF_SWITCH_CLUSTER_NUM                                      \
  (ZB_CUS_ON_OFF_SWITCH_IN_CLUSTER_NUM + ZB_CUS_ON_OFF_SWITCH_OUT_CLUSTER_NUM)


/** @brief Declare cluster list for On/Off switch device
    @param cluster_list_name - cluster list variable name
    @param basic_attr_list - attribute list for Basic cluster
    @param identify_attr_list - attribute list for Identify cluster
 */
#define ZB_CUS_DECLARE_ON_OFF_SWITCH_CLUSTER_LIST(                          \
      cluster_list_name,                                                    \
      basic_attr_list,                                                      \
      identify_attr_list)                                                   \
      zb_zcl_cluster_desc_t cluster_list_name[] =                           \
      {                                                                     \
        ZB_ZCL_CLUSTER_DESC(                                                \
          ZB_ZCL_CLUSTER_ID_IDENTIFY,                                       \
          ZB_ZCL_ARRAY_SIZE(identify_attr_list, zb_zcl_attr_t),             \
          (identify_attr_list),                                             \
          ZB_ZCL_CLUSTER_SERVER_ROLE,                                       \
          ZB_ZCL_MANUF_CODE_INVALID                                         \
        ),                                                                  \
        ZB_ZCL_CLUSTER_DESC(                                                \
          ZB_ZCL_CLUSTER_ID_BASIC,                                          \
          ZB_ZCL_ARRAY_SIZE(basic_attr_list, zb_zcl_attr_t),                \
          (basic_attr_list),                                                \
          ZB_ZCL_CLUSTER_SERVER_ROLE,                                       \
          ZB_ZCL_MANUF_CODE_INVALID                                         \
        ),                                                                  \
        ZB_ZCL_CLUSTER_DESC(                                                \
          ZB_ZCL_CLUSTER_ID_ON_OFF,                                         \
          0,                                                                \
          NULL,                                                             \
          ZB_ZCL_CLUSTER_CLIENT_ROLE,                                       \
          ZB_ZCL_MANUF_CODE_INVALID                                         \
        ),                                                                  \
        ZB_ZCL_CLUSTER_DESC(                                                \
          ZB_ZCL_CLUSTER_ID_IDENTIFY,                                       \
          0,                                                                \
          NULL,                                                             \
          ZB_ZCL_CLUSTER_CLIENT_ROLE,                                       \
          ZB_ZCL_MANUF_CODE_INVALID                                         \
        ),                                                                  \
    }


/** @brief Declare simple descriptor for On/Off switch device
    @param ep_name - endpoint variable name
    @param ep_id - endpoint ID
    @param in_clust_num - number of supported input clusters
    @param out_clust_num - number of supported output clusters
    @note in_clust_num, out_clust_num should be defined by numeric constants, not variables or any
    definitions, because these values are used to form simple descriptor type name
*/
#define ZB_ZCL_DECLARE_ON_OFF_SWITCH_SIMPLE_DESC_CUS(ep_name, ep_id, in_clust_num, out_clust_num) \
  ZB_DECLARE_SIMPLE_DESC(in_clust_num, out_clust_num);                                        \
  ZB_AF_SIMPLE_DESC_TYPE(in_clust_num, out_clust_num) simple_desc_##ep_name =                 \
  {                                                                                           \
    ep_id,                                                                                    \
    ZB_AF_HA_PROFILE_ID,                                                                      \
    ZB_CUS_ON_OFF_SWITCH_DEVICE_ID,                                                           \
    ZB_CUS_ON_OFF_SWITCH_DEVICE_VER,                                                          \
    0,                                                                                        \
    in_clust_num,                                                                             \
    out_clust_num,                                                                            \
    {                                                                                         \
      ZB_ZCL_CLUSTER_ID_BASIC,                                                                \
      ZB_ZCL_CLUSTER_ID_IDENTIFY,                                                             \
      ZB_ZCL_CLUSTER_ID_ON_OFF,                                                               \
      ZB_ZCL_CLUSTER_ID_IDENTIFY,                                                             \
    }                                                                                         \
  }


/** @brief Declare endpoint for On/off Switch device
    @param ep_name - endpoint variable name
    @param ep_id - endpoint ID
    @param cluster_list - endpoint cluster list
 */
#define ZB_CUS_DECLARE_ON_OFF_SWITCH_EP(ep_name, ep_id, cluster_list) \
  ZB_ZCL_DECLARE_ON_OFF_SWITCH_SIMPLE_DESC_CUS(                          \
      ep_name,                                                       \
      ep_id,                                                         \
      ZB_CUS_ON_OFF_SWITCH_IN_CLUSTER_NUM,                           \
      ZB_CUS_ON_OFF_SWITCH_OUT_CLUSTER_NUM);                         \
  ZB_AF_DECLARE_ENDPOINT_DESC(ep_name,                               \
                              ep_id,                                 \
      ZB_AF_HA_PROFILE_ID,                                           \
      0,                                                             \
      NULL,                                                          \
      ZB_ZCL_ARRAY_SIZE(cluster_list, zb_zcl_cluster_desc_t),        \
      cluster_list,                                                  \
      (zb_af_simple_desc_1_1_t*)&simple_desc_##ep_name, \
      0, NULL, /* No reporting ctx */           \
      0, NULL) /* No CVC ctx */

/** @brief Declare On/Off Switch device context.
    @param device_ctx - device context variable name.
    @param ep_name - endpoint variable name.
*/
#define ZB_CUS_DECLARE_ON_OFF_SWITCH_CTX(device_ctx, ep_name) \
  ZBOSS_DECLARE_DEVICE_CTX_1_EP(device_ctx, ep_name)



#endif /* ZB_CUS_ON_OFF_SWITCH_H */
