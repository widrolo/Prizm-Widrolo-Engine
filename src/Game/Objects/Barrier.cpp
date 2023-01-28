#include "./Barrier.h"

void Barrier::Reset(GM_GameMode *gm)
{
    gameMode = gm;
    Vector2 pos;
    Vector2 scl;

    pos.x = 100;
    pos.y = 100;
    SetPosition(pos);

    scl.x = 100; 
    scl.y = 50;
    SetScale(scl);

    color = COLOR_BLUE;
    CoreReset();
}
void Barrier::Draw()
{
    PawnDraw(true);
}