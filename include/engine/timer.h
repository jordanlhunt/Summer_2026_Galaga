#ifndef TIMER_H
#define TIMER_H
#include "../common.h"

typedef struct Timer {
  uint64_t performanceFrequency;
  uint64_t performanceCounter;
} Timer;

Timer *TimerCreate();
void TimerDestroy(Timer *timer);
double TimerTick(Timer *timer);
void TimerCapFramesPerSecond(Timer *timer, double targetFps);
#endif