#pragma once
#include <SFML\Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"


class Game {
public:
    Game::Game();
    void run();

private:
    void handleInput();
    void update(const float& deltaTime);
    void render();

    void doCollisions();
    bool checkCollision(Ball &circle, Paddle &rect);

    sf::RenderWindow window;
    bool isRunning{ false };

    Paddle player1;
    Paddle player2;
    Ball ball;
};
