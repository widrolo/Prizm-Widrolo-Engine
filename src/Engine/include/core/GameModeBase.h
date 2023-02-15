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


namespace WEngine
{
    class GameModeBase
    {
    protected:
        Game *pGameSession;
        WEngine::CrashHandler *pCrashHandler;
        WEngine::Allocator *pAllocator;
        WEngine::FileReader *pFileHandler;
        WEngine::CollisionManger *pCollisionManager;
        WEngine::TextCanvas *pMainCanvas;
        WEngine::Randomizer *pRandomizer;
        WEngine::SaveManager *pSaveManger;
    };
}