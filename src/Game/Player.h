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
        MAKE_SELF(Player)

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

        gm->GetTextCanvas()->AddIntBuff(gm->GetSaveManager()->GetData(0), 2, 10, 10);

        gm->GetSaveManager()->SetData(10, 0x0A0F);

        // Complete setup
        self->CoreReset();
    }
    static void Tick(void *s)
    {
        MAKE_SELF(Player)

        self->CharacterTick(self->gameMode->GetCrashHandler());
        
        if (self->key == KEY_CHAR_7)
            self->gameMode->GetSaveManager()->CreateNewSaveFile();
        
        if (self->key == KEY_CHAR_8)
            self->gameMode->GetSaveManager()->LoadSaveFromFile();
    }
    static void Draw(void *s)
    {
        MAKE_SELF(Player)

        self->CharacterDraw(true);
    }
};

