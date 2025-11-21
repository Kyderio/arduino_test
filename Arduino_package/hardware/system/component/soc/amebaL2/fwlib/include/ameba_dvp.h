/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _RL6955_DVP_H_
#define _RL6955_DVP_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup DVP
  * @brief DVP driver modules
  * @{
  */


/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup DVP_Register_Definitions DVP Register Definitions
  * @{
  */

/** @defgroup DVP_TRANSFER
  * @brief
  * @{
  */
#define DVP_BIT_STATE    ((u32)0x00000001 << 8)           /*!< R 0x0  1: dvp enable 0: dvp disable*/
#define DVP_STATE(x)     ((u32)(((x) & 0x00000001) << 8))
#define DVP_GET_STATE(x) ((u32)(((x >> 8) & 0x00000001)))
#define DVP_BIT_START    ((u32)0x00000001 << 0)           /*!< WA0 0x00  Start The transfer is launch if set this bit. When clear this bit, hardware will stop transfer after current image frame finish transfer. Dvp_start?1???? ??????????immediate_stop???frame_stop?????????????.???immediate_stop???frame_stop?,dvp_state?????,??????immediate_stop???frame_stop?????*/
#define DVP_START(x)     ((u32)(((x) & 0x00000001) << 0))
#define DVP_GET_START(x) ((u32)(((x >> 0) & 0x00000001)))
/** @} */

/** @defgroup DVP_CONFIG
  * @brief
  * @{
  */
#define DVP_BIT_PCLK_STOP_MODE     ((u32)0x00000001 << 3)           /*!< R/W 0x00  PCLK Stop mode.  Used when sensor uses HSYNC/VSYNC to perform gating on pclk, or pclk_stop_en open 0: normal 1: sensor pixclk stop mode*/
#define DVP_PCLK_STOP_MODE(x)      ((u32)(((x) & 0x00000001) << 3))
#define DVP_GET_PCLK_STOP_MODE(x)  ((u32)(((x >> 3) & 0x00000001)))
#define DVP_BIT_PIXCLK_EDGE_SEL    ((u32)0x00000001 << 2)           /*!< R/W 0x00  Pixel clock sample edge. 0: falling edge, 1: rising edge.*/
#define DVP_PIXCLK_EDGE_SEL(x)     ((u32)(((x) & 0x00000001) << 2))
#define DVP_GET_PIXCLK_EDGE_SEL(x) ((u32)(((x >> 2) & 0x00000001)))
#define DVP_BIT_VSYNC_POLARITY     ((u32)0x00000001 << 1)           /*!< R/W 0x00  Vsync polarity 0: active low, 1: active high.*/
#define DVP_VSYNC_POLARITY(x)      ((u32)(((x) & 0x00000001) << 1))
#define DVP_GET_VSYNC_POLARITY(x)  ((u32)(((x >> 1) & 0x00000001)))
#define DVP_BIT_HSYNC_POLARITY     ((u32)0x00000001 << 0)           /*!< R/W 0x00  Hsync polarity 0: active low, 1: active high.*/
#define DVP_HSYNC_POLARITY(x)      ((u32)(((x) & 0x00000001) << 0))
#define DVP_GET_HSYNC_POLARITY(x)  ((u32)(((x >> 0) & 0x00000001)))
/** @} */

/** @defgroup DVP_CROP_START_X
  * @brief
  * @{
  */
#define DVP_MASK_DMY_PIX_NUM   ((u32)0x00001FFF << 0)           /*!< R/W 0x0000  YUV path Unit: Bytes. This field indicates the number of dummy data before the valid data output. Hardware must bypass these dummy data and not sample the dummy data. yuv422 format config value is a multiple of 4  Eg: For YUV422 format, each pixel is represented by 2 bytes. Therefore, setting this field to 8 means skipping 4 pixels  In formats like YUYV, YVYU, UYVY, and VYUY, data streams from the sensor to the DVP with each two pixels sharing the same UV components. Since each pair requires 2 pixels of 16bpp, it amounts to a total of 4 bytes. Therefore, operations involving this data should be done in multiples of 4 bytes. ??crop????*/
#define DVP_DMY_PIX_NUM(x)     (((u32)((x) & 0x00001FFF) << 0))
#define DVP_GET_DMY_PIX_NUM(x) ((u32)(((x >> 0) & 0x00001FFF)))
/** @} */

/** @defgroup DVP_CROP_START_Y
  * @brief
  * @{
  */
#define DVP_MASK_DMY_LINE_NUM   ((u32)0x00000FFF << 0)           /*!< R/W 0x0000  YUV path This field indicates the number of dummy line before the valid line output. Hardware must bypass these dummy lines and not sample the dummy line data. ??crop????*/
#define DVP_DMY_LINE_NUM(x)     (((u32)((x) & 0x00000FFF) << 0))
#define DVP_GET_DMY_LINE_NUM(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup DVP_WIDTH
  * @brief
  * @{
  */
#define DVP_MASK_PIX_NUM_PRE   ((u32)0x00001FFF << 0)           /*!< R/W 0x0000  YUV path Unit:bytes HORIZON_NUM10:0. This field indicates the number of valid data per line. yuv422 format config value is a multiple of 4  Eg: For YUV422 format, each pixel is represented by 2 bytes. Therefore, setting this field to 8 means reserved 4 pixels ??crop??????,????????sub sample*/
#define DVP_PIX_NUM_PRE(x)     (((u32)((x) & 0x00001FFF) << 0))
#define DVP_GET_PIX_NUM_PRE(x) ((u32)(((x >> 0) & 0x00001FFF)))
/** @} */

/** @defgroup DVP_HEIGHT
  * @brief
  * @{
  */
#define DVP_MASK_LINE_NUM_PRE   ((u32)0x00000FFF << 0)           /*!< R/W 0x0000  YUV path VERTICAL_NUM10:0. This field indicates the number of valid line per frame. ??crop??????,????????sub sample*/
#define DVP_LINE_NUM_PRE(x)     (((u32)((x) & 0x00000FFF) << 0))
#define DVP_GET_LINE_NUM_PRE(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup DVP_FRAME_CNT
  * @brief
  * @{
  */
#define DVP_MASK_FRAME_NUM   ((u32)0x000000FF << 0)           /*!< R 0x0  Frame_cnt 7:0. This field is used to count the number of active Vsync from RealTimeImage transfer start. If the RealTimeImage transfer stop, the value of this register do not change. As soon as trigger RealTimeImage transfer, reset the value of thi register and restart to count.*/
#define DVP_FRAME_NUM(x)     (((u32)((x) & 0x000000FF) << 0))
#define DVP_GET_FRAME_NUM(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup DVP_SUBSAMPLE_CTL
  * @brief
  * @{
  */
#define DVP_BIT_L_SUB_SAMPLE_EN    ((u32)0x00000001 << 1)           /*!< R/W 0x00  YUV path Vertical (Line) Sub Sample control.  0: not sub sample, 1: sub sample.*/
#define DVP_L_SUB_SAMPLE_EN(x)     ((u32)(((x) & 0x00000001) << 1))
#define DVP_GET_L_SUB_SAMPLE_EN(x) ((u32)(((x >> 1) & 0x00000001)))
#define DVP_BIT_P_SUB_SAMPLE_EN    ((u32)0x00000001 << 0)           /*!< R/W 0x00  YUV path Horizontal (Pixel) Sub sample control. 0: not sub sample, 1: sub sample.*/
#define DVP_P_SUB_SAMPLE_EN(x)     ((u32)(((x) & 0x00000001) << 0))
#define DVP_GET_P_SUB_SAMPLE_EN(x) ((u32)(((x >> 0) & 0x00000001)))
/** @} */

/** @defgroup DVP_SUBSAMPLE_CFG
  * @brief
  * @{
  */
#define DVP_MASK_L_SUB_VLD_NUM    ((u32)0x0000000F << 12)           /*!< R/W 0x00  YUV path Vertical Sub sample valid line number.  1-15:???line num?1-15 0:???line num?16*/
#define DVP_L_SUB_VLD_NUM(x)      (((u32)((x) & 0x0000000F) << 12))
#define DVP_GET_L_SUB_VLD_NUM(x)  ((u32)(((x >> 12) & 0x0000000F)))
#define DVP_MASK_L_SUB_DROP_NUM   ((u32)0x0000000F << 8)            /*!< R/W 0x00  YUV path Vertical Sub sample invalid line number.  1-15:???line num?1-15 0:???line num?16*/
#define DVP_L_SUB_DROP_NUM(x)     (((u32)((x) & 0x0000000F) << 8))
#define DVP_GET_L_SUB_DROP_NUM(x) ((u32)(((x >> 8) & 0x0000000F)))
#define DVP_MASK_P_SUB_VLD_NUM    ((u32)0x0000000F << 4)            /*!< R/W 0x00  YUV path Horizontal (Pixel) Sub sample valid pixel number. yuv422 format config value:  4: vld 4 byte 8: vld 8 byte 12: vld 12 byte 0: vld 16 byte*/
#define DVP_P_SUB_VLD_NUM(x)      (((u32)((x) & 0x0000000F) << 4))
#define DVP_GET_P_SUB_VLD_NUM(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define DVP_MASK_P_SUB_DROP_NUM   ((u32)0x0000000F << 0)            /*!< R/W 0x00  YUV path Horizontal (Line) Sub sample invalid pixel number.  yuv422 format config value:  4: drop 4 byte 8: drop 8 byte 12: drop 12 byte 0: drop 16 byte*/
#define DVP_P_SUB_DROP_NUM(x)     (((u32)((x) & 0x0000000F) << 0))
#define DVP_GET_P_SUB_DROP_NUM(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup DVP_FRMAE_VLD_CTL
  * @brief
  * @{
  */
#define DVP_MASK_FRAME_VLD_NUM   ((u32)0x0000000F << 0)           /*!< R/W 0x00  FRAME_VALID_NUM 4'b0: all frame are valid otherwise: one frame valid in every (FRAME_VALID_NUM + 1 ) frames*/
#define DVP_FRAME_VLD_NUM(x)     (((u32)((x) & 0x0000000F) << 0))
#define DVP_GET_FRAME_VLD_NUM(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup DVP_YUV_TRANSFER
  * @brief
  * @{
  */
#define DVP_MASK_IMAGE_FORMAT   ((u32)0x00000003 << 0)           /*!< R/W 0x00  yuv422 sensor in format 2'b00: YUYV YUYV 2'b01: YVYU YVYU 2'b10: UYVY UYVY 2'b11: VYUY VYUY*/
#define DVP_IMAGE_FORMAT(x)     (((u32)((x) & 0x00000003) << 0))
#define DVP_GET_IMAGE_FORMAT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup DVP_JPEG_TRANSFER
  * @brief
  * @{
  */
#define DVP_BIT_JPG_EN      ((u32)0x00000001 << 3)           /*!< R/W 0x00  DVP JPEG MODE EN 1: Enable DVP JPEG  0: Disable DVP JPEG*/
#define DVP_JPG_EN(x)       ((u32)(((x) & 0x00000001) << 3))
#define DVP_GET_JPG_EN(x)   ((u32)(((x >> 3) & 0x00000001)))
#define DVP_MASK_JPG_MODE   ((u32)0x00000007 << 0)           /*!< R/W 0x00  DVP JPEG Mode 3'b000:Valid mode Use VSYNC as the frame synchronization signal and HSYNC as the horizontal synchronization signal. There is no dummy data in the frame. Support VSYNC pulse or level timing 3'b001:Frame mode Use VSYNC as the frame synchronization signal and HSYNC as the horizontal synchronization signal. There is dummy data in the frame. The frame contains valid data length , and valid data length is at the beginning of each line. 3'b010:Frame mode Use VSYNC as the frame synchronization signal and HSYNC as the horizontal synchronization signal. There is dummy data in the frame. The frame contains valid data length , and valid data length is at the end of each line. 3'b011:Frame mode Use VSYNC as the frame synchronization signal and HSYNC as the horizontal synchronization signal. There is dummy data in the frame. The frame does not contains valid data length. 3'b100:Use HSYNC as the frame synchronization signal,no dummy data*/
#define DVP_JPG_MODE(x)     (((u32)((x) & 0x00000007) << 0))
#define DVP_GET_JPG_MODE(x) ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup DVP_PCLK_GATING_CTL
  * @brief
  * @{
  */
#define DVP_BIT_PCLK_GATING_EN    ((u32)0x00000001 << 0)           /*!< R/W 0x00  PCLK_GATING_EN ??PCLK?VSYNC/HSYNC gating???,??pclk_stop_mode??,?pclk_gating_en?1?,pclk_stop_mode???1*/
#define DVP_PCLK_GATING_EN(x)     ((u32)(((x) & 0x00000001) << 0))
#define DVP_GET_PCLK_GATING_EN(x) ((u32)(((x >> 0) & 0x00000001)))
/** @} */

/** @defgroup DVP_PAD_CTL
  * @brief
  * @{
  */
#define DVP_MASK_PIX_BIT_SWP   ((u32)0x00000003 << 0)           /*!< R/W 0x00  pixel bit switch 2'b01: pad[9:0]={bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0,2'd0} 2'b10: pad[9:0]={2'd0,bit0,bit1,bit2,bit3,bit4,bit5,bit6,bit7} 2'b00&2'b11: pad[9:0]={2'd0,bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0} YUV422 & JPG stream only 1 byte data valid in one PCLK cycle*/
#define DVP_PIX_BIT_SWP(x)     (((u32)((x) & 0x00000003) << 0))
#define DVP_GET_PIX_BIT_SWP(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup DVP_STOP
  * @brief
  * @{
  */
#define DVP_BIT_FRAME_STOP        ((u32)0x00000001 << 1)           /*!< WA0 0x00  The stop will not be triggered untill the current frame ends ?????????(??????psram?),??????,??????????dvp_state*/
#define DVP_FRAME_STOP(x)         ((u32)(((x) & 0x00000001) << 1))
#define DVP_GET_FRAME_STOP(x)     ((u32)(((x >> 1) & 0x00000001)))
#define DVP_BIT_IMMEDIATE_STOP    ((u32)0x00000001 << 0)           /*!< WA0 0x00  If set this bit, hardware will stop transfer and return idle state immediately. Hardware will auto clear this bit. ????,????dvp_state.dma????outstanding data???????,????platform*/
#define DVP_IMMEDIATE_STOP(x)     ((u32)(((x) & 0x00000001) << 0))
#define DVP_GET_IMMEDIATE_STOP(x) ((u32)(((x >> 0) & 0x00000001)))
/** @} */

/** @defgroup DVP_JPG_FRAME_LENGTH
  * @brief
  * @{
  */
#define DVP_MASK_JPG_FRAME_LENGTH   ((u32)0x003FFFFF << 0)           /*!< R 0x00  jpg frame size*/
#define DVP_JPG_FRAME_LENGTH(x)     (((u32)((x) & 0x003FFFFF) << 0))
#define DVP_GET_JPG_FRAME_LENGTH(x) ((u32)(((x >> 0) & 0x003FFFFF)))
/** @} */

/** @defgroup DVP_INT_ST
  * @brief
  * @{
  */
#define DVP_BIT_FRAME_CNT_INT       ((u32)0x00000001 << 6)           /*!< R 0x0  all frame buffer are fulled frames , and DVP will not to receive frames in time.then gen overflow int, need to check and clear frame status done register*/
#define DVP_FRAME_CNT_INT(x)        ((u32)(((x) & 0x00000001) << 6))
#define DVP_GET_FRAME_CNT_INT(x)    ((u32)(((x >> 6) & 0x00000001)))
#define DVP_BIT_DDR_OVERFLOW_INT    ((u32)0x00000001 << 5)           /*!< R 0x0  ddr_overflow_int Only for frame buffer mode The allocated psram/ddr capacith is less than one frame*/
#define DVP_DDR_OVERFLOW_INT(x)     ((u32)(((x) & 0x00000001) << 5))
#define DVP_GET_DDR_OVERFLOW_INT(x) ((u32)(((x >> 5) & 0x00000001)))
#define DVP_BIT_BUF_OVERFLOW_INT    ((u32)0x00000001 << 4)           /*!< R 0x0  dma buffer overflow int DMA needs to cache a certain amount of data before sending data to psram/ddr. The cached data is placed in buffer(memory), If there is too much cache and it is not sent, it means overflow*/
#define DVP_BUF_OVERFLOW_INT(x)     ((u32)(((x) & 0x00000001) << 4))
#define DVP_GET_BUF_OVERFLOW_INT(x) ((u32)(((x >> 4) & 0x00000001)))
#define DVP_BIT_FRAME_BREAK_INT     ((u32)0x00000001 << 3)           /*!< R 0x0  frame_break_int yuv422 mode, The pixel count is internally compared with the configured frame size(ddr_len) pixel count???sub sample????????,???????????buffer,????psram. pixel count??ddr_len????,?pixel count??ddr_len??????. ??1:ddr len??frame size, ?????,???? ??2:ddr_len??frame size,????????? ??3: ddr_len??frame size,????ddr_overflow_int????,??????ddr_len,????frame_size jpg mode, The pixel will be counted internally, and for jpg timing with valid data length, it will be compared with the data length*/
#define DVP_FRAME_BREAK_INT(x)      ((u32)(((x) & 0x00000001) << 3))
#define DVP_GET_FRAME_BREAK_INT(x)  ((u32)(((x >> 3) & 0x00000001)))
#define DVP_BIT_FRAME_START_INT     ((u32)0x00000001 << 2)           /*!< R 0x0  frame_start_int indicating that DVP is receiving a frame of image from sensor both yuv fb and jpeg ?????,??dma????????*/
#define DVP_FRAME_START_INT(x)      ((u32)(((x) & 0x00000001) << 2))
#define DVP_GET_FRAME_START_INT(x)  ((u32)(((x >> 2) & 0x00000001)))
#define DVP_BIT_FRAME_END_INT       ((u32)0x00000001 << 1)           /*!< R 0x0  frame_end_int both yuv fb and jpeg indicating that DVP has transfered one frame of image to memory*/
#define DVP_FRAME_END_INT(x)        ((u32)(((x) & 0x00000001) << 1))
#define DVP_GET_FRAME_END_INT(x)    ((u32)(((x >> 1) & 0x00000001)))
#define DVP_BIT_LINE_END_INT        ((u32)0x00000001 << 0)           /*!< R 0x0  line_end_int Only for YUV path indicates that the image has been transferred to the configured number of lines(interrupt_line_num). ????dma?psram????line num*/
#define DVP_LINE_END_INT(x)         ((u32)(((x) & 0x00000001) << 0))
#define DVP_GET_LINE_END_INT(x)     ((u32)(((x >> 0) & 0x00000001)))
/** @} */

/** @defgroup DVP_INT_RAW
  * @brief
  * @{
  */
#define DVP_BIT_FRAME_CNT_RAW_INT       ((u32)0x00000001 << 6)           /*!< R 0x0  frame buffer cnt overflow raw int, need to clear frame status done*/
#define DVP_FRAME_CNT_RAW_INT(x)        ((u32)(((x) & 0x00000001) << 6))
#define DVP_GET_FRAME_CNT_RAW_INT(x)    ((u32)(((x >> 6) & 0x00000001)))
#define DVP_BIT_DDR_OVERFLOW_RAW_INT    ((u32)0x00000001 << 5)           /*!< R 0x0  ddr_overflow_raw_int ddr/psram??,??????ddr_len????,?????????burst_length????,?????ddr_len??????*/
#define DVP_DDR_OVERFLOW_RAW_INT(x)     ((u32)(((x) & 0x00000001) << 5))
#define DVP_GET_DDR_OVERFLOW_RAW_INT(x) ((u32)(((x >> 5) & 0x00000001)))
#define DVP_BIT_BUF_OVERFLOW_RAW_INT    ((u32)0x00000001 << 4)           /*!< R 0x0  buf_overflow_raw_int dma??buffer??,dma?????ddr/psram???,?????burst?dma?????.??????????????buffer????????.*/
#define DVP_BUF_OVERFLOW_RAW_INT(x)     ((u32)(((x) & 0x00000001) << 4))
#define DVP_GET_BUF_OVERFLOW_RAW_INT(x) ((u32)(((x >> 4) & 0x00000001)))
#define DVP_BIT_FRAME_BREAK_RAW_INT     ((u32)0x00000001 << 3)           /*!< R 0x0  frame_break_raw_int*/
#define DVP_FRAME_BREAK_RAW_INT(x)      ((u32)(((x) & 0x00000001) << 3))
#define DVP_GET_FRAME_BREAK_RAW_INT(x)  ((u32)(((x >> 3) & 0x00000001)))
#define DVP_BIT_FRAME_START_RAW_INT     ((u32)0x00000001 << 2)           /*!< R 0x0  frame_start_raw_int*/
#define DVP_FRAME_START_RAW_INT(x)      ((u32)(((x) & 0x00000001) << 2))
#define DVP_GET_FRAME_START_RAW_INT(x)  ((u32)(((x >> 2) & 0x00000001)))
#define DVP_BIT_FRAME_END_RAW_INT       ((u32)0x00000001 << 1)           /*!< R 0x0  frame_end_raw_int*/
#define DVP_FRAME_END_RAW_INT(x)        ((u32)(((x) & 0x00000001) << 1))
#define DVP_GET_FRAME_END_RAW_INT(x)    ((u32)(((x >> 1) & 0x00000001)))
#define DVP_BIT_LINE_END_RAW_INT        ((u32)0x00000001 << 0)           /*!< R 0x0  line_end_raw_int*/
#define DVP_LINE_END_RAW_INT(x)         ((u32)(((x) & 0x00000001) << 0))
#define DVP_GET_LINE_END_RAW_INT(x)     ((u32)(((x >> 0) & 0x00000001)))
/** @} */

/** @defgroup DVP_INT_EN
  * @brief
  * @{
  */
#define DVP_BIT_FRAME_CNT_INT_EN       ((u32)0x00000001 << 6)           /*!< R/W 0x00  frame_cnt_int_en*/
#define DVP_FRAME_CNT_INT_EN(x)        ((u32)(((x) & 0x00000001) << 6))
#define DVP_GET_FRAME_CNT_INT_EN(x)    ((u32)(((x >> 6) & 0x00000001)))
#define DVP_BIT_DDR_OVERFLOW_INT_EN    ((u32)0x00000001 << 5)           /*!< R/W 0x00  ddr_overflow_int_en*/
#define DVP_DDR_OVERFLOW_INT_EN(x)     ((u32)(((x) & 0x00000001) << 5))
#define DVP_GET_DDR_OVERFLOW_INT_EN(x) ((u32)(((x >> 5) & 0x00000001)))
#define DVP_BIT_BUF_OVERFLOW_INT_EN    ((u32)0x00000001 << 4)           /*!< R/W 0x00  buf_overflow_int_en*/
#define DVP_BUF_OVERFLOW_INT_EN(x)     ((u32)(((x) & 0x00000001) << 4))
#define DVP_GET_BUF_OVERFLOW_INT_EN(x) ((u32)(((x >> 4) & 0x00000001)))
#define DVP_BIT_FRAME_BREAK_INT_EN     ((u32)0x00000001 << 3)           /*!< R/W 0x00  frame_break_int_en*/
#define DVP_FRAME_BREAK_INT_EN(x)      ((u32)(((x) & 0x00000001) << 3))
#define DVP_GET_FRAME_BREAK_INT_EN(x)  ((u32)(((x >> 3) & 0x00000001)))
#define DVP_BIT_FRAME_START_INT_EN     ((u32)0x00000001 << 2)           /*!< R/W 0x00  frame_start_int_en*/
#define DVP_FRAME_START_INT_EN(x)      ((u32)(((x) & 0x00000001) << 2))
#define DVP_GET_FRAME_START_INT_EN(x)  ((u32)(((x >> 2) & 0x00000001)))
#define DVP_BIT_FRAME_END_INT_EN       ((u32)0x00000001 << 1)           /*!< R/W 0x00  frame_end_int_en*/
#define DVP_FRAME_END_INT_EN(x)        ((u32)(((x) & 0x00000001) << 1))
#define DVP_GET_FRAME_END_INT_EN(x)    ((u32)(((x >> 1) & 0x00000001)))
#define DVP_BIT_LINE_END_INT_EN        ((u32)0x00000001 << 0)           /*!< R/W 0x00  line_end_int_en*/
#define DVP_LINE_END_INT_EN(x)         ((u32)(((x) & 0x00000001) << 0))
#define DVP_GET_LINE_END_INT_EN(x)     ((u32)(((x >> 0) & 0x00000001)))
/** @} */

/** @defgroup DVP_INT_CLR
  * @brief
  * @{
  */
#define DVP_BIT_FRAME_CNT_INT_CLR       ((u32)0x00000001 << 6)           /*!< WA0 0x00  frame_cnt_int_clr*/
#define DVP_FRAME_CNT_INT_CLR(x)        ((u32)(((x) & 0x00000001) << 6))
#define DVP_GET_FRAME_CNT_INT_CLR(x)    ((u32)(((x >> 6) & 0x00000001)))
#define DVP_BIT_DDR_OVERFLOW_INT_CLR    ((u32)0x00000001 << 5)           /*!< WA0 0x00  ddr_overflow_int_clr*/
#define DVP_DDR_OVERFLOW_INT_CLR(x)     ((u32)(((x) & 0x00000001) << 5))
#define DVP_GET_DDR_OVERFLOW_INT_CLR(x) ((u32)(((x >> 5) & 0x00000001)))
#define DVP_BIT_BUF_OVERFLOW_INT_CLR    ((u32)0x00000001 << 4)           /*!< WA0 0x00  buf_overflow_int_clr*/
#define DVP_BUF_OVERFLOW_INT_CLR(x)     ((u32)(((x) & 0x00000001) << 4))
#define DVP_GET_BUF_OVERFLOW_INT_CLR(x) ((u32)(((x >> 4) & 0x00000001)))
#define DVP_BIT_FRAME_BREAK_INT_CLR     ((u32)0x00000001 << 3)           /*!< WA0 0x00  frame_break_int_clr*/
#define DVP_FRAME_BREAK_INT_CLR(x)      ((u32)(((x) & 0x00000001) << 3))
#define DVP_GET_FRAME_BREAK_INT_CLR(x)  ((u32)(((x >> 3) & 0x00000001)))
#define DVP_BIT_FRAME_START_INT_CLR     ((u32)0x00000001 << 2)           /*!< WA0 0x00  frame_start_int_clr*/
#define DVP_FRAME_START_INT_CLR(x)      ((u32)(((x) & 0x00000001) << 2))
#define DVP_GET_FRAME_START_INT_CLR(x)  ((u32)(((x >> 2) & 0x00000001)))
#define DVP_BIT_FRAME_END_INT_CLR       ((u32)0x00000001 << 1)           /*!< WA0 0x00  frame_end_int_clr*/
#define DVP_FRAME_END_INT_CLR(x)        ((u32)(((x) & 0x00000001) << 1))
#define DVP_GET_FRAME_END_INT_CLR(x)    ((u32)(((x >> 1) & 0x00000001)))
#define DVP_BIT_LINE_END_INT_CLR        ((u32)0x00000001 << 0)           /*!< WA0 0x00  line_end_int_clr*/
#define DVP_LINE_END_INT_CLR(x)         ((u32)(((x) & 0x00000001) << 0))
#define DVP_GET_LINE_END_INT_CLR(x)     ((u32)(((x >> 0) & 0x00000001)))
/** @} */

/** @defgroup DVP_DMA_CTRL
  * @brief
  * @{
  */
#define DVP_MASK_INTERRUPT_LINE_NUM   ((u32)0x000007FF << 8)           /*!< R/W 0x00  interrupt line num, for gen specific line end int*/
#define DVP_INTERRUPT_LINE_NUM(x)     (((u32)((x) & 0x000007FF) << 8))
#define DVP_GET_INTERRUPT_LINE_NUM(x) ((u32)(((x >> 8) & 0x000007FF)))
#define DVP_MASK_FRAME_BUF_NUM        ((u32)0x00000003 << 1)           /*!< R/W 0x00  number of used frame buffer  used number = frame_buf_num + 1*/
#define DVP_FRAME_BUF_NUM(x)          (((u32)((x) & 0x00000003) << 1))
#define DVP_GET_FRAME_BUF_NUM(x)      ((u32)(((x >> 1) & 0x00000003)))
#define DVP_BIT_RING_BUFFER_EN        ((u32)0x00000001 << 0)           /*!< R/W 0x00  ring buffer mode enable ring buffer mode??yuv mode???,??jpg?????????,DVP?MJPEG??????.*/
#define DVP_RING_BUFFER_EN(x)         ((u32)(((x) & 0x00000001) << 0))
#define DVP_GET_RING_BUFFER_EN(x)     ((u32)(((x >> 0) & 0x00000001)))
/** @} */

/** @defgroup DVP_FRAME_ADDR0
  * @brief
  * @{
  */
#define DVP_MASK_FRAME_ADDR0   ((u32)0x3FFFFFFF << 2)           /*!< R/W 0x00  frame buffer 0 start addr, 4 byte align ring buffer start addr,4 byte align*/
#define DVP_FRAME_ADDR0(x)     (((u32)((x) & 0x3FFFFFFF) << 2))
#define DVP_GET_FRAME_ADDR0(x) ((u32)(((x >> 2) & 0x3FFFFFFF)))
/** @} */

/** @defgroup DVP_FRAME_ADDR1
  * @brief
  * @{
  */
#define DVP_MASK_FRAME_ADDR1   ((u32)0x3FFFFFFF << 2)           /*!< R/W 0x00  frame buffer 1 start addr, 4 byte align*/
#define DVP_FRAME_ADDR1(x)     (((u32)((x) & 0x3FFFFFFF) << 2))
#define DVP_GET_FRAME_ADDR1(x) ((u32)(((x >> 2) & 0x3FFFFFFF)))
/** @} */

/** @defgroup DVP_FRAME_ADDR2
  * @brief
  * @{
  */
#define DVP_MASK_FRAME_ADDR2   ((u32)0x3FFFFFFF << 2)           /*!< R/W 0x00  frame buffer 2 start addr, 4 byte align*/
#define DVP_FRAME_ADDR2(x)     (((u32)((x) & 0x3FFFFFFF) << 2))
#define DVP_GET_FRAME_ADDR2(x) ((u32)(((x >> 2) & 0x3FFFFFFF)))
/** @} */

/** @defgroup DVP_FRAME_ADDR3
  * @brief
  * @{
  */
#define DVP_MASK_FRAME_ADDR3   ((u32)0x3FFFFFFF << 2)           /*!< R/W 0x00  frame buffer 3 start addr, 4 byte align*/
#define DVP_FRAME_ADDR3(x)     (((u32)((x) & 0x3FFFFFFF) << 2))
#define DVP_GET_FRAME_ADDR3(x) ((u32)(((x >> 2) & 0x3FFFFFFF)))
/** @} */

/** @defgroup DVP_DDR_LEN
  * @brief
  * @{
  */
#define DVP_MASK_DDR_LEN   ((u32)0x003FFFFF << 2)           /*!< R/W 0x00  ddr length, 4 byte align frame_buffer mode is frame size ring buffer mode is ring buffer szie The size of the slave space written by dma, here refers to the size of the psram allocated YUV MODE ddr_len??????frame size JPG MODE jpg????????,?????????????,????????jpg??????????????,???????*sensor??? RING BUFFER,FRAME BUFFE????? ??????ring_buffer_en????. ring_buffer_en?1?,ddr_len??ring buffer length ring_buffer_en?0?,ddr_len??frame buffer length*/
#define DVP_DDR_LEN(x)     (((u32)((x) & 0x003FFFFF) << 2))
#define DVP_GET_DDR_LEN(x) ((u32)(((x >> 2) & 0x003FFFFF)))
/** @} */

/** @defgroup DVP_DMA_DEBUG_REG0
  * @brief
  * @{
  */
#define DVP_BIT_BURST_REQ         ((u32)0x00000001 << 28)           /*!< R 0x0  */
#define DVP_BURST_REQ(x)          ((u32)(((x) & 0x00000001) << 28))
#define DVP_GET_BURST_REQ(x)      ((u32)(((x >> 28) & 0x00000001)))
#define DVP_BIT_IDLE_STATE_CLR    ((u32)0x00000001 << 24)           /*!< R 0x0  */
#define DVP_IDLE_STATE_CLR(x)     ((u32)(((x) & 0x00000001) << 24))
#define DVP_GET_IDLE_STATE_CLR(x) ((u32)(((x >> 24) & 0x00000001)))
#define DVP_MASK_TRANS_STATE      ((u32)0x00000007 << 20)           /*!< R 0x0  */
#define DVP_TRANS_STATE(x)        (((u32)((x) & 0x00000007) << 20))
#define DVP_GET_TRANS_STATE(x)    ((u32)(((x >> 20) & 0x00000007)))
#define DVP_MASK_DATA_STATE       ((u32)0x00000003 << 16)           /*!< R 0x0  */
#define DVP_DATA_STATE(x)         (((u32)((x) & 0x00000003) << 16))
#define DVP_GET_DATA_STATE(x)     ((u32)(((x >> 16) & 0x00000003)))
#define DVP_MASK_CMD_RADDR        ((u32)0x00000007 << 12)           /*!< R 0x0  */
#define DVP_CMD_RADDR(x)          (((u32)((x) & 0x00000007) << 12))
#define DVP_GET_CMD_RADDR(x)      ((u32)(((x >> 12) & 0x00000007)))
#define DVP_MASK_CMD_WADDR        ((u32)0x00000007 << 8)            /*!< R 0x0  */
#define DVP_CMD_WADDR(x)          (((u32)((x) & 0x00000007) << 8))
#define DVP_GET_CMD_WADDR(x)      ((u32)(((x >> 8) & 0x00000007)))
#define DVP_MASK_RESP_RADDR       ((u32)0x00000007 << 4)            /*!< R 0x0  */
#define DVP_RESP_RADDR(x)         (((u32)((x) & 0x00000007) << 4))
#define DVP_GET_RESP_RADDR(x)     ((u32)(((x >> 4) & 0x00000007)))
#define DVP_MASK_RESP_WADDR       ((u32)0x00000007 << 0)            /*!< R 0x0  */
#define DVP_RESP_WADDR(x)         (((u32)((x) & 0x00000007) << 0))
#define DVP_GET_RESP_WADDR(x)     ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup DVP_DMA_DEBUG_REG1
  * @brief
  * @{
  */
#define DVP_MASK_BUFIN_CNT    ((u32)0x0000003F << 16)           /*!< R 0x0  */
#define DVP_BUFIN_CNT(x)      (((u32)((x) & 0x0000003F) << 16))
#define DVP_GET_BUFIN_CNT(x)  ((u32)(((x >> 16) & 0x0000003F)))
#define DVP_MASK_BUFOUT_CNT   ((u32)0x0000003F << 8)            /*!< R 0x0  */
#define DVP_BUFOUT_CNT(x)     (((u32)((x) & 0x0000003F) << 8))
#define DVP_GET_BUFOUT_CNT(x) ((u32)(((x >> 8) & 0x0000003F)))
#define DVP_MASK_BURST_CNT    ((u32)0x0000003F << 0)            /*!< R 0x0  */
#define DVP_BURST_CNT(x)      (((u32)((x) & 0x0000003F) << 0))
#define DVP_GET_BURST_CNT(x)  ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup DVP_FUNC_DEBUG_REG0
  * @brief
  * @{
  */
#define DVP_MASK_P_STS_CCS   ((u32)0x00000007 << 16)           /*!< R 0x0  */
#define DVP_P_STS_CCS(x)     (((u32)((x) & 0x00000007) << 16))
#define DVP_GET_P_STS_CCS(x) ((u32)(((x >> 16) & 0x00000007)))
#define DVP_MASK_CCS_F_STS   ((u32)0x00000003 << 12)           /*!< R 0x0  */
#define DVP_CCS_F_STS(x)     (((u32)((x) & 0x00000003) << 12))
#define DVP_GET_CCS_F_STS(x) ((u32)(((x >> 12) & 0x00000003)))
#define DVP_MASK_CCS_L_STS   ((u32)0x00000003 << 8)            /*!< R 0x0  */
#define DVP_CCS_L_STS(x)     (((u32)((x) & 0x00000003) << 8))
#define DVP_GET_CCS_L_STS(x) ((u32)(((x >> 8) & 0x00000003)))
#define DVP_MASK_P_SUB_STS   ((u32)0x00000003 << 4)            /*!< R 0x0  */
#define DVP_P_SUB_STS(x)     (((u32)((x) & 0x00000003) << 4))
#define DVP_GET_P_SUB_STS(x) ((u32)(((x >> 4) & 0x00000003)))
#define DVP_MASK_L_SUB_STS   ((u32)0x00000003 << 0)            /*!< R 0x0  */
#define DVP_L_SUB_STS(x)     (((u32)((x) & 0x00000003) << 0))
#define DVP_GET_L_SUB_STS(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup DVP_DMA_STATUS
  * @brief
  * @{
  */
#define DVP_BIT_FRAME_STATUS_DONE3    ((u32)0x00000001 << 3)           /*!< R/W/ES 0x00  frame buffer 3 done 1: frame buffer full 0: frame buffer empty or receiving frame ?frame_end_int?????,??????????,??bit??1?????????frame buffer?????????.??software??????frame buffer???,????????bit??1?0*/
#define DVP_FRAME_STATUS_DONE3(x)     ((u32)(((x) & 0x00000001) << 3))
#define DVP_GET_FRAME_STATUS_DONE3(x) ((u32)(((x >> 3) & 0x00000001)))
#define DVP_BIT_FRAME_STATUS_DONE2    ((u32)0x00000001 << 2)           /*!< R/W/ES 0x00  frame buffer 2 done 1: frame buffer full 0: frame buffer empty or receiving frame ?frame_end_int?????,??????????,??bit??1?????????frame buffer?????????.??software??????frame buffer???,????????bit??1?0*/
#define DVP_FRAME_STATUS_DONE2(x)     ((u32)(((x) & 0x00000001) << 2))
#define DVP_GET_FRAME_STATUS_DONE2(x) ((u32)(((x >> 2) & 0x00000001)))
#define DVP_BIT_FRAME_STATUS_DONE1    ((u32)0x00000001 << 1)           /*!< R/W/ES 0x00  frame buffer 1 done 1: frame buffer full 0: frame buffer empty or receiving frame ?frame_end_int?????,??????????,??bit??1?????????frame buffer?????????.??software??????frame buffer???,????????bit??1?0*/
#define DVP_FRAME_STATUS_DONE1(x)     ((u32)(((x) & 0x00000001) << 1))
#define DVP_GET_FRAME_STATUS_DONE1(x) ((u32)(((x >> 1) & 0x00000001)))
#define DVP_BIT_FRAME_STATUS_DONE0    ((u32)0x00000001 << 0)           /*!< R/W/ES 0x00  frame buffer 0 done 1: frame buffer full 0: frame buffer empty or receiving frame ?frame_end_int?????,??????????,??bit??1?????????frame buffer?????????.??software??????frame buffer???,????????bit??1?0*/
#define DVP_FRAME_STATUS_DONE0(x)     ((u32)(((x) & 0x00000001) << 0))
#define DVP_GET_FRAME_STATUS_DONE0(x) ((u32)(((x >> 0) & 0x00000001)))
/** @} */

/** @} */
/* Exported Types --------------------------------------------------------*/

/** @defgroup DVP_Exported_Types DVP Exported Types
  * @{
  */

/** @brief DVP Register Declaration
  */

typedef struct {
	__IO uint32_t DVP_TRANSFER        ;  /*!< Register,  Address offset:0x000 */
	__IO uint32_t DVP_CONFIG          ;  /*!< Register,  Address offset:0x004 */
	__IO uint32_t RSVD0               ;  /*!< Reserved,  Address offset:0x008-0x00B */
	__IO uint32_t DVP_CROP_START_X    ;  /*!< Register,  Address offset:0x00C */
	__IO uint32_t DVP_CROP_START_Y    ;  /*!< Register,  Address offset:0x010 */
	__IO uint32_t DVP_WIDTH           ;  /*!< Register,  Address offset:0x014 */
	__IO uint32_t DVP_HEIGHT          ;  /*!< Register,  Address offset:0x018 */
	__I  uint32_t DVP_FRAME_CNT       ;  /*!< Register,  Address offset:0x01C */
	__IO uint32_t DVP_SUBSAMPLE_CTL   ;  /*!< Register,  Address offset:0x020 */
	__IO uint32_t DVP_SUBSAMPLE_CFG   ;  /*!< Register,  Address offset:0x024 */
	__IO uint32_t DVP_FRMAE_VLD_CTL   ;  /*!< Register,  Address offset:0x028 */
	__IO uint32_t DVP_YUV_TRANSFER    ;  /*!< Register,  Address offset:0x02C */
	__IO uint32_t DVP_JPEG_TRANSFER   ;  /*!< Register,  Address offset:0x030 */
	__IO uint32_t DVP_PCLK_GATING_CTL ;  /*!< Register,  Address offset:0x034 */
	__IO uint32_t DVP_PAD_CTL         ;  /*!< Register,  Address offset:0x038 */
	__O  uint32_t DVP_STOP            ;  /*!< Register,  Address offset:0x03C */
	__I  uint32_t DVP_JPG_FRAME_LENGTH;  /*!< Register,  Address offset:0x040 */
	__I  uint32_t DVP_INT_ST          ;  /*!< Register,  Address offset:0x044 */
	__I  uint32_t DVP_INT_RAW         ;  /*!< Register,  Address offset:0x048 */
	__IO uint32_t DVP_INT_EN          ;  /*!< Register,  Address offset:0x04C */
	__O  uint32_t DVP_INT_CLR         ;  /*!< Register,  Address offset:0x050 */
	__IO uint32_t DVP_DMA_CTRL        ;  /*!< Register,  Address offset:0x054 */
	__IO uint32_t DVP_FRAME_ADDR0     ;  /*!< Register,  Address offset:0x058 */
	__IO uint32_t DVP_FRAME_ADDR1     ;  /*!< Register,  Address offset:0x05C */
	__IO uint32_t DVP_FRAME_ADDR2     ;  /*!< Register,  Address offset:0x060 */
	__IO uint32_t DVP_FRAME_ADDR3     ;  /*!< Register,  Address offset:0x064 */
	__IO uint32_t DVP_DDR_LEN         ;  /*!< Register,  Address offset:0x068 */
	__IO uint32_t RSVD1               ;  /*!< Reserved,  Address offset:0x06C-0x06F */
	__I  uint32_t DVP_DMA_DEBUG_REG0  ;  /*!< Register,  Address offset:0x070 */
	__I  uint32_t DVP_DMA_DEBUG_REG1  ;  /*!< Register,  Address offset:0x074 */
	__I  uint32_t DVP_FUNC_DEBUG_REG0 ;  /*!< Register,  Address offset:0x078 */
	__IO uint32_t RSVD2               ;  /*!< Reserved,  Address offset:0x07C-0x07F */
	__IO uint32_t DVP_DMA_STATUS      ;  /*!< Register,  Address offset:0x080 */
} DVP_TypeDef;

/** @} */


// Do NOT modify any AUTO_GEN code above
/* AUTO_GEN_END */

/* MANUAL_GEN_START */

// Please add your definitions here

/* Exported Types ------------------------------------------------------------*/
/** @addtogroup DVP_Exported_Types DVP Exported Types
  * @{
  */

typedef struct {
	/* if enable YUV scale, then set subsample_ctrl & cfg register */
	u32 scale_flag;	/* 0,disable; 1, enable. bit0, pix_subsample; bit16, line_subsample */

	u16 pix_valid_byte;	/* requires a multiple of 4, max 16 */
	u16 pix_drop_byte;	/* requires a multiple of 4, max 16 */
	u16 line_valid;
	u16 line_drop;
} DVP_ScaleTypeDef;


/**
  * @brief  DVP Init Structure Definition
  */
typedef struct {
	/* pixel data swap */
	u8 bit_swap;				/*	2'b01: pad[9:0]={bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0,2'd0}
									2'b10: pad[9:0]={2'd0,bit0,bit1,bit2,bit3,bit4,bit5,bit6,bit7}
									2'b00&2'b11:pad[9:0]={2'd0,bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0} */
	/* timing info */
	u8 pclk_sample_edge;		/* 0,falling edge; 1,rising edge */
	u8 vsync_polar;				/* 0,active low; 1, active high */
	u8 hsync_polar;				/* 0,active low; 1, active high */

	/* image format info */
	u16 image_format;			/* Specifies the input image format.
								This parameter can be a value of @ref DVP_IMAGE_FORMAT. */
	union {
		u16 yuv422;				/* 2'b00,YUYV; 2'b01,YVYU; 2'b10,UYVY; 2'b11, VYUY */
		u16 jpg;				/* data_valid_len; dummy data location; hsync
								   3'b000: valid data. Vsync indicate frame sync, hsync indicate horizontal
								   3'b001: valid len -> valid data -> dummy data. Vsync indicate frame sync, hsync indicate horizontal
								   3'b010: valid data -> dummy data -> valid len. Vsync indicate frame sync, hsync indicate horizontal
								   3'b011: valid data -> dummy data. Vsync indicate frame sync, hsync indicate horizontal
								   3'b100: valid data. Only HSYNC indicate the frame signal
								*/
	} image_mode;

	/* YUV image ragne */
	u16 image_start_x;			/* drop x pixel, unit: pix_num */
	u16 image_start_y;			/* drop y line */
	u16 image_width;			/* post-crop and pre-subsample, unit: pix_num_in_bytes */
	u16 image_height;

	/* buffer mode/number/size/address info */
	u8 ring_buf_mode;			/* for yuv422: 1, ringbuf; 0, framebuf */
	u32 buf_len;				/* ddr_len or ring_buf len */

} DVP_InitTypeDef;

/** @} */

/* Exported Constants --------------------------------------------------------*/

/** @defgroup DVP_Exported_Constants DVP Exported Constants
  * @{
  */

/** @defgroup DVP_PCLK_SAMPLE_EDGE
 * @{
 */
#define DVP_PCLK_SAMPLE_FALLING_EDGE		(0)
#define DVP_PCLK_SAMPLE_RISING_EDGE			(1)
/** @} */

/** @defgroup DVP_VSYNC_POLARITY
 * @{
 */
#define DVP_VSYNC_ACTIVE_LOW				(0)
#define DVP_VSYNC_ACTIVE_HIGH				(1)
/** @} */


/** @defgroup DVP_HSYNC_POLARITY
 * @{
 */
#define DVP_HSYNC_ACTIVE_LOW				(0)
#define DVP_HSYNC_ACTIVE_HIGH				(1)
/** @} */


/** @defgroup DVP_SUBSAMPLE
 * @{
 */
#define PIX_SUB_SAMPLE_EN					(BIT0)
#define LINE_SUB_SAMPLE_EN					(BIT16)
/** @} */

/** @defgroup DVP_IMAGE_FORMAT
 * @{
 */
#define IMAGE_FORMAT_JPG					(1)
#define IMAGE_FORMAT_YUV422					(0)
/** @} */

/** @defgroup DVP_YUV422_STORAGE_FORMAT
 * @{
 */
#define IMAGE_YUV422_YUYV					(0)
#define IMAGE_YUV422_YVYU					(1)
#define IMAGE_YUV422_UYVY					(2)
#define IMAGE_YUV422_VYUY					(3)
/** @} */

/** @defgroup DVP_STOP_STREAM_METHOD
 * @{
 */
#define DVP_STOP_IMMEDIATELY					(1)
#define DVP_STOP_FRAMEDONE						(0)
/** @} */

/** @} */


/* Exported Functions --------------------------------------------------------*/
void DVP_StructInit(DVP_InitTypeDef *DVP_InitStruct);
void DVP_Init(DVP_TypeDef *dvp_dev, DVP_InitTypeDef *DVP_InitStruct);
void DVP_DmaBufConfig(DVP_TypeDef *dvp_dev, u32 BufNum, u32 *BufAddr);
void DVP_Start(void);
void DVP_Stop(u8 Immediately);

void DVP_IntConfig(DVP_TypeDef *dvp_dev, u32 DVP_IT, u32 NewStatus);
void DVP_IntLineNumConfig(DVP_TypeDef *dvp_dev, u32 LineNumer);
u32 DVP_GetIntStatus(DVP_TypeDef *dvp_dev);
u32 DVP_GetRawIntStatus(DVP_TypeDef *dvp_dev);
void DVP_ClearIntStatus(DVP_TypeDef *dvp_dev, u32 InterruptStatus);

void DVP_FramebufReturn(DVP_TypeDef *dvp_dev, u32 FramebufIdx);
u8 DVP_GetFramebuf(DVP_TypeDef *dvp_dev, u8 *fb_id_out, u32 *fb_addr_out);

u32 DVP_GetFrameCount(DVP_TypeDef *dvp_dev);

u32 DVP_GetJpegRecvLen(DVP_TypeDef *dvp_dev);
u8 DVP_GetImageFormat(DVP_TypeDef *dvp_dev);
void DVP_SubSampleConfig(DVP_TypeDef *dvp_dev, DVP_ScaleTypeDef *ScaleStruct);
void DVP_FrameSampleConfig(DVP_TypeDef *dvp_dev, u32 SkipFrameNum);
void DVP_PclkGatingCtrl(DVP_TypeDef *dvp_dev, u32 NewStatus);


/** @} */

/** @} */

// If other definitions do not need to be extracted to CHM document, add them here.
/* Other Definitions --------------------------------------------------------*/


/* MANUAL_GEN_END */

#endif