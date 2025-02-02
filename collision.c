#include <raylib.h>
#include "collision.h"
#include "player.h"

bool CheckCollision(CollisionMap map, Player *player) {
    Vector2 position[] = {
        {player->position.x + player->size.x * 0.3f, player->position.y + player->size.y * 0.3f},
        {player->position.x, player->position.y + player->size.y * 0.3f}
    };

    for (int i = 0; i < map.collision_count; i++) {
        for (int j = 0; j < 2; j++) {
            if (CheckCollisionPointRec(position[j], map.collisions[i].bounds)) {
                map.collisions[i].active = true;
                if (CheckCollisionPointPoly(position[j], map.collisions[i].points, map.collisions[i].point_count)) {
                    return true;
                }
            } else {
                map.collisions[i].active = false;
            }
        }
    }

    return false;
}

void DrawCollision(CollisionMap map) {
    for (int i = 0; i < map.collision_count; i++) {
        if (map.collisions[i].active) {
            DrawSplineLinear(map.collisions[i].points, map.collisions[i].point_count, 3, GREEN);
        }
    }
}

Vector2 cafeteria_0[] = {
    {0, 0},
    {985, 0},
    {985, 440},
    {956, 440},
    {956, 312},
    {719, 74},
    {193, 74},
    {30, 236},
    {30, 440},
    {0, 440},
    {0, 0}
};

Vector2 cafeteria_1[] = {
    {0, 534},
    {30, 534},
    {30, 734},
    {236, 930},
    {427, 930},
    {427, 989},
    {0, 989},
    {0, 534}
};

Collision CAFETERIA_COLLISIONS[] = {
    {
        .id = 0,
        .bounds = {0, 0, 985, 440},
        .points = cafeteria_0,
        .point_count = sizeof(cafeteria_0) / sizeof(cafeteria_0[0])
    },
    {
        .id = 1,
        .bounds = {0, 534, 427, 989},
        .points = cafeteria_1,
        .point_count = sizeof(cafeteria_1) / sizeof(cafeteria_1[0])
    }
};

CollisionMap SKELD[] = {
    {
        .id = "cafeteria",
        .collisions = CAFETERIA_COLLISIONS,
        .collision_count = sizeof(CAFETERIA_COLLISIONS) / sizeof(CAFETERIA_COLLISIONS[0])
    }
};
