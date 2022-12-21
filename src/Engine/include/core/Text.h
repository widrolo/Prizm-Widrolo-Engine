#include "EngineDefines.h"
#include <fxcg/display.h>
#include "../data/Fontfile.h"
#include "stdlib.h"

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
                TextCanvasBuffer[i][j] = 0x0;
            }
        }
    }

    void AddTxtBuff(const char txt[__TEXT_BUFFER_SIZE], int buffNum, unsigned char x, unsigned char y)
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
    void AddIntBuff(short num, int buffNum, unsigned char x, unsigned char y)
    {
        // The last 2 bytes tell the position
        TextCanvasBuffer[buffNum][__TEXT_BUFFER_SIZE - 1] = x;
        TextCanvasBuffer[buffNum][__TEXT_BUFFER_SIZE - 2] = y;

        char *txt = (char*)IntToChar(num);

        for (int i = 0; i < __TEXT_BUFFER_SIZE; i++)
        {
            // check to see if text has ended
            if (txt[i] == 0)
                break;

            TextCanvasBuffer[buffNum][i] = txt[i];
        }
    }
    void ClearBuff(int buffNum)
    {
        for (int j = 0; j < __TEXT_BUFFER_SIZE; j++)
        {
            TextCanvasBuffer[buffNum][j] = 0x0;
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
                /*
                    This is the uppercase text printer
                */
                case 'A':
                    VRAM_CopySprite(F_LETTER_A, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'B':
                    VRAM_CopySprite(F_LETTER_B, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'C':
                    VRAM_CopySprite(F_LETTER_C, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'D':
                    VRAM_CopySprite(F_LETTER_D, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'E':
                    VRAM_CopySprite(F_LETTER_E, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'F':
                    VRAM_CopySprite(F_LETTER_F, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'G':
                    VRAM_CopySprite(F_LETTER_G, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'H':
                    VRAM_CopySprite(F_LETTER_H, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'I':
                    VRAM_CopySprite(F_LETTER_I, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'J':
                    VRAM_CopySprite(F_LETTER_J, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'K':
                    VRAM_CopySprite(F_LETTER_K, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'L':
                    VRAM_CopySprite(F_LETTER_L, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'M':
                    VRAM_CopySprite(F_LETTER_M, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'N':
                    VRAM_CopySprite(F_LETTER_N, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'O':
                    VRAM_CopySprite(F_LETTER_O, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'P':
                    VRAM_CopySprite(F_LETTER_P, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'Q':
                    VRAM_CopySprite(F_LETTER_Q, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'R':
                    VRAM_CopySprite(F_LETTER_R, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'S':
                    VRAM_CopySprite(F_LETTER_S, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'T':
                    VRAM_CopySprite(F_LETTER_T, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'U':
                    VRAM_CopySprite(F_LETTER_U, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'V':
                    VRAM_CopySprite(F_LETTER_V, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'W':
                    VRAM_CopySprite(F_LETTER_W, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'X':
                    VRAM_CopySprite(F_LETTER_X, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'Y':
                    VRAM_CopySprite(F_LETTER_Y, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case 'Z':
                    VRAM_CopySprite(F_LETTER_Z, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                /*
                    This is the symbol printer
                */
                case ' ':
                    VRAM_CopySprite(F_SYMBOL_SPACE, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '&':
                    VRAM_CopySprite(F_SYMBOL_AMPERSAND, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '\\':
                    VRAM_CopySprite(F_SYMBOL_BACK_SLASH, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case ':':
                    VRAM_CopySprite(F_SYMBOL_COLON, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case ',':
                    VRAM_CopySprite(F_SYMBOL_COMMA, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '$':
                    VRAM_CopySprite(F_SYMBOL_DOLLAR, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '\"':
                    VRAM_CopySprite(F_SYMBOL_DOUBLE_QUOTE, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '=':
                    VRAM_CopySprite(F_SYMBOL_EQUALS, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '!':
                    VRAM_CopySprite(F_SYMBOL_EXCLAMATION, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '.':
                    VRAM_CopySprite(F_SYMBOL_FULL_STOP, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '>':
                    VRAM_CopySprite(F_SYMBOL_GREATER_THAN, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '(':
                    VRAM_CopySprite(F_SYMBOL_LEFT_BRACKET, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '{':
                    VRAM_CopySprite(F_SYMBOL_LEFT_CURLY_BRACKET, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '[':
                    VRAM_CopySprite(F_SYMBOL_LEFT_SQUARE_BRACKET, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '<':
                    VRAM_CopySprite(F_SYMBOL_LESS_THAN, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '-':
                    VRAM_CopySprite(F_SYMBOL_MINUS, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '*':
                    VRAM_CopySprite(F_SYMBOL_MULTIPLY, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '%':
                    VRAM_CopySprite(F_SYMBOL_PERCENT, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '+':
                    VRAM_CopySprite(F_SYMBOL_PLUS, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '#':
                    VRAM_CopySprite(F_SYMBOL_POUND, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '?':
                    VRAM_CopySprite(F_SYMBOL_QUESTION, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '\'':
                    VRAM_CopySprite(F_SYMBOL_QUOTE, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case ')':
                    VRAM_CopySprite(F_SYMBOL_RIGHT_BRACKET, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '}':
                    VRAM_CopySprite(F_SYMBOL_RIGHT_CURLY_BRACKET, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case ']':
                    VRAM_CopySprite(F_SYMBOL_RIGHT_SQUARE_BRACKET, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case ';':
                    VRAM_CopySprite(F_SYMBOL_SEMICOLON, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '/':
                    VRAM_CopySprite(F_SYMBOL_SLASH, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '~':
                    VRAM_CopySprite(F_SYMBOL_TILDE, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '_':
                    VRAM_CopySprite(F_SYMBOL_UNDERSCORE, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '|':
                    VRAM_CopySprite(F_SYMBOL_VERTICAL_SLASH, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                /*
                    Standart number printer 
                */
                case '0':
                    VRAM_CopySprite(F_NUMBER_ZERO, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '1':
                    VRAM_CopySprite(F_NUMBER_ONE, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '2':
                    VRAM_CopySprite(F_NUMBER_TWO, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '3':
                    VRAM_CopySprite(F_NUMBER_THREE, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '4':
                    VRAM_CopySprite(F_NUMBER_FOUR, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '5':
                    VRAM_CopySprite(F_NUMBER_FIVE, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '6':
                    VRAM_CopySprite(F_NUMBER_SIX, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '7':
                    VRAM_CopySprite(F_NUMBER_SEVEN, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '8':
                    VRAM_CopySprite(F_NUMBER_EIGTH, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                case '9':
                    VRAM_CopySprite(F_NUMBER_NINE, x + xpos, y, 8, 8);
                    xpos += 8;
                    break;
                /*
                    Invisible chars printer 
                */
                case 0: // Null byte
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
private:
    const char* IntToChar(short N)
    {
        // Prevent a bug from happening
        // TODO: fix the bug so i can remove this
        if (N & 0b1000000000000000)
        {
            const char *err = "INF";
            return err;
        }
        char* arr;
        char arr1[12];
        arr = (char*)malloc(sizeof(char) * 12);

        // ASCII Magic
        int index = 0;
        while (N) {
            arr1[++index] = N % 10 + '0';
            N /= 10;
        }
    
        int i;
        for (i = 0; i < index; i++) {
            arr[i] = arr1[index - i];
        }
        arr[i] = '\0';

        return (char*)arr;
    }
};