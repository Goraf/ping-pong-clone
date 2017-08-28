#include "Ball.h"
#include "config.h"

Ball::Ball() {
    shape.setRadius(ballRadius);
    shape.setFillColor(sf::Color::Blue);
    reset();
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

void Ball::reset() {
    velocity.x = 0.f;
    velocity.y = 0.f;
    float horizonatlCenter = windowWidth / 2.f - shape.getRadius();
    float verticalCenter = windowHeight / 2.f - shape.getRadius();
    shape.setPosition(horizonatlCenter, verticalCenter);
}