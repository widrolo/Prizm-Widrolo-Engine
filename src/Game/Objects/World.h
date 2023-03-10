#pragma once
#include "../../Engine/include/core/ImplementMinimal.h"

class World : WEngine::Pawn
{
public:
    static void Reset(void *s, GM_GameMode *gm)
    {
        MAKE_SELF(World)
        Vector2 pos;
        Vector2 scl;

        pos.x = 0;
        pos.y = 0;
        self->SetPosition(pos);

        scl.x = 384;
        scl.y = 216;
        self->SetScale(scl);

        self->color = COLOR_LIGHTGREEN;
        self->CoreReset();
    }
    static void Tick(void *s)
    {
        return;
    }
    static void Draw(void *s)
    {
        MAKE_SELF(World)
        self->PawnDraw(true);
    }
};

