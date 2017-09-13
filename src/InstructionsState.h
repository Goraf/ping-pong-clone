#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "State.h"


class InstructionsState : public State
{
public:
    InstructionsState(GameStateManager* manager, sf::RenderWindow& window);

    virtual void handleEvents(const sf::Event& event);
    virtual void update(const float& deltaTime);
    virtual void render();

private:
    sf::Font font;
    std::vector<sf::Text> text;
};
