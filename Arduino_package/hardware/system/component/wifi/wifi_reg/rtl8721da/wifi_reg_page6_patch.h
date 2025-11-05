#ifndef _RL6845_REG_PAGE6_PATCH_H_
#define _RL6845_REG_PAGE6_PATCH_H_

/** @defgroup REG_TCR_TSFT_OFS_AND_UDFL_CTL
 * @brief
 * @{
 **/
#define BIT_MASK_WMAC_TCR_TSFT_OFS_OFDM   ((u32)0x000000FF << 8)            /*!< R/W 0x4  BIT_WMAC_TCR_TSFT_OFS[15:8] is for ofdm rate time offset;*/
#define BIT_WMAC_TCR_TSFT_OFS_OFDM(x)     (((u32)((x) & 0x000000FF) << 8))
#define BIT_GET_WMAC_TCR_TSFT_OFS_OFDM(x) ((u32)(((x >> 8) & 0x000000FF)))
#define BIT_MASK_WMAC_TCR_TSFT_OFS_CCK   ((u32)0x000000FF << 0)            /*!< R/W 0x50  BIT_WMAC_TCR_TSFT_OFS[7:0] is for cck stamp time offset;*/
#define BIT_WMAC_TCR_TSFT_OFS_CCK(x)     (((u32)((x) & 0x000000FF) << 0))
#define BIT_GET_WMAC_TCR_TSFT_OFS_CCK(x) ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_WMAC_TCR_TSFT_OFS
 * @brief
 * @{
 **/
#define BIT_MASK_WMAC_TCR_TSFT_NS_OFS_OFDM              ((u32)0x000003FF << 10)          /*!<R/W 0  BIT_WMAC_TCR_TSFT_OFS[19:10] is for other rate time offset of ns part */
#define BIT_WMAC_TCR_TSFT_NS_OFS_OFDM(x)                (((u32)((x) & 0x000003FF) << 10))
#define BIT_GET_WMAC_TCR_TSFT_NS_OFS_OFDM(x)            ((u32)(((x >> 10) & 0x000003FF)))
#define BIT_MASK_WMAC_TCR_TSFT_NS_OFS_CCK              ((u32)0x000003FF << 0)          /*!<R/W 0  BIT_WMAC_TCR_TSFT_OFS[9:0] is for cck stamp time offset of ns part */
#define BIT_WMAC_TCR_TSFT_NS_OFS_CCK(x)                (((u32)((x) & 0x000003FF) << 0))
#define BIT_GET_WMAC_TCR_TSFT_NS_OFS_CCK(x)            ((u32)(((x >> 0) & 0x000003FF)))
/** @} */

#endif