#include "../../include/engine/window.h"

Window *WindowCreate(const char *title, int width, int height) {
  // Create SDL SubSystems
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("SDL_Init failed: %s", SDL_GetError());
    return NULL;
  }
  Window *gameWindow = malloc(sizeof(Window));
  if (gameWindow == NULL) {
    return NULL;
  }
  gameWindow->sdlWindow =
      SDL_CreateWindow(title, width, height, SDL_WINDOW_HIDDEN);
  if (gameWindow->sdlWindow == NULL) {
    SDL_Log("SDL_CreateWindow failed: %s\n", SDL_GetError());
    free(gameWindow);
    SDL_Quit();
    return NULL;
  }
  gameWindow->sdlRenderer = SDL_CreateRenderer(gameWindow->sdlWindow, NULL);
  if (gameWindow->sdlRenderer == NULL) {
    SDL_Log("SDL_CreateRenderer failed: %s\n", SDL_GetError());
    free(gameWindow);
    SDL_Quit();
    return NULL;
  }
  // Set the logical size so coordinates are fixed
  SDL_SetRenderLogicalPresentation(gameWindow->sdlRenderer, width, height,
                                   SDL_LOGICAL_PRESENTATION_DISABLED);
  gameWindow->isRunning = true;

  return gameWindow;
}

void WindowDestroy(Window *window) {
  if (window == NULL) {
    return;
  }
  SDL_DestroyRenderer(window->sdlRenderer);
  SDL_DestroyWindow(window->sdlWindow);
  SDL_Quit();
  free(window);
}

bool WindowPollEvents(Window *window) {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_EVENT_QUIT) {
      window->isRunning = false;
    }
    if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) {
      window->isRunning = false;
    }
  }
  return window->isRunning;
}
void *WindowGetRenderer(Window *window) { return window->sdlRenderer; }
