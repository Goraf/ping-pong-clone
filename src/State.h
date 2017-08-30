#pragma once
#include <SFML/Window/Event.hpp>

namespace sf
{
    class RenderWindow;
}

class State {
public:
    State(sf::RenderWindow& window) : window(window) { }

    virtual void onEnter() { }
    virtual void onExit() { }

    virtual void handleEvents(const sf::Event& event) = 0;
    virtual void update(const float& deltaTime) = 0;
    virtual void render() = 0;

protected:
    sf::RenderWindow& window;

};

