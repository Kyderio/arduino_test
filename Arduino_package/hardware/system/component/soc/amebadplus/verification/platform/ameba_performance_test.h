#ifndef _AMEBA_PPERF_TEST_H_
#define _AMEBA_PPERF_TEST_H_


typedef struct {
	u32 pll;

	u32 km4_clk;
	u32 km0_clk;
	u32 spic_clk;

	u32 sram_clk;
	u32 psramc_clk;
	u32 hperi_clk;

} Pperf_ClkType, *P_Pperf_ClkType;


typedef struct {
	u32 srcaddr;
	u32 dstaddr;
	u32 cpylen;
} Pperf_TestRegion, *P_Pperf_TestRegion;

typedef enum {
	PPERF_SRAM_TO_PSRAM = 0,
	PPERF_PSRAM_TO_SRAM,
	PPERF_SRAM_TO_SRAM,
	PPERF_PSRAM_TO_PSRAM,

	PPERF_FINAL_ITEM,

} Pperf_TestItem;

typedef enum {
	PPERF_MASTER_CPU = 0,
	PPERF_MASTER_GDMA,

	PPERF_FINAL_MASTER,

} Pperf_MasterID;

#endif

