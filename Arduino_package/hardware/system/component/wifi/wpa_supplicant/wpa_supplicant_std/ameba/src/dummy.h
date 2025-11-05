#ifndef DUMMY_H
#define DUMMY_H

#include "common.h"

int sha256_prf(const u8 *key, size_t key_len, const char *label,
			       const u8 *data, size_t data_len, u8 *buf, size_t buf_len);

#ifdef CONFIG_CTRL_IFACE
struct ctrl_iface_priv *
wpa_supplicant_ctrl_iface_init(struct wpa_supplicant *wpa_s);

void
wpa_supplicant_ctrl_iface_deinit(struct wpa_supplicant *wpa_s,
				 struct ctrl_iface_priv *priv);

void
wpa_supplicant_ctrl_iface_wait(struct ctrl_iface_priv *priv);

struct ctrl_iface_global_priv *
wpa_supplicant_global_ctrl_iface_init(struct wpa_global *global);

void
wpa_supplicant_global_ctrl_iface_deinit(struct ctrl_iface_global_priv *priv);
#endif

int tls_get_library_version(char *buf, size_t buf_len);

#endif //DUMMY_H
