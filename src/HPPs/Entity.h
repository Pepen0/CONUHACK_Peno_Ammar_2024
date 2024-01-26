#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>

// Base class for all entities in the game
class Entity
{
public:
    Entity(int x, int y, int w, int h);

    virtual void move() = 0;                             // Pure virtual function for movement
    virtual void draw(SDL_Renderer *renderer) const = 0; // Pure virtual function for drawing

protected:
    SDL_Rect rect;
};

#endif // ENTITY_H
