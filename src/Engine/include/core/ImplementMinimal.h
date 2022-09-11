
#include <fxcg/keyboard.h>
#include "C:\Users\Filip\Desktop\PrizmSDK-win-0.5.2\projects\Widrolo-Engine\src\Engine\include\math\vector.h"

class Actor
{
public:
    // Position in Pixels
    Vector2 position;
protected:
    // Scale in Pixels
    Vector2 scale;

    int color;

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