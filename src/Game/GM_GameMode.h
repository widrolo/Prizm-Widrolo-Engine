#pragma once

#include "../Engine/include/core/GameModeBase.h"
#include <fxcg/heap.h>

class GM_GameMode : WEngine::GameModeBase
{
public: // Engine Things

    template<typename T>
    void InitSystem(void *system, const char* msg)
    {
        system = (T*)sys_malloc(sizeof(T));
        if (system == nullptr)
            pCrashHandler->Crash(msg);

    }

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
        InitSystem<WEngine::Allocator>(pAllocator, crashMsg);
        pAllocator->Init(pCrashHandler);

        // Init File Reader
        InitSystem<WEngine::FileReader>(pFileHandler, crashMsg);
        pFileHandler->Init(pCrashHandler);

        // Init Collision Manager
        InitSystem<WEngine::CollisionManger>(pCollisionManager, crashMsg);
        pCollisionManager->Init();
        
        // Init Main Text Canvas
        InitSystem<WEngine::TextCanvas>(pMainCanvas, crashMsg);
        pMainCanvas->Init();

        // Init Randomizer
        InitSystem<WEngine::Randomizer>(pRandomizer, crashMsg);

        // Init Save Manger
        InitSystem<WEngine::SaveManager>(pSaveManger, crashMsg);
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
