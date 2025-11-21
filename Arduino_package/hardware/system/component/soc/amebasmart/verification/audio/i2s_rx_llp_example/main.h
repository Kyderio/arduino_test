#ifndef EXAMPLE_AUDIO_RECORDER_H
#define EXAMPLE_AUDIO_RECORDER_H

#include "ameba_soc.h"

#define SP_DMA_PAGE_SIZE	4096
#define SP_DMA_PAGE_NUM    	8
#define SP_FULL_BUF_SIZE	4096

typedef struct {
	GDMA_InitTypeDef       	SpRxGdmaInitStruct;              //Pointer to GDMA_InitTypeDef
	GDMA_InitTypeDef       	SpRxGdmaInitStructExt;              //Pointer to GDMA_InitTypeDef
} SP_RX_GDMA_STRUCT, *pSP_RX_GDMA_STRUCT;

typedef struct {
	u8 rx_gdma_own;
	u32 rx_addr;
	u32 rx_length;

} RX_BLOCK, *pRX_BLOCK;

typedef struct {
	RX_BLOCK rx_block[SP_DMA_PAGE_NUM];
	RX_BLOCK rx_full_block;
	u8 rx_gdma_cnt;
	u8 rx_usr_cnt;
	u8 rx_full_flag;

} SP_RX_INFO, *pSP_RX_INFO;

typedef struct {
	u8 rx_gdma_own;
	u32 rx_addr;
	u32 rx_length;

} RX_BLOCK_EXT, *pRX_BLOCK_EXT;

typedef struct {
	RX_BLOCK_EXT rx_block[SP_DMA_PAGE_NUM];
	RX_BLOCK_EXT rx_full_block;
	u8 rx_gdma_cnt;
	u8 rx_usr_cnt;
	u8 rx_full_flag;

} SP_RX_INFO_EXT, *pSP_RX_INFO_EXT;

typedef struct {

	u32 sp_clock;
	u32 sp_sample_rate;
	u32 channel_len;
	u32 word_len;
	u32 mono_stereo;
	u32 fifo_num;
	u32 multio;
	u32 tdmmode;
	u32 role;

} SP_OBJ, *pSP_OBJ;

#endif
