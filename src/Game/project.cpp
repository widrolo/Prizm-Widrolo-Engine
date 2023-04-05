#include "./GM_GameMode.h"
#include "../Engine/include/core/EngineDefines.h"


#include "./Player.h"
#include "./Objects/World.h"
#include "./Objects/Barrier.h"
#include "./Objects/RandomGuy.h"



// Initialize engine components and game objects
void Game::Awake(Game *pGame)
{
    ENGINE_BOOT

    NEW_OBJECT(World, w1, 0)
    NEW_OBJECT(RandomGuy, rg1, 1);
    NEW_OBJECT(Player, p1, 3)
}

// Ends Game execution by locking it after a crash
// here you can attempt to save the game one last time
// Panic crashes that happen because of an unrecoverable
// error will not call this function.
void Game::End()
{
    WEngine::CrashHandler* cr = pGameMode->GetCrashHandler();

    // Place own code here

    pGameMode->DealocateSystems();
    DeallocEverything();
    cr->EndProgram();
}
