#include "config.h"
#include "InstructionsState.h"
#include "PauseState.h"


PauseState::PauseState(GameStateManager * manager, sf::RenderWindow & window) :
    State(manager, window)
{
    if (!font.loadFromFile("media/Sansation.ttf"))
        window.close();

    sf::Text title("Pause", font, 45U);
    sf::FloatRect bounds = title.getLocalBounds();
    title.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    title.setPosition(windowWidth / 2.f, 60.f);
    title.setOutlineThickness(1.f);
    title.setOutlineColor(sf::Color::Red);
    text.emplace_back(title);

    sf::Text controlInstruction("I - instructions", font, 25U);
    bounds = controlInstruction.getLocalBounds();
    controlInstruction.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    controlInstruction.setPosition(windowWidth / 2.f, 450.f);
    text.emplace_back(controlInstruction);

    sf::Text controlQuit("Q - quit", font, 25U);
    bounds = controlQuit.getLocalBounds();
    controlQuit.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    controlQuit.setPosition(windowWidth / 2.f, controlInstruction.getPosition().y + 35.f);
    text.emplace_back(controlQuit);

    sf::Text returnText("Press Enter or Escape to continue", font);
    bounds = returnText.getLocalBounds();
    returnText.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    returnText.setPosition(windowWidth / 2.f, windowHeight - 50.f);
    text.emplace_back(returnText);
}

void PauseState::handleEvents(const sf::Event & event)
{
    if (event.type != sf::Event::KeyPressed)
    {
        return;
    }

    if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Return)
    {
        popState();
    }

    if (event.key.code == sf::Keyboard::I)
    {
        changeState(new InstructionsState(stateManager, window));
    }

    if (event.key.code == sf::Keyboard::Q)
    {
        resetToFirstState();
    }
}

void PauseState::update(const float & deltaTime)
{
}

void PauseState::render()
{
    for (const sf::Text& t : text)
        window.draw(t);
}
