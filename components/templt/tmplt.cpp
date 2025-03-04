//=============================================================================
//=============================================================================
#define TMPLT_CPP
//=============================================================================
#include "misc.h"
#include "gt.h"
//=============================================================================
#define INTRVL                  GT_MSEC(1000)
//=============================================================================
static uint64       			timer = GT_MSEC(2000);
static uint8        			state;
static const char*              TAG = "[TM]";
//=============================================================================
static void staticFunc();
//---------------------------
void TMPLT_Poll()
{
    // volatile static uint32 temp;
    // volatile static uint32 cntr = 0;
    //-----------------------
    uint64& gt = global_timer;
    if (timer > gt) return;
    timer += INTRVL;
    //-----------------------
    static uint8 oldSt = 255;
    if(oldSt != state){logv("state - %d", state); oldSt = state;}
    //-----------------------
    switch (state){
    //-----------------------
    case 0:
        logi("some");
        return;
    //-----------------------
    case 1:

        return;
    //-----------------------
    case 2:

        return;
}}
//---------------------------
void staticFunc()
{
    return;
}
//=============================================================================
