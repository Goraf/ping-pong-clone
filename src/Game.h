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

    sf::RenderWindow window;
    bool isRunning{ false };

    Paddle Player1;
    Ball ball;
};
