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

        // Complete setup
        self->CoreReset();
    }
    static void Tick(void *s)
    {
        MAKE_SELF(Player)

        self->CharacterTick(self->gameMode->GetCrashHandler());
        
        if (self->key == KEY_CHAR_5)
            self->gameMode->GetSaveManager()->SaveToFile();

        if (self->key == KEY_CHAR_7)
            self->gameMode->GetSaveManager()->CreateNewSaveFile();
        
        if (self->key == KEY_CHAR_8)
            self->gameMode->GetSaveManager()->LoadSaveFromFile();

        if (self->key == KEY_CHAR_9)
            self->gameMode->GetSaveManager()->SetData(32, self->GetPosition().x);

        self->gameMode->GetTextCanvas()->ClearBuff(4);
        self->gameMode->GetTextCanvas()->AddIntBuff(self->gameMode->GetSaveManager()->GetData(32), 4, 10, 10);
    }
    static void Draw(void *s)
    {
        MAKE_SELF(Player)

        self->CharacterDraw(true);
    }
};

