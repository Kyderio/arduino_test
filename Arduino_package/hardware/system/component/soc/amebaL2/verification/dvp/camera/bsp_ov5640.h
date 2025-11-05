#ifndef __OV5640_H
#define	__OV5640_H

/* store camera id */
typedef struct {
	uint8_t PIDH;
	uint8_t PIDL;
} OV5640_IDTypeDef;


/* RTK-OV5640 output image format */
typedef enum {
	RTK_OV5640_OUTPUT_FORMAT_RGB565 = 0x00,     /* RGB565 */
	RTK_OV5640_OUTPUT_FORMAT_JPEG,              /* JPEG */
	RTK_OV5640_OUTPUT_FORMAT_YUV422,            /* YUV422 */
} rtk_ov5640_output_format_t;

#define OV5640_SENSOR_PIDH       0x300A
#define OV5640_SENSOR_PIDL       0x300B

void OV5640_HW_Init(void);
// void OV5640_I2C_Init(void);
void OV5640_Reset(void);
void OV5640_ReadID(OV5640_IDTypeDef *OV5640ID);
void OV5640_Init(void);
// void OV5640_QQVGAConfig(void);
// void OV5640_WVGAConfig(void);
// void OV5640_RGB565Config(void);

uint8_t OV5640_WriteReg(uint16_t Addr, uint8_t Data);
uint8_t OV5640_ReadReg(uint16_t Addr);
// uint8_t OV5640_WriteFW(uint8_t *pBuffer ,uint16_t BufferSize);

#endif /* __DCMI_OV5640_H */

