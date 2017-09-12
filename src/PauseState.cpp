#include "config.h"
#include "GameStateManager.h"
#include "PauseState.h"


PauseState::PauseState(GameStateManager * manager, sf::RenderWindow & window) :
    State(manager, window)
{
    if (!font.loadFromFile("media/Sansation.ttf"))
        window.close();

    sf::Text title("Pause", font, 45U);
    sf::FloatRect bounds = title.getLocalBounds();
    title.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    title.setPosition(windowWidth / 2.f, 100.f);
    text.emplace_back(title);


}

void PauseState::handleEvents(const sf::Event & event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateManager->pop();
}

void PauseState::update(const float & deltaTime)
{
}

void PauseState::render()
{
    for (const sf::Text& t : text)
        window.draw(t);
}
