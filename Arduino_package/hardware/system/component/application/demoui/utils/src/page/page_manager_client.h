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

#ifndef AMEBA_APPS_PANGU_UTILS_PAGE_MANAGER_CLIENT_H
#define AMEBA_APPS_PANGU_UTILS_PAGE_MANAGER_CLIENT_H

#include <vector>
#include <stack>

#include "ui/page/page_manager.h"
#include "ui/page/page_base.h"
#include "page_base_priv.h"

class PageManagerClient : public PageManager
{
public:
	enum {
		PAGE_STATE_IDLE,
		PAGE_STATE_LOAD,
		PAGE_STATE_WILL_APPEAR,
		PAGE_STATE_DID_APPEAR,
		PAGE_STATE_ACTIVITY,
		PAGE_STATE_WILL_DISAPPEAR,
		PAGE_STATE_DID_DISAPPEAR,
		PAGE_STATE_UNLOAD
	};

	typedef enum {
		DRAG_NONE,
		DRAG_LEFT_TO_RIGHT,
		DRAG_RIGHT_TO_LEFT,
		DRAG_TOP_TO_BOTTOM,
		DRAG_BOTTOM_TO_TOP
	} DragDirection;


	typedef enum {
		ROOT_DRAG_DIR_NONE,
		ROOT_DRAG_DIR_HOR,
		ROOT_DRAG_DIR_VER,
	} RootDragDir;

	typedef void(*lv_anim_setter)(void *, int32_t);

	typedef int32_t(*lv_anim_getter)(void *);

	typedef struct {
		struct {
			int32_t start;
			int32_t end;
		} Enter;

		struct {
			int32_t start;
			int32_t end;
		} Exit;
	} AnimValue;

	typedef struct {
		lv_anim_setter setter;
		lv_anim_getter getter;
		RootDragDir drag_dir;
		AnimValue push;
		AnimValue pop;
	} LoadAnimAttr;

	struct {
		bool is_switch_req;
		bool is_busy;
		bool is_pushing;

		AnimAttr current;
		AnimAttr global;
	} AnimState;
public:
	PageManagerClient();
	~PageManagerClient();
	PageBase   *RegisterPage(PageBase *page_base, const char *page_name);
	bool        UnRegisterPage(const char *page_name);
	PageBase   *Start(const char *page_name, const PageBase::Stash *stash = nullptr);
	PageBase   *Finish();
	void        SetGlobalLoadAnimType(int32_t anim, uint16_t time, lv_anim_path_cb_t path);

private:
	PageBase         *FindPageInPool(const char *name);
	PageBase         *FindPageInStack(const char *name);
	PageBase         *GetStackTop();
	PageBase         *GetStackTopAfter();
	void              SetStackClear(bool keep_bottom = true);
	void              SetStackTopClear(const char *name);
	bool              FourceUnload(PageBase *base);
	bool              RegisterCore(PageBase *base, const char *name);
	bool              UnRegisterCore(const char *name);
	bool              GetLoadAnimAttr(uint8_t anim, LoadAnimAttr *attr);
	bool              GetIsOverAnim(uint8_t anim);
	bool              GetIsMoveAnim(uint8_t anim);
	void              AnimDefaultInit(lv_anim_t *a);
	bool              GetCurrentLoadAnimAttr(LoadAnimAttr *attr);
	const char       *GetPagePrevName();
	PageBase         *BackLauncher(const PageBase::Stash *stash);

	LoadAnim          GetCurrentLoadAnimType();
	static void       OnRootDragEvent(lv_event_t *event);
	static void       OnRootAnimFinish(lv_anim_t *a);
	static void       OnRootAsyncLeave(void *base);
	void              RootEnableDrag(lv_obj_t *root);
	static void       RootGetDragPredict(lv_coord_t *x, lv_coord_t *y);

	void              SwitchTo(PageBase *base, bool is_push_act,
							   const PageBase::Stash *stash = nullptr);
	void              SwitchSelf(PageBase *node, const PageBase::Stash *stash);
	static void       OnSwitchAnimFinish(lv_anim_t *a);
	void              SwitchAnimCreate(PageBase *base);
	void              SwitchAnimTypeUpdate(PageBase *base);
	bool              SwitchReqCheck();
	bool              SwitchAnimStateCheck();

	int32_t StateLoadExecute(PageBase *base);
	int32_t StateWillAppearExecute(PageBase *base);
	int32_t StateDidAppearExecute(PageBase *base);
	int32_t StateWillDisappearExecute(PageBase *base);
	int32_t StateDidDisappearExecute(PageBase *base);
	int32_t StateUnloadExecute(PageBase *base);
	void    StateUpdate(PageBase *base);
	int32_t GetState();

private:
	std::vector<PageBase *> page_pool_;
	std::stack<PageBase *>  page_stack_;
	PageBase              *page_prev_;
	PageBase              *page_current_;
};

#endif //AMEBA_APPS_PANGU_UTILS_PAGE_MANAGER_CLIENT_H
