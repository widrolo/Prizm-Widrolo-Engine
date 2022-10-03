#include "../../Engine/include/core/ImplementMinimal.h"
#include "../../Engine/include/core/SpriteRenderer.h"
#include "../../Engine/include/core/Collision.h"
#pragma once

class Barrier : Pawn
{
private:
    GameModeManager *pGameModeManger;
    CollisionBox collisionBox;
    CollisionManger *pCollisionManger;
public:
    void Reset(GameModeManager *pGMM, CollisionManger *pCM);
    void Tick();
    void Draw();
};

