#pragma once
#include <SFML\Graphics.hpp>

class Paddle {
public:
    Paddle();

    void update(const float& dt);
    void draw(sf::RenderTarget& target) const;

    void moveUp();
    void moveDown();
    void stopMovement();

private:
    float speed{ 200 };

    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Vector2f velocity;
};


