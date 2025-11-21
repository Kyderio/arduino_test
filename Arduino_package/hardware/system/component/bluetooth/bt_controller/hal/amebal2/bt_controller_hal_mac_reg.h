#ifndef BT_CONTROLLER_HAL_MAC_REG_H
#define BT_CONTROLLER_HAL_MAC_REG_H

//Doc: Mac_Reg_Spec_v11

#define BT_REG_BASE                              0x41840000


#define REG_CLOCK_FEN_CFG                                   0x00
#define BT_REG_FREERUN_CNT_CFG                              0x04
#define BT_REG_PS_TIMER_INT                                 0x08
#define BT_REG_FREERUN_CNT                                  0x0C
#define BT_REG_TRX_DELAY                                    0x10
#define BT_REG_STR_RX_CFG                                   0x14
#define BT_REG_STR_TX_CFG                                   0x18
#define BT_REG_TRX_CMD_CFG                                  0x1C
#define BT_REG_TXCMD_CFG0                                   0x20
#define BT_REG_TXCMD_CFG1                                   0x24
#define BT_REG_TXCMD_CFG2                                   0x28
#define BT_REG_TXCMD_CFG3                                   0x2C
#define BT_REG_RXCMD_CFG0                                   0x30
#define BT_REG_RXCMD_CFG1                                   0x34
#define BT_REG_RXCMD_CFG2                                   0x38
#define BT_REG_RXCMD_CFG3                                   0x3C
#define BT_REG_RXCMD_CFG4                                   0x40
#define BT_REG_RXCMD_CFG5                                   0x44
#define BT_REG_RXCMD_CFG6                                   0x48
#define BT_REG_RFSTBY_PRG                                   0x4C
#define BT_REG_TX_BKPRG_SET0                                0x50
#define BT_REG_TX_BKPRG_SET1                                0x54
#define BT_REG_TX_BKPRG_SET2                                0x58
#define BT_REG_RX_BKPRG_SET0                                0x5C
#define BT_REG_RX_BKPRG_SET1                                0x60
#define BT_REG_RX_BKPRG_SET2                                0x64
#define BT_REG_RX_BKRPT0                                    0x68
#define BT_REG_RX_BKRPT1                                    0x6C
#define BT_REG_RX_BKRPT2                                    0x70
#define BT_REG_RX_BKRPT3                                    0x74
#define BT_REG_RX_BKRPT4                                    0x78
#define BT_REG_RX_BKRPT_STS0                                0x7C
#define BT_REG_RX_BKRPT_STS1                                0x80
#define BT_REG_RX_BKRPT_STS2                                0x84
#define BT_REG_RX_BKRPT_STS3                                0x88
#define BT_REG_RX_BKRPT_STS4                                0x8C
#define BT_REG_TRX_FEC_CFG                                  0x90
#define BT_REG_TRX_FIELD_BIT_CFG0                           0x94
#define BT_REG_TRX_FIELD_BIT_CFG1                           0x98
#define BT_REG_TX_CI_TERM1_TERM2_FIELD_CFG                  0x9C
#define BT_REG_TRX_CFG                                      0xA0
#define BT_REG_RXCFG                                        0xA4
#define BT_REG_RXDMA_STATUS                                 0xA8
#define BT_REG_FW_HP_INTR_IMR                               0xAC
#define BT_REG_FW_HP_INTR_ISR                               0xB0
#define BT_REG_FW_LP_INTR_IMR                               0xB4
#define BT_REG_FW_LP_INTR_ISR                               0xB8
#define BT_REG_PHY_PI_HW_CFG                                0xBC
#define BT_REG_PHY_PI_SW_CFG                                0xC0
#define BT_REG_RFC_PI_SW_CFG                                0xC4
#define BT_REG_PTA_CFG                                      0xC8
#define BT_REG_PHY_MEM_CFG                                  0xCC
#define BT_REG_PSD_SCAN_CFG0                                0xD0
#define BT_REG_PSD_SCAN_CFG1                                0xD4
#define BT_REG_BT_HDR_SNR_CHK                               0xD8
#define BT_REG_RX_SNR_DBG0                                  0xDC
#define BT_REG_RX_SNR_DBG1                                  0xE0
#define BT_REG_RX_INFO_DBG                                  0xE4
#define BT_REG_TX_LATCH_TSFT                                0xE8
#define BT_REG_RX_LATCH_TSFT                                0xEC
#define BT_REG_DEBUG_PORT_CFG                               0xF4
#define BT_REG_DEBUG_PORT_RD                                0xF8

