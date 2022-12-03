
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
    color_t *pPlayerSprite = static_cast<color_t*>(sys_malloc(sizeof(color_t) * 64));
    SpriteRenderer *renderer = static_cast<SpriteRenderer*>(sys_malloc(sizeof(SpriteRenderer)));

private: // Collision Components
    bool enableStdCollisionMove;
    CollisionManger *pCollisionManager;
    CollisionBox *pCollisionBox;
    CollisionResult *pCollisionResult;

protected: // Collision functions
    void SetCollisionInfo(CollisionManger *pCollisionManager, CollisionBox *pCollisionBox, CollisionResult *pCollisionResult)
    {
        this->pCollisionManager = pCollisionManager;
        this->pCollisionBox = pCollisionBox;
        this->pCollisionResult = pCollisionResult;
    }

    void EnableCollisionMove()
    {
        if (enableStdMove)
            return;
        
        if (pCollisionManager == nullptr || pCollisionBox == nullptr || pCollisionResult == nullptr)
            return;

        enableStdCollisionMove = true;
    }

protected: // Acceessing Actor Variables Using Functions
    void SetPosition(Vector2 position) { this->position = position; }
    void SetScale(Vector2 size) { this->size = size; }
    Vector2 GetPosition() { return position; }
    Vector2 GetScale() { return size; }

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

        if (enableStdCollisionMove)
        {
            if (key == KEY_CTRL_LEFT)
            {   
                position.x -= 1 * speed;
                pCollisionBox->SetBoxInfo(position, size);
                pCollisionManager->CheckForCollision(pCollisionBox->GetID(), pCollisionResult);
                if (pCollisionResult->collided)
                {
                    position.x += 1 * speed;
                }
            }
            else if (key == KEY_CTRL_RIGHT)
            {
                position.x += 1 * speed;
                pCollisionBox->SetBoxInfo(position, size);
                pCollisionManager->CheckForCollision(pCollisionBox->GetID(), pCollisionResult);
                if (pCollisionResult->collided)
                {
                    position.x -= 1 * speed;
                }
            }
            else if (key == KEY_CTRL_UP)
            {
                position.y -= 1 * speed;
                pCollisionBox->SetBoxInfo(position, size);
                pCollisionManager->CheckForCollision(pCollisionBox->GetID(), pCollisionResult);
                if (pCollisionResult->collided)
                {
                    position.y += 1 * speed;
                }
            }
            else if (key == KEY_CTRL_DOWN)
            {
                position.y += 1 * speed;
                pCollisionBox->SetBoxInfo(position, size);
                pCollisionManager->CheckForCollision(pCollisionBox->GetID(), pCollisionResult);
                if (pCollisionResult->collided)
                {
                    position.y -= 1 * speed;
                }
            }
            pCollisionBox->SetBoxInfo(position, size);
        }
    }

    void CharacterDraw(int renderMode)
    {
        ActorDraw();
        
        switch (renderMode)
        {
        case 0:
            renderer->RenderSquare(position, size, color);
            break;
        case 1:
#if __BLEEDING_EDGE == 1
            renderer->RenderSprite8x8(position, pPlayerSprite);
#endif
            break;
        case 2:
            //renderer.RenderSquare(position, size, color);
            break;
        case 3:
            //renderer.RenderSquare(position, size, color);
            break;
        
        default:
            break;
        }
    }
    void CoreReset()
    {
        pCollisionBox = nullptr;
        pCollisionManager = nullptr;
        pCollisionResult = nullptr;

        enableStdCollisionMove = false;

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
    void SetScale(Vector2 scl) { size = scl; }
    Vector2 GetPosition() { return position; }
    Vector2 GetScale() { return size; }

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
            renderer->RenderSquare(position, size, color);
            break;
        case 1:
#if __BLEEDING_EDGE == 1
            renderer->RenderSprite8x8(position, pPawnSprite);
#endif
            break;
        case 2:
            //renderer.RenderSquare(position, size, color);
            break;
        case 3:
            //renderer.RenderSquare(position, size, color);
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

