/*
 * Copyright (c) 2021 Realtek, LLC.
 * All rights reserved.
 *
 * Licensed under the Realtek License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License from PanKore
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @addtogroup OSAL
 * @{
 *
 * @brief Declares the structures and interfaces for the Operating System Abstraction Layer (OSAL) module.
 *
 * The OSAL module provide a unified interfaces that adapter to different OS. The interfaces include the
 * memory management, thread, mutex, semaphore, time.
 *
 * @since 1.0
 * @version 1.0
 */

/**
 * @file threads.h
 *
 * @brief Declares thread interfaces.
 *
 * @since 1.0
 * @version 1.0
 */

#ifndef AMEBA_BASE_OSAL_OSAL_CXX_INTERFACES_OSAL_CXX_THREADS_H
#define AMEBA_BASE_OSAL_OSAL_CXX_INTERFACES_OSAL_CXX_THREADS_H

#include "osal_c/osal_thread.h"

#include "osal_cxx/errors.h"
#include "osal_cxx/condition.h"
#include "osal_cxx/mutex.h"
#include "osal_cxx/refptr.h"

namespace ameba
{

/**
 * @brief Enumerates thread priorities.
 *
 * @since 1.0
 * @version 1.0
 */
enum {
	PRIORITY_LOWEST         = OSAL_THREAD_PRI_LOWEST,
	PRIORITY_BACKGROUND     = OSAL_THREAD_PRI_BACKGROUND,
	PRIORITY_NORMAL         = OSAL_THREAD_PRI_BACKGROUND,
	PRIORITY_FOREGROUND     = OSAL_THREAD_PRI_BACKGROUND,
	PRIORITY_DISPLAY        = OSAL_THREAD_PRI_DISPLAY,
	PRIORITY_URGENT_DISPLAY = OSAL_THREAD_PRI_URGENT_DISPLAY,
	PRIORITY_AUDIO          = OSAL_THREAD_PRI_AUDIO,
	PRIORITY_URGENT_AUDIO   = OSAL_THREAD_PRI_URGENT_AUDIO,
	PRIORITY_HIGHEST        = OSAL_THREAD_PRI_HIGHEST,
	PRIORITY_DEFAULT        = OSAL_THREAD_PRI_DEFAULT,
	PRIORITY_MORE_FAVORABLE = OSAL_THREAD_PRI_MORE_FAVORABLE,
	PRIORITY_LESS_FAVORABLE = OSAL_THREAD_PRI_LESS_FAVORABLE,
};

/**
 * @brief Defines a thread id
 *
 * @since 1.0
 * @version 1.0
 */
typedef osal_thread_id_t thread_id_t;

/**
 * @brief Defines a thread routine function type.
 *
 * @since 1.0
 * @version 1.0
 */
typedef osal_thread_func_t thread_func_t;

class Thread : virtual public RefPtr
{
public:
	explicit Thread();
	virtual ~Thread();

	virtual res_t Start(const char *name,
						int32_t priority = PRIORITY_DEFAULT,
						size_t stack = 0);
	virtual res_t PrepareToRun();
	virtual void  RequestExit();

	res_t RequestExitAndWait();
	res_t Join();
	bool  IsRunning() const;

protected:
	bool  IsExiting() const;

private:
	virtual bool  ThreadLoop() = 0;
	static  void *ThreadEntry(void *param);

private:
	static constexpr size_t kMaxNameLen = 32;

	thread_id_t  thread_id_;
	char name_[kMaxNameLen];

	mutable  Mutex        lock_;
	Condition    exit_condition_;

	volatile bool         exit_;
	volatile bool         running_;
	res_t        status_;

	sptr<Thread> self_ptr_;

	// Thread cannot be copied
	Thread(const Thread &) = delete;
	Thread &operator= (const Thread &) = delete;

	Thread(Thread &&) = delete;
	Thread &operator= (Thread &&) = delete;
};


}; // namespace ameba

#endif // AMEBA_BASE_OSAL_OSAL_CXX_INTERFACES_OSAL_CXX_THREADS_H
/** @} */
