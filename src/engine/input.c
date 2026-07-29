#include "engine/input.h"

Input *InputCreate() {
  Input *input = malloc(sizeof(Input));
  if (input == NULL) {
    return NULL;
  }
  memset(input->currentKeys, 0, sizeof(input->currentKeys));
  memset(input->previousKeys, 0, sizeof(input->previousKeys));
}
void InputDestroy(Input *input) { free(input); }
void InputUpdate(Input *input) {
  // Move current frame's state into previous
  memccpy(input->previousKeys, input->currentKeys, sizeof(input->previousKeys));
  int numkeys;
  const bool *currentKeyboardStateArray = SDL_GetKeyboardState(&numkeys);
  int count;
  if (numkeys < INPUT_NUM_KEYS) {
    count = numkeys;
  } else {
    numkeys = INPUT_NUM_KEYS;
  }
  memcpy(input->currentKeys, currentKeyboardStateArray, (count * sizeof(bool)));
}
bool InputIsKeyDown(Input *input, SDL_Scancode sdlScanCode) {
  return input->currentKeys[sdlScanCode];
}

bool InputIsKeyPressed(Input *input, SDL_Scancode sdlScanCode) {
  return (input->currentKeys[sdlScanCode]) &&
         !(input->previousKeys[sdlScanCode]);
}