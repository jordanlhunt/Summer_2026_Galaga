#include "../include/engine/window.h"

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