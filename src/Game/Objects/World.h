#include "../../Engine/include/core/ImplementMinimal.h"
#include "../../Engine/include/core/SpriteRenderer.h"
#pragma once

class World : NPC
{
private:
    void Assign();
public:
    void Reset();
    void Tick();
    void Draw();
};

