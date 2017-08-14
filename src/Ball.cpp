#include "Ball.h"
#include "config.h"

Ball::Ball() {
    shape.setRadius(ballRadius);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Blue);
}

void Ball::update(const float& dt) {
    shape.move(velocity * dt);

    if (shape.getPosition().y <= 0.f || shape.getPosition().y >= windowHeight - 2 * ballRadius) {
        velocity.y = -velocity.y;
    }
    if (shape.getPosition().x <= 0.f || shape.getPosition().x >= windowWidth - 2 * ballRadius) {
        velocity.x = -velocity.x;
    }
}

void Ball::draw(sf::RenderTarget & target) const {
    target.draw(shape);
}
