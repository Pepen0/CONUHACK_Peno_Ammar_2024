#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL2/SDL.h>
#include <string>

class TextureManager
{
public:
    static SDL_Texture *loadTexture(const std::string &fileName, SDL_Renderer *renderer);
    static void draw(SDL_Texture *texture, SDL_Rect sourceRect, SDL_Rect destinationRect, SDL_Renderer *renderer);
};

#endif // TEXTURE_MANAGER_H
