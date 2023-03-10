#pragma once

#include "./GM_GameMode.h"
#include "../Engine/include/core/ImplementMinimal.h"
#include "../Engine/include/math/math.h"

#include "./Data/spritedata.h"

class Player : WEngine::Character
{
private:
    GM_GameMode *gameMode;
public:
    static void Reset(void *s, GM_GameMode *gm)
    {
        MAKE_SELF(Player)

        // Setup object
        self->gameMode = gm;

        self->enableStdMove = false;
        self->speed = 3;

        // Setup player
        self->position.x = 100;
        self->position.y = 70;

        self->size.x = 32;
        self->size.y = 32;

        self->color = COLOR_RED;

        // Complete setup
        self->CoreReset(gm);
    }
    static void Tick(void *s)
    {
        MAKE_SELF(Player)

        int speed = 3;

        int key = self->gameMode->GetInputManager()->GetInput();

        self->CharacterTick(self->gameMode->GetCrashHandler());

        if (key == KEY_PRGM_LEFT)
            self->position.x -= 1 * speed;
        else if (key == KEY_PRGM_RIGHT)
            self->position.x += 1 * speed;
        else if (key == KEY_PRGM_UP)
            self->position.y -= 1 * speed;
        else if (key == KEY_PRGM_DOWN)
            self->position.y += 1 * speed;
    }
    static void Draw(void *s)
    {
        MAKE_SELF(Player)

        self->CharacterDraw(false);

        self->renderer->RenderSprite(self->position, self->size, _forgbmp, false, false);
    }
};

