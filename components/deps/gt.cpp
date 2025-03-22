//=============================================================================
//=============================================================================
#define GT_CPP
//=============================================================================
#include "misc.h"
#include "gt.h"
//=============================================================================
uint64                          global_timer;
static uint64                   _gt;
static esp_timer_handle_t       timerHandle;
//=============================================================================
void timer_cb(void* arg)
{
    vTaskSuspendAll();
    _gt = esp_timer_get_time()/1000;
    xTaskResumeAll();
}
//---------------------------
void GT_Init()
{
    const esp_timer_create_args_t timer_args = {
        .callback = timer_cb,
        .arg = nullptr,
        .dispatch_method = ESP_TIMER_TASK,
        .name = "gt",
        .skip_unhandled_events = false
    };
    ESP_ERROR_CHECK(esp_timer_create(&timer_args, &timerHandle));
    ESP_ERROR_CHECK(esp_timer_start_periodic(timerHandle, 1000));
}
//---------------------------
void GT_Poll()
{
    global_timer = _gt;
}
//=============================================================================
