//=============================================================================
//=============================================================================
#include "misc.h"
#include "gt.h"
#include "cycleTool.h"
//=============================================================================
static uint64                   timer;
CycleTool                       tool("[MAIN]");
//=============================================================================
extern "C" void app_main()
{
    initArduino();
    Serial.begin(115200);
    esp_task_wdt_add(NULL);                                                     //twdt для IDLE1 отключен, включаем здесь
    esp_log_level_set("*", ESP_LOG_WARN);

    tool.enable();

    GT_Init();

    while (true)
    {
        tool.before();
        GT_Poll();


        tool.after();
        if(global_timer < timer) continue;
        esp_task_wdt_reset();
        timer++;
        taskYIELD();
    }
}
//=============================================================================
