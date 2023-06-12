#include "./EngineDefines.h"
#include <fxcg/display.h>
#include <fxcg/heap.h>
#include "./../math/vector.h"
#pragma once

#define COLOR_CLEAR (color_t)0xf81a // bright pink

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
                    if (*sprite == COLOR_CLEAR)
                    {
                        sprite++;
                        VRAM++;
                        continue;
                    }

                    *VRAM++ = *sprite++;
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
                    if (*sprite == COLOR_CLEAR)
                    {
                        sprite++;
                        VRAM--;
                        continue;
                    }
                        
                    *VRAM-- = *sprite++;
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
                    if (*sprite == COLOR_CLEAR)
                    {
                        sprite++;
                        VRAM++;
                        continue;
                    }

                    *VRAM++ = *sprite++;
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
                    if (*sprite == COLOR_CLEAR)
                    {
                        sprite++;
                        VRAM--;
                        continue;
                    }
                        
                    *VRAM-- = *sprite++;
                }
                VRAM -= LCD_WIDTH_PX - size.x;
            }
        }
    }

    void RenderSpriteSimple(const color_t *sprite, int xPos, int yPos, int xSize, int ySize)
    {
        color_t *VRAM = (color_t*)GetVRAMAddress();
        VRAM += (LCD_WIDTH_PX * yPos) + xPos;
        for(int j = yPos; j < yPos + ySize; j++) 
        {
            for (int i = xPos; i < xPos + xSize; i++) 
            {
                if (*sprite == COLOR_CLEAR)
                {
                    sprite++;
                    VRAM++;
                    continue;
                }
                *VRAM++ = *sprite++;
            }
            VRAM += LCD_WIDTH_PX - xSize;
        }
    }

#endif
};