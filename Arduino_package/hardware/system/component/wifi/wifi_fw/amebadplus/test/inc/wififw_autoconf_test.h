#ifndef __AUTOCONF_TEST_H__
#define __AUTOCONF_TEST_H__

#define CONFIG_TEST_VERA        0
#define CONFIG_TEST                 1

#if CONFIG_TEST_VERA
#define CONFIG_LPS_CG_TEST          0
#define CONFIG_LPS_PG_TEST	    0
#endif

#if CONFIG_TEST
#define CONFIG_FWLB_TEST				1
#define CONFIG_INT_TEST             1
#define CONFIG_REG_TEST             1
#define CONFIG_BUF_TEST             1
#define CONFIG_IOPATH_TEST          1
#define CONFIG_FW_LBK_TEST          1
#define CONFIG_COEX_TEST            0
#define CONFIG_TRXRPT_TEST          0
#endif


#endif