/*Definition of Register 0x00*/
struct bt_reg_clock_fen_cfg {
	uint32_t swuscfg_tsf : 4;                               //unit is 0.25us
	uint32_t sleep_clk_is_32768 : 1;                        //1: sleep clock is 32.768KHz/0: sleep clock is 32KHz
	uint32_t cksl_bt32k : 1;                                //1: bt_clock switch to 32K or 32.768K/0: bt clock switch to 40M
	uint32_t rsvd : 18;
	uint32_t rfc_rst_en : 1;                                //to RFC S0, SI test
	uint32_t clk_10m_en : 1;                                //1: enable clk_10m
	uint32_t rfc_clk_en : 1;                                //force request 40M for IP
	uint32_t sram_clk_en : 1;                               //enable sram_clk to BB
	uint32_t force_adda_iso_off : 1;                        //to BB
	uint32_t rfc_clk_force_on: 1;                           //1: enable bt_rfc_clk40 for RFAFE
	uint32_t modem_clk_force_on : 1;                        //to BB
	uint32_t clk_80M_en_btoff : 1;                          //1: enable clk40_modem to BB
};

/*Definition of Register 0x04*/
struct bt_reg_freerun_cnt_cfg {
	uint32_t ps_timer_en : 1;
	uint32_t rsvd   : 7;
	uint32_t target_time_threshold : 16;
	uint32_t rsvd1  : 6;
	uint32_t reset_freerun_p : 1;
	uint32_t en_freecnt : 1;
};

/*Definition of Register 0x10*/
struct  bt_reg_trx_delay {
	uint32_t txon_early_time : 8;
	uint32_t rsvd : 8;
	uint32_t trx_early_start_time : 8;
	uint32_t trx_pkt_head_early : 8;
};

/*Definition of Register 0x14*/
struct bt_reg_str_rx_cfg {
	uint32_t macrx_valid  : 1;
	uint32_t rsvd : 31;

};

/*Definition of Register 0x18*/
struct bt_reg_str_tx_cfg {
	uint32_t mactx_valid  : 1;
	uint32_t rsvd : 31;
};

/*Definition of Register 0x1C*/
struct bt_reg_trx_cmd_cfg {
	uint32_t txagc_add : 8;
	uint32_t txagc  : 8;
	uint32_t rf_chnl : 7;
	uint32_t rsvd : 1;
	uint32_t white_init_value : 7;
	uint32_t dis_rf_ps : 1;
};

/*Definition of Register 0x20*/
struct bt_reg_txcmd_cfg0 {
	uint32_t tx_pkt_addr : 32;
};

/*Definition of Register 0x24*/
struct bt_reg_txcmd_cfg1 {
	uint32_t tx_pta_time : 18;  //unit: 1us
	uint32_t rsvd : 2;
	uint32_t tx_bt_pri : 1;  //1: high
	uint32_t tx_bt_req : 1;
	uint32_t rsvd1: 10;
};

/*Definition of Register 0x28*/
struct bt_reg_txcmd_cfg2 {
	uint32_t tx_target_time : 32;
};

#define TRX_SPEC_TYPE_LE                0
#define TRX_SPEC_TYPE_24G_PROPRIETARY   1
#define TRX_SPEC_TYPE_BREDR             2
#define TRX_SPEC_TYPE_154               3

/*Definition of Register 0x2C*/
struct bt_reg_txcmd_cfg3 {
	uint32_t tx_pkt_length : 14;
	uint32_t tx_phy : 2;
	uint32_t tx_raw : 1;
	uint32_t rsvd : 5;
	uint32_t tx_bredr_ptt : 1;
	uint32_t tx_bredr_id_pkt : 1;
	uint32_t tx_bredr_pkt_type : 4;
	uint32_t rsvd1 : 2;
	uint32_t tx_spec_type : 2;
};

