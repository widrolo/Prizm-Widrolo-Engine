#pragma once

#include "../GM_GameMode.h"
#include "../../Engine/include/core/ImplementMinimal.h"
class Barrier : Pawn
{
public:
    GM_GameMode *gameMode;
public:
    static void Reset(void *s, GM_GameMode *pGM)
    {
        Barrier *self = (Barrier*)s;
        self->gameMode = pGM;
        Vector2 pos;
        Vector2 scl;

        pos.x = 100;
        pos.y = 100;
        self->SetPosition(pos);

        scl.x = 16; 
        scl.y = 16;
        self->SetScale(scl);

        self->color = COLOR_BLUE;
        self->CoreReset();
    }
    static void Tick(void *s)
    {
        return;
    }
    static void Draw(void *s)
    {
        Barrier *self = (Barrier*)s;
        self->PawnDraw(true);
    }
};

