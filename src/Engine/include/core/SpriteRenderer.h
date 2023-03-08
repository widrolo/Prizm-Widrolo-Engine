#include "./EngineDefines.h"
#include <fxcg/display.h>
#include <fxcg/heap.h>
#include "./../math/vector.h"
#pragma once

#define COLOR_CLEAR (color_t)0xF345

class SpriteRenderer
{
public: // Rendering Functions
    void RenderSquare(Vector2 position, Vector2 size, int color)
    {
#if __RENDERING == 0
        return;
#endif
        for (int x = 0; x < size.x; x++)
        {
            for (int y = 0; y < size.y; y++)
            {
                Bdisp_SetPoint_VRAM(x + position.x, y + position.y, color);
            }
        }
    }
#if __BLEEDING_EDGE == 1
    void RenderSprite(Vector2 position, Vector2 size, const color_t *sprite, bool xFlip, bool yFlip)
    {
        color_t *VRAM = (color_t*)GetVRAMAddress();
        
        // Draw Sprite normally
        if (!xFlip && !yFlip)
        {
            VRAM += (LCD_WIDTH_PX * position.y) + position.x;
            for(int j = position.y; j < position.y + size.y; j++) 
            {
                for (int i = position.x; i < position.x + size.x; i++) 
                {
                    VRAM++;
                    sprite++;

                    // The ugly pink that no one uses
                    if (*sprite == 0xf81a)
                        continue;

                    *VRAM = *sprite;
                }
                VRAM += LCD_WIDTH_PX - size.x;
            }
        }
        // Flip Horizontally
        if (!xFlip && yFlip)
        {
            VRAM += (LCD_WIDTH_PX * position.y) + position.x + size.x - 1;
            for(int j = position.y; j < position.y + size.y; j++) 
            {
                for (int i = position.x + size.x; i > position.x; i--) 
                {
                    VRAM--;
                    sprite++;

                    // The ugly pink that no one uses
                    if (*sprite == 0xf81a)
                        continue;
                        
                    *VRAM = *sprite;
                }
                VRAM += LCD_WIDTH_PX + size.x;
            }
        }
        // Flip Vertically
        if (xFlip && !yFlip)
        {
            VRAM += (LCD_WIDTH_PX * (position.y + size.y - 1)) + position.x;
            for(int j = position.y + size.y; j > position.y; j--) 
            {
                for (int i = position.x; i < position.x + size.x; i++) 
                {
                    VRAM++;
                    sprite++;

                    // The ugly pink that no one uses
                    if (*sprite == 0xf81a)
                        continue;

                    *VRAM = *sprite;
                }
                VRAM -= LCD_WIDTH_PX + size.x;
            }
        }
        // Flip Both Axis
        if (xFlip && yFlip)
        {
            VRAM += (LCD_WIDTH_PX * (position.y + size.y - 1)) + position.x + size.x - 1;
            for(int j = position.y + size.y; j > position.y; j--) 
            {
                for (int i = position.x + size.x; i > position.x; i--) 
                {
                    VRAM--;
                    sprite++;

                    // The ugly pink that no one uses
                    if (*sprite == 0xf81a)
                        continue;
                        
                    *VRAM = *sprite;
                }
                VRAM -= LCD_WIDTH_PX - size.x;
            }
        }
    }
#endif
};