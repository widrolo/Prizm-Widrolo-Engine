#pragma once

#include "./game.h"
#include "./CrashHandler.h"
#include "./Collision.h"
#include "./Allocator.h"
#include "./File.h"
#include "./Randomizer.h"
#include "./Text.h"
#include "./InputManager.h"
#include "./SaveGame.h"
#include "./EventsManager.h"
#include "./InputManager.h"
#include "./DebugConsole.h"


namespace WEngine
{
    class GameModeBase
    {
    protected:
        Game *pGameSession;
        CrashHandler *pCrashHandler;
        Allocator *pAllocator;
        FileReader *pFileHandler;
        CollisionManger *pCollisionManager;
        TextCanvas *pMainCanvas;
        Randomizer *pRandomizer;
        SaveManager *pSaveManger;
        EventsManager *pEventManager;
        InputManager *pInputManager;
        DebugConsole *pDebugConsole;

    public:
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
            this->pCrashHandler = (CrashHandler*)sys_malloc(sizeof(CrashHandler));
            if (pCrashHandler == nullptr)
            {
                CrashHandler::PanicCrash(crashMsg);
            }
            pCrashHandler->Init(pGame);

            // Init Allocator
            InitSystem<Allocator>(pAllocator, crashMsg);
            pAllocator->Init(pCrashHandler);

            // Init File Reader
            InitSystem<FileReader>(pFileHandler, crashMsg);
            pFileHandler->Init(pCrashHandler);

            // Init Collision Manager
            InitSystem<CollisionManger>(pCollisionManager, crashMsg);
            pCollisionManager->Init();

            // Init Main Text Canvas
            InitSystem<TextCanvas>(pMainCanvas, crashMsg);
            pMainCanvas->Init();

            // Init Randomizer
            InitSystem<Randomizer>(pRandomizer, crashMsg);

            // Init Save Manger
            InitSystem<SaveManager>(pSaveManger, crashMsg);
            pSaveManger->Init();

            // Init Events Manager
            InitSystem<EventsManager>(pEventManager, crashMsg);
            pEventManager->Init(pCrashHandler);

            // Init Input Manger
            InitSystem<InputManager>(pInputManager, crashMsg);
            
            // Init Events Manager
            InitSystem<DebugConsole>(pDebugConsole, crashMsg);
            pDebugConsole->Init();
        }

        void DealocateSystems()
        {
            // crash handler wont be deleted because its needed until the very end

            sys_free(pAllocator);
            sys_free(pFileHandler);
            sys_free(pCollisionManager);
            sys_free(pMainCanvas);
            sys_free(pRandomizer);
            sys_free(pSaveManger);
            sys_free(pEventManager);
            sys_free(pInputManager);
            sys_free(pDebugConsole);
        }

        Game* GetGameSession() { return pGameSession; }
        CrashHandler* GetCrashHandler() { return pCrashHandler; }
        Allocator* GetAllocator() { return pAllocator; }
        FileReader* GetFileReader() { return pFileHandler; }
        CollisionManger* GetCollisionManger() { return pCollisionManager; }
        TextCanvas* GetTextCanvas() { return pMainCanvas; }
        Randomizer* GetRandomizer() { return pRandomizer; }
        SaveManager* GetSaveManager() { return pSaveManger; }
        EventsManager* GetEventsManager() { return pEventManager; }
        InputManager* GetInputManager() { return pInputManager; }
        DebugConsole* GetDebugConsole() { return pDebugConsole; }
    };
}