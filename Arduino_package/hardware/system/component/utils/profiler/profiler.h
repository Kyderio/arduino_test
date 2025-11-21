/**
 * @file profiler.h
 *
 */

#ifndef PROFILER_H
#define PROFILER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PROFILER_BEGIN(task_name, task_id)                PROFILER_BEGIN_TAG(task_name, task_id, __func__)
#define PROFILER_END(task_name, task_id)                  PROFILER_END_TAG(task_name, task_id, __func__)
#define PROFILER_BEGIN_TAG(task_name, task_id, tag)       profiler_write((task_name), (task_id), (tag), 'B')
#define PROFILER_END_TAG(task_name, task_id, tag)         profiler_write((task_name), (task_id), (tag), 'E')

#define PROFILER_BUF_SIZE (5 * 1024)
#define PROFILER_STR_MAX_LEN 128
#define PROFILER_TICK_PER_SEC_MAX 1000000

/**
 * @brief Initialize the profiler
 */
void profiler_init(void);

/**
 * @brief Uninitialize the profiler
 */
void profiler_uninit(void);

/**
 * @brief Write the profiling data for a function with the given tag
 * @param task name of the task being profiled
 * @param task id of the task being profiled
 * @param func Name of the function being profiled
 * @param tag Tag to associate with the profiling data for the function
 */

void profiler_write(const char *task_name, int32_t task_id, const char *func, char tag);

/**
 * @brief Flush the profiling data to the console
 */
void profiler_flush(void);
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*PROFILER_H*/
