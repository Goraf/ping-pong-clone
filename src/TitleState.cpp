#include "config.h"
#include "MenuState.h"
#include "TitleState.h"


TitleState::TitleState(GameStateManager* manager, sf::RenderWindow& window) :
    State(manager, window)
{
    if (!font.loadFromFile("media/Sansation.ttf"))
        window.close();

    text.reserve(2);

    sf::Text title("PingPong Clone", font, 55U);
    sf::FloatRect bounds = title.getLocalBounds();
    title.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    title.setPosition(windowWidth / 2.f, windowHeight / 2.f);
    text.emplace_back(title);

    sf::Text enter("Press Enter", font);
    bounds = enter.getLocalBounds();
    enter.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    enter.setPosition(windowWidth / 2.f, windowHeight - 100.f);
    text.emplace_back(enter);
}

void TitleState::handleEvents(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
        replaceState(new MenuState(stateManager, window));
}

void TitleState::update(const float& deltaTime)
{
}

void TitleState::render()
{
    for (const sf::Text& t : text)
        window.draw(t);
}
