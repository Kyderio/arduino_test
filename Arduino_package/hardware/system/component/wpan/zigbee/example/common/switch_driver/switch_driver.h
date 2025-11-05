#ifndef SWITCH_DRIVER_H
#define SWITCH_DRIVER_H

#define GPIO_BTN_SWITCH_ON      PB_10
#define GPIO_BTN_SWITCH_OFF     PB_9
#define GPIO_BTN_TEST_1         PB_7

#define GPIO_BTN_USE_NUM        (3)

#define GPIO_BTN_LEVEL_ON       (0)

#define SWITCH_PRESSED_TIME_TH  (50000)

typedef enum {
	SWITCH_DEFAULT_CONTROL,
	SWITCH_ON_CONTROL,
	SWITCH_OFF_CONTROL,
	SWITCH_LEVEL_UP_CONTROL,
	SWITCH_LEVEL_DOWN_CONTROL,
} switch_action_t;

typedef enum {
	SWITCH_NONE,
	SWITCH_PRESSED,
	SWITCH_RELEASED,
} switch_state_t;

typedef void (*switch_callback_t)(uint32_t pin, switch_action_t action);

typedef struct switch_node {
	uint32_t pin;
	uint32_t irq_ts;
	switch_state_t state;
	switch_action_t action;
	switch_callback_t cb;
} switch_node_t;

typedef struct pin_node {
	uint32_t pin;
	uint32_t gpio_dir;
	uint32_t gpio_mode;
	uint32_t gpio_irq_trig_mode;
	gpio_irq_t gpio_adapt;
} pin_node_t;

void switch_driver_init(switch_node_t *switch_node, uint32_t num);

#endif