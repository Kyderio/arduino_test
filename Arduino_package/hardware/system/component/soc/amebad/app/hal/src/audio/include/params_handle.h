/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef AMEBA_COMPONENT_AUDIO_HAL_SRC_INCLUDE_PARAMS_HANDLE_H
#define AMEBA_COMPONENT_AUDIO_HAL_SRC_INCLUDE_PARAMS_HANDLE_H

#include "platform_stdlib.h"

struct string_cell {
	char *key;
	char *value;
	struct string_cell *next;
};

struct string_cell *string_cells_create_from_str(const char *_string);
void string_cells_destroy(struct string_cell *cell_head);

int string_cells_has_key(struct string_cell *cell_head, const char *key);
int string_cells_get_str(struct string_cell *cell_head, const char *key, char *out_val, int len);
int string_cells_get_int(struct string_cell *cell_head, const char *key, int *out_val);

#endif