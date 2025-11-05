/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef USBD_ERRNO_H
#define USBD_ERRNO_H

/* Includes ------------------------------------------------------------------*/

/* Exported defines ----------------------------------------------------------*/

#define UERR_INIT					0x20U /* Init error */
#define UERR_PERM       			0x21U /* Operation not permitted */
#define UERR_PROTO					0x22U /* Protocol error */
#define UERR_CHK					0x23U /* Check error */
#define UERR_OVERRANGE				0x24U /* Operation overrange */
#define UERR_NAND_BAD_BLOCK			0x25U /* NAND bad block */
#define UERR_NAND_WORN_BLOCK		0x26U /* NAND wore block */
#define UERR_NAND_BITFLIP_WARN		0x27U /* NAND bitflips < ECC level, corrected */
#define UERR_NAND_BITFLIP_ERROR		0x28U /* NAND bitflips equals to ECC level, corrected */
#define UERR_NAND_BITFLIP_FATAL		0x29U /* NAND bitflips higher than ECC level, cannot be corrected */

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

#endif /* USBD_ERRNO_H */

