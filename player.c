#include <raylib.h>
#include <math.h>
#include "player.h"
#include "collision.h"

void UpdatePlayer(Player *player) {
    float time = GetFrameTime();
    Vector2 position = {0};
    player->moving = false;

    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        position.x -= 1;
        player->direction = -1;
    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        position.x += 1;
        player->direction = 1;
    }
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        position.y -= 1;
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        position.y += 1;
    }

    float magnitude = sqrtf(position.x * position.x + position.y * position.y);
    if (magnitude > 0) {
        position.x = position.x / magnitude * player->speed * time * 100;
        position.y = position.y / magnitude * player->speed * time * 100;
        player->moving = true;
    }

    if (!player->moving) return;

    Vector2 old_position = player->position;
    Vector2 new_position = {player->position.x + position.x, player->position.y + position.y};

    player->position = new_position;
    if (CheckCollision(*SKELD, player)) {
        player->position = old_position;

        player->position.x += position.x;
        if (CheckCollision(*SKELD, player)) {
            player->position.x = old_position.x;
        }

        player->position.y += position.y;
        if (CheckCollision(*SKELD, player)) {
            player->position.y = old_position.y;
        }
    }
}

void DrawPlayer(Animation walk, Texture2D Idle, Player player, float scale) {
    if (player.moving) {
        DrawAnimation(walk, player.position, 0, scale, Bottom);
    } else {
        Rectangle source_rect = {
            .x = 0,
            .y = 0,
            .width = (float) Idle.width * (float) player.direction,
            .height = (float) Idle.height
        };
        Rectangle dest_rect = {
            .x = player.position.x,
            .y = player.position.y + (walk.size.y - (float) Idle.height) / 2,
            .width = (float) Idle.width * scale,
            .height = (float) Idle.height * scale
        };
        DrawTexturePro(Idle, source_rect, dest_rect, (Vector2){0}, 0, WHITE);
    }
}
