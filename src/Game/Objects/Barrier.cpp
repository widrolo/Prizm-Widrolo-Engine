#include "./Barrier.h"

void Barrier::Reset(GameModeManager *pGMM, CollisionManger *pCM)
{
    Vector2 pos;
    Vector2 scl;

    pGameModeManger = pGMM;
    pCollisionManager = pCM;

    pos.x = 100;
    pos.y = 100;
    SetPosition(pos);

    scl.x = 100;
    scl.y = 50;
    SetScale(scl);

    collisionBox.position = pos;
    collisionBox.size = scl;
    collisionBox.layer = 1;
    collisionBox.ID = pCollisionManager->GenerateNewID();

    pCollisionManager->AddBox(&collisionBox);

    color = COLOR_BLUE;
    CoreReset();
}
void Barrier::Tick()
{
    PawnTick();
}
void Barrier::Draw()
{
    PawnDraw(0);
}