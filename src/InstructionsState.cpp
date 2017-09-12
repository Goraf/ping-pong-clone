#include "config.h"
#include "InstructionsState.h"


InstructionsState::InstructionsState(GameStateManager* manager, sf::RenderWindow& window) :
    State(manager, window)
{
    if (!font.loadFromFile("media/Sansation.ttf"))
        window.close();

    text.reserve(6);

    sf::Text title("Instructions", font, 45U);
    sf::FloatRect bounds = title.getLocalBounds();
    title.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    title.setPosition(windowWidth / 2.f, 100.f);
    text.emplace_back(title);

    sf::Text rulesHeader("Rules", font);
    bounds = rulesHeader.getLocalBounds();
    rulesHeader.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    rulesHeader.setPosition(windowWidth / 2.f, 150.f);
    text.emplace_back(rulesHeader);

    sf::Text controlsHeader("In-game controls", font);
    bounds = rulesHeader.getLocalBounds();
    rulesHeader.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    controlsHeader.setPosition(windowWidth / 2.f, 350.f);
    text.emplace_back(controlsHeader);

    sf::String s;
    s += "A/Z    - player 1\n";
    s += "K/M   - player 2\n";
    s += "Enter  - launch ball";
    s += "Esc/P  - pause";
    sf::Text controls(s, font, 25U);
    controls.setPosition(windowWidth / 2.f, controlsHeader.getPosition().y + 50.f);
    text.emplace_back(controls);

    sf::Text returnText("Press any key to return", font);
    bounds = returnText.getLocalBounds();
    returnText.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    returnText.setPosition(windowWidth / 2.f, windowHeight - 100.f);
    text.emplace_back(returnText);
}

void InstructionsState::handleEvents(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
        popState();
}

void InstructionsState::update(const float& deltaTime)
{
}

void InstructionsState::render()
{
    for (const sf::Text& t : text)
        window.draw(t);
}
