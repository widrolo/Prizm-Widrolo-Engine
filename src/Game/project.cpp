#include "../Engine/include/core/game.h"
#include "./Objects/World.cpp"
#include "./Player.cpp"

Player player;
World world;
void Game::Awake()
{
    
}
void Game::Start()
{  
    world.Reset();
    player.Reset();
}
void Game::Tick()
{
    world.Tick();
    player.Tick();
}
void Game::Draw()
{
    Bdisp_AllClr_VRAM();
    world.Draw();
    player.Draw();
}
void Game::End()
{

}