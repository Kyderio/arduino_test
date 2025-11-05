#ifndef RTK_CFU_FILE_H_
#define RTK_CFU_FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RTK_CFU_FILE_ARRAY 1
//#define RTK_CFU_FILE_FS 1
//#define RTK_CFU_FILE_FS_TEST 1

#if (defined(RTK_CFU_FILE_ARRAY) && RTK_CFU_FILE_ARRAY) && (defined(RTK_CFU_FILE_FS) && RTK_CFU_FILE_FS)
#error "!!!RTK_CFU_FILE_ARRAY and RTK_CFU_FILE_FS should not define 1 at the same time!!!"
#endif

#define FwBinCountMax       20
#define FwDirnameLenMax     128
#define FwNameLenMax        128
#define FwPathLenMax        (FwDirnameLenMax + FwNameLenMax)

#define APP_DATA_1_PATTERN        "_App_Data1."

#define FWImageTyeBOOT      5

typedef struct {
	char OfferName[FwNameLenMax];
	char SrcBinName[FwNameLenMax];
	uint8_t image_type;
	bool is_download;
	bool is_srcbin_exist;
} T_FwFile_Unit;

typedef struct {
	char offerfile_dirname[FwDirnameLenMax];
	char srcbinfile_dirname[FwDirnameLenMax];
	T_FwFile_Unit fileName[FwBinCountMax];
} T_FwFile;

extern T_FwFile FwFiles;

bool rtk_cfu_file_init(void);

int rtk_cfu_file_open(char *file_name);

int rtk_cfu_file_read(int fd, char *buffer, uint32_t size);

int rtk_cfu_file_seek_set(int fd, uint32_t offset);

int rtk_cfu_file_close(int fd);

int rtk_cfu_file_access(char *file_name);

bool rtk_cfu_get_payload_bins(char *file_path);

bool rtk_cfu_get_offer_bins(char *file_path);

#ifdef __cplusplus
}
#endif

#endif