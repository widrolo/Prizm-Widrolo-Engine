#pragma once

#include "./GM_GameMode.h"
#include "../Engine/include/core/ImplementMinimal.h"
#include "../Engine/include/math/math.h"

class Player : Character
{
private:
    GM_GameMode *gameMode;
    Vector2 pos;
    Vector2 scl;
public:
    static void Reset(void *s, GM_GameMode *gm)
    {
        Player *self = (Player*)s;

        // Setup object
        self->gameMode = gm;

        self->enableStdMove = true;
        self->speed = 3;

        // Setup player
        self->pos.x = 100;
        self->pos.y = 70;
        self->SetPosition(self->pos);

        self->scl.x = 16;
        self->scl.y = 16;
        self->SetScale(self->scl);

        self->color = COLOR_RED;

        // Complete setup
        self->CoreReset();
    }
    static void Tick(void *s)
    {
        Player *self = (Player*)s;

        self->CharacterTick(self->gameMode->GetCrashHandler());
    }
    static void Draw(void *s)
    {
        Player *self = (Player*)s;

        self->CharacterDraw(true);
    }
};

