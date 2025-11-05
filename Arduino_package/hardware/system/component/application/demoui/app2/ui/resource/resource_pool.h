#ifndef AMEBA_APPS_IOT_APP_UI_RESOURCE_POOL
#define AMEBA_APPS_IOT_APP_UI_RESOURCE_POOL

#include "lvgl.h"

namespace ResourcePool
{
void        Init();
lv_font_t  *GetFont(const char *name);
const void *GetImage(const char *name);
const char *GetVrImageName(int32_t n);
}

#endif //AMEBA_APPS_IOT_APP_UI_RESOURCE_POOL
