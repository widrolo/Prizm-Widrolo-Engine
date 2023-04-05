#pragma once

#include "./EngineDefines.h"
#include "./SpriteRenderer.h"
#include "./Text.h"
#include "../math/vector.h"
#include <string.h>

namespace WEngine
{
    class DebugConsole
    {
    private:
        static const int msgLengthMax = 32;
        static const int msgAmmountMax = 6;
        char consoleBuffer[msgAmmountMax][msgLengthMax];
        TextCanvas *text = (TextCanvas*)sys_malloc(sizeof(TextCanvas));
        SpriteRenderer *background = (SpriteRenderer*)sys_malloc(sizeof(SpriteRenderer));

        bool isHidden;

        static constexpr Vector2 consolePos = {x: 0, y: LCD_HEIGHT_PX - 48};
        static constexpr Vector2 consoleSize = {x: 270, y: 48};
        
    public:
        void Init()
        {
            for (int i = 0; i < msgAmmountMax; i++)
            {
                for (int j = 0; j < msgLengthMax; j++)
                {
                    consoleBuffer[i][j] = 0x00;
                }
            }
            isHidden = false;
        }
        // Message can be only 32 chars at max
        void OutPutMsg(const char* msg)
        {
            for (int i = msgAmmountMax - 2; i < 0; i--)
            {
                for (int j = 0; j < msgLengthMax; j++)
                {
                    strcpy(consoleBuffer[i + 1], consoleBuffer[i]);
                }  
            }

            for (int i = 0; i < msgLengthMax; i++)
            {
                strcpy(consoleBuffer[0], msg);
            }  
        }

        void DrawText()
        {
            int textPosY;
            for (int i = 0; i < msgAmmountMax; i++)
            {
                textPosY = (LCD_HEIGHT_PX - 48) - (i * 8);
                text->AddTxtBuff(consoleBuffer[i], i, 8, textPosY);
            }
            
            if (!isHidden)
            {
                background->RenderSquare(consolePos, consoleSize, COLOR_WHITE);
                text->Draw();
            }
        }
    };
}
