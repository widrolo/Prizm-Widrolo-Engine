#include "../include/core/InputHandler.h"
#include <fxcg/keyboard.h>

int InputHandler::GetPressedKey()
{
    GetKey(&key);
    return key;
}