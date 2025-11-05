/*
 * Copyright (c) 2022 Realtek, LLC.
 * All rights reserved.
 *
 * Licensed under the Realtek License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License from Realtek
 *
 * Unless reqUired by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AMEBA_APPS_PANGU_WIDGET_SCROLL_VIEW_H
#define AMEBA_APPS_PANGU_WIDGET_SCROLL_VIEW_H
#include <vector>
#include "scroll_view_child_base.h"

#define GESTURE_DISTANCE 100
#define GESTURE_SHAKE_DISTANCE 80

class ScrollView
{
public:
	typedef enum {
		SCROLL_NONE = 0x00,
		SCROLL_LEFT_TO_RIGHT_DIR = 0x01,
		SCROLL_RIGHT_TO_LEFT_DIR = 0x02,
		SCROLL_UP_TO_DOWN_DIR = 0x03,
		SCROLL_DOWN_TO_UP_DIR = 0x04,
	} Scroll_dir_t;

	typedef enum {
		DRAG_NONE,
		DRAG_LEFT_TO_RIGHT,
		DRAG_RIGHT_TO_LEFT,
		DRAG_TOP_TO_BOTTOM,
		DRAG_BOTTOM_TO_TOP
	} DragDirection;

public:
	ScrollViewChildBase              *left_child_;
	ScrollViewChildBase              *right_child_;
	ScrollViewChildBase              *up_child_;
	ScrollViewChildBase              *down_child_;

public:
	ScrollView();
	~ScrollView();
	void                 scrollViewSetSize(int32_t size_x_, int32_t size_y_);
	void                 scrollViewAddChild(ScrollViewChildBase *base, const char *name,
											int32_t x, int32_t y, lv_dir_t scroll_dir);
	ScrollViewChildBase *scrollViewSetActive(const char *name);
	ScrollViewChildBase *scrollViewGetActiveChild();
	void                 scrollViewChangeChildPos(const char *name, int32_t pos_x, int32_t pos_y);
	void                 scrollViewChangeChildScrollDir(const char *name, lv_dir_t scroll_dir);
	void                 scrollViewDel(const char *name);

	void                 scrollViewChildCreate(lv_obj_t *page_base,
			ScrollViewChildBase *scroll_view_base);

	lv_obj_t            *scrollViewGetChildRoot(const char *name);

	ScrollViewChildBase *findScrollViewChildInPool(const char *name);
	ScrollViewChildBase *findLeftScrollViewChild(const char *name);
	ScrollViewChildBase *findRightScrollViewChild(const char *name);
	ScrollViewChildBase *findUpScrollViewChild(const char *name);
	ScrollViewChildBase *findDownScrollViewChild(const char *name);

private:
	typedef enum {
		LOAD_ANIM_GLOBAL = 0,

		LOAD_ANIM_OVER_LEFT,
		LOAD_ANIM_OVER_RIGHT,
		LOAD_ANIM_OVER_TOP,
		LOAD_ANIM_OVER_BOTTOM,

		LOAD_ANIM_MOVE_LEFT,
		LOAD_ANIM_MOVE_RIGHT,
		LOAD_ANIM_MOVE_TOP,
		LOAD_ANIM_MOVE_BOTTOM,

		LOAD_ANIM_FADE_ON,
		LOAD_ANIM_NONE,

		_LOAD_ANIM_LAST = LOAD_ANIM_NONE
	} LoadAnim_t;

	typedef enum {
		ROOT_DRAG_DIR_NONE,
		ROOT_DRAG_DIR_HOR,
		ROOT_DRAG_DIR_VER,
	} RootDragDir;

	/* Animated setter  */
	typedef void(*lv_anim_setter_t)(void *, int32_t);

	/* Animated getter  */
	typedef int32_t(*lv_anim_getter_t)(void *);

	/* Animation switching record  */
	typedef struct {
		struct {
			int32_t start;
			int32_t end;
		} enter;

		struct {
			int32_t start;
			int32_t end;
		} exit;
	} AnimValue_t;

	typedef struct {
		lv_anim_setter_t setter;
		lv_anim_getter_t getter;
		RootDragDir    drag_dir;
		AnimValue_t      push;
		AnimValue_t      pop;
	} LoadAnimAttr;

	typedef struct {
		uint8_t           type;
		uint16_t          time;
		lv_anim_path_cb_t path;
	} AnimAttr;

	std::vector<ScrollViewChildBase *> scrollview_base_pool_;
	ScrollViewChildBase              *child_current_;
	ScrollViewChildBase              *child_pre_;
	int32_t                           size_x_;
	int32_t                           size_y_;
	AnimAttr                        anim_global_;
	lv_style_t                        style_;

private:
	static void          OnRootDragNotifyEvent(lv_event_t *event);
	void                 RootEnableNotifyDrag(lv_obj_t *root);

	ScrollViewChildBase *FindScrollViewChildInPoolWithPos(int32_t pos_x, int32_t pos_y);

	void                 SetGlobalLoadAnimType(LoadAnim_t anim, uint16_t time, lv_anim_path_cb_t path);
	ScrollViewChildBase *MoveTo(ScrollViewChildBase *new_child, bool anim_en);
	void                 SwitchAnimCreate(ScrollViewChildBase *base);
	void                 AnimDefaultInit(lv_anim_t *a);
	bool                 GetCurrentLoadAnimAttr(LoadAnimAttr *attr);
	bool                 GetLoadAnimAttr(uint8_t anim, LoadAnimAttr *attr);
	static void          OnSwitchAnimFinish(lv_anim_t *a);
};
#endif //AMEBA_APPS_PANGU_WIDGET_SCROLL_VIEW_H