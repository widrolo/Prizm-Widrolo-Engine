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
        static const int msgAmmountMax = 4;

        char consoleBuffer[msgAmmountMax][msgLengthMax];

        TextCanvas *text;
        SpriteRenderer *background = (SpriteRenderer*)sys_malloc(sizeof(SpriteRenderer));

        bool isHidden;

        int lowestBuff;

        static constexpr Vector2 consolePos = {x: 0, y: LCD_HEIGHT_PX - 48};
        static constexpr Vector2 consoleSize = {x: 270, y: 48};
        
    public:
        void Init(TextCanvas *pTC)
        {
            isHidden = false;

            lowestBuff = __TEXT_BUFFER_AMMOUNT - msgAmmountMax;
            text = pTC;
        }
        // Message can be only 32 chars at max
        void OutPutMsg(const char* msg)
        {
            
            for (int i = msgAmmountMax - 1; i > 0; i-- )
            {
                strcpy(consoleBuffer[i + 1], consoleBuffer[i]);
            }
            strcpy(consoleBuffer[0], msg);
            strcpy(consoleBuffer[4], "WTF?");
        }

        void DrawText()
        {
            int textPosY;
            for (int i = 0; i < msgAmmountMax; i++)
            {
                textPosY = LCD_HEIGHT_PX - i * 8 - 8;
                text->AddTxtBuff(consoleBuffer[i], i + lowestBuff, 8, textPosY);
            }
            
            if (!isHidden)
            {
                background->RenderSquare(consolePos, consoleSize, COLOR_WHITE);
                
            }
        }
    };
}
