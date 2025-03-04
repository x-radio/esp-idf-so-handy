//=============================================================================
//===GLOBAL_TIMER_H============================================================
/*Arduino - только 1000 тиков в секунде*/
//=============================================================================
#ifndef GT_H
#define GT_H
//===Defines===================================================================
#define GT_TICKINSEC      	1000UL                  //тиков в секунде
#define GT_TICKINMIN        GT_TICKINSEC*60         //тиков в минуте
#define GT_TICKINHOUR     	GT_TICKINSEC*3600       //тиков в часе
#define GT_MSEC(x)          ((x)*GT_TICKINSEC/1000) //
#define GT_SEC(x)           ((x)*GT_TICKINSEC)     	//
#define GT_MIN(x)           ((x)*GT_TICKINMIN)     	//
#define GT_HOUR(x)          ((x)*GT_TICKINHOUR)     //
//===Variables=================================================================
#ifndef GT_CPP
extern uint64               global_timer;
#endif
//===Functions=================================================================
void GT_Init(void);
void GT_Poll(void);
void GT_Handler(void);
void GT_Test(uint8);
//=============================================================================
// }
#endif
