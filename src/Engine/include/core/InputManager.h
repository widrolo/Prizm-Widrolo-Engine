#pragma once

#include <fxcg/system.h>
#include <fxcg/keyboard.h>

namespace WEngine
{

    class InputManager
    {
    private:
        int key;
    public:
        void Tick()
        {
            unsigned char buffer[12];
            PRGM_GetKey_OS(buffer);

            // magic that i copied
            this->key = ( buffer[1] & 0x0F ) * 10 + ( ( buffer[2] & 0xF0 ) >> 4 );

            // Adds the ability to leave the game
            if (key == KEY_PRGM_MENU)
            {
                MsgBoxPush(6);
                PrintXY(3,  2, "  Game Paused", TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);
                PrintXY(3,  3, "  Menu to leave", TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);
                PrintXY(3,  4, "  Exit to continue", TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);

                int pauseKey;

                while (true)
                {
                    GetKey(&pauseKey);
                    if (pauseKey == KEY_CTRL_EXIT)
                        return;
                }
                
            }
        }

        int GetInput()
        {
            return key;
        }

    };
} 