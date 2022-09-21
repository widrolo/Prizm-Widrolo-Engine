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
    Assign();
    CoreReset();
}
void Player::Assign()
{
    //attempt to change color
    for (int i = 0; i < 63; i++)
    {
        malloc_sprite_test[i] = COLOR_BLUE;
    }
    
}
void Player::Tick()
{
    CharacterTick();
}

void Player::Draw()
{
    Assign();
    int y = 0;
    int x = 0;
    for (int i = 0; i < 63; i++)
    {      
        Bdisp_SetPoint_VRAM(x + GetPosition().x, y + GetPosition().y, malloc_sprite_test[i]);
        if (i % 8 == 0)
        {
            y++;
        }
        x++;
        if (x > 8)
        {
            x = 0;
        }
    }
}