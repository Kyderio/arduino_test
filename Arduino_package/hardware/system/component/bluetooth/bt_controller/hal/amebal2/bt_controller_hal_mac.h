#ifndef BT_CONTROLLER_HAL_MAC_H
#define BT_CONTROLLER_HAL_MAC_H

#include <ameba.h>
#include <bt_controller_hal_mac_reg.h>

#define BT_CONTROLLER_CLK_CFG_32000                     0
#define BT_CONTROLLER_CLK_CFG_32768                     1

#define BT_CONTROLLER_BT_REQ_PRI_HIGH                   1
#define BT_CONTROLLER_BT_REQ_PRI_LOW                    0

#define BT_CONTROLLER_US_TO_FREERUN_CNT(us)             ((us) << 2)
#define BT_CONTROLLER_FREERUN_CNT_TO_US(cnt)            ((cnt) >> 2)

#define BT_CONTROLLER_RX_DESC_SIZE                      8
#define BT_CONTROLLER_TX_CMD_SIZE                       4
#define BT_CONTROLLER_RX_CMD_SIZE                       7
#define BT_CONTROLLER_CMD_MAX_SIZE                      BT_CONTROLLER_RX_CMD_SIZE

struct bt_controller_rx_descriptor {
	uint32_t rx_pkt_len_bit : 14;
	uint32_t fcs_err : 1;
	uint32_t rsvd : 1;
	uint32_t rssi : 14;
	uint32_t rx_ci : 2;
	uint32_t instant : 32;   //unit 0.25us, rx header
};

struct bt_controller_hal_rx_cfg {
	struct bt_reg_rxcmd_cfg0 rx_cfg0;
	struct bt_reg_rxcmd_cfg1 rx_cfg1;
	struct bt_reg_rxcmd_cfg2 rx_cfg2;
	struct bt_reg_rxcmd_cfg3 rx_cfg3;
	struct bt_reg_rxcmd_cfg4 rx_cfg4;
	struct bt_reg_rxcmd_cfg5 rx_cfg5;
	struct bt_reg_rxcmd_cfg6 rx_cfg6;
};

struct bt_controller_hal_tx_cfg {
	struct bt_reg_txcmd_cfg0 tx_cfg0;
	struct bt_reg_txcmd_cfg1 tx_cfg1;
	struct bt_reg_txcmd_cfg2 tx_cfg2;
	struct bt_reg_txcmd_cfg3 tx_cfg3;
};

union bt_controller_hal_rx_cfg_set {
	struct bt_controller_hal_rx_cfg rx_cfg;
	uint32_t raw_data[BT_CONTROLLER_RX_CMD_SIZE];
};

union bt_controller_hal_tx_cfg_set {
	struct bt_controller_hal_tx_cfg tx_cfg;
	uint32_t raw_data[BT_CONTROLLER_TX_CMD_SIZE];
};

void bt_controller_hal_power_on(void);
void bt_controller_hal_power_off(void);

void bt_controller_hal_mac_init(IRQ_FUN bt_controller_irq_hdl);
void bt_controller_hal_mac_enable(void);
void bt_controller_hal_mac_disable(void);
void bt_controller_hal_mac_deinit(void);

void bt_controller_hal_mac_freerun_timer_set_32k_clock_cfg(uint8_t clk_setting);

void bt_controller_freerun_timer_start(void);
void bt_controller_freerun_timer_stop(void);
void bt_controller_freerun_timer_reset(void);
uint32_t bt_controller_hal_read_freerun_cnt(void);
void bt_controller_freerun_timer_set_cnt(uint32_t cnt);
void bt_controller_freerun_timer_clear_cnt(void);

void bt_controller_free_run_timer_enter_32k_mode(bool benter_32k_mode);

void bt_controller_mac_set_fec_config(uint8_t *p_crc_init_val);
void bt_controller_mac_rx_filter_config(uint8_t enable_crc_error);
void bt_controller_mac_set_chnl_info_config(uint8_t chnl_idx, uint8_t dis_rf_ps, uint8_t tx_gain);
void bt_controller_mac_set_tx_cmd(void *ptx_cmd);
void bt_controller_mac_set_rx_cmd(void *prx_cmd);
uint8_t whiten_le_channel(uint8_t chnl);

#endif