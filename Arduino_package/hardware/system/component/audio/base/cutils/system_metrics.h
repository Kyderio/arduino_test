/*
 * Copyright (c) 2021 Realtek, LLC.
 * All rights reserved.
 *
 * Licensed under the Realtek License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License from Realtek
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AMEBA_BASE_CUTILS_INCLUDE_CUTILS_SYSTEM_METRICS_SERVICE_H
#define AMEBA_BASE_CUTILS_INCLUDE_CUTILS_SYSTEM_METRICS_SERVICE_H

#include "system_metrics.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int64_t system_metrics_handle_t;

system_metrics_handle_t SystemMetrics_Create(const char *key);
void SystemMetrics_Delete(system_metrics_handle_t handle);

const char *SystemMetrics_GetKey(system_metrics_handle_t handle);

// set
void SystemMetrics_SetInt32(system_metrics_handle_t handle, const char *attr, int32_t value);
void SystemMetrics_SetInt64(system_metrics_handle_t handle, const char *attr, int64_t value);
void SystemMetrics_SetDouble(system_metrics_handle_t handle, const char *attr, double value);
void SystemMetrics_SetCString(system_metrics_handle_t handle, const char *attr, const char *value);

// fused get/add/set; if attr wasn't there, it's a simple set.
// these do not provide atomicity or mutual exclusion, only simpler code sequences.
void SystemMetrics_AddInt32(system_metrics_handle_t handle, const char *attr, int32_t value);
void SystemMetrics_AddInt64(system_metrics_handle_t handle, const char *attr, int64_t value);
void SystemMetrics_AddDouble(system_metrics_handle_t handle, const char *attr, double value);

// find & extract values
// return indicates whether attr exists (and thus whether value filled in)
// NULL parameter value suppresses storage of value.
bool SystemMetrics_GetInt32(system_metrics_handle_t handle, const char *attr, int32_t *value);
bool SystemMetrics_GetInt64(system_metrics_handle_t handle, const char *attr, int64_t *value);
bool SystemMetrics_GetDouble(system_metrics_handle_t handle, const char *attr, double *value);
bool SystemMetrics_GetCString(system_metrics_handle_t handle, const char *attr, char **value);
// to release strings returned via getCString()
void SystemMetrics_FreeCString(char *value);

// # of attributes set within this record.
int32_t SystemMetrics_Count(system_metrics_handle_t handle);

system_metrics_handle_t SystemMetrics_Dup(system_metrics_handle_t handle);
bool SystemMetrics_SelfRecord(system_metrics_handle_t handle);

void SystemMetrics_Init(void);
void SystemMetrics_DumpAll(void);
uint32_t SystemMetrics_Dump(uint16_t argc, uint8_t *argv[]);

#ifdef __cplusplus
}
#endif

#endif /* AMEBA_BASE_CUTILS_INCLUDE_CUTILS_SYSTEM_METRICS_SERVICE_H */
