#include "GameStateManager.h"

void GameStateManager::changeState(GameState *state)
{
    if (!states.empty())
    {
        delete states.back();
        states.pop_back();
    }
    states.push_back(state);
}

void GameStateManager::pushState(GameState *state)
{
    states.push_back(state);
}

void GameStateManager::popState()
{
    if (!states.empty())
    {
        delete states.back();
        states.pop_back();
    }
}

void GameStateManager::handleEvents()
{
    if (!states.empty())
    {
        states.back()->handleEvents();
    }
}

void GameStateManager::update()
{
    if (!states.empty())
    {
        states.back()->update();
    }
}

void GameStateManager::render()
{
    if (!states.empty())
    {
        states.back()->render();
    }
}
