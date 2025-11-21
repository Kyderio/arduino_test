#ifndef _EXAMPLE_AUDIO_DAC_H_
#define _EXAMPLE_AUDIO_DAC_H_

#ifndef ENABLE
#define   ENABLE    1
#endif

#ifndef DISABLE
#define   DISABLE   0
#endif

#include "ameba_soc.h"

#define SP_DMA_PAGE_SIZE	512  // 48k-192  16k-512
#define SP_DMA_PAGE_SIZE_EXT 512

#define SP_DMA_PAGE_NUM    4
#define SP_DMA_PAGE_NUM_EXT 4

#define SP_ZERO_BUF_SIZE	128
#define SP_ZERO_BUF_SIZE_EXT	128
#define SP_FULL_BUF_SIZE	128
#define SP_FULL_BUF_SIZE_EXT	128

#define SP_MAX_DMA_PAGE_NUM    8


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
	u32 mono_stereo;
	u32 sp_sample_rate;
	u32 codec_sample_rate;
	u32 sp_channel_len;
	u32 codec_channel_len;
	u32 sp_data_len;
	u32 codec_data_len;
	u32 tdm_mode;
	u32 fifo_num;
	u32 multio;
	u32 din_sel;
	u32 role;

} SP_OBJ, *pSP_OBJ;

#endif

