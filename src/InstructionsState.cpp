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
    title.setPosition(windowWidth / 2.f, 60.f);
    title.setOutlineThickness(1.f);
    title.setOutlineColor(sf::Color::Red);
    text.emplace_back(title);

    sf::Text rulesHeader("Rules", font);
    bounds = rulesHeader.getLocalBounds();
    rulesHeader.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    rulesHeader.setPosition(windowWidth / 2.f, 150.f);
    text.emplace_back(rulesHeader);

    sf::String r;
    r += "Players use the paddles to hit a ball back and forth.\n";
    r += "The aim is for each player to reach three points before the opponent.\n";
    r += "Point is earned when one fails to hit the ball back and it falls \nout of the screen.";
    sf::Text rules(r, font, 22U);
    rules.setPosition(50.f, rulesHeader.getPosition().y + 20.f);
    text.emplace_back(rules);

    sf::Text controlsHeader("In-game controls", font);
    bounds = controlsHeader.getLocalBounds();
    controlsHeader.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    controlsHeader.setPosition(windowWidth / 2.f, 350.f);
    text.emplace_back(controlsHeader);

    sf::String s;
    s += "A/Z    - player 1\n";
    s += "K/M   - player 2\n";
    s += "Enter  - launch ball\n";
    s += "Esc/P  - pause";
    sf::Text controls(s, font, 22U);
    controls.setPosition(50.f, controlsHeader.getPosition().y + 20.f);
    text.emplace_back(controls);

    sf::Text returnText("Press any key to return", font);
    bounds = returnText.getLocalBounds();
    returnText.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    returnText.setPosition(windowWidth / 2.f, windowHeight - 50.f);
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
