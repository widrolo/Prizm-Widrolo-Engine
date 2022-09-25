#include "../Engine/include/core/ImplementMinimal.h"
#include "../Engine/include/core/SpriteRenderer.h"
#pragma once

class Player : Character
{
private:
    GameModeManager *pGameModeManger;
public:
    void Reset(GameModeManager *pGMM);
    void Tick();
    void Draw();
};

