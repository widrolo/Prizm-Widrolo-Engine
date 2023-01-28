#include "./GM_GameMode.h"
#include "../Engine/include/core/EngineDefines.h"


#include "./Player.cpp"
#include "./Objects/World.cpp"
#include "./Objects/Barrier.cpp"

// Game objects
Player player;
World world;
Barrier barrier;

// Create managers
ENGINE_SETUP

// Initialize engine components
void Game::Awake(Game *pGame)
{
    ENGINE_AWAKE
}
// Initialize gameplay objects
void Game::Start()
{  
    player.Reset(&pGameMode);
    world.Reset();
    barrier.Reset(&pGameMode);
}
// Tick gameplay objects
void Game::Tick()
{
    player.Tick();
}
// Draw gameplay
void Game::Draw()
{
    ENGINE_DRAW
    world.Draw();
    barrier.Draw();
    player.Draw();
}
// End gameplay (if this gets called, then the game crashed)
void Game::End()
{
    CrashHandler* cr = pGameMode.GetCrashHandler();
    cr->EndProgram();
}
