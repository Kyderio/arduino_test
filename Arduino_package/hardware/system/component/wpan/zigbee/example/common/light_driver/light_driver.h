#ifndef LIGHT_DRIVER_H
#define LIGHT_DRIVER_H


void light_driver_init(void);
void light_driver_set_power(uint8_t on_off);
void light_driver_set_red(void);
void light_driver_set_green(void);
void light_driver_set_blue(void);

#endif