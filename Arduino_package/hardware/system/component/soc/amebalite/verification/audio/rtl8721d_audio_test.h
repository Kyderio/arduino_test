/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */
#ifndef _RTL8721D_AUDIO_TEST_H_
#define _RTL8721D_AUDIO_TEST_H_

#include "ameba_soc.h"

struct audio_test {
	GDMA_InitTypeDef       	SpTxGdmaInitStruct;              //Pointer to GDMA_InitTypeDef
	GDMA_InitTypeDef       	SpRxGdmaInitStruct;              //Pointer to GDMA_InitTypeDef
	GDMA_InitTypeDef       	SpTxGdmaInitStructExt;              //Pointer to GDMA_InitTypeDef
	GDMA_InitTypeDef       	SpRxGdmaInitStructExt;              //Pointer to GDMA_InitTypeDef

	u32 audio_tx_isr_cnt;	//current tx isr count
	u32 audio_tx_isr_cnt1;	//current tx isr count
	u32 audio_rx_isr_cnt;	//current rx isr count
	u32 audio_rx_isr_cnt1;	//current rx isr count

	u32 mono_val;	//when i2s playtone, set mono initial value
	u32 stereo_left_val;	//when i2s playtone, set stereo left channel init value
	u32 stereo_right_val;	//when i2s playtone, set stereo right channel init value
	u32 stereo_left_val_1;	//when i2s playtone, set stereo left channel init value
	u32 stereo_right_val_1;	//when i2s playtone, set stereo right channel init value
	u32 numBlock;
	u32 bRx1stBlk;
};

/* GDMA transmission define */
#define GDMA_SINGLE_MAX_SIZE			(128*30)
#define GDMA_SINGLE_MAX_SIZE1			(128*30)


#define SP_TX_DMA_PAGE_SIZE	512  // 48k-192
#define SP_TX_DMA_PAGE_NUM    4
#define SP_ZERO_BUF_SIZE	128

#define SP_RX_DMA_PAGE_SIZE		4096
#define SP_RX_DMA_PAGE_NUM    	8
#define SP_FULL_BUF_SIZE		128


#define RECORD_DET_TO	10

typedef struct {
	GDMA_InitTypeDef       	SpTxGdmaInitStruct;              //Pointer to GDMA_InitTypeDef
	GDMA_InitTypeDef       	SpRxGdmaInitStruct;              //Pointer to GDMA_InitTypeDef
} SP_GDMA_STRUCT, *pSP_GDMA_STRUCT;

typedef struct {
	u8 tx_gdma_own;
	u32 tx_addr;
	u32 tx_length;

} TX_BLOCK, *pTX_BLOCK;

typedef struct {
	TX_BLOCK tx_block[SP_TX_DMA_PAGE_NUM];
	TX_BLOCK tx_zero_block;
	u8 tx_gdma_cnt;
	u8 tx_usr_cnt;
	u8 tx_empty_flag;

} SP_TX_INFO, *pSP_TX_INFO;

typedef struct {

	u32 sp_clock;
	u32 mono_stereo;
	u32 sp_sample_rate;
	u32 codec_sample_rate;
	u32 sp_data_len;
	u32 sp_channel_len;
	u32 codec_data_len;
	u32 codec_channel_len;

} SP_TX_OBJ, *pSP_TX_OBJ;

typedef struct {
	u8 rx_gdma_own;
	u32 rx_addr;
	u32 rx_length;
} RX_BLOCK, *pRX_BLOCK;

typedef struct {
	RX_BLOCK rx_block[SP_RX_DMA_PAGE_NUM];
	RX_BLOCK rx_full_block;
	u8 rx_gdma_cnt;
	u8 rx_usr_cnt;
	u8 rx_full_flag;

} SP_RX_INFO, *pSP_RX_INFO;

typedef struct {

	u32 sp_clock;
	u32 mono_stereo;
	u32 sp_sample_rate;
	u32 codec_sample_rate;
	u32 tdm_mode;
	u32 fifo_num;
	u32 din_sel;
	u32 sp_data_len;
	u32 sp_channel_len;
	u32 codec_data_len;
	u32 codec_channel_len;

} SP_RX_OBJ, *pSP_RX_OBJ;

#endif
