#ifndef _RL6955_REG_PAGE3_AHB_LOCAL_H_
#define _RL6955_REG_PAGE3_AHB_LOCAL_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE3_AHB_LOCAL
  * @brief REG_PAGE3_AHB_LOCAL driver modules
  * @{
  */




/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE3_AHB_LOCAL_Register_Definitions REG_PAGE3_AHB_LOCAL Register Definitions
  * @{
  */

/** @defgroup REG_AXI_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_MAX_TXDMA   ((u32)0x00000003 << 18)           /*!< R/W 0x3  RXDMA Burst Size selection default 3. 0: 4bytes; 1: 16bytes; 2: 32bytes; 3: 64bytes*/
#define BIT_MAX_TXDMA(x)     (((u32)((x) & 0x00000003) << 18))
#define BIT_GET_MAX_TXDMA(x) ((u32)(((x >> 18) & 0x00000003)))
#define BIT_MASK_MAX_RXDMA   ((u32)0x00000003 << 16)           /*!< R/W 0x3  TXDMA Burst Size selection default 3. 0: 4bytes; 1: 16bytes; 2: 32bytes; 3: 64bytes.*/
#define BIT_MAX_RXDMA(x)     (((u32)((x) & 0x00000003) << 16))
#define BIT_GET_MAX_RXDMA(x) ((u32)(((x >> 16) & 0x00000003)))
#define BIT_AXI_STOPTX       ((u32)0x00000001 << 3)            /*!< R/W 0x0  TX packet DMA STOP*/
#define BIT_AXI_STOPPTCL     ((u32)0x00000001 << 2)            /*!< R/W 0x0  PTCL packet DMA STOP*/
#define BIT_AXI_STOPCSI      ((u32)0x00000001 << 1)            /*!< R/W 0x0  CSI packet DMA STOP*/
#define BIT_AXI_STOPRX       ((u32)0x00000001 << 0)            /*!< R/W 0x0  RX packet DMA STOP*/
/** @} */

/*==========REG_PAGE3_AHB_LOCAL Register Address Definition==========*/
#define REG_AXI_CTRL          0x300
#define REG_DUMMY             0x304

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