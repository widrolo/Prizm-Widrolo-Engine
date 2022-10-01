#include "../Engine/include/core/RuntimeManagers.h"
#include "../Engine/include/core/Collision.h"
#include "../Engine/include/core/game.h"
#include "./Objects/World.cpp"
#include "./Player.cpp"

GameModeManager *pGameModeManger = static_cast<GameModeManager*>(sys_malloc(sizeof(GameModeManager)));

GameModeBase gameMode;
CollisionManger *collsionManager = static_cast<CollisionManger*>(sys_malloc(sizeof(CollisionManger)));

Player player;
World world;
void Game::Awake()
{
    pGameModeManger->SetGameMode(&gameMode);
    pGameModeManger->SetCurrentPlayer(&player);
    pGameModeManger->SetCollisionManager(collsionManager);
}
void Game::Start()
{  
    world.Reset();
    player.Reset(pGameModeManger);
}
void Game::Tick()
{
    world.Tick();
    player.Tick();
}
void Game::Draw()
{
    Bdisp_AllClr_VRAM();
    world.Draw();
    player.Draw();
}
void Game::End()
{

}