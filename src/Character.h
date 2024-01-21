#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"

// Represents the player character
class Character : public Entity
{
public:
    Character(int x, int y, int w, int h);

    void handleInput(const SDL_Event &e);
    void move() override;
    void draw(SDL_Renderer *renderer) const override;

private:
    int stepSize;
    int dx, dy; // Delta x and y for movement
};

#endif // CHARACTER_H
