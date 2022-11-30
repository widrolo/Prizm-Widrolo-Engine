#include "./EngineDefines.h"
#include <fxcg/display.h>
#include <fxcg/heap.h>
#include "./../math/vector.h"
#pragma once

#define COLOR_CLEAR (color_t)0xF345

class SpriteRenderer
{
public: // Rendering Functions
    void RenderSquare(Vector2 position, Vector2 scale, int color)
    {
#if __RENDERING == 0
        return;
#endif
        for (int x = 0; x < scale.x; x++)
        {
            for (int y = 0; y < scale.y; y++)
            {
                Bdisp_SetPoint_VRAM(x + position.x, y + position.y, color);
            }
        }
    }
#if __BLEEDING_EDGE == 1
    void RenderSprite8x8(Vector2 position, color_t *sprite)
    {
        VRAM_CopySprite(sprite, position.x, position.y, 8, 8);
    }
#endif
};