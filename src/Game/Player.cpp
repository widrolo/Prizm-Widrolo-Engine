#include "./Player.h"
#include <fxcg/display.h>
#include <stdlib.h>

void Player::Reset()
{
    Vector2 pos;
    Vector2 scl;

    pos.x = 100;
    pos.y = 70;
    SetPosition(pos);

    scl.x = 20;
    scl.y = 20;
    SetScale(scl);

    color = COLOR_BLUE;
    CoreReset();
}
void Player::Tick()
{
    CharacterTick();
}
void Player::Draw()
{
    CharacterDraw();
    
}