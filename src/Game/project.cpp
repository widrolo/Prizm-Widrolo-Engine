#include "../Engine/include/core/RuntimeManagers.h"
#include "../Engine/include/core/Collision.h"
#include "../Engine/include/core/game.h"
#include "../Engine/include/core/CrashHandler.h"
#include "../Engine/include/core/Text.h"
// Game objects
#include "./Objects/World.cpp"
#include "./Objects/Barrier.cpp"
#include "./Player.cpp"

// Create managers
GameModeManager *pGameModeManger = static_cast<GameModeManager*>(sys_malloc(sizeof(GameModeManager)));
CrashHandler crashHandler;
GameModeBase gameMode;
CollisionManger collisionManager;
TextCanvas textCanvas;

// Create objects for gameplay
Player player;
World world;
Barrier barrier;
// Initialize engine components
void Game::Awake(Game *pGame)
{
    pGameModeManger->SetGameMode(&gameMode);
    pGameModeManger->SetCurrentPlayer(&player);
    pGameModeManger->SetCollisionManager(&collisionManager);

    crashHandler.Init(pGame);
    textCanvas.Init();
}
// Initialize gameplay objects
void Game::Start()
{  
    char *text1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    char *text2 = "!$%&/()=?{[]}\\+#- .,;:_\'*~<>|"; 

    world.Reset();
    barrier.Reset(pGameModeManger, &collisionManager);
    player.Reset(pGameModeManger, &collisionManager, &crashHandler);

    textCanvas.AddTxtBuff(text1, 0, 10, 8);
    textCanvas.AddTxtBuff(text2, 1, 10, 16);
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

    textCanvas.Draw();
}
// End gameplay (if this gets called, then the game crashed)
void Game::End()
{
    crashHandler.EndProgram();
}