/*Definition of Register 0x30*/
struct bt_reg_rxcmd_cfg0 {
	uint32_t rx_pkt_addr : 32;
};

/*Definition of Register 0x34*/
struct bt_reg_rxcmd_cfg1 {
	uint32_t rx_pta_time : 18;
	uint32_t rsvd : 2;
	uint32_t rx_bt_pri : 1;
	uint32_t rx_bt_req : 1;
	uint32_t rsvd1: 10;
};

/*Definition of Register 0x38*/
struct bt_reg_rxcmd_cfg2 {
	uint32_t rx_target_time : 32;
};

/*Definition of Register 0x3C*/
struct bt_reg_rxcmd_cfg3 {
	uint32_t rx_timeout_time : 16; //unit us
	uint32_t rx_phy : 2;
	uint32_t rsvd : 3;
	uint32_t rx_bredr_with_mic : 1;
	uint32_t rx_bredr_ptt : 1;
	uint32_t rx_bredr_id_pkt : 1;
	uint32_t rsvd1 : 6;
	uint32_t rx_spec_type : 2;
};

/*Definition of Register 0x40*/
struct bt_reg_rxcmd_cfg4 {
	uint32_t rx_access_addr0 : 32;    //LE[31:0], BREDR[35:4]
};

/*Definition of Register 0x44*/
struct bt_reg_rxcmd_cfg5 {
	uint32_t rx_access_addr1 : 32;    //LE[31:0], BREDR[67:36]
};

/*Definition of Register 0x48*/
struct bt_reg_rxcmd_cfg6 {
	uint32_t rx_le_and_lr : 1;
	uint32_t rf_rx_phy_occur : 1;
	uint32_t rx_midx : 1;
	uint32_t rsvd : 1;
	uint32_t data_exten_en : 2;
	uint32_t rsvd1 : 2;

	uint32_t en_le_acc_addr_diff : 1;
	uint32_t rx_corr_en : 1;
	uint32_t scan_filt_rssi : 1;
	uint32_t rsvd2 : 1;
	uint32_t piconet_id : 2;
	uint32_t rsvd3 : 2;

	uint32_t rx_recov_clk_adj : 2;
	uint32_t rsvd4 : 4;
	uint32_t esco_length : 10;
};

/*Definition of Register 0x4C*/
struct bt_reg_rfstby_prg {
	uint32_t stby_prg_set : 24;     //default value: 0x801000
	uint32_t rsvd : 8;
};

/*Definition of Register 0x50*/
struct bt_reg_tx_bkprg_set0 {
	uint32_t tx_bkprg_set0 : 26; //default 0x2000000 [15:0]Data, [25:16] ADDR
	uint32_t sd_pos_dly_le : 3;
	uint32_t dis_afe_ps : 1;
	uint32_t rsvd : 1;
	uint32_t dis_btafe_iso : 1;
};

/*Definition of Register 0x54*/
struct bt_reg_tx_bkprg_set1 {
	uint32_t tx_bkprg_set1 : 26;
	uint32_t le_2m_en_tx2 : 1;
	uint32_t le_lr_en_tx2 : 1;
	uint32_t rampdown_delay_le : 4;
};

/*Definition of Register 0x58*/
struct bt_reg_tx_bkprg_set2 {
	uint32_t tx_bkprg_set2  : 26;
	uint32_t le_2m_en_tx1   : 1;
	uint32_t le_lr_en_tx1   : 1;
	uint32_t rampstby_delay_le : 4;
};


/*Definition of Register 0x5C*/
struct bt_reg_rx_bkprg_set0 {
	uint32_t rx_bkprg_set0  : 27;
	uint32_t le_2m_en_rx0   : 1;
	uint32_t le_lr_en_rx0   : 1;
	uint32_t preturnon_delay_le : 3;
};

/*Definition of Register 0x60*/
struct bt_reg_rx_bkprg_set1 {
	uint32_t rx_bkprg_set1  : 27;
	uint32_t le_2m_en_rx1   : 1;
	uint32_t le_lr_en_rx1   : 1;
	uint32_t le_2m_en_tx0   : 1;
	uint32_t le_lr_en_tx0   : 1;
	uint32_t rsvd : 1;
};

