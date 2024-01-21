#include "TextureManager.h"

// Loads images into SDL_Textures
SDL_Texture *TextureManager::loadTexture(const std::string &fileName, SDL_Renderer *renderer)
{
    SDL_Surface *tempSurface = SDL_LoadBMP(fileName.c_str());
    if (!tempSurface)
    {
        std::cerr << "Failed to load BMP: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return texture;
}

// Draws textures at specified locations
void TextureManager::draw(SDL_Texture *texture, SDL_Rect sourceRect, SDL_Rect destinationRect, SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer, texture, &sourceRect, &destinationRect);
}
