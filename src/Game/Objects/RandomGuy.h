#pragma once
#include "../../Engine/include/core/ImplementMinimal.h"

class RandomGuy : WEngine::Pawn
{
public:
    GM_GameMode *gameMode;
public:
    static void Reset(void *s, GM_GameMode *pGM)
    {
        MAKE_SELF(RandomGuy)

        Vector2 position = { x: 200, y:100 };
        Vector2 size = { x: 8, y: 16 };

        self->SetPosition(position);
        self->SetScale(size);

        self->color = COLOR_GOLD;
        self->CoreReset();
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

