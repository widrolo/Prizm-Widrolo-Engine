#include "./EngineDefines.h"
#include <fxcg/display.h>
#include <fxcg/heap.h>
#include "./../math/vector.h"
#pragma once

#define COLOR_CLEAR (color_t)0xf81a // bright pink

// This pallete stores 256 16 bit colors, 
// so they can be accessed using an 8 bit int
struct Plallete8Bit // NES Type colors 
{
    color_t colors[256];
};

// This pallete stores 16 16 bit colors, 
// so they can be accessed using a 4 bit int
struct Plallete4Bit
{
    color_t colors[16];
};

// This pallete stores 4 16 bit colors, 
// so they can be accessed using a 4 bit int
struct Plallete2Bit // Game boy type game
{
    color_t colors[4];
};

// This pallete stores 2 16 bit colors, 
// so they can be accessed using 1 bit
struct Plallete1Bit // Game boy type game
{
    color_t colors[2];
};

class SpriteRenderer
{
public: // Rendering Functions

    Plallete8Bit *p8bitPall;
    Plallete4Bit *p4bitPall;
    Plallete2Bit *p2bitPall;
    Plallete1Bit *p1bitPall;

    void ApplyColorPallete(Plallete8Bit *p8bitPall, Plallete4Bit *p4bitPall, Plallete2Bit *p2bitPall, Plallete1Bit *p1bitPall)
    {
        this->p8bitPall = p8bitPall;
        this->p4bitPall = p4bitPall;
        this->p2bitPall = p2bitPall;
        this->p1bitPall = p1bitPall;
    }

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

    void RenderSpriteSimple8Bit(const char *sprite, int xPos, int yPos, int xSize, int ySize)
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
                *VRAM++ = (p8bitPall->colors[(int)(*sprite)])++;
            }
            VRAM += LCD_WIDTH_PX - xSize;
        }
    }

#endif
};