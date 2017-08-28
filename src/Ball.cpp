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
}

void Ball::draw(sf::RenderTarget & target) const {
    target.draw(shape);
}

void Ball::reset() {
    velocity.x = 0.f;
    velocity.y = 0.f;
    isMoving = false;

    float horizonatlCenter = windowWidth / 2.f - shape.getRadius();
    float verticalCenter = windowHeight / 2.f - shape.getRadius();
    shape.setPosition(horizonatlCenter, verticalCenter);
}

void Ball::launch() {
    if (!isMoving) {
        velocity.x = 300.f;
        velocity.y = 300.f;
        isMoving = true;
    }
}
