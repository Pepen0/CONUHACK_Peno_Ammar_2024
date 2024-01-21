#include "Character.h"
#include "Colors.h"

Character::Character(int x, int y, int w, int h)
    : Entity(x, y, w, h), stepSize(2), dx(0), dy(0) {}

void Character::handleInput(const SDL_Event &e)
{
    // Reset movement deltas
    dx = 0;
    dy = 0;

    // Check for keydown events
    if (e.type == SDL_KEYDOWN)
    {
        switch (e.key.keysym.scancode)
        {
        case SDL_SCANCODE_UP:
            dy = -stepSize;
            break;
        case SDL_SCANCODE_DOWN:
            dy = stepSize;
            break;
        case SDL_SCANCODE_LEFT:
            dx = -stepSize;
            break;
        case SDL_SCANCODE_RIGHT:
            dx = stepSize;
            break;
        default:
            break;
        }
    }
}

void Character::move()
{
    rect.x += dx;
    rect.y += dy;
}

void Character::draw(SDL_Renderer *renderer) const
{
    SDL_SetRenderDrawColor(renderer, Colors::Green.r, Colors::Green.g, Colors::Green.b, Colors::Green.a);
    SDL_RenderFillRect(renderer, &rect);
}
