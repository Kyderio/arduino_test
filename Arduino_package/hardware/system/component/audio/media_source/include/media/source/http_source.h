/*
 * Copyright (c) 2022 Realtek, LLC.
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

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_SOURCE_MEDIA_SOURCE_HTTP_SOURCE_H
#define AMEBA_FWK_MEDIA_PLAYBACK_SOURCE_MEDIA_SOURCE_HTTP_SOURCE_H

#include <stdio.h>
#include <atomic>

#include "osal_c/osal_errnos.h"
#include "osal_cxx/threads.h"

#include "media/source/data_source.h"
#include "media/source/cache_manager.h"

#include "media/common/media_errors.h"

#include "media/utils/rstring.h"
#include "media/utils/nocopyable.h"

#define RT_SOCK_RECV_BUFFER_SIZE            (2*512)

namespace ameba::media
{

class HttpSource : public DataSource
{
public:
	/**
	 * Http download buffer total size.
	 */
	static size_t kHttpBufferSize;

	/**
	 * This timeout is for http/https prepare stage, if timeout occurs, playback fails.
	 * The unit is millisecond.
	 */
	static size_t kHttpPreparedTimeoutMs;

	/**
	 * This timeout is only valid for non-block socket connect, if timeout occurs, socket connect fails.
	 * The unit is millisecond.
	 */
	static size_t kHttpSocketConnectTimeoutMs;

	/**
	 * Socket send data timeout. Not recommended to set it too small.
	 * The unit is millisecond.
	 */
	static size_t kHttpSendTimeoutMs;

	/**
	 * Socket receive data timeout. Not recommended to set it too small.
	 * The unit is millisecond.
	 */
	static size_t kHttpRecvTimeoutMs;

	/**
	 * Player will retry read for several times if http read data error happens.
	 * The unit is millisecond.
	 */
	static size_t kHttpReadRetryTimeMs;

	HttpSource(const char *name);

	virtual res_t Check() const;

	virtual ssize_t ReadAt(off64_t offset, void *data, size_t size);

	virtual res_t  GetLength(off64_t *size);

	virtual uint32_t GetSourceFlags()
	{
		return kHttpSource | kCachedSource;
	}

	virtual std::string ToString()
	{
		return url_;
	}

	void FininalizeCache(void);

	bool ThreadLoop() ;
	size_t GetCachedDataSize(res_t *status);

protected:
	virtual ~HttpSource();

	size_t Http_GetValidDiff(unsigned int a, unsigned int b);
	int Http_GetRingBufferlen(void)
	{
		return data_buffers_len_;
	}
	int Http_GetKeepBufferlen(void)
	{
		return Http_GetRingBufferlen() / 3;
	}
	void Http_DestoryHttpSourceParams();
	void Http_InitHttpSourceParams();
	void Http_ResetHttpSourceParams(uint32_t offset, bool reconnect = false);
	status_t Http_GetTheHostPort(const char *audio_link);
	status_t Http_GetTheSocketId(void);
	status_t Http_ConnectSocketBlocked(const  struct sockaddr_in *server_addr);
	status_t Http_ConnectSocketNonBlocked(const  struct sockaddr_in *server_addr);
	void Http_CloseSockHandle(void);
	status_t Http_PostReGetCmd();
	status_t Http_ReadChunkData(int chunk_size, int *read_size);
	status_t Http_ReadDataChunked();
	status_t Http_ReadHeaderData();
	status_t Http_ParseHeaderDataUnchunked(char *response_header);
	status_t Http_HandleStatus301(char *response_header);
	ssize_t Http_ReadSockInternal(off_t offset, void *data, size_t size);
	status_t  HttpSource_HttpOpen(const char *url);
	virtual void Disconnect();
	status_t Http_Read(void *data, size_t size);
	status_t Http_Write(void *data, size_t size);
	void Http_WaitLoopExit();

private:
	class PrepareThread;
	class DownloadThread;

	//read buffer offset that get from remote server
	volatile int total_offset_;
	//read buffer offset that get from remote server, will reset for chuncked data reconnect
	volatile int tmp_total_offset_;
	//cur read offset, which has been send to demux components
	volatile int cur_offset_;

	volatile int download_offset_;
	volatile int last_cur_offset_;

	int start_range_;
	//total file length ,from 0 to the end
	volatile int total_length_;

	CacheManager *cache_manager_;
	sptr<CacheManager::WriteHandle> write_handle_;
	char *url_;
	char *host_;
	int port_;
	char *path_;
	volatile int socket_id_;
	void *tls_;//context for tls connection

	Mutex lock_;

	Mutex prepared_lock_;
	Condition prepared_con_;
	bool prepared_;
	sptr<PrepareThread> preparethread_;
	volatile bool prepare_loop_exit_;//modify by preparethread_

	sptr<DownloadThread> downloadthread_ ;
	volatile bool thread_alive_;
	volatile bool connect_;
	volatile bool dlloop_exit_;//modify by downloadtask
	unsigned short task_alive_flag_; //debug
	bool is_https_ ;
	bool chuncked_;
	bool last_chunck_gained_;
	bool accept_ranges_;
	volatile char dl_state_;//write by downaloadtask
	//unsigned int num_read_retries_left;
	//ssize_t final_status_;//write by maintask
	volatile bool reconnect_ ;//write by maintask
	std::atomic<int32_t> forceclose_;//set by maintask, reset by downloadTask

	/*ring buffer info*/
	int data_buffers_len_;
	char *data_buffers_;
	/*
	    |____________________|_______________________________|
	    rd_index_          rd_cur_index_                wr_index_
	*/
	volatile int rd_cur_index_ ;//write by maintask
	volatile int wr_index_ ;//write by downloadtask
	volatile int rd_index_ ;//write by maintask

	//for readat in serial
	Mutex read_serializer_;

	int num_read_retries_left_;
	uint8_t buffer_[RT_SOCK_RECV_BUFFER_SIZE];

	res_t check_result_;

	DISALLOW_COPY_AND_MOVE(HttpSource);
};

}  // namespace ameba::media

#endif  // AMEBA_FWK_MEDIA_PLAYBACK_SOURCE_MEDIA_SOURCE_HTTP_SOURCE_H
