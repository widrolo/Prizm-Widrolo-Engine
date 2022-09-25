#include "./GameModeBase.h"
#include "./game.h"

#pragma once

class Player;

class GameModeManager
{
private:
    GameModeBase *pCurrentGameMode;
    Player *pCurrentPlayer;
    Game *pGameInstance;
public:
    void SetGameMode(GameModeBase *pNewGameMode)
    {
        pCurrentGameMode = pNewGameMode;
    }

    void SetCurrentPlayer(Player *pNewPlayer)
    {
        pCurrentPlayer = pNewPlayer;
    }

    Player* GetPlayer()
    {
        return pCurrentPlayer;
    }

    GameModeBase* GetGameMode()
    {
        return pCurrentGameMode;
    }
};