#ifndef _EXAMPLE_AUDIO_DAC_H_
#define _EXAMPLE_AUDIO_DAC_H_

#include "ameba_soc.h"

#define SP_DMA_PAGE_SIZE	512
#define SP_DMA_PAGE_NUM    4

typedef struct {
	GDMA_InitTypeDef       	SpTxGdmaInitStruct;              //Pointer to GDMA_InitTypeDef
	GDMA_InitTypeDef       	SpRxGdmaInitStruct;              //Pointer to GDMA_InitTypeDef
	GDMA_InitTypeDef       	SpTxGdmaInitStructExt;              //Pointer to GDMA_InitTypeDef
	GDMA_InitTypeDef       	SpRxGdmaInitStructExt;              //Pointer to GDMA_InitTypeDef
} SP_GDMA_STRUCT, *pSP_GDMA_STRUCT;

typedef struct {
	u8 tx_gdma_own;
	u32 tx_addr;
	u32 tx_length;

} TX_BLOCK, *pTX_BLOCK;

typedef struct {
	TX_BLOCK tx_block[SP_DMA_PAGE_NUM];
	TX_BLOCK tx_zero_block;
	u8 tx_gdma_cnt;
	u8 tx_usr_cnt;
	u8 tx_empty_flag;

} SP_TX_INFO, *pSP_TX_INFO;

typedef struct {
	u8 tx_gdma_own;
	u32 tx_addr;
	u32 tx_length;

} TX_BLOCK_EXT, *pTX_BLOCK_EXT;

typedef struct {
	TX_BLOCK_EXT tx_block[SP_DMA_PAGE_NUM];
	TX_BLOCK_EXT tx_zero_block;
	u8 tx_gdma_cnt;
	u8 tx_usr_cnt;
	u8 tx_empty_flag;

} SP_TX_INFO_EXT, *pSP_TX_INFO_EXT;

typedef struct {
	u32 sp_clock;
	u32 mono_stereo;
	u32 sp_sample_rate;
	u32 codec_sample_rate;
	u32 channel_len;
	u32 word_len;
	u32 fifonum;
	u32 multio;
	u32 role;

} SP_OBJ, *pSP_OBJ;

#endif

