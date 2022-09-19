#include "./EngineDefines.h"
#include <fxcg/display.h>
#include <fxcg/heap.h>
#include "C:\Users\Filip\Desktop\stuff\PrizmSDK-win-0.5.2\projects\Widrolo-Engine\src\Engine\include\math\vector.h"
#pragma once

#define COLOR_CLEAR (color_t)0xF345

class SpriteRenderer
{
public:
#if __BLEEDING_EDGE
    color_t sprite8x8[8][8] = {
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
        { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
    };
#endif

    void Init()
    {
#if __BLEEDING_EDGE
        for (int x = 0; x < 8; x++)
        {
            for (int y = 0; y < 8; y++)
            {
                sprite8x8[y][x] = 0x00;
            }
        }
#endif
    }
    void Destruct()
    {
        //sys_free(sprite8x8v2);
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
    void RenderSprite8x8(Vector2 position, color_t sprite[64])
    {
        VRAM_CopySprite(sprite, position.x, position.y, 8, 8);
//        for (int x = 0; x < 8; x++)
//        {
//            for (int y = 0; y < 8; y++)
//            {
//#if __BLEEDING_EDGE
//                Bdisp_SetPoint_VRAM(x + position.x, y + position.y, sprite8x8[y][x]);
//#endif          
//                Bdisp_SetPoint_VRAM(x + position.x, y + position.y, sprite[y][x]);
//            }
//        }
    }
#endif
};