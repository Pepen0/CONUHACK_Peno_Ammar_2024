#ifndef TILE_H
#define TILE_H

#include <SDL2/SDL.h>

class Tile
{
public:
    Tile(int x, int y, int tileSize, SDL_Texture *tileTexture);

    void draw(SDL_Renderer *renderer);

private:
    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_Texture *texture;
};

#endif // TILE_H
