#pragma once
#include <SFML\Graphics.hpp>

class Ball {
public:
    Ball();

    void update(const float& dt);
    void draw(sf::RenderTarget& target) const;

    float getPositionX() { return shape.getPosition().x; }
    float getPositionY() { return shape.getPosition().y; }
    sf::Vector2f velocity{ 300.f, 300.f };
private:
    sf::CircleShape shape;

};



