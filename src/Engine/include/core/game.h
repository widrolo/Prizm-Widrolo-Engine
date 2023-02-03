#pragma once

#include "./../../../Game/GM_GameMode.h"
#include "./EngineDefines.h"
#include <fxcg/display.h>

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

    void Awake(Game *pGame);
    void Start()
    {
        for (int i = 0; i < 64; i++)
        {
            if (awakePtrs[i] == nullptr || selfs[i] == nullptr)
                continue;

            (*awakePtrs[i])(selfs[i], nullptr); // TODO: pass in real game mode
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

public: // Game pointer caller

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