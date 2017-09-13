#include "GameStateManager.h"
#include "State.h"


State::State(GameStateManager* manager, sf::RenderWindow& window) :
    stateManager(manager),
    window(window)
{
}

void State::changeState(State* state)
{
    stateManager->push(state);
}

void State::replaceState(State * state)
{
    stateManager->replace(state);
}

void State::resetToFirstState()
{
    stateManager->resetToFirst();
}

void State::popState()
{
    stateManager->pop();
}
