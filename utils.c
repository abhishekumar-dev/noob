#include <raylib.h>
#include "utils.h"

void DrawOverlay(Texture2D texture) {
    Rectangle source_rect = {0, 0, (float) texture.width, (float) texture.height};
    Rectangle dest_rect = {0, 0, (float) GetScreenWidth(), (float) GetScreenHeight()};
    Vector2 origin = {0};
    DrawTexturePro(texture, source_rect, dest_rect, origin, 0.0f,WHITE);
}

void DebugFPS(int x, int y, Font font) {
    int fps = GetFPS();
    DrawTextEx(font, TextFormat("FPS: %2i", fps), (Vector2){(float) x, (float) y}, FPS_FONT_SIZE, 2, WHITE);
}
