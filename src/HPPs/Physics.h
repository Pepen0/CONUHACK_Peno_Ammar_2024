#ifndef PHYSICS_H
#define PHYSICS_H

#include <SDL2/SDL.h>

class Physics
{
public:
    static bool checkCollision(const SDL_Rect &a, const SDL_Rect &b);
};

#endif // PHYSICS_H
