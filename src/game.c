#include "game.h"
#include <cstdint>

static SDL_Texture *CreateSolidTexture(SDL_Renderer *sdlRenderer, int width,
                                       int height, Uint8 red, Uint8 green,
                                       Uint8 blue) {
  SDL_Surface *sdlSurface =
      SDL_CreateSurface(width, height, SDL_PIXELFORMAT_RGBA8888);

  if (sdlSurface == NULL) {
    return NULL;
  }
  Uint32 color = SDL_MapRGBA(SDL_GetPixelFormatDetails(sdlSurface->format),
                             NULL, red, green, blue, 255);
  SDL_Texture *sdlTexture =
      SDL_CreateTextureFromSurface(sdlRenderer, sdlSurface);
  SDL_DestroySurface(sdlSurface);
  return texture;
}

Game *GameCreate(const char *title, int width, int height) {
  Game *game = malloc(sizeof(Game));
  if (game == NULL) {
    return NULL;
  }
  game->window = WindowCreate(title, width, height);
  if (game->window == NULL) {
    free(game);
    return NULL;
  }
  game->timer = TimerCreate();
  if (game->timer == NULL) {
    WindowDestroy(game->window);
    free(game);
    return NULL;
  }
  // Subsystems
  game->input = InputCreate();
  if (game->input == NULL) {
    TimerDestroy(game->timer);
    WindowDestroy(game->window);
    return NULL;
  }
  game->sdlRenderer = (SDL_Renderer *)WindowGetRenderer(game->window);
  game->gameTime = 0.0;
  game->isRunning = true;
  return game;
}
void GameDestroy(Game *game) {
  if (game == NULL) {
    return;
  }
  if (game->input) {
    InputDestroy(game->input);
  }
  if (game->timer) {
    TimerDestroy(game->timer);
  }
  if (game->window) {
    WindowDestroy(game->window);
  }
  free(game);
}
static void GameUpdate(Game *game, double deltaTime) {
  game->gameTime += deltaTime;
  if (InputIsKeyPressed(game->input, SDL_SCANCODE_SPACE)) {
    printf("[game.c - GameUpdate()] - Spacebar has been pressed\n");
  }
}
static void GameRender(Game *game) {
  SDL_SetRenderDrawColor(game->sdlRenderer, 100, 149, 237, 255);
  SDL_RenderClear(game->sdlRenderer);
  SDL_RenderPresent(game->sdlRenderer);
}

void GameRun(Game *game) {
  if (game == NULL) {
    return;
  }

  double accumulator = 0.0;

  while (game->isRunning) {
    double frameTime = TimerTick(game->timer);
    if (frameTime > 0.25) {
      frameTime = 0.25;
    }
    accumulator += frameTime;

    while (accumulator >= DELTA_TIME) {
      game->isRunning = WindowPollEvents(game->window);
      InputUpdate(game->input);
      GameUpdate(game, DELTA_TIME);
      accumulator -= DELTA_TIME;
    }

    GameRender(game);
    TimerCapFramesPerSecond(game->timer, 144.0);
  }
}
