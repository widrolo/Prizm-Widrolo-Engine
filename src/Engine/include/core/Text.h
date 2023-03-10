#pragma once

#include "EngineDefines.h"
#include <fxcg/display.h>
#include <fxcg/misc.h>
#include "../data/Fontfile.hpp"
#include "./SpriteRenderer.h"
#include "stdlib.h"

namespace WEngine
{
    // This may just be the most conplex piece of code written in this engine
    class TextCanvas
    {
    private:

    #if __TEXT == 1 // We shouldnt waste memory it isnt used
        char TextCanvasBuffer[__TEXT_BUFFER_AMMOUNT][__TEXT_BUFFER_SIZE];
        SpriteRenderer *renderer = static_cast<SpriteRenderer*>(sys_malloc(sizeof(SpriteRenderer)));
    #endif

    public:
        void Init()
        {
            if (__TEXT == 0)
                return;

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
            if (__TEXT == 0)
                return;

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
        void AddIntBuff(int num, int buffNum, unsigned char x, unsigned char y)
        {
            if (__TEXT == 0)
                return;

            // The last 2 bytes tell the position
            TextCanvasBuffer[buffNum][__TEXT_BUFFER_SIZE - 1] = x;
            TextCanvasBuffer[buffNum][__TEXT_BUFFER_SIZE - 2] = y;

            unsigned char txt[24];
            itoa(num, txt);
            //char *txt = (char*)IntToChar(num);
            //if (num == 0)
            //{
            //    txt[0] = '0';
            //}

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
            if (__TEXT == 0)
                return;

            for (int j = 0; j < __TEXT_BUFFER_SIZE; j++)
            {
                TextCanvasBuffer[buffNum][j] = 0x0;
            }
        }

        void Draw()
        {
            if (__TEXT == 0)
                return;

            // Go trough all buffers and print them
            for (int i = 0; i < __TEXT_BUFFER_AMMOUNT; i++)
            {
                int xpos = 0;
                int ypos = 0;
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
                        renderer->RenderSpriteSimple(F_LETTER_A, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'B':
                        renderer->RenderSpriteSimple(F_LETTER_B, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'C':
                        renderer->RenderSpriteSimple(F_LETTER_C, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'D':
                        renderer->RenderSpriteSimple(F_LETTER_D, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'E':
                        renderer->RenderSpriteSimple(F_LETTER_E, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'F':
                        renderer->RenderSpriteSimple(F_LETTER_F, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'G':
                        renderer->RenderSpriteSimple(F_LETTER_G, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'H':
                        renderer->RenderSpriteSimple(F_LETTER_H, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'I':
                        renderer->RenderSpriteSimple(F_LETTER_I, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'J':
                        renderer->RenderSpriteSimple(F_LETTER_J, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'K':
                        renderer->RenderSpriteSimple(F_LETTER_K, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'L':
                        renderer->RenderSpriteSimple(F_LETTER_L, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'M':
                        renderer->RenderSpriteSimple(F_LETTER_M, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'N':
                        renderer->RenderSpriteSimple(F_LETTER_N, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'O':
                        renderer->RenderSpriteSimple(F_LETTER_O, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'P':
                        renderer->RenderSpriteSimple(F_LETTER_P, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'Q':
                        renderer->RenderSpriteSimple(F_LETTER_Q, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'R':
                        renderer->RenderSpriteSimple(F_LETTER_R, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'S':
                        renderer->RenderSpriteSimple(F_LETTER_S, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'T':
                        renderer->RenderSpriteSimple(F_LETTER_T, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'U':
                        renderer->RenderSpriteSimple(F_LETTER_U, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'V':
                        renderer->RenderSpriteSimple(F_LETTER_V, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'W':
                        renderer->RenderSpriteSimple(F_LETTER_W, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'X':
                        renderer->RenderSpriteSimple(F_LETTER_X, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'Y':
                        renderer->RenderSpriteSimple(F_LETTER_Y, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case 'Z':
                        renderer->RenderSpriteSimple(F_LETTER_Z, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    /*
                        This is the symbol printer
                    */
                    case ' ':
                        renderer->RenderSpriteSimple(F_SYMBOL_SPACE, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '&':
                        renderer->RenderSpriteSimple(F_SYMBOL_AMPERSAND, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '\\':
                        renderer->RenderSpriteSimple(F_SYMBOL_BACK_SLASH, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case ':':
                        renderer->RenderSpriteSimple(F_SYMBOL_COLON, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case ',':
                        renderer->RenderSpriteSimple(F_SYMBOL_COMMA, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '$':
                        renderer->RenderSpriteSimple(F_SYMBOL_DOLLAR, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '\"':
                        renderer->RenderSpriteSimple(F_SYMBOL_DOUBLE_QUOTE, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '=':
                        renderer->RenderSpriteSimple(F_SYMBOL_EQUALS, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '!':
                        renderer->RenderSpriteSimple(F_SYMBOL_EXCLAMATION, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '.':
                        renderer->RenderSpriteSimple(F_SYMBOL_FULL_STOP, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '>':
                        renderer->RenderSpriteSimple(F_SYMBOL_GREATER_THAN, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '(':
                        renderer->RenderSpriteSimple(F_SYMBOL_LEFT_BRACKET, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '{':
                        renderer->RenderSpriteSimple(F_SYMBOL_LEFT_CURLY_BRACKET, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '[':
                        renderer->RenderSpriteSimple(F_SYMBOL_LEFT_SQUARE_BRACKET, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '<':
                        renderer->RenderSpriteSimple(F_SYMBOL_LESS_THAN, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '-':
                        renderer->RenderSpriteSimple(F_SYMBOL_MINUS, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '*':
                        renderer->RenderSpriteSimple(F_SYMBOL_MULTIPLY, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '%':
                        renderer->RenderSpriteSimple(F_SYMBOL_PERCENT, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '+':
                        renderer->RenderSpriteSimple(F_SYMBOL_PLUS, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '#':
                        renderer->RenderSpriteSimple(F_SYMBOL_POUND, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '?':
                        renderer->RenderSpriteSimple(F_SYMBOL_QUESTION, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '\'':
                        renderer->RenderSpriteSimple(F_SYMBOL_QUOTE, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case ')':
                        renderer->RenderSpriteSimple(F_SYMBOL_RIGHT_BRACKET, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '}':
                        renderer->RenderSpriteSimple(F_SYMBOL_RIGHT_CURLY_BRACKET, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case ']':
                        renderer->RenderSpriteSimple(F_SYMBOL_RIGHT_SQUARE_BRACKET, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case ';':
                        renderer->RenderSpriteSimple(F_SYMBOL_SEMICOLON, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '/':
                        renderer->RenderSpriteSimple(F_SYMBOL_SLASH, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '~':
                        renderer->RenderSpriteSimple(F_SYMBOL_TILDE, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '_':
                        renderer->RenderSpriteSimple(F_SYMBOL_UNDERSCORE, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '|':
                        renderer->RenderSpriteSimple(F_SYMBOL_VERTICAL_SLASH, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    /*
                        Standart number printer 
                    */
                    case '0':
                        renderer->RenderSpriteSimple(F_NUMBER_ZERO, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '1':
                        renderer->RenderSpriteSimple(F_NUMBER_ONE, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '2':
                        renderer->RenderSpriteSimple(F_NUMBER_TWO, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '3':
                        renderer->RenderSpriteSimple(F_NUMBER_THREE, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '4':
                        renderer->RenderSpriteSimple(F_NUMBER_FOUR, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '5':
                        renderer->RenderSpriteSimple(F_NUMBER_FIVE, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '6':
                        renderer->RenderSpriteSimple(F_NUMBER_SIX, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '7':
                        renderer->RenderSpriteSimple(F_NUMBER_SEVEN, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '8':
                        renderer->RenderSpriteSimple(F_NUMBER_EIGTH, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    case '9':
                        renderer->RenderSpriteSimple(F_NUMBER_NINE, x + xpos, y + ypos, 8, 8);
                        xpos += 8;
                        break;
                    /*
                        Invisible chars printer 
                    */
                    case 0: // Null byte
                        brk = true;
                        break;
                    case '\n':
                        xpos = 0;
                        ypos += 8;
                        break;
                    case '\t':
                        xpos += 32;
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
}