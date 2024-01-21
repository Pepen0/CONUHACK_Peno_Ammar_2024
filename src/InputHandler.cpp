#include "InputHandler.h"

void InputHandler::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYDOWN)
        {
            keyMap[event.key.keysym.scancode] = true;
        }
        if (event.type == SDL_KEYUP)
        {
            keyMap[event.key.keysym.scancode] = false;
        }
    }
}

bool InputHandler::isKeyPressed(SDL_Scancode key)
{
    if (keyMap.find(key) != keyMap.end())
    {
        return keyMap[key];
    }
    return false;
}
