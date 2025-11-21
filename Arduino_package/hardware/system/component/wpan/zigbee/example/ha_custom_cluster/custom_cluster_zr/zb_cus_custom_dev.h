
#ifndef ZB_CUS_CUSTOM_DEV_H
#define ZB_CUS_CUSTOM_DEV_H

#include "zb_ha_device_config.h"
#include "zcl/zb_zcl_custom_cluster.h"

#define ZB_CUS_CUSTOM_DEV_DEVICE_ID        ZB_HA_CUSTOM_ATTR_DEVICE_ID
#define ZB_CUS_CUSTOM_DEV_DEVICE_VER       0
#define ZB_CUS_CUSTOM_DEV_IN_CLUSTER_NUM   3 /*!< On/Off light IN clusters number */
#define ZB_CUS_CUSTOM_DEV_OUT_CLUSTER_NUM  0 /*!< On/Off light OUT clusters number */

#define ZB_CUS_CUSTOM_DEV_CLUSTER_NUM                                      \
  (ZB_CUS_CUSTOM_DEV_IN_CLUSTER_NUM + ZB_CUS_CUSTOM_DEV_OUT_CLUSTER_NUM)

/*! @brief Declare cluster list for Custom device
    @param cluster_list_name - cluster list variable name
    @param basic_attr_list - attribute list for Basic cluster
    @param identify_attr_list - attribute list for Identify cluster
    @param thermostat_attr_list - attribute list for Thermostat cluster
 */
#define ZB_DECLARE_CUSTOM_DEV_CLUSTER_LIST(                                 \
  cluster_list_name,                                                    \
  basic_attr_list,                                                      \
  identify_attr_list,                                                   \
  custom_attr_list)                                                     \
  zb_zcl_cluster_desc_t cluster_list_name[] =                           \
  {                                                                     \
    ZB_ZCL_CLUSTER_DESC(                                                \
      ZB_ZCL_CLUSTER_ID_BASIC,                                          \
      ZB_ZCL_ARRAY_SIZE(basic_attr_list, zb_zcl_attr_t),                \
      (basic_attr_list),                                                \
      ZB_ZCL_CLUSTER_SERVER_ROLE,                                       \
      ZB_ZCL_MANUF_CODE_INVALID                                         \
    ),                                                                  \
    ZB_ZCL_CLUSTER_DESC(                                                \
      ZB_ZCL_CLUSTER_ID_IDENTIFY,                                       \
      ZB_ZCL_ARRAY_SIZE(identify_attr_list, zb_zcl_attr_t),             \
      (identify_attr_list),                                             \
      ZB_ZCL_CLUSTER_SERVER_ROLE,                                       \
      ZB_ZCL_MANUF_CODE_INVALID                                         \
    ),                                                                  \
    ZB_ZCL_CLUSTER_DESC(                                                \
      ZB_ZCL_CLUSTER_ID_CUSTOM,                                         \
      ZB_ZCL_ARRAY_SIZE(custom_attr_list, zb_zcl_attr_t),               \
      (custom_attr_list),                                               \
      ZB_ZCL_CLUSTER_SERVER_ROLE,                                       \
      ZB_ZCL_MANUF_CODE_INVALID                                         \
    )                                                                   \
  }


/*! @brief Declare simple descriptor for Custom device
    @param ep_name - endpoint variable name
    @param ep_id - endpoint ID
    @param in_clust_num - number of supported input clusters
    @param out_clust_num - number of supported output clusters
 */
#define ZB_DECLARE_CUSTOM_DEV_SIMPLE_DESC(                                         \
  ep_name, ep_id, in_clust_num, out_clust_num)                                 \
  ZB_DECLARE_SIMPLE_DESC(in_clust_num, out_clust_num);                         \
  ZB_AF_SIMPLE_DESC_TYPE(in_clust_num, out_clust_num) simple_desc_##ep_name =  \
  {                                                                            \
    ep_id,                                                                     \
    ZB_AF_HA_PROFILE_ID,                                                       \
    ZB_CUS_CUSTOM_DEV_DEVICE_ID,                                                       \
    ZB_CUS_CUSTOM_DEV_DEVICE_VER,                                                  \
    0,                                                                         \
    in_clust_num,                                                              \
    out_clust_num,                                                             \
    {                                                                          \
      ZB_ZCL_CLUSTER_ID_BASIC,                                                 \
      ZB_ZCL_CLUSTER_ID_IDENTIFY,                                              \
      ZB_ZCL_CLUSTER_ID_CUSTOM                                                 \
    }                                                                          \
  }


/*! @brief Declare endpoint for Custom device
    @param ep_name - endpoint variable name
    @param ep_id - endpoint ID
    @param cluster_list - endpoint cluster list
 */
#define ZB_DECLARE_CUSTOM_DEV_EP(ep_name, ep_id, cluster_list)     \
  ZB_DECLARE_CUSTOM_DEV_SIMPLE_DESC(                               \
    ep_name,                                                   \
    ep_id,                                                     \
    ZB_CUS_CUSTOM_DEV_IN_CLUSTER_NUM,                                     \
    ZB_CUS_CUSTOM_DEV_OUT_CLUSTER_NUM);                                   \
  ZB_AF_DECLARE_ENDPOINT_DESC(                                 \
    ep_name,                                                   \
    ep_id,                                                     \
    ZB_AF_HA_PROFILE_ID,                                       \
    0,                                                         \
    NULL,                                                      \
    ZB_ZCL_ARRAY_SIZE(cluster_list, zb_zcl_cluster_desc_t),    \
    cluster_list,                                              \
    (zb_af_simple_desc_1_1_t*)&simple_desc_##ep_name,          \
    0, NULL,                                                   \
    0, NULL)

/*! @brief Declare application's device context for Custom device
    @param device_ctx - device context variable
    @param ep_name - endpoint variable name
*/
#define ZB_DECLARE_CUSTOM_DEV_CTX(device_ctx, ep_name) \
  ZBOSS_DECLARE_DEVICE_CTX_1_EP(device_ctx, ep_name)



#endif /* ZB_CUS_CUSTOM_DEV_H */
