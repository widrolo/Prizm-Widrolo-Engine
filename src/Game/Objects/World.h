#include "../../Engine/include/core/ImplementMinimal.h"
#include "../../Engine/include/core/SpriteRenderer.h"
#pragma once

class World : Pawn
{
public:
    void Reset();
    void Tick();
    void Draw();
};

