//=============================================================================
//=============================================================================
/**/
//=============================================================================
#define GT_CPP
//=============================================================================
#include "misc.h"
#include "gt.h"
#include "mycomp.h"
//=============================================================================
#define INTRVL                  GT_MSEC(1000)
//=============================================================================
uint64              	        _gt, global_timer;
static uint64       			timer = GT_MSEC(2000);
static uint8        			state;
static esp_timer_handle_t       timerHandle;
static const char*              TAG = "[GT]";
//=============================================================================
static inline void timer_cb(void* arg);
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
void GT_Handler()
{
    global_timer = _gt;
}
//---------------------------
void GT_Poll()
{
    // volatile static uint32 temp;
    // volatile static uint32 cntr = 0;
    //-----------------------
    uint64& gt = global_timer;
    if (timer > gt) return;
    timer += INTRVL;
    //-----------------------
    static uint8 oldState = 99;
    if(oldState != state){logd("state - %d", state); oldState = state;}
    //-----------------------
    switch (state){
    //-----------------------
    case 0:
        state = 1;
        return;
    //-----------------------
    case 1:
        logi("info"); mycomp();
        state = 2;
        return;
    //-----------------------
    case 2:
        logi("info");
        state = 1;
        return;
    //-----------------------
    case 3:
        char buf[256];
        vTaskList(buf);
        logi("\n%s", buf);
        timer = gt + 5000;
        return;
}}
//---------------------------
void GT_Test(uint8 st)
{
    if(state == st) state = 97;
    else state = st;
}
//---------------------------
void timer_cb(void* arg)
{
    _gt = esp_timer_get_time()/1000;
}
//=============================================================================
