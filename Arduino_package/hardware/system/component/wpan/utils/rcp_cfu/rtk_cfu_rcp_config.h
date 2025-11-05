#ifndef RTK_CFU_RCP_CONFIG_H_
#define RTK_CFU_RCP_CONFIG_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

extern char RcpConfigBin[];

bool rtkrcp_config_parse(void);
bool rtkrcp_config(void);
bool rtkrcp_config_flowctl(void);
bool test_after_config_cfu_flowctl(void);

#ifdef __cplusplus
}
#endif

#endif