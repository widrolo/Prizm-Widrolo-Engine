#include "../Engine/include/core/ImplementMinimal.h"
#include "../Engine/include/core/SpriteRenderer.h"
#include "../Engine/include/core/Collision.h"
#pragma once

class Player : Character
{
private:
    GameModeManager *pGameModeManger;
    CollisionBox pCollisionBox;
    CollisionManger *pCM;
    //CollisionBox *pCollisionBox = static_cast<CollisionBox*>(sys_malloc(sizeof(CollisionBox)));
    Vector2 pos;
    Vector2 scl;
    int *collided = static_cast<int*>(sys_malloc(sizeof(int)));
public:
    void Reset(GameModeManager *pGMM);
    void Tick();
    void Draw();
};

