#include <raylib.h>
#include <stddef.h>
#include "animation.h"
#include "collision.h"
#include "player.h"
#include "scene.h"
#include "utils.h"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "noob");

    Scene skeld = LoadScene(&SKELD_SCENE);
    Animation walk = LoadAnimation("./assets/Walk", 12);
    Texture2D Idle = LoadTexture("./assets/Idle.png");
    Texture2D overlay = LoadTexture("./assets/overlay.png");
    Texture2D logo = LoadTexture("./assets/test.png");
    Font brook = LoadFontEx("./assets/fonts/Brook.otf", FPS_FONT_SIZE, NULL, 0);
    Player player = {
        .position = {444, 288},
        .direction = 1,
        .moving = false,
        .speed = 2.5f,
        .size = {
            .x = (float) Idle.width,
            .y = (float) Idle.height
        }
    };
    Camera2D camera = {
        .target = player.position,
        .offset = {
            .x = (float) GetScreenWidth() / 2,
            .y = (float) GetScreenHeight() / 2
        },
        .zoom = 1.7f
    };

    while (!WindowShouldClose()) {
        UpdateAnimation(&walk);
        UpdatePlayer(&player);

        float time = GetFrameTime();
        walk.direction = player.direction;
        if (IsWindowResized()) {
            camera.offset.x = (float) GetScreenWidth() / 2;
            camera.offset.y = (float) GetScreenHeight() / 2;
        }
        camera.target.x += (player.position.x - camera.target.x) * 5.0f * time;
        camera.target.y += (player.position.y - camera.target.y) * 5.0f * time;

        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(camera);

        DrawScene(skeld);
        DrawCollision(*SKELD);
        DrawPlayer(walk, Idle, player, 0.3f);

        EndMode2D();
        DrawOverlay(overlay);
        DebugFPS(20, 10, brook);
        DrawTexture(logo, GetScreenWidth() - logo.width - 10, GetScreenHeight() - logo.height - 10, WHITE);
        EndDrawing();
    }

    UnloadAnimation(walk);
    UnloadScene(skeld);
    UnloadTexture(Idle);
    UnloadTexture(overlay);
    UnloadTexture(logo);
    UnloadFont(brook);
    CloseWindow();
}
