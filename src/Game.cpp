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

        if (event.type == sf::Event::KeyReleased) {
            Player1.stopMovement();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        Player1.moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        Player1.moveDown();
    }

}

void Game::update(const float& deltaTime) {
    ball.update(deltaTime);
    Player1.update(deltaTime);
    std::cout << "Update: " << 1.f / deltaTime << '\n';
    doCollisions();
}

void Game::render() {
    window.clear();

    ball.draw(window);
    Player1.draw(window);

    window.display();
}

void Game::doCollisions() {
    if (checkCollision(ball, Player1)) {
        ball.velocity.x = -ball.velocity.x;
    }
}

bool Game::checkCollision(Ball &ball, Paddle &rect) {
    bool collideX = ball.getPositionX() + 2*ballRadius >= rect.getPositionX() &&
        ball.getPositionX() <= rect.getPositionX() + paddleWidth;

    bool collideY = ball.getPositionY() + 2*ballRadius >= rect.getPositionY() &&
        ball.getPositionY() <= rect.getPositionY() + paddleHeight;

    return collideX && collideY;
}
