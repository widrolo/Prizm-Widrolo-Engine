#pragma once

#include "./../../../Game/GM_GameMode.h"

class Game
{
public:
    bool isRunning;
    Game *game;

    void Awake(Game *pGame);
    void Start();
    void Tick();
    void Draw();
    void End();
};