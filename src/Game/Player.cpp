#include "./Player.h"
#include <fxcg/display.h>
#include <stdlib.h>

void Player::Reset(GameModeManager *pGMM)
{
    pGameModeManger = pGMM;
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
    CoreReset();
}
void Player::Tick()
{
    CharacterTick();

    if (key == KEY_CTRL_EXE)
        pGameModeManger->GetPlayer()->Reset(pGameModeManger);
    if (key == KEY_CHAR_0)
        pGameModeManger->GetGameMode()->ChangeSkyboxColor(COLOR_DARKGREEN);

}

void Player::Draw()
{
    CharacterDraw(0);
}