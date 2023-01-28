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

    scl.x = 32;
    scl.y = 32;
    SetScale(scl);

    color = COLOR_RED;


    // Complete setup
    CoreReset();
}
void Player::Tick()
{
    CharacterTick(gameMode->GetCrashHandler());
}

void Player::Draw()
{
    CharacterDraw(0);
}