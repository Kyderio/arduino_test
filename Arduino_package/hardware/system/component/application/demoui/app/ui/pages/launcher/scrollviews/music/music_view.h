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

#ifndef AMEBA_APPS_PANGU_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_MUSIC_VIEW_H
#define AMEBA_APPS_PANGU_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_MUSIC_VIEW_H

#include "app_common.h"

namespace Page
{

#define LV_DEMO_MUSIC_HANDLE_SIZE  20
#define ACTIVE_TRACK_CNT    3
#define INTRO_TIME          2000
#define BAR_COLOR1          lv_color_hex(0xe9dbfc)
#define BAR_COLOR2          lv_color_hex(0x6f8af6)
#define BAR_COLOR3          lv_color_hex(0xffffff)
#if LV_DEMO_MUSIC_LARGE
# define BAR_COLOR1_STOP     160
# define BAR_COLOR2_STOP     200
#else
# define BAR_COLOR1_STOP     80
# define BAR_COLOR2_STOP     100
#endif
#define BAR_COLOR3_STOP     (2 * LV_HOR_RES / 3)
#define BAR_CNT             20
#define DEG_STEP            (180/BAR_CNT)
#define BAND_CNT            4
#define BAR_PER_BAND_CNT    (BAR_CNT / BAND_CNT)

class MusicView
{
public:
    void Create(lv_obj_t* root);
    void Update();
    void MusicAlbumNext(bool next);
    void MusicPlay(uint32_t id);
    void MusicResume(void);
    void MusicPause(void);

public:
    struct
    {
        lv_obj_t* main_cont;
        lv_obj_t* spectrum_obj;
        lv_obj_t* title_label;
        lv_obj_t* artist_label;
        lv_obj_t* genre_label;
        lv_obj_t* album_img_obj;
        lv_obj_t* play_obj;
        lv_obj_t* loop_obj;
        lv_obj_t* rnd_obj;
        lv_obj_t* next_obj;
        lv_obj_t* pre_obj;
        lv_obj_t* pause_obj;
        lv_obj_t* slider_obj;
        lv_obj_t* time_obj;
    } Ui;

private:
    int32_t spectrum_i_ = 0;
    int32_t spectrum_i_pause_ = 0;
    uint32_t bar_ofs_ = 0;
    uint32_t spectrum_lane_ofs_start_ = 0;
    uint32_t bar_rot_ = 0;
    uint32_t time_act_ = 0;
    int32_t count_;
    lv_timer_t* sec_counter_timer_;
    uint32_t track_id_ = 0;
    bool playing_ = false;
    bool start_anim_ = false;
    lv_coord_t start_anim_values_[40];
    const uint16_t (*spectrum_)[4];
    uint32_t spectrum_len_;
    const uint16_t rnd_array_[30] = {994, 285, 553, 11, 792, 707, 966, 641, 852, 827, 44, 352, 146, 581, 490, 80, 729, 58, 695, 940, 724, 561, 124, 653, 27, 292, 557, 506, 382, 199};

private:
    void CreateWaveImage(lv_obj_t* parent);
    lv_obj_t* CreateSpectrumObj(lv_obj_t* parent);
    lv_obj_t* AlbumImgCreate(lv_obj_t * parent);
    lv_obj_t* CreateTitleBox(lv_obj_t * parent);
    lv_obj_t* CreateHandle(lv_obj_t * parent);
    lv_obj_t* CreateCtrlBox(lv_obj_t * parent);
    int32_t GetCos(int32_t deg, int32_t a);
    int32_t GetSin(int32_t deg, int32_t a);
    static void SpectrumDrawEventCb(lv_event_t* e);
    void OnSpectrumDrawEventCb(lv_event_t* e);
    static void AlbumGestureEventCb(lv_event_t* e);
    static void SpectrumEndCb(lv_anim_t * a);
    static void SpectrumAnimCb(void * a, int32_t v);
    void OnSpectrumAnimCb(int32_t v);
    static void PlayEventClickCb(lv_event_t * e);
    static void PrevClickEventCb(lv_event_t * e);
    static void NextClickEventCb(lv_event_t * e);
    void TrackLoad(uint32_t id);
    static void TimerCb(lv_timer_t* t);
     void OnTimerCb(lv_timer_t* t);
};

}

#endif // AMEBA_APPS_PANGU_APP_UI_PAGES_LAUNCHER_SCROLLVIEW_MUSIC_VIEW_H
