#include "../Engine/include/core/RuntimeManagers.h"
#include "../Engine/include/core/Collision.h"
#include "../Engine/include/core/game.h"
// Game objects
#include "./Objects/World.cpp"
#include "./Objects/Barrier.cpp"
#include "./Player.cpp"

// Allocate managers
GameModeManager *pGameModeManger = static_cast<GameModeManager*>(sys_malloc(sizeof(GameModeManager)));
GameModeBase gameMode;
//CollisionManger *pCollisionManager = static_cast<CollisionManger*>(sys_malloc(sizeof(CollisionManger)));
CollisionManger pCollisionManager;

// Create players
Player player;
World world;
Barrier barrier;
void Game::Awake()
{
    pGameModeManger->SetGameMode(&gameMode);
    pGameModeManger->SetCurrentPlayer(&player);
    pGameModeManger->SetCollisionManager(&pCollisionManager);
}
void Game::Start()
{  
    world.Reset();
    barrier.Reset(pGameModeManger, &pCollisionManager);
    player.Reset(pGameModeManger, &pCollisionManager);
}
void Game::Tick()
{
    world.Tick();
    barrier.Tick();
    player.Tick();
}
void Game::Draw()
{
    Bdisp_AllClr_VRAM();
    world.Draw();
    barrier.Draw();
    player.Draw();
}
void Game::End()
{

}