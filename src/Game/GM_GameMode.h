#pragma once

#include "../Engine/include/core/GameModeBase.h"
#include <fxcg/heap.h>

class GM_GameMode : GameModeBase
{
public:
    void InitGame(Game *pGame)
    {
        this->pGameSession = pGame;
        // Init Crash Handler
        this->pCrashHandler = (CrashHandler*)sys_malloc(sizeof(CrashHandler));
        if (pCrashHandler == nullptr)
        {
            Bdisp_AllClr_VRAM();
            PrintXY(3, 2, "  Out Of Memory", TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);
            Bdisp_PutDisp_DD();
            int dummy;
            while (true)
                GetKey(&dummy);
        }
        pCrashHandler->Init(pGameSession);

    }
    CrashHandler* GetCrashHandler()
    {
        return pCrashHandler;
    }
};
