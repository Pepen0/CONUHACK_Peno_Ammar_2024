#ifndef GAME_STATE_MANAGER_H
#define GAME_STATE_MANAGER_H

#include <vector>
#include "GameState.h"

class GameStateManager
{
public:
    void changeState(GameState *state);
    void pushState(GameState *state);
    void popState();
    void handleEvents();
    void update();
    void render();

private:
    std::vector<GameState *> states;
};

#endif // GAME_STATE_MANAGER_H
