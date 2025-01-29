#pragma once
#include <raylib.h>

typedef struct {
    char id[32];
    Texture2D texture;
    Vector2 position;
} Object;

typedef struct {
    Object *objects;
    int object_count;
} Scene;

extern Scene SKELD_SCENE;

Scene LoadScene(Scene *scene);

void DrawScene(Scene scene);

void UnloadScene(Scene scene);
