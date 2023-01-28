#pragma once

#include "./../../../Game/GM_GameMode.h"

class Game
{
public:
    bool isRunning;

    void Awake(Game *pGame);
    void Start();
    void Tick();
    void Draw();
    void End();
};