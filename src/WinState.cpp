#include "config.h"
#include "GameStateManager.h"
#include "WinState.h"


WinState::WinState(GameStateManager * manager, sf::RenderWindow & window, Winner winner) :
    State(manager, window)
{
    if (!font.loadFromFile("media/Sansation.ttf"))
        window.close();

    sf::String s;
    if (winner == Player1)
    {
        s += "Player one ";
    }
    else
    {
        s += "Player two ";
    }
    s += "wins";

    sf::Text winnerText(s, font, 45U);
    sf::FloatRect bounds = winnerText.getLocalBounds();
    winnerText.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    winnerText.setPosition(windowWidth / 2.f, 100.f);
    text.emplace_back(winnerText);

}

void WinState::handleEvents(const sf::Event & event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateManager->pop();
}

void WinState::update(const float & deltaTime)
{
}

void WinState::render()
{
    for (const sf::Text& t : text)
        window.draw(t);
}
