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

    color = COLOR_BLUE;
    CoreReset();
}
void Player::Assign()
{
    for (int x = 0; x < 8; x++)
        {
            for (int y = 0; y < 8; y++)
            {
                renderer.sprite8x8[x][y] = playerSprite[x][y];
            }
        }
}
void Player::Tick()
{
    CharacterTick();
}
void Player::Draw()
{
    CharacterDraw(1);
}