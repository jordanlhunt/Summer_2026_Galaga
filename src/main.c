#include "../include/main.h"
static double gameTime = 0.0;
static void GameUpdate(double deltaTime, Input *inputSystem) {
  gameTime += deltaTime;
  static double printTimer = 0.0;
  printTimer += deltaTime;
  if (printTimer >= 1.0) {
    printTimer = 0.0;
  }
  if (InputIsKeyPressed(inputSystem, SDL_SCANCODE_SPACE) == true) {
    printf("[main.c - GameUpdate()] - Spacebar has been pressed");
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

  // Systems
  Input *inputSystem = InputCreate();
  if (inputSystem == NULL) {
    TimerDestroy(timer);
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
      InputUpdate(inputSystem);
      GameUpdate(DELTA_TIME, inputSystem);
      accumulator -= DELTA_TIME;
    }
    GameRender(sdlRenderer);
    TimerCapFramesPerSecond(timer, 144.0);
  }
  InputDestroy(inputSystem);
  TimerDestroy(timer);
  WindowDestroy(gameWindow);
  return 0;
}