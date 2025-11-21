#ifndef BT_CONTROLLER_LL_UTIL_H
#define BT_CONTROLLER_LL_UTIL_H

struct bt_controller_ll_queue {
	struct list_head head;
	void *mutex;
};

bool bt_controller_ll_queue_init(struct bt_controller_ll_queue *pqueue);
void bt_controller_ll_queue_deinit(struct bt_controller_ll_queue *pqueue);
struct list_head *bt_controller_ll_queue_peek(struct bt_controller_ll_queue *pqueue);
struct list_head *bt_controller_ll_queue_dequeue_first(struct bt_controller_ll_queue *pqueue);
void bt_controller_ll_queue_enqueue_tail(struct bt_controller_ll_queue *pqueue, struct list_head *pnew_entry);
#endif