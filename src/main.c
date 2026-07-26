#include "../include/main.h"

static double gameTime = 0.0;

static void GameUpdate(double deltaTime) {
  gameTime += deltaTime;
  static double printTimer = 0.0;
  printTimer += deltaTime;
  if (printTimer >= 1.0) {
    printf("Game time: %.2f seconds \n", gameTime);
    printTimer = 0.0;
  }
}
static void GameRender(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

int main(void) {
  Window *gameWindow =
      WindowCreate("MOBY - OUTLAW PIRATE STARFIGHTER", 800, 600);
  if (gameWindow == NULL) {
    return 1;
  }
  SDL_Renderer *renderer = (SDL_Renderer *)WindowGetRenderer(gameWindow);
  while (WindowPollEvents(gameWindow)) {
    SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }
  WindowDestroy(gameWindow);
  return 0;
}