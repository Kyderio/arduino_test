#ifndef AMEBA_APPS_PANGU_APP_UI_SERVICE_MUSIC
#define AMEBA_APPS_PANGU_APP_UI_SERVICE_MUSIC

#include <stdint.h>

namespace MusicService
{
const char *MusicGetTitle(uint32_t track_id);
const char *MusicGetArtist(uint32_t track_id);
const char *MusicGetGenre(uint32_t track_id);
uint32_t MusicGetTrackLength(uint32_t track_id);
}

#endif /* AMEBA_APPS_PANGU_APP_UI_SERVICE_MUSIC */
