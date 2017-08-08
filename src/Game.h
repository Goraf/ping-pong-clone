#pragma once
#include <SFML\Graphics.hpp>



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
};
