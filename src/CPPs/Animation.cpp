#include "Animation.h"
#include <SDL2/SDL_image.h>

Animation::Animation(SDL_Texture *texture, int frameCount, float frameDuration)
    : texture(texture), frameCount(frameCount), frameDuration(frameDuration),
      currentFrameTime(0.0f), currentFrame(0) {}

void Animation::update(float deltaTime)
{
    currentFrameTime += deltaTime;
    if (currentFrameTime >= frameDuration)
    {
        currentFrame = (currentFrame + 1) % frameCount;
        currentFrameTime = 0.0f;
    }
}

void Animation::draw(SDL_Renderer *renderer, const SDL_Rect &destRect)
{
    SDL_Rect srcRect;
    int textureWidth, textureHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);

    srcRect.x = currentFrame * (textureWidth / frameCount);
    srcRect.y = 0;
    srcRect.w = textureWidth / frameCount;
    srcRect.h = textureHeight;

    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}
