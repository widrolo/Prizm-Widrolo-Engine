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
        
        gm->GetTextCanvas()->AddTxtBuff("0 = CRASH\n5 = SAVE GAME\n7 = NEW SAVE\n8 = LOAD SAVE", 3, 10, 50);

        // Complete setup
        self->CoreReset();
    }
    static void Tick(void *s)
    {
        MAKE_SELF(Player)

        self->CharacterTick(self->gameMode->GetCrashHandler());
        
        if (self->key == KEY_CHAR_0)
            self->gameMode->GetCrashHandler()->Crash("  Invoked Crash");

        if (self->key == KEY_CHAR_5)
        {
            self->gameMode->GetSaveManager()->SetData(0, self->GetPosition().x);
            self->gameMode->GetSaveManager()->SetData(32, self->GetPosition().y);
            self->gameMode->GetSaveManager()->SaveToFile();
        }

        if (self->key == KEY_CHAR_7)
        {
            self->gameMode->GetSaveManager()->CreateNewSaveFile();
        }
        
        if (self->key == KEY_CHAR_8)
        {
            self->gameMode->GetSaveManager()->LoadSaveFromFile();

            Vector2 newPos;

            newPos.x = (unsigned short)self->gameMode->GetSaveManager()->GetData(0);
            newPos.y = (unsigned short)self->gameMode->GetSaveManager()->GetData(32);
            self->gameMode->GetTextCanvas()->ClearBuff(5);
            self->gameMode->GetTextCanvas()->AddIntBuff(newPos.x, 5, 10, 30);
            self->gameMode->GetTextCanvas()->ClearBuff(4);
            self->gameMode->GetTextCanvas()->AddIntBuff(newPos.y, 4, 10, 40);

            self->SetPosition(newPos);
        }

        if (self->key == KEY_CHAR_9)
            self->gameMode->GetSaveManager()->SetData(32, self->GetPosition().x);

        
    }
    static void Draw(void *s)
    {
        MAKE_SELF(Player)

        self->CharacterDraw(true);
    }
};

