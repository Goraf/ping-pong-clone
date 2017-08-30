#pragma once

namespace sf
{
    class RenderWindow;
}

class State {
public:
    State(sf::RenderWindow& window) : window(window) { }

    virtual void update(const float& deltaTime) = 0;
    virtual void render() = 0;

protected:
    sf::RenderWindow& window;

};

