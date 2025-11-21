#include <basic_types.h>

#ifndef BT_CONTROLLER_LL_SCHEDULER_H
#define BT_CONTROLLER_LL_SCHEDULER_H

#define BT_CONTROLLER_SCHE_MIN_TIME_US          30

#define BT_CONTROLLER_SCHE_TASK_SIZE            512


enum bt_ll_sche_callback_operation {
	BT_LL_SCHE_PROCEDURE_TIMER_INTERRUPT,
	BT_LL_SCHE_PROCEDURE_TX_INTERRUPT,
	BT_LL_SCHE_PROCEDURE_RX_INTERRUPT,
	BT_LL_SCHE_PROCEDURE_COLLISION,
	BT_LL_SCHE_PROCEDURE_RESET,
};

enum bt_ll_sche_priority {
	BT_LL_SCHE_LOW,
	BT_LL_SCHE_MIDDLE,
	BT_LL_SCHE_HIGH
};

enum bt_ll_sche_result {
	BT_LL_SCHE_OK,
	BT_LL_SCHE_FAIL,
	BT_LL_SCHE_CANCEL,
	BT_LL_SCHE_TIMEOUT,
};

typedef void (*bt_ll_sche_callback)(void *param, uint8_t operation, uint8_t result);
struct bt_ll_procedure_node {
	struct list_head list;
	uint32_t instant;
	uint32_t duration_slot;
	uint16_t schedule : 1;
	uint16_t run : 1;
	uint16_t complete : 1;
	uint16_t pri : 2;
	uint16_t type : 3;
	uint16_t max_skip_cnt : 4;
	uint16_t cur_skip_cnt : 4;
	bt_ll_sche_callback callback;
	void *param;
};
struct bt_controller_ll_scheduler {
	void *schedule_task;
	void *schedule_sema;
	void *ll_free_queue;
	void *mutex;
	struct list_head ll_sche_queue;
	struct bt_ll_procedure_node ll_sche_set[BT_LL_SCHE_MAX_PROCEDURE_NUM];
	struct bt_ll_procedure_node *pcurrent_procedure;
};

bool bt_controller_scheduler_init(void);
void bt_controller_scheduler_deinit(void);
void bt_controller_scheduler_reset(void);

uint32_t bt_controller_scheduler_get_current_task_complete_instant(void);
struct bt_ll_procedure_node *bt_controller_scheduler_new_procedure(uint32_t duration_slot, bt_ll_sche_callback callback, void *param);
void bt_controller_scheduler_add_procedure(struct bt_ll_procedure_node *pbt_ll_procedure);
void bt_controller_scheduler_free_pocedure(struct bt_ll_procedure_node *pbt_ll_procedur);
void bt_controller_schedule_update_instant(struct bt_ll_procedure_node *pll_procedure, uint32_t instant);
void bt_controller_schedule_update_duration_slot(struct bt_ll_procedure_node *pll_procedure, uint32_t duration_slot);
void bt_controller_scheduler_node_reinit(struct bt_ll_procedure_node *pll_procedure, bt_ll_sche_callback callback, void *param);
void bt_controller_scheduler_complete_procedure(struct bt_ll_procedure_node *pbt_ll_procedure);
void bt_controller_scheduler_abort_procedure(struct bt_ll_procedure_node *pbt_ll_procedure);
struct bt_ll_procedure_node *bt_controller_scheduler_get_current_procedure(void);
void bt_controller_run_scheduler(void);
#endif