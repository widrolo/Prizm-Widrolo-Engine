#include <string.h>
#include <fxcg/display.h>
#include <fxcg/keyboard.h>
#include <fxcg/misc.h>
#include <fxcg/heap.h>
#include "./game.h"

#pragma once

namespace WEngine
{
    class CrashHandler
    {
    private:
        char* msg;
        bool containsMsg = false;
        Game *pGame;
    public:
        // This crash will finish the execution of the frame
        // and allows the data to be saved
        void Crash()
        {   
            pGame->isRunning = false;
        }
        // This crash will finish the execution of the frame
        // and allows the data to be saved
        void Crash(const char* msg)
        {   
            this->msg = (char*)sys_malloc(sizeof(char) * 24);
            pGame->isRunning = false;
            for (unsigned int i = 0; i < 24; i++)
            {
                this->msg[i] = msg[i];
            }
            containsMsg = true;
        }
        // This crash will hang up the game on the spot
        // and will not allow to save the data
        static void PanicCrash(const char* msg)
        {   
            Bdisp_AllClr_VRAM();
            PrintXY(3,  2, "  Panic Crash!", TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);
            PrintXY(3,  3, "  No Data Saved!", TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);
            PrintXY(3, 5, msg, TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);
            Bdisp_PutDisp_DD();
            int dummy;
            while (true)
                GetKey(&dummy);
        }
    public:
        void Init(Game *pGame)
        {
            this->pGame = pGame;
        }
        void EndProgram()
        {
            MsgBoxPush(6); 
            PrintXY(3,  2, "  Game Crashed!", TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);
            PrintXY(3,  3, "  Data Save Attempted", TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);
            if (containsMsg)
                PrintXY(3, 5, msg, TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);
            else
                PrintXY(3, 5, "  Unknown cause", TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);

            int key;

            while (true)
                GetKey(&key);
        }
    };
}