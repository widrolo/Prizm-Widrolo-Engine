#include "./Player.h"

void Player::Reset(GM_GameMode *gm)
{
    // Setup object
    gameMode = gm;

    enableStdMove = true;
    speed = 3;

    // Setup player
    pos.x = 100;
    pos.y = 70;
    SetPosition(pos);

    scl.x = 16;
    scl.y = 16;
    SetScale(scl);

    color = COLOR_RED;

    // Complete setup
    CoreReset();
}
void Player::Tick()
{
    CharacterTick(gameMode->GetCrashHandler());
    Vector2 BarrierPos = {x: 100, y: 100};
    gameMode->GetTextCanvas()->ClearBuff(0);
    gameMode->GetTextCanvas()->AddIntBuff(Wdist(BarrierPos, GetPosition()), 0, 10, 10);
}

void Player::Draw()
{
    CharacterDraw(true);
}