#include "Game.h"
#include "App.h"
#include <iostream>

// Game Constructor
Game::Game() : running(false), app(nullptr) {}

// Game Destructor
Game::~Game()
{
    cleanup();
}

// Initializes the game state
bool Game::init()
{
    app = new App();
    if (!app->InitApplication())
    {
        std::cerr << "Game Initialization Failed" << std::endl;
        return false;
    }
    running = true;
    return true;
}

// Contains the main loop that calls update and render functions
void Game::run()
{
    while (running)
    {
        handleEvents();
        update();
        render();
    }
}

// Updates the game state
void Game::update()
{
    // Update game logic here
}

// Draws the game state to the screen
void Game::render()
{
    if (app)
    {
        app->ClearScreen(app->renderer);
        app->DrawMainChar(app->square.x, app->square.y);
        SDL_RenderPresent(app->renderer);
    }
}

// Processes input events
void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;
            // Handle other events like keyboard, mouse, etc.
        }
    }
}

// Cleans up resources upon game exit
void Game::cleanup()
{
    if (app)
    {
        app->ShutdownApllication();
        delete app;
        app = nullptr;
    }
}
