#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>

typedef struct Timer Timer;

Timer *TimerCreate();
void TimerDestroy(Timer *timer);
double TimerTick(Timer *timer);
void TimerCapFramesPerSecond(Timer *timer, double targetFps);
#endif