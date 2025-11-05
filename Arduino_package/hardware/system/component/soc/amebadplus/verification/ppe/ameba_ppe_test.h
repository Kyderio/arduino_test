/*
 * Copyright (c) 2022, RT-bt hw team
 *
 * Bee4 PPE FPGA bitfile Verfication
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-09-27     feihu wang   the first version
 */


/* --------------------------------Includes --------------------------------*/



#include "ameba_soc.h"
#include "ameba_ppe_pic_source.h"

#include "stdlib.h"

/* --------------------------------Define  ----------------------------------*/
#define PPE_DBG 				printf
#define PPE_DELAY_ms			DelayMs
#define PPE_DELAY_us			DelayUs

#define PPE_CFG_REG_BASE		PPE_REG_BASE

#define PPE_ALL									((PPE_GLOBAL_TypeDef *)PPE_CFG_REG_BASE)
#define PPE_RESULT_LAYER				((PPE_RESULT_LAYER_TypeDef *)PPE_CFG_REG_BASE)
#define PPE_INPUT_LAYER1				((PPE_INPUT_LAYER_TypeDef *)(PPE_CFG_REG_BASE + 0x40 * 1))
#define PPE_INPUT_LAYER2				((PPE_INPUT_LAYER_TypeDef *)(PPE_CFG_REG_BASE + 0x40 * 2))
#define PPE_INPUT_LAYER3				((PPE_INPUT_LAYER_TypeDef *)(PPE_CFG_REG_BASE + 0x40 * 3))

typedef struct {
	uint8_t b;
	uint8_t g;
	uint8_t r;
	uint8_t a;
} T_ARGB;





/*******************************************************************************/
/* -----------------------------Alpha Blend Test Function ---------------------*/
void Test_PPE_Alpha_Blend_2_layer(u8 *argv[]);

void Test_PPE_Alpha_Blend_3_layer(u8 *argv[]);

void Test_PPE_Alpha_Blend_abort(u8 *argv[]);

void Test_PPE_Alpha_Blend_suspend_resume(u8 *argv[]);

void Test_PPE_Alpha_Blend_STARTX_STARTY(u8 *argv[]);

void Test_PPE_Alpha_Blend_WINSIZE_SOURCE(u8 *argv[]);

void Test_PPE_Alpha_Blend_WINSIZE_RESULT(u8 *argv[]);

void Test_PPE_Alpha_Blend_const_pix(u8 *argv[]);

void Test_PPE_Alpha_Blend_colro_format(u8 *argv[]);

void Test_PPE_Alpha_Blend_line_len(u8 *argv[]);

void Test_PPE_Alpha_Blend_line_len_result_layer(u8 *argv[]);

void Test_PPE_Alpha_Blend_increment(u8 *argv[]);

void Test_PPE_Alpha_Blend_byteswap(u8 *argv[]);

void Test_PPE_Alpha_Blend_key_en(u8 *argv[]);

void Test_PPE_Alpha_MultiFrame_AutoReload(u8 *argv[]);

void Test_PPE_Alpha_MultiFrame_Linklist(u8 *argv[]);

/*******************************************************************************/
/* -----------------------------Scale Test Function ---------------------------*/
void Test_PPE_Scale(u8 *argv[]);

void Test_PPE_Scale_Abort(u8 *argv[]);

void Test_PPE_Scale_suspend_resume(u8 *argv[]);

void Test_PPE_Scale_SCA_RATIO(u8 *argv[]);

void Test_PPE_Scale_WIN_SIZE(u8 *argv[]);

void Test_PPE_Scale_CONST_PIX(u8 *argv[]);

void Test_PPE_Scale_color_format(u8 *argv[]);

void Test_PPE_Scale_line_len(u8 *argv[]);

void Test_PPE_Scale_line_len_result_layer(u8 *argv[]);

void Test_PPE_Scale_INCR(u8 *argv[]);

void Test_PPE_Scale_KEY_EN(u8 *argv[]);

void Test_PPE_Scale_MultiFrame_AutoReload(u8 *argv[]);

void Test_PPE_Scale_MultiFrame_Linklist(u8 *argv[]);

/*********************************************************************************/
/* -----------------------------interrupt function  -----------------------------*/
void Test_ALL_OVER_int(void);

void Test_FRAME_OVER_int(void);

void Test_LOAD_OVER_int(void);

void Test_LINE_OVER_int(void);

void Test_PPE_SUSP_INACTIVE_int(void);

void Test_PPE_SECURE_ERROR_int(void);

void Test_PPE_SET_ERROR_int(void);

/*******************************************************************************/
/* -----------------------------Reference Function ----------------------------*/


void PPE_AlphaBlend_Simulation_2layer(PPE_ResultLayer_InitTypeDef *Result_layer, PPE_InputLayer_InitTypeDef *BackGround_layer,
									  PPE_InputLayer_InitTypeDef *Front_layer);

void PPE_AlphaBlend_Simulation_3layer(PPE_ResultLayer_InitTypeDef *Result_layer, PPE_InputLayer_InitTypeDef *Input_layer_1,
									  PPE_InputLayer_InitTypeDef *Input_layer_2, PPE_InputLayer_InitTypeDef *Input_layer_3);

void PPE_Scale_Simulation(PPE_ResultLayer_InitTypeDef *Result_layer, PPE_InputLayer_InitTypeDef *Input_layer_1, uint32_t fix_inv_sca_ratio_x,
						  uint32_t fix_inv_sca_ratio_y);

uint32_t PPE_Get_Bytes_Per_Pixel_Result(PPE_ResultLayer_InitTypeDef *Result_layer);

uint32_t PPE_Get_Bytes_Per_Pixel_Input(PPE_InputLayer_InitTypeDef *Input_layer);

bool Wheter_In_Input_Layer_Window(PPE_InputLayer_InitTypeDef *Input_layer, uint32_t current_x, uint32_t current_y);

uint32_t Get_Pixel(uint8_t *source_address, uint32_t bytes_per_pixel);

uint32_t Convert_Pixel_Format_to_ARGB8888(uint32_t old_pixel, uint32_t bytes_per_pixel);

uint32_t blend_2pixel_ARGB8888(uint32_t background_pixel, uint32_t front_ground_pixel);

void Initialize_Array_with_Random(uint8_t *source_address, uint32_t sizeof_array, uint32_t random_seed);

void PPE_Display_Controller(uint32_t Data_Source_Address, uint32_t LCD_width, uint32_t LCD_height);

void PPE_MASK_all_interrupt(void);

void PPE_CLEAR_all_interrupt(void);

void PPE_LLI_initialization_LAYER(PPE_LLI_LAYER *LLI_layer, uint32_t input_layer_num);

void PPE_LLI_initialization_GLB(PPE_LLI_GLB *LLI_GLB);

void PPE_FORM_LLI(uint32_t *LLI_destination, PPE_GLOBAL_TypeDef *PPE_global, \
				  PPE_LLI_LAYER LLI_result_layer,	PPE_LLI_LAYER LLI_input_layer1,	PPE_LLI_LAYER LLI_input_layer2,	PPE_LLI_LAYER LLI_input_layer3, \
				  PPE_LLI_GLB 	LLI_global);