/*Definition of Register 0x64*/
struct bt_reg_rx_bkprg_set2 {
	uint32_t rx_bkprg_set2  : 27;
	uint32_t le_2m_en_rx2   : 1;
	uint32_t le_lr_en_rx2   : 1;
	uint32_t prestby_dly_le : 2;
	uint32_t prestby_dly_en : 1;
};

/*Definition of Register 0x68*/
struct bt_reg_rx_bkrpt0 {
	uint32_t rx_bkrpt_set0  : 10;
	uint32_t rsvd : 22;
};

/*Definition of Register 0x6C*/
struct bt_reg_rx_bkrpt1 {
	uint32_t rx_bkrpt_set1  : 10;
	uint32_t rsvd : 22;

};

/*Definition of Register 0x70*/
struct bt_reg_rx_bkrpt2 {
	uint32_t rx_bkrpt_set2  : 10;
	uint32_t rsvd : 22;
};

/*Definition of Register 0x74*/
struct bt_reg_rx_bkrpt3 {
	uint32_t rx_bkrpt_set3  : 10;
	uint32_t rsvd : 22;
};

/*Definition of Register 0x78*/
struct bt_reg_rx_bkrpt4 {
	uint32_t rx_bkrpt_set4  : 10;
	uint32_t rsvd : 22;
};

/*Definition of Register 0x7C*/
struct bt_reg_rx_bkrpt_sts0 {
	uint32_t rx_bkrpt_sts0: 16;
	uint32_t rsvd : 16;
};

/*Definition of Register 0x80*/
struct bt_reg_rx_bkrpt_sts1 {
	uint32_t rx_bkrpt_sts1: 16;
	uint32_t rsvd : 16;
};

/*Definition of Register 0x84*/
struct bt_reg_rx_bkrpt_sts2 {
	uint32_t rx_bkrpt_sts2: 16;
	uint32_t rsvd : 16;
};

/*Definition of Register 0x88*/
struct bt_reg_rx_bkrpt_sts3 {
	uint32_t rx_bkrpt_sts3: 16;
	uint32_t rsvd : 16;
};

/*Definition of Register 0x8C*/
struct bt_reg_rx_bkrpt_sts4 {
	uint32_t rx_bkrpt_sts4: 16;
	uint32_t rsvd : 16;
};

/*Definition of Register 0x90*/
struct bt_reg_trx_fec_cfg {
	uint32_t crc_init_val : 24;
	uint32_t inval_crc : 1;
	uint32_t crc_type_sel : 2;
	uint32_t en_access_cal_crc : 1;
	uint32_t rsvd : 2;
	uint32_t bt_tx_dis_crc : 1;
	uint32_t white_dis : 1;
};

/*Definition of Register 0x94*/
struct bt_reg_trx_field_bit_cfg0 {
	uint32_t term2_total_bit : 4;
	uint32_t ci_term1_total_bit : 4;
	uint32_t preamble_total_bit : 7;
	uint32_t rsvd : 1;
	uint32_t tx_over_total_bits : 4;
	uint32_t rsvd1: 4;
	uint32_t header_total_bit : 8;
};

/*Definition of Register 0x98*/
struct bt_reg_trx_field_bit_cfg1 {
	uint32_t rsvd : 4;
	uint32_t guard_time_total_bit : 4;
	uint32_t sync_seq_total_bit : 8;
	uint32_t dv_voice_total_bit : 8;
	uint32_t access_code_total_bit : 8;
};

/*Definition of Register 0x9C*/
struct bt_reg_tx_ci_term1_term2_field_cfg {
	uint32_t tx_term2_val : 16;
	uint32_t tx_ci_term1_val : 16;
};

/*Definition of Register 0xA0*/
struct bt_reg_trx_cfg {
	uint32_t radio_off : 1;
	uint32_t radio_off_ready : 1;
	uint32_t rsvd : 6;
	uint32_t rx_polluted : 1;
	uint32_t tx_polluted : 1;
	uint32_t rsvd1  : 15;
	uint32_t adv_rx_rssi_th_en : 1;
	uint32_t en_early_txon_tgl  : 1;
	uint32_t rxgck_dly_sel : 3;
	uint32_t rx_disgclk : 1;
	uint32_t tx_disgclk : 1;
};

