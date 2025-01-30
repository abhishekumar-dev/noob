#pragma once
#include <raylib.h>

typedef enum {
    Top,
    Bottom
} Alignment;

typedef struct {
    int frame_count;
    int current_frame;
    float speed;
    float timer;
    int direction;
    Texture2D *sprites;
    Vector2 size;
} Animation;

Animation LoadAnimation(const char *id, int frame_count);

void UpdateAnimation(Animation *animation);

void DrawAnimation(Animation animation, Vector2 position, float rotation, float scale, Alignment alignment);

void UnloadAnimation(Animation animation);
