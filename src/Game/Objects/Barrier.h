#pragma once

#include "../GM_GameMode.h"
#include "../../Engine/include/core/ImplementMinimal.h"
class Barrier : WEngine::Pawn
{
public:
    GM_GameMode *gameMode;
public:
    static void E_change_pos(void *s, void *infoBuff)
    {
        MAKE_SELF(Barrier)
        int *copy = (int*)infoBuff;
        Vector2 pos = { x: copy[0], y: copy[1]};
        self->SetPosition(pos);
    }
    static void Reset(void *s, GM_GameMode *pGM)
    {
        MAKE_SELF(Barrier)
        self->gameMode = pGM;

        self->position.x = 100;
        self->position.y = 100;

        self->size.x = 16;
        self->size.y = 16;

        self->color = COLOR_BLUE;
        self->CoreReset();

        pGM->GetEventsManager()->Subscribe<Barrier>(0, self, E_change_pos);
    }
    static void Tick(void *s)
    {
        MAKE_SELF(Barrier)
        self->position.x++; 
        return;
    }
    static void Draw(void *s)
    {
        MAKE_SELF(Barrier)
        self->PawnDraw(true);
    }
};

