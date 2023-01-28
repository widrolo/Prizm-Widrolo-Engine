#pragma once

#include "../GM_GameMode.h"
#include "../../Engine/include/core/ImplementMinimal.h"
class Barrier : Pawn
{
private:
    GM_GameMode *gameMode;
public:
    void Reset(GM_GameMode *gm);
    void Draw();
};

