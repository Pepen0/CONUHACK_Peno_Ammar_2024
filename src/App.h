#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>
#include <string>

class App
{
public:
    App();
    ~App();

    bool Init();
    void Shutdown();
    void ClearScreen();
    void Render();

    SDL_Renderer *GetRenderer() const;
    SDL_Window *GetWindow() const;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    const int screenWidth;
    const int screenHeight;
    std::string windowTitle;
};

#endif // APP_H
