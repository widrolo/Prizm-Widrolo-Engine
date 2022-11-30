#include "./Player.h"
#include <fxcg/display.h>

void Player::Reset(GameModeManager *pGMM, CollisionManger *pCM)
{
    // Setup object
    pGameModeManger = pGMM;
    
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
    pCollisionBox.position = pos;
    pCollisionBox.size = scl;
    pCollisionBox.layer = 1;
    pCollisionBox.ID = pCollisionManager->GenerateNewID();
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
        pCollisionManager->CheckForCollision(pCollisionBox.ID, &collisionResult);
        if (collisionResult.collided)
            pos.x += 1 * speed;
    }
    else if (key == KEY_CTRL_RIGHT)
    {
        pos.x += 1 * speed;
        pCollisionManager->CheckForCollision(pCollisionBox.ID, &collisionResult);
        if (collisionResult.collided)
            pos.x -= 1 * speed;
    }
    else if (key == KEY_CTRL_UP)
    {
        pos.y -= 1 * speed;
        pCollisionManager->CheckForCollision(pCollisionBox.ID, &collisionResult);
        if (collisionResult.collided)
            pos.y += 1 * speed;
    }
    else if (key == KEY_CTRL_DOWN)
    {
        pos.y += 1 * speed;
        pCollisionManager->CheckForCollision(pCollisionBox.ID, &collisionResult);
        if (collisionResult.collided)
            pos.y -= 1 * speed;
    }
    
    SetPosition(pos);
    pCollisionBox.position = GetPosition();

    // Debugging 

    if (key == KEY_CTRL_EXE)
        pGameModeManger->GetPlayer()->Reset(pGameModeManger, pCollisionManager);
    if (key == KEY_CHAR_0)
        pGameModeManger->GetGameMode()->ChangeSkyboxColor(COLOR_DARKGREEN);

}

void Player::Draw()
{
    CharacterDraw(0);
}