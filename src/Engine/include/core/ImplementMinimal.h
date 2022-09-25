
#include <fxcg/keyboard.h>
#include <fxcg/heap.h>
#include "C:\Users\Filip\Desktop\stuff\PrizmSDK-win-0.5.2\projects\Widrolo-Engine\src\Engine\include\math\vector.h"
#include "./SpriteRenderer.h"

#pragma once

class Actor
{
public:
    // Position in Pixels
    Vector2 position;
public:
    // Scale in Pixels
    Vector2 scale;

    // runtime stuff
    unsigned int ticks = 0;

public:
    void ActorTick(){
        ticks++;
    }
    void ActorDraw(){
        return;
    }
};

class Character : Actor
{
protected:
    int speed;
    int color;
    bool enableStdMove;
    int key;
    color_t *pPlayerSprite = static_cast<color_t*>(sys_malloc(sizeof(color_t) * 64));
    SpriteRenderer *renderer = static_cast<SpriteRenderer*>(sys_malloc(sizeof(SpriteRenderer)));

    void SetPosition(Vector2 pos)
    {
        position = pos;
    }
    void SetScale(Vector2 scl)
    {
        scale = scl;
    }
    Vector2 GetPosition()
    {
        return position;
    }
    Vector2 GetScale()
    {
        return scale;
    }

    void CharacterTick()
    {
        ActorTick();
        if (enableStdMove)
        {
            
            GetKey(&key);

            if (key == KEY_CTRL_LEFT)
                position.x -= 1 * speed;
            else if (key == KEY_CTRL_RIGHT)
                position.x += 1 * speed;
            else if (key == KEY_CTRL_UP)
                position.y -= 1 * speed;
            else if (key == KEY_CTRL_DOWN)
                position.y += 1 * speed;
        }
    }
    /*
    * Render modes:
    * 0 - renders a cube based off the scale and the color
    * 1 - renders a 8x8 sprite
    * 2 - renders a 16x16 sprite
    * 3 - renders a 32x32 sprite
    */
    void CharacterDraw(int renderMode)
    {
        ActorDraw();
        
        switch (renderMode)
        {
        case 0:
            renderer->RenderSquare(position, scale, color);
            break;
        case 1:
            renderer->RenderSprite8x8(position, pPlayerSprite);
            break;
        case 2:
            //renderer.RenderSquare(position, scale, color);
            break;
        case 3:
            //renderer.RenderSquare(position, scale, color);
            break;
        
        default:
            break;
        }
    }
    void CoreReset()
    {
        ticks = 0;
        renderer->Init();
    }
};

class NPC : Actor
{
protected:
    int color;
    color_t *pNPCSprite = static_cast<color_t*>(sys_malloc(sizeof(color_t) * 64));
    SpriteRenderer *renderer = static_cast<SpriteRenderer*>(sys_malloc(sizeof(SpriteRenderer)));

    void SetPosition(Vector2 pos)
    {
        position = pos;
    }
    void SetScale(Vector2 scl)
    {
        scale = scl;
    }
    Vector2 GetPosition()
    {
        return position;
    }
    Vector2 GetScale()
    {
        return scale;
    }

    void NPCTick()
    {
        ActorTick();
    }

    void NPCDraw(int renderMode)
    {
        ActorDraw();
        
        switch (renderMode)
        {
        case 0:
            renderer->RenderSquare(position, scale, color);
            break;
        case 1:
            renderer->RenderSprite8x8(position, pNPCSprite);
            break;
        case 2:
            //renderer.RenderSquare(position, scale, color);
            break;
        case 3:
            //renderer.RenderSquare(position, scale, color);
            break;
        
        default:
            break;
        }
    }

    void CoreReset()
    {
        ticks = 0;
        renderer->Init();
    }
};

class GameModeBase
{
public:
    int skyboxColor;
    void InitGame();
    void ResetPlayerOnly();
    
};