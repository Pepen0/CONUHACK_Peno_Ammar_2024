#include <iostream>
#include "HPPs/Game.h"

int main(int argc, char *argv[])
{
    Game game;

    // Initialize the game
    if (!game.init())
    {
        std::cerr << "Failed to initialize game" << std::endl;
        return -1;
    }

    // Run the game loop
    game.run();

    // Cleanup resources upon game exit
    game.cleanup();

    return 0;
}
