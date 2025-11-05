#ifndef __RTK_GC2145_H
#define __RTK_GC2145_H

typedef enum {
	RTK_GC2145_OUTPUT_FORMAT_RGB565 = 0x00,     /* RGB565 */
	RTK_GC2145_OUTPUT_FORMAT_YUV422,            /* YUV422 */
} rtk_gc2145_output_format_t;


typedef struct {
	uint8_t CHIP_IDH;
	uint8_t CHIP_IDL;
} GC2145_IDTypeDef;

void GC2145_HW_Init(void);
void GC2145_ReadID(GC2145_IDTypeDef *GC2145ID);
uint8_t GC2145_WriteReg(uint16_t Addr, uint8_t Data);
uint8_t GC2145_ReadReg(uint16_t Addr);
void gc2145_init_reg(void);
void gc2145_set_pixformat(rtk_gc2145_output_format_t pix_format);
int gc2145_set_framesize(framesize_t framesize);

#endif
