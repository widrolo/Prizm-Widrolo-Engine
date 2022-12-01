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
    pCollisionBox.MakeBox(pos, scl, 1, pCollisionManager->GenerateNewID());
    pCollisionManager->AddBox(&pCollisionBox);

    // Complete setup
    CoreReset();
}
void Player::Tick()
{
    CharacterTick();

    // Advanced movement

    if (key == KEY_CTRL_LEFT)
    {   
        pos.x -= 1 * speed;
        pCollisionManager->CheckForCollision(pCollisionBox.GetID(), &collisionResult);
        if (collisionResult.collided)
            pos.x += 1 * speed;
    }
    else if (key == KEY_CTRL_RIGHT)
    {
        pos.x += 1 * speed;
        pCollisionManager->CheckForCollision(pCollisionBox.GetID(), &collisionResult);
        if (collisionResult.collided)
            pos.x -= 1 * speed;
    }
    else if (key == KEY_CTRL_UP)
    {
        pos.y -= 1 * speed;
        pCollisionManager->CheckForCollision(pCollisionBox.GetID(), &collisionResult);
        if (collisionResult.collided)
            pos.y += 1 * speed;
    }
    else if (key == KEY_CTRL_DOWN)
    {
        pos.y += 1 * speed;
        pCollisionManager->CheckForCollision(pCollisionBox.GetID(), &collisionResult);
        if (collisionResult.collided)
            pos.y -= 1 * speed;
    }
    
    SetPosition(pos);
    pCollisionBox.SetBoxInfo(pos, scl);

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