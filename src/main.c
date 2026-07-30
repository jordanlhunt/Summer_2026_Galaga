#include "../include/main.h"
int main() {
  Game *game = GameCreate("MOBY - ★ OUTLAW PIRATE STARFIGHTER ★", 800, 600);
  if (game == NULL) {
    return 1;
  }
  GameRun(game);
  GameDestroy(game);
  return 0;
}