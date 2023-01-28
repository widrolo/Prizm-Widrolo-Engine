#pragma once

#include <fxcg/system.h>
#include <fxcg/keyboard.h>

class InputManager
{
private:
    unsigned char key;
public:
    void Tick()
    {
        PRGM_GetKey_OS(&key);

        if (key == KEY_PRGM_MENU)
        {
            Restart();
        }
    }
};


