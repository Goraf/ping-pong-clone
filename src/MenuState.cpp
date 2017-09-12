#include "config.h"
#include "InstructionsState.h"
#include "MenuState.h"
#include "PlayState.h"


MenuState::MenuState(GameStateManager * manager, sf::RenderWindow & window) :
    State(manager, window),
    optionIndex(0)
{
    if (!font.loadFromFile("media/Sansation.ttf"))
        window.close();

    sf::Text playOption("Play", font, 45U);
    sf::FloatRect bounds = playOption.getLocalBounds();
    playOption.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    playOption.setPosition(windowWidth / 2.f, windowHeight / 2.f);
    playOption.setOutlineThickness(3.f);
    playOption.setOutlineColor(sf::Color::Blue);
    options.emplace_back(playOption);

    sf::Text instructionsOption("Instructions", font, 45U);
    bounds = instructionsOption.getLocalBounds();
    instructionsOption.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    instructionsOption.setPosition(playOption.getPosition() + sf::Vector2f(0.f, 60.f));
    instructionsOption.setOutlineThickness(3.f);
    options.emplace_back(instructionsOption);

    sf::Text exitOption("Exit", font, 45U);
    bounds = exitOption.getLocalBounds();
    exitOption.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    exitOption.setPosition(instructionsOption.getPosition() + sf::Vector2f(0.f, 60.f));
    exitOption.setOutlineThickness(3.f);
    options.emplace_back(exitOption);
}

void MenuState::handleEvents(const sf::Event & event)
{
    if (event.type != sf::Event::KeyPressed)
        return;

    if (event.key.code == sf::Keyboard::Return)
    {
        switch (optionIndex)
        {
        case Play:
            changeState(new PlayState(stateManager, window));
            break;

        case Instructions:
            changeState(new InstructionsState(stateManager, window));
            break;

        case Exit:
            window.close();

        default:
            break;
        }
    }
    else if (event.key.code == sf::Keyboard::Up)
    {
        if (optionIndex > 0)
            --optionIndex;
        else
            optionIndex = options.size() - 1;

        updateOptionText();
    }
    else if (event.key.code == sf::Keyboard::Down)
    {
        if (optionIndex < options.size() - 1)
            ++optionIndex;
        else
            optionIndex = 0;

        updateOptionText();
    }
}

void MenuState::update(const float & deltaTime)
{
}

void MenuState::render()
{
    for (const sf::Text& text : options)
        window.draw(text);
}

void MenuState::updateOptionText()
{
    if (options.empty())
    {
        return;
    }

    for (sf::Text& text : options)
    {
        text.setOutlineColor(sf::Color::Black);
    }

    options[optionIndex].setOutlineColor(sf::Color::Blue);
}
