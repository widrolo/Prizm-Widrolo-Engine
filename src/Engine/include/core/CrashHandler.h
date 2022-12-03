#include <string.h>
#include <fxcg/display.h>
#include <fxcg/keyboard.h>
#include <fxcg/misc.h>

#pragma once

class CrashHandler
{
private:
    unsigned char lines[5];
    Game *pGame;
public:
    void Crash()
    {   
        pGame->isRunning = false;
    }
public:
    void Init(Game *pGame)
    {
        this->pGame = pGame;
    }
    void EndProgram()
    {
        MsgBoxPush(6); 
        PrintXY(3, 2, "  Game Crashed!", TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);

        int key;

        while (true)
            GetKey(&key);
    }
};