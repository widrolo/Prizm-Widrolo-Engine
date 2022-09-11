
#include <fxcg/keyboard.h>
#include "C:\Users\Filip\Desktop\PrizmSDK-win-0.5.2\projects\Widrolo-Engine\src\Engine\include\math\vector.h"
#include "./SpriteRenderer.h"

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
public:

private:
    SpriteRenderer renderer = SpriteRenderer();

protected:
    int speed;
    int color;
    bool enableStdMove;

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
            int key;
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
    void CharacterDraw()
    {
        ActorDraw();
        
        renderer.RenderSquare(position, scale, color);
    }
    void CoreReset()
    {
        ticks = 0;
    }
};

class GameModeBase
{
public:
    int skyboxColor;
    void InitGame();
    void ResetPlayerOnly();
    
};