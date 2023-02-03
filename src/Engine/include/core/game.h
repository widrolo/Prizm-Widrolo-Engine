#pragma once

#include "./EngineDefines.h"
#include <fxcg/display.h>
#include "./../../../Game/GM_GameMode.h"

#include "./Text.h"

class GM_GameMode;

class Game
{
private: // Function pointers
    void (*awakePtrs[64])(void *self, GM_GameMode*);
    void (*tickPtrs[64])(void *self);
    void (*drawPtrs[64])(void *self);
    void *selfs[64];
public: // Game runtime called my main()
    bool isRunning;
    GM_GameMode *pGameMode;
    TextCanvas *pTextCanvas;

    void Awake(Game *pGame);
    void Start()
    {
        for (int i = 0; i < 64; i++)
        {
            if (awakePtrs[i] == nullptr || selfs[i] == nullptr)
                continue;

            (*awakePtrs[i])(selfs[i], pGameMode);
        }
    }
    void Tick()
    {
        for (int i = 0; i < 64; i++)
        {
            if (tickPtrs[i] == nullptr || selfs[i] == nullptr)
                continue;

            (*tickPtrs[i])(selfs[i]);
        }
    }
    void Draw()
    {
        ENGINE_DRAW(
            for (int i = 0; i < 64; i++)
            {
                if (drawPtrs[i] == nullptr || selfs[i] == nullptr)
                    continue;

                (*drawPtrs[i])(selfs[i]);
            }
        )
    }
    void End();

public: // Game runtime manger

    void EnginePreInit()
    {
        for (int i = 0; i < 64; i++)
        {
            awakePtrs[i] = nullptr;
            tickPtrs[i] = nullptr;
            drawPtrs[i] = nullptr;
            selfs[i] = nullptr;
        }
    }

    void EngineSetGamemode(GM_GameMode *pGM, TextCanvas *pTC)
    {
        pGameMode = pGM;
        pTextCanvas = pTC;
    }
    	
    // Adds an object to be called later, takes function pointers as first arument
    void AddObj(void (*awakePtr)(void *self, GM_GameMode*), void (*tickPtr)(void *self),
        void (*drawPtr)(void *self), int buffNum, void *self)
    {
        awakePtrs[buffNum] = awakePtr;
        tickPtrs[buffNum] = tickPtr;
        drawPtrs[buffNum] = drawPtr;
        selfs[buffNum] = self;
    }
};