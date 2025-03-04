//=============================================================================
//=============================================================================
#include "misc.h"
#include "gt.h"
//=============================================================================
extern "C" void app_main()
{
    initArduino();
    Serial.begin(115200);
    vTaskPrioritySet(NULL, 0);

    GT_Init();

    while (true)
    {
        GT_Poll();

        yield();
    }
}
//=============================================================================
