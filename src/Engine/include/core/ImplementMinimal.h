#include <fxcg/keyboard.h>
#include <fxcg/heap.h>
#include "./../math/vector.h"
#include "./SpriteRenderer.h"
#include "./CrashHandler.h"
#include "./Collision.h"

#pragma once


class Actor
{
public: // Actor Variables
    Vector2 position;
    Vector2 size;
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
    SpriteRenderer *renderer = static_cast<SpriteRenderer*>(sys_malloc(sizeof(SpriteRenderer)));

protected: // Acceessing Actor Variables Using Functions
    void SetPosition(Vector2 position) { this->position = position; }
    void SetScale(Vector2 size) { this->size = size; }
    Vector2 GetPosition() { return position; }
    Vector2 GetScale() { return size; }

protected: // Character Specific Functions
    void CharacterTick(CrashHandler *ch)
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

    void CharacterDraw(bool stdRender)
    {
        ActorDraw();
        
        if (stdRender)
            renderer->RenderSquare(position, size, color);
    }
    void CoreReset()
    {
        ticks = 0;
    }
};


class Pawn : Actor
{
protected:
    int color;
    SpriteRenderer *renderer = static_cast<SpriteRenderer*>(sys_malloc(sizeof(SpriteRenderer)));

protected:
    void SetPosition(Vector2 pos) { position = pos; }
    void SetScale(Vector2 scl) { size = scl; }
    Vector2 GetPosition() { return position; }
    Vector2 GetScale() { return size; }

protected:
    void PawnTick()
    {
        ActorTick();
    }

    void PawnDraw(bool stdRender)
    {
        ActorDraw();
        
        if (stdRender)
            renderer->RenderSquare(position, size, color);
    }

    void CoreReset()
    {
        ticks = 0;
    }
};

