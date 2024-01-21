#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>
#include <map>
#include <SDL2/SDL.h>

class ResourceManager
{
public:
    static SDL_Texture *loadTexture(const std::string &fileName, SDL_Renderer *renderer);
    // Other resource management methods (for audio, fonts, etc.)

private:
    static std::map<std::string, SDL_Texture *> textures;
};

#endif // RESOURCE_MANAGER_H
