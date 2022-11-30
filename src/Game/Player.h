#include "../Engine/include/core/ImplementMinimal.h"
#include "../Engine/include/core/SpriteRenderer.h"
#include "../Engine/include/core/Collision.h"
#pragma once

class Player : Character
{
private:
    GameModeManager *pGameModeManger;
    CollisionBox pCollisionBox;
    CollisionManger *pCollisionManager;
    CollisionResult collisionResult;

    Vector2 pos;
    Vector2 scl;
public:
    void Reset(GameModeManager *pGMM, CollisionManger *pCM);
    void Tick();
    void Draw();
};

