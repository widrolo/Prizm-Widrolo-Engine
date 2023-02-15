#include "./GM_GameMode.h"
#include "../Engine/include/core/EngineDefines.h"


#include "./Player.h"
#include "./Objects/World.h"
#include "./Objects/Barrier.h"
#include "./Objects/RandomGuy.h"

// Permanent game objects
Player *pPlayer;
World *pWorld;
Barrier *pBarrier;
RandomGuy *pRandomGuy;

ENGINE_SETUP

// Initialize engine components and game objects
void Game::Awake(Game *pGame)
{
    ENGINE_AWAKE

    pGame->EngineSetGamemode(&PGAMEMODE, PGAMEMODE.GetTextCanvas());
    
    pPlayer = (Player*)PGAMEMODE.GetAllocator()->AllocateEZ(sizeof(Player));
    pGame->AddObj(&pPlayer->Reset, &pPlayer->Tick, &pPlayer->Draw, 3, pPlayer);

    PGAMEMODE.GetTextCanvas()->AddTxtBuff("THIS IS JUST A DEMO OF\nTHE ENGINE AND DOES NOT\nREPRESENT ANY GAME\nENGINE VERSION: 0.8 ALPHA", 1, 180, 180);
}

// Ends Game execution by locking it after a crash
// here you can attempt to save the game one last time
void Game::End()
{
    WEngine::CrashHandler* cr = PGAMEMODE.GetCrashHandler();
    cr->EndProgram();
}
