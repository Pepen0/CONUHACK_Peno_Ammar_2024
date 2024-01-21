#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

// Forward declaration of any classes used by Game
struct App;

class Game
{
public:
    Game();  // Constructor
    ~Game(); // Destructor

    bool init();         // Initializes the game state
    void run();          // Contains the main loop that calls update and render functions
    void update();       // Updates the game state
    void render();       // Draws the game state to the screen
    void handleEvents(); // Processes input events
    void cleanup();      // Cleans up resources upon game exit

private:
    bool running;
    App *app;
};

#endif // GAME_H
