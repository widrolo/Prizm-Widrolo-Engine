#include "./World.h"

void World::Reset()
{
    Vector2 pos;
    Vector2 scl;

    pos.x = 0;
    pos.y = 0;
    SetPosition(pos);

    scl.x = 384;
    scl.y = 216;
    SetScale(scl);

    color = COLOR_GREEN;
    CoreReset();
}
void World::Tick()
{
    PawnTick();
}
void World::Draw()
{
    PawnDraw(0);
}