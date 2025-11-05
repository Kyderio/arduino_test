/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _RL6955_MJPEG_H_
#define _RL6955_MJPEG_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup MJPEG
  * @brief MJPEG driver modules
  * @{
  */


/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup MJPEG_Register_Definitions MJPEG Register Definitions
  * @{
  */

/** @defgroup MJPEG_CTRL
  * @brief MJPEG control register
  * @{
  */
#define MJPEG_BIT_JPEG_IDLE       ((u32)0x00000001 << 3)           /*!< R 0x0  jpeg idle status*/
#define MJPEG_JPEG_IDLE(x)        ((u32)(((x) & 0x00000001) << 3))
#define MJPEG_BIT_JPEG_FRAME_STOP ((u32)0x00000001 << 2)           /*!< WA0 0x0  jpeg stop processing after current frame enc/dec done*/
#define MJPEG_JPEG_FRAME_STOP(x)  ((u32)(((x) & 0x00000001) << 2))
#define MJPEG_BIT_JPEG_QUICK_STOP ((u32)0x00000001 << 1)           /*!< WA0 0x0  jpeg stop processing after current axi cmd complete.*/
#define MJPEG_JPEG_QUICK_STOP(x)  ((u32)(((x) & 0x00000001) << 1))
#define MJPEG_BIT_JPEG_START      ((u32)0x00000001 << 0)           /*!< WA0 0x0  jpeg start processing*/
#define MJPEG_JPEG_START(x)       ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_CONFIG
  * @brief MJPEG config register
  * @{
  */
#define MJPEG_MASK_Y_SIZE                  ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  Number of lines in source image*/
#define MJPEG_Y_SIZE(x)                    (((u32)((x) & 0x0000FFFF) << 16))
#define MJPEG_GET_Y_SIZE(x)                ((u32)(((x >> 16) & 0x0000FFFF)))
#define MJPEG_BIT_HDR_EN                   ((u32)0x00000001 << 8)            /*!< R/W 0x0  Header Processing (generation/parsing) enabled when set*/
#define MJPEG_HDR_EN(x)                    ((u32)(((x) & 0x00000001) << 8))
#define MJPEG_MASK_COMPONENT_NUM_SCAN      ((u32)0x00000003 << 6)            /*!< R/W 0x0  Number of Components for Scan Header Marker Segment, minus one.*/
#define MJPEG_COMPONENT_NUM_SCAN(x)        (((u32)((x) & 0x00000003) << 6))
#define MJPEG_GET_COMPONENT_NUM_SCAN(x)    ((u32)(((x >> 6) & 0x00000003)))
#define MJPEG_MASK_COLSPCTYPE              ((u32)0x00000003 << 4)            /*!< R/W 0x0  colspctype defines the number of quantization tables to insert in the output stream minus one. 0 = Grayscale, 1 = YUV, 2 = RGB, 3 = CMYK*/
#define MJPEG_COLSPCTYPE(x)                (((u32)((x) & 0x00000003) << 4))
#define MJPEG_GET_COLSPCTYPE(x)            ((u32)(((x >> 4) & 0x00000003)))
#define MJPEG_BIT_EN_OR_DE                 ((u32)0x00000001 << 3)            /*!< R/W 0x0  Selects encoding or decoding behavior. When this bit is set, the CODEC acts as a decoder; otherwise, it works as an encoder*/
#define MJPEG_EN_OR_DE(x)                  ((u32)(((x) & 0x00000001) << 3))
#define MJPEG_BIT_RST_MARKER_PROCESSING_EN ((u32)0x00000001 << 2)            /*!< R/W 0x0  Enables restart marker processing when set. The ECS Encoder inserts restart markers every NRST +1 MCU*/
#define MJPEG_RST_MARKER_PROCESSING_EN(x)  ((u32)(((x) & 0x00000001) << 2))
#define MJPEG_MASK_COMPONENT_NUM_IMG       ((u32)0x00000003 << 0)            /*!< R/W 0x0  Number of color components in the source image minus 1. For example, in a grayscale image its value is 0; for a RGB or YUV image its value is = 2*/
#define MJPEG_COMPONENT_NUM_IMG(x)         (((u32)((x) & 0x00000003) << 0))
#define MJPEG_GET_COMPONENT_NUM_IMG(x)     ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup MJPEG_MCUNUM
  * @brief MJPEG MCU number register
  * @{
  */
#define MJPEG_MASK_MCU_NUM   ((u32)0x03FFFFFF << 0)           /*!< R/W 0x0  Number of MCU units to encode minus 1*/
#define MJPEG_MCU_NUM(x)     (((u32)((x) & 0x03FFFFFF) << 0))
#define MJPEG_GET_MCU_NUM(x) ((u32)(((x >> 0) & 0x03FFFFFF)))
/** @} */

/** @defgroup MJPEG_RST_INTERVAL
  * @brief MJPEG reset interval control register
  * @{
  */
#define MJPEG_MASK_X_SIZE   ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  Number of pixels per line*/
#define MJPEG_X_SIZE(x)       (((u32)((x) & 0x0000FFFF) << 16))
#define MJPEG_GET_X_SIZE(x)   ((u32)(((x >> 16) & 0x0000FFFF)))
#define MJPEG_MASK_NRST     ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  NRST value is the number of MCUs between two restart markers minus 1. The content of this register is ignored if the rst_marker_processing_en bit is not set.*/
#define MJPEG_NRST(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define MJPEG_GET_NRST(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup MJPEG_COMPONENTx
  * @brief MJPEG component registerx
  * @{
  */
#define MJPEG_MASK_H_FACTOR       ((u32)0x0000000F << 12)           /*!< R/W 0x0  Horizontal Sampling factor for component i.*/
#define MJPEG_H_FACTOR(x)         (((u32)((x) & 0x0000000F) << 12))
#define MJPEG_GET_H_FACTOR(x)     ((u32)(((x >> 12) & 0x0000000F)))
#define MJPEG_MASK_V_FACTOR       ((u32)0x0000000F << 8)            /*!< R/W 0x0  Vertical Sampling factor for component i.*/
#define MJPEG_V_FACTOR(x)         (((u32)((x) & 0x0000000F) << 8))
#define MJPEG_GET_V_FACTOR(x)     ((u32)(((x >> 8) & 0x0000000F)))
#define MJPEG_MASK_BLOCK_NUM      ((u32)0x0000000F << 4)            /*!< R/W 0x0  The value is the number of data units (8 x 8 blocks of data) of the color component i contained in the MCU minus 1. The range is 0-15, because 4 bits are set aside for this field.*/
#define MJPEG_BLOCK_NUM(x)        (((u32)((x) & 0x0000000F) << 4))
#define MJPEG_GET_BLOCK_NUM(x)    ((u32)(((x >> 4) & 0x0000000F)))
#define MJPEG_MASK_QTABLE_INDEX   ((u32)0x00000003 << 2)            /*!< R/W 0x0  It indicates the quantization table to be used for the color component i. Since four quantization tables are possible, 2 bits are sufficient for this field (bits 3-2 in the register).*/
#define MJPEG_QTABLE_INDEX(x)     (((u32)((x) & 0x00000003) << 2))
#define MJPEG_GET_QTABLE_INDEX(x) ((u32)(((x >> 2) & 0x00000003)))
#define MJPEG_BIT_HTABLE_INDEX_AC ((u32)0x00000001 << 1)            /*!< R/W 0x0  It selects the Huffman table for the encoding of the AC coefficients in the data units belonging to the color component i. Since only two AC tables are allowed in the baseline algorithm, one bit is sufficient (bit 1 in the register).*/
#define MJPEG_HTABLE_INDEX_AC(x)  ((u32)(((x) & 0x00000001) << 1))
#define MJPEG_BIT_HTABLE_INDEX_DC ((u32)0x00000001 << 0)            /*!< R/W 0x0  It bit selects the Huffman table for the encoding of the DC coefficient in the data units belonging to the color component i. Since only two DC tables are allowed in the baseline algorithm, one bit is sufficient (bit 0 in the register).*/
#define MJPEG_HTABLE_INDEX_DC(x)  ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_SW_QMEM
  * @brief MJPEG Qtable memory configuration
  * @{
  */
#define MJPEG_BIT_SW_QMEM_EN      ((u32)0x00000001 << 29)           /*!< R/W 0x0  Qtable configuration information, SRAM chip selection signal, write 1 when reading and writing*/
#define MJPEG_SW_QMEM_EN(x)       ((u32)(((x) & 0x00000001) << 29))
#define MJPEG_BIT_SW_QMEM_WE      ((u32)0x00000001 << 28)           /*!< R/W 0x0  Qtable configuration information, SRAM write enable*/
#define MJPEG_SW_QMEM_WE(x)       ((u32)(((x) & 0x00000001) << 28))
#define MJPEG_MASK_SW_QMEM_ADDR   ((u32)0x000000FF << 16)           /*!< R/W 0x0  Qtable configuration information, selected address for SRAM*/
#define MJPEG_SW_QMEM_ADDR(x)     (((u32)((x) & 0x000000FF) << 16))
#define MJPEG_GET_SW_QMEM_ADDR(x) ((u32)(((x >> 16) & 0x000000FF)))
#define MJPEG_MASK_SW_QMEM_DIN    ((u32)0x000000FF << 0)            /*!< R/W 0x0  Qtable configuration information, write SRAM value*/
#define MJPEG_SW_QMEM_DIN(x)      (((u32)((x) & 0x000000FF) << 0))
#define MJPEG_GET_SW_QMEM_DIN(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup MJPEG_SW_HUFFENC
  * @brief MJPEG huffman memory configuration
  * @{
  */
#define MJPEG_BIT_SW_HUFFENC_EN      ((u32)0x00000001 << 29)           /*!< R/W 0x0  huffman table configuration information, SRAM chip selection signal, write 1 when reading and writing*/
#define MJPEG_SW_HUFFENC_EN(x)       ((u32)(((x) & 0x00000001) << 29))
#define MJPEG_BIT_SW_HUFFENC_WE      ((u32)0x00000001 << 28)           /*!< R/W 0x0  huffman table configuration information, SRAM write enable*/
#define MJPEG_SW_HUFFENC_WE(x)       ((u32)(((x) & 0x00000001) << 28))
#define MJPEG_MASK_SW_HUFFENC_ADDR   ((u32)0x000001FF << 16)           /*!< R/W 0x0  huffman table configuration information, selected address for SRAM*/
#define MJPEG_SW_HUFFENC_ADDR(x)     (((u32)((x) & 0x000001FF) << 16))
#define MJPEG_GET_SW_HUFFENC_ADDR(x) ((u32)(((x >> 16) & 0x000001FF)))
#define MJPEG_MASK_SW_HUFFENC_DIN    ((u32)0x00000FFF << 0)            /*!< R/W 0x0  huffman table configuration information, write SRAM value*/
#define MJPEG_SW_HUFFENC_DIN(x)      (((u32)((x) & 0x00000FFF) << 0))
#define MJPEG_GET_SW_HUFFENC_DIN(x)  ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup MJPEG_SW_DHT
  * @brief MJPEG DQT memory configuration
  * @{
  */
#define MJPEG_BIT_SW_DHT_EN      ((u32)0x00000001 << 29)           /*!< R/W 0x0  DHT configuration information, SRAM chip selection signal, write 1 when reading and writing*/
#define MJPEG_SW_DHT_EN(x)       ((u32)(((x) & 0x00000001) << 29))
#define MJPEG_BIT_SW_DHT_WE      ((u32)0x00000001 << 28)           /*!< R/W 0x0  DHT configuration information, SRAM write enable*/
#define MJPEG_SW_DHT_WE(x)       ((u32)(((x) & 0x00000001) << 28))
#define MJPEG_MASK_SW_DHT_ADDR   ((u32)0x000001FF << 16)           /*!< R/W 0x0  DHT configuration information, selected address for SRAM*/
#define MJPEG_SW_DHT_ADDR(x)     (((u32)((x) & 0x000001FF) << 16))
#define MJPEG_GET_SW_DHT_ADDR(x) ((u32)(((x >> 16) & 0x000001FF)))
#define MJPEG_MASK_SW_DHT_DIN    ((u32)0x000000FF << 0)            /*!< R/W 0x0  DHT configuration information, write SRAM value*/
#define MJPEG_SW_DHT_DIN(x)      (((u32)((x) & 0x000000FF) << 0))
#define MJPEG_GET_SW_DHT_DIN(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup MJPEG_DONE_INT_STS
  * @brief MJPEG encoder/decoder done interrupt status
  * @{
  */
#define MJPEG_BIT_JPEG_DEC_DONE_INT ((u32)0x00000001 << 1)           /*!< R 0x0  JPEG decoding done interrupt (JPEG clock domain)*/
#define MJPEG_JPEG_DEC_DONE_INT(x)  ((u32)(((x) & 0x00000001) << 1))
#define MJPEG_BIT_JPEG_ENC_DONE_INT ((u32)0x00000001 << 0)           /*!< R 0x0  JPEG encoding done interrupt (JPEG clock domain)*/
#define MJPEG_JPEG_ENC_DONE_INT(x)  ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_DONE_INT_EN
  * @brief MJPEG encoder/decoder done interrupt enable signal
  * @{
  */
#define MJPEG_BIT_JPEG_DEC_DONE_INT_EN ((u32)0x00000001 << 1)           /*!< R/W 0x0  JPEG decoding interrupt enable signal*/
#define MJPEG_JPEG_DEC_DONE_INT_EN(x)  ((u32)(((x) & 0x00000001) << 1))
#define MJPEG_BIT_JPEG_ENC_DONE_INT_EN ((u32)0x00000001 << 0)           /*!< R/W 0x0  JPEG encoding interrupt enable signal*/
#define MJPEG_JPEG_ENC_DONE_INT_EN(x)  ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_DONE_INT_CLR
  * @brief MJPEG encoder/decoder done interrupt clear signal
  * @{
  */
#define MJPEG_BIT_JPEG_DEC_DONE_INT_CLR ((u32)0x00000001 << 1)           /*!< R/W 0x0  JPEG encoding interrupt clearing signal*/
#define MJPEG_JPEG_DEC_DONE_INT_CLR(x)  ((u32)(((x) & 0x00000001) << 1))
#define MJPEG_BIT_JPEG_ENC_DONE_INT_CLR ((u32)0x00000001 << 0)           /*!< R/W 0x0  JPEG encoding interrupt clearing signal*/
#define MJPEG_JPEG_ENC_DONE_INT_CLR(x)  ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_DONE_INT_RAW
  * @brief MJPEG encoder/decoder done interrupt raw status
  * @{
  */
#define MJPEG_BIT_JPEG_DEC_DONE_INT_RAW ((u32)0x00000001 << 1)           /*!< R 0x0  JPEG decoding done raw interrupt (JPEG clock domain)*/
#define MJPEG_JPEG_DEC_DONE_INT_RAW(x)  ((u32)(((x) & 0x00000001) << 1))
#define MJPEG_BIT_JPEG_ENC_DONE_INT_RAW ((u32)0x00000001 << 0)           /*!< R 0x0  JPEG encoding done raw interrupt (JPEG clock domain)*/
#define MJPEG_JPEG_ENC_DONE_INT_RAW(x)  ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_RD_START_ADDR
  * @brief MJPEG encoder/decoder reading buffer address
  * @{
  */
#define MJPEG_MASK_RD_START_ADDR   ((u32)0x3FFFFFFF << 2)           /*!< R/W 0x0  The starting address of the read during encoding or decoding, aligned with 4 bytes*/
#define MJPEG_RD_START_ADDR(x)     (((u32)((x) & 0x3FFFFFFF) << 2))
#define MJPEG_GET_RD_START_ADDR(x) ((u32)(((x >> 2) & 0x3FFFFFFF)))
/** @} */

/** @defgroup MJPEG_RD_BUFFER_LEN
  * @brief MJPEG encoder/decoder reading buffer length
  * @{
  */
#define MJPEG_MASK_RD_LEN   ((u32)0x00FFFFFF << 0)           /*!< R/W 0x0  The length of the read during encoding or decoding*/
#define MJPEG_RD_LEN(x)     (((u32)((x) & 0x00FFFFFF) << 0))
#define MJPEG_GET_RD_LEN(x) ((u32)(((x >> 0) & 0x00FFFFFF)))
/** @} */

/** @defgroup MJPEG_RING_BUFFER_MODE
  * @brief MJPEG ringbuffer enable signal
  * @{
  */
#define MJPEG_BIT_RING_BUFFER_EN ((u32)0x00000001 << 0)           /*!< R/W 0x0  ring buffer enable signal*/
#define MJPEG_RING_BUFFER_EN(x)  ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_RING_BUFFER_SIZE
  * @brief MJPEG ringbuffer size
  * @{
  */
#define MJPEG_MASK_RING_BUFFER_SIZE   ((u32)0x0000003F << 0)           /*!< R/W 0x0  ring buffer size (unit: line). The ring buffer size  must be a multiple of 8, while the DDR len of DVP is in byte units. When in ring buffer mode, it is necessary to satisfy the condition of ring_fuffer_stize * width * 2=DDR len*/
#define MJPEG_RING_BUFFER_SIZE(x)     (((u32)((x) & 0x0000003F) << 0))
#define MJPEG_GET_RING_BUFFER_SIZE(x) ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup MJPEG_WR_START_ADDR
  * @brief MJPEG encoder/decoder writeing buffer address
  * @{
  */
#define MJPEG_MASK_WR_START_ADDR   ((u32)0x3FFFFFFF << 2)           /*!< R/W 0x0  The starting address of the write during encoding or decoding, aligned with 4 bytes*/
#define MJPEG_WR_START_ADDR(x)     (((u32)((x) & 0x3FFFFFFF) << 2))
#define MJPEG_GET_WR_START_ADDR(x) ((u32)(((x >> 2) & 0x3FFFFFFF)))
/** @} */

/** @defgroup MJPEG_ENC_WR_START_ADDR_1
  * @brief MJPEG ringbuffer address 1
  * @{
  */
#define MJPEG_MASK_ENC_WR_START_ADDR_1   ((u32)0x3FFFFFFF << 2)           /*!< R/W 0x0  the encoder stream write address for buffer1 in the ring buffer mode, aligned with 4 bytes*/
#define MJPEG_ENC_WR_START_ADDR_1(x)     (((u32)((x) & 0x3FFFFFFF) << 2))
#define MJPEG_GET_ENC_WR_START_ADDR_1(x) ((u32)(((x >> 2) & 0x3FFFFFFF)))
/** @} */

/** @defgroup MJPEG_ENC_WR_START_ADDR_2
  * @brief MJPEG ringbuffer address 2
  * @{
  */
#define MJPEG_MASK_ENC_WR_START_ADDR_2   ((u32)0x3FFFFFFF << 2)           /*!< R/W 0x0  the encoder stream write address for buffer2 in the ring buffer mode, aligned with 4 bytes*/
#define MJPEG_ENC_WR_START_ADDR_2(x)     (((u32)((x) & 0x3FFFFFFF) << 2))
#define MJPEG_GET_ENC_WR_START_ADDR_2(x) ((u32)(((x >> 2) & 0x3FFFFFFF)))
/** @} */

/** @defgroup MJPEG_ENC_WR_START_ADDR_3
  * @brief MJPEG ringbuffer address 3
  * @{
  */
#define MJPEG_MASK_ENC_WR_START_ADDR_3   ((u32)0x3FFFFFFF << 2)           /*!< R/W 0x0  the encoder stream write address for buffer3 in the ring buffer mode, aligned with 4 bytes*/
#define MJPEG_ENC_WR_START_ADDR_3(x)     (((u32)((x) & 0x3FFFFFFF) << 2))
#define MJPEG_GET_ENC_WR_START_ADDR_3(x) ((u32)(((x >> 2) & 0x3FFFFFFF)))
/** @} */

/** @defgroup MJPEG_WR_BUFFER_LEN
  * @brief MJPEG writing buffer size
  * @{
  */
#define MJPEG_MASK_BUFFER_LENGTH   ((u32)0x003FFFFF << 2)           /*!< R/W 0x0  The size of the address space allocated to the encoder write stream, aligned with 4 bytes*/
#define MJPEG_BUFFER_LENGTH(x)     (((u32)((x) & 0x003FFFFF) << 2))
#define MJPEG_GET_BUFFER_LENGTH(x) ((u32)(((x >> 2) & 0x003FFFFF)))
/** @} */

/** @defgroup MJPEG_ENC_BUFFER_RECEIVED_LENGTH
  * @brief MJPEG received length of buffer0
  * @{
  */
#define MJPEG_MASK_BUFFER_RECEIVED_LENGTH_0   ((u32)0x007FFFFF << 0)           /*!< R 0x0  the received length of buffer0*/
#define MJPEG_BUFFER_RECEIVED_LENGTH_0(x)     (((u32)((x) & 0x007FFFFF) << 0))
#define MJPEG_GET_BUFFER_RECEIVED_LENGTH_0(x) ((u32)(((x >> 0) & 0x007FFFFF)))
/** @} */

/** @defgroup MJPEG_ENC_BUFFER_RECEIVED_LENGTH_1
  * @brief MJPEG received length of buffer1
  * @{
  */
#define MJPEG_MASK_BUFFER_RECEIVED_LENGTH_1   ((u32)0x007FFFFF << 0)           /*!< R 0x0  the received length of buffer1*/
#define MJPEG_BUFFER_RECEIVED_LENGTH_1(x)     (((u32)((x) & 0x007FFFFF) << 0))
#define MJPEG_GET_BUFFER_RECEIVED_LENGTH_1(x) ((u32)(((x >> 0) & 0x007FFFFF)))
/** @} */

/** @defgroup MJPEG_ENC_BUFFER_RECEIVED_LENGTH_2
  * @brief MJPEG received length of buffer2
  * @{
  */
#define MJPEG_MASK_BUFFER_RECEIVED_LENGTH_2   ((u32)0x007FFFFF << 0)           /*!< R 0x0  the received length of buffer2*/
#define MJPEG_BUFFER_RECEIVED_LENGTH_2(x)     (((u32)((x) & 0x007FFFFF) << 0))
#define MJPEG_GET_BUFFER_RECEIVED_LENGTH_2(x) ((u32)(((x >> 0) & 0x007FFFFF)))
/** @} */

/** @defgroup MJPEG_ENC_BUFFER_RECEIVED_LENGTH_3
  * @brief MJPEG received length of buffer3
  * @{
  */
#define MJPEG_MASK_BUFFER_RECEIVED_LENGTH_3   ((u32)0x007FFFFF << 0)           /*!< R 0x0  the received length of buffer3*/
#define MJPEG_BUFFER_RECEIVED_LENGTH_3(x)     (((u32)((x) & 0x007FFFFF) << 0))
#define MJPEG_GET_BUFFER_RECEIVED_LENGTH_3(x) ((u32)(((x >> 0) & 0x007FFFFF)))
/** @} */

/** @defgroup MJPEG_BUFFER_OVERFLOW_INT_STS
  * @brief MJPEG overflow interrupt status
  * @{
  */
#define MJPEG_BIT_RINGBUFFER_OVERFLOW_INT ((u32)0x00000001 << 1)           /*!< R 0x0  ring buffer overflow interrupt flag,indicate ringbuffer overflow during encoding*/
#define MJPEG_RINGBUFFER_OVERFLOW_INT(x)  ((u32)(((x) & 0x00000001) << 1))
#define MJPEG_BIT_WR_OVERFLOW_INT         ((u32)0x00000001 << 0)           /*!< R 0x0  write overflow interrupt flag,indicate write buffer is overflowed during encoding and decoding*/
#define MJPEG_WR_OVERFLOW_INT(x)          ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_BUFFER_OVERFLOW_INT_EN
  * @brief MJPEG overflow interrupt enable signal
  * @{
  */
#define MJPEG_BIT_RINGBUFFER_OVERFLOW_INT_EN ((u32)0x00000001 << 1)           /*!< R/W 0x0  ring buffer overflow interrupt enable signal*/
#define MJPEG_RINGBUFFER_OVERFLOW_INT_EN(x)  ((u32)(((x) & 0x00000001) << 1))
#define MJPEG_BIT_WR_OVERFLOW_INT_EN         ((u32)0x00000001 << 0)           /*!< R/W 0x0  write overflow interrupt enable signal*/
#define MJPEG_WR_OVERFLOW_INT_EN(x)          ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_BUFFER_OVERFLOW_INT_CLR
  * @brief MJPEG overflow interrupt clear signal
  * @{
  */
#define MJPEG_BIT_RINGBUFFER_OVERFLOW_INT_CLR ((u32)0x00000001 << 1)           /*!< R/W 0x0  ring buffer overflow interrupt clear signal*/
#define MJPEG_RINGBUFFER_OVERFLOW_INT_CLR(x)  ((u32)(((x) & 0x00000001) << 1))
#define MJPEG_BIT_WR_OVERFLOW_INT_CLR         ((u32)0x00000001 << 0)           /*!< R/W 0x0  write overflow interrupt clear signal*/
#define MJPEG_WR_OVERFLOW_INT_CLR(x)          ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_BUFFER_OVERFLOW_INT_RAW
  * @brief MJPEG overflow interrupt raw status
  * @{
  */
#define MJPEG_BIT_RINGBUFFER_OVERFLOW_INT_RAW ((u32)0x00000001 << 1)           /*!< R 0x0  ring buffer overflow interrupt raw signal*/
#define MJPEG_RINGBUFFER_OVERFLOW_INT_RAW(x)  ((u32)(((x) & 0x00000001) << 1))
#define MJPEG_BIT_WR_OVERFLOW_INT_RAW         ((u32)0x00000001 << 0)           /*!< R 0x0  write overflow interrupt raw signal*/
#define MJPEG_WR_OVERFLOW_INT_RAW(x)          ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_BUFFER_FRAME_NUM
  * @brief MJPEG number of buffer in ringbufffer mode
  * @{
  */
#define MJPEG_MASK_BUFFER_FRAME_NUM   ((u32)0x00000007 << 0)           /*!< R/W 0x0  Indicates the number of buffers configured for encoding the output stream when encoding in ring buffer mode*/
#define MJPEG_BUFFER_FRAME_NUM(x)     (((u32)((x) & 0x00000007) << 0))
#define MJPEG_GET_BUFFER_FRAME_NUM(x) ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup MJPEG_BUFFER_FRAME_STATUS
  * @brief MJPEG buffer status
  * @{
  */
#define MJPEG_MASK_BUFFER_FRAME_STATUS   ((u32)0x0000000F << 0)           /*!< R/W 0x0  bits [0] [1] [2] [3] respectively represent the status of the buffer ([x] bit 1 indicates which buffer already contains a frame of encoded data)*/
#define MJPEG_BUFFER_FRAME_STATUS(x)     (((u32)((x) & 0x0000000F) << 0))
#define MJPEG_GET_BUFFER_FRAME_STATUS(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup MJPEG_BUFFER_FRAME_CNT
  * @brief MJPEG using buffer index
  * @{
  */
#define MJPEG_MASK_BUFFER_FRAME_CNT   ((u32)0x00000003 << 0)           /*!< R 0x0  indicates which buffer is currently being written to*/
#define MJPEG_BUFFER_FRAME_CNT(x)     (((u32)((x) & 0x00000003) << 0))
#define MJPEG_GET_BUFFER_FRAME_CNT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup MJPEG_TIMEOUT_CFG
  * @brief MJPEG timeout configuration
  * @{
  */
#define MJPEG_MASK_TIMEOUT_CFG   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  timeout value (unit: clock cycle)*/
#define MJPEG_TIMEOUT_CFG(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define MJPEG_GET_TIMEOUT_CFG(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup MJPEG_TIMEOUT_CFG_EN
  * @brief MJPEG timeout function enable
  * @{
  */
#define MJPEG_BIT_TIMEOUT_CFG_EN ((u32)0x00000001 << 0)           /*!< R/W 0x0  enable/disable timeout function*/
#define MJPEG_TIMEOUT_CFG_EN(x)  ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_TIMEOUT_STS
  * @brief MJPEG timeout interrupt status
  * @{
  */
#define MJPEG_BIT_TIMEOUT_INT ((u32)0x00000001 << 0)           /*!< R 0x0  timeout interrupt status*/
#define MJPEG_TIMEOUT_INT(x)  ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_TIMEOUT_EN
  * @brief MJPEG timeout interrupt enable signal
  * @{
  */
#define MJPEG_BIT_TIMEOUT_INT_EN ((u32)0x00000001 << 0)           /*!< R/W 0x0  timeout interrupt enable*/
#define MJPEG_TIMEOUT_INT_EN(x)  ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_TIMEOUT_CLR
  * @brief MJPEG timeout interrupt clear signal
  * @{
  */
#define MJPEG_BIT_TIMEOUT_INT_CLR ((u32)0x00000001 << 0)           /*!< R/W 0x0  timeout interrupt clear*/
#define MJPEG_TIMEOUT_INT_CLR(x)  ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_TIMEOUT_RAW
  * @brief MJPEG timeout interrupt raw status
  * @{
  */
#define MJPEG_BIT_TIMEOUT_INT_RAW ((u32)0x00000001 << 0)           /*!< R 0x0  timeout interrupt raw status*/
#define MJPEG_TIMEOUT_INT_RAW(x)  ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_BUFFER_CNT_OVERFLOW_INT_STS
  * @brief MJPEG ringbuffer count overflow interrupt status
  * @{
  */
#define MJPEG_BIT_BUFFER_CNT_OVERFLOW_INT ((u32)0x00000001 << 0)           /*!< R 0x0  ringbuffer count overflow interrupt status*/
#define MJPEG_BUFFER_CNT_OVERFLOW_INT(x)  ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_BUFFER_CNT_OVERFLOW_INT_EN
  * @brief MJPEG ringbuffer count overflow interrupt enable signal
  * @{
  */
#define MJPEG_BIT_BUFFER_CNT_OVERFLOW_INT_EN ((u32)0x00000001 << 0)           /*!< R/W 0x0  ringbuffer count overflow interrupt enable signal*/
#define MJPEG_BUFFER_CNT_OVERFLOW_INT_EN(x)  ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_BUFFER_CNT_OVERFLOW_INT_CLR
  * @brief MJPEG ringbuffer count overflow interrupt clear signal
  * @{
  */
#define MJPEG_BIT_BUFFER_CNT_OVERFLOW_INT_CLR ((u32)0x00000001 << 0)           /*!< R/W 0x0  ringbuffer count overflow interrupt clear signal*/
#define MJPEG_BUFFER_CNT_OVERFLOW_INT_CLR(x)  ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_BUFFER_CNT_OVERFLOW_INT_RAW
  * @brief MJPEG ringbuffer count overflow interrupt raw signal
  * @{
  */
#define MJPEG_BIT_BUFFER_CNT_OVERFLOW_INT_RAW ((u32)0x00000001 << 0)           /*!< R 0x0  ringbuffer count overflow interrupt raw status*/
#define MJPEG_BUFFER_CNT_OVERFLOW_INT_RAW(x)  ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @defgroup MJPEG_MISS_FRAME_CNT
  * @brief MJPEG ringbuffer miss frame count
  * @{
  */
#define MJPEG_BIT_MISS_FRAME_CNT ((u32)0x00000001 << 0)           /*!< R 0x0  ringbuffer miss frame count*/
#define MJPEG_MISS_FRAME_CNT(x)  ((u32)(((x) & 0x00000001) << 0))
/** @} */

/** @} */
/* Exported Types --------------------------------------------------------*/

/** @defgroup MJPEG_Exported_Types MJPEG Exported Types
  * @{
  */

/** @brief MJPEG Register Declaration
  */

typedef struct {
	__IO uint32_t MJPEG_CTRL                        ;  /*!< MJPEG CONTROL REGISTER,  Address offset:0x000 */
	__IO uint32_t MJPEG_CONFIG                      ;  /*!< MJPEG CONFIG REGISTER,  Address offset:0x004 */
	__IO uint32_t MJPEG_MCUNUM                      ;  /*!< MJPEG MCU NUMBER REGISTER,  Address offset:0x008 */
	__IO uint32_t MJPEG_RST_INTERVAL                ;  /*!< MJPEG RESET INTERVAL CONTROL REGISTER,  Address offset:0x00C */
	__IO uint32_t MJPEG_COMPONENTx[4]               ;  /*!< MJPEG COMPONENT REGISTERx Register,  Address offset:0x010-0x01C */
	__IO uint32_t MJPEG_SW_QMEM                     ;  /*!< MJPEG QTABLE MEMORY CONFIGURATION Register,  Address offset:0x020 */
	__IO uint32_t MJPEG_SW_HUFFENC                  ;  /*!< MJPEG HUFFMAN MEMORY CONFIGURATION Register,  Address offset:0x024 */
	__IO uint32_t MJPEG_SW_DHT                      ;  /*!< MJPEG DQT MEMORY CONFIGURATION Register,  Address offset:0x028 */
	__I  uint32_t MJPEG_DONE_INT_STS                ;  /*!< MJPEG ENCODER/DECODER DONE INTERRUPT STATUS Register,  Address offset:0x02C */
	__IO uint32_t MJPEG_DONE_INT_EN                 ;  /*!< MJPEG ENCODER/DECODER DONE INTERRUPT ENABLE SIGNAL Register,  Address offset:0x030 */
	__IO uint32_t MJPEG_DONE_INT_CLR                ;  /*!< MJPEG ENCODER/DECODER DONE INTERRUPT CLEAR SIGNAL Register,  Address offset:0x034 */
	__I  uint32_t MJPEG_DONE_INT_RAW                ;  /*!< MJPEG ENCODER/DECODER DONE INTERRUPT RAW STATUS Register,  Address offset:0x038 */
	__IO uint32_t MJPEG_RD_START_ADDR               ;  /*!< MJPEG ENCODER/DECODER READING BUFFER ADDRESS Register,  Address offset:0x03C */
	__IO uint32_t MJPEG_RD_BUFFER_LEN               ;  /*!< MJPEG ENCODER/DECODER READING BUFFER LENGTH Register,  Address offset:0x040 */
	__IO uint32_t RSVD0                             ;  /*!< Reserved,  Address offset:0x044-0x047 */
	__IO uint32_t MJPEG_RING_BUFFER_MODE            ;  /*!< MJPEG RINGBUFFER ENABLE SIGNAL Register,  Address offset:0x048 */
	__IO uint32_t MJPEG_RING_BUFFER_SIZE            ;  /*!< MJPEG RINGBUFFER SIZE Register,  Address offset:0x04C */
	__IO uint32_t MJPEG_WR_START_ADDR               ;  /*!< MJPEG ENCODER/DECODER WRITEING BUFFER ADDRESS Register,  Address offset:0x050 */
	__IO uint32_t MJPEG_ENC_WR_START_ADDR_1         ;  /*!< MJPEG RINGBUFFER ADDRESS 1 Register,  Address offset:0x054 */
	__IO uint32_t MJPEG_ENC_WR_START_ADDR_2         ;  /*!< MJPEG RINGBUFFER ADDRESS 2 Register,  Address offset:0x058 */
	__IO uint32_t MJPEG_ENC_WR_START_ADDR_3         ;  /*!< MJPEG RINGBUFFER ADDRESS 3 Register,  Address offset:0x05C */
	__IO uint32_t MJPEG_WR_BUFFER_LEN               ;  /*!< MJPEG WRITING BUFFER SIZE Register,  Address offset:0x060 */
	__I  uint32_t MJPEG_ENC_BUFFER_RECEIVED_LENGTH  ;  /*!< MJPEG RECEIVED LENGTH OF BUFFER0 Register,  Address offset:0x064 */
	__I  uint32_t MJPEG_ENC_BUFFER_RECEIVED_LENGTH_1;  /*!< MJPEG RECEIVED LENGTH OF BUFFER1 Register,  Address offset:0x068 */
	__I  uint32_t MJPEG_ENC_BUFFER_RECEIVED_LENGTH_2;  /*!< MJPEG RECEIVED LENGTH OF BUFFER2 Register,  Address offset:0x06C */
	__I  uint32_t MJPEG_ENC_BUFFER_RECEIVED_LENGTH_3;  /*!< MJPEG RECEIVED LENGTH OF BUFFER3 Register,  Address offset:0x070 */
	__I  uint32_t MJPEG_BUFFER_OVERFLOW_INT_STS     ;  /*!< MJPEG OVERFLOW INTERRUPT STATUS Register,  Address offset:0x074 */
	__IO uint32_t MJPEG_BUFFER_OVERFLOW_INT_EN      ;  /*!< MJPEG OVERFLOW INTERRUPT ENABLE SIGNAL Register,  Address offset:0x078 */
	__IO uint32_t MJPEG_BUFFER_OVERFLOW_INT_CLR     ;  /*!< MJPEG OVERFLOW INTERRUPT CLEAR SIGNAL Register,  Address offset:0x07C */
	__I  uint32_t MJPEG_BUFFER_OVERFLOW_INT_RAW     ;  /*!< MJPEG OVERFLOW INTERRUPT RAW STATUS Register,  Address offset:0x080 */
	__IO uint32_t MJPEG_BUFFER_FRAME_NUM            ;  /*!< MJPEG NUMBER OF BUFFER IN RINGBUFFFER MODE Register,  Address offset:0x084 */
	__IO uint32_t MJPEG_BUFFER_FRAME_STATUS         ;  /*!< MJPEG BUFFER STATUS Register,  Address offset:0x088 */
	__I  uint32_t MJPEG_BUFFER_FRAME_CNT            ;  /*!< MJPEG USING BUFFER INDEX Register,  Address offset:0x08C */
	__IO uint32_t MJPEG_TIMEOUT_CFG                 ;  /*!< MJPEG TIMEOUT CONFIGURATION Register,  Address offset:0x090 */
	__IO uint32_t MJPEG_TIMEOUT_CFG_EN              ;  /*!< MJPEG TIMEOUT FUNCTION ENABLE Register,  Address offset:0x094 */
	__I  uint32_t MJPEG_TIMEOUT_STS                 ;  /*!< MJPEG TIMEOUT INTERRUPT STATUS Register,  Address offset:0x098 */
	__IO uint32_t MJPEG_TIMEOUT_EN                  ;  /*!< MJPEG TIMEOUT INTERRUPT ENABLE SIGNAL Register,  Address offset:0x09C */
	__IO uint32_t MJPEG_TIMEOUT_CLR                 ;  /*!< MJPEG TIMEOUT INTERRUPT CLEAR SIGNAL Register,  Address offset:0x0A0 */
	__I  uint32_t MJPEG_TIMEOUT_RAW                 ;  /*!< MJPEG TIMEOUT INTERRUPT RAW STATUS Register,  Address offset:0x0A4 */
	__IO uint32_t RSVD1[6]                          ;  /*!< Reserved,  Address offset:0x0A8-0x0BF */
	__I  uint32_t MJPEG_BUFFER_CNT_OVERFLOW_INT_STS ;  /*!< MJPEG RINGBUFFER COUNT OVERFLOW INTERRUPT STATUS Register,  Address offset:0x0C0 */
	__IO uint32_t MJPEG_BUFFER_CNT_OVERFLOW_INT_EN  ;  /*!< MJPEG RINGBUFFER COUNT OVERFLOW INTERRUPT ENABLE SIGNAL Register,  Address offset:0x0C4 */
	__IO uint32_t MJPEG_BUFFER_CNT_OVERFLOW_INT_CLR ;  /*!< MJPEG RINGBUFFER COUNT OVERFLOW INTERRUPT CLEAR SIGNAL Register,  Address offset:0x0C8 */
	__I  uint32_t MJPEG_BUFFER_CNT_OVERFLOW_INT_RAW ;  /*!< MJPEG RINGBUFFER COUNT OVERFLOW INTERRUPT RAW SIGNAL Register,  Address offset:0x0CC */
	__I  uint32_t MJPEG_MISS_FRAME_CNT              ;  /*!< MJPEG RINGBUFFER MISS FRAME COUNT Register,  Address offset:0x0D0 */
} MJPEG_TypeDef;

/** @} */


// Do NOT modify any AUTO_GEN code above
/* AUTO_GEN_END */

/* MANUAL_GEN_START */

// Please add your definitions here

/* Exported Types ------------------------------------------------------------*/


#define MJPEG_DEC_DONE_INT						((u32)0x00000001 << 0)
#define MJPEG_ENC_DONE_INT						((u32)0x00000001 << 1)
#define MJPEG_WR_BUFF_OVERFLOW_INT				((u32)0x00000001 << 2)
#define MJPEG_RINGBUF_OVERFLOW_INT				((u32)0x00000001 << 3)
#define MJPEG_TO_INT							((u32)0x00000001 << 4)
#define MJPEG_BUF_CNT_OVERFLOW_INT				((u32)0x00000001 << 5)

#define MJPEG_QMEM_SIZE							256
#define MJPEG_HUFFENC_SIZE						384
#define MJPEG_DHT_SIZE							412


typedef struct {
	u32 input_addr;				/* input buffer address. 4B aligned */
	u32 input_length;			/* input buffer length */
	u32 output_addr;			/* output buffer address. 4B aligned*/
	u32 output_length;			/* output buffer length. 4B aligned*/
} MJPEG_Dec_InitStruct;


typedef struct {
	u32 ringbuffer_mode;		/*ringbuffer mode is a collaborative Mode with DVP. 0: don't use ringbuffer mode; 1: use ringbuffer mode. */
	u32 quality_factor;			/* it decide image quailty (1~100) */
	u32 image_width;
	u32 image_height;
	u32 input_addr;				/* input buffer address */
	u32 input_length;			/* input buffer length */
	u32 output_buf_num;			/* output buffer number, can be 1~4 */
	u32 output_length;			/* output buffer length. 4B aligned */
	u32 output_addr;			/* output buffer address. 4B aligned*/
	u32 output_addr1;			/* output buffer address 1. 4B aligned. if not used, ignore it */
	u32 output_addr2;			/* output buffer address 2. 4B aligned. if not used, ignore it */
	u32 output_addr3;			/* output buffer address 3. 4B aligned. if not used, ignore it */
	u32 rinbuffer_line;			/* ring buffer line number (16~48 and must be multipe of 8), sync with dvp.  if not used, ignore it */
	u8 *qtable;					/* quantization table. If user want to use default table in JPEG standard, ignore it */
	u32 qtable_size;			/* quantization table size. If user want to default table in JPEG standard, ignore  it */
	u16 *hufftable;				/* huffman table. If user want to default table in JPEG standard, ignore it */
	u32 hufftable_size;			/* huffman table. If user want to default table in JPEG standard, ignore it */
	u8 *dhtable;				/* DHT aera in JPEG DHT marker. If user want to default table in JPEG standard, ignore it */
	u32 dhtable_size;			/* DHT aera in JPEG DHT marker. If user want to default table in JPEG standard, ignore it */
} MJPEG_Enc_InitStruct;


/* Exported Constants --------------------------------------------------------*/

/* Exported Functions --------------------------------------------------------*/

void MJPEG_Start(void);
void MJPEG_QuickStop(void);
void MJPEG_FrameStop(void);
void MJPEG_Timeout_En(u32 new_status);
void MJPEG_Timeout_Config(u32 timeout_cycle);
void MJPEG_SetInputBuf(u32 addr, u32 len);
void MJPEG_SetOutputBuf(u32 addr, u32 len);
void MJPEG_INTConfig(u32 intr, u32 new_state);
void MJPEG_INTClear(u32 intr);
u32 MJPEG_GetStatus(void);
u32 MJPEG_GetRawStatus(void);
void MJPEG_Dec_StructInit(MJPEG_Dec_InitStruct *mjpec_dec_initstruct);
void MJPEG_Dec_Init(MJPEG_Dec_InitStruct *mjpec_dec_initstruct);
void MJPEG_Dec_GetImageRes(u32 *width, u32 *height);
void MJPEG_Enc_StructInit(MJPEG_Enc_InitStruct *mjpec_enc_initstruct);
void MJPEG_Enc_Init(MJPEG_Enc_InitStruct *mjpec_enc_initstruct);
u32 MJPEG_Enc_GetImgSize(void);
u32 MJPEG_Enc_GetCurRingbufIndex(void);
u32 MJPEG_Enc_GetRecvRingbufIndex(void);
void MJPEG_Enc_ReleaseRingbuff(u32 ringbuff_bit_index);
u32 MJPEG_Enc_GetRingbufImgSize(u32 buf_index);
void MJPEG_Enc_SetRingBuf(u32 num, u32 addr0, u32 addr1, u32 addr2, u32 addr3, u32 len);
void MJPEG_Enc_RingBufModeEn(u32 new_status);
void MJPEG_Enc_SetRingBufLine(u32 line);
void MJPEG_Enc_WriteQTable(u8 *src, u32 size, u32 qf);
void MJPEG_Enc_WriteHuffTable(u16 *src, u32 size);
void MJPEG_Enc_WriteDHTable(u8 *src, u32 size);
void MJPEG_Enc_ReadQTable(u8 *src, u32 size);
void MJPEG_Enc_ReadHuffTable(u16 *src, u32 size);
void MJPEG_Enc_ReadDHTable(u8 *src, u32 size);

/** @} */

/** @} */

// If other definitions do not need to be extracted to CHM document, add them here.
/* Other Definitions --------------------------------------------------------*/


/* MANUAL_GEN_END */

#endif