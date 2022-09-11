#include <fxcg/display.h>
#include "C:\Users\Filip\Desktop\PrizmSDK-win-0.5.2\projects\Widrolo-Engine\src\Engine\include\math\vector.h"
#pragma once

#define COLOR_CLEAR (color_t)0xF345

class SpriteRenderer
{
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
    void RenderSprite8x8(Vector2 position, color_t data[64])
    {
        VRAM_CopySprite(data, position.x, position.y, 8, 8);
        //for (int x = 0; x < 8; x++)
        //{
        //    for (int y = 0; y < 8; y++)
        //    {
        //        Bdisp_SetPoint_VRAM(x + position.x, y + position.y, sprite8x8[y][x]);
        //    }
        //}
    }
};