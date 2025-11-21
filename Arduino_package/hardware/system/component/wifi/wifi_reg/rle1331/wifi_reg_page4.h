#ifndef _RL6955_REG_PAGE4_H_
#define _RL6955_REG_PAGE4_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_PAGE4
  * @brief REG_PAGE4 driver modules
  * @{
  */




/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_PAGE4_Register_Definitions REG_PAGE4 Register Definitions
  * @{
  */

/** @defgroup REG_Q0_INFO
  * @brief
  * @{
  */
#define BIT_MASK_TAIL_PKT_Q0     ((u32)0x000000FF << 24)           /*!< RO 0xFF  The LLT index of the last packet of QUEUE0.*/
#define BIT_TAIL_PKT_Q0(x)       (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_TAIL_PKT_Q0(x)   ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_HEAD_PKT_Q0     ((u32)0x000000FF << 16)           /*!< RO 0xFF  The LLT index of the first packet of QUEUE0.*/
#define BIT_HEAD_PKT_Q0(x)       (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_HEAD_PKT_Q0(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_PKT_NUM_Q0      ((u32)0x0000007F << 9)            /*!< RO 0x0  The total QUEUE0 pkt number in TxLLT*/
#define BIT_PKT_NUM_Q0(x)        (((u32)((x) & 0x0000007F) << 9))
#define BIT_GET_PKT_NUM_Q0(x)    ((u32)(((x >> 9) & 0x0000007F)))
#define BIT_MASK_QUEUEMACID_Q0   ((u32)0x0000007F << 2)            /*!< RO 0x0  MacID of head pkt*/
#define BIT_QUEUEMACID_Q0(x)     (((u32)((x) & 0x0000007F) << 2))
#define BIT_GET_QUEUEMACID_Q0(x) ((u32)(((x >> 2) & 0x0000007F)))
#define BIT_MASK_QUEUEAC_Q0      ((u32)0x00000003 << 0)            /*!< RO 0x0  AC type of QUEUE0*/
#define BIT_QUEUEAC_Q0(x)        (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_QUEUEAC_Q0(x)    ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_Q1_INFO
  * @brief
  * @{
  */
#define BIT_MASK_TAIL_PKT_Q1     ((u32)0x000000FF << 24)           /*!< RO 0xFF  The LLT index of the last packet of QUEUE1.*/
#define BIT_TAIL_PKT_Q1(x)       (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_TAIL_PKT_Q1(x)   ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_HEAD_PKT_Q1     ((u32)0x000000FF << 16)           /*!< RO 0xFF  The LLT index of the first packet of QUEUE1.*/
#define BIT_HEAD_PKT_Q1(x)       (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_HEAD_PKT_Q1(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_PKT_NUM_Q1      ((u32)0x0000007F << 9)            /*!< RO 0x0  The total QUEUE1 pkt number in TxLLT*/
#define BIT_PKT_NUM_Q1(x)        (((u32)((x) & 0x0000007F) << 9))
#define BIT_GET_PKT_NUM_Q1(x)    ((u32)(((x >> 9) & 0x0000007F)))
#define BIT_MASK_QUEUEMACID_Q1   ((u32)0x0000007F << 2)            /*!< RO 0x0  MacID of head pkt*/
#define BIT_QUEUEMACID_Q1(x)     (((u32)((x) & 0x0000007F) << 2))
#define BIT_GET_QUEUEMACID_Q1(x) ((u32)(((x >> 2) & 0x0000007F)))
#define BIT_MASK_QUEUEAC_Q1      ((u32)0x00000003 << 0)            /*!< RO 0x0  AC type of QUEUE1*/
#define BIT_QUEUEAC_Q1(x)        (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_QUEUEAC_Q1(x)    ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_Q2_INFO
  * @brief
  * @{
  */
#define BIT_MASK_TAIL_PKT_Q2     ((u32)0x000000FF << 24)           /*!< RO 0xFF  The LLT index of the last packet of QUEUE2.*/
#define BIT_TAIL_PKT_Q2(x)       (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_TAIL_PKT_Q2(x)   ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_HEAD_PKT_Q2     ((u32)0x000000FF << 16)           /*!< RO 0xFF  The LLT index of the first packet of QUEUE2.*/
#define BIT_HEAD_PKT_Q2(x)       (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_HEAD_PKT_Q2(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_PKT_NUM_Q2      ((u32)0x0000007F << 9)            /*!< RO 0x0  The total QUEUE1 pkt number in TxLLT*/
#define BIT_PKT_NUM_Q2(x)        (((u32)((x) & 0x0000007F) << 9))
#define BIT_GET_PKT_NUM_Q2(x)    ((u32)(((x >> 9) & 0x0000007F)))
#define BIT_MASK_QUEUEMACID_Q2   ((u32)0x0000007F << 2)            /*!< RO 0x0  MacID of head pkt*/
#define BIT_QUEUEMACID_Q2(x)     (((u32)((x) & 0x0000007F) << 2))
#define BIT_GET_QUEUEMACID_Q2(x) ((u32)(((x >> 2) & 0x0000007F)))
#define BIT_MASK_QUEUEAC_Q2      ((u32)0x00000003 << 0)            /*!< RO 0x0  AC type of QUEUE2*/
#define BIT_QUEUEAC_Q2(x)        (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_QUEUEAC_Q2(x)    ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_Q3_INFO
  * @brief
  * @{
  */
#define BIT_MASK_TAIL_PKT_Q3     ((u32)0x000000FF << 24)           /*!< RO 0xFF  The LLT index of the last packet of QUEUE3.*/
#define BIT_TAIL_PKT_Q3(x)       (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_TAIL_PKT_Q3(x)   ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_HEAD_PKT_Q3     ((u32)0x000000FF << 16)           /*!< RO 0xFF  The LLT index of the first packet of QUEUE3.*/
#define BIT_HEAD_PKT_Q3(x)       (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_HEAD_PKT_Q3(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_PKT_NUM_Q3      ((u32)0x0000007F << 9)            /*!< RO 0x0  The total QUEUE1 pkt number in TxLLT*/
#define BIT_PKT_NUM_Q3(x)        (((u32)((x) & 0x0000007F) << 9))
#define BIT_GET_PKT_NUM_Q3(x)    ((u32)(((x >> 9) & 0x0000007F)))
#define BIT_MASK_QUEUEMACID_Q3   ((u32)0x0000007F << 2)            /*!< RO 0x0  MacID of head pkt*/
#define BIT_QUEUEMACID_Q3(x)     (((u32)((x) & 0x0000007F) << 2))
#define BIT_GET_QUEUEMACID_Q3(x) ((u32)(((x >> 2) & 0x0000007F)))
#define BIT_MASK_QUEUEAC_Q3      ((u32)0x00000003 << 0)            /*!< RO 0x0  AC type of QUEUE3*/
#define BIT_QUEUEAC_Q3(x)        (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_QUEUEAC_Q3(x)    ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_Q4_INFO
  * @brief
  * @{
  */
#define BIT_MASK_TAIL_PKT_Q4     ((u32)0x000000FF << 24)           /*!< RO 0xFF  The LLT index of the last packet of QUEUE4.*/
#define BIT_TAIL_PKT_Q4(x)       (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_TAIL_PKT_Q4(x)   ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_HEAD_PKT_Q4     ((u32)0x000000FF << 16)           /*!< RO 0xFF  The LLT index of the first packet of QUEUE4.*/
#define BIT_HEAD_PKT_Q4(x)       (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_HEAD_PKT_Q4(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_PKT_NUM_Q4      ((u32)0x0000007F << 9)            /*!< RO 0x0  The total QUEUE4 pkt number in TxLLT*/
#define BIT_PKT_NUM_Q4(x)        (((u32)((x) & 0x0000007F) << 9))
#define BIT_GET_PKT_NUM_Q4(x)    ((u32)(((x >> 9) & 0x0000007F)))
#define BIT_MASK_QUEUEMACID_Q4   ((u32)0x0000007F << 2)            /*!< RO 0x0  MacID of head pkt*/
#define BIT_QUEUEMACID_Q4(x)     (((u32)((x) & 0x0000007F) << 2))
#define BIT_GET_QUEUEMACID_Q4(x) ((u32)(((x >> 2) & 0x0000007F)))
#define BIT_MASK_QUEUEAC_Q4      ((u32)0x00000003 << 0)            /*!< RO 0x0  AC type of QUEUE4*/
#define BIT_QUEUEAC_Q4(x)        (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_QUEUEAC_Q4(x)    ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_Q5_INFO
  * @brief
  * @{
  */
#define BIT_MASK_TAIL_PKT_Q5     ((u32)0x000000FF << 24)           /*!< RO 0xFF  The LLT index of the last packet of QUEUE5.*/
#define BIT_TAIL_PKT_Q5(x)       (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_TAIL_PKT_Q5(x)   ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_HEAD_PKT_Q5     ((u32)0x000000FF << 16)           /*!< RO 0xFF  The LLT index of the first packet of QUEUE5.*/
#define BIT_HEAD_PKT_Q5(x)       (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_HEAD_PKT_Q5(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_PKT_NUM_Q5      ((u32)0x0000007F << 9)            /*!< RO 0x0  The total QUEUE5 pkt number in TxLLT*/
#define BIT_PKT_NUM_Q5(x)        (((u32)((x) & 0x0000007F) << 9))
#define BIT_GET_PKT_NUM_Q5(x)    ((u32)(((x >> 9) & 0x0000007F)))
#define BIT_MASK_QUEUEMACID_Q5   ((u32)0x0000007F << 2)            /*!< RO 0x0  MacID of head pkt*/
#define BIT_QUEUEMACID_Q5(x)     (((u32)((x) & 0x0000007F) << 2))
#define BIT_GET_QUEUEMACID_Q5(x) ((u32)(((x >> 2) & 0x0000007F)))
#define BIT_MASK_QUEUEAC_Q5      ((u32)0x00000003 << 0)            /*!< RO 0x0  AC type of QUEUE5*/
#define BIT_QUEUEAC_Q5(x)        (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_QUEUEAC_Q5(x)    ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_Q6_INFO
  * @brief
  * @{
  */
#define BIT_MASK_TAIL_PKT_Q6     ((u32)0x000000FF << 24)           /*!< RO 0xFF  The LLT index of the last packet of QUEUE6.*/
#define BIT_TAIL_PKT_Q6(x)       (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_TAIL_PKT_Q6(x)   ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_HEAD_PKT_Q6     ((u32)0x000000FF << 16)           /*!< RO 0xFF  The LLT index of the first packet of QUEUE6.*/
#define BIT_HEAD_PKT_Q6(x)       (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_HEAD_PKT_Q6(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_PKT_NUM_Q6      ((u32)0x0000007F << 9)            /*!< RO 0x0  The total QUEUE6 pkt number in TxLLT*/
#define BIT_PKT_NUM_Q6(x)        (((u32)((x) & 0x0000007F) << 9))
#define BIT_GET_PKT_NUM_Q6(x)    ((u32)(((x >> 9) & 0x0000007F)))
#define BIT_MASK_QUEUEMACID_Q6   ((u32)0x0000007F << 2)            /*!< RO 0x0  MacID of head pkt*/
#define BIT_QUEUEMACID_Q6(x)     (((u32)((x) & 0x0000007F) << 2))
#define BIT_GET_QUEUEMACID_Q6(x) ((u32)(((x >> 2) & 0x0000007F)))
#define BIT_MASK_QUEUEAC_Q6      ((u32)0x00000003 << 0)            /*!< RO 0x0  AC type of QUEUE6*/
#define BIT_QUEUEAC_Q6(x)        (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_QUEUEAC_Q6(x)    ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_Q7_INFO
  * @brief
  * @{
  */
#define BIT_MASK_TAIL_PKT_Q7     ((u32)0x000000FF << 24)           /*!< RO 0xFF  The LLT index of the last packet of QUEUE7.*/
#define BIT_TAIL_PKT_Q7(x)       (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_TAIL_PKT_Q7(x)   ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_HEAD_PKT_Q7     ((u32)0x000000FF << 16)           /*!< RO 0xFF  The LLT index of the first packet of QUEUE7.*/
#define BIT_HEAD_PKT_Q7(x)       (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_HEAD_PKT_Q7(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_PKT_NUM_Q7      ((u32)0x0000007F << 9)            /*!< RO 0x0  The total QUEUE7 pkt number in TxLLT*/
#define BIT_PKT_NUM_Q7(x)        (((u32)((x) & 0x0000007F) << 9))
#define BIT_GET_PKT_NUM_Q7(x)    ((u32)(((x >> 9) & 0x0000007F)))
#define BIT_MASK_QUEUEMACID_Q7   ((u32)0x0000007F << 2)            /*!< RO 0x0  MacID of head pkt*/
#define BIT_QUEUEMACID_Q7(x)     (((u32)((x) & 0x0000007F) << 2))
#define BIT_GET_QUEUEMACID_Q7(x) ((u32)(((x >> 2) & 0x0000007F)))
#define BIT_MASK_QUEUEAC_Q7      ((u32)0x00000003 << 0)            /*!< RO 0x0  AC type of QUEUE7*/
#define BIT_QUEUEAC_Q7(x)        (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_QUEUEAC_Q7(x)    ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_MGQ_INFO
  * @brief
  * @{
  */
#define BIT_MASK_TAIL_PKT_MGQ     ((u32)0x000000FF << 24)           /*!< RO 0xFF  The LLT index of the last packet of MGQ.*/
#define BIT_TAIL_PKT_MGQ(x)       (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_TAIL_PKT_MGQ(x)   ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_HEAD_PKT_MGQ     ((u32)0x000000FF << 16)           /*!< RO 0xFF  The LLT index of the first packet of MGQ.*/
#define BIT_HEAD_PKT_MGQ(x)       (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_HEAD_PKT_MGQ(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_PKT_NUM_MGQ      ((u32)0x0000007F << 9)            /*!< RO 0x0  The total MGQ pkt number in TxLLT*/
#define BIT_PKT_NUM_MGQ(x)        (((u32)((x) & 0x0000007F) << 9))
#define BIT_GET_PKT_NUM_MGQ(x)    ((u32)(((x >> 9) & 0x0000007F)))
#define BIT_MASK_QUEUEMACID_MGQ   ((u32)0x0000007F << 2)            /*!< RO 0x0  MacID of head pkt*/
#define BIT_QUEUEMACID_MGQ(x)     (((u32)((x) & 0x0000007F) << 2))
#define BIT_GET_QUEUEMACID_MGQ(x) ((u32)(((x >> 2) & 0x0000007F)))
#define BIT_MASK_QUEUEAC_MGQ      ((u32)0x00000003 << 0)            /*!< RO 0x0  AC type of MGQ*/
#define BIT_QUEUEAC_MGQ(x)        (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_QUEUEAC_MGQ(x)    ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_HGQ_INFO
  * @brief
  * @{
  */
#define BIT_MASK_TAIL_PKT_HGQ     ((u32)0x000000FF << 24)           /*!< RO 0xFF  The LLT index of the last packet of HGQ.*/
#define BIT_TAIL_PKT_HGQ(x)       (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_TAIL_PKT_HGQ(x)   ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_HEAD_PKT_HGQ     ((u32)0x000000FF << 16)           /*!< RO 0xFF  The LLT index of the first packet of HGQ.*/
#define BIT_HEAD_PKT_HGQ(x)       (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_HEAD_PKT_HGQ(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_PKT_NUM_HGQ      ((u32)0x0000007F << 9)            /*!< RO 0x0  The total HGQ pkt number in TxLLT*/
#define BIT_PKT_NUM_HGQ(x)        (((u32)((x) & 0x0000007F) << 9))
#define BIT_GET_PKT_NUM_HGQ(x)    ((u32)(((x >> 9) & 0x0000007F)))
#define BIT_MASK_QUEUEMACID_HGQ   ((u32)0x0000007F << 2)            /*!< RO 0x0  MacID of head pkt*/
#define BIT_QUEUEMACID_HGQ(x)     (((u32)((x) & 0x0000007F) << 2))
#define BIT_GET_QUEUEMACID_HGQ(x) ((u32)(((x >> 2) & 0x0000007F)))
#define BIT_MASK_QUEUEAC_HGQ      ((u32)0x00000003 << 0)            /*!< RO 0x0  AC type of HGQ*/
#define BIT_QUEUEAC_HGQ(x)        (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_QUEUEAC_HGQ(x)    ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_QUE_EMPTY_STOP
  * @brief
  * @{
  */
#define BIT_RDQ_EMPTY   ((u32)0x00000001 << 21) /*!< RO 0x1  When this bit is raised, RDQ queue is empty. Report by MAC.*/
#define BIT_EVTQ_EMPTY  ((u32)0x00000001 << 20) /*!< RO 0x1  When this bit is raised, EVTQ queue is empty. Report by MAC.*/
#define BIT_BCNQ1_EMPTY ((u32)0x00000001 << 19) /*!< RO 0x1  When this bit is raised, beacon queue of PORT2 sync beacon / PORT2 disc beacon empty.*/
#define BIT_BCNQ0_EMPTY ((u32)0x00000001 << 18) /*!< RO 0x1  When this bit is raised, beacon queue of PORT1 SoftAP beacon  is empty.*/
#define BIT_HGQ_EMPTY   ((u32)0x00000001 << 17) /*!< RO 0x1  When this bit is raised, HGQ queue is empty. Report by MAC.*/
#define BIT_MGQ_EMPTY   ((u32)0x00000001 << 16) /*!< RO 0x1  When this bit is raised, MGQ queue is empty. Report by MAC.*/
#define BIT_AC7Q_EMPTY  ((u32)0x00000001 << 15) /*!< RO 0x1  When this bit is raised, AC7 queue is empty. Report by MAC.*/
#define BIT_AC6Q_EMPTY  ((u32)0x00000001 << 14) /*!< RO 0x1  When this bit is raised, AC6 queue is empty. Report by MAC.*/
#define BIT_AC5Q_EMPTY  ((u32)0x00000001 << 13) /*!< RO 0x1  When this bit is raised, AC5 queue is empty. Report by MAC.*/
#define BIT_AC4Q_EMPTY  ((u32)0x00000001 << 12) /*!< RO 0x1  When this bit is raised, AC4 queue is empty. Report by MAC.*/
#define BIT_AC3Q_EMPTY  ((u32)0x00000001 << 11) /*!< RO 0x1  When this bit is raised, AC3 queue is empty. Report by MAC.*/
#define BIT_AC2Q_EMPTY  ((u32)0x00000001 << 10) /*!< RO 0x1  When this bit is raised, AC2 queue is empty. Report by MAC.*/
#define BIT_AC1Q_EMPTY  ((u32)0x00000001 << 9)  /*!< RO 0x1  When this bit is raised, AC1 queue is empty. Report by MAC.*/
#define BIT_AC0Q_EMPTY  ((u32)0x00000001 << 8)  /*!< RO 0x1  When this bit is raised, AC0 queue is empty. Report by MAC.*/
#define BIT_AC7Q_STOP   ((u32)0x00000001 << 7)  /*!< RO 0x0  When this bit is raised, AC7 queue is stop. Report by MAC.*/
#define BIT_AC6Q_STOP   ((u32)0x00000001 << 6)  /*!< RO 0x0  When this bit is raised, AC6 queue is stop. Report by MAC.*/
#define BIT_AC5Q_STOP   ((u32)0x00000001 << 5)  /*!< RO 0x0  When this bit is raised, AC5 queue is stop. Report by MAC.*/
#define BIT_AC4Q_STOP   ((u32)0x00000001 << 4)  /*!< RO 0x0  When this bit is raised, AC4 queue is stop. Report by MAC.*/
#define BIT_AC3Q_STOP   ((u32)0x00000001 << 3)  /*!< RO 0x0  When this bit is raised, AC3 queue is stop. Report by MAC.*/
#define BIT_AC2Q_STOP   ((u32)0x00000001 << 2)  /*!< RO 0x0  When this bit is raised, AC2 queue is stop. Report by MAC.*/
#define BIT_AC1Q_STOP   ((u32)0x00000001 << 1)  /*!< RO 0x0  When this bit is raised, AC1 queue is stop. Report by MAC.*/
#define BIT_AC0Q_STOP   ((u32)0x00000001 << 0)  /*!< RO 0x0  When this bit is raised, AC0 queue is stop. Report by MAC.*/
/** @} */

/** @defgroup REG_PTCL_TB_CTRL
  * @brief
  * @{
  */
#define BIT_EN_DL_BCNQ0         ((u32)0x00000001 << 31) /*!< R/W 0x0  1: ptcl consider there is bcn pkt in TXBUF when bcn pkt first be transferd in; 0: mask bcn pkt num in bcn queue*/
#define BIT_EN_DL_BCNQ1         ((u32)0x00000001 << 30) /*!< R/W 0x0  1: ptcl consider there is bcn pkt in TXBUF when bcn pkt first be transferd in; 0: mask bcn pkt num in bcn queue*/
#define BIT_BCNQ_PKT_REL_EN     ((u32)0x00000001 << 29) /*!< R/W 0x0  If this bit is set, the BCN pkt will be set to non-valid after BCN TX.*/
#define BIT_CLR_REQ_REL_BCNQ_EN ((u32)0x00000001 << 28) /*!< R/W 0x0  If this bit is set, the BCN pkt will be set to non-valid when scheduler clear TX BCN CMD even non-TX.*/
#define BIT_FORCE_RND_PRI       ((u32)0x00000001 << 27) /*!< R/W 0x0  queue select priority control 1:old round robin method 0:depend on last selected queue*/
#define BIT_EN_FOUR_QUEUE       ((u32)0x00000001 << 26) /*!< R/W 0x0  1: Enable 88C 4AC Mode 0: Enable 8723 ACQ0~7 Mode*/
#define BIT_MGQ_DEL_EN          ((u32)0x00000001 << 25) /*!< R/W 0x0  1: MGQ packet will be dropped when enable macid delete function; 0: MGQ packet cannot be dropped*/
#define BIT_HGQ_DEL_EN          ((u32)0x00000001 << 24) /*!< R/W 0x0  1: HGQ packet will be dropped when enable macid delete function; 0: HGQ packet cannot be dropped*/
#define BIT_MOREDATA_BYPASS     ((u32)0x00000001 << 23) /*!< R/W 0x0  For HGQ moredata field. 1: bypass txdesc.moredata bit*/
#define BIT_EN_STATUS_TRIPKT    ((u32)0x00000001 << 22) /*!< R/W 0x1  */
#define BIT_EN_PKTIN_TRIPKT     ((u32)0x00000001 << 21) /*!< R/W 0x0  If trigger frame is transmitted into txpktbuf, HW generates interrupt 1: Enable 0: Disable*/
#define BIT_EVTQ_DEL_EN         ((u32)0x00000001 << 17) /*!< R/W 0x0  1: EVTQ packet will be dropped when enable macid delete function; 0: EVTQ packet cannot be dropped*/
#define BIT_DIS_BLOCK_PKTIN     ((u32)0x00000001 << 16) /*!< R/W 0x1  1: allow different macid+ac packet assigned to same ACQ queue*/
#define BIT_EN_HTC_RATE_ADPT    ((u32)0x00000001 << 15) /*!< R/W 0x1  1: if tx data rate fallback to CCK/OFDM rate, HW will remove HTC field in mac header*/
#define BIT_EN_ONLY_TB_HTC      ((u32)0x00000001 << 14) /*!< R/W 0x0  1: only TB can carry HTC field*/
#define BIT_EN_CTRL_HTC         ((u32)0x00000001 << 13) /*!< R/W 0x0  1: rts/cts2s/cts2ap/bar will carry HTC field by ctrl_wrapper frame, valid when txdesc.HTC = 1 0: rts/cts2s/cts2ap/bar will NOT carry HTC field even though txdesc.HTC = 1*/
#define BIT_IGNORE_QOS_NULL     ((u32)0x00000001 << 12) /*!< R/W 0x0  1: will not TX QoS Null when rx Basic trigger*/
#define BIT_CHK_TB_AGG          ((u32)0x00000001 << 7)  /*!< R/W 0x0  When this bit is set, check agg_max_num and agg_max_time*/
#define BIT_DIS_CHK_TB_AC       ((u32)0x00000001 << 6)  /*!< R/W 0x1  When this bit is set, don't care the AC of DATA*/
#define BIT_EN_TB_PRETX         ((u32)0x00000001 << 5)  /*!< R/W 0x1  When this bit is set, enable pretx function of TB PPDU, assert txen before gen_cmd_rdy.*/
#define BIT_EN_UPD_TB_RETRY     ((u32)0x00000001 << 4)  /*!< R/W 0x1  enable write retrybit in MH and add retrycnt when TB PPDU TX fail.*/
#define BIT_EN_TB_SIFS_BK       ((u32)0x00000001 << 3)  /*!< R/W 0x1  If sifs_timeout_tb_ref (from trxptcl) asserted, break the aggr process of TB PPDU*/
#define BIT_EN_PKTIN_CPUMGQ_INT ((u32)0x00000001 << 2)  /*!< R/W 0x0  If cpumgq pktin, HW generates pktin interrupt 1: Enable 0: Disable*/
#define BIT_TB_BYPASS_TXPOWER   ((u32)0x00000001 << 1)  /*!< R/W 0x0  1: NOT abort TB PPDU even the txpwr_abort_tx_idx(from txpwr_ctrl) is illegal 0: enable tx power abort TB*/
#define BIT_TB_DEL_EN           ((u32)0x00000001 << 0)  /*!< R/W 0x0  Enable TB PPDU packet delete: 1) pkt_ageout; 2) macid_delete*/
/** @} */

/** @defgroup REG_BCNQ_ADDR0
  * @brief
  * @{
  */
#define BIT_MASK_BCNQ_ADDR0   ((u32)0xFFFFFFFF << 0)           /*!< R/WPD 0x0  The address of beacon frame in host memory. For SoftAP beacon(P1) Generate a pulse to inform the update of ADDR*/
#define BIT_BCNQ_ADDR0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BCNQ_ADDR0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BCNQ_ADDR1
  * @brief
  * @{
  */
#define BIT_MASK_BCNQ_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/WPD 0x0  The address of beacon frame in host memory. For NAN sync Beacon (P2, 2.4G and 5G) and NAN Disc Beacon (P2)  Generate a pulse to inform the update of ADDR*/
#define BIT_BCNQ_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BCNQ_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_AMPDU_CTRL
  * @brief
  * @{
  */
#define BIT_EN_PRE_TX_CMD              ((u32)0x00000001 << 31)           /*!< R/W 0x1  enable pre tx cmd to use aggr more packet*/
#define BIT_MAX_PRETX_AGGR_EN          ((u32)0x00000001 << 30)           /*!< R/W 0x1  1: enable PRETX function, default is enable 0: disable PRETX function*/
#define BIT_MASK_MAX_PRETX_AGGR_TIME   ((u32)0x000007FF << 19)           /*!< R/W 0x64  If BIT_PRETX_AGGR_EN = 1, the bits will count down after PHYTXON signal asserting every transmission in pre-tx mode.(Default: 23F, mac_clk = 20MHz, 3us;Smart,mac_clk = 40MHz, 3.5us)*/
#define BIT_MAX_PRETX_AGGR_TIME(x)     (((u32)((x) & 0x000007FF) << 19))
#define BIT_GET_MAX_PRETX_AGGR_TIME(x) ((u32)(((x >> 19) & 0x000007FF)))
#define BIT_MASK_TRY_PKT_LMT           ((u32)0x0000003F << 10)           /*!< R/W 0x1  aggr packet limit  valid when Try_rate of txdesc or ctrl_info is 1*/
#define BIT_TRY_PKT_LMT(x)             (((u32)((x) & 0x0000003F) << 10))
#define BIT_GET_TRY_PKT_LMT(x)         ((u32)(((x >> 10) & 0x0000003F)))
#define BIT_EN_WAIT_TXDESC_WDONE       ((u32)0x00000001 << 9)            /*!< R/W 0x0  1: wait write txdesc done before assert set_cmd_p*/
#define BIT_SINGLE_AMPDU_EN            ((u32)0x00000001 << 8)            /*!< R/W 0x0  If this bit is set, Enable single sub-frame APMDU.*/
#define BIT_EN_A_CTRL_BREAK            ((u32)0x00000001 << 7)            /*!< R/W 0x1  1: break the AGGR process when the a_ctrl field in TXDESC is different*/
#define BIT_EN_RTY_BK_COD              ((u32)0x00000001 << 6)            /*!< R/W 0x0  AMPDU aggregation mode with retry MPDUs and new MPDUs. When this bit is enabled, if new MPDU's data rate is not the same as retry MPDUs' fallback data rate, the aggregation will be broken.*/
#define BIT_EN_RETRY_BK                ((u32)0x00000001 << 5)            /*!< R/W 0x1  AMPDU aggregation mode with retry MPDUs and new MPDUs. When this bit is clear enabled, an AMPDU aggregates retried MPDU and new MPDU. All the aggregation criteria is still the same with normal AMPDU operation.*/
#define BIT_USE_INI_RATE               ((u32)0x00000001 << 4)            /*!< R/W 0x0  0: If Txdesc's USE RATE = 0 and this field is equal to 0, the datarate of TXRPT SRAM is used as tx pkt's datarate. (ECO flow) 1: TXInfo's datarate is used as tx pkt's datarate.*/
#define BIT_RTS_NAV_BK                 ((u32)0x00000001 << 3)            /*!< R/W 0x0  Control The RTS NAV criteria for TX. When this bit is clear, TX may aggregates only according to the number of MPDUs existing in the TXPKTBUF, the limit of aggregation size and number, and also the break time.  When this bit is set, TX will be under the RTS NAV criteria. No excess RTS NAV is allowed.*/
#define BIT_DIS_SSN_CHECK              ((u32)0x00000001 << 2)            /*!< R/W 0x0  Disable checker the SSN rule when generating AMPDU TX cmd.*/
#define BIT_MACID_MATCH_RTS            ((u32)0x00000001 << 1)            /*!< R/W 0x0  Enable the packet that follow the RTS have same MACID*/
#define BIT_BMC_NAV_PROTECT            ((u32)0x00000001 << 0)            /*!< R/W 0x1  Enable the NAV protection when transmit broadcast/multicast*/
/** @} */

/** @defgroup REG_AMPDU_MAX_LENGTH
  * @brief
  * @{
  */
#define BIT_MASK_AGGR_MAX_NUM      ((u32)0x0000003F << 24)           /*!< R/W 0x14  the maximum aggregation packet number limit*/
#define BIT_AGGR_MAX_NUM(x)        (((u32)((x) & 0x0000003F) << 24))
#define BIT_GET_AGGR_MAX_NUM(x)    ((u32)(((x >> 24) & 0x0000003F)))
#define BIT_MASK_AMPDU_MAX_TIME    ((u32)0x000000FF << 16)           /*!< R/W 0x64  AMPDU duration limit in the unit of 32us.*/
#define BIT_AMPDU_MAX_TIME(x)      (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_AMPDU_MAX_TIME(x)  ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_AGGR_MAX_LENGTH   ((u32)0x0000FFFF << 0)            /*!< R/W 0xFFFF  AMPDU length limit, unit:128Byte*/
#define BIT_AGGR_MAX_LENGTH(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_AGGR_MAX_LENGTH(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_FREE_TAIL_SIFS
  * @brief
  * @{
  */
#define BIT_MASK_FW_FREE_TAIL          ((u32)0x000000FF << 24)           /*!< RO 0x0  Real-time Free Tail LLT_index Number*/
#define BIT_FW_FREE_TAIL(x)            (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_FW_FREE_TAIL(x)        ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_SPEC_SIFS_OFDM_PTCL   ((u32)0x000000FF << 8)            /*!< R/W 0x10  The spec SIFS value for duration calculation*/
#define BIT_SPEC_SIFS_OFDM_PTCL(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_SPEC_SIFS_OFDM_PTCL(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_SPEC_SIFS_CCK_PTCL    ((u32)0x000000FF << 0)            /*!< R/W 0x0A  The spec SIFS value for duration calculation*/
#define BIT_SPEC_SIFS_CCK_PTCL(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_SPEC_SIFS_CCK_PTCL(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_TXBF_CTRL
  * @brief
  * @{
  */
#define BIT_ENABLE_NDPA                 ((u32)0x00000001 << 31)           /*!< R/W 0x0  Set '1' for MAC to enable sending NDPA or NDP Announcement MPDU*/
#define BIT_MASK_NDPA_RATE              ((u32)0x0000003F << 24)           /*!< R/W 0x04  NDPA tx rate setting, from CCK 1M to HE NSS1 MCS9*/
#define BIT_NDPA_RATE(x)                (((u32)((x) & 0x0000003F) << 24))
#define BIT_GET_NDPA_RATE(x)            ((u32)(((x >> 24) & 0x0000003F)))
#define BIT_NDPA_BW                     ((u32)0x00000001 << 17)           /*!< R/W 0x0  NDPA bandwidth setting 1: 40M 0: 20M*/
#define BIT_MU_SND_FLAG                 ((u32)0x00000001 << 16)           /*!< R/W 0x0  indicate the MU Beamforming, used for verification. Assert when the packet is MU-NDPA or BFRP*/
#define BIT_MASK_SPE_FRAME_INDICATION   ((u32)0x00000007 << 13)           /*!< R/W 0x0  indicate some specific frame, used for verification.  Co-work with TXDESC.RAW and MU_SND_FLAG. 000: not specified 001: BFRP (VHT MU BF) 100: TF MU-RTS 101: TF-BFRP (HE MU BF) 111: OTHER Trigger Frame*/
#define BIT_SPE_FRAME_INDICATION(x)     (((u32)((x) & 0x00000007) << 13))
#define BIT_GET_SPE_FRAME_INDICATION(x) ((u32)(((x >> 13) & 0x00000007)))
#define BIT_DIS_NDP_BFEN                ((u32)0x00000001 << 12)           /*!< R/W 0x1  1: disable beamforming with NDP*/
#define BIT_TXBCN_NOBLOCK_NDP           ((u32)0x00000001 << 11)           /*!< R/W 0x1  beacon packet will not block NDP packet*/
#define BIT_TXBF0_40M_EN                ((u32)0x00000001 << 10)           /*!< R/W 0x0  TxBF status of beamformee0 xBW=40M*/
#define BIT_TXBF0_20M_EN                ((u32)0x00000001 << 9)            /*!< R/W 0x0  TxBF status of beamformee0 xBW=20M*/
#define BIT_MASK_TXBF0_TXAID            ((u32)0x000001FF << 0)            /*!< R/W 0x0  P_AID[8:0] of the associated beamformee0*/
#define BIT_TXBF0_TXAID(x)              (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_TXBF0_TXAID(x)          ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_DUP_CTRL
  * @brief
  * @{
  */
#define BIT_EN_DATA_DUP  ((u32)0x00000001 << 1) /*!< R/W 0x0  1: enable data duplicate x CCK/OFDM rate*/
#define BIT_EN_CCK_NONHT ((u32)0x00000001 << 0) /*!< R/W 0x0  1: enable signaling TA or duplicate of CCK rate*/
/** @} */

/** @defgroup REG_PTCL_CTN_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_DATA_RETRY_UNIT    ((u32)0x00000003 << 30)           /*!< R/W 0x1  indicate the unit of ctrl_info/txdesc data_retry_limit 0: unit=1 1: unit=2*/
#define BIT_DATA_RETRY_UNIT(x)      (((u32)((x) & 0x00000003) << 30))
#define BIT_GET_DATA_RETRY_UNIT(x)  ((u32)(((x >> 30) & 0x00000003)))
#define BIT_MASK_RTS_RETRY_UNIT     ((u32)0x00000003 << 28)           /*!< R/W 0x1  indicate the unit of ctrl_info/txdesc rts_retry_limit 0: unit=1 1: unit=2 2: unit=4*/
#define BIT_RTS_RETRY_UNIT(x)       (((u32)((x) & 0x00000003) << 28))
#define BIT_GET_RTS_RETRY_UNIT(x)   ((u32)(((x >> 28) & 0x00000003)))
#define BIT_MASK_TXSC_IN_40M        ((u32)0x00000003 << 26)           /*!< R/W 0x0  Value of Data frame Tx sub-carrier mode 40MHz*/
#define BIT_TXSC_IN_40M(x)          (((u32)((x) & 0x00000003) << 26))
#define BIT_GET_TXSC_IN_40M(x)      ((u32)(((x >> 26) & 0x00000003)))
#define BIT_MASK_TXSC_IN_20M        ((u32)0x00000003 << 24)           /*!< R/W 0x0  Value of Data frame Tx sub-carrier mode 20MHz*/
#define BIT_TXSC_IN_20M(x)          (((u32)((x) & 0x00000003) << 24))
#define BIT_GET_TXSC_IN_20M(x)      ((u32)(((x >> 24) & 0x00000003)))
#define BIT_TXRTS_IN_TXOP           ((u32)0x00000001 << 23)           /*!< R/W 0x0  1: can tx rts in txop*/
#define BIT_DATA_RTY_OVER_DROP      ((u32)0x00000001 << 22)           /*!< R/W 0x0  1: only drop when data retry over 0: drop when data or rts retry over*/
#define BIT_EN_PTCL_GCLK            ((u32)0x00000001 << 21)           /*!< R/W 0x1  1: enable clock gating*/
#define BIT_GI_LTF_FB_SEL           ((u32)0x00000001 << 20)           /*!< R/W 0x0  0: no GI_LTF fallback 1: GI_LTF fallback option 1 enabled (downgrade GI_LTF first from init. rate)*/
#define BIT_CHECK_CCK_EN            ((u32)0x00000001 << 19)           /*!< R/W 0x0  If this bit is set, HW check Tx pkt's data rate. When data rate is CCK rate, modify the rate to NON_CCK_RATE.*/
#define BIT_RTS_LIMIT_IN_OFDM       ((u32)0x00000001 << 18)           /*!< R/W 0x0  Rts rate will not down to cck rate*/
#define BIT_EN_RTYBIT               ((u32)0x00000001 << 17)           /*!< R/W 0x1  1: update Retry Bit in mac header 0: Disable*/
#define BIT_USE_DATA_BW             ((u32)0x00000001 << 16)           /*!< R/W 0x0  1 : Use des2_data_bw for this packet 0 : when des1_cca_rts = 2'b10, update_bw depend on ch_bw_status*/
#define BIT_MASK_CFEND_TXTIME       ((u32)0x000001FF << 6)            /*!< R/W 0x34  Cfend packet txtime bit[8:0]*/
#define BIT_CFEND_TXTIME(x)         (((u32)((x) & 0x000001FF) << 6))
#define BIT_GET_CFEND_TXTIME(x)     ((u32)(((x >> 6) & 0x000001FF)))
#define BIT_MASK_BASIC_CFEND_RATE   ((u32)0x0000003F << 0)            /*!< R/W 0x04  The initial rate for basic CFEND frame transmitted as EDCA originator. The response control frame shall be selected by the definition of 802.11n. OFDM6M*/
#define BIT_BASIC_CFEND_RATE(x)     (((u32)((x) & 0x0000003F) << 0))
#define BIT_GET_BASIC_CFEND_RATE(x) ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_CTN_BREAK_CFG
  * @brief
  * @{
  */
#define BIT_EN_USE_PRETX_BREAK     ((u32)0x00000001 << 8)           /*!< R/W 0x0  1: use max_pretx_aggr_break to replace sifs_break when en_pretx_cmd, for longer gen_cmd time*/
#define BIT_MASK_CTN_BUS_TIMEOUT   ((u32)0x000000FF << 0)           /*!< R/W 0x3C  when sifs_bk or max_pretx_aggr_break occurs during FETCH_TXDESC, wait bus respond, timeout will break early unit: 1T mac_clk, default 16T*/
#define BIT_CTN_BUS_TIMEOUT(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_CTN_BUS_TIMEOUT(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_DATA_RATE_REPT
  * @brief
  * @{
  */
#define BIT_MASK_DATA_RATE_REP_TIME1_4TH   ((u32)0x00000007 << 28)           /*!< R/W 0x0  DATA1 indicate the number of repetitions of the rate after 3rd rate fallback 0: repeat 1 time 1: repeat 2 times 2: repeat 4 times 3: repeat 8 times 4: repeat 16 times*/
#define BIT_DATA_RATE_REP_TIME1_4TH(x)     (((u32)((x) & 0x00000007) << 28))
#define BIT_GET_DATA_RATE_REP_TIME1_4TH(x) ((u32)(((x >> 28) & 0x00000007)))
#define BIT_MASK_DATA_RATE_REP_TIME1_3RD   ((u32)0x0000000F << 24)           /*!< R/W 0x01  DATA1. selected by ctrl_info  The number of repetitions of the third rate*/
#define BIT_DATA_RATE_REP_TIME1_3RD(x)     (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_DATA_RATE_REP_TIME1_3RD(x) ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_DATA_RATE_REP_TIME1_2ND   ((u32)0x0000000F << 20)           /*!< R/W 0x01  DATA1. selected by ctrl_info  The number of repetitions of the second rate*/
#define BIT_DATA_RATE_REP_TIME1_2ND(x)     (((u32)((x) & 0x0000000F) << 20))
#define BIT_GET_DATA_RATE_REP_TIME1_2ND(x) ((u32)(((x >> 20) & 0x0000000F)))
#define BIT_MASK_DATA_RATE_REP_TIME1_1ST   ((u32)0x0000000F << 16)           /*!< R/W 0x01  DATA1. selected by ctrl_info  The number of repetitions of the first rate*/
#define BIT_DATA_RATE_REP_TIME1_1ST(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_DATA_RATE_REP_TIME1_1ST(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_DATA_RATE_REP_TIME0_4TH   ((u32)0x00000007 << 12)           /*!< R/W 0x0  DATA0 indicate the number of repetitions of the rate after 3rd rate fallback 0: repeat 1 time 1: repeat 2 times 2: repeat 4 times 3: repeat 8 times 4: repeat 16 times*/
#define BIT_DATA_RATE_REP_TIME0_4TH(x)     (((u32)((x) & 0x00000007) << 12))
#define BIT_GET_DATA_RATE_REP_TIME0_4TH(x) ((u32)(((x >> 12) & 0x00000007)))
#define BIT_MASK_DATA_RATE_REP_TIME0_3RD   ((u32)0x0000000F << 8)            /*!< R/W 0x01  DATA0 The number of repetitions of the third rate*/
#define BIT_DATA_RATE_REP_TIME0_3RD(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_DATA_RATE_REP_TIME0_3RD(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_DATA_RATE_REP_TIME0_2ND   ((u32)0x0000000F << 4)            /*!< R/W 0x01  DATA0 The number of repetitions of the second rate*/
#define BIT_DATA_RATE_REP_TIME0_2ND(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_DATA_RATE_REP_TIME0_2ND(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_DATA_RATE_REP_TIME0_1ST   ((u32)0x0000000F << 0)            /*!< R/W 0x01  DATA0 The number of repetitions of the first rate*/
#define BIT_DATA_RATE_REP_TIME0_1ST(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_DATA_RATE_REP_TIME0_1ST(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_RATE_REPT
  * @brief
  * @{
  */
#define BIT_MASK_CTRL_RATE_REP_TIME_4TH   ((u32)0x00000007 << 12)           /*!< R/W 0x0  RTA_CTS2S indicate the number of repetitions of the rate after 3rd rate fallback 0: repeat 1 time 1: repeat 2 times 2: repeat 4 times 3: repeat 8 times 4: repeat 16 times*/
#define BIT_CTRL_RATE_REP_TIME_4TH(x)     (((u32)((x) & 0x00000007) << 12))
#define BIT_GET_CTRL_RATE_REP_TIME_4TH(x) ((u32)(((x >> 12) & 0x00000007)))
#define BIT_MASK_CTRL_RATE_REP_TIME_3RD   ((u32)0x0000000F << 8)            /*!< R/W 0x01  RTS/CTS2S The number of repetitions of the third rate*/
#define BIT_CTRL_RATE_REP_TIME_3RD(x)     (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_CTRL_RATE_REP_TIME_3RD(x) ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_CTRL_RATE_REP_TIME_2ND   ((u32)0x0000000F << 4)            /*!< R/W 0x01  RTS/CTS2S The number of repetitions of the second rate*/
#define BIT_CTRL_RATE_REP_TIME_2ND(x)     (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_CTRL_RATE_REP_TIME_2ND(x) ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_CTRL_RATE_REP_TIME_1ST   ((u32)0x0000000F << 0)            /*!< R/W 0x01  RTS/CTS2S The number of repetitions of the first rate*/
#define BIT_CTRL_RATE_REP_TIME_1ST(x)     (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_CTRL_RATE_REP_TIME_1ST(x) ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_DATA_RATE_MASK0
  * @brief
  * @{
  */
#define BIT_MASK_DATA_RATE_MASK_TABLE_0   ((u32)0x003FFFFF << 0)           /*!< R/W 0x0  Data Auto Rate Fallback Table Register 0, indexed by fb_mask_idx in TXDESC. Each bit is mapped as the following:  Bit[0:3] = {1M, 2M, 5.5M, 11M } Bit[4:11] = {6M, 9M, 12M, 18M, 24M, 36M, 48M, 54M} Bit[12:21] = HT/VHT/HE MCS0~MCS9*/
#define BIT_DATA_RATE_MASK_TABLE_0(x)     (((u32)((x) & 0x003FFFFF) << 0))
#define BIT_GET_DATA_RATE_MASK_TABLE_0(x) ((u32)(((x >> 0) & 0x003FFFFF)))
/** @} */

/** @defgroup REG_DATA_RATE_MASK1
  * @brief
  * @{
  */
#define BIT_MASK_DATA_RATE_MASK_TABLE_1   ((u32)0x003FFFFF << 0)           /*!< R/W 0x0  Data Auto Rate Fallback Table Register 1, indexed by fb_mask_idx in TXDESC. Each bit is mapped as the following:  Bit[0:3] = {1M, 2M, 5.5M, 11M } Bit[4:11] = {6M, 9M, 12M, 18M, 24M, 36M, 48M, 54M} Bit[12:21] = HT/VHT/HE MCS0~MCS9*/
#define BIT_DATA_RATE_MASK_TABLE_1(x)     (((u32)((x) & 0x003FFFFF) << 0))
#define BIT_GET_DATA_RATE_MASK_TABLE_1(x) ((u32)(((x >> 0) & 0x003FFFFF)))
/** @} */

/** @defgroup REG_DATA_RATE_MASK2
  * @brief
  * @{
  */
#define BIT_MASK_DATA_RATE_MASK_TABLE_2   ((u32)0x003FFFFF << 0)           /*!< R/W 0x0  Data Auto Rate Fallback Table Register 2, indexed by fb_mask_idx in TXDESC. Each bit is mapped as the following:  Bit[0:3] = {1M, 2M, 5.5M, 11M } Bit[4:11] = {6M, 9M, 12M, 18M, 24M, 36M, 48M, 54M} Bit[12:21] = HT/VHT/HE MCS0~MCS9*/
#define BIT_DATA_RATE_MASK_TABLE_2(x)     (((u32)((x) & 0x003FFFFF) << 0))
#define BIT_GET_DATA_RATE_MASK_TABLE_2(x) ((u32)(((x >> 0) & 0x003FFFFF)))
/** @} */

/** @defgroup REG_DATA_RATE_MASK3
  * @brief
  * @{
  */
#define BIT_MASK_DATA_RATE_MASK_TABLE_3   ((u32)0x003FFFFF << 0)           /*!< R/W 0x0  Data Auto Rate Fallback Table Register 3, indexed by fb_mask_idx in TXDESC. Each bit is mapped as the following:  Bit[0:3] = {1M, 2M, 5.5M, 11M } Bit[4:11] = {6M, 9M, 12M, 18M, 24M, 36M, 48M, 54M} Bit[12:21] = HT/VHT/HE MCS0~MCS9*/
#define BIT_DATA_RATE_MASK_TABLE_3(x)     (((u32)((x) & 0x003FFFFF) << 0))
#define BIT_GET_DATA_RATE_MASK_TABLE_3(x) ((u32)(((x >> 0) & 0x003FFFFF)))
/** @} */

/** @defgroup REG_CTRL_RATE_MASK
  * @brief
  * @{
  */
#define BIT_MASK_CTRL_RATE_MASK_TABLE   ((u32)0x003FFFFF << 0)           /*!< R/W 0x0  CTRL(RTS/CTS2S) Auto Rate Fallback Table Register. Each bit is mapped as the following:  Bit[0:3] = {1M, 2M, 5.5M, 11M } Bit[4:11] = {6M, 9M, 12M, 18M, 24M, 36M, 48M, 54M} Bit[12:21] = HT/VHT/HE MCS0~MCS9*/
#define BIT_CTRL_RATE_MASK_TABLE(x)     (((u32)((x) & 0x003FFFFF) << 0))
#define BIT_GET_CTRL_RATE_MASK_TABLE(x) ((u32)(((x >> 0) & 0x003FFFFF)))
/** @} */

/** @defgroup REG_TXRPT_CTRL
  * @brief
  * @{
  */
#define BIT_EN_FTMRPT             ((u32)0x00000001 << 23)           /*!< R/W 0x1  When this bit asserted, HW will report FTM rpt*/
#define BIT_RD_FTMT2R_ERR         ((u32)0x00000001 << 22)           /*!< RW1C 0x0  Indicates the timeout error in FTM t2r report*/
#define BIT_MASK_TXRPT_NUM_THRS   ((u32)0x0000000F << 16)           /*!< R/W 0x01  if the number of txrpt exceeds the threshold,then assert txrpt interrupts*/
#define BIT_TXRPT_NUM_THRS(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_TXRPT_NUM_THRS(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_TXRPT_DIS             ((u32)0x00000001 << 15)           /*!< R/W 0x0  when this bit is enabled, HW will not generate txrpt for driver's fixed rate packets*/
#define BIT_DIS_TXFAIL_RPT        ((u32)0x00000001 << 14)           /*!< R/W 0x1  when this bit is enabled, HW will not generate txrpt for tx failed packets*/
#define BIT_EN_BCN_TRXRPT         ((u32)0x00000001 << 12)           /*!< R/W 0x1  when this bit is enabled, HW will generate txrpt for BCN*/
#define BIT_MASK_TXRPT_QUEUE_EN   ((u32)0x000001FF << 0)            /*!< R/W 0x3F  1: HW will report tx_status  0: no report BIT0: BK Queue BIT1: BE Queue BIT2: VI Queue BIT3: VO Queue BIT4: MGT Queue BIT5: HG Queue BIT6: BCN Queue BIT7: TB Queue BIT8: EVENT QUEUE*/
#define BIT_TXRPT_QUEUE_EN(x)     (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_TXRPT_QUEUE_EN(x) ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_PRE_PTA_CTRL
  * @brief
  * @{
  */
#define BIT_PTA_WL_PRI_MASK_RDQ       ((u32)0x00000001 << 31)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has RDQ packet*/
#define BIT_PTA_WL_PRI_MASK_EVTQ      ((u32)0x00000001 << 30)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has EVTQ packet*/
#define BIT_PTA_WL_PRI_MASK_BCNQ      ((u32)0x00000001 << 29)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has BCNQ packet*/
#define BIT_PTA_WL_PRI_MASK_MGQ       ((u32)0x00000001 << 28)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has MGQ packet*/
#define BIT_PTA_WL_PRI_MASK_HGQ       ((u32)0x00000001 << 27)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has HGQ packet*/
#define BIT_PTA_WL_PRI_MASK_BK        ((u32)0x00000001 << 26)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has BKQ packet*/
#define BIT_PTA_WL_PRI_MASK_BE        ((u32)0x00000001 << 25)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has BEQ packet*/
#define BIT_PTA_WL_PRI_MASK_VI        ((u32)0x00000001 << 24)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has VIQ packet*/
#define BIT_PTA_WL_PRI_MASK_VO        ((u32)0x00000001 << 23)          /*!< R/W 0x0  PTCL send wl_pri to PTA when pktbuf has VOQ packet*/
#define BIT_PTA_WL_TX_EN              ((u32)0x00000001 << 22)          /*!< R/W 0x0  enable WL PTA (should be set in init MAC)*/
#define BIT_PTA_EDCCA_EN              ((u32)0x00000001 << 21)          /*!< R/W 0x0  0 : wl_tx signal to PTA does not consider EDCCA 1 : wl_tx signal to PTA consider EDCCA*/
#define BIT_EN_GNT_BT_AWAKE           ((u32)0x00000001 << 17)          /*!< R/W 0x1  Enable pollute bit function.(C card ECO item, modify hardware circuit and add two options) 0: Disable 1: Enable When (GNT_BT option/LTE_RX option/(GNT_WL==0)) == 1, retry count can't increase if Tx fail.  One or more packets will record in polluted bit field of txreport when txreport generates in Tx ok or tx drop.*/
#define BIT_EN_BT_POLLUTE_RX          ((u32)0x00000001 << 16)          /*!< R/W 0x1  enable write BT Polluted field during RX RESP*/
#define BIT_MASK_BT_POLLUTE_PKT_CNT   ((u32)0x00000FFF << 0)           /*!< RWC 0x0  count the tx fail pkt caused by bt pollute, write 0x46C[11] will clear the counter*/
#define BIT_BT_POLLUTE_PKT_CNT(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_BT_POLLUTE_PKT_CNT(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_PROT_MODE_CTRL
  * @brief
  * @{
  */
#define BIT_EN_TXOP_BASE_RTS          ((u32)0x00000001 << 31)           /*!< R/W 0x0  enable TXOP duration-based RTS/CTS*/
#define BIT_MASK_RTS_TXOP_THRS        ((u32)0x000003FF << 21)           /*!< R/W 0x0  unit:32us, valid when BIT_EN_TXOP_BASE_RTS = 1*/
#define BIT_RTS_TXOP_THRS(x)          (((u32)((x) & 0x000003FF) << 21))
#define BIT_GET_RTS_TXOP_THRS(x)      ((u32)(((x >> 21) & 0x000003FF)))
#define BIT_MASK_RTS_PKTTIME_THRS     ((u32)0x000000FF << 8)            /*!< R/W 0x1  RTS packet txtime threshold, unit is 64 us*/
#define BIT_RTS_PKTTIME_THRS(x)       (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_RTS_PKTTIME_THRS(x)   ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_RTS_PKTLENGTH_THRS   ((u32)0x000000FF << 0)            /*!< R/W 0x1  RTS packet Length threshold, unit is 128 bytes*/
#define BIT_RTS_PKTLENGTH_THRS(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_RTS_PKTLENGTH_THRS(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_BAR_MODE_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_COLLISION_DETECT_TIME   ((u32)0x0000000F << 24)           /*!< R/W 0xF  0~15: The field indicated collision detect time for broadcast or Beacon packet.(unit: us)*/
#define BIT_COLLISION_DETECT_TIME(x)     (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_COLLISION_DETECT_TIME(x) ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_MASK_BAR_RTYLMT              ((u32)0x00000003 << 16)           /*!< R/W 0x2  BAR retry limit*/
#define BIT_BAR_RTYLMT(x)                (((u32)((x) & 0x00000003) << 16))
#define BIT_GET_BAR_RTYLMT(x)            ((u32)(((x >> 16) & 0x00000003)))
#define BIT_MASK_BAR_PKTTIME_THRS        ((u32)0x000000FF << 8)            /*!< R/W 0xFF  BAR packet time thrs*/
#define BIT_BAR_PKTTIME_THRS(x)          (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_BAR_PKTTIME_THRS(x)      ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_BAR_PKTNUM_THRS         ((u32)0x0000007F << 0)            /*!< R/W 0x7F  BAR Pktnum Thrs*/
#define BIT_BAR_PKTNUM_THRS(x)           (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_BAR_PKTNUM_THRS(x)       ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_MACID_DROP
  * @brief
  * @{
  */
#define BIT_MASK_MACID_DROP   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Macid31~Macid0 Drop (per bit controlled)*/
#define BIT_MACID_DROP(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MACID_DROP(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MACID_PAUSE
  * @brief
  * @{
  */
#define BIT_MASK_MACID_PAUSE   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  Macid31~Macid 0 Packet Sleep. (per bit controlled)*/
#define BIT_MACID_PAUSE(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MACID_PAUSE(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MACID_RLS
  * @brief
  * @{
  */
#define BIT_MASK_MACID_RELEASE   ((u32)0xFFFFFFFF << 0)           /*!< R/WP/ES 0x0  Macid31~Macid0 Release(per bit controlled)*/
#define BIT_MACID_RELEASE(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MACID_RELEASE(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MACID_PAUSE_RLS
  * @brief
  * @{
  */
#define BIT_MACID_RLS_SEL_ONE       ((u32)0x00000001 << 31)          /*!< R/W 0x0  1: will TX MPDU during macid_release_mode 0: can TX AMPDU during macid_release_mode*/
#define BIT_MASK_MACID_OFFSET       ((u32)0x0000001F << 8)           /*!< R/WPD 0x0  write this field to set REG_macid_release[macid_offset] = macid_value*/
#define BIT_MACID_OFFSET(x)         (((u32)((x) & 0x0000001F) << 8))
#define BIT_GET_MACID_OFFSET(x)     ((u32)(((x >> 8) & 0x0000001F)))
#define BIT_MACID_VALUE             ((u32)0x00000001 << 7)           /*!< R/WPD 0x0  write this field to set REG_macid_release[macid_offset] = macid_value*/
#define BIT_DIS_MACID_RELEASE_RTY   ((u32)0x00000001 << 3)           /*!< R/W 0x0  when release one packet for a macid, retry should happen on the same ACQ. Set 1 to remove this requirement*/
#define BIT_EN_SET_MOREDATA         ((u32)0x00000001 << 2)           /*!< R/W 0x1  1: Enable HW set the more data bit of the PKT that MACID release function tx. 0: Disable HW set the more data bit of the PKT that MACID release function tx.*/
#define BIT_DIS_CLEAR_MACID_RELEASE ((u32)0x00000001 << 1)           /*!< R/W 0x0  1: HW No clear MACID Release bit after release the pkt. 0: HW will clear MACID Release bit after release the pkt.*/
#define BIT_MACID_RELEASE_EN        ((u32)0x00000001 << 0)           /*!< R/W 0x1  1: Enable MACID Release function. (same as MACID DROP) 0: Disable MACID Release function.*/
/** @} */

/** @defgroup REG_HW_SEQ0
  * @brief
  * @{
  */
#define BIT_MASK_HW_SSN_SEQ0   ((u32)0x00000FFF << 16)           /*!< R/W/ES 0x0  When TXDESC HWSEQEN is set, MAC will overwrite SEQ control by this register. Before DRV hand over the SEQ control to HW, DRV may set the current SEQ to this register. When DRV will take back the SEQ control from HW, DRV may get the current sequence from this register.*/
#define BIT_HW_SSN_SEQ0(x)     (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_HW_SSN_SEQ0(x) ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_EN_HWSSN      ((u32)0x000001FF << 0)            /*!< R/W 0x0  HW update the SSN [6:0], When this bit enable and EN_HWSEQ of TXDESC, MAC will overwrite MACHDR SEQ according to TXDESC QSEL [0] BIT_HWSEQ_VO_EN [1] BIT_HWSEQ_VI_EN [2] BIT_HWSEQ_BE_EN [3] BIT_HWSEQ_BK_EN [4] BIT_HWSEQ_MGT_EN [5] BIT_HWSEQ_HGQ_EN [6] BIT_HWSEQ_BCN_EN,don't care  EN_HWSEQ of TXDESC [7] BIT_HWSEQ_TBQ_EN [8] BIT_HWSEQ_EVTQ_EN*/
#define BIT_EN_HWSSN(x)        (((u32)((x) & 0x000001FF) << 0))
#define BIT_GET_EN_HWSSN(x)    ((u32)(((x >> 0) & 0x000001FF)))
/** @} */

/** @defgroup REG_HW_SEQ1_2
  * @brief
  * @{
  */
#define BIT_MASK_HW_SSN_SEQ2   ((u32)0x00000FFF << 16)           /*!< R/W/ES 0x0  When TXDESC HWSEQEN is set, MAC will overwrite SEQ control by this register. Before DRV hand over the SEQ control to HW, DRV may set the current SEQ to this register. When DRV will take back the SEQ control from HW, DRV may get the current sequence from this register.*/
#define BIT_HW_SSN_SEQ2(x)     (((u32)((x) & 0x00000FFF) << 16))
#define BIT_GET_HW_SSN_SEQ2(x) ((u32)(((x >> 16) & 0x00000FFF)))
#define BIT_MASK_HW_SSN_SEQ1   ((u32)0x00000FFF << 0)            /*!< R/W/ES 0x0  When TXDESC HWSEQEN is set, MAC will overwrite SEQ control by this register. Before DRV hand over the SEQ control to HW, DRV may set the current SEQ to this register. When DRV will take back the SEQ control from HW, DRV may get the current sequence from this register.*/
#define BIT_HW_SSN_SEQ1(x)     (((u32)((x) & 0x00000FFF) << 0))
#define BIT_GET_HW_SSN_SEQ1(x) ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup REG_PTCL_STATUS
  * @brief
  * @{
  */
#define BIT_MASK_PTCL_TOTAL_PKT      ((u32)0x000000FF << 24)           /*!< RO 0x0  Total Packet in LLT*/
#define BIT_PTCL_TOTAL_PKT(x)        (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_PTCL_TOTAL_PKT(x)    ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_TXLLT_FULL               ((u32)0x00000001 << 23)           /*!< RO 0x0  indicate TXLLT is full*/
#define BIT_MASK_TXBD_TOTAL_PKT      ((u32)0x0000007F << 16)           /*!< RO 0x0  Total Packet in TXBD FIFO*/
#define BIT_TXBD_TOTAL_PKT(x)        (((u32)((x) & 0x0000007F) << 16))
#define BIT_GET_TXBD_TOTAL_PKT(x)    ((u32)(((x >> 16) & 0x0000007F)))
#define BIT_RD_TXHANG_ERR            ((u32)0x00000001 << 15)           /*!< RW1C 0x0  Indicates the txhang error: no tx in 0xFFFF cycle*/
#define BIT_RD_STATUS_ERR            ((u32)0x00000001 << 14)           /*!< RW1C 0x0  Indicates the status error: get invalid page (NULL PKT)*/
#define BIT_RD_CTN_ERR               ((u32)0x00000001 << 13)           /*!< RW1C 0x0  Indicates the cnt error: get invalid page (NULL PKT)*/
#define BIT_RD_PKTIN_ERR_2           ((u32)0x00000001 << 12)           /*!< RW1C 0x0  Indicates the pktin error: get invalid page (NULL PKT)*/
#define BIT_RD_PKTIN_ERR_1           ((u32)0x00000001 << 11)           /*!< RW1C 0x0  Indicates the pktin error: total page error*/
#define BIT_RD_PKTIN_ERR_0           ((u32)0x00000001 << 10)           /*!< RW1C 0x0  Indicates the pktin error: assign to invalid queue (queue_idx = 0)*/
#define BIT_RD_TXRPT_FULL            ((u32)0x00000001 << 9)            /*!< RW1C 0x0  indicates the txrpt buffer is full*/
#define BIT_RLS_FIFO_FULL_DRV        ((u32)0x00000001 << 7)            /*!< RO 0x0  indicate TXRLS FIFO for driver is full*/
#define BIT_RLS_FIFO_ALMOST_FULL_DRV ((u32)0x00000001 << 6)            /*!< RO 0x0  indicate TXRLS FIFO for driver is almost full*/
#define BIT_RLS_FIFO_FULL_FW         ((u32)0x00000001 << 5)            /*!< RO 0x0  indicate TXRLS FIFO for fw is full*/
#define BIT_RLS_FIFO_ALMOST_FULL_FW  ((u32)0x00000001 << 4)            /*!< RO 0x0  indicate TXRLS FIFO for fw is almost full*/
#define BIT_RTS_DATA_SEP             ((u32)0x00000001 << 2)            /*!< R/W 0x1  1:rts retry cnt & retry limit calculate separately*/
#define BIT_TX_NULL_1                ((u32)0x00000001 << 1)            /*!< RO 0x0  Port 0/1 Tx Null 1 packet ok indicator*/
#define BIT_TX_NULL_0                ((u32)0x00000001 << 0)            /*!< RO 0x0  Port 0/1 Tx Null 0 packet ok indicator*/
/** @} */

/** @defgroup REG_TXPKT_STATISTIC
  * @brief
  * @{
  */
#define BIT_MASK_TXPKT_CNT_SEL       ((u32)0x0000000F << 28)           /*!< R/W 0x0  Select the counter to show in 0X14A0 BIT_TXPKT_CNT_RPT. 0: r_TX_OK_RTY0 1: r_TX_OK_RTY1 2: r_TX_OK_RTY2 3: r_TX_OK_RTY3 4: r_TX_OK_RTY4 5: r_RTY_DROP 6: r_BMC_TXOK 7: r_TOTAL_PKT_CNT*/
#define BIT_TXPKT_CNT_SEL(x)         (((u32)((x) & 0x0000000F) << 28))
#define BIT_GET_TXPKT_CNT_SEL(x)     ((u32)(((x >> 28) & 0x0000000F)))
#define BIT_MASK_REF_MACID           ((u32)0x0000000F << 24)           /*!< R/W 0xF  if BIT_REF_MACID = 0xF, count all eligible frames and ignore MACID; else, only count the frames whose MACID = BIT_REF_MACID BMC packet ignore MACID.*/
#define BIT_REF_MACID(x)             (((u32)((x) & 0x0000000F) << 24))
#define BIT_GET_REF_MACID(x)         ((u32)(((x >> 24) & 0x0000000F)))
#define BIT_TX_CNT_CLR               ((u32)0x00000001 << 23)           /*!< R/W 0x0  Write 1 to clear the counters.*/
#define BIT_DIS_FW_RLS_FIFO_STOP_MGQ ((u32)0x00000001 << 13)           /*!< R/W 0x0  1: don't clear ptcl_mgq_has_pkt when FW release FIFO is full.*/
#define BIT_MASK_TXPKT_CNT_RPT       ((u32)0x00001FFF << 0)            /*!< RO 0x0  The results of TXPKT counter. Depends on BIT_TXPKT_CNT_SEL.*/
#define BIT_TXPKT_CNT_RPT(x)         (((u32)((x) & 0x00001FFF) << 0))
#define BIT_GET_TXPKT_CNT_RPT(x)     ((u32)(((x >> 0) & 0x00001FFF)))
/** @} */

/** @defgroup REG_PMAC_CTRL
  * @brief
  * @{
  */
#define BIT_MASK_MP_TXNUM_THRES   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  threshold for the number of times a frame can be transferred. If the TX counter reaches the BIT_MP_TXNUM_THRES, stop TX*/
#define BIT_MP_TXNUM_THRES(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_MP_TXNUM_THRES(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_PMAC_TXCNT       ((u32)0x00000FFF << 8)            /*!< RO 0x0  tx statistic during PMAC*/
#define BIT_PMAC_TXCNT(x)         (((u32)((x) & 0x00000FFF) << 8))
#define BIT_GET_PMAC_TXCNT(x)     ((u32)(((x >> 8) & 0x00000FFF)))
#define BIT_MP_TEST_EN_REL        ((u32)0x00000001 << 1)            /*!< RO 0x0  1: indicates that it is during the PMAC TX period*/
#define BIT_MP_TEST_EN            ((u32)0x00000001 << 0)            /*!< R/W 0x0  1: Enable PMAC function, for MP test 0: stop PMAC function*/
/** @} */

/** @defgroup REG_TXBD_TXRPT_RW_PTR
  * @brief
  * @{
  */
#define BIT_MASK_TXRPT_FIFO_R_PTR   ((u32)0x000000FF << 24)           /*!< RO 0x0  read pointer of TXRPT FIFO*/
#define BIT_TXRPT_FIFO_R_PTR(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_TXRPT_FIFO_R_PTR(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_TXRPT_FIFO_W_PTR   ((u32)0x000000FF << 16)           /*!< RO 0x0  write pointer of TXRPT FIFO*/
#define BIT_TXRPT_FIFO_W_PTR(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_TXRPT_FIFO_W_PTR(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_TXBD_R_PTR_HW      ((u32)0x0000007F << 8)            /*!< RO 0x0  read pointer of TXBD FIFO*/
#define BIT_TXBD_R_PTR_HW(x)        (((u32)((x) & 0x0000007F) << 8))
#define BIT_GET_TXBD_R_PTR_HW(x)    ((u32)(((x >> 8) & 0x0000007F)))
#define BIT_MASK_TXBD_W_PTR_SW      ((u32)0x0000007F << 0)            /*!< RO 0x0  write pointer of TXBD FIFO*/
#define BIT_TXBD_W_PTR_SW(x)        (((u32)((x) & 0x0000007F) << 0))
#define BIT_GET_TXBD_W_PTR_SW(x)    ((u32)(((x >> 0) & 0x0000007F)))
/** @} */

/** @defgroup REG_TXRLS_RW_PTR
  * @brief
  * @{
  */
#define BIT_MASK_RLS_FIFO_R_PTR_DRV   ((u32)0x000000FF << 24)           /*!< RO 0x0  read pointer of Driver TXRLS FIFO*/
#define BIT_RLS_FIFO_R_PTR_DRV(x)     (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_RLS_FIFO_R_PTR_DRV(x) ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_RLS_FIFO_W_PTR_DRV   ((u32)0x000000FF << 16)           /*!< RO 0x0  write pointer of Driver TXRLS FIFO*/
#define BIT_RLS_FIFO_W_PTR_DRV(x)     (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_RLS_FIFO_W_PTR_DRV(x) ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_RLS_FIFO_R_PTR_FW    ((u32)0x000000FF << 8)            /*!< RO 0x0  read pointer of FW TXRLS FIFO*/
#define BIT_RLS_FIFO_R_PTR_FW(x)      (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_RLS_FIFO_R_PTR_FW(x)  ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_RLS_FIFO_W_PTR_FW    ((u32)0x000000FF << 0)            /*!< RO 0x0  write pointer of FW TXRLS FIFO*/
#define BIT_RLS_FIFO_W_PTR_FW(x)      (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_RLS_FIFO_W_PTR_FW(x)  ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_EVTQ_INFO
  * @brief
  * @{
  */
#define BIT_MASK_TAIL_PKT_EVTQ     ((u32)0x000000FF << 24)           /*!< RO 0xFF  The LLT index of the last packet of EVTQ.*/
#define BIT_TAIL_PKT_EVTQ(x)       (((u32)((x) & 0x000000FF) << 24))
#define BIT_GET_TAIL_PKT_EVTQ(x)   ((u32)(((x >> 24) & 0x000000FF)))
#define BIT_MASK_HEAD_PKT_EVTQ     ((u32)0x000000FF << 16)           /*!< RO 0xFF  The LLT index of the first packet of EVTQ.*/
#define BIT_HEAD_PKT_EVTQ(x)       (((u32)((x) & 0x000000FF) << 16))
#define BIT_GET_HEAD_PKT_EVTQ(x)   ((u32)(((x >> 16) & 0x000000FF)))
#define BIT_MASK_PKT_NUM_EVTQ      ((u32)0x0000007F << 9)            /*!< RO 0x0  The total EVTQ pkt number in TxLLT*/
#define BIT_PKT_NUM_EVTQ(x)        (((u32)((x) & 0x0000007F) << 9))
#define BIT_GET_PKT_NUM_EVTQ(x)    ((u32)(((x >> 9) & 0x0000007F)))
#define BIT_MASK_QUEUEMACID_EVTQ   ((u32)0x0000007F << 2)            /*!< RO 0x0  MacID of head pkt*/
#define BIT_QUEUEMACID_EVTQ(x)     (((u32)((x) & 0x0000007F) << 2))
#define BIT_GET_QUEUEMACID_EVTQ(x) ((u32)(((x >> 2) & 0x0000007F)))
#define BIT_MASK_QUEUEAC_EVTQ      ((u32)0x00000003 << 0)            /*!< RO 0x0  AC type of EVTQ*/
#define BIT_QUEUEAC_EVTQ(x)        (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_QUEUEAC_EVTQ(x)    ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_RADAR_ADDR
  * @brief
  * @{
  */
#define BIT_MASK_RADAR_ADDR   ((u32)0xFFFFFFFF << 0)           /*!< R/WPD 0x0  The address of RADAR frame in host memory.  Generate a pulse to inform the update of ADDR*/
#define BIT_RADAR_ADDR(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_RADAR_ADDR(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_RADAR_CFG_PAGE4
  * @brief
  * @{
  */
#define BIT_CLR_RDQ_NUM ((u32)0x00000001 << 1) /*!< R/W 0x0  Clear rdq pkt number*/
#define BIT_RDQ_EN      ((u32)0x00000001 << 0) /*!< R/W 0x1  1: en rdq, can pktin*/
/** @} */

/*==========REG_PAGE4 Register Address Definition==========*/
#define REG_Q0_INFO                    0x400
#define REG_Q1_INFO                    0x404
#define REG_Q2_INFO                    0x408
#define REG_Q3_INFO                    0x40C
#define REG_Q4_INFO                    0x410
#define REG_Q5_INFO                    0x414
#define REG_Q6_INFO                    0x418
#define REG_Q7_INFO                    0x41C
#define REG_MGQ_INFO                   0x420
#define REG_HGQ_INFO                   0x424
#define REG_QUE_EMPTY_STOP             0x428
#define REG_PTCL_TB_CTRL               0x42C
#define REG_BCNQ_ADDR0                 0x430
#define REG_BCNQ_ADDR1                 0x434
#define REG_AMPDU_CTRL                 0x438
#define REG_AMPDU_MAX_LENGTH           0x43C
#define REG_FREE_TAIL_SIFS             0x440
#define REG_TXBF_CTRL                  0x444
#define REG_DUP_CTRL                   0x448
#define REG_PTCL_CTN_CTRL              0x44C
#define REG_CTN_BREAK_CFG              0x450
#define REG_DATA_RATE_REPT             0x454
#define REG_CTRL_RATE_REPT             0x458
#define REG_DATA_RATE_MASK0            0x45C
#define REG_DATA_RATE_MASK1            0x460
#define REG_DATA_RATE_MASK2            0x464
#define REG_DATA_RATE_MASK3            0x468
#define REG_CTRL_RATE_MASK             0x46C
#define REG_TXRPT_CTRL                 0x470
#define REG_PRE_PTA_CTRL               0x478
#define REG_PROT_MODE_CTRL             0x47C
#define REG_BAR_MODE_CTRL              0x480
#define REG_MACID_DROP                 0x484
#define REG_MACID_PAUSE                0x488
#define REG_MACID_RLS                  0x48C
#define REG_MACID_PAUSE_RLS            0x490
#define REG_HW_SEQ0                    0x494
#define REG_HW_SEQ1_2                  0x498
#define REG_PTCL_STATUS                0x49C
#define REG_TXPKT_STATISTIC            0x4A0
#define REG_PMAC_CTRL                  0x4A4
#define REG_TXBD_TXRPT_RW_PTR          0x4A8
#define REG_TXRLS_RW_PTR               0x4AC
#define REG_EVTQ_INFO                  0x4B0
#define REG_RADAR_ADDR                 0x4B4
#define REG_RADAR_CFG_PAGE4            0x4B8
#define REG_DUMMY_PAGE4                0x4FC

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