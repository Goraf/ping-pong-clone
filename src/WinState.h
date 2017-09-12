#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "State.h"


enum Winner
{
    Player1,
    Player2
};

class WinState : public State
{
public:
    WinState(GameStateManager* manager, sf::RenderWindow& window, Winner winner);

    virtual void handleEvents(const sf::Event& event);
    virtual void update(const float& deltaTime);
    virtual void render();

private:
    sf::Font font;
    std::vector<sf::Text> text;
};
