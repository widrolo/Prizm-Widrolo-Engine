#include "../Engine/include/core/ImplementMinimal.h"
#include "../Engine/include/core/SpriteRenderer.h"
#include "../Engine/include/core/Collision.h"
#include "../Engine/include/core/File.h"
#pragma once

class Player : Character
{
private:
    GameModeManager *pGameModeManger;
    CollisionBox collisionBox;
    CollisionManger *pCollisionManager;
    CollisionResult collisionResult;
    CrashHandler *pCrashHandler;
    FileReader *pFileReader;
    WFile file;

    Vector2 pos;
    Vector2 scl;
public:
    void Reset(GameModeManager *pGMM, CollisionManger *pCM, CrashHandler *pCH, FileReader *pFR);
    void Tick();
    void Draw();
    void End();
};

