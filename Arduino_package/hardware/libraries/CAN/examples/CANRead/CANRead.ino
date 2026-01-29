#include <AmebaCAN.h>

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
    Serial.begin(115200);
    while (!Serial) { }

    if (!CAN0.begin(CanBitRate::BR_250k))
    {
        Serial.println("CAN0.begin(...) failed.");
        for (;;) {}
    }
}

void loop()
{
    if (CAN0.available())
    {
        CanMsg const msg = CAN0.read();
        Serial.println(msg);
    }
}
