#include "./World.h"

void World::Assign()
{

}
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
    Assign();
    CoreReset();
}
void World::Tick()
{

}
void World::Draw()
{
    NPCDraw(0);
}