/*Definition of Register 0xA4*/
struct bt_reg_rxcfg {
	uint32_t r_rxpkt_endaddr  : 10;
	uint32_t rsvd : 2;
	uint32_t r_rxffovfl_rsv : 4;
	uint32_t r_fcs_no_check : 1;
	uint32_t r_rxdma_engine_pause : 1;
	uint32_t rsvd1  : 14;
};


/*Definition of Register 0xA8*/
struct bt_reg_rxdma_status {
	uint32_t rxpkt_wptr  : 10;
	uint32_t rsvd : 6;
	uint32_t rxpkt_rptr  : 10;
	uint32_t rx_st   : 3;
	uint32_t rx_sff_overflow : 1;
	uint32_t rx_sff_underflow : 1;
	uint32_t tx_sff_overflow : 1;
};

/*Definition of Register 0xAC*/
struct bt_reg_fw_hp_intr_imr {
	uint32_t rsvd : 1;
	uint32_t fs_tx_ok_int_en : 1;
	uint32_t fs_tx_fail_int_en : 1;
	uint32_t fs_rx_ok_int_en : 1;
	uint32_t fs_rx_fail_int_en : 1;
	uint32_t fs_rx_timeout_int_en : 1;
	uint32_t fs_cancel_tx_int_en : 1;
	uint32_t fs_cancel_rx_int_en : 1;
	uint32_t fs_rxbuffer_full_int_en : 1;
	uint32_t fs_rxdma_done_int_en : 1;
	uint32_t fs_rx_id_pkt_done_int_en : 1;
	uint32_t rsvd1 : 21;
};

/*Definition of Register 0xB0*/
struct bt_reg_fw_hp_intr_isr {
	uint32_t rsvd : 1;
	uint32_t fs_tx_ok_int : 1;
	uint32_t fs_tx_fail_int : 1;
	uint32_t fs_rx_ok_int : 1;
	uint32_t fs_rx_fail_int : 1;
	uint32_t fs_rx_timeout_int : 1;
	uint32_t fs_cancel_tx_int : 1;
	uint32_t fs_cancel_rx_int : 1;
	uint32_t fs_rxbuffer_full_int : 1;
	uint32_t fs_rxdma_done_int : 1;
	uint32_t fs_rx_id_pkt_done_int : 1;
	uint32_t rsvd1 : 21;
};

/*Definition of Register 0xB4*/
struct bt_reg_fw_lp_intr_imr {
	uint32_t fs_ps_timer_int_en : 1;
	uint32_t fs_ps_psd_done_int_en : 1;
	uint32_t rsvd : 30;
};

/*Definition of Register 0xB8*/
struct bt_reg_fw_lp_intr_isr {
	uint32_t fs_ps_timer_int : 1;
	uint32_t fs_ps_psd_done_int : 1;
	uint32_t rsvd : 30;
};

/*Definition of Register 0xBC*/
struct bt_reg_phy_pi_hw_cfg {
	uint32_t bzpi_to_val : 3;
	uint32_t rsvd : 5;
	uint32_t trig_meter_delay : 8;
	uint32_t tx_meter_en : 1;
	uint32_t rx_meter_en : 1;
	uint32_t rsvd1 : 14;
};

/*Definition of Register 0xC0*/
struct bt_reg_phy_pi_sw_cfg {
	uint32_t btphy_pi_wdata : 16;
	uint32_t btphy_pi_addr : 12;
	uint32_t btphy_pi_wen : 1;
	uint32_t btphy_pi_en : 1;
	uint32_t btphy_pi_cyc : 2;
};

/*Definition of Register 0xC4*/
struct bt_reg_rfc_pi_sw_cfg {
	uint32_t sw_pi_iod_rfc  : 16;
	uint32_t sw_pi_ioad_rfc : 8;
	uint32_t sw_pi_iow_rfc : 1;
	uint32_t sw_pi_rfc_sel  : 1;
	uint32_t sw_pi_cyc : 2;
	uint32_t rsvd : 4;
};

