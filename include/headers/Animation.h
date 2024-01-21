#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2/SDL.h>

class Animation
{
public:
    Animation(SDL_Texture *texture, int frameCount, float frameDuration);

    void update(float deltaTime);
    void draw(SDL_Renderer *renderer, const SDL_Rect &destRect);

private:
    SDL_Texture *texture;
    int frameCount;
    float frameDuration;
    float currentFrameTime;
    int currentFrame;
};

#endif // ANIMATION_H
