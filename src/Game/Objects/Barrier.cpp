#include "./Barrier.h"

void Barrier::Reset(GameModeManager *pGMM, CollisionManger *pCM)
{
    Vector2 pos;
    Vector2 scl;

    pGameModeManger = pGMM;
    pCollisionManger = pCM;

    pos.x = 100;
    pos.y = 100;
    SetPosition(pos);

    scl.x = 50;
    scl.y = 100;
    SetScale(scl);

    collisionBox.position = pos;
    collisionBox.size = scl;
    collisionBox.layer = 1;
    collisionBox.ID = 200;

    // TODO: GET THIS BS TO WORK!!!
    
    //pCollisionManger->AddBox(&collisionBox);

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