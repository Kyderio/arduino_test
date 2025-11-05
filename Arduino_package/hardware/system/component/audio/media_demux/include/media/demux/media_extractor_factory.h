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

#ifndef AMEBA_FWK_MEDIA_PLAYBACK_DEMUX_MEDIA_DEMUX_MEDIA_EXTRACTOR_FACTORY_H
#define AMEBA_FWK_MEDIA_PLAYBACK_DEMUX_MEDIA_DEMUX_MEDIA_EXTRACTOR_FACTORY_H

#include <stdio.h>
#include <memory>
#include <list>

#include "osal_cxx/mutex.h"

#include "media/demux/media_extractor.h"

namespace ameba::media
{

class DataSourceBase;
class ExtractorPlugin;

class MediaExtractorFactory
{
public:
	static int kFastProbe;

	static sptr<MediaExtractor> Create(
		int type, const sptr<DataSource> &source, const char *mime = NULL);
	static void Destroy();
private:
	static Mutex g_plugin_mutex_;
	static std::shared_ptr<std::list<sptr<ExtractorPlugin>>> g_plugins_;
	static bool g_plugins_registered_;

	static Mutex g_lite_plugin_mutex_;
	static std::shared_ptr<std::list<sptr<ExtractorPlugin>>> g_lite_plugins_;
	static bool g_lite_plugins_registered_;

	static void RegisterExtractor(
		const sptr<ExtractorPlugin> &plugin, std::list<sptr<ExtractorPlugin>> &plugin_list);

	static CreateFunction Detect(int type, DataSourceBase *source,
								 float *confidence, void **meta, ReleaseMetaFunction *release_meta,
								 sptr<ExtractorPlugin> &plugin);

	static CreateFunction ProbeSource(
		int type, DataSourceBase *source, ProbeBuffer *probe_buffer,
		float *confidence, void **meta,
		ReleaseMetaFunction *release_meta, sptr<ExtractorPlugin> &plugin);

	static void UpdateExtractors();
	static void UpdateLiteExtractors();
};

}  // namespace ameba::media

#endif  // AMEBA_FWK_MEDIA_PLAYBACK_DEMUX_MEDIA_DEMUX_MEDIA_EXTRACTOR_FACTORY_H
