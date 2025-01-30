#include <raylib.h>
#include "animation.h"
#include "scene.h"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "noob");

    Animation walk = LoadAnimation("./assets/Walk", 12);
    Scene skeld = LoadScene(&SKELD_SCENE);
    Camera2D camera = {
        .target = {0},
        .zoom = 1.7f
    };

    while (!WindowShouldClose()) {
        UpdateAnimation(&walk);

        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(camera);
        DrawScene(skeld);
        EndMode2D();
        DrawAnimation(walk, (Vector2){0}, 0, 0.5f, Bottom);
        EndDrawing();
    }

    UnloadAnimation(walk);
    UnloadScene(skeld);
    CloseWindow();
}
