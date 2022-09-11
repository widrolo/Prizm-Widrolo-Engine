#include "Game/project.cpp"
#include "Engine/include/core/game.h"

int main() {
    Game game;
    game.Awake();
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
