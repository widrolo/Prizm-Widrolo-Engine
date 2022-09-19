#include "Game/project.cpp"
#include "Engine/include/core/game.h"

int main() {
    Game game;
    game.Awake();
#if __FINAL || __EMULATE_FINAL
    PrintXY(2, 2, "Press any key to start", TEXT_MODE_TRANSPARENT_BACKGROUND, COLOR_BLACK);
#endif 
    bool isRunning = true;
    Bdisp_AllClr_VRAM();

    game.Start();
    while (isRunning) 
    {
        game.Tick();
        game.Draw();
    }
    game.End();
    return 0;
}
