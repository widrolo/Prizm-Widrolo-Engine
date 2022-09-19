#include "../Engine/include/core/ImplementMinimal.h"
#include "../Engine/include/core/SpriteRenderer.h"
#pragma once

class Player : Character
{
private:
    color_t playerSprite[8][8] = {
        {COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE},
        {COLOR_BLUE, 0, 0, 0, 0, 0, 0, COLOR_BLUE},
        {COLOR_BLUE, 0, 0, 0, 0, 0, 0, COLOR_BLUE},
        {COLOR_BLUE, 0, 0, 0, 0, 0, 0, COLOR_BLUE},
        {COLOR_BLUE, 0, 0, 0, 0, 0, 0, COLOR_BLUE},
        {COLOR_BLUE, 0, 0, 0, 0, 0, 0, COLOR_BLUE},
        {COLOR_BLUE, 0, 0, 0, 0, 0, 0, COLOR_BLUE},
        {COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE},
    };
    color_t playerSprite64[64] = {
        COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE,
        COLOR_BLUE, 0, 0, 0, 0, 0, 0, COLOR_BLUE,
        COLOR_BLUE, 0, 0, 0, 0, 0, 0, COLOR_BLUE,
        COLOR_BLUE, 0, 0, 0, 0, 0, 0, COLOR_BLUE,
        COLOR_BLUE, 0, 0, 0, 0, 0, 0, COLOR_BLUE,
        COLOR_BLUE, 0, 0, 0, 0, 0, 0, COLOR_BLUE,
        COLOR_BLUE, 0, 0, 0, 0, 0, 0, COLOR_BLUE,
        COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE, COLOR_BLUE
    };
    void Assign();
public:
    void Reset();
    void Tick();
    void Draw();
};

