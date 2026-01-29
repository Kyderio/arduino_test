#include <AmebaCAN.h>

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static uint32_t const CAN_ID = 0x20;

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
    if (!CAN1.begin(CanBitRate::BR_250k))
    {
        Serial.println("CAN0.begin(...) failed.");
        for (;;) {}
    }
}

static uint32_t msg_cnt = 0;

void loop()
{
    /* Assemble a CAN message with the format of
    * 0xCA 0xFE 0x00 0x00 [4 byte message counter]
    */
    uint8_t const msg_data[] = {0xCA,0xFE,0,0,0,0,0,0};
    memcpy((void *)(msg_data + 4), &msg_cnt, sizeof(msg_cnt));
    CanMsg const msgWrite(CanStandardId(CAN_ID), sizeof(msg_data), msg_data);

    /* Transmit the CAN message, capture and display an
    * error core in case of failure.
    */
    int const rc = CAN0.write(msgWrite);
    if (rc < 0)
    {
        Serial.print  ("CAN0.write(...) failed with error code ");
        Serial.println(rc);
        for (;;) { }
    }

    if (CAN1.available())
    {
        CanMsg const msgRead = CAN1.read();
        Serial.println(msgRead);
    }
    else
    {
        Serial.println("No msg");
    }

    /* Increase the message counter. */
    msg_cnt++;

    /* Only send one message per second. */
    delay(1000);
}
