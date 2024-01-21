#include "ResourceManager.h"

std::map<std::string, SDL_Texture *> ResourceManager::textures;

SDL_Texture *ResourceManager::loadTexture(const std::string &fileName, SDL_Renderer *renderer)
{
    if (textures.find(fileName) == textures.end())
    {
        // Load the texture and add it to the map
        SDL_Texture *texture = IMG_LoadTexture(renderer, fileName.c_str());
        textures[fileName] = texture;
    }
    return textures[fileName];
}

// Implement other resource management methods
