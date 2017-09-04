#pragma once
#include <SFML\Graphics.hpp>
#include <random>

class Ball
{
public:
    Ball();

    void update(const float& dt);
    void draw(sf::RenderTarget& target) const;
    void reset();
    void launch();

    float getPositionX()
    {
        return shape.getPosition().x;
    }

    float getPositionY()
    {
        return shape.getPosition().y;
    }

    sf::Vector2f velocity;

private:
    sf::CircleShape shape;
    bool isMoving = false;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dist;
};
