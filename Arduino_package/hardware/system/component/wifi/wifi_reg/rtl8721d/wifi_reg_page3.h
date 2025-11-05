#ifndef _project_name_REG_PAGE3_H_
#define _project_name_REG_PAGE3_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE3
  * @brief REG_PAGE3 driver modules
  * @{
  */


/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE3_Register_Definitions REG_PAGE3 Register Definitions
  * @{
  */

/** @defgroup REG_HCI_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_HCI_MAX_RXDMA   ((u32)0x00000003 << 28)           /*!< R/W 0x11  RXDMA Burst Size selection default 3.   0:4byte; 1:16byte; 2:32byte; 3:64 bytes;*/
#define BIT_HCI_MAX_RXDMA(x)     (((u32)((x) & 0x00000003) << 28))
#define BIT_GET_HCI_MAX_RXDMA(x) ((u32)(((x >> 28) & 0x00000003)))
#define BIT_MASK_HCI_MAX_TXDMA   ((u32)0x00000003 << 24)           /*!< R/W 0x11  TXDMA Burst Size selection default 3.   0:4byte; 1:16byte; 2:32byte; 3:64 bytes;  If multi-tag is enable, the size is fixed at 64byte. If multi-tag is disable, the size is determined by the bit fields.*/
#define BIT_HCI_MAX_TXDMA(x)     (((u32)((x) & 0x00000003) << 24))
#define BIT_GET_HCI_MAX_TXDMA(x) ((u32)(((x >> 24) & 0x00000003)))
#define BIT_REG_TXDMA_FAIL_PS    ((u32)0x00000001 << 21)           /*!< R/W 0x0  Write 1 to cause a txdma fail pulse to inform MAC TDE.*/
#define BIT_RX_CLOSE_EN          ((u32)0x00000001 << 15)           /*!< R/W 0x0  Display Dword0[28:16] type of Rx buffer descriptor 0: TotalLen 1: Rxtag*/
#define BIT_STOP_BCNQ            ((u32)0x00000001 << 14)           /*!< R/W 0x0  BCNQ DMA STOP*/
#define BIT_STOP_MGQ             ((u32)0x00000001 << 13)           /*!< R/W 0x0  MGQ DMA STOP*/
#define BIT_STOP_VOQ             ((u32)0x00000001 << 12)           /*!< R/W 0x0  VOKQ DMA STOP*/
#define BIT_STOP_VIQ             ((u32)0x00000001 << 11)           /*!< R/W 0x0  VIQ DMA STOP*/
#define BIT_STOP_BEQ             ((u32)0x00000001 << 10)           /*!< R/W 0x0  BEQ DMA STOP*/
#define BIT_STOP_BKQ             ((u32)0x00000001 << 9)            /*!< R/W 0x0  BKQ DMA STOP*/
#define BIT_STOP_RXQ             ((u32)0x00000001 << 8)            /*!< R/W 0x1  RX DMA STOP*/
#define BIT_STOP_HI7Q            ((u32)0x00000001 << 7)            /*!< R/W 0x0  Stop HI7Q DMA*/
#define BIT_STOP_HI6Q            ((u32)0x00000001 << 6)            /*!< R/W 0x0  Stop HI6Q DMA*/
#define BIT_STOP_HI5Q            ((u32)0x00000001 << 5)            /*!< R/W 0x0  Stop HI5Q DMA*/
#define BIT_STOP_HI4Q            ((u32)0x00000001 << 4)            /*!< R/W 0x0  Stop HI4Q DMA*/
#define BIT_STOP_HI3Q            ((u32)0x00000001 << 3)            /*!< R/W 0x0  Stop HI3Q DMA*/
#define BIT_STOP_HI2Q            ((u32)0x00000001 << 2)            /*!< R/W 0x0  Stop HI2Q DMA*/
#define BIT_STOP_HI1Q            ((u32)0x00000001 << 1)            /*!< R/W 0x0  Stop HI1Q DMA*/
#define BIT_STOP_HI0Q            ((u32)0x00000001 << 0)            /*!< R/W 0x0  Stop HI0Q DMA*/
/** @} */

/** @defgroup REG_INT_MIG
  * @brief
  * @{
  */
#define BIT_MASK_TXTTIMER_MATCH_NUM   ((u32)0x0000000F << 28)           /*!< R/W 0x0  When the number of timer matched condition exceeds this setting, then interrupt is issued.*/
#define BIT_TXTTIMER_MATCH_NUM(x)     (((u32)((x) & 0x0000000F) << 28))
#define BIT_GET_TXTTIMER_MATCH_NUM(x) ((u32)(((x >> 28) & 0x0000000F)))
#define BIT_MASK_TXPKT_NUM_MATCH      ((u32)0x0000000F << 24)           /*!< R/W 0x0  When the buffered TX packet number is matched, the interrupt is then issued*/
#define BIT_TXPKT_NUM_MATCH(x)        (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_TXPKT_NUM_MATCH(x)    ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_RXTTIMER_MATCH_NUM   ((u32)0x0000000F << 20)           /*!< R/W 0x0  When the number of timer matched condition exceeds this setting, then interrupt is issued.*/
#define BIT_RXTTIMER_MATCH_NUM(x)     (((u32)((x) & 0x0000000F) << 20))
#define BIT_GET_RXTTIMER_MATCH_NUM(x) ((u32)(((x >> 20) & 0x0000000F)))
#define BIT_MASK_RXPKT_NUM_MATCH      ((u32)0x0000000F << 16)           /*!< R/W 0x0  When the buffered RX packet number is matched, the interrupt is then issued*/
#define BIT_RXPKT_NUM_MATCH(x)        (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_RXPKT_NUM_MATCH(x)    ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_TSFT_INCR_SEL        ((u32)0x00000007 << 0)            /*!< R/W 0x0  timer unit selector for setting Interrupt Migration BIT[31:28] and BIT[23:20] must be configured, too*/
#define BIT_TSFT_INCR_SEL(x)          (((u32)((x) & 0x00000007) << 0))
#define BIT_GET_TSFT_INCR_SEL(x)      ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_BCNQ_TXBD_DESA
  * @brief
  * @{
  */
#define BIT_MASK_BCNQ_TXBD_DESA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Buffer Descriptor Base Address for Beacon Queue*/
#define BIT_BCNQ_TXBD_DESA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BCNQ_TXBD_DESA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MGQ_TXBD_DESA
  * @brief
  * @{
  */
#define BIT_MASK_MGQ_TXBD_DESA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Buffer Descriptor Base Address for Manage Queue*/
#define BIT_MGQ_TXBD_DESA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MGQ_TXBD_DESA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_VOQ_TXBD_DESA
  * @brief
  * @{
  */
#define BIT_MASK_VOQ_TXBD_DESA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Buffer Descriptor Base Address for VO Queue*/
#define BIT_VOQ_TXBD_DESA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_VOQ_TXBD_DESA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_VIQ_TXBD_DESA
  * @brief
  * @{
  */
#define BIT_MASK_VIQ_TXBD_DESA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Buffer Descriptor Base Address for VI Queue*/
#define BIT_VIQ_TXBD_DESA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_VIQ_TXBD_DESA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BEQ_TXBD_DESA
  * @brief
  * @{
  */
#define BIT_MASK_BEQ_TXBD_DESA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Buffer Descriptor Base Address for BE Queue*/
#define BIT_BEQ_TXBD_DESA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BEQ_TXBD_DESA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BKQ_TXBD_DESA
  * @brief
  * @{
  */
#define BIT_MASK_BKQ_TXBD_DESA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Buffer Descriptor Base Address for BK Queue*/
#define BIT_BKQ_TXBD_DESA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BKQ_TXBD_DESA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_RXQ_RXBD_DESA
  * @brief
  * @{
  */
#define BIT_MASK_RXQ_RXBD_DESA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Buffer Descriptor Base Address for RX*/
#define BIT_RXQ_RXBD_DESA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_RXQ_RXBD_DESA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HI0Q_TXBD_DESA
  * @brief
  * @{
  */
#define BIT_MASK_HI0Q_TXBD_DESA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Buffer Descriptor Base Address for HI0 Queue*/
#define BIT_HI0Q_TXBD_DESA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HI0Q_TXBD_DESA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HI1Q_TXBD_DESA
  * @brief
  * @{
  */
#define BIT_MASK_HI1Q_TXBD_DESA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Buffer Descriptor Base Address for HI1 Queue*/
#define BIT_HI1Q_TXBD_DESA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HI1Q_TXBD_DESA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HI2Q_TXBD_DESA
  * @brief
  * @{
  */
#define BIT_MASK_HI2Q_TXBD_DESA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Buffer Descriptor Base Address for HI2 Queue*/
#define BIT_HI2Q_TXBD_DESA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HI2Q_TXBD_DESA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HI3Q_TXBD_DESA
  * @brief
  * @{
  */
#define BIT_MASK_HI3Q_TXBD_DESA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Buffer Descriptor Base Address for HI3 Queue*/
#define BIT_HI3Q_TXBD_DESA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HI3Q_TXBD_DESA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HI4Q_TXBD_DESA
  * @brief
  * @{
  */
#define BIT_MASK_HI4Q_TXBD_DESA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Buffer Descriptor Base Address for HI4 Queue*/
#define BIT_HI4Q_TXBD_DESA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HI4Q_TXBD_DESA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HI5Q_TXBD_DESA
  * @brief
  * @{
  */
#define BIT_MASK_HI5Q_TXBD_DESA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Buffer Descriptor Base Address for HI5 Queue*/
#define BIT_HI5Q_TXBD_DESA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HI5Q_TXBD_DESA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HI6Q_TXBD_DESA
  * @brief
  * @{
  */
#define BIT_MASK_HI6Q_TXBD_DESA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Buffer Descriptor Base Address for HI6 Queue*/
#define BIT_HI6Q_TXBD_DESA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HI6Q_TXBD_DESA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HI7Q_TXBD_DESA
  * @brief
  * @{
  */
#define BIT_MASK_HI7Q_TXBD_DESA   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Buffer Descriptor Base Address for HI7 Queue*/
#define BIT_HI7Q_TXBD_DESA(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HI7Q_TXBD_DESA(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MGQ_TXBD_RX_RXBD_NUM
  * @brief
  * @{
  */
#define BIT_MASK_BCNQ_DESC_MODE   ((u32)0x00000003 << 29)           /*!< R/W 0x0  BCNQ descriptor mode : 0 : 2 segments each descriptor 1 : 4 segments each descriptor 2 : 8 segments each descriptor PS, Each BSSID BCNQ has 128 Bytes interval (For MBSSID)*/
#define BIT_BCNQ_DESC_MODE(x)     (((u32)((x) & 0x00000003) << 29))
#define BIT_GET_BCNQ_DESC_MODE(x) ((u32)(((x >> 29) & 0x00000003)))
#define BIT_BCNQ_FLAG             ((u32)0x00000001 << 28)           /*!< R/W 0x0  BCNQ FLAGing bit Read : BCNQ work Write : BCNQ Polling*/
#define BIT_MASK_RXDES_NUM     ((u32)0x00000FFF << 16)           /*!< R/W 0x0  RX queue descriptor's number*/
#define BIT_RXDES_NUM(x)       (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_RXDES_NUM(x)   ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MGQ_FLAG              ((u32)0x00000001 << 14)           /*!< RO 0x0  MGQ FLAGing bit, read result will be bpqflag*/
#define BIT_MASK_MGQ_DESC_MODE    ((u32)0x00000003 << 12)           /*!< R/W 0x0  MGQ descriptor mode : 0 : 2 segments each descriptor 1 : 4 segments each descriptor 2 : 8 segments each descriptor*/
#define BIT_MGQ_DESC_MODE(x)      (((u32)((x) & 0x00000003) << 12))
#define BIT_GET_MGQ_DESC_MODE(x)  ((u32)(((x >> 12) & 0x00000003)))
#define BIT_MASK_MGQDES_NUM       ((u32)0x00000FFF << 0)            /*!< R/W 0x0  MG queue descriptor's number*/
#define BIT_MGQDES_NUM(x)         (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_MGQDES_NUM(x)     ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_VOQ_TXBD_NUM
  * @brief
  * @{
  */
#define BIT_HCI_VOQ_FLAG         ((u16)0x00000001 << 14)           /*!< RO 0x0  VOQ, read result will be voqflag*/
#define BIT_MASK_VOQ_DESC_MODE   ((u16)0x00000003 << 12)           /*!< R/W 0x0  VOQ descriptor mode : 0 : 2 segments each descriptor 1 : 4 segments each descriptor 2 : 8 segments each descriptor*/
#define BIT_VOQ_DESC_MODE(x)     (((u16)((x) & 0x00000003) << 12))
#define BIT_GET_VOQ_DESC_MODE(x) ((u16)(((x >> 12) & 0x00000003)))
#define BIT_MASK_VOQ_DESC_NUM    ((u16)0x00000FFF << 0)            /*!< R/W 0x0  VO queue descriptor's number*/
#define BIT_VOQ_DESC_NUM(x)      (((u16)((x) & 0x00000FFF) << 0))
#define BIT_GET_VOQ_DESC_NUM(x)  ((u16)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_VIQ_TXBD_NUM
  * @brief
  * @{
  */
#define BIT_HCI_VIQ_FLAG         ((u16)0x00000001 << 14)           /*!< RO 0x0  VIQ, read result will be voqflag*/
#define BIT_MASK_VIQ_DESC_MODE   ((u16)0x00000003 << 12)           /*!< R/W 0x0  VIQ descriptor mode : 0 : 2 segments each descriptor 1 : 4 segments each descriptor 2 : 8 segments each descriptor*/
#define BIT_VIQ_DESC_MODE(x)     (((u16)((x) & 0x00000003) << 12))
#define BIT_GET_VIQ_DESC_MODE(x) ((u16)(((x >> 12) & 0x00000003)))
#define BIT_MASK_VIQ_DESC_NUM    ((u16)0x00000FFF << 0)            /*!< R/W 0x0  VI queue descriptor's number*/
#define BIT_VIQ_DESC_NUM(x)      (((u16)((x) & 0x00000FFF) << 0))
#define BIT_GET_VIQ_DESC_NUM(x)  ((u16)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_BEQ_TXBD_NUM
  * @brief
  * @{
  */
#define BIT_HCI_BEQ_FLAG         ((u16)0x00000001 << 14)           /*!< RO 0x0  BEQ, read result will be voqflag*/
#define BIT_MASK_BEQ_DESC_MODE   ((u16)0x00000003 << 12)           /*!< R/W 0x0  BEQ descriptor mode : 0 : 2 segments each descriptor 1 : 4 segments each descriptor 2 : 8 segments each descriptor*/
#define BIT_BEQ_DESC_MODE(x)     (((u16)((x) & 0x00000003) << 12))
#define BIT_GET_BEQ_DESC_MODE(x) ((u16)(((x >> 12) & 0x00000003)))
#define BIT_MASK_BEQ_DESC_NUM    ((u16)0x00000FFF << 0)            /*!< R/W 0x0  BE queue descriptor's number*/
#define BIT_BEQ_DESC_NUM(x)      (((u16)((x) & 0x00000FFF) << 0))
#define BIT_GET_BEQ_DESC_NUM(x)  ((u16)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_BKQ_TXBD_NUM
  * @brief
  * @{
  */
#define BIT_HCI_BKQ_FLAG         ((u16)0x00000001 << 14)           /*!< RO 0x0  BKQ, read result will be voqflag*/
#define BIT_MASK_BKQ_DESC_MODE   ((u16)0x00000003 << 12)           /*!< R/W 0x0  BKQ descriptor mode : 0 : 2 segments each descriptor 1 : 4 segments each descriptor 2 : 8 segments each descriptor*/
#define BIT_BKQ_DESC_MODE(x)     (((u16)((x) & 0x00000003) << 12))
#define BIT_GET_BKQ_DESC_MODE(x) ((u16)(((x >> 12) & 0x00000003)))
#define BIT_MASK_BKQ_DESC_NUM    ((u16)0x00000FFF << 0)            /*!< R/W 0x0  BK queue descriptor's number*/
#define BIT_BKQ_DESC_NUM(x)      (((u16)((x) & 0x00000FFF) << 0))
#define BIT_GET_BKQ_DESC_NUM(x)  ((u16)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HI0Q_TXBD_NUM
  * @brief
  * @{
  */
#define BIT_HI0Q_FLAG             ((u16)0x00000001 << 14)           /*!< RO 0x0  HI0Q flag*/
#define BIT_MASK_HI0Q_DESC_MODE   ((u16)0x00000003 << 12)           /*!< R/W 0x0  HI0Q descriptor mode : 0 : 2 segments each descriptor 1 : 4 segments each descriptor 2 : 8 segments each descriptor*/
#define BIT_HI0Q_DESC_MODE(x)     (((u16)((x) & 0x00000003) << 12))
#define BIT_GET_HI0Q_DESC_MODE(x) ((u16)(((x >> 12) & 0x00000003)))
#define BIT_MASK_HI0Q_DESC_NUM    ((u16)0x00000FFF << 0)            /*!< R/W 0x0  HI0 queue descriptor's number*/
#define BIT_HI0Q_DESC_NUM(x)      (((u16)((x) & 0x00000FFF) << 0))
#define BIT_GET_HI0Q_DESC_NUM(x)  ((u16)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HI1Q_TXBD_NUM
  * @brief
  * @{
  */
#define BIT_HI1Q_FLAG             ((u16)0x00000001 << 14)           /*!< RO 0x0  HI1Q flag*/
#define BIT_MASK_HI1Q_DESC_MODE   ((u16)0x00000003 << 12)           /*!< R/W 0x0  HI1Q descriptor mode : 0 : 2 segments each descriptor 1 : 4 segments each descriptor 2 : 8 segments each descriptor*/
#define BIT_HI1Q_DESC_MODE(x)     (((u16)((x) & 0x00000003) << 12))
#define BIT_GET_HI1Q_DESC_MODE(x) ((u16)(((x >> 12) & 0x00000003)))
#define BIT_MASK_HI1Q_DESC_NUM    ((u16)0x00000FFF << 0)            /*!< R/W 0x0  HI1 queue descriptor's number*/
#define BIT_HI1Q_DESC_NUM(x)      (((u16)((x) & 0x00000FFF) << 0))
#define BIT_GET_HI1Q_DESC_NUM(x)  ((u16)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HI2Q_TXBD_NUM
  * @brief
  * @{
  */
#define BIT_HI2Q_FLAG             ((u16)0x00000001 << 14)           /*!< RO 0x0  HI2Q flag*/
#define BIT_MASK_HI2Q_DESC_MODE   ((u16)0x00000003 << 12)           /*!< R/W 0x0  HI2Q descriptor mode : 0 : 2 segments each descriptor 1 : 4 segments each descriptor 2 : 8 segments each descriptor*/
#define BIT_HI2Q_DESC_MODE(x)     (((u16)((x) & 0x00000003) << 12))
#define BIT_GET_HI2Q_DESC_MODE(x) ((u16)(((x >> 12) & 0x00000003)))
#define BIT_MASK_HI2Q_DESC_NUM    ((u16)0x00000FFF << 0)            /*!< R/W 0x0  HI2 queue descriptor's number*/
#define BIT_HI2Q_DESC_NUM(x)      (((u16)((x) & 0x00000FFF) << 0))
#define BIT_GET_HI2Q_DESC_NUM(x)  ((u16)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HI3Q_TXBD_NUM
  * @brief
  * @{
  */
#define BIT_HI3Q_FLAG             ((u16)0x00000001 << 14)           /*!< RO 0x0  HI3Q flag*/
#define BIT_MASK_HI3Q_DESC_MODE   ((u16)0x00000003 << 12)           /*!< R/W 0x0  HI3Q descriptor mode : 0 : 2 segments each descriptor 1 : 4 segments each descriptor 2 : 8 segments each descriptor*/
#define BIT_HI3Q_DESC_MODE(x)     (((u16)((x) & 0x00000003) << 12))
#define BIT_GET_HI3Q_DESC_MODE(x) ((u16)(((x >> 12) & 0x00000003)))
#define BIT_MASK_HI3Q_DESC_NUM    ((u16)0x00000FFF << 0)            /*!< R/W 0x0  HI3 queue descriptor's number*/
#define BIT_HI3Q_DESC_NUM(x)      (((u16)((x) & 0x00000FFF) << 0))
#define BIT_GET_HI3Q_DESC_NUM(x)  ((u16)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HI4Q_TXBD_NUM
  * @brief
  * @{
  */
#define BIT_HI4Q_FLAG             ((u16)0x00000001 << 14)           /*!< RO 0x0  HI4Q flag*/
#define BIT_MASK_HI4Q_DESC_MODE   ((u16)0x00000003 << 12)           /*!< R/W 0x0  HI4Q descriptor mode : 0 : 2 segments each descriptor 1 : 4 segments each descriptor 2 : 8 segments each descriptor*/
#define BIT_HI4Q_DESC_MODE(x)     (((u16)((x) & 0x00000003) << 12))
#define BIT_GET_HI4Q_DESC_MODE(x) ((u16)(((x >> 12) & 0x00000003)))
#define BIT_MASK_HI4Q_DESC_NUM    ((u16)0x00000FFF << 0)            /*!< R/W 0x0  HI4 queue descriptor's number*/
#define BIT_HI4Q_DESC_NUM(x)      (((u16)((x) & 0x00000FFF) << 0))
#define BIT_GET_HI4Q_DESC_NUM(x)  ((u16)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HI5Q_TXBD_NUM
  * @brief
  * @{
  */
#define BIT_HI5Q_FLAG             ((u16)0x00000001 << 14)           /*!< RO 0x0  HI5Q flag*/
#define BIT_MASK_HI5Q_DESC_MODE   ((u16)0x00000003 << 12)           /*!< R/W 0x0  HI5Q descriptor mode : 0 : 2 segments each descriptor 1 : 4 segments each descriptor 2 : 8 segments each descriptor*/
#define BIT_HI5Q_DESC_MODE(x)     (((u16)((x) & 0x00000003) << 12))
#define BIT_GET_HI5Q_DESC_MODE(x) ((u16)(((x >> 12) & 0x00000003)))
#define BIT_MASK_HI5Q_DESC_NUM    ((u16)0x00000FFF << 0)            /*!< R/W 0x0  HI5 queue descriptor's number*/
#define BIT_HI5Q_DESC_NUM(x)      (((u16)((x) & 0x00000FFF) << 0))
#define BIT_GET_HI5Q_DESC_NUM(x)  ((u16)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HI6Q_TXBD_NUM
  * @brief
  * @{
  */
#define BIT_HI6Q_FLAG             ((u16)0x00000001 << 14)           /*!< RO 0x0  HI6Q flag*/
#define BIT_MASK_HI6Q_DESC_MODE   ((u16)0x00000003 << 12)           /*!< R/W 0x0  HI6Q descriptor mode : 0 : 2 segments each descriptor 1 : 4 segments each descriptor 2 : 8 segments each descriptor*/
#define BIT_HI6Q_DESC_MODE(x)     (((u16)((x) & 0x00000003) << 12))
#define BIT_GET_HI6Q_DESC_MODE(x) ((u16)(((x >> 12) & 0x00000003)))
#define BIT_MASK_HI6Q_DESC_NUM    ((u16)0x00000FFF << 0)            /*!< R/W 0x0  HI6 queue descriptor's number*/
#define BIT_HI6Q_DESC_NUM(x)      (((u16)((x) & 0x00000FFF) << 0))
#define BIT_GET_HI6Q_DESC_NUM(x)  ((u16)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HI7Q_TXBD_NUM
  * @brief
  * @{
  */
#define BIT_HI7Q_FLAG             ((u16)0x00000001 << 14)           /*!< RO 0x0  HI7Q flag*/
#define BIT_MASK_HI7Q_DESC_MODE   ((u16)0x00000003 << 12)           /*!< R/W 0x0  HI7Q descriptor mode : 0 : 2 segments each descriptor 1 : 4 segments each descriptor 2 : 8 segments each descriptor*/
#define BIT_HI7Q_DESC_MODE(x)     (((u16)((x) & 0x00000003) << 12))
#define BIT_GET_HI7Q_DESC_MODE(x) ((u16)(((x >> 12) & 0x00000003)))
#define BIT_MASK_HI7Q_DESC_NUM    ((u16)0x00000FFF << 0)            /*!< R/W 0x0  HI7 queue descriptor's number*/
#define BIT_HI7Q_DESC_NUM(x)      (((u16)((x) & 0x00000FFF) << 0))
#define BIT_GET_HI7Q_DESC_NUM(x)  ((u16)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_BD_RWPTR_CLR
  * @brief
  * @{
  */
#define BIT_CLR_HI7Q_HW_IDX   ((u32)0x00000001 << 29) /*!< W 0x0  Clear HI7Q hardware index, write 1 and hardware auto clear*/
#define BIT_CLR_HI6Q_HW_IDX   ((u32)0x00000001 << 28) /*!< W 0x0  Clear HI6Q hardware index, write 1 and hardware auto clear*/
#define BIT_CLR_HI5Q_HW_IDX   ((u32)0x00000001 << 27) /*!< W 0x0  Clear HI5Q hardware index, write 1 and hardware auto clear*/
#define BIT_CLR_HI4Q_HW_IDX   ((u32)0x00000001 << 26) /*!< W 0x0  Clear HI4Q hardware index, write 1 and hardware auto clear*/
#define BIT_CLR_HI3Q_HW_IDX   ((u32)0x00000001 << 25) /*!< W 0x0  Clear HI3Q hardware index, write 1 and hardware auto clear*/
#define BIT_CLR_HI2Q_HW_IDX   ((u32)0x00000001 << 24) /*!< W 0x0  Clear HI2Q hardware index, write 1 and hardware auto clear*/
#define BIT_CLR_HI1Q_HW_IDX   ((u32)0x00000001 << 23) /*!< W 0x0  Clear HI1Q hardware index, write 1 and hardware auto clear*/
#define BIT_CLR_HI0Q_HW_IDX   ((u32)0x00000001 << 22) /*!< W 0x0  Clear HI0Q hardware index, write 1 and hardware auto clear*/
#define BIT_CLR_BKQ_HW_IDX    ((u32)0x00000001 << 21) /*!< W 0x0  Clear BKQ hardware index, write 1 and hardware auto clear*/
#define BIT_CLR_BEQ_HW_IDX    ((u32)0x00000001 << 20) /*!< W 0x0  Clear BEQ hardware index, write 1 and hardware auto clear*/
#define BIT_CLR_VIQ_HW_IDX    ((u32)0x00000001 << 19) /*!< W 0x0  Clear VIQ hardware index, write 1 and hardware auto clear*/
#define BIT_CLR_VOQ_HW_IDX    ((u32)0x00000001 << 18) /*!< W 0x0  Clear VOQ hardware index, write 1 and hardware auto clear*/
#define BIT_CLR_MGQ_HW_IDX    ((u32)0x00000001 << 17) /*!< W 0x0  Clear MGQ hardware index, write 1 and hardware auto clear*/
#define BIT_CLR_RXQ_HW_IDX    ((u32)0x00000001 << 16) /*!< W 0x0  Clear RXQ hardware index, write 1 and hardware auto clear*/
#define BIT_AXI_TXDMA_SWRST_N ((u32)0x00000001 << 15) /*!< W 0x0  sw reset wlan axi txdma circuit, write 1 and hardware auto clear*/
#define BIT_AXI_RXDMA_SWRST_N ((u32)0x00000001 << 14) /*!< W 0x0  sw reset wlan axi rxdma circuit, write 1 and hardware auto clear*/
#define BIT_CLR_HI7Q_HOST_IDX ((u32)0x00000001 << 13) /*!< W 0x0  Clear HI7Q host index, write 1 and hardware auto clear*/
#define BIT_CLR_HI6Q_HOST_IDX ((u32)0x00000001 << 12) /*!< W 0x0  Clear HI6Q host index, write 1 and hardware auto clear*/
#define BIT_CLR_HI5Q_HOST_IDX ((u32)0x00000001 << 11) /*!< W 0x0  Clear HI5Q host index, write 1 and hardware auto clear*/
#define BIT_CLR_HI4Q_HOST_IDX ((u32)0x00000001 << 10) /*!< W 0x0  Clear HI4Q host index, write 1 and hardware auto clear*/
#define BIT_CLR_HI3Q_HOST_IDX ((u32)0x00000001 << 9)  /*!< W 0x0  Clear HI3Q host index, write 1 and hardware auto clear*/
#define BIT_CLR_HI2Q_HOST_IDX ((u32)0x00000001 << 8)  /*!< W 0x0  Clear HI2Q host index, write 1 and hardware auto clear*/
#define BIT_CLR_HI1Q_HOST_IDX ((u32)0x00000001 << 7)  /*!< W 0x0  Clear HI1Q host index, write 1 and hardware auto clear*/
#define BIT_CLR_HI0Q_HOST_IDX ((u32)0x00000001 << 6)  /*!< W 0x0  Clear HI0Q host index, write 1 and hardware auto clear*/
#define BIT_CLR_BKQ_HOST_IDX  ((u32)0x00000001 << 5)  /*!< W 0x0  Clear BKQ host index, write 1 and hardware auto clear*/
#define BIT_CLR_BEQ_HOST_IDX  ((u32)0x00000001 << 4)  /*!< W 0x0  Clear BEQ host index, write 1 and hardware auto clear*/
#define BIT_CLR_VIQ_HOST_IDX  ((u32)0x00000001 << 3)  /*!< W 0x0  Clear VIQ host index, write 1 and hardware auto clear*/
#define BIT_CLR_VOQ_HOST_IDX  ((u32)0x00000001 << 2)  /*!< W 0x0  Clear VOQ host index, write 1 and hardware auto clear*/
#define BIT_CLR_MGQ_HOST_IDX  ((u32)0x00000001 << 1)  /*!< W 0x0  Clear MGQ host index, write 1 and hardware auto clear*/
#define BIT_CLR_RXQ_HOST_IDX  ((u32)0x00000001 << 0)  /*!< W 0x0  Clear RXQ host index, write 1 and hardware auto clear*/
/** @} */

/** @defgroup REG_VOQ_TXBD_IDX
  * @brief
  * @{
  */
#define BIT_MASK_VOQ_HW_IDX     ((u32)0x00000FFF << 16)           /*!< RO 0x0  VO queue descriptor's hardware index*/
#define BIT_VOQ_HW_IDX(x)       (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_VOQ_HW_IDX(x)   ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_VOQ_HOST_IDX   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  VO queue descriptor's host index. The field is redefined as paket size when BIT_EN_EARLY_MODE is 1 and BIT_EARLY_MODE_SEL is selecting VOQ.*/
#define BIT_VOQ_HOST_IDX(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_VOQ_HOST_IDX(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_VIQ_TXBD_IDX
  * @brief
  * @{
  */
#define BIT_MASK_VIQ_HW_IDX     ((u32)0x00000FFF << 16)           /*!< RO 0x0  VI queue descriptor's hardware index*/
#define BIT_VIQ_HW_IDX(x)       (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_VIQ_HW_IDX(x)   ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_VIQ_HOST_IDX   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  VI queue descriptor's host index. The field is redefined as paket size when BIT_EN_EARLY_MODE is 1 and BIT_EARLY_MODE_SEL is selecting VIQ.*/
#define BIT_VIQ_HOST_IDX(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_VIQ_HOST_IDX(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_BEQ_TXBD_IDX
  * @brief
  * @{
  */
#define BIT_MASK_BEQ_HW_IDX     ((u32)0x00000FFF << 16)           /*!< RO 0x0  BE queue descriptor's hardware index*/
#define BIT_BEQ_HW_IDX(x)       (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_BEQ_HW_IDX(x)   ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_BEQ_HOST_IDX   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  BE queue descriptor's host index. The field is redefined as paket size when BIT_EN_EARLY_MODE is 1 and BIT_EARLY_MODE_SEL is selecting BEQ.*/
#define BIT_BEQ_HOST_IDX(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_BEQ_HOST_IDX(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_BKQ_TXBD_IDX
  * @brief
  * @{
  */
#define BIT_MASK_BKQ_HW_IDX     ((u32)0x00000FFF << 16)           /*!< RO 0x0  BK queue descriptor's hardware index*/
#define BIT_BKQ_HW_IDX(x)       (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_BKQ_HW_IDX(x)   ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_BKQ_HOST_IDX   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  BK queue descriptor's host index. The field is redefined as paket size when BIT_EN_EARLY_MODE is 1 and BIT_EARLY_MODE_SEL is selecting BKQ.*/
#define BIT_BKQ_HOST_IDX(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_BKQ_HOST_IDX(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_MGQ_TXBD_IDX
  * @brief
  * @{
  */
#define BIT_MASK_MGQ_HW_IDX     ((u32)0x00000FFF << 16)           /*!< RO 0x0  MG queue descriptor's hardware index*/
#define BIT_MGQ_HW_IDX(x)       (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_MGQ_HW_IDX(x)   ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_MGQ_HOST_IDX   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  MG queue descriptor's host index*/
#define BIT_MGQ_HOST_IDX(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_MGQ_HOST_IDX(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_RXQ_RXBD_IDX
  * @brief
  * @{
  */
#define BIT_MASK_RXQ_HW_IDX     ((u32)0x00000FFF << 16)           /*!< RO 0x0  RX queue descriptor's hardware index*/
#define BIT_RXQ_HW_IDX(x)       (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_RXQ_HW_IDX(x)   ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_RXQ_HOST_IDX   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  RX queue descriptor's host index*/
#define BIT_RXQ_HOST_IDX(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_RXQ_HOST_IDX(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HI0Q_TXBD_IDX
  * @brief
  * @{
  */
#define BIT_MASK_HI0Q_HW_IDX     ((u32)0x00000FFF << 16)           /*!< RO 0x0  HI0 queue descriptor's hardware index*/
#define BIT_HI0Q_HW_IDX(x)       (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_HI0Q_HW_IDX(x)   ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_HI0Q_HOST_IDX   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  HI0 queue descriptor's host index*/
#define BIT_HI0Q_HOST_IDX(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_HI0Q_HOST_IDX(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HI1Q_TXBD_IDX
  * @brief
  * @{
  */
#define BIT_MASK_HI1Q_HW_IDX     ((u32)0x00000FFF << 16)           /*!< RO 0x0  HI1 queue descriptor's hardware index*/
#define BIT_HI1Q_HW_IDX(x)       (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_HI1Q_HW_IDX(x)   ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_HI1Q_HOST_IDX   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  HI1 queue descriptor's host index*/
#define BIT_HI1Q_HOST_IDX(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_HI1Q_HOST_IDX(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HI2Q_TXBD_IDX
  * @brief
  * @{
  */
#define BIT_MASK_HI2Q_HW_IDX     ((u32)0x00000FFF << 16)           /*!< RO 0x0  HI2 queue descriptor's hardware index*/
#define BIT_HI2Q_HW_IDX(x)       (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_HI2Q_HW_IDX(x)   ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_HI2Q_HOST_IDX   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  HI2 queue descriptor's host index*/
#define BIT_HI2Q_HOST_IDX(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_HI2Q_HOST_IDX(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HI3Q_TXBD_IDX
  * @brief
  * @{
  */
#define BIT_MASK_HI3Q_HW_IDX     ((u32)0x00000FFF << 16)           /*!< RO 0x0  HI3 queue descriptor's hardware index*/
#define BIT_HI3Q_HW_IDX(x)       (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_HI3Q_HW_IDX(x)   ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_HI3Q_HOST_IDX   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  HI3 queue descriptor's host index*/
#define BIT_HI3Q_HOST_IDX(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_HI3Q_HOST_IDX(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HI4Q_TXBD_IDX
  * @brief
  * @{
  */
#define BIT_MASK_HI4Q_HW_IDX     ((u32)0x00000FFF << 16)           /*!< RO 0x0  HI4 queue descriptor's hardware index*/
#define BIT_HI4Q_HW_IDX(x)       (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_HI4Q_HW_IDX(x)   ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_HI4Q_HOST_IDX   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  HI4 queue descriptor's host index*/
#define BIT_HI4Q_HOST_IDX(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_HI4Q_HOST_IDX(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HI5Q_TXBD_IDX
  * @brief
  * @{
  */
#define BIT_MASK_HI5Q_HW_IDX     ((u32)0x00000FFF << 16)           /*!< RO 0x0  HI5 queue descriptor's hardware index*/
#define BIT_HI5Q_HW_IDX(x)       (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_HI5Q_HW_IDX(x)   ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_HI5Q_HOST_IDX   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  HI5 queue descriptor's host index*/
#define BIT_HI5Q_HOST_IDX(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_HI5Q_HOST_IDX(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HI6Q_TXBD_IDX
  * @brief
  * @{
  */
#define BIT_MASK_HI6Q_HW_IDX     ((u32)0x00000FFF << 16)           /*!< RO 0x0  HI6 queue descriptor's hardware index*/
#define BIT_HI6Q_HW_IDX(x)       (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_HI6Q_HW_IDX(x)   ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_HI6Q_HOST_IDX   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  HI6 queue descriptor's host index*/
#define BIT_HI6Q_HOST_IDX(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_HI6Q_HOST_IDX(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HI7Q_TXBD_IDX
  * @brief
  * @{
  */
#define BIT_MASK_HI7Q_HW_IDX     ((u32)0x00000FFF << 16)           /*!< RO 0x0  HI7 queue descriptor's hardware index*/
#define BIT_HI7Q_HW_IDX(x)       (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_HI7Q_HW_IDX(x)   ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_HI7Q_HOST_IDX   ((u32)0x00000FFF << 0)            /*!< R/W 0x0  HI7 queue descriptor's host index*/
#define BIT_HI7Q_HOST_IDX(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_HI7Q_HOST_IDX(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_HCI_HRPWM1_V1
  * @brief
  * @{
  */
#define BIT_MASK_HCI_HRPWM   ((u8)0x000000FF << 0)           /*!< R/W 0x0  HCI host request power mode. This register will be mapped to RPWM register (0x9c). And generate an interrupt to MCU*/
#define BIT_HCI_HRPWM(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_HCI_HRPWM(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_HCI_HCPWM1_V1
  * @brief
  * @{
  */
#define BIT_MASK_HCI_HCPWM   ((u8)0x000000FF << 0)           /*!< RO 0x0  HCI host current power mode. This register will be mapped from CPWM register (0x12F). When CPWM is toggled, CPWM_INT is issued to HISRE register*/
#define BIT_HCI_HCPWM(x)     (((u8)((x) & 0x000000FF) << 0))
#define BIT_GET_HCI_HCPWM(x) ((u8)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_HCI_CTRL2
  * @brief
  * @{
  */
#define BIT_HCI_INT ((u8)0x00000001 << 3) /*!< RO 0x0  combined Interrupt of ISR&IMR.*/
/** @} */

/** @defgroup REG_HCI_HRPWM2_V1
  * @brief
  * @{
  */
#define BIT_MASK_HCI_HRPWM2   ((u16)0x0000FFFF << 0)           /*!< R/W 0x0  HCI host request power mode. This register will be mapped to RPWM2 register (0x9E~0x9F). And generate an interrupt to MCU*/
#define BIT_HCI_HRPWM2(x)     (((u16)((x) & 0x0000FFFF) << 0))
#define BIT_GET_HCI_HRPWM2(x) ((u16)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_HCI_HCPWM2_V1
  * @brief
  * @{
  */
#define BIT_MASK_HCI_HCPWM2   ((u16)0x0000FFFF << 0)           /*!< RO 0x0  HCI host request power mode. This register will be mapped from CPWM register (0x14C). When CPWM is toggled, CPWM_INT is issued to HISRE register*/
#define BIT_HCI_HCPWM2(x)     (((u16)((x) & 0x0000FFFF) << 0))
#define BIT_GET_HCI_HCPWM2(x) ((u16)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_HCI_H2C_MSG_V1
  * @brief
  * @{
  */
#define BIT_MASK_DRV2FW_INFO   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  DRIVER TO FIRMWARE MESSAGE*/
#define BIT_DRV2FW_INFO(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_DRV2FW_INFO(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HCI_C2H_MSG_V1
  * @brief
  * @{
  */
#define BIT_MASK_HCI_C2H_MSG   ((u32)0xFFFFFFFF << 0)           /*!< RO 0x0  User Defined Message*/
#define BIT_HCI_C2H_MSG(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_HCI_C2H_MSG(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_DMA_ISR_V1
  * @brief
  * @{
  */
#define BIT_AXI_BCNDERR7_ISR  ((u32)0x00000001 << 31) /*!< R/W1C 0x0  ISR of BSSID7 BCN DMA fail*/
#define BIT_AXI_BCNDERR6_ISR  ((u32)0x00000001 << 30) /*!< R/W1C 0x0  ISR of BSSID6 BCN DMA fail*/
#define BIT_AXI_BCNDERR5_ISR  ((u32)0x00000001 << 29) /*!< R/W1C 0x0  ISR of BSSID5 BCN DMA fail*/
#define BIT_AXI_BCNDERR4_ISR  ((u32)0x00000001 << 28) /*!< R/W1C 0x0  ISR of BSSID4 BCN DMA fail*/
#define BIT_AXI_BCNDERR3_ISR  ((u32)0x00000001 << 27) /*!< R/W1C 0x0  ISR of BSSID3 BCN DMA fail*/
#define BIT_AXI_BCNDERR2_ISR  ((u32)0x00000001 << 26) /*!< R/W1C 0x0  ISR of BSSID2 BCN DMA fail*/
#define BIT_AXI_BCNDERR1_ISR  ((u32)0x00000001 << 25) /*!< R/W1C 0x0  ISR of BSSID1 BCN DMA fail*/
#define BIT_AXI_BCNDERR0_ISR  ((u32)0x00000001 << 24) /*!< R/W1C 0x0  ISR of BSSID0 BCN DMA fail*/
#define BIT_AXI_BCNDFAIL7_ISR ((u32)0x00000001 << 23) /*!< R/W1C 0x0  ISR of BSSID7 BCN DMA OK*/
#define BIT_AXI_BCNDOK6_ISR   ((u32)0x00000001 << 22) /*!< R/W1C 0x0  ISR of BSSID6 BCN DMA OK*/
#define BIT_AXI_BCNDOK5_ISR   ((u32)0x00000001 << 21) /*!< R/W1C 0x0  ISR of BSSID5 BCN DMA OK*/
#define BIT_AXI_BCNDOK4_ISR   ((u32)0x00000001 << 20) /*!< R/W1C 0x0  ISR of BSSID4 BCN DMA OK*/
#define BIT_AXI_BCNDOK3_ISR   ((u32)0x00000001 << 19) /*!< R/W1C 0x0  ISR of BSSID3 BCN DMA OK*/
#define BIT_AXI_BCNDOK2_ISR   ((u32)0x00000001 << 18) /*!< R/W1C 0x0  ISR of BSSID2 BCN DMA OK*/
#define BIT_AXI_BCNDOK1_ISR   ((u32)0x00000001 << 17) /*!< R/W1C 0x0  ISR of BSSID1 BCN DMA OK*/
#define BIT_AXI_BCNDOK0_ISR   ((u32)0x00000001 << 16) /*!< R/W1C 0x0  ISR of BSSID0 BCN DMA OK*/
#define BIT_AXI_HIGHDOK_ISR   ((u32)0x00000001 << 8)  /*!< R/W1C 0x0  ISR of High Queue DMA OK*/
#define BIT_AXI_MGDOK_ISR     ((u32)0x00000001 << 6)  /*!< R/W1C 0x0  ISR of Mgt Queue DMA OK*/
#define BIT_AXI_BKDOK_ISR     ((u32)0x00000001 << 5)  /*!< R/W1C 0x0  ISR of BK Queue DMA OK*/
#define BIT_AXI_BEDOK_ISR     ((u32)0x00000001 << 4)  /*!< R/W1C 0x0  ISR of BE Queue DMA OK*/
#define BIT_AXI_VIDOK_ISR     ((u32)0x00000001 << 3)  /*!< R/W1C 0x0  ISR of VI Queue DMA OK*/
#define BIT_AXI_VODOK_ISR     ((u32)0x00000001 << 2)  /*!< R/W1C 0x0  ISR of VO Queue DMA OK*/
#define BIT_AXI_RDU_ISR       ((u32)0x00000001 << 1)  /*!< R/W1C 0x0  ISR of RX Desc unavailable*/
#define BIT_AXI_RXDMA_OK_ISR  ((u32)0x00000001 << 0)  /*!< R/W1C 0x0  ISR of RX DMA OK*/
/** @} */

/** @defgroup REG_DMA_IMR_V1
  * @brief
  * @{
  */
#define BIT_AXI_BCNDERR7_IMR ((u32)0x00000001 << 31) /*!< R/W 0x0  IMR of BSSID7 BCN DMA fail*/
#define BIT_AXI_BCNDERR6_IMR ((u32)0x00000001 << 30) /*!< R/W 0x0  IMR of BSSID6 BCN DMA fail*/
#define BIT_AXI_BCNDERR5_IMR ((u32)0x00000001 << 29) /*!< R/W 0x0  IMR of BSSID5 BCN DMA fail*/
#define BIT_AXI_BCNDERR4_IMR ((u32)0x00000001 << 28) /*!< R/W 0x0  IMR of BSSID4 BCN DMA fail*/
#define BIT_AXI_BCNDERR3_IMR ((u32)0x00000001 << 27) /*!< R/W 0x0  IMR of BSSID3 BCN DMA fail*/
#define BIT_AXI_BCNDERR2_IMR ((u32)0x00000001 << 26) /*!< R/W 0x0  IMR of BSSID2 BCN DMA fail*/
#define BIT_AXI_BCNDERR1_IMR ((u32)0x00000001 << 25) /*!< R/W 0x0  IMR of BSSID1 BCN DMA fail*/
#define BIT_AXI_BCNDERR0_IMR ((u32)0x00000001 << 24) /*!< R/W 0x0  IMR of BSSID0 BCN DMA fail*/
#define BIT_AXI_BCNDOK7_IMR  ((u32)0x00000001 << 23) /*!< R/W 0x0  IMR of BSSID7 BCN DMA OK*/
#define BIT_AXI_BCNDOK6_IMR  ((u32)0x00000001 << 22) /*!< R/W 0x0  IMR of BSSID6 BCN DMA OK*/
#define BIT_AXI_BCNDOK5_IMR  ((u32)0x00000001 << 21) /*!< R/W 0x0  IMR of BSSID5 BCN DMA OK*/
#define BIT_AXI_BCNDOK4_IMR  ((u32)0x00000001 << 20) /*!< R/W 0x0  IMR of BSSID4 BCN DMA OK*/
#define BIT_AXI_BCNDOK3_IMR  ((u32)0x00000001 << 19) /*!< R/W 0x0  IMR of BSSID3 BCN DMA OK*/
#define BIT_AXI_BCNDOK2_IMR  ((u32)0x00000001 << 18) /*!< R/W 0x0  IMR of BSSID2 BCN DMA OK*/
#define BIT_AXI_BCNDOK1_IMR  ((u32)0x00000001 << 17) /*!< R/W 0x0  IMR of BSSID1 BCN DMA OK*/
#define BIT_AXI_BCNDOK0_IMR  ((u32)0x00000001 << 16) /*!< R/W 0x0  IMR of BSSID0 BCN DMA OK*/
#define BIT_AXI_HIGHDOK_IMR  ((u32)0x00000001 << 8)  /*!< R/W 0x0  IMR of High Queue DMA OK*/
#define BIT_AXI_MGDOK_IMR    ((u32)0x00000001 << 6)  /*!< R/W 0x0  IMR of Mgt Queue DMA OK*/
#define BIT_AXI_BKDOK_IMR    ((u32)0x00000001 << 5)  /*!< R/W 0x0  IMR of BK Queue DMA OK*/
#define BIT_AXI_BEDOK_IMR    ((u32)0x00000001 << 4)  /*!< R/W 0x0  IMR of BE Queue DMA OK*/
#define BIT_AXI_VIDOK_IMR    ((u32)0x00000001 << 3)  /*!< R/W 0x0  IMR of VI Queue DMA OK*/
#define BIT_AXI_VODOK_IMR    ((u32)0x00000001 << 2)  /*!< R/W 0x0  IMR of VO Queue DMA OK*/
#define BIT_AXI_RDU_IMR      ((u32)0x00000001 << 1)  /*!< R/W 0x0  IMR of RX Desc unavailable*/
#define BIT_AXI_RXDMA_OK_IMR ((u32)0x00000001 << 0)  /*!< R/W 0x0  IMR of RX DMA OK*/
/** @} */

/** @defgroup REG_STUCK_FLAG_V1
  * @brief
  * @{
  */
#define BIT_RX_STUCK       ((u32)0x00000001 << 9) /*!< RO 0x0  RX DMA stuck.*/
#define BIT_TX_STUCK       ((u32)0x00000001 << 8) /*!< RO 0x0  TX DMA stuck.*/
#define BIT_MST_BUSY       ((u32)0x00000001 << 3) /*!< RO   indicate WLAN AXI master interface is busy*/
#define BIT_RXBUF_ZERO_ERR ((u32)0x00000001 << 2) /*!< R/W1C   indicate the error that rest rxdma size is 0 after fetching new rxbd*/
#define BIT_HDR_SIZE_ERR   ((u32)0x00000001 << 1) /*!< R/W1C   indicate the error that header size is less than txdes size*/
#define BIT_EN_STUCK_DBG   ((u32)0x00000001 << 0) /*!< R/W 0x0  enable DMA stuck debug*/
/** @} */

/** @defgroup REG_WDT_CFG
  * @brief
  * @{
  */
#define BIT_MASK_WATCH_DOG_RECORD_V1   ((u32)0x00003FFF << 10)           /*!< RO 0x0  Time out ahb address*/
#define BIT_WATCH_DOG_RECORD_V1(x)     (((u32)((x) & 0x00003FFF) << 10))
#define BIT_GET_WATCH_DOG_RECORD_V1(x) ((u32)(((x >> 10) & 0x00003FFF)))
#define BIT_R_IO_TIMEOUT_FLAG_V1       ((u32)0x00000001 << 9)            /*!< R/W 0x0  ahb timeout flag.Write "1" to clear.*/
#define BIT_EN_WATCH_DOG_V1            ((u32)0x00000001 << 8)            /*!< R/W 0x0  Enable ahb timeout watchdog*/
/** @} */

/** @defgroup REG_HCI_MIX_CFG
  * @brief
  * @{
  */
#define BIT_MASK_DEBUG_SEL       ((u32)0x00000003 << 22)           /*!< R/W 0x0  debug output selector for 0x310~0x378*/
#define BIT_DEBUG_SEL(x)         (((u32)((x) & 0x00000003) << 22))
#define BIT_GET_DEBUG_SEL(x)     ((u32)(((x >> 22) & 0x00000003)))
#define BIT_MASK_RDE_SFF_WRPTR   ((u32)0x0000001F << 15)           /*!< RO   rxdma sync fifo wr pointer*/
#define BIT_RDE_SFF_WRPTR(x)     (((u32)((x) & 0x0000001F) << 15))
#define BIT_GET_RDE_SFF_WRPTR(x) ((u32)(((x >> 15) & 0x0000001F)))
#define BIT_MASK_RDE_SFF_RDPTR   ((u32)0x0000001F << 10)           /*!< RO   rxdma sync fifo rd pointer*/
#define BIT_RDE_SFF_RDPTR(x)     (((u32)((x) & 0x0000001F) << 10))
#define BIT_GET_RDE_SFF_RDPTR(x) ((u32)(((x >> 10) & 0x0000001F)))
#define BIT_MASK_TDE_SFF_WRPTR   ((u32)0x0000001F << 5)            /*!< RO   txdma sync fifo wr pointer*/
#define BIT_TDE_SFF_WRPTR(x)     (((u32)((x) & 0x0000001F) << 5))
#define BIT_GET_TDE_SFF_WRPTR(x) ((u32)(((x >> 5) & 0x0000001F)))
#define BIT_EN_MUL_TAG           ((u32)0x00000001 << 6)            /*!< W 0x1  Enable multi-tag.*/
#define BIT_MASK_TDE_SFF_RDPTR   ((u32)0x0000001F << 0)            /*!< RO   txdma sync fifo rd pointer*/
#define BIT_TDE_SFF_RDPTR(x)     (((u32)((x) & 0x0000001F) << 0))
#define BIT_GET_TDE_SFF_RDPTR(x) ((u32)(((x >> 0) & 0x0000001F)))
/** @} */

/*==========REG_PAGE3 Register Address Definition==========*/
#define REG_HCI_CTRL                      0x300
#define REG_INT_MIG                       0x304
#define REG_BCNQ_TXBD_DESA                0x308
#define REG_MGQ_TXBD_DESA                 0x310
#define REG_VOQ_TXBD_DESA                 0x318
#define REG_VIQ_TXBD_DESA                 0x320
#define REG_BEQ_TXBD_DESA                 0x328
#define REG_BKQ_TXBD_DESA                 0x330
#define REG_RXQ_RXBD_DESA                 0x338
#define REG_HI0Q_TXBD_DESA                0x340
#define REG_HI1Q_TXBD_DESA                0x348
#define REG_HI2Q_TXBD_DESA                0x350
#define REG_HI3Q_TXBD_DESA                0x358
#define REG_HI4Q_TXBD_DESA                0x360
#define REG_HI5Q_TXBD_DESA                0x368
#define REG_HI6Q_TXBD_DESA                0x370
#define REG_HI7Q_TXBD_DESA                0x378
#define REG_MGQ_TXBD_RX_RXBD_NUM          0x380
#define REG_VOQ_TXBD_NUM                  0x384
#define REG_VIQ_TXBD_NUM                  0x386
#define REG_BEQ_TXBD_NUM                  0x388
#define REG_BKQ_TXBD_NUM                  0x38A
#define REG_HI0Q_TXBD_NUM                 0x38C
#define REG_HI1Q_TXBD_NUM                 0x38E
#define REG_HI2Q_TXBD_NUM                 0x390
#define REG_HI3Q_TXBD_NUM                 0x392
#define REG_HI4Q_TXBD_NUM                 0x394
#define REG_HI5Q_TXBD_NUM                 0x396
#define REG_HI6Q_TXBD_NUM                 0x398
#define REG_HI7Q_TXBD_NUM                 0x39A
#define REG_BD_RWPTR_CLR                  0x39C
#define REG_VOQ_TXBD_IDX                  0x3A0
#define REG_VIQ_TXBD_IDX                  0x3A4
#define REG_BEQ_TXBD_IDX                  0x3A8
#define REG_BKQ_TXBD_IDX                  0x3AC
#define REG_MGQ_TXBD_IDX                  0x3B0
#define REG_RXQ_RXBD_IDX                  0x3B4
#define REG_HI0Q_TXBD_IDX                 0x3B8
#define REG_HI1Q_TXBD_IDX                 0x3BC
#define REG_HI2Q_TXBD_IDX                 0x3C0
#define REG_HI3Q_TXBD_IDX                 0x3C4
#define REG_HI4Q_TXBD_IDX                 0x3C8
#define REG_HI5Q_TXBD_IDX                 0x3CC
#define REG_HI6Q_TXBD_IDX                 0x3D0
#define REG_HI7Q_TXBD_IDX                 0x3D4
#define REG_HCI_HRPWM1_V1                 0x3D9
#define REG_HCI_HCPWM1_V1                 0x3DA
#define REG_HCI_CTRL2                     0x3DB
#define REG_HCI_HRPWM2_V1                 0x3DC
#define REG_HCI_HCPWM2_V1                 0x3DE
#define REG_HCI_H2C_MSG_V1                0x3E0
#define REG_HCI_C2H_MSG_V1                0x3E4
#define REG_DMA_ISR_V1                    0x3E8
#define REG_DMA_IMR_V1                    0x3EC
#define REG_STUCK_FLAG_V1                 0x3F0
#define REG_WDT_CFG                       0x3F8
#define REG_HCI_MIX_CFG                   0x3FC

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