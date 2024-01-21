#include "Animation.h"

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
    srcRect.x = currentFrame * (texture->w / frameCount);
    srcRect.y = 0;
    srcRect.w = texture->w / frameCount;
    srcRect.h = texture->h;

    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}
