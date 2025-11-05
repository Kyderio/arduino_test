#ifndef BT_CONTROLLER_H
#define BT_CONTROLLER_H

#include <basic_types.h>
#include <string.h>
#include <stdio.h>
#include <osif.h>
#include <dlist.h>
#include <ameba.h>
#include <bt_debug.h>
#include <bt_controller_hci_spec.h>
#include <bt_controller_hal_conf.h>
#include <bt_controller_ll_feature.h>
#include <bt_controller_config.h>
#include <bt_controller_ll_util.h>
#include <bt_controller_addr.h>
#include <bt_controller_ll_le_pdu.h>
#include <bt_controller_hal.h>
#include <bt_controller_vhci.h>
#include <bt_controller_ll_schedule.h>
#include <bt_controller_ll_le.h>


struct bt_controller_manager {
	struct bt_controller_hci_manager hci_manager;
	struct bt_controller_hal_info    hal_info;
	struct bt_controller_ll_le_manager ll_le_manager;
	struct bt_controller_ll_scheduler ll_scheduler_manager;
};

extern struct bt_controller_manager g_bt_controller_manger;

bool bt_controller_init(void);
void bt_controller_enable(void);
void bt_controller_disable(void);
void bt_controller_reset(void);
void bt_controller_deinit(void);

#endif