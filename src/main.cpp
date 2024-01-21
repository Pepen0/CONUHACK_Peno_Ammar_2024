#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
using namespace std;
#define SDL_MAIN_HANDLED

// Graphics
namespace Graphics
{
    struct Screen
    {
        const int WIDTH = 1280;
        const int HEIGHT = 720;
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
    int x;
    int y;
    SDL_Texture *image;
    SquareState state;
    int step;
};

struct Bullet
{
    int x, y;
    SDL_Texture *image;
    int velocityX, velocityY;
};

struct Zombie
{
    int x, y;
    SDL_Texture *image;
};

std::vector<Bullet> bullets;
std::vector<Zombie> zombies;

// Application
struct App
{
    const int DefaultStep = 2;
    SDL_Window *window;
    SDL_Renderer *renderer;
    Graphics::Screen screen;
    Square square;
    SDL_Texture *zombieTexture;
} app;

// Function to load texture
SDL_Texture *LoadTexture(const string &filePath, SDL_Renderer *renderer)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer, filePath.c_str());
    if (texture == nullptr)
    {
        cout << "Failed to load texture. Error: " << IMG_GetError() << endl;
    }
    return texture;
}

// Function to create a bullet
void ShootBullet(int velocityX, int velocityY)
{
    Bullet newBullet;
    newBullet.x = app.square.x;
    newBullet.y = app.square.y;
    newBullet.velocityX = velocityX;
    newBullet.velocityY = velocityY;
    newBullet.image = LoadTexture("res/image/bullet.png", app.renderer);
    bullets.push_back(newBullet);
}

// Remove bullet if it goes off screen
void UpdateBullets()
{
    for (auto &bullet : bullets)
    {
        bullet.x += bullet.velocityX;
        bullet.y += bullet.velocityY;
    }
}

// Function to draw bullets
void DrawBullets(SDL_Renderer *renderer)
{
    for (const auto &bullet : bullets)
    {
        SDL_Rect bulletRect = {bullet.x, bullet.y, 10, 10}; // Adjust size as needed
        SDL_RenderCopy(renderer, bullet.image, NULL, &bulletRect);
    }
}

// Function to update zombies
void UpdateZombies()
{
    static int frameCount = 0;
    frameCount++;

    if (frameCount % 2 == 0)
    { // Move every 2 frames
        for (auto &zombie : zombies)
        {
            if (zombie.x < app.square.x)
                zombie.x++;
            if (zombie.x > app.square.x)
                zombie.x--;
            if (zombie.y < app.square.y)
                zombie.y++;
            if (zombie.y > app.square.y)
                zombie.y--;
        }
    }
}

