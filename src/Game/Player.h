#pragma once

#include "./GM_GameMode.h"
#include "../Engine/include/core/ImplementMinimal.h"

class Player : Character
{
private:
    GM_GameMode *gameMode;
    Vector2 pos;
    Vector2 scl;
public:
    void Reset(GM_GameMode *gm);
    void Tick();
    void Draw();
    void End();
};

