#pragma once
#include <raylib.h>
#include "animation.h"

typedef struct {
    Vector2 position;
    int direction;
    float speed;
    bool moving;
    Vector2 size;
} Player;

void UpdatePlayer(Player *player);

void DrawPlayer(Animation walk, Texture2D Idle, Player player, float scale);
