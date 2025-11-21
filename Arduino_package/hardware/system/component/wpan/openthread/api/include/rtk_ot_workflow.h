#ifndef RTK_OT_WORKFLOW_H_
#define RTK_OT_WORKFLOW_H_

#include "rtk_wpan_osif.h"
#include <openthread/instance.h>
#include <openthread/tasklet.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	void *handler;
	void *handler_arg;
} workflow_task_t;

typedef void (*workflow_handler)(otInstance *instance, void *handler_arg);

int rtk_ot_workflow_init(void);
int rtk_ot_workflow_deinit(void);
int rtk_ot_workflow_push(workflow_task_t *work);
int rtk_ot_workflow_pause(void);
int rtk_ot_workflow_resume(void);
void rtk_ot_workflow_process(otInstance *instance);

#ifdef __cplusplus
}
#endif

#endif
