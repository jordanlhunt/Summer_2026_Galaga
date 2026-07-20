#ifndef WINDOW_H
#define WINDOW_H
#include <SDL3/SDL.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct Window {
  SDL_Window *sdlWindow;
  SDL_Renderer *sdlRenderer;
  bool isRunning;
} Window;

Window *WindowCreate(const char *title, int width, int height);
void WindowDestroy(Window *window);
bool WindowPollEvents(Window *window);
void *WindowGetRenderer(Window *window);
#endif