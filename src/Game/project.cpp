#include "./GM_GameMode.h"
#include "../Engine/include/core/EngineDefines.h"

#include <fxcg/display.h>

#include "./Player.cpp"

// Game objects
Player player;

// Create managers
GM_GameMode pGameMode;



// Initialize engine components
void Game::Awake(Game *pGame)
{
    pGameMode.InitGame(pGame);
}
// Initialize gameplay objects
void Game::Start()
{  
    player.Reset(&pGameMode);
}
// Tick gameplay objects
void Game::Tick()
{
    player.Tick();
}
// Draw gameplay
void Game::Draw()
{
    player.Draw();
}
// End gameplay (if this gets called, then the game crashed)
void Game::End()
{

}