#include "engine/timer.h"

Timer *TimerCreate() {
  Timer *newTimer = malloc(sizeof(Timer));
  if (newTimer == NULL) {
    return NULL;
  }
  newTimer->performanceFrequency = SDL_GetPerformanceFrequency();
  newTimer->performanceCounter = SDL_GetPerformanceCounter();
  return newTimer;
}
void TimerDestroy(Timer *timer) { free(timer); }
double TimerTick(Timer *timer) {
  uint64_t currentPerformanceCounter = SDL_GetPerformanceCounter();
  uint64_t deltaTime = currentPerformanceCounter - timer->performanceCounter;
  return ((double)deltaTime / (double)timer->performanceFrequency);
}
void TimerCapFramesPerSecond(Timer *timer, double targetFps) {
  double targetFramePerSecond = 1.0 / targetFps;
  uint64_t now = SDL_GetPerformanceCounter();
  double elapsedTime = (double)(now - timer->performanceCounter) /
                       (double)timer->performanceFrequency;
  if (elapsedTime < targetFramePerSecond) {
    double sleepTime =
        (targetFramePerSecond - elapsedTime) * 1000.0; // milliseconds
    SDL_Delay((uint32_t)sleepTime);
    timer->performanceCounter +=
        (uint64_t)(sleepTime * timer->performanceFrequency / 1000.0);
  }
}