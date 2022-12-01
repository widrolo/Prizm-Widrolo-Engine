#include <string.h>
#include <fxcg/display.h>

#pragma once

class CrashHandler
{
public:
    void Crash()
    {
        DisplayMessageBox((unsigned char*)"Program has crashed!");
    }
};