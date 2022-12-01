#include "../Engine/include/core/RuntimeManagers.h"
#include "../Engine/include/core/Collision.h"
#include "../Engine/include/core/game.h"
#include "../Engine/include/core/CrashHandler.h"
// Game objects
#include "./Objects/World.cpp"
#include "./Objects/Barrier.cpp"
#include "./Player.cpp"

// Create managers
GameModeManager *pGameModeManger = static_cast<GameModeManager*>(sys_malloc(sizeof(GameModeManager)));
CrashHandler crashHandler;
GameModeBase gameMode;
CollisionManger collisionManager;

// Create objects for gameplay
Player player;
World world;
Barrier barrier;
// Initialize engine components
void Game::Awake()
{
    pGameModeManger->SetGameMode(&gameMode);
    pGameModeManger->SetCurrentPlayer(&player);
    pGameModeManger->SetCollisionManager(&collisionManager);
}
// Initialize gameplay objects
void Game::Start()
{  
    world.Reset();
    barrier.Reset(pGameModeManger, &collisionManager);
    player.Reset(pGameModeManger, &collisionManager, &crashHandler);
}
// Tick gameplay objects
void Game::Tick()
{
    world.Tick();
    barrier.Tick();
    player.Tick();
}
// Draw gameplay
void Game::Draw()
{
    Bdisp_AllClr_VRAM();
    world.Draw();
    barrier.Draw();
    player.Draw();
}
// End gameplay (if this gets called, then the game crashed)
void Game::End()
{

}