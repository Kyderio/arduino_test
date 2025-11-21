/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _SECTION_CONFIG_ROM_H_
#define _SECTION_CONFIG_ROM_H_

#define RAM_VECTOR_TABLE1_SECTION          \
        SECTION(".ram_vector_table1")
#define RAM_VECTOR_TABLE2_SECTION          \
        SECTION(".ram_vector_table2")
#define RAM_VECTOR_TABLE3_SECTION          \
        SECTION(".ram_vector_table3")

//3 //3 Hal Section
#define HAL_ROM_TEXT_SECTION                         \
        SECTION(".hal.rom.text")

#define HAL_ROM_ENTRY_NS_SECTION                         \
        SECTION(".hal.rom.entryns.rodata")

#define HAL_ROM_DATA_SECTION                         \
        SECTION(".hal.rom.rodata")

#define HAL_ROM_BSS_SECTION                         \
        SECTION(".hal.rom.bss")

#define HAL_ROM_BSS_SECTION_BANK		\
        SECTION(".hal.rom.bank.bss")

//3 Shell
#define SHELL_ROM_TEXT_SECTION	HAL_ROM_TEXT_SECTION
#define SHELL_ROM_BSS_SECTION	HAL_ROM_BSS_SECTION
#define SHELL_ROM_DATA_SECTION	HAL_ROM_DATA_SECTION


//3 Apple  Section
#define APPLE_ROM_TEXT_SECTION                      \
        SECTION(".apple.rom.text")

#define APPLE_ROM_DATA_SECTION                      \
        SECTION(".apple.rom.rodata")

//3 Libc Section
#define LIBC_ROM_TEXT_SECTION                      \
        SECTION(".libc.rom.text")

#define LIBC_ROM_DATA_SECTION                      \
        SECTION(".libc.rom.rodata")

//3 SSL Section
#define SSL_ROM_TEXT_SECTION				\
        SECTION(".ssl.rom.text")
#define SSL_ROM_DATA_SECTION				\
        SECTION(".ssl.rom.rodata")
#define SSL_RAM_MAP_SECTION				\
        SECTION(".ssl_ram_map")



#endif //_SECTION_CONFIG_ROM_H_
