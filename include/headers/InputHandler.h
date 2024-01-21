#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SDL2/SDL.h>
#include <map>

class InputHandler
{
public:
    void update();
    bool isKeyPressed(SDL_Scancode key);

private:
    std::map<SDL_Scancode, bool> keyMap;
};

#endif // INPUT_HANDLER_H
