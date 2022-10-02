#include "./Player.h"
#include <fxcg/display.h>

void Player::Reset(GameModeManager *pGMM)
{
    pGameModeManger = pGMM;
    
    pCM = pGameModeManger->GetCollisionManager();

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
    pCollisionBox.ID = 100;
    pGameModeManger->GetCollisionManager()->AddBox(&pCollisionBox);

    color = COLOR_RED;
    CoreReset();
}
void Player::Tick()
{
    CharacterTick();

    // TODO Make the collison work

    //pGameModeManger->GetCollisionManager()->CheckForCollision(pCollisionBox.ID, collided);

    if (key == KEY_CTRL_LEFT)
    {
        //if (pGameModeManger->GetCollisionManager()->CheckForCollision(pCollisionBox.ID))
            pos.x -= 1 * speed;
    }
    else if (key == KEY_CTRL_RIGHT)
    {
        //if (pGameModeManger->GetCollisionManager()->CheckForCollision(pCollisionBox.ID))
            pos.x += 1 * speed;
    }
    else if (key == KEY_CTRL_UP)
    {
        //if (pGameModeManger->GetCollisionManager()->CheckForCollision(pCollisionBox.ID))
            pos.y -= 1 * speed;
    }
    else if (key == KEY_CTRL_DOWN)
    {
        //if (pGameModeManger->GetCollisionManager()->CheckForCollision(pCollisionBox.ID))
            pos.y += 1 * speed;
    }
    
    SetPosition(pos);

    if (key == KEY_CTRL_EXE)
        pGameModeManger->GetPlayer()->Reset(pGameModeManger);
    if (key == KEY_CHAR_0)
        pGameModeManger->GetGameMode()->ChangeSkyboxColor(COLOR_DARKGREEN);

}

void Player::Draw()
{
    CharacterDraw(0);
}