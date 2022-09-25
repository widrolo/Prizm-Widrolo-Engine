#include "./Player.h"
#include <fxcg/display.h>
#include <stdlib.h>

void Player::Reset()
{
    Vector2 pos;
    Vector2 scl;
    

    enableStdMove = true;
    speed = 3;

    pos.x = 100;
    pos.y = 70;
    SetPosition(pos);

    scl.x = 20;
    scl.y = 20;
    SetScale(scl);

    color = COLOR_RED;
    Assign();
    CoreReset();
}
void Player::Assign()
{
    //attempt to change color
    for (int i = 0; i < 63; i++)
    {
        pPlayerSprite[i] = COLOR_BLUE;
    }
    
}
void Player::Tick()
{
    CharacterTick();
}

void Player::Draw()
{
    CharacterDraw(0);
}