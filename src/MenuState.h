#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "State.h"


class MenuState : public State
{
public:
    MenuState(GameStateManager* manager, sf::RenderWindow& window);

    virtual void handleEvents(const sf::Event& event);
    virtual void update(const float& deltaTime);
    virtual void render();

    void updateOptionText();

private:
    enum OptionNames
    {
        Play,
        Instructions,
        Exit
    };

    sf::Font font;
    sf::Text title;
    std::vector<sf::Text> options;
    std::size_t optionIndex;
};
