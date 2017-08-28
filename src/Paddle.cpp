#include "config.h"
#include "Paddle.h"

Paddle::Paddle(float positionX) {
    position.x = positionX;
    position.y = (windowHeight / 2) - (paddleHeight / 2);
    shape.setSize(sf::Vector2f(paddleWidth, paddleHeight));
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Magenta);
    velocity.x = 0.f;
    velocity.y = 0.f;
}

void Paddle::update(const float& dt) {
    position += velocity * dt;

    if (position.y <= 0.f) {
        position.y = 0.f;
        velocity.y = 0.f;
    }
    if (position.y >= windowHeight - paddleHeight) {
        position.y = windowHeight - paddleHeight;
        velocity.y = 0.f;
    }
    shape.setPosition(position);
}

void Paddle::draw(sf::RenderTarget& target) const {
    target.draw(shape);
}

void Paddle::moveUp() {
    velocity.y = -speed;
}

void Paddle::moveDown() {
    velocity.y = speed;
}

void Paddle::stopMovement() {
    velocity.y = 0.f;
}
