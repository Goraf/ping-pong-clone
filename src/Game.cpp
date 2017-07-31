#include "Game.h"


Game::Game() {
    window.create(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Titlebar | sf::Style::Close);
}

void Game::run() {
    isRunning = true;
    while (isRunning) {
        handleInput();
        update();
        render();
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

void Game::update() {
}

void Game::render() {
    window.display();
}
