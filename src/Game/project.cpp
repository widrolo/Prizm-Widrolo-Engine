#include "./GM_GameMode.h"
#include "../Engine/include/core/EngineDefines.h"


#include "./Player.h"
#include "./Objects/World.cpp"
#include "./Objects/Barrier.h"

// Permanent game objects
Player *pPlayer;
World *pWorld;
Barrier *pBarrier;

ENGINE_SETUP

// Initialize engine components and game objects
void Game::Awake(Game *pGame)
{
    ENGINE_AWAKE

    pBarrier = (Barrier*)pGameMode.GetAllocator()->AllocateEZ(sizeof(Barrier));
    pGame->AddObj(&pBarrier->Reset, &pBarrier->Tick, &pBarrier->Draw, 0, pBarrier);

    pPlayer = (Player*)pGameMode.GetAllocator()->AllocateEZ(sizeof(Player));
    pGame->AddObj(&pPlayer->Reset, &pPlayer->Tick, &pPlayer->Draw, 1, pPlayer);

    pGameMode.GetTextCanvas()->AddTxtBuff("THIS IS JUST A DEMO OF\nTHE ENGINE AND DOES NOT\nREPRESENT ANY GAME\nENGINE VERSION: 0.8 ALPHA", 1, 180, 180);
}

// Ends Game execution by locking it after a crash
// here you can attempt to save the game one last time
void Game::End()
{
    CrashHandler* cr = pGameMode.GetCrashHandler();
    cr->EndProgram();
}
