#include "App.h"
#include <iostream>

App::App() : window(nullptr), renderer(nullptr), screenWidth(1280), screenHeight(720), windowTitle("SDL Application") {}

App::~App()
{
    Shutdown();
}

bool App::Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void App::Shutdown()
{
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    SDL_Quit();
}

void App::ClearScreen()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black color
    SDL_RenderClear(renderer);
}

void App::Render()
{
    // Here you can add code to render specific objects, if needed
    SDL_RenderPresent(renderer);
}

SDL_Renderer *App::GetRenderer() const
{
    return renderer;
}

SDL_Window *App::GetWindow() const
{
    return window;
}
