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
