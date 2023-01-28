#pragma once

#include "./game.h"
#include "./CrashHandler.h"
#include "./Collision.h"
#include "./Allocator.h"
#include "./File.h"
#include "./Randomizer.h"
#include "./Text.h"
#include "./InputManager.h"


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
};