#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "animation.h"

Animation LoadAnimation(const char *id, int frame_count) {
    Animation animation = {
        .frame_count = frame_count,
        .current_frame = 0,
        .speed = 0.05f,
        .direction = 1
    };
    animation.sprites = malloc(sizeof(Texture2D) * frame_count);

    char src[128];
    for (int i = 0; i < frame_count; i++) {
        sprintf(src, "%s%04d.png", id, i + 1);
        animation.sprites[i] = LoadTexture(src);

        if (animation.size.x < (float) animation.sprites[i].width) {
            animation.size.x = (float) animation.sprites[i].width;
        }
        if (animation.size.y < (float) animation.sprites[i].height) {
            animation.size.y = (float) animation.sprites[i].height;
        }
    }
    return animation;
}

void UpdateAnimation(Animation *animation) {
    animation->timer += GetFrameTime();
    if (animation->timer >= animation->speed) {
        animation->timer = 0.0f;
        animation->current_frame = (animation->current_frame + 1) % animation->frame_count;
    }
}

void DrawAnimation(Animation animation, Vector2 position, float rotation, float scale, Alignment alignment) {
    Texture2D texture = animation.sprites[animation.current_frame];
    Rectangle source_rect = {
        .x = 0,
        .y = 0,
        .width = (float) texture.width * (float) animation.direction,
        .height = (float) texture.height
    };
    Rectangle dest_rect = {
        .x = position.x,
        .y = position.y,
        .width = (float) texture.width * scale,
        .height = (float) texture.height * scale
    };

    if (alignment == Bottom) {
        dest_rect.y += (animation.size.y - (float) texture.height) * scale;
    }

    Vector2 origin = {0};
    DrawTexturePro(texture, source_rect, dest_rect, origin, rotation, WHITE);
}

void UnloadAnimation(Animation animation) {
    for (int i = 0; i < animation.frame_count; ++i) {
        UnloadTexture(animation.sprites[i]);
    }
    free(animation.sprites);
}
