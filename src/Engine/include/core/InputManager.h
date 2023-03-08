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
        }

        int GetKey()
        {
            return key;
        }

    };
} 