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

    const unsigned windowWidth = 800;
    const unsigned windowHeight = 600;
    const std::string windowTitle = "PongClone";

    sf::RenderWindow window;
    bool isRunning{ false };
};
