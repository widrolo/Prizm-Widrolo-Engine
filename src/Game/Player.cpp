#include "./Player.h"
#include "./Data/S_GHOST.h"
#include <fxcg/display.h>

void Player::Reset(GameModeManager *pGMM, CollisionManger *pCM, CrashHandler *pCH, FileReader *pFR, TextCanvas *pTC)
{
    // Setup object
    pGameModeManger = pGMM;
    pCrashHandler = pCH;
    pCollisionManager = pCM;
    pFileReader = pFR;
    pTextCanvas = pTC;

    enableStdMove = true;
    speed = 3;

    // Setup player
    pos.x = 100;
    pos.y = 70;
    SetPosition(pos);

    scl.x = 32;
    scl.y = 32;
    SetScale(scl);

    color = COLOR_RED;

    // Setup File
    file.SetName("\\\\fls0\\File.txt");

    // Setup collision
    collisionBox.MakeBox(pos, scl, 1, pCollisionManager->GenerateNewID());
    pCollisionManager->AddBox(&collisionBox);

    // Complete setup
    CoreReset();
}
void Player::Tick()
{
    CharacterTick(pCrashHandler);
    
    collisionResult.Reset();
    collisionBox.SetBoxInfo(pos, scl);

    // Debugging 

    // Debug Runtime Manipulation
    if (key == KEY_CTRL_EXE)
        pGameModeManger->GetPlayer()->Reset(pGameModeManger, pCollisionManager, pCrashHandler, pFileReader, pTextCanvas);
    if (key == KEY_CHAR_0)
        pGameModeManger->GetGameMode()->ChangeSkyboxColor(COLOR_DARKGREEN);
    if (key == KEY_CHAR_1)
        pCrashHandler->Crash("  Key Interrupt");
    
    // Debug Text
    if (key == KEY_CHAR_5)
    {
        pTextCanvas->ClearBuff(0);
        pTextCanvas->AddTxtBuff("OMG IT WORKS!!", 0, 10, 8);
    }

    // Debug File Handling
    if (key == KEY_CHAR_7)
        pFileReader->CreateFile(&file);
    if (key == KEY_CHAR_8)
        pFileReader->OpenFile(&file);
    if (key == KEY_CHAR_9)
        pFileReader->CloseFile(&file);

}

void Player::Draw()
{
    //CharacterDraw(1);
    Vector2 pos = GetPosition();
    Vector2 scl;
    scl.x = 8;
    scl.y = 8;
    renderer->RenderSprite(pos, scl, S_GHOST_CORNER, false, false);
    pos.y += 8;
    renderer->RenderSprite(pos, scl, S_GHOST_SIDE, false, false);
    pos.y += 8;
    renderer->RenderSprite(pos, scl, S_GHOST_SIDE, false, false);
    pos.y += 8;
    renderer->RenderSprite(pos, scl, S_GHOST_CORNER, true, false);

    pos.y = GetPosition().y;
    pos.x += 8;
    renderer->RenderSprite(pos, scl, S_GHOST_TOP, false, false);
    pos.y += 8;
    renderer->RenderSprite(pos, scl, S_GHOST_EYE, false, false);
    pos.y += 8;
    renderer->RenderSprite(pos, scl, S_GHOST_MOUTH, false, false);
    pos.y += 8;
    renderer->RenderSprite(pos, scl, S_GHOST_LEG, false, false);

    pos.y = GetPosition().y;
    pos.x += 8;
    renderer->RenderSprite(pos, scl, S_GHOST_TOP, false, true);
    pos.y += 8;
    renderer->RenderSprite(pos, scl, S_GHOST_EYE, false, true);
    pos.y += 8;
    renderer->RenderSprite(pos, scl, S_GHOST_MOUTH, false, true);
    pos.y += 8;
    renderer->RenderSprite(pos, scl, S_GHOST_LEG, false, true);

    pos.y = GetPosition().y;
    pos.x += 8;
    renderer->RenderSprite(pos, scl, S_GHOST_CORNER, false, true);
    pos.y += 8;
    renderer->RenderSprite(pos, scl, S_GHOST_SIDE, false, true);
    pos.y += 8;
    renderer->RenderSprite(pos, scl, S_GHOST_SIDE, false, true);
    pos.y += 8;
    renderer->RenderSprite(pos, scl, S_GHOST_CORNER, true, true);

}