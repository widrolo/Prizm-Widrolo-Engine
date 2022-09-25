#include <fxcg/display.h>

#pragma once

class GameModeBase
{
private:
    color_t sSkyboxColor;
public:
    void InitGame();
    void ChangeSkyboxColor(color_t newColor)
    {
        sSkyboxColor = newColor;
        DrawFrame(sSkyboxColor);
    }
};