#include <SPI.h>

uint8_t buf[256];
void setup() {
    Serial.begin(115200);  // start serial for output
    SPI.begin();           // initialize SPI

    uint32_t i;
    for (i = 0; i < 256; ++i) {
        buf[i] = i;
    }
    SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0, SPI_CONTROLLER)); //config as controller
    SPI.transfer(buf, 256);
    SPI.endTransaction();
    Serial.print("Controller received buffer:");
    for (i = 0; i < 256; ++i) {
        Serial.println(buf[i]);
    }
}

void loop() {

    static uint8_t val = 0;
    uint8_t receivedVal = 0;

    SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0, SPI_CONTROLLER)); //config as controller

    Serial.print("Send:");
    Serial.println(val);
    receivedVal = SPI.transfer(val);
    Serial.print("Receive:");
    Serial.println(receivedVal);

    SPI.endTransaction();

    val++;

    delay(500);

}
