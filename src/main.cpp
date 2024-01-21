#include <iostream>
#include <SDL2/SDL.h>
using namespace std;
#define SDL_MAIN_HANDLED

// Colors
namespace Colors
{
    const SDL_Color Black = {0, 0, 0, SDL_ALPHA_OPAQUE};
    const SDL_Color Green = {0, 255, 0, SDL_ALPHA_OPAQUE};
}

// Graphics
namespace Graphics
{
    struct Screen
    {
        const int WIDTH = 512;
        const int HEIGHT = 284;

        const int center_X = WIDTH / 2;
        const int center_Y = HEIGHT / 2;
    };
};

// Game object
enum SquareState
{
    IDLE,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT
};

struct Square
{
    int HEIGHT;
    int WIDTH;
    int x;
    int y;

    SquareState state;
    int step;
};

// Application
struct App
{
    const int DefaultStep = 2;
    SDL_Window *window;
    SDL_Renderer *renderer;

    Graphics::Screen screen;

    Square square =
        {
            32,
            32,
            screen.center_X,
            screen.center_Y,
            IDLE,
            DefaultStep};

} app;

// SDL routine

bool InitSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        cout << "SDL_Init failed with error: " << SDL_GetError() << endl;
        return false;
    }
    return true;
}

// Graphic routine
void ClearScreen(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, Colors::Black.r, Colors::Black.g, Colors::Black.b, Colors::Black.a);
    SDL_RenderClear(renderer);
}

void DrawMainChar(int x, int y)
{
    SDL_Rect rect;
    rect.x = x - (app.square.WIDTH / 2);
    rect.y = y - (app.square.HEIGHT / 2);
    rect.w = app.square.WIDTH;
    rect.h = app.square.HEIGHT;

    SDL_SetRenderDrawColor(app.renderer, Colors::Green.r, Colors::Green.g, Colors::Green.b, Colors::Green.a);

    SDL_RenderFillRect(app.renderer, &rect);
}

// Application routine

void ShutdownApllication()
{
    if (app.window != nullptr)
    {
        SDL_DestroyWindow(app.window);
        app.window = nullptr;
    }

    if (app.renderer != nullptr)
    {
        SDL_DestroyRenderer(app.renderer);
        app.renderer = nullptr;
    }

    SDL_Quit();
}

bool InitApplication()
{
    if (InitSDL() == false)
    {
        ShutdownApllication();
        return false;
    }

    app.window = SDL_CreateWindow(
        "SDL Create Window (512x284)",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        app.screen.WIDTH,
        app.screen.HEIGHT,
        SDL_WINDOW_SHOWN);

    if (app.window == nullptr)
    {
        cout << "cannot create the window. Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return EXIT_FAILURE;
    }

    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_PRESENTVSYNC);

    return true;
}

void Setstate()
{
}
// main code
int main(int argc, char *argv[])
{

    if (InitApplication() == false)
    {
        ShutdownApllication();
        return EXIT_FAILURE;
    }

    // Draw loop
    SDL_Event event;
    bool running = true;

    while (running)
    {
        ClearScreen(app.renderer);

        // check character state
        switch (app.square.state)
        {
        case MOVE_UP:
        {
            app.square.y = app.square.y - app.square.step;
            break;
        }
        case MOVE_DOWN:
        {
            app.square.y = app.square.y + app.square.step;
            break;
        }
        case MOVE_LEFT:
        {
            app.square.x = app.square.x + app.square.step;
            break;
        }
        case MOVE_RIGHT:
        {
            app.square.x = app.square.x + app.square.step;
            break;
        }
        default:
            break;
        }

        // check and process I/O
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
            {
                running = event.key.keysym.scancode != SDL_SCANCODE_ESCAPE;
                break;
            }
            case SDL_QUIT:
            {
                running = false;
                break;
            }
            default:
            {
                break;
            }
            }
        }

        // Compute char position
        DrawMainChar(app.square.x, app.square.y);

        // Present result
        SDL_RenderPresent(app.renderer);
    }

    ShutdownApllication();

    return EXIT_SUCCESS;
}