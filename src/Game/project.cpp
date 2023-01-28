#include "./GM_GameMode.h"
#include "../Engine/include/core/EngineDefines.h"


#include "./Player.cpp"
#include "./Objects/World.cpp"
#include "./Objects/Barrier.cpp"

// Game objects
Player player;
World world;
Barrier barrier;

ENGINE_SETUP

// Initialize engine components
void Game::Awake(Game *pGame)
{
    ENGINE_AWAKE
}
// Initialize gameplay objects
void Game::Start()
{  
    pGameMode.GetTextCanvas()->AddTxtBuff("THIS IS JUST A DEMO OF\nTHE ENGINE AND DOES NOT\nREPRESENT ANY GAME\nENGINE VERSION: 0.8 ALPHA", 1, 180, 180);
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
    ENGINE_DRAW(
        world.Draw();
        barrier.Draw();
        player.Draw();
    )
}
// Ends Game execution by locking it after a crash
// here you can attempt to save the game one last time
void Game::End()
{
    CrashHandler* cr = pGameMode.GetCrashHandler();
    cr->EndProgram();
}
