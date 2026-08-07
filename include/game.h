#ifndef GAME_H
#define GAME_H
#define TARGET_UPDATES_PER_SECOND 60.0
#define DELTA_TIME (1.0 / TARGET_UPDATES_PER_SECOND)
#include "common.h"
#include "engine/entity.h"
#include "engine/input.h"
#include "engine/timer.h"
#include "engine/window.h"
typedef struct Game {
  Window *window;
  Timer *timer;
  Input *input;
  SDL_Renderer *sdlRenderer;
  double gameTime;
  bool isRunning;
} Game;
Game *GameCreate(const char *title, int width, int height);
void GameRun(Game *game);
void GameDestroy(Game *game);
#endif
