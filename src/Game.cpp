#include <iostream>
#include "config.h"
#include "Game.h"


Game::Game() : 
    player1(50.f),
    player2(windowWidth - 50.f - paddleWidth)
{
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

        sf::sleep(sf::milliseconds(1));
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
            player1.stopMovement();
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
            ball.launch();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player1.moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        player1.moveDown();
    }
}

void Game::update(const float& deltaTime) {
    ball.update(deltaTime);
    player1.update(deltaTime);
    player2.update(deltaTime);
    doCollisions();

    if (ball.getPositionX() <= 0.f || ball.getPositionX() >= windowWidth - 2 * ballRadius)
        ball.reset();
}

void Game::render() {
    window.clear();

    ball.draw(window);
    player1.draw(window);
    player2.draw(window);

    window.display();
}

void Game::doCollisions() {
    if (checkCollision(ball, player1))
        ball.velocity.x = -ball.velocity.x;

    if (checkCollision(ball, player2))
        ball.velocity.x = -ball.velocity.x;
}

bool Game::checkCollision(Ball &ball, Paddle &rect) {
    bool collideX = ball.getPositionX() + 2*ballRadius >= rect.getPositionX() &&
        ball.getPositionX() <= rect.getPositionX() + paddleWidth;

    bool collideY = ball.getPositionY() + 2*ballRadius >= rect.getPositionY() &&
        ball.getPositionY() <= rect.getPositionY() + paddleHeight;

    return collideX && collideY;
}
