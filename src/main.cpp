#include "Game/project.cpp"
#include "Engine/include/core/game.h"

int main() {
    // Load Game
    Game* pGame = (Game*)sys_malloc(sizeof(Game));
    pGame->EnginePreInit();
    pGame->isRunning = true;
    pGame->Awake(pGame);

    // Clear the screen in preperation of Game start
    Bdisp_AllClr_VRAM();
    
    // Draw first Frame
    pGame->Draw();
    // Game start and Game loop begin
    pGame->Start();
    while (pGame->isRunning) 
    {
        pGame->Tick();
        pGame->Draw();
        OS_InnerWait_ms(10);
    }
    // Game end (use for soft crashes only)
    pGame->End();
    sys_free(pGame);
    return 0;
}
