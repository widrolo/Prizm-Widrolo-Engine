#include "../Engine/include/core/ImplementMinimal.h"
#include "../Engine/include/core/SpriteRenderer.h"
#include "../Engine/include/core/Collision.h"
#pragma once

class Player : Character
{
private:
    GameModeManager *pGameModeManger;
    CollisionBox collisionBox;
    CollisionManger *pCollisionManager;
    CollisionResult collisionResult;
    CrashHandler *pCrashHandler;

    Vector2 pos;
    Vector2 scl;
public:
    void Reset(GameModeManager *pGMM, CollisionManger *pCM, CrashHandler *pCH);
    void Tick();
    void Draw();
};

