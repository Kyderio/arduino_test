#ifndef _RL6955_REG_PAGE2_WDMA_H_
#define _RL6955_REG_PAGE2_WDMA_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE2_WDMA
  * @brief REG_PAGE2_WDMA driver modules
  * @{
  */




/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE2_WDMA_Register_Definitions REG_PAGE2_WDMA Register Definitions
  * @{
  */

/** @defgroup REG_RXDMA_STATE
  * @brief
  * @{
  */
#define BIT_RXDMA_RESET         ((u32)0x00000001 << 27)          /*!< WA0 0x0  when set to 1, enable rxdma ctl state set to IDLE*/
#define BIT_RXDMA_GCLK_EN       ((u32)0x00000001 << 26)          /*!< R/W 0x0  when set to 1, enable rxdma clock gating funtion*/
#define BIT_CSIPKT_NUM_OVERFLOW ((u32)0x00000001 << 25)          /*!< R 0x0  csipkt number in CSIPKTBUFFER greater than 255*/
#define BIT_CSIDMA_PKT_REQ      ((u32)0x00000001 << 24)          /*!< R 0x0  csidma has request*/
#define BIT_DMA_ST_IDLE_CSI     ((u32)0x00000001 << 23)          /*!< R 0x0  csidma is idle*/
#define BIT_RXDMA_SFF_UNDERFLOW ((u32)0x00000001 << 20)          /*!< RW1C 0x0  rxdma syncfifo is underflow*/
#define BIT_RXDMA_SFF_OVERFLOW  ((u32)0x00000001 << 19)          /*!< RW1C 0x0  rxdma syncfifo is overflow*/
#define BIT_RXPKT_NUM_OVERFLOW  ((u32)0x00000001 << 18)          /*!< R 0x0  rxpkt number in RXPKTBUFFER greater than 255*/
#define BIT_RXDMA_PKT_REQ       ((u32)0x00000001 << 17)          /*!< R 0x0  rxdma has request*/
#define BIT_DMA_ST_IDLE_RX      ((u32)0x00000001 << 16)          /*!< R 0x0  rxdma is idle*/
#define BIT_DMA_PKT_ARB         ((u32)0x00000001 << 15)          /*!< R/W 0x0  */
#define BIT_CSIPKT_RELEASE_POLL ((u32)0x00000001 << 14)          /*!< WA0 0x0  One pulse. When this bit is set, RXDMA will decrease CSI PKT counter by one. Before this bit is polled, FW shall update RXFF_RD_PTR first.*/
#define BIT_RXPKT_RELEASE_POLL  ((u32)0x00000001 << 13)          /*!< WA0 0x0  One pulse. When this bit is set, RXDMA will decrease RX PKT counter by one. Before this bit is polled, FW shall update RXFF_RD_PTR first.*/
#define BIT_FW_RELEASE_EN       ((u32)0x00000001 << 12)          /*!< R/W 0x0  When this bit is set, RXDMA will stop after on-going RXDMA packet to host completed*/
#define BIT_MASK_FW_UPD_RDPTR   ((u32)0x000007FF << 0)           /*!< R/W 0x0  FW shall update this register before FW write RXPKT_RELEASE_POLL to 1. 8bytes unit*/
#define BIT_FW_UPD_RDPTR(x)     (((u32)((x) & 0x000007FF) << 0))
#define BIT_GET_FW_UPD_RDPTR(x) ((u32)(((x >> 0) & 0x000007FF)))
/** @} */

/** @defgroup REG_RXPKT_NUM
  * @brief
  * @{
  */
#define BIT_MASK_CSIPKT_NUM   ((u32)0x000000FF << 8)           /*!< R 0x0  The number of packets in CSIPKTBUF.*/
#define BIT_CSIPKT_NUM(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_CSIPKT_NUM(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_RXPKT_NUM    ((u32)0x000000FF << 0)           /*!< R 0x0  The number of packets in RXPKTBUF.*/
#define BIT_RXPKT_NUM(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_RXPKT_NUM(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_WDMA_DEBUG
  * @brief
  * @{
  */
#define BIT_MASK_WDMA_DBG   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  debug signal of WDMA_TOP*/
#define BIT_WDMA_DBG(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_WDMA_DBG(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_RXBD_PTR
  * @brief
  * @{
  */
#define BIT_RXBD_FIFO_FULL      ((u32)0x00000001 << 24)           /*!< R 0x0  Available rxbd and used rxbd is equal to total rxbd number*/
#define BIT_MASK_RXBD_RPTR_HW   ((u32)0x000000FF << 16)           /*!< R 0x0  read pointer of HW of RXBD MEM*/
#define BIT_RXBD_RPTR_HW(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_RXBD_RPTR_HW(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_RXBD_RPTR_SW   ((u32)0x000000FF << 8)            /*!< R 0x0  read pointer of SW of RXBD MEM*/
#define BIT_RXBD_RPTR_SW(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_RXBD_RPTR_SW(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_RXBD_WPTR_SW   ((u32)0x000000FF << 0)            /*!< R 0x0  write pointer of SW of RXBD MEM*/
#define BIT_RXBD_WPTR_SW(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_RXBD_WPTR_SW(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_CSIBD_PTR
  * @brief
  * @{
  */
#define BIT_CSIBD_FIFO_FULL      ((u32)0x00000001 << 24)           /*!< R 0x0  Available csibd and used csibd is equal to total rxbd number*/
#define BIT_MASK_CSIBD_RPTR_HW   ((u32)0x000000FF << 16)           /*!< R 0x0  read pointer of HW of CSIBD MEM*/
#define BIT_CSIBD_RPTR_HW(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_CSIBD_RPTR_HW(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_CSIBD_RPTR_SW   ((u32)0x000000FF << 8)            /*!< R 0x0  read pointer of SW of CSIBD MEM*/
#define BIT_CSIBD_RPTR_SW(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_CSIBD_RPTR_SW(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_CSIBD_WPTR_SW   ((u32)0x000000FF << 0)            /*!< R 0x0  write pointer of SW of CSIBD MEM*/
#define BIT_CSIBD_WPTR_SW(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_CSIBD_WPTR_SW(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_USED_BD_NUM
  * @brief
  * @{
  */
#define BIT_MASK_CSIBD_HW_AVAIL_NUM   ((u32)0x000000FF << 24)           /*!< R 0x0  available csibd number*/
#define BIT_CSIBD_HW_AVAIL_NUM(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_CSIBD_HW_AVAIL_NUM(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_RXBD_HW_AVAIL_NUM    ((u32)0x000000FF << 16)           /*!< R 0x0  available rxbd number*/
#define BIT_RXBD_HW_AVAIL_NUM(x)      (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_RXBD_HW_AVAIL_NUM(x)  ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_CSIBD_HW_USED_NUM    ((u32)0x000000FF << 8)            /*!< R 0x0  used csibd number*/
#define BIT_CSIBD_HW_USED_NUM(x)      (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_CSIBD_HW_USED_NUM(x)  ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_RXBD_HW_USED_NUM     ((u32)0x000000FF << 0)            /*!< R 0x0  used rxbd number*/
#define BIT_RXBD_HW_USED_NUM(x)       (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_RXBD_HW_USED_NUM(x)   ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/*==========REG_PAGE2_WDMA Register Address Definition==========*/
#define REG_RXDMA_STATE          0x200
#define REG_RXPKT_NUM            0x204
#define REG_WDMA_DEBUG           0x208
#define REG_RXBD_PTR             0x20C
#define REG_CSIBD_PTR            0x210
#define REG_USED_BD_NUM          0x214

/** @} */


// Do NOT modify any AUTO_GEN code above
/* AUTO_GEN_END */

/* MANUAL_GEN_START */

// Please add your definitions here

/* Exported Types ------------------------------------------------------------*/

/* Exported Constants --------------------------------------------------------*/

/* Exported Functions --------------------------------------------------------*/


/** @} */

/** @} */

// If other definitions do not need to be extracted to CHM document, add them here.
/* Other Definitions --------------------------------------------------------*/


/* MANUAL_GEN_END */

#endif