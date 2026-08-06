#include "engine/entity.h"

Entity entities[MAX_ENTITIES];
int entityCount = 0;

void EntityInitialize() {
  memset(entities, 0, sizeof(entities));
  entityCount = 0;
}

Entity *EntitySpawn(int entityType, float x, float y, SDL_Texture *sdlTexture,
                    int width, int height) {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (entities[i].isActive == false) {
      entities[i].isActive = true;
      entities[i].entityType = entityType;
      entities[i].positionX = x;
      entities[i].positionY = y;
      entities[i].sdlTexture = sdlTexture;
      entities[i].width = width;
      entities[i].height = height;
      entities[i].hitpoints = 1;
      entities[i].timer = 0.0f;
      entityCount += 1;
      return &entities[i];
    }
  }
  return NULL;
}
void EntityDestroy(Entity *entity) {
  if (entity != NULL && entity->isActive) {
    entity->isActive = false;
    entityCount -= 1;
  }
}
void EntityUpdateAll(float deltaTime) {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (entities[i].isActive) {
      entities[i].positionX += entities[i].velocityX * deltaTime;
      entities[i].positionY += entities[i].velocityY * deltaTime;
      if (entities[i].timer > 0.0f) {
        entities[i].timer -= deltaTime;
      }
    }
  }
}
void EntityRenderAll(SDL_Renderer *sdlRenderer) {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (entities[i].isActive && entities[i].sdlTexture != NULL) {
      SDL_Rect destinationRect = {.x = (int)entities[i].positionX,
                                  .y = (int)entities[i].positionY,
                                  .w = entities[i].width,
                                  .h = entities[i].height};
      SDL_RenderCopy(sdlRenderer, entities[i].sdlTexture, NULL,
                     &destinationRect);
    }
  }
}
