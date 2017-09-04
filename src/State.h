#pragma once
#include <SFML/Window/Event.hpp>

namespace sf
{
    class RenderWindow;
}

class GameStateManager;


class State
{
public:
    State(GameStateManager* manager, sf::RenderWindow& window);
    virtual ~State() { }

    virtual void onEnter() { }
    virtual void onExit() { }

    virtual void handleEvents(const sf::Event& event) = 0;
    virtual void update(const float& deltaTime) = 0;
    virtual void render() = 0;

    void changeState(State* state);

protected:
    GameStateManager* stateManager;
    sf::RenderWindow& window;
};
