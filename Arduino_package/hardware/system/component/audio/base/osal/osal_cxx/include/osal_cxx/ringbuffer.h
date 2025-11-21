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

#ifndef AMEBA_BASE_OSAL_OSAL_CXX_INTERFACES_OSAL_CXX_RINGBUFFER_H
#define AMEBA_BASE_OSAL_OSAL_CXX_INTERFACES_OSAL_CXX_RINGBUFFER_H

#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "osal_c/osal_mem.h"

namespace ameba
{

template <class T>
class RingBuffer
{
public:
	explicit RingBuffer(size_t size, const char *name = NULL);
	~RingBuffer();

	ssize_t Write(const T ev);
	ssize_t Write(const T *ev, size_t size);
	ssize_t Read(T *ev);
	ssize_t Read(T *ev, size_t size);

	size_t Size();
	size_t Space();
	size_t Available();

	size_t GetWritePoint();
	size_t GetReadPoint();

	void Reset();

private:
	size_t size_;
	T *data_;
	size_t rptr_;
	size_t wptr_;
	const char *name_;
};

template <class T>
RingBuffer<T>::RingBuffer(size_t size, const char *name)
{
	size_ = size;
	rptr_ = 0;
	wptr_ = 0;

	if (name) {
		size_t len = strlen(name);
		name_ = (const char *)osal_calloc(sizeof(char) * (len + 1));
		memcpy((void *)name_, name, len + 1);
	} else {
		name_ = "anonymous";
	}

	data_ = new T[size];

	printf("++RingBuffer[%s]\n", name_);
}

template <class T>
RingBuffer<T>::~RingBuffer()
{
	printf("~~RingBuffer[%s]\n", name_);

	delete[] data_;

	if (name_) {
		osal_free((void *)name_);
	}
}

template <class T>
ssize_t RingBuffer<T>::Write(const T ev)
{
	size_t size = 1;
	size_t write_pos = (wptr_ % size_);
	size_t copy = size_ - write_pos;
	if (copy <= 0) {
		return 0;
	}

	data_[write_pos] = ev;
	wptr_ = (wptr_ + size) % size_;

	//printf("Write [%ld-%ld-%ld]\n", wptr_, rptr_, size_);
	return size;
}

template <class T>
ssize_t RingBuffer<T>::Write(const T *ev, size_t size)
{
	if (!size || !ev) {
		printf("try to write from empty buffer.\n");
		return -1;
	}

	size_t write_pos = (wptr_ % size_);
	size_t copy = size_ - write_pos;

	if (copy > size) {
		copy = size;
	}

	memcpy(&data_[write_pos], ev, copy * sizeof(T));

	if (size > copy) {
		memcpy(data_, &ev[copy], (size - copy) * sizeof(T));
	}

	wptr_ = (wptr_ + size) % size_;

	//printf("Write [%ld-%ld-%ld]\n", wptr_, rptr_, size_);
	return size;
}

template <class T>
ssize_t RingBuffer<T>::Read(T *ev)
{
	(*ev) = NULL;
	size_t available_to_read = wptr_ - rptr_;
	size_t size = 1;
	if (available_to_read <= 0) {
		return 0;
	}

	size_t read_pos = (rptr_ % size_);

	(*ev) = data_[read_pos];
	data_[read_pos] = NULL;

	rptr_ = (rptr_ + size) % size_;

	//printf("Read [%ld-%ld-%ld]\n", wptr_, rptr_, size_);
	return size;
}

template <class T>
ssize_t RingBuffer<T>::Read(T *ev, size_t size)
{
	size_t read_pos = (rptr_ % size_);
	size_t copy = size_ - read_pos;

	if (copy > size) {
		copy = size;
	}

	memcpy(ev, &data_[read_pos], copy * sizeof(T));

	if (size > copy) {
		memcpy(&ev[copy], data_, (size - copy) * sizeof(T));
	}

	rptr_ = (rptr_ + size) % size_;

	//printf("Read [%ld-%ld-%ld]\n", wptr_, rptr_, size_);
	return size;
}

template <class T>
size_t RingBuffer<T>::Size()
{
	return size_;
}

template <class T>
size_t RingBuffer<T>::Space()
{
	//printf("space [%u-%u-%u], %u\n", wptr_, rptr_, size_, (size_ - 1 + rptr_ - wptr_) % size_);
	return ((size_ - 1 + rptr_ - wptr_) % size_);
}

template <class T>
size_t RingBuffer<T>::Available()
{
	//printf("avail [%u-%u-%u], %u\n", wptr_, rptr_, size_, (size_ + wptr_ - rptr_) % size_);
	return ((size_ + wptr_ - rptr_) % size_);
}

template <class T>
size_t RingBuffer<T>::GetWritePoint()
{
	return wptr_;
}

template <class T>
size_t RingBuffer<T>::GetReadPoint()
{
	return rptr_;
}

template <class T>
void RingBuffer<T>::Reset()
{
	wptr_ = rptr_ = 0;
}

}  // namespace ameba
#endif // AMEBA_BASE_OSAL_OSAL_CXX_INTERFACES_OSAL_CXX_RINGBUFFER_H
