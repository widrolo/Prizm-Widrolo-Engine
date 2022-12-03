
#pragma once
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