/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _FLOADER_CMDBUF_H_
#define _FLOADER_CMDBUF_H_

/**
 * @brief PART1.Cmd Buffer variable and function
 *
 */
/* 1. define frame basic info*/
#define FRAME_BODY_LEN 1030
#define CMD_FRAME_NUM 64
#define FRAME_HEADER_LEN 4

struct FrameHeader {
	uint8_t start;
	uint8_t len_l;
	uint8_t len_h;
	uint8_t len_xor;
};

struct CmdTable {
	struct FrameHeader frame_header;
	uint8_t cmd_list[FRAME_BODY_LEN];
};

/*1.1 define global varible to store cmd frame*/
extern struct CmdTable cmd_table[CMD_FRAME_NUM];

/*1.2 define write/read cmd index */
extern struct CmdTable *cur_cmd; 		//Points to the frame currently being received
extern volatile int wcmd_idx; 			// write cmd index
extern volatile int rcmd_idx; 			// read cmd index


/**
 * @brief Get the free cmdbuf entry but do not increment the index
 *
 * @return free struct CmdTable* area
 */
struct CmdTable *get_free_cmdbuf(void);

/**
 * @brief increments the write index and marks the command as pending after interrupt processing is complete.
 *
 */
void enqueue_cmdbuf(void);
/**
 * @brief Get the pending cmdbuf to be processed and increment the read index
 *
 * @return struct CmdTable*
 */
struct CmdTable *get_pending_cmdbuf(void);

/**
 * @brief Get the free cmdbuf count object
 *
 * @return  free cmdbuf number
 */
int get_free_cmdbuf_count(void);
/**
 * @brief Get the cmdbuf index currently to be written
 *
 * @return write index
 */
uint32_t get_cmd_write_index(void);
/**
 * @brief Get the cmdbuf index currently to be read
 *
 * @return read index
 */
uint32_t get_cmd_read_index(void);
/**
 * @brief Reset cmdbuf parameters
 *
 * @return None
 */
void reset_cmdbuf(void);

#endif