#pragma once

#include "./GM_GameMode.h"
#include "./Objects/Barrier.h"
#include "../Engine/include/core/ImplementMinimal.h"
#include "../Engine/include/math/math.h"

#include "./Data/spritedata.h"
#include "./Data/PlayerSprite.hpp"

class Player : WEngine::Character
{
private:
    int spawnbuffcount;
    GM_GameMode *gameMode;
public:
    void ChangePosDispatch()
    {
        int *pos = (int*)sys_malloc(sizeof(int) * 2);

        pos[0] = 10;
        pos[1] = 10;

        gameMode->GetEventsManager()->Dispatch(0, (void*)pos);
    }
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

        self->size.x = 8;
        self->size.y = 8;

        self->color = COLOR_RED;
        self->spawnbuffcount = 10;

        Plallete8Bit *pall = (Plallete8Bit*)gm->GetAllocator()->AllocateEZ(sizeof(Plallete8Bit));
        pall->colors[0] = COLOR_CLEAR;
        pall->colors[1] = COLOR_RED;
        pall->colors[2] = COLOR_GREEN;
        pall->colors[3] = COLOR_BLUE;

        self->renderer->ApplyColorPallete(pall, nullptr, nullptr, nullptr);

        // Complete setup
        self->CoreReset(gm);
    }
    static void Tick(void *s)
    {
        MAKE_SELF(Player)

        int speed = 3;

        int key = self->gameMode->GetInputManager()->GetInput();

        self->CharacterTick();

        if (key == KEY_PRGM_LEFT)
            self->position.x -= 1 * speed;
        else if (key == KEY_PRGM_RIGHT)
            self->position.x += 1 * speed;
        else if (key == KEY_PRGM_UP)
            self->position.y -= 1 * speed;
        else if (key == KEY_PRGM_DOWN)
            self->position.y += 1 * speed;

        if (key == KEY_PRGM_0)
        {
            NEW_OBJECT_AFTER(Barrier, b1, self->spawnbuffcount)
            self->spawnbuffcount++;
        }
        if (key == KEY_PRGM_1)
        {
            self->ChangePosDispatch();
        }
    }
    static void Draw(void *s)
    {
        MAKE_SELF(Player)

        self->CharacterDraw(false);

        //self->renderer->RenderSprite(self->position, self->size, _forgbmp, false, false);
        self->renderer->RenderSpriteSimple8Bit(_playerSprite, self->position.x, self->position.y, self->size.x, self->size.y);
    }
};

