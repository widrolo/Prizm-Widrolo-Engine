#include "./GM_GameMode.h"
#include "../Engine/include/core/EngineDefines.h"


#include "./Player.h"
#include "./Objects/World.h"
#include "./Objects/Barrier.h"
#include "./Objects/RandomGuy.h"

ENGINE_SETUP

// Initialize engine components and game objects
void Game::Awake(Game *pGame)
{
    ENGINE_AWAKE

    NEW_OBJECT(World, w1, 0)
    NEW_OBJECT(Barrier, b1, 1)
    NEW_OBJECT(RandomGuy, rg1, 2)
    NEW_OBJECT(Player, p1, 4)

    PGAMEMODE.GetTextCanvas()->AddTxtBuff("THIS IS JUST A DEMO OF\nTHE ENGINE AND DOES NOT\nREPRESENT ANY GAME\n\nENGINE VERSION: 0.8 ALPHA", 1, 180, 170);
}

// Ends Game execution by locking it after a crash
// here you can attempt to save the game one last time
void Game::End()
{
    WEngine::CrashHandler* cr = PGAMEMODE.GetCrashHandler();
    cr->EndProgram();
}
