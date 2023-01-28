#include "./GM_GameMode.h"
#include "../Engine/include/core/EngineDefines.h"


#include "./Player.cpp"
#include "./Objects/World.cpp"
#include "./Objects/Barrier.cpp"

// Permanent game objects
Player *pPlayer;
World *pWorld;
Barrier *pBarrier;

ENGINE_SETUP

// Initialize engine components
void Game::Awake(Game *pGame)
{
    ENGINE_AWAKE
}
// Initialize gameplay objects
void Game::Start()
{  
    // Create Objects (no pointer checking required)
    pPlayer = (Player*)pGameMode.GetAllocator()->AllocateEZ(sizeof(Player));
    pWorld = (World*)pGameMode.GetAllocator()->AllocateEZ(sizeof(World));
    pBarrier = (Barrier*)pGameMode.GetAllocator()->AllocateEZ(sizeof(Barrier));

    // Call reset functions
    pGameMode.GetTextCanvas()->AddTxtBuff("THIS IS JUST A DEMO OF\nTHE ENGINE AND DOES NOT\nREPRESENT ANY GAME\nENGINE VERSION: 0.8 ALPHA", 1, 180, 180);
    pPlayer->Reset(&pGameMode);
    pWorld->Reset();
    pBarrier->Reset(&pGameMode);
}
// Tick gameplay objects
void Game::Tick()
{
    pPlayer->Tick();
}
// Draw gameplay
void Game::Draw()
{
    ENGINE_DRAW(
        pWorld->Draw();
        pBarrier->Draw();
        pPlayer->Draw();
    )
}
// Ends Game execution by locking it after a crash
// here you can attempt to save the game one last time
void Game::End()
{
    CrashHandler* cr = pGameMode.GetCrashHandler();
    cr->EndProgram();
}
