#include <SPI.h>

void setup() {
    Serial.begin(115200);  // start serial for output
    SPI.begin();           // initialize SPI
    SPI1.begin();           // initialize SPI
}

void loop() {
    static uint8_t val = 0;
    uint8_t receivedVal = 0;

    SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0, SPI_CONTROLLER)); //config as controller
    SPI1.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0, SPI_PERIPHERAL)); //config as peripheral

    Serial.print("Controller send:");
    Serial.println(val);
    receivedVal = SPI.transfer(val);
    Serial.print("Controller received:");
    Serial.println(receivedVal);

    Serial.print("Peripheral send:");
    Serial.println(255-val);
    receivedVal = SPI1.transfer(255-val);
    Serial.print("Peripheral received:");
    Serial.println(receivedVal);

    SPI.endTransaction();
    SPI1.endTransaction();

    val++;

    delay(500);
}
