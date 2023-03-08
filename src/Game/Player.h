#pragma once

#include "./GM_GameMode.h"
#include "../Engine/include/core/ImplementMinimal.h"
#include "../Engine/include/math/math.h"

class Player : WEngine::Character
{
private:
    GM_GameMode *gameMode;
    Vector2 pos;
    Vector2 scl;
public:
    static void Reset(void *s, GM_GameMode *gm)
    {
        MAKE_SELF(Player)

        // Setup object
        self->gameMode = gm;

        self->enableStdMove = false;
        self->speed = 3;

        // Setup player
        self->pos.x = 100;
        self->pos.y = 70;
        self->SetPosition(self->pos);

        self->scl.x = 16;
        self->scl.y = 16;
        self->SetScale(self->scl);

        self->color = COLOR_RED;
        
        gm->GetTextCanvas()->AddTxtBuff("0 = CRASH\n5 = SAVE GAME\n7 = NEW SAVE\n8 = LOAD SAVE", 3, 10, 50);

        // Complete setup
        self->CoreReset();
    }
    static void Tick(void *s)
    {
        MAKE_SELF(Player)

        int speed = 3;

        int key = self->gameMode->GetInputManager()->GetKey();

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

        self->CharacterDraw(true);
    }
};

