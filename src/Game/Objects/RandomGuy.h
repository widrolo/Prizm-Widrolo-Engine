#pragma once
#include "../../Engine/include/core/ImplementMinimal.h"

class RandomGuy : WEngine::Pawn
{
public:
    GM_GameMode *gameMode;
public:
    static void E_change_pos(void *s, void *infoBuff)
    {
        MAKE_SELF(RandomGuy)
        int *copy = (int*)infoBuff;
        self->position.x = copy[0];
        self->position.y = copy[1];
        self->gameMode->GetDebugConsole()->OutPutMsg("CHANGED POS");
        sys_free(infoBuff);
    }
    static void Reset(void *s, GM_GameMode *pGM)
    {
        MAKE_SELF(RandomGuy)

        Vector2 position = { x: 200, y:100 };
        Vector2 size = { x: 8, y: 16 };

        self->SetPosition(position);
        self->SetScale(size);

        self->color = COLOR_GOLD;
        self->CoreReset();

        pGM->GetEventsManager()->Subscribe<RandomGuy>(0, self, E_change_pos);
    }

    static void Tick(void *s)
    {
        return;
    }

    static void Draw(void *s)
    {
        MAKE_SELF(RandomGuy)

        self->PawnDraw(true);
    }
};

