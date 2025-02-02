#pragma once
#include <raylib.h>
#include "player.h"

typedef struct {
    int id;
    Rectangle bounds;
    Vector2 *points;
    int point_count;
    bool active;
} Collision;

typedef struct {
    const char *id;
    Collision *collisions;
    int collision_count;
} CollisionMap;

extern CollisionMap SKELD[];

bool CheckCollision(CollisionMap map, Player *player);

void DrawCollision(CollisionMap map);
