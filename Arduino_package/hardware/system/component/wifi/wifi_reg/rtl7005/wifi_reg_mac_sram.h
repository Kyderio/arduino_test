#ifndef _RL7005_REG_MAC_SRAM_H_
#define _RL7005_REG_MAC_SRAM_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup REG_MAC_SRAM
  * @brief REG_MAC_SRAM driver modules
  * @{
  */


/* AUTO_GEN_START */
// Do NOT modify any AUTO_GEN code below

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup REG_MAC_SRAM_Register_Definitions REG_MAC_SRAM Register Definitions
  * @{
  */

/** @defgroup REG_KEYCAM0_ENTRYx
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRYx_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRYx_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRYx_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRYx_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRYx_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRYx_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRYx_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRYx_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRYx_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRYx_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRYx_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRYx_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRYx_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRYx_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRYx_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRYx
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRYx_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRYx_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRYx_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRYx
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRYx_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRYx_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRYx_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRYx
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRYx_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRYx_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRYx_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRYx
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRYx_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRYx_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRYx_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRYx
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRYx_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRYx_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRYx_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRYx
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRYx_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRYx_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRYx_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY00
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY00_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY00_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY00_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY00_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY00_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY00_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY00_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY00_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY00_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY00_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY00_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY00_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY00_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY00_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY00_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY00
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY00_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY00_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY00_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY00
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY00_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY00_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY00_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY00
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY00_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY00_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY00_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY00
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY00_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY00_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY00_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY00
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY00_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY00_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY00_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY00
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY00_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY00_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY00_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY01
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY01_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY01_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY01_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY01_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY01_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY01_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY01_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY01_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY01_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY01_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY01_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY01_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY01_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY01_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY01_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY01
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY01_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY01_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY01_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY01
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY01_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY01_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY01_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY01
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY01_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY01_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY01_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY01
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY01_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY01_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY01_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY01
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY01_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY01_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY01_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY01
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY01_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY01_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY01_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY02
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY02_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY02_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY02_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY02_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY02_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY02_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY02_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY02_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY02_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY02_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY02_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY02_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY02_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY02_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY02_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY02
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY02_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY02_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY02_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY02
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY02_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY02_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY02_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY02
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY02_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY02_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY02_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY02
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY02_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY02_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY02_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY02
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY02_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY02_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY02_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY02
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY02_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY02_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY02_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY03
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY03_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY03_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY03_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY03_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY03_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY03_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY03_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY03_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY03_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY03_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY03_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY03_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY03_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY03_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY03_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY03
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY03_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY03_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY03_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY03
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY03_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY03_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY03_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY03
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY03_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY03_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY03_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY03
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY03_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY03_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY03_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY03
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY03_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY03_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY03_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY03
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY03_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY03_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY03_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY04
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY04_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY04_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY04_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY04_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY04_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY04_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY04_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY04_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY04_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY04_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY04_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY04_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY04_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY04_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY04_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY04
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY04_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY04_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY04_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY04
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY04_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY04_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY04_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY04
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY04_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY04_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY04_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY04
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY04_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY04_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY04_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY04
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY04_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY04_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY04_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY04
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY04_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY04_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY04_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY05
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY05_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY05_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY05_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY05_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY05_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY05_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY05_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY05_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY05_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY05_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY05_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY05_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY05_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY05_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY05_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY05
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY05_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY05_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY05_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY05
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY05_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY05_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY05_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY05
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY05_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY05_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY05_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY05
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY05_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY05_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY05_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY05
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY05_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY05_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY05_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY05
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY05_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY05_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY05_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY06
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY06_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY06_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY06_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY06_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY06_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY06_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY06_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY06_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY06_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY06_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY06_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY06_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY06_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY06_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY06_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY06
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY06_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY06_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY06_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY06
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY06_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY06_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY06_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY06
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY06_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY06_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY06_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY06
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY06_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY06_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY06_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY06
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY06_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY06_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY06_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY06
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY06_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY06_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY06_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY07
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY07_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY07_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY07_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY07_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY07_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY07_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY07_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY07_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY07_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY07_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY07_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY07_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY07_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY07_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY07_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY07
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY07_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY07_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY07_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY07
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY07_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY07_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY07_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY07
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY07_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY07_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY07_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY07
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY07_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY07_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY07_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY07
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY07_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY07_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY07_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY07
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY07_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY07_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY07_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY08
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY08_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY08_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY08_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY08_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY08_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY08_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY08_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY08_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY08_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY08_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY08_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY08_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY08_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY08_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY08_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY08
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY08_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY08_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY08_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY08
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY08_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY08_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY08_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY08
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY08_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY08_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY08_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY08
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY08_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY08_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY08_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY08
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY08_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY08_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY08_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY08
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY08_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY08_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY08_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY09
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY09_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY09_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY09_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY09_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY09_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY09_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY09_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY09_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY09_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY09_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY09_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY09_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY09_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY09_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY09_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY09
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY09_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY09_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY09_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY09
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY09_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY09_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY09_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY09
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY09_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY09_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY09_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY09
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY09_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY09_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY09_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY09
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY09_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY09_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY09_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY09
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY09_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY09_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY09_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY10
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY10_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY10_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY10_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY10_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY10_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY10_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY10_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY10_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY10_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY10_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY10_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY10_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY10_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY10_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY10_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY10
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY10_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY10_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY10_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY10
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY10_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY10_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY10_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY10
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY10_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY10_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY10_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY10
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY10_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY10_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY10_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY10
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY10_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY10_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY10_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY10
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY10_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY10_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY10_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY11
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY11_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY11_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY11_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY11_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY11_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY11_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY11_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY11_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY11_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY11_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY11_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY11_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY11_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY11_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY11_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY11
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY11_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY11_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY11_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY11
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY11_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY11_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY11_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY11
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY11_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY11_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY11_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY11
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY11_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY11_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY11_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY11
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY11_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY11_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY11_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY11
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY11_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY11_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY11_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY12
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY12_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY12_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY12_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY12_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY12_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY12_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY12_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY12_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY12_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY12_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY12_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY12_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY12_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY12_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY12_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY12
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY12_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY12_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY12_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY12
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY12_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY12_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY12_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY12
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY12_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY12_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY12_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY12
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY12_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY12_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY12_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY12
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY12_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY12_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY12_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY12
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY12_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY12_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY12_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY13
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY13_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY13_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY13_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY13_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY13_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY13_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY13_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY13_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY13_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY13_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY13_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY13_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY13_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY13_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY13_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY13
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY13_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY13_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY13_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY13
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY13_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY13_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY13_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY13
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY13_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY13_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY13_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY13
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY13_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY13_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY13_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY13
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY13_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY13_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY13_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY13
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY13_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY13_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY13_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY14
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY14_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY14_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY14_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY14_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY14_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY14_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY14_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY14_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY14_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY14_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY14_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY14_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY14_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY14_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY14_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY14
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY14_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY14_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY14_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY14
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY14_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY14_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY14_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY14
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY14_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY14_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY14_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY14
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY14_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY14_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY14_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY14
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY14_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY14_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY14_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY14
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY14_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY14_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY14_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY15
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY15_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY15_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY15_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY15_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY15_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY15_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY15_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY15_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY15_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY15_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY15_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY15_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY15_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY15_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY15_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY15
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY15_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY15_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY15_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY15
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY15_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY15_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY15_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY15
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY15_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY15_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY15_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY15
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY15_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY15_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY15_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY15
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY15_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY15_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY15_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY15
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY15_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY15_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY15_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY16
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY16_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY16_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY16_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY16_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY16_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY16_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY16_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY16_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY16_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY16_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY16_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY16_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY16_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY16_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY16_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY16
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY16_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY16_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY16_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY16
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY16_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY16_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY16_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY16
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY16_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY16_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY16_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY16
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY16_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY16_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY16_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY16
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY16_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY16_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY16_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY16
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY16_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY16_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY16_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY17
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY17_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY17_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY17_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY17_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY17_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY17_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY17_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY17_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY17_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY17_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY17_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY17_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY17_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY17_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY17_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY17
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY17_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY17_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY17_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY17
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY17_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY17_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY17_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY17
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY17_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY17_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY17_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY17
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY17_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY17_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY17_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY17
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY17_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY17_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY17_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY17
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY17_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY17_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY17_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY18
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY18_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY18_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY18_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY18_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY18_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY18_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY18_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY18_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY18_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY18_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY18_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY18_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY18_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY18_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY18_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY18
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY18_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY18_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY18_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY18
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY18_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY18_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY18_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY18
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY18_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY18_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY18_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY18
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY18_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY18_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY18_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY18
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY18_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY18_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY18_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY18
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY18_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY18_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY18_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY19
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY19_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY19_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY19_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY19_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY19_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY19_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY19_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY19_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY19_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY19_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY19_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY19_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY19_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY19_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY19_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY19
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY19_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY19_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY19_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY19
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY19_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY19_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY19_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY19
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY19_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY19_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY19_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY19
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY19_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY19_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY19_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY19
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY19_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY19_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY19_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY19
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY19_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY19_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY19_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY20
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY20_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY20_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY20_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY20_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY20_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY20_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY20_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY20_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY20_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY20_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY20_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY20_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY20_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY20_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY20_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY20
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY20_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY20_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY20_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY20
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY20_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY20_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY20_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY20
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY20_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY20_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY20_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY20
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY20_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY20_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY20_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY20
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY20_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY20_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY20_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY20
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY20_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY20_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY20_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY21
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY21_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY21_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY21_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY21_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY21_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY21_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY21_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY21_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY21_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY21_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY21_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY21_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY21_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY21_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY21_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY21
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY21_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY21_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY21_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY21
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY21_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY21_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY21_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY21
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY21_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY21_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY21_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY21
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY21_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY21_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY21_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY21
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY21_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY21_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY21_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY21
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY21_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY21_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY21_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY22
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY22_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY22_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY22_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY22_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY22_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY22_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY22_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY22_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY22_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY22_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY22_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY22_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY22_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY22_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY22_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY22
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY22_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY22_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY22_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY22
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY22_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY22_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY22_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY22
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY22_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY22_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY22_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY22
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY22_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY22_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY22_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY22
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY22_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY22_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY22_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY22
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY22_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY22_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY22_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY23
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY23_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY23_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY23_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY23_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY23_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY23_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY23_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY23_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY23_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY23_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY23_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY23_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY23_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY23_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY23_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY23
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY23_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY23_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY23_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY23
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY23_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY23_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY23_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY23
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY23_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY23_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY23_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY23
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY23_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY23_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY23_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY23
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY23_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY23_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY23_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY23
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY23_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY23_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY23_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY24
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY24_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY24_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY24_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY24_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY24_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY24_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY24_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY24_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY24_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY24_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY24_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY24_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY24_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY24_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY24_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY24
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY24_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY24_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY24_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY24
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY24_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY24_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY24_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY24
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY24_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY24_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY24_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY24
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY24_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY24_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY24_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY24
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY24_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY24_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY24_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY24
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY24_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY24_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY24_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY25
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY25_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY25_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY25_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY25_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY25_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY25_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY25_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY25_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY25_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY25_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY25_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY25_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY25_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY25_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY25_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY25
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY25_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY25_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY25_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY25
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY25_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY25_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY25_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY25
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY25_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY25_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY25_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY25
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY25_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY25_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY25_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY25
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY25_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY25_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY25_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY25
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY25_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY25_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY25_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY26
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY26_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY26_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY26_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY26_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY26_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY26_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY26_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY26_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY26_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY26_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY26_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY26_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY26_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY26_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY26_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY26
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY26_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY26_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY26_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY26
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY26_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY26_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY26_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY26
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY26_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY26_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY26_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY26
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY26_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY26_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY26_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY26
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY26_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY26_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY26_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY26
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY26_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY26_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY26_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY27
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY27_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY27_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY27_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY27_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY27_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY27_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY27_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY27_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY27_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY27_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY27_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY27_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY27_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY27_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY27_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY27
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY27_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY27_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY27_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY27
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY27_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY27_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY27_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY27
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY27_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY27_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY27_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY27
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY27_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY27_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY27_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY27
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY27_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY27_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY27_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY27
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY27_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY27_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY27_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY28
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY28_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY28_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY28_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY28_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY28_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY28_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY28_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY28_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY28_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY28_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY28_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY28_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY28_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY28_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY28_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY28
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY28_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY28_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY28_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY28
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY28_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY28_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY28_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY28
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY28_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY28_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY28_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY28
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY28_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY28_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY28_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY28
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY28_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY28_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY28_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY28
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY28_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY28_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY28_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY29
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY29_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY29_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY29_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY29_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY29_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY29_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY29_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY29_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY29_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY29_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY29_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY29_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY29_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY29_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY29_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY29
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY29_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY29_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY29_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY29
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY29_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY29_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY29_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY29
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY29_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY29_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY29_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY29
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY29_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY29_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY29_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY29
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY29_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY29_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY29_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY29
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY29_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY29_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY29_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY30
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY30_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY30_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY30_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY30_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY30_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY30_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY30_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY30_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY30_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY30_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY30_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY30_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY30_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY30_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY30_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY30
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY30_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY30_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY30_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY30
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY30_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY30_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY30_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY30
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY30_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY30_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY30_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY30
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY30_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY30_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY30_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY30
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY30_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY30_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY30_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY30
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY30_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY30_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY30_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_KEYCAM0_ENTRY31
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM0_ENTRY31_ADDR0       ((u32)0x0000FFFF << 16)           /*!< R/W 0x0  address[15:0]*/
#define BIT_KEYCAM0_ENTRY31_ADDR0(x)         (((u32)((x) & 0x0000FFFF) << 16))
#define BIT_GET_KEYCAM0_ENTRY31_ADDR0(x)     ((u32)(((x >> 16) & 0x0000FFFF)))
#define BIT_KEYCAM0_ENTRY31_VALID            ((u32)0x00000001 << 15)           /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY31_EXTTYPE          ((u32)0x00000001 << 9)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY31_REPEATER_MODE    ((u32)0x00000001 << 8)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY31_MGNT             ((u32)0x00000001 << 7)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY31_GRPKEY_BIT       ((u32)0x00000001 << 6)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY31_MICKEY_BIT       ((u32)0x00000001 << 5)            /*!< R/W 0x0  */
#define BIT_MASK_KEYCAM0_ENTRY31_TYPE        ((u32)0x00000007 << 2)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY31_TYPE(x)          (((u32)((x) & 0x00000007) << 2))
#define BIT_GET_KEYCAM0_ENTRY31_TYPE(x)      ((u32)(((x >> 2) & 0x00000007)))
#define BIT_MASK_KEYCAM0_ENTRY31_KEYID_BIT   ((u32)0x00000003 << 0)            /*!< R/W 0x0  */
#define BIT_KEYCAM0_ENTRY31_KEYID_BIT(x)     (((u32)((x) & 0x00000003) << 0))
#define BIT_GET_KEYCAM0_ENTRY31_KEYID_BIT(x) ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_KEYCAM1_ENTRY31
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM1_ENTRY31_ADDR1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  address[47:16]*/
#define BIT_KEYCAM1_ENTRY31_ADDR1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM1_ENTRY31_ADDR1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM2_ENTRY31
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM2_ENTRY31_KEY0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[31:0]*/
#define BIT_KEYCAM2_ENTRY31_KEY0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM2_ENTRY31_KEY0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM3_ENTRY31
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM3_ENTRY31_KEY1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[63:32]*/
#define BIT_KEYCAM3_ENTRY31_KEY1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM3_ENTRY31_KEY1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM4_ENTRY31
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM4_ENTRY31_KEY2   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[95:64]*/
#define BIT_KEYCAM4_ENTRY31_KEY2(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM4_ENTRY31_KEY2(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM5_ENTRY31
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM5_ENTRY31_KEY3   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  key[127:96]*/
#define BIT_KEYCAM5_ENTRY31_KEY3(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_KEYCAM5_ENTRY31_KEY3(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_KEYCAM6_ENTRY31
  * @brief
  * @{
  */
#define BIT_MASK_KEYCAM6_ENTRY31_MFB   ((u32)0x0000007F << 25)           /*!< R/W 0x0  */
#define BIT_KEYCAM6_ENTRY31_MFB(x)     (((u32)((x) & 0x0000007F) << 25))
#define BIT_GET_KEYCAM6_ENTRY31_MFB(x) ((u32)(((x >> 25) & 0x0000007F)))
/** @} */

/** @defgroup REG_BACAM0_ENTRYx
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRYx_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRYx_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRYx_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRYx
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRYx_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRYx_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRYx_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRYx_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRYx_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRYx_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRYx_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRYx_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRYx_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRYx
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRYx_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRYx_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRYx_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRYx
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRYx_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRYx_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRYx_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY00
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY00_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY00_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY00_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY00
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY00_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY00_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY00_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY00_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY00_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY00_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY00_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY00_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY00_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY00
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY00_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY00_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY00_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY00
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY00_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY00_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY00_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY01
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY01_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY01_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY01_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY01
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY01_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY01_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY01_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY01_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY01_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY01_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY01_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY01_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY01_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY01
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY01_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY01_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY01_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY01
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY01_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY01_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY01_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY02
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY02_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY02_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY02_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY02
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY02_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY02_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY02_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY02_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY02_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY02_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY02_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY02_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY02_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY02
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY02_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY02_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY02_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY02
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY02_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY02_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY02_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY03
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY03_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY03_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY03_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY03
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY03_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY03_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY03_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY03_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY03_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY03_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY03_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY03_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY03_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY03
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY03_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY03_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY03_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY03
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY03_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY03_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY03_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY04
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY04_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY04_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY04_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY04
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY04_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY04_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY04_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY04_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY04_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY04_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY04_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY04_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY04_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY04
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY04_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY04_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY04_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY04
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY04_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY04_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY04_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY05
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY05_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY05_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY05_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY05
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY05_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY05_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY05_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY05_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY05_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY05_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY05_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY05_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY05_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY05
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY05_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY05_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY05_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY05
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY05_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY05_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY05_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY06
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY06_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY06_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY06_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY06
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY06_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY06_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY06_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY06_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY06_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY06_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY06_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY06_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY06_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY06
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY06_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY06_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY06_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY06
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY06_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY06_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY06_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY07
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY07_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY07_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY07_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY07
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY07_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY07_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY07_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY07_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY07_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY07_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY07_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY07_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY07_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY07
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY07_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY07_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY07_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY07
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY07_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY07_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY07_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY08
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY08_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY08_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY08_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY08
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY08_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY08_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY08_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY08_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY08_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY08_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY08_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY08_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY08_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY08
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY08_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY08_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY08_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY08
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY08_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY08_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY08_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY09
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY09_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY09_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY09_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY09
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY09_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY09_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY09_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY09_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY09_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY09_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY09_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY09_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY09_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY09
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY09_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY09_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY09_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY09
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY09_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY09_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY09_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY10
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY10_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY10_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY10_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY10
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY10_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY10_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY10_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY10_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY10_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY10_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY10_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY10_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY10_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY10
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY10_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY10_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY10_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY10
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY10_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY10_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY10_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY11
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY11_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY11_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY11_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY11
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY11_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY11_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY11_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY11_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY11_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY11_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY11_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY11_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY11_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY11
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY11_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY11_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY11_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY11
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY11_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY11_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY11_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY12
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY12_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY12_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY12_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY12
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY12_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY12_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY12_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY12_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY12_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY12_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY12_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY12_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY12_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY12
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY12_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY12_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY12_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY12
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY12_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY12_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY12_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY13
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY13_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY13_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY13_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY13
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY13_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY13_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY13_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY13_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY13_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY13_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY13_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY13_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY13_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY13
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY13_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY13_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY13_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY13
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY13_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY13_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY13_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY14
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY14_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY14_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY14_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY14
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY14_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY14_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY14_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY14_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY14_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY14_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY14_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY14_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY14_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY14
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY14_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY14_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY14_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY14
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY14_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY14_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY14_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY15
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY15_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY15_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY15_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY15
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY15_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY15_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY15_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY15_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY15_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY15_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY15_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY15_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY15_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY15
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY15_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY15_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY15_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY15
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY15_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY15_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY15_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY16
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY16_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY16_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY16_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY16
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY16_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY16_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY16_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY16_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY16_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY16_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY16_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY16_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY16_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY16
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY16_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY16_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY16_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY16
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY16_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY16_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY16_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY17
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY17_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY17_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY17_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY17
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY17_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY17_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY17_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY17_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY17_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY17_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY17_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY17_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY17_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY17
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY17_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY17_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY17_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY17
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY17_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY17_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY17_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY18
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY18_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY18_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY18_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY18
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY18_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY18_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY18_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY18_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY18_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY18_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY18_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY18_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY18_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY18
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY18_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY18_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY18_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY18
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY18_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY18_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY18_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY19
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY19_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY19_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY19_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY19
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY19_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY19_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY19_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY19_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY19_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY19_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY19_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY19_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY19_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY19
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY19_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY19_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY19_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY19
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY19_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY19_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY19_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY20
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY20_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY20_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY20_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY20
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY20_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY20_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY20_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY20_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY20_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY20_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY20_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY20_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY20_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY20
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY20_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY20_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY20_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY20
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY20_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY20_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY20_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY21
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY21_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY21_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY21_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY21
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY21_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY21_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY21_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY21_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY21_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY21_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY21_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY21_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY21_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY21
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY21_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY21_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY21_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY21
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY21_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY21_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY21_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY22
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY22_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY22_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY22_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY22
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY22_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY22_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY22_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY22_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY22_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY22_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY22_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY22_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY22_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY22
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY22_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY22_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY22_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY22
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY22_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY22_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY22_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY23
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY23_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY23_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY23_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY23
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY23_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY23_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY23_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY23_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY23_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY23_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY23_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY23_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY23_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY23
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY23_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY23_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY23_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY23
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY23_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY23_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY23_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY24
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY24_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY24_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY24_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY24
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY24_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY24_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY24_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY24_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY24_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY24_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY24_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY24_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY24_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY24
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY24_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY24_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY24_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY24
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY24_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY24_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY24_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY25
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY25_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY25_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY25_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY25
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY25_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY25_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY25_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY25_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY25_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY25_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY25_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY25_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY25_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY25
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY25_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY25_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY25_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY25
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY25_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY25_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY25_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY26
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY26_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY26_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY26_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY26
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY26_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY26_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY26_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY26_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY26_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY26_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY26_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY26_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY26_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY26
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY26_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY26_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY26_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY26
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY26_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY26_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY26_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY27
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY27_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY27_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY27_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY27
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY27_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY27_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY27_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY27_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY27_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY27_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY27_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY27_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY27_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY27
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY27_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY27_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY27_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY27
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY27_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY27_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY27_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY28
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY28_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY28_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY28_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY28
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY28_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY28_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY28_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY28_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY28_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY28_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY28_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY28_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY28_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY28
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY28_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY28_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY28_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY28
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY28_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY28_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY28_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY29
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY29_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY29_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY29_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY29
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY29_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY29_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY29_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY29_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY29_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY29_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY29_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY29_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY29_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY29
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY29_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY29_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY29_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY29
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY29_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY29_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY29_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY30
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY30_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY30_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY30_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY30
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY30_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY30_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY30_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY30_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY30_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY30_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY30_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY30_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY30_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY30
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY30_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY30_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY30_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY30
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY30_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY30_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY30_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM0_ENTRY31
  * @brief
  * @{
  */
#define BIT_MASK_BACAM0_ENTRY31_INFO_TA0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM0_ENTRY31_INFO_TA0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM0_ENTRY31_INFO_TA0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM1_ENTRY31
  * @brief
  * @{
  */
#define BIT_MASK_BACAM1_ENTRY31_INFO_SSN   ((u32)0x00000FFF << 20)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY31_INFO_SSN(x)     (((u32)((x) & 0x00000FFF) << 20))
#define BIT_GET_BACAM1_ENTRY31_INFO_SSN(x) ((u32)(((x >> 20) & 0x00000FFF)))
#define BIT_MASK_BACAM1_ENTRY31_INFO_TID   ((u32)0x0000000F << 16)           /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY31_INFO_TID(x)     (((u32)((x) & 0x0000000F) << 16))
#define BIT_GET_BACAM1_ENTRY31_INFO_TID(x) ((u32)(((x >> 16) & 0x0000000F)))
#define BIT_MASK_BACAM1_ENTRY31_INFO_TA1   ((u32)0x0000FFFF << 0)            /*!< R/W 0x0  */
#define BIT_BACAM1_ENTRY31_INFO_TA1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_BACAM1_ENTRY31_INFO_TA1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_BACAM2_ENTRY31
  * @brief
  * @{
  */
#define BIT_MASK_BACAM2_ENTRY31_BITMAP0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM2_ENTRY31_BITMAP0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM2_ENTRY31_BITMAP0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_BACAM3_ENTRY31
  * @brief
  * @{
  */
#define BIT_MASK_BACAM3_ENTRY31_BITMAP1   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_BACAM3_ENTRY31_BITMAP1(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_BACAM3_ENTRY31_BITMAP1(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRYx
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRYx_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRYx_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRYx_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRYx
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRYx_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRYx_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRYx_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRYx_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRYx_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRYx_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY00
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY00_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY00_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY00_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY00
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY00_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY00_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY00_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY00_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY00_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY00_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY01
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY01_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY01_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY01_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY01
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY01_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY01_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY01_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY01_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY01_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY01_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY02
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY02_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY02_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY02_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY02
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY02_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY02_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY02_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY02_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY02_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY02_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY03
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY03_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY03_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY03_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY03
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY03_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY03_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY03_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY03_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY03_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY03_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY04
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY04_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY04_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY04_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY04
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY04_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY04_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY04_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY04_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY04_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY04_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY05
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY05_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY05_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY05_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY05
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY05_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY05_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY05_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY05_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY05_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY05_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY06
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY06_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY06_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY06_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY06
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY06_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY06_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY06_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY06_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY06_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY06_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY07
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY07_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY07_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY07_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY07
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY07_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY07_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY07_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY07_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY07_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY07_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY08
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY08_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY08_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY08_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY08
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY08_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY08_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY08_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY08_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY08_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY08_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY09
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY09_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY09_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY09_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY09
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY09_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY09_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY09_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY09_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY09_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY09_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY10
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY10_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY10_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY10_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY10
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY10_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY10_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY10_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY10_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY10_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY10_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY11
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY11_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY11_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY11_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY11
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY11_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY11_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY11_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY11_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY11_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY11_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY12
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY12_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY12_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY12_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY12
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY12_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY12_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY12_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY12_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY12_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY12_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY13
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY13_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY13_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY13_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY13
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY13_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY13_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY13_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY13_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY13_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY13_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY14
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY14_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY14_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY14_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY14
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY14_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY14_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY14_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY14_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY14_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY14_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY15
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY15_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY15_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY15_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY15
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY15_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY15_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY15_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY15_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY15_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY15_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY16
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY16_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY16_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY16_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY16
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY16_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY16_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY16_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY16_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY16_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY16_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY17
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY17_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY17_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY17_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY17
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY17_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY17_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY17_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY17_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY17_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY17_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY18
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY18_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY18_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY18_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY18
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY18_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY18_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY18_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY18_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY18_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY18_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY19
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY19_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY19_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY19_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY19
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY19_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY19_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY19_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY19_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY19_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY19_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY20
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY20_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY20_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY20_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY20
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY20_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY20_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY20_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY20_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY20_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY20_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY21
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY21_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY21_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY21_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY21
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY21_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY21_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY21_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY21_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY21_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY21_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY22
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY22_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY22_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY22_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY22
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY22_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY22_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY22_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY22_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY22_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY22_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY23
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY23_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY23_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY23_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY23
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY23_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY23_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY23_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY23_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY23_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY23_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY24
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY24_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY24_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY24_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY24
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY24_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY24_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY24_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY24_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY24_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY24_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY25
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY25_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY25_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY25_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY25
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY25_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY25_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY25_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY25_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY25_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY25_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY26
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY26_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY26_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY26_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY26
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY26_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY26_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY26_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY26_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY26_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY26_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY27
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY27_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY27_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY27_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY27
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY27_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY27_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY27_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY27_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY27_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY27_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY28
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY28_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY28_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY28_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY28
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY28_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY28_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY28_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY28_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY28_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY28_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY29
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY29_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY29_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY29_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY29
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY29_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY29_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY29_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY29_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY29_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY29_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY30
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY30_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY30_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY30_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY30
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY30_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY30_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY30_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY30_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY30_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY30_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_MBIDCAM0_ENTRY31
  * @brief
  * @{
  */
#define BIT_MASK_MBIDCAM0_ENTRY31_BSSID_MACID0   ((u32)0xFFFFFFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM0_ENTRY31_BSSID_MACID0(x)     (((u32)((x) & 0xFFFFFFFF) << 0))
#define BIT_GET_MBIDCAM0_ENTRY31_BSSID_MACID0(x) ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_MBIDCAM1_ENTRY31
  * @brief
  * @{
  */
#define BIT_MBIDCAM1_ENTRY31_VALID               ((u32)0x00000001 << 23)          /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY31_LSIG_TXOP_EN        ((u32)0x00000001 << 17)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MBIDCAM1_ENTRY31_DUA_CTS_EN          ((u32)0x00000001 << 16)          /*!< R/W 0x0  only use in mbidcam*/
#define BIT_MASK_MBIDCAM1_ENTRY31_BSSID_MACID1   ((u32)0x0000FFFF << 0)           /*!< R/W 0x0  */
#define BIT_MBIDCAM1_ENTRY31_BSSID_MACID1(x)     (((u32)((x) & 0x0000FFFF) << 0))
#define BIT_GET_MBIDCAM1_ENTRY31_BSSID_MACID1(x) ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_ADDRESSCAM_ENTRYx
  * @brief
  * @{
  */
#define BIT_ADDRESSCAM_ENTRYx_VALID          ((u32)0x00000001 << 31)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRYx_SUBTYPE_MASK   ((u32)0x00000001 << 30)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRYx_A2_UNMATCH     ((u32)0x00000001 << 29)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRYx_NORMAL         ((u32)0x00000001 << 28)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRYx_UL_RELAY       ((u32)0x00000001 << 27)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRYx_RELAY          ((u32)0x00000001 << 26)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRYx_DATA           ((u32)0x00000001 << 21)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRYx_MGNT           ((u32)0x00000001 << 20)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRYx_CTRL           ((u32)0x00000001 << 19)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRYx_SUBTYPE   ((u32)0x0000000F << 15)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRYx_SUBTYPE(x)     (((u32)((x) & 0x0000000F) << 15))
#define BIT_GET_ADDRESSCAM_ENTRYx_SUBTYPE(x) ((u32)(((x >> 15) & 0x0000000F)))
#define BIT_ADDRESSCAM_ENTRYx_BC             ((u32)0x00000001 << 14)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRYx_MC             ((u32)0x00000001 << 13)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRYx_UC             ((u32)0x00000001 << 12)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRYx_A1        ((u32)0x0000000F << 8)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRYx_A1(x)          (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_ADDRESSCAM_ENTRYx_A1(x)      ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRYx_A2        ((u32)0x0000000F << 4)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRYx_A2(x)          (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_ADDRESSCAM_ENTRYx_A2(x)      ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRYx_A3        ((u32)0x0000000F << 0)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRYx_A3(x)          (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_ADDRESSCAM_ENTRYx_A3(x)      ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_ADDRESSCAM_ENTRY00
  * @brief
  * @{
  */
#define BIT_ADDRESSCAM_ENTRY00_VALID          ((u32)0x00000001 << 31)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY00_SUBTYPE_MASK   ((u32)0x00000001 << 30)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY00_A2_UNMATCH     ((u32)0x00000001 << 29)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY00_NORMAL         ((u32)0x00000001 << 28)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY00_UL_RELAY       ((u32)0x00000001 << 27)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY00_RELAY          ((u32)0x00000001 << 26)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY00_DATA           ((u32)0x00000001 << 21)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY00_MGNT           ((u32)0x00000001 << 20)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY00_CTRL           ((u32)0x00000001 << 19)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY00_SUBTYPE   ((u32)0x0000000F << 15)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY00_SUBTYPE(x)     (((u32)((x) & 0x0000000F) << 15))
#define BIT_GET_ADDRESSCAM_ENTRY00_SUBTYPE(x) ((u32)(((x >> 15) & 0x0000000F)))
#define BIT_ADDRESSCAM_ENTRY00_BC             ((u32)0x00000001 << 14)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY00_MC             ((u32)0x00000001 << 13)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY00_UC             ((u32)0x00000001 << 12)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY00_A1        ((u32)0x0000000F << 8)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY00_A1(x)          (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_ADDRESSCAM_ENTRY00_A1(x)      ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY00_A2        ((u32)0x0000000F << 4)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY00_A2(x)          (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_ADDRESSCAM_ENTRY00_A2(x)      ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY00_A3        ((u32)0x0000000F << 0)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY00_A3(x)          (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_ADDRESSCAM_ENTRY00_A3(x)      ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_ADDRESSCAM_ENTRY01
  * @brief
  * @{
  */
#define BIT_ADDRESSCAM_ENTRY01_VALID          ((u32)0x00000001 << 31)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY01_SUBTYPE_MASK   ((u32)0x00000001 << 30)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY01_A2_UNMATCH     ((u32)0x00000001 << 29)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY01_NORMAL         ((u32)0x00000001 << 28)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY01_UL_RELAY       ((u32)0x00000001 << 27)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY01_RELAY          ((u32)0x00000001 << 26)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY01_DATA           ((u32)0x00000001 << 21)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY01_MGNT           ((u32)0x00000001 << 20)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY01_CTRL           ((u32)0x00000001 << 19)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY01_SUBTYPE   ((u32)0x0000000F << 15)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY01_SUBTYPE(x)     (((u32)((x) & 0x0000000F) << 15))
#define BIT_GET_ADDRESSCAM_ENTRY01_SUBTYPE(x) ((u32)(((x >> 15) & 0x0000000F)))
#define BIT_ADDRESSCAM_ENTRY01_BC             ((u32)0x00000001 << 14)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY01_MC             ((u32)0x00000001 << 13)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY01_UC             ((u32)0x00000001 << 12)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY01_A1        ((u32)0x0000000F << 8)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY01_A1(x)          (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_ADDRESSCAM_ENTRY01_A1(x)      ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY01_A2        ((u32)0x0000000F << 4)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY01_A2(x)          (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_ADDRESSCAM_ENTRY01_A2(x)      ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY01_A3        ((u32)0x0000000F << 0)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY01_A3(x)          (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_ADDRESSCAM_ENTRY01_A3(x)      ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_ADDRESSCAM_ENTRY02
  * @brief
  * @{
  */
#define BIT_ADDRESSCAM_ENTRY02_VALID          ((u32)0x00000001 << 31)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY02_SUBTYPE_MASK   ((u32)0x00000001 << 30)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY02_A2_UNMATCH     ((u32)0x00000001 << 29)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY02_NORMAL         ((u32)0x00000001 << 28)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY02_UL_RELAY       ((u32)0x00000001 << 27)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY02_RELAY          ((u32)0x00000001 << 26)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY02_DATA           ((u32)0x00000001 << 21)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY02_MGNT           ((u32)0x00000001 << 20)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY02_CTRL           ((u32)0x00000001 << 19)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY02_SUBTYPE   ((u32)0x0000000F << 15)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY02_SUBTYPE(x)     (((u32)((x) & 0x0000000F) << 15))
#define BIT_GET_ADDRESSCAM_ENTRY02_SUBTYPE(x) ((u32)(((x >> 15) & 0x0000000F)))
#define BIT_ADDRESSCAM_ENTRY02_BC             ((u32)0x00000001 << 14)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY02_MC             ((u32)0x00000001 << 13)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY02_UC             ((u32)0x00000001 << 12)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY02_A1        ((u32)0x0000000F << 8)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY02_A1(x)          (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_ADDRESSCAM_ENTRY02_A1(x)      ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY02_A2        ((u32)0x0000000F << 4)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY02_A2(x)          (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_ADDRESSCAM_ENTRY02_A2(x)      ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY02_A3        ((u32)0x0000000F << 0)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY02_A3(x)          (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_ADDRESSCAM_ENTRY02_A3(x)      ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_ADDRESSCAM_ENTRY03
  * @brief
  * @{
  */
#define BIT_ADDRESSCAM_ENTRY03_VALID          ((u32)0x00000001 << 31)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY03_SUBTYPE_MASK   ((u32)0x00000001 << 30)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY03_A2_UNMATCH     ((u32)0x00000001 << 29)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY03_NORMAL         ((u32)0x00000001 << 28)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY03_UL_RELAY       ((u32)0x00000001 << 27)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY03_RELAY          ((u32)0x00000001 << 26)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY03_DATA           ((u32)0x00000001 << 21)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY03_MGNT           ((u32)0x00000001 << 20)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY03_CTRL           ((u32)0x00000001 << 19)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY03_SUBTYPE   ((u32)0x0000000F << 15)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY03_SUBTYPE(x)     (((u32)((x) & 0x0000000F) << 15))
#define BIT_GET_ADDRESSCAM_ENTRY03_SUBTYPE(x) ((u32)(((x >> 15) & 0x0000000F)))
#define BIT_ADDRESSCAM_ENTRY03_BC             ((u32)0x00000001 << 14)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY03_MC             ((u32)0x00000001 << 13)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY03_UC             ((u32)0x00000001 << 12)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY03_A1        ((u32)0x0000000F << 8)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY03_A1(x)          (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_ADDRESSCAM_ENTRY03_A1(x)      ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY03_A2        ((u32)0x0000000F << 4)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY03_A2(x)          (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_ADDRESSCAM_ENTRY03_A2(x)      ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY03_A3        ((u32)0x0000000F << 0)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY03_A3(x)          (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_ADDRESSCAM_ENTRY03_A3(x)      ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_ADDRESSCAM_ENTRY04
  * @brief
  * @{
  */
#define BIT_ADDRESSCAM_ENTRY04_VALID          ((u32)0x00000001 << 31)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY04_SUBTYPE_MASK   ((u32)0x00000001 << 30)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY04_A2_UNMATCH     ((u32)0x00000001 << 29)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY04_NORMAL         ((u32)0x00000001 << 28)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY04_UL_RELAY       ((u32)0x00000001 << 27)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY04_RELAY          ((u32)0x00000001 << 26)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY04_DATA           ((u32)0x00000001 << 21)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY04_MGNT           ((u32)0x00000001 << 20)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY04_CTRL           ((u32)0x00000001 << 19)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY04_SUBTYPE   ((u32)0x0000000F << 15)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY04_SUBTYPE(x)     (((u32)((x) & 0x0000000F) << 15))
#define BIT_GET_ADDRESSCAM_ENTRY04_SUBTYPE(x) ((u32)(((x >> 15) & 0x0000000F)))
#define BIT_ADDRESSCAM_ENTRY04_BC             ((u32)0x00000001 << 14)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY04_MC             ((u32)0x00000001 << 13)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY04_UC             ((u32)0x00000001 << 12)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY04_A1        ((u32)0x0000000F << 8)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY04_A1(x)          (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_ADDRESSCAM_ENTRY04_A1(x)      ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY04_A2        ((u32)0x0000000F << 4)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY04_A2(x)          (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_ADDRESSCAM_ENTRY04_A2(x)      ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY04_A3        ((u32)0x0000000F << 0)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY04_A3(x)          (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_ADDRESSCAM_ENTRY04_A3(x)      ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_ADDRESSCAM_ENTRY05
  * @brief
  * @{
  */
#define BIT_ADDRESSCAM_ENTRY05_VALID          ((u32)0x00000001 << 31)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY05_SUBTYPE_MASK   ((u32)0x00000001 << 30)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY05_A2_UNMATCH     ((u32)0x00000001 << 29)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY05_NORMAL         ((u32)0x00000001 << 28)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY05_UL_RELAY       ((u32)0x00000001 << 27)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY05_RELAY          ((u32)0x00000001 << 26)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY05_DATA           ((u32)0x00000001 << 21)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY05_MGNT           ((u32)0x00000001 << 20)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY05_CTRL           ((u32)0x00000001 << 19)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY05_SUBTYPE   ((u32)0x0000000F << 15)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY05_SUBTYPE(x)     (((u32)((x) & 0x0000000F) << 15))
#define BIT_GET_ADDRESSCAM_ENTRY05_SUBTYPE(x) ((u32)(((x >> 15) & 0x0000000F)))
#define BIT_ADDRESSCAM_ENTRY05_BC             ((u32)0x00000001 << 14)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY05_MC             ((u32)0x00000001 << 13)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY05_UC             ((u32)0x00000001 << 12)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY05_A1        ((u32)0x0000000F << 8)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY05_A1(x)          (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_ADDRESSCAM_ENTRY05_A1(x)      ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY05_A2        ((u32)0x0000000F << 4)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY05_A2(x)          (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_ADDRESSCAM_ENTRY05_A2(x)      ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY05_A3        ((u32)0x0000000F << 0)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY05_A3(x)          (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_ADDRESSCAM_ENTRY05_A3(x)      ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_ADDRESSCAM_ENTRY06
  * @brief
  * @{
  */
#define BIT_ADDRESSCAM_ENTRY06_VALID          ((u32)0x00000001 << 31)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY06_SUBTYPE_MASK   ((u32)0x00000001 << 30)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY06_A2_UNMATCH     ((u32)0x00000001 << 29)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY06_NORMAL         ((u32)0x00000001 << 28)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY06_UL_RELAY       ((u32)0x00000001 << 27)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY06_RELAY          ((u32)0x00000001 << 26)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY06_DATA           ((u32)0x00000001 << 21)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY06_MGNT           ((u32)0x00000001 << 20)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY06_CTRL           ((u32)0x00000001 << 19)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY06_SUBTYPE   ((u32)0x0000000F << 15)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY06_SUBTYPE(x)     (((u32)((x) & 0x0000000F) << 15))
#define BIT_GET_ADDRESSCAM_ENTRY06_SUBTYPE(x) ((u32)(((x >> 15) & 0x0000000F)))
#define BIT_ADDRESSCAM_ENTRY06_BC             ((u32)0x00000001 << 14)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY06_MC             ((u32)0x00000001 << 13)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY06_UC             ((u32)0x00000001 << 12)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY06_A1        ((u32)0x0000000F << 8)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY06_A1(x)          (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_ADDRESSCAM_ENTRY06_A1(x)      ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY06_A2        ((u32)0x0000000F << 4)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY06_A2(x)          (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_ADDRESSCAM_ENTRY06_A2(x)      ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY06_A3        ((u32)0x0000000F << 0)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY06_A3(x)          (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_ADDRESSCAM_ENTRY06_A3(x)      ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_ADDRESSCAM_ENTRY07
  * @brief
  * @{
  */
#define BIT_ADDRESSCAM_ENTRY07_VALID          ((u32)0x00000001 << 31)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY07_SUBTYPE_MASK   ((u32)0x00000001 << 30)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY07_A2_UNMATCH     ((u32)0x00000001 << 29)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY07_NORMAL         ((u32)0x00000001 << 28)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY07_UL_RELAY       ((u32)0x00000001 << 27)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY07_RELAY          ((u32)0x00000001 << 26)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY07_DATA           ((u32)0x00000001 << 21)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY07_MGNT           ((u32)0x00000001 << 20)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY07_CTRL           ((u32)0x00000001 << 19)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY07_SUBTYPE   ((u32)0x0000000F << 15)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY07_SUBTYPE(x)     (((u32)((x) & 0x0000000F) << 15))
#define BIT_GET_ADDRESSCAM_ENTRY07_SUBTYPE(x) ((u32)(((x >> 15) & 0x0000000F)))
#define BIT_ADDRESSCAM_ENTRY07_BC             ((u32)0x00000001 << 14)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY07_MC             ((u32)0x00000001 << 13)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY07_UC             ((u32)0x00000001 << 12)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY07_A1        ((u32)0x0000000F << 8)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY07_A1(x)          (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_ADDRESSCAM_ENTRY07_A1(x)      ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY07_A2        ((u32)0x0000000F << 4)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY07_A2(x)          (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_ADDRESSCAM_ENTRY07_A2(x)      ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY07_A3        ((u32)0x0000000F << 0)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY07_A3(x)          (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_ADDRESSCAM_ENTRY07_A3(x)      ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_ADDRESSCAM_ENTRY08
  * @brief
  * @{
  */
#define BIT_ADDRESSCAM_ENTRY08_VALID          ((u32)0x00000001 << 31)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY08_SUBTYPE_MASK   ((u32)0x00000001 << 30)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY08_A2_UNMATCH     ((u32)0x00000001 << 29)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY08_NORMAL         ((u32)0x00000001 << 28)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY08_UL_RELAY       ((u32)0x00000001 << 27)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY08_RELAY          ((u32)0x00000001 << 26)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY08_DATA           ((u32)0x00000001 << 21)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY08_MGNT           ((u32)0x00000001 << 20)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY08_CTRL           ((u32)0x00000001 << 19)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY08_SUBTYPE   ((u32)0x0000000F << 15)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY08_SUBTYPE(x)     (((u32)((x) & 0x0000000F) << 15))
#define BIT_GET_ADDRESSCAM_ENTRY08_SUBTYPE(x) ((u32)(((x >> 15) & 0x0000000F)))
#define BIT_ADDRESSCAM_ENTRY08_BC             ((u32)0x00000001 << 14)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY08_MC             ((u32)0x00000001 << 13)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY08_UC             ((u32)0x00000001 << 12)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY08_A1        ((u32)0x0000000F << 8)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY08_A1(x)          (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_ADDRESSCAM_ENTRY08_A1(x)      ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY08_A2        ((u32)0x0000000F << 4)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY08_A2(x)          (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_ADDRESSCAM_ENTRY08_A2(x)      ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY08_A3        ((u32)0x0000000F << 0)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY08_A3(x)          (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_ADDRESSCAM_ENTRY08_A3(x)      ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_ADDRESSCAM_ENTRY09
  * @brief
  * @{
  */
#define BIT_ADDRESSCAM_ENTRY09_VALID          ((u32)0x00000001 << 31)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY09_SUBTYPE_MASK   ((u32)0x00000001 << 30)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY09_A2_UNMATCH     ((u32)0x00000001 << 29)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY09_NORMAL         ((u32)0x00000001 << 28)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY09_UL_RELAY       ((u32)0x00000001 << 27)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY09_RELAY          ((u32)0x00000001 << 26)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY09_DATA           ((u32)0x00000001 << 21)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY09_MGNT           ((u32)0x00000001 << 20)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY09_CTRL           ((u32)0x00000001 << 19)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY09_SUBTYPE   ((u32)0x0000000F << 15)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY09_SUBTYPE(x)     (((u32)((x) & 0x0000000F) << 15))
#define BIT_GET_ADDRESSCAM_ENTRY09_SUBTYPE(x) ((u32)(((x >> 15) & 0x0000000F)))
#define BIT_ADDRESSCAM_ENTRY09_BC             ((u32)0x00000001 << 14)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY09_MC             ((u32)0x00000001 << 13)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY09_UC             ((u32)0x00000001 << 12)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY09_A1        ((u32)0x0000000F << 8)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY09_A1(x)          (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_ADDRESSCAM_ENTRY09_A1(x)      ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY09_A2        ((u32)0x0000000F << 4)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY09_A2(x)          (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_ADDRESSCAM_ENTRY09_A2(x)      ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY09_A3        ((u32)0x0000000F << 0)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY09_A3(x)          (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_ADDRESSCAM_ENTRY09_A3(x)      ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_ADDRESSCAM_ENTRY10
  * @brief
  * @{
  */
#define BIT_ADDRESSCAM_ENTRY10_VALID          ((u32)0x00000001 << 31)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY10_SUBTYPE_MASK   ((u32)0x00000001 << 30)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY10_A2_UNMATCH     ((u32)0x00000001 << 29)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY10_NORMAL         ((u32)0x00000001 << 28)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY10_UL_RELAY       ((u32)0x00000001 << 27)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY10_RELAY          ((u32)0x00000001 << 26)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY10_DATA           ((u32)0x00000001 << 21)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY10_MGNT           ((u32)0x00000001 << 20)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY10_CTRL           ((u32)0x00000001 << 19)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY10_SUBTYPE   ((u32)0x0000000F << 15)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY10_SUBTYPE(x)     (((u32)((x) & 0x0000000F) << 15))
#define BIT_GET_ADDRESSCAM_ENTRY10_SUBTYPE(x) ((u32)(((x >> 15) & 0x0000000F)))
#define BIT_ADDRESSCAM_ENTRY10_BC             ((u32)0x00000001 << 14)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY10_MC             ((u32)0x00000001 << 13)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY10_UC             ((u32)0x00000001 << 12)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY10_A1        ((u32)0x0000000F << 8)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY10_A1(x)          (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_ADDRESSCAM_ENTRY10_A1(x)      ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY10_A2        ((u32)0x0000000F << 4)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY10_A2(x)          (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_ADDRESSCAM_ENTRY10_A2(x)      ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY10_A3        ((u32)0x0000000F << 0)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY10_A3(x)          (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_ADDRESSCAM_ENTRY10_A3(x)      ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_ADDRESSCAM_ENTRY11
  * @brief
  * @{
  */
#define BIT_ADDRESSCAM_ENTRY11_VALID          ((u32)0x00000001 << 31)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY11_SUBTYPE_MASK   ((u32)0x00000001 << 30)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY11_A2_UNMATCH     ((u32)0x00000001 << 29)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY11_NORMAL         ((u32)0x00000001 << 28)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY11_UL_RELAY       ((u32)0x00000001 << 27)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY11_RELAY          ((u32)0x00000001 << 26)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY11_DATA           ((u32)0x00000001 << 21)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY11_MGNT           ((u32)0x00000001 << 20)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY11_CTRL           ((u32)0x00000001 << 19)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY11_SUBTYPE   ((u32)0x0000000F << 15)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY11_SUBTYPE(x)     (((u32)((x) & 0x0000000F) << 15))
#define BIT_GET_ADDRESSCAM_ENTRY11_SUBTYPE(x) ((u32)(((x >> 15) & 0x0000000F)))
#define BIT_ADDRESSCAM_ENTRY11_BC             ((u32)0x00000001 << 14)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY11_MC             ((u32)0x00000001 << 13)           /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY11_UC             ((u32)0x00000001 << 12)           /*!< R/W 0x0  */
#define BIT_MASK_ADDRESSCAM_ENTRY11_A1        ((u32)0x0000000F << 8)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY11_A1(x)          (((u32)((x) & 0x0000000F) << 8))
#define BIT_GET_ADDRESSCAM_ENTRY11_A1(x)      ((u32)(((x >> 8) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY11_A2        ((u32)0x0000000F << 4)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY11_A2(x)          (((u32)((x) & 0x0000000F) << 4))
#define BIT_GET_ADDRESSCAM_ENTRY11_A2(x)      ((u32)(((x >> 4) & 0x0000000F)))
#define BIT_MASK_ADDRESSCAM_ENTRY11_A3        ((u32)0x0000000F << 0)            /*!< R/W 0x0  */
#define BIT_ADDRESSCAM_ENTRY11_A3(x)          (((u32)((x) & 0x0000000F) << 0))
#define BIT_GET_ADDRESSCAM_ENTRY11_A3(x)      ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/*==========REG_MAC_SRAM Register Address Definition==========*/
#define REG_TXPKTBUF                    0x20000
#define REG_RXPKTBUF                    0x30000
#define REG_TXRPTBUF                    0x40000
#define REG_LLT                         0x50000
#define REG_KEYCAM0_ENTRY00             0x50800
#define REG_KEYCAM1_ENTRY00             0x50804
#define REG_KEYCAM2_ENTRY00             0x50808
#define REG_KEYCAM3_ENTRY00             0x5080C
#define REG_KEYCAM4_ENTRY00             0x50810
#define REG_KEYCAM5_ENTRY00             0x50814
#define REG_KEYCAM6_ENTRY00             0x50818
#define REG_KEYCAM7_ENTRY00             0x5081C
#define REG_KEYCAM0_ENTRY01             0x50820
#define REG_KEYCAM1_ENTRY01             0x50824
#define REG_KEYCAM2_ENTRY01             0x50828
#define REG_KEYCAM3_ENTRY01             0x5082C
#define REG_KEYCAM4_ENTRY01             0x50830
#define REG_KEYCAM5_ENTRY01             0x50834
#define REG_KEYCAM6_ENTRY01             0x50838
#define REG_KEYCAM7_ENTRY01             0x5083C
#define REG_KEYCAM0_ENTRY02             0x50840
#define REG_KEYCAM1_ENTRY02             0x50844
#define REG_KEYCAM2_ENTRY02             0x50848
#define REG_KEYCAM3_ENTRY02             0x5084C
#define REG_KEYCAM4_ENTRY02             0x50850
#define REG_KEYCAM5_ENTRY02             0x50854
#define REG_KEYCAM6_ENTRY02             0x50858
#define REG_KEYCAM7_ENTRY02             0x5085C
#define REG_KEYCAM0_ENTRY03             0x50860
#define REG_KEYCAM1_ENTRY03             0x50864
#define REG_KEYCAM2_ENTRY03             0x50868
#define REG_KEYCAM3_ENTRY03             0x5086C
#define REG_KEYCAM4_ENTRY03             0x50870
#define REG_KEYCAM5_ENTRY03             0x50874
#define REG_KEYCAM6_ENTRY03             0x50878
#define REG_KEYCAM7_ENTRY03             0x5087C
#define REG_KEYCAM0_ENTRY04             0x50880
#define REG_KEYCAM1_ENTRY04             0x50884
#define REG_KEYCAM2_ENTRY04             0x50888
#define REG_KEYCAM3_ENTRY04             0x5088C
#define REG_KEYCAM4_ENTRY04             0x50890
#define REG_KEYCAM5_ENTRY04             0x50894
#define REG_KEYCAM6_ENTRY04             0x50898
#define REG_KEYCAM7_ENTRY04             0x5089C
#define REG_KEYCAM0_ENTRY05             0x508A0
#define REG_KEYCAM1_ENTRY05             0x508A4
#define REG_KEYCAM2_ENTRY05             0x508A8
#define REG_KEYCAM3_ENTRY05             0x508AC
#define REG_KEYCAM4_ENTRY05             0x508B0
#define REG_KEYCAM5_ENTRY05             0x508B4
#define REG_KEYCAM6_ENTRY05             0x508B8
#define REG_KEYCAM7_ENTRY05             0x508BC
#define REG_KEYCAM0_ENTRY06             0x508C0
#define REG_KEYCAM1_ENTRY06             0x508C4
#define REG_KEYCAM2_ENTRY06             0x508C8
#define REG_KEYCAM3_ENTRY06             0x508CC
#define REG_KEYCAM4_ENTRY06             0x508D0
#define REG_KEYCAM5_ENTRY06             0x508D4
#define REG_KEYCAM6_ENTRY06             0x508D8
#define REG_KEYCAM7_ENTRY06             0x508DC
#define REG_KEYCAM0_ENTRY07             0x508E0
#define REG_KEYCAM1_ENTRY07             0x508E4
#define REG_KEYCAM2_ENTRY07             0x508E8
#define REG_KEYCAM3_ENTRY07             0x508EC
#define REG_KEYCAM4_ENTRY07             0x508F0
#define REG_KEYCAM5_ENTRY07             0x508F4
#define REG_KEYCAM6_ENTRY07             0x508F8
#define REG_KEYCAM7_ENTRY07             0x508FC
#define REG_KEYCAM0_ENTRY08             0x50900
#define REG_KEYCAM1_ENTRY08             0x50904
#define REG_KEYCAM2_ENTRY08             0x50908
#define REG_KEYCAM3_ENTRY08             0x5090C
#define REG_KEYCAM4_ENTRY08             0x50910
#define REG_KEYCAM5_ENTRY08             0x50914
#define REG_KEYCAM6_ENTRY08             0x50918
#define REG_KEYCAM7_ENTRY08             0x5091C
#define REG_KEYCAM0_ENTRY09             0x50920
#define REG_KEYCAM1_ENTRY09             0x50924
#define REG_KEYCAM2_ENTRY09             0x50928
#define REG_KEYCAM3_ENTRY09             0x5092C
#define REG_KEYCAM4_ENTRY09             0x50930
#define REG_KEYCAM5_ENTRY09             0x50934
#define REG_KEYCAM6_ENTRY09             0x50938
#define REG_KEYCAM7_ENTRY09             0x5093C
#define REG_KEYCAM0_ENTRY10             0x50940
#define REG_KEYCAM1_ENTRY10             0x50944
#define REG_KEYCAM2_ENTRY10             0x50948
#define REG_KEYCAM3_ENTRY10             0x5094C
#define REG_KEYCAM4_ENTRY10             0x50950
#define REG_KEYCAM5_ENTRY10             0x50954
#define REG_KEYCAM6_ENTRY10             0x50958
#define REG_KEYCAM7_ENTRY10             0x5095C
#define REG_KEYCAM0_ENTRY11             0x50960
#define REG_KEYCAM1_ENTRY11             0x50964
#define REG_KEYCAM2_ENTRY11             0x50968
#define REG_KEYCAM3_ENTRY11             0x5096C
#define REG_KEYCAM4_ENTRY11             0x50970
#define REG_KEYCAM5_ENTRY11             0x50974
#define REG_KEYCAM6_ENTRY11             0x50978
#define REG_KEYCAM7_ENTRY11             0x5097C
#define REG_KEYCAM0_ENTRY12             0x50980
#define REG_KEYCAM1_ENTRY12             0x50984
#define REG_KEYCAM2_ENTRY12             0x50988
#define REG_KEYCAM3_ENTRY12             0x5098C
#define REG_KEYCAM4_ENTRY12             0x50990
#define REG_KEYCAM5_ENTRY12             0x50994
#define REG_KEYCAM6_ENTRY12             0x50998
#define REG_KEYCAM7_ENTRY12             0x5099C
#define REG_KEYCAM0_ENTRY13             0x509A0
#define REG_KEYCAM1_ENTRY13             0x509A4
#define REG_KEYCAM2_ENTRY13             0x509A8
#define REG_KEYCAM3_ENTRY13             0x509AC
#define REG_KEYCAM4_ENTRY13             0x509B0
#define REG_KEYCAM5_ENTRY13             0x509B4
#define REG_KEYCAM6_ENTRY13             0x509B8
#define REG_KEYCAM7_ENTRY13             0x509BC
#define REG_KEYCAM0_ENTRY14             0x509C0
#define REG_KEYCAM1_ENTRY14             0x509C4
#define REG_KEYCAM2_ENTRY14             0x509C8
#define REG_KEYCAM3_ENTRY14             0x509CC
#define REG_KEYCAM4_ENTRY14             0x509D0
#define REG_KEYCAM5_ENTRY14             0x509D4
#define REG_KEYCAM6_ENTRY14             0x509D8
#define REG_KEYCAM7_ENTRY14             0x509DC
#define REG_KEYCAM0_ENTRY15             0x509E0
#define REG_KEYCAM1_ENTRY15             0x509E4
#define REG_KEYCAM2_ENTRY15             0x509E8
#define REG_KEYCAM3_ENTRY15             0x509EC
#define REG_KEYCAM4_ENTRY15             0x509F0
#define REG_KEYCAM5_ENTRY15             0x509F4
#define REG_KEYCAM6_ENTRY15             0x509F8
#define REG_KEYCAM7_ENTRY15             0x509FC
#define REG_KEYCAM0_ENTRY16             0x50A00
#define REG_KEYCAM1_ENTRY16             0x50A04
#define REG_KEYCAM2_ENTRY16             0x50A08
#define REG_KEYCAM3_ENTRY16             0x50A0C
#define REG_KEYCAM4_ENTRY16             0x50A10
#define REG_KEYCAM5_ENTRY16             0x50A14
#define REG_KEYCAM6_ENTRY16             0x50A18
#define REG_KEYCAM7_ENTRY16             0x50A1C
#define REG_KEYCAM0_ENTRY17             0x50A20
#define REG_KEYCAM1_ENTRY17             0x50A24
#define REG_KEYCAM2_ENTRY17             0x50A28
#define REG_KEYCAM3_ENTRY17             0x50A2C
#define REG_KEYCAM4_ENTRY17             0x50A30
#define REG_KEYCAM5_ENTRY17             0x50A34
#define REG_KEYCAM6_ENTRY17             0x50A38
#define REG_KEYCAM7_ENTRY17             0x50A3C
#define REG_KEYCAM0_ENTRY18             0x50A40
#define REG_KEYCAM1_ENTRY18             0x50A44
#define REG_KEYCAM2_ENTRY18             0x50A48
#define REG_KEYCAM3_ENTRY18             0x50A4C
#define REG_KEYCAM4_ENTRY18             0x50A50
#define REG_KEYCAM5_ENTRY18             0x50A54
#define REG_KEYCAM6_ENTRY18             0x50A58
#define REG_KEYCAM7_ENTRY18             0x50A5C
#define REG_KEYCAM0_ENTRY19             0x50A60
#define REG_KEYCAM1_ENTRY19             0x50A64
#define REG_KEYCAM2_ENTRY19             0x50A68
#define REG_KEYCAM3_ENTRY19             0x50A6C
#define REG_KEYCAM4_ENTRY19             0x50A70
#define REG_KEYCAM5_ENTRY19             0x50A74
#define REG_KEYCAM6_ENTRY19             0x50A78
#define REG_KEYCAM7_ENTRY19             0x50A7C
#define REG_KEYCAM0_ENTRY20             0x50A80
#define REG_KEYCAM1_ENTRY20             0x50A84
#define REG_KEYCAM2_ENTRY20             0x50A88
#define REG_KEYCAM3_ENTRY20             0x50A8C
#define REG_KEYCAM4_ENTRY20             0x50A90
#define REG_KEYCAM5_ENTRY20             0x50A94
#define REG_KEYCAM6_ENTRY20             0x50A98
#define REG_KEYCAM7_ENTRY20             0x50A9C
#define REG_KEYCAM0_ENTRY21             0x50AA0
#define REG_KEYCAM1_ENTRY21             0x50AA4
#define REG_KEYCAM2_ENTRY21             0x50AA8
#define REG_KEYCAM3_ENTRY21             0x50AAC
#define REG_KEYCAM4_ENTRY21             0x50AB0
#define REG_KEYCAM5_ENTRY21             0x50AB4
#define REG_KEYCAM6_ENTRY21             0x50AB8
#define REG_KEYCAM7_ENTRY21             0x50ABC
#define REG_KEYCAM0_ENTRY22             0x50AC0
#define REG_KEYCAM1_ENTRY22             0x50AC4
#define REG_KEYCAM2_ENTRY22             0x50AC8
#define REG_KEYCAM3_ENTRY22             0x50ACC
#define REG_KEYCAM4_ENTRY22             0x50AD0
#define REG_KEYCAM5_ENTRY22             0x50AD4
#define REG_KEYCAM6_ENTRY22             0x50AD8
#define REG_KEYCAM7_ENTRY22             0x50ADC
#define REG_KEYCAM0_ENTRY23             0x50AE0
#define REG_KEYCAM1_ENTRY23             0x50AE4
#define REG_KEYCAM2_ENTRY23             0x50AE8
#define REG_KEYCAM3_ENTRY23             0x50AEC
#define REG_KEYCAM4_ENTRY23             0x50AF0
#define REG_KEYCAM5_ENTRY23             0x50AF4
#define REG_KEYCAM6_ENTRY23             0x50AF8
#define REG_KEYCAM7_ENTRY23             0x50AFC
#define REG_KEYCAM0_ENTRY24             0x50B00
#define REG_KEYCAM1_ENTRY24             0x50B04
#define REG_KEYCAM2_ENTRY24             0x50B08
#define REG_KEYCAM3_ENTRY24             0x50B0C
#define REG_KEYCAM4_ENTRY24             0x50B10
#define REG_KEYCAM5_ENTRY24             0x50B14
#define REG_KEYCAM6_ENTRY24             0x50B18
#define REG_KEYCAM7_ENTRY24             0x50B1C
#define REG_KEYCAM0_ENTRY25             0x50B20
#define REG_KEYCAM1_ENTRY25             0x50B24
#define REG_KEYCAM2_ENTRY25             0x50B28
#define REG_KEYCAM3_ENTRY25             0x50B2C
#define REG_KEYCAM4_ENTRY25             0x50B30
#define REG_KEYCAM5_ENTRY25             0x50B34
#define REG_KEYCAM6_ENTRY25             0x50B38
#define REG_KEYCAM7_ENTRY25             0x50B3C
#define REG_KEYCAM0_ENTRY26             0x50B40
#define REG_KEYCAM1_ENTRY26             0x50B44
#define REG_KEYCAM2_ENTRY26             0x50B48
#define REG_KEYCAM3_ENTRY26             0x50B4C
#define REG_KEYCAM4_ENTRY26             0x50B50
#define REG_KEYCAM5_ENTRY26             0x50B54
#define REG_KEYCAM6_ENTRY26             0x50B58
#define REG_KEYCAM7_ENTRY26             0x50B5C
#define REG_KEYCAM0_ENTRY27             0x50B60
#define REG_KEYCAM1_ENTRY27             0x50B64
#define REG_KEYCAM2_ENTRY27             0x50B68
#define REG_KEYCAM3_ENTRY27             0x50B6C
#define REG_KEYCAM4_ENTRY27             0x50B70
#define REG_KEYCAM5_ENTRY27             0x50B74
#define REG_KEYCAM6_ENTRY27             0x50B78
#define REG_KEYCAM7_ENTRY27             0x50B7C
#define REG_KEYCAM0_ENTRY28             0x50B80
#define REG_KEYCAM1_ENTRY28             0x50B84
#define REG_KEYCAM2_ENTRY28             0x50B88
#define REG_KEYCAM3_ENTRY28             0x50B8C
#define REG_KEYCAM4_ENTRY28             0x50B90
#define REG_KEYCAM5_ENTRY28             0x50B94
#define REG_KEYCAM6_ENTRY28             0x50B98
#define REG_KEYCAM7_ENTRY28             0x50B9C
#define REG_KEYCAM0_ENTRY29             0x50BA0
#define REG_KEYCAM1_ENTRY29             0x50BA4
#define REG_KEYCAM2_ENTRY29             0x50BA8
#define REG_KEYCAM3_ENTRY29             0x50BAC
#define REG_KEYCAM4_ENTRY29             0x50BB0
#define REG_KEYCAM5_ENTRY29             0x50BB4
#define REG_KEYCAM6_ENTRY29             0x50BB8
#define REG_KEYCAM7_ENTRY29             0x50BBC
#define REG_KEYCAM0_ENTRY30             0x50BC0
#define REG_KEYCAM1_ENTRY30             0x50BC4
#define REG_KEYCAM2_ENTRY30             0x50BC8
#define REG_KEYCAM3_ENTRY30             0x50BCC
#define REG_KEYCAM4_ENTRY30             0x50BD0
#define REG_KEYCAM5_ENTRY30             0x50BD4
#define REG_KEYCAM6_ENTRY30             0x50BD8
#define REG_KEYCAM7_ENTRY30             0x50BDC
#define REG_KEYCAM0_ENTRY31             0x50BE0
#define REG_KEYCAM1_ENTRY31             0x50BE4
#define REG_KEYCAM2_ENTRY31             0x50BE8
#define REG_KEYCAM3_ENTRY31             0x50BEC
#define REG_KEYCAM4_ENTRY31             0x50BF0
#define REG_KEYCAM5_ENTRY31             0x50BF4
#define REG_KEYCAM6_ENTRY31             0x50BF8
#define REG_KEYCAM7_ENTRY31             0x50BFC
#define REG_BACAM0_ENTRY00              0x51000
#define REG_BACAM1_ENTRY00              0x51004
#define REG_BACAM2_ENTRY00              0x51008
#define REG_BACAM3_ENTRY00              0x5100C
#define REG_BACAM0_ENTRY01              0x51010
#define REG_BACAM1_ENTRY01              0x51014
#define REG_BACAM2_ENTRY01              0x51018
#define REG_BACAM3_ENTRY01              0x5101C
#define REG_BACAM0_ENTRY02              0x51020
#define REG_BACAM1_ENTRY02              0x51024
#define REG_BACAM2_ENTRY02              0x51028
#define REG_BACAM3_ENTRY02              0x5102C
#define REG_BACAM0_ENTRY03              0x51030
#define REG_BACAM1_ENTRY03              0x51034
#define REG_BACAM2_ENTRY03              0x51038
#define REG_BACAM3_ENTRY03              0x5103C
#define REG_BACAM0_ENTRY04              0x51040
#define REG_BACAM1_ENTRY04              0x51044
#define REG_BACAM2_ENTRY04              0x51048
#define REG_BACAM3_ENTRY04              0x5104C
#define REG_BACAM0_ENTRY05              0x51050
#define REG_BACAM1_ENTRY05              0x51054
#define REG_BACAM2_ENTRY05              0x51058
#define REG_BACAM3_ENTRY05              0x5105C
#define REG_BACAM0_ENTRY06              0x51060
#define REG_BACAM1_ENTRY06              0x51064
#define REG_BACAM2_ENTRY06              0x51068
#define REG_BACAM3_ENTRY06              0x5106C
#define REG_BACAM0_ENTRY07              0x51070
#define REG_BACAM1_ENTRY07              0x51074
#define REG_BACAM2_ENTRY07              0x51078
#define REG_BACAM3_ENTRY07              0x5107C
#define REG_BACAM0_ENTRY08              0x51080
#define REG_BACAM1_ENTRY08              0x51084
#define REG_BACAM2_ENTRY08              0x51088
#define REG_BACAM3_ENTRY08              0x5108C
#define REG_BACAM0_ENTRY09              0x51090
#define REG_BACAM1_ENTRY09              0x51094
#define REG_BACAM2_ENTRY09              0x51098
#define REG_BACAM3_ENTRY09              0x5109C
#define REG_BACAM0_ENTRY10              0x510A0
#define REG_BACAM1_ENTRY10              0x510A4
#define REG_BACAM2_ENTRY10              0x510A8
#define REG_BACAM3_ENTRY10              0x510AC
#define REG_BACAM0_ENTRY11              0x510B0
#define REG_BACAM1_ENTRY11              0x510B4
#define REG_BACAM2_ENTRY11              0x510B8
#define REG_BACAM3_ENTRY11              0x510BC
#define REG_BACAM0_ENTRY12              0x510C0
#define REG_BACAM1_ENTRY12              0x510C4
#define REG_BACAM2_ENTRY12              0x510C8
#define REG_BACAM3_ENTRY12              0x510CC
#define REG_BACAM0_ENTRY13              0x510D0
#define REG_BACAM1_ENTRY13              0x510D4
#define REG_BACAM2_ENTRY13              0x510D8
#define REG_BACAM3_ENTRY13              0x510DC
#define REG_BACAM0_ENTRY14              0x510E0
#define REG_BACAM1_ENTRY14              0x510E4
#define REG_BACAM2_ENTRY14              0x510E8
#define REG_BACAM3_ENTRY14              0x510EC
#define REG_BACAM0_ENTRY15              0x510F0
#define REG_BACAM1_ENTRY15              0x510F4
#define REG_BACAM2_ENTRY15              0x510F8
#define REG_BACAM3_ENTRY15              0x510FC
#define REG_BACAM0_ENTRY16              0x51100
#define REG_BACAM1_ENTRY16              0x51104
#define REG_BACAM2_ENTRY16              0x51108
#define REG_BACAM3_ENTRY16              0x5110C
#define REG_BACAM0_ENTRY17              0x51110
#define REG_BACAM1_ENTRY17              0x51114
#define REG_BACAM2_ENTRY17              0x51118
#define REG_BACAM3_ENTRY17              0x5111C
#define REG_BACAM0_ENTRY18              0x51120
#define REG_BACAM1_ENTRY18              0x51124
#define REG_BACAM2_ENTRY18              0x51128
#define REG_BACAM3_ENTRY18              0x5112C
#define REG_BACAM0_ENTRY19              0x51130
#define REG_BACAM1_ENTRY19              0x51134
#define REG_BACAM2_ENTRY19              0x51138
#define REG_BACAM3_ENTRY19              0x5113C
#define REG_BACAM0_ENTRY20              0x51140
#define REG_BACAM1_ENTRY20              0x51144
#define REG_BACAM2_ENTRY20              0x51148
#define REG_BACAM3_ENTRY20              0x5114C
#define REG_BACAM0_ENTRY21              0x51150
#define REG_BACAM1_ENTRY21              0x51154
#define REG_BACAM2_ENTRY21              0x51158
#define REG_BACAM3_ENTRY21              0x5115C
#define REG_BACAM0_ENTRY22              0x51160
#define REG_BACAM1_ENTRY22              0x51164
#define REG_BACAM2_ENTRY22              0x51168
#define REG_BACAM3_ENTRY22              0x5116C
#define REG_BACAM0_ENTRY23              0x51170
#define REG_BACAM1_ENTRY23              0x51174
#define REG_BACAM2_ENTRY23              0x51178
#define REG_BACAM3_ENTRY23              0x5117C
#define REG_BACAM0_ENTRY24              0x51180
#define REG_BACAM1_ENTRY24              0x51184
#define REG_BACAM2_ENTRY24              0x51188
#define REG_BACAM3_ENTRY24              0x5118C
#define REG_BACAM0_ENTRY25              0x51190
#define REG_BACAM1_ENTRY25              0x51194
#define REG_BACAM2_ENTRY25              0x51198
#define REG_BACAM3_ENTRY25              0x5119C
#define REG_BACAM0_ENTRY26              0x511A0
#define REG_BACAM1_ENTRY26              0x511A4
#define REG_BACAM2_ENTRY26              0x511A8
#define REG_BACAM3_ENTRY26              0x511AC
#define REG_BACAM0_ENTRY27              0x511B0
#define REG_BACAM1_ENTRY27              0x511B4
#define REG_BACAM2_ENTRY27              0x511B8
#define REG_BACAM3_ENTRY27              0x511BC
#define REG_BACAM0_ENTRY28              0x511C0
#define REG_BACAM1_ENTRY28              0x511C4
#define REG_BACAM2_ENTRY28              0x511C8
#define REG_BACAM3_ENTRY28              0x511CC
#define REG_BACAM0_ENTRY29              0x511D0
#define REG_BACAM1_ENTRY29              0x511D4
#define REG_BACAM2_ENTRY29              0x511D8
#define REG_BACAM3_ENTRY29              0x511DC
#define REG_BACAM0_ENTRY30              0x511E0
#define REG_BACAM1_ENTRY30              0x511E4
#define REG_BACAM2_ENTRY30              0x511E8
#define REG_BACAM3_ENTRY30              0x511EC
#define REG_BACAM0_ENTRY31              0x511F0
#define REG_BACAM1_ENTRY31              0x511F4
#define REG_BACAM2_ENTRY31              0x511F8
#define REG_BACAM3_ENTRY31              0x511FC
#define REG_MBIDCAM0_ENTRY00            0x51800
#define REG_MBIDCAM1_ENTRY00            0x51804
#define REG_MBIDCAM0_ENTRY01            0x51808
#define REG_MBIDCAM1_ENTRY01            0x5180C
#define REG_MBIDCAM0_ENTRY02            0x51810
#define REG_MBIDCAM1_ENTRY02            0x51814
#define REG_MBIDCAM0_ENTRY03            0x51818
#define REG_MBIDCAM1_ENTRY03            0x5181C
#define REG_MBIDCAM0_ENTRY04            0x51820
#define REG_MBIDCAM1_ENTRY04            0x51824
#define REG_MBIDCAM0_ENTRY05            0x51828
#define REG_MBIDCAM1_ENTRY05            0x5182C
#define REG_MBIDCAM0_ENTRY06            0x51830
#define REG_MBIDCAM1_ENTRY06            0x51834
#define REG_MBIDCAM0_ENTRY07            0x51838
#define REG_MBIDCAM1_ENTRY07            0x5183C
#define REG_MBIDCAM0_ENTRY08            0x51840
#define REG_MBIDCAM1_ENTRY08            0x51844
#define REG_MBIDCAM0_ENTRY09            0x51848
#define REG_MBIDCAM1_ENTRY09            0x5184C
#define REG_MBIDCAM0_ENTRY10            0x51850
#define REG_MBIDCAM1_ENTRY10            0x51854
#define REG_MBIDCAM0_ENTRY11            0x51858
#define REG_MBIDCAM1_ENTRY11            0x5185C
#define REG_MBIDCAM0_ENTRY12            0x51860
#define REG_MBIDCAM1_ENTRY12            0x51864
#define REG_MBIDCAM0_ENTRY13            0x51868
#define REG_MBIDCAM1_ENTRY13            0x5186C
#define REG_MBIDCAM0_ENTRY14            0x51870
#define REG_MBIDCAM1_ENTRY14            0x51874
#define REG_MBIDCAM0_ENTRY15            0x51878
#define REG_MBIDCAM1_ENTRY15            0x5187C
#define REG_MBIDCAM0_ENTRY16            0x51880
#define REG_MBIDCAM1_ENTRY16            0x51884
#define REG_MBIDCAM0_ENTRY17            0x51888
#define REG_MBIDCAM1_ENTRY17            0x5188C
#define REG_MBIDCAM0_ENTRY18            0x51890
#define REG_MBIDCAM1_ENTRY18            0x51894
#define REG_MBIDCAM0_ENTRY19            0x51898
#define REG_MBIDCAM1_ENTRY19            0x5189C
#define REG_MBIDCAM0_ENTRY20            0x518A0
#define REG_MBIDCAM1_ENTRY20            0x518A4
#define REG_MBIDCAM0_ENTRY21            0x518A8
#define REG_MBIDCAM1_ENTRY21            0x518AC
#define REG_MBIDCAM0_ENTRY22            0x518B0
#define REG_MBIDCAM1_ENTRY22            0x518B4
#define REG_MBIDCAM0_ENTRY23            0x518B8
#define REG_MBIDCAM1_ENTRY23            0x518BC
#define REG_MBIDCAM0_ENTRY24            0x518C0
#define REG_MBIDCAM1_ENTRY24            0x518C4
#define REG_MBIDCAM0_ENTRY25            0x518C8
#define REG_MBIDCAM1_ENTRY25            0x518CC
#define REG_MBIDCAM0_ENTRY26            0x518D0
#define REG_MBIDCAM1_ENTRY26            0x518D4
#define REG_MBIDCAM0_ENTRY27            0x518D8
#define REG_MBIDCAM1_ENTRY27            0x518DC
#define REG_MBIDCAM0_ENTRY28            0x518E0
#define REG_MBIDCAM1_ENTRY28            0x518E4
#define REG_MBIDCAM0_ENTRY29            0x518E8
#define REG_MBIDCAM1_ENTRY29            0x518EC
#define REG_MBIDCAM0_ENTRY30            0x518F0
#define REG_MBIDCAM1_ENTRY30            0x518F4
#define REG_MBIDCAM0_ENTRY31            0x518F8
#define REG_MBIDCAM1_ENTRY31            0x518FC
#define REG_DUMMY                       0x51900
#define REG_ADDRESSCAM_ENTRY00          0x51C00
#define REG_ADDRESSCAM_ENTRY01          0x51C04
#define REG_ADDRESSCAM_ENTRY02          0x51C08
#define REG_ADDRESSCAM_ENTRY03          0x51C0C
#define REG_ADDRESSCAM_ENTRY04          0x51C10
#define REG_ADDRESSCAM_ENTRY05          0x51C14
#define REG_ADDRESSCAM_ENTRY06          0x51C18
#define REG_ADDRESSCAM_ENTRY07          0x51C1C
#define REG_ADDRESSCAM_ENTRY08          0x51C20
#define REG_ADDRESSCAM_ENTRY09          0x51C24
#define REG_ADDRESSCAM_ENTRY10          0x51C28
#define REG_ADDRESSCAM_ENTRY11          0x51C2C
#define REG_CSI_BUFFER                  0x52000
#define REG_PHSTS_BUFFER                0x54000

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