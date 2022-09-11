#include "./Player.h"
#include <fxcg/display.h>
#include <stdlib.h>

void Player::Start()
{
    position.x = 100;
    position.y = 70;

    scale.x = 20;
    scale.y = 20;

    color = COLOR_BLUE;
}
void Player::Tick()
{
    ActorTick();
    
    int key;
    GetKey(&key);

    if (key == KEY_CTRL_LEFT)
        position.x -= 3;
    else if (key == KEY_CTRL_RIGHT)
        position.x += 3;
    else if (key == KEY_CTRL_UP)
        position.y -= 3;
    else if (key == KEY_CTRL_DOWN)
        position.y += 3;
    Bdisp_AllClr_VRAM();
}
void Player::Draw()
{
    ActorDraw();
    renderer.RenderSquare(position, scale, color);
}