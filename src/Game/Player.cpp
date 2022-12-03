#include "./Player.h"
#include <fxcg/display.h>

void Player::Reset(GameModeManager *pGMM, CollisionManger *pCM, CrashHandler *pCH)
{
    // Setup object
    pGameModeManger = pGMM;
    pCrashHandler = pCH;
    pCollisionManager = pCM;

    enableStdMove = false;
    speed = 3;

    // Setup player
    pos.x = 100;
    pos.y = 70;
    SetPosition(pos);

    scl.x = 20;
    scl.y = 20;
    SetScale(scl);

    color = COLOR_RED;

    // Setup collision
    collisionBox.MakeBox(pos, scl, 1, pCollisionManager->GenerateNewID());
    pCollisionManager->AddBox(&collisionBox);
    SetCollisionInfo(pCollisionManager, &collisionBox, &collisionResult);
    EnableCollisionMove();

    // Complete setup
    CoreReset();
}
void Player::Tick()
{
    CharacterTick();
    
    collisionResult.Reset();
    SetPosition(pos);
    collisionBox.SetBoxInfo(pos, scl);

    // Debugging 

    if (key == KEY_CTRL_EXE)
        pGameModeManger->GetPlayer()->Reset(pGameModeManger, pCollisionManager, pCrashHandler);
    if (key == KEY_CHAR_0)
        pGameModeManger->GetGameMode()->ChangeSkyboxColor(COLOR_DARKGREEN);
    if (key == KEY_CHAR_1)
        pCrashHandler->Crash();

}

void Player::Draw()
{
    CharacterDraw(0);
}