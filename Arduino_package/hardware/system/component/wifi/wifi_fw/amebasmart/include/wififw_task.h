#ifndef __WIFIFW_TASK_H__
#define __WIFIFW_TASK_H__

//3 TaskBitMap0
#define RATEADAPTIVE        						BIT0
#define H2CEVENT            						BIT1
#define C2HEVENT            						BIT2
#define REMOTEWAKEEVENT     						BIT4
#define BTMAILBOXEVENT      						BIT7

extern rtos_sema_t	fw_comm_sema;
extern rtos_sema_t	fw_ipc_cmd_sema;
extern u8 wifi_enable;
extern u8 wifi_disable;
extern u8 wifi_is_enable;
extern void wififw_task_send_signal(u32  event);
#define WIFIFW_TASK_IPC_STACK_SIZE	(208 + 128 + CONTEXT_SAVE_SIZE)
#define WIFIFW_TASK_FUNC_STACK_SIZE	(540 + 128 + CONTEXT_SAVE_SIZE)

#endif
