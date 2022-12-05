#include "EngineDefines.h"
#include <fxcg/display.h>
#include "../data/Fontfile.h"

// This may just be the most conplex piece of code written in this engine
class TextCanvas
{
private:

#if __TEXT == 1 // We shouldnt waste memory it isnt used
    char TextCanvasBuffer[__TEXT_BUFFER_AMMOUNT][__TEXT_BUFFER_SIZE];
#endif

public:
    void Init()
    {
#if __TEXT == 1
    return;
#endif
        for (int i = 0; i < __TEXT_BUFFER_AMMOUNT; i++)
        {
            for (int j = 0; j < __TEXT_BUFFER_SIZE; j++)
            {
                TextCanvasBuffer[i][j] = 0;
            }
        }
    }

    void AddTxtBuff(char txt[__TEXT_BUFFER_SIZE], int buffNum, unsigned char x, unsigned char y)
    {
        // The last 2 bytes tell the position
        TextCanvasBuffer[buffNum][__TEXT_BUFFER_SIZE - 1] = x;
        TextCanvasBuffer[buffNum][__TEXT_BUFFER_SIZE - 2] = y;

        for (int i = 0; i < __TEXT_BUFFER_SIZE; i++)
        {
            // check to see if text has ended
            if (txt[i] == 0)
                break;

            TextCanvasBuffer[buffNum][i] = txt[i];
        }
        

    }
    
    void Draw()
    {
        // Go trough all buffers and print them
        for (int i = 0; i < __TEXT_BUFFER_AMMOUNT; i++)
        {
            int xpos = 0;
            bool brk = false;

            for (int j = 0; j < __TEXT_BUFFER_SIZE; j++)
            {
                // take the current char
                char currentChar = TextCanvasBuffer[i][j];

                // get text position
                unsigned char x = TextCanvasBuffer[i][__TEXT_BUFFER_SIZE - 1];
                unsigned char y = TextCanvasBuffer[i][__TEXT_BUFFER_SIZE - 2];

                // select character to draw
                switch (currentChar)
                {
                case 65: // A
                    VRAM_CopySprite(TEXT_LETTER_A, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                
                case 0:
                    brk = true;
                    break;

                default:
                    break;
                }

                if (brk)
                    break;
            }
        }

        
    }
};