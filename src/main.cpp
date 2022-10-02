#include "Game/project.cpp"
#include "Engine/include/core/game.h"

int main() {
    Game game;
    game.Awake();
    Bdisp_AllClr_VRAM();
#if __FINAL || __EMULATE_FINAL
    PrintXY(5, 2, "Press Any Key", TEXT_MODE_TRANSPARENT_BACKGROUND, COLOR_BLACK);
#endif 
    bool isRunning = true;

    game.Start();
    while (isRunning) 
    {
        game.Tick();
        game.Draw();
    }
    game.End();
    return 0;
}
