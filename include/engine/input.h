#ifndef INPUT_H
#define INPUT_H
#include "../common.h"
#define INPUT_NUM_KEYS SDL_SCANCODE_COUNT
typedef struct Input {
  bool currentKeys[INPUT_NUM_KEYS];
  bool previousKeys[INPUT_NUM_KEYS];
} Input;
Input *InputCreate();
void InputDestroy(Input *input);
void InputUpdate(Input *input);
bool InputIsKeyDown(Input *input, SDL_Scancode sdlScanCode);
bool InputIsKeyPressed(Input *input, SDL_Scancode sdlScanCode);
bool InputIsKeyReleased(Input *input, SDL_Scancode sdlScaneCode);
#endif