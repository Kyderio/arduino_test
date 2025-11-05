/******************************************************************************
 *
 * Copyright(c) 2007 - 2017  Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * The full GNU General Public License is included in this distribution in the
 * file called LICENSE.
 *
 * Contact Information:
 * wlanfae <wlanfae@realtek.com>
 * Realtek Corporation, No. 2, Innovation Road II, Hsinchu Science Park,
 * Hsinchu 300, Taiwan.
 *
 * Larry Finger <Larry.Finger@lwfinger.net>
 *
 *****************************************************************************/

#ifndef __INC_ADCSMP_H
#define __INC_ADCSMP_H

#if (PHYDM_LA_MODE_SUPPORT)

/* 2020.07.03 [8723F] Fix SD4 compile error*/
#define DYNAMIC_LA_MODE "4.2"

/* @1 ============================================================
 * 1  Definition
 * 1 ============================================================
 */

/* @ ============================================================
 *  enumrate
 *  ============================================================
 */
enum la_dump_mode {
	LA_BB_ADC_DUMP		= 0,
	LA_MAC_DBG_DUMP		= 1
};

enum rt_adcsmp_trig_sel {
	PHYDM_ADC_BB_TRIG	= 0,
	PHYDM_ADC_MAC_TRIG	= 1,
	PHYDM_ADC_RF0_TRIG	= 2,
	PHYDM_ADC_RF1_TRIG	= 3,
	PHYDM_MAC_TRIG		= 4
};

enum rt_adcsmp_trig_sig_sel {
	ADCSMP_TRIG_CRCOK	= 0,
	ADCSMP_TRIG_CRCFAIL	= 1,
	ADCSMP_TRIG_CCA		= 2,
	ADCSMP_TRIG_REG		= 3
};

enum rt_adcsmp_state {
	ADCSMP_STATE_IDLE	= 0,
	ADCSMP_STATE_SET	= 1,
	ADCSMP_STATE_QUERY	= 2
};

enum la_buff_mode {
	ADCSMP_BUFF_HALF	= 0,
	ADCSMP_BUFF_ALL		= 1	/*Only use in MP Driver*/
};

/* @ ============================================================
 *   structure
 *  ============================================================
 */

struct rt_adcsmp_string {
	u32			*octet;
	u32			length;
	u32			buffer_size;
};

#ifdef PHYDM_IC_JGR3_SERIES_SUPPORT
struct la_adv_trig {
	u32			la_and4_mask;
	u32			la_and4_bitmap;

	u8			la_and1_sel;
	u8			la_and1_val;

	u8			la_and2_sel;
	u8			la_and2_val;

	u8			la_and3_sel;
	u8			la_and3_val;

	u8 		b_la_adv_bbtrigger_en: 1;
	u8		b_la_ori_bb_dis: 1;
	u8			b_la_and1_inv: 1;
	u8			b_la_and2_inv: 1;
	u8			b_la_and3_inv: 1;
	u8			b_la_and4_inv: 1;
};
#endif

struct rt_adcsmp {
	struct rt_adcsmp_string adc_smp_buf;
#ifdef PHYDM_IC_JGR3_SERIES_SUPPORT
	struct la_adv_trig	    adv_trig_table;
#endif
	enum rt_adcsmp_state	adc_smp_state;
	enum la_buff_mode	    la_buff_mode;
	enum la_dump_mode	    la_dump_mode;
	u32			la_trig_sig_sel;
	u32			la_trigger_time;
	/*@1.BB mode: Dbg port header sel, 2.MAC mode: for reference mask*/
	u32			la_mac_mask_or_hdr_sel;
	u32			la_dbg_port;
	u32			la_count;
	u32			smp_number;
	u8			la_trig_mode;
	u8			la_dma_type;
	u8			la_trigger_edge;
	u8			la_smp_rate;
	u8 		b_is_la_print: 1;
	u8 		b_en_fake_trig: 1;
};

/* @ ============================================================
 *  Function Prototype
 *  ============================================================
 */

void phydm_la_set(void);

void phydm_la_cmd(char input[][16], u32 *_used, char *output,
				  u32 *_out_len);

void phydm_la_stop(void);

void phydm_la_init(void);

#endif
#endif
