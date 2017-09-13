#pragma once
#include <SFML\Graphics.hpp>


class Paddle
{
public:
    Paddle(float positionX);

    void update(const float& dt);
    void draw(sf::RenderTarget& target) const;

    void moveUp();
    void moveDown();
    void stopMovement();

    float getPositionX()
    {
        return shape.getPosition().x;
    }

    float getPositionY()
    {
        return shape.getPosition().y;
    }

    void addPoint();
    int getPoints();

private:
    float speed{ 200 };
    int score;

    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Vector2f velocity;
};


