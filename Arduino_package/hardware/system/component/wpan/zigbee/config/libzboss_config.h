
#ifndef LIBZBOSS_CONFIG_H__
#define LIBZBOSS_CONFIG_H__

#include "platform_autoconf.h"

#ifdef CONFIG_AMEBASMART
#error "!!!unsupported IC for zigbee config!!!"

#elif defined(CONFIG_AMEBALITE)

#if defined(CONFIG_WPAN_ZIGBEE_APPLICATION_EN) && CONFIG_WPAN_ZIGBEE_APPLICATION_EN
#if defined(ZB_ED_ROLE) && ZB_ED_ROLE
#include "libzboss_amebalite_config.ed.h"
#else
#include "libzboss_amebalite_config.h"
#endif
#elif defined(CONFIG_WPAN_ZIGBEE_MAC_TEST_EN) && CONFIG_WPAN_ZIGBEE_MAC_TEST_EN
#include "libzboss_amebalite_config_mac_cert.h"
#elif defined(CONFIG_WPAN_ZIGBEE_ZCP_TEST_EN) && CONFIG_WPAN_ZIGBEE_ZCP_TEST_EN
#include "libzboss_amebalite_config_r22_autotests.h"
#elif defined(CONFIG_WPAN_ZIGBEE_REGRESSION_TEST_EN) && CONFIG_WPAN_ZIGBEE_REGRESSION_TEST_EN
#include "libzboss_amebalite_config_regression_test.h"
#endif

#else
#error "!!!unsupported IC for zigbee config!!!"
#endif

#endif /* LIBZBOSS_CONFIG_H__ */
