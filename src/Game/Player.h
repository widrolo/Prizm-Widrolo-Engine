#include "../Engine/include/core/ImplementMinimal.h"
#include "../Engine/include/core/InputHandler.h"
#include "../Engine/core/InputHandler.cpp"
#include "../Engine/include/core/SpriteRenderer.h"
#pragma once

class Player : Character
{
public:
    void Reset();
    void Tick();
    void Draw();
};

