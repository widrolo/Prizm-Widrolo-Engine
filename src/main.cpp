#include "Game/project.cpp"
#include "Engine/include/core/game.h"

int main() {
    // Load game
    Game* game = (Game*)sys_malloc(sizeof(Game));
    game->EnginePreInit();
    game->isRunning = true;
    game->Awake(game);

    // Clear the screen in preperation of game start
    Bdisp_AllClr_VRAM();
    
    // Draw first Frame
    game->Draw();
    // Game start and Game loop begin
    game->Start();
    while (game->isRunning) 
    {
        game->Tick();
        game->Draw();
    }
    // Game end (use for soft crashes only)
    game->End();
    return 0;
}
