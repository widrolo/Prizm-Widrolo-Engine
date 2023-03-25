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
        void Crash()
        {   
            pGame->isRunning = false;
        }
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
        static void CrashNow(const char* msg)
        {   
            PrintXY(3, 2, msg, TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);
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
            if (containsMsg)
                PrintXY(3, 4, msg, TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);


            int key;

            while (true)
                GetKey(&key);
        }
    };
}