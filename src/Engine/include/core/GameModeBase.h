#pragma once

#include "./../../../Game/Player.h"
#include "./game.h"
#include "./CrashHandler.h"
#include "./Collision.h"
#include "./Allocator.h"
#include "./File.h"
#include "./Randomizer.h"
#include "./Text.h"

#define ENGINE_SETUP CrashHandler crashHandler;CollisionManger collisionManager;Allocator allocator;FileReader fileHandler;Randomizer randomizer;TextCanvas mainCanvas;
#define ENGINE_SETUP_ARGS *crashHandler, *collisionManager, *allocator, *fileHandler, *randomizer, *mainCanvas

class GameModeBase
{
public:
    Game *pGame;
    CrashHandler *pCrashHandler;
    CollisionManger *pCollisionManager;
    Allocator *pAllocator;
    FileReader *pFileHandler;
    Randomizer *pRandomizer;
    TextCanvas *pMainCanvas;

public:
    void InitGame(Game *pGame, CrashHandler *pCrashHandler, CollisionManger *pCollisionManager, 
                    Allocator *pAllocator, FileReader *pFileHandler, Randomizer *pRandomizer, TextCanvas *pMainCanvas)
    {

    }
};