/*Definition of Register 0xC8*/
struct bt_reg_pta_cfg {
	uint32_t tx_confirm_delay : 8;
	uint32_t rsvd : 19;
	uint32_t neglect_wlan_act_at_rx : 1;
	uint32_t neglect_wlan_act : 1;
	uint32_t trx_reject_sw : 1;
	uint32_t trx_reject_sw_en : 1;
	uint32_t enable_pta : 1;
};

/*Definition of Register 0xCC*/
struct bt_reg_phy_mem_cfg {
	uint32_t btphy_retention_cfg : 8;
	uint32_t btphy_retention_on : 1;
	uint32_t btphy_retention_mode : 1;
	uint32_t btphy_retention_done : 1;
	uint32_t acc_chk2_flag : 1;
	uint32_t en_modem_write_data : 1;
	uint32_t en_modem_to_sram_dbg : 1;
	uint32_t rst_modem_to_rxbuf_p : 1;
	uint32_t rsvd : 1;
	uint32_t bts0s1_rdata_ored_sel : 1;
	uint32_t bts1_bb_sel_s1_trx : 1;
	uint32_t rsvd1 : 10;
	uint32_t phy_retram_ds : 1;
	uint32_t phy_offram_sd : 1;
	uint32_t phy_offram_ds : 1;
	uint32_t phy_pon_sram_ds : 1;
};

/*Definition of Register 0xD0*/
struct bt_reg_psd_scan_cfg0 {
	uint32_t psd_start : 7;
	uint32_t rsvd : 1;
	uint32_t psd_end : 7;
	uint32_t rsvd1 : 1;
	uint32_t psd_step : 7;
	uint32_t rsvd2 : 1;
	uint32_t psd_mode : 1;
	uint32_t rsvd3 : 7;
};

/*Definition of Register 0xD4*/
struct bt_reg_psd_scan_cfg1 {
	uint32_t psd_timeout : 10;
	uint32_t rsvd : 13;
	uint32_t psd_en : 1;
	uint32_t psd_scan_cmd : 8;
};

/*Definition of Register 0xD8*/
struct bt_reg_bt_hdr_snr_chk {
	uint32_t bt_snr_req_sel_rxon : 1;
	uint32_t hec_chk_en : 1;
	uint32_t header_snr_chk_en : 1;
	uint32_t rsvd : 5;
	uint32_t header_snr_threshold : 16;
	uint32_t hec_init_value : 8;
};

/*Definition of Register 0xDC*/
struct bt_reg_rx_snr_dbg0 {
	uint32_t payload_snr_est : 16;
	uint32_t header_snr_est : 16;
};

/*Definition of Register 0xE0*/
struct bt_reg_rx_snr_dbg1 {
	uint32_t err_max_est : 14;
	uint32_t rsvd : 18;
};

/*Definition of Register 0xE4*/
struct bt_reg_rx_info_dbg {
	uint32_t rcvd_crc : 24;
	uint32_t fec_err : 1;
	uint32_t hec_err : 1;
	uint32_t rx_sync_undetect : 1;
	uint32_t sch_trx_idle : 1;
	uint32_t rsvd : 2;
	uint32_t rcvd_pkt_type : 2;
};

