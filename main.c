#include <raylib.h>
#include "scene.h"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "noob");

    Scene skeld = LoadScene(&SKELD_SCENE);
    Camera2D camera = {
        .target = {0},
        .zoom = 1.7f
    };

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(camera);
        DrawScene(skeld);
        EndMode2D();
        EndDrawing();
    }

    UnloadScene(skeld);
    CloseWindow();
}