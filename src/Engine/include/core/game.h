#pragma once

#include "./EngineDefines.h"
#include <fxcg/display.h>
#include "./../../../Game/GM_GameMode.h"

#include "./Text.h"


class GM_GameMode;

class Game
{
private: // Function pointers
    void (*awakePtrs[__MAX_OBJECTS])(void *self, GM_GameMode*);
    void (*tickPtrs[__MAX_OBJECTS])(void *self);
    void (*drawPtrs[__MAX_OBJECTS])(void *self);
    void *selfs[__MAX_OBJECTS];
public: // Game runtime called my main()
    bool isRunning;
    GM_GameMode *pGameMode;
    WEngine::TextCanvas *pTextCanvas;
    void Awake(Game *pGame);
    void Start()
    {
        for (int i = 0; i < __MAX_OBJECTS; i++)
        {
            if (awakePtrs[i] == nullptr || selfs[i] == nullptr)
                continue;
            (*awakePtrs[i])(selfs[i], pGameMode);
        }
    }
    void Tick()
    {
        for (int i = 0; i < __MAX_OBJECTS; i++)
        {
            if (tickPtrs[i] == nullptr || selfs[i] == nullptr)
                continue;
            (*tickPtrs[i])(selfs[i]);
        }
    }
    void Draw()
    {
        if (__RENDERING == 0)
            return;
        ENGINE_DRAW(
            for (int i = 0; i < __MAX_OBJECTS; i++)
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
        for (int i = 0; i < __MAX_OBJECTS; i++)
        {
            awakePtrs[i] = nullptr;
            tickPtrs[i] = nullptr;
            drawPtrs[i] = nullptr;
            selfs[i] = nullptr;
        }
    }
    void EngineSetGamemode( GM_GameMode *pGM, WEngine::TextCanvas *pTC)
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