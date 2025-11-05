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

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_SOURCE_MEDIA_CDATA_SOURCE_H
#define AMEBA_FWK_MEDIA_PLAYBACK_SOURCE_MEDIA_CDATA_SOURCE_H

#include <stdio.h>
#include <string>

#include "osal_cxx/mutex.h"
#include "osal_cxx/condition.h"

#include "media/source/data_source.h"
#include "media/common/media_errors.h"
#include "media/rtdata_source.h"

namespace ameba::media
{

class CDataSource : public DataSource
{
public:
	static size_t kCDataSourceBufferSize;
	static size_t kCDataSourceReadRetryTimeMs;
	static size_t kCDataSourceSleepTimeMs;
	static size_t kCDataSourceWriteBlockSize;
	static size_t kCDataSourcePreparedTimeoutMs;

	CDataSource(struct RTDataSource *source);

	virtual res_t Check() const;

	virtual ssize_t ReadAt(off64_t offset, void *data, size_t size);

	virtual res_t GetLength(off64_t *size);

	virtual uint32_t GetSourceFlags()
	{
		return kDataSource;
	}

	virtual std::string ToString()
	{
		return name_;
	}

	virtual void Disconnect();

protected:
	virtual ~CDataSource();

private:
	class PrepareThread;
	class WriteThread;

	struct RTDataSource *source_;
	Mutex lock_;
	std::string name_;
	volatile bool connect_;

	volatile int cur_offset_; // current read offset according to source
	volatile int total_offset_; // total read offset according to source

	/*ring buffer info*/
	int length_;
	char *data_;
	/*
	 |____________________|_______________________________|
	 rd_index_             rd_cur_index_               wr_index_
	 */
	volatile int rd_cur_index_;//written by main task
	volatile int wr_index_;//written by write task
	volatile int rd_index_;//written by main task

	Mutex prepared_lock_;
	Condition prepared_con_;
	bool prepared_;
	sptr<PrepareThread> prepare_thread_;
	volatile bool prepare_loop_exit_;//modify by preparethread_

	/*write thread */
	sptr<WriteThread> write_thread_;
	volatile bool write_thread_alive_;

	unsigned int final_status_;

	res_t check_result_;

	ssize_t ReadInternal(off_t offset, void *data, size_t size);

	size_t RingBufferRead(void *data, off_t offset, size_t size, status_t *res);
	size_t RingBufferWrite(size_t size, status_t *res);
	int GetRingBufferKeepBufferLength();
	int GetRingBufferFreeSize();
	int GetRingBufferValidDiff(unsigned int a, unsigned int b);
	int GetRingBufferReadableSizeFromOffset(off_t offset);
	void PrintRingBuffer();

	CDataSource(const CDataSource &);
	CDataSource &operator=(const CDataSource &);
};

}  // namespace ameba::media

#endif  // AMEBA_FWK_MEDIA_PLAYBACK_SOURCE_MEDIA_CDATA_SOURCE_H
