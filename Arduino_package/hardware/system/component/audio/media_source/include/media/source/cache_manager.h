/*
 * Copyright (c) 2025 Realtek, LLC.
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

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_SOURCE_MEDIA_SOURCE_CACHE_MANAGER_H
#define AMEBA_FWK_MEDIA_PLAYBACK_SOURCE_MEDIA_SOURCE_CACHE_MANAGER_H

#include <map>
#include <list>

#include "osal_cxx/errors.h"
#include "osal_cxx/mutex.h"
#include "osal_cxx/refptr.h"

#include "media/utils/rstring.h"

namespace ameba::media
{
class CacheManager {
public:
    typedef void (*CompleteCallback)(const RString& cachedPath);
    class WriteHandle : public RefPtr {
    public:
        WriteHandle(const RString& tmpPath, CompleteCallback completionCallback, CacheManager* manager, int64_t offset, int64_t size_);
        ~WriteHandle();

        bool Write(const char* data, int64_t offset, size_t size);
        void Finalize(bool success);

    private:
        FILE* out_file_;
        RString tmp_path_;
        CompleteCallback completion_callback_;
        bool finalized_ = false;
        CacheManager* manager_;
        int64_t offset_;
        int64_t size_;
    };

    static CacheManager *GetInstance();

    RString GetCachedFilePath(const RString& url);

    sptr<WriteHandle> BeginWriteCache(const RString& url, int size, CompleteCallback completionCallback);

    void ClearAllCache();

    static int media_cacheable;
    static char* prefix;
    static char* cache_dir;
    static unsigned int media_max_cache_count;

private:
    enum CacheStatus {
        CACHE_IDLE,
        CACHEING,
        CACHE_FINISH,
    };

    struct CacheEntry {
        RString filePath;
        int status;
        int64_t size;
    };

    CacheManager();
    CacheManager(const CacheManager&) = delete;
    CacheManager& operator=(const CacheManager&) = delete;

    void FinalizeCacheWrite(const RString& url,
                          bool success,
                          CompleteCallback completionCallback);

    void LoadCacheIndex(const RString& dir_name);
    RString UrlToFileName(const RString& url) const;
    void RemoveFile(const RString& path);

    std::map<RString, CacheEntry> cache_index_;
    Mutex lock_;
};

}
#endif /* AMEBA_FWK_MEDIA_PLAYBACK_SOURCE_MEDIA_SOURCE_CACHE_MANAGER_H */
