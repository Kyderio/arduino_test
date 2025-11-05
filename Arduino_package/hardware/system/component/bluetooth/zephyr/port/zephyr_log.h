#ifndef  BTSNOOP_H
#define  BTSNOOP_H

#ifdef __cplusplus
extern "C" {
#endif


#define ZLOG_STACK_MODE_OFF       0
#define ZLOG_STACK_MODE_PRINTF    1
#define ZLOG_STACK_MODE_ARGS      2

#define ZLOG_SNOOP_ON 	1
#define ZLOG_STACK_MODE   ZLOG_STACK_MODE_ARGS

#if (ZLOG_SNOOP_ON || (ZLOG_STACK_MODE == ZLOG_STACK_MODE_ARGS))
void zephyr_btlog_init(void);
void zephyr_btlog_deinit(void);
#else
#define zephyr_btlog_init()
#define zephyr_btlog_deinit()
#endif

/* create snoop packet and send to host computer */
#if ZLOG_SNOOP_ON
void btsnoop_send(uint8_t type, uint8_t *data, uint32_t len, bool c2h);
#else
#define btsnoop_send(type, data, len, c2h)
#endif

#if (ZLOG_STACK_MODE == ZLOG_STACK_MODE_ARGS)
void zephyr_stacklog_args_send(char level, int log_idx, char num, ...);
#else
#define zephyr_stacklog_args_send(...)
#endif

void z_printf(const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif /* BTSNOOP_H */
