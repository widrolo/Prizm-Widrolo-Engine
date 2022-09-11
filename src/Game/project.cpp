#include "../Engine/include/core/game.h"
#include "./Player.h"
#include "./Player.cpp"

Player player;
void Game::Awake()
{
    
}
void Game::Start()
{
    player.Start();
}
void Game::Tick()
{
    player.Tick();
}
void Game::Draw()
{
    player.Draw();
}
void Game::End()
{

}