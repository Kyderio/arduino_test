#ifndef __WIFIFW_MEM_IO_TEST_H__
#define __WIFIFW_MEM_IO_TEST_H__

#define IOPATH_CATEGORY_NUM   1
#define RPT_TESTNUM			10
#define RPT_SIZE			8

enum HIOE_MEM_BK_TEST {
	HIOERXFF = 1,
	HIOERPTBUF,
	HIOEMACREG,
	HIOEBBREG,
	HIOERFREG,
	HIOEMACIDCAM,
	HIOECSIFF,
};

typedef bool(*_IOPATH_Test_Func_Ptr)(void);

extern void CPUIOPATHTest(u8 testcnt);
extern void HIOEMEMBackupRestoreTest(u8 testid);
void bcnelagg_test(void);
#endif
