#include "../Engine/include/core/game.h"
#include "./Player.h"
#include "./Player.cpp"

Player player;
void Game::Awake()
{
    
}
void Game::Start()
{
    player.Reset();
}
void Game::Tick()
{
    player.Tick();
}
void Game::Draw()
{
    Bdisp_AllClr_VRAM();
    player.Draw();
}
void Game::End()
{

}