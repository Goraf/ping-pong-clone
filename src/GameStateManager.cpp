#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
    states.reserve(4);
}

void GameStateManager::push(State* state)
{
    states.emplace_back(state);
    states.back()->onEnter();
}

void GameStateManager::pop()
{
    if (!states.empty())
    {
        states.back()->onExit();
        states.pop_back();
    }
}

State* GameStateManager::getCurrentState()
{
    return states.back().get();
}
