/******************************************************************************
 *
 * Copyright(c) 2016 - 2017 Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 *****************************************************************************/
#ifndef RTW_COEX_VERSION_H
#define RTW_COEX_VERSION_H

/*
 * Update Rule @ 20250327:
 * 1. coex version / wl_fw version (xx.xx.xx.xx)
 *      1-1. branch id:         master/v1.0/v1.1
 *      1-2. Hot-Fix-version:   ++ if modification has no effects on other co-work module, sort of mistake typo etc.
 *      1-3. sub-version:       ++ if modification that has no effects on other co-work module, sort of new func add, arch change etc.
 *      1-4. main-version:      ++ if modification that has effects on other co-work module, sort of interfaces change etc.
 * 2. bt_fw version (xx.xx)
 *      2-1. followed by bt fw team (BT FW coex version -> main-version + 1 if update.)
 * 3. wlfw_desired / btfw_desired
 *      3-1. match criteria
 *          3-1-1. wlfw_desired: main-version ==, sub-version <= wl_fw version
 *          3-1-2. btfw_desired: == bt_fw version
 *      3-2. wlfw_desired: follow WL_FW update
 *      3-3. btfw_desired: follow BT_FW update
 * 4. update log
 */

enum COEX_VERSION_MATCH_TYPE {
	COEX_VER_MATCH_DISABLE = 0,
	COEX_VER_MATCH_MISMATCH = 1,
	COEX_VER_MATCH_MATCHED = 2,
	COEX_VER_MATCH_INVALID
};

/* CONFIG_COEX_VERSION / CONFIG_COEX_VER_WLFW_DESIRED Format
 * [31:24] -> main-version
 * [23:16] -> sub-version
 * [15:8]  -> Hot-Fix-version
 * [7:0]   -> branch ID, ex: 0x00-> Master-Branch; 0x01->v1.0; 0X02->v1.1
 */

#if defined(CONFIG_AMEBASMART)
#define CONFIG_COEX_VERSION                 0x01020200
#define CONFIG_COEX_VER_WLFW_DESIRED        0x00000000
#define CONFIG_COEX_VER_BTFW_DESIRED        0x0707
#elif defined(CONFIG_AMEBALITE)
#define CONFIG_COEX_VERSION                 0x01020200
#define CONFIG_COEX_VER_WLFW_DESIRED        0x00000000
#define CONFIG_COEX_VER_BTFW_DESIRED        0x0707
#elif defined(CONFIG_AMEBADPLUS)
#define CONFIG_COEX_VERSION                 0x01020200
#define CONFIG_COEX_VER_WLFW_DESIRED        0x00000000
#define CONFIG_COEX_VER_BTFW_DESIRED        0x0606
#elif defined(CONFIG_AMEBAGREEN2)
#define CONFIG_COEX_VERSION                 0x01010100
#define CONFIG_COEX_VER_WLFW_DESIRED        0x00000000
#define CONFIG_COEX_VER_BTFW_DESIRED        0x0606
#elif defined(CONFIG_AMEBAL2)
#define CONFIG_COEX_VERSION                 0x01010100
#define CONFIG_COEX_VER_WLFW_DESIRED        0x00000000
#define CONFIG_COEX_VER_BTFW_DESIRED        0x0000
#elif defined(CONFIG_AMEBASMARTPLUS)
#define CONFIG_COEX_VERSION                 0x01010100
#define CONFIG_COEX_VER_WLFW_DESIRED        0x00000000
#define CONFIG_COEX_VER_BTFW_DESIRED        0x0000
#elif defined(CONFIG_AMEBAD)
#define CONFIG_COEX_VERSION                 0x01010100
#define CONFIG_COEX_VER_WLFW_DESIRED        0x00000000
#define CONFIG_COEX_VER_BTFW_DESIRED        0x0000
#else
#error "Please config coex setting for support new IC!!!"
#endif


/*
 *  update version match log
 *  order: new date first

 *  date:
    version_xxx:
    log:

 *  date: 2025-04-11
    version_amebasmart:     coex: 0x01020200; wl_fw: 0x00000000; bt_fw: 0x0707;
    version_amebalite:      coex: 0x01020200; wl_fw: 0x00000000; bt_fw: 0x0707;
    version_amebadplus:     coex: 0x01020200; wl_fw: 0x00000000; bt_fw: 0x0606;
    log: ++ coex version for policy format change(struct->union)

 *  date: 2025-03-31
    version_amebasmart:     coex: 0x01010200; wl_fw: 0x00000000; bt_fw: 0x0707;
    version_amebalite:      coex: 0x01010200; wl_fw: 0x00000000; bt_fw: 0x0707;
    version_amebadplus:     coex: 0x01010200; wl_fw: 0x00000000; bt_fw: 0x0606;

 *  date: 2025-03-27
    version_amebasmart:     coex: 0x01010100; wl_fw: 0x00000000; bt_fw: 0x0707;
    version_amebalite:      coex: 0x01010100; wl_fw: 0x00000000; bt_fw: 0x0707;
    version_amebadplus:     coex: 0x01010100; wl_fw: 0x00000000; bt_fw: 0x0000;
    version_amebagreen2:    coex: 0x01010100; wl_fw: 0x00000000; bt_fw: 0x0000;
    version_amebaL2:        coex: 0x01010100; wl_fw: 0x00000000; bt_fw: 0x0000;
    version_amebasmartplus: coex: 0x01010100; wl_fw: 0x00000000; bt_fw: 0x0000;
    log: initial commit
 */

#endif
