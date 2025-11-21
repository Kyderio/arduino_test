#ifndef DRIVER_AMEBA_H
#define DRIVER_AMEBA_H

#include "includes.h"
#include "driver.h"
#include "wpa_supplicant_i.h"
#include "bss.h"
#include "l2_packet.h"

struct ameba_global {
	void *ctx;
};

struct wpa_driver_ameba_data {
	struct ameba_global *global; //global_priv
	void *ctx;                   //wpa_supplicant
	void *dev_priv;
	const struct ameba_wpas_std_wifi_ops *wifi_ops; //For WIFI Driver ops
	u8 own_addr[ETH_ALEN];

};


/* The callback function will be assigned to wifi driver, wifi driver
 * call the related callback function, then back to wpa_supplicant
 * mechanism
 */
struct ameba_wpas_std_cb_fns
{
	void (*scan_start)(struct wpa_driver_ameba_data *drv_ctx);
};

struct ameba_wpas_std_wifi_ops
{
        void *(*init)(void *wpas_std_ctx, int intf_idx, struct ameba_wpas_std_cb_fns *cb_fns);
};


#endif /* DRIVER_AMEBA_H */
