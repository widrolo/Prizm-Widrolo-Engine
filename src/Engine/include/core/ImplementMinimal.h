
#define Minimal_Inlcuded

#include <fxcg/keyboard.h>
#include <fxcg/heap.h>
#include "./../math/vector.h"
#include "./SpriteRenderer.h"
#include "./RuntimeManagers.h"

#pragma once


class Actor
{
public: // Actor Variables
    Vector2 position;
    Vector2 scale;
    unsigned int ticks = 0;

public: // Actor Functions
    void ActorTick(){
        ticks++;
    }
    void ActorDraw(){
        return;
    }
};

class Character : Actor
{
protected: // Character Specific Variables
    int speed;
    int color;
    bool enableStdMove;
    int key;
    color_t *pPlayerSprite = static_cast<color_t*>(sys_malloc(sizeof(color_t) * 64));
    SpriteRenderer *renderer = static_cast<SpriteRenderer*>(sys_malloc(sizeof(SpriteRenderer)));

protected: // Acceessing Actor Variables Using Functions
    void SetPosition(Vector2 pos) { position = pos; }
    void SetScale(Vector2 scl) { scale = scl; }
    Vector2 GetPosition() { return position; }
    Vector2 GetScale() { return scale; }

protected: // Character Specific Functions
    void CharacterTick()
    {
        ActorTick();
        GetKey(&key);
        if (enableStdMove)
        {
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
    }
};

class Pawn : Actor
{
protected: // Pawn Specific Variables
    int color;
    color_t *pPawnSprite = static_cast<color_t*>(sys_malloc(sizeof(color_t) * 64));
    SpriteRenderer *renderer = static_cast<SpriteRenderer*>(sys_malloc(sizeof(SpriteRenderer)));

protected: // Acceessing Actor Variables Using Functions
    void SetPosition(Vector2 pos) { position = pos; }
    void SetScale(Vector2 scl) { scale = scl; }
    Vector2 GetPosition() { return position; }
    Vector2 GetScale() { return scale; }

protected: // Pawn Behavior
    void PawnTick()
    {
        ActorTick();
    }

    void PawnDraw(int renderMode)
    {
        ActorDraw();
        
        switch (renderMode)
        {
        case 0:
            renderer->RenderSquare(position, scale, color);
            break;
        case 1:
            renderer->RenderSprite8x8(position, pPawnSprite);
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
    }
};

