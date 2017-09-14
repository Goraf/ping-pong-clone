#include <iostream>
#include "config.h"
#include "Game.h"
#include "TitleState.h"

Game::Game() :
    stateManager()
{
    window.create(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Titlebar | sf::Style::Close);
    stateManager.push(new TitleState(&stateManager, window));
}

void Game::run()
{
    sf::Clock clock;
    const float deltaTime{ 0.01f };

    sf::Time newTime;
    sf::Time frameTime;
    sf::Time currentTime = clock.restart();

    float accumulator{ 0.0f };

    while (window.isOpen())
    {
        newTime = clock.getElapsedTime();
        frameTime = newTime - currentTime;

        if (frameTime.asSeconds() > 0.25f)
            frameTime = sf::seconds(0.25f);

        currentTime = newTime;
        accumulator += frameTime.asSeconds();

        handleInput();

        while (accumulator >= deltaTime)
        {
            update(deltaTime);
            accumulator -= deltaTime;
        }

        render();

        sf::sleep(sf::milliseconds(1));
    }
}

void Game::handleInput()
{
    sf::Event event;
    while (window.pollEvent(event)) 
    {
        stateManager.getCurrentState()->handleEvents(event);

        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(const float& deltaTime)
{
    stateManager.getCurrentState()->update(deltaTime);
}

void Game::render()
{
    window.clear();

    stateManager.getCurrentState()->render();

    window.display();
}
