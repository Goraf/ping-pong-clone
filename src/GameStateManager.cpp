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

void GameStateManager::replace(State * state)
{
    pop();
    push(state);
}

void GameStateManager::resetToFirst()
{
    if (states.size() > 1)
    {
        states.erase(states.begin() + 1, states.end());
    }
}

State* GameStateManager::getCurrentState()
{
    return states.back().get();
}
