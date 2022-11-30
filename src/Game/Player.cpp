#include "./Player.h"
#include <fxcg/display.h>

void Player::Reset(GameModeManager *pGMM, CollisionManger *pCM)
{
    pGameModeManger = pGMM;
    
    pCollisionManager = pCM;

    enableStdMove = false;
    speed = 3;

    pos.x = 100;
    pos.y = 70;
    SetPosition(pos);

    scl.x = 20;
    scl.y = 20;
    SetScale(scl);

    pCollisionBox.position = pos;
    pCollisionBox.size = scl;
    pCollisionBox.layer = 1;
    pCollisionBox.ID = pCollisionManager->GenerateNewID();
    pCollisionManager->AddBox(&pCollisionBox);



    color = COLOR_RED;
    CoreReset();
}
void Player::Tick()
{
    CharacterTick();

    // TODO Make the collison work

    pCollisionManager->CheckForCollision(pCollisionBox.ID, &collisionResult);

    if (key == KEY_CTRL_LEFT)
    {
        if (collisionResult.collided)
            pos.x -= 1 * speed;
    }
    else if (key == KEY_CTRL_RIGHT)
    {
        if (collisionResult.collided)
            pos.x += 1 * speed;
    }
    else if (key == KEY_CTRL_UP)
    {
        if (collisionResult.collided)
            pos.y -= 1 * speed;
    }
    else if (key == KEY_CTRL_DOWN)
    {
        if (collisionResult.collided)
            pos.y += 1 * speed;
    }
    
    SetPosition(pos);
    pCollisionBox.position = GetPosition();

    if (key == KEY_CTRL_EXE)
        pGameModeManger->GetPlayer()->Reset(pGameModeManger, pCollisionManager);
    if (key == KEY_CHAR_0)
        pGameModeManger->GetGameMode()->ChangeSkyboxColor(COLOR_DARKGREEN);

}

void Player::Draw()
{
    CharacterDraw(0);
}