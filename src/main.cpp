#include "Game/project.cpp"
#include "Engine/include/core/game.h"

int main() {
    // Load game
    Game game;
    game.Awake();

    // Clear the screen in preperation of game start
    Bdisp_AllClr_VRAM();

    // Start Notification (basic anti piracy)
#if __FINAL || __EMULATE_FINAL
    PrintXY(5, 6, "   An Filip", TEXT_MODE_TRANSPARENT_BACKGROUND, COLOR_BLACK);
#endif 

    // Game start and Game loop begin
    game.Start();
    bool isRunning = true;
    while (isRunning) 
    {
        game.Tick();
        game.Draw();
    }
    // Game end (use for soft crashes only)
    game.End();
    return 0;
}
