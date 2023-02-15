#pragma once

#include "../Engine/include/core/GameModeBase.h"
#include <fxcg/heap.h>

class GM_GameMode : WEngine::GameModeBase
{
public: // Engine Things
    void InitGame(Game *pGame)
    {
        const char* crashMsg = "  Engine Init Fail";
        this->pGameSession = pGame;
        // Init Crash Handler
        this->pCrashHandler = (WEngine::CrashHandler*)sys_malloc(sizeof(WEngine::CrashHandler));
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
        this->pAllocator = (WEngine::Allocator*)sys_malloc(sizeof(WEngine::Allocator));
        if (pAllocator == nullptr)
            pCrashHandler->Crash(crashMsg);
        pAllocator->Init(pCrashHandler);

        // Init File Reader
        this->pFileHandler = (WEngine::FileReader*)sys_malloc(sizeof(WEngine::FileReader));
        if (pFileHandler == nullptr)
            pCrashHandler->Crash(crashMsg);
        pFileHandler->Init(pCrashHandler);

        // Init Collision Manager
        this->pCollisionManager = (WEngine::CollisionManger*)sys_malloc(sizeof(WEngine::CollisionManger));
        if (pCollisionManager == nullptr)
            pCrashHandler->Crash(crashMsg);
        pCollisionManager->Init();
        
        // Init Main Text Canvas
        this->pMainCanvas = (WEngine::TextCanvas*)sys_malloc(sizeof(WEngine::TextCanvas));
        if (pMainCanvas == nullptr)
            pCrashHandler->Crash(crashMsg);
        pMainCanvas->Init();

        // Init Randomizer
        this->pRandomizer = (WEngine::Randomizer*)sys_malloc(sizeof(WEngine::Randomizer));
        if (pRandomizer == nullptr)
            pCrashHandler->Crash(crashMsg);

        // Init Main Text Canvas
        this->pSaveManger = (WEngine::SaveManager*)sys_malloc(sizeof(WEngine::SaveManager));
        if (pMainCanvas == nullptr)
            pCrashHandler->Crash(crashMsg);
        pSaveManger->Init();
    }
public: // Engine Getters
    WEngine::CrashHandler* GetCrashHandler() { return pCrashHandler; }
    WEngine::Allocator* GetAllocator() { return pAllocator; }
    WEngine::FileReader* GetFileReader() { return pFileHandler; }
    WEngine::CollisionManger* GetCollisionManger() { return pCollisionManager; }
    WEngine::TextCanvas* GetTextCanvas() { return pMainCanvas; }
    WEngine::Randomizer* GetRandomizer() { return pRandomizer; }
    WEngine::SaveManager* GetSaveManager() { return pSaveManger; }
};
