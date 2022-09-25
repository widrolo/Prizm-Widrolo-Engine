#include "./EngineDefines.h"
#include <fxcg/display.h>
#include <fxcg/heap.h>
#include "C:\Users\Filip\Desktop\stuff\PrizmSDK-win-0.5.2\projects\Widrolo-Engine\src\Engine\include\math\vector.h"
#pragma once

#define COLOR_CLEAR (color_t)0xF345

class SpriteRenderer
{
public:

    void Init()
    {

    }
    void Destruct()
    {
        
    }
public:
    void RenderSquare(Vector2 position, Vector2 scale, int color)
    {
        for (int x = 0; x < scale.x; x++)
        {
            for (int y = 0; y < scale.y; y++)
            {
                Bdisp_SetPoint_VRAM(x + position.x, y + position.y, color);
            }
        }
    }
#if __DEV
    void RenderSprite8x8(Vector2 position, color_t *sprite)
    {
        VRAM_CopySprite(sprite, position.x, position.y, 8, 8);
    }
#endif
};