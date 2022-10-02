#include "./Collision.h"
#include "./GameModeBase.h"
#include "./game.h"

#pragma once

class Player;

class GameModeManager
{
private: // Pointers To Important Parts Of The Program
    GameModeBase *pCurrentGameMode;
    CollisionManger *pCurrentCollsionManager;
    Player *pCurrentPlayer;
    Game *pGameInstance;

public: // Access Functions For The Pointers
    void SetGameMode(GameModeBase *pNewGameMode) { pCurrentGameMode = pNewGameMode; }
    void SetCurrentPlayer(Player *pNewPlayer) { pCurrentPlayer = pNewPlayer; }
    void SetCollisionManager(CollisionManger *pNewCollisionManger) { pCurrentCollsionManager = pNewCollisionManger; }

    Player* GetPlayer() { return pCurrentPlayer; }
    GameModeBase* GetGameMode() { return pCurrentGameMode; }
    CollisionManger* GetCollisionManager() { return pCurrentCollsionManager; }
};