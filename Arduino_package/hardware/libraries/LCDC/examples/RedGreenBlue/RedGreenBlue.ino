#include <LCDC.h>

uint8_t *PIX_DATA0 = NULL;
uint8_t *PIX_DATA1 = NULL;
uint8_t *PIX_DATA2 = NULL;
uint32_t counter = 0;
uint32_t index = 0;
const bool user_buffer = false;
AmebaLCDC lcdc(user_buffer);

static void fill_framebuf(uint32_t width, uint32_t height, uint32_t depth)
{
    uint32_t i;

    for (i = 0; i < width*height*depth/8; i = i + depth/8) {
        /* buffer0: red */
        PIX_DATA0[i] = 0x00;
        PIX_DATA0[i + 1] = 0x00;
        PIX_DATA0[i + 2] = 0xFF;

        /* buffer1: green */
        PIX_DATA1[i] = 0x00;
        PIX_DATA1[i + 1] = 0xFF;
        PIX_DATA1[i + 2] = 0x00;

        if (user_buffer == true) {
            /* buffer2: blue */
            PIX_DATA2[i] = 0xFF;
            PIX_DATA2[i + 1] = 0x00;
            PIX_DATA2[i + 2] = 0x00;
        }
    }
    DCache_Clean((u32)PIX_DATA0, width*height*depth/8);
    DCache_Clean((u32)PIX_DATA1, width*height*depth/8);
    if (user_buffer == true)
        DCache_Clean((u32)PIX_DATA2, width*height*depth/8);
}

static void flush_frame(void *data) {
    if (counter == 0) {
        if (user_buffer == true) {
            /* display red green blue cyclically */
            if (index % 3 == 0) {
                lcdc.inform_render_done(PIX_DATA0);
            } else if (index % 3 == 1) {
                lcdc.inform_render_done(PIX_DATA1);
            } else {
                lcdc.inform_render_done(PIX_DATA2);
            }
        } else {
            /* display red green cyclically */
            if (index % 2 == 0) {
                lcdc.inform_render_done(PIX_DATA0);
            } else {
                lcdc.inform_render_done(PIX_DATA1);
            }
        }
        index++;
    }

    if (counter++ == 50)
        counter = 0;
}

void setup() {
    uint32_t width, height, depth;
    Serial.begin(115200);  // start serial for output

    lcdc.get_info(&width, &height, &depth);

    if (user_buffer == true) {
        PIX_DATA0 = (uint8_t *)malloc(width*height*depth/8);
        if (PIX_DATA0 == NULL) {
            Serial.println("Allocate PIX_DATA0 fail!!!");
            return;
        }
        PIX_DATA1 = (uint8_t *)malloc(width*height*depth/8);
        if (PIX_DATA1 == NULL) {
            Serial.println("Allocate PIX_DATA1 fail!!!");
            return;
        }
        PIX_DATA2 = (uint8_t *)malloc(width*height*depth/8);
        if (PIX_DATA2 == NULL) {
            Serial.println("Allocate PIX_DATA2 fail!!!");
            return;
        }
    } else {
        PIX_DATA0 = lcdc.get_buffer(0);
        PIX_DATA1 = lcdc.get_buffer(1);
    }
    
    fill_framebuf(width, height, depth);

    lcdc.register_callback(flush_frame, NULL);
    lcdc.begin(&lcdc);
    Serial.println("Setup done!!!");
}

void loop() {

}