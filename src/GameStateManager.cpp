#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
    states.reserve(3);
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

void GameStateManager::replace(State * state)
{
    pop();
    push(state);
}

State* GameStateManager::getCurrentState()
{
    return states.back().get();
}
