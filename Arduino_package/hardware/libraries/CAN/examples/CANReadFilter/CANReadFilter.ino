#include <AmebaCAN.h>

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static uint32_t const CAN_ID = 0x20;
static int msg_num = 0;

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
    Serial.begin(115200);
    while (!Serial) { }

    AmebaCanFilter const rxFilter(CAN_ID, CAN_STD_ID_MASK, 0);
    CAN0.setRxFilter(rxFilter);

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
        msg_num++;
        if (msg_num == 1) {
            CAN0.removeRxFilter();
        }
    }
}
