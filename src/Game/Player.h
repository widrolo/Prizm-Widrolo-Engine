#include "../Engine/include/core/ImplementMinimal.h"
#include "../Engine/include/core/SpriteRenderer.h"
#pragma once

class Player : Character
{
private:
    void Assign();
public:
    void Reset();
    void Tick();
    void Draw();
};