// Function to check bullet-zombie collision
void CheckBulletZombieCollision()
{
    for (auto it = bullets.begin(); it != bullets.end();)
    {
        bool bulletHit = false;
        for (auto zit = zombies.begin(); zit != zombies.end();)
        {
            if (abs(it->x - zit->x) < 10 && abs(it->y - zit->y) < 10)
            {
                zit = zombies.erase(zit);
                bulletHit = true;
                break;
            }
            else
            {
                ++zit;
            }
        }
        if (bulletHit)
        {
            it = bullets.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

// Function to draw zombies
void DrawZombies(SDL_Renderer *renderer)
{
    for (const auto &zombie : zombies)
    {
        SDL_Rect rect = {zombie.x - 30, zombie.y - 30, 60, 60}; // Adjust size as needed
        SDL_RenderCopy(renderer, zombie.image, NULL, &rect);
    }
}

// SDL routine
bool InitSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        cout << "SDL_Init failed with error: " << SDL_GetError() << endl;
        return false;
    }

    if (IMG_Init(IMG_INIT_PNG) < 0)
    {
        cout << "IMG_Init failed with error: " << IMG_GetError() << endl;
        return false;
    }

    return true;
}

// Graphic routine
void ClearScreen(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // Black color
    SDL_RenderClear(renderer);
}

void DrawMainChar(SDL_Renderer *renderer, Square &square)
{
    int width, height;
    SDL_QueryTexture(square.image, NULL, NULL, &width, &height);

    SDL_Rect rect;
    rect.x = square.x - (width / 2);
    rect.y = square.y - (height / 2);
    rect.w = width;
    rect.h = height;

    SDL_RenderCopy(renderer, square.image, NULL, &rect);
}

// Application routine
void ShutdownApplication()
{
    if (app.square.image != nullptr)
    {
        SDL_DestroyTexture(app.square.image);
        app.square.image = nullptr;
    }

    if (app.zombieTexture != nullptr)
    {
        SDL_DestroyTexture(app.zombieTexture);
        app.zombieTexture = nullptr;
    }

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

    IMG_Quit();
    SDL_Quit();
}

bool InitApplication()
{
    if (!InitSDL())
    {
        ShutdownApplication();
        return false;
    }

    app.window = SDL_CreateWindow(
        "SDL Image Example",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        app.screen.WIDTH,
        app.screen.HEIGHT,
        SDL_WINDOW_SHOWN);

    if (app.window == nullptr)
    {
        cout << "Failed to create window. Error: " << SDL_GetError() << endl;
        ShutdownApplication();
        return false;
    }

    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
    if (app.renderer == nullptr)
    {
        cout << "Failed to create renderer. Error: " << SDL_GetError() << endl;
        ShutdownApplication();
        return false;
    }

    // Load images
    app.square.image = LoadTexture("res/image/base.png", app.renderer);
    app.zombieTexture = LoadTexture("res/image/zombie.webp", app.renderer);
    if (app.square.image == nullptr || app.zombieTexture == nullptr)
    {
        ShutdownApplication();
        return false;
    }

    // Initialize square
    app.square.x = app.screen.center_X;
    app.square.y = app.screen.center_Y;
    app.square.state = IDLE;
    app.square.step = app.DefaultStep;

    // Initialize zombies
    for (int i = 0; i < 5; ++i)
    {
        Zombie newZombie;
        newZombie.x = rand() % app.screen.WIDTH;
        newZombie.y = rand() % app.screen.HEIGHT;
        newZombie.image = app.zombieTexture;
        zombies.push_back(newZombie);
    }

    return true;
}

void SetState(SquareState new_state)
{
    app.square.state = new_state;
}

// main code
int main(int argc, char *argv[])
{
    if (!InitApplication())
    {
        return EXIT_FAILURE;
    }

    // Initialize zombies
    for (int i = 0; i < 5; ++i)
    {
        Zombie newZombie;
        newZombie.x = rand() % app.screen.WIDTH;
        newZombie.y = rand() % app.screen.HEIGHT;
        newZombie.image = app.zombieTexture;
        zombies.push_back(newZombie);
    }

    SDL_Event event;
    bool running = true;

    while (running)
    {
        ClearScreen(app.renderer);

        // Character state
        switch (app.square.state)
        {
        case MOVE_UP:
            app.square.y -= app.square.step;
            break;
        case MOVE_DOWN:
            app.square.y += app.square.step;
            break;
        case MOVE_LEFT:
            app.square.x -= app.square.step;
            break;
        case MOVE_RIGHT:
            app.square.x += app.square.step;
            break;
        default:
            break;
        }

        // Update and draw bullets
        UpdateBullets();
        DrawBullets(app.renderer);

        // Update and draw zombies
        UpdateZombies();
        DrawZombies(app.renderer);

        // Check collisions
        CheckBulletZombieCollision();

        // I/O processing
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                running = event.key.keysym.scancode != SDL_SCANCODE_ESCAPE;
                if (event.key.keysym.scancode == SDL_SCANCODE_UP)
                {
                    SetState(MOVE_UP);
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
                {
                    SetState(MOVE_DOWN);
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
                {
                    SetState(MOVE_LEFT);
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
                {
                    SetState(MOVE_RIGHT);
                }

                // Shooting keys
                if (event.key.keysym.sym == SDLK_a) // Left
                {
                    ShootBullet(-10, 0);
                }
                else if (event.key.keysym.sym == SDLK_w) // Up
                {
                    ShootBullet(0, -10);
                }
                else if (event.key.keysym.sym == SDLK_d) // Right
                {
                    ShootBullet(10, 0);
                }
                else if (event.key.keysym.sym == SDLK_s) // Down
                {
                    ShootBullet(0, 10);
                }

                break;
            case SDL_KEYUP:
                if (event.key.keysym.scancode == SDL_SCANCODE_UP ||
                    event.key.keysym.scancode == SDL_SCANCODE_DOWN ||
                    event.key.keysym.scancode == SDL_SCANCODE_LEFT ||
                    event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
                {
                    SetState(IDLE);
                }
                break;
            case SDL_QUIT:
                running = false;
                break;
            }
        }

        DrawMainChar(app.renderer, app.square);
        SDL_RenderPresent(app.renderer);
    }

    ShutdownApplication();
    return EXIT_SUCCESS;
}
