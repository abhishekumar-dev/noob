#include <stdio.h>
#include <raylib.h>
#include "scene.h"

Object SKELD_OBJECTS[] = {
    {
        .id = "room_hallwaydown",
        .position = {414, 954}
    },
    {
        .id = "room_storage",
        .position = {81, 1246}
    },
    {
        .id = "room_cafeteria",
        .position = {0}
    }
};

Scene SKELD_SCENE = {
    .objects = SKELD_OBJECTS,
    .object_count = sizeof(SKELD_OBJECTS) / sizeof(SKELD_OBJECTS[0]),
};

Scene LoadScene(Scene *scene) {
    char src[128];
    for (int i = 0; i < scene->object_count; i++) {
        sprintf(src, "./assets/%s.png", scene->objects[i].id);
        scene->objects[i].texture = LoadTexture(src);
        SetTextureFilter(scene->objects[i].texture, TEXTURE_FILTER_BILINEAR);
    }
    return *scene;
}

void DrawScene(Scene scene) {
    for (int i = 0; i < scene.object_count; i++) {
        DrawTextureEx(scene.objects[i].texture, scene.objects[i].position, 0, 1.0f, WHITE);
    }
}

void UnloadScene(Scene scene) {
    for (int i = 0; i < scene.object_count; i++) {
        UnloadTexture(scene.objects[i].texture);
    }
}
