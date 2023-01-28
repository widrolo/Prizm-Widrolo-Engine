#pragma once

#include "../Engine/include/core/GameModeBase.h"
#include <fxcg/heap.h>

class GM_GameMode : GameModeBase
{
public: // Engine Things
    void InitGame(Game *pGame)
    {
        const char* crashMsg = "  Engine Init Fail";
        this->pGameSession = pGame;
        // Init Crash Handler
        this->pCrashHandler = (CrashHandler*)sys_malloc(sizeof(CrashHandler));
        if (pCrashHandler == nullptr)
        {
            Bdisp_AllClr_VRAM();
            PrintXY(3, 2, crashMsg, TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);
            Bdisp_PutDisp_DD();
            int dummy;
            while (true)
                GetKey(&dummy);
        }
        pCrashHandler->Init(pGame);

        // Init Allocator
        this->pAllocator = (Allocator*)sys_malloc(sizeof(Allocator));
        if (pAllocator == nullptr)
            pCrashHandler->Crash(crashMsg);
        pAllocator->Init(pCrashHandler);

        // Init File Reader
        this->pFileHandler = (FileReader*)sys_malloc(sizeof(FileReader));
        if (pFileHandler == nullptr)
            pCrashHandler->Crash(crashMsg);
        pFileHandler->Init(pCrashHandler);

        // Init Collision Manager
        this->pCollisionManager = (CollisionManger*)sys_malloc(sizeof(CollisionManger));
        if (pCollisionManager == nullptr)
            pCrashHandler->Crash(crashMsg);
        pCollisionManager->Init();
        
        // Init Main Text Canvas
        this->pMainCanvas = (TextCanvas*)sys_malloc(sizeof(TextCanvas));
        if (pMainCanvas == nullptr)
            pCrashHandler->Crash(crashMsg);
        pMainCanvas->Init();

        // Init Randomizer
        this->pRandomizer = (Randomizer*)sys_malloc(sizeof(Randomizer));
        if (pRandomizer == nullptr)
            pCrashHandler->Crash(crashMsg);
    }
public: // Engine Getters
    CrashHandler* GetCrashHandler() { return pCrashHandler; }
    Allocator* GetAllocator() { return pAllocator; }
    FileReader* GetFileReader() { return pFileHandler; }
    CollisionManger* GetCollisionManger() { return pCollisionManager; }
    TextCanvas* GetTextCanvas() { return pMainCanvas; }
    Randomizer* GetRandomizer() { return pRandomizer; }
};
