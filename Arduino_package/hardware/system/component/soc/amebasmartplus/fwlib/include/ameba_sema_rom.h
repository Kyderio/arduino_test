/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _AMEBA_SEMA_H_
#define _AMEBA_SEMA_H_

/** @defgroup IPC_Valid_SEMID
  * @{
  */
#define IS_IPC_VALID_SEMID(SEM_ID) ((SEM_ID) < 16)
/** @} */

/**
  * @brief IPC SEM IDX
  */
typedef enum {
	IPC_SEM_IMQ = 0,
	IPC_SEM_FLASH,
	IPC_SEM_OTP,
	IPC_SEM_CRYPTO,
	IPC_SEM_DIAGNOSE,
	IPC_SEM_MAX = 16,			/* can't be this value, total 16 ipc semaphores*/
} IPC_SEM_IDX;
/** @} */


/* Exported functions --------------------------------------------------------*/
/** @defgroup IPC_Exported_Functions IPC Exported Functions
  * @{
  */
u32 IPC_SEMTake(u32 SEM_Idx, u32 timeout);
u32 IPC_SEMFree(u32 SEM_Idx);
void IPC_SEMDelayStub(void (*pfunc)(uint32_t));
void IPC_patch_function(void (*pfunc1)(uint32_t), void (*pfunc2)(uint32_t), uint32_t lock_id);
/** @} */

#endif