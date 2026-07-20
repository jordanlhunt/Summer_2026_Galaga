#include "../include/engine/window.h"
#include "SDL3/SDL.h"
#include <SDL3/SDL_render.h>

int main(void) {
  Window *gameWindow =
      WindowCreate("MOBY - OUTLAW PIRATE STARFIGHTER", 224, 288);
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