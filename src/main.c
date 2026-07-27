#include "../include/main.h"
static double gameTime = 0.0;
static void GameUpdate(double deltaTime) {
  gameTime += deltaTime;
  static double printTimer = 0.0;
  printTimer += deltaTime;
  if (printTimer >= 1.0) {
    printTimer = 0.0;
  }
}
static void GameRender(SDL_Renderer *sdlRenderer) {
  SDL_SetRenderDrawColor(sdlRenderer, 100, 149, 237, 255);
  SDL_RenderClear(sdlRenderer);
  SDL_RenderPresent(sdlRenderer);
}
int main(void) {
  Window *gameWindow =
      WindowCreate("MOBY - OUTLAW PIRATE STARFIGHTER", 800, 600);
  if (gameWindow == NULL) {
    return 1;
  }
  SDL_Renderer *sdlRenderer = (SDL_Renderer *)WindowGetRenderer(gameWindow);
  Timer *timer = TimerCreate();
  if (timer == NULL) {
    WindowDestroy(gameWindow);
    return 1;
  }
  double accumulator = 0.0;
  bool isRunning = true;
  while (isRunning) {
    double frameTime = TimerTick(timer);
    if (frameTime > .25) {
      frameTime = .25;
    }
    accumulator += frameTime;
    while (accumulator >= DELTA_TIME) {
      isRunning = WindowPollEvents(gameWindow);
      GameUpdate(DELTA_TIME);
      accumulator -= DELTA_TIME;
    }
    GameRender(sdlRenderer);
    TimerCapFramesPerSecond(timer, 144.0);
  }
  TimerDestroy(timer);
  WindowDestroy(gameWindow);
  return 0;
}