#ifndef _project_name_REG_PAGE2_H_
#define _project_name_REG_PAGE2_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE2
  * @brief REG_PAGE2 driver modules
  * @{
  */


/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE2_Register_Definitions REG_PAGE2 Register Definitions
  * @{
  */

/** @defgroup REG_RQPN_CTRL_HLPQ
  * @brief
  * @{
  */
#define BIT_LD_RQPN         ((u32)0x00000001 << 31)           /*!< W 0x0  Write 1 to set RQPN bit[79:0] value to page numbers for initialization*/
#define BIT_EP2Q_PUBLIC_DIS ((u32)0x00000001 << 29)           /*!< R/W 0x0  When this bit is set, Extra queue2 available Tx page size excludes the public queue. Otherwise, Extra queue2 available Tx page size includes public queue*/
#define BIT_EP1Q_PUBLIC_DIS ((u32)0x00000001 << 28)           /*!< R/W 0x0  When this bit is set, Extra queue1 available Tx page size excludes the public queue. Otherwise, Extra queue1 available Tx page size includes public queue*/
#define BIT_EPQ_PUBLIC_DIS  ((u32)0x00000001 << 27)           /*!< R/W 0x0  When this bit is set, Extra queue available Tx page size excludes the public queue. Otherwise, Extra queue available Tx page size includes public queue*/
#define BIT_NPQ_PUBLIC_DIS  ((u32)0x00000001 << 26)           /*!< R/W 0x0  When this bit is set, Low queue available Tx page size excludes the public queue. Otherwise, Low queue available Tx page size includes public queue*/
#define BIT_LPQ_PUBLIC_DIS  ((u32)0x00000001 << 25)           /*!< R/W 0x0  When this bit is set, Low queue available Tx page size excludes the public queue. Otherwise, Low queue available Tx page size includes public queue*/
#define BIT_HPQ_PUBLIC_DIS  ((u32)0x00000001 << 24)           /*!< R/W 0x0  When this bit is set, High queue available Tx page size excludes the public queue. Otherwise,  High queue available Tx page size includes public queue*/
#define BIT_MASK_PUBQ       ((u32)0x000000FF << 16)           /*!< R/W 0x0  Public Reserved Page Number*/
#define BIT_PUBQ(x)         (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_PUBQ(x)     ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_LPQ        ((u32)0x000000FF << 8)            /*!< R/W 0x0  Low Priority Queue Reserved Page Number*/
#define BIT_LPQ(x)          (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_LPQ(x)      ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_HPQ        ((u32)0x000000FF << 0)            /*!< R/W 0x0  High Priority Queue Reserved Page Number*/
#define BIT_HPQ(x)          (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_HPQ(x)      ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_FIFOPAGE_INFO
  * @brief
  * @{
  */
#define BIT_MASK_TXPKTNUM       ((u32)0x000000FF << 24)           /*!< R 0x0  Packet number in TXPKTBUF (Normal/Low/Extra1/Extra2)*/
#define BIT_TXPKTNUM(x)         (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_TXPKTNUM(x)     ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_PUBQ_AVAL_PG   ((u32)0x000000FF << 16)           /*!< R 0x0  Available Public Queue Page Number*/
#define BIT_PUBQ_AVAL_PG(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_PUBQ_AVAL_PG(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_LPQ_AVAL_PG    ((u32)0x000000FF << 8)            /*!< R 0x0  Available Low Priority Queue Page Number*/
#define BIT_LPQ_AVAL_PG(x)      (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_LPQ_AVAL_PG(x)  ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_HPQ_AVAL_PG    ((u32)0x000000FF << 0)            /*!< R 0x0  Available High Priority Queue Page Number*/
#define BIT_HPQ_AVAL_PG(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_HPQ_AVAL_PG(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_DWBCN0_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_LLT_FREE_PAGE   ((u32)0x000000FF << 24)           /*!< R 0x0  LLT Free head Page*/
#define BIT_LLT_FREE_PAGE(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_LLT_FREE_PAGE(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_BCN_VALID            ((u32)0x00000001 << 16)           /*!< R/W1C 0x0  When this bit is set, the beacon packet has finished to write to txpktbuffer. Clear by SW*/
#define BIT_MASK_BCN_HEAD        ((u32)0x000000FF << 8)            /*!< R/W 0xF6  The head page of packet of Bcnq which is Tx DMA filled Bcnq packet from*/
#define BIT_BCN_HEAD(x)          (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_BCN_HEAD(x)      ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_BLK_DESC_NUM    ((u32)0x0000000F << 4)            /*!< R/W 0x0  The Most Number of Tx Descriptor per Bulk Out Only for USB*/
#define BIT_BLK_DESC_NUM(x)      (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_BLK_DESC_NUM(x)  ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_BLK_DESC_OPT         ((u32)0x00000001 << 0)            /*!< R/W 0x0  option to select usb descriptor number(according to 0x208[7:4]) 1 : usb_desc_num = 2 * r_blk_desc_num 0 : usb_desc_num = 4 * r_blk_desc_num*/
/** @} */

/** @defgroup REG_TXDMA_OFFSET_CHK
  * @brief
  * @{
  */
#define BIT_EN_CHKSUM_ERR_FIN     ((u32)0x00000001 << 31)           /*!< R/W 0x0  Let checksum offload statemachine finish if checksum parser error*/
#define BIT_EN_PCIE_DMA_MOD       ((u32)0x00000001 << 30)           /*!< R/W 0x0  Enable every dma latch fifo ptr for pcie as usb mode as one pkt trans in permu*/
#define BIT_EN_TXQUE_CLR          ((u32)0x00000001 << 29)           /*!< R/W 0x0  Enable tx queue clr clear tx pkt in tde in usb mode*/
#define BIT_EN_PCIE_FIFO_MODE     ((u32)0x00000001 << 28)           /*!< R/W 0x0  Enable pcie fifo store forward txdesc as before mode*/
#define BIT_MASK_PG_UNDER_TH_V2   ((u32)0x000000FF << 16)           /*!< R/W 0xFD  Page threshold value is check by Tx DMA engine.*/
#define BIT_PG_UNDER_TH_V2(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_PG_UNDER_TH_V2(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_EN_RESTORE_H2C_BY_RST ((u32)0x00000001 << 15)           /*!< R/W 0x0  when set to1, HW will set H2C read point to H2C queue's header page once TDE enable*/
#define BIT_SDIO_TDE_FINISH       ((u32)0x00000001 << 14)           /*!< R/W 0x0  When set to 1, TDE statemachine will end earlier for SDIO compare with PCIE/USB*/
#define BIT_SDIO_TXDESC_CHKSUM_EN ((u32)0x00000001 << 13)           /*!< R/W 0x0  Enable SDIO checksum*/
#define BIT_RST_RDPTR             ((u32)0x00000001 << 12)           /*!< R/W 0x0  Reset the read pointer of sync FIFO*/
#define BIT_RST_WRPTR             ((u32)0x00000001 << 11)           /*!< R/W 0x0  Reset the write pointer of sync FIFO*/
#define BIT_CHK_PG_TH_EN          ((u32)0x00000001 << 10)           /*!< R/W 0x0  Enable Tx DMA to check total pages if it is under page threshold*/
#define BIT_DROP_DATA_EN          ((u32)0x00000001 << 9)            /*!< R/W 0x0  Enable Tx DMA to drop the redundant data of packet*/
#define BIT_CHECK_OFFSET_EN       ((u32)0x00000001 << 8)            /*!< R/W 0x0  Enable Tx DMA to check offset value*/
#define BIT_MASK_CHECK_OFFSET     ((u32)0x000000FF << 0)            /*!< R/W 0x0  Offset value is check by Tx DMA engine*/
#define BIT_CHECK_OFFSET(x)       (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_CHECK_OFFSET(x)   ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TXDMA_STATUS
  * @brief
  * @{
  */
#define BIT_HI_OQT_UDN         ((u32)0x00000001 << 17) /*!< R/W1C 0x0  High Priority Queue_Tx OQT underflow*/
#define BIT_HI_OQT_OVF         ((u32)0x00000001 << 16) /*!< R/W1C 0x0  High Priority Queue_Tx OQT overflow*/
#define BIT_PAYLOAD_CHKSUM_ERR ((u32)0x00000001 << 15) /*!< R/W1C 0x0  Payload checksum error*/
#define BIT_PAYLOAD_UDN        ((u32)0x00000001 << 14) /*!< R/W1C 0x0  Payload is under the packet length of Tx descriptor. Clear by SW.*/
#define BIT_PAYLOAD_OVF        ((u32)0x00000001 << 13) /*!< R/W1C 0x0  Payload is over the packet length of Tx descriptor. Clear by SW.*/
#define BIT_DSC_CHKSUM_FAIL    ((u32)0x00000001 << 12) /*!< R/W1C 0x0  Tx descriptor checksum error. Clear by SW.*/
#define BIT_UNKNOWN_QSEL       ((u32)0x00000001 << 11) /*!< R/W1C 0x0  An unknown QSEL of Tx descriptor is detected. Clear by SW.*/
#define BIT_EP_QSEL_DIFF       ((u32)0x00000001 << 10) /*!< R/W1C 0x0  Tx Endpoint is unmatched with the QSEL of descriptor. Clear by SW.*/
#define BIT_TX_OFFS_UNMATCH    ((u32)0x00000001 << 9)  /*!< R/W1C 0x0  Tx offset is unmatched. Clear by SW.*/
#define BIT_TXOQT_UDN          ((u32)0x00000001 << 8)  /*!< R/W1C 0x0  TXOQT Underflow. Clear by SW.*/
#define BIT_TXOQT_OVF          ((u32)0x00000001 << 7)  /*!< R/W1C 0x0  TXOQT Overflow. Clear by SW.*/
#define BIT_TXDMA_SFF_UDN      ((u32)0x00000001 << 6)  /*!< R/W1C 0x0  TXDMA Sync FIFO Underflow. Clear by SW.*/
#define BIT_TXDMA_SFF_OVF      ((u32)0x00000001 << 5)  /*!< R/W1C 0x0  TXDMA Sync FIFO Overflow. Clear by SW.*/
#define BIT_LLT_NULL_PG        ((u32)0x00000001 << 4)  /*!< R/W1C 0x0  TXDMA reads NULL page. Clear by SW.*/
#define BIT_PAGE_UDN           ((u32)0x00000001 << 3)  /*!< R/W1C 0x0  Total pages included PTCL un-return pages are under the total reserved pages minus the page threshold. Clear by SW.*/
#define BIT_PAGE_OVF           ((u32)0x00000001 << 2)  /*!< R/W1C 0x0  Total pages included PTCL un-return pages are over the total reserved pages. Clear by SW.*/
#define BIT_TXFF_PG_UDN        ((u32)0x00000001 << 1)  /*!< R/W1C 0x0  TXFF page underflow in TDE page controller. Clear by SW.*/
#define BIT_TXFF_PG_OVF        ((u32)0x00000001 << 0)  /*!< R/W1C 0x0  TXFF page overflow in TDE page controller.. Clear by SW.*/
/** @} */

/** @defgroup REG_RQPN_NPQ
  * @brief
  * @{
  */
#define BIT_MASK_EXQ_AVAL_PG   ((u32)0x000000FF << 24)           /*!< R 0x0  Available Extra Queue Page Number*/
#define BIT_EXQ_AVAL_PG(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_EXQ_AVAL_PG(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_EXQ           ((u32)0x000000FF << 16)           /*!< R/W 0x0  Extra Queue Reserved Page Number*/
#define BIT_EXQ(x)             (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_EXQ(x)         ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_NPQ_AVAL_PG   ((u32)0x000000FF << 8)            /*!< R 0x0  Available Normal Priority Queue Page Number*/
#define BIT_NPQ_AVAL_PG(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_NPQ_AVAL_PG(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_NPQ           ((u32)0x000000FF << 0)            /*!< R/W 0x0  Normal Priority Queue Reserved Page Number*/
#define BIT_NPQ(x)             (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_NPQ(x)         ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TQPNT1
  * @brief
  * @{
  */
#define BIT_MASK_NPQ_HIGH_TH   ((u32)0x000000FF << 24)           /*!< R/W 0x0  For SDIO,  Normal Priority Queue Page Number High Threshold*/
#define BIT_NPQ_HIGH_TH(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_NPQ_HIGH_TH(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_NPQ_LOW_TH    ((u32)0x000000FF << 16)           /*!< R/W 0x0  For SDIO, Normal Priority Queue Page Number Low Threshold*/
#define BIT_NPQ_LOW_TH(x)      (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_NPQ_LOW_TH(x)  ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_HPQ_HIGH_TH   ((u32)0x000000FF << 8)            /*!< R/W 0x0  For SDIO, High Priority Queue Page Number High Threshold*/
#define BIT_HPQ_HIGH_TH(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_HPQ_HIGH_TH(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_HPQ_LOW_TH    ((u32)0x000000FF << 0)            /*!< R/W 0x0  For SDIO, High Priority Queue Page Number Low Threshold*/
#define BIT_HPQ_LOW_TH(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_HPQ_LOW_TH(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TQPNT2
  * @brief
  * @{
  */
#define BIT_MASK_EXQ_HIGH_TH   ((u32)0x000000FF << 24)           /*!< R/W 0x0  For SDIO,  Extra Priority Queue Page Number High Threshold*/
#define BIT_EXQ_HIGH_TH(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_EXQ_HIGH_TH(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_EXQ_LOW_TH    ((u32)0x000000FF << 16)           /*!< R/W 0x0  For SDIO,  Extra Priority Queue Page Number Low Threshold*/
#define BIT_EXQ_LOW_TH(x)      (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_EXQ_LOW_TH(x)  ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_LPQ_HIGH_TH   ((u32)0x000000FF << 8)            /*!< R/W 0x0  For SDIO,  Low Priority Queue Page Number High Threshold*/
#define BIT_LPQ_HIGH_TH(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_LPQ_HIGH_TH(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_LPQ_LOW_TH    ((u32)0x000000FF << 0)            /*!< R/W 0x0  For SDIO,  Low Priority Queue Page Number Low Threshold*/
#define BIT_LPQ_LOW_TH(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_LPQ_LOW_TH(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TDE_DEBUG
  * @brief
  * @{
  */
#define BIT_MASK_TDE_DEBUG   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  tde debug port register.*/
#define BIT_TDE_DEBUG(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_TDE_DEBUG(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_AUTO_LLT
  * @brief
  * @{
  */
#define BIT_MASK_TXPKTNUM_V1            ((u32)0x000000FF << 24)           /*!< R 0x0  Packet number in TXPKTBUF (High and Extra)*/
#define BIT_TXPKTNUM_V1(x)              (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_TXPKTNUM_V1(x)          ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_TDE_DBG_SEL                 ((u32)0x00000001 << 23)           /*!< R/W 0x0  debug signals selection of Tx DMA*/
#define BIT_MASK_QSEL_DIFF              ((u32)0x00000001 << 22)           /*!< R/W 0x0  Mask the error bit(tx endpoint is unmatched with qsel, 0x210[10])*/
#define BIT_AUTO_INIT_LLT               ((u32)0x00000001 << 16)           /*!< R/W 0x0  Write 1 to enable HW init LLT, driver need polling to 0 meaning init success*/
#define BIT_MASK_TX_OQT_HE_FREE_SPACE   ((u32)0x000000FF << 8)            /*!< R 0x0  High and Extra priority queue*/
#define BIT_TX_OQT_HE_FREE_SPACE(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_TX_OQT_HE_FREE_SPACE(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_TX_OQT_NL_FREE_SPACE   ((u32)0x000000FF << 0)            /*!< R 0x0  Normal and low priority queue*/
#define BIT_TX_OQT_NL_FREE_SPACE(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_TX_OQT_NL_FREE_SPACE(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_DWBCN1_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_BCN_HEAD_2                    ((u32)0x000000FF << 24)           /*!< R/W 0xFA  The head page of packet of Bcnq which is Tx DMA filled Bcnq packet from.*/
#define BIT_BCN_HEAD_2(x)                      (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_BCN_HEAD_2(x)                  ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_SW_BCN_SEL                    ((u32)0x00000003 << 20)           /*!< R/W 0x0  Bcnq head selection from SW setting 2'b01 : r_bcn_head_1 2'b10 : r_bcn_head_2*/
#define BIT_SW_BCN_SEL(x)                      (((u32)((x) & 0x00000003) << 20))
#define BIT_GET_SW_BCN_SEL(x)                  ((u32)(((x >> 20) & 0x00000003)))
#define BIT_BCN_VALID_2                        ((u32)0x00000001 << 18)           /*!< R/W 0x0  When this bit is set, the beacon packet has finished to write to txpktbuffer. Clear by SW.*/
#define BIT_SW_BCN_SEL_EN                      ((u32)0x00000001 << 17)           /*!< R/W 0x0  Enable Bcnq head selection from SW setting*/
#define BIT_BCN_VALID_1                        ((u32)0x00000001 << 16)           /*!< R/W 0x0  When this bit is set, the beacon packet has finished to write to txpktbuffer. Clear by SW.*/
#define BIT_MASK_BCN_HEAD_1                    ((u32)0x000000FF << 8)            /*!< R/W 0x0  The head page of packet of Bcnq which is Tx DMA filled Bcnq packet from.*/
#define BIT_BCN_HEAD_1(x)                      (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_BCN_HEAD_1(x)                  ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_MAX_TX_PKT_FOR_USB_AND_SDIO   ((u32)0x000000FF << 0)            /*!< R/W 0x0  Unit : packet number*/
#define BIT_MAX_TX_PKT_FOR_USB_AND_SDIO(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_MAX_TX_PKT_FOR_USB_AND_SDIO(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TX_ALIGNMENT_CTRL
  * @brief
  * @{
  */
#define BIT_ADJUSTABLE_SIZE_EN    ((u32)0x00000001 << 15)          /*!< R/W 0x0  Enable tx alignment for sdio. SW can assign the alignment size of blocks in an aggregated-packet.*/
#define BIT_MASK_ALIGNMENT_SIZE   ((u32)0x00000FFF << 0)           /*!< R/W 0x0  The alignment size of blocks in an aggregated-packet. Unit: Byte*/
#define BIT_ALIGNMENT_SIZE(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_ALIGNMENT_SIZE(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_RQPN_EXQ1_EXQ2
  * @brief
  * @{
  */
#define BIT_MASK_EXQ2_AVAL_PG   ((u32)0x000000FF << 24)           /*!< R 0x0  Available Page Number of Extra Queue2*/
#define BIT_EXQ2_AVAL_PG(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_EXQ2_AVAL_PG(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_EXQ2           ((u32)0x000000FF << 16)           /*!< R/W 0x0  Extra Queue2 Reserved Page Number*/
#define BIT_EXQ2(x)             (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_EXQ2(x)         ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_EXQ1_AVAL_PG   ((u32)0x000000FF << 8)            /*!< R 0x0  Available Page Number of Extra Queue1*/
#define BIT_EXQ1_AVAL_PG(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_EXQ1_AVAL_PG(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_EXQ1           ((u32)0x000000FF << 0)            /*!< R/W 0x0  Extra Queue1 Reserved Page Number*/
#define BIT_EXQ1(x)             (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_EXQ1(x)         ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TQPNT3_V1
  * @brief
  * @{
  */
#define BIT_MASK_EXQ2_HIGH_TH   ((u32)0x000000FF << 24)           /*!< R/W 0x0  For SDIO,  Extra Queue2 Page Number High Threshold*/
#define BIT_EXQ2_HIGH_TH(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_EXQ2_HIGH_TH(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_EXQ2_LOW_TH    ((u32)0x000000FF << 16)           /*!< R/W 0x0  For SDIO,  Extra Queue2 Page Number Low Threshold*/
#define BIT_EXQ2_LOW_TH(x)      (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_EXQ2_LOW_TH(x)  ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_EXQ1_HIGH_TH   ((u32)0x000000FF << 8)            /*!< R/W 0x0  For SDIO,  Extra Queue1 Page Number High Threshold*/
#define BIT_EXQ1_HIGH_TH(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_EXQ1_HIGH_TH(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_EXQ1_LOW_TH    ((u32)0x000000FF << 0)            /*!< R/W 0x0  For SDIO,  Extra Queue1 Page Number Low Threshold*/
#define BIT_EXQ1_LOW_TH(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_EXQ1_LOW_TH(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_H2C_HEAD
  * @brief
  * @{
  */
#define BIT_MASK_H2C_HEAD_V2   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  h2c head addr*/
#define BIT_H2C_HEAD_V2(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_H2C_HEAD_V2(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_H2C_TAIL
  * @brief
  * @{
  */
#define BIT_MASK_H2C_TAIL_V2   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  h2c tail addr*/
#define BIT_H2C_TAIL_V2(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_H2C_TAIL_V2(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_H2C_READ_ADDR
  * @brief
  * @{
  */
#define BIT_MASK_H2C_READ_ADDR_V2   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  h2c read addr by fw*/
#define BIT_H2C_READ_ADDR_V2(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_H2C_READ_ADDR_V2(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_H2C_WR_ADDR
  * @brief
  * @{
  */
#define BIT_MASK_H2C_WR_ADDR_V2   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  h2c write addr by hw*/
#define BIT_H2C_WR_ADDR_V2(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_H2C_WR_ADDR_V2(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_H2C_INFO
  * @brief
  * @{
  */
#define BIT_H2C_SPACE_VLD      ((u32)0x00000001 << 3)           /*!< R 0x0  H2C space valid*/
#define BIT_H2C_WR_ADDR_RST    ((u32)0x00000001 << 2)           /*!< R/W 0x0  reset H2C write addr*/
#define BIT_MASK_H2C_LEN_SEL   ((u32)0x00000003 << 0)           /*!< R/W 0x0  h2c pkt len sel : 2'b0 : 16B, 2'b01 : 32B, 2'b10 : 64B, 2'b11 128B*/
#define BIT_H2C_LEN_SEL(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_H2C_LEN_SEL(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_RXDMA_AGG_PG_TH
  * @brief
  * @{
  */
#define BIT_RXDMA_AGG_OLD_MOD_V1   ((u32)0x00000001 << 31)           /*!< R/W 0x0  usb rx dma old mode store pkt and forward*/
#define BIT_RXAGG_TH_MODE          ((u32)0x00000001 << 29)           /*!< R/W 0x0  0: rde start rxdma when aggregated length over specified threshold; 1: rde start rxdma when next packet, if aggregated, will cause the total length over specified threshold*/
#define BIT_MASK_PKT_NUM_WOL       ((u32)0x000000FF << 16)           /*!< R/W 0x0  In wol mode, 8051 should refer this packet counter in RXFF*/
#define BIT_PKT_NUM_WOL(x)         (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_PKT_NUM_WOL(x)     ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_DMA_AGG_TO_V1     ((u32)0x000000FF << 8)            /*!< R/W 0x0  dma agg timeout time : unit : 32us*/
#define BIT_DMA_AGG_TO_V1(x)       (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_DMA_AGG_TO_V1(x)   ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_RXDMA_AGG_PG_TH   ((u32)0x000000FF << 0)            /*!< R/W 0x0  rxdma agg length threshold  if sdio : unit 1K, others unit is 4K if use RXDMA_AGG_OLD_MOD in use, unit is 1K*/
#define BIT_RXDMA_AGG_PG_TH(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_RXDMA_AGG_PG_TH(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_RXPKT_NUM
  * @brief
  * @{
  */
#define BIT_MASK_RXPKT_NUM      ((u32)0x000000FF << 24)           /*!< R 0x0  The number of packets in RXPKTBUF.*/
#define BIT_RXPKT_NUM(x)        (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_RXPKT_NUM(x)    ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_STOP_RXDMA          ((u32)0x00000001 << 20)           /*!< R/W 0x0  Notify rx dma engine to stop handling new request from macrx*/
#define BIT_RXDMA_REQ           ((u32)0x00000001 << 19)           /*!< R/W 0x0  rxdma has request*/
#define BIT_FW_RELEASE_EN       ((u32)0x00000001 << 18)           /*!< R/W 0x0  When this bit is set, RXDMA will enter this mode after on-going RXDMA packet to host completed,  and stop DMA packet to host. RXDMA will then report*/
#define BIT_RXDMA_IDLE          ((u32)0x00000001 << 17)           /*!< R 0x0  When RXMA finishes on-going DMA operation, RXMDA will report idle state in this bit.  FW can start releasing packets after RXDMA entering idle mode.*/
#define BIT_RXPKT_RELEASE_POLL  ((u32)0x00000001 << 16)           /*!< W 0x0  When this bit is set, RXDMA will decrease RX PKT counter by one. Before this bit is polled,  FW shall update RXFF_RD_PTR first.*/
#define BIT_MASK_FW_UPD_RDPTR   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  FW shall update this register before FW write RXPKT_RELEASE_POLL to 1.*/
#define BIT_FW_UPD_RDPTR(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_FW_UPD_RDPTR(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_RXDMA_STATUS
  * @brief
  * @{
  */
#define BIT_C2H_PKT_OVF      ((u32)0x00000001 << 7) /*!< R/W1C 0x0  CH2 pkt overflow. Clr by SW*/
#define BIT_AGG_CONFGI_ISSUE ((u32)0x00000001 << 6) /*!< R/W1C 0x0  rxdma agg config error. Clr by SW*/
#define BIT_FW_POLL_ISSUE    ((u32)0x00000001 << 5) /*!< R/W1C 0x0  FW Release Poll Error. Clear by SW.*/
#define BIT_RX_DATA_UDN      ((u32)0x00000001 << 4) /*!< R/W1C 0x0  FW Release Poll Error. Clear by SW.*/
#define BIT_RX_SFF_UDN       ((u32)0x00000001 << 3) /*!< R/W1C 0x0  RX Sync FIFO Underflow. Clear by SW.*/
#define BIT_RX_SFF_OVF       ((u32)0x00000001 << 2) /*!< R/W1C 0x0  RX Sync FIFO Overflow. Clear by SW.*/
#define BIT_RXPKT_OVF        ((u32)0x00000001 << 0) /*!< R/W1C 0x0  When RX Packet is more than 255 packets remaining in FF. Clear by SW.*/
/** @} */

/** @defgroup REG_RXDMA_DPR
  * @brief
  * @{
  */
#define BIT_MASK_RDE_DEBUG   ((u32)0xFFFFFFFF << 0)           /*!< R 0x0  rde debug port register.*/
#define BIT_RDE_DEBUG(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_RDE_DEBUG(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_RXDMA_MODE
  * @brief
  * @{
  */
#define BIT_MASK_BURST_SIZE   ((u32)0x00000003 << 4)           /*!< R/W 0x0  Every burst pkt len 2'b00 : 1KB 2'b01 : 512B 2'b10 : 64B Others : 64B P.S. USB 3.0 must set : 0x00         USB 2.0 High-speed must set : 0x01         USB 2.0 Full-speed must set : 0x10*/
#define BIT_BURST_SIZE(x)     (((u32)((x) & 0x00000003) << 4))
#define BIT_GET_BURST_SIZE(x) ((u32)(((x >> 4) & 0x00000003)))
#define BIT_MASK_BURST_CNT    ((u32)0x00000003 << 2)           /*!< R/W 0x1  Burst number in dma mode, support at most 4burst(2'b11) P.S, DD suggest 0x11*/
#define BIT_BURST_CNT(x)      (((u32)((x) & 0x00000003) << 2))
#define BIT_GET_BURST_CNT(x)  ((u32)(((x >> 2) & 0x00000003)))
#define BIT_DMA_MODE          ((u32)0x00000001 << 1)           /*!< R/W 0x0  For usb use dma mode; for pcie clr this bit ; for SDIO use Rx DMA Aggregation mode*/
/** @} */

/** @defgroup REG_C2H_PKT
  * @brief
  * @{
  */
#define BIT_R_C2H_PKT_REQ         ((u32)0x00000001 << 16)          /*!< R/W 0x0  C2h packet dma request*/
#define BIT_MASK_R_C2H_STR_ADDR   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  C2h packet start address*/
#define BIT_R_C2H_STR_ADDR(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_R_C2H_STR_ADDR(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/*==========REG_PAGE2 Register Address Definition==========*/
#define REG_RQPN_CTRL_HLPQ             0x200
#define REG_FIFOPAGE_INFO              0x204
#define REG_DWBCN0_CTRL                0x208
#define REG_TXDMA_OFFSET_CHK           0x20C
#define REG_TXDMA_STATUS               0x210
#define REG_RQPN_NPQ                   0x214
#define REG_TQPNT1                     0x218
#define REG_TQPNT2                     0x21C
#define REG_TDE_DEBUG                  0x220
#define REG_AUTO_LLT                   0x224
#define REG_DWBCN1_CTRL                0x228
#define REG_TX_ALIGNMENT_CTRL          0x22C
#define REG_RQPN_EXQ1_EXQ2             0x230
#define REG_TQPNT3_V1                  0x234
#define REG_H2C_HEAD                   0x244
#define REG_H2C_TAIL                   0x248
#define REG_H2C_READ_ADDR              0x24C
#define REG_H2C_WR_ADDR                0x250
#define REG_H2C_INFO                   0x254
#define REG_RXDMA_AGG_PG_TH            0x280
#define REG_RXPKT_NUM                  0x284
#define REG_RXDMA_STATUS               0x288
#define REG_RXDMA_DPR                  0x28C
#define REG_RXDMA_MODE                 0x290
#define REG_C2H_PKT                    0x294

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