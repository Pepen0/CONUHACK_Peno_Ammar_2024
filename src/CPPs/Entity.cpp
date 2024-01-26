#include "Entity.h"

Entity::Entity(int x, int y, int w, int h)
{
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

// No definitions for pure virtual functions, as they will be implemented by derived classes
