#include <iostream>
#include "config.h"
#include "Game.h"


Game::Game() {
    window.create(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Titlebar | sf::Style::Close);
}

void Game::run() {
    isRunning = true;
    sf::Clock clock;
    const float deltaTime{ 0.01f };

    sf::Time newTime;
    sf::Time frameTime;
    sf::Time currentTime = clock.restart();

    float accumulator{ 0.0f };

    while (isRunning) {
        newTime = clock.getElapsedTime();
        frameTime = newTime - currentTime;
        if (frameTime.asSeconds() > 0.25f)
            frameTime = sf::seconds(0.25f);
        currentTime = newTime;

        accumulator += frameTime.asSeconds();

        handleInput();

        while (accumulator >= deltaTime) {
            update(deltaTime);
            accumulator -= deltaTime;
        }

        render();

        std::cout << "Render: " << 1.f / frameTime.asSeconds() << '\n';
    }
}

void Game::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            isRunning = false;
        }
    }
}

void Game::update(const float& deltaTime) {
    std::cout << "Update: " << 1.f / deltaTime << '\n';
}

void Game::render() {
    window.clear();
    window.display();
}
