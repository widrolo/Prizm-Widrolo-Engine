#pragma once

#include "../GM_GameMode.h"
#include "../../Engine/include/core/ImplementMinimal.h"
class Barrier : Pawn
{
private:
    GM_GameMode *gameMode;
public:
    virtual void Reset(GM_GameMode *pGM) override
    {
        gameMode = pGM;
        Vector2 pos;
        Vector2 scl;

        pos.x = 100;
        pos.y = 100;
        SetPosition(pos);

        scl.x = 16; 
        scl.y = 16;
        SetScale(scl);

        color = COLOR_BLUE;
        CoreReset();
    }
    virtual void Tick() override
    {
        return;
    }
    void MyTick()
    {
        return;
    }
    virtual void Draw() override
    {
        PawnDraw(true);
    }
};

