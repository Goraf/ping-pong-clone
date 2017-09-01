#pragma once
#include <SFML\Graphics.hpp>
#include "GameStateManager.h"


class Game {
public:
    Game::Game();
    void run();

private:
    void handleInput();
    void update(const float& deltaTime);
    void render();

    sf::RenderWindow window;
    GameStateManager stateManager;
    bool isRunning{ false };
};
