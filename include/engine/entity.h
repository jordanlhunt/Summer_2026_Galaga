#ifndef ENTITY_H
#include "../common.h"
#define MAX_ENTITIES 256

typedef enum ENTITY_TYPE {
  ENTITY_NONE,
  ENTITY_PLAYER,
  ENTITY_ENEMY,
  ENTITY_BULLET_PLAYER,
  ENTITY_BULLET_ENEMY
} ENTITY_TYPE;
typedef struct Entity {
  float positionX;
  float positionY;
  float velocityX;
  float velocityY;
  int width;
  int height;
  SDL_Texture *sdlTexture;
  bool isActive;
  int entityType;
  int hitpoints;
  float timer;
} Entity;

extern Entity entities[MAX_ENTITIES];
extern int entityCount;

void EntityInitialize();
void EntitySpawn(int type, float x, float y, SDL_Texture *sdlTexture, int width,
                 int height);
void EntityDestroy(Entity *entity);
void EntityUpdateAll(float deltaTime);
void EntityRenderAll(SDL_Renderer *sdlRenderer);
#endif