union bt_mac_reg {
	uint32_t raw_data;
	struct bt_reg_clock_fen_cfg clock_fen_cfg;                                      //0x00
	struct bt_reg_freerun_cnt_cfg freerun_cnt_cfg;                                  //0x04
	struct bt_reg_trx_delay trx_delay;                                              //0x10
	struct bt_reg_str_rx_cfg str_rx_cfg;                                            //0x14
	struct bt_reg_str_tx_cfg str_tx_cfg;                                            //0x18
	struct bt_reg_trx_cmd_cfg trx_cmd_cfg;                                          //0x1C
	struct bt_reg_txcmd_cfg0 txcmd_cfg0;                                          //0x20
	struct bt_reg_txcmd_cfg1 txcmd_cfg1;                                          //0x24
	struct bt_reg_txcmd_cfg2 txcmd_cfg2;                                          //0x28
	struct bt_reg_txcmd_cfg3 txcmd_cfg3;                                          //0x2C
	struct bt_reg_rxcmd_cfg0 rxcmd_cfg0;                                          //0x30
	struct bt_reg_rxcmd_cfg1 rxcmd_cfg1;                                          //0x34
	struct bt_reg_rxcmd_cfg2 rxcmd_cfg2;                                          //0x38
	struct bt_reg_rxcmd_cfg3 rxcmd_cfg3;                                          //0x3C
	struct bt_reg_rxcmd_cfg4 rxcmd_cfg4;                                          //0x40
	struct bt_reg_rxcmd_cfg5 rxcmd_cfg5;                                          //0x44
	struct bt_reg_rxcmd_cfg6 rxcmd_cfg6;                                          //0x48
	struct bt_reg_rfstby_prg rfstby_prg;                                            //0x4C
	struct bt_reg_tx_bkprg_set0 tx_bkprg_set0;                                      //0x50
	struct bt_reg_tx_bkprg_set1 tx_bkprg_set1;                                      //0x54
	struct bt_reg_tx_bkprg_set2 tx_bkprg_set2;                                      //0x58
	struct bt_reg_rx_bkprg_set0 rx_bkprg_set0;                                      //0x5C
	struct bt_reg_rx_bkprg_set1 rx_bkprg_set1;                                      //0x60
	struct bt_reg_rx_bkprg_set2 rx_bkprg_set2;                                      //0x64
	struct bt_reg_rx_bkrpt0 rx_bkrpt0;                                              //0x68
	struct bt_reg_rx_bkrpt1 rx_bkrpt1;                                              //0x6C
	struct bt_reg_rx_bkrpt2 rx_bkrpt2;                                              //0x70
	struct bt_reg_rx_bkrpt3 rx_bkrpt3;                                              //0x74
	struct bt_reg_rx_bkrpt4 rx_bkrpt4;                                              //0x78
	struct bt_reg_rx_bkrpt_sts0 rx_bkrpt_sts0;                                      //0x7C
	struct bt_reg_rx_bkrpt_sts1 rx_bkrpt_sts1;                                      //0x80
	struct bt_reg_rx_bkrpt_sts2 rx_bkrpt_sts2;                                      //0x84
	struct bt_reg_rx_bkrpt_sts3 rx_bkrpt_sts3;                                      //0x88
	struct bt_reg_rx_bkrpt_sts4 rx_bkrpt_sts4;                                      //0x8C
	struct bt_reg_trx_fec_cfg trx_fec_cfg;                                          //0x90
	struct bt_reg_trx_field_bit_cfg0 trx_field_bit_cfg0;                           //0x94
	struct bt_reg_trx_field_bit_cfg1 trx_field_bit_cfg1;                           //0x98
	struct bt_reg_tx_ci_term1_term2_field_cfg tx_ci_term1_term2_field_cfg;          //0x9C
	struct bt_reg_trx_cfg trx_cfg;                                                  //0xA0
	struct bt_reg_rxcfg rxcfg;                                                      //0xA4
	struct bt_reg_rxdma_status rxdma_status;                                        //0xA8
	struct bt_reg_fw_hp_intr_imr fw_hp_intr_imr;                                    //0xAC
	struct bt_reg_fw_hp_intr_isr fw_hp_intr_isr;                                    //0xB0
	struct bt_reg_fw_lp_intr_imr fw_lp_intr_imr;                                    //0xB4
	struct bt_reg_fw_lp_intr_isr fw_lp_intr_isr;                                    //0xB8
	struct bt_reg_phy_pi_hw_cfg phy_pi_hw_cfg;                                      //0xBC
	struct bt_reg_phy_pi_sw_cfg phy_pi_sw_cfg;                                      //0xC0
	struct bt_reg_rfc_pi_sw_cfg rfc_pi_sw_cfg;                                      //0xC4
	struct bt_reg_pta_cfg pta_cfg;                                                  //0xC8
	struct bt_reg_phy_mem_cfg phy_mem_cfg;                                          //0xCC
	struct bt_reg_psd_scan_cfg0 psd_scan_cfg0;                                      //0xD0
	struct bt_reg_psd_scan_cfg0 psd_scan_cfg1;                                      //0xD4
};

#endif