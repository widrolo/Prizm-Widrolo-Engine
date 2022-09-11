#include "../Engine/include/core/ImplementMinimal.h"
#include "../Engine/include/core/InputHandler.h"
#include "../Engine/core/InputHandler.cpp"
#include "../Engine/include/core/SpriteRenderer.h"
#pragma once

class Player : Actor
{
public:
    SpriteRenderer renderer = SpriteRenderer();

public:
    void Start();
    void Tick();
    void Draw();
};

