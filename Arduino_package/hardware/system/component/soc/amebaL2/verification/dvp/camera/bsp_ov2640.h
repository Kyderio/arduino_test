#ifndef __OV2640_H
#define	__OV2640_H

/* RTK-OV2640: option for sensor output color fomat */
typedef enum {
	RTK_OV2640_OUTPUT_FORMAT_RGB565 = 0x00,     /* RGB565 */
	RTK_OV2640_OUTPUT_FORMAT_JPEG,              /* JPEG */
	RTK_OV2640_OUTPUT_FORMAT_YUV,              /* YUV */
} rtk_image_output_format_t;

/* RTK-MC2640 select ov2640 register bank group */
typedef enum {
	RTK_OV2640_REG_BANK_DSP = 0x00, /* DSP bank */
	RTK_OV2640_REG_BANK_SENSOR,     /* Sensor bank */
} rtk_ov2640_reg_bank_t;

/* Image Sizes enumeration */
typedef enum {
	BMP_QQVGA             =   0x00,	    /* BMP Image QQVGA 160x120 Size */
	BMP_QVGA              =   0x01,      /* BMP Image VGA 800*480 Size */
	JPEG_160x120          =   0x02,	    /* JPEG Image 160x120 Size */
	JPEG_176x144          =   0x03,	    /* JPEG Image 176x144 Size */
	JPEG_320x240          =   0x04,	    /* JPEG Image 320x240 Size */
	JPEG_352x288          =   0x05	    /* JPEG Image 352x288 Size */
} ImageFormat_TypeDef;

typedef struct {
	uint8_t Manufacturer_ID1;
	uint8_t Manufacturer_ID2;
	uint8_t PIDH;
	uint8_t PIDL;
} OV2640_IDTypeDef;

#define OV2640_DEVICE_WRITE_ADDRESS    0x60
#define OV2640_DEVICE_READ_ADDRESS     0x61

void OV2640_HW_Init(void);
void OV2640_Reset(void);
void OV2640_ReadID(OV2640_IDTypeDef *OV2640ID);
void OV2640_Init(void);
uint8_t OV2640_WriteReg(uint16_t Addr, uint8_t Data);
uint8_t OV2640_ReadReg(uint16_t Addr);
// uint8_t OV2640_Reg_bank_select(rtk_ov2640_reg_bank_t bank);
void ov2640_init_reg(void);
uint8_t ov2640_set_output_format(rtk_image_output_format_t format);
uint8_t ov2640_set_output_size(uint16_t width, uint16_t height);


#endif


