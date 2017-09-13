#pragma once
#include <SFML\Graphics.hpp>
#include <random>

class Paddle;

class Ball
{
public:
    Ball();

    void update(const float& dt);
    void draw(sf::RenderTarget& target) const;
    void reset();
    void launch();

    void resolveCollision(float px, float py, float dx, float dy, Paddle & p);

    float getPositionX()
    {
        return shape.getPosition().x;
    }

    float getPositionY()
    {
        return shape.getPosition().y;
    }

    const unsigned short getHitsByPaddle()
    {
        return hitsByPaddle;
    }

    sf::Vector2f velocity;

private:
    sf::CircleShape shape;
    bool isMoving = false;

    unsigned short hitsByPaddle = 0;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dist;
};
