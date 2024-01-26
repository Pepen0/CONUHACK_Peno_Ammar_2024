#include "Tile.h"

Tile::Tile(int x, int y, int tileSize, SDL_Texture *tileTexture)
    : texture(tileTexture)
{
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = tileSize;
    srcRect.h = tileSize;

    destRect.x = x;
    destRect.y = y;
    destRect.w = tileSize;
    destRect.h = tileSize;
}

void Tile::draw(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}
